#pragma once
#include <sys/types.h>

typedef struct {
    char range;
    char unk1;
    char unk2;
    char attackShape : 3;
    char attackShapeAngle : 5;
} vs_Range;

typedef struct {
    u_char id;
    char subId;
    char wepId;
    char category;
    u_short maxDp;
    u_short maxPp;
    u_short currentDp;
    u_short currentPp;
    signed char strength;
    signed char intelligence;
    signed char agility;
    char cost;
    char damageType : 2;
    char costType : 3;
    char unk10_5 : 3;
    char unk11;
    u_short unk12;
    vs_Range range;
    signed char classes[8];
    signed char affinities[8];
    u_short material;
    char assembledWeaponIndex;
    char index;
} vs_InventoryBlade;

typedef struct {
    u_short id;
    char subId;
    u_char category;
    char gemSlots;
    signed char strength;
    signed char intelligence;
    signed char agility;
    signed char types[4];
    u_short assembledWeaponIndex;
    u_short index;
} vs_InventoryGrip;

typedef struct {
    u_short id;
    char subId;
    char unk3;
    char gemEffects;
    signed char strength;
    signed char intelligence;
    signed char agility;
    signed char classes[8];
    signed char affinities[8];
    u_short setItemIndex;
    short index;
} vs_InventoryGem;

typedef struct {
    char index;
    u_char blade;
    u_char grip;
    char isEquipped;
    u_char gems[4];
    char name[24];
} vs_InventoryWeapon;

typedef struct {
    u_char id;
    u_char subId;
    char wepId;
    char category;
    u_short maxDp;
    u_short maxPp;
    u_short currentDp;
    u_short currentPp;
    char gemSlots;
    signed char strength;
    signed char intelligence;
    signed char agility;
    signed char types[4]; // 0x10
    signed char classes[8];
    signed char affinities[8];
    u_short material;
    u_char limb;
    u_char index;
} vs_InventoryArmor;

typedef struct {
    char index;
    char isEquipped;
    short unk2;
    vs_InventoryArmor base;
    u_char gems[4]; // 0x2C
} vs_InventoryShield;

typedef struct {
    u_short id;
    char count;
    char index;
} vs_InventoryMisc;

typedef struct {
    vs_InventoryWeapon weapons[32];
    vs_InventoryShield shields[32];
    vs_InventoryBlade blades[64];
    vs_InventoryGrip grips[64];
    vs_InventoryArmor armor[64];
    vs_InventoryGem gems[192];
    vs_InventoryMisc misc[256];
    // 0x3C00
} vs_ContainerData;

typedef struct {
    u_short weapons[32];
    u_short blades[64];
    u_short grips[64];
    u_short shields[32];
    u_short armor[64];
    u_short gems[192];
    u_short misc[256];
} vs_ContainerIndices;

typedef struct {
    vs_ContainerData data;
    vs_ContainerIndices indices;
} vs_Container;

typedef struct {
    u_char weapons[8];
    u_char blades[16];
    u_char grips[16];
    u_char shields[8];
    u_char armor[16];
    u_char gems[48];
    u_char misc[64];
} vs_InventoryIndices;

typedef struct {
    char unk0[15][256];
    vs_InventoryIndices unkF00;
    vs_ContainerData unkFB0;
    vs_ContainerData unk4BB0;
    vs_ContainerData unk87B0;
    u_short itemsToTransfer[64];
    vs_Container unkC430;
    vs_Container unk105B0;
} vs_InventoryStorage;

enum vs_itemCategories {
    itemCategoryWeapon,
    itemCategoryBlade,
    itemCategoryGrip,
    itemCategoryShield,
    itemCategoryArmor,
    itemCategoryGem,
    itemCategoryMisc,
    itemCategoryManage
};

enum vs_gemTargets { gemTargetShield = 0x80 };
