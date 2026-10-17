/* Shared textured particle setup: the origin, target and spline control points of each
 * particle. The overlay supplies the entry points and the corner counter. */

#include "src/BATTLE/BATTLE.PRG/5BF94.h"
#include "vs_inline_c.h"
#include <inline_c.h>
#include <rand.h>

typedef struct {
    u_char unk0;
    u_char unk1;
    short unk2;
    SVECTOR* unk4;
    int unk8;
    int unkC;
    func_800D6CF_t unk10;
} func_800FA098_arg3;

extern int VS_PARTICLE_CORNER_STATE;

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

    switch (scratch->flags & 7) {
    case 0:
        break;

    case 1:
        vs_battle_addVecToSvec(&scratch->unk98, D_800F5310, &scratch->unk98);
        break;

    case 2:
        applyVector(&scratch->unk98, world->t[0], world->t[1], world->t[2], +=);
        break;
    }

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
