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

typedef struct {
    char subId;
    char wepId;
    char category;
    char gemSlots;
    char strength;
    char intelligence;
    char agility;
    char unk7;
} _armorInfo;

typedef struct {
    u_long combinationsOffset;
    u_long materialsOffset;
    u_long initDataOffset;
    char data[0];
} _syd;

extern u_long* D_1F800000[];

static void _drawOk(int row, int arg1)
{
    vs_battle_renderTextRawColor("OK", vs_getXY(175, row * 16 + 32),
        ((rsin(arg1 * 8) >> 5) + 64) * 0x10101, D_1F800000[1] - 3);
}

static void _addMenuTitle(int row, int textOffset)
{
    vs_battle_menuItem_t* menuItem;

    int y = 18;
    if (row != 0) {
        y = 34;
    }
    menuItem = vs_battle_setMenuItem(
        row, 320, y, 140, 8, (char*)&vs_mainMenu_menu12Text[textOffset]);
    menuItem->state = 2;
    menuItem->targetX = 180;
    menuItem->selected = 1;
}

static u_char _workshopFlags;
static u_char _combiningItem;
static char _[2] __attribute__((unused));
static u_int D_8010BC84[5];

void func_80102A34(int arg0)
{
    u_int i;
    u_int var_t0;

    var_t0 = 0;
    if (arg0 < 5) {
        for (i = 0; i < 5; ++i) {
            if (var_t0 < D_8010BC84[i]) {
                var_t0 = D_8010BC84[i];
            }
        }

        D_8010BC84[arg0] = var_t0 + 1;
        return;
    }
    vs_battle_rMemzero(D_8010BC84, sizeof D_8010BC84);
}

int func_80102AB8(int arg0)
{
    int i;
    int var_a2 = 0;

    if (arg0 < 5) {
        D_8010BC84[arg0] = 0;
    } else {
        for (i = 0; i < 5; ++i) {
            if (D_8010BC84[var_a2] < D_8010BC84[i]) {
                var_a2 = i;
            }
        }

        if (D_8010BC84[var_a2] != 0) {
            D_8010BC84[var_a2] = 0;
            return var_a2 + 1;
        }
    }
    return 0;
}

void func_80102B50(int textOffset, int icon)
{
    int a0;
    vs_battle_menuItem_t* menuItem = vs_battle_setMenuItem(
        32, -164, 18, 164, 8, (char*)&vs_mainMenu_menu12Text[textOffset]);
    menuItem->state = 5;
    menuItem->targetX = 0x10;
    menuItem->selected = 1;
    menuItem->icon = icon;

    vs_mainMenu_resetStats();
    a0 = 7;
    if (icon == 24) {
        vs_mainMenu_setRangeRisk(0, 0, 0, 1);
        a0 = 3;
    }

    func_800FBBD4(a0);

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

void _disassembleWeapon(int weaponIndex)
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

    vs_battle_inventory.grips[weapon->grip - 1].combinedWeaponIndex = 0;
    vs_battle_inventory.blades[weapon->blade - 1].combinedWeaponIndex = 0;

    index = weapon->index;
    vs_battle_rMemzero(weapon, sizeof *weapon);
    weapon->index = index;

    vs_mainMenu_rebuildInventory(0);
}

void _assembleWeapon(int bladeIndex, int gripIndex, int gemInfo)
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
    blade->combinedWeaponIndex = weaponIndex;
    grip->combinedWeaponIndex = weaponIndex;

    for (i = 0; i < gemSlots; ++i) {
        gemInfo = weapon->gems[i];
        if (gemInfo != 0) {
            vs_battle_inventory.gems[gemInfo - 1].setItemIndex = weaponIndex;
        }
    }

    memset(weapon->name, vs_char_terminator, sizeof weapon->name);
    vs_mainMenu_rebuildInventory(0);
}

void _disassembleShield(int index)
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

int _isValidGrip(vs_battle_inventoryBlade* blade, vs_battle_inventoryGrip* grip)
{
    static u_short _validGripFlags[] = { 0, 0xE, 0xF0, 0x100, 0x200 };

    if ((blade == NULL) || (grip == NULL)) {
        return 1;
    }
    return (1 << blade->category) & _validGripFlags[grip->category];
}

int func_80103380(int arg0)
{

    vs_battle_playMenuLeaveSfx();
    vs_mainMenu_clearMenuExcept(vs_mainMenu_menuItemIds_none);
    func_800FA810(0);

    if (arg0 != 0) {
        func_800FBBD4(-1);
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

void _populateItemsList(int count, char** text, int* rowTypes)
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
    menuItem->icon = j >> 0x1A;
    menuItem->material = (j >> 0x10) & 7;
    menuItem->selected = 1;
    D_8010BCA3 = (j >> 0x13) & 0x7F;
}

int func_801035E0(void) { return _itemsList == NULL ? _itemsListSelection : -1; }

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
                menuItem->unkD = v0 - 100;
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
                            menuItem->unkD = v1 - 0x64;
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

void func_80103C20(int arg0, int arg1)
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
        func_800FD404(arg0);
        break;
    case 2:
        func_800FD504(arg1);
        break;
    case 3:
        func_800FD270(_combiningItem + 1);
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
        func_80103C20(new_var, new_var2);
    }
}

void func_80103D8C(int arg0)
{
    vs_battle_menuItem_t* menuItem;

    menuItem = vs_battle_getMenuItem(arg0);
    menuItem->state = 4;
    menuItem->targetX = 155;
    menuItem->unk1A = 18;
}

static char D_8010BCA4[64];

static int _assembleBladeMenu(int params)
{
    static int D_8010BBFC;
    static char state;
    static char bladeToAssemble;
    static char gripToAssemble;
    static char _[1] __attribute__((unused));

    int bladeCount;
    int i;
    void* textBuf;
    char** menuText;
    int temp_s0;
    vs_battle_inventoryBlade* blade = NULL;
    vs_battle_inventoryGrip* grip = NULL;

    if (params != 0) {
        bladeToAssemble = params & 0x7F;
        gripToAssemble = (params >> 8);
        func_80103D8C(11);
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
            D_8010BCA4[0] = bladeToAssemble;

            for (i = 0; i < 16; ++i) {

                char(*p)[40] = &D_800619D8.unk0;
                temp_s0 = (*p)[i + 8];

                if ((temp_s0 != 0) && (temp_s0 != bladeToAssemble)) {

                    blade = &vs_battle_inventory.blades[temp_s0 - 1];

                    if (blade->combinedWeaponIndex == 0) {

                        vs_mainMenu_setBladeUi(blade, menuText + bladeCount * 2,
                            &vs_battle_rowTypeBuf[bladeCount], textBuf + bladeCount * 96);

                        if (_isValidGrip(blade, grip) == 0) {
                            menuText[bladeCount * 2 + 1] = (char*)&vs_mainMenu_menu12Text
                                [VS_MENU12_BIN_OFFSET_invalidBlade];
                            vs_battle_rowTypeBuf[bladeCount] |= 1;
                        }

                        D_8010BCA4[bladeCount] = temp_s0;
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
        temp_s0 = D_8010BCA4[_itemsListWindow + _itemsListSelection];
        if (temp_s0 != 0) {
            func_800FD404((int)temp_s0);
        } else {
            func_800FBB8C(3);
            vs_mainMenu_resetStats();
            vs_mainMenu_setRangeRisk(0, 0, 0, 1);
        }

        func_800FF9E4(_itemsListSelection + _itemsListWindow, (int)_itemsListState);
        _navigateItemsList(2);

        D_8010BBFC = func_801035E0() + 1;

        if (D_8010BBFC != 0) {
            vs_mainMenu_clearMenuExcept(vs_mainMenu_menuItemIds_none);
            if (D_8010BBFC == -2) {
                return -2;
            }
            if (D_8010BBFC > 0) {
                D_8010BBFC = D_8010BCA4[D_8010BBFC - 1];
            }
            state = 2;
        }
        break;
    case 2:
        if (vs_mainmenu_ready() != 0) {
            return D_8010BBFC;
        }
        break;
    }
    return 0;
}

int _assembleGripMenu(int params)
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
    int temp_s0;

    vs_battle_inventoryGrip* grip = NULL;
    vs_battle_inventoryBlade* blade = NULL;

    if (params != 0) {
        gripToAssemble = params & 0x7F;
        bladeToAssemble = params >> 8;
        func_80103D8C(0xC);
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
            D_8010BCA4[0] = gripToAssemble;

            for (i = 0; i < 16; ++i) {

                temp_s0 = D_800619D8.unk0[i + 0x18];

                if ((temp_s0 != 0) && (temp_s0 != gripToAssemble)) {

                    grip = &vs_battle_inventory.grips[temp_s0 - 1];

                    if (grip->combinedWeaponIndex == 0) {

                        vs_mainMenu_setGripUi(grip, menuText + gripCount * 2,
                            &vs_battle_rowTypeBuf[gripCount], textBuf + gripCount * 0x60);

                        if (_isValidGrip(blade, grip) == 0) {
                            menuText[gripCount * 2 + 1] = (char*)&vs_mainMenu_menu12Text
                                [VS_MENU12_BIN_OFFSET_invalidGrip];
                            vs_battle_rowTypeBuf[gripCount] |= 1;
                        }

                        D_8010BCA4[gripCount] = temp_s0;
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
        temp_s0 = D_8010BCA4[_itemsListWindow + _itemsListSelection];
        vs_mainMenu_drawDpPpbars(8);

        if (temp_s0 != 0) {
            func_800FD504((int)temp_s0);
        } else {
            func_800FBB8C(4);
            vs_mainMenu_resetStats();
        }

        func_800FF9E4(_itemsListSelection + _itemsListWindow, _itemsListState);
        _navigateItemsList(2);

        D_8010BC04 = func_801035E0() + 1;

        if (D_8010BC04 != 0) {
            vs_mainMenu_clearMenuExcept(vs_mainMenu_menuItemIds_none);
            if (D_8010BC04 == -2) {
                return -2;
            }
            if (D_8010BC04 > 0) {
                D_8010BC04 = D_8010BCA4[D_8010BC04 - 1];
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
    int temp_s0;
    int gemCount;
    void* textBuf;
    char** menuText;

    vs_battle_inventoryGem* gem = NULL;

    if (params != 0) {
        i = params & 0x7;
        gemCount = params & 0xF8;
        gemToAttach = params >> gemCount;
        func_80103D8C(i + 10);
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
            D_8010BCA4[0] = gemToAttach;

            for (i = 0; i < 48; ++i) {

                temp_s0 = D_800619D8.unk0[i + 0x40];

                if ((temp_s0 != 0) && (temp_s0 != gemToAttach)) {

                    gem = &vs_battle_inventory.gems[temp_s0 - 1];

                    if (gem->setItemIndex == 0) {
                        vs_mainMenu_setGemUi(gem, menuText + gemCount * 2,
                            &vs_battle_rowTypeBuf[gemCount], textBuf + gemCount * 96);
                        D_8010BCA4[gemCount] = temp_s0;
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
        temp_s0 = D_8010BCA4[_itemsListWindow + _itemsListSelection];
        vs_mainMenu_drawDpPpbars(8);
        if (temp_s0 != 0) {
            func_800FD878(temp_s0);
        } else {
            func_800FBB8C(3);
            vs_mainMenu_resetStats();
        }

        func_800FF9E4(_itemsListSelection + _itemsListWindow, _itemsListState);
        _navigateItemsList(2);

        D_8010BC0C = func_801035E0() + 1;

        if (D_8010BC0C != 0) {
            vs_mainMenu_clearMenuExcept(vs_mainMenu_menuItemIds_none);
            if (D_8010BC0C == -2) {
                return -2;
            }
            if (D_8010BC0C > 0) {
                D_8010BC0C = D_8010BCA4[D_8010BC0C - 1];
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

int func_80104868(void)
{
    _disassembleWeapon(_combiningItem);
    return func_80103380(1);
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
    int temp_s1;
    int submenuResult;
    int temp_v1;
    int i;
    int gemSlots;
    vs_battle_inventoryBlade* blade;
    vs_battle_inventoryGrip* grip;
    vs_battle_menuItem_t* menuItem;

    if (arg0 != 0) {
        func_800C8E04(1);
        func_80102A34(5);
        vs_mainMenu_clearMenuExcept(vs_mainMenu_menuItemIds_none);
        _combiningItem = func_800FEB08(0, 0);
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

    temp_s1 = gripToAssemble != 0;

    if (temp_s1 != 0) {
        grip = &vs_battle_inventory.grips[gripToAssemble - 1];
    }

    itemInfo &= temp_s1;

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
            func_80102B50(0x111, 0x18);
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

                    temp_s1 = func_80102AB8(5);
                    _disassembleWeapon(_combiningItem);

                    switch (temp_s1) {
                    case 0:
                        return func_80104868();
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
                        gemInfo[temp_s1 - 3] = 0;
                        _assembleWeapon(
                            bladeToAssemble - 1, gripToAssemble - 1, *(int*)gemInfo);
                        itemInfo = VS_MENU12_BIN_OFFSET_gems;
                        break;
                    }

                    vs_battle_playMenuLeaveSfx();
                    selectedOption = temp_s1 - 1;
                    menuItem = vs_battle_setMenuItem(temp_s1 + 10,
                        temp_s1 < 3 ? 162 : 169, (temp_s1 * 16) + 18, 151, 0,
                        (char*)&vs_mainMenu_menu12Text[itemInfo]);
                    menuItem->selected = 1;
                    menuItem->unkA = 1;
                    func_80103C20(bladeToAssemble, gripToAssemble);
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

                func_800FF9E4(selectedOption, 16);

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
                    temp_s1 = gemInfo[selectedOption - 2];
                    if (temp_s1 != 0) {
                        vs_mainMenu_setGemUi(&vs_battle_inventory.gems[temp_s1 - 1],
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
                return func_80104868();
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
                    func_80102AB8(0);
                    _disassembleWeapon(_combiningItem);
                } else {
                    bladeToAssemble = submenuResult;
                    func_80102A34(0);
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
        return func_80104868();
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
                    gripToAssemble = 0U;
                    func_80102AB8(1);
                    _disassembleWeapon(_combiningItem);
                } else {
                    gripToAssemble = submenuResult;
                    func_80102A34(1);
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
        return func_80104868();
    case 5:
        submenuResult = _attachGem(0);
        if (submenuResult == 0) {
            break;
        }
        if (submenuResult != -2) {
            if (submenuResult > 0) {
                if (submenuResult == gemInfo[selectedOption - 2]) {
                    gemInfo[selectedOption - 2] = 0;
                    func_80102AB8(selectedOption);
                } else {
                    gemInfo[selectedOption - 2] = submenuResult;
                    func_80102A34(selectedOption);
                    ++selectedOption;
                }
            }
            _assembleWeapon(bladeToAssemble - 1, gripToAssemble - 1, *(int*)gemInfo);
            _assembleBladeMenuHeader(bladeToAssemble * 0x10 | (gripToAssemble << 0xA));
            state = 1;
            break;
        }
        return func_80104868();
    case 6:
        vs_battle_renderEquipStats(2);
        _confirmCombine(3);
        vs_mainmenu_setMessage(
            (char*)&vs_mainMenu_menu12Text[VS_MENU12_BIN_OFFSET_attachmentConfirm]);
        state = 7;
        break;
    case 7:
        temp_s1 = _confirmCombine(0);

        if (temp_s1 == 0) {
            break;
        }

        switch (temp_s1) {
        case 1:
            vs_battle_playMenuSelectSfx();
            vs_mainMenu_clearMenuExcept(10);
            func_800FBBD4(-1);
            vs_mainMenu_drawDpPpbars(4);
            state = 8;
            break;
        case 2:
            vs_battle_renderEquipStats(1);
            state = temp_s1;
            break;
        case 3:
            return func_80104868();
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
        if (shield->unk1 != 0) {
            vs_battle_equipShield(shield);
        }
    } else if (weapon->unk3 != 0) {
        vs_battle_equipWeapon(weapon);
    }
    return func_80103380(1);
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
                D_8010BCA4[i] = var_s2;
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

            var_s2 = D_8010BCA4[selectedRow];
            _combiningItem = var_s2 - 1;

            if (isShield != 0) {
                func_800FD5A0(var_s2);
                shield = &vs_battle_inventory.shields[var_s2 - 1];
                gemSlots = shield->base.gemSlots;
                attachedGems = shield->gems;
            } else {
                func_800FD270(var_s2);
                weapon = &vs_battle_inventory.weapons[var_s2 - 1];
                gemSlots = vs_battle_inventory.grips[weapon->grip - 1].gemSlots;
                attachedGems = weapon->gems;
            }
            func_800FBBD4(7);
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
                        func_800FF9E4(itemInfo, 16);
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
                        if (shield->unk1 != 0) {
                            vs_battle_equipShield(shield);
                        }
                    } else if (weapon->unk3 != 0) {
                        vs_battle_equipWeapon(weapon);
                    }
                }
                func_800FBB8C(7);
                vs_mainMenu_drawDpPpbars(11);
                if (isShield != 0) {
                    func_800FD5A0(var_s2);
                    vs_mainMenu_initUiShield(shield, menuText, rowTypes, textBuf);
                } else {
                    func_800FD270(var_s2);
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
            func_800FBBD4(-1);
            vs_mainMenu_drawDpPpbars(4);
            vs_mainMenu_clearMenuExcept(vs_mainMenu_menuItemIds_none);
            func_800FA810(0);
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

int func_80106610(int arg0)
{
    static int D_8010BC38;
    static char D_8010BC3C;
    static char D_8010BC3D;
    static char D_8010BC3E;

    char* sp10[16];
    int sp50[8];
    int temp_v0_6;
    int var_s7;
    int i;
    int j;
    int var_s1;
    int itemInfo;
    vs_battle_inventoryShield* temp_s0;
    vs_battle_menuItem_t* temp_v0_2;

    if (arg0 != 0) {
        func_800C8E04(1);
        D_8010BC3E = (char)(arg0 - 1);
        D_8010BC3C = 0;
        return 0;
    }
    switch (D_8010BC3C) {
    case 0:
        if (vs_mainmenu_ready() != 0) {
            _addMenuTitle(0, (int)vs_mainMenu_menu12Text[D_8010BC3E + 0x29]);
            D_8010BC3C = 1;
        }
        break;
    case 1:
        if (vs_mainmenu_ready() != 0) {
            var_s7 = 0;
            for (i = 0; i < 8; i++) {
                if (D_8010BC3E != 0) {
                    var_s1 = D_800619D8.unk28[i];
                    if (var_s1 != 0) {
                        temp_s0 = &vs_battle_inventory.shields[var_s1 - 1];
                        vs_mainMenu_initUiShield(temp_s0, &sp10[var_s7 * 2],
                            &sp50[var_s7], vs_battle_stringBuf);
                        sp10[var_s7 * 2 + 1] = (char*)(vs_mainMenu_menu12Text + 0x201);
                        for (j = 0; j < temp_s0->base.gemSlots; ++j) {
                            if (temp_s0->gems[j] != 0) {
                                break;
                            }
                        }
                        if (j == temp_s0->base.gemSlots) {
                            sp10[var_s7 * 2 + 1] =
                                (char*)(vs_mainMenu_menu12Text + 0x1E0);
                            sp50[var_s7] |= 1;
                        }
                        ++var_s7;
                        D_8010BCA4[var_s7] = var_s1;
                    }
                } else {
                    var_s1 = D_800619D8.unk0[i];
                    if (var_s1 != 0) {
                        vs_mainMenu_initUiWeapon(&vs_battle_inventory.weapons[var_s1 - 1],
                            &sp10[var_s7 * 2], &sp50[var_s7], vs_battle_stringBuf);
                        sp10[var_s7 * 2 + 1] = (char*)(vs_mainMenu_menu12Text + 0x1F1);
                        ++var_s7;
                        D_8010BCA4[var_s7] = var_s1;
                    }
                }
            }
            vs_mainmenu_setMenuRows(var_s7, (D_8010BC3E + 0x3A) | 0x19100, sp10, sp50);
            D_8010BC3C = 2;
        }
        break;
    case 2:
        D_8010BC38 = vs_mainmenu_getSelectedRow() + 1;
        if (D_8010BC38 != 0) {
            vs_mainMenu_clearMenuExcept(vs_mainMenu_menuItemIds_none);
            if (D_8010BC38 < 0) {
                return D_8010BC38;
            }
            temp_v0_2 = vs_battle_getMenuItem(0);
            temp_v0_2->state = 2;
            temp_v0_2->w = 0xA4;
            temp_v0_2->targetX = 0x10;
            temp_v0_2 = vs_battle_getMenuItem(D_8010BC38 + 9);
            temp_v0_2->state = 4;
            temp_v0_2->targetX = 0x9B;
            temp_v0_2->unk1A = 0x12;
            D_8010BC3C = 3;
        }
        break;
    case 3:
        if (vs_mainmenu_ready() != 0) {
            vs_battle_getMenuItem(0)->icon = D_8010BC3E != 0 ? 0x1B : 0x18;
            _copyMenuItem(0, 0x20);
            _copyMenuItem(D_8010BC38 + 9, 0xA);
            var_s1 = D_8010BCA4[D_8010BC38];
            _combiningItem = var_s1 - 1;
            if (D_8010BC3E != 0) {
                func_800FD5A0(var_s1);
            } else {
                func_800FD270(var_s1);
            }
            func_800FBBD4(7);
            vs_mainMenu_drawDpPpbars(3);
            D_8010BC3D = 0U;
            D_8010BC3C = 4;
        }
        break;
    case 4:
        if (D_8010BC3D < 5) {
            ++D_8010BC3D;
            if (D_8010BC3E != 0) {
                func_800FC704(D_8010BC3D, _combiningItem + 1, 1);
            } else {
                func_800FC510(D_8010BC3D, _combiningItem + 1, 1);
            }
            break;
        }
        if (D_8010BC3E != 0) {
            itemInfo = vs_battle_inventory.shields[_combiningItem].unk1;
        } else {
            itemInfo = vs_battle_inventory.weapons[_combiningItem].unk3;
        }
        _confirmationPrompt(1);
        vs_mainmenu_setMessage(
            (char*)&vs_mainMenu_menu12Text[vs_mainMenu_menu12Text[D_8010BC3E * 4 + 0x27
                                                                  + (itemInfo != 0)]]);
        D_8010BC3C = itemInfo + 5;
        break;
    case 5:
    case 6:
        temp_v0_6 = _confirmationPrompt(0);
        if (temp_v0_6 != 0) {
            func_800FBBD4(-1);
            vs_mainMenu_drawDpPpbars(4);
            vs_mainMenu_clearMenuExcept(vs_mainMenu_menuItemIds_none);
            func_800FA810(0);

            switch (temp_v0_6) {
            case 1:
                vs_main_playSfxDefault(0x7E, 0x19);
                if (D_8010BC3E != 0) {
                    _disassembleShield(_combiningItem);
                } else {
                    _disassembleWeapon(_combiningItem);
                }
                if (D_8010BC3C == 5) {
                    return -1;
                }
                if (D_8010BC3E != 0) {
                    func_800FE3A0();
                } else {
                    func_800FE360();
                }
                D_8010BC3C = 7;
                break;
            case 2:
                D_8010BC3C = 0;
                break;
            case 3:
                return func_80103380(0);
            }
        }
        break;
    case 7:
        if (func_8010BA58(D_8010BC3E) == 0) {
            return -1;
        }
        break;
    }
    return 0;
}

int func_80106C64(int arg0)
{
    static char D_8010BC3F;
    static char _0 __attribute__((unused));
    extern char D_8010BC41;
    static char _1[3] __attribute__((unused));

    char* text[4];
    int rowTypes[2];
    int temp_s0;
    int temp_v0;
    int var_a0;
    int i;

    if (arg0 != 0) {
        D_8010BC41 = 1;
        func_800FA92C(2, 1);
        D_8010BC3F = 0;
        return 0;
    }
    switch (D_8010BC3F) {
    case 0:
        if (vs_mainmenu_ready() != 0) {
            for (i = 0; i < 2; ++i) {
                text[i * 2] = (char*)&vs_mainMenu_menu12Text
                    [vs_mainMenu_menu12Text[i * 2 + VS_MENU12_BIN_INDEX_weapons]];
                text[i * 2 + 1] = (char*)&vs_mainMenu_menu12Text[vs_mainMenu_menu12Text
                        [i + VS_MENU12_BIN_INDEX_disassembleWeaponDesc]];

                var_a0 = 0;
                if (i != 0) {
                    var_a0 = 3;
                }

                temp_v0 = vs_mainMenu_getItemCount(var_a0, 0);
                rowTypes[i] = (temp_v0 << 9) + 0x400000;

                if (temp_v0 == 0) {
                    text[i * 2 + 1] =
                        (char*)&vs_mainMenu_menu12Text[VS_MENU12_BIN_OFFSET_noItems];
                    rowTypes[i] |= 1;
                }
            }
            temp_s0 = vs_main_settings.cursorMemory;
            if (D_8010BC41 == 0) {
                vs_main_settings.cursorMemory = 1;
            }
            D_8010BC41 = 0;
            vs_mainmenu_setMenuRows(2, 0x239, text, rowTypes);
            vs_main_settings.cursorMemory = temp_s0;
            D_8010BC3F = 1;
        }
        break;
    case 1:
        temp_s0 = vs_mainmenu_getSelectedRow() + 1;
        if (temp_s0 != 0) {
            if (temp_s0 < 0) {
                vs_mainMenu_clearMenuExcept(0);
                return temp_s0;
            }
            vs_mainMenu_clearMenuExcept(vs_mainMenu_menuItemIds_none);
            func_80106610(temp_s0);
            D_8010BC3F = 2;
        }
        break;
    case 2:
        temp_s0 = func_80106610(0);
        if (temp_s0 != 0) {
            if (temp_s0 != -1) {
                return temp_s0;
            }
            D_8010BC3F = 3;
        }
        break;
    case 3:
        if (vs_mainmenu_ready() != 0) {
            func_800FFBC8();
            _addMenuTitle(0, 0x57);
            _addMenuTitle(0xC, 0x93);
            D_8010BC3F = 0;
        }
        break;
    }
    return 0;
}

int func_80106ECC(int arg0)
{
    static int D_8010BC44;
    static char D_8010BC48;
    static char D_8010BC49;
    static char _[2] __attribute__((unused));

    char* sp10[16];
    int sp50[8];
    int i;
    int var_s2;
    int temp_s0;
    vs_battle_menuItem_t* temp_v0_2;

    if (arg0 != 0) {
        func_800C8E04(1);
        vs_mainmenu_setMessage((char*)&vs_mainMenu_menu12Text[0x1C8]);
        vs_mainMenu_clearMenuExcept(vs_mainMenu_menuItemIds_none);
        D_8010BC48 = 0;
        return 0;
    }
    switch (D_8010BC48) {
    case 0:
        if (vs_mainmenu_ready() != 0) {
            _addMenuTitle(0, 0xB8);
            D_8010BC48 = 1;
        }
        break;
    case 1:
        if (vs_mainmenu_ready() != 0) {
            var_s2 = 0;
            for (i = 0; i < 8; ++i) {
                temp_s0 = D_800619D8.unk0[i];
                if (temp_s0 != 0) {
                    vs_mainMenu_initUiWeapon(&vs_battle_inventory.weapons[temp_s0 - 1],
                        &sp10[var_s2 * 2], &sp50[var_s2], vs_battle_stringBuf);
                    sp10[(var_s2 * 2) + 1] = (char*)&vs_mainMenu_menu12Text[0x1C8];
                    ++var_s2;
                    D_8010BCA4[var_s2] = temp_s0;
                }
            }
            vs_mainmenu_setMenuRows(var_s2, 0x1913C, sp10, sp50);
            D_8010BC48 = 2;
        }
        break;
    case 2:
        D_8010BC44 = vs_mainmenu_getSelectedRow() + 1;
        if (D_8010BC44 != 0) {
            vs_mainMenu_clearMenuExcept(vs_mainMenu_menuItemIds_none);
            if (D_8010BC44 < 0) {
                return D_8010BC44;
            }
            temp_v0_2 = vs_battle_getMenuItem(0);
            temp_v0_2->state = 2;
            temp_v0_2->w = 0xA4;
            temp_v0_2->targetX = 0x10;
            temp_v0_2 = vs_battle_getMenuItem(D_8010BC44 + 9);
            temp_v0_2->state = 4;
            temp_v0_2->targetX = 0x9B;
            temp_v0_2->unk1A = 0x12;
            D_8010BC48 = 3;
        }
        break;
    case 3:
        if (vs_mainmenu_ready() != 0) {
            vs_battle_getMenuItem(0)->icon = 0x18;
            _copyMenuItem(0, 0x20);
            _copyMenuItem(D_8010BC44 + 9, 0xA);
            temp_s0 = D_8010BCA4[D_8010BC44];
            _combiningItem = temp_s0 - 1;
            func_800FD270(temp_s0);
            func_800FBBD4(7);
            vs_mainMenu_drawDpPpbars(3);
            D_8010BC49 = 0;
            D_8010BC48 = 4;
        }
        break;
    case 4:
        if (D_8010BC49 < 5) {
            D_8010BC49 = (D_8010BC49 + 1);
            func_800FC510(D_8010BC49, _combiningItem + 1, 1);
            return 0;
        }
        _confirmationPrompt(1);
        vs_mainmenu_setMessage((char*)&vs_mainMenu_menu12Text[0x1D6]);
        D_8010BC48 = 5;
        break;
    case 5:
        i = _confirmationPrompt(0);
        if (i != 0) {
            func_800FBBD4(-1);
            vs_mainMenu_drawDpPpbars(4);
            switch (i) {
            case 1:
                vs_battle_playMenuSelectSfx();
                vs_mainMenu_clearMenuExcept(0xA);
                vs_battle_getMenuItem(0xA)->unk2 = i;
                D_8010BC48 = 6;
                break;
            case 2:
                vs_mainMenu_clearMenuExcept(vs_mainMenu_menuItemIds_none);
                func_800FA810(0);
                D_8010BC48 = 0;
                break;
            case 3:
                return func_80103380(0);
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

int func_801072FC(int arg0)
{
    static int D_8010BC4C;
    static char D_8010BC50;
    static char _[3] __attribute__((unused));

    int ppCost;
    int i;
    int new_var;

    if (arg0 != 0) {
        func_800FA92C(4, 1);
        D_8010BC50 = 0;
        return 0;
    }

    switch (D_8010BC50) {
    case 0:
        if (vs_mainmenu_ready() != 0) {
            _confirmationPrompt(1);
            vs_mainmenu_setMessage(
                (char*)&vs_mainMenu_menu12Text[VS_MENU12_BIN_OFFSET_repairConfirm]);
            D_8010BC50 = 1;
        }
        break;
    case 1:
        i = _confirmationPrompt(0);
        if (i != 0) {
            D_8010BC4C = -1;
            if (i == 1) {
                vs_main_playSfxDefault(0x7E, 0xD);
                D_8010BC50 = 2;
            } else {
                if (i == 3) {
                    vs_battle_playMenuLeaveSfx();
                    return -2;
                }
                func_800FFBC8();
                vs_mainMenu_menuItemLeaveRight(0xE);
                D_8010BC50 = 4;
            }
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
                if (weapon->unk3 != 0) {
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

                if (shield->unk1 != 0) {
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

        D_8010BC50 = 3;
        break;
    case 3:
        if (vs_main_buttonsPressed.pad[0].low != 0) {
            vs_battle_playMenuLeaveSfx();
            vs_mainMenu_menuItemLeaveRight(0xE);
            if (vs_main_buttonsPressed.all & PADRup) {
                return -2;
            }
            func_800FFBC8();
            D_8010BC50 = 4;
        }
        break;
    case 4:
        if (vs_mainmenu_ready() != 0) {
            return D_8010BC4C;
        }
        break;
    }
    return 0;
}

static void* _sydData = NULL;

int vs_menuC_loadSyd(int id)
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

vs_battle_menuItem_t* func_801077DC(int arg0, int arg1)
{
    vs_battle_menuItem_t* item = vs_battle_setMenuItem(0, 0x9B, 0x12, 0xA5, 0,
        (arg1 == 0 ? (char*)&vs_mainMenu_menu12Text[vs_mainMenu_menu12Text[arg0 + 0x4F]]
                   : vs_mainMenu_itemNames[arg1]));
    item->selected = 1;
    return item;
}

vs_battle_menuItem_t* func_8010785C(int arg0, int arg1)
{
    vs_battle_menuItem_t* temp_v0;

    temp_v0 = func_801077DC(arg0, arg1);
    temp_v0->state = 2;
    temp_v0->targetX = 0x9B;
    temp_v0->initialX = 0x140;

    return temp_v0;
}

vs_battle_inventoryBlade* func_8010B2B4(vs_battle_inventoryBlade*,
    vs_battle_inventoryBlade*, vs_battle_inventoryBlade*, void*);

static vs_battle_inventoryBlade D_8010BCE4;
static char D_8010BD10[2];
static char _1[2] __attribute__((unused));

void func_80107894(int arg0)
{
    int i;
    int var_s3;
    u_int temp_v1;
    int temp_s2;
    vs_battle_inventoryBlade* itemInfo;

    i = D_8010BD10[0];
    temp_s2 = D_8010BD10[1];

    var_s3 = i != 0;
    if (temp_s2 != 0) {
        var_s3 += 2;
    }

    switch (var_s3) {
    case 0:
        vs_battle_rMemzero(&D_8010BCE4, 0x2C);
        break;
    case 1:
    case 2:
        vs_battle_copyAligned(
            &D_8010BCE4, &vs_battle_inventory.blades[i + temp_s2 - 1], 0x2C);
        break;
    case 3:
        vs_battle_rMemzero(&D_8010BCE4, 0x2C);
        func_8010B2B4(&vs_battle_inventory.blades[i - 1],
            &vs_battle_inventory.blades[temp_s2 - 1], &D_8010BCE4, _sydData);
        break;
    }

    itemInfo = &D_8010BCE4;
    itemInfo->combinedWeaponIndex = 0;

    vs_mainMenu_resetStats();
    vs_mainMenu_setRangeRisk(0, 0, 0, 1);

    temp_v1 = arg0 - 1;

    if (temp_v1 >= 2) {
        if (D_8010BCE4.id != 0) {
            for (i = 0; i < 16; ++i) {
                vs_mainMenu_equipmentStats[i] = itemInfo->classes[i & 7];
                vs_mainMenu_equipmentStats[16 + i] = itemInfo->affinities[i & 7];
            }
            vs_mainMenu_setDpPp(itemInfo->currentDp, itemInfo->maxDp, itemInfo->currentPp,
                itemInfo->maxPp);
            vs_mainMenu_setStrIntAgi(
                itemInfo->strength, itemInfo->intelligence, itemInfo->agility, 1);
            vs_mainMenu_setRangeRisk(itemInfo->range.unk0, itemInfo->cost, 0, 1);
            vs_mainMenu_equipmentSubtype = 2;
        }
    } else if (var_s3 & arg0) {
        func_800FD404(D_8010BD10[temp_v1]);
    }
}

int func_80107AD4(int arg0)
{
    static int D_8010BC5C;
    static char D_8010BC60;
    static char D_8010BC61;

    int var_s4;
    int i;
    char* temp_s7;
    char** temp_fp;
    int temp_a0;
    int temp_s0;
    vs_battle_inventoryBlade* var_s2 = NULL;

    if (arg0 != 0) {
        D_8010BC61 = arg0;
        func_80103D8C(arg0 + 0xA);
        D_8010BC60 = 0;
        return 0;
    }

    temp_s0 = D_8010BD10[D_8010BC61 - 1];
    if (temp_s0 != 0) {
        var_s2 = &vs_battle_inventory.blades[temp_s0 - 1];
    }

    switch (D_8010BC60) {
    case 0:
        if (vs_mainmenu_ready() != 0) {
            temp_s7 = vs_main_allocHeapR(0x72C);
            temp_fp = (char**)(temp_s7 + 0x6A4);
            if (var_s2 == NULL) {
                temp_fp[0] = (char*)&vs_mainMenu_menu12Text[VS_MENU12_BIN_OFFSET_blade];
                temp_fp[1] = (char*)&vs_mainMenu_menu12Text
                    [VS_MENU12_BIN_OFFSET_selectBladeToCombine];
                *vs_battle_rowTypeBuf = 1;
            } else {
                vs_mainMenu_setBladeUi(var_s2, temp_fp, vs_battle_rowTypeBuf, temp_s7);
            }

            *D_8010BCA4 = temp_s0;
            var_s4 = 1;

            for (i = 0; i < 16; ++i) {
                temp_s0 = D_800619D8.unk0[i + 8];
                if ((temp_s0 != 0) && (temp_s0 != D_8010BD10[0])
                    && (temp_s0 != D_8010BD10[1])) {
                    int new_var = temp_s0;
                    var_s2 = &vs_battle_inventory.blades[temp_s0 - 1];
                    vs_mainMenu_setBladeUi(var_s2, temp_fp + var_s4 * 2,
                        &vs_battle_rowTypeBuf[var_s4], temp_s7 + var_s4 * 0x60);
                    if (!((D_8010BB30[_workshopFlags] >> var_s2->material) & 1)) {
                        temp_fp[var_s4 * 2 + 1] = (char*)&vs_mainMenu_menu12Text
                            [VS_MENU12_BIN_OFFSET_invalidBladeMaterial];
                        vs_battle_rowTypeBuf[var_s4] |= 1;
                    }

                    temp_a0 = var_s2->combinedWeaponIndex;

                    if (temp_a0 != 0) {
                        vs_battle_rowTypeBuf[var_s4] =
                            vs_battle_rowTypeBuf[var_s4]
                            | (vs_battle_inventory.weapons[temp_a0 - 1].unk3 == 0
                                    ? 0xCC00
                                    : 0xCA00);
                    }
                    D_8010BCA4[var_s4] = new_var;
                    ++var_s4;
                }
            }

            _populateItemsList(var_s4, temp_fp, vs_battle_rowTypeBuf);
            vs_main_freeHeapR(temp_s7);
            D_8010BC60 = 1;
        }
        break;
    case 1:
        temp_s0 = D_8010BCA4[_itemsListWindow + _itemsListSelection];
        if (temp_s0 != 0) {
            func_800FD404(temp_s0);
        } else {
            vs_mainMenu_resetStats();
            vs_mainMenu_setRangeRisk(0, 0, 0, 1);
        }
        func_800FF9E4(_itemsListSelection + _itemsListWindow, _itemsListState);
        _navigateItemsList(2);
        D_8010BC5C = func_801035E0() + 1;
        if (D_8010BC5C != 0) {
            vs_mainMenu_clearMenuExcept(vs_mainMenu_menuItemIds_none);
            if (D_8010BC5C == -2) {
                return -2;
            }
            if (D_8010BC5C > 0) {
                D_8010BC5C = D_8010BCA4[D_8010BC5C - 1];
            }
            D_8010BC60 = 2;
        }
        break;
    case 2:
        if (vs_mainmenu_ready() != 0) {
            return D_8010BC5C;
        }
        break;
    }
    return 0;
}

void func_80107EBC(vs_battle_menuItem_t* arg0, vs_battle_inventoryBlade* arg1)
{
    int temp_v1;

    arg0->icon = arg1->category;
    arg0->material = arg1->material;
    temp_v1 = arg1->combinedWeaponIndex;
    if (temp_v1 != 0) {
        int var_v1 = 1;
        if (vs_battle_inventory.weapons[temp_v1 - 1].unk3 == 0) {
            var_v1 = 2;
        }
        arg0->unkD = var_v1;
    }
}

int func_80107F14(int arg0)
{
    static char D_8010BB74 = 0;

    static char D_8010BC62;
    static char D_8010BC63;
    static char D_8010BC64;
    static char _[3] __attribute__((unused));

    char* sp18[2];
    int sp20;
    int temp_s0;
    int var_s1;
    int temp_v0_2;
    int i;
    u_short* var_a0_2;
    int i_2;
    vs_battle_inventoryBlade* temp_s3;
    vs_battle_inventoryBlade* var_a0;
    vs_battle_menuItem_t* temp_v0;

    if (arg0 != 0) {
        func_80102A34(5);
        *(u_short*)&D_8010BD10 = 0;
        func_80107894(0);
        D_8010BC63 = 1;
        D_8010BC62 = 0U;
        return 0;
    }

    var_s1 = 0;
    if (D_8010BD10[0] != 0) {
        var_s1 = D_8010BD10[1] > 0;
    }

    D_8010BC64 += 0x10;
    if (D_8010BC62 != 2) {
        D_8010BC64 = 0;
    }

    switch (D_8010BC62) {
    case 0:
        if (vs_mainmenu_ready() == 0) {
            break;
        }
        func_80102B50(0x487, 0x18);
        // Fallthrough
    case 1:
        var_s1 = D_8010BCE4.id;
        temp_v0 = func_8010785C(0, var_s1);
        if (var_s1 != 0) {
            func_80107EBC(temp_v0, &D_8010BCE4);
        }

        for (i = 0; i < 2; ++i) {
            int new_var;
            var_s1 = D_8010BD10[i];
            if (var_s1 != 0) {
                temp_s3 = &vs_battle_inventory.blades[var_s1 - 1];
            }
            temp_v0 = vs_battle_setMenuItem(i + 0xB, 0x14E, 0x22 + i * 0x10, 0x97, 0,
                (char*)(var_s1 == 0 ? vs_mainMenu_menu12Text + (new_var = 0x436)
                                    : (u_short*)vs_mainMenu_itemNames[temp_s3->id]));
            temp_v0->state = 2;
            temp_v0->targetX = 0xA9;
            if (var_s1 == 0) {
                temp_v0->unkA = 1;
            } else {
                func_80107EBC(temp_v0, temp_s3);
            }
        }
        D_8010BC62 = 2;
        break;
    case 2:
        if (vs_mainmenu_ready() != 0) {
            if (!(vs_main_buttonsPressed.all & 0x10)) {
                if (var_s1 != 0) {
                    _drawOk(2, D_8010BC64);
                }
                if (vs_main_buttonsPressed.all & 0x40) {
                    temp_v0_2 = func_80102AB8(5);
                    if (temp_v0_2 != 0) {
                        vs_battle_playMenuLeaveSfx();
                        D_8010BC63 = temp_v0_2;
                        D_8010BD10[temp_v0_2 - 1] = 0;
                        func_80107894(temp_v0_2);
                        temp_v0 = vs_battle_setMenuItem(temp_v0_2 + 0xA, 0xA9,
                            (temp_v0_2 * 0x10) + 0x12, 0x97, 0,
                            (char*)(vs_mainMenu_menu12Text + 0x436));
                        temp_v0->selected = 1;
                        temp_v0->unkA = 1;
                        var_s1 = D_8010BCE4.id;
                        temp_v0 = func_801077DC(0, var_s1);
                        if (var_s1 != 0) {
                            func_80107EBC(temp_v0, &D_8010BCE4);
                        }
                        break;
                    }
                    return func_80103380(1);
                }
                if (vs_main_buttonsPressed.all & 0x800) {
                    if (var_s1 != 0) {
                        vs_battle_playMenuSelectSfx();
                        vs_battle_getMenuItem(D_8010BC63 + 0xA)->selected = 0;
                        D_8010BC63 = 3;
                        D_8010BC62 = 4;
                        func_80107894(3);
                        return 0;
                    }
                }
                i_2 = D_8010BC63;
                if (vs_main_buttonsPressed.all & 0x20) {
                    if (i_2 == 0) {
                        func_800C02E0();
                    } else {
                        vs_battle_playMenuSelectSfx();
                        if (i_2 == 3) {
                            D_8010BC62 = 4;
                        } else {
                            vs_mainMenu_clearMenuExcept(vs_mainMenu_menuItemIds_none);
                            func_80107AD4(i_2);
                            D_8010BC62 = 3;
                        }
                        break;
                    }
                }
                if (vs_main_buttonRepeat & 0x1000) {
                    if (i_2 == 0) {
                        i_2 = var_s1 + 2;
                    } else {
                        --i_2;
                    }
                }
                if (vs_main_buttonRepeat & 0x4000) {
                    if (i_2 == (var_s1 + 2)) {
                        i_2 = 0;
                    } else {
                        ++i_2;
                    }
                }

                if (i_2 != D_8010BC63) {
                    vs_battle_playMenuChangeSfx();
                    D_8010BC63 = i_2;
                    func_80107894(i_2 & 0xFF);
                }
                vs_battle_rowTypeBuf[0] = D_8010BCE4.id < 1U;

                for (var_s1 = 1; var_s1 < 3; ++var_s1) {
                    vs_battle_getMenuItem(var_s1 + 0xA)->selected =
                        (var_s1 ^ D_8010BC63) == 0;
                    vs_battle_rowTypeBuf[var_s1] = D_8010BD10[var_s1 - 1] == 0;
                }

                vs_battle_rowTypeBuf[3] = 1;
                func_800FF9E4(i_2, 0x10);
                sp18[1] = (char*)(vs_mainMenu_menu12Text + 0x459);
                switch (i_2) {
                case 0:
                    var_a0 = &D_8010BCE4;
                    if (D_8010BCE4.id != 0) {
                        vs_mainMenu_setBladeUi(var_a0, sp18, &sp20, vs_battle_stringBuf);
                    }
                    break;
                case 1:
                case 2:
                    var_s1 = D_8010BD10[i_2 - 1];
                    if (var_s1 != 0) {
                        var_a0 = &vs_battle_inventory.blades[var_s1 - 1];
                        vs_mainMenu_setBladeUi(var_a0, sp18, &sp20, vs_battle_stringBuf);
                    }
                    break;
                case 3:
                    sp18[1] = (char*)(vs_mainMenu_menu12Text + 0x39E);
                    break;
                }
                vs_mainmenu_setMessage(sp18[1]);
                var_s1 = (((i_2 * 0x10) + 0xA) << 0x10) | 0x9B;
                if (i_2 == 0) {
                    var_s1 -= 0xE;
                }
                if (i_2 == 3) {
                    var_s1 += 0xFFFC0000;
                }
                D_8010BB74 = func_800FFCDC(D_8010BB74, var_s1);
                break;
            }
            return func_80103380(1);
        }
        D_8010BC64 = 0;
        break;
    case 3:
        temp_s0 = func_80107AD4(0);
        if (temp_s0 != 0) {
            if (temp_s0 != -2) {
                if (temp_s0 > 0) {
                    var_s1 = D_8010BC63 - 1;
                    if (temp_s0 == D_8010BD10[D_8010BC63 - 1]) {
                        D_8010BD10[D_8010BC63 - 1] = 0;
                        func_80102AB8(var_s1);
                    } else {
                        D_8010BD10[D_8010BC63 - 1] = temp_s0;
                        func_80102A34(var_s1);
                        D_8010BC63 = (D_8010BC63 + 1);
                        if (var_s1 == 1) {
                            if (D_8010BD10[0] == 0) {
                                D_8010BC63 = var_s1;
                            }
                        }
                    }
                    func_80107894(D_8010BC63);
                }
                D_8010BC62 = 1;
                break;
            }
            return func_80103380(1);
        }
        break;
    case 4:
        vs_battle_renderEquipStats(2);
        _confirmCombine(2);
        var_s1 = 0;

        for (i = 0; i < 2; ++i) {
            var_s1 |= vs_battle_inventory.blades[D_8010BD10[i] - 1].combinedWeaponIndex;
        }
        if (var_s1 == 0) {
            var_a0_2 = vs_mainMenu_menu12Text + 0x42B;
        } else {
            var_a0_2 = vs_mainMenu_menu12Text + 0x4A7;
        }
        vs_mainmenu_setMessage((char*)var_a0_2);
        D_8010BC62 = 5;
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
            func_800FBBD4(-1);
            vs_mainMenu_drawDpPpbars(4);
            vs_mainMenu_clearMenuExcept(vs_mainMenu_menuItemIds_none);
            func_800FA810(0);

            for (i = 0; i < 2; ++i) {
                temp_s3 = &vs_battle_inventory.blades[D_8010BD10[i] - 1];
                var_s1 = temp_s3->combinedWeaponIndex;
                if (var_s1 != 0) {
                    if (vs_battle_inventory.weapons[var_s1 - 1].unk3 != 0) {
                        func_800FE360();
                        D_8010BC62 = 6;
                    }
                    _disassembleWeapon(var_s1 - 1);
                }
                func_800FE3E0(1, D_8010BD10[i]);
            }

            temp_s0 = D_8010BD10[0];
            temp_s3 = &vs_battle_inventory.blades[temp_s0 - 1];
            vs_battle_copyAligned(temp_s3, &D_8010BCE4, 0x2C);
            temp_s3->index = temp_s0;
            vs_mainMenu_rebuildInventory(1);
            return D_8010BC62 != 6;
        case 2:
            vs_battle_playMenuLeaveSfx();
            vs_battle_renderEquipStats(1);
            D_8010BC62 = temp_v0_2;
            break;
        case 3:
            return func_80103380(1);
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

void func_801087E4(vs_battle_inventoryShield* shield)
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

vs_battle_inventoryArmor* _combineShields(vs_battle_inventoryArmor*,
    vs_battle_inventoryArmor*, vs_battle_inventoryArmor*, void*);

static vs_battle_inventoryShield D_8010BD14;
static u_char D_8010BD44[16];

void func_80108908(int arg0)
{
    int var_s2;
    u_int temp_v1;
    int temp_s1;
    int temp_s3;
    vs_battle_inventoryShield* itemInfo;

    temp_s1 = D_8010BD44[0];
    temp_s3 = D_8010BD44[1];

    var_s2 = temp_s1 > 0;

    if (temp_s3 != 0) {
        var_s2 += 2;
    }

    switch (var_s2) {
    case 0:
        vs_battle_rMemzero(&D_8010BD14, sizeof D_8010BD14);
        break;
    case 1:
    case 2:
        vs_battle_copyAligned(&D_8010BD14,
            &vs_battle_inventory.shields[temp_s1 + temp_s3 - 1], sizeof D_8010BD14);
        break;
    case 3:
        vs_battle_rMemzero(&D_8010BD14, sizeof D_8010BD14);
        _combineShields(&vs_battle_inventory.shields[temp_s1 - 1].base,
            &vs_battle_inventory.shields[temp_s3 - 1].base, &D_8010BD14.base, _sydData);
        break;
    }

    itemInfo = &D_8010BD14;
    itemInfo->unk1 = 0;

    vs_mainMenu_resetStats();

    temp_v1 = arg0 - 1;

    if (temp_v1 > 1) {
        if (itemInfo->base.id != 0) {
            func_801087E4(itemInfo);
        }
    } else if (var_s2 & arg0) {
        func_801087E4(&vs_battle_inventory.shields[D_8010BD44[temp_v1] - 1]);
    }
}

void func_80108A9C(vs_battle_inventoryShield* arg0, char** arg1, int* arg2, char* arg3)
{
    int temp_s1;

    temp_s1 = *(int*)arg0->gems;
    *(int*)arg0->gems = 0;
    vs_mainMenu_initUiShield(arg0, arg1, arg2, arg3);
    *(int*)arg0->gems = temp_s1;
}

int func_80108AD4(int arg0)
{
    static int D_8010BC68;
    static char D_8010BC6C;
    static char D_8010BC6D;

    char** sp10;
    int var_s4;
    int i;
    char* temp_v0;
    int temp_s0;
    vs_battle_inventoryShield* var_s2;

    var_s2 = NULL;
    if (arg0 != 0) {
        D_8010BC6D = arg0;
        func_80103D8C(arg0 + 0xA);
        D_8010BC6C = 0;
        return 0;
    }

    temp_s0 = D_8010BD44[D_8010BC6D - 1];
    if (temp_s0 != 0) {
        var_s2 = &vs_battle_inventory.shields[temp_s0 - 1];
    }

    switch (D_8010BC6C) {
    case 0:
        if (vs_mainmenu_ready() != 0) {
            temp_v0 = vs_main_allocHeapR(0x3CC);
            sp10 = (char**)(temp_v0 + 0x384);
            if (var_s2 == NULL) {
                sp10[0] = (char*)&vs_mainMenu_menu12Text[VS_MENU12_BIN_OFFSET_shield];
                sp10[1] =
                    (char*)&vs_mainMenu_menu12Text[VS_MENU12_BIN_OFFSET_selectShield];
                *vs_battle_rowTypeBuf = 1;
            } else {
                func_80108A9C(var_s2, sp10, vs_battle_rowTypeBuf, temp_v0);
            }

            *D_8010BCA4 = temp_s0;
            var_s4 = 1;

            for (i = 0; i < 8; ++i) {
                temp_s0 = D_800619D8.unk0[i + 0x28];
                if ((temp_s0 != 0) && (temp_s0 != D_8010BD44[0])
                    && (temp_s0 != D_8010BD44[1])) {
                    var_s2 = &vs_battle_inventory.shields[temp_s0 - 1];
                    func_80108A9C(var_s2, sp10 + var_s4 * 2,
                        &vs_battle_rowTypeBuf[var_s4], temp_v0 + var_s4 * 0x60);
                    if (!((D_8010BB30[_workshopFlags] >> var_s2->base.material) & 1)) {
                        sp10[var_s4 * 2 + 1] = (char*)&vs_mainMenu_menu12Text
                            [VS_MENU12_BIN_OFFSET_invalidShieldMaterial];
                        vs_battle_rowTypeBuf[var_s4] |= 1;
                    }
                    if (var_s2->unk1 != 0) {
                        vs_battle_rowTypeBuf[var_s4] |= 0xCA00;
                    }
                    D_8010BCA4[var_s4] = temp_s0;
                    ++var_s4;
                }
            }

            _populateItemsList(var_s4, sp10, vs_battle_rowTypeBuf);
            vs_main_freeHeapR(temp_v0);
            D_8010BC6C = 1;
        }
        break;
    case 1:
        temp_s0 = D_8010BCA4[_itemsListWindow + _itemsListSelection];
        if (temp_s0 != 0) {
            func_801087E4(&vs_battle_inventory.shields[temp_s0 - 1]);
        } else {
            vs_mainMenu_resetStats();
        }
        func_800FF9E4(_itemsListSelection + _itemsListWindow, _itemsListState);
        _navigateItemsList(2);
        D_8010BC68 = func_801035E0() + 1;
        if (D_8010BC68 != 0) {
            vs_mainMenu_clearMenuExcept(vs_mainMenu_menuItemIds_none);
            if (D_8010BC68 == -2) {
                return -2;
            }
            if (D_8010BC68 > 0) {
                D_8010BC68 = D_8010BCA4[D_8010BC68 - 1];
            }
            D_8010BC6C = 2;
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

void func_80108E9C(vs_battle_menuItem_t* arg0, vs_battle_inventoryShield* arg1)
{
    arg0->icon = 0xF;
    arg0->material = arg1->base.material;
    arg0->unkD = arg1->unk1 != 0;
}

int func_80108EC4(int arg0)
{
    static char D_8010BB75 = 0;

    static char D_8010BC6E;
    static char D_8010BC6F;
    static char D_8010BC70;
    static char _[3] __attribute__((unused));

    char* sp18[2];
    int sp20;
    int temp_s0_3;
    int var_a0;
    int var_s1;
    int i;
    u_short* var_a0_2;
    int temp_s1;
    int temp_s2;
    int temp_v1_2;
    vs_battle_inventoryShield* temp_s0;
    vs_battle_inventoryShield* itemInfo;
    vs_battle_menuItem_t* temp_v0;

    if (arg0 != 0) {
        func_80102A34(5);
        *(u_short*)D_8010BD44 = 0;
        func_80108908(0);
        D_8010BC6F = 1;
        D_8010BC6E = 0;
        return 0;
    }

    var_s1 = 0;

    if (D_8010BD44[0] != 0) {
        var_s1 = D_8010BD44[1] > 0;
    }

    D_8010BC70 += 0x10;
    if (D_8010BC6E != 2) {
        D_8010BC70 = 0;
    }

    switch (D_8010BC6E) {
    case 0:
        if (vs_mainmenu_ready() == 0) {
            break;
        }
        func_80102B50(0x48F, 0x1B);
        // Fallthrough
    case 1:
        temp_s1 = D_8010BD14.base.id;
        temp_v0 = func_8010785C(1, temp_s1);
        if (temp_s1 != 0) {
            func_80108E9C(temp_v0, &D_8010BD14);
        }

        for (i = 0; i < 2; ++i) {
            int new_var;
            temp_s1 = D_8010BD44[i];
            if (temp_s1 != 0) {
                itemInfo = &vs_battle_inventory.shields[temp_s1 - 1];
            }
            temp_v0 = vs_battle_setMenuItem(i + 0xB, 0x14E, 0x22 + i * 0x10, 0x97, 0,
                (char*)(temp_s1 == 0
                            ? vs_mainMenu_menu12Text + (new_var = 0x439)
                            : (u_short*)vs_mainMenu_itemNames[itemInfo->base.id]));
            temp_v0->state = 2;
            temp_v0->targetX = 0xA9;
            if (temp_s1 == 0) {
                temp_v0->unkA = 1;
            } else {
                func_80108E9C(temp_v0, itemInfo);
            }
        }

        D_8010BC6E = 2;
        break;
    case 2:
        if (vs_mainmenu_ready() != 0) {
            if (!(vs_main_buttonsPressed.all & 0x10)) {
                if (var_s1 != 0) {
                    _drawOk(2, D_8010BC70);
                }
                if (vs_main_buttonsPressed.all & 0x40) {
                    temp_s2 = func_80102AB8(5);
                    if (temp_s2 != 0) {
                        vs_battle_playMenuLeaveSfx();
                        D_8010BC6F = temp_s2;
                        D_8010BD44[temp_s2 - 1] = 0;
                        func_80108908(temp_s2);
                        temp_v0 = vs_battle_setMenuItem(temp_s2 + 0xA, 0xA9,
                            (temp_s2 * 0x10) + 0x12, 0x97, 0,
                            (char*)(vs_mainMenu_menu12Text + 0x439));
                        temp_v0->selected = 1;
                        temp_v0->unkA = 1;
                        var_s1 = D_8010BD14.base.id;
                        temp_v0 = func_801077DC(1, var_s1);
                        if (var_s1 != 0) {
                            func_80108E9C(temp_v0, &D_8010BD14);
                            return 0;
                        }
                        break;
                    }
                    return func_80103380(1);
                }
                if (vs_main_buttonsPressed.all & 0x800) {
                    if (var_s1 != 0) {
                        vs_battle_playMenuSelectSfx();
                        vs_battle_getMenuItem(D_8010BC6F + 0xA)->selected = 0;
                        D_8010BC6F = 3U;
                        D_8010BC6E = 4U;
                        func_80108908(3);
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
                            D_8010BC6E = 4;
                        } else {
                            vs_mainMenu_clearMenuExcept(vs_mainMenu_menuItemIds_none);
                            func_80108AD4(temp_s2);
                            D_8010BC6E = 3;
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
                    func_80108908(D_8010BC6F);
                }
                vs_battle_rowTypeBuf[0] = D_8010BD14.base.id < 1;

                for (var_s1 = 1; var_s1 < 3; ++var_s1) {
                    vs_battle_getMenuItem(var_s1 + 0xA)->selected =
                        (var_s1 ^ D_8010BC6F) == 0;
                    vs_battle_rowTypeBuf[var_s1] = D_8010BD44[var_s1 - 1] == 0;
                }

                vs_battle_rowTypeBuf[3] = 1;
                func_800FF9E4(temp_s2, 0x10);
                sp18[1] = (char*)(vs_mainMenu_menu12Text + 0x461);
                switch (temp_s2) {
                case 0:
                    if (D_8010BD14.base.id != 0) {
                        func_80108A9C(&D_8010BD14, sp18, &sp20, vs_battle_stringBuf);
                    }
                    break;
                case 1:
                case 2:
                    var_s1 = D_8010BD44[temp_s2 - 1];
                    if (var_s1 != 0) {
                        temp_s0 = &vs_battle_inventory.shields[var_s1 - 1];
                        var_s1 = *(int*)temp_s0->gems;
                        *(int*)temp_s0->gems = 0;
                        func_80108A9C(temp_s0, sp18, &sp20, vs_battle_stringBuf);
                        *(int*)temp_s0->gems = var_s1;
                    }
                    break;
                case 3:
                    sp18[1] = (char*)(vs_mainMenu_menu12Text + 0x39E);
                    break;
                }
                vs_mainmenu_setMessage((char*)sp18[1]);
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
            return func_80103380(1);
        }
        D_8010BC70 = 0;
        break;
    case 3:
        temp_s2 = func_80108AD4(0);
        if (temp_s2 != 0) {
            if (temp_s2 != -2) {
                if (temp_s2 > 0) {
                    var_s1 = D_8010BC6F - 1;
                    if (temp_s2 == D_8010BD44[D_8010BC6F - 1]) {
                        D_8010BD44[D_8010BC6F - 1] = 0;
                        func_80102AB8(var_s1);
                    } else {
                        D_8010BD44[D_8010BC6F - 1] = temp_s2;
                        func_80102A34(var_s1);
                        D_8010BC6F = (D_8010BC6F + 1);
                        if (var_s1 == 1) {
                            if (D_8010BD44[0] == 0) {
                                D_8010BC6F = var_s1;
                            }
                        }
                    }
                    func_80108908(D_8010BC6F);
                }
                D_8010BC6E = 1;
                break;
            }
            return func_80103380(1);
        }
        break;
    case 4:
        vs_battle_renderEquipStats(2);
        _confirmCombine(2);
        var_s1 = 0;

        for (i = 0; i < 2; ++i) {

            itemInfo = &vs_battle_inventory.shields[D_8010BD44[i] - 1];
            temp_v1_2 = itemInfo->base.gemSlots;
            var_s1 |= itemInfo->unk1;

            for (var_a0 = 0; var_a0 < temp_v1_2; ++var_a0) {
                var_s1 |= itemInfo->gems[var_a0];
            }
        }

        if (var_s1 == 0) {
            var_a0_2 = vs_mainMenu_menu12Text + 0x42B;
        } else {
            var_a0_2 = vs_mainMenu_menu12Text + 0x4A7;
        }
        vs_mainmenu_setMessage((char*)var_a0_2);
        D_8010BC6E = 5;
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
            func_800FBBD4(-1);
            vs_mainMenu_drawDpPpbars(4);
            vs_mainMenu_clearMenuExcept(vs_mainMenu_menuItemIds_none);
            func_800FA810(0);

            for (i = 0; i < 2; ++i) {
                temp_s1 = D_8010BD44[i];
                temp_s0_3 = temp_s1 - 1;
                if (vs_battle_inventory.shields[temp_s0_3].unk1 != 0) {
                    func_800FE3A0();
                    D_8010BC6E = 6;
                }
                _disassembleShield(temp_s0_3);
                func_800FE3E0(3, temp_s1);
            }

            temp_s2 = D_8010BD44[0];
            temp_s0 = &vs_battle_inventory.shields[temp_s2 - 1];
            vs_battle_copyAligned(temp_s0, &D_8010BD14, 0x30);
            temp_s0->index = temp_s2;
            vs_mainMenu_rebuildInventory(3);
            return D_8010BC6E != 6;
        case 2:
            vs_battle_playMenuLeaveSfx();
            vs_battle_renderEquipStats(1);
            D_8010BC6E = temp_s2;
            break;
        case 3:
            return func_80103380(1);
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

vs_battle_inventoryArmor* _combineArmor(vs_battle_inventoryArmor*,
    vs_battle_inventoryArmor*, vs_battle_inventoryArmor*, void*);

static vs_battle_inventoryArmor D_8010BD54;
static char D_8010BD7C[2];
static char _2[2] __attribute__((unused));

void func_80109790(int arg0)
{
    int var_a0;
    int i;
    int var_s2;
    u_int temp_v1;
    int temp_s3;
    vs_battle_inventoryArmor* itemInfo;

    i = D_8010BD7C[0];
    temp_s3 = D_8010BD7C[1];

    var_s2 = i != 0;
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
            &D_8010BD54, &vs_battle_inventory.armor[i + temp_s3 - 1], 0x28);
        break;
    case 3:
        vs_battle_rMemzero(&D_8010BD54, 0x28);
        _combineArmor(&vs_battle_inventory.armor[i - 1],
            &vs_battle_inventory.armor[temp_s3 - 1], &D_8010BD54, _sydData);
        break;
    }

    itemInfo = &D_8010BD54;
    itemInfo->bodyPart = 0;

    vs_mainMenu_resetStats();

    temp_v1 = arg0 - 1;

    if (temp_v1 >= 2) {
        if (D_8010BD54.id != 0) {
            for (i = 0; i < 16; ++i) {
                vs_mainMenu_equipmentStats[i] = itemInfo->classes[i & 7];
                vs_mainMenu_equipmentStats[16 + i] = itemInfo->affinities[i & 7];
            }

            for (i = 0; i < 4; ++i) {
                vs_mainMenu_equipmentStats[32 + i] = itemInfo->types[i];
                var_a0 += 2;
            }
            vs_mainMenu_setDpPp(itemInfo->currentDp, itemInfo->maxDp, 0, 0);
            vs_mainMenu_setStrIntAgi(
                itemInfo->strength, itemInfo->intelligence, itemInfo->agility, 1);
            vs_mainMenu_equipmentSubtype = 0x10;
            vs_mainMenu_strIntAgi[1].strength = itemInfo->strength;
            vs_mainMenu_strIntAgi[1].intelligence = itemInfo->intelligence;
            vs_mainMenu_strIntAgi[1].agility = itemInfo->agility;
        }
    } else if (var_s2 & arg0) {
        func_800FD700(D_8010BD7C[temp_v1]);
    }
}

int func_801099FC(int arg0)
{
    static int D_8010BC74;
    static char D_8010BC78;
    static char D_8010BC79;

    char** sp10;
    int var_s4;
    int i;
    char* temp_v0;
    int temp_s0;
    int s0_2;
    vs_battle_inventoryArmor* var_s2;

    var_s2 = NULL;
    if (arg0 != 0) {
        D_8010BC79 = arg0;
        func_80103D8C(arg0 + 0xA);
        D_8010BC78 = 0;
        return 0;
    }

    temp_s0 = D_8010BD7C[D_8010BC79 - 1];
    if (temp_s0 != 0) {
        var_s2 = &vs_battle_inventory.armor[temp_s0 - 1];
    }

    switch (D_8010BC78) {
    case 0:
        if (vs_mainmenu_ready() != 0) {
            s0_2 = temp_s0;
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

            *D_8010BCA4 = s0_2;
            var_s4 = 1;

            for (i = 0; i < 16; ++i) {
                temp_s0 = D_800619D8.unk0[i + 0x30];
                if ((temp_s0 != 0) && (temp_s0 != D_8010BD7C[0])
                    && (temp_s0 != D_8010BD7C[1])) {
                    var_s2 = &vs_battle_inventory.armor[temp_s0 - 1];
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
                        D_8010BCA4[var_s4] = temp_s0;
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
        temp_s0 = D_8010BCA4[_itemsListWindow + _itemsListSelection];
        if (temp_s0 != 0) {
            func_800FD700(temp_s0);
        } else {
            vs_mainMenu_resetStats();
        }
        func_800FF9E4(_itemsListSelection + _itemsListWindow, _itemsListState);
        _navigateItemsList(2);
        D_8010BC74 = func_801035E0() + 1;
        if (D_8010BC74 != 0) {
            vs_mainMenu_clearMenuExcept(vs_mainMenu_menuItemIds_none);
            if (D_8010BC74 == -2) {
                return -2;
            }
            if (D_8010BC74 > 0) {
                D_8010BC74 = D_8010BCA4[D_8010BC74 - 1];
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

void func_80109DBC(vs_battle_menuItem_t* arg0, vs_battle_inventoryArmor* arg1)
{
    arg0->icon = arg1->category + 0xE;
    arg0->material = arg1->material;
    arg0->unkD = arg1->bodyPart != 0;
}

int func_80109DEC(int arg0)
{
    static char D_8010BB76 = 0;

    static char D_8010BC7A;
    static char D_8010BC7B;
    static char D_8010BC7C;

    char* sp18[2];
    int sp20;
    int temp_v0_2;
    int temp_s0;
    int temp_v0_6;
    int i;
    int var_s1;
    u_short* var_a0_2;
    int i_2;
    vs_battle_inventoryArmor* var_s3;
    vs_battle_menuItem_t* temp_a0;
    vs_battle_menuItem_t* temp_v0;

    if (arg0 != 0) {
        func_80102A34(5);
        *(u_short*)D_8010BD7C = 0;
        func_80109790(0);
        D_8010BC7B = 1;
        D_8010BC7A = 0;
        return 0;
    }

    var_s1 = 0;
    if (D_8010BD7C[0] != 0) {
        var_s1 = D_8010BD7C[1] > 0;
    }

    D_8010BC7C += 0x10;

    if (D_8010BC7A != 2) {
        D_8010BC7C = 0;
    }

    switch (D_8010BC7A) {
    case 0:
        if (vs_mainmenu_ready() == 0) {
            break;
        }
        func_80102B50(0x497, 0x1C);
        // Fallthrough
    case 1:
        var_s1 = D_8010BD54.id;
        temp_a0 = func_8010785C(2, var_s1);
        if (var_s1 != 0) {
            func_80109DBC(temp_a0, &D_8010BD54);
        }

        for (i = 0; i < 2; ++i) {
            int new_var;
            var_s1 = D_8010BD7C[i];
            if (var_s1 != 0) {
                var_s3 = &vs_battle_inventory.armor[var_s1 - 1];
            }
            temp_v0 = vs_battle_setMenuItem(i + 0xB, 0x14E, 0x22 + i * 0x10, 0x97, 0,
                (char*)(var_s1 == 0 ? vs_mainMenu_menu12Text + (new_var = 0x43D)
                                    : (u_short*)vs_mainMenu_itemNames[var_s3->id]));
            temp_v0->state = 2;
            temp_v0->targetX = 0xA9;

            if (var_s1 == 0) {
                temp_v0->unkA = 1;
            } else {
                func_80109DBC(temp_v0, var_s3);
            }
        }

        D_8010BC7A = 2;
        break;
    case 2:
        if (vs_mainmenu_ready() != 0) {
            if (!(vs_main_buttonsPressed.all & 0x10)) {
                if (var_s1 != 0) {
                    _drawOk(2, D_8010BC7C);
                }
                if (vs_main_buttonsPressed.all & 0x40) {
                    temp_v0_2 = func_80102AB8(5);
                    if (temp_v0_2 != 0) {
                        vs_battle_playMenuLeaveSfx();
                        D_8010BC7B = temp_v0_2;
                        D_8010BD7C[temp_v0_2 - 1] = 0;
                        func_80109790(temp_v0_2);
                        temp_v0 = vs_battle_setMenuItem(temp_v0_2 + 0xA, 0xA9,
                            (temp_v0_2 * 0x10) + 0x12, 0x97, 0,
                            (char*)(vs_mainMenu_menu12Text + 0x43D));
                        temp_v0->selected = 1;
                        temp_v0->unkA = 1;
                        var_s1 = D_8010BD54.id;
                        temp_a0 = func_801077DC(2, var_s1);
                        if (var_s1 != 0) {
                            func_80109DBC(temp_a0, &D_8010BD54);
                        }
                        break;
                    }
                    return func_80103380(1);
                }
                if (vs_main_buttonsPressed.all & 0x800) {
                    if (var_s1 != 0) {
                        vs_battle_playMenuSelectSfx();
                        vs_battle_getMenuItem(D_8010BC7B + 0xA)->selected = 0;
                        D_8010BC7B = 3;
                        D_8010BC7A = 4;
                        func_80109790(3);
                        return 0;
                    }
                }
                i_2 = D_8010BC7B;
                if (vs_main_buttonsPressed.all & 0x20) {
                    if (i_2 == 0) {
                        func_800C02E0();
                    } else {
                        vs_battle_playMenuSelectSfx();
                        if (i_2 == 3) {
                            D_8010BC7A = 4;
                        } else {
                            vs_mainMenu_clearMenuExcept(vs_mainMenu_menuItemIds_none);
                            func_801099FC(i_2);
                            D_8010BC7A = 3;
                        }
                        break;
                    }
                }
                if (vs_main_buttonRepeat & 0x1000) {
                    if (i_2 == 0) {
                        i_2 = var_s1 + 2;
                    } else {
                        --i_2;
                    }
                }
                if (vs_main_buttonRepeat & 0x4000) {
                    if (i_2 == (var_s1 + 2)) {
                        i_2 = 0;
                    } else {
                        ++i_2;
                    }
                }

                if (i_2 != D_8010BC7B) {
                    vs_battle_playMenuChangeSfx();
                    D_8010BC7B = i_2;
                    func_80109790(D_8010BC7B);
                }
                vs_battle_rowTypeBuf[0] = D_8010BD54.id < 1;

                for (var_s1 = 1; var_s1 < 3; ++var_s1) {
                    vs_battle_getMenuItem(var_s1 + 0xA)->selected =
                        (var_s1 ^ D_8010BC7B) == 0;
                    vs_battle_rowTypeBuf[var_s1] = D_8010BD7C[var_s1 - 1] == 0;
                }

                vs_battle_rowTypeBuf[3] = 1;
                func_800FF9E4(i_2, 0x10);
                sp18[1] = (char*)(vs_mainMenu_menu12Text + 0x46A);
                switch (i_2) {
                case 0:
                    if (D_8010BD54.id != 0) {
                        vs_mainMenu_setAccessoryUi(
                            &D_8010BD54, sp18, &sp20, vs_battle_stringBuf);
                    }
                    break;
                case 1:
                case 2:
                    var_s1 = D_8010BD7C[i_2 - 1];
                    if (var_s1 != 0) {
                        vs_mainMenu_setAccessoryUi(&vs_battle_inventory.armor[var_s1 - 1],
                            sp18, &sp20, vs_battle_stringBuf);
                    }
                    break;
                case 3:
                    sp18[1] = (char*)(vs_mainMenu_menu12Text + 0x39E);
                    break;
                }
                vs_mainmenu_setMessage((char*)sp18[1]);
                var_s1 = (((i_2 * 0x10) + 0xA) << 0x10) | 0x9B;
                if (i_2 == 0) {
                    var_s1 -= 0xE;
                }
                if (i_2 == 3) {
                    var_s1 += 0xFFFC0000;
                }
                D_8010BB76 = func_800FFCDC(D_8010BB76, var_s1);
                break;
            }
            return func_80103380(1);
        }
        D_8010BC7C = 0;
        break;
    case 3:
        temp_s0 = func_801099FC(0);
        if (temp_s0 != 0) {
            if (temp_s0 != -2) {
                if (temp_s0 > 0) {
                    var_s1 = D_8010BC7B - 1;
                    if (temp_s0 == D_8010BD7C[D_8010BC7B - 1]) {
                        D_8010BD7C[D_8010BC7B - 1] = 0;
                        func_80102AB8(var_s1);
                    } else {
                        D_8010BD7C[D_8010BC7B - 1] = temp_s0;
                        func_80102A34(var_s1);
                        D_8010BC7B = (D_8010BC7B + 1);
                        if (var_s1 == 1) {
                            if (D_8010BD7C[0] == 0) {
                                D_8010BC7B = var_s1;
                            }
                        }
                    }
                    func_80109790(D_8010BC7B);
                }
                D_8010BC7A = 1;
                break;
            }
            return func_80103380(1);
        }
        break;
    case 4:
        vs_battle_renderEquipStats(2);
        _confirmCombine(2);
        var_s1 = 0;

        for (i = 0; i < 2; ++i) {
            var_s1 |= vs_battle_inventory.armor[D_8010BD7C[i] - 1].bodyPart;
        }
        if (var_s1 == 0) {
            var_a0_2 = vs_mainMenu_menu12Text + 0x42B;
        } else {
            var_a0_2 = vs_mainMenu_menu12Text + 0x4A7;
        }
        vs_mainmenu_setMessage((char*)var_a0_2);
        D_8010BC7A = 5;
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
            func_800FBBD4(-1);
            vs_mainMenu_drawDpPpbars(4);
            vs_mainMenu_clearMenuExcept(vs_mainMenu_menuItemIds_none);
            func_800FA810(0);
            for (i = 0; i < 2; ++i) {
                var_s3 = &vs_battle_inventory.armor[D_8010BD7C[i] - 1];
                var_s1 = var_s3->bodyPart;
                if (var_s1 != 0) {
                    vs_battle_equipArmor(var_s1 - 1, NULL);
                    var_s3->bodyPart = 0;
                }
                func_800FE3E0(4, D_8010BD7C[i]);
            }
            temp_s0 = D_8010BD7C[0];
            var_s3 = &vs_battle_inventory.armor[temp_s0 - 1];
            vs_battle_copyAligned(var_s3, &D_8010BD54, 0x28);
            var_s3->index = temp_s0;
            vs_mainMenu_rebuildInventory(4);
            return 1;
        case 2:
            vs_battle_playMenuLeaveSfx();
            vs_battle_renderEquipStats(1);
            D_8010BC7A = temp_v0_6;
            break;
        case 3:
            return func_80103380(1);
        }
        break;
    }
    return 0;
}

int func_8010A63C(int arg0)
{
    int i;
    vs_battle_inventoryArmor* var_a1 = vs_battle_inventory.armor;
    int var_a2 = 0;

    if (arg0 == 2) {
        for (i = 0; i < 16; ++i, ++var_a1) {
            int var_v1 = 0;
            if (var_a1->id != 0) {
                var_v1 = (var_a1->category ^ 7) > 0;
            }
            var_a2 += var_v1;
        }
    } else {
        var_a2 = vs_mainMenu_getItemCount((arg0 * 2) | 1, 0);
    }
    return var_a2;
}

int func_8010A6BC(int arg0)
{
    static int (*D_8010BB78[])(int) = { func_80107F14, func_80108EC4, func_80109DEC };

    static char D_8010BC7D;
    static char D_8010BC7E;

    char* text[6];
    int temp_a2;
    int temp_v0;
    int i;
    int temp_s1;

    if (arg0 != 0) {
        D_8010BC7E = 1;
        func_800FA92C(5, 1);
        D_8010BC7D = 0U;
        return 0;
    }

    switch (D_8010BC7D) {
    case 0:
        if (vs_mainmenu_ready() != 0) {
            for (i = 0; i < 3; ++i) {
                temp_a2 = func_8010A63C(i);
                text[i * 2] = (char*)&vs_mainMenu_menu12Text
                    [vs_mainMenu_menu12Text[i + VS_MENU12_BIN_INDEX_blade]];
                text[i * 2 + 1] =
                    temp_a2 < 2 ? (char*)&vs_mainMenu_menu12Text[vs_mainMenu_menu12Text
                                          [VS_MENU12_BIN_INDEX_noItems - (temp_a2 * 4)]]
                                : (char*)&vs_mainMenu_menu12Text[vs_mainMenu_menu12Text
                                          [i + VS_MENU12_BIN_INDEX_combineBlades]];
                vs_battle_rowTypeBuf[i] = temp_a2 < 2;
            }

            temp_s1 = vs_main_settings.cursorMemory;
            if (D_8010BC7E == 0) {
                vs_main_settings.cursorMemory = 1;
            }
            D_8010BC7E = 0;
            vs_mainmenu_setMenuRows(3, 0x23D, text, vs_battle_rowTypeBuf);
            vs_main_settings.cursorMemory = temp_s1;
            D_8010BC7D = 1;
        }
        break;
    case 1:
        func_800FF9E4(func_801008B0(), D_801023D0);
        temp_v0 = vs_mainmenu_getSelectedRow();
        i = temp_v0 + 1;
        if (i != 0) {
            if (i < 0) {
                vs_mainMenu_clearMenuExcept(0);
                return i;
            }
            vs_mainMenu_clearMenuExcept(vs_mainMenu_menuItemIds_none);
            D_8010BB78[temp_v0](1);
            vs_menuC_loadSyd(i);
            D_8010BC7D = temp_v0 + 2;
        }
        break;
    case 2:
    case 3:
    case 4:
        if (vs_menuC_loadSyd(0) != 0) {
            i = D_8010BB78[D_8010BC7D - 2](0);
            if (i != 0) {
                vs_main_freeHeapR(_sydData);
                _sydData = NULL;
                if (i == -1) {
                    D_8010BC7D = 5;
                    break;
                }
                return i;
            }
        }
        break;
    case 5:
        if (vs_mainmenu_ready() != 0) {
            func_800FFBC8();
            _addMenuTitle(0, 0x57);
            _addMenuTitle(0xF, 0xED);
            D_8010BC7D = 0U;
        }
        break;
    }
    return 0;
}

int func_8010A978(char* state)
{
    static char D_8010BC7F;

    char* sp10[12];
    int i;
    int temp_v0_5;
    vs_battle_menuItem_t* temp_v0;

    switch (*state) {
    case 0:
        D_8010BC7F = 1;
        // fallthrough
    case 1:

        for (i = 0; i < 7; ++i) {
            vs_mainMenu_rebuildInventory(i);
        }
        func_80100414(0x7FE, 0x80);
        temp_v0 = vs_battle_getMenuItem(0);
        if ((temp_v0->state != 1) || (temp_v0->initialX != 0xB4)) {
            _addMenuTitle(0, 0x57);
        }
        *state = 2;
        break;
    case 2:
        if (vs_mainmenu_ready() != 0) {
            for (i = 0; i < 6; ++i) {
                sp10[i * 2] =
                    (char*)&vs_mainMenu_menu12Text[vs_mainMenu_menu12Text[i * 2 + 1]];
                sp10[i * 2 + 1] =
                    (char*)&vs_mainMenu_menu12Text[vs_mainMenu_menu12Text[i * 2 + 2]];
                vs_battle_rowTypeBuf[i] = 0;
            }

            i = vs_mainMenu_getItemCount(0, 0);
            if (i == 8) {
                sp10[1] =
                    (char*)&vs_mainMenu_menu12Text[VS_MENU12_BIN_OFFSET_weaponsFull];
                vs_battle_rowTypeBuf[0] = 1;
            }
            if (i == 0) {
                sp10[7] = (char*)&vs_mainMenu_menu12Text[VS_MENU12_BIN_OFFSET_noWeapons];
                vs_battle_rowTypeBuf[3] = 1;
            }
            _workshopFlags = vs_battle_getWorkshopFlags();
            if (!_workshopFlags) {
                for (i = 3; i != 0;) {
                    if (++i == 6) {
                        i = 0;
                    }
                    sp10[i * 2 + 1] = (char*)&vs_mainMenu_menu12Text
                        [VS_MENU12_BIN_OFFSET_notInWorkshop];
                    vs_battle_rowTypeBuf[i] = 1;
                }
            }
            i = vs_main_settings.cursorMemory;
            if (D_8010BC7F == 0) {
                vs_main_settings.cursorMemory = 1;
            }
            D_8010BC7F = 0;
            vs_mainmenu_setMenuRows(6, 0x135, sp10, vs_battle_rowTypeBuf);
            vs_main_settings.cursorMemory = i;
            *state = 3;
        }
        break;
    case 3:
        func_800FF9E4(func_801008B0(), D_801023D0);
        temp_v0_5 = vs_mainmenu_getSelectedRow();
        i = temp_v0_5 + 1;
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
                switch (temp_v0_5) {
                case 0:
                    _assembleMenu(1);
                    *state = 4;
                    break;
                case 1:
                    _attachGemsTopMenu(1);
                    *state = 5;
                    break;
                case 2:
                    func_80106C64(1);
                    *state = 6;
                    break;
                case 3:
                    func_80106ECC(1);
                    *state = 7;
                    break;
                case 4:
                    func_801072FC(1);
                    *state = 8;
                    break;
                case 5:
                    func_8010A6BC(1);
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
        i = func_80106C64(0);
        if (i != 0) {
            if (i == -2) {
                *state = 0xB;
            } else {
                *state = 0xA;
            }
        }
        break;
    case 7:
        i = func_80106ECC(0);
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
        i = func_801072FC(0);
        if (i != 0) {
            if (i == -2) {
                *state = 0xB;
            } else {
                *state = 0xA;
            }
        }
        break;
    case 9:
        i = func_8010A6BC(0);
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

void _setClassAffinities(signed char* first, signed char* second, signed char* result,
    int materialsDifferent, int setAffinities)
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

void _setTypeValues(
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

static char* _combinationResults;
static char* _materialResults;
static void* D_8010BD88;

vs_battle_inventoryBlade* func_8010B2B4(vs_battle_inventoryBlade* arg0,
    vs_battle_inventoryBlade* arg1, vs_battle_inventoryBlade* arg2, void* sydData)
{
    char* temp_a0;
    int new_var;

    _combinationResults = sydData + ((_syd*)sydData)->combinationsOffset;
    _materialResults = sydData + ((_syd*)sydData)->materialsOffset;
    D_8010BD88 = sydData + ((_syd*)sydData)->initDataOffset;

    vs_main_memcpy(arg2, arg0, sizeof *arg2);

    new_var = arg0->category * 0x32 + arg0->material * 0x1F4 + arg1->material * 0xA
            + arg1->category;
    arg2->material = _materialResults[new_var - 0x5FA];
    arg2->subId = _combinationResults[(arg0->id * 0x60) + arg1->id];
    arg2->id = arg2->subId;

    temp_a0 = D_8010BD88 + (arg2->id * 0x10);
    arg2->wepId = temp_a0[1];
    arg2->category = temp_a0[2];
    arg2->cost = temp_a0[5];
    arg2->damageType = temp_a0[3] & 3;
    arg2->costType = temp_a0[4] & 7;
    arg2->unk12 = temp_a0[6];
    arg2->range = *(vs_battle_range_t*)&temp_a0[12];
    arg2->strength = temp_a0[8] + D_8004EDDC[arg2->material][0x18];
    arg2->intelligence = temp_a0[9] + D_8004EDDC[arg2->material][0x1A];
    arg2->agility = temp_a0[10] + D_8004EDDC[arg2->material][0x1C];
    arg2->maxDp = arg2->currentDp = (arg0->maxDp + arg1->maxDp) >> 1;
    arg2->maxPp = ((arg0->maxPp + arg1->maxPp) >> 1);
    arg2->currentPp = ((arg0->currentPp + arg1->currentPp) >> 1);
    if (arg0->material == arg1->material) {
        _setClassAffinities(arg0->classes, arg1->classes, arg2->classes, 0, 0);
        _setClassAffinities(arg0->affinities, arg1->affinities, arg2->affinities, 0, 1);
    } else {
        _setClassAffinities(arg0->classes, arg1->classes, arg2->classes, 1, 0);
        _setClassAffinities(arg0->affinities, arg1->affinities, arg2->affinities, 1, 1);
    }
    return arg2;
}

static _armorInfo* _shieldCombinationInitData;

vs_battle_inventoryArmor* _combineShields(vs_battle_inventoryArmor* first,
    vs_battle_inventoryArmor* second, vs_battle_inventoryArmor* result, void* sydData)
{
    _armorInfo* info;

    _combinationResults = sydData + ((_syd*)sydData)->combinationsOffset;
    _materialResults = sydData + ((_syd*)sydData)->materialsOffset;
    _shieldCombinationInitData = sydData + ((_syd*)sydData)->initDataOffset;

    vs_main_memcpy(result, first, sizeof *result);

    result->material = _materialResults[(first->material * 8) + second->material];
    result->subId = _combinationResults[(first->subId * 0x11) + second->subId];
    result->id = result->subId + 0x7E;
    info = &_shieldCombinationInitData[result->subId];
    result->wepId = info->wepId;
    result->category = info->category;
    result->gemSlots = info->gemSlots;
    result->strength = info->strength + D_8004EDDC[result->material][0x18];
    result->intelligence = info->intelligence + D_8004EDDC[result->material][0x1A];
    result->agility = info->agility + D_8004EDDC[result->material][0x1C];
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

vs_battle_inventoryArmor* _combineArmor(vs_battle_inventoryArmor* first,
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
    result->id = result->subId + 0x7E;
    info = &_combinationInitData[result->subId];
    result->category = info->category;
    result->strength = info->strength + D_8004EDDC[result->material][0x18];
    result->intelligence = info->intelligence + D_8004EDDC[result->material][0x1A];
    result->agility = info->agility + D_8004EDDC[result->material][0x1C];
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
