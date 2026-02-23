#include "common.h"
#include "168.h"
#include "../MAINMENU.PRG/C48.h"
#include "../MAINMENU.PRG/413C.h"
#include "../../BATTLE/BATTLE.PRG/146C.h"
#include "../../BATTLE/BATTLE.PRG/573B8.h"
#include "../../BATTLE/BATTLE.PRG/5BF94.h"
#include "../../assets/MENU/MENU12.BIN.h"
#include "vs_string.h"
#include "lbas.h"
#include "gpu.h"
#include <libetc.h>
#include <memory.h>

extern u_long* D_1F800000[];

static void _drawOk(int row, int arg1)
{
    vs_battle_renderTextRawColor("OK", vs_getXY(175, row * 16 + 32),
        ((rsin(arg1 * 8) >> 5) + 64) * 0x10101, D_1F800000[1] - 3);
}

static void _addMenuTitle(int id, int textTableOffset)
{
    vs_battle_menuItem_t* menuItem;

    int y = 18;
    if (id != 0) {
        y = 34;
    }
    menuItem = vs_battle_setMenuItem(
        id, 320, y, 140, 8, (char*)&vs_mainMenu_menu12Text[textTableOffset]);
    menuItem->state = 2;
    menuItem->targetX = 180;
    menuItem->selected = 1;
}

static u_char _workshopFlags;
static u_char _combiningItem;
static char _[2] __attribute__((unused));
static u_int _slotSelectionHistory[5];

static void _pushSelectionHistory(int index)
{
    u_int i;
    u_int max;

    max = 0;
    if (index < 5) {
        for (i = 0; i < 5; ++i) {
            if (max < _slotSelectionHistory[i]) {
                max = _slotSelectionHistory[i];
            }
        }

        _slotSelectionHistory[index] = max + 1;
        return;
    }
    vs_battle_rMemzero(_slotSelectionHistory, sizeof _slotSelectionHistory);
}

static int _popSelectionHistory(int index)
{
    int i;
    int max = 0;

    if (index < 5) {
        _slotSelectionHistory[index] = 0;
    } else {
        for (i = 0; i < 5; ++i) {
            if (_slotSelectionHistory[max] < _slotSelectionHistory[i]) {
                max = i;
            }
        }

        if (_slotSelectionHistory[max] != 0) {
            _slotSelectionHistory[max] = 0;
            return max + 1;
        }
    }
    return 0;
}

static void _initMenuItem(int textOffset, int icon)
{
    int a0;
    vs_battle_menuItem_t* menuItem = vs_battle_setMenuItem(
        32, -164, 18, 164, 8, (char*)&vs_mainMenu_menu12Text[textOffset]);
    menuItem->state = 5;
    menuItem->targetX = 16;
    menuItem->selected = 1;
    menuItem->icon = icon;

    vs_mainMenu_resetStats();
    a0 = 7;
    if (icon == 24) {
        vs_mainMenu_setRangeRisk(0, 0, 0, 1);
        a0 = 3;
    }

    vs_mainMenu_drawClassAffinityType(a0);

    a0 = 3;
    if (icon == 28) {
        a0 = 1;
    }

    vs_mainMenu_drawDpPpbars(a0);
    vs_battle_renderEquipStats(1);
}

static void _copyMenuItem(int source, int target)
{
    if (source != target) {
        vs_battle_copyAligned(&vs_battle_menuItems[target], &vs_battle_menuItems[source],
            sizeof vs_battle_menuItems[target]);
        vs_mainMenu_deactivateMenuItem(source);
    }
}

static int _confirmationPrompt(int arg0)
{
    static char cursorState = 0;
    static char state;
    static char selectedOption;

    int i;
    vs_battle_menuItem_t* menuItem;

    int action = 0;

    if (arg0 != 0) {
        func_800C8E04(1);
        selectedOption = 0;
        state = 0;
        return 0;
    }

    switch (state) {
    case 0:
    case 1:
        menuItem =
            vs_battle_setMenuItem(state + 29, 320, (state * 16) + 146, 320 - 194, 0,
                (char*)&vs_mainMenu_menu12Text
                    [vs_mainMenu_menu12Text[state + VS_MENU12_BIN_INDEX_optionYes]]);
        menuItem->state = 2;
        menuItem->targetX = 194;
        ++state;
        break;
    case 2:
        state += vs_mainmenu_ready();
        break;
    case 3:
        for (i = 0; i < 2; ++i) {
            vs_battle_getMenuItem(i + 29)->selected = i == selectedOption;
        }
        if (vs_main_buttonsPressed.all & PADRup) {
            action = 3;
        } else if (vs_main_buttonsPressed.all & PADRdown) {
            action = 2;
        } else if (vs_main_buttonsPressed.all & PADRright) {
            action = selectedOption + 1;
        } else {
            if (vs_main_buttonRepeat & (PADLup | PADLdown)) {
                vs_battle_playMenuChangeSfx();
                selectedOption = 1 - selectedOption;
            }
            cursorState = vs_battle_drawCursor(cursorState, selectedOption + 8);
        }
        break;
    }

    if (action != 0) {
        if (action == 2) {
            vs_battle_playMenuLeaveSfx();
        }
        for (i = 29; i < 31; ++i) {
            vs_mainMenu_menuItemLeaveRight(i);
        }
    }

    return action;
}

static int _confirmCombine(int arg0)
{
    static char cursorState = 0;
    static char state;
    static char selectedOption;
    static char cancelCombinePos;
    static char _[3] __attribute__((unused));

    int i;
    u_short* text;
    vs_battle_menuItem_t* menuItem;

    int action = 0;

    if (arg0 != 0) {
        func_800C8E04(1);
        cancelCombinePos = arg0;
        selectedOption = 0;
        state = 0;
        return 0;
    }

    switch (state) {
    case 0:
    case 1:
    case 2:
        text = &vs_mainMenu_menu12Text
                   [vs_mainMenu_menu12Text[state + VS_MENU12_BIN_INDEX_optionYes]];
        if (state == cancelCombinePos) {
            text = &vs_mainMenu_menu12Text[VS_MENU12_BIN_OFFSET_cancelCombine];
        }
        menuItem = vs_battle_setMenuItem(
            state + 29, 320, (state * 16) + 130, 320 - 194, 0, (char*)text);
        menuItem->state = 2;
        menuItem->targetX = 194;
        ++state;
        break;
    case 3:
        state += vs_mainmenu_ready();
        break;
    case 4:
        for (i = 0; i < 3; ++i) {
            vs_battle_getMenuItem(i + 29)->selected = i == selectedOption;
        }
        if (vs_main_buttonsPressed.all & PADRup) {
            action = 3;
        } else if (vs_main_buttonsPressed.all & PADRdown) {
            action = 2;
        } else if (vs_main_buttonsPressed.all & PADRright) {
            action = selectedOption + 1;
        } else {
            i = selectedOption;
            if (vs_main_buttonRepeat & PADLup) {
                i += 2;
            }
            if (vs_main_buttonRepeat & PADLdown) {
                ++i;
            }
            if (i >= 3) {
                i -= 3;
            }
            if (i != selectedOption) {
                vs_battle_playMenuChangeSfx();
                selectedOption = i;
            }
            cursorState = vs_battle_drawCursor(cursorState, selectedOption + 7);
        }
        break;
    }

    if (action != 0) {
        if (action == 2) {
            vs_battle_playMenuLeaveSfx();
        }
        for (i = 29; i < 32; ++i) {
            vs_mainMenu_menuItemLeaveRight(i);
        }
    }
    return action;
}

static void _disassembleWeapon(int weaponIndex)
{
    int i;
    int index;
    vs_battle_inventoryWeapon* weapon = &vs_battle_inventory.weapons[weaponIndex];

    if (weapon->blade == 0) {
        return;
    }

    for (i = 0; i < vs_battle_inventory.grips[weapon->grip - 1].gemSlots; ++i) {
        index = weapon->gems[i];
        if (index != 0) {
            vs_battle_inventory.gems[index - 1].setItemIndex = 0;
            weapon->gems[i] = 0;
        }
    }

    vs_battle_inventory.grips[weapon->grip - 1].assembledWeaponIndex = 0;
    vs_battle_inventory.blades[weapon->blade - 1].assembledWeaponIndex = 0;

    index = weapon->index;
    vs_battle_rMemzero(weapon, sizeof *weapon);
    weapon->index = index;

    vs_mainMenu_rebuildInventory(0);
}

static void _assembleWeapon(int bladeIndex, int gripIndex, int gemInfo)
{
    int i;
    int weaponIndex;

    vs_battle_inventoryWeapon* weapon = &vs_battle_inventory.weapons[_combiningItem];
    vs_battle_inventoryBlade* blade = &vs_battle_inventory.blades[bladeIndex];
    vs_battle_inventoryGrip* grip = &vs_battle_inventory.grips[gripIndex];
    int gemSlots = grip->gemSlots;

    _disassembleWeapon(_combiningItem);

    weapon->blade = bladeIndex + 1;
    weapon->grip = gripIndex + 1;

    for (i = 0; i < gemSlots; ++i) {
        weapon->gems[i] = gemInfo;
        gemInfo >>= 8;
    }

    weaponIndex = _combiningItem + 1;
    blade->assembledWeaponIndex = weaponIndex;
    grip->assembledWeaponIndex = weaponIndex;

    for (i = 0; i < gemSlots; ++i) {
        gemInfo = weapon->gems[i];
        if (gemInfo != 0) {
            vs_battle_inventory.gems[gemInfo - 1].setItemIndex = weaponIndex;
        }
    }

    memset(weapon->name, vs_char_terminator, sizeof weapon->name);
    vs_mainMenu_rebuildInventory(0);
}

static void _disassembleShield(int index)
{
    int i;
    vs_battle_inventoryShield* shield = &vs_battle_inventory.shields[index];
    int slots = shield->base.gemSlots;

    for (i = 0; i < slots; ++i) {
        int gemIndex = shield->gems[i];
        if (gemIndex != 0) {
            vs_battle_inventory.gems[gemIndex - 1].setItemIndex = 0;
            shield->gems[i] = 0;
        }
    }
}

static int _isValidGrip(vs_battle_inventoryBlade* blade, vs_battle_inventoryGrip* grip)
{
    static u_short _validGripFlags[] = { 0, 0xE, 0xF0, 0x100, 0x200 };

    if ((blade == NULL) || (grip == NULL)) {
        return 1;
    }
    return (1 << blade->category) & _validGripFlags[grip->category];
}

static int _leaveItemSlotSelection(int arg0)
{

    vs_battle_playMenuLeaveSfx();
    vs_mainMenu_clearMenuExcept(vs_mainMenu_menuItemIds_none);
    vs_mainMenu_menuItemLeaveLeft(0);

    if (arg0 != 0) {
        vs_mainMenu_drawClassAffinityType(-1);
        vs_battle_renderEquipStats(2);
        vs_mainMenu_drawDpPpbars(4);
    }

    func_800FFA88(2);

    return vs_main_buttonsPressed.all & PADRup ? -2 : -1;
}

static u_short* _itemsList;
static int _itemsListSelection;
static char _itemsListState;
static char _itemCount;
static char _itemsListWindow;
static char D_8010BCA3;

static void _populateItemsList(int count, char** text, int* rowTypes)
{
    int j;
    int i;
    u_short* temp_v1;
    vs_battle_menuItem_t* menuItem;

    _itemCount = count;
    _itemsListWindow = 0;
    _itemsListSelection = 0;
    _itemsListState = 1;
    /* Actually something along the lines of an array of
        struct _itemInfo{
            u_short title[14];
            int     rowType;
            u_short description[48];
        };
    but this doesn't match */
    _itemsList = vs_main_allocHeapR(count << 7);

    for (i = 0; i < count; ++i) {

        *((int*)(&(&_itemsList[i * 0x40])[14])) = rowTypes[i];

        temp_v1 = (u_short*)text[i * 2];

        if (temp_v1 != NULL) {
            for (j = 0; j < 13; ++j) {
                _itemsList[(i * 0x40) + j] = temp_v1[j];
            }
            _itemsList[(i * 0x40) + 13] = 0xE7E7;
        } else {
            _itemsList[i * 0x40] = 0xE7E7;
        }

        temp_v1 = (u_short*)text[i * 2 + 1];

        if (temp_v1 != NULL) {
            _itemsList[(i * 0x40) + 16] = 0xF8;
            for (j = 0; j < 46; ++j) {
                _itemsList[(i * 0x40) + j + 17] = temp_v1[j];
            }
            _itemsList[(i * 0x40) + 63] = 0xE7E7;
        } else {
            _itemsList[(i * 0x40) + 16] = 0xE7E7;
        }
    }

    j = rowTypes[0];
    menuItem = vs_battle_setMenuItem(20, 155, 18, 165, 0, (char*)_itemsList);
    menuItem->unk7 = j & 1;
    menuItem->icon = j >> 26;
    menuItem->material = (j >> 16) & 7;
    menuItem->selected = 1;
    D_8010BCA3 = (j >> 19) & 0x7F;
}

static int _getSelectedRow(void) { return _itemsList == NULL ? _itemsListSelection : -1; }

static void _navigateItemsList(int arg0)
{
    static char D_8010BB2E = 0;

    int itemInfo;
    int previousSelection;
    int v0;
    int v1;
    int i;
    int previousWindow;
    vs_battle_menuItem_t* menuItem;

    if (_itemsListState < 6) {
        if (_itemsListState == _itemCount) {
            _itemsListState = 16;
        } else {
            menuItem = vs_battle_setMenuItem(_itemsListState + 20, 320,
                (_itemsListState * 16) + 18, 151, 0,
                (char*)&_itemsList[_itemsListState * 64]);
            menuItem->state = 2;
            menuItem->targetX = 169;
            itemInfo = *(int*)&_itemsList[_itemsListState * 64 + 14];
            menuItem->unk7 = itemInfo & 1;
            menuItem->icon = (itemInfo >> 0x1A);
            v0 = (itemInfo >> 9) & 0x7F;
            if (v0 != 0) {
                menuItem->itemState = v0 - 100;
            }
            menuItem->material = (itemInfo >> 0x10) & 7;
            ++_itemsListState;
            if (_itemsListState == 6) {
                if (_itemCount >= 7) {
                    menuItem->unk5 = 2;
                }
                _itemsListState = 16;
            }
        }
    } else {
        previousWindow = _itemsListWindow;
        previousSelection = _itemsListSelection + previousWindow;
        menuItem = vs_battle_getMenuItem(_itemsListSelection + 20);
        vs_mainmenu_setMessage((char*)&_itemsList[previousSelection * 64 + 16]);

        switch (_itemsListState) {
        case 16:
            if (vs_mainmenu_ready() != 0) {
                _itemsListState = 17;
                return;
            }
            return;
        case 17:
            if (vs_main_buttonsPressed.all & PADRup) {
                if (!(arg0 & 2)) {
                    vs_battle_playMenuLeaveSfx();
                }
                vs_main_freeHeapR(_itemsList);
                _itemsList = NULL;
                _itemsListSelection = -3;
                return;
            }
            if (vs_main_buttonsPressed.all & PADRright) {
                if (menuItem->unk7 != 0) {
                    func_800C02E0();
                } else {
                    vs_main_freeHeapR(_itemsList);
                    _itemsList = NULL;
                    _itemsListSelection = previousSelection;
                    if (arg0 != 0) {
                        if (previousSelection == 0) {
                            vs_main_playSfxDefault(0x7E, 0x22);
                        } else {
                            vs_main_playSfxDefault(0x7E, 0x21);
                        }
                    }
                    break;
                }
            }
            menuItem->selected = 0;
            if (vs_main_buttonsPressed.all & PADRdown) {
                vs_battle_playMenuLeaveSfx();
                vs_main_freeHeapR(_itemsList);
                _itemsList = NULL;
                _itemsListSelection = -2;
                return;
            }
            if (vs_main_buttonRepeat & PADLup) {
                if (_itemCount < 7 || _itemsListWindow == 0) {
                    if (_itemsListSelection != 0) {
                        --_itemsListSelection;
                    }
                } else {
                    if (_itemsListSelection == 2) {
                        --_itemsListWindow;
                    } else {
                        --_itemsListSelection;
                    }
                }
            }
            if (vs_main_buttonRepeat & PADLdown) {
                if (_itemCount < 7) {
                    if (_itemsListSelection < (_itemCount - 1)) {
                        ++_itemsListSelection;
                    }
                } else {
                    if (_itemsListWindow == (_itemCount - 6)) {
                        if (_itemsListSelection < 5) {
                            ++_itemsListSelection;
                        }
                    } else if (_itemsListSelection == 4) {
                        ++_itemsListWindow;
                    } else {
                        ++_itemsListSelection;
                    }
                }
            }
            if (previousSelection != (_itemsListSelection + _itemsListWindow)) {
                vs_battle_playMenuChangeSfx();
                if (_itemsListWindow != previousWindow) {
                    char unksp18[_itemCount];
                    for (i = 0; i < _itemCount; ++i) {
                        unksp18[i] = 0;
                    }
                    itemInfo = _itemCount;

                    if (itemInfo >= 7u) {
                        itemInfo = 6;
                    }

                    for (i = 1; i < itemInfo; ++i) {
                        menuItem = vs_battle_getMenuItem(i + 20);
                        unksp18[i + previousWindow] = menuItem->unk4;
                    }

                    for (i = 1;;) {
                        int v0;
                        menuItem = vs_battle_setMenuItem(i + 20, 169, i * 16 + 18, 151, 0,
                            (char*)&_itemsList[(i + _itemsListWindow) * 64]);
                        menuItem->unk4 = *(unksp18 + (i + _itemsListWindow));
                        v0 = _itemsListWindow;
                        v0 = i + _itemsListWindow;
                        itemInfo = *(int*)&_itemsList[v0 * 64 + 14];
                        menuItem->unk7 = itemInfo & 1;
                        menuItem->icon = (itemInfo >> 0x1A);
                        v1 = (itemInfo >> 9) & 0x7F;
                        if (v1 != 0) {
                            menuItem->itemState = v1 - 0x64;
                        }
                        menuItem->material = (itemInfo >> 0x10) & 7;
                        ++i;
                        if (i == _itemCount) {
                            break;
                        }
                        if (i == 6) {
                            if ((_itemsListWindow + 6) < _itemCount) {
                                menuItem->unk5 = 2;
                            }
                            break;
                        }
                    }
                    if (_itemsListWindow != 0) {
                        vs_battle_getMenuItem(21)->unk5 = 1;
                    }
                }
                itemInfo = *(
                    int*)&_itemsList[(_itemsListSelection + _itemsListWindow) * 64 + 14];
                D_8010BCA3 = (itemInfo >> 0x13) & 0x7F;
            }
            vs_battle_getMenuItem(_itemsListSelection + 20)->selected = 1;
            i = (((_itemsListSelection * 16) + 10) << 0x10) | 155;
            if (_itemsListSelection == 0) {
                i -= 14;
            }
            D_8010BB2E = func_800FFCDC(D_8010BB2E, i);
            break;
        }
    }
}

static void _setUiStats(int arg0, int arg1)
{
    int var_v1;

    vs_mainMenu_resetStats();
    vs_mainMenu_setRangeRisk(0, 0, 0, 1);
    vs_mainMenu_equipmentSubtype = 0;

    var_v1 = arg0 != 0;
    if (arg1 != 0) {
        var_v1 += 2;
    }

    switch (var_v1) {
    case 1:
        vs_mainMenu_setUiBladeStats(arg0);
        break;
    case 2:
        vs_mainMenu_setUiGripStats(arg1);
        break;
    case 3:
        vs_mainMenu_setUiWeaponStats(_combiningItem + 1);
        break;
    }

    func_800FBB8C(7);
    vs_mainMenu_drawDpPpbars(11);
}

static void _assembleBladeMenuHeader(int arg0)
{
    vs_battle_menuItem_t* menuItem;

    int s1 = arg0 >> 4;
    int s2 = (arg0 >> 10);
    int new_var = s1 & 0x3F;
    int new_var2 = s2 & 0x3F;
    arg0 &= 0xF;
    menuItem = vs_battle_setMenuItem(32, 16, 18, 164, 8,
        (char*)(&vs_mainMenu_menu12Text
                    [vs_mainMenu_menu12Text[arg0 + VS_MENU12_BIN_INDEX_assemble]]));
    menuItem->icon = 24;
    menuItem->selected = 1;
    if (arg0 == 0) {
        _setUiStats(new_var, new_var2);
    }
}

static void _initMenuHeader(int arg0)
{
    vs_battle_menuItem_t* menuItem = vs_battle_getMenuItem(arg0);
    menuItem->state = 4;
    menuItem->targetX = 155;
    menuItem->unk1A = 18;
}

static char _availableItems[64];

static int _assembleBladeMenu(int params)
{
    static int selectedRow;
    static char state;
    static char bladeToAssemble;
    static char gripToAssemble;
    static char _[1] __attribute__((unused));

    int bladeCount;
    int i;
    void* textBuf;
    char** menuText;
    int itemId;
    vs_battle_inventoryBlade* blade = NULL;
    vs_battle_inventoryGrip* grip = NULL;

    if (params != 0) {
        bladeToAssemble = params & 0x7F;
        gripToAssemble = (params >> 8);
        _initMenuHeader(11);
        state = 0;
        return 0;
    }

    if (bladeToAssemble != 0) {
        blade = &vs_battle_inventory.blades[bladeToAssemble - 1];
    }
    if (gripToAssemble != 0) {
        grip = &vs_battle_inventory.grips[gripToAssemble - 1];
    }

    switch (state) {
    case 0:
        if (vs_mainmenu_ready() != 0) {
            textBuf = vs_main_allocHeapR(0x72C);
            menuText = textBuf + 0x6A4;
            if (blade == NULL) {
                menuText[0] = (char*)&vs_mainMenu_menu12Text[VS_MENU12_BIN_OFFSET_blades];
                menuText[1] =
                    (char*)&vs_mainMenu_menu12Text[VS_MENU12_BIN_OFFSET_bladesDesc];
                *vs_battle_rowTypeBuf = 1;
            } else {
                vs_mainMenu_setBladeUi(blade, menuText, vs_battle_rowTypeBuf, textBuf);
            }

            bladeCount = 1;
            _availableItems[0] = bladeToAssemble;

            for (i = 0; i < 16; ++i) {

                char(*p)[40] = &D_800619D8.unk0;
                itemId = (*p)[i + 8];

                if ((itemId != 0) && (itemId != bladeToAssemble)) {

                    blade = &vs_battle_inventory.blades[itemId - 1];

                    if (blade->assembledWeaponIndex == 0) {

                        vs_mainMenu_setBladeUi(blade, menuText + bladeCount * 2,
                            &vs_battle_rowTypeBuf[bladeCount], textBuf + bladeCount * 96);

                        if (_isValidGrip(blade, grip) == 0) {
                            menuText[bladeCount * 2 + 1] = (char*)&vs_mainMenu_menu12Text
                                [VS_MENU12_BIN_OFFSET_invalidBlade];
                            vs_battle_rowTypeBuf[bladeCount] |= 1;
                        }

                        _availableItems[bladeCount] = itemId;
                        ++bladeCount;
                    }
                }
            }

            _populateItemsList(bladeCount, menuText, vs_battle_rowTypeBuf);
            vs_main_freeHeapR(textBuf);
            state = 1;
        }
        break;
    case 1:
        itemId = _availableItems[_itemsListWindow + _itemsListSelection];
        if (itemId != 0) {
            vs_mainMenu_setUiBladeStats(itemId);
        } else {
            func_800FBB8C(3);
            vs_mainMenu_resetStats();
            vs_mainMenu_setRangeRisk(0, 0, 0, 1);
        }

        vs_mainMenu_printInformation(
            _itemsListSelection + _itemsListWindow, _itemsListState);
        _navigateItemsList(2);

        selectedRow = _getSelectedRow() + 1;

        if (selectedRow != 0) {
            vs_mainMenu_clearMenuExcept(vs_mainMenu_menuItemIds_none);
            if (selectedRow == -2) {
                return -2;
            }
            if (selectedRow > 0) {
                selectedRow = _availableItems[selectedRow - 1];
            }
            state = 2;
        }
        break;
    case 2:
        if (vs_mainmenu_ready() != 0) {
            return selectedRow;
        }
        break;
    }
    return 0;
}

static int _assembleGripMenu(int params)
{
    static int D_8010BC04;
    static char state;
    static char bladeToAssemble;
    static char gripToAssemble;
    static char _ __attribute__((unused));

    int gripCount;
    int i;
    void* textBuf;
    char** menuText;
    int itemId;

    vs_battle_inventoryGrip* grip = NULL;
    vs_battle_inventoryBlade* blade = NULL;

    if (params != 0) {
        gripToAssemble = params & 0x7F;
        bladeToAssemble = params >> 8;
        _initMenuHeader(0xC);
        state = 0;
        return 0;
    }
    if (bladeToAssemble != 0) {
        blade = &vs_battle_inventory.blades[bladeToAssemble - 1];
    }
    if (gripToAssemble != 0) {
        grip = &vs_battle_inventory.grips[gripToAssemble - 1];
    }

    switch (state) {
    case 0:
        if (vs_mainmenu_ready() != 0) {
            textBuf = vs_main_allocHeapR(0x72CU);
            menuText = textBuf + 0x6A4;
            if (grip == NULL) {
                menuText[0] = (char*)&vs_mainMenu_menu12Text[VS_MENU12_BIN_OFFSET_grips];
                menuText[1] =
                    (char*)&vs_mainMenu_menu12Text[VS_MENU12_BIN_OFFSET_gripsDesc];
                *vs_battle_rowTypeBuf = 1;
            } else {
                vs_mainMenu_setGripUi(grip, menuText, vs_battle_rowTypeBuf, textBuf);
            }

            gripCount = 1;
            _availableItems[0] = gripToAssemble;

            for (i = 0; i < 16; ++i) {

                itemId = D_800619D8.unk0[i + 0x18];

                if ((itemId != 0) && (itemId != gripToAssemble)) {

                    grip = &vs_battle_inventory.grips[itemId - 1];

                    if (grip->assembledWeaponIndex == 0) {

                        vs_mainMenu_setGripUi(grip, menuText + gripCount * 2,
                            &vs_battle_rowTypeBuf[gripCount], textBuf + gripCount * 0x60);

                        if (_isValidGrip(blade, grip) == 0) {
                            menuText[gripCount * 2 + 1] = (char*)&vs_mainMenu_menu12Text
                                [VS_MENU12_BIN_OFFSET_invalidGrip];
                            vs_battle_rowTypeBuf[gripCount] |= 1;
                        }

                        _availableItems[gripCount] = itemId;
                        ++gripCount;
                    }
                }
            }

            _populateItemsList(gripCount, menuText, vs_battle_rowTypeBuf);
            vs_main_freeHeapR(textBuf);
            state = 1;
        }
        break;
    case 1:
        itemId = _availableItems[_itemsListWindow + _itemsListSelection];
        vs_mainMenu_drawDpPpbars(8);

        if (itemId != 0) {
            vs_mainMenu_setUiGripStats((int)itemId);
        } else {
            func_800FBB8C(4);
            vs_mainMenu_resetStats();
        }

        vs_mainMenu_printInformation(
            _itemsListSelection + _itemsListWindow, _itemsListState);
        _navigateItemsList(2);

        D_8010BC04 = _getSelectedRow() + 1;

        if (D_8010BC04 != 0) {
            vs_mainMenu_clearMenuExcept(vs_mainMenu_menuItemIds_none);
            if (D_8010BC04 == -2) {
                return -2;
            }
            if (D_8010BC04 > 0) {
                D_8010BC04 = _availableItems[D_8010BC04 - 1];
            }
            state = 2;
        }
        break;
    case 2:
        if (vs_mainmenu_ready() != 0) {
            return D_8010BC04;
        }
        break;
    }
    return 0;
}

static int _attachGem(int params)
{
    static int D_8010BC0C;
    static char state;
    static char gemToAttach;

    int i;
    int itemId;
    int gemCount;
    void* textBuf;
    char** menuText;

    vs_battle_inventoryGem* gem = NULL;

    if (params != 0) {
        i = params & 0x7;
        gemCount = params & 0xF8;
        gemToAttach = params >> gemCount;
        _initMenuHeader(i + 10);
        state = 0;
        return 0;
    }

    if (gemToAttach != 0) {
        gem = &vs_battle_inventory.gems[gemToAttach - 1];
    }

    switch (state) {
    case 0:
        if (vs_mainmenu_ready() != 0) {
            textBuf = vs_main_allocHeapR(0x14AC);
            menuText = textBuf + 0x1324;

            if (gem == NULL) {
                menuText[0] = (char*)&vs_mainMenu_menu12Text[VS_MENU12_BIN_OFFSET_gems];
                menuText[1] =
                    (char*)&vs_mainMenu_menu12Text[VS_MENU12_BIN_OFFSET_gemsDesc];
                *vs_battle_rowTypeBuf = 1;
            } else {
                vs_mainMenu_setGemUi(gem, menuText, vs_battle_rowTypeBuf, textBuf);
            }

            gemCount = 1;
            _availableItems[0] = gemToAttach;

            for (i = 0; i < 48; ++i) {

                itemId = D_800619D8.unk0[i + 0x40];

                if ((itemId != 0) && (itemId != gemToAttach)) {

                    gem = &vs_battle_inventory.gems[itemId - 1];

                    if (gem->setItemIndex == 0) {
                        vs_mainMenu_setGemUi(gem, menuText + gemCount * 2,
                            &vs_battle_rowTypeBuf[gemCount], textBuf + gemCount * 96);
                        _availableItems[gemCount] = itemId;
                        ++gemCount;
                    }
                }
            }
            _populateItemsList(gemCount, menuText, vs_battle_rowTypeBuf);
            vs_main_freeHeapR(textBuf);
            state = 1;
        }
        break;
    case 1:
        itemId = _availableItems[_itemsListWindow + _itemsListSelection];
        vs_mainMenu_drawDpPpbars(8);
        if (itemId != 0) {
            func_800FD878(itemId);
        } else {
            func_800FBB8C(3);
            vs_mainMenu_resetStats();
        }

        vs_mainMenu_printInformation(
            _itemsListSelection + _itemsListWindow, _itemsListState);
        _navigateItemsList(2);

        D_8010BC0C = _getSelectedRow() + 1;

        if (D_8010BC0C != 0) {
            vs_mainMenu_clearMenuExcept(vs_mainMenu_menuItemIds_none);
            if (D_8010BC0C == -2) {
                return -2;
            }
            if (D_8010BC0C > 0) {
                D_8010BC0C = _availableItems[D_8010BC0C - 1];
            }
            state = 2;
        }
        break;
    case 2:
        if (vs_mainmenu_ready() != 0) {
            return D_8010BC0C;
        }
        break;
    }
    return 0;
}

static int _leaveAssembleMenu(void)
{
    _disassembleWeapon(_combiningItem);
    return _leaveItemSlotSelection(1);
}

static char D_8010BB30[] = { 0, 0xE, 0x18, 0x38, 0xC0, 0x3E, 0xFE };

static int _assembleMenu(int arg0)
{
    static int D_8010BB38[] = { 0x000A008D, 0x001A0094, 0x002A0094, 0x003A009B,
        0x004A009B, 0x005A009B, 0x006A009B };

    static char D_8010BB54 = 0;
    static char D_8010BB55 = 0;

    static char state;
    static char selectedOption;
    static char bladeToAssemble;
    static char gripToAssemble;
    static char _[2] __attribute__((unused));
    static char gemInfo[4];

    char* menuText[2];
    int sp20;
    int itemInfo;
    int itemSlot;
    int submenuResult;
    int temp_v1;
    int i;
    int gemSlots;
    vs_battle_inventoryBlade* blade;
    vs_battle_inventoryGrip* grip;
    vs_battle_menuItem_t* menuItem;

    if (arg0 != 0) {
        func_800C8E04(1);
        _pushSelectionHistory(5);
        vs_mainMenu_clearMenuExcept(vs_mainMenu_menuItemIds_none);
        _combiningItem = vs_mainMenu_getFirstItem(0, NULL);
        bladeToAssemble = 0;
        gripToAssemble = 0;
        *(int*)gemInfo = 0;
        selectedOption = 0;
        state = 0;
        return 0;
    }

    gemSlots = 0;
    itemInfo = bladeToAssemble > 0;

    if (itemInfo != 0) {
        blade = &vs_battle_inventory.blades[bladeToAssemble - 1];
    }

    itemSlot = gripToAssemble != 0;

    if (itemSlot != 0) {
        grip = &vs_battle_inventory.grips[gripToAssemble - 1];
    }

    itemInfo &= itemSlot;

    if (itemInfo != 0) {
        gemSlots = grip->gemSlots;
    }

    D_8010BB55 += 16;

    if (state != 2) {
        D_8010BB55 = 0;
    }

    switch (state) {
    case 0:
        if (vs_mainmenu_ready() != 0) {
            _initMenuItem(0x111, 0x18);
            vs_mainMenu_equipmentSubtype = 0;
            state = 1;
        }
        break;
    case 1:
        menuItem = vs_battle_setMenuItem(0xA, 0x140, 0x12, 0xA5, 0,
            (char*)&vs_mainMenu_menu12Text[VS_MENU12_BIN_OFFSET_weapon]);
        menuItem->state = 2;
        menuItem->selected = 1;
        menuItem->targetX = 155;
        menuItem = vs_battle_setMenuItem(11, 327, 34, 158, 0,
            bladeToAssemble == 0
                ? (char*)&vs_mainMenu_menu12Text[VS_MENU12_BIN_OFFSET_blades]
                : vs_mainMenu_itemNames[blade->id]);
        menuItem->state = 2;
        menuItem->targetX = 162;
        if (bladeToAssemble != 0) {
            menuItem->icon = blade->category;
            menuItem->material = blade->material;
        } else {
            menuItem->unkA = 1;
        }
        menuItem = vs_battle_setMenuItem(0xC, 0x147, 0x32, 0x9E, 0,
            gripToAssemble == 0
                ? (char*)&vs_mainMenu_menu12Text[VS_MENU12_BIN_OFFSET_grips]
                : vs_mainMenu_itemNames[vs_battle_inventory.grips[gripToAssemble - 1]
                                            .id]);
        menuItem->state = 2;
        menuItem->unkA = gripToAssemble == 0;
        menuItem->targetX = 0xA2;
        if (gripToAssemble != 0) {
            menuItem->icon = grip->category + 0xA;
        } else {
            menuItem->unkA = 1;
        }

        for (i = 0; i < gemSlots; ++i) {
            int v = gemInfo[i];
            menuItem = vs_battle_setMenuItem(i + 0xD, 0x14E, 0x42 + i * 0x10, 0x97, 0,
                v == 0 ? (char*)(vs_mainMenu_menu12Text + 0x421)
                       : vs_mainMenu_itemNames[vs_battle_inventory.gems[v - 1].id]);
            menuItem->state = 2;
            menuItem->targetX = 0xA9;
            if (v != 0) {
                menuItem->icon = 0x16;
            } else {
                menuItem->unkA = 1;
            }
        }
        state = 2;
        break;
    case 2:
        if (vs_mainmenu_ready() != 0) {
            if (!(vs_main_buttonsPressed.all & PADRup)) {

                if (itemInfo != 0) {
                    _assembleWeapon(
                        bladeToAssemble - 1, gripToAssemble - 1, *(int*)gemInfo);
                    _drawOk(gemSlots + 2, D_8010BB55);
                }

                if (vs_main_buttonsPressed.all & PADRdown) {

                    itemSlot = _popSelectionHistory(5);
                    _disassembleWeapon(_combiningItem);

                    switch (itemSlot) {
                    case 0:
                        return _leaveAssembleMenu();
                    case 1:
                        bladeToAssemble = 0;
                        *(int*)gemInfo = 0;
                        for (itemInfo = 13; itemInfo < 16; ++itemInfo) {
                            vs_mainMenu_menuItemLeaveRight(itemInfo);
                        }
                        itemInfo = VS_MENU12_BIN_OFFSET_blades;
                        break;
                    case 2:
                        gripToAssemble = 0;
                        *(int*)gemInfo = 0;
                        for (itemInfo = 13; itemInfo < 16; ++itemInfo) {
                            vs_mainMenu_menuItemLeaveRight(itemInfo);
                        }
                        itemInfo = VS_MENU12_BIN_OFFSET_grips;
                        break;
                    default:
                        gemInfo[itemSlot - 3] = 0;
                        _assembleWeapon(
                            bladeToAssemble - 1, gripToAssemble - 1, *(int*)gemInfo);
                        itemInfo = VS_MENU12_BIN_OFFSET_gems;
                        break;
                    }

                    vs_battle_playMenuLeaveSfx();
                    selectedOption = itemSlot - 1;
                    menuItem = vs_battle_setMenuItem(itemSlot + 10,
                        itemSlot < 3 ? 162 : 169, (itemSlot * 16) + 18, 151, 0,
                        (char*)&vs_mainMenu_menu12Text[itemInfo]);
                    menuItem->selected = 1;
                    menuItem->unkA = 1;
                    _setUiStats(bladeToAssemble, gripToAssemble);
                    break;
                }

                if ((vs_main_buttonsPressed.all & PADstart) && (itemInfo != 0)) {
                    vs_battle_playMenuSelectSfx();
                    vs_battle_getMenuItem(selectedOption + 11)->selected = 0;
                    selectedOption = gemSlots + 2;
                    state = 6;
                    break;
                }

                i = selectedOption;

                if (vs_main_buttonsPressed.all & PADRright) {
                    vs_battle_playMenuSelectSfx();
                    if (i == (gemSlots + 2)) {
                        state = 6;
                    } else {
                        int a0;
                        int a0_2;
                        vs_mainMenu_clearMenuExcept(vs_mainMenu_menuItemIds_none);
                        switch (i) {
                        case 0:
                            _assembleBladeMenuHeader(1);
                            a0 = gripToAssemble << 8;
                            a0 += 128;
                            _assembleBladeMenu(bladeToAssemble + a0);
                            state = 3;
                            break;
                        case 1:
                            _assembleBladeMenuHeader(2);
                            a0_2 = bladeToAssemble << 8;
                            a0_2 += 128;
                            _assembleGripMenu(gripToAssemble + a0_2);
                            state = 4;
                            break;
                        default:
                            _assembleBladeMenuHeader(3);
                            _attachGem((i + 1) | ((i - 1) * 8) | (*(int*)gemInfo << 8));
                            state = 5;
                            break;
                        }
                        break;
                    }
                }
                if (vs_main_buttonRepeat & PADLup) {
                    if (i == 0) {
                        i = gemSlots + itemInfo + 1;
                    } else {
                        --i;
                    }
                }
                if (vs_main_buttonRepeat & PADLdown) {
                    if (i == (gemSlots + itemInfo + 1)) {
                        i = 0;
                    } else {
                        ++i;
                    }
                }
                if (i != selectedOption) {
                    vs_battle_playMenuChangeSfx();
                    selectedOption = i;
                }

                for (i = 0; i < 5; ++i) {
                    vs_battle_getMenuItem(i + 11)->selected = i == selectedOption;
                }

                vs_battle_rowTypeBuf[0] = bladeToAssemble == 0;
                vs_battle_rowTypeBuf[1] = gripToAssemble == 0;

                for (i = 0; i < gemSlots; ++i) {
                    vs_battle_rowTypeBuf[i + 2] = gemInfo[i] == 0;
                }

                vs_battle_rowTypeBuf[i + 2] = 1;

                vs_mainMenu_printInformation(selectedOption, 16);

                if (selectedOption >= 2) {
                    i = VS_MENU12_BIN_INDEX_selectGem;
                    if (selectedOption == (gemSlots + 2)) {
                        i = VS_MENU12_BIN_INDEX_pressOk;
                    }
                } else {
                    i = selectedOption + VS_MENU12_BIN_INDEX_selectBladeToAssemble;
                }

                menuText[1] = (char*)&vs_mainMenu_menu12Text[vs_mainMenu_menu12Text[i]];

                switch (selectedOption) {
                case 0:
                    if (bladeToAssemble != 0) {
                        vs_mainMenu_setBladeUi(
                            &vs_battle_inventory.blades[bladeToAssemble - 1], menuText,
                            &sp20, vs_battle_stringBuf);
                    }
                    break;
                case 1:
                    if (gripToAssemble != 0) {
                        vs_mainMenu_setGripUi(
                            &vs_battle_inventory.grips[gripToAssemble - 1], menuText,
                            &sp20, vs_battle_stringBuf);
                    }
                    break;
                case 2:
                case 3:
                case 4:
                    itemSlot = gemInfo[selectedOption - 2];
                    if (itemSlot != 0) {
                        vs_mainMenu_setGemUi(&vs_battle_inventory.gems[itemSlot - 1],
                            menuText, &sp20, vs_battle_stringBuf);
                    }
                    break;
                }

                vs_mainmenu_setMessage(menuText[1]);

                i = D_8010BB38[selectedOption + 1];

                if (selectedOption == (gemSlots + 2)) {
                    i += 0xFFFC0000;
                }

                D_8010BB54 = func_800FFCDC(D_8010BB54, i);

            } else {
                return _leaveAssembleMenu();
            }
        } else {
            D_8010BB55 = 0;
        }
        break;
    case 3:
        submenuResult = _assembleBladeMenu(0);
        if (submenuResult == 0) {
            break;
        }
        if (submenuResult != -2) {
            if (submenuResult > 0) {

                *(int*)gemInfo = 0;

                for (itemInfo = 13; itemInfo < 16; ++itemInfo) {
                    vs_mainMenu_menuItemLeaveRight(itemInfo);
                }

                if (submenuResult == bladeToAssemble) {
                    bladeToAssemble = 0;
                    _popSelectionHistory(0);
                    _disassembleWeapon(_combiningItem);
                } else {
                    bladeToAssemble = submenuResult;
                    _pushSelectionHistory(0);
                    selectedOption = 1;
                    if (gripToAssemble != 0) {
                        _assembleWeapon(
                            bladeToAssemble - 1, gripToAssemble - 1, *(int*)gemInfo);
                    }
                }
            }
            _assembleBladeMenuHeader(bladeToAssemble * 0x10 | (gripToAssemble << 0xA));
            state = 1;
            break;
        }
        return _leaveAssembleMenu();
    case 4:
        submenuResult = _assembleGripMenu(0);
        if (submenuResult == 0) {
            break;
        }
        if (submenuResult != -2) {
            if (submenuResult > 0) {
                *(int*)gemInfo = 0;
                for (itemInfo = 13; itemInfo < 16; ++itemInfo) {
                    vs_mainMenu_menuItemLeaveRight(itemInfo);
                }
                if (submenuResult == gripToAssemble) {
                    gripToAssemble = 0;
                    _popSelectionHistory(1);
                    _disassembleWeapon(_combiningItem);
                } else {
                    gripToAssemble = submenuResult;
                    _pushSelectionHistory(1);
                    selectedOption = ((bladeToAssemble != 0) * 2);
                    if (bladeToAssemble != 0) {
                        _assembleWeapon(
                            bladeToAssemble - 1, gripToAssemble - 1, *(int*)gemInfo);
                    }
                }
            }
            _assembleBladeMenuHeader(bladeToAssemble * 0x10 | (gripToAssemble << 0xA));
            state = 1;
            break;
        }
        return _leaveAssembleMenu();
    case 5:
        submenuResult = _attachGem(0);
        if (submenuResult == 0) {
            break;
        }
        if (submenuResult != -2) {
            if (submenuResult > 0) {
                if (submenuResult == gemInfo[selectedOption - 2]) {
                    gemInfo[selectedOption - 2] = 0;
                    _popSelectionHistory(selectedOption);
                } else {
                    gemInfo[selectedOption - 2] = submenuResult;
                    _pushSelectionHistory(selectedOption);
                    ++selectedOption;
                }
            }
            _assembleWeapon(bladeToAssemble - 1, gripToAssemble - 1, *(int*)gemInfo);
            _assembleBladeMenuHeader(bladeToAssemble * 0x10 | (gripToAssemble << 0xA));
            state = 1;
            break;
        }
        return _leaveAssembleMenu();
    case 6:
        vs_battle_renderEquipStats(2);
        _confirmCombine(3);
        vs_mainmenu_setMessage(
            (char*)&vs_mainMenu_menu12Text[VS_MENU12_BIN_OFFSET_attachmentConfirm]);
        state = 7;
        break;
    case 7:
        itemSlot = _confirmCombine(0);

        if (itemSlot == 0) {
            break;
        }

        switch (itemSlot) {
        case 1:
            vs_battle_playMenuSelectSfx();
            vs_mainMenu_clearMenuExcept(10);
            vs_mainMenu_drawClassAffinityType(-1);
            vs_mainMenu_drawDpPpbars(4);
            state = 8;
            break;
        case 2:
            vs_battle_renderEquipStats(1);
            state = itemSlot;
            break;
        case 3:
            return _leaveAssembleMenu();
        }
        break;
    case 8:
        if (vs_mainmenu_ready() != 0) {
            D_801022D5 = 0;
            vs_battle_stringBuf[0] = 0;
            vs_battle_stringBuf[1] = _combiningItem;
            _assembleBladeMenuHeader(4);
            func_800FFA88(2);
            return 1;
        }
        break;
    }
    return 0;
}

static void _addGemSelector(int arg0 __attribute__((unused)), int arg1)
{
    vs_battle_menuItem_t* temp_v0 =
        vs_battle_setMenuItem(arg1 + 10, 320, (arg1 * 16) + 18, 320 - 169, 0,
            (char*)&vs_mainMenu_menu12Text[VS_MENU12_BIN_OFFSET_gems]);
    temp_v0->state = 2;
    temp_v0->targetX = 169;
    temp_v0->unkA = 1;
}

static int _attachGems(char* gems, int isShield)
{
    int i;
    int gem;
    u_char* attachedGems;
    vs_battle_inventoryShield* shield;
    vs_battle_inventoryWeapon* weapon;

    weapon = &vs_battle_inventory.weapons[_combiningItem];
    shield = &vs_battle_inventory.shields[_combiningItem];

    if (isShield != 0) {
        attachedGems = shield->gems;
    } else {
        attachedGems = weapon->gems;
    }

    for (i = 0; i < 3; ++i) {
        gem = attachedGems[i];
        if (gem != 0) {
            vs_battle_inventory.gems[gem - 1].setItemIndex = 0;
            attachedGems[i] = 0;
        }
    }

    for (i = 0; i < 3; ++i) {
        gem = gems[i];
        if (gem != 0) {
            vs_battle_inventory.gems[gem - 1].setItemIndex =
                _combiningItem + ((isShield << 7) + 1);
            attachedGems[i] = gem;
        }
    }
    if (isShield != 0) {
        if (shield->isEquipped != 0) {
            vs_battle_equipShield(shield);
        }
    } else if (weapon->isEquipped != 0) {
        vs_battle_equipWeapon(weapon);
    }
    return _leaveItemSlotSelection(1);
}

static int _attachGemsMenu(int arg0)
{
    static char D_8010BB56 = 0;
    static char D_8010BB57 = 0;

    static int selectedRow;
    static char state;
    static char D_8010BC21;
    static u_char D_8010BC22;
    static char gemSlots;
    static char isShield;
    static char _0[3] __attribute__((unused));
    static char D_8010BC28[4];
    static char targetGems[4];
    static u_char* attachedGems;

    char textBuf[0x300];
    char* menuText[16];
    int rowTypes[8];
    int var_s2;
    int j;
    int i;
    int var_a2;
    int itemInfo;
    vs_battle_inventoryShield* shield;
    vs_battle_inventoryWeapon* weapon;
    vs_battle_menuItem_t* menuItem;

    if (arg0 != 0) {
        func_800C8E04(1);
        isShield = arg0 - 1;
        state = 0;
        return 0;
    }

    switch (state) {
    case 0:
        if (vs_mainmenu_ready() != 0) {
            _addMenuTitle(0, vs_mainMenu_menu12Text[isShield + 32]);
            state = 1;
        }
        break;
    case 1:
        if (vs_mainmenu_ready() == 0) {
            break;
        }

        i = 0;

        for (j = 0; j < 8; ++j) {
            char* new_var = textBuf;
            itemInfo = 0;

            if (isShield != 0) {
                var_s2 = D_800619D8.unk28[j];
                if (var_s2 != 0) {
                    shield = &vs_battle_inventory.shields[var_s2 - 1];
                    vs_mainMenu_initUiShield(
                        shield, &menuText[i * 2], &rowTypes[i], textBuf + i * 96);
                    itemInfo = shield->base.gemSlots;
                }
            } else {
                var_s2 = D_800619D8.unk0[j];
                if (var_s2 != 0) {
                    weapon = &vs_battle_inventory.weapons[var_s2 - 1];
                    vs_mainMenu_initUiWeapon(
                        weapon, &menuText[i * 2], &rowTypes[i], textBuf + i * 96);
                    itemInfo = vs_battle_inventory.grips[weapon->grip - 1].gemSlots;
                }
            }

            if (var_s2 != 0) {
                vs_battle_stringContext.integers[0] = itemInfo;
                vs_battle_printf(textBuf + i * 96,
                    (char*)&vs_mainMenu_menu12Text[vs_mainMenu_menu12Text
                            [isShield * 2
                                + (itemInfo == 0 ? VS_MENU12_BIN_INDEX_weaponNoGemSlots
                                                 : VS_MENU12_BIN_INDEX_weaponGemSlots)]]);
                menuText[i * 2 + 1] = new_var + i * 96;
                rowTypes[i] |= itemInfo == 0;
                ++i;
                _availableItems[i] = var_s2;
            }
        }

        vs_mainmenu_setMenuRows(i, (isShield + 55) | 0x19100, menuText, rowTypes);
        state = 2;
        break;
    case 2:
        selectedRow = vs_mainmenu_getSelectedRow() + 1;
        if (selectedRow != 0) {
            vs_mainMenu_clearMenuExcept(vs_mainMenu_menuItemIds_none);
            if (selectedRow < 0) {
                return selectedRow;
            }
            menuItem = vs_battle_getMenuItem(0);
            menuItem->state = 2;
            menuItem->w = 164;
            menuItem->targetX = 16;
            menuItem = vs_battle_getMenuItem(selectedRow + 9);
            menuItem->state = 4;
            menuItem->targetX = 155;
            menuItem->unk1A = 18;
            state = 3;
        }
        break;
    case 3:
        if (vs_mainmenu_ready() != 0) {
            vs_battle_menuItem_t* menuItem = vs_battle_getMenuItem(0);

            var_a2 = 24;
            if (isShield != 0) {
                var_a2 = 27;
            }
            menuItem->icon = var_a2;

            _copyMenuItem(0, 32);
            _copyMenuItem(selectedRow + 9, 10);

            var_s2 = _availableItems[selectedRow];
            _combiningItem = var_s2 - 1;

            if (isShield != 0) {
                func_800FD5A0(var_s2);
                shield = &vs_battle_inventory.shields[var_s2 - 1];
                gemSlots = shield->base.gemSlots;
                attachedGems = shield->gems;
            } else {
                vs_mainMenu_setUiWeaponStats(var_s2);
                weapon = &vs_battle_inventory.weapons[var_s2 - 1];
                gemSlots = vs_battle_inventory.grips[weapon->grip - 1].gemSlots;
                attachedGems = weapon->gems;
            }
            vs_mainMenu_drawClassAffinityType(7);
            vs_mainMenu_drawDpPpbars(3);
            vs_battle_renderEquipStats(1);

            *(int*)D_8010BC28 = 0;
            for (itemInfo = 0; itemInfo < gemSlots; ++itemInfo) {
                D_8010BC28[itemInfo] = attachedGems[itemInfo];
            }
            D_8010BC21 = 0;
            D_8010BC22 = 0;
            state = 4;
            *(int*)targetGems = *(int*)D_8010BC28;
        }
        break;
    case 4:
        if (D_8010BC21 < 5) {
            ++D_8010BC21;
            if (isShield != 0) {
                menuItem = func_800FC704(D_8010BC21, _combiningItem + 1, 1);
            } else {
                menuItem = func_800FC510(D_8010BC21, _combiningItem + 1, 1);
            }
            if (menuItem != NULL) {
                if (menuItem->unk7 != 0) {
                    _addGemSelector(D_8010BC21 - ((1 - isShield) * 2), D_8010BC21);
                    break;
                }
            }
        } else {
            state = 5;
        }
        break;
    case 5:
        if (vs_mainmenu_ready() != 0) {
            if (!(vs_main_buttonsPressed.all & PADRup)) {
                D_8010BB57 += 16;
                _drawOk(gemSlots + ((1 - isShield) * 2), D_8010BB57);
                if (vs_main_buttonsPressed.all & PADRdown) {
                    _attachGems(targetGems, isShield);
                    state = 0;
                } else if (vs_main_buttonsPressed.all & PADstart) {
                    int new_var2 = 11;
                    vs_battle_playMenuSelectSfx();
                    vs_battle_getMenuItem(((1 - isShield) * 2) + (D_8010BC22 + new_var2))
                        ->selected = 0;
                    state = 7;
                    D_8010BC22 = gemSlots;
                } else {
                    itemInfo = D_8010BC22;
                    if (vs_main_buttonsPressed.all & PADRright) {
                        vs_battle_playMenuSelectSfx();
                        if (itemInfo == gemSlots) {
                            state = 7;
                        } else {
                            int new_var3;
                            vs_mainMenu_clearMenuExcept(vs_mainMenu_menuItemIds_none);
                            new_var3 = ((1 - isShield) * 2) + 1;
                            _attachGem((itemInfo + new_var3) | ((itemInfo + 1) * 8)
                                       | (*(int*)D_8010BC28 << 8));
                            state = 6;
                        }
                    } else {
                        if (vs_main_buttonRepeat & 0x1000) {
                            if (itemInfo == 0) {
                                itemInfo = gemSlots;
                            } else {
                                --itemInfo;
                            }
                        }
                        if (vs_main_buttonRepeat & 0x4000) {
                            if (itemInfo == gemSlots) {
                                itemInfo = 0;
                            } else {
                                ++itemInfo;
                            }
                        }
                        if (itemInfo != D_8010BC22) {
                            vs_battle_playMenuChangeSfx();
                            D_8010BC22 = itemInfo;
                        }

                        for (i = 0; i < gemSlots; ++i) {
                            vs_battle_getMenuItem(11 + ((1 - isShield) * 2) + i)
                                ->selected = i == D_8010BC22;
                            vs_battle_rowTypeBuf[i] = D_8010BC28[i] == 0;
                        }

                        vs_battle_rowTypeBuf[i] = 1;
                        vs_mainMenu_printInformation(itemInfo, 16);
                        menuText[1] = (char*)&vs_mainMenu_menu12Text
                            [VS_MENU12_BIN_OFFSET_selectGem];
                        if (itemInfo == gemSlots) {
                            menuText[1] = (char*)&vs_mainMenu_menu12Text
                                [VS_MENU12_BIN_OFFSET_pressOk];
                        } else {
                            i = *(itemInfo + D_8010BC28);
                            if (i != 0) {
                                vs_mainMenu_setGemUi(&vs_battle_inventory.gems[i - 1],
                                    menuText, rowTypes, &textBuf);
                            }
                        }
                        vs_mainmenu_setMessage(menuText[1]);
                        i = 26;
                        i = ((((1 - isShield) << 5) + ((itemInfo * 16) + i)) << 0x10)
                          | 155;
                        if (itemInfo == gemSlots) {
                            i += 0xFFFC0000;
                        }
                        D_8010BB56 = func_800FFCDC(D_8010BB56, i);
                    }
                }
            } else {
                return _attachGems(targetGems, isShield);
            }
        } else {
            D_8010BB57 = 0;
        }
        break;
    case 6:
        itemInfo = _attachGem(0);
        if (itemInfo != 0) {
            if (itemInfo != -2) {
                var_s2 = _combiningItem + 1;
                weapon = &vs_battle_inventory.weapons[var_s2 - 1];
                shield = &vs_battle_inventory.shields[var_s2 - 1];
                attachedGems = isShield != 0 ? shield->gems : weapon->gems;
                if (itemInfo > 0) {
                    i = D_8010BC28[D_8010BC22];
                    if (itemInfo == i) {
                        vs_battle_inventory.gems[itemInfo - 1].setItemIndex = 0;
                        attachedGems[D_8010BC22] = 0;
                        D_8010BC28[D_8010BC22] = 0;
                    } else {
                        if (i != 0) {
                            vs_battle_inventory.gems[i - 1].setItemIndex = 0;
                        }
                        vs_battle_inventory.gems[itemInfo - 1].setItemIndex =
                            var_s2 + (isShield << 7);
                        attachedGems[D_8010BC22] = itemInfo;
                        D_8010BC28[D_8010BC22] = itemInfo;
                        ++D_8010BC22;
                    }
                    if (isShield != 0) {
                        if (shield->isEquipped != 0) {
                            vs_battle_equipShield(shield);
                        }
                    } else if (weapon->isEquipped != 0) {
                        vs_battle_equipWeapon(weapon);
                    }
                }
                func_800FBB8C(7);
                vs_mainMenu_drawDpPpbars(11);
                if (isShield != 0) {
                    func_800FD5A0(var_s2);
                    vs_mainMenu_initUiShield(shield, menuText, rowTypes, textBuf);
                } else {
                    vs_mainMenu_setUiWeaponStats(var_s2);
                    vs_mainMenu_initUiWeapon(weapon, menuText, rowTypes, textBuf);
                }
                menuItem = vs_battle_setMenuItem(10, 320, 18, 137, 0, menuText[0]);
                menuItem->state = 2;
                menuItem->targetX = 155;
                menuItem->selected = 1;
                i = rowTypes[0];
                menuItem->icon = i >> 0x1A;
                menuItem->material = (i >> 0x10) & 7;
                D_8010BC21 = 0;
                state = 4;
            } else {
                return _attachGems(targetGems, isShield);
            }
        }
        break;
    case 7:
        vs_battle_renderEquipStats(2);
        _confirmCombine(3);
        vs_mainmenu_setMessage(
            (char*)&vs_mainMenu_menu12Text[VS_MENU12_BIN_OFFSET_attachmentConfirm]);
        state = 8;
        break;
    case 8:
        itemInfo = _confirmCombine(0);
        if (itemInfo == 0) {
            break;
        }
        switch (itemInfo) {
        case 1:
            vs_main_playSfxDefault(0x7E, 0x18);
            func_800FFBC8();
            vs_mainMenu_drawClassAffinityType(-1);
            vs_mainMenu_drawDpPpbars(4);
            vs_mainMenu_clearMenuExcept(vs_mainMenu_menuItemIds_none);
            vs_mainMenu_menuItemLeaveLeft(0);
            return 1;
        case 2:
            vs_battle_playMenuLeaveSfx();
            vs_battle_renderEquipStats(1);
            state = 5;
            break;
        case 3:
            return _attachGems(targetGems, isShield);
            break;
        }
        break;
    }
    return 0;
}

static int _attachGemsTopMenu(int arg0)
{
    static char state;
    static char noForceCursorMemory;
    static char _[2] __attribute__((unused));

    char* text[4];
    int rowTypes[4];
    int i;

    if (arg0 != 0) {
        noForceCursorMemory = 1;
        func_800FA92C(1, 1);
        state = 0;
        return 0;
    }

    switch (state) {
    case 0:
        if (vs_mainmenu_ready() == 0) {
            break;
        }
        for (i = 0; i < 4; ++i) {
            text[i] = (char*)&vs_mainMenu_menu12Text
                [vs_mainMenu_menu12Text[VS_MENU12_BIN_INDEX_weapons + i]];
            rowTypes[i] = 0;
        }
        if (vs_mainMenu_getItemCount(0, NULL) == 0) {
            rowTypes[0] = 1;
            text[1] = (char*)&vs_mainMenu_menu12Text[VS_MENU12_BIN_OFFSET_noItems];
        }
        if (vs_mainMenu_getItemCount(3, NULL) == 0) {
            rowTypes[1] = 1;
            text[3] = (char*)&vs_mainMenu_menu12Text[VS_MENU12_BIN_OFFSET_noItems];
        }
        i = vs_main_settings.cursorMemory;
        if (noForceCursorMemory == 0) {
            vs_main_settings.cursorMemory = 1;
        }
        noForceCursorMemory = 0;
        vs_mainmenu_setMenuRows(2, 566, text, rowTypes);
        vs_main_settings.cursorMemory = i;
        state = 1;
        break;
    case 1:
        i = vs_mainmenu_getSelectedRow() + 1;
        if (i != 0) {
            if (i < 0) {
                vs_mainMenu_clearMenuExcept(0);
                return i;
            }
            vs_mainMenu_clearMenuExcept(vs_mainMenu_menuItemIds_none);
            _attachGemsMenu(i);
            state = 2;
        }
        break;
    case 2:
        i = _attachGemsMenu(0);
        if (i != 0) {
            if (i != -1) {
                return i;
            }
            state = 3;
        }
        break;
    case 3:
        if (vs_mainmenu_ready() != 0) {
            func_800FFBC8();
            _addMenuTitle(0, VS_MENU12_BIN_OFFSET_setup);
            _addMenuTitle(11, VS_MENU12_BIN_OFFSET_attachGems);
            state = 0;
        }
        break;
    }
    return 0;
}

int func_8010BA58(int);

static int _disassembleMenu(int arg0)
{
    static int selectedRow;
    static char state;
    static char D_8010BC3D;
    static char isShield;

    char* menuText[16];
    int rowTypes[8];
    int confirmation;
    int count;
    int i;
    int j;
    int selectedItem;
    int itemInfo;
    vs_battle_inventoryShield* shield;
    vs_battle_menuItem_t* menuItem;

    if (arg0 != 0) {
        func_800C8E04(1);
        isShield = arg0 - 1;
        state = 0;
        return 0;
    }

    switch (state) {
    case 0:
        if (vs_mainmenu_ready() != 0) {
            _addMenuTitle(0,
                vs_mainMenu_menu12Text[isShield + VS_MENU12_BIN_INDEX_disassembleWeapon]);
            state = 1;
        }
        break;
    case 1:
        if (vs_mainmenu_ready() != 0) {
            count = 0;
            for (i = 0; i < 8; i++) {
                if (isShield != 0) {
                    selectedItem = D_800619D8.unk28[i];
                    if (selectedItem != 0) {
                        shield = &vs_battle_inventory.shields[selectedItem - 1];
                        vs_mainMenu_initUiShield(shield, &menuText[count * 2],
                            &rowTypes[count], vs_battle_stringBuf);
                        menuText[count * 2 + 1] = (char*)&vs_mainMenu_menu12Text
                            [VS_MENU12_BIN_OFFSET_chooseShieldDisassemble];
                        for (j = 0; j < shield->base.gemSlots; ++j) {
                            if (shield->gems[j] != 0) {
                                break;
                            }
                        }
                        if (j == shield->base.gemSlots) {
                            menuText[count * 2 + 1] = (char*)&vs_mainMenu_menu12Text
                                [VS_MENU12_BIN_OFFSET_noGems];
                            rowTypes[count] |= 1;
                        }
                        ++count;
                        _availableItems[count] = selectedItem;
                    }
                } else {
                    selectedItem = D_800619D8.unk0[i];
                    if (selectedItem != 0) {
                        vs_mainMenu_initUiWeapon(
                            &vs_battle_inventory.weapons[selectedItem - 1],
                            &menuText[count * 2], &rowTypes[count], vs_battle_stringBuf);
                        menuText[count * 2 + 1] = (char*)&vs_mainMenu_menu12Text
                            [VS_MENU12_BIN_OFFSET_chooseWeaponDisassemble];
                        ++count;
                        _availableItems[count] = selectedItem;
                    }
                }
            }
            vs_mainmenu_setMenuRows(count, (isShield + 58) | 0x19100, menuText, rowTypes);
            state = 2;
        }
        break;
    case 2:
        selectedRow = vs_mainmenu_getSelectedRow() + 1;
        if (selectedRow == 0) {
            break;
        }
        vs_mainMenu_clearMenuExcept(vs_mainMenu_menuItemIds_none);
        if (selectedRow < 0) {
            return selectedRow;
        }
        menuItem = vs_battle_getMenuItem(0);
        menuItem->state = 2;
        menuItem->w = 164;
        menuItem->targetX = 16;
        menuItem = vs_battle_getMenuItem(selectedRow + 9);
        menuItem->state = 4;
        menuItem->targetX = 155;
        menuItem->unk1A = 18;
        state = 3;
        break;
    case 3:
        if (vs_mainmenu_ready() == 0) {
            break;
        }
        vs_battle_getMenuItem(0)->icon = isShield != 0 ? 27 : 24;
        _copyMenuItem(0, 0x20);
        _copyMenuItem(selectedRow + 9, 10);
        selectedItem = _availableItems[selectedRow];
        _combiningItem = selectedItem - 1;
        if (isShield != 0) {
            func_800FD5A0(selectedItem);
        } else {
            vs_mainMenu_setUiWeaponStats(selectedItem);
        }
        vs_mainMenu_drawClassAffinityType(7);
        vs_mainMenu_drawDpPpbars(3);
        D_8010BC3D = 0;
        state = 4;
        break;
    case 4:
        if (D_8010BC3D < 5) {
            ++D_8010BC3D;
            if (isShield != 0) {
                func_800FC704(D_8010BC3D, _combiningItem + 1, 1);
            } else {
                func_800FC510(D_8010BC3D, _combiningItem + 1, 1);
            }
            break;
        }
        if (isShield != 0) {
            itemInfo = vs_battle_inventory.shields[_combiningItem].isEquipped;
        } else {
            itemInfo = vs_battle_inventory.weapons[_combiningItem].isEquipped;
        }
        _confirmationPrompt(1);
        vs_mainmenu_setMessage((char*)&vs_mainMenu_menu12Text[vs_mainMenu_menu12Text
                [isShield * 4 + VS_MENU12_BIN_INDEX_disassembleWeaponConfirm
                    + (itemInfo != 0)]]);
        state = itemInfo + 5;
        break;
    case 5:
    case 6:
        confirmation = _confirmationPrompt(0);
        if (confirmation == 0) {
            break;
        }
        vs_mainMenu_drawClassAffinityType(-1);
        vs_mainMenu_drawDpPpbars(4);
        vs_mainMenu_clearMenuExcept(vs_mainMenu_menuItemIds_none);
        vs_mainMenu_menuItemLeaveLeft(0);

        switch (confirmation) {
        case 1:
            vs_main_playSfxDefault(0x7E, 0x19);
            if (isShield != 0) {
                _disassembleShield(_combiningItem);
            } else {
                _disassembleWeapon(_combiningItem);
            }
            if (state == 5) {
                return -1;
            }
            if (isShield != 0) {
                vs_mainMenu_unequipShield();
            } else {
                vs_mainMenu_unequipAllWeapons();
            }
            state = 7;
            break;
        case 2:
            state = 0;
            break;
        case 3:
            return _leaveItemSlotSelection(0);
        }
        break;
    case 7:
        if (func_8010BA58(isShield) == 0) {
            return -1;
        }
        break;
    }
    return 0;
}

static int _disassembleTopMenu(int arg0)
{
    static char state;
    static char _0 __attribute__((unused));
    static char forceNoCursorMemory;
    static char _1[2] __attribute__((unused));

    char* text[4];
    int rowTypes[2];
    int selection;
    int itemCount;
    int i;

    if (arg0 != 0) {
        forceNoCursorMemory = 1;
        func_800FA92C(2, 1);
        state = 0;
        return 0;
    }

    switch (state) {
    case 0:
        if (vs_mainmenu_ready() != 0) {
            for (i = 0; i < 2; ++i) {
                text[i * 2] = (char*)&vs_mainMenu_menu12Text
                    [vs_mainMenu_menu12Text[i * 2 + VS_MENU12_BIN_INDEX_weapons]];
                text[i * 2 + 1] = (char*)&vs_mainMenu_menu12Text[vs_mainMenu_menu12Text
                        [i + VS_MENU12_BIN_INDEX_disassembleWeaponDesc]];

                itemCount = vs_mainMenu_getItemCount((i != 0) * 3, NULL);
                rowTypes[i] = (itemCount << 9) + 0x400000;

                if (itemCount == 0) {
                    text[i * 2 + 1] =
                        (char*)&vs_mainMenu_menu12Text[VS_MENU12_BIN_OFFSET_noItems];
                    rowTypes[i] |= 1;
                }
            }
            selection = vs_main_settings.cursorMemory;
            if (forceNoCursorMemory == 0) {
                vs_main_settings.cursorMemory = 1;
            }
            forceNoCursorMemory = 0;
            vs_mainmenu_setMenuRows(2, 0x239, text, rowTypes);
            vs_main_settings.cursorMemory = selection;
            state = 1;
        }
        break;
    case 1:
        selection = vs_mainmenu_getSelectedRow() + 1;
        if (selection == 0) {
            break;
        }
        if (selection < 0) {
            vs_mainMenu_clearMenuExcept(0);
            return selection;
        }
        vs_mainMenu_clearMenuExcept(vs_mainMenu_menuItemIds_none);
        _disassembleMenu(selection);
        state = 2;
        break;
    case 2:
        selection = _disassembleMenu(0);
        if (selection == 0) {
            break;
        }
        if (selection != -1) {
            return selection;
        }
        state = 3;
        break;
    case 3:
        if (vs_mainmenu_ready() != 0) {
            func_800FFBC8();
            _addMenuTitle(0, VS_MENU12_BIN_OFFSET_setup);
            _addMenuTitle(12, VS_MENU12_BIN_OFFSET_disassemble);
            state = 0;
        }
        break;
    }
    return 0;
}

static int _renameWeaponMenu(int arg0)
{
    static int selectedRow;
    static char state;
    static char D_8010BC49;
    static char _[2] __attribute__((unused));

    char* menuText[16];
    int rowTypes[8];
    int i;
    int itemId;
    vs_battle_menuItem_t* menuItem;

    if (arg0 != 0) {
        func_800C8E04(1);
        vs_mainmenu_setMessage(
            (char*)&vs_mainMenu_menu12Text[VS_MENU12_BIN_OFFSET_chooseWeaponRename]);
        vs_mainMenu_clearMenuExcept(vs_mainMenu_menuItemIds_none);
        state = 0;
        return 0;
    }

    switch (state) {
    case 0:
        if (vs_mainmenu_ready() != 0) {
            _addMenuTitle(0, VS_MENU12_BIN_OFFSET_rename);
            state = 1;
        }
        break;
    case 1:
        if (vs_mainmenu_ready() != 0) {
            int count = 0;
            for (i = 0; i < 8; ++i) {
                itemId = D_800619D8.unk0[i];
                if (itemId != 0) {
                    vs_mainMenu_initUiWeapon(&vs_battle_inventory.weapons[itemId - 1],
                        &menuText[count * 2], &rowTypes[count], vs_battle_stringBuf);
                    menuText[(count * 2) + 1] = (char*)&vs_mainMenu_menu12Text
                        [VS_MENU12_BIN_OFFSET_chooseWeaponRename];
                    ++count;
                    _availableItems[count] = itemId;
                }
            }
            vs_mainmenu_setMenuRows(count, 0x1913C, menuText, rowTypes);
            state = 2;
        }
        break;
    case 2:
        selectedRow = vs_mainmenu_getSelectedRow() + 1;
        if (selectedRow == 0) {
            break;
        }

        vs_mainMenu_clearMenuExcept(vs_mainMenu_menuItemIds_none);

        if (selectedRow < 0) {
            return selectedRow;
        }
        menuItem = vs_battle_getMenuItem(0);
        menuItem->state = 2;
        menuItem->w = 164;
        menuItem->targetX = 16;
        menuItem = vs_battle_getMenuItem(selectedRow + 9);
        menuItem->state = 4;
        menuItem->targetX = 155;
        menuItem->unk1A = 18;
        state = 3;
        break;
    case 3:
        if (vs_mainmenu_ready() != 0) {
            vs_battle_getMenuItem(0)->icon = 24;
            _copyMenuItem(0, 32);
            _copyMenuItem(selectedRow + 9, 10);
            itemId = _availableItems[selectedRow];
            _combiningItem = itemId - 1;
            vs_mainMenu_setUiWeaponStats(itemId);
            vs_mainMenu_drawClassAffinityType(7);
            vs_mainMenu_drawDpPpbars(3);
            D_8010BC49 = 0;
            state = 4;
        }
        break;
    case 4:
        if (D_8010BC49 < 5) {
            ++D_8010BC49;
            func_800FC510(D_8010BC49, _combiningItem + 1, 1);
            return 0;
        }
        _confirmationPrompt(1);
        vs_mainmenu_setMessage(
            (char*)&vs_mainMenu_menu12Text[VS_MENU12_BIN_OFFSET_renamePrompt]);
        state = 5;
        break;
    case 5:
        i = _confirmationPrompt(0);
        if (i != 0) {
            vs_mainMenu_drawClassAffinityType(-1);
            vs_mainMenu_drawDpPpbars(4);
            switch (i) {
            case 1:
                vs_battle_playMenuSelectSfx();
                vs_mainMenu_clearMenuExcept(10);
                vs_battle_getMenuItem(10)->unk2 = i;
                state = 6;
                break;
            case 2:
                vs_mainMenu_clearMenuExcept(vs_mainMenu_menuItemIds_none);
                vs_mainMenu_menuItemLeaveLeft(0);
                state = 0;
                break;
            case 3:
                return _leaveItemSlotSelection(0);
            }
        }
        break;
    case 6:
        if (vs_mainmenu_ready() != 0) {
            D_801022D5 = 0;
            vs_battle_stringBuf[0] = 1;
            vs_battle_stringBuf[1] = _combiningItem;
            func_800FFA88(2);
            return 1;
        }
        break;
    }
    return 0;
}

static int _repairMenu(int arg0)
{
    static int returnedFromPrompt;
    static char state;
    static char _[3] __attribute__((unused));

    int ppCost;
    int i;
    int new_var;

    if (arg0 != 0) {
        func_800FA92C(4, 1);
        state = 0;
        return 0;
    }

    switch (state) {
    case 0:
        if (vs_mainmenu_ready() != 0) {
            _confirmationPrompt(1);
            vs_mainmenu_setMessage(
                (char*)&vs_mainMenu_menu12Text[VS_MENU12_BIN_OFFSET_repairConfirm]);
            state = 1;
        }
        break;
    case 1:
        i = _confirmationPrompt(0);
        if (i == 0) {
            break;
        }
        returnedFromPrompt = -1;
        if (i == 1) {
            vs_main_playSfxDefault(0x7E, 0xD);
            state = 2;
        } else {
            if (i == 3) {
                vs_battle_playMenuLeaveSfx();
                return -2;
            }
            func_800FFBC8();
            vs_mainMenu_menuItemLeaveRight(14);
            state = 4;
        }
        break;
    case 2:
        func_800C8E04(3);
        vs_mainmenu_setMessage(
            (char*)&vs_mainMenu_menu12Text[VS_MENU12_BIN_OFFSET_repairComplete]);

        for (i = 0; i < 16; ++i) {
            new_var = D_800619D8.unk0[i + 8];
            if (new_var != 0) {
                vs_battle_inventoryBlade* blade =
                    &vs_battle_inventory.blades[new_var - 1];

                ppCost = blade->maxDp - blade->currentDp;
                ppCost = blade->currentPp - (ppCost / 100);
                blade->currentDp = blade->maxDp;

                if (ppCost >= 0) {
                    blade->currentPp = ppCost;
                } else {
                    blade->currentPp = 0;
                }
            }
        }

        for (i = 0; i < 8; ++i) {
            new_var = D_800619D8.unk0[i];
            if (new_var != 0) {
                vs_battle_inventoryWeapon* weapon =
                    &vs_battle_inventory.weapons[new_var - 1];
                if (weapon->isEquipped != 0) {
                    vs_battle_equipWeapon(weapon);
                }
            }
        }

        for (i = 0; i < 8; ++i) {
            new_var = D_800619D8.unk28[i];
            if (new_var != 0) {
                vs_battle_inventoryShield* shield =
                    &vs_battle_inventory.shields[new_var - 1];

                ppCost = shield->base.maxDp - shield->base.currentDp;
                ppCost = shield->base.currentPp - (ppCost / 100);
                shield->base.currentDp = shield->base.maxDp;

                if (ppCost >= 0) {
                    shield->base.currentPp = ppCost;
                } else {
                    shield->base.currentPp = 0;
                }

                if (shield->isEquipped != 0) {
                    vs_battle_equipShield(shield);
                }
            }
        }

        for (i = 0; i < 16; ++i) {
            new_var = D_800619D8.unk28[i + 8];
            if (new_var != 0) {
                vs_battle_inventoryArmor* armor = &vs_battle_inventory.armor[new_var - 1];
                if (armor->category != 7) {

                    ppCost = armor->maxDp - armor->currentDp;
                    ppCost = armor->currentPp - (ppCost / 100);
                    armor->currentDp = armor->maxDp;

                    if (ppCost >= 0) {
                        armor->currentPp = ppCost;
                    } else {
                        armor->currentPp = 0;
                    }
                    if (armor->bodyPart != 0) {
                        vs_battle_equipArmor(armor->bodyPart - 1, armor);
                    }
                }
            }
        }

        state = 3;
        break;
    case 3:
        if (vs_main_buttonsPressed.pad[0].low != 0) {
            vs_battle_playMenuLeaveSfx();
            vs_mainMenu_menuItemLeaveRight(0xE);
            if (vs_main_buttonsPressed.all & PADRup) {
                return -2;
            }
            func_800FFBC8();
            state = 4;
        }
        break;
    case 4:
        if (vs_mainmenu_ready() != 0) {
            return returnedFromPrompt;
        }
        break;
    }
    return 0;
}

static void* _sydData = NULL;

static int _loadSyd(int id)
{
    static int _sydLbas[] = { VS_BLADE_SYD_LBA, VS_SHIELD_SYD_LBA, VS_ARMOR_SYD_LBA };
    static int _sydSizes[] = { VS_BLADE_SYD_SIZE, VS_SHIELD_SYD_SIZE, VS_ARMOR_SYD_SIZE };

    static vs_main_CdQueueSlot* _sydCdQueueSlot;
    static char _sydFileLoading;
    static char _[3] __attribute__((unused));

    vs_main_CdFile cdFile;

    if (id != 0) {
        --id;
        _sydData = vs_main_allocHeapR(_sydSizes[id]);
        cdFile.lba = _sydLbas[id];
        cdFile.size = _sydSizes[id];
        _sydCdQueueSlot = vs_main_allocateCdQueueSlot(&cdFile);
        vs_main_cdEnqueue(_sydCdQueueSlot, _sydData);
        _sydFileLoading = 1;
        return 0;
    }
    if (_sydFileLoading == 0) {
        return 1;
    }

    if (_sydCdQueueSlot->state == 4) {
        vs_main_freeCdQueueSlot(_sydCdQueueSlot);
        _sydFileLoading = 0;
        return 1;
    }
    return 0;
}

static vs_battle_menuItem_t* _setItemRow(int itemType, int index)
{
    vs_battle_menuItem_t* menuItem = vs_battle_setMenuItem(0, 155, 18, 165, 0,
        (index == 0
                ? (char*)&vs_mainMenu_menu12Text
                      [vs_mainMenu_menu12Text[itemType + VS_MENU12_BIN_INDEX_newBlade]]
                : vs_mainMenu_itemNames[index]));
    menuItem->selected = 1;
    return menuItem;
}

static vs_battle_menuItem_t* _initItemRow(int itemType, int index)
{
    vs_battle_menuItem_t* menuItem;

    menuItem = _setItemRow(itemType, index);
    menuItem->state = 2;
    menuItem->targetX = 155;
    menuItem->initialX = 320;

    return menuItem;
}

static vs_battle_inventoryBlade* _combineBlades(vs_battle_inventoryBlade*,
    vs_battle_inventoryBlade*, vs_battle_inventoryBlade*, void*);

static vs_battle_inventoryBlade _combinedBlade;
static char D_8010BD10[2];
static char _1[2] __attribute__((unused));

static void _setCombineBladeUi(int arg0)
{
    int i;
    int var_s3;
    u_int temp_v1;
    int temp_s2;
    vs_battle_inventoryBlade* blade;

    i = D_8010BD10[0];
    temp_s2 = D_8010BD10[1];

    var_s3 = i != 0;
    if (temp_s2 != 0) {
        var_s3 += 2;
    }

    switch (var_s3) {
    case 0:
        vs_battle_rMemzero(&_combinedBlade, sizeof _combinedBlade);
        break;
    case 1:
    case 2:
        vs_battle_copyAligned(&_combinedBlade,
            &vs_battle_inventory.blades[i + temp_s2 - 1], sizeof _combinedBlade);
        break;
    case 3:
        vs_battle_rMemzero(&_combinedBlade, sizeof _combinedBlade);
        _combineBlades(&vs_battle_inventory.blades[i - 1],
            &vs_battle_inventory.blades[temp_s2 - 1], &_combinedBlade, _sydData);
        break;
    }

    blade = &_combinedBlade;
    blade->assembledWeaponIndex = 0;

    vs_mainMenu_resetStats();
    vs_mainMenu_setRangeRisk(0, 0, 0, 1);

    temp_v1 = arg0 - 1;

    if (temp_v1 >= 2) {
        if (_combinedBlade.id != 0) {
            for (i = 0; i < 16; ++i) {
                vs_mainMenu_equipmentStats[i] = blade->classes[i & 7];
                vs_mainMenu_equipmentStats[16 + i] = blade->affinities[i & 7];
            }
            vs_mainMenu_setDpPp(
                blade->currentDp, blade->maxDp, blade->currentPp, blade->maxPp);
            vs_mainMenu_setStrIntAgi(
                blade->strength, blade->intelligence, blade->agility, 1);
            vs_mainMenu_setRangeRisk(blade->range.unk0, blade->cost, 0, 1);
            vs_mainMenu_equipmentSubtype = 2;
        }
    } else if (var_s3 & arg0) {
        vs_mainMenu_setUiBladeStats(D_8010BD10[temp_v1]);
    }
}

static int _selectBlade(int arg0)
{
    static int selectedRow;
    static char state;
    static char D_8010BC61;

    int count;
    int i;
    char* textBuf;
    char** menuText;
    int temp_a0;
    int itemId;
    vs_battle_inventoryBlade* blade = NULL;

    if (arg0 != 0) {
        D_8010BC61 = arg0;
        _initMenuHeader(arg0 + 10);
        state = 0;
        return 0;
    }

    itemId = D_8010BD10[D_8010BC61 - 1];
    if (itemId != 0) {
        blade = &vs_battle_inventory.blades[itemId - 1];
    }

    switch (state) {
    case 0:
        if (vs_mainmenu_ready() == 0) {
            break;
        }

        textBuf = vs_main_allocHeapR(0x72C);
        menuText = (char**)(textBuf + 0x6A4);

        if (blade == NULL) {
            menuText[0] = (char*)&vs_mainMenu_menu12Text[VS_MENU12_BIN_OFFSET_blade];
            menuText[1] =
                (char*)&vs_mainMenu_menu12Text[VS_MENU12_BIN_OFFSET_selectBladeToCombine];
            *vs_battle_rowTypeBuf = 1;
        } else {
            vs_mainMenu_setBladeUi(blade, menuText, vs_battle_rowTypeBuf, textBuf);
        }

        _availableItems[0] = itemId;
        count = 1;

        for (i = 0; i < 16; ++i) {
            itemId = D_800619D8.unk0[i + 8];
            if ((itemId != 0) && (itemId != D_8010BD10[0]) && (itemId != D_8010BD10[1])) {
                int new_var = itemId;
                blade = &vs_battle_inventory.blades[itemId - 1];
                vs_mainMenu_setBladeUi(blade, menuText + count * 2,
                    &vs_battle_rowTypeBuf[count], textBuf + count * 0x60);
                if (!((D_8010BB30[_workshopFlags] >> blade->material) & 1)) {
                    menuText[count * 2 + 1] = (char*)&vs_mainMenu_menu12Text
                        [VS_MENU12_BIN_OFFSET_invalidBladeMaterial];
                    vs_battle_rowTypeBuf[count] |= 1;
                }

                temp_a0 = blade->assembledWeaponIndex;

                if (temp_a0 != 0) {
                    vs_battle_rowTypeBuf[count] =
                        vs_battle_rowTypeBuf[count]
                        | (vs_battle_inventory.weapons[temp_a0 - 1].isEquipped == 0
                                ? 0xCC00
                                : 0xCA00);
                }
                _availableItems[count] = new_var;
                ++count;
            }
        }

        _populateItemsList(count, menuText, vs_battle_rowTypeBuf);
        vs_main_freeHeapR(textBuf);
        state = 1;
        break;
    case 1:
        itemId = _availableItems[_itemsListWindow + _itemsListSelection];
        if (itemId != 0) {
            vs_mainMenu_setUiBladeStats(itemId);
        } else {
            vs_mainMenu_resetStats();
            vs_mainMenu_setRangeRisk(0, 0, 0, 1);
        }
        vs_mainMenu_printInformation(
            _itemsListSelection + _itemsListWindow, _itemsListState);
        _navigateItemsList(2);
        selectedRow = _getSelectedRow() + 1;
        if (selectedRow != 0) {
            vs_mainMenu_clearMenuExcept(vs_mainMenu_menuItemIds_none);
            if (selectedRow == -2) {
                return -2;
            }
            if (selectedRow > 0) {
                selectedRow = _availableItems[selectedRow - 1];
            }
            state = 2;
        }
        break;
    case 2:
        if (vs_mainmenu_ready() != 0) {
            return selectedRow;
        }
        break;
    }
    return 0;
}

static void _setBladeMenuItem(
    vs_battle_menuItem_t* menuItem, vs_battle_inventoryBlade* blade)
{
    int assembledWeapon;

    menuItem->icon = blade->category;
    menuItem->material = blade->material;
    assembledWeapon = blade->assembledWeaponIndex;
    if (assembledWeapon != 0) {
        menuItem->itemState =
            vs_battle_inventory.weapons[assembledWeapon - 1].isEquipped == 0 ? 2 : 1;
    }
}

static int _combineBladeMenu(int arg0)
{
    static char D_8010BB74 = 0;

    static char state;
    static char D_8010BC63;
    static char D_8010BC64;
    static char _[3] __attribute__((unused));

    char* menuText[2];
    int rowType;
    int itemId;
    int var_s1;
    int temp_v0_2;
    int i;
    char* var_a0_2;
    int i_2;
    vs_battle_inventoryBlade* blade;
    vs_battle_menuItem_t* menuItem;

    if (arg0 != 0) {
        _pushSelectionHistory(5);
        *(u_short*)&D_8010BD10 = 0;
        _setCombineBladeUi(0);
        D_8010BC63 = 1;
        state = 0;
        return 0;
    }

    var_s1 = 0;
    if (D_8010BD10[0] != 0) {
        var_s1 = D_8010BD10[1] > 0;
    }

    D_8010BC64 += 16;
    if (state != 2) {
        D_8010BC64 = 0;
    }

    switch (state) {
    case 0:
        if (vs_mainmenu_ready() == 0) {
            break;
        }
        _initMenuItem(VS_MENU12_BIN_OFFSET_combineBlade, 24);
        // Fallthrough
    case 1:
        var_s1 = _combinedBlade.id;
        menuItem = _initItemRow(0, var_s1);
        if (var_s1 != 0) {
            _setBladeMenuItem(menuItem, &_combinedBlade);
        }

        for (i = 0; i < 2; ++i) {
            var_s1 = D_8010BD10[i];
            if (var_s1 != 0) {
                blade = &vs_battle_inventory.blades[var_s1 - 1];
            }
            menuItem = vs_battle_setMenuItem(i + 11, 334, 34 + i * 16, 151, 0,
                var_s1 == 0 ? (char*)&vs_mainMenu_menu12Text[VS_MENU12_BIN_OFFSET_blade]
                            : vs_mainMenu_itemNames[blade->id]);
            menuItem->state = 2;
            menuItem->targetX = 169;
            if (var_s1 == 0) {
                menuItem->unkA = 1;
            } else {
                _setBladeMenuItem(menuItem, blade);
            }
        }
        state = 2;
        break;
    case 2:
        if (vs_mainmenu_ready() != 0) {
            if (!(vs_main_buttonsPressed.all & PADRup)) {
                if (var_s1 != 0) {
                    _drawOk(2, D_8010BC64);
                }
                if (vs_main_buttonsPressed.all & PADRdown) {
                    temp_v0_2 = _popSelectionHistory(5);
                    if (temp_v0_2 != 0) {
                        vs_battle_playMenuLeaveSfx();
                        D_8010BC63 = temp_v0_2;
                        D_8010BD10[temp_v0_2 - 1] = 0;
                        _setCombineBladeUi(temp_v0_2);
                        menuItem = vs_battle_setMenuItem(temp_v0_2 + 10, 169,
                            (temp_v0_2 * 16) + 18, 151, 0,
                            (char*)&vs_mainMenu_menu12Text[VS_MENU12_BIN_OFFSET_blade]);
                        menuItem->selected = 1;
                        menuItem->unkA = 1;
                        var_s1 = _combinedBlade.id;
                        menuItem = _setItemRow(0, var_s1);
                        if (var_s1 != 0) {
                            _setBladeMenuItem(menuItem, &_combinedBlade);
                        }
                        break;
                    }
                    return _leaveItemSlotSelection(1);
                }
                if (vs_main_buttonsPressed.all & PADstart) {
                    if (var_s1 != 0) {
                        vs_battle_playMenuSelectSfx();
                        vs_battle_getMenuItem(D_8010BC63 + 10)->selected = 0;
                        D_8010BC63 = 3;
                        state = 4;
                        _setCombineBladeUi(3);
                        return 0;
                    }
                }
                i_2 = D_8010BC63;
                if (vs_main_buttonsPressed.all & PADRright) {
                    if (i_2 == 0) {
                        func_800C02E0();
                    } else {
                        vs_battle_playMenuSelectSfx();
                        if (i_2 == 3) {
                            state = 4;
                        } else {
                            vs_mainMenu_clearMenuExcept(vs_mainMenu_menuItemIds_none);
                            _selectBlade(i_2);
                            state = 3;
                        }
                        break;
                    }
                }
                if (vs_main_buttonRepeat & PADLup) {
                    if (i_2 == 0) {
                        i_2 = var_s1 + 2;
                    } else {
                        --i_2;
                    }
                }
                if (vs_main_buttonRepeat & PADLdown) {
                    if (i_2 == (var_s1 + 2)) {
                        i_2 = 0;
                    } else {
                        ++i_2;
                    }
                }

                if (i_2 != D_8010BC63) {
                    vs_battle_playMenuChangeSfx();
                    D_8010BC63 = i_2;
                    _setCombineBladeUi(D_8010BC63);
                }
                vs_battle_rowTypeBuf[0] = _combinedBlade.id < 1;

                for (var_s1 = 1; var_s1 < 3; ++var_s1) {
                    vs_battle_getMenuItem(var_s1 + 10)->selected = var_s1 == D_8010BC63;
                    vs_battle_rowTypeBuf[var_s1] = D_8010BD10[var_s1 - 1] == 0;
                }

                vs_battle_rowTypeBuf[3] = 1;
                vs_mainMenu_printInformation(i_2, 16);
                menuText[1] = (char*)&vs_mainMenu_menu12Text
                    [VS_MENU12_BIN_OFFSET_selectBladeToCombine];
                switch (i_2) {
                case 0:
                    if (_combinedBlade.id != 0) {
                        vs_mainMenu_setBladeUi(
                            &_combinedBlade, menuText, &rowType, vs_battle_stringBuf);
                    }
                    break;
                case 1:
                case 2:
                    var_s1 = D_8010BD10[i_2 - 1];
                    if (var_s1 != 0) {
                        vs_mainMenu_setBladeUi(&vs_battle_inventory.blades[var_s1 - 1],
                            menuText, &rowType, vs_battle_stringBuf);
                    }
                    break;
                case 3:
                    menuText[1] =
                        (char*)&vs_mainMenu_menu12Text[VS_MENU12_BIN_OFFSET_pressOk];
                    break;
                }

                vs_mainmenu_setMessage(menuText[1]);
                var_s1 = (((i_2 * 16) + 10) << 0x10) | 0x9B;

                if (i_2 == 0) {
                    var_s1 -= 14;
                }
                if (i_2 == 3) {
                    var_s1 += 0xFFFC0000;
                }
                D_8010BB74 = func_800FFCDC(D_8010BB74, var_s1);
                break;
            }
            return _leaveItemSlotSelection(1);
        }
        D_8010BC64 = 0;
        break;
    case 3:
        itemId = _selectBlade(0);
        if (itemId == 0) {
            break;
        }
        if (itemId == -2) {
            return _leaveItemSlotSelection(1);
        }
        if (itemId > 0) {
            var_s1 = D_8010BC63 - 1;
            if (itemId == D_8010BD10[D_8010BC63 - 1]) {
                D_8010BD10[D_8010BC63 - 1] = 0;
                _popSelectionHistory(var_s1);
            } else {
                D_8010BD10[D_8010BC63 - 1] = itemId;
                _pushSelectionHistory(var_s1);
                D_8010BC63 = (D_8010BC63 + 1);
                if (var_s1 == 1) {
                    if (D_8010BD10[0] == 0) {
                        D_8010BC63 = var_s1;
                    }
                }
            }
            _setCombineBladeUi(D_8010BC63);
        }
        state = 1;
        break;
    case 4:
        vs_battle_renderEquipStats(2);
        _confirmCombine(2);
        var_s1 = 0;

        for (i = 0; i < 2; ++i) {
            var_s1 |= vs_battle_inventory.blades[D_8010BD10[i] - 1].assembledWeaponIndex;
        }
        if (var_s1 == 0) {
            var_a0_2 =
                (char*)&vs_mainMenu_menu12Text[VS_MENU12_BIN_OFFSET_attachmentConfirm];
        } else {
            var_a0_2 =
                (char*)&vs_mainMenu_menu12Text[VS_MENU12_BIN_OFFSET_cancelCombineConfirm];
        }
        vs_mainmenu_setMessage(var_a0_2);
        state = 5;
        break;
    case 5:
        temp_v0_2 = _confirmCombine(0);

        if (temp_v0_2 == 0) {
            break;
        }

        switch (temp_v0_2) {
        case 1:
            vs_main_playSfxDefault(0x7E, 0x18);
            func_800FFBC8();
            vs_mainMenu_drawClassAffinityType(-1);
            vs_mainMenu_drawDpPpbars(4);
            vs_mainMenu_clearMenuExcept(vs_mainMenu_menuItemIds_none);
            vs_mainMenu_menuItemLeaveLeft(0);

            for (i = 0; i < 2; ++i) {
                blade = &vs_battle_inventory.blades[D_8010BD10[i] - 1];
                var_s1 = blade->assembledWeaponIndex;
                if (var_s1 != 0) {
                    if (vs_battle_inventory.weapons[var_s1 - 1].isEquipped != 0) {
                        vs_mainMenu_unequipAllWeapons();
                        state = 6;
                    }
                    _disassembleWeapon(var_s1 - 1);
                }
                vs_mainMenu_initItem(1, D_8010BD10[i]);
            }

            itemId = D_8010BD10[0];
            blade = &vs_battle_inventory.blades[itemId - 1];
            vs_battle_copyAligned(blade, &_combinedBlade, sizeof *blade);
            blade->index = itemId;
            vs_mainMenu_rebuildInventory(1);
            return state != 6;
        case 2:
            vs_battle_playMenuLeaveSfx();
            vs_battle_renderEquipStats(1);
            state = 2;
            break;
        case 3:
            return _leaveItemSlotSelection(1);
        }
        break;
    case 6:
        if (func_8010BA58(0) == 0) {
            return -1;
        }
        break;
    }
    return 0;
}

static void _setShieldUi(vs_battle_inventoryShield* shield)
{
    int i;
    vs_battle_inventoryArmor* base = &shield->base;

    vs_mainMenu_resetStats();

    for (i = 0; i < 16; ++i) {
        vs_mainMenu_equipmentStats[i] = base->classes[i & 7];
        vs_mainMenu_equipmentStats[16 + i] = base->affinities[i & 7];
    }

    for (i = 0; i < 4; ++i) {
        vs_mainMenu_equipmentStats[32 + i] = base->types[i];
    }

    vs_mainMenu_setDpPp(base->currentDp, base->maxDp, 0, 0);
    vs_mainMenu_setStrIntAgi(base->strength, base->intelligence, base->agility, 1);
    vs_mainMenu_strIntAgi[1].strength = base->strength;
    vs_mainMenu_strIntAgi[1].intelligence = base->intelligence;
    vs_mainMenu_strIntAgi[1].agility = base->agility;
    vs_mainMenu_equipmentSubtype = 8;
}

static vs_battle_inventoryArmor* _combineShields(vs_battle_inventoryArmor*,
    vs_battle_inventoryArmor*, vs_battle_inventoryArmor*, void*);

static vs_battle_inventoryShield D_8010BD14;
static u_char _itemsToCombine[16];

static void _initCombineShields(int arg0)
{
    u_int temp_v1;
    vs_battle_inventoryShield* shield;

    int first = _itemsToCombine[0];
    int second = _itemsToCombine[1];

    int var_s2 = first > 0;

    if (second != 0) {
        var_s2 += 2;
    }

    switch (var_s2) {
    case 0:
        vs_battle_rMemzero(&D_8010BD14, sizeof D_8010BD14);
        break;
    case 1:
    case 2:
        vs_battle_copyAligned(&D_8010BD14,
            &vs_battle_inventory.shields[first + second - 1], sizeof D_8010BD14);
        break;
    case 3:
        vs_battle_rMemzero(&D_8010BD14, sizeof D_8010BD14);
        _combineShields(&vs_battle_inventory.shields[first - 1].base,
            &vs_battle_inventory.shields[second - 1].base, &D_8010BD14.base, _sydData);
        break;
    }

    shield = &D_8010BD14;
    shield->isEquipped = 0;

    vs_mainMenu_resetStats();

    temp_v1 = arg0 - 1;

    if (temp_v1 > 1) {
        if (shield->base.id != 0) {
            _setShieldUi(shield);
        }
    } else if (var_s2 & arg0) {
        _setShieldUi(&vs_battle_inventory.shields[_itemsToCombine[temp_v1] - 1]);
    }
}

static void _initUiShield(
    vs_battle_inventoryShield* shield, char** menuText, int* rowTypes, char* stringBuf)
{
    int gems = *(int*)shield->gems;
    *(int*)shield->gems = 0;
    vs_mainMenu_initUiShield(shield, menuText, rowTypes, stringBuf);
    *(int*)shield->gems = gems;
}

static int _selectShields(int arg0)
{
    static int D_8010BC68;
    static char state;
    static char D_8010BC6D;

    char** menuText;
    int rowType;
    int i;
    char* stringBuf;
    int itemId;
    vs_battle_inventoryShield* shield;

    shield = NULL;

    if (arg0 != 0) {
        D_8010BC6D = arg0;
        _initMenuHeader(arg0 + 10);
        state = 0;
        return 0;
    }

    itemId = _itemsToCombine[D_8010BC6D - 1];
    if (itemId != 0) {
        shield = &vs_battle_inventory.shields[itemId - 1];
    }

    switch (state) {
    case 0:
        if (vs_mainmenu_ready() != 0) {
            stringBuf = vs_main_allocHeapR(0x3CC);
            menuText = (char**)(stringBuf + 0x384);
            if (shield == NULL) {
                menuText[0] = (char*)&vs_mainMenu_menu12Text[VS_MENU12_BIN_OFFSET_shield];
                menuText[1] =
                    (char*)&vs_mainMenu_menu12Text[VS_MENU12_BIN_OFFSET_selectShield];
                *vs_battle_rowTypeBuf = 1;
            } else {
                _initUiShield(shield, menuText, vs_battle_rowTypeBuf, stringBuf);
            }

            _availableItems[0] = itemId;
            rowType = 1;

            for (i = 0; i < 8; ++i) {
                itemId = D_800619D8.unk0[i + 0x28];
                if ((itemId != 0) && (itemId != _itemsToCombine[0])
                    && (itemId != _itemsToCombine[1])) {
                    shield = &vs_battle_inventory.shields[itemId - 1];
                    _initUiShield(shield, menuText + rowType * 2,
                        &vs_battle_rowTypeBuf[rowType], stringBuf + rowType * 0x60);
                    if (!((D_8010BB30[_workshopFlags] >> shield->base.material) & 1)) {
                        menuText[rowType * 2 + 1] = (char*)&vs_mainMenu_menu12Text
                            [VS_MENU12_BIN_OFFSET_invalidShieldMaterial];
                        vs_battle_rowTypeBuf[rowType] |= 1;
                    }
                    if (shield->isEquipped != 0) {
                        vs_battle_rowTypeBuf[rowType] |= 0xCA00;
                    }
                    _availableItems[rowType] = itemId;
                    ++rowType;
                }
            }

            _populateItemsList(rowType, menuText, vs_battle_rowTypeBuf);
            vs_main_freeHeapR(stringBuf);
            state = 1;
        }
        break;
    case 1:
        itemId = _availableItems[_itemsListWindow + _itemsListSelection];
        if (itemId != 0) {
            _setShieldUi(&vs_battle_inventory.shields[itemId - 1]);
        } else {
            vs_mainMenu_resetStats();
        }
        vs_mainMenu_printInformation(
            _itemsListSelection + _itemsListWindow, _itemsListState);
        _navigateItemsList(2);
        D_8010BC68 = _getSelectedRow() + 1;
        if (D_8010BC68 != 0) {
            vs_mainMenu_clearMenuExcept(vs_mainMenu_menuItemIds_none);
            if (D_8010BC68 == -2) {
                return -2;
            }
            if (D_8010BC68 > 0) {
                D_8010BC68 = _availableItems[D_8010BC68 - 1];
            }
            state = 2;
        }
        break;
    case 2:
        if (vs_mainmenu_ready() != 0) {
            return D_8010BC68;
        }
        break;
    }
    return 0;
}

static void _setShieldMenuItem(
    vs_battle_menuItem_t* menuItem, vs_battle_inventoryShield* shield)
{
    menuItem->icon = 15;
    menuItem->material = shield->base.material;
    menuItem->itemState = shield->isEquipped != 0;
}

static int _combineShieldMenu(int arg0)
{
    static char D_8010BB75 = 0;

    static char state;
    static char D_8010BC6F;
    static char D_8010BC70;
    static char _[3] __attribute__((unused));

    char* menuText[2];
    int rowType;
    int itemId_3;
    int var_a0;
    int var_s1;
    int i;
    u_short* var_a0_2;
    int temp_s1;
    int temp_s2;
    int temp_v1_2;
    vs_battle_inventoryShield* shield1;
    vs_battle_inventoryShield* shield0;
    vs_battle_menuItem_t* temp_v0;

    if (arg0 != 0) {
        _pushSelectionHistory(5);
        *(u_short*)_itemsToCombine = 0;
        _initCombineShields(0);
        D_8010BC6F = 1;
        state = 0;
        return 0;
    }

    var_s1 = 0;

    if (_itemsToCombine[0] != 0) {
        var_s1 = _itemsToCombine[1] > 0;
    }

    D_8010BC70 += 0x10;
    if (state != 2) {
        D_8010BC70 = 0;
    }

    switch (state) {
    case 0:
        if (vs_mainmenu_ready() == 0) {
            break;
        }
        _initMenuItem(0x48F, 0x1B);
        // Fallthrough
    case 1:
        temp_s1 = D_8010BD14.base.id;
        temp_v0 = _initItemRow(1, temp_s1);
        if (temp_s1 != 0) {
            _setShieldMenuItem(temp_v0, &D_8010BD14);
        }

        for (i = 0; i < 2; ++i) {
            temp_s1 = _itemsToCombine[i];
            if (temp_s1 != 0) {
                shield0 = &vs_battle_inventory.shields[temp_s1 - 1];
            }
            temp_v0 = vs_battle_setMenuItem(i + 0xB, 0x14E, 0x22 + i * 0x10, 0x97, 0,
                (temp_s1 == 0
                        ? (char*)&vs_mainMenu_menu12Text[VS_MENU12_BIN_OFFSET_shield]
                        : vs_mainMenu_itemNames[shield0->base.id]));
            temp_v0->state = 2;
            temp_v0->targetX = 0xA9;
            if (temp_s1 == 0) {
                temp_v0->unkA = 1;
            } else {
                _setShieldMenuItem(temp_v0, shield0);
            }
        }

        state = 2;
        break;
    case 2:
        if (vs_mainmenu_ready() != 0) {
            if (!(vs_main_buttonsPressed.all & PADRup)) {
                if (var_s1 != 0) {
                    _drawOk(2, D_8010BC70);
                }
                if (vs_main_buttonsPressed.all & PADRdown) {
                    temp_s2 = _popSelectionHistory(5);
                    if (temp_s2 != 0) {
                        vs_battle_playMenuLeaveSfx();
                        D_8010BC6F = temp_s2;
                        _itemsToCombine[temp_s2 - 1] = 0;
                        _initCombineShields(temp_s2);
                        temp_v0 = vs_battle_setMenuItem(temp_s2 + 0xA, 0xA9,
                            (temp_s2 * 0x10) + 0x12, 0x97, 0,
                            (char*)(vs_mainMenu_menu12Text + 0x439));
                        temp_v0->selected = 1;
                        temp_v0->unkA = 1;
                        var_s1 = D_8010BD14.base.id;
                        temp_v0 = _setItemRow(1, var_s1);
                        if (var_s1 != 0) {
                            _setShieldMenuItem(temp_v0, &D_8010BD14);
                            return 0;
                        }
                        break;
                    }
                    return _leaveItemSlotSelection(1);
                }
                if (vs_main_buttonsPressed.all & 0x800) {
                    if (var_s1 != 0) {
                        vs_battle_playMenuSelectSfx();
                        vs_battle_getMenuItem(D_8010BC6F + 0xA)->selected = 0;
                        D_8010BC6F = 3;
                        state = 4U;
                        _initCombineShields(3);
                        return 0;
                    }
                }
                temp_s2 = D_8010BC6F;
                if (vs_main_buttonsPressed.all & 0x20) {
                    if (temp_s2 == 0) {
                        func_800C02E0();
                    } else {
                        vs_battle_playMenuSelectSfx();
                        if (temp_s2 == 3) {
                            state = 4;
                        } else {
                            vs_mainMenu_clearMenuExcept(vs_mainMenu_menuItemIds_none);
                            _selectShields(temp_s2);
                            state = 3;
                        }
                        break;
                    }
                }

                if (vs_main_buttonRepeat & 0x1000) {
                    if (temp_s2 == 0) {
                        temp_s2 = var_s1 + 2;
                    } else {
                        --temp_s2;
                    }
                }

                if (vs_main_buttonRepeat & 0x4000) {
                    if (temp_s2 == (var_s1 + 2)) {
                        temp_s2 = 0;
                    } else {
                        ++temp_s2;
                    }
                }

                if (temp_s2 != D_8010BC6F) {
                    vs_battle_playMenuChangeSfx();
                    D_8010BC6F = temp_s2;
                    _initCombineShields(D_8010BC6F);
                }
                vs_battle_rowTypeBuf[0] = D_8010BD14.base.id < 1;

                for (var_s1 = 1; var_s1 < 3; ++var_s1) {
                    vs_battle_getMenuItem(var_s1 + 0xA)->selected = var_s1 == D_8010BC6F;
                    vs_battle_rowTypeBuf[var_s1] = _itemsToCombine[var_s1 - 1] == 0;
                }

                vs_battle_rowTypeBuf[3] = 1;
                vs_mainMenu_printInformation(temp_s2, 0x10);
                menuText[1] =
                    (char*)&vs_mainMenu_menu12Text[VS_MENU12_BIN_OFFSET_selectShield];
                switch (temp_s2) {
                case 0:
                    if (D_8010BD14.base.id != 0) {
                        _initUiShield(
                            &D_8010BD14, menuText, &rowType, vs_battle_stringBuf);
                    }
                    break;
                case 1:
                case 2:
                    var_s1 = _itemsToCombine[temp_s2 - 1];
                    if (var_s1 != 0) {
                        shield1 = &vs_battle_inventory.shields[var_s1 - 1];
                        var_s1 = *(int*)shield1->gems;
                        *(int*)shield1->gems = 0;
                        _initUiShield(shield1, menuText, &rowType, vs_battle_stringBuf);
                        *(int*)shield1->gems = var_s1;
                    }
                    break;
                case 3:
                    menuText[1] = (char*)(vs_mainMenu_menu12Text + 0x39E);
                    break;
                }
                vs_mainmenu_setMessage((char*)menuText[1]);
                var_s1 = (((temp_s2 * 0x10) + 0xA) << 0x10) | 0x9B;
                if (temp_s2 == 0) {
                    var_s1 -= 0xE;
                }
                if (temp_s2 == 3) {
                    var_s1 += 0xFFFC0000;
                }
                D_8010BB75 = func_800FFCDC(D_8010BB75, var_s1);
                break;
            }
            return _leaveItemSlotSelection(1);
        }
        D_8010BC70 = 0;
        break;
    case 3:
        temp_s2 = _selectShields(0);
        if (temp_s2 != 0) {
            if (temp_s2 != -2) {
                if (temp_s2 > 0) {
                    var_s1 = D_8010BC6F - 1;
                    if (temp_s2 == _itemsToCombine[D_8010BC6F - 1]) {
                        _itemsToCombine[D_8010BC6F - 1] = 0;
                        _popSelectionHistory(var_s1);
                    } else {
                        _itemsToCombine[D_8010BC6F - 1] = temp_s2;
                        _pushSelectionHistory(var_s1);
                        D_8010BC6F = (D_8010BC6F + 1);
                        if (var_s1 == 1) {
                            if (_itemsToCombine[0] == 0) {
                                D_8010BC6F = var_s1;
                            }
                        }
                    }
                    _initCombineShields(D_8010BC6F);
                }
                state = 1;
                break;
            }
            return _leaveItemSlotSelection(1);
        }
        break;
    case 4:
        vs_battle_renderEquipStats(2);
        _confirmCombine(2);
        var_s1 = 0;

        for (i = 0; i < 2; ++i) {

            shield0 = &vs_battle_inventory.shields[_itemsToCombine[i] - 1];
            temp_v1_2 = shield0->base.gemSlots;
            var_s1 |= shield0->isEquipped;

            for (var_a0 = 0; var_a0 < temp_v1_2; ++var_a0) {
                var_s1 |= shield0->gems[var_a0];
            }
        }

        if (var_s1 == 0) {
            var_a0_2 = vs_mainMenu_menu12Text + 0x42B;
        } else {
            var_a0_2 = vs_mainMenu_menu12Text + 0x4A7;
        }
        vs_mainmenu_setMessage((char*)var_a0_2);
        state = 5;
        break;
    case 5:
        temp_s2 = _confirmCombine(0);

        if (temp_s2 == 0) {
            break;
        }

        switch (temp_s2) {
        case 1:
            vs_main_playSfxDefault(0x7E, 0x18);

            func_800FFBC8();
            vs_mainMenu_drawClassAffinityType(-1);
            vs_mainMenu_drawDpPpbars(4);
            vs_mainMenu_clearMenuExcept(vs_mainMenu_menuItemIds_none);
            vs_mainMenu_menuItemLeaveLeft(0);

            for (i = 0; i < 2; ++i) {
                temp_s1 = _itemsToCombine[i];
                itemId_3 = temp_s1 - 1;
                if (vs_battle_inventory.shields[itemId_3].isEquipped != 0) {
                    vs_mainMenu_unequipShield();
                    state = 6;
                }
                _disassembleShield(itemId_3);
                vs_mainMenu_initItem(3, temp_s1);
            }

            temp_s2 = _itemsToCombine[0];
            shield1 = &vs_battle_inventory.shields[temp_s2 - 1];
            vs_battle_copyAligned(shield1, &D_8010BD14, 0x30);
            shield1->index = temp_s2;
            vs_mainMenu_rebuildInventory(3);
            return state != 6;
        case 2:
            vs_battle_playMenuLeaveSfx();
            vs_battle_renderEquipStats(1);
            state = temp_s2;
            break;
        case 3:
            return _leaveItemSlotSelection(1);
        }
        break;
    case 6:
        if (func_8010BA58(1) == 0) {
            return -1;
        }
        break;
    }
    return 0;
}

static vs_battle_inventoryArmor* _combineArmor(vs_battle_inventoryArmor*,
    vs_battle_inventoryArmor*, vs_battle_inventoryArmor*, void*);

static vs_battle_inventoryArmor D_8010BD54;
static char D_8010BD7C[2];
static char _2[2] __attribute__((unused));

static void _initCombineArmor(int arg0)
{
    int var_a0;
    u_int temp_v1;
    vs_battle_inventoryArmor* armor;

    int i = D_8010BD7C[0];
    int temp_s3 = D_8010BD7C[1];
    int var_s2 = i != 0;

    if (temp_s3 != 0) {
        var_s2 += 2;
    }

    switch (var_s2) {
    case 0:
        vs_battle_rMemzero(&D_8010BD54, sizeof D_8010BD54);
        break;
    case 1:
    case 2:
        vs_battle_copyAligned(
            &D_8010BD54, &vs_battle_inventory.armor[i + temp_s3 - 1], sizeof D_8010BD54);
        break;
    case 3:
        vs_battle_rMemzero(&D_8010BD54, sizeof D_8010BD54);
        _combineArmor(&vs_battle_inventory.armor[i - 1],
            &vs_battle_inventory.armor[temp_s3 - 1], &D_8010BD54, _sydData);
        break;
    }

    armor = &D_8010BD54;
    armor->bodyPart = 0;

    vs_mainMenu_resetStats();

    temp_v1 = arg0 - 1;

    if (temp_v1 >= 2) {
        if (D_8010BD54.id != 0) {
            for (i = 0; i < 16; ++i) {
                vs_mainMenu_equipmentStats[i] = armor->classes[i & 7];
                vs_mainMenu_equipmentStats[16 + i] = armor->affinities[i & 7];
            }

            for (i = 0; i < 4; ++i) {
                vs_mainMenu_equipmentStats[32 + i] = armor->types[i];
                var_a0 += 2;
            }
            vs_mainMenu_setDpPp(armor->currentDp, armor->maxDp, 0, 0);
            vs_mainMenu_setStrIntAgi(
                armor->strength, armor->intelligence, armor->agility, 1);
            vs_mainMenu_equipmentSubtype = 0x10;
            vs_mainMenu_strIntAgi[1].strength = armor->strength;
            vs_mainMenu_strIntAgi[1].intelligence = armor->intelligence;
            vs_mainMenu_strIntAgi[1].agility = armor->agility;
        }
    } else if (var_s2 & arg0) {
        func_800FD700(D_8010BD7C[temp_v1]);
    }
}

static int _initUiArmor(int arg0)
{
    static int D_8010BC74;
    static char D_8010BC78;
    static char D_8010BC79;

    char** sp10;
    int var_s4;
    int i;
    char* temp_v0;
    int itemId;
    int s0_2;
    vs_battle_inventoryArmor* var_s2;

    var_s2 = NULL;
    if (arg0 != 0) {
        D_8010BC79 = arg0;
        _initMenuHeader(arg0 + 0xA);
        D_8010BC78 = 0;
        return 0;
    }

    itemId = D_8010BD7C[D_8010BC79 - 1];
    if (itemId != 0) {
        var_s2 = &vs_battle_inventory.armor[itemId - 1];
    }

    switch (D_8010BC78) {
    case 0:
        if (vs_mainmenu_ready() != 0) {
            s0_2 = itemId;
            temp_v0 = vs_main_allocHeapR(0x72CU);
            sp10 = (char**)(temp_v0 + 0x6A4);
            if (var_s2 == NULL) {
                sp10[0] = (char*)&vs_mainMenu_menu12Text[VS_MENU12_BIN_OFFSET_armor];
                sp10[1] =
                    (char*)&vs_mainMenu_menu12Text[VS_MENU12_BIN_OFFSET_selectArmor];
                *vs_battle_rowTypeBuf = 1;
            } else {
                vs_mainMenu_setAccessoryUi(var_s2, sp10, vs_battle_rowTypeBuf, temp_v0);
            }

            *_availableItems = s0_2;
            var_s4 = 1;

            for (i = 0; i < 16; ++i) {
                itemId = D_800619D8.unk0[i + 0x30];
                if ((itemId != 0) && (itemId != D_8010BD7C[0])
                    && (itemId != D_8010BD7C[1])) {
                    var_s2 = &vs_battle_inventory.armor[itemId - 1];
                    if (var_s2->category != 7) {
                        vs_mainMenu_setAccessoryUi(var_s2, sp10 + var_s4 * 2,
                            &vs_battle_rowTypeBuf[var_s4], temp_v0 + var_s4 * 0x60);
                        if (!((D_8010BB30[_workshopFlags] >> var_s2->material) & 1)) {
                            sp10[var_s4 * 2 + 1] = (char*)&vs_mainMenu_menu12Text
                                [VS_MENU12_BIN_OFFSET_invalidArmorMaterial];
                            vs_battle_rowTypeBuf[var_s4] |= 1;
                        }
                        if (var_s2->bodyPart != 0) {
                            vs_battle_rowTypeBuf[var_s4] |= 0xCA00;
                        }
                        _availableItems[var_s4] = itemId;
                        ++var_s4;
                    }
                }
            }
            _populateItemsList(var_s4, sp10, vs_battle_rowTypeBuf);
            vs_main_freeHeapR(temp_v0);
            D_8010BC78 = 1;
        }
        break;
    case 1:
        itemId = _availableItems[_itemsListWindow + _itemsListSelection];
        if (itemId != 0) {
            func_800FD700(itemId);
        } else {
            vs_mainMenu_resetStats();
        }
        vs_mainMenu_printInformation(
            _itemsListSelection + _itemsListWindow, _itemsListState);
        _navigateItemsList(2);
        D_8010BC74 = _getSelectedRow() + 1;
        if (D_8010BC74 != 0) {
            vs_mainMenu_clearMenuExcept(vs_mainMenu_menuItemIds_none);
            if (D_8010BC74 == -2) {
                return -2;
            }
            if (D_8010BC74 > 0) {
                D_8010BC74 = _availableItems[D_8010BC74 - 1];
            }
            D_8010BC78 = 2;
        }
        break;
    case 2:
        if (vs_mainmenu_ready() != 0) {
            return D_8010BC74;
        }
        break;
    }
    return 0;
}

static void _setArmorMenuItem(
    vs_battle_menuItem_t* menuItem, vs_battle_inventoryArmor* armor)
{
    menuItem->icon = armor->category + 14;
    menuItem->material = armor->material;
    menuItem->itemState = armor->bodyPart != 0;
}

static int _combineArmorMenu(int arg0)
{
    static char D_8010BB76 = 0;

    static char state;
    static char D_8010BC7B;
    static char D_8010BC7C;

    char* menuText[2];
    int rowType;
    int itemId;
    int temp_v0_6;
    int i;
    int var_s1;
    char* var_a0_2;
    int i_2;
    vs_battle_inventoryArmor* armor;
    vs_battle_menuItem_t* temp_a0;
    vs_battle_menuItem_t* temp_v0;

    if (arg0 != 0) {
        _pushSelectionHistory(5);
        *(u_short*)D_8010BD7C = 0;
        _initCombineArmor(0);
        D_8010BC7B = 1;
        state = 0;
        return 0;
    }

    var_s1 = 0;
    if (D_8010BD7C[0] != 0) {
        var_s1 = D_8010BD7C[1] > 0;
    }

    D_8010BC7C += 16;

    if (state != 2) {
        D_8010BC7C = 0;
    }

    switch (state) {
    case 0:
        if (vs_mainmenu_ready() == 0) {
            break;
        }
        _initMenuItem(0x497, 0x1C);
        // Fallthrough
    case 1:
        var_s1 = D_8010BD54.id;
        temp_a0 = _initItemRow(2, var_s1);
        if (var_s1 != 0) {
            _setArmorMenuItem(temp_a0, &D_8010BD54);
        }

        for (i = 0; i < 2; ++i) {
            var_s1 = D_8010BD7C[i];
            if (var_s1 != 0) {
                armor = &vs_battle_inventory.armor[var_s1 - 1];
            }
            temp_v0 = vs_battle_setMenuItem(i + 11, 334, 34 + i * 16, 151, 0,
                var_s1 == 0 ? (char*)&vs_mainMenu_menu12Text[VS_MENU12_BIN_OFFSET_armor]
                            : vs_mainMenu_itemNames[armor->id]);
            temp_v0->state = 2;
            temp_v0->targetX = 169;

            if (var_s1 == 0) {
                temp_v0->unkA = 1;
            } else {
                _setArmorMenuItem(temp_v0, armor);
            }
        }

        state = 2;
        break;
    case 2:
        if (vs_mainmenu_ready() != 0) {
            if (!(vs_main_buttonsPressed.all & PADRup)) {
                if (var_s1 != 0) {
                    _drawOk(2, D_8010BC7C);
                }
                if (vs_main_buttonsPressed.all & PADRdown) {
                    int temp_v0_2 = _popSelectionHistory(5);
                    if (temp_v0_2 != 0) {
                        vs_battle_playMenuLeaveSfx();
                        D_8010BC7B = temp_v0_2;
                        D_8010BD7C[temp_v0_2 - 1] = 0;
                        _initCombineArmor(temp_v0_2);
                        temp_v0 = vs_battle_setMenuItem(temp_v0_2 + 10, 169,
                            (temp_v0_2 * 16) + 18, 151, 0,
                            (char*)&vs_mainMenu_menu12Text[VS_MENU12_BIN_OFFSET_armor]);
                        temp_v0->selected = 1;
                        temp_v0->unkA = 1;
                        var_s1 = D_8010BD54.id;
                        temp_a0 = _setItemRow(2, var_s1);
                        if (var_s1 != 0) {
                            _setArmorMenuItem(temp_a0, &D_8010BD54);
                        }
                        break;
                    }
                    return _leaveItemSlotSelection(1);
                }
                if (vs_main_buttonsPressed.all & PADstart) {
                    if (var_s1 != 0) {
                        vs_battle_playMenuSelectSfx();
                        vs_battle_getMenuItem(D_8010BC7B + 10)->selected = 0;
                        D_8010BC7B = 3;
                        state = 4;
                        _initCombineArmor(3);
                        return 0;
                    }
                }
                i_2 = D_8010BC7B;
                if (vs_main_buttonsPressed.all & PADRright) {
                    if (i_2 == 0) {
                        func_800C02E0();
                    } else {
                        vs_battle_playMenuSelectSfx();
                        if (i_2 == 3) {
                            state = 4;
                        } else {
                            vs_mainMenu_clearMenuExcept(vs_mainMenu_menuItemIds_none);
                            _initUiArmor(i_2);
                            state = 3;
                        }
                        break;
                    }
                }
                if (vs_main_buttonRepeat & PADLup) {
                    if (i_2 == 0) {
                        i_2 = var_s1 + 2;
                    } else {
                        --i_2;
                    }
                }
                if (vs_main_buttonRepeat & PADLdown) {
                    if (i_2 == (var_s1 + 2)) {
                        i_2 = 0;
                    } else {
                        ++i_2;
                    }
                }

                if (i_2 != D_8010BC7B) {
                    vs_battle_playMenuChangeSfx();
                    D_8010BC7B = i_2;
                    _initCombineArmor(D_8010BC7B);
                }
                vs_battle_rowTypeBuf[0] = D_8010BD54.id < 1;

                for (var_s1 = 1; var_s1 < 3; ++var_s1) {
                    vs_battle_getMenuItem(var_s1 + 10)->selected = var_s1 == D_8010BC7B;
                    vs_battle_rowTypeBuf[var_s1] = D_8010BD7C[var_s1 - 1] == 0;
                }

                vs_battle_rowTypeBuf[3] = 1;
                vs_mainMenu_printInformation(i_2, 16);
                menuText[1] =
                    (char*)&vs_mainMenu_menu12Text[VS_MENU12_BIN_OFFSET_selectArmor];
                switch (i_2) {
                case 0:
                    if (D_8010BD54.id != 0) {
                        vs_mainMenu_setAccessoryUi(
                            &D_8010BD54, menuText, &rowType, vs_battle_stringBuf);
                    }
                    break;
                case 1:
                case 2:
                    var_s1 = D_8010BD7C[i_2 - 1];
                    if (var_s1 != 0) {
                        vs_mainMenu_setAccessoryUi(&vs_battle_inventory.armor[var_s1 - 1],
                            menuText, &rowType, vs_battle_stringBuf);
                    }
                    break;
                case 3:
                    menuText[1] =
                        (char*)&vs_mainMenu_menu12Text[VS_MENU12_BIN_OFFSET_pressOk];
                    break;
                }
                vs_mainmenu_setMessage((char*)menuText[1]);
                var_s1 = (((i_2 * 16) + 10) << 0x10) | 0x9B;
                if (i_2 == 0) {
                    var_s1 -= 14;
                }
                if (i_2 == 3) {
                    var_s1 += 0xFFFC0000;
                }
                D_8010BB76 = func_800FFCDC(D_8010BB76, var_s1);
                break;
            }
            return _leaveItemSlotSelection(1);
        }
        D_8010BC7C = 0;
        break;
    case 3:
        itemId = _initUiArmor(0);
        if (itemId == 0) {
            break;
        }
        if (itemId == -2) {
            return _leaveItemSlotSelection(1);
        }
        if (itemId > 0) {
            var_s1 = D_8010BC7B - 1;
            if (itemId == D_8010BD7C[D_8010BC7B - 1]) {
                D_8010BD7C[D_8010BC7B - 1] = 0;
                _popSelectionHistory(var_s1);
            } else {
                D_8010BD7C[D_8010BC7B - 1] = itemId;
                _pushSelectionHistory(var_s1);
                D_8010BC7B = (D_8010BC7B + 1);
                if (var_s1 == 1) {
                    if (D_8010BD7C[0] == 0) {
                        D_8010BC7B = var_s1;
                    }
                }
            }
            _initCombineArmor(D_8010BC7B);
        }
        state = 1;
        break;
    case 4:
        vs_battle_renderEquipStats(2);
        _confirmCombine(2);

        var_s1 = 0;

        for (i = 0; i < 2; ++i) {
            var_s1 |= vs_battle_inventory.armor[D_8010BD7C[i] - 1].bodyPart;
        }
        if (var_s1 == 0) {
            var_a0_2 =
                (char*)&vs_mainMenu_menu12Text[VS_MENU12_BIN_OFFSET_attachmentConfirm];
        } else {
            var_a0_2 =
                (char*)&vs_mainMenu_menu12Text[VS_MENU12_BIN_OFFSET_cancelCombineConfirm];
        }
        vs_mainmenu_setMessage(var_a0_2);
        state = 5;
        break;
    case 5:
        temp_v0_6 = _confirmCombine(0);

        if (temp_v0_6 == 0) {
            break;
        }

        switch (temp_v0_6) {
        case 1:
            vs_main_playSfxDefault(0x7E, 0x18);

            func_800FFBC8();
            vs_mainMenu_drawClassAffinityType(-1);
            vs_mainMenu_drawDpPpbars(4);
            vs_mainMenu_clearMenuExcept(vs_mainMenu_menuItemIds_none);
            vs_mainMenu_menuItemLeaveLeft(0);
            for (i = 0; i < 2; ++i) {
                armor = &vs_battle_inventory.armor[D_8010BD7C[i] - 1];
                var_s1 = armor->bodyPart;
                if (var_s1 != 0) {
                    vs_battle_equipArmor(var_s1 - 1, NULL);
                    armor->bodyPart = 0;
                }
                vs_mainMenu_initItem(4, D_8010BD7C[i]);
            }
            itemId = D_8010BD7C[0];
            armor = &vs_battle_inventory.armor[itemId - 1];
            vs_battle_copyAligned(armor, &D_8010BD54, sizeof *armor);
            armor->index = itemId;
            vs_mainMenu_rebuildInventory(4);
            return 1;
        case 2:
            vs_battle_playMenuLeaveSfx();
            vs_battle_renderEquipStats(1);
            state = temp_v0_6;
            break;
        case 3:
            return _leaveItemSlotSelection(1);
        }
        break;
    }
    return 0;
}

static int _countArmor(int arg0)
{
    int i;

    vs_battle_inventoryArmor* armor = vs_battle_inventory.armor;
    int count = 0;

    if (arg0 == 2) {
        for (i = 0; i < 16; ++i, ++armor) {
            int var_v1 = 0;
            if (armor->id != 0) {
                var_v1 = armor->category != 7;
            }
            count += var_v1;
        }
    } else {
        count = vs_mainMenu_getItemCount((arg0 * 2) | 1, NULL);
    }
    return count;
}

static int _combineTopMenu(int arg0)
{
    static int (*combineMenus[])(
        int) = { _combineBladeMenu, _combineShieldMenu, _combineArmorMenu };

    static char state;
    static char forceNoCursorMemory;

    char* text[6];
    int selectedRow;
    int i;
    int temp_s1;

    if (arg0 != 0) {
        forceNoCursorMemory = 1;
        func_800FA92C(5, 1);
        state = 0;
        return 0;
    }

    switch (state) {
    case 0:
        if (vs_mainmenu_ready() != 0) {
            for (i = 0; i < 3; ++i) {
                int count = _countArmor(i);
                text[i * 2] = (char*)&vs_mainMenu_menu12Text
                    [vs_mainMenu_menu12Text[i + VS_MENU12_BIN_INDEX_blade]];
                text[i * 2 + 1] =
                    count < 2 ? (char*)&vs_mainMenu_menu12Text[vs_mainMenu_menu12Text
                                        [VS_MENU12_BIN_INDEX_noItems - (count * 4)]]
                              : (char*)&vs_mainMenu_menu12Text[vs_mainMenu_menu12Text
                                        [i + VS_MENU12_BIN_INDEX_combineBlades]];
                vs_battle_rowTypeBuf[i] = count < 2;
            }

            temp_s1 = vs_main_settings.cursorMemory;
            if (forceNoCursorMemory == 0) {
                vs_main_settings.cursorMemory = 1;
            }
            forceNoCursorMemory = 0;
            vs_mainmenu_setMenuRows(3, 0x23D, text, vs_battle_rowTypeBuf);
            vs_main_settings.cursorMemory = temp_s1;
            state = 1;
        }
        break;
    case 1:
        vs_mainMenu_printInformation(func_801008B0(), D_801023D0);
        selectedRow = vs_mainmenu_getSelectedRow();
        i = selectedRow + 1;
        if (i != 0) {
            if (i < 0) {
                vs_mainMenu_clearMenuExcept(0);
                return i;
            }
            vs_mainMenu_clearMenuExcept(vs_mainMenu_menuItemIds_none);
            combineMenus[selectedRow](1);
            _loadSyd(i);
            state = selectedRow + 2;
        }
        break;
    case 2:
    case 3:
    case 4:
        if (_loadSyd(0) != 0) {
            i = combineMenus[state - 2](0);
            if (i != 0) {
                vs_main_freeHeapR(_sydData);
                _sydData = NULL;
                if (i == -1) {
                    state = 5;
                    break;
                }
                return i;
            }
        }
        break;
    case 5:
        if (vs_mainmenu_ready() != 0) {
            func_800FFBC8();
            _addMenuTitle(0, VS_MENU12_BIN_OFFSET_setup);
            _addMenuTitle(15, VS_MENU12_BIN_OFFSET_combine);
            state = 0U;
        }
        break;
    }
    return 0;
}

int vs_menuC_exec(char* state)
{
    static char D_8010BC7F;

    char* menuText[12];
    int i;
    int selectedRow;
    vs_battle_menuItem_t* menuItem;

    switch (*state) {
    case 0:
        D_8010BC7F = 1;
        // fallthrough
    case 1:

        for (i = 0; i < 7; ++i) {
            vs_mainMenu_rebuildInventory(i);
        }
        func_80100414(0x7FE, 0x80);
        menuItem = vs_battle_getMenuItem(0);
        if ((menuItem->state != 1) || (menuItem->initialX != 180)) {
            _addMenuTitle(0, VS_MENU12_BIN_OFFSET_setup);
        }
        *state = 2;
        break;
    case 2:
        if (vs_mainmenu_ready() != 0) {
            for (i = 0; i < 6; ++i) {
                menuText[i * 2] = (char*)&vs_mainMenu_menu12Text
                    [vs_mainMenu_menu12Text[i * 2 + VS_MENU12_BIN_INDEX_assembleWeapons]];
                menuText[i * 2 + 1] =
                    (char*)&vs_mainMenu_menu12Text[vs_mainMenu_menu12Text
                            [i * 2 + VS_MENU12_BIN_INDEX_assembleWeaponsDesc]];
                vs_battle_rowTypeBuf[i] = 0;
            }

            i = vs_mainMenu_getItemCount(0, 0);
            if (i == 8) {
                menuText[1] =
                    (char*)&vs_mainMenu_menu12Text[VS_MENU12_BIN_OFFSET_weaponsFull];
                vs_battle_rowTypeBuf[0] = 1;
            }
            if (i == 0) {
                menuText[7] =
                    (char*)&vs_mainMenu_menu12Text[VS_MENU12_BIN_OFFSET_noWeapons];
                vs_battle_rowTypeBuf[3] = 1;
            }
            _workshopFlags = vs_battle_getWorkshopFlags();
            if (!_workshopFlags) {
                for (i = 3; i != 0;) {
                    if (++i == 6) {
                        i = 0;
                    }
                    menuText[i * 2 + 1] = (char*)&vs_mainMenu_menu12Text
                        [VS_MENU12_BIN_OFFSET_notInWorkshop];
                    vs_battle_rowTypeBuf[i] = 1;
                }
            }
            i = vs_main_settings.cursorMemory;
            if (D_8010BC7F == 0) {
                vs_main_settings.cursorMemory = 1;
            }
            D_8010BC7F = 0;
            vs_mainmenu_setMenuRows(6, 0x135, menuText, vs_battle_rowTypeBuf);
            vs_main_settings.cursorMemory = i;
            *state = 3;
        }
        break;
    case 3:
        vs_mainMenu_printInformation(func_801008B0(), D_801023D0);
        selectedRow = vs_mainmenu_getSelectedRow();
        i = selectedRow + 1;
        if (i != 0) {
            if (i < 0) {
                vs_mainMenu_clearMenuExcept(vs_mainMenu_menuItemIds_none);
                if (i == -2) {
                    D_800F514C = 0;
                    *state = 0xB;
                } else {
                    vs_battle_menuState.currentState = vs_battle_menuState.returnState;
                    vs_battle_menuState.returnState = 0;
                    D_800F4EA0 &= ~0x200;
                    *state = 0;
                }
            } else {
                switch (selectedRow) {
                case 0:
                    _assembleMenu(1);
                    *state = 4;
                    break;
                case 1:
                    _attachGemsTopMenu(1);
                    *state = 5;
                    break;
                case 2:
                    _disassembleTopMenu(1);
                    *state = 6;
                    break;
                case 3:
                    _renameWeaponMenu(1);
                    *state = 7;
                    break;
                case 4:
                    _repairMenu(1);
                    *state = 8;
                    break;
                case 5:
                    _combineTopMenu(1);
                    *state = 9;
                    break;
                }
            }
        }
        break;
    case 4:
        i = _assembleMenu(0);
        if (i != 0) {
            if (i != -2) {
                *state = 0xA;
                if (i == 1) {
                    vs_battle_menuState.currentState = 8;
                    func_800FFBA8();
                } else {
                    func_800FFBC8();
                }
            } else {
                *state = 0xB;
            }
        }
        break;
    case 5:
        i = _attachGemsTopMenu(0);
        if (i != 0) {
            if (i == -2) {
                *state = 0xB;
            } else {
                *state = 0xA;
            }
        }
        break;
    case 6:
        i = _disassembleTopMenu(0);
        if (i != 0) {
            if (i == -2) {
                *state = 0xB;
            } else {
                *state = 0xA;
            }
        }
        break;
    case 7:
        i = _renameWeaponMenu(0);
        if (i != 0) {
            if (i != -2) {
                *state = 0xA;
                if (i == 1) {
                    vs_battle_menuState.currentState = 8;
                }
            } else {
                *state = 0xB;
            }
        }
        break;
    case 8:
        i = _repairMenu(0);
        if (i != 0) {
            if (i == -2) {
                *state = 0xB;
            } else {
                *state = 0xA;
            }
        }
        break;
    case 9:
        i = _combineTopMenu(0);
        if (i != 0) {
            if (i == -2) {
                *state = 0xB;
            } else {
                *state = 0xA;
            }
        }
        break;
    case 10:
        func_800FFBC8();
        if (vs_mainmenu_ready() != 0) {
            *state = 1;
        }
        break;
    case 11:
        vs_battle_menuState.currentState = vs_battle_menuState.returnState;
        vs_battle_menuState.returnState = 1;
        D_800F4EA0 &= ~0x200;
        *state = 0;
        break;
    }
    return 0;
}

static void _setClassAffinities(signed char* first, signed char* second,
    signed char* result, int materialsDifferent, int setAffinities)
{
    static char _classFactorLookup[][6] = { { 2, 0, 1, 1, 1, 0 }, { 0, 2, 0, 1, 1, 1 },
        { 1, 0, 2, 0, 1, 1 }, { 1, 1, 0, 2, 0, 1 }, { 1, 1, 1, 0, 2, 0 },
        { 0, 1, 1, 1, 0, 2 } };

    static char _affinityFactorLookup[][7] = { { 2, 1, 1, 1, 1, 1, 1 },
        { 1, 2, 1, 0, 1, 1, 1 }, { 1, 1, 2, 1, 0, 1, 1 }, { 1, 0, 1, 2, 1, 1, 1 },
        { 1, 1, 0, 1, 2, 1, 1 }, { 1, 1, 1, 1, 1, 2, 0 }, { 1, 1, 1, 1, 1, 0, 2 } };

    static short _sameMaterialStatFactors[] = { 4, 6, 8 };
    static short _differentMaterialStatFactors[] = { 3, 5, 7 };

    short statSum;
    short statValue;
    int i;
    int nStats;
    u_int firstMaxStat;
    u_int secondMaxStat;
    signed char firstMaxVal;
    signed char secondMaxVal;
    signed char minStatVal;
    signed char maxStatValue;
    short factorLookup;

    nStats = 6;
    if (setAffinities != 0) {
        nStats = 7;
    }
    secondMaxVal = -128;
    firstMaxVal = -128;
    maxStatValue = -128;
    secondMaxStat = 0;
    firstMaxStat = 0;

    for (i = 0; i < nStats; ++i) {
        if (firstMaxVal < first[i]) {
            firstMaxVal = first[i];
            firstMaxStat = i;
        }
        if (maxStatValue < first[i]) {
            maxStatValue = first[i];
        }
    }

    for (i = 0; i < nStats; ++i) {
        if (secondMaxVal < second[i]) {
            secondMaxVal = second[i];
            secondMaxStat = i;
        }
        if (maxStatValue < second[i]) {
            maxStatValue = second[i];
        }
    }

    minStatVal = 127;

    for (i = 0; i < nStats; ++i) {
        if (first[i] < minStatVal) {
            minStatVal = first[i];
        }
    }

    for (i = 0; i < nStats; ++i) {
        if (second[i] < minStatVal) {
            minStatVal = second[i];
        }
    }

    for (i = 0; i < nStats; ++i) {
        if ((first[i] == maxStatValue) || ((second[i] == maxStatValue))) {
            result[i] = maxStatValue;
        } else if ((first[i] == minStatVal) || (second[i] == minStatVal)) {
            result[i] = minStatVal;
        } else {
            if (setAffinities == 0) {
                factorLookup = _classFactorLookup[firstMaxStat][secondMaxStat];
            } else {
                factorLookup = _affinityFactorLookup[firstMaxStat][secondMaxStat];
            }
            statSum = first[i] + second[i];
            if (materialsDifferent == 0) {
                statValue = (statSum * _sameMaterialStatFactors[factorLookup]) / 10;
            } else {
                statValue =
                    (statSum * *(factorLookup + _differentMaterialStatFactors)) / 10;
            }
            if (statValue > 100) {
                statValue = 100;
            } else if (statValue < -100) {
                statValue = -100;
            }
            result[i] = statValue;
        }
    }
}

static void _setTypeValues(
    signed char* first, signed char* second, signed char* result, int materialsDifferent)
{
    static short _sameMaterialTypeFactors[] = { 6, 8 };
    static short _differentMaterialTypeFactors[] = { 4, 6 };

    short typeValue;
    short typeValueSum;
    int sameMaxType;
    int i;
    u_int firstMaxType;
    u_int secondMaxType;
    signed char firstMaxVal;
    signed char secondMaxVal;

    secondMaxVal = -128;
    firstMaxVal = -128;
    secondMaxType = 1;
    firstMaxType = 1;

    for (i = 1; i < 4; ++i) {
        if (firstMaxVal < first[i]) {
            firstMaxVal = first[i];
            firstMaxType = i;
        }
    }

    for (i = 1; i < 4; ++i) {
        if (secondMaxVal < second[i]) {
            secondMaxVal = second[i];
            secondMaxType = i;
        }
    }

    for (i = 1; i < 4; ++i) {
        sameMaxType = firstMaxType == secondMaxType;
        typeValueSum = first[i] + second[i];
        if (materialsDifferent == 0) {
            typeValue = (typeValueSum * _sameMaterialTypeFactors[sameMaxType]) / 10;
        } else {
            typeValue = (typeValueSum * _differentMaterialTypeFactors[sameMaxType]) / 10;
        }
        if (typeValue > 100) {
            typeValue = 100;
        } else if (typeValue < -100) {
            typeValue = -100;
        }
        result[i] = typeValue;
    }
}

typedef struct {
    u_long combinationsOffset;
    u_long materialsOffset;
    u_long initDataOffset;
    char data[0];
} _syd;

static char* _combinationResults;
static char* _materialResults;
static void* _bladeCombinationInitData;

static vs_battle_inventoryBlade* _combineBlades(vs_battle_inventoryBlade* first,
    vs_battle_inventoryBlade* second, vs_battle_inventoryBlade* result, void* sydData)
{
    struct {
        char subId;
        char wepId;
        char category;
        char damageType;
        char costType;
        char cost;
        char unk6;
        char unk7;
        char strength;
        char intelligence;
        char agility;
        char _;
        vs_battle_range_t range;
    }* info;

    _combinationResults = sydData + ((_syd*)sydData)->combinationsOffset;
    _materialResults = sydData + ((_syd*)sydData)->materialsOffset;
    _bladeCombinationInitData = sydData + ((_syd*)sydData)->initDataOffset;

    vs_main_memcpy(result, first, sizeof(*result));

    result->material = _materialResults[(first->material - 3) * 500 + first->category * 50
                                        + (second->material - 3) * 10 + second->category];
    result->subId = _combinationResults[(first->id * 96) + second->id];
    result->id = result->subId;
    info = _bladeCombinationInitData + (result->id * 16);
    result->wepId = info->wepId;
    result->category = info->category;
    result->cost = info->cost;
    result->damageType = info->damageType & 3;
    result->costType = info->costType & 7;
    result->unk12 = info->unk6;
    result->range = info->range;
    result->strength = info->strength + D_8004EDDC[result->material][24];
    result->intelligence = info->intelligence + D_8004EDDC[result->material][26];
    result->agility = info->agility + D_8004EDDC[result->material][28];
    result->maxDp = result->currentDp = (first->maxDp + second->maxDp) >> 1;
    result->maxPp = (first->maxPp + second->maxPp) >> 1;
    result->currentPp = (first->currentPp + second->currentPp) >> 1;

    if (first->material == second->material) {
        _setClassAffinities(first->classes, second->classes, result->classes, 0, 0);
        _setClassAffinities(
            first->affinities, second->affinities, result->affinities, 0, 1);
    } else {
        _setClassAffinities(first->classes, second->classes, result->classes, 1, 0);
        _setClassAffinities(
            first->affinities, second->affinities, result->affinities, 1, 1);
    }
    return result;
}

typedef struct {
    char subId;
    char wepId;
    char category;
    char gemSlots;
    char strength;
    char intelligence;
    char agility;
    char _;
} _armorInfo;

static _armorInfo* _shieldCombinationInitData;

static vs_battle_inventoryArmor* _combineShields(vs_battle_inventoryArmor* first,
    vs_battle_inventoryArmor* second, vs_battle_inventoryArmor* result, void* sydData)
{
    _armorInfo* info;

    _combinationResults = sydData + ((_syd*)sydData)->combinationsOffset;
    _materialResults = sydData + ((_syd*)sydData)->materialsOffset;
    _shieldCombinationInitData = sydData + ((_syd*)sydData)->initDataOffset;

    vs_main_memcpy(result, first, sizeof *result);

    result->material = _materialResults[(first->material * 8) + second->material];
    result->subId = _combinationResults[(first->subId * 17) + second->subId];
    result->id = result->subId + 126;
    info = &_shieldCombinationInitData[result->subId];
    result->wepId = info->wepId;
    result->category = info->category;
    result->gemSlots = info->gemSlots;
    result->strength = info->strength + D_8004EDDC[result->material][24];
    result->intelligence = info->intelligence + D_8004EDDC[result->material][26];
    result->agility = info->agility + D_8004EDDC[result->material][28];
    result->maxDp = result->currentDp = (first->maxDp + second->maxDp) / 2;
    result->maxPp = ((first->maxPp + second->maxPp) >> 1);
    result->currentPp = ((first->currentPp + second->currentPp) >> 1);
    if (first->material == second->material) {
        _setClassAffinities(first->classes, second->classes, result->classes, 0, 0);
        _setClassAffinities(
            first->affinities, second->affinities, result->affinities, 0, 1);
        _setTypeValues(first->types, second->types, result->types, 0);
    } else {
        _setClassAffinities(first->classes, second->classes, result->classes, 1, 0);
        _setClassAffinities(
            first->affinities, second->affinities, result->affinities, 1, 1);
        _setTypeValues(first->types, second->types, result->types, 1);
    }
    return result;
}

static _armorInfo* _combinationInitData;

static vs_battle_inventoryArmor* _combineArmor(vs_battle_inventoryArmor* first,
    vs_battle_inventoryArmor* second, vs_battle_inventoryArmor* result, void* sydData)
{
    _armorInfo* info;

    _combinationResults = sydData + ((_syd*)sydData)->combinationsOffset;
    _materialResults = sydData + ((_syd*)sydData)->materialsOffset;
    _combinationInitData = sydData + ((_syd*)sydData)->initDataOffset;

    vs_main_memcpy(result, first, sizeof *result);

    result->material = _materialResults[first->material * 128 + (first->category - 2) * 32
                                        + second->material * 4 + (second->category - 2)];
    result->subId = _combinationResults[(first->subId - 16) * 65 + (second->subId - 16)];
    result->id = result->subId + 126;
    info = &_combinationInitData[result->subId];
    result->category = info->category;
    result->strength = info->strength + D_8004EDDC[result->material][24];
    result->intelligence = info->intelligence + D_8004EDDC[result->material][26];
    result->agility = info->agility + D_8004EDDC[result->material][28];
    result->maxDp = result->currentDp = (first->maxDp + second->maxDp) / 2;
    if (first->material == second->material) {
        _setClassAffinities(first->classes, second->classes, result->classes, 0, 0);
        _setClassAffinities(
            first->affinities, second->affinities, result->affinities, 0, 1);
        _setTypeValues(first->types, second->types, result->types, 0);
    } else {
        _setClassAffinities(first->classes, second->classes, result->classes, 1, 0);
        _setClassAffinities(
            first->affinities, second->affinities, result->affinities, 1, 1);
        _setTypeValues(first->types, second->types, result->types, 1);
    }
    return result;
}
