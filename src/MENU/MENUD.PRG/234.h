#pragma once
#include "../../BATTLE/BATTLE.PRG/146C.h"

void func_80102A34(
    vs_battle_equippedWeapon*, vs_battle_inventoryWeapon*, vs_menu_containerData*);
void func_80102BB0(
    vs_battle_equippedShield*, vs_battle_inventoryShield*, vs_menu_containerData*);

typedef struct {
    vs_menu_containerData unk0;
    short unk3C00[1];
} func_80102C94_t;

extern func_80102C94_t* vs_menuD_containerData;
