#include "common.h"
#include "146C.h"

typedef struct {
    int* unk0;
    int unk4;
    short unk8;
} func_80092F74_t;

typedef struct {
    int* unk0;
    int unk4;
    short unk8;
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
void func_80091998(int);
void func_800919D8(int);
void func_8009291C(int);

extern short D_800F1D98[];
extern short D_800F1DB4;
extern short D_800F1DB6;
extern short D_800F1DC4;
extern char D_800F1DCB;
extern D_800F1DD8_t D_800F1DD8[];
extern short D_800F2270;
extern short D_800F227A;

INCLUDE_RODATA("build/src/BATTLE/BATTLE.PRG/nonmatchings/2842C", D_80068EB4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/2842C", func_80090C2C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/2842C", func_80090EEC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/2842C", func_800911B8);

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

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/2842C", func_80091378);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/2842C", func_800913BC);

void func_80091468(int arg0, int arg1)
{
    D_800F1DB4 = arg0;
    D_800F1DB6 = arg1;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/2842C", func_8009147C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/2842C", func_800918E8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/2842C", func_8009195C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/2842C", func_80091998);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/2842C", func_800919D8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/2842C", func_80091A1C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/2842C", func_80091A78);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/2842C", func_80091AC0);

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

int func_80092E14(func_80092F74_t* arg0, func_80092F74_t2* arg1);
INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/2842C", func_80092E14);

int func_80092E7C(func_80092F74_t* arg0, func_80092F74_t2* arg1);
INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/2842C", func_80092E7C);

int func_80092EDC(func_80092F74_t* arg0, func_80092F74_t2* arg1);
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
    func_80091998(arg1->unk4);
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

int func_800935B8(func_80092F74_t* arg0, func_80092F74_t2* arg1);
INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/2842C", func_800935B8);

int func_800935F8(func_80092F74_t* arg0 __attribute__((unused)), func_80092F74_t2* arg1)
{
    func_8009291C(arg1->unk4);
    return 0;
}

int func_8009361C(func_80092F74_t* unk0 __attribute__((unused)), func_80092F74_t2* arg1)
{
    func_800919D8(arg1->unk4);
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

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/2842C", func_80093A14);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/2842C", func_80093A70);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/2842C", func_80093AB4);

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

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/2842C", func_800971D4);

void func_8009722C(void) { D_800F227A = 1; }
