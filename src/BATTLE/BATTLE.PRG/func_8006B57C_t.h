#pragma once

typedef struct {
    char unk0;
    char unk1;
    char unk2;
    char unk3_0 : 3;
    char unk3_3 : 5;
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
} vs_battle_inventoryBlade;

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
} vs_battle_inventoryGrip;

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
    short unk1A;
} vs_battle_inventoryGem;

typedef struct {
    char unk0;
    u_char blade;
    u_char grip;
    char unk3;
    u_char gems[4];
    char name[24];
} vs_battle_inventoryWeapon;

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
    char types[4]; // 0x10
    char classes[8];
    char affinities[8];
    u_short material;
    u_char unk26;
    u_char index;
} vs_battle_inventoryArmor;

typedef struct {
    char unk0;
    char unk1;
    short unk2;
    vs_battle_inventoryArmor unk4;
    u_char gems[4]; // 0x2C
} vs_battle_inventoryShield;

typedef struct {
    u_short id;
    char unk2;
    char unk3;
} vs_battle_inventoryItem;

typedef struct {
    vs_battle_inventoryWeapon weapons[32];
    vs_battle_inventoryShield shields[32]; // 0x400
    vs_battle_inventoryBlade blades[64]; // 0xA00
    vs_battle_inventoryGrip grips[64]; // 0x1500
    vs_battle_inventoryArmor armor[64]; // 0x1900
    vs_battle_inventoryGem gems[192]; // 0x2300
    vs_battle_inventoryItem items[256]; // 0x3800
    // 0x3C00
} vs_menu_containerData;
