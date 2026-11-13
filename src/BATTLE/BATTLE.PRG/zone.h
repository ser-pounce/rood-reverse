#pragma once
#include "mpd.h"
#include "src/SLUS_010.40/cd.h"
#include <sys/types.h>
#include <libgte.h>

typedef struct {
    u_char unk0[0x464];
} ZndEnemy;

typedef struct {
    u_char bytes[8];
} ActorSpawnSettings;

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
    ActorSpawnSettings settings;
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
} MpdEnemy;

typedef struct {
    int zndId;
    vs_CdFile* mpdLbas;
    int zndEnemyCount;
    ZndEnemy* zndEnemies;
    vs_CdFile* zudFiles;
    int unk14;
    vs_CdQueueSlot* unk18;
    void* unk1C;
    vs_CdQueueSlot* zndCdFile;
    void* zndData;
    int musicId;
    int musicSlot;
    int unk30;
    int mapId;
    int unk38;
    short unk3C;
    short unk3E;
    ZoneContextBounds bounds;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    vs_CdQueueSlot* mpdCdFile;
    void* mpdData;
    u_int mpdEnemyCount;
    MpdEnemy* mpdEnemies;
    int unk68;
} ZoneContext;

extern ZoneContext zoneContext;
