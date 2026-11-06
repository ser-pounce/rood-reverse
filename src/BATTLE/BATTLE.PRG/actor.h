#pragma once
#include "entity.h"
#include "uiEquipment.h"
#include <sys/types.h>
#include <libgte.h>

typedef struct {
    char unk0[0x5E8];
} vs_battle_actor4;

typedef struct {
    u_short id;
    char index : 4;
    char unk2_4 : 4;
    char unk3;
} vs_battle_actor_unk8C0;

// Bits 0-4 are set while the matching limb is down (HP below 2), see D_800E8200 and
// D_800E8204. The effects are: head, cannot cast like Silent; right arm, damage dealt
// halved; left arm, hit threshold doubled; body, risk recovers more slowly; legs,
// movement speed halved.
// Bits 5-28 are the status effects and match the order of vs_main_statusEffectParams.
enum vs_battle_statuses {
    vsBattleStatusHeadDown = 1 << 0,
    vsBattleStatusRightArmDown = 1 << 1,
    vsBattleStatusLeftArmDown = 1 << 2,
    vsBattleStatusBodyDown = 1 << 3,
    vsBattleStatusLegsDown = 1 << 4,
    vsBattleStatusStrDown = 1 << 5,
    vsBattleStatusStrUp = 1 << 6,
    vsBattleStatusIntDown = 1 << 7,
    vsBattleStatusIntUp = 1 << 8,
    vsBattleStatusAgiDown = 1 << 9,
    vsBattleStatusAgiUp = 1 << 10,
    vsBattleStatusQuicken = 1 << 11,
    vsBattleStatusSilent = 1 << 12,
    vsBattleStatusParalysis = 1 << 13,
    vsBattleStatusPoison = 1 << 14,
    vsBattleStatusNumbness = 1 << 15,
    vsBattleStatusCurse = 1 << 16,
    vsBattleStatusRegen = 1 << 17,
    vsBattleStatusWard = 1 << 18,
    vsBattleStatusEquDown = 1 << 19,
    vsBattleStatusEquUp = 1 << 20,
    vsBattleStatusAirAtkUp = 1 << 21,
    vsBattleStatusFireAtkUp = 1 << 22,
    vsBattleStatusEarthAtkUp = 1 << 23,
    vsBattleStatusWaterAtkUp = 1 << 24,
    vsBattleStatusAirDefUp = 1 << 25,
    vsBattleStatusFireDefUp = 1 << 26,
    vsBattleStatusEarthDefUp = 1 << 27,
    vsBattleStatusWaterDefUp = 1 << 28
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
    /* 0x954 */ u_short actionDelay;
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
            u_char unk8;
            u_char unk9;
            u_char unkA;
            u_int unkB_0 : 2;
            u_int unkB_2 : 2;
            u_int unkB_4 : 4;
        } fields;
    } command;
    /* 0x0C */ union {
        int s32[3];
        short s16[6];
        u_short u16[6];
        u_char u8[12];
    } commandArgs;
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
    vs_battle_movementPosition unk2C;
    u_short unk30_0 : 4;
    u_short unk30_4 : 5;
    u_int unk30_9 : 5;
    u_int unk30_14 : 2;
    u_int unk30_16 : 6;
    u_int unk30_22 : 5;
    u_int unk30_27 : 5;
    u_int unk34_0 : 12;
    u_int unk34_12 : 2;
    u_int unk34_14 : 1;
    u_int unk34_15 : 17;
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
vs_battle_actor* vs_battle_getActor(int actorId);
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

int func_8009AA84(int);
int func_8009CC20(int, int);
int func_8009CFB0(int);
void func_8009D468(int);
void func_8009D934(int, int, int);
void func_8009E634(D_800F4538_t*);
void func_8009F940(int, int, CVECTOR*, CVECTOR*);
int func_800A0204(int, int, int, int);
int func_800A0768(int, CVECTOR*);
int func_800A07FC(int, CVECTOR*);
void func_800A087C(int actorId, int);
u_int func_800A0BE0(int actorId);
int func_800A1108(int, vs_battle_actorPosition*);
int func_800A13EC(int, int, int*, int);
