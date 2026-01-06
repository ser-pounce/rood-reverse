#pragma once
#include "../../SLUS_010.40/main.h"
#include "../../SLUS_010.40/D_80061068_t.h"

typedef struct {
    short unk0;
    short unk2;
    short unk4;
    short unk6;
    union {
        short s16;
        char u8[2];
    } unk8;
    char unkA;
    char unkB;
} D_800F1910_t2;

typedef struct {
    u_int unk0_0 : 8;
    u_int unk0_8 : 1;
    u_int unk0_9 : 1;
    u_int unk0_10 : 3;
    u_int unk0_13 : 3;
    u_int unk0_16 : 1;
    u_int unk0_17 : 1;
    u_int unk0_18 : 2;
    u_int unk0_19 : 12;
} func_8008B764_t;

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
    func_8008B764_t unkB4;
} D_800F1CA0_t;

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
    int unk14[136];
} func_8008D710_t;

typedef struct {
    D_800F1910_t2 unk0;
    short unkC;
    short unkE;
    short unk10;
    char unk12;
    char unk13;
} func_8008C1C8_t;

typedef struct {
    u_short unk0_0 : 5;
    u_short unk0_5 : 5;
    u_short unk0_10 : 3;
    u_short unk0_13 : 3;
} func_8008B960_t2;

typedef struct {
    char unk0;
    char unk1;
    func_8008B960_t2 unk2;
    int unk4;
    char unk8;
    char unk9;
    char unkA;
    char unkB;
} func_8008B960_t;

typedef struct {
    short unk0;
    short unk2;
    short unk4;
    short unk6;
} D_800F1C60_t;

typedef struct {
    int unk0[5];
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    char unk30;
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
} D_800F1C84_t;

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
    int unk0;
    int unk4;
    int unk8;
    int* unkC;
    int* unk10;
} func_8008A908_t;

typedef struct {
    u_short unk0_0 : 5;
    u_short unk0_5 : 5;
    u_short unk0_10 : 1;
    u_short unk0_11 : 3;
    u_short unk0_14 : 1;
    u_short unk0_15 : 1;
    u_short unk2;
    char unk4[0];
} func_8008C2C0_t;

typedef struct {
    char unk0;
    char unk1;
    short unk2;
    u_int unk4;
    u_int unk8;
    u_int unkC;
    u_int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    u_int unk24;
    u_int unk28;
    u_int unk2C;
    u_int unk30;
    u_int unk34;
    u_int unk38;
    u_int unk3C;
    u_int unk40;
    u_int unk44;
    u_int unk48;
    u_int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int* unk64;
    D_800F1C60_t* unk68;
    func_8008B764_t* unk6C;
    func_8008B960_t* unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    D_800F1910_t2* unk84;
    func_8008C1C8_t* unk88;
    D_800F1C84_t* unk8C;
    int unk90;
    int unk94;
    func_8008A908_t* unk98;
    vs_battle_scene* unk9C;
    u_short* unkA0;
    func_8008C2C0_t* unkA4;
    D_800F1CA0_t* unkA8;
    func_8008D710_t* unkAC;
    u_int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    void* unkC0;
} D_800F1BF8_t;

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
} vs_battle_equippedWeapon_unk;

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
} vs_battle_equippedItem;

typedef struct {
    char name[24];
    vs_battle_equippedItem blade; // 0x18
    vs_battle_equippedItem grip; // 0x48
    vs_battle_equippedItem gems[3]; // 0x78
    char wepId;
    char damageTypeValue;
    char risk;
    char unk10B;
    char unk10C;
    u_char unk10D;
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
} vs_battle_equippedWeapon;

typedef struct {
    int unk0[6];
    vs_battle_equippedItem shield; // 0x18
    vs_battle_equippedItem gems[3]; // 0x48
    char unkD8; // 0xD8
    char unkD9;
    u_char unkDA;
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
} vs_battle_equippedShield;

typedef struct {
    vs_battle_equippedItem armor;
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
} vs_battle_equippedArmor;

typedef struct {
    short unk0;
    short unk2;
    signed char unk4;
    char unk5;
    u_char nameIndex;
    char unk7;
    u_short types[4];
    u_short affinities[8];
    vs_battle_equippedArmor armor; // 0x18
} vs_battle_equippedItem_hitLocations;

typedef struct {
    vs_battle_equippedItem accessory;
    short currentStr;
    short currentInt;
    short currentAgility;
    char material;
    u_char unk37;
    u_short types[4];
    u_short classes[8];
    u_short affinities[8];
} vs_battle_equippedAccessory;

typedef struct {
    u_short unk0;
    char unk2;
    char unk3;
} func_8006BE64_t3;

typedef struct {
    u_short unk0;
    char unk2;
} func_8006BDF0_t;

typedef struct {
    char unk0[0x5E8];
} vs_battle_actor4;

typedef struct {
    char unk0[0x178];
} vs_battle_actor3;

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
    short unk2E;
    char unk30;
    char unk31;
    char unk32;
    char unk33;
    u_int unk34 : 8;
    u_int unk35 : 8;
    u_int unk36 : 8;
    u_int unk37_0 : 3;
    u_int unk37_3 : 5;
    u_int unk38 : 8;
    u_int unk39 : 8;
    u_int unk3A : 8;
    u_int unk3B_0 : 3;
    u_int unk3B_3 : 5;
    vs_battle_equippedWeapon weapon; // 0x3C
    vs_battle_equippedShield shield; // 1C4
    vs_battle_equippedAccessory accessory; // 328
    vs_battle_equippedItem_hitLocations hitLocations[6]; // 388
    u_short unk8C0[48];
    char unk920[6][6];
    int unk944;
    int unk948;
    char unk94C[8];
    union {
        struct {
            u_short unk0;
            char unk2_0 : 1;
            char unk2_1 : 1;
            char unk2_2 : 6;
            u_char unk3;
        } fields;
        u_int u32;
    } flags;
    func_8006BE64_t3 unk958;
    int unk95C;
    func_8006BDF0_t unk960;
} vs_battle_actor2;

typedef struct vs_battle_actor {
    struct vs_battle_actor* next;
    int active;
    char unk8;
    char unk9;
    char unkA;
    char unkB;
    int unkC;
    union {
        char u8[4];
        int s32;
    } unk10;
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
    char unk28;
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
    vs_battle_actor unk0;
    vs_battle_actor2 unk50;
    vs_battle_actor3 unk9B4;
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
} _enemy_t;

typedef struct {
    short unk0;
    short unk2;
    short unk4;
    short unk6;
} _zoneContext_t2;

typedef struct {
    int zndId;
    vs_main_CdFile* mpdLbas;
    int enemyCount;
    _enemy_t* enemies;
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
    _zoneContext_t2 unk40;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    vs_main_CdQueueSlot* mpdCdFile;
    void* mpdData;
    int unk60;
    void* unk64;
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
    VECTOR unk0;
    VECTOR unk10;
    int unk20;
    int unk24;
    int unk28;
} D_800F1904_t3;

typedef struct {
    char unk0[6];
    short unk6;
    short unk8;
    char unkA;
    char unkB;
    int unkC[189];
} D_800F1BAC_t;

void func_80069FC4(int, int);
void vs_battle_copyInventoryBladeStats(
    vs_battle_equippedItem*, vs_battle_inventoryBlade*);
void vs_battle_copyInventoryGripStats(vs_battle_equippedItem*, vs_battle_inventoryGrip*);
void vs_battle_copyInventoryArmorStats(
    vs_battle_equippedItem*, vs_battle_inventoryArmor*);
void vs_battle_copyInventoryGemStats(vs_battle_equippedItem*, vs_battle_inventoryGem*);
void vs_battle_applyWeapon(vs_battle_equippedWeapon*, vs_battle_inventoryWeapon*);
void vs_battle_applyShield(vs_battle_equippedShield*, vs_battle_inventoryShield*);
void vs_battle_applyArmor(vs_battle_equippedArmor*, vs_battle_inventoryArmor*);
void vs_battle_applyAccessory(
    vs_battle_equippedAccessory* arg0, vs_battle_inventoryArmor* arg1);
void vs_battle_equipWeapon(vs_battle_inventoryWeapon*);
void vs_battle_copyEquippedBladeStats(
    vs_battle_inventoryBlade* dropBlade, vs_battle_equippedItem* targetBlade);
void vs_battle_copyEquippedGripStats(vs_battle_inventoryGrip*, vs_battle_equippedItem*);
void vs_battle_copyEquippedGemStats(vs_battle_inventoryGem*, vs_battle_equippedItem*);
void vs_battle_copyEquippedWeaponStats(
    vs_battle_inventoryWeapon* arg0, vs_battle_equippedWeapon* arg1);
void vs_battle_copyEquippedShieldStats(
    vs_battle_inventoryShield*, vs_battle_equippedShield*);
void vs_battle_copyEquippedArmorStats(
    vs_battle_inventoryArmor*, vs_battle_equippedArmor*);
void vs_battle_copyEquippedAccessoryStats(
    vs_battle_inventoryArmor*, vs_battle_equippedAccessory*);
void func_8006CE50(void);
int vs_battle_getCurrentRoomId(void);
void func_8007ACB0(void);
int func_8007C36C(int arg0);
void func_8007CCF0(int);
void func_8007DD50(int);
void func_8007DDAC(int arg0);
void func_8007DDB8(int* arg0);
void func_8007DDD4(P_CODE* arg0);
void func_8007DDF8(D_800F1A68_t* arg0);
void func_8007DE2C(int arg0);
void func_8007DE44(u_int arg0);
void func_8007DE5C(int arg0);
int func_8007DFF0(u_int, u_int, int);
int func_8007E0A8(u_int, u_int, int);
int func_8007E180(int arg0);
int func_8007E1C0(int arg0);
void func_80086FA8(int, vs_battle_actor2*);
void vs_battle_setDoorEntered(void);
void func_8008A4DC(int arg0);
int func_8008A4FC(void);
int vs_battle_getSkillFlags(int, int);
void func_8008B430(char*, int);
void vs_battle_setRoomsUnk0(vs_battle_scene*);
void func_8008B6B4(void);
int vs_battle_getCurrentSceneId(void);
void func_8008D820(u_int*, func_80103530_t*);
int vs_battle_getMapCompletion(void);
int func_8008E7BC(int, int, u_int);
void func_8008E88C(void);
int* func_8008EB24(void);
void func_8008EB30(int*);
int func_800995B0(void);
int func_8009967C(void);
void vs_battle_exec(void);

extern int vs_battle_mapCompletionFlags[];
extern char D_800E8F28;
extern _zoneContext_t _zoneContext;
extern D_800F18E8_t D_800F18E8;
extern vs_battle_actor* vs_battle_actors[];
extern D_800F1904_t3 D_800F19D0;
extern vs_battle_actor* vs_battle_characterState;
extern D_80061068_t D_800F1AB0;
extern u_short D_800F1BA4;
extern u_short* D_800F1BA8;
extern D_800F1BAC_t* D_800F1BAC;
extern short D_800F1BB6;
extern short vs_battle_doorEntered;
extern void* vs_battle_sceneBuffer;
extern vs_battle_manualDisplayState_t vs_battle_manualDisplayState;
extern u_char D_800F1BF0[8];
extern char D_800F1BF7;
extern D_800F1BF8_t D_800F1BF8;
extern void* D_800F1CBC;
extern func_8008B960_t D_800F1CC8;
extern short D_800F1CD4;
extern char D_800F1CD6;
extern int D_800F1CD8;
extern int D_800F1CE0[8];
extern char vs_battle_executeAbilityType;
extern char D_800F51C1;
