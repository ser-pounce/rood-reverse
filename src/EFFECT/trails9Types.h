#pragma once
#include "src/BATTLE/BATTLE.PRG/5BF94.h"
#include <stddef.h>
#include <libgte.h>

typedef struct {
    SVECTOR splinePoints[4];
    u_char stepCount;
    u_char splineSampleCount;
    u_char trailCollapseCounter;
    u_char currentSplineSample;
    SVECTOR splineSamples[9];
    int splineProgress;
    int speed;
    int unk;
} vs_trail9;

typedef struct {
    u_char unk0;
    u_char unk1;
    u_char trailcount;
    u_char unk3;
    vs_trail9* trails;
    int curveSampleDistance;
    func_800D6CF_t unkC;
    u_char sampledTransparencyCurve[0];
} vs_trail9State;
