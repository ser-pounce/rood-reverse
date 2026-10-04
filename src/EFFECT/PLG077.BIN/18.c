#include "common.h"

#define VS_MESH10_FUNCTION func_800F9818
#define VS_MESH10_VERTICES D_800FD908
#define VS_MESH10_FACES D_800FD958
#include "src/EFFECT/meshes10.h"

INCLUDE_ASM("build/src/EFFECT/PLG077.BIN/nonmatchings/18", func_800FA324);

#define VS_GRID_FUNCTION func_800FB294
#include "src/EFFECT/grids.h"

#define VS_SURFACE_FUNCTION func_800FBDE4
#define VS_SURFACE_VERTICES D_800FD9D8
#define VS_SURFACE_REPEAT
#include "src/EFFECT/surfaces.h"

INCLUDE_ASM("build/src/EFFECT/PLG077.BIN/nonmatchings/18", func_800FC97C);
