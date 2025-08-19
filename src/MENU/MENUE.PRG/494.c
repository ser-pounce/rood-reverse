#include "common.h"
#include "../../SLUS_010.40/main.h"
#include "../../SLUS_010.40/sfx.h"
#include "../MAINMENU.PRG/C48.h"
#include "../MAINMENU.PRG/413C.h"
#include "../MAINMENU.PRG/8170.h"
#include "../../BATTLE/BATTLE.PRG/146C.h"
#include "../../BATTLE/BATTLE.PRG/5BF94.h"
#include "gpu.h"
#include "lbaMacros.h"
#include "lbas.h"
#include <libetc.h>
#include <stdio.h>

typedef struct {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
} _menuBgTransparencies_t;

typedef struct {
    int unk0;
    int unk4;
    int unk8;
} _menuBgChunkWidths_t;

enum arrowType_e {
    arrowTypeUp,
    arrowTypeDown,
};

typedef struct {
    short enabled;
    u_short stateBits;
    short stateDuration;
    short repeat;
    short currentStateBit;
    short frameCounter;
    short state;
    short _;
} BlinkState_t;

static char* _vsStringCpy(char* arg0, char* arg1);
static int _initState();
static int _showMenu();
static void func_80103E6C(short*);
static void _drawPaginationArrow(enum arrowType_e arrowType);
static void _drawContentLines();
static short _getBlinkState(BlinkState_t* arg0);
static int _topMenu(int arg0);
static void _copySprites(u_long const* arg0, int arg1);
static void _copyCluts(u_long* arg0, int arg1);
static int _calculateContentEnd();
static void func_80103BC8();
static void func_80103CF0();
static void _setPageBg(int arg0, int arg1, int arg2, int arg3, int arg4);
static void _fadeMenuUpper();
static void _fadeMenuLower();
static void _drawControlsBg(int x, int y, int w, int h);

static void func_80102C94(int arg0)
{
    if (arg0 != 0) {
        func_800FFA88(2);
        D_801022D6 = 0;
        return;
    }
    func_800FFA88(0);
    D_801022D6 = 1;
}

static void _setMenuRows(int rowCount, int highlightedRow, char** strings)
{
    int rowTypes[rowCount];
    int i;
    char cursor;

    for (i = 0; i < rowCount; ++i) {
        rowTypes[i] = 0;
    }

    rowTypes[rowCount - 1] |= 4;

    if ((rowCount < 9) || (highlightedRow < 8)) {
        D_800F4EE8.unk0[4] = highlightedRow;
        D_800F4EE8.unk0[5] = 0;
    } else if (highlightedRow >= (rowCount - 8)) {
        D_800F4EE8.unk0[4] = highlightedRow - (rowCount - 9);
        D_800F4EE8.unk0[5] = rowCount - 9;
    } else {
        D_800F4EE8.unk0[4] = 4;
        D_800F4EE8.unk0[5] = highlightedRow - 4;
    }
    cursor = vs_main_settings.cursorMemory;
    vs_main_settings.cursorMemory = 1;
    vs_mainmenu_setMenuRows(rowCount, 0x102, strings, rowTypes);
    vs_main_settings.cursorMemory = cursor;
}

static int _getSelectedRow()
{
    int row;

    row = vs_mainmenu_getSelectedRow();
    if (row < -1) {
        func_800FA8E0(5);
        return row;
    }
    if (row >= 0) {
        func_800FA92C(D_800F4EE8.unk0[4], 1);
    }
    return row;
}

static void func_80102E48(char* text)
{
    vs_battle_menuItem_t* menuItem;

    menuItem = vs_battle_setMenuItem(10, 320, 34, 0x8C, 9, text);
    menuItem->state = 2;
    menuItem->x = 180;
    menuItem->selected = 1;
    menuItem->unkA = 1;
}

static void func_80102E9C() { func_800FA8E0(8); }

static void _menuReady() { vs_mainmenu_ready(); }

static u_short D_80104E54[] = {
#include "../../assets/MENU/MENUE.PRG/menuText.vsString"
};

// Junk?
static u_short _0 = 0x0380;

int vs_menuE_exec(char* state)
{
    static int menuResult = 0;
    static char init = 0;
    static char D_8010522D = 0;
    static short _2 = 0x54;

    switch (*state) {
    case 3:
        func_800FFB68(1);
        D_8010522D = 8;
        init = 0;
        *state = 4;
        break;
    case 4:
        if (init == 0) {
            init = _initState();
        }
        if (D_8010522D != 0) {
            D_8010522D -= 1;
        } else if (init != 0) {
            func_8008A4DC(0);
            func_800CB654(1);
            D_800EB9B0 = 0x200000;
            *state = 5;
        }
        break;
    case 5:
        *state += vs_mainmenu_ready();
        break;
    case 6:
        menuResult = _showMenu();
        if (menuResult == 0) {
            break;
        }
        func_80100414(-4, 0x80);
        func_800CB654(0);
        D_800EB9B0 = 0;
        func_8008A4DC(1);
        func_800FFA88(0);
        func_800FA8E0(0x28);
        *state = 7;
        break;
    case 7:
        func_800FFB68(0);
        *state = 8;
        break;
    case 8:
        if (D_801022D8 != 0) {
            break;
        }
        if (menuResult == 2) {
            vs_battle_menuState.currentState = 0xA;
        }
        D_801022D6 = 0;
        *state = 0;
        return 1;
    }
    return 0;
}

// Likely file split but...meh

static int _topMenu_state;
static int _selectedRow;
static vs_main_CdQueueSlot* _helpTextCdQueue;
static vs_main_CdQueueSlot* _helpAssetsCdQueue;
static int _showMenuState;
static int _scrollPosition;
static int _contentEnd;
static int _pageArrowAnimState;
static int D_80105250;
static int* _helpText;
static u_long* _helpAssets;

static int _initState()
{
    if (D_80060021 == 0) {
        vs_main_bzero(
            &vs_battle_manualDisplayState, sizeof(vs_battle_manualDisplayState));
    }
    func_8007DFF0(0x1D, 3, 5);
    _showMenuState = 0;
    _scrollPosition = 0;
    _contentEnd = 0;
    _helpText = NULL;
    _helpAssets = NULL;
    return 1;
}

// Unused data, seems to be a miscopying, perhaps through a header.
// The same data is defined and used in BATTLE.PRG
static u_int const _[] = { 0xFFEAFFFA, 0xFFEA0012, 0x0001FFFA, 0x00010012, 0xFFEAFFEF,
    0xFFEA0007, 0x0001FFEF, 0x00010007, 0xFFE3FFF6, 0xFFE30014, 0x0001FFF6, 0x00010014,
    0xFFE3FFED, 0xFFE30009, 0x0001FFED, 0x00010009, 0xFFF0FFF7, 0xFFF0000B, 0xFFFDFFF7,
    0xFFFD000B, 0xFFF0FFF6, 0xFFF0000A, 0xFFFDFFF6, 0xFFFD000A, 0x10581040, 0x27582740,
    0x103F1057, 0x273F2757, 0x11971179, 0x2F972F79, 0x11781196, 0x2F782F96, 0x11B411A0,
    0x1EB41EA0, 0x119F11B3, 0x1E9F1EB3, 0xFFF0FFFE, 0xFFF0FFF2, 0xFFEB0000, 0xFFEBFFF9,
    0xFFF50003, 0xFFF50003, 0x00400000, 0x000C0024, 0x00400000, 0x000C0018, 0x00400018,
    0x000C0014, 0x0040002C, 0x000C0018, 0x004000E0, 0x000C0010, 0x004C00D4, 0x000C0020,
    0x00400096, 0x000C001A, 0x00400044, 0x000C0028, 0x0040006C, 0x000C001E, 0x0040008A,
    0x000C0032, 0x004000BC, 0x000C0024, 0x004C0000, 0x000C0034, 0x004C0034, 0x000C001E,
    0x00580090, 0x000C003A, 0x004C0078, 0x000C003C, 0x004C00B4, 0x000C001E, 0x00580088,
    0x000C0008, 0x00580068, 0x000C0020, 0x0058004C, 0x000C0028, 0x00580000, 0x000C0010,
    0x00580014, 0x000C0014, 0x00580028, 0x000C001E, 0x00580048, 0x000C0020, 0x004C0066,
    0x000C0010, 0x006400DC, 0x000C0012, 0x00340098, 0x000C001A, 0x002800B6, 0x000C001E,
    0x002800D6, 0x000C0018, 0x00340098, 0x000C001C, 0x003400B4, 0x000C0028, 0x003400DC,
    0x000C001E, 0x0040006C, 0x000C001E, 0x001C00D8, 0x000C001C, 0x00001F01, 0x001B1D02,
    0x001B1E02, 0x001A1C02, 0x001B2002, 0x00050102, 0x01040102, 0x00050202, 0x01040202,
    0x00050302, 0x01040302, 0x02000701, 0x02000801, 0x02000901, 0x02000A01, 0x02000B01,
    0x02000C01, 0x03000D01, 0x03000E01, 0x00050F02, 0x01040F02, 0x02131002, 0x02141002,
    0x02151002, 0x02161002, 0x02131102, 0x02141102, 0x02151102, 0x02161102, 0x00000000,
    0x00000000, 0x00000000, 0x00D0D0D0, 0x00FFC040, 0x0030D0FF, 0x0060E0A0, 0x00A00048,
    0x00080020, 0x00A8004C, 0x0008001C, 0x00B0004E, 0x0008001A, 0x00B8004E, 0x0008001A,
    0x00C00052, 0x00080016, 0x00C80052, 0x00080016, 0x00D00052, 0x00080016, 0x00A00068,
    0x0008001C, 0x00A80068, 0x0008001A, 0x00B00068, 0x0008001E, 0x00B80068, 0x00080024,
    0x00C00068, 0x00080020, 0x00C80068, 0x00080012, 0x00A00090, 0x0008001E, 0x00A80090,
    0x0008000E, 0x00B00090, 0x00080012, 0x00B80090, 0x0008001A, 0x00C00090, 0x0008001A,
    0x00C80090, 0x00080016, 0x00D00090, 0x00080024 };

static vs_main_CdFile const _helpFileCdFiles[] = { mkHfoPair(HELP01), mkHfoPair(HELP02),
    mkHfoPair(HELP03), mkHfoPair(HELP04), mkHfoPair(HELP05), mkHfoPair(HELP06),
    mkHfoPair(HELP07), mkHfoPair(HELP08), mkHfoPair(HELP09), mkHfoPair(HELP10),
    mkHfoPair(HELP11), mkHfoPair(HELP12), mkHfoPair(HELP13), mkHfoPair(HELP14) };

static P_CODE const _colorStops0[] = { { 0, 0x20, 0x50, 0 }, { 0x19, 0x82, 0x6C, 0 },
    { 0x40, 0x30, 0x66, 0 }, { 0x40, 0x38, 0x20, 0 } };
static P_CODE const _colorStops1[] = { { 0, 0x5, 0x33, 0 }, { 0x1, 0x28, 0x26, 0 },
    { 0x8, 0x8, 0x20, 0 }, { 0x10, 0x10, 0x8, 0 } };

static int _showMenu()
{
    char charBuf[60];
    int temp_s2;
    int selectedRow;
    int var_s1;
    u_long** s0;
    int cdState;

    switch (_showMenuState) {
    case 0:
        func_80100414(0x7FE, 0x80);
        ++_showMenuState;
        break;
    case 1:
        func_800FFBC8();
        _topMenu(1);
        ++_showMenuState;
        break;
    case 2:
        selectedRow = _topMenu(0);
        if (selectedRow == -1) {
            break;
        }
        if (selectedRow < 0) {
            if (selectedRow == -3) {
                _showMenuState = 7;
            } else {
                _showMenuState = 6;
            }
        } else {
            _showMenuState = 3;
            if (_helpText != NULL) {
                vs_main_freeHeapR(_helpText);
            }
            if (_helpAssets != NULL) {
                vs_main_freeHeapR(_helpAssets);
            }

            _helpText = vs_main_allocHeapR(_helpFileCdFiles[selectedRow * 2 + 1].size);
            _helpAssets = vs_main_allocHeapR(_helpFileCdFiles[selectedRow * 2].size);
            _helpAssetsCdQueue
                = vs_main_allocateCdQueueSlot(&_helpFileCdFiles[selectedRow * 2]);
            vs_main_cdEnqueue(_helpAssetsCdQueue, _helpAssets);
            _helpTextCdQueue
                = vs_main_allocateCdQueueSlot(&_helpFileCdFiles[selectedRow * 2 + 1]);
            vs_main_cdEnqueue(_helpTextCdQueue, _helpText);
        }
        vs_battle_manualDisplayState.currentManual
            = D_800F4EE8.unk0[4] + D_800F4EE8.unk0[5];
        func_800FFBA8();
        break;
    case 3:
        cdState = _helpAssetsCdQueue->state;
        if (cdState != vs_main_CdQueueStateLoaded) {
            break;
        }
        vs_main_freeCdQueueSlot(_helpAssetsCdQueue);
        _copySprites(_helpAssets + 2, _helpAssets[0]);
        _copyCluts(_helpAssets + ((_helpAssets[0] << 5) + 2), _helpAssets[1]);
        if (_helpAssets != NULL) {
            vs_main_freeHeapR(_helpAssets);
        }
        _helpAssets = NULL;
        _showMenuState = 4;
        break;
    case 4:
        if (_helpTextCdQueue->state != vs_main_CdQueueStateLoaded) {
            break;
        }
        vs_main_freeCdQueueSlot(_helpTextCdQueue);
        func_800CCF08(0, 0, 8, 0x34, 0x19, 0xA, 8, 0x34);
        _scrollPosition
            = vs_battle_manualDisplayState
                  .scrollPositions[vs_battle_manualDisplayState.currentManual];
        _contentEnd = _calculateContentEnd();
        _showMenuState = 5;
        D_80105250 = 0;
        break;
    case 5:
        var_s1 = _scrollPosition / 10;
        temp_s2 = _contentEnd / 10;
        if (vs_main_buttonsPressed.all & (PADRright | PADRdown)) {
            _showMenuState = 1;
        }
        if (vs_main_buttonsPressed.all & PADRup) {
            _showMenuState = 7;
        }
        if (vs_main_buttonsPressed.all & PADstart) {
            var_s1 = 0;
            _scrollPosition = 0;
        } else if (vs_main_buttonsPreviousState & PADRleft) {
            if ((vs_main_buttonsPressed.all & PADLup) && (var_s1 == 0) && (temp_s2 > 0)) {
                var_s1 = temp_s2;
                _scrollPosition = temp_s2 * 10;
                vs_main_playSfxDefault(0x7E, VS_SFX_MENUCHANGE);
            } else if ((vs_main_buttonsPressed.all & PADLdown) && (var_s1 == temp_s2)
                && (temp_s2 > 0)) {
                var_s1 = 0;
                _scrollPosition = 0;
                vs_main_playSfxDefault(0x7E, VS_SFX_MENUCHANGE);
            } else if ((vs_main_buttonRepeat & PADLup) && (var_s1 > 0)) {
                var_s1 -= 1;
                _scrollPosition = var_s1 * 10;
                vs_main_playSfxDefault(0x7E, VS_SFX_MENUCHANGE);
            } else if ((vs_main_buttonRepeat & PADLdown) && (var_s1 < temp_s2)) {
                var_s1 += 1;
                _scrollPosition = var_s1 * 10;
                vs_main_playSfxDefault(0x7E, VS_SFX_MENUCHANGE);
            }
        } else {
            if ((vs_main_buttonsPressed.all & PADLup) && (_scrollPosition == 0)
                && (_contentEnd > 0)) {
                _scrollPosition = _contentEnd;
                vs_main_playSfxDefault(0x7E, VS_SFX_MENUCHANGE);
            } else if (vs_main_buttonsPressed.all & PADLdown
                && (_scrollPosition == _contentEnd) && (_scrollPosition > 0)) {
                _scrollPosition = 0;
                vs_main_playSfxDefault(0x7E, VS_SFX_MENUCHANGE);
            } else if ((vs_main_buttonRepeat & PADLup) && (_scrollPosition > 0)) {
                --_scrollPosition;
                vs_main_playSfxDefault(0x7E, VS_SFX_MENUCHANGE);
            } else if ((vs_main_buttonRepeat & PADLdown)
                && (_scrollPosition < _contentEnd)) {
                ++_scrollPosition;
                vs_main_playSfxDefault(0x7E, VS_SFX_MENUCHANGE);
            }
        }
        s0 = (u_long**)getScratchAddr(0);
        func_800FFC68(1, 8, 0x10, s0[1] + 6);
        func_800C6540("TURN    PAGE", 0x12001C, 0x808080, s0[1] + 6);
        _drawControlsBg(0x10, 0x12, 0x60, 0xC);
        func_800FFC68(2, 8, 0x22, s0[1] + 6);
        func_800C6540("MENU", 0x24001C, 0x808080, s0[1] + 6);
        _drawControlsBg(0x10, 0x24, 0x40, 0xC);
        func_800C6540("PAGE", 0xC400D8, 0x808080, s0[1] + 7);
        sprintf(charBuf, "#%d/", var_s1 + 1);
        func_800C6540(charBuf, 0xC40118, 0x808080, s0[1] + 7);
        sprintf(charBuf, "#%d", temp_s2 + 1);
        func_800C6540(charBuf, 0xC40130, 0x808080, s0[1] + 7);
        vs_battle_manualDisplayState
            .scrollPositions[vs_battle_manualDisplayState.currentManual]
            = _scrollPosition;
        if (_showMenuState != 5) {
            if (vs_main_buttonsPressed.all & PADRright) {
                vs_main_playSfxDefault(0x7E, VS_SFX_MENUSELECT);
            } else {
                vs_main_playSfxDefault(0x7E, VS_SFX_MENULEAVE);
            }
            func_800CCDF4(0)->unk4[12] = 0;
            if (_helpText != NULL) {
                vs_main_freeHeapR(_helpText);
            }
            _helpText = NULL;
            break;
        }
        _setPageBg(8, 52, 310, 136, 0);
        _pageArrowAnimState = (_pageArrowAnimState + 1) & 0xF;
        if (_scrollPosition > 0) {
            _fadeMenuUpper();
        }
        if (_scrollPosition < _contentEnd) {
            _fadeMenuLower();
        }
        if (D_80105250 < 8) {
            ++D_80105250;
        } else {
            func_80103CF0();
        }
        func_80103BC8();
        break;
    case 6:
        if (_helpText != NULL) {
            vs_main_freeHeapR(_helpText);
        }
        if (_helpAssets != NULL) {
            vs_main_freeHeapR(_helpAssets);
        }
        func_8007E0A8(0x1D, 3, 5);
        return 1;
    case 7:
        if (_helpText != NULL) {
            vs_main_freeHeapR(_helpText);
        }
        if (_helpAssets != NULL) {
            vs_main_freeHeapR(_helpAssets);
        }
        func_8007E0A8(0x1D, 3, 5);
        return 2;
    }
    return 0;
}

static int _topMenu(int init)
{
    enum state { initRows, selectRow };

    char* strings[28];
    int i;

    if (init != 0) {
        _topMenu_state = 0;
        _selectedRow = 0;
    }

    switch (_topMenu_state) {
    case initRows:
        for (i = 0; i < 14; ++i) {
            strings[i * 2] = (char*)&D_80104E54[D_80104E54[i]];
            strings[i * 2 + 1] = (char*)&D_80104E54[D_80104E54[14 + i]];
        }
        _setMenuRows(14, vs_battle_manualDisplayState.currentManual, strings);
        ++_topMenu_state;
        break;
    case selectRow:
        _selectedRow = _getSelectedRow();
        if (_selectedRow != -1) {
            return _selectedRow;
        }
        break;
    }
    return -1;
}

static void _copySprites(u_long const* buffer, int count)
{
    RECT rect;
    int i;

    i = 0;
    rect.w = 4;
    rect.h = 16;

    for (i = 0; i < count; ++i) {
        rect.x = (i % 48) * 4 + 832;
        rect.y = (i / 48) * 16 + 256;
        LoadImage2(&rect, (u_long*)buffer);
        buffer += 4 * 16 / 2;
    }
}

static void _copyCluts(u_long* buffer, int count)
{
    RECT rect;
    int i;

    rect.w = 16;
    rect.h = 1;

    for (i = 0; i < count; ++i) {
        rect.x = (i % 16) * 16 + 768;
        rect.y = i / 16 + 496;
        LoadImage2(&rect, buffer);
        buffer += 8;
    }
}

static int _calculateContentEnd()
{
    int temp_v1;
    int var_a0;

    var_a0 = _helpText[4] & 0xFFFF;
    temp_v1 = (_helpText[4] & 0xFFFF) % 10;
    if (temp_v1 > 0) {
        var_a0 += 10 - temp_v1;
    }
    var_a0 -= 10;
    if (var_a0 < 0) {
        var_a0 = 0;
    }
    return var_a0;
}

static void func_80103BC8()
{
    char sp10[1024];
    int var_s0;
    int var_s2;
    u_short* temp_s3;
    char* var_a0;
    int temp_a1;

    sp10[0] = 0xF8;
    sp10[1] = 0;
    sp10[2] = 0xFB;
    sp10[3] = 6;
    sp10[4] = -0x18;

    temp_s3 = (ushort*)(_helpText + 4);
    var_s2 = _scrollPosition + 10;
    var_a0 = sp10 + 4;

    if ((u_short)_helpText[4] < var_s2) {
        var_s2 = (u_short)_helpText[4];
    }

    temp_a1 = _scrollPosition;

    for (var_s0 = temp_a1; var_s0 < var_s2; ++var_s0) {
        temp_a1 = temp_s3[var_s0 + 1];
        var_a0 = _vsStringCpy(var_a0, (char*)(temp_s3 + temp_a1));
    }

    var_a0[-1] = 0xE7;
    func_800C6BF0(0, &sp10);
}

static char* _vsStringCpy(char* arg0, char* arg1)
{
    char c;

    for (c = *arg1; c != 0xE7; c = *arg1) {
        if (c >= 0xEC) {
            *arg0 = c;
            ++arg1;
            ++arg0;
        }
        *arg0++ = *arg1++;
    }
    *arg0 = 0xE8;
    return arg0 + 1;
}

static void func_80103CF0()
{
    RECT rect;
    DR_AREA* area;
    int i;
    int var_v0;
    u_short* temp_s2;
    void** q;
    void** p = (void**)getScratchAddr(0);

    area = p[0];
    SetDrawArea(area, &vs_main_drawEnv[(vs_main_frameBuf + 1) & 1].clip);
    AddPrim(p[1], area++);
    p[0] = area;

    _drawContentLines();

    var_v0 = *_helpText;
    if (var_v0 < 0) {
        var_v0 += 3;
    }
    temp_s2 = (u_short*)_helpText + 8 + (var_v0 >> 2) * 2;

    for (i = 0; i < temp_s2[0]; ++i) {
        func_80103E6C(&temp_s2[temp_s2[i + 1]]);
    }
    if (vs_main_drawEnv[(vs_main_frameBuf + 1) & 1].clip.x >= 320) {
        rect.x = 333;
    } else {
        rect.x = 13;
    }
    rect.w = 300;
    rect.y = 55;
    rect.h = 130;

    q = (void**)getScratchAddr(0);
    area = q[0];
    SetDrawArea(area, &rect);
    AddPrim(q[1], area++);
    q[0] = area;
}

static inline void _insertTpage(int primIndex, short tpage)
{
    __asm__("scratch = $t3;"
            "tpageOp = $t4;"
            "addrMask = $t5;"
            "tpage = $t6;"
            "li         scratch, 0x1F800000;"
            "sll        $t0, %0, 2;"
            "lw         $t4, 4(scratch);"
            "lw         $t7, (scratch);"
            "addu       $t0, $t4;"
            "lw         $t1, ($t0);"
            "li         tpageOp, 0xE1000000;"
            "and        tpage, %1, 0x1FF;"
            "or         tpageOp, 0x200;"
            "or         tpageOp, tpage;"
            "sw         tpageOp, 4($t7);"
            "sw         $zero, 8($t7);"
            "li         addrMask, 0xFFFFFF;"
            "li         $t4, 0x2000000;"
            "li         $t6, 0xFF000000;"
            "and        $t2, $t1, addrMask;"
            "or         $t4, $t2;"
            "sw         $t4, ($t7);"
            "and        $t2, $t1, $t6;"
            "and        $t4, $t7, addrMask;"
            "or         $t4, $t2;"
            "sw         $t4, ($t0);"
            "addu       $t2, $t7, 0xC;"
            "sw         $t2, (scratch);"
            :
            : "r"(primIndex), "r"(tpage)
            : "t0", "t1", "t2", "t3", "t4", "t5", "t6", "t7");
}

static inline int _min(int arg0, int arg1)
{
    if (arg0 >= arg1) {
        return arg1;
    }
    return arg0;
}

static inline int _add_int(int arg0, int arg1) { return (arg0 + arg1); }

static void func_80103E6C(short* arg0)
{
    short posX;
    short posY;
    short width;
    short height;
    short tileMode;
    short clutPacked;
    int spriteW;
    int spriteH;
    int tileStride;
    int spriteX;
    int spriteY;
    int j;
    int i;
    SPRT* sprite;
    u_long** scratch;
    short tPage;

    if ((*arg0 == 0) || ((_getBlinkState((BlinkState_t*)arg0) << 0x10) == 0)) {
        arg0 += 8;
        posX = *arg0++;
        posY = *arg0++;
        width = *arg0++;
        height = *arg0++;
        ++arg0;
        tileMode = *arg0++;
        clutPacked = *arg0++;

        clutPacked = ((((clutPacked % 16) << 4) + 0x300) >> 4)
            | (((clutPacked / 16) + 0x1F0) << 6);

        tileStride = 8;
        if (tileMode == 16) {
            tileStride = 16;
        }

        for (i = 0; i < height; i += 16) {
            spriteH = _min(height - i, 16);

            for (j = 0; j < width; ++arg0, j += tileStride) {
                spriteW = _min(width - j, tileStride);
                spriteX = 0x0D;
                spriteX = posX + (j + spriteX);
                spriteY = _add_int(posY, i + 0x37);
                spriteY -= _scrollPosition * 0xD;

                if ((spriteY >= 0x27) && (spriteY < 0xB9)) {
                    int spriteV0;
                    int spriteU0;
                    sprite = *((void**)0x1F800000);
                    setSprt(sprite);
                    setShadeTex(sprite, 1);
                    sprite->clut = clutPacked;
                    setXY0(sprite, spriteX, spriteY);

                    spriteU0 = (*arg0 / 16);
                    tPage = spriteU0;
                    tPage = tPage % 3 + 0x1D;

                    if (tileMode == 0x10) {
                        sprite->u0 = ((*arg0 - (spriteU0 << 4)) << 0x10) >> 0xC;
                    } else {
                        tPage |= 0x80;
                        sprite->u0 = ((*arg0 - (spriteU0 << 4)) << 0x10) >> 0xD;
                    }

                    spriteV0 = (*arg0 / 48);
                    sprite->v0 = (spriteV0 << 4);
                    setWH(sprite, spriteW, spriteH);

                    scratch = (void*)getScratchAddr(0);
                    AddPrim(scratch[1], sprite++);
                    scratch[0] = (void*)sprite;
                    _insertTpage(0, tPage);
                }
            }
        }
    }
}

static void _setPageBg(int x, int y, int w, int h, int color)
{
    POLY_G4* poly;
    u_long** p;

    poly = *(POLY_G4**)getScratchAddr(0);
    setPolyG4(poly);
    setXY4(poly, x, y, (x + w) - 1, y, x, (y + h) - 1, (x + w) - 1, (y + h) - 1);
    setRGB0(poly, _colorStops0[color].r0, _colorStops0[color].g0, _colorStops0[color].b0);
    setRGB1(poly, _colorStops1[color].r0, _colorStops1[color].g0, _colorStops1[color].b0);
    setRGB2(poly, _colorStops0[color].r0, _colorStops0[color].g0, _colorStops0[color].b0);
    setRGB3(poly, _colorStops1[color].r0, _colorStops1[color].g0, _colorStops1[color].b0);

    p = (u_long**)getScratchAddr(0);
    AddPrim(p[1] + 7, poly++);
    p[0] = (u_long*)poly;
    _insertTpage(7, 96);
}

static _menuBgChunkWidths_t const _menuBgChunkWidths = { 128, 128, 64 };

static _menuBgTransparencies_t const _menuBgTransparencies[]
    = { { 128, 115, 121, 88 }, { 76, 64, 53, 42 }, { 33, 24, 17, 11 }, { 6, 3, 1, 0 } };

static void _fadeMenuUpper()
{
    int widths[4];
    int transparency[16];
    _menuBgTransparencies_t const* var_v0;
    _menuBgTransparencies_t* var_v1;
    int i;
    int j;
    POLY_FT4* poly;
    TILE* tile;

    *(_menuBgChunkWidths_t*)widths = _menuBgChunkWidths;

    var_v1 = (_menuBgTransparencies_t*)transparency;
    var_v0 = _menuBgTransparencies;

    do {
        *var_v1++ = *var_v0++;
    } while (var_v0 != (_menuBgTransparencies + 4));

    _drawPaginationArrow(arrowTypeUp);
    poly = *(void**)getScratchAddr(0);

    for (i = 0; i < 16; ++i) {
        for (j = 0; j < 3; ++j) {
            setPolyFT4(poly);
            setXY4(poly, j << 7, i + 52, widths[j] + (j << 7), i + 52, j << 7, i + 53,
                widths[j] + (j << 7), i + 53);
            setUV4(poly, 0, i + 52, widths[j], i + 52, 0, i + 53, widths[j], i + 53);
            setClut(poly, 768, 227);
            poly->tpage = (j + 32) | 128 | (640 >> 6) | (256 >> 4);
            setSemiTrans(poly, 1);
            setRGB0(poly, transparency[i], transparency[i], transparency[i]);
            AddPrim(*(u_long**)getScratchAddr(1) - 7, poly++);
        }
    }

    tile = (TILE*)poly;
    for (i = 0; i < 16; ++i) {
        setTile(&tile[i]);
        setSemiTrans(&tile[i], 1);
        setXY0(&tile[i], 0, i + 52);
        setWH(&tile[i], 320, 1);
        setRGB0(&tile[i], transparency[i], transparency[i], transparency[i]);
        AddPrim(*(u_long**)getScratchAddr(1) - 7, &tile[i]);
    }

    *(void**)getScratchAddr(0) = (void*)poly + 16 * sizeof(TILE);
    _insertTpage(-7, 64);
}

static void _fadeMenuLower()
{
    int widths[4];
    int transparency[16];
    _menuBgTransparencies_t const* var_v0;
    _menuBgTransparencies_t* var_v1;
    int i;
    int j;
    POLY_FT4* poly;
    TILE* tile;

    *(_menuBgChunkWidths_t*)widths = _menuBgChunkWidths;

    var_v1 = (_menuBgTransparencies_t*)transparency;
    var_v0 = _menuBgTransparencies;

    do {
        *var_v1++ = *var_v0++;
    } while (var_v0 != (_menuBgTransparencies + 4));

    _drawPaginationArrow(arrowTypeDown);

    poly = *(void**)getScratchAddr(0);

    for (i = 0; i < 16; ++i) {
        for (j = 0; j < 3; ++j) {
            setPolyFT4(poly);
            setXY4(poly, j << 7, 187 - i, widths[j] + (j << 7), 187 - i, j << 7, 188 - i,
                widths[j] + (j << 7), 188 - i);
            setUV4(poly, 0, -69 - i, widths[j], -69 - i, 0, -68 - i, widths[j], -68 - i);
            setClut(poly, 768, 227);
            poly->tpage = (j + 32) | 128 | (640 >> 6) | (256 >> 4);
            setSemiTrans(poly, 1);
            setRGB0(poly, transparency[i], transparency[i], transparency[i]);
            AddPrim(*(u_long**)getScratchAddr(1) - 7, poly++);
        }
    }

    tile = (TILE*)poly;

    for (i = 0; i < 16; ++i) {
        setTile(&tile[i]);
        setSemiTrans(&tile[i], 1);
        setXY0(&tile[i], 0, 0xBB - i);
        setWH(&tile[i], 320, 1);
        setRGB0(&tile[i], transparency[i], transparency[i], transparency[i]);
        AddPrim(*(u_long**)getScratchAddr(1) - 7, &tile[i]);
    }

    *(void**)getScratchAddr(0) = (void*)poly + 16 * sizeof(TILE);
    _insertTpage(-7, 64);
}

static void _drawPaginationArrow(enum arrowType_e arrowType)
{
    int y;
    POLY_FT4* poly;
    u_long** p;

    if (arrowType != arrowTypeUp) {
        if (_pageArrowAnimState < 9) {
            y = (_pageArrowAnimState >> 1) + 184;
        } else {
            y = -(_pageArrowAnimState >> 2) + 190;
        }
    } else {
        if (_pageArrowAnimState < 9) {
            int v0 = 40;
            y = v0 - (_pageArrowAnimState >> 1);
        } else {
            y = (_pageArrowAnimState >> 2) + 34;
        }
    }

    poly = (POLY_FT4*)*getScratchAddr(0);
    setPolyFT4(poly);
    setShadeTex(poly, 1);
    setXY4(poly, 152, y, 168, y, 152, y + 16, 168, y + 16);
    setUV4(poly, arrowType * 16, 48, arrowType * 16 + 16, 48, arrowType * 16, 64,
        arrowType * 16 + 16, 64);
    setTPage(poly, clut4Bit, semiTransparencyHalf, 768, 0);

    if (vs_main_buttonsPreviousState & PADRleft) {
        setClut(poly, 896, 223);
    } else {
        setClut(poly, 912, 223);
    }
    p = (u_long**)getScratchAddr(0);
    AddPrim(p[1] - 7, poly++);
    p[0] = (void*)poly;
}

static void _drawContentLines()
{
    short var_a1;
    short i;
    short* var_s0;
    int var_v0;
    int var_v1;
    LINE_F2* line;
    short s4;
    char* c;

    if (_helpText[2] <= 0) {
        return;
    }

    line = *(LINE_F2**)getScratchAddr(0);

    var_v1 = _helpText[0];
    if (var_v1 < 0) {
        var_v1 += 3;
    }
    var_v1 >>= 2;

    var_v0 = _helpText[1];
    if (var_v0 < 0) {
        var_v0 += 3;
    }

    var_v0 = var_v1 + (var_v0 >> 2);
    var_s0 = (short*)&(_helpText)[var_v0 + 4];

    s4 = *var_s0++;

    for (i = 0; i < s4; ++i) {
        var_a1 = 0;
        if (*var_s0 != 0) {
            var_a1 = _getBlinkState((BlinkState_t*)var_s0);
        }
        var_s0 += 8;
        setLineF2(line);
        line->x0 = *var_s0++ + 13;
        line->y0 = *var_s0++ + 55 - _scrollPosition * 13;
        line->x1 = *var_s0++ + 13;
        line->y1 = *var_s0++ + 55 - _scrollPosition * 13;
        c = (char*)var_s0;
        setRGB0(line, c[0], c[1], c[2]);
        var_s0 += 2;
        if ((line->y0 < 55) && ((line->y1 >= 55) == 0)) {
            continue;
        }
        if (((line->y0 < 186) || (line->y1 < 186)) && ((var_a1 << 16) == 0)) {
            AddPrim(*(void**)getScratchAddr(1), line++);
        }
    }
    *(void**)getScratchAddr(0) = line;
}

static short _getBlinkState(BlinkState_t* state)
{
    short nextState;

    if (state->currentStateBit >= 16) {
        return state->state;
    }

    nextState = state->stateBits >> state->currentStateBit;
    nextState = nextState & 1;

    if ((++state->frameCounter) >= state->stateDuration) {
        state->frameCounter = 0;
        if ((++state->currentStateBit) >= 16) {
            if (state->repeat != 0) {
                state->currentStateBit = 0;
            }
        }
    }
    return state->state = nextState ^ 1;
}

static void _drawControlsBg(int x, int y, int w, int h)
{
    int i;
    int j;
    LINE_G2* line;
    POLY_F4* poly;
    u_long** p;

    line = (LINE_G2*)*getScratchAddr(0);
    for (i = y, j = w; i < (y + h) - 1; ++i, --j) {
        setLineG2(line);
        setXY2(line, x, i, (x + j) - 1, i);
        setRGB0(line, 64, 56, 32);
        setRGB1(line, 16, 16, 8);
        AddPrim(*(u_long**)getScratchAddr(1) + 7, line++);
    }
    x += 2;
    y += 2;
    poly = (POLY_F4*)line;
    setPolyF4(poly);
    setXY4(poly, x, y, (x + w) - 1, y, x, (y + h) - 1, (x + w) - h, (y + h) - 1);
    setRGB0(poly, 0, 0, 0);

    p = (u_long**)getScratchAddr(0);
    AddPrim(p[1] + 7, poly);
    p[0] = (u_long*)(poly + 1);
}
