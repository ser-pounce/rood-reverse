#include "0.h"

#define VS_ROTATING_SURFACE_FUNCTION vs_effect_tornado_0
#include "src/EFFECT/rotatingSurfaces.h"

#define VS_RING_FUNCTION vs_effect_tornado_1
#define VS_RING_COLORS D_800FC24C

static CVECTOR VS_RING_COLORS[] = {
    { 255, 255, 255 },
    { 128, 128, 128 },
    { 255, 128, 0 },
    { 0, 128, 255 },
    { 0, 255, 0 },
    { 255, 0, 255 },
    { 0, 128, 0 },
    { 128, 0, 128 },
};

#include "src/EFFECT/rings.h"

#define VS_CLOSED_RING_FUNCTION vs_effect_tornado_2
#define VS_CLOSED_RING_TEXTURE_COLUMNS 4
#include "src/EFFECT/closedRings.h"
