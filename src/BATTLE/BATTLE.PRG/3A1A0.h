#pragma once
#include <libgte.h>

typedef struct {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
    short unk18;
    short unk1A;
    short unk1C;
    short unk1E;
    int unk20[15];
    char unk5C;
    char unk5D;
    char unk5E;
    char unk5F;
    char unk60[0x10C];
    int unk16C;
} D_800F45E0_t;

extern D_800F45E0_t* D_800F45E0[];

typedef struct {
    char unk0;
    char unk1;
    char unk2;
    char unk3;
} func_8006EBF8_t_fields;

typedef struct {
    union {
        func_8006EBF8_t_fields fields;
        int value;
    } unk0;
    short unk4;
    short unk6;
    short unk8;
    short unkA;
} func_8006EBF8_t3;

typedef struct {
    func_8006EBF8_t3 unk0;
    int unkC;
} func_8006EBF8_t;

typedef struct {
    char unk0_0;
    char unk0_8;
    char unk0_16;
    u_int unk0_24 : 8;
} func_80089888_t;

void func_800A1108(int, func_8006EBF8_t*);
void func_800A36E0(int, char, func_8006EBF8_t*);
void func_800A4D8C(void);
void func_800A30A0(int, func_80089888_t*, int, int);
void func_800A4828(int, void*);
void func_800A9D24(int, SVECTOR*, int);
