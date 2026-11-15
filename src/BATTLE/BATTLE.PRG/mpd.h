#pragma once
#include "loot.h"
#include "src/SLUS_010.40/zoneState.h"
#include <sys/types.h>
#include <libgte.h>

typedef struct {
    short width;
    short height;
    short unk4;
    short unk6;
} MpdRoomCollisionMapSection;

enum MpdTileShape {
    tileShapeFull,
    tileShapeTriangle0,
    tileShapeTriangle1,
    tileShapeTriangle2,
    tileShapeTriangle3,
    tileShapeBlocked
};

typedef struct {
    u_int unk0_0 : 5;
    u_int unk0_5 : 1;
    u_int unk0_6 : 1;
    u_int unk0_7 : 1;
    u_int unk0_8 : 1;
    u_int unk0_9 : 1;
    u_int shape : 3;
    u_int unk0_13 : 1;
    u_int unk0_14 : 1;
    u_int unk0_15 : 1;
    u_int unk0_16 : 1;
    u_int unk0_17 : 1;
    u_int unk0_18 : 2;
    u_int unk0_20 : 12;
} MpdTile;

typedef struct {
    short unk0;
    short unk2;
    short unk4;
    short unk6;
    union {
        short s16;
        struct {
            char state;
            char unk1;
        } lock;
    } unk8;
    char unkA;
    char unkB;
} MpdRoomSection9;

typedef struct {
    MpdRoomSection9 unk0;
    short keyOrSigil;
    short unkE;
    short unk10;
    char unk12;
    char unk13;
} MpdRoomSectionA;

typedef struct {
    int unk0[5];
    VECTOR unk14;
    int unk24;
    int unk28;
    int unk2C;
    char isWorkshop;
    char unk31;
    char trapLevel;
    char unk33;
    short unk34;
    short unk36;
    short unk38;
    short unk3A;
    short unk3C;
    short unk3E;
    short unk40;
    short unk42;
    short unk44;
    short unk46;
    union {
        short s16[2];
        int s32;
    } unk48[2];
    short sceneId;
    short unk52;
    short unk54;
    short unk56;
} MpdRoomSectionB;

typedef struct {
    int unk0;
    int unk4;
    int unk8;
    int* unkC;
    int* unk10;
    int unk14[0];
} MpdRoomSectionE;

typedef struct {
    int visited;
    void* dataAddress;
    short zoneId;
    short mapId;
} vs_Room;

typedef struct {
    int roomCount;
    vs_Room rooms[0];
} vs_Scene;

typedef struct {
    u_short unk0_0 : 5;
    u_short unk0_5 : 5;
    u_short unk0_10 : 1;
    u_short unk0_11 : 3;
    u_short unk0_14 : 1;
    u_short unk0_15 : 1;
    u_short unk2;
    char unk4[0];
} MpdRoomSection11;

typedef struct {
    u_int geometryId : 8;
    u_int needsRider : 1;
    u_int stopped : 1;
    u_int lastWaypoint : 2;
    u_int unk0_12 : 2;
    u_int fromWaypoint : 2;
    u_int unk0_16 : 7;
    u_int unk0_23 : 3;
    u_int pathDirection : 1; // 1 = heading to a higher waypoint, 0 = to a lower one
    u_int toWaypoint : 2;
    u_int leg : 3;
    u_int docked : 1; // 1 = waiting at a waypoint, 0 = travelling
    u_int rider : 7; // actor standing on it, 0x7F = nobody
    u_int startWaypoint : 2;
    u_int unk4_10 : 6;
    u_int timer : 16;
    VECTOR waypoints[4]; // pad = frames to wait there
    VECTOR legs[6]; // movement per step, pad = number of steps
    int x;
    int y;
    int z;
    MpdTile unkB4;
} MpdCloudstone;

typedef struct {
    short unk0;
    short unk2;
    short unk4;
    short unk6;
    short unk8;
    short unkA;
    short unkC;
    short unkE;
    short unk10;
    short unk12;
    vs_Loot unk14;
} MpdRoomSection13;

typedef struct {
    short minX;
    short minZ;
    short maxX;
    short maxZ;
} ZoneContextBounds;

typedef struct {
    char unk0;
    char unk1;
    short unk2;
    struct {
        u_int geometrySectionLen;
        u_int collisionMapSectionLen;
        u_int tileMapLen;
        u_int doorSectionLen;
        u_int lightingSectionLen;
        u_int section6Len;
        u_int section7Len;
        u_int section8Len;
        u_int section9Len;
        u_int sectionALen;
        u_int sectionBLen;
        u_int textureEffectsSectionLen;
        u_int sectionDLen;
        u_int sectionELen;
        u_int sectionFLen;
        u_int section10Len;
        u_int section11Len;
        u_int cloudstoneSectionLen;
        u_int section13Len;
        u_int akaoSectionLen;
        u_int section15Len;
        u_int section16Len;
        u_int section17Len;
        u_int section18Len;
    } header;
    int* geometrySection;
    MpdRoomCollisionMapSection* collisionMapSection;
    MpdTile* tileMap;
    vs_Warp* doorSection;
    int lightingSection;
    int section6;
    int section7;
    int section8;
    MpdRoomSection9* section9;
    MpdRoomSectionA* sectionA;
    MpdRoomSectionB* sectionB;
    void* textureEffectsSection;
    void* sectionD;
    MpdRoomSectionE* sectionE;
    vs_Scene* sectionF;
    u_short* section10;
    MpdRoomSection11* section11;
    MpdCloudstone* cloudstoneSection;
    MpdRoomSection13* section13;
    u_int* section14;
    int section15;
    int section16;
    int section17;
    ZoneContextBounds* section18;
} MpdRoomSection;

typedef struct {
    int vertexCount;
    SVECTOR vertices[0];
} vs_RoomVertices;

typedef struct {
    char name[32];
    short prev;
    short next;
} vs_RoomName;

/**
 * Retrieves room ID, only used for teleporting.
 *
 * @return Unique room ID from 0-511.
 */
int vs_battle_getCurrentRoomId(void);
void vs_battle_setRoomsUnk0(vs_Scene*);
int vs_battle_getCurrentSceneId(void);
extern MpdRoomSection vs_battle_roomData;

void vs_battle_setDoorEntered(void);
int vs_battle_inWorkshop(void);
int vs_battle_getMapCompletion(void);
int func_8008E7BC(int, int, u_int);
extern int vs_battle_mapCompletionFlags[];
extern vs_Warp vs_battle_spawnPoint;
extern short vs_battle_doorEntered;
extern void* vs_battle_sceneBuffer;
