#pragma once

typedef struct {
    char unk0;
    char unk1;
    char unk2;
    char unk3;
} vs_battle_range_t;

typedef struct {
    char id;
    char unk1;
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
    short costType;
    short unk12;
    vs_battle_range_t range;
    signed char classes[8];
    signed char affinities[8];
    short material;
    short unk2A;
} func_8006B57C_t;

typedef struct {
    short id;
    char unk2;
    char category;
    char gemSlots;
    char strength;
    char intelligence;
    char agility;
    char types[4];
    char unkC[4];
} vs_battle_setGripForDrop_t;

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
} func_800FD17C_t;