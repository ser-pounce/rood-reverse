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

/**
 * Controls whether the background fades in or out.
 *
 * @param fadeState 0 == fade in, fade out otherwise.
 */
void vs_mainMenu_toggleBackgroundFade(int fadeState);

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

/**
 * Renders the provided value.
 */
int vs_mainMenu_renderIntColor(int value, int xy, int color, u_long* before);

/**
 * Renders the provided value with preset colors based on
 * a comparison to `threshold`.
 */
int vs_mainMenu_renderIntWithThreshold(int value, int xy, int threshold, u_long* before);

/**
 * Invokes `vs_mainMenu_renderIntColor` with a neutral gray color.
 */
void vs_mainMenu_renderIntColorDefault(int value, int xy, u_long* before);

enum vs_mainMenu_icons { mainMenuIconGem = 22 };

/**
 * Renders a well-known icon at the specified point.
 *
 * @param icon Packed value:
 *
 * - Bits 0-7: Icon id
 *
 * - Bit 8: Toggle low / high brightness
 *
 * - Bits 16-17: 1 == fade from top, 2 == fade from bottom
 */
void vs_mainMenu_renderMenuRowIcon(int icon, int x, int y);

/**
 * Populates one of two elements for displaying skill costs.
 *
 * @param index 0 is intended for the cost type, 1 for the value.
 * @param disabled Displays value in gray.
 */
void vs_mainmenu_setSkillCost(int index, char const* text, int xOffset, int disabled);

/**
 * Renders the brownish, chisel-shaped background used behind command buttons.
 */
void vs_mainmenu_renderButtonBackground(int x, int y, int w, int h);

/**
 * Sets the background rendering position within the OT.
 *
 * @param otOffset Generally small negative values when fading out (-2, -4),
 * and large values when fading in (2046 / 2047). Positive values also disable
 * the limb status indicator.
 */
void vs_mainMenu_setBackgroundRenderPriority(int otOffset, int brightness);

/**
 * Unpacks the RLE buffer and stores it in VRAM.
 */
void vs_mainMenu_unpackMenubg(u_int* buf);

#define menuRowInfo(id, x, y) ((y) << 8) | ((x) << 4) | (id)

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
 * Stores the currently selected row for later cursor retrieval.
 *
 * @return Packed value:
 *
 * - Bits 0-7: The absolute row offset.
 *
 * - Bits 8-15: The row's identifer.
 */
int vs_mainMenu_storeCursor(void);

/**
 * Retrieve absolute row confirmed by the user.
 */
int vs_mainMenu_getConfirmedRow(void);

enum vs_mainMenu_menuSelection {
    menuSelectionConfirm,
    menuSelectionBack = 0xFFFF,
    menuSelectionQuit = -2
};

/**
 * Retrieve currently selected row.
 *
 * @return The relative row, or -1 if menu cleanup is still ongoing.
 */
int vs_mainmenu_getSelectedRow(void);

/**
 * Renders the item rows and manages user input.
 */
void vs_mainMenu_renderItemsList(void);

/**
 * Draws `character` at the specified offset, intended for row labels.
 *
 * @return The x position immediately after the rendered character.
 */
int vs_mainMenu_renderRowLabel(
    u_int character, int x, vs_battle_menuItem_t* menuItem, u_long* before);

/**
 * Renders the tab navigation arrows, e.g. in the inventory, container,
 * or status menus.
 *
 * @param mode 0 == intended for item category navigation,
 * renders arrows only. 1 == Renders the arrows at the top
 * right of the screen, adding "L1/R1" prompts next to them.
 */
void vs_mainMenu_renderTabNavigation(int mode);

/**
 * Redraws the entire screen based on the current state.
 */
void vs_mainMenu_renderScreen(void);

/**
 * Controls whether the purple skill cost elements are rendered.
 */
extern char vs_mainMenu_displaySkillCost;

/**
 * Increments while appending actions to the command menu.
 * Values of 16+ indicate that the menu has finished rendering.
 */
extern char vs_mainMenu_actionMenuState;

/**
 * 0 for regular orange cursor, 1 for teal.
 */
extern char vs_mainMenu_cursorColor;

/**
 * Setting to 1 disables rendering the menu rows on the right.
 */
extern char vs_mainMenu_hideMenu;

/**
 * Can be polled to determine whether the background is
 * fully faded out or int.
 */
extern int vs_mainMenu_backgroundFadeStep;

/**
 * Increments while appending items to the items list.
 * Values of 16+ indicate that the list has finished rendering.
 */
extern char vs_mainMenu_itemsListRow;

/**
 * Freezes the tab arrow animation and sets their color to teal.
 */
extern char vs_mainMenu_freezeTabArrows;

extern char _rangeRiskData[8];
extern short D_80102488[4];

/**
 * memzero'd but otherwise seems to be unused.
 */
extern char D_80102490[8];

extern short D_80102498[4];
extern char _menuActionsPageOffset;

/**
 * Holds the ID of the item in the current status view.
 */
extern char vs_mainMenu_currentStatusViewItem;

extern char bss_7[2];

/**
 * For whatever reason the text for MENUC is loaded with ITEMNAME and
 * ITEMHELP and is available to all modules.
 */
extern u_short* vs_mainMenu_menu12Text;

/**
 * Stores the basic stats for display at the bottom right of the UI.
 */
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

/**
 * Holds the ID of the current cursor position on the status view.
 */
extern u_char vs_mainMenu_selectedStatusViewElement;

enum vs_mainMenu_statPage {
    statPageClass,
    statPageAffinity,
    statPageType,
    statPageNone,
};

/**
 * Which stat page is currently active.
 */
extern char vs_mainMenu_itemStatPage;

extern char bss_3[6];

/**
 * Holds the values for class / affinity / type
 */
extern short vs_mainMenu_equipmentStats[64];

/**
 * Exposes the text table imported from ITEMHELP.BIN
 */
extern u_short* vs_mainMenu_itemHelp;

/**
 * Controls which of the class / affinity / type pages are accessible.
 */
extern char vs_mainMenu_enabledStatPages;

/**
 * Flags that determine which of the UI elements shoud be rendered.
 */
extern char vs_mainMenu_equipmentSubtype;

extern char bss_4[18];
extern struct textHeader_t _textHeaders[];

/**
 * Purpose unclear, seems to be related to an unused game setting.
 */
extern char vs_mainMenu_containerEmptyBackup;
