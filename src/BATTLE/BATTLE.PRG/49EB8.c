#include "common.h"
#include "49EB8.h"
#include "30DB0.h"
#include "44F14.h"
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
void func_800B396C(MATRIX*, VECTOR*);
int func_800B3A68(void*, MATRIX*, int, void*);
void func_800B3CF0(D_800F2458_t*, void*, void*, void*);
void func_800B4594(D_800F2458_t*, void*, void*, void*);
void func_800B4B14(void*);
void func_800B516C(D_800F2458_t*, void*, void*, void*);
void func_800B5C30(D_800F2458_t*, void*, void*, void*);

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

__asm__(".set push;"
        ".set noreorder;"
        "glabel func_800B396C;"
        "lw         $t0, 0x0($a0);"
        "lw         $t1, 0x4($a0);"
        "lw         $t2, 0x8($a0);"
        "lw         $t3, 0xC($a0);"
        "lw         $t4, 0x0($a1);"
        "sll        $t7, $t0, 16;"
        "sra        $t7, 16;"
        "sra        $t8, $t1, 16;"
        "sll        $t9, $t3, 16;"
        "sra        $t9, 16;"
        "mtc2       $t4, $8;"
        "mtc2       $t7, $9;"
        "mtc2       $t8, $10;"
        "mtc2       $t9, $11;"
        "sra        $t7, $t0, 16;"
        "sra        $t9, $t3, 16;"
        "gpf        1;"
        "lw         $t5, 0x4($a1);"
        "sll        $t8, $t2, 16;"
        "sra        $t8, 16;"
        "addu       $v0, $zero, $a0;"
        "mfc2       $v1, $9;"
        "mfc2       $a2, $10;"
        "mfc2       $a3, $11;"
        "mtc2       $t5, $8;"
        "mtc2       $t7, $9;"
        "mtc2       $t8, $10;"
        "mtc2       $t9, $11;"
        "sll        $t7, $t1, 16;"
        "sra        $t7, 16;"
        "gpf        1;"
        "lh         $t4, 0x10($a0);"
        "lw         $t6, 0x8($a1);"
        "sra        $t8, $t2, 16;"
        "and        $v1, 0xFFFF;"
        "and        $a3, 0xFFFF;"
        "mfc2       $t1, $9;"
        "mfc2       $t2, $10;"
        "mfc2       $t3, $11;"
        "mtc2       $t6, $8;"
        "mtc2       $t7, $9;"
        "mtc2       $t8, $10;"
        "mtc2       $t4, $11;"
        "sll        $a2, 16;"
        "sll        $t1, 16;"
        "gpf        1;"
        "and        $t2, 0xFFFF;"
        "sll        $t3, 16;"
        "or         $t1, $v1;"
        "sw         $t1, 0x0($v0);"
        "or         $t3, $a3;"
        "mfc2       $t4, $9;"
        "mfc2       $t5, $10;"
        "mfc2       $t6, $11;"
        "and        $t4, 0xFFFF;"
        "or         $t4, $a2;"
        "sll        $t5, 16;"
        "or         $t5, $t2;"
        "sw         $t4, 0x4($v0);"
        "sw         $t5, 0x8($v0);"
        "sw         $t3, 0xC($v0);"
        "j          $ra;"
        "sh         $t6, 0x10($v0);"
        "endlabel func_800B396C;"
        ".set pop;");

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/49EB8", func_800B3A68);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/49EB8", func_800B3CF0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/49EB8", func_800B4594);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/49EB8", func_800B4B14);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/49EB8", func_800B516C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/49EB8", func_800B5C30);

__asm__(".set push;"
        ".set noreorder;"
        "glabel func_800B63AC;"
        "la         $v0, D_800F4538;"
        "sll        $v1, $a0, 2;"
        "addu       $v0, $v1;"
        "lw         $v0, 0x0($v0);"
        "nop;"
        "lb         $v1, 0xA($v0);"
        "lb         $t1, 0x5B0($v0);"
        "and        $t0, $v1, 0x40;"
        "bnez       $t0, .L800B6424;"
        "and        $t0, $v1, 0x20;"
        "bnez       $t0, .L800B6454;"
        "and        $t1, 0xFC;"
        "or         $t1, 0x1;"
        "sb         $t1, 0x5B0($v0);"
        ".L800B63E8:"
        "addu       $sp, -0x4;"
        "sw         $ra, 0x0($sp);"
        "jal        func_800A208C;"
        "addu       $a0, $v0, $zero;"
        "lw         $ra, 0x0($sp);"
        "addu       $sp, 0x4;"
        "jr         $ra;"
        "endlabel func_800B63AC;"
        ".set pop");

__asm__(".set push;"
        ".set reorder;"
        "glabel func_800B6404;"
        "la         $v0, D_800F4538;"
        "sll        $v1, $a0, 2;"
        "addu       $v0, $v1;"
        "lw         $v0, 0x0($v0);"
        "lb         $v1, 0xA($v0);"
        ".L800B6424:"
        "and        $v1, 0x9F;"
        "or         $v1, 0x40;"
        "sb         $v1, 0xA($v0);"
        ".set nomove;"
        "j          .L800B63E8;"
        "endlabel func_800B6404;"
        ".set pop");

void func_800B6438(int arg0, int* arg1, int arg2, int arg3)
{
    __asm__("la         $v0, D_800F4538;"
            "sll        $v1, $a0, 2;"
            "addu       $v0, $v1;"
            "lw         $v0, 0x0($v0);"
            "nop;"
            "lb         $v1, 0xA($v0);"
            ".L800B6454:"
            "addu       $sp, -0x14;"
            "sw         $v0, 0x0($sp);"
            "sw         $a1, 0x4($sp);"
            "sw         $a2, 0x8($sp);"
            "sw         $a3, 0xC($sp);"
            "sw         $ra, 0x10($sp);"
            "or         $v1, 0x60;"
            "sb         $v1, 0xA($v0);"
            "or         $a1, $zero, 0x1F;"
            "addu       $a2, $zero, $zero;"
            "jal        func_800A0204;"
            "or         $a3, $zero, 0x8;"
            "lw         $a0, 0x0($sp);"
            "lw         $a1, 0x4($sp);"
            "lw         $a2, 0x8($sp);"
            "jal        func_800A208C;"
            "lw         $a3, 0xC($sp);"
            "lw         $ra, 0x10($sp);"
            "addu       $sp, 0x14;");
}

__asm__(".set push;"
        ".set noreorder;"
        "glabel func_800B64A8;"
        "addu       $sp, -0x4;"
        "sw         $ra, 0x0($sp);"
        "jal        func_800B64CC;"
        "addu       $a3, $a1, $zero;"
        "or         $v1, $zero, 0x0;"
        "sb         $v1, 0x1848($v0);"
        "lw         $ra, 0x0($sp);"
        "addu       $sp, 0x4;"
        "j          $ra;"
        "endlabel func_800B64A8;"
        ".set pop");

void func_800B64CC(int arg0, int arg1, int arg2, int arg3)
{
    __asm__("la         $v0, D_800F4538;"
            "sll        $v1, %0, 2;"
            "addu       $v0, $v1;"
            "lw         $v0, 0x0($v0);"
            "or         $v1, $zero, 0x1;"
            "sll        $t0, %3, 16;"
            "or         $t0, %1;"
            "sw         $t0, 0x184C($v0);"
            "sw         %2, 0x1850($v0);"
            ".L800B64F4:"
            "sw         $v1, 0x1848($v0);"
        :
        : "r"(arg0), "r"(arg1), "r"(arg2), "r"(arg3));
}

__asm__("glabel func_800B6500;"
        "la         $v0, D_800F4538;"
        "sll        $v1, $a0, 2;"
        "addu       $v0, $v1;"
        "lw         $v0, 0x0($v0);"
        "lw         $t2, 0x0($a1);"
        "lw         $t3, 0x4($a1);"
        "sw         $t2, 0x1858($v0);"
        "sw         $t3, 0x185C($v0);"
        "lb         $t1, 0xA($v0);"
        "j          .L800B64F4;"
        "or         $v1, $zero, 0x2;"
        "endlabel func_800B6500;");

__asm__("glabel func_800B6530;"
        "ori     $t4, $zero, 0x4;"
        "j       .L800B6540;"
        "addu    $a3, $a2, $zero;"
        "endlabel func_800B6530;");

__asm__(".set push;"
        ".set noreorder;"
        "glabel func_800B653C;"
        "ori        $t4, $zero, 0x3;"
        ".L800B6540:"
        "la         $v0, D_800F4538;"
        "sll        $v1, $a0, 2;"
        "addu       $v0, $v1;"
        "lw         $v0, 0x0($v0);"
        "lw         $t2, 0x0($a1);"
        "lw         $t3, 0x4($a1);"
        "sw         $a2, 0x1850($v0);"
        "lb         $t1, 0xA($v0);"
        "sh         $a3, 0x184E($v0);"
        "sw         $t2, 0x1858($v0);"
        "sw         $t3, 0x185C($v0);"
        "or         $t1, 0x20;"
        "sb         $t1, 0xA($v0);"
        "sw         $t4, 0x1848($v0);"
        "j          $ra;"
        "endlabel func_800B653C;"
        ".set pop;");

__asm__(".set push;"
        ".set noreorder;"
        "glabel func_800B6580;"
        "la         $v0, D_800F4538;"
        "sll        $v1, $a0, 2;"
        "addu       $v0, $v1;"
        "lw         $v0, 0x0($v0);"
        "lw         $t2, 0x0($a1);"
        "lb         $t1, 0xB($v0);"
        "sll        $t0, $a2, 16;"
        "and        $t1, 0xF;"
        "bnez       $t1, .L800B65E4;"
        "or         $t1, 0x1;"
        "lbu        $a0, 0x17FD($v0);"
        "sh         $zero, 0x1A($v0);"
        "sw         $t2, 0x5EC($v0);"
        "sw         $t0, 0x5F0($v0);"
        "sb         $t1, 0xB($v0);"
        "slt        $t3, $a0, 0x2;"
        "bnez       $t3, .L800B65E4;"
        ".nop;"
        "addu       $sp, -0x4;"
        "sw         $ra, 0x0($sp);"
        "jal        func_800B6580;"
        ".nop;"
        "lw         $ra, 0x0($sp);"
        "addu       $sp, 0x4;"
        ".L800B65E4:"
        "jr         $ra;"
        "endlabel func_800B6580;"
        ".set pop;");

__asm__(".set push;"
        ".set noreorder;"
        "glabel func_800B65E8;"
        "ori     $t1,$zero,0x10;"
        "j       .L800B65F8;"
        ".nop;"
        "endlabel func_800B65E8;"
        ".set pop;");

__asm__(".set push;"
        ".set noreorder;"
        "glabel func_800B65F4;"
        "ori        $t1, $zero, 0x40;"
        ".L800B65F8:"
        "la         $v0, D_800F4538;"
        "sll        $v1, $a0, 2;"
        "addu       $v0, $v0, $v1;"
        "lw         $v0, 0x0($v0);"
        "lw         $t2, 0x0($a1);"
        "lw         $t3, 0x4($a1);"
        "lb         $t4, 0xB($v0);"
        "sw         $t2, 0x5EC($v0);"
        "sw         $t3, 0x5F0($v0);"
        "sh         $a2, 0x5F2($v0);"
        "and        $t4, 0x8F;"
        "or         $t1, $t4, $t1;"
        "sb         $t1, 0xB($v0);"
        "j          $ra;"
        "endlabel func_800B65F4;"
        ".set pop;");

void func_800B6634(int arg0, int arg1)
{
    __asm__("la         $v0, D_800F4538;"
            "sll        $v1, $a0, 2;"
            "addu       $v0, $v1;"
            "lw         $v0, 0x0($v0);"
            "addu       $sp, -0xC;"
            "lhu        $t0, 0x63C($v0);"
            "sw         $ra, 0x0($sp);"
            "or         $a2, $zero, 0x80;"
            "sltu       $t0, 0x80;"
            "beqz       $t0, .L800B6668;"
            "sw         $a0, 0x4($sp);"
            "or         $a2, $zero, 0x20;"
            ".L800B6668:"
            "jal        func_800A9EB4;"
            "sw         $a1, 0x8($sp);"
            ".L800B6670:"
            "lw         $a0, 0x4($sp);"
            "jal        func_800A249C;"
            "lw         $a1, 0x8($sp);"
            "lw         $ra, 0x0($sp);"
            "addu       $sp, 0xC;");
}

__asm__(".set push;"
        ".set reorder;"
        "glabel func_800B668C;"
        "addu       $sp, -0xC;"
        "sw         $ra, 0x0($sp);"
        "sw         $a0, 0x4($sp);"
        "sw         $a1, 0x8($sp);"
        "jal        func_800AA8D0;"
        "j          .L800B6670;"
        "endlabel func_800B668C;"
        ".set pop;");
