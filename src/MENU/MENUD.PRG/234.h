#pragma once
#include "../../BATTLE/BATTLE.PRG/146C.h"

typedef struct {
    vs_battle_inventoryWeapon weapons[32];
    vs_battle_inventoryShield shields[32]; // 0x18F0
    vs_battle_inventoryBlade blades[64]; // 0x9D4
    vs_battle_inventoryGrip grips[64]; // 0x14F0
    vs_battle_inventoryArmor armor[64]; // 0x1EF0
    vs_battle_inventoryGem gems[192];
    vs_battle_inventoryItem items[256];
} vs_menu_containerData;

void func_80102A34(
    vs_battle_equippedWeapon*, vs_battle_inventoryWeapon*, vs_menu_containerData*);
void func_80102BB0(void*, void*, vs_menu_containerData*);

extern vs_menu_containerData* vs_menuD_containerData;
