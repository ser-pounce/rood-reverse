#pragma once

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

void func_800A36E0(int, char, int*);
void func_800A4D8C(void);
short func_800E6694(int);
