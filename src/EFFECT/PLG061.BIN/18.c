#include "common.h"
#include "src/BATTLE/BATTLE.PRG/5BF94.h"
#include "src/SLUS_010.40/32154.h"
#include "vs_inline_c.h"
#include "gpu.h"
#include <inline_c.h>
#include <rand.h>

#define VS_SURFACE_FUNCTION func_800F9818
#define VS_SURFACE_VERTICES D_800FCA90
#include "src/EFFECT/surfaces.h"

#define VS_GRID_FUNCTION func_800FA3B0
#include "src/EFFECT/grids.h"

#define VS_RING_FUNCTION func_800FAF00
#define VS_RING_COLORS D_800FCD10
#include "src/EFFECT/rings.h"

#define VS_CLOSED_RING_FUNCTION func_800FBB24
#define VS_CLOSED_RING_COLORS D_800FCD30
#include "src/EFFECT/closedRings.h"
