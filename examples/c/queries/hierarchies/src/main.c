#include <hierarchies.h>
#include <stdio.h>

typedef struct {
    double x;
    double y;
} Position;

int main(int argc, char *argv[]) {
    ecs_world_t *ecs = ecs_init_w_args(argc, argv);

    ECS_COMPONENT(ecs, Position);

    // Tags for local/ecs position
    ECS_TAG(ecs, Local);
    ECS_TAG(ecs, World);

    // Create a hierarchy. For an explanation see the entities/hierarchy example
    ecs_entity_t sun = ecs_entity(ecs, { .name = "Sun" });
    ecs_add_pair(ecs, sun, ecs_id(Position), World);
    ecs_set_pair(ecs, sun, Position, Local, {1, 1});

        ecs_entity_t mercury = ecs_entity(ecs, { .name = "Mercury" });
        ecs_add_pair(ecs, mercury, EcsChildOf, sun);
        ecs_add_pair(ecs, mercury, ecs_id(Position), World);
        ecs_set_pair(ecs, mercury, Position, Local, {1, 1});

        ecs_entity_t venus = ecs_entity(ecs, { .name = "Venus" });
        ecs_add_pair(ecs, venus, EcsChildOf, sun);
        ecs_add_pair(ecs, venus, ecs_id(Position), World);
        ecs_set_pair(ecs, venus, Position, Local, {2, 2});

        ecs_entity_t earth = ecs_entity(ecs, { .name = "Earth" });
        ecs_add_pair(ecs, earth, EcsChildOf, sun);
        ecs_add_pair(ecs, earth, ecs_id(Position), World);
        ecs_set_pair(ecs, earth, Position, Local, {3, 3});

            ecs_entity_t moon = ecs_entity(ecs, { .name = "Moon" });
            ecs_add_pair(ecs, moon, EcsChildOf, earth);
            ecs_add_pair(ecs, moon, ecs_id(Position), World);
            ecs_set_pair(ecs, moon, Position, Local, {0.1, 0.1});

    // Create a hierarchical query to compute the global position from the
    // local position and the parent position.
    ecs_query_t *q = ecs_query(ecs, {
        .terms = {
            // Read from entity's Local position
            { .id = ecs_pair(ecs_id(Position), Local), .inout = EcsIn }, 
            // Write to entity's World position
            { .id = ecs_pair(ecs_id(Position), World), .inout = EcsOut },

            // Read from parent's World position
            {
                .id = ecs_pair(ecs_id(Position), World), 
                .inout = EcsIn,
                // Get from the parent in breadth-first order (cascade)
                .src.id = EcsCascade,
                // Make parent term optional so we also match the root (sun)
                .oper = EcsOptional
            }
        }
    });

    // Do the transform
    ecs_iter_t it = ecs_query_iter(ecs, q);
    while (ecs_query_next(&it)) {
        const Position *p = ecs_field(&it, Position, 0);
        Position *p_out = ecs_field(&it, Position, 1);
        const Position *p_parent = ecs_field(&it, Position, 2);
        
        // Inner loop, iterates entities in archetype
        for (int i = 0; i < it.count; i ++) {
            p_out[i].x = p[i].x;
            p_out[i].y = p[i].y;
            if (p_parent) {
                p_out[i].x += p_parent->x;
                p_out[i].y += p_parent->y;
            }
        }
    }

    // Print ecs positions
    it = ecs_each_pair_t(ecs, Position, World);
    while (ecs_each_next(&it)) {
        Position *p = ecs_field(&it, Position, 0);
        for (int i = 0; i < it.count; i ++) {
            printf("%s: {%f, %f}\n", ecs_get_name(ecs, it.entities[i]),
                p[i].x, p[i].y);
        }
    }

    return ecs_fini(ecs);
}
