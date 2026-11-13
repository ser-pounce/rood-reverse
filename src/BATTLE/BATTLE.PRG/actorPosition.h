#pragma once
#include "tilePosition.h"
#include <sys/types.h>
#include <libgte.h>

typedef struct {
    vs_TilePosition unk0;
    SVECTOR unk4;
} ActorLocation;

typedef struct {
    ActorLocation unk0;
    int unkC;
} vs_ActorPosition;
