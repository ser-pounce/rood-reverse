#include "58EC.h"
#include "C48.h"
#include "2D10.h"
#include "src/SLUS_010.40/overlay.h"
#include "src/BATTLE/BATTLE.PRG/573B8.h"
#include "src/BATTLE/BATTLE.PRG/5BF94.h"
#include "gpu.h"
#include "vs_string.h"
#include <libetc.h>

typedef struct {
    u_short name[14];
    int menuRowFlags;
    u_short description[48];
} _itemsText_t;

typedef struct textHeader_t {
    char text[14];
    char disabled;
    char x;
} textHeader_t;

extern u_long* D_1F800000[];

char vs_mainMenu_actionMenuState = 0;
static u_short* _sortItemsTextBuf = NULL;
static int _selectedItemAction = 0;
static char _actionsSubMenuId = 0;
static char _itemActionCount = 0;
static char _itemActionListOffset = 0;

char _rangeRiskData[8];
short D_80102488[4];
char D_80102490[8];
short D_80102498[4];

char _menuActionsPageOffset;
char vs_mainMenu_currentStatusViewItem;
char bss_7[2] __attribute__((unused));
u_short* vs_mainMenu_menu12Text;
short vs_mainMenu_strIntAgi[8];
u_char vs_mainMenu_selectedStatusViewElement;
char vs_mainMenu_itemStatPage;
char bss_3[6] __attribute__((unused));
short vs_mainMenu_equipmentStats[64];
u_short* vs_mainMenu_itemHelp;
char vs_mainMenu_enabledStatPages;
char vs_mainMenu_equipmentSubtype;
char bss_4[18] __attribute__((unused)); // Garbage, patched in MAINMENU_PRG.py
textHeader_t _textHeaders[2];
char vs_mainMenu_containerEmptyBackup;

void vs_mainMenu_addMenuActions(
    int rowCount, int subMenuId, char* menuText[], int rowTypes[])
{
    int scrollableRows;

    int i = 0;
    int scrollOffset = 0;
    _menuActionsPageOffset = rowCount >> 8;
    rowCount &= 0xFF;

    if (!_menuActionsPageOffset) {
        if (rowCount < 7) {
            _menuActionsPageOffset = 10 - rowCount;
        } else {
            _menuActionsPageOffset = 3;
        }
    }

    _actionsSubMenuId = subMenuId;

    if (subMenuId == actionMenuDiscard) {
        i = 1;
    } else if ((vs_main_settings.cursorMemory != 0) && (subMenuId != 3)) {
        i = D_800F4EE8.cursorMemories[subMenuId * 2];
        scrollOffset = D_800F4EE8.cursorMemories[subMenuId * 2 + 1];
    }

    scrollableRows = rowCount - 7;

    if (scrollableRows < 0) {

        i += scrollOffset;
        scrollOffset = 0;

        if (i >= rowCount) {
            i = 0;
        }

    } else if (scrollableRows < scrollOffset) {

        if ((i + scrollOffset) >= rowCount) {
            i = 0;
            scrollOffset = 0;
        } else {
            i += scrollOffset - scrollableRows;
            scrollOffset = scrollableRows;
        }
    }

    if ((scrollOffset > 0) && (i == 0)) {
        i = 1;
        --scrollOffset;
    }

    if ((scrollOffset < scrollableRows) && (i == 6)) {
        i = 5;
        ++scrollOffset;
    }

    _selectedItemAction = i;
    _itemActionListOffset = scrollOffset;
    _itemActionCount = rowCount;
    vs_mainMenu_actionMenuState = 0;

    _sortItemsTextBuf = vs_main_allocHeapR(rowCount * 128);

    for (i = 0; i < rowCount; ++i) {
        char* text;

        ((_itemsText_t*)_sortItemsTextBuf)[i].menuRowFlags = rowTypes[i];

        if (menuText[i * 2] != NULL) {
            vs_battle_copyAligned(&_sortItemsTextBuf[i * 64], menuText[i * 2], 26);

            _sortItemsTextBuf[(i * 64) + 13] =
                vs_char_terminator << 8 | vs_char_terminator;
        } else {
            _sortItemsTextBuf[i * 64] = vs_char_terminator << 8 | vs_char_terminator;
        }

        text = menuText[i * 2 + 1];

        if (text != NULL) {
            ((_itemsText_t*)_sortItemsTextBuf)[i].description[0] = vs_char_chunkSize;

            vs_battle_copyAligned(&_sortItemsTextBuf[(i * 64) + 17], text, 92);

            ((_itemsText_t*)_sortItemsTextBuf)[i].description[47] =
                vs_char_terminator << 8 | vs_char_terminator;
        } else {
            ((_itemsText_t*)_sortItemsTextBuf)[i].description[0] =
                vs_char_terminator << 8 | vs_char_terminator;
        }
    }
}

int vs_mainMenu_getSelectedAction(void)
{
    return _selectedItemAction + _itemActionListOffset;
}

int vs_mainMenu_actionInputProcessed(void)
{
    return _sortItemsTextBuf == NULL ? _selectedItemAction : -1;
}

/**
 * Draws the action menu row at the specified position.
 *
 * @return The selected row.
 */
static vs_battle_menuItem_t* _renderActionRow(int row, int x)
{
    vs_battle_menuItem_t* menuItem = vs_battle_setMenuItem(row + 32, x,
        ((row + _menuActionsPageOffset) * 16) + 18, 126, 0,
        (char*)((_itemsText_t*)_sortItemsTextBuf)[_itemActionListOffset + row].name);

    int flags =
        ((_itemsText_t*)_sortItemsTextBuf)[_itemActionListOffset + row].menuRowFlags;

    menuItem->unselectable = flags & 1;

    if ((row == 0) && (_itemActionListOffset != 0)) {
        menuItem->fadeEffect = menuItem_fadeTop;
    }

    return menuItem;
}

void vs_mainMenu_renderItemActionMenu(void)
{
    static char cursorAnimStep = 0;

    int selectedAction;
    int i;
    int previousOffset;
    vs_battle_menuItem_t* menuItem;

    if (vs_mainMenu_actionMenuState < 10) {
        menuItem = _renderActionRow(vs_mainMenu_actionMenuState, -194);
        menuItem->state = 5;
        menuItem->targetPosition0 = 0;

        ++vs_mainMenu_actionMenuState;

        if (vs_mainMenu_actionMenuState == _itemActionCount) {
            vs_mainMenu_actionMenuState = 16;
        }

        if (vs_mainMenu_actionMenuState == 7) {

            if ((vs_mainMenu_actionMenuState + _itemActionListOffset)
                < _itemActionCount) {
                menuItem->fadeEffect = 2;
            }

            vs_mainMenu_actionMenuState = 16;
        }

    } else {

        menuItem = vs_battle_getMenuItem(_selectedItemAction + 32);

        vs_mainmenu_setInformationMessage(
            (char*)(_sortItemsTextBuf
                    + (((_selectedItemAction + _itemActionListOffset) * 64) + 16)));

        switch (vs_mainMenu_actionMenuState) {
        case 16:
            if (vs_mainmenu_ready() != 0) {
                vs_mainMenu_actionMenuState = 17;
            }
            break;

        case 17:
            selectedAction = _selectedItemAction + _itemActionListOffset;
            previousOffset = _itemActionListOffset;

            if (vs_main_buttonsPressed.all & PADRup) {

                vs_main_freeHeapR(_sortItemsTextBuf);

                _sortItemsTextBuf = NULL;
                D_800F4EE8.cursorMemories[_actionsSubMenuId * 2] = _selectedItemAction;
                D_800F4EE8.cursorMemories[_actionsSubMenuId * 2 + 1] =
                    _itemActionListOffset;
                _selectedItemAction = -3;
                break;
            }

            if (vs_main_buttonsPressed.all & PADRright) {
                if (menuItem->unselectable == 0) {
                    menuItem->selected = 1;
                    vs_main_freeHeapR(_sortItemsTextBuf);
                    _sortItemsTextBuf = NULL;
                    D_800F4EE8.cursorMemories[_actionsSubMenuId * 2] =
                        _selectedItemAction;
                    D_800F4EE8.cursorMemories[_actionsSubMenuId * 2 + 1] =
                        _itemActionListOffset;
                    _selectedItemAction = selectedAction;
                    break;
                }
                vs_battle_playInvalidSfx();
            }

            menuItem->selected = 0;

            if (vs_main_buttonsPressed.all & PADRdown) {
                vs_main_freeHeapR(_sortItemsTextBuf);
                _sortItemsTextBuf = NULL;
                D_800F4EE8.cursorMemories[_actionsSubMenuId * 2] = _selectedItemAction;
                D_800F4EE8.cursorMemories[_actionsSubMenuId * 2 + 1] =
                    _itemActionListOffset;
                _selectedItemAction = -2;
                break;
            }

            if (vs_main_buttonRepeat & PADLup) {
                if (_itemActionCount < 8) {
                    if (_selectedItemAction == 0) {
                        _selectedItemAction = _itemActionCount - 1;
                    } else {
                        --_selectedItemAction;
                    }
                } else if (_itemActionListOffset == 0) {
                    if (_selectedItemAction == 0) {
                        if (vs_main_buttonsPressed.all & PADLup) {
                            _selectedItemAction = 6;
                            _itemActionListOffset = _itemActionCount - 7;
                        }
                    } else {
                        --_selectedItemAction;
                    }
                } else if (_selectedItemAction == 1) {
                    --_itemActionListOffset;
                } else {
                    --_selectedItemAction;
                }
            }

            if (vs_main_buttonRepeat & PADLdown) {
                if (_itemActionCount < 8) {
                    if (_selectedItemAction == (_itemActionCount - 1)) {
                        _selectedItemAction = 0;
                    } else {
                        ++_selectedItemAction;
                    }
                } else if (_itemActionListOffset == (_itemActionCount - 7)) {
                    if (_selectedItemAction == 6) {
                        if (vs_main_buttonsPressed.all & PADLdown) {
                            _selectedItemAction = 0;
                            _itemActionListOffset = 0;
                        }
                    } else {
                        ++_selectedItemAction;
                    }
                } else if (_selectedItemAction == 5) {
                    _itemActionListOffset = _itemActionListOffset + 1;
                } else {
                    _selectedItemAction += 1;
                }
            }

            if (selectedAction != (_selectedItemAction + _itemActionListOffset)) {
                vs_battle_playMenuChangeSfx();

                if (_itemActionListOffset != previousOffset) {
                    int actionCount;

                    char gradientStates[_itemActionCount];

                    for (i = 0; i < _itemActionCount; ++i) {
                        gradientStates[i] = 0;
                    }

                    actionCount = _itemActionCount;

                    if (actionCount > 7u) {
                        actionCount = 7;
                    }

                    for (i = 0; i < actionCount; ++i) {
                        gradientStates[i + previousOffset] =
                            vs_battle_getMenuItem(i + 32)->gradientState;
                    }

                    for (i = 0;;) {
                        menuItem = _renderActionRow(i, 0);
                        menuItem->gradientState =
                            gradientStates[i + _itemActionListOffset];
                        ++i;

                        if (i == _itemActionCount) {
                            break;
                        }

                        if (i == 7) {
                            if ((_itemActionListOffset + 7) < _itemActionCount) {
                                menuItem->fadeEffect = 2;
                            }
                            break;
                        }
                    }
                }
            }

            menuItem = vs_battle_getMenuItem(_selectedItemAction + 32);
            menuItem->selected = 1;
            cursorAnimStep =
                vs_mainMenu_renderCursor(cursorAnimStep, vs_getXY(0, menuItem->y - 8));

            break;
        }
    }
}

void vs_mainMenu_printInformation(int sourceRow, int actionMenuState)
{
    if (actionMenuState < 16) {
        return;
    }

    if (vs_battle_rowTypeBuf[sourceRow] & 1) {

        if ((vs_main_settings.information == 0)
            && (vs_main_buttonsState & (PADLup | PADLdown))) {
            return;
        }

        vs_battle_initInformationTextBox(informationTextBoxHeaderCaution);

        vs_battle_textBoxes[7].state = 11;

    } else if (vs_main_settings.information != 0) {

        vs_battle_initInformationTextBox(informationTextBoxHeaderInformation);

        vs_battle_textBoxes[7].state = 11;

    } else {
        vs_battle_textBoxes[7].state = 0;
    }
}

char vs_mainMenu_displaySkillCost = 0;
char vs_mainMenu_cursorColor = 0;
char vs_mainMenu_hideMenu = 0;
int vs_mainMenu_backgroundFadeStep = 0;
char _backgroundFadeState = 0;
static short _backgroundOtOffset = -4;
static short _backgroundBrightness = 128;
static char _menuActionCurrent = 0;
static char _menuActionNext = 0;

void vs_mainMenu_setMenuCommand(enum vs_mainMenu_menuCommands action)
{
    _menuActionNext = action;
}

/**
 * Renders the menu command, sliding in and out as necessary.
 */
static void _renderMenuCommand(void)
{
    static int actionYPos = 0;
    static u_short menuActionUvs[] = { vs_getUV(0, 0), vs_getUV(0, 64), vs_getUV(64, 64),
        vs_getUV(100, 64), vs_getUV(132, 64), vs_getUV(188, 64), vs_getUV(0, 74) };
    static int menuActionRenderPostitions[] = { vs_getXY(0, 0), vs_getXY(62, 10),
        vs_getXY(36, 10), vs_getXY(30, 10), vs_getXY(56, 10), vs_getXY(30, 10),
        vs_getXY(32, 10), vs_getXY(0, 0) };

    u_long* prim;
    int action = _menuActionCurrent;
    int y = actionYPos;

    if (action != _menuActionNext) {
        if (y == 0) {
            _menuActionCurrent = _menuActionNext;
            return;
        }
        y -= 2;
    } else if (y < 12) {
        y += 2;
    }

    actionYPos = y;

    if (action != 0) {
        prim = vs_battle_setSprite((1 << 8) | 128,
            (312 - (menuActionRenderPostitions[action] & 0xFF))
                | ((actionYPos - 4) << 16),
            menuActionRenderPostitions[action], D_1F800000[2]);
        prim[1] = vs_getTpage(768, 0, clut4Bit, semiTransparencyFull, ditheringOff);
        prim[4] = menuActionUvs[action] | vs_getUV0Clut(0, 0, 848, 223);
    }
}

void vs_mainMenu_toggleBackgroundFade(int fadeState)
{
    if (fadeState != 0) {
        _backgroundOtOffset = -4;
        _backgroundBrightness = 128;
    }

    _backgroundFadeState = fadeState;
}

void vs_mainMenu_deactivateMenuItem(int row)
{
    vs_battle_menuItem_t* menuItem = &vs_battle_menuItems[row];
    menuItem->state = menuItemStateInactive;
}

void vs_mainMenu_dismissInformationBox(void) { vs_battle_dismissTextBox(7); }

void vs_mainMenu_initInformationBox(void)
{
    if (vs_main_settings.information != 0) {
        vs_battle_initInformationTextBox(informationTextBoxHeaderInformation);
    } else {
        vs_mainMenu_dismissInformationBox();
    }
}

void vs_mainmenu_setInformationMessage(char* message)
{
#pragma vsstring(start)
    static char infoMessage[] =
        "|!0|000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000\0\0";
#pragma vsstring(end)

    vs_battle_memcpy(&infoMessage[2], message, 96);
    vs_battle_textBoxes[7].unk0.unk0_24 = 32;
    vs_battle_setTextBox(7, infoMessage);
}

void vs_mainmenu_renderButton(
    enum vs_mainMenu_buttonIDs buttonId, int x, int y, u_long* before)
{
    if (before == NULL) {
        before = D_1F800000[2];
    }

    vs_battle_setSpriteDefaultTexPage(
        128, vs_getXY_2(x, y), vs_getWH(16, 16), before)[4] =
        vs_getUV0Clut((buttonId & 3) * 16, ((buttonId & 4) * 4) + 128, 944, 223);
}

int vs_mainMenu_renderCursor(u_int animStep, int xy)
{
    int clut;
    int cursorAnimStep = animStep >> (vs_mainMenu_cursorColor * 8);

    u_long* prim = vs_battle_setSpriteDefaultTexPage(
        vs_battle_cursorBrightnessAnimation[cursorAnimStep], xy, vs_getWH(16, 16),
        D_1F800000[2]);

    if (vs_mainMenu_cursorColor == 0) {
        clut = vs_getUV0Clut(32, 48, 896, 223);
    } else {
        clut = vs_getUV0Clut(32, 48, 928, 223);
    }

    prim[4] = clut;
    vs_mainMenu_cursorColor = 0;

    return (cursorAnimStep + 1) & 0xF;
}

int vs_mainMenu_renderIntColor(int value, int xy, int color, u_long* before)
{
    int buf;
    int bcd = value;

    if (value < 0) {
        bcd = -value;
    }

    do {
        bcd = vs_battle_toBCD(bcd);
        buf = ((bcd & 0xF) << 8) | ('0' << 8) | '#';

        vs_battle_renderTextRawColor((char*)&buf, xy, color, before);

        bcd >>= 4;
        xy -= 8;
    } while (bcd != 0);

    if (value < 0) {
        buf = ('-' << 8) | '#';
        vs_battle_renderTextRawColor((char*)&buf, xy + 1, color, before);
    }

    return xy;
}

int vs_mainMenu_renderIntWithThreshold(int value, int xy, int threshold, u_long* before)
{
    int color = vs_getRGB888(128, 128, 128);

    if (threshold < value) {
        color = vs_getRGB888(32, 64, 128);
    }

    if (value < threshold) {
        color = vs_getRGB888(128, 64, 32);
    }

    return vs_mainMenu_renderIntColor(value, xy, color, before);
}

void vs_mainMenu_renderIntColorDefault(int value, int xy, u_long* before)
{
    vs_mainMenu_renderIntColor(value, xy, vs_getRGB888(128, 128, 128), before);
}

/**
 * Fades the top or bottom 16 pixels of the icon, used for elements at the
 * very top or bottom of the menu.
 */
static void _renderFeatheredIcon(int direction, int xy, int uvClut, u_long* before)
{
    int i = 0;

    if (direction < 0) {
        xy += vs_getXY(0, 15);
        uvClut += vs_getUV0Clut(0, 15, 0, 0);
    }

    do {
        ++i;

        vs_battle_setSpriteDefaultTexPage(
            (i * 8) | (1 << 8), xy, vs_getWH(16, 1), before)[4] = uvClut;

        xy += vs_getXY(0, direction);
        uvClut += vs_getUV0Clut(0, direction, 0, 0);
    } while (i < 16);
}

static void func_800FFF38(int arg0, int arg1)
{
    u_long* temp_a1;
    int new_var2;

    temp_a1 = vs_battle_setSpriteDefault(0x70007, arg1);
    new_var2 = (((arg0 / 3) * 8) + 0xD8) | ((((arg0 % 3) * 8) + 0xC8) << 8);
    if (arg0 == 2) {
        temp_a1[4] = new_var2 | 0x37FA0000;
    } else {
        temp_a1[4] = new_var2 | 0x37F90000;
    }
}

static void _renderOutsetIcon(int icon, int xy)
{
    vs_battle_setSpriteDefault(vs_getWH(16, 16), xy)[4] =
        vs_getUV0Clut(96 - (icon * 16), 128, 976, 223);
}

void vs_mainMenu_renderMenuRowIcon(int icon, int x, int y)
{
    static u_short iconUvs[] = { vs_getUV(80, 96), vs_getUV(144, 96), vs_getUV(160, 96),
        vs_getUV(112, 96), vs_getUV(128, 96), vs_getUV(176, 96), vs_getUV(208, 96),
        vs_getUV(96, 96), vs_getUV(48, 112), vs_getUV(128, 112), vs_getUV(0, 112),
        vs_getUV(16, 112), vs_getUV(32, 112), vs_getUV(224, 96), vs_getUV(64, 112),
        vs_getUV(80, 112), vs_getUV(96, 112), vs_getUV(112, 112), vs_getUV(128, 112),
        vs_getUV(144, 112), vs_getUV(160, 112), vs_getUV(32, 96), vs_getUV(176, 112),
        vs_getUV(120, 128), vs_getUV(136, 128), vs_getUV(152, 128), vs_getUV(168, 128),
        vs_getUV(184, 128), vs_getUV(200, 128), vs_getUV(216, 128), vs_getUV(232, 128),
        vs_getUV(96, 128), vs_getUV(80, 128) };

    int fade = icon >> 16;
    int brightness = (icon >> 8) & 1;
    icon = (icon - 1) & 0xFF;

    if (fade == 0) {
        u_long* prim = vs_battle_setSpriteDefaultTexPage(
            64 << brightness, vs_getXY_2(x, y), vs_getWH(16, 16), D_1F800000[2] + 1);

        prim[4] = vs_getUV0Clut(iconUvs[icon], 0, 992, 223);

        if (icon >= 23) {
            prim[3] -= 12;
            prim[4] = vs_getUV0Clut(iconUvs[icon], 0, 976, 223);
        }

    } else {
        if (fade == 2) {
            fade = -1;
        }

        _renderFeatheredIcon(fade, vs_getXY_2(x, y),
            vs_getUV0Clut(iconUvs[icon], 0, 992, 223), D_1F800000[2] + 1);
    }
}

void vs_mainmenu_setSkillCost(int index, char const* text, int xOffset, int disabled)
{
    vs_mainMenu_displaySkillCost = 1;

    vs_battle_rMemcpy(&_textHeaders[index], text, 14);

    _textHeaders[index].disabled = disabled;
    _textHeaders[index].x = xOffset;
}

/**
 * Slides and renders the ability cost element.
 */
static void _renderAbilityCost(void)
{
    static u_char animState = 8;

    u_long* scratch = D_1F800000[1] - 1;

    if (vs_mainMenu_displaySkillCost != 0) {
        if (animState != 0) {
            --animState;
        }
    } else {
        if (animState < 5) {
            animState = 5;
        } else if (animState < 8) {
            ++animState;
        }
    }

    if (animState < 8) {
        int i;
        u_long* poly;
        int x0;
        int x1 = -vs_battle_rowAnimationSteps[animState];

        for (i = 0; i < 2; ++i) {
            vs_battle_renderTextRawColor(_textHeaders[i].text,
                ((x1 + _textHeaders[i].x) & 0xFFFF) | (160 << 16),
                vs_getRGB888(128, 128, 128) >> _textHeaders[i].disabled, NULL);
        }

        x0 = x1 & 0xFFFF;
        poly = D_1F800000[0];

        poly[0] = (*scratch & 0xFFFFFF) | 0x0A000000;
        poly[1] = vs_getTpage(0, 0, clut4Bit, semiTransparencyHalf, ditheringOn);
        poly[2] = vs_getRGB0(primPolyG4, 8, 8, 32);
        poly[3] = x0 | (160 << 16);
        poly[4] = vs_getRGB888(64, 48, 102);
        poly[5] = (x1 + 80) | (160 << 16);
        poly[6] = vs_getRGB888(8, 8, 32);
        poly[7] = x0 | (171 << 16);
        poly[8] = vs_getRGB888(64, 48, 102);
        poly[9] = (x1 + 80) | (171 << 16);
        poly[10] = vs_getTpage(0, 0, clut4Bit, semiTransparencyHalf, ditheringOff);

        *scratch = ((u_long)poly << 8) >> 8;
        D_1F800000[0] = poly + 11;

        vs_battle_addTile(
            scratch, vs_getRGB0(primTile, 0, 0, 0), x0 | (162 << 16), vs_getWH(82, 11));
    }
}

void vs_mainmenu_renderButtonBackground(int x, int y, int w, int h)
{
    int i;
    u_long* var_t2 = D_1F800000[0];
    u_long* temp_v1 = D_1F800000[1] - 3;

    for (i = 0; i < h; ++i) {
        var_t2[0] = vs_getTag(u_long[6], temp_v1[0]);
        var_t2[1] = vs_getTpage(0, 0, 0, 0, ditheringOn);
        var_t2[2] = vs_getRGB0(primLineG2, 64, 56, 32);
        var_t2[3] = ((x & 0xFFFF) | ((y + i) << 0x10));
        var_t2[4] = vs_getRGB888(16, 16, 8);
        var_t2[5] = vs_getXY_2((x + w) - i, y + i);
        var_t2[6] = vs_getTpage(0, 0, clut4Bit, semiTransparencyHalf, ditheringOff);
        temp_v1[0] = (((u_long)var_t2 << 8) >> 8);
        var_t2 += 7;
    }

    D_1F800000[0] = var_t2;
}

void vs_mainMenu_setBackgroundRenderPriority(int otOffset, int brightness)
{
    if (otOffset > 0) {
        vs_battle_lowerScreenUiState |= 2;
    } else {
        vs_battle_lowerScreenUiState &= 1;
    }

    _backgroundOtOffset = otOffset;
    _backgroundBrightness = brightness;
}

void vs_mainMenu_unpackMenubg(u_int* buf)
{
    static RECT rects[] = { { 640, 256, 32, 240 }, { 768, 256, 32, 240 } };

    int var_a2;
    int i;
    u_int var_v1;
    void* data = vs_overlay_slots[2];
    u_int* temp_t1 = data + 0x200;

    for (i = 0, var_a2 = 0; i < 0x1780;) {

        u_int temp_a0 = temp_t1[i++];

        for (var_v1 = temp_a0 & 0xFFFF; var_v1 != 0; --var_v1) {
            buf[var_a2++] = 0;
        }

        for (var_v1 = temp_a0 >> 16; var_v1 != 0; --var_v1) {
            buf[var_a2++] = temp_t1[i++];
        }
    }

    func_8007DFF0(0x1A, 3, 6);
    ClearImage(&rects[0], 0, 0, 0);
    ClearImage(&rects[1], 0, 0, 0);

    if (((vs_battle_menuState.currentState & 0x3F) == 7) && (D_800F4EA0 & 0x200)
        && (vs_main_stateFlags.gameOver == 1)) {
        vs_battle_renderImage(vs_getXY(640, 511), data, vs_getWH(256, 1));
    } else {
        vs_main_loadClut((u_short*)data, 3, 0, 256);
    }

    vs_battle_renderImage(vs_getXY(672, 256), buf, vs_getWH(96, 240));
    vs_mainMenu_setBackgroundRenderPriority(-4, 128);
}

char vs_mainMenu_itemsListRow = 0;
static u_short* _itemsText = NULL;
static int _selectedRow = 0;
static u_char _subMenuId = 0;
static char _subMenuRowInfo = 0;
static char _subMenuPage = 0;
static char _menuRowYOffset = 0;
static u_short _subMenuRowCount = 0;

void vs_mainmenu_setMenuRows(int rowCount, int rowInfo, char* strings[], int rowTypes[])
{
    int temp_v1_2;
    int var_v0;
    u_int var_a0;

    int i = 0;
    int page = 0;
    int subMenuId = rowInfo & 0xFF;
    _menuRowYOffset = (rowInfo >> 0xC);
    _subMenuId = subMenuId;
    rowInfo = (rowInfo >> 8) & 0xF;

    if (vs_main_settings.cursorMemory != 0) {
        i = D_800F4EE8.cursorMemories[subMenuId * 2];
        page = D_800F4EE8.cursorMemories[subMenuId * 2 + 1];
    }

    temp_v1_2 = 10;
    temp_v1_2 = rowCount - temp_v1_2 + rowInfo;

    if (temp_v1_2 < 0) {
        i += page;
        page = 0;
        if (i >= rowCount) {
            i = 0;
        }
    } else {
        if (temp_v1_2 < page) {
            if ((i + page) >= rowCount) {
                i = 0;
                page = 0;
            } else {
                i += page - temp_v1_2;
                page = temp_v1_2;
            }
        }

        var_v0 = page < temp_v1_2;

        if ((page > 0) && (i == 0)) {
            i = 1;
            page -= 1;
            var_v0 = page < temp_v1_2;
        }

        if (var_v0 != 0) {
            var_a0 = rowCount << 7;
            if (i == (9 - rowInfo)) {
                i -= 1;
                page += 1;
                ;
            }
        }
    }

    _selectedRow = i;

    _subMenuPage = page;
    _subMenuRowCount = rowCount;
    _subMenuRowInfo = rowInfo;
    vs_mainMenu_itemsListRow = 0;

    _itemsText = vs_main_allocHeapR(rowCount * 128);

    for (i = 0; i < rowCount; ++i) {
        char* text;

        ((_itemsText_t*)_itemsText)[i].menuRowFlags = rowTypes[i];

        if (strings[i * 2] != NULL) {
            vs_battle_copyAligned(&_itemsText[i * 64], strings[i * 2], 26);

            _itemsText[(i * 64) + 13] = vs_char_terminator << 8 | vs_char_terminator;
        } else {
            _itemsText[i * 64] = vs_char_terminator << 8 | vs_char_terminator;
        }

        text = strings[i * 2 + 1];

        if (text != NULL) {
            ((_itemsText_t*)_itemsText)[i].description[0] = vs_char_chunkSize;

            vs_battle_copyAligned(&_itemsText[(i * 64) + 17], text, 92);

            ((_itemsText_t*)_itemsText)[i].description[47] =
                vs_char_terminator << 8 | vs_char_terminator;
        } else {
            ((_itemsText_t*)_itemsText)[i].description[0] =
                vs_char_terminator << 8 | vs_char_terminator;
        }
    }
}

int vs_mainMenu_storeCursor(void)
{
    vs_main_freeHeapR(_itemsText);

    _itemsText = NULL;
    D_800F4EE8.cursorMemories[_subMenuId * 2] = _selectedRow;
    D_800F4EE8.cursorMemories[_subMenuId * 2 + 1] = _subMenuPage;

    return (_selectedRow + _subMenuPage) | ((_selectedRow + (_subMenuRowInfo * 10)) << 8);
}

int vs_mainMenu_getConfirmedRow(void) { return _selectedRow + _subMenuPage; }

int vs_mainmenu_getSelectedRow(void) { return _itemsText != NULL ? -1 : _selectedRow; }

static vs_battle_menuItem_t* func_801008F0(int row, int x)
{
    int temp_v1;
    vs_battle_menuItem_t* menuItem = vs_battle_setMenuItem(row + (_subMenuRowInfo * 10),
        x, ((row + _subMenuRowInfo) * 16) + 18, _menuRowYOffset + 126, 0,
        (char*)((_itemsText_t*)_itemsText)[_subMenuPage + row].name);

    int flags = ((_itemsText_t*)_itemsText)[_subMenuPage + row].menuRowFlags;

    menuItem->unselectable = flags & 1;
    menuItem->backgroundWidth += (flags & 2) * 12;

    temp_v1 = (flags >> 3) & 1;

    menuItem->invertGradient = temp_v1;
    menuItem->fontColor = temp_v1 | ((flags >> 2) & 1);
    menuItem->rowIcon = (flags >> 26);

    if ((row == 0) && (_subMenuPage != 0)) {
        menuItem->fadeEffect = 1;
    }

    row = (flags >> 9) & 0x7F;

    if (row <= 100) {
        menuItem->count = row;
    } else if (row <= 102) {
        menuItem->outsetIcon = row - 100;
    } else {
        menuItem->subText = vs_battle_limbNames[row - 103];
    }

    menuItem->material = (flags >> 16) & 7;
    menuItem->max = (flags >> 19) & 0x7F;
    return menuItem;
}

void vs_mainMenu_renderItemsList(void)
{
    static char cursorAnimStep = 0;

    int absRow;
    int temp_v1;
    int i;
    int var_s1;
    int page;
    vs_battle_menuItem_t* menuItem;

    if (_subMenuRowCount == 0) {

        if (_itemsText != NULL) {
            vs_main_freeHeapR(_itemsText);
            _itemsText = NULL;
        }

        _selectedRow = -2;
        return;
    }

    if (vs_mainMenu_itemsListRow < 10) {

        menuItem = func_801008F0(vs_mainMenu_itemsListRow, 320);

        menuItem->state = menuItemStateSlideX;
        ++vs_mainMenu_itemsListRow;
        menuItem->targetPosition0 = 194 - _menuRowYOffset;

        if (vs_mainMenu_itemsListRow == _subMenuRowCount) {
            vs_mainMenu_itemsListRow = 16;
        }

        if (vs_mainMenu_itemsListRow == (10 - _subMenuRowInfo)) {

            if ((vs_mainMenu_itemsListRow + _subMenuPage) < _subMenuRowCount) {
                menuItem->fadeEffect = menuItem_fadeBottom;
            }

            vs_mainMenu_itemsListRow = 16;
        }
    } else {

        menuItem = vs_battle_getMenuItem(_selectedRow + (_subMenuRowInfo * 10));
        vs_mainmenu_setInformationMessage(
            (char*)(_itemsText + (((_selectedRow + _subMenuPage) * 64) + 16)));

        switch (vs_mainMenu_itemsListRow) {
        case 16:
            if (vs_mainmenu_ready()) {
                vs_mainMenu_itemsListRow = 17;
            }
            return;

        case 17:
            absRow = _selectedRow + _subMenuPage;
            page = _subMenuPage;

            if (vs_main_buttonsPressed.all & PADRup) {

                vs_battle_playMenuLeaveSfx();
                vs_main_freeHeapR(_itemsText);

                _itemsText = NULL;
                D_800F4EE8.cursorMemories[_subMenuId * 2] = _selectedRow;
                D_800F4EE8.cursorMemories[_subMenuId * 2 + 1] = _subMenuPage;
                _selectedRow = -3;

                return;
            }

            if (vs_main_buttonsPressed.all & PADRright) {
                if (menuItem->unselectable == 0) {

                    menuItem->selected = 1;

                    vs_battle_playMenuSelectSfx();
                    vs_main_freeHeapR(_itemsText);

                    _itemsText = NULL;
                    D_800F4EE8.cursorMemories[_subMenuId * 2] = _selectedRow;
                    D_800F4EE8.cursorMemories[_subMenuId * 2 + 1] = _subMenuPage;
                    _selectedRow = absRow;

                    return;
                }

                vs_battle_playInvalidSfx();
            }

            menuItem->selected = 0;

            if (vs_main_buttonsPressed.all & PADRdown) {

                vs_battle_playMenuLeaveSfx();
                vs_main_freeHeapR(_itemsText);

                _itemsText = NULL;
                D_800F4EE8.cursorMemories[_subMenuId * 2] = _selectedRow;
                D_800F4EE8.cursorMemories[_subMenuId * 2 + 1] = _subMenuPage;
                _selectedRow = -2;

                return;
            }

            if (vs_main_buttonRepeat & PADLup) {

                if (_subMenuRowCount <= (10 - _subMenuRowInfo)) {

                    if (_selectedRow == 0) {
                        _selectedRow = _subMenuRowCount - 1;
                    } else {
                        --_selectedRow;
                    }

                } else if (_subMenuPage == 0) {

                    if (_selectedRow == 0) {
                        if (vs_main_buttonsPressed.all & PADLup) {
                            _selectedRow = 9 - _subMenuRowInfo;
                            _subMenuPage = _subMenuRowInfo + (_subMenuRowCount + 246);
                        }
                    } else {
                        --_selectedRow;
                    }

                } else if (_selectedRow == 1) {
                    --_subMenuPage;
                } else {
                    --_selectedRow;
                }
            }

            if (vs_main_buttonRepeat & PADLdown) {

                if (_subMenuRowCount <= (10 - _subMenuRowInfo)) {

                    if (_selectedRow == (_subMenuRowCount - 1)) {
                        _selectedRow = 0;
                    } else {
                        ++_selectedRow;
                    }

                } else if (_subMenuPage == (_subMenuRowCount + (_subMenuRowInfo - 10))) {

                    if (_selectedRow == (9 - _subMenuRowInfo)) {

                        if (vs_main_buttonsPressed.all & PADLdown) {
                            _selectedRow = 0;
                            _subMenuPage = 0;
                        }

                    } else {
                        ++_selectedRow;
                    }

                } else if (_selectedRow == (8 - _subMenuRowInfo)) {
                    ++_subMenuPage;
                } else {
                    ++_selectedRow;
                }
            }

            if (absRow != (_selectedRow + _subMenuPage)) {

                vs_battle_playMenuChangeSfx();

                if (_subMenuPage != page) {

                    char gradientStates[_subMenuRowCount];

                    for (i = 0; i < _subMenuRowCount; ++i) {
                        gradientStates[i] = 0;
                    }

                    var_s1 = _subMenuRowCount;
                    temp_v1 = 10 - _subMenuRowInfo;

                    if (temp_v1 < var_s1) {
                        var_s1 = temp_v1;
                    }

                    for (i = 0; i < var_s1; ++i) {
                        gradientStates[i + page] =
                            vs_battle_getMenuItem(i + (_subMenuRowInfo * 10))
                                ->gradientState;
                    }

                    for (i = 0;;) {
                        menuItem = func_801008F0(i, 194 - _menuRowYOffset);
                        menuItem->gradientState = gradientStates[i + _subMenuPage];
                        i += 1;

                        if (i == _subMenuRowCount) {
                            break;
                        }

                        if (i == (10 - _subMenuRowInfo)) {
                            if ((i + _subMenuPage) < _subMenuRowCount) {
                                menuItem->fadeEffect = 2;
                            }
                            break;
                        }
                    }
                }
            }

            vs_battle_getMenuItem(_selectedRow + (_subMenuRowInfo * 10))->selected = 1;

            cursorAnimStep = vs_mainMenu_renderCursor(cursorAnimStep,
                (180 - _menuRowYOffset)
                    | ((((_selectedRow + _subMenuRowInfo) * 16) + 10) << 0x10));

            break;
        }
    }
}

/**
 * Renders the background with optional transparency.
 *
 * @param brightness Passed as the fade step from 0-16, if < 16 the background
 * will blend with the previous screen.
 */
static void _renderBackground(int brightness)
{
    int opaque;
    u_long* prim;

    int uCoord = 0;
    u_long* before = D_1F800000[1] + _backgroundOtOffset;

    if (vs_main_frameBuf == 0) {
        uCoord = 320;
    }

    brightness *= 8;
    opaque = brightness == 128;

    if (opaque) {
        brightness = _backgroundBrightness;
    } else {
        brightness |= 256;
    }

    prim = vs_battle_setSprite(brightness, 256, vs_getWH(64, 240), before);
    prim[1] = vs_getTpage(768, 256, clut8Bit, semiTransparencyFull, ditheringOff);
    prim[4] = vs_getUV0Clut(0, 0, 768, 227);

    prim = vs_battle_setSprite(brightness, 0, vs_getWH(256, 240), before);
    prim[1] = vs_getTpage(640, 256, clut8Bit, semiTransparencyFull, ditheringOff);
    prim[4] = vs_getUV0Clut(0, 0, 768, 227);

    if (!opaque) {
        int new_var = 288;
        brightness = (256 | 128) - brightness;

        vs_battle_setSprite(brightness, 0, vs_getWH(256, 240), before)[1] =
            (((u_int)uCoord >> 6) | new_var
                | vs_getTpage(0, 0, clut4Bit, semiTransparencyHalf, ditheringOff));
        vs_battle_setSprite(brightness, 256, vs_getWH(64, 240), before)[1] =
            (((uCoord + 256) >> 6) | new_var
                | vs_getTpage(0, 0, clut4Bit, semiTransparencyHalf, ditheringOff));
    }
}

#pragma vsstring(start)
int vs_mainMenu_renderRowLabel(
    u_int character, int x, vs_battle_menuItem_t* menuItem, u_long* before)
{
    int i;
    int uvClut;
    u_long* prim;
    int new_var;

    int s7 = character >> 0x1F;
    character &= 0xFFFF;
    new_var = vs_char_nonPrinting;

    if ((character < new_var) && (character == ' ')) {
        do {
            do {
                return x + 6;
            } while (0);
        } while (0);
    }

    i = menuItem->fontColor * 16;

    if (menuItem->fontColor == 0) {
        i = menuItem->unselectable * 48;
    }

    uvClut = (((character & 0x1FF) % 21) * 0xC) | (((character & 0x1FF) / 21) * 0xC00)
           | (getClut(i + 896, 222) << 16);

    for (i = 0; i < 12; ++i) {

        prim = vs_battle_setSprite(s7 == 0 ? (i * 8) + 264 : 352 - (i * 8),
            vs_getXY_2(x, menuItem->y + i), vs_getWH(12, 1), before);
        prim[4] = uvClut;
        prim[1] = vs_getTpage(832, 0, clut4Bit, semiTransparencyFull, 0);
        uvClut += 256;
    }

    return x + vs_battle_characterWidths[character];
}
#pragma vsstring(end)

char vs_mainMenu_freezeTabArrows = 0;

void vs_mainMenu_renderTabNavigation(int mode)
{
    static char arrowAnimState = 11;
    static char const* controls[] = { "1", "L", "1", "R" };
    static int controlPositions[] = { vs_getXY(216, 8), vs_getXY(210, 8),
        vs_getXY(288, 8), vs_getXY(282, 8) };
    int i;
    int color;
    int clut;
    u_int xy;

    clut = vs_getUV0Clut(0, 0, 912, 223);
    color = vs_getRGB888(64, 64, 64);

    if ((vs_mainMenu_freezeTabArrows != 0) || (arrowAnimState != 11)) {

        clut = vs_getUV0Clut(0, 0, 896, 223);
        ++arrowAnimState;
        color = vs_getRGB888(128, 128, 128);

        if (arrowAnimState >= 12) {
            arrowAnimState = 0;
        }
    }

    xy = arrowAnimState >> 2;

    if (mode != 0) {
        for (i = 0; i < 4; ++i) {
            vs_battle_renderTextRawColor(controls[i], controlPositions[i], color, NULL);
        }
        i = vs_getXY(200, 5);
    } else {
        i = vs_getXY(16, 16);
    }

    vs_battle_setSpriteDefault(vs_getWH(16, 16), i - xy)[4] = clut | vs_getUV(0, 48);

    i = vs_getXY(162, 17);

    if (mode != 0) {
        i = vs_getXY(292, 6);
    }

    vs_battle_setSpriteDefault(vs_getWH(16, 16), i + xy)[4] = clut | vs_getUV(16, 48);
}

static void func_8010154C(vs_battle_menuItem_t* arg0)
{
    static char D_80102408 = 0;
    static char D_80102409 = 0;

    int sp10;
    u_int sp14;
    int sp18;
    int backgroundWidth;
    int temp_v1;
    int temp_fp;
    int temp_v1_2;
    int i;
    u_long* var_s2;
    int var_s3;
    u_int var_s5;
    int temp_a0;
    u_int temp_v0_3;
    u_long* temp_s7;

    char* ptr = &arg0->text[0];
    sp14 = 0;

    if (vs_main_frameBuf == 0) {
        sp14 = 0x140;
    }

    var_s5 = *(int*)&arg0->x;
    temp_s7 = D_1F800000[2] + 2;
    sp10 = arg0->w;
    sp18 = arg0->gradientState;
    temp_fp = arg0->fadeEffect - 1;
    backgroundWidth = arg0->backgroundWidth;

    if (vs_main_frameBuf != D_80102408) {
        ++D_80102409;
        D_80102408 = vs_main_frameBuf;
        if (D_80102409 >= 0xC) {
            D_80102409 = 0;
        }
    }

    var_s3 = D_80102409 >> 2;
    var_s3 = temp_fp == 0 ? var_s3 - 5 : 1 - var_s3;

    if (arg0->x == 0) {
        for (i = 32; i < 40; ++i) {
            if (vs_battle_getMenuItem(i)->state >= 2) {
                break;
            }
        }
        if (i == 0x28) {
            var_s2 = temp_s7 - 2;
            vs_battle_setSpriteDefaultTexPage(0x80, ((arg0->y + var_s3) << 0x10) | 0x7E,
                0x100010, var_s2)[4] = ((temp_fp * 0x10) | 0x37F93000);
        }
    } else {
        for (i = 0; i < 32; ++i) {
            if (vs_battle_getMenuItem(i)->state >= 2) {
                break;
            }
        }
        if (i == 0x20) {
            vs_battle_setSpriteDefaultTexPage(0x80,
                ((arg0->x - 0xE) & 0xFFFF) | ((arg0->y + var_s3) << 0x10), 0x100010,
                temp_s7 - 2)[4] = (int)((temp_fp * 0x10) | 0x37F93000);
        }
    }

    temp_v1 = arg0->x;

    i = temp_v1 + 6;
    if (arg0->rowIcon != 0) {
        i = temp_v1 + 0x16;
    }

    while ((var_s3 = *ptr++) != 0xFF) {
        if (var_s3 == 0xFA) {
            i += *ptr++;
        } else {
            i = vs_mainMenu_renderRowLabel(var_s3 | (temp_fp << 0x1F), i, arg0, temp_s7);
        }
    }

    if (sp10 != 0) {
        var_s2 = D_1F800000[0];

        for (i = 0; i < 12; ++i) {
            if (temp_fp == 0) {
                var_s3 = i * 8 + 0x20;
            } else {
                var_s3 = 0x78 - i * 8;
            }
            var_s2[0] = (*temp_s7 & 0xFFFFFF) | 0x06000000;
            var_s2[1] = 0xE1000220;
            var_s2[2] = (vs_battle_uiGradientStop(8 - sp18, backgroundWidth, var_s3)
                         | 0x52000000);
            var_s2[3] = var_s5;
            var_s2[4] = vs_battle_uiGradientStop(sp18, backgroundWidth, var_s3);
            var_s2[5] = ((var_s5 + sp10 - 1) & 0xFFFF) | ((var_s5 >> 0x10) << 0x10);
            var_s2[6] = 0xE1000020;
            temp_v0_3 = (u_long)var_s2 << 8;
            var_s2 += 7;
            *temp_s7 = temp_v0_3 >> 8;
            var_s5 += 0x10000;
        }

        D_1F800000[0] = var_s2;

        if (temp_fp == 0) {
            vs_battle_addTile(temp_s7, 0x60000000,
                ((var_s5 + 2) & 0xFFFF) | ((var_s5 >> 0x10) << 0x10), sp10 | 0x20000);
        }

        if (sp18 != 0) {
            arg0->gradientState = sp18 - 1;
        }

        var_s5 = var_s5 + 0xFFF40000;

        sp10 |= 0x10000;
        var_s3 = ((arg0->x < 0x80) ^ 1) << 7;

        for (i = 0; i < 12; ++i) {
            var_s2 = vs_battle_setSprite(
                temp_fp == 0 ? 0x78 - i * 8 : i * 8 + 0x20, var_s5, sp10, temp_s7);
            temp_v1_2 = (var_s5 - var_s3);
            temp_a0 = var_s5 >> 0x10;
            var_s5 += 0x10000;
            var_s2[1] = ((sp14 + var_s3) >> 6) | 0xE1000120;
            var_s2[4] = temp_v1_2 & 0xFF;
            var_s2[4] = var_s2[4] | (temp_a0 << 8);
        }
    }
}

static void _renderMenuItems(void)
{
    int i;
    vs_battle_menuItem_t* menuItem = vs_battle_menuItems;

    for (i = 0; i < 40; ++i, ++menuItem) {
        int var_v1;
        u_long* temp_s3;
        int target;
        int origin;
        int temp_a1;
        int temp_s0;

        int j = menuItem->state;

        if (j == 0) {
            continue;
        }

        switch (j) {
        case 1:
            break;

        case 2:
            origin = menuItem->x;
            target = menuItem->targetPosition0;

            if (origin < target) {

                origin += 32;

                if (target < origin) {
                    origin = target;
                }
            } else {
                if (target < origin) {

                    for (j = 1; j < 16; ++j) {
                        if ((target + vs_battle_rowAnimationSteps[j]) >= origin) {
                            break;
                        }
                    }

                    origin = target + vs_battle_rowAnimationSteps[j - 1];

                    if ((target >= 155) && (menuItem->w < (320 - origin))) {

                        menuItem->w = 64 - origin;

                        if ((320 - origin) > 165) {
                            menuItem->w = 165;
                        }
                    }
                }
            }

            menuItem->x = origin;

            if (origin == target) {
                menuItem->state = 1;
            }
            break;

        case 3:
            origin = menuItem->y;
            target = menuItem->targetPosition0;

            if (origin < target) {

                for (j = 1; j < 16; ++j) {
                    if (origin >= (target - vs_battle_rowAnimationSteps[j])) {
                        break;
                    }
                }

                origin = target - vs_battle_rowAnimationSteps[j - 1];

            } else if (target < origin) {

                for (j = 1; j < 16; ++j) {
                    if ((target + vs_battle_rowAnimationSteps[j]) >= origin) {
                        break;
                    }
                }

                origin = target + vs_battle_rowAnimationSteps[j - 1];
            }

            menuItem->y = origin;

            if (origin == target) {
                menuItem->state = 1;
            }

            break;

        case 4:
            origin = menuItem->x;
            target = menuItem->targetPosition0;

            if (origin != target) {

                for (j = 1; j < 16; ++j) {
                    if ((target + vs_battle_rowAnimationSteps[j]) >= origin) {
                        break;
                    }
                }

                menuItem->x = vs_battle_rowAnimationSteps[j - 1] + target;

                if (menuItem->w < (320 - menuItem->x)) {
                    menuItem->w = (64 - menuItem->x);
                }

            } else {

                origin = menuItem->y;
                target = menuItem->targetPosition1;

                if (origin != target) {
                    for (j = 1; j < 16; ++j) {
                        if ((target + vs_battle_rowAnimationSteps[j]) >= origin) {
                            break;
                        }
                    }
                    menuItem->y = vs_battle_rowAnimationSteps[j - 1] + target;
                }

                if (menuItem->y == target) {
                    menuItem->state = 1;
                }
            }
            break;

        case 5:
            origin = menuItem->x;
            target = menuItem->targetPosition0;

            if (target < origin) {

                origin -= 32;

                if (origin < target) {
                    origin = target;
                }

                if (-menuItem->w >= origin) {
                    menuItem->state = 0;
                }

            } else {
                if (origin < target) {

                    for (j = 1; j < 16; ++j) {
                        if (origin >= (target - vs_battle_rowAnimationSteps[j])) {
                            break;
                        }
                    }

                    origin = target - vs_battle_rowAnimationSteps[j - 1];
                }
            }

            menuItem->x = origin;

            if (origin == target) {
                if (origin < 0) {
                    menuItem->state = 0;
                } else {
                    menuItem->state = 1;
                }
            }
            break;
        }

        if (vs_mainMenu_hideMenu) {
            continue;
        }

        j = menuItem->max;
        temp_s3 = D_1F800000[2] + 2;

        if (j != 0) {

            if (menuItem->w == 126) {
                var_v1 = menuItem->x + 116;
                origin = var_v1 | ((menuItem->y + 1) << 0x10);
            } else {
                var_v1 = (((menuItem->x * 19) >> 4) + 96) & 0xFFFF;
                origin = var_v1 | ((menuItem->y + 1) << 0x10);
            }

            vs_mainMenu_renderIntColorDefault(j, origin, temp_s3);

            temp_s0 = origin - 30;

            vs_battle_renderTextRaw("/", temp_s0, temp_s3);
            vs_mainMenu_renderIntColorDefault(menuItem->count, temp_s0, temp_s3);

            if ((menuItem->y == 18) && (menuItem->x < 96)) {
                vs_mainMenu_renderIntColorDefault(
                    menuItem->itemPage, origin + 32, temp_s3);
                vs_battle_renderTextRaw("-", origin, temp_s3);
            }

        } else {

            j = menuItem->count;

            if (j != 0) {
                vs_battle_renderValue(0,
                    ((menuItem->x + menuItem->w) - 16) | ((menuItem->y + 3) << 0x10), j,
                    temp_s3);
            }
        }

        if (menuItem->x < 320) {

            if (menuItem->fadeEffect != 0) {
                func_8010154C(menuItem);
            } else {
                vs_battle_renderMenuItem(menuItem);
            }

            j = menuItem->outsetIcon;

            if (j != 0) {
                _renderOutsetIcon(
                    j - 1, (menuItem->x - 24) | ((menuItem->y - 3) << 0x10));
            }
        }

        j = menuItem->buttonId;

        if (j != 0) {
            vs_mainmenu_renderButton(j - 1, menuItem->x + 5, menuItem->y - 2, NULL);
        }

        j = menuItem->rowIcon;

        if (j != 0) {
            vs_mainMenu_renderMenuRowIcon(
                (menuItem->fadeEffect << 0x10) | (menuItem->selected << 8) | j,
                menuItem->x, menuItem->y - 2);
        }

        j = menuItem->material;

        if (j != 0) {
            func_800FFF38(j - 1, (menuItem->x + 13) | ((menuItem->y - 3) << 0x10));
        }
    }
}

void vs_mainMenu_renderScreen(void)
{
    int fadeStep = vs_mainMenu_backgroundFadeStep;

    if (_itemsText != NULL) {
        vs_mainMenu_renderItemsList();
    }

    if (_backgroundFadeState != 0) {

        fadeStep += 2;

        if (fadeStep >= 17) {
            fadeStep = 16;
        }
    } else {
        fadeStep -= 2;

        if (fadeStep < 0) {
            fadeStep = 0;
        }
    }

    vs_mainMenu_backgroundFadeStep = fadeStep;

    if (fadeStep != 0) {
        _renderBackground(fadeStep);
    }

    if (vs_battle_shortcutInvoked == 0) {
        _renderMenuCommand();
    }

    if (vs_battle_menuItems != 0) {
        _renderMenuItems();
    }

    _renderAbilityCost();
    vs_mainMenu_drawClassAffinityType(0);
    vs_mainMenu_renderEquipStats(0);
    vs_mainMenu_renderDpPpBars(0);
}
