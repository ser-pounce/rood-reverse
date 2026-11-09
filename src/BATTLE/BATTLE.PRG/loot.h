#pragma once
#include "src/SLUS_010.40/inventory.h"
#include <sys/types.h>

typedef struct {
    char difficultyFlags;
    char unk1;
    char unk2;
    char unk3;
    vs_main_InventoryBlade blade;
    vs_main_InventoryGrip grip;
    vs_main_InventoryGem gems[3];
    char name[24];
} vs_battle_LootedWeapon;

typedef struct {
    char difficultyFlags;
    char unk1;
    char unk2;
    char unk3;
    vs_main_InventoryBlade blade;
} vs_battle_LootedBlade;

typedef struct {
    char difficultyFlags;
    char unk1;
    char unk2;
    char unk3;
    vs_main_InventoryGrip grip;
} vs_battle_LootedGrip;

typedef struct {
    char difficultyFlags;
    char unk1;
    char unk2;
    char unk3;
    vs_main_InventoryArmor shield;
    vs_main_InventoryGem gems[3];
} vs_battle_LootedShield;

typedef struct {
    char difficultyFlags;
    char unk1;
    char unk2;
    char unk3;
    vs_main_InventoryArmor armor;
} vs_battle_LootedArmor;

typedef struct {
    char difficultyFlags;
    char unk1;
    char unk2;
    char unk3;
    vs_main_InventoryArmor accessory;
} vs_battle_LootedAccessory;

typedef struct {
    char difficultyFlags;
    char unk1;
    char unk2;
    char unk3;
    vs_main_InventoryGem gem;
} vs_battle_LootedGem;

typedef struct {
    u_short id;
    char difficultyFlags;
    char count;
} vs_battle_LootedMisc;

typedef struct {
    vs_battle_LootedWeapon weapon;
    vs_battle_LootedBlade blade;
    vs_battle_LootedGrip grip;
    vs_battle_LootedShield shield; // 0xF0
    vs_battle_LootedArmor armor[2]; // 0x170
    vs_battle_LootedAccessory accessory; // 0x1C8
    vs_battle_LootedGem gem; // 0x1F4
    vs_battle_LootedMisc misc[3]; // 0x214
} vs_battle_Loot;
