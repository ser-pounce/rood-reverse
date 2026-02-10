#pragma once
#include <stddef.h>
#include "../../SLUS_010.40/main.h"
#include "../../BATTLE/BATTLE.PRG/5BF94.h"

typedef struct {
    short strength;
    short intelligence;
    short agility;
    short unk6;
} vs_mainMenu_strIntAgi_t;

void func_800FA448(void);
void vs_mainMenu_menuItemLeaveRight(int arg0);
void func_800FA810(int arg0);
void func_800FA854(int arg0);
void func_800FA8E0(int);
int vs_mainmenu_ready(void);
void func_800FA92C(int arg0, int arg1);
void func_800FAAC8(int);
void func_800FAEBC(int);
void func_800FBB8C(int arg0);
void func_800FBBD4(int);
void vs_mainMenu_setRangeRisk(int arg0, int arg1, int arg2, int arg3);
void vs_mainMenu_setStrIntAgi(int, int, int, int);
void func_800FBD80(int);
void vs_battle_renderEquipStats(int);
void vs_mainMenu_setDpPp(int, int, int, int);
void vs_mainMenu_drawDpPpbars(int);
void vs_mainMenu_setWeaponUi(vs_battle_uiWeapon*, char**, int*, char*);
vs_battle_menuItem_t* func_800FC510(int, int, int);
vs_battle_menuItem_t* func_800FC704(int, int, int);
void func_800FCA08(vs_battle_inventoryWeapon* arg0, char** arg1, int* arg2, char* arg3);
void vs_mainMenu_setBladeUi(vs_battle_inventoryBlade*, char**, int*, char*);
void vs_mainMenu_setGripUi(vs_battle_inventoryGrip*, char**, int*, char*);
void func_800FCE40(vs_battle_inventoryShield* arg0, char** arg1, int* arg2, char* arg3);
void vs_mainMenu_setShieldUi(vs_battle_uiShield*, char**, int*, char*);
void vs_mainMenu_setArmorUi(vs_battle_uiArmor*, char**, int*, char*);
void vs_mainMenu_setAccessoryUi(
    vs_battle_inventoryArmor* arg0, char** arg1, int* arg2, char* arg3);
void vs_mainMenu_setGemUi(
    vs_battle_inventoryGem* arg0, char** arg1, int* arg2, void* arg3);
void vs_mainMenu_setItemUi(
    vs_battle_inventoryMisc* arg0, char** arg1, int* arg2, void* arg3);
void func_800FD270(int);
void func_800FD404(int);
void func_800FD504(int);
void func_800FD5A0(int);
void func_800FD700(int);
void func_800FD878(int);
void vs_mainMenu_resetStats(void);
void func_8010044C(u_int*);

extern char vs_mainMenu_weaponHands[];
extern char (*vs_mainMenu_itemNames)[24];
extern char vs_mainMenu_inventoryItemCapacities[];
extern char* vs_mainMenu_inventoryIndices[];
extern char D_801023D0;
extern vs_menu_inventoryStorage_t* vs_menu_inventoryStorage;
extern vs_mainMenu_strIntAgi_t vs_mainMenu_strIntAgi[2];
extern char D_801024B9;
extern short vs_mainMenu_equipmentStats[0x40];
extern short D_80102508;
extern u_short* vs_mainMenu_itemHelp;
extern char D_80102544;
extern char vs_mainMenu_equipmentSubtype;
extern char D_80102578;
extern vs_battle_inventoryGem* D_80102458;
extern vs_battle_inventoryGrip* D_80102460;
extern vs_battle_inventoryBlade* D_80102464;
extern vs_battle_inventoryArmor* D_80102468;
extern vs_battle_inventoryShield* D_8010246C;
extern vs_battle_inventoryWeapon* D_80102470;
