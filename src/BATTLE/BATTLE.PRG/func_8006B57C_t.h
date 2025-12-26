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
    u_short maxDp;
    u_short maxPp;
    u_short currentDp;
    u_short currentPp;
    char strength;
    char intelligence;
    char agility;
    char cost;
    char damageType : 2;
    char costType : 3;
    char unk10_5 : 3;
    char unk11;
    u_short unk12;
    vs_battle_range_t range;
    signed char classes[8];
    signed char affinities[8];
    short material;
    char unk2A;
    char index;
} vs_battle_droppedBlade;

typedef struct {
    u_short id;
    char subId;
    char category;
    char gemSlots;
    char strength;
    char intelligence;
    char agility;
    char types[4];
    u_short unkC;
    u_short unkE;
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
    u_short unk18;
    char unk1A;
    char unk1B;
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
