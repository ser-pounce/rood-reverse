#pragma once
#include "src/SLUS_010.40/inventory.h"
#include <sys/types.h>

typedef struct {
    char difficultyFlags;
    char unk1;
    char unk2;
    char unk3;
    vs_InventoryBlade blade;
    vs_InventoryGrip grip;
    vs_InventoryGem gems[3];
    char name[24];
} vs_LootedWeapon;

typedef struct {
    char difficultyFlags;
    char unk1;
    char unk2;
    char unk3;
    vs_InventoryBlade blade;
} vs_LootedBlade;

typedef struct {
    char difficultyFlags;
    char unk1;
    char unk2;
    char unk3;
    vs_InventoryGrip grip;
} vs_LootedGrip;

typedef struct {
    char difficultyFlags;
    char unk1;
    char unk2;
    char unk3;
    vs_InventoryArmor shield;
    vs_InventoryGem gems[3];
} vs_LootedShield;

typedef struct {
    char difficultyFlags;
    char unk1;
    char unk2;
    char unk3;
    vs_InventoryArmor armor;
} vs_LootedArmor;

typedef struct {
    char difficultyFlags;
    char unk1;
    char unk2;
    char unk3;
    vs_InventoryArmor accessory;
} vs_LootedAccessory;

typedef struct {
    char difficultyFlags;
    char unk1;
    char unk2;
    char unk3;
    vs_InventoryGem gem;
} vs_LootedGem;

typedef struct {
    u_short id;
    char difficultyFlags;
    char count;
} vs_LootedMisc;

typedef struct {
    vs_LootedWeapon weapon;
    vs_LootedBlade blade;
    vs_LootedGrip grip;
    vs_LootedShield shield; // 0xF0
    vs_LootedArmor armor[2]; // 0x170
    vs_LootedAccessory accessory; // 0x1C8
    vs_LootedGem gem; // 0x1F4
    vs_LootedMisc misc[3]; // 0x214
} vs_Loot;
