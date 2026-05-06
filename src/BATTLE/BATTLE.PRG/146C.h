#pragma once
#include "../../SLUS_010.40/main.h"
#include "../../SLUS_010.40/D_80061068_t.h"
#include "2842C.h"

typedef struct {
    short width;
    short height;
    short unk4;
    short unk6;
} _mpdRoomCollisionMapSection;

typedef struct {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
    int unk18;
    int dataOffset;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
} _mpdGeometryHeader;

typedef struct {
    short p1x, p1y, p1z;
    char p2x, p2y, p2z;
    char p3x, p3y, p3z;
    char r1, g1, b1, type;
    char r2, g2, b2, u3;
    char r3, g3, b3, v3;
    char u1, v1;
    short texelMask;
    char u2, v2;
    short idTexture;
} _mpdPolygt3;

typedef struct {
    short p1x, p1y, p1z;
    char p2x, p2y, p2z;
    char p3x, p3y, p3z;
    char r1, g1, b1, type;
    char r2, g2, b2, u3;
    char r3, g3, b3, v3;
    char u1, v1;
    short texelMask;
    char u2, v2;
    short idTexture;
    char p4x, p4y, p4z, u4;
    char r4, g4, b4, v4;
} _mpdPolygt4;

typedef struct {
    int numGroups;
    _mpdGeometryHeader groups[0];
} _mpdGeometrySection;

typedef struct {
    u_int unk0_0 : 5;
    u_int unk0_5 : 3;
    u_int unk0_8 : 1;
    u_int unk0_9 : 1;
    u_int unk0_10 : 3;
    u_int unk0_13 : 3;
    u_int unk0_16 : 1;
    u_int unk0_17 : 1;
    u_int unk0_18 : 2;
    u_int unk0_19 : 12;
} _mpdRoomSection3;

typedef struct {
    u_short unk0_0 : 5;
    u_short unk0_5 : 5;
    u_short unk0_10 : 3;
    u_short unk0_13 : 3;
} _mpdRoomDoorSection2;

typedef struct {
    char targetZone;
    char targetRoom;
    _mpdRoomDoorSection2 unk2;
    int unk4;
    char unk8;
    char unk9;
    char unkA;
    char unkB;
} _mpdRoomDoorSection_t;

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
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    char isWorkshop;
    char unk31;
    char unk32;
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
    VECTOR unk8[10];
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
    int textureEffectsSection;
    int sectionD;
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
    short class[2][8];
    short affinity[2][8];
} vs_battle_classAffinityCurrent;

typedef struct {
    short class[8];
    u_short affinity[8];
} vs_battle_classAffinityBaseline;

typedef struct {
    u_short unk0[0x18];
} vs_battle_uiWeapon_unk;

typedef struct {
    u_short unk0;
    u_short unk2;
    char unk4;
    char unk5;
    char unk6;
    char unk7;
} func_80103080_t;

typedef struct {
    u_short id;
    signed char subId;
    signed char wepId;
    char category;
    signed char strength;
    signed char intelligence;
    signed char agility;
    u_short currentDp;
    u_short maxDp;
    u_short currentPp;
    u_short maxPp;
    char damageType; // 0x10
    char costType;
    char cost;
    char material;
    char unk14;
    char gemSlots;
    char gemEffects;
    char index;
    vs_battle_range_t range;
    signed char types[4];
    signed char classes[8];
    signed char affinities[8];
} vs_battle_uiEquipment;

typedef struct {
    char name[24];
    vs_battle_uiEquipment blade; // 0x18
    vs_battle_uiEquipment grip; // 0x48
    vs_battle_uiEquipment gems[3]; // 0x78
    char wepId;
    char damageTypeValue;
    char risk;
    char unk10B;
    char dropRate;
    u_char index;
    u_char damageType;
    u_char skillType;
    u_short currentPp;
    u_short maxPp;
    u_short currentDp;
    u_short maxDp;
    short currentStr;
    u_short baseStr;
    short currentInt;
    u_short baseInt;
    short currentAgility;
    u_short baseAgility;
    vs_battle_range_t range;
    vs_battle_classAffinityCurrent classAffinityCurrent;
    short unk168[8];
    vs_battle_classAffinityBaseline classAffinityBaseline;
} vs_battle_uiWeapon;

typedef struct {
    int unk0[6];
    vs_battle_uiEquipment base; // 0x18
    vs_battle_uiEquipment gems[3]; // 0x48
    char wepId; // 0xD8
    char dropRate;
    u_char index;
    char unkDB;
    u_short currentDp;
    u_short maxDp;
    u_short currentPp;
    u_short maxPp;
    short currentStr;
    u_short baseStr;
    short currentInt;
    u_short baseInt;
    short currentAgility;
    u_short baseAgility;
    char types[4];
    vs_battle_classAffinityCurrent classAffinityCurrent; // 0xF4
    short unk134[8];
    vs_battle_classAffinityBaseline classAffinityBaseline; // 0x144
} vs_battle_uiShield;

typedef struct {
    vs_battle_uiEquipment armor;
    u_short currentDp; // 0x30
    u_short maxDp;
    short currentStr;
    u_short baseStr;
    short currentInt;
    u_short baseInt;
    short currentAgility;
    u_short baseAgility;
    u_short types[4];
    vs_battle_classAffinityCurrent classAffinityCurrent;
    short unk88[8];
    char unk98;
    char unk99;
    u_char unk9A;
    u_char unk9B;
    vs_battle_classAffinityBaseline classAffinityBaseline;
} vs_battle_uiArmor;

typedef struct {
    short hp;
    short maxHp;
    signed char agilityDefenseBonus;
    char unk5;
    u_char nameIndex;
    char chainEvasion;
    short types[4];
    short affinities[8];
    vs_battle_uiArmor armor; // 0x18
} vs_battle_uiEquipment_bodyPart;

typedef struct {
    vs_battle_uiEquipment accessory;
    short currentStr;
    short currentInt;
    short currentAgility;
    char dropRate;
    u_char unk37;
    u_short types[4];
    u_short classes[8];
    u_short affinities[8];
} vs_battle_uiAccessory;

typedef struct {
    u_short id;
    char count;
    char unk3;
} vs_battle_uiMisc;

typedef struct {
    u_short id;
    char dropRate;
} vs_battle_uiMiscRand;

typedef struct {
    char unk0[0x5E8];
} vs_battle_actor4;

typedef struct {
    int unk0;
    int unk4;
    int unk8;
    char unkC[0x16C];
} vs_battle_actor3;

typedef struct {
    short unk0;
    char unk2_0 : 4;
    char unk2_4 : 4;
    char unk3;
} vs_battle_actor_unk8C0;

typedef struct {
    u_short unk0;
    char unk2_0 : 1;
    char unk2_1 : 1;
    char unk2_2 : 6;
    u_char unk3;
} vs_battle_actor2_flags;

typedef struct {
    char name[24];
    short currentHP;
    short maxHP;
    short currentMP;
    short maxMP;
    u_short risk;
    u_short strength;
    u_short totalStrength;
    u_short intelligence;
    u_short totalIntelligence;
    u_short agility;
    u_short totalAgility;
    char unk2E;
    char unk2F;
    char unk30;
    char unk31;
    char unk32;
    char unk33;
    u_int unk34 : 8;
    u_int unk35 : 8;
    u_int unk36 : 8;
    u_int enemyClass : 3;
    u_int reach : 5;
    u_int currentRange : 8;
    u_int unk39 : 8;
    u_int unk3A : 8;
    u_int unk3B_0 : 3;
    u_int currentAttackShapeAngle : 5;
    vs_battle_uiWeapon weapon; // 0x3C
    vs_battle_uiShield shield; // 1C4
    vs_battle_uiAccessory accessory; // 328
    vs_battle_uiEquipment_bodyPart bodyParts[6]; // 388
    vs_battle_actor_unk8C0 armor[6][4];
    char unk920[6][6];
    int unk944;
    int unk948;
    u_char unk94C[8];
    u_short unk954;
    u_char unk956_0 : 1;
    u_char unk956_1 : 1;
    u_char unk956_2 : 6;
    u_char unk957;
    vs_battle_uiMisc miscItem;
    int unk95C;
    vs_battle_uiMiscRand unk960;
} vs_battle_actor2;

typedef struct vs_battle_actor {
    /* 0x00 */ struct vs_battle_actor* next;
    /* 0x04 */ int id;
    /* 0x08 */ char unk8;
    /* 0x09 */ char unk9;
    /* 0x0A */ char unkA;
    /* 0x0B */ char unkB;
    /* 0x0C */ int unkC;
    union {
        char u8[4];
        int s32;
    /* 0x10 */ } unk10;
    int unk14;
    u_short unk18;
    u_short unk1A;
    u_short unk1C;
    char unk1E;
    char unk1F;
    int unk20;
    char unk24;
    char equippedWeaponCategory;
    char unk26;
    u_char unk27;
    char defeated;
    char unk29;
    char unk2A;
    char unk2B;
    union {
        char u8[4];
        int s32;
    } unk2C;
    int unk30;
    int unk34;
    int unk38;
    vs_battle_actor2* unk3C;
    int unk40;
    vs_battle_actor3* unk44;
    vs_battle_actor4* unk48[2];
} vs_battle_actor;

typedef struct {
    struct {
        vs_battle_actor unk0;
        vs_battle_actor2 unk50;
    } unk0;
    vs_battle_actor3 unk9B4;
} vs_battle_actor_dat2;

typedef struct {
    vs_battle_actor_dat2 unk0;
    char unkB2C[0x1788];
    vs_battle_actor4 unk22B4[2];
} vs_battle_actor_dat;

typedef struct {
    char id;
    char exit;
    char flags;
    char lock;
} vs_battle_door;

typedef struct {
    char p0;
    char p1;
    char p2;
    char p3;
} vs_battle_prim;

typedef struct {
    int vertexCount;
    SVECTOR vertices[0];
} vs_battle_roomVertices;

typedef struct {
    char name[32];
    short prev;
    short next;
} vs_battle_roomName;

typedef struct {
    u_short currentManual;
    u_short unk2;
    u_short scrollPositions[14];
    u_short unk20;
    char unk22;
    char unk23;
} vs_battle_manualDisplayState_t;

typedef struct {
    int unk0;
    RECT* unk4;
    u_long* unk8;
    RECT* unkC;
    u_short* unk10;
} func_80103530_t;

typedef struct {
    char unk0[0x464];
} _zndEnemy;

typedef struct {
    char unk0;
    char unk1;
    char unk2;
    char unk3;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
} _mpdEnemy;

typedef struct {
    int zndId;
    vs_main_CdFile* mpdLbas;
    int zndEnemyCount;
    _zndEnemy* zndEnemies;
    vs_main_CdFile* zudFiles;
    int unk14;
    int unk18;
    int unk1C;
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

typedef struct {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
} D_800F1A68_t;

typedef struct {
    u_short unk0_0 : 10;
    u_short unk0_10 : 6;
} D_800F18E8_t;

typedef struct {
    /* 0x00 */ VECTOR position;
    /* 0x10 */ VECTOR lookAt;
    /* 0x20 */ int pitch;
    /* 0x24 */ int yaw;
    /* 0x28 */ int unk5C;
    /* 0x2C */ int unk60;
    /* 0x30 */ int farClip;
} camera_t2;

typedef struct {
    /* 0x00 */ void* unk0;
    /* 0x04 */ void* unk4;
    /* 0x08 */ void* unk8;
    /* 0x0C */ int unkC;
    /* 0x10 */ u_int firstPersonViewFacing;
    /* 0x14 */ MATRIX viewMatrix;
    /* 0x34 */ camera_t2 t2;
} camera_t;

typedef struct {
    int yaw;
    int pitch;
    int distance;
    int mode;
} _sphericalValues;

typedef struct {
    _sphericalValues values;
    _sphericalValues delta;
    int initialDistance;
    int unk24;
    int speed;
} _sphericalCamera;

typedef struct {
    int unk0;
    short unk4;
    short unk6;
    union {
        char u8[2];
        u_short u16;
    } unk8;
    char unkA;
    char unkB;
    int unkC;
    int unk10;
    int unk14;
} D_800F1BAC_t;

typedef struct {
    vs_battle_uiEquipment blade;
    vs_battle_uiEquipment grip;
    vs_battle_uiEquipment gems[3];
    char material;
    char dropRate;
    short index;
    char name[24]; /* vs_string */
} vs_battle_weaponIntermediate;

typedef struct {
    vs_battle_uiEquipment base;
    vs_battle_uiEquipment gems[3];
    char material;
    char dropRate;
    short index;
} vs_battle_shieldIntermediate;

typedef struct {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
} vs_unk_gfx_t2;

typedef struct {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    vs_unk_gfx_t2 unk14;
} vs_unk_gfx_t;

typedef struct {
    u_char titlePage;
    char titleRow;
    u_char encyclopaediaPage;
    char encyclopaediaRow;
    char recordTimePage;
    char recordTimeRow;
    char gazettePage;
    char gazetteRow;
} vs_battle_menu9CursorMemory_t;

typedef struct vs_battle_lootListNode {
    struct vs_battle_lootListNode* next;
    int actorId;
    vs_battle_loot loot;
} vs_battle_lootListNode;

typedef struct {
    POLY_F4 covered;
    POLY_F4 edge;
} vs_battle_screenTransitionWipePoly;

typedef struct {
    camera_t2 fromCameraState;
    _sphericalCamera fromSpherical;
    int fromNearClip;
    int fromProjectionDistance;
    int fromFarClip;
    _sphericalCamera toSpherical;
    int toNearClip;
    int toProjectionDistance;
    int toFarClip;
    VECTOR targetPosition;
    VECTOR targetLookAt;
    VECTOR direction;
    VECTOR lookAtStep;
    int farClipStep;
    int nearClipStep;
    int projectionDistanceStep;
    int transitionSpeed;
    int transitionFrames;
} vs_battle_cameraTransition_t;

typedef struct {
    vs_battle_uiEquipment equip;
    char material;
    char unk31;
    char unk32;
    char unk33;
} _armorIntermediate;

typedef struct {
    vs_battle_uiEquipment equip;
    char dropRate;
    char unk31;
    char unk32;
    char unk33;
} _accessoryIntermediate;

typedef struct {
    u_short unk0;
    char unk2;
    char unk3;
} _armorIntermediateInit_unk10;

typedef struct {
    u_short hp;
    char agilityDefenseBonus;
    char chainEvasion;
    signed char unk4[4];
    signed char unk8[4];
    int unkC;
    _armorIntermediateInit_unk10 unk10[4];
    _armorIntermediate unk20;
    char unk54[6];
    char unk5A[2];
} _armorIntermediateInit;

typedef struct {
    u_short unk0;
    char unk2;
    u_int reach : 5;
    u_int unk3_5 : 3;
    char name[24]; /* vs_string */
    short hp;
    short mp;
    char strength;
    char intelligence;
    char agility;
    char unk23;
    char unk24;
    char walkSpeed;
    char unk26;
    char runSpeed;
    int unk28;
    int unk2C;
    char unk30;
    char unk31;
    char unk32;
    char unk33;
    vs_battle_weaponIntermediate weapon;
    vs_battle_shieldIntermediate shield;
    _accessoryIntermediate accessory;
    _armorIntermediateInit armor[6];
    int unk460;
} vs_battle_charInitData;

typedef struct {
    char unk0;
    char unk1;
    char unk2;
    char unk3;
    int unk4;
} D_800F53B8_t4;

typedef struct func_800D4910_t {
    struct func_800D4910_t* next;
    int (*unk4)(struct func_800D4910_t*, int, int);
} func_800D4910_t;

typedef struct {
    short unk0;
    short unk2;
    short unk4;
    u_short unk6;
} func_8006CE70_t;

void func_80069C6C(int);
void func_8006CDB8(int);
void func_80069FC4(int, int);
void vs_battle_copyInventoryBladeStats(vs_battle_uiEquipment*, vs_battle_inventoryBlade*);
void vs_battle_copyInventoryGripStats(vs_battle_uiEquipment*, vs_battle_inventoryGrip*);
void vs_battle_copyInventoryArmorStats(vs_battle_uiEquipment*, vs_battle_inventoryArmor*);
void vs_battle_copyInventoryGemStats(vs_battle_uiEquipment*, vs_battle_inventoryGem*);
void vs_battle_applyWeapon(vs_battle_uiWeapon*, vs_battle_inventoryWeapon*);
void vs_battle_applyShield(vs_battle_uiShield*, vs_battle_inventoryShield*);
void vs_battle_applyArmor(vs_battle_uiArmor*, vs_battle_inventoryArmor*);
void vs_battle_applyAccessory(
    vs_battle_uiAccessory* arg0, vs_battle_inventoryArmor* arg1);
void vs_battle_equipWeapon(vs_battle_inventoryWeapon*);
void vs_battle_equipShield(vs_battle_inventoryShield* shield);
void vs_battle_equipArmor(int part, vs_battle_inventoryArmor* armor);
void vs_battle_equipAccessory(vs_battle_inventoryArmor* accessory);
void vs_battle_applyShieldStats(vs_battle_uiShield*, vs_battle_shieldIntermediate*);
void vs_battle_applyWeaponStats(vs_battle_uiWeapon*, vs_battle_weaponIntermediate*);
void vs_battle_copyUiBladeStats(
    vs_battle_inventoryBlade* dropBlade, vs_battle_uiEquipment* targetBlade);
void vs_battle_copyUiGripStats(vs_battle_inventoryGrip*, vs_battle_uiEquipment*);
void vs_battle_copyUiGemStats(vs_battle_inventoryGem*, vs_battle_uiEquipment*);
void vs_battle_copyUiWeaponStats(
    vs_battle_inventoryWeapon* arg0, vs_battle_uiWeapon* arg1);
void vs_battle_copyUiShieldStats(vs_battle_inventoryShield*, vs_battle_uiShield*);
void vs_battle_copyUiArmorStats(vs_battle_inventoryArmor*, vs_battle_uiArmor*);
void vs_battle_copyUiAccessoryStats(vs_battle_inventoryArmor*, vs_battle_uiAccessory*);
void vs_battle_nop0(vs_battle_actor2*);
void func_8006C480(int, int);
void func_8006C4A4(int, int);
void func_8006CDD8(func_8006CE70_t*);
void func_8006CE50(void);
void func_8006CE70(func_8006CE70_t*);
int vs_battle_getCurrentRoomId(void);
void func_800760CC(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5);
void func_80076F24(
    int id, vs_battle_charInitData* arg1, int arg2, int arg3, int arg4, int arg5);
vs_battle_actor* func_800774FC(int arg0, int arg1, int bladeWepId, int bladeMaterial,
    int shieldWepId, int shieldMaterial, func_8007C8F8_t_flags* arg6, int arg7);
void func_80077EC4(void);
int vs_battle_syncCameraAnglesFromPosition(_sphericalCamera*);
int func_8007BD8C(int);
void func_8007AC94(int arg0);
void func_8007ACB0(void);
void func_8007B0FC(void);
void func_8007B104(void);
void func_8007B1B8(int, int, short, short, short);
void func_8007B29C(int, int, int, short, short, short);
void func_8007B344(int, int, short, short, short);
void func_8007B9A0(void);
int func_8007B9FC(void);
void func_8007BA98(int, int, int, int);
void func_8007BBB8(int, int);
void func_8007BBD8(int, int, int);
void func_8007C4D4(void);
int func_8007C8F8(int);
void func_8007CE74(int);
int func_8007CF80(int);
void func_8007BCCC(void);
void func_8007BD3C(int);
int func_8007BDD8(int);
int func_8007BE10(int);
void func_8007BE20(int, int);
void func_8007BEC4(int);
int func_8007BEE4(void);
void func_8007BF04(void);
int func_8007BF0C(void);
void func_8007BF2C(void);
void func_8007BF4C(void);
void func_8007BFC0(void);
void func_8007C050(void);
void func_8007C0AC(int, int);
void func_8007C28C(int);
void func_8007C31C(void);
void func_8007C348(int, int);
int func_8007C36C(int arg0);
int func_8007C398(void);
void func_8007C404(void);
void func_8007C424(void);
void func_8007C444(int, int, int);
void func_8007C460(int);
void func_8007C46C(int, int, int);
void func_8007C4AC(int, int, int);
void func_8007C580(D_80061068_t*, int, int);
void func_8007C654(D_80061068_t*, int, int);
void func_8007C8A4(int, int);
int func_8007C928(u_int arg0, int arg1, func_8007C8F8_t_flags* arg2);
void func_8007CA20(int, int, int);
void func_8007CAA4(int);
void func_8007CB84(int, int wepId);
void func_8007CBBC(int);
void func_8007CBDC(int, int, int);
void func_8007CC18(int, int, int);
void func_8007CC4C(int);
void func_8007CC6C(int);
int func_8007CCAC(void);
void vs_battle_setFarClip(int arg0, int arg1);
void vs_battle_initialiseCameraFromSpherical(VECTOR*, VECTOR*, int, int);
int func_8007CF18(int);
vs_battle_actor* func_8007CF64(int actorId);
void func_8007CFF8(int, SVECTOR*);
int func_8007D03C(int);
int func_8007D08C(int, int);
int func_8007D15C(int);
void func_8007D1A8(int, int);
int vs_battle_isSkillUnlocked(u_int);
void vs_battle_setSkillUnlocked(u_int);
void func_8007D340(int);
void func_8007D3F8(void);
void func_8007DF48(void);
void vs_battle_setProjectionDistance(int);
void vs_battle_setCameraPosition(VECTOR* inPosition);
void vs_battle_setCameraLookAt(VECTOR* inLookAt);
void vs_battle_setNearClip(int arg0);
void func_8007DD50(int);
void func_8007DDAC(int arg0);
void func_8007DDB8(D_800F1A68_t* arg0);
void func_8007DDD4(P_CODE* arg0);
void func_8007DDF8(D_800F1A68_t* arg0);
void func_8007DE2C(int arg0);
void func_8007DE44(u_int arg0);
void func_8007DE5C(int arg0);
int func_8007DFF0(u_int, u_int, int);
int func_8007E0A8(u_int, u_int, int);
int func_8007E180(int arg0);
int func_8007E1C0(int arg0);
int vs_battle_itemIdIsInInventory(int);
void func_80086FA8(int, vs_battle_actor2*);
void vs_battle_setDoorEntered(void);
int func_80089104(void);
void func_8008A4DC(int arg0);
int func_8008A4FC(void);
void func_8008A6FC(void);
int vs_battle_getSkillFlags(int, int);
void func_8008B430(char*, int);
void vs_battle_setRoomsUnk0(vs_battle_scene*);
void func_8008B6B4(void);
int func_8008B808(int, int, int, int);
int vs_battle_getCurrentSceneId(void);
int vs_battle_inWorkshop(void);
void vs_battle_setDoorEntered2(int arg0);
void func_8008C40C(void);
void func_8008D594(int);
void func_8008D5A0(int);
void func_8008D820(u_int*, func_80103530_t*);
int vs_battle_getMapCompletion(void);
void func_8008E224(int, int);
int func_8008E470(void);
int func_8008E7BC(int, int, u_int);
void func_8008E88C(void);
void func_8008EAE4(int, int);
void func_8008EAF8(int);
int* func_8008EB24(void);
void func_8008EB30(int*);
int func_8008EFCC(int);
int func_8008F0FC(void);
int func_8008F234(void);
void vs_battle_exec(void);

extern int vs_battle_mapCompletionFlags[];
extern char D_800E8F28;
extern _zoneContext_t _zoneContext;
extern D_800F18E8_t D_800F18E8;
extern vs_battle_lootListNode* _lootListHead;
extern vs_battle_actor* vs_battle_actors[];
extern _sphericalCamera vs_battle_cameraCurrentSpherical;
extern vs_battle_actor* vs_battle_characterState;
extern D_80061068_t D_800F1AB0;
extern u_short D_800F1BA4;
extern u_short* D_800F1BA8;
extern D_800F1BAC_t (*D_800F1BAC)[32];
extern short D_800F1BB6;
extern short vs_battle_doorEntered;
extern void* vs_battle_sceneBuffer;
extern vs_battle_manualDisplayState_t vs_battle_manualDisplayState;
extern vs_battle_menu9CursorMemory_t vs_battle_menu9CursorMemory;
extern char D_800F1BF7;
extern _mpdRoomSection vs_battle_roomData;
extern void* D_800F1CBC;
extern _mpdRoomDoorSection_t D_800F1CC8;
extern short D_800F1CD4;
extern char D_800F1CD6;
extern int D_800F1CD8;
extern int D_800F1CE0[8];
extern char vs_battle_executeAbilityType;
extern char D_800F51C1;
extern DR_MODE vs_battle_screenTransitionDrMode[];
extern int vs_battle_screenTransitionAlpha;
extern vs_battle_screenTransitionWipePoly vs_battle_screenTransitionWipePolyF4[];
extern POLY_G4 vs_battle_screenTransitionEdgePolyG4[];
extern POLY_F4 vs_battle_screenTransitionPolyF4[];
extern camera_t _camera;
extern vs_battle_cameraTransition_t* vs_battle_cameraTransition;
extern u_int vs_battle_screenTransitionStep;
extern int vs_battle_screenTransitionEffect;
extern int vs_battle_screenTransitionWipeAngle;
extern int vs_battle_screenTransitionSpeed;
