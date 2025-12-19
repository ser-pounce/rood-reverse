#pragma once
#include "../../SLUS_010.40/main.h"
#include "../../SLUS_010.40/D_80061068_t.h"

typedef struct {
    short unk0;
    short unk2;
    u_short unk4;
    u_short unk6;
    short unk8;
    char unkA;
    char unkB;
} D_800F1910_t2;

typedef struct {
    char unk0;
    char unk1;
    short unk2;
    u_int unk4;
    u_int unk8;
    u_int unkC;
    u_short unk10;
    u_short unk12;
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
    int unk64;
    short* unk68;
    char* unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    D_800F1910_t2* unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int (*unkA8)[46];
    short* unkAC;
    int unkB0[5];
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
} vs_battle_weaponInfo_unk;

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
    signed char unk2;
    signed char wepId;
    char category;
    signed char strength;
    signed char intelligence;
    signed char agility;
    u_short currentDp;
    u_short maxDp;
    u_short currentPp;
    u_short maxPp;
    char damageType;
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
} vs_battle_equipment;

typedef struct {
    char name[24];
    vs_battle_equipment blade;
    vs_battle_equipment grip;
    vs_battle_equipment gems[3];
    u_short unk108;
    char risk;
    char unk10B;
    char unk10C;
    u_char unk10D;
    u_char unk10E;
    u_char unk10F;
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
    char range;
    char unk125;
    short unk126;
    vs_battle_classAffinityCurrent classAffinityCurrent;
    short unk168[8];
    vs_battle_classAffinityBaseline classAffinityBaseline;
} vs_battle_weaponInfo;

typedef struct {
    int unk0[6];
    vs_battle_equipment shield; // 0x18
    vs_battle_equipment gems[3]; // 0x48
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
} vs_battle_shieldInfo;

typedef struct {
    vs_battle_equipment armor;
    u_short currentDp;
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
} vs_battle_armorInfo;

typedef struct {
    u_short unk0;
    u_short unk2;
    char unk4;
    char unk5;
    u_char nameIndex;
    char unk7;
    u_short types[4];
    u_short affinities[8];
    vs_battle_armorInfo armor; // 0x18
} vs_battle_equipment_hitLocations;

typedef struct {
    vs_battle_equipment accessory;
    short currentStr;
    short currentInt;
    short currentAgility;
    char unk36;
    u_char unk37;
    u_short types[4];
    u_short classes[8];
    u_short affinities[8];
} vs_battle_accessoryInfo;

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
    short name[8];
    int unk10;
    short unk14;
    short unk16;
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
    short unk30;
    short unk32;
    u_char unk34;
    u_char unk35;
    char unk36;
    char unk37;
    int unk38;
    vs_battle_weaponInfo weapon; // 0x3C
    vs_battle_shieldInfo shield; // 1C4
    vs_battle_accessoryInfo accessory; // 328
    vs_battle_equipment_hitLocations hitLocations[6]; // 388
    u_short unk8C0[66];
    int unk944;
    int unk948;
    char unk94C[8];
    union {
        struct {
            u_short unk0;
            char unk2_0 : 2;
            char unk2_2 : 6;
            char unk3;
        } fields;
        u_int u32;
    } flags;
    func_8006BE64_t3 unk958;
    int unk95C;
    func_8006BDF0_t unk960;
} vs_battle_actor2;

typedef struct vs_battle_actor {
    struct vs_battle_actor* unk0;
    int unk4;
    char unk8;
    char unk9;
    char unkA;
    char unkB;
    int unkC;
    int unk10;
    int unk14;
    u_short unk18;
    u_short unk1A;
    u_short unk1C;
    short unk1E;
    int unk20;
    char unk24;
    char equippedWeaponType;
    char unk26;
    u_char unk27;
    char unk28;
    char unk29;
    char unk2A;
    char unk2B;
    short x;
    short y;
    int unk30;
    int unk34;
    int unk38;
    vs_battle_actor2* unk3C;
    int unk40;
    int unk44;
    void* unk48[2];
} vs_battle_actor;

typedef struct {
    int visited;
    void* dataAddress;
    short zoneId;
    short mapId;
} vs_battle_room;

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
    int roomCount;
    vs_battle_room rooms[0];
} vs_battle_scene;

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
    u_long* unk10;
} func_80103530_t;

typedef struct {
    int zndId;
    vs_main_CdFile* unk4;
    int unk8;
    void* unkC;
    void* unk10;
    int unk14;
    int unk18;
    int unk1C;
    vs_main_CdQueueSlot* unk20;
    void* unk24;
    int unk28;
    int unk2C;
    int unk30;
    int mapId;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    vs_main_CdQueueSlot* unk58;
    void* unk5C;
    int unk60;
    void* unk64;
    int unk68;
} D_800F1880_t;

typedef struct {
    char unk0;
    char unk1;
    char unk2;
    char unk3;
} D_800F1A78_t;

typedef struct {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
} D_800F1A68_t;

typedef struct {
    short unk0;
    char unk2;
    char unk3;
    char unk4;
    char unk5;
    char unk6;
    char unk7;
    char unk8[4];
    char unkC;
    char unkD;
    char unkE;
    char unkF;
    char unk10[4];
    char unk14;
    char unk15;
    char unk16;
    char unk17;
    short unk18;
    char unk1A;
    char unk1B;
    char unk1C[4];
    char unk20[4];
    int unk24;
    char unk28[4];
    int unk2C;
} func_8006AC74_t;

typedef struct {
    u_short unk0_0 : 10;
    u_short unk0_10 : 6;
} D_800F18E8_t;

void func_80069FC4(int, int);
void func_8006AB44(void*, void*);
void func_8006AC74(func_8006AC74_t*, func_8006AC74_t*);
void func_8006ACFC(void*, vs_battle_setEquipmentForDrop_t*);
void func_8006AE0C(func_8006AC74_t*, func_8006AC74_t*);
void func_8006AEAC(vs_battle_weaponInfo*, char*);
void func_8006B02C(vs_battle_shieldInfo*, void*);
void func_8006B110(vs_battle_armorInfo*, vs_battle_setEquipmentForDrop_t*);
void func_8006B194(vs_battle_accessoryInfo* arg0, vs_battle_setEquipmentForDrop_t* arg1);
void func_8006B338(void*);
void vs_battle_setBladeForDrop(
    func_8006B57C_t* dropBlade, vs_battle_equipment* targetBlade);
void vs_battle_setGripForDrop(vs_battle_setGripForDrop_t*, vs_battle_equipment*);
void vs_battle_setGemForDrop(func_800FD17C_t*, vs_battle_equipment*);
void vs_battle_setWeaponForDrop(u_char* arg0, vs_battle_weaponInfo* arg1);
void func_8006B9E0(u_char*, vs_battle_shieldInfo*);
void vs_battle_setArmorForDrop(vs_battle_setEquipmentForDrop_t*, vs_battle_armorInfo*);
void vs_battle_setAccesoryForDrop(
    vs_battle_setEquipmentForDrop_t*, vs_battle_accessoryInfo*);
void func_8006CE50(void);
int vs_battle_getCurrentRoomId(void);
void func_8007ACB0(void);
int func_8007C36C(int arg0);
void func_8007CCF0(int);
void func_8007DD50(int);
void func_8007DDAC(int arg0);
void func_8007DDB8(int* arg0);
void func_8007DDD4(D_800F1A78_t* arg0);
void func_8007DDF8(D_800F1A68_t* arg0);
void func_8007DE2C(int arg0);
void func_8007DE44(u_int arg0);
void func_8007DE5C(int arg0);
int func_8007DFF0(char, int, int);
void func_8007E0A8(int, int, int);
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
extern D_800F1880_t D_800F1880;
extern D_800F18E8_t D_800F18E8;
extern vs_battle_actor* vs_battle_actors[];
extern int D_800F19D0[];
extern vs_battle_actor* vs_battle_characterState;
extern D_80061068_t D_800F1AB0;
extern u_short D_800F1BA4;
extern u_short* D_800F1BA8;
extern void* D_800F1BAC;
extern short D_800F1BB6;
extern short vs_battle_exitZoneId;
extern void* vs_battle_sceneBuffer;
extern vs_battle_manualDisplayState_t vs_battle_manualDisplayState;
extern u_char D_800F1BF0[8];
extern char D_800F1BF7;
extern D_800F1BF8_t D_800F1BF8;
extern vs_battle_scene* vs_battle_currentScene;
extern void* D_800F1CBC;
extern signed char D_800F1CC8[12];
extern short D_800F1CD4;
extern char D_800F1CD6;
extern int D_800F1CD8;
extern int D_800F1CE0[8];
extern char vs_battle_executeAbilityType;
extern char D_800F51C1;
