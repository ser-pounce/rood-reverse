#include "224.h"
#include "src/BATTLE/BATTLE.PRG/2842C.h"
#include "src/BATTLE/BATTLE.PRG/30D14.h"
#include "src/BATTLE/BATTLE.PRG/3A1A0.h"
#include "src/BATTLE/BATTLE.PRG/40564.h"
#include "src/BATTLE/BATTLE.PRG/44F14.h"
#include "src/BATTLE/BATTLE.PRG/4A0A8.h"
#include "src/BATTLE/BATTLE.PRG/5BF94.h"

void func_800F9A24(int arg0)
{
    func_800F9A78(arg0);
    func_800F9CB0();

    D_800F4538[1]->unk0.weaponDrawn = 1;

    func_800A0204(1, 1, 0, 0);
}

void func_800F9A78(int arg0)
{
    vs_battle_objectData sp10;
    D_800F4538_t* temp_s0;
    D_800F4538_t* temp_s2;
    int i;
    D_800F4538_t* temp_s3;
    void* temp_v0;

    temp_s2 = D_800F4538[arg0];
    temp_s3 = vs_main_allocHeap(0x1900);
    sp10.dataType = 2;
    sp10.index = 1;
    sp10.modelId = temp_s2->unk6E6;
    sp10.dataAddr = arg0;
    sp10.unk4 = temp_s3;
    sp10.actorId = 0xFF;
    sp10.variant = temp_s2->unk0.unk10;
    sp10.material = 0;

    vs_battle_populateDataSlot(&sp10);

    if (temp_s2->unk17FD >= 2) {
        temp_s0 = D_800F4538[temp_s2->unk17FD];
        temp_v0 = vs_main_allocHeap(0x1900);
        sp10.dataType = 2;
        sp10.index = 16;
        sp10.modelId = temp_s0->unk6E6;
        sp10.dataAddr = temp_s2->unk17FD;
        sp10.unk4 = temp_v0;
        sp10.actorId = 1;
        sp10.unk11 = 0xFC;
        sp10.variant = temp_s2->unk0.unk10;
        sp10.material = 0;

        vs_battle_populateDataSlot(&sp10);
    }

    for (i = 0; i < 2; ++i) {
        vs_battle_wepModels_t* temp_s0 =
            vs_battle_wepModels[(temp_s2->unk0.unkF * 2) + i];
        if (temp_s0 != 0) {
            temp_v0 = vs_main_allocHeap(sizeof *temp_s0);
            sp10.dataType = 4;
            sp10.index = i + 2;
            sp10.modelId = temp_s0->modelId;
            sp10.dataAddr = arg0 * 2 + i;
            sp10.unk4 = temp_v0;
            sp10.actorId = 1;
            sp10.unk11 = temp_s0->unkC;
            sp10.material = temp_s0->unk9_4;
            vs_battle_populateDataSlot(&sp10);
        }
    }

    while (vs_battle_processObjectDataQueue() != 0)
        ;

    temp_s3->unk5D4 = temp_s2->unk5D4;

    if (temp_s2->unk0.unkF == 0) {
        temp_s3->unk5D8 = vs_main_allocHeap(0x7800);

        func_8009C378(temp_s3->unk5D8, temp_s2->unk5D8);
    } else {
        temp_s3->unk5D8 = temp_s2->unk5D8;
    }

    temp_s3->unk5B1 = temp_s2->unk5B1;
    temp_s3->unk5B4 = temp_s2->unk5B4;
    temp_s3->unk5B5 = temp_s2->unk5B5;
}

typedef struct {
    u_int unk0_0 : 8;
    u_int unk0_8 : 8;
    u_int unk0_16 : 8;
    u_int unk0_24 : 8;
} D_800F4538_unk58_3;

void func_800F9CB0(void)
{
    D_800F4538_unk58_2 sp10;
    int new_var;
    D_800F4538_unk58_3 sp18;
    D_800F4538_t* temp_s0;
    int i;

    temp_s0 = D_800F4538[1];

    for (i = 0; i < 2; ++i) {
        if (D_800F4590[i] != NULL) {
            D_800F4590[i]->unk8 |= 0x10;
        }
    }

    func_8009D468(1, i);

    temp_s0->unk0.position.vx = 0;
    temp_s0->unk0.position.vy = 0;
    temp_s0->unk0.position.vz = 0;
    temp_s0->unk5B0_4 = 0;
    temp_s0->unk0.skip = 0;
    temp_s0->unk0.unk9_7 = 0;
    sp10.unk0 = -1;
    sp10.unk1 = -1;
    sp10.unk2 = -1;

    sp18.unk0_0 = 2;
    sp18.unk0_8 = 254;
    sp18.unk0_16 = 2;
    sp18.unk0_24 = 16;

    if (D_800F4538[16] == NULL) {
        func_8009F940(1, 1, (D_800F4538_unk58_2*)&sp18, &sp10);
    } else {
        D_800F4538[16]->unk0.skip = 0;
    }

    sp10.unk0 = 0;
    sp10.unk1 = 0;
    sp10.unk2 = 0;

    func_800A0768(1, &sp10);
    func_800A07FC(1, 0);

    temp_s0->unk648_16 = 0;
}

void func_800F9E0C(void)
{
    void* sp10[2];
    void* temp_s1;

    temp_s1 = D_800F4538[1];
    sp10[0] = vs_battle_wepModels[2];
    sp10[1] = vs_battle_wepModels[3];

    func_8009CFB0(1);
    vs_main_freeHeap(temp_s1);

    temp_s1 = D_800F4538[16];

    if (temp_s1 != NULL) {
        func_8009CFB0(0x10);
        vs_main_freeHeap(temp_s1);
    }

    if (sp10[0] != NULL) {
        vs_main_freeHeap(sp10[0]);
    }

    if (sp10[1] != NULL) {
        vs_main_freeHeap(sp10[1]);
    }
}

int func_800F9EB8(void* arg0)
{
    int _[2];
    int i;
    D_800F4538_t* temp_s1;
    int new_var2;
    int new_var3;
    temp_s1 = D_800F4538[1];

    if (temp_s1 == NULL) {
        return -1;
    }

    if (temp_s1->unk0.nBones == 0) {
        return -1;
    }

    if (temp_s1->unk0.skip) {
        return -1;
    }

    func_800AECA0(arg0);

    temp_s1->unk5B2 =
        ((int)(vs_gametime_tickspeed + (((u_int)vs_gametime_tickspeed) >> 0x1F))) >> 1;

    if (temp_s1->unk0.freeze) {
        func_800AB4F0(temp_s1);
        func_800AF6E8(temp_s1);
    } else {
        func_800AEAE8(temp_s1);
    }

    func_800B28A8(temp_s1, arg0, 0);

    if (temp_s1->unk17FD > 1) {
        func_800AB4F0(D_800F4538[16]);
    }

    if (temp_s1->unk17FD != 0) {
        int* p = (int*)0x1F800000;
        new_var2 = (temp_s1->unk6F4.unk3 * 4) + 0xC0;
        p[1] += new_var2;

        applyVector(&temp_s1->unk0.position, temp_s1->unk6F4.unk0, temp_s1->unk6F4.unk1,
            temp_s1->unk6F4.unk2, +=);

        func_800B002C(temp_s1, temp_s1->unk17FD);
        func_800B28A8(temp_s1, arg0, temp_s1->unk17FD);

        p = (int*)0x1F800000;
        new_var3 = (temp_s1->unk6F4.unk3 * 4) + 0xC0;
        p[1] -= new_var3;

        applyVector(&temp_s1->unk0.position, temp_s1->unk6F4.unk0, temp_s1->unk6F4.unk1,
            temp_s1->unk6F4.unk2, -=);
    }

    if (temp_s1->unk0.unk9_4) {
        return -2;
    }

    for (i = 0; i < 2; ++i) {
        int v = i + 2;
        vs_battle_wepModels_t* temp_a0 = vs_battle_wepModels[v];

        if ((temp_a0 != 0) && temp_a0->unk8_4) {
            MATRIX* bone = &temp_s1->bones[temp_a0->unkD];

            bone->t[0] -= temp_s1->unk6F4.unk0;
            bone->t[1] -= temp_s1->unk6F4.unk1;
            bone->t[2] -= temp_s1->unk6F4.unk2;

            func_800B217C(temp_a0, bone);

            bone->t[0] += temp_s1->unk6F4.unk0;
            bone->t[1] += temp_s1->unk6F4.unk1;
            bone->t[2] += temp_s1->unk6F4.unk2;
        }
    }

    return 0;
}

static int func_800FA188(int arg0, int arg1, int* arg2)
{
    int i;
    int var_t2 = 0;
    int ret = 0;
    D_800F45E0_t** var_t0 = D_800F45E0;

    for (i = 0; i < 16; ++i) {
        D_800F45E0_t* temp_v1 = var_t0[i];
        if ((var_t0[i] != 0)
            && ((((!var_t0[i]->unk8_0) && (!temp_v1->unk9_0)) && (temp_v1->unk1A == 0))
                && (temp_v1->unk5C == arg0))
            && (temp_v1->unk5E == arg1)) {
            if (temp_v1->unk6C[8].unk0_4 == 2) {
                ret = 1;
            } else {
                var_t2 -= 0x80;
            }
        }
    }

    *arg2 = var_t2;
    return ret;
}

static int func_800FA238(int arg0, int arg1, int arg2) __attribute__((unused));
static int func_800FA238(int arg0, int arg1, int arg2)
{
    int i;
    D_800F45E0_t** var_t0 = D_800F45E0;
    int new_var = arg2 + 0x80;

    for (i = 0; i < 16; ++i) {
        D_800F45E0_t* temp_v1 = var_t0[i];

        if (var_t0[i] && !var_t0[i]->unk8_0 && !temp_v1->unk9_0
            && (temp_v1->unk5C == arg0) && (temp_v1->unk5E == arg1)
            && (temp_v1->unk1E >= arg2) && (new_var >= temp_v1->unk1E)) {
            return 1;
        }
    }

    return 0;
}

void func_800FA2CC(void)
{
    u_short* sp10;
    int i;
    int i_2;
    D_800F4538_t* temp_s1;

    temp_s1 = D_800F4538[0];

    for (i = 0; i < 2; ++i) {
        vs_battle_wepModels_t* var_a0 = vs_battle_wepModels[i];

        if (var_a0 != 0) {
            if (temp_s1->unk0.weaponDrawn) {
                var_a0->unk11 = 0x40;
                var_a0->unk8_4 = 1;
            } else {
                var_a0->unk11 = 0;
            }
        }
    }

    func_8009E634(temp_s1);

    i_2 = 1;

    if (temp_s1->unk0.weaponDrawn) {
        i_2 = 101;
    }

    temp_s1->animationId = i_2;
    temp_s1->unk5AC_20 = 0;
    temp_s1->unk187C = func_800AD494(temp_s1, i_2, &sp10);
    temp_s1->unk6E3 = D_800F49DC;
    temp_s1->unk5BC = *sp10;

    func_800AD008(temp_s1, &temp_s1->unkC54);
    func_800AFA28(temp_s1, &temp_s1->unkC54, 1);
    vs_main_memcpy(&temp_s1->unk704, &temp_s1->unkC54, sizeof temp_s1->unk704);

    temp_s1->unkC54.unk540 = 0;
    temp_s1->unk6E0 = 0;
    temp_s1->unk5CD = 0;
    temp_s1->unk5CC = 0;
}

void func_800FA3FC(int arg0)
{
    vs_battle_objectData sp10;

    func_8009CC20(0, 0);

    sp10.dataType = 7;
    sp10.index = 0;
    sp10.modelId = arg0;
    sp10.actorId = 0;

    vs_battle_populateDataSlot(&sp10);
}
