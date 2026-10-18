#include "18.h"

#define VS_SURFACE_FUNCTION vs_effect_flameSphere_0
#define VS_SURFACE_VERTICES D_800FCA90

#include "src/EFFECT/sphericalSurfaceVertices.h"

#include "src/EFFECT/surfaces.h"

#define VS_GRID_FUNCTION vs_effect_flameSphere_1
#include "src/EFFECT/grids.h"

#define VS_RING_FUNCTION vs_effect_flameSphere_2
#define VS_RING_COLORS D_800FCD10

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

#define VS_CLOSED_RING_FUNCTION vs_effect_flameSphere_3
#define VS_CLOSED_RING_COLORS D_800FCD30

static CVECTOR VS_CLOSED_RING_COLORS[] = {
    { 255, 255, 255 },
    { 128, 128, 128 },
    { 255, 128, 0 },
    { 0, 128, 255 },
    { 0, 255, 0 },
    { 255, 0, 255 },
    { 0, 128, 0 },
    { 128, 0, 128 },
};

#include "src/EFFECT/closedRings.h"
