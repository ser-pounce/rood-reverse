#include "common.h"
#include "40564.h"
#include "3A1A0.h"
#include <abs.h>

void func_8007A824(DR_MOVE*);
int func_800A6EE8(SVECTOR*, int, int, int);
void func_800AA698(int arg0, SVECTOR* arg1, int arg2);
void func_800AA984(int, short, int);
void func_800AAA88(int arg0, SVECTOR* arg1, int arg2);
void func_800AA290(int, func_8006EBF8_t_fields*, int, int);
void func_800AA490(int, func_8006EBF8_t_fields*, int, int);
void func_800AB098(D_800F4538_t*, int, int);

extern u_char D_800E8F2C;

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/40564", func_800A8D64);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/40564", func_800A8E84);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/40564", func_800A8FD4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/40564", func_800A91DC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/40564", func_800A92B8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/40564", func_800A9378);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/40564", func_800A9530);

void func_800A97EC(int arg0, func_8006EBF8_t_fields* arg1, int arg2, int arg3)
{
    int angle;

    D_800F4538_t* actor = D_800F4538[arg0];

    if (arg2 == 0 && arg3 == 0) {

        func_800AA290(arg0, arg1, -1, 0);

        angle = arg1->unk0_24;
        angle <<= 4;
        angle %= ONE;
        angle -= actor->unk0.facing;

        func_800AA984(arg0, (short)angle, 0);

        actor->unk5AC_0 = 0;
        actor->unk0.currentTileX = arg1->unk0_0;
        actor->unk0.unk5D = arg1->unk0_8;
        actor->unk0.currentTileZ = arg1->unk0_16;
    } else {
        if (arg3 == -1) {
            actor->unk5C6 = actor->unk5C0;
        } else {
            actor->unk5C6 = arg3;
        }

        if (arg2 == -1) {
            actor->unk5C4 = actor->unk5C2;
        } else {
            actor->unk5C4 = arg2;
        }

        func_800AA490(arg0, arg1, -1, actor->unk5C6);

        actor->unk5EC.vx = (arg1->unk0_0 * 128) + 64;
        actor->unk5EC.vz = (arg1->unk0_16 * 128) + 64;
        actor->unk5EC.vy = func_800A6EE8(&actor->unk5EC, 0, 0, 1);
        angle = 0x8000;

        if (arg1->unk0_24 == 0xFF) {
            actor->unk5EC.pad = angle;
        } else {
            actor->unk5EC.pad = arg1->unk0_24 * 16;
        }

        actor->unk5AC_0 = 1;
        actor->unk5AC_2 = 0;
    }
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/40564", func_800A9988);

void func_800A9C54(int arg0, func_8006EBF8_t_fields* arg1, int arg2)
{
    D_800F4538_t* temp_s0 = D_800F4538[arg0];

    if (arg2 == -1) {
        func_800AA290(arg0, arg1, -1, temp_s0->unk5C2);
    } else {
        func_800AA290(arg0, arg1, -1, arg2);
    }

    temp_s0->unk0.currentTileX = arg1->unk0_0;
    temp_s0->unk0.unk5D = arg1->unk0_8;
    temp_s0->unk0.currentTileZ = arg1->unk0_16;
}

void func_800A9CDC(int arg0, func_8006EBF8_t_fields* arg1, int arg2)
{
    D_800F4538_t* new_var = D_800F4538[arg0];

    if (arg2 == -1) {
        func_800AA490(arg0, arg1, -1, new_var->unk5C0);
    } else {
        func_800AA490(arg0, arg1, -1, arg2);
    }
}

void func_800A9D24(int arg0, SVECTOR* arg1, int arg2)
{
    u_short temp_s0;
    D_800F4538_t* temp_s1 = D_800F4538[arg0];

    if (arg2 == -1) {
        func_800AA698(arg0, arg1, -1);
        return;
    }

    temp_s0 = temp_s1->unk5C2;
    temp_s1->unk5C2 = arg2;

    func_800AA698(arg0, arg1, -1);

    temp_s1->unk5C2 = temp_s0;
}

void func_800A9D90(int arg0, SVECTOR* arg1, int arg2)
{
    SVECTOR sp10;
    u_short temp_s0;
    D_800F4538_t* temp_s1 = D_800F4538[arg0];

    sp10.vx = arg1->vx - temp_s1->unk0.position.vx;
    sp10.vy = arg1->vy - temp_s1->unk0.position.vy;
    sp10.vz = arg1->vz - temp_s1->unk0.position.vz;

    if (arg2 == -1) {
        func_800AA698(arg0, &sp10, -1);
        return;
    }

    temp_s0 = temp_s1->unk5C2;
    temp_s1->unk5C2 = arg2;

    func_800AA698(arg0, &sp10, -1);

    temp_s1->unk5C2 = temp_s0;
}

void func_800A9E38(int arg0, int arg1, int arg2)
{
    u_short temp_s0;
    D_800F4538_t* temp_s1 = D_800F4538[arg0];

    if (arg2 == -1) {
        func_800AA984(arg0, arg1, -1);
        return;
    }

    temp_s0 = temp_s1->unk5C0;
    temp_s1->unk5C0 = arg2;

    func_800AA984(arg0, arg1, -1);

    temp_s1->unk5C0 = temp_s0;
}

void func_800A9EB4(int arg0, short arg1, int arg2)
{
    u_short temp_s0;
    D_800F4538_t* temp_s1 = D_800F4538[arg0];

    arg1 -= temp_s1->unk0.facing;

    if (arg1 > ONE / 2) {
        arg1 -= ONE;
    }

    if (arg1 < -ONE / 2) {
        arg1 += ONE;
    }

    if (arg2 == -1) {
        func_800AA984(arg0, arg1, -1);
        return;
    }

    temp_s0 = temp_s1->unk5C0;
    temp_s1->unk5C0 = arg2;

    func_800AA984(arg0, arg1, -1);

    temp_s1->unk5C0 = temp_s0;
}

void func_800A9F64(int arg0, SVECTOR* arg1, int arg2)
{
    u_short temp_s0;

    D_800F4538_t* temp_s1 = D_800F4538[arg0];

    if (arg2 == -1) {
        func_800AAA88(arg0, arg1, -1);
        return;
    }

    temp_s0 = temp_s1->unk5C0;
    temp_s1->unk5C0 = arg2;

    func_800AAA88(arg0, arg1, -1);

    temp_s1->unk5C0 = temp_s0;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/40564", func_800A9FD0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/40564", func_800AA108);

void func_800AA218(int arg0, func_8006EBF8_t_fields* arg1, int arg2)
{
    D_800F4538_t* temp_s0 = D_800F4538[arg0];

    if (temp_s0 != NULL) {
        func_800AA290(arg0, arg1, arg2, temp_s0->unk5C2);
        temp_s0->unk0.currentTileX = arg1->unk0_0;
        temp_s0->unk0.unk5D = arg1->unk0_8;
        temp_s0->unk0.currentTileZ = arg1->unk0_16;
    }
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/40564", func_800AA290);

void func_800AA454(int arg0, func_8006EBF8_t_fields* arg1, int arg2)
{
    func_800AA490(arg0, arg1, arg2, D_800F4538[arg0]->unk5C0);
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/40564", func_800AA490);

void func_800AA600(int arg0, SVECTOR* arg1, int arg2) { func_800AA698(arg0, arg1, arg2); }

void func_800AA620(int arg0, SVECTOR* arg1, int arg2)
{
    SVECTOR sp10;
    D_800F4538_t* temp_a3 = D_800F4538[arg0];

    if (temp_a3 != NULL) {
        sp10.vx = arg1->vx - temp_a3->unk0.position.vx;
        sp10.vy = arg1->vy - temp_a3->unk0.position.vy;
        sp10.vz = arg1->vz - temp_a3->unk0.position.vz;

        func_800AA698(arg0, &sp10, arg2);
    }
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/40564", func_800AA698);

void func_800AA82C(int arg0, short arg1, int arg2) { func_800AA984(arg0, arg1, arg2); }

void func_800AA850(int arg0, u_short arg1, int arg2)
{
    short temp_a1;
    short var_v1;
    D_800F4538_t* temp_v0 = D_800F4538[arg0];

    if (temp_v0 == NULL) {
        return;
    }

    temp_a1 = arg1 - temp_v0->unk0.facing;
    var_v1 = temp_a1;

    if (temp_a1 > ONE / 2) {
        var_v1 = temp_a1 - ONE;
    }

    if (var_v1 < -ONE / 2) {
        var_v1 += ONE;
    }

    func_800AA984(arg0, var_v1, arg2);
}

void func_800AA8D0(int arg0, short arg1, int arg2)
{
    int arg2_2;
    int var_v0;
    D_800F4538_t* temp_v0 = D_800F4538[arg0];

    if (temp_v0 == NULL) {
        return;
    }

    arg1 -= temp_v0->unk0.facing;

    if (arg1 > ONE / 2) {
        arg1 -= ONE;
    }

    if (arg1 < -ONE / 2) {
        arg1 += ONE;
    }

    var_v0 = arg1;

    var_v0 = ABS(var_v0);
    arg2 = ABS(arg2);

    arg2_2 = var_v0 / arg2;

    if ((var_v0 % arg2) != 0) {
        ++arg2_2;
    }

    func_800AA984(arg0, arg1, arg2_2);
}

void func_800AA984(int arg0, short arg1, int arg2)
{
    int m;
    D_800F4538_t* a = D_800F4538[arg0];

    if (a == NULL) {
        return;
    }

    m = arg1;
    a->unk0.unk3E = m;
    a->unk0.unk3C = 0;
    a->unk0.unk40 = 0;

    if (arg2 == 0) {
        short sum;
        a->unk0.unk18 = 0;
    recenter:
        sum = (u_short)a->unk0.facing + a->unk0.unk3E;
        a->unk0.facing = sum;
        a->unk0.facing = sum % ONE;
    } else if (arg2 == -1) {
        int speed;

        if (m < 0) {
            m = -m;
        }

        speed = m * a->unk5C0;
        a->unk0.unk18 = speed / ONE;

        if (speed & 0xFFF) {
            a->unk0.unk18 = (speed / ONE) + 1;
        }

        if (a->unk0.unk18 != 0) {
            return;
        }

        goto recenter;

    } else {
        a->unk0.unk18 = arg2;
    }
}

void func_800AAA68(int arg0, SVECTOR* arg1, int arg2) { func_800AAA88(arg0, arg1, arg2); }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/40564", func_800AAA88);

void func_800AABD0(int arg0, SVECTOR* arg1, int arg2)
{
    D_800F4538_t* temp_a3 = D_800F4538[arg0];

    if (temp_a3 != NULL) {

        if (arg2 == 0) {
            temp_a3->unk5C8 = 0;
            temp_a3->unk0.unk2C = arg1->vx;
            temp_a3->unk0.unk2E = arg1->vy;
            temp_a3->unk0.unk30 = arg1->vz;
            return;
        }

        temp_a3->unk0.unk44.vx = arg1->vx - temp_a3->unk0.unk2C;
        temp_a3->unk0.unk44.vy = arg1->vy - temp_a3->unk0.unk2E;
        temp_a3->unk0.unk44.vz = arg1->vz - temp_a3->unk0.unk30;

        if ((*(int*)&temp_a3->unk0.unk44 == 0)
            && ((temp_a3->unk0.unk44.vz << 0x10) == 0)) {
            temp_a3->unk5C8 = 0;
            return;
        }

        temp_a3->unk5C8 = arg2;
    }
}

void func_800AAC80(RECT* arg0, int arg1, int arg2)
{
    DR_MOVE* drMove = *(DR_MOVE**)0x1F800000;
    SetDrawMove(drMove, arg0, arg1, arg2);
    func_8007A824(drMove);
    *(DR_MOVE**)0x1F800000 = drMove + 1;
}

void func_800AACDC(void)
{
    void* new_var;
    RECT sp10;
    DR_MOVE* temp_s0;

    sp10.x = 470;
    sp10.y = 384;
    sp10.w = 18;
    sp10.h = 36;

    new_var = (void*)0x1F800000;
    temp_s0 = *((DR_MOVE**)0x1F800000);
    new_var = (void*)0x10;

    SetDrawMove(temp_s0, &sp10, 16, 400);
    func_8007A824(temp_s0);

    *((void**)0x1F800000) = (DR_MOVE*)(temp_s0 + 1);
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/40564", func_800AAD4C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/40564", func_800AAE9C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/40564", func_800AB098);

void func_800AB2AC(int arg0)
{

    if (arg0 == D_800E8F2C) {
        int i;

        for (i = 0; i < 17; ++i) {
            D_800F4538_t* temp_s0 = D_800F4538[i];
            if ((temp_s0 != NULL) && (temp_s0->unk183E[arg0] != 0xFF)) {
                func_800AB098(temp_s0, 0, 0);
                func_800AB098(temp_s0, 1, 0);
            }
        }
    }
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/40564", func_800AB358);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/40564", func_800AB4F0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/40564", func_800AB788);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/40564", func_800AB9A4);

int func_800AC0D4(u_char* arg0, u_char* arg1, int arg2)
{
    int i;
    int var_t0 = 0;

    for (i = 0; i < 3; ++i) {
        if (arg2 < 0) {
            if (*arg1 < *arg0) {
                var_t0 = 1;
                *arg0 += arg2;
                if (*arg0 < *arg1) {
                    *arg0 = *arg1;
                }
            }
        } else {
            if (*arg0 < *arg1) {
                var_t0 = 1;
                *arg0 += arg2;
                if (*arg1 < *arg0) {
                    *arg0 = *arg1;
                }
            }
        }
        ++arg0;
        ++arg1;
    }

    return var_t0;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/40564", func_800AC168);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/40564", func_800AC37C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/40564", func_800AC440);

void func_800AC500(D_800F4538_t* arg0)
{
    int i;

    arg0->unk18D0 = 0;
    arg0->unk18D1 = 0;

    for (i = 0; i < arg0->unk0.nBones; ++i) {
        arg0->unk0.unk68->armatures[i].unkC = 0;
    }
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/40564", func_800AC540);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/40564", func_800AC690);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/40564", func_800ACF54);

void func_800ACFA0(short* arg0, u_char* arg1, int arg2)
{
    int a3;
    a3 = arg1[0];
    a3 <<= 8;
    a3 |= arg1[1];
    a3 *= 2;
    arg0[0] = a3;

    a3 = arg1[2];
    a3 <<= 8;
    a3 |= arg1[3];
    a3 *= 2;
    arg0[1] = a3;

    a3 = arg1[4];
    a3 <<= 8;
    a3 |= arg1[5];
    a3 *= 2;
    arg0[2] = a3;

    arg0[3] = 6;

    if (arg2 != 0xFF) {
        arg0[3] = 0;
    }

    arg0[339] = 0;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/40564", func_800AD008);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/40564", func_800AD494);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/40564", func_800AD62C);
