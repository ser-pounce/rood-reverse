#pragma once
#include "../../BATTLE/BATTLE.PRG/146C.h"

void vs_menuD_initUiWeapon(
    vs_battle_uiWeapon*, vs_battle_inventoryWeapon*, vs_menu_containerData*);
void vs_menuD_initUiShield(
    vs_battle_uiShield*, vs_battle_inventoryShield*, vs_menu_containerData*);

extern vs_menu_container* vs_menuD_containerData;
