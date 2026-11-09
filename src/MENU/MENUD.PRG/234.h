#pragma once
#include "src/SLUS_010.40/inventory.h"
#include "src/BATTLE/BATTLE.PRG/uiEquipment.h"

int vs_menuD_exec(u_char*);
void vs_menuD_initUiWeapon(
    vs_battle_UiWeapon*, vs_main_InventoryWeapon*, vs_menu_ContainerData*);
void vs_menuD_initUiShield(
    vs_battle_UiShield*, vs_main_InventoryShield*, vs_menu_ContainerData*);

extern vs_menu_Container* vs_menuD_containerData;
