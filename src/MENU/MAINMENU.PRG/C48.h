#pragma once
#include <stddef.h>
#include "../../SLUS_010.40/main.h"
#include "../../BATTLE/BATTLE.PRG/5BF94.h"

enum vs_mainMenu_menuItemIds { vs_mainMenu_menuItemIds_none = 40 };

void func_800FA448(void);
void vs_mainMenu_menuItemFlyoutRight(int arg0);
void vs_mainMenu_menuItemFlyoutLeft(int arg0);
int vs_mainMenu_getEquipmentMaxStats(void* item, u_int itemCategory);
void func_800FA854(int arg0);
void vs_mainMenu_clearMenuExcept(enum vs_mainMenu_menuItemIds id);
int vs_mainmenu_ready(void);
void func_800FA92C(int arg0, int arg1);
void vs_mainMenu_exec(int);
void func_800FAEBC(int);
void func_800FBB8C(int arg0);
void vs_mainMenu_drawClassAffinityType(int);
void vs_mainMenu_setRangeRisk(int arg0, int arg1, int arg2, int arg3);
void vs_mainMenu_setStrIntAgi(int, int, int, int);
void func_800FBD80(int);
void vs_mainMenu_renderEquipStats(int);
void vs_mainMenu_setDpPp(int, int, int, int);
void vs_mainMenu_drawDpPpbars(int);
void vs_mainMenu_setUiWeapon(vs_battle_uiWeapon*, char**, int*, char*);
vs_battle_menuItem_t* vs_mainMenu_initSetWeaponGemMenu(int, int, int);
vs_battle_menuItem_t* vs_mainMenu_initSetShieldGemMenu(int, int, int);
void vs_mainMenu_initUiWeapon(
    vs_battle_inventoryWeapon* arg0, char** arg1, int* arg2, char* arg3);
void vs_mainMenu_setUiBlade(vs_battle_inventoryBlade*, char**, int*, char*);
void vs_mainMenu_setUiGrip(vs_battle_inventoryGrip*, char**, int*, char*);
void vs_mainMenu_initUiShield(
    vs_battle_inventoryShield* arg0, char** arg1, int* arg2, char* arg3);
void vs_mainMenu_setUiShield(vs_battle_uiShield*, char**, int*, char*);
void vs_mainMenu_setUiArmor(vs_battle_uiArmor*, char**, int*, char*);
void vs_mainMenu_initUiArmor(
    vs_battle_inventoryArmor* arg0, char** arg1, int* arg2, char* arg3);
void vs_mainMenu_setUiGem(
    vs_battle_inventoryGem* arg0, char** arg1, int* arg2, void* arg3);
void vs_mainMenu_setUiItem(
    vs_battle_inventoryMisc* arg0, char** arg1, int* arg2, void* arg3);
void vs_mainMenu_setUiBladeStats(int);
void vs_mainMenu_setUiGripStats(int);
void vs_mainMenu_setShieldStats(int);
void vs_mainMenu_setArmorStats(int);
void vs_mainMenu_setGemStats(int);
void vs_mainMenu_resetStats(void);
void func_8010044C(u_int*);

extern char vs_mainMenu_weaponHands[];
extern vs_menu_inventoryStorage_t* vs_menu_inventoryStorage;
extern char D_80102578;
