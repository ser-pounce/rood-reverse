#include "common.h"
#include <rand.h>
#include "146C.h"
#include "3A1A0.h"
#include "44F14.h"
#include "../../SLUS_010.40/main.h"

u_char** func_800AD494(D_800F4538_t*, u_char, u_short**);
void func_800AD714(D_800F4538_t*, D_800F4538_unkC54*, int, u_char*);
void func_800AF844(D_800F4538_unkC54*, D_800F4538_unkC54*, int);
void func_800B147C(D_800F4538_unkC54*, D_800F4538_unkC54*, int, int, int);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/44F14", func_800AD714);

void func_800AE46C(void) { }

void func_800AE474(void) { }

void func_800AE47C(D_800F4538_t* arg0)
{
    u_short* sp10;
    int var_v1;
    void* var_a3;

    u_char** v0 = func_800AD494(arg0, arg0->animationId, &sp10);
    u_char* temp_a3 = *v0;
    temp_a3 += sp10[2];

    var_v1 = temp_a3[0];

    if (var_v1 == 0xFF) {
        var_a3 = temp_a3 + 2;
        var_v1 = temp_a3[1] + 0xFF;
    } else {
        var_a3 = temp_a3 + 1;
    }

    arg0->unk704.unk542 = var_v1;
    arg0->unk704.unk544 = var_a3;

    func_800AD714(arg0, &arg0->unk704, 2, var_a3);
}

void func_800AE4FC(D_800F4538_unk0* arg0, int arg1)
{
    D_800F4538_t* actor;
    int temp;
    int sp[2];
    int type = arg1;

    if (arg0->position.vy >= 0xBB8) {
        return;
    }

    actor = D_800F4538[arg0->unkF];

    if (actor->unk17E4.unk0 == 2) {
        sp[0] = 0x80;
        sp[1] = 0;
    } else {
        if ((*((int*)&actor->unk0.nQuads + 1) & 0x3F9F00) != 0x8000) {
            func_800A1280(arg0->unkF, 0xFF, &actor->unk6FC, 0);
        }

        temp = vs_main_computeSfxPan(*(int*)&actor->unk6FC, actor->unk6FC.vz);
        sp[0] = temp >> 0x10;

        if (actor->unk17E4.unk1 != 0) {
            sp[0] = actor->unk17E4.unk1;
        }

        sp[1] = temp & 0xFFFF;

        if (actor->unk17E4.unk2 != 0) {
            sp[1] = actor->unk17E4.unk2;
        }
    }

    if (sp[1] == 0) {
        return;
    }

    if (type == 8) {
        func_8006CD60(arg0->unk68->akaoOffset, sp[0], sp[1]);
    } else if (type == 4) {
        func_800461CC(0x7E, arg0->unk68->akaoOffset, rand() % 4 + 4, sp[0], sp[1]);
    } else {
        func_800461CC(0x180, arg0->unk68->akaoOffset, type, sp[0], sp[1]);
    }
}

void func_800AE68C(int arg0, int arg1)
{
    func_800AE4FC(&D_800F4538[arg0]->unk0, arg1 + 4);
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/44F14", func_800AE6C0);

void func_800AE7D8(void* arg0, int arg1, int arg2)
{
    SVECTOR* temp_s0;

    temp_s0 = arg0 + 0x1C;
    vs_main_panSfx(0x7E, arg1, temp_s0);
    if (arg2 != 0) {
        vs_main_panSfx(0x7E, arg2, temp_s0);
    }
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/44F14", func_800AE828);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/44F14", func_800AE980);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/44F14", func_800AEAE8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/44F14", func_800AECA0);

void func_800AEEC4(D_800F4538_t* arg0) __attribute__((unused));
void func_800AEEC4(D_800F4538_t* arg0)
{
    int _[2] __attribute__((unused));
    int var_a2;
    int v0;
    int temp_v1 = arg0->unk17E4.unk0;

    if ((temp_v1 != 1) || (arg0->unk17E4.unk3 == 0)) {
        return;
    }

    var_a2 = vs_gametime_tickspeed / 2;

    if (arg0->unk17E4.unk3 < var_a2) {
        var_a2 = arg0->unk17E4.unk3;
    }

    temp_v1 = arg0->unk17E8.unk2 - arg0->unk17E4.unk2;

    if (temp_v1 != 0) {
        temp_v1 *= var_a2;
        v0 = temp_v1 / arg0->unk17E4.unk3;
        arg0->unk17E4.unk2 = arg0->unk17E4.unk2 + v0;
    }

    temp_v1 = arg0->unk17E8.unk1 - arg0->unk17E4.unk1;

    if (temp_v1 != 0) {
        temp_v1 *= var_a2;
        v0 = temp_v1 / arg0->unk17E4.unk3;
        arg0->unk17E4.unk1 = arg0->unk17E4.unk1 + v0;
    }

    arg0->unk17E4.unk3 -= var_a2;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/44F14", func_800AEF94);

void func_800AF6E8(D_800F4538_t* arg0)
{
    func_800AFA28(arg0, &arg0->unkC54, 0);

    if (arg0->unk5CC != 0) {
        int v5b2;

        if (arg0->unk5CC == 1) {
            func_800AF844(&arg0->unk704, &arg0->unkC54, arg0->unk0.nBones);
        }

        v5b2 = arg0->unk5B2;

        if (v5b2 != 1) {
            int next = arg0->unk5CC + 0xFF;
            arg0->unk5CC = v5b2 + next;

            if (arg0->unk5CC >= arg0->unk5CD) {
                arg0->unk5CC = 0;
                arg0->unk5CD = 0;
                goto tail;
            }
        }

        func_800B147C(
            &arg0->unk704, &arg0->unkC54, arg0->unk0.nBones, arg0->unk5CC, arg0->unk5CD);

        arg0->unk704.unk548_16 = arg0->unkC54.unk548_16;
        arg0->unk704.unk548_17 = arg0->unkC54.unk548_17;

        func_800B002C(arg0, 0);

        ++arg0->unk5CC;

        if (arg0->unk5CC >= arg0->unk5CD) {
            arg0->unk5CC = 0;
            arg0->unk5CD = 0;
        }
        return;
    }

tail:
    vs_main_memcpy(&arg0->unk704, &arg0->unkC54, sizeof(arg0->unk704));
    func_800B002C(arg0, 0);
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/44F14", func_800AF844);

void func_800AF960(D_800F45E0_t* arg0) __attribute__((unused));
void func_800AF960(D_800F45E0_t* arg0)
{
    int temp_lo;

    D_800F4538_unk1864* a2 = &arg0->unk1864;

    if (a2->unk4 != 0) {
        temp_lo = a2->unkA / a2->unk4;
        a2->unkA -= temp_lo;
        a2->unk8 += temp_lo;
        --a2->unk4;
    }

    a2->unk8 &= 0xFFF;

    if (a2->unk5 != 0) {
        temp_lo = a2->unk10 / a2->unk5;
        a2->unk10 -= temp_lo;
        a2->unkC += temp_lo;
        temp_lo = a2->unk12 / a2->unk5;
        a2->unk12 -= temp_lo;
        a2->unkE += temp_lo;
        --a2->unk5;
    }
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/44F14", func_800AFA28);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/44F14", func_800AFDE8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/44F14", func_800B002C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/44F14", func_800B07DC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/44F14", func_800B0908);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/44F14", func_800B101C);

int func_800B13CC(int arg0, int arg1, int arg2)
{
    int i;
    int var_a3 = 0xBB8;

    for (i = 0; i < 16; ++i) {

        D_800F45E0_t* temp_v1 = D_800F45E0[i];

        if ((temp_v1 != NULL) && !(temp_v1->unk8_0) && !(temp_v1->unk6C[8].unk0_3)
            && (temp_v1->unk5C == arg0) && (temp_v1->unk5E == arg1)) {

            int temp_v1_2 = temp_v1->unk1E;

            if ((arg2 < temp_v1_2) && (temp_v1_2 < var_a3)) {
                var_a3 = temp_v1_2;
            }
        }
    }

    var_a3 -= 128;

    if (var_a3 > 0) {
        var_a3 = 0;
    }

    return var_a3;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/44F14", func_800B147C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/44F14", func_800B16F4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/44F14", func_800B17F0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/44F14", func_800B196C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/44F14", func_800B1A68);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/44F14", func_800B217C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/44F14", func_800B26B8);
