#pragma once
#include "src/SLUS_010.40/cd.h"
#include <sys/types.h>

typedef struct {
    u_char unk0;
    u_char unk1;
    u_short unk2;
    short unk4;
    short unk6;
    int edgeGlow;
    vs_CdQueueSlot* slot;
} D_800EB9B4_t;

void func_800F9800(int);
void func_800F986C(void);
void func_800F9BC0(short, short);
void func_800F9BD8(void);
void setScreenEdgeGlow(int);
void drawScreenEdgeGlow(void);

extern D_800EB9B4_t* D_800EB9B4;
