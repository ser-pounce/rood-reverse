#pragma once
#include "src/SLUS_010.40/main.h"
#include "src/BATTLE/BATTLE.PRG/146C.h"
#include "src/BATTLE/BATTLE.PRG/5BF94.h"
#include "src/BATTLE/BATTLE.PRG/func_8006B57C_t.h"

void vs_mainMenu_initSortUi(int count, int subMenuId, char* menuText[], int rowTypes[]);
int func_800FF348(void);
int vs_mainMenu_getSelectedItemAction(void);
void vs_mainMenu_processItemActionMenu(void);
void vs_mainMenu_printInformation(int, int);

enum vs_mainMenu_menuActions {
    menuActionNone,
    menuActionCommand,
    menuActionMenu,
    menuActionNum,
    menuActionWarning,
    menuActionHelp,
    menuActionInfo
};

/**
 * Sets the text at the very top of the menu.
 * Text is automatically animated replaced with a slide animation
 * off the top of the screen.
 */
void vs_mainMenu_setNextMenuAction(enum vs_mainMenu_menuActions action);

void func_800FFA94(void);
void func_800FFB68(int);
void vs_mainMenu_deactivateMenuItem(int);

/**
 * Dismisses text box ID 7, used for the information
 * display at the bottom of the screen.
 */
void vs_mainMenu_dismissTextBox(void);

/**
 * Initializes text box ID 7, used for the information
 * display at the bottom of the screen.
 */
void vs_mainMenu_initTextBox(void);

void vs_mainmenu_setInformationMessage(char*);
void vs_mainmenu_renderButton(int index, int x, int y, u_long* data);
int vs_mainMenu_renderCursor(u_int animStep, int xy);
int vs_mainMenu_renderIntColor(int, int, int, u_long*);
int func_800FFE20(int arg0, int arg1, int arg2, u_long* arg3);
void vs_mainMenu_renderIntColorDefault(int, int, u_long*);
void vs_mainMenu_renderMenuRowIcon(int, int, int);
void vs_mainMenu_unpackMenubg(u_int*);

/**
 * Populates one of two elements for displaying skill costs.
 *
 * @param index 0 is intended for the cost type, 1 for the value.
 * @param disabled Displays value in gray.
 */
void vs_mainmenu_setSkillCost(int index, char const* text, int xOffset, int disabled);

void vs_mainmenu_renderButtonUiBackground(int x, int y, int w, int h);
void func_80100414(int, int);
int func_80100814(void);

/**
 * Initialises multiple menu rows
 *
 * @param rowCount
 * @param rowInfo Packed values
 * - Bits 0-3: Submenu identifier for cursor history
 * - Bits 4-7: X offset in menu rows
 * - Bits 8+: Y negative offset in pixels
 * @param strings Pairs of strings for the menu and info text box.
 * @param rowTypes Packed row style flags.
 */
void vs_mainmenu_setMenuRows(int rowCount, int rowInfo, char* strings[], int rowTypes[]);

/**
 * Retrieve row confirmed by the user.
 */
int vs_mainMenu_getConfirmedRow(void);

enum vs_mainMenu_menuSelection {
    menuSelectionConfirm,
    menuSelectionBack = 0xFFFF,
    menuSelectionQuit = -2
};

/**
 * Retrieve currently selected row.
 */
int vs_mainmenu_getSelectedRow(void);

void func_80100A5C(void);
void func_80101118(int);
int func_80101268(u_int, int, vs_battle_menuItem_t*, u_long*);
void func_801013F8(int);
void func_8010154C(vs_battle_menuItem_t* arg0);
void func_80101F38(void);

#define menuRowInfo(id, x, y) ((y) << 8) | ((x) << 4) | (id)

extern char vs_mainMenu_isLevelledSpell;
extern char D_801022C4;
extern char vs_menu_cursorColor;
extern char vs_mainMenu_hideMenu;
extern int D_801022D8;
extern char D_801023D0;
extern char D_801023E3;
extern char _rangeRiskData[8];
extern short D_80102488[4];
extern char D_80102490[8];
extern short D_80102498[4];
extern char D_801024A0;
extern char vs_mainMenu_currentUiItem;
extern char bss_7[2];
extern u_short* vs_mainMenu_menu12Text;
extern short vs_mainMenu_strIntAgi[8];
extern u_char vs_mainMenu_selectedUiElement;
extern char D_801024B9;
extern char bss_3[6];
extern short vs_mainMenu_equipmentStats[64];
extern u_short* vs_mainMenu_itemHelp;
extern char D_80102544;
extern char vs_mainMenu_equipmentSubtype;
extern char bss_4[18];
extern struct textHeader_t _textHeaders[2];
extern char D_80102578;
