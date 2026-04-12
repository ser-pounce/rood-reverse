#pragma once
#include "../../SLUS_010.40/main.h"
#include "../../BATTLE/BATTLE.PRG/146C.h"
#include "../../BATTLE/BATTLE.PRG/func_8006B57C_t.h"

typedef struct {
    vs_battle_classAffinityCurrent classAffinityCurrent;
    short types[32];
} vs_mainMenu_setUiWeaponStats_t;

void func_80101F38(void);

extern char D_80102410[64];
extern int D_80102450;
extern char D_80102454;
extern char D_80102455;
extern char D_80102456;
extern vs_battle_inventoryGem* vs_mainMenu_gems;
extern vs_menu_inventoryStorage_t* vs_menu_inventoryStorage;
extern vs_battle_inventoryGrip* vs_mainMenu_grips;
extern vs_battle_inventoryBlade* vs_mainMenu_blades;
extern vs_battle_inventoryArmor* vs_mainMenu_armor;
extern vs_battle_inventoryShield* vs_mainMenu_shields;
extern vs_battle_inventoryWeapon* vs_mainMenu_weapons;
extern vs_main_CdQueueSlot* _itemNamesCdQueueSlot;
extern char _itemNamesLoading;
extern char D_80102480[8];
extern short D_80102488[4];
extern char D_80102490[8];
extern short D_80102498[];
extern char D_801024A0;
extern char D_801024A1;
extern u_short* vs_mainMenu_menu12Text;
extern short vs_mainMenu_strIntAgi[8];
extern u_char D_801024B8;
extern char D_801024B9;
extern short vs_mainMenu_equipmentStats[64];
extern u_short* vs_mainMenu_itemHelp;
extern char D_80102544;
extern char vs_mainMenu_equipmentSubtype;
