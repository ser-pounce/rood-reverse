#pragma once
#include "../../SLUS_010.40/main.h"
#include "../../BATTLE/BATTLE.PRG/5BF94.h"

int vs_mainMenu_loadItemNames(int);
void func_800FDD78(void);
void func_800FDEBC(void);
int func_800FEB94(
    int arg0, vs_battle_inventory_t* arg1, int arg2, vs_battle_inventory_t* arg3);
void vs_mainMenu_unequipAllWeapons(void);
void vs_mainMenu_unequipShield(void);
void vs_mainMenu_initItem(int, int);
int vs_mainMenu_ensureItemNamesLoaded(void);
int vs_mainMenu_getItemCount(int, vs_battle_inventory_t*);
int vs_mainMenu_getFirstItem(int, vs_battle_inventory_t*);
void func_800FF0EC(int, int, char**, int*);
int func_800FF348(void);
int func_800FF360(void);
void func_800FF43C(void);
void vs_mainMenu_printInformation(int, int);
void func_800FFA88(int);
void func_800FFA94(void);
void func_800FFB68(int);
void vs_mainMenu_deactivateMenuItem(int);
int vs_mainMenu_findItem(int category, int id);
void func_800FFBA8(void);
void vs_mainMenu_rebuildInventory(int);
void func_800FFBC8(void);
void vs_mainmenu_drawButton(int index, int x, int y, u_long* data);
int func_800FFCDC(u_int, int);
int func_800FFE20(int arg0, int arg1, int arg2, u_long* arg3);
void func_800FFE70(int, int, u_long*);
void func_800FFF38(int arg0, int arg1);
void func_800FFFBC(int arg0, int arg1);
int vs_mainMenu_printIntColor(int, int, int, u_long*);
void vs_mainmenu_setMessage(char*);
void vs_mainmenu_setAbilityCost(int index, char const* text, int x, int);
void vs_mainMenu_drawRowIcon(int, int, int);
void func_80100164(void);
void vs_mainMenu_drawButtonUiBackground(int, int, int, int);
void func_80100414(int, int);
void vs_mainmenu_setMenuRows(int rowCount, int, char* strings[], int rowtypes[]);
int func_80100814(void);
int func_801008B0(void);
int vs_mainmenu_getSelectedRow(void);
void func_80100A5C(void);
void func_80101118(int);
int func_80101268(u_int, int, vs_battle_menuItem_t*, u_long*);
void func_801013F8(int);
void func_8010154C(vs_battle_menuItem_t* arg0);

extern char vs_mainMenu_isLevelledSpell;
extern char vs_mainMenu_equipmentDetailNavigationMap[][4];
extern int D_801021A0[];
extern int vs_mainMenu_mainCursorXY[];
extern char D_801022C4;
extern char D_801022D5;
extern char D_801023E3;
extern char D_801024A1;
extern u_char D_801024B8;
extern u_short* vs_mainMenu_menu12Text;
