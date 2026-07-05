#pragma once
#include "src/SLUS_010.40/main.h"
#include "src/BATTLE/BATTLE.PRG/146C.h"
#include "src/BATTLE/BATTLE.PRG/5BF94.h"
#include "src/BATTLE/BATTLE.PRG/func_8006B57C_t.h"

enum vs_mainMenu_actionsMenuActions { actionMenuDiscard = 4, actionMenuSort = 45 };

/**
 * Adds rows to the actions menu.
 *
 * @param count High byte indicates the starting offset when there are more than 7
 * actions.
 * @param subMenuId An identifier used for some conditional logic and managing cursor
 * memory.
 */
void vs_mainMenu_addMenuActions(
    int count, int subMenuId, char* menuText[], int rowTypes[]);

/**
 * Returns the currently highlighted action.
 */
int vs_mainMenu_getSelectedAction(void);

/**
 * Determines both whether the top level action menu has finished cleaning up, and
 * retrieves the selected action.
 *
 * @return The selected action if the main action menu hs finished cleanup, -1 otherwise.
 */
int vs_mainMenu_actionInputProcessed(void);

/**
 * Updates the action menu.
 */
void vs_mainMenu_renderItemActionMenu(void);

/**
 * Prints the selected rows' description to information box if the present.
 *
 * @param actionMenuState Function does nothing if this is < 16.
 */
void vs_mainMenu_printInformation(int sourceRow, int actionMenuState);

enum vs_mainMenu_menuCommands {
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
 */
void vs_mainMenu_setMenuCommand(enum vs_mainMenu_menuCommands action);

void func_800FFB68(int);

/**
 * Removes the menu row.
 */
void vs_mainMenu_deactivateMenuItem(int row);

/**
 * Dismisses text box ID 7, used for the information
 * display at the bottom of the screen.
 */
void vs_mainMenu_dismissInformationBox(void);

/**
 * Initializes text box ID 7, used for the information
 * display at the bottom of the screen.
 */
void vs_mainMenu_initInformationBox(void);

/**
 * Copies the text to display in the info box.
 */
void vs_mainmenu_setInformationMessage(char* message);

enum vs_mainMenu_buttonIDs {
    buttonIdTriangle,
    buttonIdSquare,
    buttonIdCircle,
    buttonIdCross,
    buttonIdL1,
    buttonIdR1,
    buttonIdL2,
    buttonIdR2
};

/**
 * Renders a well-known button.
 *
 * @param before Can be set to null, in which case prepends to
 * the OT at 0x1F800008.
 */
void vs_mainmenu_renderButton(
    enum vs_mainMenu_buttonIDs buttonId, int x, int y, u_long* before);

/**
 * Renders the cursor at the specified location and with the
 * provided animation step (essentially mapped to a brightness value).
 * Cursor color is set by assigning to `vs_mainMenu_cursorColor`.
 *
 * @return The next animation step.
 */
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
extern char vs_mainMenu_actionMenuState;
extern char vs_mainMenu_cursorColor;
extern char vs_mainMenu_hideMenu;
extern int D_801022D8;
extern char D_801023D0;
extern char D_801023E3;
extern char _rangeRiskData[8];
extern short D_80102488[4];
extern char D_80102490[8];
extern short D_80102498[4];
extern char _menuActionsPageOffset;
extern char vs_mainMenu_currentUiItem;
extern char bss_7[2];
extern u_short* vs_mainMenu_menu12Text;
extern short vs_mainMenu_strIntAgi[8];

enum vs_mainMenu_statusUiIds {
    statusUiPp,
    statusUiDp,
    statusUistatPageFirstElement,
    statusUistatPageLastElement = 8,
    statusUiPrincipleItem,
    statusUiRange = 16,
    statusUiRisk,
    statusUiStr,
    statusUiInt,
    statusUiAgi,
};

extern u_char vs_mainMenu_selectedStatusViewElement;

enum vs_mainMenu_statPage {
    statPageClass,
    statPageAffinity,
    statPageType,
    statPageNone,
};

extern char vs_mainMenu_itemStatPage;

extern char bss_3[6];
extern short vs_mainMenu_equipmentStats[64];
extern u_short* vs_mainMenu_itemHelp;
extern char vs_mainMenu_enabledStatPages;
extern char vs_mainMenu_equipmentSubtype;
extern char bss_4[18];
extern struct textHeader_t _textHeaders[];
extern char D_80102578;
