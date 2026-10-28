#pragma once
#include "src/SLUS_010.40/main.h"
#include <sys/types.h>
#include <libgte.h>

typedef struct {
    short width;
    short height;
    short unk4;
    short unk6;
} _mpdRoomCollisionMapSection;

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
} _mpdRoomSection3;

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
} _mpdRoomSection9;

typedef struct {
    _mpdRoomSection9 unk0;
    short keyOrSigil;
    short unkE;
    short unk10;
    char unk12;
    char unk13;
} _mpdRoomSectionA;

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
} _mpdRoomSectionB;

typedef struct {
    int unk0;
    int unk4;
    int unk8;
    int* unkC;
    int* unk10;
    int unk14[0];
} _mpdRoomSectionE;

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
} _mpdRoomSection11;

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
    _mpdRoomSection3 unkB4;
} _mpdRoomSection12;

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
} _mpdRoomSection13;

typedef struct {
    short minX;
    short minZ;
    short maxX;
    short maxZ;
} _zoneContextBounds;

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
    _mpdRoomCollisionMapSection* collisionMapSection;
    _mpdRoomSection3* section3;
    _mpdRoomDoorSection_t* doorSection;
    int lightingSection;
    int section6;
    int section7;
    int section8;
    _mpdRoomSection9* section9;
    _mpdRoomSectionA* sectionA;
    _mpdRoomSectionB* sectionB;
    void* textureEffectsSection;
    void* sectionD;
    _mpdRoomSectionE* sectionE;
    vs_battle_scene* sectionF;
    u_short* section10;
    _mpdRoomSection11* section11;
    _mpdRoomSection12* section12;
    _mpdRoomSection13* section13;
    u_int* section14;
    int section15;
    int section16;
    int section17;
    _zoneContextBounds* section18;
} _mpdRoomSection;

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
_mpdRoomSection3* func_8008B764(u_int arg0, u_int arg1, int arg2);
void vs_battle_setRoomsUnk0(vs_battle_scene*);
int vs_battle_getCurrentSceneId(void);
extern _mpdRoomSection vs_battle_roomData;

void vs_battle_setDoorEntered(void);
int vs_battle_inWorkshop(void);
int vs_battle_getMapCompletion(void);
int func_8008E7BC(int, int, u_int);
extern int vs_battle_mapCompletionFlags[];
extern _mpdRoomDoorSection_t D_800F1AB0;
extern short vs_battle_doorEntered;
extern void* vs_battle_sceneBuffer;
