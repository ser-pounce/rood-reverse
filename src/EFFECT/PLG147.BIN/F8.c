#include "common.h"

#define VS_RING_FUNCTION func_800F98F8
#define VS_RING_COLORS D_800FBB10
#include "src/EFFECT/rings.h"

#define VS_PARTICLE_ORIGIN_FUNCTION func_800FA51C
#define VS_PARTICLE_TARGET_FUNCTION func_800FACA4
#define VS_PARTICLE_CORNER_STATE D_800FBB30
#include "src/EFFECT/particleSetup.h"

INCLUDE_ASM("build/src/EFFECT/PLG147.BIN/nonmatchings/F8", func_800FAEBC);

INCLUDE_ASM("build/src/EFFECT/PLG147.BIN/nonmatchings/F8", func_800FB36C);

INCLUDE_ASM("build/src/EFFECT/PLG147.BIN/nonmatchings/F8", func_800FB89C);
