#pragma once
#include "func_8006EBF8_t.h"

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
    char unk0_0;
    char unk0_8;
    char unk0_16;
    u_int unk0_24 : 8;
} func_80089888_t;

typedef struct {
    char unk0;
    char unk1;
    char unk2;
    char unk3;
    int unk4;
    char unk8_0 : 1;
    char unk8_1 : 1;
    char unk8_2 : 1;
    char unk8_3 : 1;
    char unk8_4 : 1;
    char unk8_5 : 3;
    union {
        struct {
            u_char unk0_0 : 4;
            u_char unk0_4 : 1;
            u_char unk0_5 : 3;
        } u0;
        struct {
            u_char unk0_0 : 4;
            u_char unk0_4 : 4;
        } u1;
    } unk9;
    u_char unkA_0 : 7;
    u_char unkA_7 : 1;
    u_char unkB_0 : 4;
    u_char unkB_4 : 4;
    u_char unkC;
    u_char unkD;
    u_char unkE;
    u_char unkF;
    u_char unk10;
    u_char unk11;
    u_char unk12;
    u_char unk13;
    int unk14;
    int unk18;
    short unk1C;
    short unk1E;
    short unk20;
    short unk22;
    int unk24[18];
    int unk6C[42][8];
    int unk5AC;
    u_char unk5B0;
    u_char unk5B1;
    u_char unk5B2;
    u_char unk5B3;
    u_char unk5B4;
    u_char unk5B5;
    u_char unk5B6;
    u_char unk5B7;
    u_char unk5B8;
    u_char unk5B9;
    u_char unk5BA;
    u_char unk5BB;
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
    int unk5E0;
    int unk5E4;
    int unk5E8;
    int unk5EC[0x17];
    int unk648;
    int unk64C[0x25];
    u_char unk6E0;
    u_char unk6E1;
    u_char unk6E2;
    u_char unk6E3;
    short unk6E4;
    short unk6E6;
    short unk6E8[6];
    signed char unk6F4;
    signed char unk6F5;
    signed char unk6F6;
    u_char unk6F7;
    int unk6F8;
    int unk6FC;
    int unk700;
    u_char unk704[0x550];
    u_char unkC54[0x540];
    short unk1194;
    short unk1196;
    int unk1198[0x199];
    u_char unk17FC;
    u_char unk17FD;
    u_char unk1800[0x4A];
    u_char unk1848;
    u_char unk1849;
    u_char unk184A;
    u_char unk184B;
    u_short unk184C;
    u_short unk184E;
    u_int unk1850;
    u_char unk1854[0x28];
    int unk187C;
} func_800A2C48_t;

void func_800A1108(int, func_8006EBF8_t*);
void func_800A36E0(int, char, func_8006EBF8_t*);
void func_800A4D8C(void);
void func_800A30A0(int, func_80089888_t*, int, int);
void func_800A35A8(void);
void func_800A4828(int, MATRIX*);
void func_800A9D24(int, SVECTOR*, int);

extern func_800A2C48_t* D_800F4588[];
