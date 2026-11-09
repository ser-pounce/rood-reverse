#pragma once
#include "common.h"
#include "tilePosition.h"
#include <sys/types.h>

typedef struct {
    u_char index;
    u_char hidden;
    short actorState;
    short currentHP;
    short maxHP;
    short currentMP;
    short maxMP;
    short strength;
    short intelligence;
    short agility;
    short limbHP[6];
    UNUSED short _;
    int statuses;
    vs_battle_tilePosition tile;
} vs_main_savedEnemyState_t;

typedef struct {
    char lru;
    char zndId;
    u_short mapId;
    u_int nextSlot;
    vs_main_savedEnemyState_t state[8];
} vs_main_zoneEnemyCache_t;

typedef struct {
    u_short x : 5;
    u_short z : 5;
    u_short surface : 3;
    u_short arrivalSurface : 3;
} vs_main_targetTile_t;

typedef struct {
    u_char zndId;
    u_char mpdId;
    vs_main_targetTile_t targetTile;
    u_short unlockValue : 8;
    u_short x : 5;
    u_short facing : 2;
    u_short walkForward : 1;
    u_short unlockFlag : 10;
    u_short z : 5;
    u_short faceCamera : 1;
    u_char doorId;
    UNUSED u_char _[3];
} vs_main_warp_t;

// Avoids breaking .bss order
#ifndef VS_MAIN_INCLUDE
extern int vs_main_zoneEnemyCacheIndex;
extern vs_main_warp_t vs_main_spawnPoint;
extern vs_main_zoneEnemyCache_t vs_main_zoneEnemyCache[4];
#endif
