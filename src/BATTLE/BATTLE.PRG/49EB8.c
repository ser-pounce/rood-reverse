#include "common.h"
#include "30DB0.h"
#include "44F14.h"
#include "4B16C.h"
#include "4DEA8.h"
#include "battleUnk.h"
#include "entity.h"
#include "src/SLUS_010.40/main.h"
#include "src/SLUS_010.40/32154.h"
#include "scratch.h"
#include "vs_inline_c.h"
#include <abs.h>
#include <inline_c.h>

typedef struct {
    int words[2];
} func_800B28A8_t;

extern char D_800E8FC0;

void func_8008C458(int, int, void*, void*);
void func_800B17F0(SVECTOR*, MATRIX*);
void func_800B196C(MATRIX*, MATRIX*);

inline void func_800B26B8(D_800F4538_t* actor, MATRIX* parent, int bone, int saved)
{
    D_1F80035C_t* scratch = (void*)0x1F80035C;

    scratch->matrix = *(actor->unk1890 + saved - 1);
    func_800B196C(parent, &scratch->matrix);
    gte_SetRotMatrix(parent);
    gte_SetTransMatrix(parent);
    --saved;
    setVector(&scratch->position, actor->unk1890[saved].t[0], actor->unk1890[saved].t[1],
        actor->unk1890[saved].t[2]);
    gte_ldv0(&scratch->position);
    gte_rtv0tr2();
    gte_stlvnl(scratch->matrix.t);
    *(D_800F2458.bones + bone) = scratch->matrix;
    actor->bones[bone] = scratch->matrix;
}

void func_800B28A8(D_800F4538_t* actor, MATRIX* camera, int mode)
{
    int _[2] __attribute__((unused));
    func_800B28A8_t header;
    D_1F80035C_t* scratch = (void*)0x1F80035C;
    int i;
    int temp;
    vs_scratch_t* s2;

    scratch->model = actor->unk0.unk68;

    gte_SetRotMatrix(camera);
    gte_SetTransMatrix(camera);
    *(long long*)&scratch->position = *(long long*)&scratch->offset;
    gte_ldv0((SVECTOR*)0x1F8003A8);
    gte_rtv0tr2();
    setVector(&scratch->rotation, actor->unk704.unk0[0].vx >> 1,
        actor->unk704.unk0[0].vy >> 1, actor->unk704.unk0[0].vz >> 1);
    gte_stlvnl(((MATRIX*)0x1F8003C0)->t);
    applyVector(
        &scratch->rotation, actor->unk0.unk24, actor->unk0.facing, actor->unk0.unk28, +=);

    if (actor->unk5AC_21) {
        if ((func_800BEB00() == 4 || actor->unk0.freeze) && mode == 0) {
            if (!actor->unk5AC_22) {
                temp = actor->unk1802[0] + 1;

                if (temp > actor->unk1802[1]) {
                    actor->unk5AC_22 = 1;
                    temp = actor->unk1802[1];
                }
            } else {
                temp = actor->unk1802[0] - 1;

                if (temp < 0) {
                    actor->unk5AC_22 = 0;
                    temp = 0;
                }
            }

            actor->unk1802[0] = temp;
        }

        scratch->rotation.vy += actor->unk1802[0] >> 1;
    }

    *(int*)&scratch->rotation &= 0x0FFF0FFF;
    *(int*)&scratch->rotation.vz &= 0xFFF;
    func_800B17F0(&scratch->rotation, &scratch->matrix);
    func_800B196C(camera, &scratch->matrix);

    if (!actor->unk0.unk9_5) {
        if (actor) {
            setVector(&scratch->scale, actor->unk183C, actor->unk183C, actor->unk183C);
            func_800B396C(&scratch->matrix, &scratch->scale);
        } else {
            setVector(&scratch->scale, actor->unk183C, actor->unk183C, actor->unk183C);
            func_800B396C(&scratch->matrix, &scratch->scale);
        }
    }

    if (actor->unk0.unk2C != ONE || actor->unk0.unk2E != ONE
        || actor->unk0.unk30 != ONE) {
        setVector(
            &scratch->scale, actor->unk0.unk2E, actor->unk0.unk30, actor->unk0.unk2C);
        func_800B396C(&scratch->matrix, &scratch->scale);
    }

    D_800F3C58.bones[0] = scratch->matrix;
    D_800F2458.boneScale[0].vx = scratch->scale.vx = actor->unk704.unk150[0].vx;
    D_800F2458.boneScale[0].vy = scratch->scale.vy = actor->unk704.unk150[0].vy;
    D_800F2458.boneScale[0].vz = scratch->scale.vz = actor->unk704.unk150[0].vz;

    if (scratch->scale.vx != 64 || scratch->scale.vy != 64 || scratch->scale.vz != 64) {
        applyVector(&scratch->scale, 6, 6, 6, <<=);
        func_800B396C(&scratch->matrix, &scratch->scale);
    }

    actor->bones[0] = scratch->matrix;
    scratch->position.vx = scratch->position.vy = 0;

    for (i = 1; i < actor->unk0.nBones; ++i) {
        temp = scratch->model->armatures[i].unkC;

        if (temp != 0) {
            func_800B26B8(actor, camera, i, temp);
        } else {
            int parent = scratch->model->armatures[i].unk4;
            scratch->parent = &actor->bones[parent];
            gte_SetRotMatrix(scratch->parent);
            gte_SetTransMatrix(scratch->parent);
            setVector(&scratch->position, -scratch->model->armatures[parent].unk0, 0, 0);
            gte_ldv0(&scratch->position);
            gte_rtv0tr2();
            setVector(&scratch->rotation, actor->unk704.unk0[i].vx >> 1,
                actor->unk704.unk0[i].vy >> 1, actor->unk704.unk0[i].vz >> 1);
            temp = (scratch->model->armatures + i)->unk8;

            switch (temp) {
            case 0:
                break;
            case 1:
                scratch->rotation.vx -= scratch->unk3A >> 1;
                scratch->rotation.vz += scratch->unk3A >> 3;
                break;
            case 2:
                scratch->rotation.vx -= scratch->unk3A >> 1;
                scratch->rotation.vy -= scratch->unk3A >> 1;
                scratch->rotation.vz += scratch->unk3A >> 3;

                if (scratch->unk3A != 0) {
                    scratch->rotation.vy += scratch->unk3C >> 3;
                } else {
                    scratch->rotation.vy -= scratch->unk3C >> 3;
                }

                scratch->rotation.vz += scratch->unk3C >> 2;
                break;
            case 3:
            case 4:
            case 5:
            case 6:
                if (actor->unk0.freeze) {
                    u_short* p = actor->unk1880[temp - 3];

                    p[1] += p[0];
                    scratch->rotation.vx = p[1];
                }
                break;
            case 7: {
                s2 = ((vs_scratch_t*)0x1F800000);
                setVector(&scratch->rotation, s2->camera.angles.vx,
                    s2->camera.angles.vy - 0x400, s2->camera.angles.vz);
            }
            case 8:
            case 9: {
                int dx, dz, yaw;
                s2 = ((vs_scratch_t*)0x1F800000);
                dx = s2->camera.position.vx / ONE - scratch->offset.vx;
                dz = s2->camera.position.vz / ONE - scratch->offset.vz;

                if (dx == 0 && dz == 0) {
                    yaw = 0;
                } else {
                    yaw = -ratan2(dz, dx) & 0xFFF;
                }
                scratch->rotation.vy = yaw;

                if (temp == 8) {
                    dx = s2->camera.position.vx / ONE - scratch->offset.vx;
                    dz = s2->camera.position.vz / ONE - scratch->offset.vz;
                    dx *= dx;

                    if (dx < 0) {
                        dx = -dx;
                    }

                    dz *= dz;
                    dz = ABS(dz);

                    dx = vs_gte_rsqrt(dx + dz);
                    {
                        int dy = s2->camera.position.vy / ONE;
                        dy -= scratch->offset.vy;
                        scratch->rotation.vz = ratan2(dy, dx) & 0xFFF;
                    }
                } else {
                    scratch->rotation.vz = 0;
                }
                break;
            }
            }

            gte_stlvnl(scratch->matrix.t);
            *(int*)&scratch->rotation &= 0x0FFF0FFF;
            *(int*)&scratch->rotation.vz &= 0xFFF;

            if (temp >= 7) {
                RotMatrixYXZ_gte(&scratch->rotation, &scratch->matrix);
                func_800B196C(camera, &scratch->matrix);
                setVector(
                    &scratch->scale, actor->unk183C, actor->unk183C, actor->unk183C);
                func_800B396C(&scratch->matrix, &scratch->scale);
                setVector(&scratch->scale, actor->unk0.unk2E, actor->unk0.unk30,
                    actor->unk0.unk2C);
                func_800B396C(&scratch->matrix, &scratch->scale);
            } else {
                func_800B17F0(&scratch->rotation, &scratch->matrix);
                func_800B196C(D_800F2458.bones + parent, &scratch->matrix);
            }

            if (*(int*)&actor->unk704.unk150[i] == 0x400040
                && actor->unk704.unk150[i].vz == 0x40) {
                D_800F2458.boneScale[i].vx = scratch->scale.vx =
                    D_800F2458.boneScale[parent].vx;
                D_800F2458.boneScale[i].vy = scratch->scale.vy =
                    D_800F2458.boneScale[parent].vy;
                scratch->scale.vz = D_800F2458.boneScale[parent].vz;
                D_800F2458.boneScale[i].vz = scratch->scale.vz;
            } else {
                scratch->scale.vx = D_800F2458.boneScale[parent].vx;
                scratch->scale.vy = D_800F2458.boneScale[parent].vy;
                scratch->scale.vz = D_800F2458.boneScale[parent].vz;
                applyVector(&scratch->scale, actor->unk704.unk150[i].vx,
                    actor->unk704.unk150[i].vy, actor->unk704.unk150[i].vz, *=);
                applyVector(&scratch->scale, 6, 6, 6, >>=);
                D_800F2458.boneScale[i].vx = scratch->scale.vx;
                D_800F2458.boneScale[i].vy = scratch->scale.vy;
                D_800F2458.boneScale[i].vz = scratch->scale.vz;
            }

            *(D_800F2458.bones + i) = scratch->matrix;

            if (scratch->scale.vx != 64 || scratch->scale.vy != 64
                || scratch->scale.vz != 64) {
                applyVector(&scratch->scale, 6, 6, 6, <<=);
                func_800B396C(&scratch->matrix, &scratch->scale);
            }

            actor->bones[i] = scratch->matrix;
        }
    }

    if (actor->unk0.visible
        && (actor->unk0.position.vy < 0x100
            || (actor->unk0.unkF != 0 && func_800BEB00() == 4))) {
        D_800F4538_t* visual;
        int detailed;

        header = *(func_800B28A8_t*)actor;
        visual = actor;

        if (mode < 2) {
            scratch->model = actor->unk0.unk68;
            scratch->clut = actor->unk6E8;
            scratch->unk38 = actor->unk6EA;
            scratch->tpage = D_800F46A8[actor->unk5BB].tpage;
        } else {
            *(func_800B28A8_t*)actor = *(func_800B28A8_t*)D_800F4538[mode];
            scratch->model = D_800F4538[mode]->unk0.unk68;
            scratch->clut = D_800F4538[mode]->unk6E8;
            scratch->unk38 = D_800F4538[mode]->unk6EA;
            scratch->tpage = D_800F46A8[D_800F4538[mode]->unk5BB].tpage;
            visual = D_800F4538[mode];
        }

        if (func_800B3A68(actor, actor->bones, -vs_main_nearClip * 4, scratch->model)
            == 0) {
            actor->unk0.unk9_4 = 1;
        } else {
            detailed = 0;
            actor->unk0.unk9_4 = 0;

            if (D_800E8FC0 != 0 || visual->unk0.unk64.unk0 != 0) {
                detailed = 1;
            }

            if ((u_int)(visual->unk0.unk9_0 - 4) < 5 && visual->unk0.unk9_0 != 6) {
                detailed = 1;
            }

            if (visual->unk0.unk9_0 == 0xF) {
                detailed = 1;
            }

            if (!actor->unk0.unk8_3) {
                if (mode == 1) {
                    func_800B3CF0(&D_800F2458, actor, &actor->unk6F8, scratch->model);
                } else {
                    if (!actor->unk5AC_8) {
                        if (actor->unk648_16) {
                            temp = actor->unk0.position.vz;
                            temp <<= 16;
                            func_8008C458(temp | actor->unk0.position.vx,
                                actor->unk0.currentTile.y, &actor->unk0.unk58,
                                &scratch->offset);
                        } else {
                            actor->unk0.unk58.unk0 = 0x80;
                            actor->unk0.unk58.unk1 = 0x80;
                            actor->unk0.unk58.unk2 = 0x80;
                        }
                    }

                    if (visual->unk0.unk9_0 < 4) {
                        temp = actor->unk0.unk58.unk0;
                        ((u_char*)&visual->unk1864)[0] = temp;
                        temp += (signed char)visual->unk6F2 * 4;

                        if (temp < 0) {
                            temp = 0;
                        }

                        if (temp >= 0x100) {
                            temp = 0xFF;
                        }

                        visual->unk0.unk54.r = temp;
                        temp = actor->unk0.unk58.unk1;
                        ((u_char*)&visual->unk1864)[1] = temp;
                        temp += (signed char)visual->unk6F1 * 4;

                        if (temp < 0) {
                            temp = 0;
                        }

                        if (temp >= 0x100) {
                            temp = 0xFF;
                        }

                        visual->unk0.unk54.g = temp;
                        temp = actor->unk0.unk58.unk2;
                        ((u_char*)&visual->unk1864)[2] = temp;
                        temp += (signed char)visual->unk6F0 * 4;

                        if (temp < 0) {
                            temp = 0;
                        }

                        if (temp >= 0x100) {
                            temp = 0xFF;
                        }

                        visual->unk0.unk54.b = temp;
                    }

                    if (detailed != 0) {
                        func_800B516C(
                            &D_800F2458, actor, &visual->unk0.unk54, scratch->model);
                    } else {
                        func_800B3CF0(
                            &D_800F2458, actor, &visual->unk0.unk54, scratch->model);
                    }
                }
            } else {
                if (actor->unk0.unk9_0 < 4) {
                    temp = scratch->offset.vz;
                    temp <<= 16;
                    func_8008C458(temp | scratch->offset.vx, actor->unk0.currentTile.y,
                        &scratch->unk0[0x30], &actor->unk0.position);
                    {
                        int color;

                        color = scratch->unk0[0x30];
                        temp = (color >> 1) + 0x40;
                        ((u_char*)&actor->unk1864)[0] = temp;
                        color = scratch->unk0[0x31];
                        temp = (color >> 1) + 0x40;
                        ((u_char*)&actor->unk1864)[1] = temp;
                        color = scratch->unk0[0x32];
                        temp = (color >> 1) + 0x40;
                        ((u_char*)&actor->unk1864)[2] = temp;
                    }
                }

                if (detailed != 0) {
                    func_800B5C30(&D_800F2458, actor, &actor->unk0.unk54, scratch->model);
                } else {
                    func_800B4594(&D_800F2458, actor, &actor->unk0.unk54, scratch->model);
                }
            }
        }

        if (mode == 0 && actor->unk0.unk9_7) {
            func_800B4B14(actor);
        }

        *(func_800B28A8_t*)actor = header;
    }
}
