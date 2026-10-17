#include "common.h"

#define VS_RING_FUNCTION func_800F9800
#define VS_RING_COLORS D_800FD5A8
#define VS_RING_TRANSPOSED
#include "src/EFFECT/rings.h"

#define VS_MESH10_FUNCTION func_800FA424
#define VS_MESH10_VERTICES D_800FD5E8
#define VS_MESH10_FACES D_800FD638
#include "src/EFFECT/meshes10.h"

#define VS_SURFACE_FUNCTION func_800FAF30
#define VS_SURFACE_VERTICES D_800FD698
#define VS_SURFACE_TEXTURE_COLUMNS 4
#include "src/EFFECT/surfaces.h"

/* rings.h defines its state types unguarded, so rename them for this second copy. */
#define vs_ringState vs_ringState2
#define vs_ringPrim vs_ringPrim2
#define VS_RING_FUNCTION func_800FBAC8
#define VS_RING_COLORS D_800FD918
#include "src/EFFECT/rings.h"
#undef vs_ringState
#undef vs_ringPrim

#define VS_ROTATING_SURFACE_TEXTURE_COLUMNS 4
#define VS_ROTATING_SURFACE_FUNCTION func_800FC6EC
#include "src/EFFECT/rotatingSurfaces.h"
