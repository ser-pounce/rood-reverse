#include "../../build/assets/MENU/MENU8.PRG/rename.h"
#include "../SLUS_010.40/main.h"
#include "../MAINMENU.PRG/C48.h"
#include "../MAINMENU.PRG/413C.h"
#include "../../BATTLE/BATTLE.PRG/146C.h"
#include "../../BATTLE/BATTLE.PRG/573B8.h"
#include "../../BATTLE/BATTLE.PRG/5BF94.h"
#include "vs_string.h"
#include "gpu.h"
#include <libetc.h>

static u_char D_80105F2E;
static char _1;
static char D_80105F30;
static u_char _animStep;
static char _2[2];
static char* _charTable;
static char _3[8];
static char _stringBuf[20];

static char D_80105DB0 = 0;

static int _insertDeleteHandler(int bufPos)
{
    int previousPos;
    int i;

    D_80105DB0 = 1;
    previousPos = bufPos;

    if (vs_main_buttonRepeat & PADRup) {
        vs_battle_playMenuChangeSfx();
        for (i = 19; bufPos < i; --i) {
            _stringBuf[i] = _stringBuf[i - 1];
        }
        _stringBuf[bufPos] = vs_char_space;
    } else if (vs_main_buttonRepeat & PADRleft) {
        vs_battle_playMenuChangeSfx();
        for (i = bufPos; i < 19; ++i) {
            _stringBuf[i] = _stringBuf[i + 1];
        }
        _stringBuf[19] = vs_char_space;
    } else if ((vs_main_buttonsState & (PADL1 | PADR1)) != (PADL1 | PADR1)) {
        if (vs_main_buttonRepeat & PADL1) {
            if (bufPos == 0) {
                if (vs_main_buttonsPressed.all & PADL1) {
                    bufPos = 19;
                }
            } else {
                --bufPos;
            }
        }
        if (vs_main_buttonRepeat & PADR1) {
            if (bufPos == 19) {
                if (vs_main_buttonsPressed.all & PADR1) {
                    bufPos = 0;
                }
            } else {
                ++bufPos;
            }
        }
    }
    if (bufPos != previousPos) {
        vs_battle_playMenuChangeSfx();
    }
    return bufPos;
}

static int _copyNormalizedString(char* stringBuf)
{
    int pos;
    int i;

    for (pos = 0, i = 0; i < 20; ++pos, ++i) {
        if (_stringBuf[i] == vs_char_terminator) {
            break;
        }
        stringBuf[pos] = _stringBuf[i];
    }

    stringBuf[pos--] = vs_char_terminator;

    while (stringBuf[pos] == vs_char_space) {
        stringBuf[pos--] = vs_char_terminator;
        if (pos < 0) {
            return 1;
        }
    }

    pos += 2;

    while (pos < 24) {
        stringBuf[pos++] = vs_char_zero;
    }

    return 0;
}

static char D_80105DB1 = 0;
static u_char D_80105DB2 = 0;
static u_short _renameMenuStrings[] = {
#include "../../assets/MENU/MENU8.PRG/rename.vsString"
};

extern u_long* D_1F800000[];

static void func_80103FD8(int arg0)
{
    static int D_80105EA8[] = { 0x004800D8, 0x00B4008E, 0x00480070, 0x00E00070,
        0x004800D8, 0x00E000D8, 0x00B4008E, 0x00E00070, 0x004800D8, 0x00B40122,
        0x00E000D8, 0x00E00140, 0x004800D8, 0x00480140, 0x00B40122, 0x00E00140 };

    static char D_80105EE8[] = { vs_char_terminator, vs_char_terminator,
        vs_char_terminator, vs_char_terminator };
    static char D_80105EEC[8] = { 0 };
    static char D_80105EF4 = 0;

    u_int* sp18;
    int temp_s4;
    int temp_t1;
    int j;
    int i;
    char* commandString;
    u_long* var_s1;
    int temp_s0_2;
    int temp_s3;

    sp18 = (u_int*)D_1F800000[1] - 1;
    vs_mainmenu_drawButton(3, (-arg0 + 16), 50, 0);
    vs_mainmenu_drawButton(1, (-arg0 + 16), 66, 0);
    vs_mainmenu_drawButton(0, (-arg0 + 16), 82, 0);
    var_s1 = (void*)func_800C0214(0x100010, ((-arg0 + 16) & 0xFFFF) | 0x220000);
    var_s1[4] = 0x37FB70B0;
    var_s1 += 6;
    D_80105EEC[D_80105DB2] = 8;
    D_80105DB2 = 0;

    for (i = 1; i < 5; ++i) {
        temp_s0_2 = D_80105EEC[i];
        if (D_80105EEC[i] != 0) {
            --D_80105EEC[i];
        }
        temp_s4 = func_800C8FAC(8 - temp_s0_2, 0, 128) | 0x50000000;
        temp_t1 = func_800C8FAC(temp_s0_2, 0, 128);

        for (j = 0; j < 12; ++j) {
            int v1;
            var_s1[0] = (*sp18 & 0xFFFFFF) | 0x06000000;
            var_s1[1] = vs_getTpage(0, 0, 0, 0, 1);
            var_s1[2] = temp_s4;
            var_s1[3] = ((-arg0) & 0xFFFF) | (j + 20 + i * 16) << 16;
            var_s1[4] = temp_t1;
            v1 = j - 96;
            var_s1[5] = ((-arg0 - v1) & 0xFFFF) | (j + 20 + i * 16) << 16;
            var_s1[6] = vs_getTpage(0, 0, 0, 0, 0);
            *sp18 = ((u_long)var_s1 << 8) >> 8;
            var_s1 += 7;
        }
    }

    D_1F800000[0] = var_s1;
    func_800C7210(4);
    for (i = 0; i < 4; ++i) {
        commandString =
            (char*)&_renameMenuStrings[_renameMenuStrings[VS_rename_INDEX_insert - i]];
        temp_s4 = 40;
        while ((j = *commandString++) != vs_char_terminator) {
            func_800C70F8(j, temp_s4 - arg0, 84 - (i * 16), D_1F800000[1] - 5);
            temp_s4 += 6;
        }
    }

    vs_battle_setMenuItem(0x1D, arg0 + 0x9C, 0x30, 0xA4, 0, D_80105EE8)->selected = 1;
    for (j = 0; j < 20; ++j) {
        temp_s0_2 = _stringBuf[j];
        if (temp_s0_2 != vs_char_space) {
            int new_var3 = (j * 6 + 0xA2);
            func_800C70F8(temp_s0_2, arg0 + new_var3, 0x30, D_1F800000[2] - 2);
        }
    }
    if (arg0 == 0) {
        u_long* a1;
        temp_s3 = 0x404040;
        temp_s4 = 0x37F9;
        if ((D_80105DB0 != 0) || (D_80105DB1 != 0xB)) {
            temp_s3 = 0x808080;
            ++D_80105DB1;
            --temp_s4;
            if (D_80105DB1 >= 0xC) {
                D_80105DB1 = 0;
            }
        }
        D_80105DB0 = 0;
        j = (D_80105DB1 >> 2);
        func_800C6540("1", 0x330098, temp_s3, 0);
        func_800C6540("L", 0x330092, temp_s3, 0);
        func_800C0214(0x100010, (136 - j) | 0x300000)->unk10 = (temp_s4 << 0x10) | 0x3000;
        func_800C6540("1", 0x330124, temp_s3, 0);
        func_800C6540("R", 0x33011E, temp_s3, 0);
        func_800C0214(0x100010, (j + 0x128) | 0x300000)->unk10 =
            (temp_s4 << 0x10) | 0x3010;
        a1 = D_1F800000[2];
        var_s1 = D_1F800000[0];
        var_s1[0] = ((u_long)a1[0] & 0xFFFFFF) | 0x09000000;
        var_s1[1] = vs_getTpage(0, 0, 0, 0, 1);
        var_s1[2] = vs_getRGB0(primPolyG4, 0, 0, 0);
        var_s1[3] = vs_getRGB888(208, 0, 30);
        var_s1[4] = 0;
        var_s1[5] = vs_getRGB888(232, 0, 32);
        var_s1[6] = 0xC0A080;
        var_s1[7] = vs_getRGB888(232, 0, 46);
        var_s1[8] = 0;
        var_s1[9] = vs_getRGB888(0, 1, 30);
        D_1F800000[2][0] = ((u_long)var_s1 << 8) >> 8;
        D_1F800000[0] = var_s1 + 10;

        if (++D_80105EF4 >= 0xC) {
            D_80105EF4 = 0;
        }
    }

    commandString = (char*)(_renameMenuStrings + VS_rename_OFFSET_charTable);
    for (i = 0; i < 9; ++i) {
        for (j = 0; j < 14; ++j) {
            int temp_s8 = (arg0 + 0x82);
            func_800C70F8(commandString[i * 15 + j], temp_s8 + j * 12, (i * 16) + 78,
                D_1F800000[2] - 2);
        }
    }

    for (j = 0; j < 16; j += 4) {
        var_s1 = D_1F800000[0];
        var_s1[0] = (*sp18 & 0xFFFFFF) | 0x09000000;
        var_s1[1] = vs_getTpage(0, 0, 0, 0, 1);
        var_s1[2] = vs_getRGB0(primPolyG4, 0, 65, 107);
        var_s1[3] = arg0 + D_80105EA8[j];
        var_s1[4] = 0x330500;
        var_s1[5] = arg0 + D_80105EA8[j + 1];
        var_s1[6] = 0x330500;
        var_s1[7] = arg0 + D_80105EA8[j + 2];
        var_s1[8] = 0x330500;
        var_s1[9] = arg0 + D_80105EA8[j + 3];
        *sp18 = ((u_long)var_s1 << 8) >> 8;
        D_1F800000[0] = (u_long*)(var_s1 + 10);
    }
}

static void _highlightSelection(int x, int y, int w, int h)
{
    u_long* temp_t0;
    u_long* temp_t4;

    temp_t4 = D_1F800000[2];
    temp_t0 = D_1F800000[0];
    temp_t0[0] = (*temp_t4 & 0xFFFFFF) | 0x09000000;
    temp_t0[1] = vs_getTpage(0, 0, 0, semiTransparencyFull, ditheringOn);
    temp_t0[2] = vs_getRGB0(primPolyG4SemiTrans, 128, 160, 192);
    temp_t0[3] = (x | (y << 16));
    temp_t0[4] = 0;
    temp_t0[5] = (x + w) | (y << 16);
    temp_t0[6] = 0;
    temp_t0[7] = x | ((y + h) << 16);
    temp_t0[8] = vs_getRGB888(128, 160, 192);
    temp_t0[9] = (x + w) | ((y + h) << 16);
    *temp_t4 = ((u_long)temp_t0 << 8) >> 8;
    D_1F800000[0] = temp_t0 + 10;
}

static int _highlightCharSelection(int arg0, int column, int row)
{
    int x;
    int y;

    x = column * 12;
    y = row * 16;
    _highlightSelection(x + 128, y + 76, 10, 18);
    return func_800FFCDC(arg0, (x + 112) | ((y + 66) << 16));
}

static int _confirmScreen(int init)
{
    static char cursorState = 0;
    static int _0[] = { 0x01002AFA, 0x00E79CF1 }; // Junk string?

    static char state;
    static char selectedRow;
    static char _1[14];

    int i;

    if (init != 0) {
        selectedRow = 0;
        state = 0;
    }

    switch (state) {
    case 0:
    case 1:
    case 2: {
        vs_battle_menuItem_t* menuItem = vs_battle_setMenuItem(state + 20, 320,
            (state * 16) + 128, 0x7E, 0,
            (char*)&_renameMenuStrings[_renameMenuStrings[state
                                                          + VS_rename_INDEX_optionYes]]);
        menuItem->state = 2;
        menuItem->x = 194;
        ++state;
        break;
    }
    case 3:
        state += vs_mainmenu_ready();
        break;
    case 4:
        for (i = 0; i < 3; ++i) {
            vs_battle_getMenuItem(i + 20)->selected = (selectedRow ^ i) == 0;
        }

        if (vs_main_buttonsPressed.all & (PADRright | PADRdown)) {
            for (i = 0; i < 3; ++i) {
                func_800FA8A0(i + 20);
            }
            if (vs_main_buttonsPressed.all & PADRdown) {
                selectedRow = 1;
            }
            return selectedRow + 1;
        }
        i = selectedRow;
        if (vs_main_buttonRepeat & PADLup) {
            i += 2;
        }
        if (vs_main_buttonRepeat & PADLdown) {
            ++i;
        }
        if (i >= 3) {
            i -= 3;
        }
        if (i != selectedRow) {
            vs_battle_playMenuChangeSfx();
            selectedRow = i;
        }
        cursorState = vs_battle_drawCursor(cursorState, i + 7);
        break;
    }
    return 0;
}

static void func_8010493C(int arg0)
{
    int i;

    if (arg0 < 4) {
        D_80105DB2 = arg0 + 1;
    }

    for (i = 4; i < 9; ++i) {
        vs_battle_getMenuItem(i + 29)->selected = i == arg0;
    }
}

static int func_801049A0(int arg0)
{
    static char D_80105F10[24];
    static char D_80105F28;
    static char D_80105F29;
    static char _charTableColumn;
    static char _charTableRow;
    static u_char currentPos;
    static char D_80105F2D;
    int temp_v0_10;
    int var_a1;
    int var_s1;
    char* temp_s0;
    if (arg0 != 0) {
        _charTableColumn = 0;
        _charTableRow = 0;
        currentPos = 0;
        D_80105F2D = 0;
        D_80105F29 = 8;
        D_80105F28 = 0;
        return 0;
    }
    switch (D_80105F28) {
    case 0:
        if (D_80105F29 != 0) {
            --D_80105F29;
        } else {
            D_80105F28 = 2;
        }
        break;

    case 1:
        currentPos = _insertDeleteHandler(currentPos);
        if (vs_main_buttonsPressed.all & (1 << 11)) {
            vs_battle_playMenuSelectSfx();
            func_8010493C(255);
            D_80105F28 = 3;
            break;
        }
        if (vs_main_buttonRepeat & (1 << 6)) {
            vs_battle_playMenuChangeSfx();
            if (currentPos != 0) {
                --currentPos;
                for (var_s1 = currentPos; var_s1 < 19; ++var_s1) {
                    _stringBuf[var_s1] = _stringBuf[var_s1 + 1];
                }

                _stringBuf[19] = 0x8F;
            }
        }
        var_s1 = _charTableRow;
        if (vs_main_buttonsPressed.all & (1 << 13)) {
            vs_battle_playMenuChangeSfx();
            func_8010493C(255);
            if (var_s1 == 3) {
                var_s1 = 1;
            } else {
                var_s1 = 0;
            }
            _charTableRow = var_s1;
            D_80105F28 = 2;
            break;
        }
        if (vs_main_buttonsPressed.all & (1 << 5)) {
            switch (var_s1) {
            case 0:
                vs_battle_playMenuSelectSfx();
                func_8010493C(255);
                D_80105F28 = 3;
                break;

            case 1:
                if (currentPos != 0) {
                    --currentPos;
                    for (var_a1 = currentPos; var_a1 < 19; ++var_a1) {
                        _stringBuf[var_a1] = _stringBuf[var_a1 + 1];
                    }

                    _stringBuf[19] = vs_char_space;
                }
                break;

            case 2:
                for (var_a1 = currentPos; var_a1 < 0x13; ++var_a1) {
                    _stringBuf[var_a1] = _stringBuf[var_a1 + 1];
                }

                _stringBuf[19] = vs_char_space;
                break;

            case 3:
                for (var_a1 = 0x13; currentPos < var_a1; --var_a1) {
                    _stringBuf[var_a1] = _stringBuf[var_a1 - 1];
                }

                _stringBuf[currentPos] = vs_char_space;
                break;
            }

            if (D_80105F28 != 1) {
                break;
            }
            vs_battle_playMenuChangeSfx();
        }
        if (vs_main_buttonRepeat & (1 << 12)) {
            if (var_s1 == 0) {
                if (vs_main_buttonsPressed.all & (1 << 12)) {
                    var_s1 = 3;
                }
            } else {
                --var_s1;
            }
        }
        if (vs_main_buttonRepeat & (1 << 14)) {
            if (var_s1 == 3) {
                if (vs_main_buttonsPressed.all & (1 << 14)) {
                    var_s1 = 0;
                }
            } else {
                ++var_s1;
            }
        }
        if (var_s1 != _charTableRow) {
            vs_battle_playMenuChangeSfx();
            _charTableRow = var_s1;
        }
        func_8010493C(var_s1);
        D_80105F29 = func_800FFCDC(D_80105F29, ((var_s1 * 16) + 28) << 16);
        break;

    case 2:
        currentPos = _insertDeleteHandler(currentPos);
        if (vs_main_buttonsPressed.all & (1 << 11)) {
            vs_battle_playMenuSelectSfx();
            D_80105F28 = 3;
            break;
        }
        if (vs_main_buttonsPressed.all & (1 << 5)) {
            vs_battle_playMenuChangeSfx();
            var_s1 = _charTable[_charTableColumn + (_charTableRow * 15)];
            _stringBuf[currentPos] = var_s1;
            if (currentPos < 19) {
                ++currentPos;
            }
        }
        if (vs_main_buttonRepeat & (1 << 6)) {
            vs_battle_playMenuChangeSfx();
            if (currentPos != 0) {
                --currentPos;
                for (var_s1 = currentPos; var_s1 < 19; ++var_s1) {
                    _stringBuf[var_s1] = _stringBuf[var_s1 + 1];
                }

                _stringBuf[19] = vs_char_space;
            }
        }
        var_a1 = _charTableColumn + (_charTableRow * 14);
        if (vs_main_buttonRepeat & (1 << 12)) {
            if (_charTableRow != 0) {
                --_charTableRow;
            } else if (vs_main_buttonsPressed.all & (1 << 12)) {
                _charTableRow = 8;
            }
        }
        if (vs_main_buttonRepeat & (1 << 14)) {
            if (_charTableRow == 8) {
                if (vs_main_buttonsPressed.all & (1 << 14)) {
                    _charTableRow = D_80105F28 != 2;
                }
            } else {
                ++_charTableRow;
            }
        }
        if (vs_main_buttonRepeat & (1 << 15)) {
            if (_charTableColumn == 0) {
                if (vs_main_buttonsPressed.all & (1 << 15)) {
                    vs_battle_playMenuChangeSfx();
                    if (_charTableRow == 0) {
                        _charTableRow = 2;
                    } else {
                        _charTableRow = 3;
                    }
                    D_80105F28 = 1;
                    break;
                }
            } else {
                --_charTableColumn;
            }
        }
        if (vs_main_buttonRepeat & (1 << 13)) {
            if (_charTableColumn == 13) {
                if (vs_main_buttonsPressed.all & (1 << 13)) {
                    _charTableColumn = 0;
                }
            } else {
                ++_charTableColumn;
            }
        }
        if (var_a1 != (_charTableColumn + (_charTableRow * 14))) {
            vs_battle_playMenuChangeSfx();
        }
        break;

    case 3:
        func_8010493C(0);
        D_80105F30 = 0;
        D_80105F28 = 4;
        break;

    case 4:
        if (_animStep == 0xA) {
            if (_copyNormalizedString(D_80105F10) != 0) {
                vs_battle_rMemcpy(D_80105F10,
                    vs_mainMenu_itemNames
                        + D_80060168.unk280[D_80060168.unk0[D_80105F2E][1] - 1][0],
                    0x18);
            }
            func_800C8E04(1);
            vs_battle_stringContext.strings[0] = D_80105F10;
            vs_battle_printf(vs_battle_stringBuf,
                (char*)(_renameMenuStrings + VS_rename_OFFSET_confirmPrompt));
            vs_mainmenu_setMessage(vs_battle_stringBuf);
            _confirmScreen(1);
            D_80105F28 = 5;
        }
        break;

    case 5:
        temp_v0_10 = _confirmScreen(0);
        if (temp_v0_10 != 0) {
            func_800CD064(7);
            if (temp_v0_10 == 2) {
                vs_battle_playMenuLeaveSfx();
                D_80105F30 = 1;
                D_80105F28 = 6;
                break;
            }
            temp_s0 = D_80060168.unk0[D_80105F2E];
            if (temp_v0_10 == 1) {
                vs_main_playSfxDefault(0x7E, 0xD);
                vs_battle_rMemcpy(temp_s0 + 8, D_80105F10, sizeof(D_80105F10));
                if (temp_s0[3] != 0) {
                    func_8006B338(temp_s0);
                }
                return 1;
            }
            vs_battle_playMenuLeaveSfx();
            if (temp_s0[8] == 0xE7) {
                vs_battle_rMemcpy(temp_s0 + 8,
                    vs_mainMenu_itemNames + D_80060168.unk280[temp_s0[1] - 1][0], 0x18);
            }
            return 1;
        }
        break;

    case 6:
        if (_animStep == 0) {
            _charTableColumn = 0;
            _charTableRow = 0;
            D_80105F28 = 2;
            break;
        }
        break;
    }

    if (D_80105F28 == 2) {
        D_80105F29 = _highlightCharSelection(D_80105F29, _charTableColumn, _charTableRow);
    }
    if (((u_int)(D_80105F28 - 1)) < 2U) {
        _highlightSelection((currentPos * 6) + 0xA1, 0x30, 8, 0xC);
    }
    return 0;
}

int vs_menu8_execRename(char* state)
{
    int i;
    int currentState;
    char* var_v1;
    char* var_v0;
    int v1;

    currentState = *state;
    switch (*state) {
    case 0:
        D_80105F2E = vs_battle_stringBuf[1];
        _charTable = (char*)(_renameMenuStrings + VS_rename_OFFSET_charTable);
        func_800FFBA8();
        v1 = vs_char_space;
        i = 19;
        var_v0 = &_stringBuf[i];
        for (; i >= 0; --i) {
            *var_v0-- = v1;
        }
        if (vs_battle_stringBuf[0] == 1) {
            var_v1 = &D_80060168.unk0[D_80105F2E][8];
            for (i = 0; i < 20; ++i) {
                int c = *var_v1++;
                if (c == vs_char_terminator) {
                    break;
                } else if (c == vs_char_space) {
                    continue;
                } else if (c == vs_char_spacing) {
                    ++var_v1;
                } else {
                    _stringBuf[i] = c;
                }
            }
        }
        D_80105F30 = 0;
        _animStep = 10;
        *state = 1;
        break;
    case 1:
        func_801049A0(1);
        D_80105F30 = currentState;
        *state = 2;
        break;
    case 2:
        if (func_801049A0(0) != 0) {
            func_800FA8A0(0xA);
            func_800FA810(0);
            func_800FFBC8();
            *state = 3;
        }
        break;
    case 3:
        if (_animStep == 10) {
            *state = 0;
            vs_battle_menuState.currentState = 13;
        }
        break;
    }
    if (D_80105F30 != 0) {
        if (_animStep != 0) {
            --_animStep;
        }
        func_80103FD8(vs_battle_rowAnimationSteps[_animStep]);
    } else if (_animStep < 10) {
        ++_animStep;
        func_80103FD8(_animStep << 5);
    }
    return 0;
}
