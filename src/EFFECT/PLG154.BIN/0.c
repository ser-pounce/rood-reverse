#include <stddef.h>
#include <libgte.h>

#define VS_MESH10_FUNCTION func_800F9800
#define VS_MESH10_VERTICES D_800FB29C
#define VS_MESH10_FACES D_800FB2EC

// Dupe of D_800FB34C below
static CVECTOR D_800FB27C[]
    __attribute__((unused)) = { { 255, 255, 255 }, { 128, 128, 128 }, { 255, 128, 0 },
        { 0, 128, 255 }, { 0, 255, 0 }, { 255, 0, 255 }, { 0, 128, 0 }, { 128, 0, 128 } };

static SVECTOR VS_MESH10_VERTICES[] = { { 0, -ONE, 0, 0 },
    { ONE * 0.7698, ONE / 3, 0, 0 }, { -ONE * 0.3846, ONE / 3, ONE * 0.6668, 0 },
    { -ONE * 0.3858, ONE / 3, -ONE * 0.6663, 0 }, { ONE * 0.3848, -ONE / 3, 0, 1 },
    { ONE * 0.1927, ONE / 3, ONE / 3, 1 }, { -ONE * 0.1922, -ONE / 3, ONE / 3, 1 },
    { -ONE * 0.1929, -ONE / 3, -ONE * 0.3331, 1 },
    { ONE * 0.1920, ONE / 3, -ONE * 0.3331, 1 }, { -ONE * 0.3851, ONE / 3, 0, 1 } };

static u_char VS_MESH10_FACES[][6] = { { 0, 4, 6, 0, 2, 4 }, { 4, 5, 6, 2, 8, 4 },
    { 4, 1, 5, 2, 6, 8 }, { 6, 5, 2, 4, 8, 10 }, { 0, 6, 7, 0, 2, 4 },
    { 6, 9, 7, 2, 8, 4 }, { 6, 2, 9, 2, 6, 8 }, { 7, 9, 3, 4, 8, 10 },
    { 0, 7, 4, 0, 2, 4 }, { 7, 8, 4, 2, 8, 4 }, { 7, 3, 8, 2, 6, 8 },
    { 4, 8, 1, 4, 8, 10 }, { 1, 8, 5, 0, 2, 4 }, { 8, 9, 5, 2, 8, 4 },
    { 8, 3, 9, 2, 6, 8 }, { 5, 9, 2, 4, 8, 10 } };

#include "src/EFFECT/meshes10.h"

#define VS_CLOSED_RING_FUNCTION func_800FA30C
#define VS_CLOSED_RING_COLORS D_800FB34C
#define VS_CLOSED_RING_TEXTURE_COLUMNS 4

static CVECTOR VS_CLOSED_RING_COLORS[] = { { 255, 255, 255 }, { 128, 128, 128 },
    { 255, 128, 0 }, { 0, 128, 255 }, { 0, 255, 0 }, { 255, 0, 255 }, { 0, 128, 0 },
    { 128, 0, 128 } };

#include "src/EFFECT/closedRings.h"
