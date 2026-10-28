#pragma once
#include <sys/types.h>
#include <libgte.h>

typedef struct {
    u_char targetActor;
    signed char targetLimb;
    u_char hitThreshold;
    u_char unk3;
    short hp;
    short mp;
} func_8008631C_t2;

typedef struct {
    short value0;
    short value1;
} limbEffects_t;

typedef struct {
    func_8008631C_t2 unk0;
    short risk;
    short strength;
    short intelligence;
    short agility;
    short maxHp;
    short maxMp;
    int removeStatuses;
    int inflictStatuses;
    u_int hpEffect : 2;
    u_int mpEffect : 2;
    u_int riskEffect : 2;
    u_int strengthEffect : 2;
    u_int intelligenceEffect : 2;
    u_int agilityEffect : 2;
    u_int maxHpEffect : 2;
    u_int maxMpEffect : 2;
    u_int unk1C_16 : 2;
    u_int weaponDpEffect : 2;
    u_int weaponPpEffect : 2;
    u_int armorDpEffect : 2;
    u_int shieldPpEffect : 2;
    u_int unk1C_26 : 2;
    u_int unk1C_28 : 4;
    union {
        limbEffects_t effects;
        u_int hp;
    } limbs[6];
    short weaponDp;
    short weaponPp;
    short armorDp;
    short shieldPp;
    int unk40;
} _hitEntity_t;

typedef struct {
    u_short actionIndex;
    char unk2;
    char unk3;
    _hitEntity_t unk4;
    u_short unk48;
    u_short unk4A;
    _hitEntity_t unk4C[30];
    SVECTOR unk844;
} D_800F19CC_t2;
