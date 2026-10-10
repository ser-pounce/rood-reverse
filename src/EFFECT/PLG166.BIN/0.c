#include "common.h"
#include "src/BATTLE/BATTLE.PRG/5BF94.h"
#include "src/SLUS_010.40/32154.h"
#include "vs_inline_c.h"
#include "gpu.h"
#include <inline_c.h>
#include <rand.h>

#define VS_ROTATING_SURFACE_FUNCTION func_800F9800
#include "src/EFFECT/rotatingSurfaces.h"

#define VS_MIRROR_SURFACE_FUNCTION func_800FA6B8
#define VS_MIRROR_SURFACE_VERTICES D_800FCEC0
#include "src/EFFECT/mirroredSurfaces.h"

#define VS_CLOSED_RING_FUNCTION func_800FB32C
#define VS_CLOSED_RING_COLORS D_800FD140
#define VS_CLOSED_RING_TEXTURE_COLUMNS 4
#include "src/EFFECT/closedRings.h"

#define VS_RING_FUNCTION func_800FC29C
#define VS_RING_COLORS D_800FD160
#define VS_RING_TRANSPOSED
#include "src/EFFECT/rings.h"
