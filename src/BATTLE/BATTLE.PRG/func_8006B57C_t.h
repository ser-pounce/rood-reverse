#pragma once

typedef struct {
    char unk0;
    char unk1;
    char unk2;
    char unk3_0 : 3;
    char unk3_3 : 5;
} vs_battle_range_t;

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
    vs_battle_range_t range;
    signed char classes[8];
    signed char affinities[8];
    u_short material;
    char assembledWeaponIndex;
    char index;
} vs_battle_inventoryBlade;

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
} vs_battle_inventoryGrip;

typedef struct {
    u_short id;
    char unk2;
    char unk3;
    char gemEffects;
    signed char strength;
    signed char intelligence;
    signed char agility;
    signed char classes[8];
    signed char affinities[8];
    u_short setItemIndex;
    short index;
} vs_battle_inventoryGem;

typedef struct {
    char index;
    u_char blade;
    u_char grip;
    char isEquipped;
    u_char gems[4];
    char name[24];
} vs_battle_inventoryWeapon;

typedef struct {
    char unk0;
    char unk1;
    char unk2;
    char unk3;
    vs_battle_inventoryBlade blade;
    vs_battle_inventoryGrip grip;
    vs_battle_inventoryGem gems[3];
    char unk94[0x18];
} vs_battle_setWeaponForDropRand;

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
    u_char bodyPart;
    u_char index;
} vs_battle_inventoryArmor;

typedef struct {
    char index;
    char isEquipped;
    short unk2;
    vs_battle_inventoryArmor base;
    u_char gems[4]; // 0x2C
} vs_battle_inventoryShield;

typedef struct {
    char unk0;
    char unk1;
    char unk2;
    char unk3;
    vs_battle_inventoryArmor shield;
    vs_battle_inventoryGem gems[3];
} vs_battle_shieldForDropRand;

typedef struct {
    u_short id;
    char count;
    char index;
} vs_battle_inventoryMisc;

typedef struct {
    vs_battle_inventoryWeapon weapons[32];
    vs_battle_inventoryShield shields[32];
    vs_battle_inventoryBlade blades[64];
    vs_battle_inventoryGrip grips[64];
    vs_battle_inventoryArmor armor[64];
    vs_battle_inventoryGem gems[192];
    vs_battle_inventoryMisc misc[256];
    // 0x3C00
} vs_menu_containerData;

typedef struct {
    u_short weapons[32];
    u_short blades[64];
    u_short grips[64];
    u_short shields[32];
    u_short armor[64];
    u_short gems[192];
    u_short misc[256];
} vs_menu_containerIndices;

typedef struct {
    vs_menu_containerData data;
    vs_menu_containerIndices indices;
} vs_menu_container;

typedef struct {
    char unk0[8];
    char unk8[16];
    char unk18[16];
    char unk28[8];
    char unk30[16];
    char unk40[48];
    char unk70[64];
} D_800619D8_t;

typedef struct {
    char unk0[15][256];
    D_800619D8_t unkF00;
    vs_menu_containerData unkFB0;
    vs_menu_containerData unk4BB0;
    vs_menu_containerData unk87B0;
    u_short itemsToTransfer[64];
    vs_menu_container unkC430;
    vs_menu_container unk105B0;
} vs_menu_inventoryStorage_t;

enum vs_itemCategories {
    itemCategoryWeapon,
    itemCategoryBlade,
    itemCategoryGrip,
    itemCategoryShield,
    itemCategoryArmor,
    itemCategoryGem,
    itemCategoryItem
};

enum vs_gemTargets { gemTargetShield = 0x80 };

typedef struct {
    char unk0;
    char unk1;
    char unk2;
    char unk3;
    vs_battle_inventoryArmor accessory;
} _setAccessoryForDropRand_t;

typedef struct {
    char unk0;
    char unk1;
    char unk2;
    char unk3;
    vs_battle_inventoryArmor armor;
} _setArmorForDropRand_t;

typedef struct {
    char unk0;
    char unk1;
    char unk2;
    char unk3;
    vs_battle_inventoryBlade blade;
} _setBladeForDropRand_t;

typedef struct {
    char unk0;
    char unk1;
    char unk2;
    char unk3;
    vs_battle_inventoryGrip grip;
} _setGripForDropRand_t;

typedef struct {
    char unk0;
    char unk1;
    char unk2;
    char unk3;
    vs_battle_inventoryGem gem;
} _setGemForDropRand_t;

typedef struct {
    vs_battle_setWeaponForDropRand weapon;
    _setBladeForDropRand_t unkB0;
    _setGripForDropRand_t unkE0;
    vs_battle_shieldForDropRand shield; // 0xF0
    _setArmorForDropRand_t armor[2]; // 0x170
    _setAccessoryForDropRand_t accessory; // 0x1C8
    _setGemForDropRand_t gem; // 0x1F4
    vs_battle_inventoryMisc misc[2]; // 0x214
    u_short unk21C;
    char unk21E;
    char unk21F;
} func_8006BE64_t2;