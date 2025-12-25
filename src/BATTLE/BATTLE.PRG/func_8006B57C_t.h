#pragma once

typedef struct {
    char unk0;
    char unk1;
    char unk2;
    char unk3;
} vs_battle_range_t;

typedef struct {
    char id;
    char subId;
    char wepId;
    char category;
    short maxDp;
    short maxPp;
    short currentDp;
    short currentPp;
    char strength;
    char intelligence;
    char agility;
    char cost;
    short damageType : 2;
    short costType : 3;
    short unk10_7 : 11;
    short unk12;
    vs_battle_range_t range;
    signed char classes[8];
    signed char affinities[8];
    short material;
    short unk2A;
} vs_battle_droppedBlade;

typedef struct {
    short id;
    char subId;
    char category;
    char gemSlots;
    char strength;
    char intelligence;
    char agility;
    char types[4];
    char unkC[4];
} vs_battle_droppedGrip;

typedef struct {
    u_short id;
    char unk2;
    char unk3;
    char gemEffects;
    char strength;
    char intelligence;
    char agility;
    signed char classes[8];
    signed char affinities[8];
    signed char unk18[4];
} vs_battle_droppedGem;

typedef struct {
    char unk0;
    u_char blade;
    u_char grip;
    char unk3;
    u_char gems[4];
    char name[24];
} vs_battle_droppedWeapon;

typedef struct {
    char id;
    char subId;
    char wepId;
    char category;
    u_short maxDp;
    u_short maxPp;
    u_short currentDp;
    u_short currentPp;
    char gemSlots;
    char strength;
    char intelligence;
    char agility;
    char types[4];
    char classes[8];
    char affinities[8];
    u_short material;
    u_char unk26;
    u_char unk27;
} vs_battle_droppedArmor;

typedef struct {
    char unk0;
    char unk1;
    short unk2;
    vs_battle_droppedArmor unk4;
    char gems[4];
} vs_battle_droppedShield;
