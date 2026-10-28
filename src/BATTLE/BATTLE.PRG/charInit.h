#pragma once
#include "uiEquipment.h"
#include <sys/types.h>
#include <libgte.h>

typedef struct {
    u_short id;
    char unk2;
    char index;
} _actions;

typedef struct {
    u_short hp;
    char agilityDefenseBonus;
    char chainEvasion;
    signed char types[4];
    signed char affinities[8];
    _actions actions[4];
    _armorIntermediate unk20;
    char dpSplash[6];
    char unk5A[2];
} _limbInit;

typedef struct {
    u_short subType;
    u_char unk2;
    u_int reach : 5;
    u_int unk3_5 : 3;
    char name[24];
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
    _limbInit limbs[6];
    int mpdIdentifer;
} vs_battle_charInitData;
