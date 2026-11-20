#pragma once
#include "src/SLUS_010.40/cd.h"
#include <sys/types.h>

typedef struct {
    u_char loading;
    u_char blurActive;
    u_short blurDepth;
    short lensZoom; // ONE = normal
    short lensDistortion; // negative = barrel, positive = pincushion
    int edgeGlow;
    vs_CdQueueSlot* slot;
} ScreenEffects;

void setScreenBlurDepth(int);
void drawScreenBlur(void);
void setScreenLensDistortion(short, short);
void applyScreenLensDistortion(void);
void setScreenEdgeGlow(int);
void drawScreenEdgeGlow(void);

extern ScreenEffects* screenEffects;
