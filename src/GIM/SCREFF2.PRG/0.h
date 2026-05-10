#pragma once
#include "../../SLUS_010.40/main.h"

typedef struct {
    u_char unk0;
    u_char unk1;
    u_short unk2;
    short unk4;
    short unk6;
    int unk8;
    vs_main_CdQueueSlot* slot;
} D_800EB9B4_t;

void func_800F9800(int);
void func_800F986C(void);
void func_800F9BD8(void);
void func_800F9DE8(int);
void func_800F9FB8(void);

extern D_800EB9B4_t* D_800EB9B4;
