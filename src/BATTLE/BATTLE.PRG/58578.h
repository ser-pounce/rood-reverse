#pragma once
#include <stddef.h>
#include <libgte.h>
#include "573B8.h"

typedef struct {
    char unk0;
    char unk1;
    char unk2;
    char unk3;
    short unk4;
    char unk6;
    char unk7;
    int unk8;
    int unkC;
    char* limbName;
} D_800EB9B8_unk990;

typedef struct {
    func_800C1564_t unk0[2];
    short unk20;
    short unk22;
    short unk24;
    short unk26;
    short unk28;
    short unk2A;
    char unk2C;
    char unk2D;
    char unk2E;
    char unk2F;
    signed char unk30;
    char unk31;
    short unk32;
    int unk34;
    SVECTOR unk38;
    func_800C5798_t* unk40;
    func_800C5798_t* unk44;
    menuShapeVertex unk48[297];
    D_800EB9B8_unk990 unk990[24];
    char unkB70[0x3800];
    int unk4370[81];
    short unk44B4[0x302];
    u_char unk4AB8[0x64];
} D_800EB9B8_t;

extern D_800EB9B8_t* D_800EB9B8;

int vs_battle_mapStickDeadZone(int);
int func_800C1564(func_800C1564_t* arg0, u_short* arg1);
void func_800C1664(int arg0, D_800F19CC_t5* arg1, int arg2);
void func_800C16DC();
void* func_800C282C(void);
void func_800C28AC(SVECTOR* position, int arg1);
void func_800C2B0C(SVECTOR* position, u_int row);
int func_800C4734(void);
void func_800C0D78(void);
