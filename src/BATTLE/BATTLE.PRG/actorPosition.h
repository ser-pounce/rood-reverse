#pragma once
#include "tilePosition.h"
#include <sys/types.h>
#include <libgte.h>

typedef struct {
    vs_battle_tilePosition unk0;
    SVECTOR unk4;
} vs_battle_actorLocation;

typedef struct {
    vs_battle_actorLocation unk0;
    int unkC;
} vs_battle_actorPosition;
