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
} mpdRoomCollisionMapSection_t;

typedef struct {
    u_int unk0_0 : 5;
    u_int unk0_5 : 1;
    u_int unk0_6 : 1;
    u_int unk0_7 : 1;
    u_int unk0_8 : 1;
    u_int unk0_9 : 1;
    u_int unk0_10 : 3;
    u_int unk0_13 : 1;
    u_int unk0_14 : 1;
    u_int unk0_15 : 1;
    u_int unk0_16 : 1;
    u_int unk0_17 : 1;
    u_int unk0_18 : 2;
    u_int unk0_20 : 12;
} mpdRoomSection3_t;

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
} mpdRoomSection9_t;

typedef struct {
    mpdRoomSection9_t unk0;
    short keyOrSigil;
    short unkE;
    short unk10;
    char unk12;
    char unk13;
} mpdRoomSectionA_t;

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
} mpdRoomSectionB_t;

typedef struct {
    int unk0;
    int unk4;
    int unk8;
    int* unkC;
    int* unk10;
    int unk14[0];
} mpdRoomSectionE_t;

typedef struct {
    int visited;
    void* dataAddress;
    short zoneId;
    short mapId;
} vs_battle_room;

typedef struct {
    int roomCount;
    vs_battle_room rooms[0];
} vs_battle_scene;

typedef struct {
    u_short unk0_0 : 5;
    u_short unk0_5 : 5;
    u_short unk0_10 : 1;
    u_short unk0_11 : 3;
    u_short unk0_14 : 1;
    u_short unk0_15 : 1;
    u_short unk2;
    char unk4[0];
} mpdRoomSection11_t;

typedef struct {
    u_int unk0_0 : 8;
    u_int unk0_8 : 1;
    u_int unk0_9 : 1;
    u_int unk0_10 : 2;
    u_int unk0_12 : 2;
    u_int unk0_14 : 2;
    u_int unk0_16 : 7;
    u_int unk0_23 : 3;
    u_int unk0_26 : 1;
    u_int unk0_27 : 2;
    u_int unk0_29 : 3;
    u_int unk4_0 : 1;
    u_int unk4_1 : 7;
    u_int unk4_8 : 2;
    u_int unk4_10 : 6;
    u_int unk4_16 : 16;
    VECTOR unk8[4];
    VECTOR unk48[6];
    int unkA8;
    int unkAC;
    int unkB0;
    mpdRoomSection3_t unkB4;
} mpdRoomSection12_t;

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
    vs_battle_loot unk14;
} mpdRoomSection13_t;

typedef struct {
    short minX;
    short minZ;
    short maxX;
    short maxZ;
} zoneContextBounds_t;

typedef struct {
    char unk0;
    char unk1;
    short unk2;
    struct {
        u_int geometrySectionLen;
        u_int collisionMapSectionLen;
        u_int section3Len;
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
        u_int section12Len;
        u_int section13Len;
        u_int akaoSectionLen;
        u_int section15Len;
        u_int section16Len;
        u_int section17Len;
        u_int section18Len;
    } header;
    int* geometrySection;
    mpdRoomCollisionMapSection_t* collisionMapSection;
    mpdRoomSection3_t* section3;
    vs_main_warp_t* doorSection;
    int lightingSection;
    int section6;
    int section7;
    int section8;
    mpdRoomSection9_t* section9;
    mpdRoomSectionA_t* sectionA;
    mpdRoomSectionB_t* sectionB;
    void* textureEffectsSection;
    void* sectionD;
    mpdRoomSectionE_t* sectionE;
    vs_battle_scene* sectionF;
    u_short* section10;
    mpdRoomSection11_t* section11;
    mpdRoomSection12_t* section12;
    mpdRoomSection13_t* section13;
    u_int* section14;
    int section15;
    int section16;
    int section17;
    zoneContextBounds_t* section18;
} mpdRoomSection_t;

typedef struct {
    int vertexCount;
    SVECTOR vertices[0];
} vs_battle_roomVertices;

typedef struct {
    char name[32];
    short prev;
    short next;
} vs_battle_roomName;

/**
 * Retrieves room ID, only used for teleporting.
 *
 * @return Unique room ID from 0-511.
 */
int vs_battle_getCurrentRoomId(void);
mpdRoomSection3_t* func_8008B764(u_int arg0, u_int arg1, int arg2);
void vs_battle_setRoomsUnk0(vs_battle_scene*);
int vs_battle_getCurrentSceneId(void);
extern mpdRoomSection_t vs_battle_roomData;

void vs_battle_setDoorEntered(void);
int vs_battle_inWorkshop(void);
int vs_battle_getMapCompletion(void);
int func_8008E7BC(int, int, u_int);
extern int vs_battle_mapCompletionFlags[];
extern vs_main_warp_t vs_battle_spawnPoint;
extern short vs_battle_doorEntered;
extern void* vs_battle_sceneBuffer;
