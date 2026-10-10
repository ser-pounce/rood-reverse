#include "common.h"
#include "src/BATTLE/BATTLE.PRG/5BF94.h"
#include "src/SLUS_010.40/32154.h"
#include "vs_inline_c.h"
#include "gpu.h"
#include <inline_c.h>
#include <rand.h>

#define VS_MIRROR_SURFACE_FUNCTION func_800F9818
#define VS_MIRROR_SURFACE_VERTICES D_800FE5C4
#include "src/EFFECT/mirroredSurfaces.h"

#define VS_ROTATING_SURFACE_REPEAT
#define VS_ROTATING_SURFACE_FUNCTION func_800FA48C
#include "src/EFFECT/rotatingSurfaces.h"

#define VS_RING_FUNCTION func_800FB348
#define VS_RING_COLORS D_800FE844
#define VS_RING_TRANSPOSED
#include "src/EFFECT/rings.h"

#define VS_GRID_FUNCTION func_800FBF6C
#include "src/EFFECT/grids.h"

#define VS_SURFACE_FUNCTION func_800FCABC
#define VS_SURFACE_VERTICES D_800FE864
#define VS_SURFACE_REPEAT
#include "src/EFFECT/surfaces.h"

#define VS_CLOSED_RING_FUNCTION func_800FD654
#define VS_CLOSED_RING_COLORS D_800FEAE4
#define VS_CLOSED_RING_TEXTURE_COLUMNS 4
#include "src/EFFECT/closedRings.h"
