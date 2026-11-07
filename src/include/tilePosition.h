#pragma once
#include <sys/types.h>

typedef struct {
    u_char x;
    u_char surface;
    u_char z;
    u_char status;
} __attribute__((aligned(4))) vs_battle_tilePosition;

// A tile is often handled as a single 32-bit word: it is cleared by storing -1 (all
// bytes 0xFF, "no tile") and compared whole. The sign bit of the word is also tested to
// tell a set tile from the cleared one. The matching build does this with a word cast;
// NON_MATCHING builds use well-defined C instead.
#ifdef NON_MATCHING
#define VS_TILE_CLEAR(tile) \
    ((tile) = (vs_battle_tilePosition) { 0xFF, 0xFF, 0xFF, 0xFF })
#define VS_TILE_IS_SET(tile) ((tile).status < 0x80)
#define VS_TILE_EQ(a, b)                                                               \
    ((a).x == (b).x && (a).surface == (b).surface && (a).z == (b).z                  \
        && (a).status == (b).status)
#else
#define VS_TILE_CLEAR(tile) (*(int*)&(tile) = -1)
#define VS_TILE_IS_SET(tile) (*(int*)&(tile) >= 0)
#define VS_TILE_EQ(a, b) (*(int*)&(a) == *(int*)&(b))
#endif

// A copy of a tile that is compared against other tiles repeatedly, e.g. in a loop. The
// matching build keeps it in a register as a plain word.
#ifdef NON_MATCHING
typedef vs_battle_tilePosition vs_battle_tileKey;
#define VS_TILE_KEY(tile) (tile)
#define VS_TILE_KEY_EQ(key, tile) VS_TILE_EQ(key, tile)
#else
typedef int vs_battle_tileKey;
#define VS_TILE_KEY(tile) (*(int*)&(tile))
#define VS_TILE_KEY_EQ(key, tile) ((key) == *(int*)&(tile))
#endif
