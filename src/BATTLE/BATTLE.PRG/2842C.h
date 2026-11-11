#pragma once
#include "objectData.h"
#include <stddef.h>
#include <libgte.h>
#include <libgpu.h>

typedef struct {
    RECT uv;
    CVECTOR colors[4];
} BackgroundTile;

typedef struct {
    int width;
    int height;
    int unk8;
    BackgroundTile tiles[0];
} BackgroundLayout;

extern vs_ObjectData vs_battle_objectDataSlots[16];
