#pragma once

#include "common.h"
#include "inventory.h"
#include "main.h"
#include "gpu.h"
#include <sys/file.h>

enum slotState_e {
    slotStateUnavailable = 0,
    slotStateAvailable = 1,
    slotStateTemporary = 2,
    slotStateInUse = 3
};

/** Save format revision, a BCD date: 2000-01-07. */
#define SAVE_FORMAT_VERSION 0x20000107

typedef struct {
    enum slotState_e slotState;
    u_int generation;
    int version;
} saveBase_t;

typedef struct {
    vs_Gametime_t gameTime;
    u_short cumulativeSaveCount;
    u_short currentGameSaveCount;
    u_short currentHP;
    u_short maxHP;
    char saveLocation;
    char clearCount;
    char mapCompletion;
    char unk1B;
    u_short currentMP;
    u_short maxMP;
} stats_t;

typedef struct {
    char magic[2]; // "SC"
    u_char iconFlag; // 0x11..0x13: icon frame count
    u_char blockCount;
    u_short title[32]; // Shift-JIS
    char reserved44[0xC];
    char pocketStationHeader[0x10];
    char iconPalette[0x20];
} saveTitleFrame_t;

typedef struct {
    int key;
    saveBase_t base;
} saveIdentity_t;

typedef struct {
    saveIdentity_t identity;
    stats_t stats;
    char checksums[0x5C];
} saveInfoFrame_t;

typedef struct {
    saveTitleFrame_t titleFrame;
    char iconFrame0[0x80];
    char pocketStationIcon[0x80];
    saveInfoFrame_t info;
    char stateFlags[0x440];
    char actionsLearned[32];
    char mapStatus[0x48];
    vs_main_settings_t settings;
    vs_main_characterSnapshot_t character;
    vs_main_inventory_t inventory;
    vs_main_inventoryIndices_t inventoryIndices;
    vs_main_warp_t spawnPoint;
    vs_main_scoredata_t scoreData;
    int zoneEnemyCacheIndex;
    vs_main_zoneEnemyCache_t zoneEnemyCache[4];
    vs_main_artsStatus_t artsStatus;
    vs_menu_containerData containerData;
    char pad[0x220];
} savedata_t;

enum fileMenuElementState_e {
    fileMenuElementStateInactive = 0,
    fileMenuElementStateStatic = 1,
    fileMenuElementStateAnimateX = 2,
    fileMenuElementStateAnimateY = 3,
    fileMenuElementStateAnimateNegX = 4
};

typedef struct {
    char state;
    char slotId;
    char outertextBlendFactor;
    char innertextBlendFactor;
    char selected;
    char slotUnavailable;
    char saveLocation;
    char unk7;
    short targetPosition;
    short unkA;
    short x;
    short y;
    short w;
    short h;
    char text[32];
} fileMenuElements_t;

typedef struct {
    u_long tag;
    union {
        VS_SPRT sprt;
        VS_TILE_TPAGE tile_tpage;
        VS_TILE tile;
        VS_POLY_G4_TPAGE polyG4_tpage;
        VS_POLY_G4 polyG4;
        struct {
            VS_TILE_TPAGE tile;
            VS_POLY_G4 polyG4;
        } tilePoly;
        u_long raw[15];
    } prim;
} primBuf_t;

typedef struct {
    u_short locationCluts[2][256];
    char iconPalettes[7][32];
    char iconBitmaps[7][128];
    char pocketStationIcons[7][128];
    // MCDATA.BIN is 0xBE0 bytes and MCMAN.BIN is read in at the next sector boundary
    UNUSED char _[0x420];
} mcdata_t;
