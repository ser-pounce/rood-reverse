#pragma once
#include "src/SLUS_010.40/cd.h"
#include <sys/types.h>

typedef struct {
    u_char loading;
    u_char blurActive;
    u_short blurDepth;
    short unk4;
    short unk6;
    int edgeGlow;
    vs_CdQueueSlot* slot;
} ScreenEffects;

void setScreenBlurDepth(int);
void drawScreenBlur(void);
void func_800F9BC0(short, short);
void func_800F9BD8(void);
void setScreenEdgeGlow(int);
void drawScreenEdgeGlow(void);

extern ScreenEffects* screenEffects;
