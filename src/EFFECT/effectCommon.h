/* Types and code blocks shared by the effect headers. */

#ifndef VS_EFFECT_COMMON_H
#define VS_EFFECT_COMMON_H

#include "src/BATTLE/BATTLE.PRG/battleEffect.h"
#include "gpu.h"
#include <inline_c.h>

typedef struct {
    int tag;
    POLY_GT4 poly;
    int drawMode;
} vs_gt4Prim;

typedef struct {
    u_char u;
    u_char v;
} vs_uv;

/* State of the ring-like effects, which grow a radius and a height every frame. */
typedef struct {
    u_char lifetime;
    u_char effect;
    short pad;
    int radius;
    int radiusSpeed;
    int height;
    int heightSpeed;
    int angle;
    int age;
    func_800D6CF_t texture;
} vs_ringState;

/* Defines the table of the eight standard effect colors. */
#define VS_STANDARD_COLORS(name)                                                         \
    static CVECTOR name[] = { { 255, 255, 255 }, { 128, 128, 128 }, { 255, 128, 0 },     \
        { 0, 128, 255 }, { 0, 255, 0 }, { 255, 0, 255 }, { 0, 128, 0 },                  \
        { 128, 0, 128 } }

/* Offsets the effect position in `scratch` by the effect's anchor: nothing, the fixed
 * point D_800F5310, or the translation of `matrix`. */
#define VS_APPLY_ANCHOR(scratch, matrix)                                                 \
    switch ((scratch)->flags & 7) {                                                      \
    case 0:                                                                              \
        break;                                                                           \
                                                                                         \
    case 1:                                                                              \
        vs_battle_addVecToSvec(&(scratch)->unk98, D_800F5310, &(scratch)->unk98);        \
        break;                                                                           \
                                                                                         \
    case 2:                                                                              \
        applyVector(&(scratch)->unk98, (matrix)->t[0], (matrix)->t[1], (matrix)->t[2],   \
            +=);                                                                         \
        break;                                                                           \
    }

/* Spawns the effect's child effect, positioned at the effect position in `scratch`. */
#define VS_SPAWN_CHILD(effect, scratch, battle, actorMatrix, child)                      \
    if ((effect)->unk3) {                                                                \
        (child).unk60 = 0;                                                               \
        if ((effect)->flags & 0x20000) {                                                 \
            SetRotMatrix(actorMatrix);                                                   \
            SetTransMatrix(actorMatrix);                                                 \
            copyVector(&(scratch)->unk2C, &(scratch)->unk98);                            \
            gte_ldv0(&(scratch)->unk2C);                                                 \
            gte_rtv0tr2();                                                               \
            gte_stlvnl(&(scratch)->unk34);                                               \
            setVector(&(child).motion.position, (scratch)->unk34.vx * ONE,               \
                (scratch)->unk34.vy * ONE, (scratch)->unk34.vz * ONE);                   \
        } else {                                                                         \
            setVector(&(child).motion.position, (scratch)->unk98.vx * ONE,               \
                (scratch)->unk98.vy * ONE, (scratch)->unk98.vz * ONE);                   \
        }                                                                                \
        func_800D2ADC(battle, (effect)->unk3 - 1, 0, 0, &(child));                       \
    }

#endif
