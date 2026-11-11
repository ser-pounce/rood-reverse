#pragma once
#include "tilePosition.h"
#include <sys/types.h>
#include <libgte.h>

typedef struct {
    vs_battle_tilePosition unk0;
    SVECTOR unk4;
} vs_ActorLocation;

typedef struct {
    vs_ActorLocation unk0;
    int unkC;
} vs_ActorPosition;
