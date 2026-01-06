#include "common.h"
#include "146C.h"
#include "../../SLUS_010.40/main.h"

typedef struct {
    int* unk0;
    int unk4;
    short unk8;
    short unkA;
    int unkC;
    int unk10;
    int unk14;
    int unk18;
    short unk1C;
    short unk1E;
    short unk20;
    short unk22;
    short unk24;
    short unk26;
    short unk28;
    short unk2A;
    short unk2C;
    short unk2E;
    short unk30;
    short unk32;
} func_80092F74_t;

typedef struct {
    int* unk0;
    union {
        u_short u16[2];
        int s32;
    } unk4[4];
    int unk14;
    int unk18;
} func_80092F74_t2;

typedef struct {
    char unk0;
    char unk1;
    char unk2;
    char unk3;
    int unk4;
    int unk8;
} D_800F1DD8_t;

void func_80090B28(void);
void func_8009121C(void);
int func_80091998(int);
int func_800919D8(int);
void func_8009291C(int);
int func_80092EDC(func_80092F74_t* arg0, func_80092F74_t2* arg1);

extern short D_800F1D00;
extern short D_800F1D98[];
extern short D_800F1DB4;
extern short D_800F1DB6;
extern short D_800F1DC0;
extern short D_800F1DC2;
extern short D_800F1DC4;
extern char D_800F1DCB;
extern void* D_800F1DD4;
extern D_800F1DD8_t D_800F1DD8[];
extern short D_800F2258;
extern short D_800F2270;
extern short D_800F2272;
extern short D_800F2278;
extern short D_800F227A;
extern short D_800F227E;

INCLUDE_RODATA("build/src/BATTLE/BATTLE.PRG/nonmatchings/2842C", D_80068EB4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/2842C", func_80090C2C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/2842C", func_80090EEC);

int _clamp(short arg0, int arg1, int arg2)
{
    short var_t0;
    short var_v1;

    if ((arg1 << 0x10) < (arg2 << 0x10)) {
        var_t0 = arg1;
        var_v1 = arg2;
    } else {
        var_t0 = arg2;
        var_v1 = arg1;
    }
    if (arg0 < var_t0) {
        return var_t0;
    }
    if (var_v1 < arg0) {
        return var_v1;
    }
    return arg0;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/2842C", func_8009121C);

void func_80091314(int arg0) { D_800F1DCB = arg0; }

void func_80091320(int arg0)
{
    D_800F1DC4 = arg0;
    func_8009121C();
    func_80090B28();
}

void func_8009134C(int arg0, int arg1)
{
    D_800F1D98[5] = arg0;
    D_800F1D98[4] = arg1;
    func_80090B28();
}

void func_80091378(void)
{
    D_800F1DC0 = 0;
    D_800F1DC2 = 0;
    if (D_800F1DD4 != NULL) {
        vs_main_freeHeap(D_800F1DD4);
    }
    D_800F1DD4 = NULL;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/2842C", func_800913BC);

void func_80091468(int arg0, int arg1)
{
    D_800F1DB4 = arg0;
    D_800F1DB6 = arg1;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/2842C", func_8009147C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/2842C", func_800918E8);

void* func_8009195C(int arg0)
{
    if (D_800F1BF8.unk64 != NULL) {
        int v1 = *D_800F1BF8.unk64;
        int* a1 = D_800F1BF8.unk64 + 1;
        if ((arg0 >= 0) && (arg0 < v1)) {
            return a1 + (arg0 * 16);
        }
    }
    return NULL;
}

int func_80091998(int arg0)
{
    int* temp_v0 = func_8009195C(arg0);
    if (temp_v0 != NULL) {
        *temp_v0 &= ~0x100;
        return 1;
    }
    return 0;
}

int func_800919D8(int arg0)
{
    int* temp_v0 = func_8009195C(arg0);
    if (temp_v0 != NULL) {
        *temp_v0 |= 0x100;
        return 1;
    }
    return 0;
}

int func_80091A1C(int arg0, int arg1)
{
    int* temp_s0 = func_8009195C(arg0);
    int* temp_a1 = func_8009195C(arg1);

    if ((temp_s0 != NULL) && (temp_a1 != NULL)) {
        int temp_a0 = *temp_s0;
        *temp_s0 = *temp_a1;
        *temp_a1 = temp_a0;
        return 1;
    }
    return 0;
}

int func_80091A78(int arg0, int arg1)
{
    u_short* temp_v0 = func_8009195C(arg0);
    if (temp_v0 != NULL) {
        temp_v0[1] = (u_short)(temp_v0[1] + arg1);
        return 1;
    }
    return 0;
}

int func_80091AC0(int arg0)
{
    int* temp_v0 = func_8009195C(arg0);
    if (temp_v0 != NULL) {
        *temp_v0 |= 0x1000;
        return 1;
    }
    return 0;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/2842C", func_80091B04);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/2842C", func_80091C6C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/2842C", func_80091E10);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/2842C", func_80091FE8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/2842C", func_800923F8);

int func_80092540(void) { return 0; }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/2842C", func_80092548);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/2842C", func_800927AC);

void func_80092914(void) { }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/2842C", func_8009291C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/2842C", func_80092A18);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/2842C", func_80092B04);

int func_80092C68(func_80092F74_t* arg0, func_80092F74_t2* arg1);
INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/2842C", func_80092C68);

int func_80092E14(func_80092F74_t* arg0, func_80092F74_t2* arg1)
{
    arg0->unk24 = arg1->unk4[0].u16[0];
    arg0->unk26 = arg1->unk4[0].u16[1];
    arg0->unk28 = arg1->unk4[1].u16[0];
    arg0->unk2A = arg1->unk4[1].u16[1];
    arg0->unk2C = arg1->unk4[2].u16[0];
    arg0->unk2E = arg1->unk4[2].u16[1];
    arg0->unk30 = arg1->unk4[3].u16[0];
    arg0->unk32 = arg1->unk4[3].u16[1];
    return 0;
}

int func_80092E7C(func_80092F74_t* arg0, func_80092F74_t2* arg1)
{
    arg0->unkC = arg1->unk4[0].s32;
    arg0->unk10 = arg1->unk4[1].s32;
    arg0->unk14 = arg1->unk4[2].s32;
    arg0->unk1C = arg1->unk4[3].s32;
    arg0->unk1E = arg1->unk14;
    arg0->unk20 = arg1->unk18;
    func_80092EDC(arg0, arg1);
    return 0;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/2842C", func_80092EDC);

int func_80092F6C(func_80092F74_t* arg0 __attribute__((unused)),
    func_80092F74_t2* arg1 __attribute__((unused)))
{
    return 0;
}

int func_80092F74(func_80092F74_t* arg0, func_80092F74_t2* arg1 __attribute__((unused)))
{
    if (arg0->unk8 >= 0) {
        *arg0->unk0 = 0x100;
    }
    return 0;
}

int func_80092F98(func_80092F74_t* arg0, func_80092F74_t2* arg1)
{
    func_80091998(arg1->unk4[0].s32);
    return 0;
}

int func_80092FBC(func_80092F74_t* arg0, func_80092F74_t2* arg1);
INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/2842C", func_80092FBC);

int func_8009306C(func_80092F74_t* arg0, func_80092F74_t2* arg1);
INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/2842C", func_8009306C);

int func_80093364(func_80092F74_t* arg0, func_80092F74_t2* arg1);
INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/2842C", func_80093364);

int func_8009352C(func_80092F74_t* arg0, func_80092F74_t2* arg1);
INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/2842C", func_8009352C);

int func_800935B8(func_80092F74_t* arg0, func_80092F74_t2* arg1)
{
    if (D_800F1BF8.unkB0 != NULL) {
        func_8004644C(0x200, D_800F1BF8.unkB0, arg1->unk4[0].u16[1]);
        D_800F2258 = -1;
    }
    return 0;
}

int func_800935F8(func_80092F74_t* arg0 __attribute__((unused)), func_80092F74_t2* arg1)
{
    func_8009291C(arg1->unk4[0].s32);
    return 0;
}

int func_8009361C(func_80092F74_t* unk0 __attribute__((unused)), func_80092F74_t2* arg1)
{
    func_800919D8(arg1->unk4[0].s32);
    return 0;
}

int func_80093640(func_80092F74_t* arg0, func_80092F74_t2* arg1);
INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/2842C", func_80093640);

int func_800936F0(func_80092F74_t* arg0 __attribute__((unused)),
    func_80092F74_t2* arg1 __attribute__((unused)))
{
    return 0;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/2842C", func_800936F8);

int func_80093764(int arg0) { return D_800F1DD8[arg0].unk0; }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/2842C", func_80093788);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/2842C", func_80093824);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/2842C", func_800938AC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/2842C", func_80093914);

void func_80093A14(void)
{
    D_800F1D00 = 1;
    if ((D_800F2258 != -1) && (D_800F1BF8.unkB0 != NULL)) {
        func_80046494(0x200, D_800F1BF8.unkB0, D_800F2258, 0x7F, 0);
    }
}

void func_80093A70(void)
{
    if (D_800F2258 != -1) {
        if (D_800F1BF8.unkB0 != 0) {
            func_800462E8(0x200, D_800F1BF8.unkB0, D_800F2258);
        }
    }
}

void func_80093AB4(void)
{
    D_800F2270 = 0;
    D_800F2272 = 0;
    D_800F227E = 0;
    D_800F2278 = 0;
    D_800F227A = 0;
    vs_main_bzero(D_800F1BAC, sizeof *D_800F1BAC);
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/2842C", func_80093B04);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/2842C", func_80093B68);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/2842C", func_80093E64);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/2842C", func_80093F24);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/2842C", func_80093FEC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/2842C", func_8009406C);

INCLUDE_RODATA("build/src/BATTLE/BATTLE.PRG/nonmatchings/2842C", D_80068F04);

INCLUDE_RODATA("build/src/BATTLE/BATTLE.PRG/nonmatchings/2842C", D_80068F64);

INCLUDE_RODATA("build/src/BATTLE/BATTLE.PRG/nonmatchings/2842C", D_80068F94);

INCLUDE_RODATA("build/src/BATTLE/BATTLE.PRG/nonmatchings/2842C", D_80068FAC);

INCLUDE_RODATA("build/src/BATTLE/BATTLE.PRG/nonmatchings/2842C", D_800690B4);

INCLUDE_RODATA("build/src/BATTLE/BATTLE.PRG/nonmatchings/2842C", D_80069134);

INCLUDE_RODATA("build/src/BATTLE/BATTLE.PRG/nonmatchings/2842C", D_80069144);

INCLUDE_RODATA("build/src/BATTLE/BATTLE.PRG/nonmatchings/2842C", D_8006917C);

INCLUDE_RODATA("build/src/BATTLE/BATTLE.PRG/nonmatchings/2842C", D_800691E4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/2842C", func_800941FC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/2842C", func_80094844);

void func_80094AF8(D_800F1BAC_t* arg0)
{
    arg0->unkB = 0;
    arg0->unk6 = arg0->unk6 - 1;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/2842C", func_80094B0C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/2842C", func_80094E18);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/2842C", func_8009506C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/2842C", func_80095258);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/2842C", func_800957D0);

INCLUDE_RODATA("build/src/BATTLE/BATTLE.PRG/nonmatchings/2842C", D_80069240);

INCLUDE_RODATA("build/src/BATTLE/BATTLE.PRG/nonmatchings/2842C", D_80069250);

INCLUDE_RODATA("build/src/BATTLE/BATTLE.PRG/nonmatchings/2842C", D_80069258);

INCLUDE_RODATA("build/src/BATTLE/BATTLE.PRG/nonmatchings/2842C", D_8006925C);

INCLUDE_RODATA("build/src/BATTLE/BATTLE.PRG/nonmatchings/2842C", D_80069264);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/2842C", func_800958A4);

INCLUDE_RODATA("build/src/BATTLE/BATTLE.PRG/nonmatchings/2842C", D_80069288);

INCLUDE_RODATA("build/src/BATTLE/BATTLE.PRG/nonmatchings/2842C", D_80069290);

INCLUDE_RODATA("build/src/BATTLE/BATTLE.PRG/nonmatchings/2842C", D_80069298);

INCLUDE_RODATA("build/src/BATTLE/BATTLE.PRG/nonmatchings/2842C", D_800692A4);

INCLUDE_RODATA("build/src/BATTLE/BATTLE.PRG/nonmatchings/2842C", D_800692B4);

INCLUDE_RODATA("build/src/BATTLE/BATTLE.PRG/nonmatchings/2842C", D_800692C0);

INCLUDE_RODATA("build/src/BATTLE/BATTLE.PRG/nonmatchings/2842C", D_800692D0);

INCLUDE_RODATA("build/src/BATTLE/BATTLE.PRG/nonmatchings/2842C", D_800692D8);

INCLUDE_RODATA("build/src/BATTLE/BATTLE.PRG/nonmatchings/2842C", D_800692E0);

INCLUDE_RODATA("build/src/BATTLE/BATTLE.PRG/nonmatchings/2842C", D_80069300);

INCLUDE_RODATA("build/src/BATTLE/BATTLE.PRG/nonmatchings/2842C", D_80069308);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/2842C", func_80095A4C);

void func_80095B70(int arg0) { D_800F2270 = arg0; }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/2842C", func_80095B7C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/2842C", func_80095C18);

int func_80096254(int arg0, int arg1)
{
    return (((arg0 & 0xFFFF) + (arg1 & 0xFFFF)) & 0xFFFF)
         | (((arg0 >> 0x10) + (arg1 >> 0x10)) << 0x10);
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/2842C", func_8009627C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/2842C", func_800962E4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/2842C", func_8009639C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/2842C", func_80096444);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/2842C", func_8009651C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/2842C", func_80096768);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/2842C", func_8009695C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/2842C", func_80096FF0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/2842C", func_800970BC);

void func_800971D4(void)
{
    int i;
    D_800F1BAC_t* p = *D_800F1BAC;

    for (i = 0; i < D_800F227E; ++i, ++p) {
        if (p->unk8 == 7) {
            p->unk8 = 6;
        }
    }
}

void func_8009722C(void) { D_800F227A = 1; }
