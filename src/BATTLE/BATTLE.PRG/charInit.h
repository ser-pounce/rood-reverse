#pragma once
#include "uiEquipment.h"
#include <sys/types.h>
#include <libgte.h>

typedef struct {
    u_short id;
    char unk2;
    char index;
} Actions;

typedef struct {
    u_short hp;
    char agilityDefenseBonus;
    char chainEvasion;
    signed char types[4];
    signed char affinities[8];
    Actions actions[4];
    ArmorIntermediate unk20;
    char dpSplash[6];
    char unk5A[2];
} LimbInit;

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
    vs_battle_WeaponIntermediate weapon;
    vs_battle_ShieldIntermediate shield;
    AccessoryIntermediate accessory;
    LimbInit limbs[6];
    int mpdIdentifer;
} vs_battle_CharInitData;
