#pragma once
#include "../../BATTLE/BATTLE.PRG/146C.h"

int vs_menuD_exec(u_char*);
void vs_menuD_initUiWeapon(
    vs_battle_uiWeapon*, vs_main_inventoryWeapon*, vs_menu_containerData*);
void vs_menuD_initUiShield(
    vs_battle_uiShield*, vs_main_inventoryShield*, vs_menu_containerData*);

extern vs_menu_container* vs_menuD_containerData;
