#pragma once
#include "../../SLUS_010.40/main.h"
#include "../../SLUS_010.40/D_80061068_t.h"

typedef struct {
    char unk0;
    char unk1;
    short unk2;
    int unk4[9];
    u_int unk28;
    u_int unk2C[8];
    u_int unk4C;
    int unk50[14];
    int unk88;
    int unk8C[8];
    int unkAC;
    int unkB0[5];
} D_800F1BF8_t;

typedef struct {
    short class[2][8];
    short affinity[2][8];
} vs_battle_classAffinityCurrent;

typedef struct {
    u_short class[8];
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
    char range;
    char unk19;
    u_short unk1A;
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
    int unk168[4];
    vs_battle_classAffinityBaseline classAffinityBaseline;
} vs_battle_weaponInfo;

typedef struct {
    int unk0[6];
    vs_battle_equipment shield;
    vs_battle_equipment gems[3];
    u_short unkD8;
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
    vs_battle_classAffinityCurrent classAffinityCurrent;
    int unk134[4];
    vs_battle_classAffinityBaseline classAffinityBaseline;
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
    int unk88[4];
    u_short unk98;
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
    u_short unk8[4];
    u_short unk10[8];
    vs_battle_armorInfo armor;
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
    short unk0;
    short unk2;
    int unk4;
    short unk8;
    short unkA;
    short unkC;
    short unkE;
    int unk10;
    short unk14;
    short unk16;
    short currentHP;
    short maxHP;
    short currentMP;
    short maxMP;
    u_short unk20;
    short unk22;
    short unk24;
    short unk26;
    short unk28;
    short unk2A;
    short unk2C;
    short unk2E;
    short unk30;
    short unk32;
    short unk34;
    char unk36;
    char unk37;
    int unk38;
    vs_battle_weaponInfo weapon;
    vs_battle_shieldInfo shield;
    vs_battle_accessoryInfo accessory;
    vs_battle_equipment_hitLocations hitLocations[6];
    u_short unk8C0[68];
    int unk948;
    char unk94C[8];
    u_int flags;
} vs_battle_actor2;

typedef struct {
    int unk0[2];
    int unk8;
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
    signed char unk26;
    signed char unk27;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    vs_battle_actor2* unk3C;
    int unk40;
    int unk44;
} vs_battle_actor;

typedef struct {
    u_short unk0;
    char unk2;
    char unk3;
} func_800FD17C_t;

void func_80069FC4(int, int);
void func_8006AEAC(vs_battle_weaponInfo*, char*);
void func_8006B02C(void*, int);
void func_8006B110(vs_battle_armorInfo*, func_8006B7BC_t*);
void func_8006B338(void*);
void func_8006B57C(int*, vs_battle_equipment*);
void func_8006B6AC(int*, vs_battle_equipment*);
void func_8006B728(func_800FD17C_t*, void*);
void func_8006B8C0(void*, vs_battle_weaponInfo*);
void func_8006B9E0(void*, vs_battle_shieldInfo*);
void func_8006BAA8(func_8006B7BC_t*, vs_battle_armorInfo*);
void func_8006BADC(func_8006B7BC_t*, vs_battle_accessoryInfo*);
void func_8006CE50(void);
int vs_battle_getClosestSavePoint(void);
void func_8007ACB0(void);
void func_8007CCF0(int);
int func_8007DFF0(int, int, int);
void func_8007E0A8(int, int, int);
int func_8007E180(int arg0);
int func_8007E1C0(int arg0);
void func_8008AB68(void);
void func_8008A4DC(int arg0);
int func_8008A4FC(void);
int vs_battle_getSkillFlags(int, int);
void func_8008B430(char*, int);
void func_8008B6B4(void);
int func_8008E5F0(void);
void func_8008E88C(void);
int* func_8008EB24(void);
void func_8008EB30(int*);
void func_800995B0(void);
int func_8009967C(void);
void vs_battle_exec(void);

typedef struct {
    u_short currentManual;
    u_short unk2;
    u_short scrollPositions[16];
} vs_battle_manualDisplayState_t;

extern u_short D_800F18E8;
extern vs_battle_actor* vs_battle_actors[];
extern int D_800F19D0[];
extern vs_battle_actor* vs_battle_characterState;
extern D_80061068_t D_800F1AB0;
extern u_short D_800F1BA4;
extern short* D_800F1BA8;
extern void* D_800F1BAC;
extern short D_800F1BB6;
extern short D_800F1BBE;
extern int D_800F1BC0;
extern vs_battle_manualDisplayState_t vs_battle_manualDisplayState;
extern signed char D_800F1BF0[8];
extern D_800F1BF8_t D_800F1BF8;
extern void* D_800F1CBC;
extern signed char D_800F1CC8[12];
extern short D_800F1CD4;
extern char D_800F1CD6;
extern int D_800F1CD8;
extern int D_800F1CE0[8];
extern char vs_battle_executeAbilityType;
