#pragma once
#include "src/SLUS_010.40/inventory.h"
#include "src/BATTLE/BATTLE.PRG/uiEquipment.h"

int vs_menuD_exec(u_char*);
void vs_menuD_initUiWeapon(vs_UiWeapon*, vs_InventoryWeapon*, vs_ContainerData*);
void vs_menuD_initUiShield(vs_UiShield*, vs_InventoryShield*, vs_ContainerData*);

extern vs_Container* vs_menuD_containerData;
