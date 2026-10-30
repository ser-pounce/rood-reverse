#pragma once
#include "src/SLUS_010.40/inventory.h"
#include <sys/types.h>

typedef struct {
    char difficultyFlags;
    char unk1;
    char unk2;
    char unk3;
    vs_main_inventoryBlade blade;
    vs_main_inventoryGrip grip;
    vs_main_inventoryGem gems[3];
    char name[24];
} vs_battle_lootedWeapon;

typedef struct {
    char difficultyFlags;
    char unk1;
    char unk2;
    char unk3;
    vs_main_inventoryBlade blade;
} vs_battle_lootedBlade;

typedef struct {
    char difficultyFlags;
    char unk1;
    char unk2;
    char unk3;
    vs_main_inventoryGrip grip;
} vs_battle_lootedGrip;

typedef struct {
    char difficultyFlags;
    char unk1;
    char unk2;
    char unk3;
    vs_main_inventoryArmor shield;
    vs_main_inventoryGem gems[3];
} vs_battle_lootedShield;

typedef struct {
    char difficultyFlags;
    char unk1;
    char unk2;
    char unk3;
    vs_main_inventoryArmor armor;
} vs_battle_lootedArmor;

typedef struct {
    char difficultyFlags;
    char unk1;
    char unk2;
    char unk3;
    vs_main_inventoryArmor accessory;
} vs_battle_lootedAccessory;

typedef struct {
    char difficultyFlags;
    char unk1;
    char unk2;
    char unk3;
    vs_main_inventoryGem gem;
} vs_battle_lootedGem;

typedef struct {
    u_short id;
    char difficultyFlags;
    char count;
} vs_battle_lootedMisc;

typedef struct {
    vs_battle_lootedWeapon weapon;
    vs_battle_lootedBlade blade;
    vs_battle_lootedGrip grip;
    vs_battle_lootedShield shield; // 0xF0
    vs_battle_lootedArmor armor[2]; // 0x170
    vs_battle_lootedAccessory accessory; // 0x1C8
    vs_battle_lootedGem gem; // 0x1F4
    vs_battle_lootedMisc misc[3]; // 0x214
} vs_battle_loot;
