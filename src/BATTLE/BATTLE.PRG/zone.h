#pragma once
#include "mpd.h"
#include "src/SLUS_010.40/main.h"
#include <sys/types.h>
#include <libgte.h>

typedef struct {
    u_char unk0[0x464];
} _zndEnemy;

typedef struct {
    u_char bytes[8];
} actorSpawnSettings;

typedef struct {
    u_char type;
    u_char index;
    u_char hidden;
    u_char unk3;
    u_char id;
    u_char slot;
    u_char flagTest;
    u_char statTest;
    u_short flagValue;
    u_short statValue;
    u_char x;
    u_char direction;
    u_char z;
    u_char height;
    actorSpawnSettings settings;
    u_char unk18[2];
    u_short itemId;
    u_short item2Id;
    u_short item3Id;
    u_char itemCount;
    u_char item2Count;
    u_char item3Count;
    u_char facing;
    u_char unk24;
    u_char variant;
    u_char unk26;
    u_char sceneTest;
} _mpdEnemy;

typedef struct {
    int zndId;
    vs_main_CdFile* mpdLbas;
    int zndEnemyCount;
    _zndEnemy* zndEnemies;
    vs_main_CdFile* zudFiles;
    int unk14;
    vs_main_CdQueueSlot* unk18;
    void* unk1C;
    vs_main_CdQueueSlot* zndCdFile;
    void* zndData;
    int musicId;
    int musicSlot;
    int unk30;
    int mapId;
    int unk38;
    short unk3C;
    short unk3E;
    _zoneContextBounds bounds;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    vs_main_CdQueueSlot* mpdCdFile;
    void* mpdData;
    u_int mpdEnemyCount;
    _mpdEnemy* mpdEnemies;
    int unk68;
} _zoneContext_t;

extern _zoneContext_t _zoneContext;
