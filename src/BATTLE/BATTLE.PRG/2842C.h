#pragma once
#include "objectData.h"
#include <stddef.h>
#include <libgte.h>
#include <libgpu.h>

typedef struct {
    RECT uv;
    CVECTOR colors[4];
} vs_BackgroundTile;

typedef struct {
    int width;
    int height;
    int unk8;
    vs_BackgroundTile tiles[0];
} vs_BackgroundLayout;

extern vs_ObjectData vs_battle_objectDataSlots[16];
