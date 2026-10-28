/* Shared particle setup: the origin, target and spline control points of each
 * particle. This names the effect's entry point, VS_PARTICLE_DISPATCH_FUNCTION, and the
 * helpers are named after it. */

#include "src/EFFECT/entry.h"
#include "src/BATTLE/BATTLE.PRG/camera.h"
#define VS_PARTICLE_DISPATCH_FUNCTION VS_ENTRY_FUNCTION

#include "src/BATTLE/BATTLE.PRG/battleEffect.h"
#include "src/BATTLE/BATTLE.PRG/6E644.h"
#include "src/SLUS_010.40/32154.h"
#include "vs_inline_c.h"
#include <inline_c.h>
#include <rand.h>
#include "src/EFFECT/effectCommon.h"

#ifndef VS_PARTICLE_SETUP_TYPES
#define VS_PARTICLE_SETUP_TYPES
typedef struct {
    u_char unk0;
    u_char unk1;
    short unk2;
    SVECTOR* unk4;
    int unk8;
    int unkC;
    func_800D6CF_t unk10;
} func_800FA098_arg3;
#endif

#define VS_PARTICLE_ORIGIN_FUNCTION VS_CAT(VS_PARTICLE_DISPATCH_FUNCTION, _origin)
#define VS_PARTICLE_TARGET_FUNCTION VS_CAT(VS_PARTICLE_DISPATCH_FUNCTION, _target)
#define VS_PARTICLE_CONTROL_FUNCTION VS_CAT(VS_PARTICLE_DISPATCH_FUNCTION, _control)

#define VS_PARTICLE_CORNER_STATE VS_CAT(VS_PARTICLE_ORIGIN_FUNCTION, _state)
static int VS_PARTICLE_CORNER_STATE = 0;

void VS_PARTICLE_ORIGIN_FUNCTION(func_800FA098_arg0* effect, func_800FA098_arg1* scratch,
    D_800F53B8_t* battle, func_800FA098_arg3* state)
{
    int startX;
    SVECTOR* point;
    int step;
    int angle;
    int startZ;
    int i;
    MATRIX* world;

    vs_battle_lerpVector(
        effect->unk18, vs_battle_sampleCurve(effect->unk8, state->unkC), &scratch->unk98);
    world = &battle->unk1C[effect->unkC8].world;

    VS_APPLY_ANCHOR(scratch, world)

    vs_battle_lerpVector(
        effect->unk24, vs_battle_sampleCurve(effect->unk9, state->unkC), &scratch->unkA8);
    SetRotMatrix(world);
    gte_zrtr();

    switch (scratch->flags & 0x38) {
    case 0:
        for (i = 0; i < state->unk2; ++i) {
            point = &state->unk4[i * 4];
            angle = rand();
            scratch->unk170 = rsin(angle);
            scratch->unk178 = rcos(angle);
            angle = rand();
            scratch->unk174 = rsin(angle);
            scratch->unk17C = rcos(angle);
            setVector(point,
                (((scratch->unkA8.vx * scratch->unk178) >> 12) * scratch->unk17C) >> 12,
                (((scratch->unkA8.vy * scratch->unk178) >> 12) * scratch->unk174) >> 12,
                (scratch->unkA8.vz * scratch->unk170) >> 12);

            if (scratch->flags & 0x40000) {
                ApplyRotMatrix(point, &scratch->unk34);
                copyVector(point, &scratch->unk34);
            }

            addVector(point, &scratch->unk98);
        }

        return;

    case 8:
        for (i = 0; i < state->unk2; ++i) {
            point = &state->unk4[i * 4];

            switch (scratch->flags & 0x1800) {
            case 0:
            case 0x800:
                switch (rand() % 6) {
                case 0:
                    point->vx = scratch->unkA8.vx;
                    goto randomYZ;

                case 1:
                    point->vx = -scratch->unkA8.vx;
                randomYZ:
                    point->vy =
                        vs_battle_randUniformInt(scratch->unkA8.vy, -scratch->unkA8.vy);
                    point->vz =
                        vs_battle_randUniformInt(scratch->unkA8.vz, -scratch->unkA8.vz);
                    break;

                case 2:
                    point->vy = scratch->unkA8.vy;
                    goto randomXZ;

                case 3:
                    point->vy = -scratch->unkA8.vy;
                randomXZ:
                    point->vx =
                        vs_battle_randUniformInt(scratch->unkA8.vx, -scratch->unkA8.vx);
                    point->vz =
                        vs_battle_randUniformInt(scratch->unkA8.vz, -scratch->unkA8.vz);
                    break;

                case 4:
                    point->vz = scratch->unkA8.vz;
                    goto randomXY;

                case 5:
                    point->vz = -scratch->unkA8.vz;
                randomXY:
                    point->vx =
                        vs_battle_randUniformInt(scratch->unkA8.vx, -scratch->unkA8.vx);
                    point->vy =
                        vs_battle_randUniformInt(scratch->unkA8.vy, -scratch->unkA8.vy);
                    break;
                }
                break;

            case 0x1000:
                VS_PARTICLE_CORNER_STATE = (VS_PARTICLE_CORNER_STATE + 1) & 7;
                setVector(point,
                    (VS_PARTICLE_CORNER_STATE & 1) ? scratch->unkA8.vx
                                                   : -scratch->unkA8.vx,
                    (VS_PARTICLE_CORNER_STATE & 2) ? scratch->unkA8.vy
                                                   : -scratch->unkA8.vy,
                    (VS_PARTICLE_CORNER_STATE & 4) ? scratch->unkA8.vz
                                                   : -scratch->unkA8.vz);
                break;
            }

            if (scratch->flags & 0x40000) {
                ApplyRotMatrix(point, &scratch->unk34);
                copyVector(point, &scratch->unk34);
            }

            addVector(point, &scratch->unk98);
        }

        return;

    case 16:
    case 24:
    case 32:
    case 40:
        scratch->unk184 = 4;
        scratch->unk188 = 4;
        break;

    case 48:
        scratch->unk184 = effect->unkCA;

        if (scratch->unk184 == 0) {
            scratch->unk184 = 1;
        }

        scratch->unk188 = effect->unkCB;

        if (scratch->unk188 == 0) {
            scratch->unk188 = scratch->unk184;
        }
        break;

    default:
        return;
    }

    step = ONE / scratch->unk184;

    if ((scratch->flags & 0x1800) != 0x1000) {
        VS_PARTICLE_CORNER_STATE %= scratch->unk188;
        angle = VS_PARTICLE_CORNER_STATE * step + ONE / 8;
        startX = (rcos(angle) * scratch->unkA8.vx) >> 12;
        startZ = (rsin(angle) * scratch->unkA8.vz) >> 12;
    }

    for (i = 0; i < state->unk2; ++i) {
        int x;
        int z;

        point = &state->unk4[i * 4];
        VS_PARTICLE_CORNER_STATE = (VS_PARTICLE_CORNER_STATE + 1) % scratch->unk188;
        angle = VS_PARTICLE_CORNER_STATE * step + ONE / 8;
        x = (rcos(angle) * scratch->unkA8.vx) >> 12;
        z = (rsin(angle) * scratch->unkA8.vz) >> 12;

        if ((scratch->flags & 0x1800) == 0x1000) {
            point->vx = x;
            point->vz = z;
        } else {
            int t = rand() >> 3;

            point->vx = (((x - startX) * t) >> 12) + startX;
            point->vz = (((z - startZ) * t) >> 12) + startZ;
        }

        point->vy = 0;

        if (scratch->flags & 0x40000) {
            ApplyRotMatrix(point, &scratch->unk34);
            copyVector(point, &scratch->unk34);
        }

        addVector(point, &scratch->unk98);
    }
}

void VS_PARTICLE_TARGET_FUNCTION(func_800FA098_arg0* effect, func_800FA098_arg1* scratch,
    D_800F53B8_t* battle, func_800FA098_arg3* state)
{
    int i;

    vs_battle_lerpSvector(effect->unk34[6],
        vs_battle_sampleCurve(effect->unkF, state->unkC), &scratch->unk13C);
    vs_battle_lerpSvector(effect->unk34[7],
        vs_battle_sampleCurve(effect->unk10, state->unkC), &scratch->unk144);

    switch (scratch->flags & 0x1C0) {
    case 0xC0:
        applyVector(&scratch->unk13C, battle->unk1C[effect->unkC9].world.t[0],
            battle->unk1C[effect->unkC9].world.t[1],
            battle->unk1C[effect->unkC9].world.t[2], +=);
        break;

    case 0x80:
        applyVector(&scratch->unk13C, D_800F5230.position.vx, D_800F5230.position.vy,
            D_800F5230.position.vz, +=);
        break;

    case 0:
        break;
    }

    for (i = 0; i < state->unk2; ++i) {
        SVECTOR* target = &state->unk4[i * 4 + 3];

        setVector(target,
            scratch->unk13C.vx
                + vs_battle_randUniformInt(scratch->unk144.vx, -scratch->unk144.vx),
            scratch->unk13C.vy
                + vs_battle_randUniformInt(scratch->unk144.vy, -scratch->unk144.vy),
            scratch->unk13C.vz
                + vs_battle_randUniformInt(scratch->unk144.vz, -scratch->unk144.vz));
    }
}

void VS_PARTICLE_CONTROL_FUNCTION(func_800FA098_arg0* effect, func_800FA098_arg1* scratch,
    D_800F53B8_t* battle, func_800FA098_arg3* state)
{
    int i;

    for (i = 0; i < state->unk2; ++i) {
        SVECTOR startOffset;
        SVECTOR endOffset;
        SVECTOR* points = &state->unk4[i * 4];
        int distance;
        int startAngle;
        int endAngle;
        int startRadius;
        int endRadius;

        setVector(&scratch->unk34, points[3].vx - points[0].vx,
            points[3].vy - points[0].vy, points[3].vz - points[0].vz);
        distance = vs_gte_rsqrt(scratch->unk34.vx * scratch->unk34.vx
                                + scratch->unk34.vy * scratch->unk34.vy
                                + scratch->unk34.vz * scratch->unk34.vz);
        vs_battle_lerp2DVector(effect->unk94[0],
            vs_battle_sampleCurve(effect->unk12, state->unkC), scratch->unk124);
        vs_battle_lerp2DVector(effect->unk94[1],
            vs_battle_sampleCurve(effect->unk13, state->unkC), scratch->unk12C);
        vs_battle_lerp2DVector(effect->unk94[2],
            vs_battle_sampleCurve(effect->unkC, state->unkC), scratch->unk118);
        vs_battle_lerpVector(effect->unk34[1],
            vs_battle_sampleCurve(effect->unkB, state->unkC), &scratch->unkC8);
        vs_battle_lerpVector(effect->unk34[0],
            vs_battle_sampleCurve(effect->unkA, state->unkC), &scratch->unkE8);
        vs_battle_lerpSvector(effect->unk34[2],
            vs_battle_sampleCurve(effect->unkD, state->unkC), &scratch->unkF8);

        if (scratch->unkF8.vx != 0) {
            int along =
                scratch->unk118[0] + rand() % scratch->unkF8.vx - scratch->unkF8.vx / 2;

            if (&scratch->unk34) {
                startOffset.vz = distance * along / 256;
            } else {
                startOffset.vz = distance * along / 256;
            }
        } else {
            startOffset.vz = distance * scratch->unk118[0] / 256;
        }

        if (scratch->unkF8.vy != 0) {
            int along =
                scratch->unk118[1] + rand() % scratch->unkF8.vy - scratch->unkF8.vy / 2;
            endOffset.vz = distance + distance * along / 256;
        } else {
            endOffset.vz = distance + distance * scratch->unk118[1] / 256;
        }

        startRadius = scratch->unk124[0];

        if (scratch->unk124[1] != 0) {
            startRadius += rand() % scratch->unk124[1];
        }

        endRadius = scratch->unk12C[0];

        if (scratch->unk12C[1] != 0) {
            endRadius += rand() % scratch->unk12C[1];
        }

        startAngle = scratch->unkE8.vx;

        if (scratch->unkC8.vx != 0) {
            startAngle += rand() % (scratch->unkC8.vx * 2) - scratch->unkC8.vx;
        }

        endAngle = scratch->unkE8.vy;

        if (scratch->unkC8.vy != 0) {
            endAngle += rand() % (scratch->unkC8.vy * 2) - scratch->unkC8.vy;
        }

        startOffset.vx = (rcos(startAngle) * startRadius) >> 12;
        startOffset.vy = (rsin(startAngle) * startRadius) >> 12;
        endOffset.vx = (rcos(endAngle) * endRadius) >> 12;
        endOffset.vy = (rsin(endAngle) * endRadius) >> 12;
        vs_battle_svecToVec(points, &scratch->unk34);
        vs_battle_svecToVec(points + 3, &scratch->unk44);
        vs_battle_lookAt(&scratch->unk34, &scratch->unk44, &scratch->unk64);
        gte_SetRotMatrix(&scratch->unk64);
        gte_SetTransVector2(&scratch->unk34);
        gte_ldv0(&startOffset);
        gte_rtv0tr2();
        gte_stlvnl(&scratch->unk34);
        vs_battle_vecToSvec(&scratch->unk34, points + 1);
        gte_ldv0(&endOffset);
        gte_rtv0tr2();
        gte_stlvnl(&scratch->unk44);
        vs_battle_vecToSvec(&scratch->unk44, points + 2);
    }
}

#undef VS_PARTICLE_CORNER_STATE
