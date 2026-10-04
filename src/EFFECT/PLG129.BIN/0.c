#include "common.h"

#define VS_RING_FUNCTION func_800F9800
#define VS_RING_COLORS D_800FD5A8
#define VS_RING_TRANSPOSED
#include "src/EFFECT/rings.h"

INCLUDE_ASM("build/src/EFFECT/PLG129.BIN/nonmatchings/0", func_800FA424);

INCLUDE_ASM("build/src/EFFECT/PLG129.BIN/nonmatchings/0", func_800FAF30);

#define VS_RING_FUNCTION func_800FBAC8
#define VS_RING_COLORS D_800FD918
#include "src/EFFECT/rings.h"

INCLUDE_ASM("build/src/EFFECT/PLG129.BIN/nonmatchings/0", func_800FC6EC);
