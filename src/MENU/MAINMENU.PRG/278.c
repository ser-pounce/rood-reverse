#include "common.h"
#include "278.h"
#include "../SLUS_010.40/main.h"
#include "../BATTLE/BATTLE.PRG/146C.h"
#include "../BATTLE/BATTLE.PRG/2842C.h"
#include "../BATTLE/BATTLE.PRG/30D14.h"
#include "../BATTLE/BATTLE.PRG/3A1A0.h"
#include "../BATTLE/BATTLE.PRG/40564.h"
#include "../BATTLE/BATTLE.PRG/44F14.h"
#include "../BATTLE/BATTLE.PRG/4A0A8.h"

typedef struct {
    char unk0;
    char unk1;
    char unk2;
    char unk3;
    int unk4;
    int unk8;
    char unkC;
    u_char unkD;
    char unkE;
    char unkF;
    char unk10;
    char unk11;
    char unk12;
    char unk13;
    int unk14;
    int unk18;
    short unk1C;
    short unk1E;
    short unk20;
    short unk22;
    int unk24[18];
    int unk6C[42][8];
    int unk5AC;
    char unk5B0;
    char unk5B1;
    char unk5B2;
    char unk5B3;
    char unk5B4;
    char unk5B5;
    char unk5B6;
    char unk5B7;
    char unk5B8;
    char unk5B9;
    char unk5BA;
    char unk5BB;
    short unk5BC;
    short unk5BE;
    int unk5C0;
    int unk5C4;
    int unk5C8;
    char unk5CC;
    char unk5CD;
    short unk5CE;
    int unk5D0;
    int unk5D4;
    void* unk5D8;
    int unk5DC;
    int unk5E0[0x1A];
    int unk648;
    int unk64C[0x25];
    char unk6E0;
    char unk6E1;
    char unk6E2;
    char unk6E3;
    short unk6E4;
    short unk6E6;
    short unk6E8[6];
    signed char unk6F4;
    signed char unk6F5;
    signed char unk6F6;
    char unk6F7;
    int unk6F8;
    int unk6FC;
    int unk700;
    char unk704[0x550];
    char unkC54[0x540];
    short unk1194;
    short unk1196;
    int unk1198[0x199];
    char unk17FC;
    u_char unk17FD;
    short unk17FE;
    int unk1800[0x1F];
    int unk187C;
} D_800F4538_t;

extern D_800F4538_t* D_800F4538[];
extern D_800F4538_t* D_800F4588[];
extern char D_800F49DC;

void func_800F9A24(int);
INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/278", func_800F9A24);

void func_800F9A78(int arg0)
{
    func_8007C8F8_t sp10;
    D_800F4538_t* temp_s0;
    D_800F4538_t* temp_s2;
    int i;
    D_800F4538_t* temp_s3;
    void* temp_v0;

    temp_s2 = D_800F4538[arg0];
    temp_s3 = vs_main_allocHeap(0x1900);
    sp10.unk0 = 2;
    sp10.unk1 = 1;
    sp10.unk2 = temp_s2->unk6E6;
    sp10.unk8 = arg0;
    sp10.unk4 = temp_s3;
    sp10.unk10 = 0xFF;
    sp10.unk13 = temp_s2->unk10;
    sp10.unk12 = 0;
    func_800995E8(&sp10);

    if (temp_s2->unk17FD >= 2) {
        temp_s0 = D_800F4538[temp_s2->unk17FD];
        temp_v0 = vs_main_allocHeap(0x1900);
        sp10.unk0 = 2;
        sp10.unk1 = 0x10;
        sp10.unk2 = temp_s0->unk6E6;
        sp10.unk8 = temp_s2->unk17FD;
        sp10.unk4 = temp_v0;
        sp10.unk10 = 1;
        sp10.unk11 = 0xFC;
        sp10.unk13 = temp_s2->unk10;
        sp10.unk12 = 0;
        func_800995E8(&sp10);
    }
    for (i = 0; i < 2; ++i) {
        temp_s0 = D_800F4588[(temp_s2->unkF * 2) + i];
        if (temp_s0 != 0) {
            temp_v0 = vs_main_allocHeap(0x5E8);
            sp10.unk0 = 4;
            sp10.unk1 = i + 2;
            sp10.unk2 = temp_s0->unkE;
            sp10.unk8 = arg0 * 2 + i;
            sp10.unk4 = temp_v0;
            sp10.unk10 = 1;
            sp10.unk11 = temp_s0->unkC;
            sp10.unk12 = ((u_int)temp_s0->unk8 >> 0xC) & 0xF;
            func_800995E8(&sp10);
        }
    }

    while (func_8009967C() != 0)
        ;

    temp_s3->unk5D4 = temp_s2->unk5D4;

    if (temp_s2->unkF == 0) {
        temp_s3->unk5D8 = vs_main_allocHeap(0x7800);
        func_8009C378(temp_s3->unk5D8, temp_s2->unk5D8);
    } else {
        temp_s3->unk5D8 = temp_s2->unk5D8;
    }
    temp_s3->unk5B1 = temp_s2->unk5B1;
    temp_s3->unk5B4 = temp_s2->unk5B4;
    temp_s3->unk5B5 = temp_s2->unk5B5;
}

void func_800F9CB0(void)
{
    char sp10[3];
    int sp18;
    int i;
    D_800F4538_t* temp_s0;
    int new_var;
    int new_var3;

    temp_s0 = D_800F4538[1];

    for (i = 0; i < 2; ++i) {
        if (D_800F4588[i + 2] != 0) {
            D_800F4588[i + 2]->unk8 |= 0x10;
        }
    }

    func_8009D468(1, i);
    temp_s0->unk1C = 0;
    new_var = temp_s0->unk8 & (~1);
    temp_s0->unk1E = 0;
    temp_s0->unk20 = 0;
    *((int*)(&temp_s0->unk5B0)) &= ~0x10;
    temp_s0->unk8 = new_var & 0xFFFF7FFF;
    sp10[0] = 0xFF;
    sp10[1] = 0xFF;
    sp10[2] = 0xFF;
    sp18 = ((((sp18 & (~0xFF)) | 2) & 0xFFFF00FF) | 0xFE00);
    new_var3 = 0x20000;
    sp18 = (sp18 & 0xFE02) | new_var3;
    sp18 |= 0x10000000;
    if (D_800F4538[16] == 0) {
        func_8009F940(1, 1, &sp18, sp10);
    } else {
        D_800F4538[16]->unk8 &= ~1;
    }
    sp10[0] = 0;
    sp10[1] = 0;
    sp10[2] = 0;
    func_800A0768(1, sp10);
    func_800A07FC(1, 0);
    temp_s0->unk648 &= 0xFFFEFFFF;
}

void func_800F9E0C(void)
{
    void* sp10[2];
    void* temp_s1;

    temp_s1 = D_800F4538[1];
    sp10[0] = D_800F4588[2];
    sp10[1] = D_800F4588[3];

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

static inline int _insertTpage(int arg0, u_int arg1) { return arg0 + arg1; }

int func_800F9EB8(void* arg0)
{
    int _[2] __attribute__((unused));
    int i;
    D_800F4538_t* temp_a0;
    int* temp_s0;
    D_800F4538_t* temp_s1;
    int new_var2;
    int new_var3;

    temp_s1 = D_800F4538[1];
    if (temp_s1 == NULL) {
        return -1;
    }
    if (temp_s1->unk0 == 0) {
        return -1;
    }
    if (temp_s1->unk8 & 1) {
        return -1;
    }
    func_800AECA0(arg0);
    temp_s1->unk5B2 =
        ((int)(vs_gametime_tickspeed + ((u_int)vs_gametime_tickspeed >> 0x1F)) >> 1);
    if (temp_s1->unk8 & 4) {
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
        new_var2 = (temp_s1->unk6F7 * 4) + 0xC0;
        p[1] += new_var2;
        temp_s1->unk1C += temp_s1->unk6F4;
        temp_s1->unk1E += temp_s1->unk6F5;
        temp_s1->unk20 += temp_s1->unk6F6;
        func_800B002C(temp_s1, temp_s1->unk17FD);
        func_800B28A8(temp_s1, arg0, temp_s1->unk17FD);
        p = (int*)0x1F800000;
        new_var3 = (temp_s1->unk6F7 * 4) + 0xC0;
        p[1] -= new_var3;
        temp_s1->unk1C -= temp_s1->unk6F4;
        temp_s1->unk1E -= temp_s1->unk6F5;
        temp_s1->unk20 -= temp_s1->unk6F6;
    }
    if ((temp_s1->unk8 & 0x1000)) {
        return -2;
    }

    for (i = 0; i < 2; ++i) {
        temp_a0 = D_800F4588[_insertTpage(i, 2)];
        if ((temp_a0 != 0) && (temp_a0->unk8 & 0x10)) {
            temp_s0 = temp_s1->unk6C[temp_a0->unkD];
            temp_s0[5] -= temp_s1->unk6F4;
            temp_s0[6] -= temp_s1->unk6F5;
            temp_s0[7] -= temp_s1->unk6F6;
            func_800B217C(temp_a0, temp_s0);
            temp_s0[5] += temp_s1->unk6F4;
            temp_s0[6] += temp_s1->unk6F5;
            temp_s0[7] += temp_s1->unk6F6;
        }
    }
    return 0;
}

int func_800FA188(int arg0, int arg1, int* arg2)
{
    D_800F45E0_t* temp_v1;
    int temp_a3;
    int i;
    int var_t2;
    int var_t3;

    var_t2 = 0;
    var_t3 = 0;
    for (i = 0; i < 16; ++i) {
        temp_v1 = D_800F45E0[i];
        if (temp_v1 == NULL) {
            continue;
        }
        temp_a3 = temp_v1->unk8;
        if (!(temp_v1->unk8 & 1) && !(temp_a3 & 0xF00) && (temp_v1->unk1A == 0)
            && (temp_v1->unk5C == arg0) && (temp_v1->unk5E == arg1)) {
            if ((temp_v1->unk16C & 0x30) == 0x20) {
                var_t3 = 1;
            } else {
                var_t2 -= 0x80;
            }
        }
    }
    *arg2 = var_t2;
    return var_t3;
}

static int func_800FA238(int arg0, int arg1, int arg2)
{
    D_800F45E0_t* new_var2;
    int temp_a3;
    int i;
    int new_var = arg2 + 0x80;

    for (i = 0; i < 16; ++i) {
        new_var2 = D_800F45E0[i];
        if ((D_800F45E0[i] != 0) && (temp_a3 = D_800F45E0[i]->unk8, !(temp_a3 & 1))
            && (!(temp_a3 & 0xF00)) && (D_800F45E0[i]->unk5C == arg0)
            && (new_var2->unk5E == arg1) && (D_800F45E0[i]->unk1E >= arg2)
            && (new_var >= D_800F45E0[i]->unk1E)) {
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
    char* temp_s0;
    D_800F4538_t* temp_s1;

    temp_s1 = D_800F4538[0];

    for (i = 0; i < 2; ++i) {
        D_800F4538_t* var_a0 = D_800F4588[i];
        if (var_a0 != 0) {
            if (temp_s1->unk8 & 0x800000) {
                var_a0->unk11 = 0x40;
                var_a0->unk8 |= 0x10;
            } else {
                var_a0->unk11 = 0;
            }
        }
    }

    func_8009E634(temp_s1, i);

    i_2 = 1;
    if (temp_s1->unk8 & 0x800000) {
        i_2 = 0x65;
    }

    temp_s1->unk5B8 = i_2;
    temp_s1->unk5AC = temp_s1->unk5AC & 0xFFEFFFFF;
    temp_s1->unk187C = func_800AD494(temp_s1, i_2, &sp10);
    temp_s1->unk6E3 = D_800F49DC;
    temp_s0 = temp_s1->unkC54;
    temp_s1->unk5BC = *sp10;
    func_800AD008(temp_s1, temp_s0);
    func_800AFA28(temp_s1, temp_s0, 1);
    vs_main_memcpy(temp_s1->unk704, temp_s0, 0x550U);
    temp_s1->unk1194 = 0;
    temp_s1->unk6E0 = 0;
    temp_s1->unk5CD = 0;
    temp_s1->unk5CC = 0;
}

void func_800FA3FC(int arg0)
{
    func_8007C8F8_t sp10;

    func_8009CC20(0, 0);
    sp10.unk0 = 7;
    sp10.unk1 = 0;
    sp10.unk2 = arg0;
    sp10.unk10 = 0;
    func_800995E8(&sp10);
}
