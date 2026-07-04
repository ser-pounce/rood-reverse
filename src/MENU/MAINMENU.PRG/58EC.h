#pragma once
#include "../../SLUS_010.40/main.h"
#include "../../BATTLE/BATTLE.PRG/146C.h"
#include "../../BATTLE/BATTLE.PRG/func_8006B57C_t.h"

void func_80101F38(void);

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

#define menuRowInfo(id, x, y) ((y) << 8) | ((x) << 4) | (id)

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
