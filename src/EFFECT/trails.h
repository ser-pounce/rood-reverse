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
    SVECTOR splineSamples[TRAIL_SAMPLE_COUNT];
    int splineProgress;
    int speed;
    int unk;
} _trail;

typedef struct {
    u_char unk0;
    u_char unk1;
    u_char trailcount;
    u_char unk3;
    _trail* trails;
    int unk8;
    func_800D6CF_t unkC;
    u_char sampledTransparencyCurve[0];
} func_800FA76C_arg3;
