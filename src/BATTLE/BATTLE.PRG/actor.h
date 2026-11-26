#pragma once
#include "entity.h"
#include "uiEquipment.h"
#include "tilePosition.h"
#include <sys/types.h>
#include <libgte.h>

typedef struct {
    char unk0[0x5E8];
} ActorSubModel;

typedef struct {
    u_short id;
    char index : 4;
    char unk2_4 : 4;
    char unk3;
} Actor_unk8C0;

// Bits 0-4 are set while the matching limb is down (HP below 2), see D_800E8200 and
// D_800E8204. The effects are: head, cannot cast like Silent; right arm, damage dealt
// halved; left arm, hit threshold doubled; body, risk recovers more slowly; legs,
// movement speed halved.
// Bits 5-28 are the status effects and match the order of vs_main_statusEffectParams.
enum statuses {
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

enum ActorFlags {
    vsBattleActorFlagBladeVisible = 1 << 11,
    vsBattleActorFlagShieldVisible = 1 << 12,
    vsBattleActorFlagWeaponsVisible =
        vsBattleActorFlagBladeVisible | vsBattleActorFlagShieldVisible
};

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
    vs_UiWeapon weapon;
    vs_UiShield shield;
    vs_UiAccessory accessory;
    vs_UiEquipment_limb limbs[6];
    Actor_unk8C0 armor[6][4];
    char dpSplash[6][6];
    int unk944;
    int statuses;
    u_char statusTimers[8];
    u_short actionDelay;
    u_char unk956_0 : 1;
    u_char isAnalyzed : 1;
    u_char unk956_2 : 6;
    u_char unk957;
    UiMisc miscItem;
    UiMisc unk95C;
    UiMiscRand unk960;
} vs_ActorStats;

enum ActorRole {
    actorRoleAshley = 1,
    actorRoleFriendly = 2,
    actorRoleEngagedEnemy = 4,
    actorRoleDisengagedEnemy = 8,
    actorRoleModelOnly = 0x10, // no battle role
    actorRoleCombatant = actorRoleAshley | actorRoleFriendly | actorRoleEngagedEnemy,
};

typedef struct Actor {
    struct Actor* next;
    int slot;
    u_char unk8;
    u_char unk9;
    u_char unkA;
    u_char unkB_0 : 2;
    u_char unkB_2 : 2;
    u_char unkB_4 : 4;
    union {
        int s32[3];
        short s16[6];
        u_short u16[6];
        u_char u8[12];
    } commandArgs;
    u_short id;
    u_short subType;
    u_short role;
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
    vs_TilePosition currentTile;
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
    vs_ActorStats* stats;
    int unk40;
    EntityBase* unk44;
    void* unk48[2];
} Actor;

typedef struct {
    Actor unk0;
    vs_ActorStats unk50;
} ActorAndStats;

typedef struct {
    ActorAndStats unk0;
    D_800F45E0_t unk9B4;
} ObjectActor_dat;

typedef struct {
    ActorAndStats unk0;
    D_800F4538_t unk9B4;
    char unk2290[0x24];
    ActorSubModel unk22B4[2];
} Actor_dat;

typedef struct {
    ActorAndStats unk0;
    D_800F4538_t unk9B4;
    char unk2290[0x24];
    D_800F4538_t unk22B4;
    char unk3B90[0x24];
} ActorExtraShp_dat;

void vs_battle_nop0(vs_ActorStats*);
void func_80086FA8(int, vs_ActorStats*);
extern Actor* vs_battle_actors[];
extern Actor* vs_battle_characterState;

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
void vs_battle_setActorEdgeHighlight(int, int, EdgeHighlight*, CVECTOR*);
int vs_battle_setActorAnimation(int actorId, int animation, int unused, int blendFrames);
int func_800A0768(int, CVECTOR*);
int setActorLightColor(int, CVECTOR*);
void vs_battle_setActorFlags(int actorId, int flags);
u_int vs_battle_getActorFlags(int actorId);
int vs_battle_getActorPosition(int, vs_ActorPosition*);
int func_800A13EC(int, int, int*, int);
