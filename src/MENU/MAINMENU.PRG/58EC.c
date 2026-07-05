#include "58EC.h"
#include "C48.h"
#include "2D10.h"
#include "src/SLUS_010.40/overlay.h"
#include "src/BATTLE/BATTLE.PRG/573B8.h"
#include "src/BATTLE/BATTLE.PRG/5BF94.h"
#include "gpu.h"
#include "vs_string.h"
#include <libetc.h>

typedef struct textHeader_t {
    char text[14];
    char disabled;
    char x;
} textHeader_t;

extern u_long* D_1F800000[];

char D_801022C4 = 0;
static u_short* D_801022C8 = NULL;
static int _selectedItemAction = 0;
static char _sortSubMenuId = 0;
static char _itemActionCount = 0;
static char _itemActionListOffset = 0;

char _rangeRiskData[8];
short D_80102488[4];
char D_80102490[8];
short D_80102498[4];

char D_801024A0;
char vs_mainMenu_currentUiItem;
char bss_7[2];
u_short* vs_mainMenu_menu12Text;
short vs_mainMenu_strIntAgi[8];
u_char vs_mainMenu_selectedStatusViewElement;
char vs_mainMenu_itemStatPage;
char bss_3[6];
short vs_mainMenu_equipmentStats[64];
u_short* vs_mainMenu_itemHelp;
char vs_mainMenu_enabledStatPages;
char vs_mainMenu_equipmentSubtype;
char bss_4[18]; // Garbage, patched in MAINMENU_PRG.py
textHeader_t _textHeaders[2];
char D_80102578;

void vs_mainMenu_initSortUi(int rowCount, int subMenuId, char* menuText[], int rowTypes[])
{
    int temp_v1_2;
    int i;
    int var_a2;

    i = 0;
    var_a2 = 0;
    D_801024A0 = rowCount >> 8;
    rowCount &= 0xFF;

    if (!D_801024A0) {
        if (rowCount < 7) {
            D_801024A0 = 0xA - rowCount;
        } else {
            D_801024A0 = 3;
        }
    }

    _sortSubMenuId = subMenuId;

    if (subMenuId == 4) {
        i = 1;
    } else if ((vs_main_settings.cursorMemory != 0) && (subMenuId != 3)) {
        i = D_800F4EE8.cursorMemories[subMenuId * 2];
        var_a2 = D_800F4EE8.cursorMemories[subMenuId * 2 + 1];
    }
    temp_v1_2 = rowCount - 7;
    if (temp_v1_2 < 0) {
        i += var_a2;
        var_a2 = 0;
        if (i >= rowCount) {
            i = 0;
        }
    } else if (temp_v1_2 < var_a2) {
        if ((i + var_a2) >= rowCount) {
            i = 0;
            var_a2 = 0;
        } else {
            i += var_a2 - temp_v1_2;
            var_a2 = temp_v1_2;
        }
    }

    if ((var_a2 > 0) && (i == 0)) {
        i = 1;
        --var_a2;
    }
    if (var_a2 < temp_v1_2) {
        if (i == 6) {
            i = 5;
            ++var_a2;
        }
    }
    _selectedItemAction = i;
    _itemActionListOffset = var_a2;
    _itemActionCount = rowCount;
    D_801022C4 = 0;
    D_801022C8 = vs_main_allocHeapR(rowCount << 7);

    for (i = 0; i < rowCount; ++i) {
        char* s;
        *((int*)(&(&D_801022C8[i * 64])[14])) = rowTypes[i];

        if (menuText[i * 2] != NULL) {
            vs_battle_copyAligned(&D_801022C8[i * 64], menuText[i * 2], 0x1A);
            D_801022C8[(i * 64) + 13] = 0xE7E7;
        } else {
            D_801022C8[i * 64] = 0xE7E7;
        }

        s = menuText[i * 2 + 1];
        if (s != NULL) {
            D_801022C8[(i * 64) + 16] = 0xF8;
            vs_battle_copyAligned(&D_801022C8[(i * 64) + 17], s, 0x5C);
            D_801022C8[(i * 64) + 63] = 0xE7E7;
        } else {
            D_801022C8[(i * 64) + 16] = 0xE7E7;
        }
    }
}

int func_800FF348(void) { return _selectedItemAction + _itemActionListOffset; }

int vs_mainMenu_getSelectedItemAction(void)
{
    return D_801022C8 == NULL ? _selectedItemAction : -1;
}

static vs_battle_menuItem_t* func_800FF388(int arg0, int arg1)
{
    vs_battle_menuItem_t* temp_v0 =
        vs_battle_setMenuItem(arg0 + 0x20, arg1, ((arg0 + D_801024A0) * 0x10) + 0x12,
            0x7E, 0, (char*)&D_801022C8[(_itemActionListOffset + arg0) * 0x40]);
    int v = *((int*)&D_801022C8[(_itemActionListOffset + arg0) * 0x40 + 14]);
    temp_v0->unselectable = v & 1;
    if ((arg0 == 0) && (_itemActionListOffset != 0)) {
        temp_v0->fadeEffect = 1;
    }
    return temp_v0;
}

void vs_mainMenu_processItemActionMenu(void)
{
    static char D_801022D3 = 0;

    int temp_s6;
    int var_a0;
    int i;
    int temp_s5;
    int var_s1;
    vs_battle_menuItem_t* menuItem;

    if (D_801022C4 < 10) {
        menuItem = func_800FF388(D_801022C4, -194);
        menuItem->state = 5;
        menuItem->targetPosition0 = 0;
        ++D_801022C4;
        if (D_801022C4 == _itemActionCount) {
            D_801022C4 = 16;
        }
        if (D_801022C4 == 7) {
            if ((D_801022C4 + _itemActionListOffset) < _itemActionCount) {
                menuItem->fadeEffect = 2;
            }
            D_801022C4 = 16;
        }
    } else {
        menuItem = vs_battle_getMenuItem(_selectedItemAction + 32);
        vs_mainmenu_setInformationMessage(
            (char*)(D_801022C8
                    + (((_selectedItemAction + _itemActionListOffset) << 6) + 16)));

        switch (D_801022C4) {
        case 16:
            if (vs_mainmenu_ready() != 0) {
                D_801022C4 = 17;
                return;
            }
            return;
        case 17:
            temp_s6 = _selectedItemAction + _itemActionListOffset;
            temp_s5 = _itemActionListOffset;

            if (vs_main_buttonsPressed.all & PADRup) {
                vs_main_freeHeapR(D_801022C8);
                D_801022C8 = NULL;
                D_800F4EE8.cursorMemories[_sortSubMenuId * 2] = _selectedItemAction;
                D_800F4EE8.cursorMemories[_sortSubMenuId * 2 + 1] = _itemActionListOffset;
                _selectedItemAction = -3;
                return;
            }

            if (vs_main_buttonsPressed.all & PADRright) {
                if (menuItem->unselectable == 0) {
                    menuItem->selected = 1;
                    vs_main_freeHeapR(D_801022C8);
                    D_801022C8 = NULL;
                    D_800F4EE8.cursorMemories[_sortSubMenuId * 2] = _selectedItemAction;
                    D_800F4EE8.cursorMemories[_sortSubMenuId * 2 + 1] =
                        _itemActionListOffset;
                    _selectedItemAction = temp_s6;
                    return;
                }
                vs_battle_playInvalidSfx();
            }

            menuItem->selected = 0;

            if (vs_main_buttonsPressed.all & PADRdown) {
                vs_main_freeHeapR(D_801022C8);
                D_801022C8 = NULL;
                D_800F4EE8.cursorMemories[_sortSubMenuId * 2] = _selectedItemAction;
                D_800F4EE8.cursorMemories[_sortSubMenuId * 2 + 1] = _itemActionListOffset;
                _selectedItemAction = -2;
                return;
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

            if (temp_s6 != (_selectedItemAction + _itemActionListOffset)) {
                vs_battle_playMenuChangeSfx();

                if (_itemActionListOffset != temp_s5) {
                    char gradientStates[_itemActionCount];
                    for (i = 0; i < _itemActionCount; ++i) {
                        gradientStates[i] = 0;
                    }
                    var_s1 = _itemActionCount;
                    if (var_s1 > 7u) {
                        var_s1 = 7;
                    }
                    for (i = 0; i < var_s1; ++i) {
                        gradientStates[i + temp_s5] =
                            vs_battle_getMenuItem(i + 32)->gradientState;
                    }

                    var_a0 = 0;
                    for (i = 0;;) {
                        menuItem = func_800FF388(i, 0);
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
            D_801022D3 =
                vs_mainMenu_renderCursor((u_int)D_801022D3, (menuItem->y - 8) << 0x10);
            break;
        }
    }
}

void vs_mainMenu_printInformation(int arg0, int arg1)
{
    if (arg1 >= 16) {
        if (vs_battle_rowTypeBuf[arg0] & 1) {

            if ((vs_main_settings.information == 0)
                && (vs_main_buttonsState & (PADLup | PADLdown))) {
                return;
            }

            vs_battle_initInformationTextBox(1);

            vs_battle_textBoxes[7].state = 11;

        } else if (vs_main_settings.information != 0) {

            vs_battle_initInformationTextBox(2);

            vs_battle_textBoxes[7].state = 11;

        } else {
            vs_battle_textBoxes[7].state = 0;
        }
    }
}

char vs_mainMenu_isLevelledSpell = 0;
char vs_menu_cursorColor = 0;
char vs_mainMenu_hideMenu = 0;
int D_801022D8 = 0;
char D_801022DC = 0;
static short D_801022DE = -4;
static short D_801022E0 = 128;
static char _menuActionCurrent = 0;
static char _menuActionNext = 0;

void vs_mainMenu_setNextMenuAction(enum vs_mainMenu_menuActions action)
{
    _menuActionNext = action;
}

void func_800FFA94(void)
{
    static int D_801022E4 = 0;
    static u_short D_801022E8[] = { vs_getUV(0, 0), vs_getUV(0, 64), vs_getUV(64, 64),
        vs_getUV(100, 64), vs_getUV(132, 64), vs_getUV(188, 64), vs_getUV(0, 74) };
    static int D_801022F8[] = { vs_getXY(0, 0), vs_getXY(0x3E, 10), vs_getXY(0x24, 10),
        vs_getXY(0x1E, 10), vs_getXY(0x38, 10), vs_getXY(0x1E, 10), vs_getXY(0x20, 10),
        vs_getXY(0, 0) };

    int var_a1;
    u_long* temp_v0;
    int temp_s0;

    temp_s0 = _menuActionCurrent;
    var_a1 = D_801022E4;
    if (temp_s0 != _menuActionNext) {
        if (var_a1 == 0) {
            _menuActionCurrent = _menuActionNext;
            return;
        }
        var_a1 -= 2;
    } else if (var_a1 < 0xC) {
        var_a1 += 2;
    }
    D_801022E4 = var_a1;
    if (temp_s0 != 0) {
        temp_v0 = vs_battle_setSprite(0x180,
            (0x138 - (D_801022F8[temp_s0] & 0xFF)) | ((D_801022E4 - 4) << 16),
            D_801022F8[temp_s0], D_1F800000[2]);
        temp_v0[1] = 0xE100002C;
        temp_v0[4] = D_801022E8[temp_s0] | 0x37F50000;
    }
}

void func_800FFB68(int arg0)
{
    if (arg0 != 0) {
        D_801022DE = -4;
        D_801022E0 = 0x80;
    }
    D_801022DC = arg0;
}

void vs_mainMenu_deactivateMenuItem(int arg0)
{
    vs_battle_menuItem_t* item = &vs_battle_menuItems[arg0];
    item->state = menuItemStateInactive;
}

void vs_mainMenu_dismissTextBox(void) { vs_battle_dismissTextBox(7); }

void vs_mainMenu_initTextBox(void)
{
    if (vs_main_settings.information != 0) {
        vs_battle_initInformationTextBox(2);
    } else {
        vs_mainMenu_dismissTextBox();
    }
}

void vs_mainmenu_setInformationMessage(char* arg0)
{
#pragma vsstring(start)
    static char infoMessage[] =
        "|!0|000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000\0\0";
#pragma vsstring(end)

    vs_battle_memcpy(&infoMessage[2], arg0, 0x60);
    vs_battle_textBoxes[7].unk0.unk0_24 = 32;
    vs_battle_setTextBox(7, infoMessage);
}

void vs_mainmenu_renderButton(int index, int x, int y, u_long* data)
{
    if (data == NULL) {
        data = D_1F800000[2];
    }
    vs_battle_setSpriteDefaultTexPage(0x80, (x & 0xFFFF) | (y << 0x10), 0x100010,
        data)[4] = ((index & 3) * 0x10) | ((((index & 4) * 4) + 0x80) << 8) | 0x37FB0000;
}

int vs_mainMenu_renderCursor(u_int animStep, int xy)
{
    int clut;
    int cursorAnimStep = animStep >> (vs_menu_cursorColor * 8);

    u_long* temp_a1 = vs_battle_setSpriteDefaultTexPage(
        vs_battle_cursorBrightnessAnimation[cursorAnimStep], xy, vs_getWH(16, 16),
        D_1F800000[2]);

    if (vs_menu_cursorColor == 0) {
        clut = vs_getUV0Clut(32, 48, 896, 223);
    } else {
        clut = vs_getUV0Clut(32, 48, 928, 223);
    }

    temp_a1[4] = clut;
    vs_menu_cursorColor = 0;

    return (cursorAnimStep + 1) & 0xF;
}

int vs_mainMenu_renderIntColor(int arg0, int arg1, int arg2, u_long* arg3)
{
    int sp10;
    int var_s0 = arg0;

    if (arg0 < 0) {
        var_s0 = -arg0;
    }

    do {
        var_s0 = vs_battle_toBCD(var_s0);
        sp10 = ((var_s0 & 0xF) << 8) | ('0' << 8) | '#';
        vs_battle_renderTextRawColor((char*)&sp10, arg1, arg2, arg3);
        var_s0 = var_s0 >> 4;
        arg1 -= 8;
    } while (var_s0 != 0);

    if (arg0 < 0) {
        sp10 = ('-' << 8) | '#';
        vs_battle_renderTextRawColor((char*)&sp10, arg1 + 1, arg2, arg3);
    }

    return arg1;
}

int func_800FFE20(int arg0, int arg1, int arg2, u_long* arg3)
{
    int var_a2;

    var_a2 = 0x808080;
    if (arg2 < arg0) {
        var_a2 = 0x804020;
    }
    if (arg0 < arg2) {
        var_a2 = 0x204080;
    }
    return vs_mainMenu_renderIntColor(arg0, arg1, var_a2, arg3);
}

void vs_mainMenu_renderIntColorDefault(int arg0, int arg1, u_long* arg2)
{
    vs_mainMenu_renderIntColor(arg0, arg1, 0x808080, arg2);
}

static void func_800FFE98(int offset, int xy, int clut, u_long* before)
{
    int i = 0;

    if (offset < 0) {
        xy += vs_getXY(0, 15);
        clut += vs_getUV0Clut(0, 15, 0, 0);
    }

    do {
        ++i;

        vs_battle_setSpriteDefaultTexPage((i * 8) | 256, xy, vs_getWH(16, 1), before)[4] =
            clut;

        xy += vs_getXY(0, offset);
        clut += vs_getUV0Clut(0, offset, 0, 0);
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

void vs_mainMenu_renderMenuRowIcon(int arg0, int arg1, int arg2)
{
    static u_short clutUvs[] = { vs_getUV(80, 96), vs_getUV(144, 96), vs_getUV(160, 96),
        vs_getUV(112, 96), vs_getUV(128, 96), vs_getUV(176, 96), vs_getUV(208, 96),
        vs_getUV(96, 96), vs_getUV(48, 112), vs_getUV(128, 112), vs_getUV(0, 112),
        vs_getUV(16, 112), vs_getUV(32, 112), vs_getUV(224, 96), vs_getUV(64, 112),
        vs_getUV(80, 112), vs_getUV(96, 112), vs_getUV(112, 112), vs_getUV(128, 112),
        vs_getUV(144, 112), vs_getUV(160, 112), vs_getUV(32, 96), vs_getUV(176, 112),
        vs_getUV(120, 128), vs_getUV(136, 128), vs_getUV(152, 128), vs_getUV(168, 128),
        vs_getUV(184, 128), vs_getUV(200, 128), vs_getUV(216, 128), vs_getUV(232, 128),
        vs_getUV(96, 128), vs_getUV(80, 128) };

    int v1;
    int var_a0;
    u_long* prim;

    var_a0 = arg0 >> 0x10;
    v1 = (arg0 >> 8) & 1;
    arg0 = (arg0 - 1) & 0xFF;

    if (var_a0 == 0) {
        prim = vs_battle_setSpriteDefaultTexPage(
            64 << v1, vs_getXY_2(arg1, arg2), vs_getWH(16, 16), D_1F800000[2] + 1);
        prim[4] = vs_getUV0Clut(clutUvs[arg0], 0, 992, 223);

        if (arg0 >= 23) {
            prim[3] -= 12;
            prim[4] = vs_getUV0Clut(clutUvs[arg0], 0, 976, 223);
        }
    } else {
        if (var_a0 == 2) {
            var_a0 = -1;
        }

        func_800FFE98(var_a0, vs_getXY_2(arg1, arg2),
            vs_getUV0Clut(clutUvs[arg0], 0, 992, 223), D_1F800000[2] + 1);
    }
}

void vs_mainmenu_setSkillCost(int index, char const* text, int xOffset, int disabled)
{
    vs_mainMenu_isLevelledSpell = 1;
    vs_battle_rMemcpy(&_textHeaders[index], text, 14);
    _textHeaders[index].disabled = disabled;
    _textHeaders[index].x = xOffset;
}

static void func_80100164(void)
{
    static u_char D_801023BE = 8;

    int temp_s2;
    int temp_t1;
    int var_s1;
    u_long* temp_s5;
    u_long* temp_v1_2;

    temp_s5 = D_1F800000[1] - 1;

    if (vs_mainMenu_isLevelledSpell != 0) {
        if (D_801023BE != 0) {
            --D_801023BE;
        }
    } else {
        if (D_801023BE < 5) {
            D_801023BE = 5;
        } else if (D_801023BE < 8) {
            ++D_801023BE;
        }
    }

    if (D_801023BE < 8) {
        temp_s2 = -vs_battle_rowAnimationSteps[D_801023BE];

        for (var_s1 = 0; var_s1 < 2; ++var_s1) {
            vs_battle_renderTextRawColor(_textHeaders[var_s1].text,
                ((temp_s2 + _textHeaders[var_s1].x) & 0xFFFF) | 0xA00000,
                0x808080 >> _textHeaders[var_s1].disabled, NULL);
        }

        temp_t1 = temp_s2 & 0xFFFF;
        temp_v1_2 = D_1F800000[0];
        temp_v1_2[0] = (*temp_s5 & 0xFFFFFF) | 0x0A000000;
        temp_v1_2[1] = 0xE1000200;
        temp_v1_2[2] = 0x38200808;
        temp_v1_2[3] = temp_t1 | 0xA00000;
        temp_v1_2[4] = 0x663040;
        temp_v1_2[5] = (temp_s2 + 0x50) | 0xA00000;
        temp_v1_2[6] = 0x200808;
        temp_v1_2[7] = temp_t1 | 0xAB0000;
        temp_v1_2[8] = 0x663040;
        temp_v1_2[9] = (temp_s2 + 0x50) | 0xAB0000;
        temp_v1_2[10] = 0xE1000000;
        *temp_s5 = ((u_long)temp_v1_2 << 8) >> 8;
        D_1F800000[0] = temp_v1_2 + 11;
        func_800CCCB8(temp_s5, 0x60000000, temp_t1 | 0xA20000, 0xB0052);
    }
}

void vs_mainmenu_renderButtonUiBackground(int x, int y, int w, int h)
{
    int i;
    u_long* var_t2 = D_1F800000[0];
    u_long* temp_v1 = D_1F800000[1] - 3;

    for (i = 0; i < h; ++i) {
        var_t2[0] = vs_getTag(u_long[6], temp_v1[0]);
        var_t2[1] = vs_getTpage(0, 0, 0, 0, ditheringOn);
        var_t2[2] = vs_getRGB0(primLineG2, 0x40, 0x38, 0x20);
        var_t2[3] = ((x & 0xFFFF) | ((y + i) << 0x10));
        var_t2[4] = vs_getRGB888(16, 16, 8);
        var_t2[5] = ((((x + w) - i) & 0xFFFF) | ((y + i) << 0x10));
        var_t2[6] = vs_getTpage(0, 0, 0, 0, ditheringOff);
        temp_v1[0] = (((u_long)var_t2 << 8) >> 8);
        var_t2 += 7;
    }
    D_1F800000[0] = var_t2;
}

void func_80100414(int arg0, int arg1)
{
    if (arg0 > 0) {
        D_800F4E90 |= 2;
    } else {
        D_800F4E90 &= 1;
    }
    D_801022DE = arg0;
    D_801022E0 = arg1;
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
    func_80100414(-4, 0x80);
}

typedef struct {
    u_short name[14];
    int menuRowFlags;
    u_short description[48];
} _itemsText_t;

char D_801023D0 = 0;
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
    D_801023D0 = 0;

    _itemsText = vs_main_allocHeapR(rowCount * 128);

    for (i = 0; i < rowCount; ++i) {
        char* text;

        ((_itemsText_t*)_itemsText)[i].menuRowFlags = rowTypes[i];

        if (strings[i * 2] != NULL) {
            vs_battle_copyAligned(&_itemsText[i * 64], strings[i * 2], 26);

            (_itemsText + i * 64)[13] = vs_char_terminator << 8 | vs_char_terminator;
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

int func_80100814(void)
{
    vs_main_freeHeapR(_itemsText);

    _itemsText = NULL;
    D_800F4EE8.cursorMemories[_subMenuId * 2] = _selectedRow;
    D_800F4EE8.cursorMemories[_subMenuId * 2 + 1] = _subMenuPage;

    return (_selectedRow + _subMenuPage) | ((_selectedRow + (_subMenuRowInfo * 10)) << 8);
}

int vs_mainMenu_getConfirmedRow(void) { return _selectedRow + _subMenuPage; }

int vs_mainmenu_getSelectedRow(void) { return _itemsText != NULL ? -1 : _selectedRow; }

static vs_battle_menuItem_t* func_801008F0(int arg0, int arg1)
{
    int flags;
    int temp_v1;
    vs_battle_menuItem_t* menuItem = vs_battle_setMenuItem(arg0 + (_subMenuRowInfo * 10),
        arg1, ((arg0 + _subMenuRowInfo) * 16) + 18, _menuRowYOffset + 126, 0,
        (char*)&_itemsText[(_subMenuPage + arg0) * 64]);

    flags = ((_itemsText_t*)_itemsText)[_subMenuPage + arg0].menuRowFlags;

    menuItem->unselectable = flags & 1;
    menuItem->backgroundWidth += (flags & 2) * 12;

    temp_v1 = (flags >> 3) & 1;

    menuItem->invertGradient = temp_v1;
    menuItem->fontColor = temp_v1 | ((flags >> 2) & 1);
    menuItem->rowIcon = (flags >> 26);

    if ((arg0 == 0) && (_subMenuPage != 0)) {
        menuItem->fadeEffect = 1;
    }

    arg0 = (flags >> 9) & 0x7F;

    if (arg0 <= 100) {
        menuItem->count = arg0;
    } else if (arg0 <= 102) {
        menuItem->outsetIcon = arg0 - 100;
    } else {
        menuItem->subText = vs_battle_limbNames[arg0 - 103];
    }

    menuItem->material = (flags >> 16) & 7;
    menuItem->max = (flags >> 19) & 0x7F;
    return menuItem;
}

void func_80100A5C(void)
{
    static char D_801023E2 = 0;

    int temp_s6;
    int temp_v1;
    int i;
    int var_s1;
    int temp_s5;
    vs_battle_menuItem_t* menuItem;

    if (_subMenuRowCount == 0) {

        if (_itemsText != NULL) {
            vs_main_freeHeapR(_itemsText);
            _itemsText = NULL;
        }

        _selectedRow = -2;
        return;
    }

    if (D_801023D0 < 10) {

        menuItem = func_801008F0(D_801023D0, 320);

        menuItem->state = 2;
        ++D_801023D0;
        menuItem->targetPosition0 = 0xC2 - _menuRowYOffset;

        if (D_801023D0 == _subMenuRowCount) {
            D_801023D0 = 0x10;
        }

        if (D_801023D0 == (0xA - _subMenuRowInfo)) {

            if ((D_801023D0 + _subMenuPage) < _subMenuRowCount) {
                menuItem->fadeEffect = 2;
            }

            D_801023D0 = 0x10;
        }
    } else {

        menuItem = vs_battle_getMenuItem(_selectedRow + (_subMenuRowInfo * 10));
        vs_mainmenu_setInformationMessage(
            (char*)(_itemsText + (((_selectedRow + _subMenuPage) << 6) + 16)));

        switch (D_801023D0) {
        case 16:
            if (vs_mainmenu_ready()) {
                D_801023D0 = 0x11;
            }
            return;

        case 17:
            temp_s6 = _selectedRow + _subMenuPage;
            temp_s5 = _subMenuPage;

            if (vs_main_buttonsPressed.all & 0x10) {
                vs_battle_playMenuLeaveSfx();
                vs_main_freeHeapR(_itemsText);

                _itemsText = NULL;
                D_800F4EE8.cursorMemories[_subMenuId * 2] = _selectedRow;
                D_800F4EE8.cursorMemories[_subMenuId * 2 + 1] = _subMenuPage;
                _selectedRow = -3;

                return;
            }

            if (vs_main_buttonsPressed.all & 0x20) {
                if (menuItem->unselectable == 0) {

                    menuItem->selected = 1;

                    vs_battle_playMenuSelectSfx();
                    vs_main_freeHeapR(_itemsText);

                    _itemsText = NULL;
                    D_800F4EE8.cursorMemories[_subMenuId * 2] = _selectedRow;
                    D_800F4EE8.cursorMemories[_subMenuId * 2 + 1] = _subMenuPage;
                    _selectedRow = temp_s6;

                    return;
                }

                vs_battle_playInvalidSfx();
            }

            menuItem->selected = 0;

            if (vs_main_buttonsPressed.all & 0x40) {

                vs_battle_playMenuLeaveSfx();
                vs_main_freeHeapR(_itemsText);

                _itemsText = NULL;
                D_800F4EE8.cursorMemories[_subMenuId * 2] = _selectedRow;
                D_800F4EE8.cursorMemories[_subMenuId * 2 + 1] = _subMenuPage;
                _selectedRow = -2;

                return;
            }

            if (vs_main_buttonRepeat & 0x1000) {
                if (_subMenuRowCount <= (10 - _subMenuRowInfo)) {
                    if (_selectedRow == 0) {
                        _selectedRow = _subMenuRowCount - 1;
                    } else {
                        --_selectedRow;
                    }
                } else if (_subMenuPage == 0) {
                    if (_selectedRow == 0) {
                        if (vs_main_buttonsPressed.all & 0x1000) {
                            _selectedRow = 9 - _subMenuRowInfo;
                            _subMenuPage = _subMenuRowInfo + (_subMenuRowCount + 0xF6);
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

            if (vs_main_buttonRepeat & 0x4000) {
                if (_subMenuRowCount <= (10 - _subMenuRowInfo)) {
                    if (_selectedRow == (_subMenuRowCount - 1)) {
                        _selectedRow = 0;
                    } else {
                        ++_selectedRow;
                    }
                } else if (_subMenuPage == (_subMenuRowCount + (_subMenuRowInfo - 10))) {
                    if (_selectedRow == (9 - _subMenuRowInfo)) {
                        if (vs_main_buttonsPressed.all & 0x4000) {
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

            if (temp_s6 != (_selectedRow + _subMenuPage)) {

                vs_battle_playMenuChangeSfx();

                if (_subMenuPage != temp_s5) {
                    char unksp10[_subMenuRowCount];
                    for (i = 0; i < _subMenuRowCount; ++i) {
                        unksp10[i] = 0;
                    }
                    var_s1 = _subMenuRowCount;
                    temp_v1 = 10 - _subMenuRowInfo;
                    if (temp_v1 < var_s1) {
                        var_s1 = temp_v1;
                    }

                    for (i = 0; i < var_s1; ++i) {
                        unksp10[i + temp_s5] =
                            vs_battle_getMenuItem(i + (_subMenuRowInfo * 10))
                                ->gradientState;
                    }
                    for (i = 0;;) {
                        menuItem = func_801008F0(i, 194 - _menuRowYOffset);
                        menuItem->gradientState = unksp10[i + _subMenuPage];
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

            vs_battle_getMenuItem(_selectedRow + (_subMenuRowInfo * 0xA))->selected = 1;

            D_801023E2 = vs_mainMenu_renderCursor((u_int)D_801023E2,
                (0xB4 - _menuRowYOffset)
                    | ((((_selectedRow + _subMenuRowInfo) * 0x10) + 0xA) << 0x10));
            break;
        }
    }
}

void func_80101118(int arg0)
{
    int var_a0;
    int temp_s4;
    int var_s3;
    u_long* temp_s2;
    u_long* temp_v0;

    var_s3 = 0;
    temp_s2 = D_1F800000[1] + D_801022DE;

    if (vs_main_frameBuf == 0) {
        var_s3 = 0x140;
    }

    arg0 *= 8;
    temp_s4 = arg0 == 0x80;

    if (temp_s4 != 0) {
        arg0 = D_801022E0;
        var_a0 = arg0;
    } else {
        arg0 = arg0 | 0x100;
        var_a0 = arg0;
    }
    temp_v0 = vs_battle_setSprite(var_a0, 0x100, 0xF00040, temp_s2);
    temp_v0[1] = 0xE10000BC;
    temp_v0[4] = 0x38F00000;

    temp_v0 = vs_battle_setSprite(arg0, 0, 0xF00100, temp_s2);
    temp_v0[1] = 0xE10000BA;
    temp_v0[4] = 0x38F00000;

    if (temp_s4 == 0) {
        int new_var = 0x120;
        arg0 = 0x180 - arg0;
        vs_battle_setSprite(arg0, 0, 0xF00100, temp_s2)[1] =
            (((u_int)var_s3 >> 6) | new_var | 0xE1000000);
        vs_battle_setSprite(arg0, 0x100, 0xF00040, temp_s2)[1] =
            (((var_s3 + 0x100) >> 6) | new_var | 0xE1000000);
    }
}

#pragma vsstring(start)
int func_80101268(u_int arg0, int arg1, vs_battle_menuItem_t* menuItem, u_long* arg3)
{
    int i;
    int var_s2;
    u_long* temp_v0_2;
    int new_var;

    int s7 = arg0 >> 0x1F;
    arg0 &= 0xFFFF;
    new_var = vs_char_nonPrinting;

    if ((arg0 < new_var) && (arg0 == ' ')) {
        do {
            do {
                return arg1 + 6;
            } while (0);
        } while (0);
    }

    i = menuItem->fontColor * 16;

    if (menuItem->fontColor == 0) {
        i = menuItem->unselectable * 48;
    }

    var_s2 = (((arg0 & 0x1FF) % 21) * 0xC) | (((arg0 & 0x1FF) / 21) * 0xC00)
           | (((((i + 0x380) >> 4) & 0x3F) | 0x3780) << 0x10);

    for (i = 0; i < 12; ++i) {

        temp_v0_2 = vs_battle_setSprite(s7 == 0 ? (i * 8) + 0x108 : 0x160 - (i * 8),
            (arg1 & 0xFFFF) | ((menuItem->y + i) << 0x10), 0x1000C, arg3);
        temp_v0_2[4] = var_s2;
        temp_v0_2[1] = 0xE100002D;
        var_s2 += 256;
    }

    return arg1 + vs_battle_characterWidths[arg0];
}
#pragma vsstring(end)

char D_801023E3 = 0;

void func_801013F8(int arg0)
{
    static char D_801023E4 = 11;
    static char const* D_801023E8[] = { "1", "L", "1", "R" };
    static int D_801023F8[] = { vs_getXY(0xD8, 8), vs_getXY(0xD2, 8), vs_getXY(0x120, 8),
        vs_getXY(0x11A, 8) };
    int i;
    int color;
    int var_s4;
    u_int temp_s5;

    var_s4 = 0x37F90000;
    color = 0x404040;

    if ((D_801023E3 != 0) || (D_801023E4 != 0xB)) {
        var_s4 = 0x37F80000;
        ++D_801023E4;
        color = 0x808080;
        if (D_801023E4 >= 12) {
            D_801023E4 = 0;
        }
    }

    temp_s5 = D_801023E4 >> 2;

    if (arg0 != 0) {
        for (i = 0; i < 4; ++i) {
            vs_battle_renderTextRawColor(D_801023E8[i], D_801023F8[i], color, NULL);
        }
        i = 0x500C8;
    } else {
        i = 0x100010;
    }

    vs_battle_setSpriteDefault(0x100010, i - temp_s5)[4] = var_s4 | 0x3000;

    i = 0x1100A2;

    if (arg0 != 0) {
        i = 0x60124;
    }

    vs_battle_setSpriteDefault(0x100010, i + temp_s5)[4] = var_s4 | 0x3010;
}

void func_8010154C(vs_battle_menuItem_t* arg0)
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
            i = func_80101268(var_s3 | (temp_fp << 0x1F), i, arg0, temp_s7);
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
            func_800CCCB8(temp_s7, 0x60000000,
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

void func_80101F38(void)
{
    int var_s0;

    var_s0 = D_801022D8;
    if (_itemsText != NULL) {
        func_80100A5C();
    }
    if (D_801022DC != 0) {
        var_s0 = var_s0 + 2;
        if (var_s0 >= 17) {
            var_s0 = 16;
        }
    } else {
        var_s0 = var_s0 - 2;
        if (var_s0 < 0) {
            var_s0 = 0;
        }
    }
    D_801022D8 = var_s0;
    if (var_s0 != 0) {
        func_80101118(var_s0);
    }
    if (vs_battle_shortcutInvoked == 0) {
        func_800FFA94();
    }
    if (vs_battle_menuItems != 0) {
        _renderMenuItems();
    }
    func_80100164();
    vs_mainMenu_drawClassAffinityType(0);
    vs_mainMenu_renderEquipStats(0);
    vs_mainMenu_renderDpPpBars(0);
}
