#pragma once
#include <sys/types.h>
#include <libgte.h>
#include "3A1A0.h"
#include "uiEquipment.h"

typedef struct {
    char unk0[0x5E8];
} vs_battle_actor4;

typedef struct {
    u_short id;
    char index : 4;
    char unk2_4 : 4;
    char unk3;
} vs_battle_actor_unk8C0;

/*
Flags for statuses
0x00000020 str down
0x00000040 str up
0x00000080 int down
0x00000100 int up
0x00000200 agi down
0x00000400 agi up
0x00000800 quicken
0x00001000 silent
0x00002000 paralysis
0x00004000 poison
0x00008000 numbness
0x00010000 curse
0x00020000 Regenaration
0x00040000 magic ward
0x00080000 equip down
0x00100000 equip up
0x00200000 air atk up
0x00400000 fire atk up
0x00800000 earth atk up
0x01000000 water atk up
0x02000000 air def up
0x04000000 fire def up
0x08000000 earth def up
0x10000000 water def up
*/

enum vs_battle_statuses {
    vsBattleStatusStrDown = 1 << 0,
    vsBattleStatusStrUp = 1 << 1,
    vsBattleStatusIntDown = 1 << 2,
    vsBattleStatusIntUp = 1 << 3,
    vsBattleStatusAgiDown = 1 << 4,
    vsBattleStatusAgiUp = 1 << 5,
    vsBattleStatusQuicken = 1 << 6,
    vsBattleStatusSilent = 1 << 7,
    vsBattleStatusParalysis = 1 << 8,
    vsBattleStatusPoison = 1 << 9,
    vsBattleStatusNumbness = 1 << 10,
    vsBattleStatusCurse = 1 << 11,
    vsBattleStatusRegen = 1 << 12,
    vsBattleStatusWard = 1 << 13,
    vsBattleStatusEquDown = 1 << 14,
    vsBattleStatusEquUp = 1 << 15,
    vsBattleStatusAirAtkUp = 1 << 16,
    vsBattleStatusFireAtkUp = 1 << 17,
    vsBattleStatusEarthAtkUp = 1 << 18,
    vsBattleStatusWaterAtkUp = 1 << 19,
    vsBattleStatusAirDefUp = 1 << 20,
    vsBattleStatusFireDefUp = 1 << 21,
    vsBattleStatusEarthDefUp = 1 << 22,
    vsBattleStatusWaterDefUp = 1 << 23
};

typedef struct {
    /* 0x000 */ char name[24];
    /* 0x018 */ short currentHP;
    /* 0x01A */ short maxHP;
    /* 0x01C */ short currentMP;
    /* 0x01E */ short maxMP;
    /* 0x020 */ u_short risk;
    /* 0x022 */ u_short strength;
    /* 0x024 */ u_short totalStrength;
    /* 0x026 */ u_short intelligence;
    /* 0x028 */ u_short totalIntelligence;
    /* 0x02A */ u_short agility;
    /* 0x02C */ u_short totalAgility;
    /* 0x02E */ char unk2E;
    /* 0x02F */ char unk2F;
    /* 0x030 */ char unk30;
    /* 0x031 */ char unk31;
    /* 0x032 */ char unk32;
    /* 0x033 */ char unk33;
    /* 0x034 */ u_int unk34 : 8;
    /* 0x035 */ u_int unk35 : 8;
    /* 0x036 */ u_int unk36 : 8;
    /* 0x037 */ u_int enemyClass : 3;
    /* 0x037 */ u_int reach : 5;
    /* 0x038 */ u_int currentRange : 8;
    /* 0x039 */ u_int unk39 : 8;
    /* 0x03A */ u_int unk3A : 8;
    /* 0x03B */ u_int unk3B_0 : 3;
    /* 0x03B */ u_int currentAttackShapeAngle : 5;
    /* 0x03C */ vs_battle_uiWeapon weapon;
    /* 0x1D4 */ vs_battle_uiShield shield;
    /* 0x338 */ vs_battle_uiAccessory accessory;
    /* 0x398 */ vs_battle_uiEquipment_limb limbs[6];
    /* 0x8C0 */ vs_battle_actor_unk8C0 armor[6][4];
    /* 0x920 */ char dpSplash[6][6];
    /* 0x944 */ int unk944;
    /* 0x948 */ int statuses;
    /* 0x94C */ u_char statusTimers[8];
    /* 0x954 */ u_short unk954;
    /* 0x956 */ u_char unk956_0 : 1;
    /* 0x956 */ u_char isAnalyzed : 1;
    /* 0x956 */ u_char unk956_2 : 6;
    /* 0x957 */ u_char unk957;
    /* 0x958 */ vs_battle_uiMisc miscItem;
    /* 0x95C */ vs_battle_uiMisc unk95C;
    /* 0x960 */ vs_battle_uiMiscRand unk960;
    /* 0x964 */
} vs_battle_actor2;

typedef struct vs_battle_actor {
    /* 0x00 */ struct vs_battle_actor* next;
    /* 0x04 */ int id;
    /* 0x08 */ union {
        u_int value;
        struct {
            u_int unk8 : 8;
            u_int unk9 : 8;
            u_int unkA : 8;
            u_int unkB_0 : 2;
            u_int unkB_2 : 2;
            u_int unkB_4 : 4;
        } fields;
    } command;
    /* 0x0C */ int unkC;
    union {
        u_char u8[4];
        u_short u16[2];
        int s32;
    /* 0x10 */ } unk10;
    int unk14;
    u_short unk18;
    u_short subType;
    u_short unk1C;
    u_char unk1E;
    u_char unk1F;
    int weaponDrawn;
    u_char unk24;
    u_char equippedWeaponCategory;
    u_char unk26;
    u_char unk27;
    u_char defeated;
    u_char unk29;
    u_char unk2A;
    u_char unk2B;
    union {
        u_char u8[4];
        int s32;
    } unk2C;
    u_short unk30_0 : 4;
    u_short unk30_4 : 5;
    u_int unk30_9 : 5;
    u_int unk30_14 : 18;
    int unk34;
    int unk38;
    vs_battle_actor2* unk3C;
    int unk40;
    D_800F4538_t* unk44;
    vs_battle_actor4* unk48[2];
} vs_battle_actor;

typedef struct {
    struct {
        vs_battle_actor unk0;
        vs_battle_actor2 unk50;
    } unk0;
    D_800F4538_unk0 unk9B4;
    MATRIX unk6C[8];
    int unk16C;
    int unk170;
    int unk174;
} vs_battle_actor_dat2;

typedef struct {
    vs_battle_actor_dat2 unk0;
    char unkB2C[0x1788];
    vs_battle_actor4 unk22B4[2];
} vs_battle_actor_dat;

void vs_battle_nop0(vs_battle_actor2*);
vs_battle_actor* func_8007CF64(int actorId);
void func_80086FA8(int, vs_battle_actor2*);
extern vs_battle_actor* vs_battle_actors[];
extern vs_battle_actor* vs_battle_characterState;

/**
 * Retrieve action availability info.
 *
 * @return Packed value
 * - Bit 0:
 * - Bit 1: Requirements not met (i.e. insufficient HP/MP/Risk)
 * - Bit 2: action locked
 */
int vs_battle_getActionFlags(int actorId, int actionId);
