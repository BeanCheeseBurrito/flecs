#include <meta.h>

static void meta_test_primitive(
    ecs_world_t *world, 
    ecs_entity_t t, 
    ecs_primitive_kind_t kind, 
    ecs_size_t size, 
    ecs_size_t alignment) 
{
    const EcsComponent *ct = ecs_get(world, t, EcsComponent);
    test_assert(ct != NULL);
    test_assert(ct->size == size);
    test_assert(ct->alignment == alignment);

    const EcsType *mt = ecs_get(world, t, EcsType);
    test_assert(mt != NULL);
    test_assert(mt->kind == EcsPrimitiveType);

    const EcsPrimitive *pt = ecs_get(world, t, EcsPrimitive);
    test_assert(pt != NULL);
    test_assert(pt->kind == kind);
}

#define meta_test_type(kind, type)\
    static void meta_test_##type(ecs_world_t *world, ecs_entity_t t) {\
        meta_test_primitive(world, t, kind, ECS_SIZEOF(ecs_##type##_t), ECS_ALIGNOF(ecs_##type##_t));\
    }

#define meta_test_builtin(world, type)\
    meta_test_##type(world, ecs_id(ecs_##type##_t))

meta_test_type(EcsBool, bool)
meta_test_type(EcsByte, byte)
meta_test_type(EcsChar, char)
meta_test_type(EcsI8, i8)
meta_test_type(EcsI16, i16)
meta_test_type(EcsI32, i32)
meta_test_type(EcsI64, i64)
meta_test_type(EcsIPtr, iptr)
meta_test_type(EcsU8, u8)
meta_test_type(EcsU16, u16)
meta_test_type(EcsU32, u32)
meta_test_type(EcsU64, u64)
meta_test_type(EcsUPtr, uptr)
meta_test_type(EcsF32, f32)
meta_test_type(EcsF64, f64)
meta_test_type(EcsString, string)
meta_test_type(EcsEntity, entity)
meta_test_type(EcsId, id)

void PrimitiveTypes_bool(void) {
    ecs_world_t *world = ecs_init();

    ecs_entity_t t = ecs_insert(world, ecs_value(EcsPrimitive, {.kind = EcsBool}));
    test_assert(t != 0);

    meta_test_bool(world, t);

    ecs_fini(world);
}

void PrimitiveTypes_byte(void) {
    ecs_world_t *world = ecs_init();

    ecs_entity_t t = ecs_insert(world, ecs_value(EcsPrimitive, {.kind = EcsByte}));
    test_assert(t != 0);

    meta_test_byte(world, t);

    ecs_fini(world);
}

void PrimitiveTypes_char(void) {
    ecs_world_t *world = ecs_init();

    ecs_entity_t t = ecs_insert(world, ecs_value(EcsPrimitive, {.kind = EcsChar}));
    test_assert(t != 0);

    meta_test_char(world, t);

    ecs_fini(world);
}

void PrimitiveTypes_i8(void) {
    ecs_world_t *world = ecs_init();

    ecs_entity_t t = ecs_insert(world, ecs_value(EcsPrimitive, {.kind = EcsI8}));
    test_assert(t != 0);

    meta_test_i8(world, t);

    ecs_fini(world);
}

void PrimitiveTypes_i16(void) {
    ecs_world_t *world = ecs_init();

    ecs_entity_t t = ecs_insert(world, ecs_value(EcsPrimitive, {.kind = EcsI16}));
    test_assert(t != 0);

    meta_test_i16(world, t);

    ecs_fini(world);
}

void PrimitiveTypes_i32(void) {
    ecs_world_t *world = ecs_init();

    ecs_entity_t t = ecs_insert(world, ecs_value(EcsPrimitive, {.kind = EcsI32}));
    test_assert(t != 0);

    meta_test_i32(world, t);

    ecs_fini(world);
}

void PrimitiveTypes_i64(void) {
    ecs_world_t *world = ecs_init();

    ecs_entity_t t = ecs_insert(world, ecs_value(EcsPrimitive, {.kind = EcsI64}));
    test_assert(t != 0);

    meta_test_i64(world, t);

    ecs_fini(world);
}

void PrimitiveTypes_iptr(void) {
    ecs_world_t *world = ecs_init();

    ecs_entity_t t = ecs_insert(world, ecs_value(EcsPrimitive, {.kind = EcsIPtr}));
    test_assert(t != 0);

    meta_test_iptr(world, t);

    ecs_fini(world);
}

void PrimitiveTypes_u8(void) {
    ecs_world_t *world = ecs_init();

    ecs_entity_t t = ecs_insert(world, ecs_value(EcsPrimitive, {.kind = EcsU8}));
    test_assert(t != 0);

    meta_test_u8(world, t);

    ecs_fini(world);
}

void PrimitiveTypes_u16(void) {
    ecs_world_t *world = ecs_init();

    ecs_entity_t t = ecs_insert(world, ecs_value(EcsPrimitive, {.kind = EcsU16}));
    test_assert(t != 0);

    meta_test_u16(world, t);

    ecs_fini(world);
}

void PrimitiveTypes_u32(void) {
    ecs_world_t *world = ecs_init();

    ecs_entity_t t = ecs_insert(world, ecs_value(EcsPrimitive, {.kind = EcsU32}));
    test_assert(t != 0);

    meta_test_u32(world, t);

    ecs_fini(world);
}

void PrimitiveTypes_u64(void) {
    ecs_world_t *world = ecs_init();

    ecs_entity_t t = ecs_insert(world, ecs_value(EcsPrimitive, {.kind = EcsU64}));
    test_assert(t != 0);

    meta_test_u64(world, t);

    ecs_fini(world);
}

void PrimitiveTypes_uptr(void) {
    ecs_world_t *world = ecs_init();

    ecs_entity_t t = ecs_insert(world, ecs_value(EcsPrimitive, {.kind = EcsUPtr}));
    test_assert(t != 0);

    meta_test_uptr(world, t);

    ecs_fini(world);
}

void PrimitiveTypes_float(void) {
    ecs_world_t *world = ecs_init();

    ecs_entity_t t = ecs_insert(world, ecs_value(EcsPrimitive, {.kind = EcsF32}));
    test_assert(t != 0);

    meta_test_f32(world, t);

    ecs_fini(world);
}

void PrimitiveTypes_double(void) {
    ecs_world_t *world = ecs_init();

    ecs_entity_t t = ecs_insert(world, ecs_value(EcsPrimitive, {.kind = EcsF64}));
    test_assert(t != 0);

    meta_test_f64(world, t);

    ecs_fini(world);
}

void PrimitiveTypes_string(void) {
    ecs_world_t *world = ecs_init();

    ecs_entity_t t = ecs_insert(world, ecs_value(EcsPrimitive, {.kind = EcsString}));
    test_assert(t != 0);

    meta_test_string(world, t);

    ecs_fini(world);
}

void PrimitiveTypes_entity(void) {
    ecs_world_t *world = ecs_init();

    ecs_entity_t t = ecs_insert(world, ecs_value(EcsPrimitive, {.kind = EcsEntity}));
    test_assert(t != 0);

    meta_test_entity(world, t);

    ecs_fini(world);
}

void PrimitiveTypes_id(void) {
    ecs_world_t *world = ecs_init();

    ecs_entity_t t = ecs_insert(world, ecs_value(EcsPrimitive, {.kind = EcsId}));
    test_assert(t != 0);

    meta_test_id(world, t);

    ecs_fini(world);
}

void PrimitiveTypes_builtin_bool(void) {
    ecs_world_t *world = ecs_init();

    meta_test_builtin(world, bool);

    ecs_fini(world);
}

void PrimitiveTypes_builtin_byte(void) {
    ecs_world_t *world = ecs_init();

    meta_test_builtin(world, byte);

    ecs_fini(world);
}

void PrimitiveTypes_builtin_char(void) {
    ecs_world_t *world = ecs_init();

    meta_test_builtin(world, char);

    ecs_fini(world);
}

void PrimitiveTypes_builtin_i8(void) {
    ecs_world_t *world = ecs_init();

    meta_test_builtin(world, i8);

    ecs_fini(world);
}

void PrimitiveTypes_builtin_i16(void) {
    ecs_world_t *world = ecs_init();

    meta_test_builtin(world, i16);

    ecs_fini(world);
}

void PrimitiveTypes_builtin_i32(void) {
    ecs_world_t *world = ecs_init();

    meta_test_builtin(world, i32);

    ecs_fini(world);
}

void PrimitiveTypes_builtin_i64(void) {
    ecs_world_t *world = ecs_init();

    meta_test_builtin(world, i64);

    ecs_fini(world);
}

void PrimitiveTypes_builtin_iptr(void) {
    ecs_world_t *world = ecs_init();

    meta_test_builtin(world, iptr);

    ecs_fini(world);
}

void PrimitiveTypes_builtin_u8(void) {
    ecs_world_t *world = ecs_init();

    meta_test_builtin(world, u8);

    ecs_fini(world);
}

void PrimitiveTypes_builtin_u16(void) {
    ecs_world_t *world = ecs_init();

    meta_test_builtin(world, i16);

    ecs_fini(world);
}

void PrimitiveTypes_builtin_u32(void) {
    ecs_world_t *world = ecs_init();

    meta_test_builtin(world, u32);

    ecs_fini(world);
}

void PrimitiveTypes_builtin_u64(void) {
    ecs_world_t *world = ecs_init();

    meta_test_builtin(world, u64);

    ecs_fini(world);
}

void PrimitiveTypes_builtin_uptr(void) {
    ecs_world_t *world = ecs_init();

    meta_test_builtin(world, uptr);

    ecs_fini(world);
}

void PrimitiveTypes_builtin_float(void) {
    ecs_world_t *world = ecs_init();

    meta_test_builtin(world, f32);

    ecs_fini(world);
}

void PrimitiveTypes_builtin_double(void) {
    ecs_world_t *world = ecs_init();

    meta_test_builtin(world, f64);

    ecs_fini(world);
}

void PrimitiveTypes_builtin_string(void) {
    ecs_world_t *world = ecs_init();

    meta_test_builtin(world, string);

    ecs_fini(world);
}

void PrimitiveTypes_builtin_entity(void) {
    ecs_world_t *world = ecs_init();

    meta_test_builtin(world, entity);

    ecs_fini(world);
}

void PrimitiveTypes_builtin_id(void) {
    ecs_world_t *world = ecs_init();

    meta_test_builtin(world, id);

    ecs_fini(world);
}

#define STRUCT_W_PRIMITIVE_TEST(PrimitiveType)\
    typedef struct {\
        ecs_bool_t before;\
        PrimitiveType v;\
        ecs_bool_t after;\
    } T;\
\
    ecs_world_t *world = ecs_init();\
\
    ecs_entity_t t = ecs_struct_init(world, &(ecs_struct_desc_t){\
        .entity = ecs_entity(world, {.name = "T"}),\
        .members = {\
            {"before", ecs_id(ecs_bool_t)},\
            {"v", ecs_id(PrimitiveType)},\
            {"after", ecs_id(ecs_bool_t)}\
        }\
    });\
\
    test_assert(t != 0);\
    test_str(ecs_get_name(world, t), "T");\
\
    meta_test_struct(world, t, T);\
    meta_test_member(world, t, T, before, ecs_id(ecs_bool_t), 1);\
    meta_test_member(world, t, T, v, ecs_id(PrimitiveType), 1);\
    meta_test_member(world, t, T, after, ecs_id(ecs_bool_t), 1);\
\
    ecs_fini(world);

void PrimitiveTypes_struct_w_bool(void) {
    STRUCT_W_PRIMITIVE_TEST(ecs_bool_t)
}

void PrimitiveTypes_struct_w_byte(void) {
    STRUCT_W_PRIMITIVE_TEST(ecs_byte_t)
}

void PrimitiveTypes_struct_w_char(void) {
    STRUCT_W_PRIMITIVE_TEST(ecs_char_t)
}

void PrimitiveTypes_struct_w_i8(void) {
    STRUCT_W_PRIMITIVE_TEST(ecs_i8_t)
}

void PrimitiveTypes_struct_w_i16(void) {
    STRUCT_W_PRIMITIVE_TEST(ecs_i16_t)
}

void PrimitiveTypes_struct_w_i32(void) {
    STRUCT_W_PRIMITIVE_TEST(ecs_i32_t)
}

void PrimitiveTypes_struct_w_i64(void) {
    STRUCT_W_PRIMITIVE_TEST(ecs_i64_t)
}

void PrimitiveTypes_struct_w_iptr(void) {
    STRUCT_W_PRIMITIVE_TEST(ecs_iptr_t)
}

void PrimitiveTypes_struct_w_u8(void) {
    STRUCT_W_PRIMITIVE_TEST(ecs_u8_t)
}

void PrimitiveTypes_struct_w_u16(void) {
    STRUCT_W_PRIMITIVE_TEST(ecs_u16_t)
}

void PrimitiveTypes_struct_w_u32(void) {
    STRUCT_W_PRIMITIVE_TEST(ecs_u32_t)
}

void PrimitiveTypes_struct_w_u64(void) {
    STRUCT_W_PRIMITIVE_TEST(ecs_u64_t)
}

void PrimitiveTypes_struct_w_uptr(void) {
    STRUCT_W_PRIMITIVE_TEST(ecs_uptr_t)
}

void PrimitiveTypes_struct_w_float(void) {
    STRUCT_W_PRIMITIVE_TEST(ecs_f32_t)
}

void PrimitiveTypes_struct_w_double(void) {
    STRUCT_W_PRIMITIVE_TEST(ecs_f64_t)
}

void PrimitiveTypes_struct_w_string(void) {
    STRUCT_W_PRIMITIVE_TEST(ecs_string_t)
}

void PrimitiveTypes_struct_w_entity(void) {
    STRUCT_W_PRIMITIVE_TEST(ecs_entity_t)
}

void PrimitiveTypes_struct_w_id(void) {
    STRUCT_W_PRIMITIVE_TEST(ecs_id_t)
}

void PrimitiveTypes_primitive_init(void) {
    ecs_world_t *world = ecs_init();

    ecs_entity_t t = ecs_primitive_init(world, &(ecs_primitive_desc_t){
        .entity = ecs_entity(world, {.name = "T"}),
        .kind = EcsU16
    });
    test_assert(t != 0);
    
    test_str(ecs_get_name(world, t),"T");

    const EcsPrimitive *prim_ptr = ecs_get(world, t, EcsPrimitive);
    test_assert(prim_ptr != NULL);
    test_int(prim_ptr->kind, EcsU16);

    const EcsType *type_ptr = ecs_get(world, t, EcsType);
    test_assert(type_ptr != NULL);
    test_int(type_ptr->kind, EcsPrimitiveType);

    ecs_fini(world);
}

void PrimitiveTypes_primitive_w_short_notation(void) {
    ecs_world_t *world = ecs_init();

    ecs_entity_t t = ecs_primitive(world, {
        .entity = ecs_entity(world, {.name = "T"}),
        .kind = EcsU16
    });
    test_assert(t != 0);
    
    test_str(ecs_get_name(world, t),"T");

    const EcsPrimitive *prim_ptr = ecs_get(world, t, EcsPrimitive);
    test_assert(prim_ptr != NULL);
    test_int(prim_ptr->kind, EcsU16);

    const EcsType *type_ptr = ecs_get(world, t, EcsType);
    test_assert(type_ptr != NULL);
    test_int(type_ptr->kind, EcsPrimitiveType);

    ecs_fini(world);
}
