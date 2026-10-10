#include "common.h"
#include "src/BATTLE/BATTLE.PRG/5BF94.h"
#include "src/SLUS_010.40/32154.h"
#include "vs_inline_c.h"
#include "gpu.h"
#include <inline_c.h>
#include <rand.h>

#define VS_GRID_FUNCTION func_800F9818
#include "src/EFFECT/grids.h"

#define VS_CLOSED_RING_FUNCTION func_800FA368
#define VS_CLOSED_RING_COLORS D_800FCDB8
#define VS_CLOSED_RING_TEXTURE_COLUMNS 4
#include "src/EFFECT/closedRings.h"

#define VS_RING_FUNCTION func_800FB2D8
#define VS_RING_COLORS D_800FCDD8
#include "src/EFFECT/rings.h"

#define VS_ROTATING_SURFACE_REPEAT
#define VS_ROTATING_SURFACE_FUNCTION func_800FBEFC
#include "src/EFFECT/rotatingSurfaces.h"
