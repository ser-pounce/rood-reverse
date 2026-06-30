#include "common.h"
#include "238.h"
#include "57BC.h"
#include "src/SLUS_010.40/main.h"
#include "src/SLUS_010.40/31724.h"
#include "src/SLUS_010.40/sfx.h"
#include "src/BATTLE/BATTLE.PRG/146C.h"
#include "src/BATTLE/BATTLE.PRG/2842C.h"
#include "src/BATTLE/BATTLE.PRG/2EA3C.h"
#include "src/BATTLE/BATTLE.PRG/30D14.h"
#include "src/BATTLE/BATTLE.PRG/40564.h"
#include "src/BATTLE/BATTLE.PRG/573B8.h"
#include "src/BATTLE/BATTLE.PRG/5BF94.h"
#include "src/MENU/MAINMENU.PRG/278.h"
#include "src/MENU/MAINMENU.PRG/C48.h"
#include "src/MENU/MAINMENU.PRG/2D10.h"
#include "src/MENU/MAINMENU.PRG/58EC.h"
#include "build/assets/MENU/MENU9.PRG/menuText.h"
#include "build/assets/MENU/MENU9.PRG/rankText.h"
#include "build/assets/MENU/MENU9.PRG/titleText.h"
#include "build/assets/MENU/MENU9.PRG/titleDescriptions.h"
#include "build/assets/MENU/MENU9.PRG/statHeaders.h"
#include "build/assets/MENU/MENU9.PRG/statDescriptions.h"
#include "build/assets/MENU/MENU9.PRG/timeAttacks.h"
#include "build/assets/MENU/MENU9.PRG/timeAttackDescriptions.h"
#include "build/assets/MENU/MENU9.PRG/miscInfo.h"
#include "build/src/include/lbas.h"
#include "insertTPage.h"
#include "vs_string.h"
#include "gpu.h"
#include <libetc.h>
#include <stdio.h>
#include <strings.h>
#include <libgpu.h>
#include <abs.h>

extern void* D_1F800000[];

/**
 * Hides or shows the menu action at the very top of the menu.
 */
void _toggleMenuAction(int enable)
{
    if (enable != 0) {
        vs_mainMenu_setNextMenuAction(menuActionMenu);
        vs_mainMenu_hideMenu = 0;
    } else {
        vs_mainMenu_setNextMenuAction(menuActionNone);
        vs_mainMenu_hideMenu = 1;
    }
}

void _renderFadedMenuItem(vs_battle_menuItem_t* menuItem)
{
    static char _previousFrameBuf = 0;
    static char _navigationAnimState = 0;

    int w;
    int frameBuf;
    int animState;
    int bgWidth;
    int fadeEffect;
    char temp_v1_2;
    int brightness;
    int var_s0;
    int i;
    u_long* prim;
    u_char* menuText;
    u_int temp_a0;
    u_int xy;
    u_long* before;
    int state;
    int s5;

    menuText = menuItem->text;
    frameBuf = 0;

    if (vs_main_frameBuf == 0) {
        frameBuf = 320;
    }

    xy = *(int*)&menuItem->x;
    before = D_1F800000[2] + 8;
    w = menuItem->w;
    animState = menuItem->animationState;
    fadeEffect = menuItem->fadeEffect - 1;
    bgWidth = menuItem->backgroundWidth;

    if (vs_main_frameBuf != _previousFrameBuf) {

        ++_navigationAnimState;
        _previousFrameBuf = vs_main_frameBuf;

        if (_navigationAnimState >= 12) {
            _navigationAnimState = 0;
        }
    }

    state = menuItem->state;

    if ((state == 1) && (menuItem->x < 0x80U)) {

        var_s0 = _navigationAnimState >> 2;

        if (fadeEffect == 0) {
            var_s0 = var_s0 - 5;
        } else {
            var_s0 = state - var_s0;
        }

        vs_battle_setSpriteDefaultTexPage(128,
            (menuItem->x - 14) | ((menuItem->y + var_s0) << 0x10), vs_getWH(16, 16),
            before - 1)[4] = (fadeEffect << 4) | vs_getUV0Clut(0, 48, 912, 223);
    }

    i = menuItem->x + 6;

    while ((var_s0 = *menuText++) != vs_char_printString) {
        if (var_s0 == vs_char_spacing) {
            i += *menuText++;
        } else {
            i = func_80101268(var_s0 | (fadeEffect << 0x1F), i, menuItem, before);
        }
    }

    if (w == 0) {
        return;
    }

    prim = D_1F800000[0];

    for (i = 0, s5 = 0; i < 12; s5 += 8, ++i) {

        if (fadeEffect == 0) {
            var_s0 = s5 + 32;
        } else {
            var_s0 = s5;
            var_s0 = 120 - s5;
        }

        prim[0] = (*before & 0xFFFFFF) | (6 << 24);
        prim[1] = vs_getTpage(0, 0, clut4Bit, semiTransparencyFull, ditheringOn);
        prim[2] = vs_battle_uiGradientStop(8 - animState, bgWidth, var_s0)
                | vs_getRGB0(primLineG2SemiTrans, 0, 0, 0);
        prim[3] = xy;
        prim[4] = vs_battle_uiGradientStop(animState, bgWidth, var_s0);
        prim[5] = ((xy + w - 1) & 0xFFFF) | ((xy >> 0x10) << 0x10);
        prim[6] = vs_getTpage(0, 0, clut4Bit, semiTransparencyFull, ditheringOff);

        *before = ((u_long)prim << 8) >> 8;
        prim += 7;
        xy += vs_getXY(0, 1);
    }

    D_1F800000[0] = prim;

    if (fadeEffect == 0) {
        func_800CCCB8(before, 0x60000000, ((xy + 2) & 0xFFFF) | ((xy >> 0x10) << 0x10),
            w | 0x20000);
    }

    if (animState != 0) {
        menuItem->animationState = animState - 1;
    }

    xy = xy + (-12 << 16);
    w |= 0x10000;
    var_s0 = (menuItem->x >= 128) << 7;

    for (i = 0; i < 12; ++i) {

        if (fadeEffect == 0) {
            brightness = 120 - i * 8;
        } else {
            brightness = i * 8 + 32;
        }

        prim = vs_battle_setSprite(brightness, xy, w, before);

        temp_v1_2 = xy - var_s0;
        temp_a0 = xy >> 0x10;
        xy += 1 << 16;

        prim[1] = ((u_int)(frameBuf + var_s0) >> 6)
                | vs_getTpage(
                    0, 0, semiTransparencySubtract, semiTransparencyFull, ditheringOff);
        prim[4] = temp_v1_2 | (temp_a0 << 8);
    }
}

/**
 * Stores the current cursor position and page and sets
 * the next menu rows.
 */
void _setRows(int rowCount, int absoluteRow, char* text[])
{
    int rowTypes[rowCount];
    int i;
    char cursorBackup;

    for (i = 0; i < rowCount; ++i) {
        rowTypes[i] = 0;
    }

    if ((rowCount < 9) || (absoluteRow < 8)) {
        D_800F4EE8.cursorMemories[2] = absoluteRow;
        D_800F4EE8.cursorMemories[3] = 0;
    } else if (absoluteRow >= (rowCount - 8)) {
        D_800F4EE8.cursorMemories[2] = absoluteRow - (rowCount - 9);
        D_800F4EE8.cursorMemories[3] = rowCount - 9;
    } else {
        D_800F4EE8.cursorMemories[2] = 4;
        D_800F4EE8.cursorMemories[3] = absoluteRow - 4;
    }

    cursorBackup = vs_main_settings.cursorMemory;
    vs_main_settings.cursorMemory = 1;

    vs_mainmenu_setMenuRows(rowCount, menuRowInfo(1, 0, 1), text, rowTypes);

    vs_main_settings.cursorMemory = cursorBackup;
}

/**
 * Hoists the selected row to the top, or clears the menu on cancellation.
 */
int _getSelectedRow(void)
{
    int row = vs_mainmenu_getSelectedRow();

    if (row < -1) {
        vs_mainMenu_clearMenuExcept(5);
    } else if (row >= 0) {
        vs_mainMenu_flyoutMenuRightAndHoistSelection(D_800F4EE8.cursorMemories[2], 1);
    }

    return row;
}

/**
 * Unused, possibly copied from another menu.
 */
void _setMenuRow10(char* text) __attribute__((unused));
void _setMenuRow10(char* text)
{
    vs_battle_menuItem_t* menuItem = vs_battle_setMenuItem(10, 320, 34, 140, 9, text);
    menuItem->state = menuItemTransition_toLeft;
    menuItem->targetPosition0 = 180;
    menuItem->selected = 1;
    menuItem->fontColor = 1;
}

/**
 * Unused, possibly copied from another menu.
 */
void _clearMenuExceptRow8(void) __attribute__((unused));
void _clearMenuExceptRow8(void) { vs_mainMenu_clearMenuExcept(8); }

/**
 * Unused, possibly copied from another menu.
 */
void _menuReady(void) __attribute__((unused));
void _menuReady(void) { vs_mainmenu_ready(); }

int _initData(void);
int _menuInput(void);

/**
 * Module entrypoint.
 *
 * @return 1 if menu is closing, 0 otherwise.
 */
int vs_menu9_exec(u_char* state)
{
    static int initDelay;
    static int _initDataComplete;
    static int _selectedRow;

    enum state {
        init = 3,
        initData,
        waitMenuReady,
    };

    switch (*state) {
    case init:
        func_800FFB68(1);
        initDelay = 8;
        _initDataComplete = 0;
        *state = initData;
        break;

    case initData:
        if (_initDataComplete == 0) {
            _initDataComplete = _initData();
        }

        if (initDelay != 0) {
            --initDelay;
            break;
        }

        if (_initDataComplete == 0) {
            break;
        }

        func_8008A4DC(0);
        func_800CB654(1);

        D_800EB9B0 = 0x200000;
        *state = waitMenuReady;
        // Fallthrough

    case waitMenuReady:
        *state += vs_mainmenu_ready();
        break;

    case 6:
        _selectedRow = _menuInput();

        if (_selectedRow != 0) {

            func_80100414(-4, 0x80);
            func_800CB654(0);

            D_800EB9B0 = 0;

            func_8008A4DC(1);
            vs_mainMenu_setNextMenuAction(menuActionNone);
            vs_mainMenu_clearMenuExcept(vs_mainMenu_menuItemIds_none);

            *state = 7;
        }
        break;

    case 7:
        func_800FFB68(0);
        *state = 8;
        break;

    case 8:
        if (D_801022D8 == 0) {

            if (_selectedRow == 2) {
                vs_battle_menuState.currentState = 9;
            }

            vs_mainMenu_hideMenu = 0;
            *state = 0;

            return 1;
        }
        break;
    }
    return 0;
}

typedef struct {
    char selected;
    char unk1;
    char animationState;
    char disabled;
    short x;
    short rowIndex;
    char* title;
    char* description;
} _gazetteRow;

typedef struct {
    short zudId;
    short unk2;
    short killFlagsOffset;
    short killFlagsCount;
    short selected;
    short animationState;
    u_char unlocked;
    u_char prev;
    u_char next;
    u_char unkF;
    char name[28];
} _monBinData_t;

static void _determineCharacterRank(void);
void _setTitleFlags(void);
void _calculateScore(void);

static int _0 __attribute__((unused));
static _gazetteRow _gazetteRows[32];
static SVECTOR _cameraAngles;
static int _enemyNavigationState;
static int _menuState;
static int _nextState;
static int _cameraDistance;
static int _buttonHeld;

/**
 * Never read.
 */
static u_short _initCameraDistance;

static short _cameraHeightOffset;
static short _selectedEnemy;
static short _enemySkipDelay;
static int _zoomColor;
static int _rotationColor;
static int _hideUi;
static u_long _score;
static u_short _characterRank;
static u_short _clearCount;
static u_short _openedChestCount;
static u_short _mapCompletion;
static vs_main_CdQueueSlot* _monBinCdQueueSlot;
static _monBinData_t* _monBinData;
static u_short* _enemyDescriptions;
static int _1[2] __attribute__((unused));
static VECTOR _cameraPositionBackup;
static VECTOR _cameraAnglesBackup;

int _initData(void)
{
    int i;
    int j;

    if (vs_main_mapStatus.roomFlags[1] & 0x800000) {
        vs_main_mapStatus.roomFlags[1] |= 0x400000;
    }

    _menuState = 0;
    _hideUi = 0;

    if (vs_main_settings.cursorMemory == 0) {
        vs_main_bzero(&vs_battle_menu9CursorMemory, sizeof vs_battle_menu9CursorMemory);
    }

    _mapCompletion = 0;

    for (i = 0; i < 16; ++i) {
        for (j = 0; j < 32; ++j) {
            int v = 1;
            if (vs_main_mapStatus.roomFlags[i] & vs_battle_mapCompletionFlags[i]
                & (v << j)) {
                ++_mapCompletion;
            }
        }
    }

    _openedChestCount = 0;

    for (i = 0; i < 64; ++i) {
        if (vs_main_stateFlags.chestsOpened[i] != 0) {
            ++_openedChestCount;
        }
    }

    _clearCount = vs_main_stateFlags.clearCount;

    if (_mapCompletion > vs_main_scoredata.mapCompletion) {
        vs_main_scoredata.mapCompletion = _mapCompletion;
    }
    if (_openedChestCount > vs_main_scoredata.openedChestCount) {
        vs_main_scoredata.openedChestCount = _openedChestCount;
    }

    vs_main_memcpy(&_cameraPositionBackup, &((camera_t*)getScratchAddr(0))->t2.position,
        sizeof _cameraPositionBackup);
    vs_main_memcpy(&_cameraAnglesBackup, &((camera_t*)getScratchAddr(0))->t2.angles.vx,
        sizeof _cameraAnglesBackup);
    _setTitleFlags();
    _calculateScore();
    _determineCharacterRank();

    return 1;
}

static const vs_main_CdFile _monBinFile = { VS_MON_BIN_LBA, VS_MON_BIN_SIZE };

static const P_CODE _colorStops0[] = { { 0, 65, 107 }, { 25, 130, 108 }, { 64, 48, 102 },
    { 64, 56, 32 } };

static const P_CODE _colorStops1[] = { { 0, 5, 51 }, { 1, 40, 38 }, { 8, 8, 32 },
    { 16, 16, 8 } };

static u_short _menuText[] = {
#include "build/assets/MENU/MENU9.PRG/menuText.vsString"
};
static u_short _rankText[] = {
#include "build/assets/MENU/MENU9.PRG/rankText.vsString"
};
static u_short _titleText[] = {
#include "build/assets/MENU/MENU9.PRG/titleText.vsString"
};
static u_short _titleDescriptions[] = {
#include "build/assets/MENU/MENU9.PRG/titleDescriptions.vsString"
};
static u_short _statHeaders[] = {
#include "build/assets/MENU/MENU9.PRG/statHeaders.vsString"
};
static u_short _statDescriptions[] = {
#include "build/assets/MENU/MENU9.PRG/statDescriptions.vsString"
};
static u_short _timeAttacks[] = {
#include "build/assets/MENU/MENU9.PRG/timeAttacks.vsString"
};
static u_short _timeAttackDescriptions[] = {
#include "build/assets/MENU/MENU9.PRG/timeAttackDescriptions.vsString"
};
static u_short _miscInfo[] = {
#include "build/assets/MENU/MENU9.PRG/miscInfo.vsString"
};

#pragma vsstring(start)
static char _yesString[] = "YES\0";
static char _noString[] = "NO\0";
#pragma vsstring(end)

static char const* _timeAttackReferenceTimes[] = { "$00:25:00", "$00:30:00", "$00:40:00",
    "$00:50:00", "$01:00:00", "$01:15:00", "$01:00:00", "$01:25:00" };

void _restoreCamera(void);
void _setEnemyDescription(void);
int _topMenu(int arg0);
void _renderTopMenu(int arg0);
void _setTitleRows(void);
void _renderTitleMenu(int arg0);
void _initEnemyList(void);
void _renderEnemyMenu(int arg0);
void _renderEnemyDetailScreen(int arg0, int arg1);
void _setStatText(void);
void _renderBossRushDetails(int);
void _printBossRushMenuRow(void);
void _leaveBossRushMenu(void);
void _renderBossRushRecords(int);
void _renderEnemyNavigation(int arg0);

int _menuInput(void)
{
    static int menuAnimState;

    enum state {
        init,
        initData,
        topMenu,
    };

    int _[8] __attribute__((unused));
    vs_battle_textBox* textBox;
    _gazetteRow* var_s0;
    int lStickX;
    int lStickY;
    int selectedRow;

    switch (_menuState) {
    case init:
        func_80100414(0x7FF, 0x80);

        ++_menuState;
        break;

    case initData:
        func_800F9A24(0);
        func_801080C8();

        _cameraDistance = 0x150;
        _cameraHeightOffset = 0x6B;
        _initCameraDistance = D_800F4538[1]->cameraDistance;
        _cameraAngles.vx = 0xF40;
        _cameraAngles.vy = 0xE47;
        _cameraAngles.vz = 0;

        vs_battle_initTextBox(0, 0, 0xB, 0xF8, 0x10, 1, 0xB, 0xF8);
        vs_battle_setTextBox(0, (char*)&_rankText[_rankText[_characterRank]]);
        _topMenu(1);

        menuAnimState = 0;
        ++_menuState;
        break;

    case topMenu:
        _renderTopMenu(menuAnimState);

        if (menuAnimState < 8) {
            textBox = vs_battle_getTextBox(0);
            textBox->y -= 6;
            textBox->yIndent -= 6;
            ++menuAnimState;
        }

        selectedRow = _topMenu(0);

        if (selectedRow == -1) {
            return 0;
        }

        if (selectedRow == -3) {
            _nextState = 2;
        } else if (selectedRow == -2) {
            _nextState = 1;
        } else if (selectedRow == 3) {
            _monBinData = vs_main_allocHeapR(_monBinFile.size);
            _monBinCdQueueSlot = vs_main_allocateCdQueueSlot(&_monBinFile);

            vs_main_cdEnqueue(_monBinCdQueueSlot, _monBinData);

            _nextState = 0;
        } else {
            _nextState = 0;
        }

        D_800F1BF7 = D_800F4EE8.cursorMemories[2] + D_800F4EE8.cursorMemories[3];

        vs_battle_dismissTextBox(0);

        ++_menuState;
        break;

    case 3:
        _renderTopMenu(menuAnimState);

        if (menuAnimState > 0) {

            textBox = vs_battle_getTextBox(0);

            if (textBox != NULL) {
                textBox->y += 6;
                textBox->yIndent += 6;
            }

            --menuAnimState;
            break;
        }

        func_800F9E0C();

        if (_nextState == 0) {
            _menuState = (D_800F1BF7 * 3) + 4;
            break;
        }

        _restoreCamera();

        return _nextState;

    case 4:
        vs_mainMenu_initTextBox();
        _setTitleRows();

        menuAnimState = 0;
        ++_menuState;
        break;

    case 5:
        if ((vs_battle_menu9CursorMemory.titleRow == 0)
            && (vs_battle_menu9CursorMemory.titlePage == 0)
            && (vs_main_buttonsPressed.all & PADLup)) {

            vs_main_playSfxDefault(0x7E, VS_SFX_MENUCHANGE);
            vs_battle_menu9CursorMemory.titlePage = 0x18;
            vs_battle_menu9CursorMemory.titleRow = 7;

        } else if ((vs_battle_menu9CursorMemory.titleRow == 7)
                   && (vs_battle_menu9CursorMemory.titlePage == 24)
                   && (vs_main_buttonsPressed.all & PADLdown)) {

            vs_main_playSfxDefault(0x7E, VS_SFX_MENUCHANGE);
            vs_battle_menu9CursorMemory.titlePage = 0;
            vs_battle_menu9CursorMemory.titleRow = 0;

        } else {
            if (vs_main_buttonRepeat & PADLup) {
                if (vs_battle_menu9CursorMemory.titleRow >= 2) {

                    vs_main_playSfxDefault(0x7E, VS_SFX_MENUCHANGE);
                    --vs_battle_menu9CursorMemory.titleRow;

                } else {
                    if (vs_battle_menu9CursorMemory.titlePage != 0) {

                        --vs_battle_menu9CursorMemory.titlePage;
                        vs_main_playSfxDefault(0x7E, VS_SFX_MENUCHANGE);

                    } else if (vs_battle_menu9CursorMemory.titleRow != 0) {

                        --vs_battle_menu9CursorMemory.titleRow;
                        vs_main_playSfxDefault(0x7E, VS_SFX_MENUCHANGE);
                    }
                }
            } else if (vs_main_buttonRepeat & PADLdown) {
                if (vs_battle_menu9CursorMemory.titleRow >= 6U) {

                    if (vs_battle_menu9CursorMemory.titlePage < 0x18U) {

                        ++vs_battle_menu9CursorMemory.titlePage;
                        vs_main_playSfxDefault(0x7E, VS_SFX_MENUCHANGE);

                    } else {
                        if (vs_battle_menu9CursorMemory.titleRow < 7) {

                            ++vs_battle_menu9CursorMemory.titleRow;
                            vs_main_playSfxDefault(0x7E, VS_SFX_MENUCHANGE);
                        }
                    }

                } else {
                    ++vs_battle_menu9CursorMemory.titleRow;
                    vs_main_playSfxDefault(0x7E, VS_SFX_MENUCHANGE);
                }
            }
        }
        if (vs_main_buttonsPressed.all & (PADRup | PADRdown)) {

            vs_main_playSfxDefault(0x7E, 6);
            vs_mainMenu_dismissTextBox();

            ++_menuState;

            if (vs_main_buttonsPressed.all & PADRup) {
                _nextState = 1;
            } else {
                _nextState = 0;
            }
        }

        _renderTitleMenu(menuAnimState);

        if (menuAnimState < 8) {
            ++menuAnimState;
        }

        break;

    case 6:
        _renderTitleMenu(menuAnimState);

        if (menuAnimState <= 0) {
            if (_nextState == 0) {
                _menuState = 1;
                break;
            }

            _restoreCamera();

            return 2;
        }

        --menuAnimState;
        break;

    case 7:
        vs_mainMenu_initTextBox();
        _setStatText();

        menuAnimState = 0;
        ++_menuState;
        break;

    case 8:
        if ((vs_battle_menu9CursorMemory.recordTimeRow == 0)
            && (vs_battle_menu9CursorMemory.recordTimePage == 0)
            && (vs_main_buttonsPressed.all & PADLup)) {

            vs_main_playSfxDefault(0x7E, 4);

            vs_battle_menu9CursorMemory.recordTimePage = 0xF;
            vs_battle_menu9CursorMemory.recordTimeRow = 7;

        } else if ((vs_battle_menu9CursorMemory.recordTimeRow == 7)
                   && (vs_battle_menu9CursorMemory.recordTimePage == 0xF)
                   && (vs_main_buttonsPressed.all & PADLdown)) {

            vs_main_playSfxDefault(0x7E, 4);

            vs_battle_menu9CursorMemory.recordTimePage = 0;
            vs_battle_menu9CursorMemory.recordTimeRow = 0;

        } else {
            if (vs_main_buttonRepeat & PADLup) {
                if (vs_battle_menu9CursorMemory.recordTimeRow >= 2) {

                    vs_main_playSfxDefault(0x7E, 4);

                    --vs_battle_menu9CursorMemory.recordTimeRow;

                } else {
                    if (vs_battle_menu9CursorMemory.recordTimePage != 0) {

                        --vs_battle_menu9CursorMemory.recordTimePage;

                        vs_main_playSfxDefault(0x7E, 4);

                    } else if (vs_battle_menu9CursorMemory.recordTimeRow != 0) {

                        --vs_battle_menu9CursorMemory.recordTimeRow;

                        vs_main_playSfxDefault(0x7E, 4);
                    }
                }
            } else if (vs_main_buttonRepeat & PADLdown) {
                if (vs_battle_menu9CursorMemory.recordTimeRow >= 6) {
                    if (vs_battle_menu9CursorMemory.recordTimePage < 0xF) {

                        ++vs_battle_menu9CursorMemory.recordTimePage;

                        vs_main_playSfxDefault(0x7E, 4);

                    } else {
                        if (vs_battle_menu9CursorMemory.recordTimeRow < 7) {

                            ++vs_battle_menu9CursorMemory.recordTimeRow;

                            vs_main_playSfxDefault(0x7E, 4);
                        }
                    }
                } else {
                    ++vs_battle_menu9CursorMemory.recordTimeRow;

                    vs_main_playSfxDefault(0x7E, 4);
                }
            }
        }
        if (vs_main_buttonsPressed.all & (PADRup | PADRdown)) {

            vs_main_playSfxDefault(0x7E, 6);
            vs_mainMenu_dismissTextBox();

            ++_menuState;

            if (vs_main_buttonsPressed.all & PADRup) {
                _nextState = 1;
            } else {
                _nextState = 0;
            }
        }

        _renderBossRushDetails(menuAnimState);

        if (menuAnimState < 8) {
            ++menuAnimState;
        }
        break;

    case 9:
        _renderBossRushDetails(menuAnimState);

        if (menuAnimState <= 0) {
            if (_nextState == 0) {
                _menuState = 1;
                break;
            }
            _restoreCamera();
            return 2;
        }

        --menuAnimState;
        break;

    case 10:
        vs_mainMenu_initTextBox();
        _printBossRushMenuRow();

        ++_menuState;
        break;

    case 11:
        if (vs_main_buttonRepeat & PADLup) {

            vs_main_playSfxDefault(0x7E, 4);

            vs_battle_menu9CursorMemory.gazettePage =
                (vs_battle_menu9CursorMemory.gazettePage - 1) & 7;
        } else {
            if (vs_main_buttonRepeat & PADLdown) {

                vs_main_playSfxDefault(0x7E, 4);

                vs_battle_menu9CursorMemory.gazettePage =
                    (vs_battle_menu9CursorMemory.gazettePage + 1) & 7;
            }
        }

        if (vs_main_buttonsPressed.all & (PADRup | PADRdown)) {

            vs_main_playSfxDefault(0x7E, 6);
            vs_mainMenu_dismissTextBox();
            _leaveBossRushMenu();

            ++_menuState;

            if (vs_main_buttonsPressed.all & PADRup) {
                _nextState = 1;
            } else {
                _nextState = 0;
            }
        }

        _renderBossRushRecords(menuAnimState);

        if (menuAnimState < 8) {
            ++menuAnimState;
        }
        break;

    case 12:
        _renderBossRushRecords(menuAnimState);

        if (menuAnimState > 0) {
            --menuAnimState;
            break;
        }

        for (menuAnimState = 0, var_s0 = _gazetteRows; menuAnimState < 8;
             ++menuAnimState, ++var_s0) {
            if (var_s0->animationState == 0) {
                vs_mainMenu_deactivateMenuItem(menuAnimState);
            }
        }

        menuAnimState = 0;

        if (_nextState == 0) {
            _menuState = 1;
            break;
        }

        _restoreCamera();
        return 2;

    case 13:
        if (_monBinCdQueueSlot->state == vs_main_CdQueueStateLoaded) {

            vs_main_freeCdQueueSlot(_monBinCdQueueSlot);

            _enemyDescriptions = (u_short*)(_monBinData + 150);

            vs_mainMenu_initTextBox();
            _initEnemyList();

            menuAnimState = 0;
            ++_menuState;
        }
        break;

    case 14:
        if ((vs_battle_menu9CursorMemory.encyclopaediaRow == 0)
            && (vs_battle_menu9CursorMemory.encyclopaediaPage == 0)
            && (vs_main_buttonsPressed.all & PADLup)) {

            vs_main_playSfxDefault(0x7E, 4);
            vs_battle_menu9CursorMemory.encyclopaediaPage = 0x46;
            vs_battle_menu9CursorMemory.encyclopaediaRow = 7;

        } else if ((vs_battle_menu9CursorMemory.encyclopaediaRow == 7)
                   && (vs_battle_menu9CursorMemory.encyclopaediaPage == 0x46)
                   && (vs_main_buttonsPressed.all & PADLdown)) {

            vs_main_playSfxDefault(0x7E, 4);
            vs_battle_menu9CursorMemory.encyclopaediaPage = 0;
            vs_battle_menu9CursorMemory.encyclopaediaRow = 0;

        } else if (vs_main_buttonRepeat & PADLup) {

            if (vs_battle_menu9CursorMemory.encyclopaediaRow > 1) {
                vs_main_playSfxDefault(0x7E, 4);
                --vs_battle_menu9CursorMemory.encyclopaediaRow;
            } else if (vs_battle_menu9CursorMemory.encyclopaediaPage != 0) {
                --vs_battle_menu9CursorMemory.encyclopaediaPage;
                vs_main_playSfxDefault(0x7E, 4);
            } else if (vs_battle_menu9CursorMemory.encyclopaediaRow != 0) {
                --vs_battle_menu9CursorMemory.encyclopaediaRow;
                vs_main_playSfxDefault(0x7E, 4);
            }

        } else if (vs_main_buttonRepeat & PADLdown) {
            if (vs_battle_menu9CursorMemory.encyclopaediaRow >= 6) {
                if (vs_battle_menu9CursorMemory.encyclopaediaPage < 0x46) {

                    ++vs_battle_menu9CursorMemory.encyclopaediaPage;
                    vs_main_playSfxDefault(0x7E, 4);

                } else {
                    if (vs_battle_menu9CursorMemory.encyclopaediaRow < 7) {

                        ++vs_battle_menu9CursorMemory.encyclopaediaRow;
                        vs_main_playSfxDefault(0x7E, 4);
                    }
                }
            } else {
                ++vs_battle_menu9CursorMemory.encyclopaediaRow;
                vs_main_playSfxDefault(0x7E, 4);
            }
        }
        if (vs_main_buttonsPressed.all & PADRright) {
            if (_monBinData[vs_battle_menu9CursorMemory.encyclopaediaPage
                            + vs_battle_menu9CursorMemory.encyclopaediaRow]
                    .unlocked
                != 0) {

                vs_main_playSfxDefault(0x7E, 5);
                vs_menu9_loadZud(
                    _monBinData[vs_battle_menu9CursorMemory.encyclopaediaPage
                                + vs_battle_menu9CursorMemory.encyclopaediaRow]
                        .zudId);

                ++_menuState;
                _nextState = 2;

            } else {
                vs_main_playSfxDefault(0x7E, 7);
            }

        } else if (vs_main_buttonsPressed.all & (PADRup | PADRdown)) {

            vs_main_playSfxDefault(0x7E, 6);
            vs_mainMenu_dismissTextBox();

            ++_menuState;

            if (vs_main_buttonsPressed.all & PADRup) {
                _nextState = 1;
            } else {
                _nextState = 0;
            }
        }

        _renderEnemyMenu(menuAnimState);

        if (menuAnimState < 8) {
            ++menuAnimState;
        }

        break;

    case 15:
        _renderEnemyMenu(menuAnimState);

        if (menuAnimState <= 0) {

            if (_nextState == 2) {
                _menuState = 19;
                break;
            }

            if (_nextState != 1) {
                vs_main_freeHeapR(_monBinData);
                _menuState = 1;
                break;
            }

            vs_main_freeHeapR(_monBinData);
            _restoreCamera();
            return 2;
        }

        --menuAnimState;
        break;

    case 19:
        if (vs_menu9_loadZud(_monBinData[vs_battle_menu9CursorMemory.encyclopaediaPage
                                         + vs_battle_menu9CursorMemory.encyclopaediaRow]
                                 .zudId)
            == 0) {

            int temp_v1_4 = D_800F4538[1]->cameraDistance;
            _initCameraDistance = temp_v1_4;
            _cameraHeightOffset = D_800F4538[1]->cameraHeightOffset;
            _cameraDistance = (temp_v1_4 << 0x10) >> 0xE;

            if (_cameraDistance < 0x280) {
                _cameraDistance = 0x280;
            } else if (_cameraDistance > 0x1800) {
                _cameraDistance = 0x1800;
            }

            _cameraAngles.vy = 0x100;
            _buttonHeld = 0;
            _cameraAngles.vx = 0;
            _cameraAngles.vz = 0;
            _selectedEnemy = vs_battle_menu9CursorMemory.encyclopaediaPage
                           + vs_battle_menu9CursorMemory.encyclopaediaRow;

            _setEnemyDescription();
            _toggleMenuAction(_hideUi == 0);

            ++_menuState;
        }
        break;

    case 20:
        if (_monBinData[_selectedEnemy].prev != _selectedEnemy) {
            _enemyNavigationState = (_enemyNavigationState + 1) & 0xF;

            _renderEnemyNavigation(0);
            _renderEnemyNavigation(1);
        }

        if (vs_main_buttonsPressed.all & (PADRup | PADRdown)) {

            vs_main_playSfxDefault(0x7E, 6);

            if (_hideUi != 0) {
                _toggleMenuAction(1);
            }

            ++_menuState;

            if (vs_main_buttonsPressed.all & PADRup) {
                vs_mainMenu_dismissTextBox();
                _nextState = 1;
            } else {
                _nextState = 0;
            }
        }

        _rotationColor = vs_getRGB888(128, 128, 128);
        _zoomColor = vs_getRGB888(128, 128, 128);

        if ((lStickX = vs_main_stickPosBuf.lStickX - 0x80, ABS(lStickX) > 0x40)
            || (lStickY = vs_main_stickPosBuf.lStickY - 0x80, ABS(lStickY) > 0x40)) {

            _zoomColor = vs_getRGB888(32, 32, 32);

            if (lStickX < -0x40) {
                _cameraAngles.vy -= 0x40;
            } else if (lStickX > 0x40) {
                _cameraAngles.vy += 0x40;
            }

            if ((vs_main_stickPosBuf.lStickY - 0x80) < -0x40) {
                _cameraAngles.vx += 0x40;
            } else if ((vs_main_stickPosBuf.lStickY - 0x80) > 0x40) {
                _cameraAngles.vx -= 0x40;
            }

            if (_cameraAngles.vx < 0) {
                _cameraAngles.vx = 0;
            }

            if (_cameraAngles.vx > 0x400) {
                _cameraAngles.vx = 0x400;
            }

        } else {
            if (vs_main_buttonsPreviousState & PADL2) {
                int rStickX;
                int rStickY;
                _zoomColor = vs_getRGB888(32, 32, 32);

                if ((rStickX = vs_main_stickPosBuf.rStickX - 0x80, ABS(rStickX) > 0x40)
                    || (rStickY = vs_main_stickPosBuf.rStickY - 0x80,
                        ABS(rStickY) > 0x40)) {

                    if (rStickX < -0x40) {
                        _cameraAngles.vy -= 0x40;
                    } else if (rStickX > 0x40) {
                        _cameraAngles.vy += 0x40;
                    }

                    if ((vs_main_stickPosBuf.rStickY - 0x80) < -0x40) {
                        _cameraAngles.vx += 0x40;
                    } else if ((vs_main_stickPosBuf.rStickY - 0x80) > 0x40) {
                        _cameraAngles.vx -= 0x40;
                    }

                    if (_cameraAngles.vx < 0) {
                        _cameraAngles.vx = 0;
                    }

                    if (_cameraAngles.vx > 0x400) {
                        _cameraAngles.vx = 0x400;
                    }

                } else {
                    if (vs_main_buttonsPreviousState & PADLup) {
                        _cameraAngles.vx += 0x40;
                    } else if (vs_main_buttonsPreviousState & PADLdown) {
                        _cameraAngles.vx -= 0x40;
                    }

                    if (vs_main_buttonsPreviousState & PADLright) {
                        _cameraAngles.vy = _cameraAngles.vy + 0x40;
                    } else if (vs_main_buttonsPreviousState & PADLleft) {
                        _cameraAngles.vy = _cameraAngles.vy - 0x40;
                    }

                    if (_cameraAngles.vx < 0) {
                        _cameraAngles.vx = 0;
                    }

                    if (_cameraAngles.vx > 0x400) {
                        _cameraAngles.vx = 0x400;
                    }
                }

            } else if (vs_main_buttonsPreviousState & PADR2) {
                int rStickX;
                int rStickY;
                _rotationColor = vs_getRGB888(32, 32, 32);

                if ((rStickX = vs_main_stickPosBuf.rStickX - 0x80, ABS(rStickX) > 0x40)
                    || (rStickY = vs_main_stickPosBuf.rStickY - 0x80,
                        ABS(rStickY) > 0x40)) {

                    if ((vs_main_stickPosBuf.rStickY - 0x80) < -0x40) {
                        _cameraDistance -= 4;
                    } else if ((vs_main_stickPosBuf.rStickY - 0x80) > 0x40) {
                        _cameraDistance += 4;
                    }

                } else {
                    if (vs_main_buttonsPreviousState & PADLup) {
                        _cameraDistance -= 0x40;
                    } else if (vs_main_buttonsPreviousState & PADLdown) {
                        _cameraDistance += 0x40;
                    }
                }

                if (_cameraDistance >= 0x280) {
                    if (_cameraDistance > 0x1800) {
                        _cameraDistance = 0x1800;
                    }
                } else {
                    _cameraDistance = 0x280;
                }
            }
        }

        if (vs_main_buttonsPressed.all & PADselect) {
            _toggleMenuAction(_hideUi);
            _hideUi ^= 1;
        }

        if ((vs_main_buttonsPreviousState & (PADL1 | PADR1)) != (PADL1 | PADR1)) {

            if (vs_main_buttonsPressed.all & (PADL1 | PADR1)) {
                _enemySkipDelay = 0;
            }

            if (vs_main_buttonRepeat & PADR1) {
                if (_enemySkipDelay == 0) {
                    if (_monBinData[_selectedEnemy].next != _selectedEnemy) {

                        vs_main_playSfxDefault(0x7E, 11);

                        _selectedEnemy = _monBinData[_selectedEnemy].next;
                        _buttonHeld = PADR1;

                        _setEnemyDescription();
                    }
                }
                _enemySkipDelay = (_enemySkipDelay + 1) & 3;
            }

            if (vs_main_buttonRepeat & PADL1) {
                if (_enemySkipDelay == 0) {
                    if (_monBinData[_selectedEnemy].prev != _selectedEnemy) {

                        vs_main_playSfxDefault(0x7E, 11);

                        _selectedEnemy = _monBinData[_selectedEnemy].prev;
                        _buttonHeld = PADL1;

                        _setEnemyDescription();
                    }
                }

                _enemySkipDelay = (_enemySkipDelay + 1) & 3;
            }
        }

        _renderEnemyDetailScreen(menuAnimState, 0);

        if (menuAnimState < 8) {
            textBox = vs_battle_getTextBox(0);
            textBox->x -= 0x10;
            textBox->xIndent -= 0x10;
            ++menuAnimState;
        }

        if (vs_main_buttonsReleased & _buttonHeld) {

            if (_buttonHeld == PADR1) {
                _buttonHeld = 1;
            } else {
                _buttonHeld = 2;
            }

            _rotationColor = vs_getRGB888(32, 32, 32);
            _zoomColor = vs_getRGB888(32, 32, 32);
            _menuState = 0x19;
        }
        break;

    case 21:
        _rotationColor = vs_getRGB888(32, 32, 32);
        _zoomColor = vs_getRGB888(32, 32, 32);

        _renderEnemyDetailScreen(menuAnimState, 0);

        if (menuAnimState > 0) {

            textBox = vs_battle_getTextBox(0);

            if (textBox != NULL) {
                textBox->x += 0x10;
                textBox->xIndent += 0x10;
            }
            --menuAnimState;
            break;
        }

        vs_menu9_freeZud();

        if (_nextState != 0) {
            vs_main_freeHeapR(_monBinData);
            _restoreCamera();
            return 2;
        }

        _selectedEnemy = vs_battle_menu9CursorMemory.encyclopaediaPage
                       + vs_battle_menu9CursorMemory.encyclopaediaRow;

        vs_mainmenu_setInformationMessage(
            (char*)&_enemyDescriptions[_enemyDescriptions[_selectedEnemy]]);

        _menuState = 0xE;
        break;

    case 25:
        _renderEnemyNavigation(2);
        _renderEnemyNavigation(3);
        _renderEnemyDetailScreen(menuAnimState, _buttonHeld);

        if (menuAnimState > 0) {
            --menuAnimState;
            break;
        }

        vs_menu9_freeZud();
        vs_menu9_loadZud(_monBinData[_selectedEnemy].zudId);

        ++_menuState;
        break;

    case 26:
        _renderEnemyNavigation(2);
        _renderEnemyNavigation(3);
        _renderEnemyDetailScreen(menuAnimState, 3);

        if (vs_menu9_loadZud(_monBinData[vs_battle_menu9CursorMemory.encyclopaediaPage
                                         + vs_battle_menu9CursorMemory.encyclopaediaRow]
                                 .zudId)
            == 0) {

            int temp_v1_10 = D_800F4538[1]->cameraDistance;
            _initCameraDistance = temp_v1_10;
            _cameraHeightOffset = D_800F4538[1]->cameraHeightOffset;
            _cameraDistance = (temp_v1_10 << 0x10) >> 0xE;

            if (_cameraDistance < 0x280) {
                _cameraDistance = 0x280;
            } else if (_cameraDistance >= 0x1801) {
                _cameraDistance = 0x1800;
            }
            ++_menuState;
        }
        break;

    case 27:
        _renderEnemyNavigation(2);
        _renderEnemyNavigation(3);
        _renderEnemyDetailScreen(menuAnimState, 3 - _buttonHeld);

        if (menuAnimState < 8) {
            ++menuAnimState;
        } else {
            _buttonHeld = 0;
            _menuState = 0x14;
        }

        break;
    }

    return 0;
}

/**
 * Resets the camera back to the stored view.
 */
void _restoreCamera(void)
{
    vs_main_memcpy(&((camera_t*)getScratchAddr(0))->t2.position, &_cameraPositionBackup,
        sizeof _cameraPositionBackup);
    vs_main_memcpy(&((camera_t*)getScratchAddr(0))->t2.angles.vx, &_cameraAnglesBackup,
        sizeof _cameraAnglesBackup);
}

/**
 * Set's the current enemy description or a generic message if the enemy
 * hasn't been defeated.
 */
void _setEnemyDescription(void)
{
    if (_monBinData[_selectedEnemy].unlocked != 0) {
        vs_mainmenu_setInformationMessage(
            (char*)&_enemyDescriptions[_enemyDescriptions[_selectedEnemy]]);
    } else {
        vs_mainmenu_setInformationMessage(
            (char*)&_miscInfo[_miscInfo[VS_miscInfo_INDEX_enemyNotDefeated]]);
    }
}

/**
 * Handles input for the top level menu.
 *
 * @return -1 if initializing or user exits, selected row otherwise.
 */
int _topMenu(int initialize)
{
    static int state;
    static int selectedRow;

    char* menuText[8];
    int i;

    if (initialize != 0) {
        state = 0;
        selectedRow = 0;
    }

    switch (state) {
    case 0:
        for (i = 0; i < 4; ++i) {
            menuText[i * 2] = (char*)&_menuText[_menuText[i]];
            menuText[i * 2 + 1] = NULL;
        }

        _setRows(4, D_800F1BF7, menuText);

        ++state;
        break;

    case 1:
        selectedRow = _getSelectedRow();

        if (selectedRow == -1) {
            break;
        }

        return selectedRow;
    }

    return -1;
}

void _buildYawMatrix(MATRIX* arg0, short arg1);
void _buildPitchMatrix(MATRIX* arg0, short arg1);

/**
 * Updates the camera with the adjusted parameters.
 */
void _buildCameraMatrix(MATRIX* cameraMatrix)
{
    SVECTOR negPosition;
    SVECTOR position;
    MATRIX pitchMatrix;
    int angle0;
    int angle1;
    int angle2;
    camera_t* camera;

    angle0 = (angle1 = rsin(_cameraAngles.vy));
    angle1 = rcos(_cameraAngles.vx);
    position.vx = (((angle0 * _cameraDistance) / ONE) * angle1) / ONE;

    angle0 = rcos(_cameraAngles.vy);
    angle1 = rcos(_cameraAngles.vx);
    position.vz = (((angle0 * -_cameraDistance) / ONE) * angle1) / ONE;

    angle2 = rsin(_cameraAngles.vx) * -_cameraDistance;
    position.vy = (angle2 / ONE) - (_cameraHeightOffset / 2);

    camera = (camera_t*)getScratchAddr(0);
    setVector(
        &camera->t2.position, position.vx * ONE, position.vy * ONE, position.vz * ONE);
    camera->t2.angles.vx = _cameraAngles.vx;
    camera->t2.angles.vy = _cameraAngles.vy;
    camera->t2.angles.vz = _cameraAngles.vz;

    _buildYawMatrix(cameraMatrix, _cameraAngles.vy);
    _buildPitchMatrix(&pitchMatrix, _cameraAngles.vx);
    func_80041C68(&pitchMatrix, cameraMatrix);

    applyVector(&negPosition, position.vx, position.vy, position.vz, = -);

    ApplyMatrix(cameraMatrix, &negPosition, (VECTOR*)&cameraMatrix->t);
}

/**
 * Updates camera yaw angle.
 */
void _buildYawMatrix(MATRIX* cameraMatrix, short angle)
{
    int sine = rsin(-angle);
    int cosine = rcos(-angle);

    cameraMatrix->m[0][0] = cosine;
    cameraMatrix->m[0][1] = 0;
    cameraMatrix->m[0][2] = -sine;
    cameraMatrix->m[1][0] = 0;
    cameraMatrix->m[1][1] = ONE;
    cameraMatrix->m[1][2] = 0;
    cameraMatrix->m[2][0] = sine;
    cameraMatrix->m[2][1] = 0;
    cameraMatrix->m[2][2] = cosine;
}

/**
 * Updates camera pitch angle.
 */
void _buildPitchMatrix(MATRIX* pitchMatrix, short angle)
{
    int sine = rsin(angle);
    int cosine = rcos(angle);

    pitchMatrix->m[0][0] = ONE;
    pitchMatrix->m[0][1] = 0;
    pitchMatrix->m[0][2] = 0;
    pitchMatrix->m[1][0] = 0;
    pitchMatrix->m[1][1] = cosine;
    pitchMatrix->m[1][2] = -sine;
    pitchMatrix->m[2][0] = 0;
    pitchMatrix->m[2][1] = sine;
    pitchMatrix->m[2][2] = cosine;
}

/**
 * The trapezeoid behind the "Rotation" and "Zoom" commands.
 */
void _renderCommandsBg(int x, int y, int w, int h, int color)
{
    int i;
    int var_s7;
    LINE_G2* line;
    POLY_F4* poly;

    void** scratch = (void**)getScratchAddr(0);

    line = scratch[0];

    for (i = y, var_s7 = w; i < ((y + h) - 1); ++i, --var_s7) {
        setLineG2(line);
        setXY2(line, x, i, (x + var_s7) - 1, i);
        setRGB0(
            line, _colorStops0[color].r0, _colorStops0[color].g0, _colorStops0[color].b0);
        setRGB1(
            line, _colorStops1[color].r0, _colorStops1[color].g0, _colorStops1[color].b0);

        AddPrim(*((void**)getScratchAddr(1)) + 0x1C, line++);
    }

    x += 2;
    y += 2;
    poly = (POLY_F4*)line;

    setPolyF4(poly);
    setXY4(poly, x, y, (x + w) - 1, y, x, (y + h) - 1, (x + w) - h, (y + h) - 1);
    setRGB0(poly, 0, 0, 0);

    scratch = (void**)getScratchAddr(0);

    AddPrim(scratch[1] + 0x1C, poly++);

    scratch[0] = (void*)poly;

    _insertTPage(7, getTPage(0, 3, 0, 0));
}

/**
 * The quads behind "Score" and "Risk Breaker Rank".
 */
void _renderGradientQuad(int x, int y, int w, int h, int color)
{
    char b1;
    char g0;
    char r1;
    char g1;
    char r0;
    char b0;
    POLY_G4* polyG4;
    POLY_F4* polyF4;
    void** scratch = (void**)0x1F800000;

    int a3 = (x + w) - 1;
    int a2 = (y + h) - 1;

    polyG4 = scratch[0];
    setPolyG4(polyG4);
    r0 = _colorStops0[color].r0;
    g0 = _colorStops0[color].g0;
    b0 = _colorStops0[color].b0;
    r1 = _colorStops1[color].r0;
    g1 = _colorStops1[color].g0;
    b1 = _colorStops1[color].b0;

    setXY4(polyG4, x, y, a3, y, x, a2, a3, a2);
    setRGB0(polyG4, r0, g0, b0);
    setRGB1(polyG4, r1, g1, b1);
    setRGB2(polyG4, r0, g0, b0);
    setRGB3(polyG4, r1, g1, b1);

    AddPrim(scratch[1] + 0x1C, polyG4++);

    x += 2;
    y += 2;

    polyF4 = (POLY_F4*)polyG4;
    setPolyF4(polyF4);
    setXY4(polyF4, x, y, (x + w) - 1, y, x, (y + h) - 1, (x + w) - 1, (y + h) - 1);
    setRGB0(polyF4, 0, 0, 0);

    AddPrim(scratch[1] + 0x1C, polyF4++);

    scratch[0] = polyF4;

    _insertTPage(7, getTPage(0, 3, 0, 0));
}

/**
 * The black footer background on the top menu
 * (replaced by an info box on other screens).
 */
void _renderFooterBg(int x)
{
    POLY_F4* polyF4;
    void** scratch = (void**)getScratchAddr(0);
    POLY_G4* polyG4 = scratch[0];

    setPolyG4(polyG4);
    setXY4(polyG4, 0, x, 320, x, 0, x + 8, 320, x + 8);
    setRGB0(polyG4, 0, 0, 0);
    setRGB1(polyG4, 0, 0, 0);
    setRGB2(polyG4, 128, 128, 128);
    setRGB3(polyG4, 128, 128, 128);
    setSemiTrans(polyG4, 1);

    AddPrim(scratch[1] + 0x1C, polyG4++);

    polyF4 = (POLY_F4*)polyG4;

    setPolyF4(polyF4);
    setXY4(polyF4, 0, x + 8, 320, x + 8, 0, 240, 320, 240);
    setRGB0(polyF4, 0, 0, 0);

    AddPrim(scratch[1] + 0x1C, polyF4++);

    scratch[0] = polyF4;

    _insertTPage(7, getTPage(0, 2, 0, 0));
}

void _renderScreenEdgeFade(void);

/**
 * Bundles camera update and non-menu UI elements.
 */
void _renderTopMenu(int animStep)
{
    vs_battle_geomOffset sp18;
    vs_battle_geomOffset sp20;
    char sp28[128];
    MATRIX spA8;
    void** scratch;

    if (animStep < 8) {
        _renderScreenEdgeFade();
    }

    vs_battle_getGeomOffset(&sp18);

    sp20.x = 0x80 - ((8 - animStep) << 5);
    sp20.y = 0xF0;

    vs_battle_setGeomOffset(&sp20);
    _buildCameraMatrix(&spA8);
    func_800F9EB8(&spA8);
    vs_battle_setGeomOffset(&sp18);

    sprintf(sp28, "#%ld", _score);

    scratch = (void**)getScratchAddr(0);

    vs_battle_renderTextRawColor("SCORE", (((animStep * 16) - 120) & 0xFFFF) | (16 << 16),
        vs_getRGB888(128, 128, 128), scratch[1] + 0x1C);
    vs_battle_renderTextRawColor(sp28, ((animStep * 16) & 0xFFFF) | (16 << 16),
        vs_getRGB888(128, 128, 128), scratch[1] + 0x1C);

    _renderGradientQuad((animStep * 16) - 128, 16, 136, 12, 2);
    vs_battle_renderTextRawColor("RISK   BREAKER   RANK",
        (((animStep * 16) - 120) & 0xFFFF) | (184 << 16), vs_getRGB888(128, 128, 128),
        scratch[1] + 0x1C);

    _renderGradientQuad((animStep * 16) - 128, 184, 136, 12, 1);
    _renderFooterBg(236 - (animStep * 6));
}

/**
 * Configures the text and row status for the titles submenu.
 */
void _setTitleRows(void)
{
    int i;
    _gazetteRow* row;
    int new_var;

    for (i = 0, row = _gazetteRows; i < 32; ++i, ++row) {

        row->x = 60;
        row->rowIndex = i + 1;
        row->selected = 0;
        row->animationState = 0;
        row->disabled = 0;

        if (vs_main_scoredata.titles & ((new_var = 1) << i)) {
            row->unk1 = 1;
            row->title = (char*)&_titleText[_titleText[i]];
            row->description = (char*)&_titleDescriptions[_titleDescriptions[i]];
        } else {
            row->unk1 = 0;
            row->title = (char*)&_miscInfo[_miscInfo[VS_miscInfo_INDEX_noneClear]];
            row->description =
                (char*)&_miscInfo[_miscInfo[VS_miscInfo_INDEX_conditionsNotMet]];
        }
    }
}

/**
 * Renders a title index.
 *
 * @param dimmed Renders the digit with a lower brightness.
 * De facto reserved for the first title when the window doesn't
 * start at index 01.
 */
void _renderTitleNo(int arg0, int arg1, int enemyNo, int arg3);

/**
 * Manages the title selection menu and its animation.
 *
 * @param animState Value from 0-8, incremented or decremented linearly.
 */
void _renderTitleMenu(int animState)
{
    static char cursorAnimState = 0;

    int i;
    vs_battle_menuItem_t* menuItem;

    _gazetteRow* row = _gazetteRows;
    int selectedRow =
        vs_battle_menu9CursorMemory.titlePage + vs_battle_menu9CursorMemory.titleRow;

    for (i = 0; i < 32; ++i, ++row) {
        if (i == selectedRow) {
            if (row->selected == 0) {
                vs_mainmenu_setInformationMessage(row->description);
            }
            row->selected = 1;
            if (row->unk1 != 0) {
                row->animationState = 8;
            }
        } else {
            row->selected = 0;
            if (row->animationState != 0) {
                --row->animationState;
            }
        }
    }

    row = &_gazetteRows[vs_battle_menu9CursorMemory.titlePage];

    for (i = 0; i < 8; ++i, ++row) {

        int y = (animState * 23) - 16;

        if ((56 + i * 16) < y) {
            y = (56 + i * 16);
        }

        if (row->selected != 0) {
            if (animState == 8) {
                cursorAnimState = vs_mainMenu_renderCursor(
                    cursorAnimState, vs_getXY_2(row->x - 12, y - 8));
            }
        }

        menuItem = vs_battle_setMenuItem(0, row->x, y, 200, 0, row->title);

        if (row->unk1 == 0) {
            menuItem->fontColor = 3;
        }
        menuItem->animationState = row->animationState;

        if ((i == 0) && (vs_battle_menu9CursorMemory.titlePage != 0)) {
            menuItem->fadeEffect = menuItem_fadeEffect_fadeTop;
        }

        if ((i == 7) && (vs_battle_menu9CursorMemory.titlePage != 24)) {
            menuItem->fadeEffect = menuItem_fadeEffect_fadeBottom;
        }

        _renderTitleNo(row->x - 14, y, row->rowIndex, menuItem->fadeEffect & 1);

        if ((menuItem->fadeEffect != menuItem_fadeEffect_none) && (animState == 8)) {
            _renderFadedMenuItem(menuItem);
        } else {
            vs_battle_renderMenuItem(menuItem);
        }
    }

    vs_battle_getMenuItem(0)->state = 0;
}

void _renderTitleNo(int x, int y, int titleNo, int dimmed)
{
    char digits[2];
    int i;
    POLY_FT4* poly;

    sprintf(digits, "%02d", titleNo);

    x += 19;
    poly = *(void**)0x1F800000;

    for (i = 1; i >= 0; --i, x -= 5) {

        setPolyFT4(poly);
        setXY4(poly, x, y - 4, x + 6, y - 4, x, y + 6, x + 6, y + 6);
        setcode(poly, (getcode(poly) | 0x02) & 0xFE);

        setUV4(poly, (digits[i] - 48) * 6, 0, ((digits[i] - 48) * 6) + 6, 0,
            (digits[i] - 48) * 6, 10, ((digits[i] - 48) * 6) + 6, 10);

        if (dimmed != 0) {
            setTPage(poly, 0, 1, 768, 0);
            setRGB0(poly, 32, 32, 32);
            setClut(poly, 880, 223);
        } else {
            setTPage(poly, 0, 0, 768, 0);
            setRGB0(poly, 128, 128, 128);
            setClut(poly, 832, 223);
        }

        AddPrim(*(void**)0x1F800008, poly++);
    }

    *(void**)0x1F800000 = poly;
}

/**
 * Renders the enemy index.
 *
 * @param dimmed Renders the digit with a lower brightness.
 * De facto reserved for the first enemy when the window doesn't
 * start at index 01.
 */
void _renderEnemyNo(int x, int y, int enemyNo, int dimmed)
{
    char digits[2];
    int i;
    POLY_FT4* poly;

    sprintf(digits, "%03d", enemyNo);

    x += 0x18;
    poly = *(void**)getScratchAddr(0);

    for (i = 2; i >= 0; --i, x -= 5) {

        setPolyFT4(poly);
        setXY4(poly, x, y - 4, x + 6, y - 4, x, y + 6, x + 6, y + 6);
        setcode(poly, (getcode(poly) | 0x02) & 0xFE);
        setUV4(poly, (digits[i] - 48) * 6, 0, ((digits[i] - 48) * 6) + 6, 0,
            (digits[i] - 48) * 6, 10, ((digits[i] - 48) * 6) + 6, 10);

        if (dimmed != 0) {
            setTPage(poly, 0, 1, 768, 0);
            setRGB0(poly, 32, 32, 32);
            setClut(poly, 880, 223);
        } else {
            setTPage(poly, 0, 0, 768, 0);
            setRGB0(poly, 128, 128, 128);
            setClut(poly, 832, 223);
        }

        AddPrim(*(void**)getScratchAddr(2), poly++);
    }

    *(void**)getScratchAddr(0) = poly;
}

/**
 * Determines unlocked enemies and updates the two-way list.
 */
void _initEnemyList(void)
{
    int i;
    char index;
    _monBinData_t* enemy;

    for (i = 0, enemy = _monBinData; i < 78; ++i, ++enemy) {
        int j;
        enemy->unlocked = 0;

        for (j = enemy->killFlagsOffset;
             j < (enemy->killFlagsOffset + enemy->killFlagsCount); ++j) {

            int flag = vs_main_scoredata.enemyKillFlags[j / 32] & (1 << (j % 32));

            if (flag) {
                enemy->unlocked = 1;
                break;
            }
        }
    }

    for (i = 0, enemy = _monBinData, index = -1; i < 78; ++i, ++enemy) {
        if (enemy->unlocked != 0) {
            enemy->prev = index;
            index = i;
        }
    }

    for (i = 0, enemy = _monBinData; i < 78; ++i, ++enemy) {
        if (enemy->unlocked != 0) {
            enemy->prev = index;
            break;
        }
    }

    for (i = 77, enemy = &_monBinData[77], index = -1; i >= 0; --i, --enemy) {
        if (enemy->unlocked != 0) {
            enemy->next = index;
            index = i;
        }
    }

    for (i = 77, enemy = &_monBinData[77]; i >= 0; --i, --enemy) {
        if (enemy->unlocked != 0) {
            enemy->next = index;
            break;
        }
    }
}

/**
 * Manages the enemy selection menu and its animation.
 *
 * @param animState Value from 0-8, incremented or decremented linearly.
 */
void _renderEnemyMenu(int animState)
{
    static char D_80109899 = 0;

    int i;
    int sp18;
    int selectedRow = vs_battle_menu9CursorMemory.encyclopaediaPage
                    + vs_battle_menu9CursorMemory.encyclopaediaRow;
    _monBinData_t* enemy = _monBinData;

    for (i = 0; i < 78; ++i) {

        if (i == selectedRow) {

            if (enemy->selected == 0) {
                if (enemy->unlocked != 0) {
                    vs_mainmenu_setInformationMessage(
                        (char*)&_enemyDescriptions[_enemyDescriptions[i]]);
                } else {
                    vs_mainmenu_setInformationMessage(
                        (char*)&_miscInfo[_miscInfo[VS_miscInfo_INDEX_enemyNotDefeated]]);
                }
            }

            enemy->selected = 1;

            if (enemy->unlocked != 0) {
                enemy->animationState = 8;
            }
        } else {

            enemy->selected = 0;

            if (enemy->animationState > 0) {
                --enemy->animationState;
            }
        }

        ++enemy;
    }

    i = 0;
    sp18 = animState * 23;
    enemy = &_monBinData[vs_battle_menu9CursorMemory.encyclopaediaPage];

    for (; i < 8; ++i, ++enemy) {
        int x;
        vs_battle_menuItem_t* menuItem;

        vs_battle_menu9CursorMemory_t* cursorMem = &vs_battle_menu9CursorMemory;
        int y = sp18 - 16;

        if ((56 + i * 16) < y) {
            y = 56 + i * 16;
        }

        x = 60;

        if ((enemy->selected != 0) && (animState == 8)) {
            D_80109899 = vs_mainMenu_renderCursor(D_80109899, ((y - 8) << 0x10) | 48);
        }

        if (enemy->unlocked != 0) {
            menuItem = vs_battle_setMenuItem(0, x, y, 200, 0, enemy->name);
        } else {
            menuItem = vs_battle_setMenuItem(0, x, y, 0xC8, 0,
                (char*)&_miscInfo[_miscInfo[VS_miscInfo_INDEX_enemyNameNone]]);
            menuItem->fontColor = 3;
        }

        menuItem->animationState = enemy->animationState;

        if ((i == 0) && (cursorMem->encyclopaediaPage != 0)) {
            menuItem->fadeEffect = menuItem_fadeEffect_fadeTop;
        }

        if ((i == 7) && (cursorMem->encyclopaediaPage != 70)) {
            menuItem->fadeEffect = menuItem_fadeEffect_fadeBottom;
        }

        _renderEnemyNo(
            x - 14, y, cursorMem->encyclopaediaPage + i + 1, menuItem->fadeEffect & 1);

        if ((menuItem->fadeEffect != 0) && (animState == 8)) {
            _renderFadedMenuItem(menuItem);
        } else {
            vs_battle_renderMenuItem(menuItem);
        }
    }

    vs_battle_getMenuItem(0)->state = 0;
}

/**
 * @brief Sets the camera and enemy details.
 */
void _renderEnemyDetailScreen(int animState, int state)
{
    char const* enemyClassName[] = { "HUMAN", "BEAST", "UNDEAD", "PHANTOM", "DRAGON",
        "EVIL" };
    MATRIX sp30;
    vs_battle_geomOffset sp50;
    vs_battle_geomOffset sp58;
    char sp60[12];
    int temp_s0;
    int temp_s2;
    int temp_s4;
    int temp_s6;
    void** scratch;

    if (animState < 8) {
        _renderScreenEdgeFade();
    }

    if (state != 3) {

        vs_battle_getGeomOffset(&sp50);

        if (state == 2) {
            sp58.x = ((8 - animState) << 5) + 160;
        } else {
            sp58.x = 160 - ((8 - animState) << 5);
        }

        sp58.y = 0x68;

        vs_battle_setGeomOffset(&sp58);
        _buildCameraMatrix(&sp30);
        func_800F9EB8(&sp30);
        vs_battle_setGeomOffset(&sp50);
    }

    if (state > 0) {
        animState = 8;
    }

    if (_hideUi == 0) {
        temp_s2 = (8 - animState) * 16;

        vs_battle_renderMenuItem(vs_battle_setMenuItem(
            0, temp_s2 + 184, 166, 256, 0, &_monBinData[_selectedEnemy].name[2]));
        vs_battle_getMenuItem(0)->state = 0;

        temp_s4 = animState * 16;
        scratch = (void**)getScratchAddr(0);

        vs_mainmenu_drawButton(6, temp_s4 - 120, 15, scratch[1] + 24);

        temp_s0 = (temp_s4 - 100) & 0xFFFF;

        vs_battle_renderTextRawColor(
            "ROTATION", temp_s0 | 0x120000, _rotationColor, scratch[1] + 24);

        temp_s6 = temp_s4 - 112;

        _renderCommandsBg(temp_s6, 18, 96, 12, 3);
        vs_mainmenu_drawButton(7, temp_s4 - 120, 34, scratch[1] + 24);
        vs_battle_renderTextRawColor(
            "ZOOM", temp_s0 | (36 << 16), _zoomColor, scratch[1] + 24);
        _renderCommandsBg(temp_s6, 36, 78, 12, 3);
        sprintf(sp60, "NO.   %03d/%03d", _selectedEnemy + 1, 78);
        vs_battle_renderTextRawColor(
            sp60, ((temp_s4 - 120) & 0xFFFF) | 0xA00000, 0x808080, scratch[1] + 0x1C);
        _renderGradientQuad(temp_s4 - 128, 160, 100, 12, 2);
        vs_battle_renderTextRawColor(enemyClassName[_monBinData[_selectedEnemy].unk2],
            ((temp_s2 + 188) & 0xFFFF) | 0x9B0000, 0x808080, NULL);
        _renderGradientQuad(temp_s2 + 180, 155, 140, 26, 1);
    }
}

/**
 * Draws a semitransparent gradient on the left and right edges of the screen.
 */
void _renderScreenEdgeFade(void)
{
    void** scratch = (void**)0x1F800000;
    POLY_G4* poly = scratch[0];

    setPolyG4(poly);
    setXY4(poly, 0, 0, 64, 0, 0, 240, 64, 240);
    setRGB0(poly, 128, 128, 128);
    setRGB1(poly, 0, 0, 0);
    setRGB2(poly, 128, 128, 128);
    setRGB3(poly, 0, 0, 0);
    setSemiTrans(poly, 1);

    AddPrim(scratch[1] + 0x20, poly++);

    setPolyG4(poly);
    setXY4(poly, 256, 0, 320, 0, 256, 240, 320, 240);
    setRGB0(poly, 0, 0, 0);
    setRGB1(poly, 128, 128, 128);
    setRGB2(poly, 0, 0, 0);
    setRGB3(poly, 128, 128, 128);
    setSemiTrans(poly, 1);

    AddPrim(scratch[1] + 32, poly++);

    scratch[0] = poly;

    _insertTPage(8, getTPage(0, 2, 0, 0));
}

void _strcpy(u_char* dest, u_char* src)
{
    while (*src != vs_char_terminator) {
        *dest++ = *src++;
    }

    *dest = *src;
}

void _strcat(char* dest, char* src)
{
    while (*dest != vs_char_terminator) {
        ++dest;
    }

    while (*src != vs_char_terminator) {
        *dest++ = *src++;
    }

    *dest = *src;
}

/**
 * Sets the rows for the Gazette screen.
 */
void _setStatText(void)
{
    int i;
    _gazetteRow* p;

    for (i = 0, p = _gazetteRows; i < 23; ++i, ++p) {
        p->x = 16;
        p->title = (void*)&_statHeaders[_statHeaders[i]];
        p->description = (void*)&_statDescriptions[_statDescriptions[i]];
        p->animationState = 0;
        p->rowIndex = i + 1;
        p->selected = 0;
        p->disabled = 0;
        p->unk1 = 1;
    }
}

// https://decomp.me/scratch/Xo8T1
INCLUDE_ASM("build/src/MENU/MENU9.PRG/nonmatchings/238", _renderBossRushDetails);

/**
 * Prints an integer in VS string encoding.
 */
void _toVsStringInt(char* buf, int value)
{
    int len;
    int i;

    buf++;
    buf--;

    sprintf(buf, "%d", value);
    len = strlen(buf);

    for (i = 0; i < len; ++i) {
        buf[i] -= '0';
    }

    buf += len;
    *buf = vs_char_terminator;
}

/**
 * Same as _toVsStringInt but appends a %.
 */
void _toVsStringPercent(char* buf, int value)
{
    typedef struct {
        char data[4];
    } percent_t;
#pragma vsstring(start)
    static percent_t percent = { "%\0" };
#pragma vsstring(end)

    int len;
    int i;

    buf++;
    buf--;

    sprintf(buf, "%d", value);
    len = strlen(buf);

    for (i = 0; i < len; ++i) {
        buf[i] -= '0';
    }

    buf += len;

    *((percent_t*)buf) = percent;
}

/**
 * Prints the best time, prepended with the game "round".
 */
void _printFastestClearTime(char* buf, int rounds, int totalSeconds)
{
    int len;
    int i;
    int minutes;
    int seconds;
    char* str;

    if (_clearCount == 0) {
        _strcpy(
            (u_char*)buf, (u_char*)&_miscInfo[_miscInfo[VS_miscInfo_INDEX_noneClear]]);
        return;
    }

    minutes = totalSeconds / 60;

    if (minutes >= 100) {
        minutes = 99;
        seconds = 59;
    } else {
        seconds = totalSeconds % 60;
    }

    *buf = vs_char_R;
    str = buf + 1;

    sprintf(str, "%d", rounds + 1);
    len = strlen(str);

    for (i = 0; i < len; ++i) {
        str[i] -= '0';
    }

    str = &str[len];
    *str++ = vs_char_spacing;
    *str++ = 12;

    sprintf(str, "%02d", minutes);
    len = strlen(str);

    for (i = 0; i < len; ++i) {
        str[i] -= '0';
    }

    str = &str[len];
    *str++ = vs_char_colon;

    sprintf(str, "%02d", seconds);
    len = strlen(str);

    for (i = 0; i < len; ++i) {
        str[i] -= '0';
    }

    str += len;
    *str = vs_char_terminator;
}

/**
 * Sets the menu rows for the boss rush screen.
 */
void _printBossRushMenuRow(void)
{
    int i;
    _gazetteRow* row;

    for (i = 0, row = _gazetteRows; i < 8; ++i, ++row) {
        row->x = 194;
        if ((vs_main_scoredata.bossTimeTrialScores[i][0].time) == 0x800000) {
            row->disabled = 1;
            row->title = (char*)&_miscInfo[_miscInfo[VS_miscInfo_INDEX_noneBossRush]];
            row->description =
                (char*)&_miscInfo[_miscInfo[VS_miscInfo_INDEX_noneBossRushDesc]];
        } else {
            row->disabled = 0;
            row->title = (char*)&_timeAttacks[_timeAttacks[i]];
            row->description =
                (char*)&_timeAttackDescriptions[_timeAttackDescriptions[i]];
        }
        row->selected = 0;
        row->animationState = i + 1;
        row->unk1 = 1;
    }
}

/**
 *  Row animation when leaving record time menu.
 */
void _leaveBossRushMenu(void)
{
    int i;
    _gazetteRow* p = _gazetteRows;

    for (i = 0; i < 8; ++i, ++p) {
        if (p->animationState == 0) {
            vs_battle_menuItem_t* menuItem = vs_battle_getMenuItem(i);
            menuItem->state = 2;
            menuItem->targetPosition0 = 320;
        } else {
            p->animationState = -1;
        }
    }
}

/**
 * Renders the boss selection menu and currently selected boss records.
 */
void _renderBossRushRecords(int selected)
{
    static char D_801098A0 = 0;

    char* difficulty[] __attribute__((unused)) = { "EASY", "NORMAL" };
    int difficultyColors[]
        __attribute__((unused)) = { vs_getRGB(0, 128, 128), vs_getRGB(128, 128, 0) };

    char sp28[16];
    int sp38;
    _gazetteRow* sp3C;
    _gazetteRow* var_s1;
    int var_fp;
    int i;
    int j;
    int var_s7;
    int time;
    vs_battle_menuItem_t* menuItem;
    void** p;
    void** r;
    void** q;

    var_s1 = _gazetteRows;
    var_s7 = 0;
    sp38 = vs_battle_menu9CursorMemory.gazettePage;

    for (i = 0; i < 8; ++i, ++var_s1) {
        if (var_s1->animationState != 0) {
            if (!(--var_s1->animationState)) {
                menuItem = vs_battle_setMenuItem(
                    i, 0x140, 0x32 + i * 0x10, 0x88, 0, var_s1->title);
                menuItem->unselectable = var_s1->disabled;
                menuItem->state = 2;
                menuItem->targetPosition0 = 0xC2;
            }
        } else if (vs_battle_getMenuItem(i)->state == 1) {
            ++var_s7;
        }
    }

    var_s1 = _gazetteRows;

    for (i = 0; i < 8; ++var_s1, ++i) {

        if ((var_s7 != 8) || (selected != var_s7)) {
            continue;
        }

        menuItem = vs_battle_getMenuItem(i);

        if (i == sp38) {

            if (var_s1->selected == 0) {
                vs_mainmenu_setInformationMessage(var_s1->description);
            }

            var_s1->selected = 1;
            menuItem->selected = 1;
            var_fp = (((sp38 * 0x10) + 0x2A) << 0x10) | 0xB6;

            D_801098A0 = vs_mainMenu_renderCursor(D_801098A0, var_fp);

            sp3C = var_s1;

        } else {
            var_s1->selected = 0;
            menuItem->selected = 0;
        }
    }

    p = ((void**)0x1F800000);
    vs_battle_renderTextRawColor(
        "PLAYER TIME", vs_getXY((selected * 0x10) - 0x78, 0x20), 0x808080, p[1] + 0x1C);
    _renderGradientQuad((selected * 0x10) - 0x80, 0x20, 0x60, 0xC, 1);
    vs_battle_renderTextRawColor(
        "1ST", vs_getXY((selected * 0x10) - 0x68, 0x32), 0x808080, p[1] + 0x1C);
    vs_battle_renderTextRawColor(
        "2ND", vs_getXY((selected * 0x10) - 0x68, 0x50), 0x808080, p[1] + 0x1C);
    vs_battle_renderTextRawColor(
        "3RD", vs_getXY((selected * 0x10) - 0x68, 0x6E), 0x808080, p[1] + 0x1C);

    for (j = 0; j < 3; ++j) {

        time = vs_main_scoredata.bossTimeTrialScores[sp38][j].time;

        if (time != 0x800000) {
            sprintf(
                sp28, "$%02d:%02d:%02d", time >> 0x10, (time >> 8) & 0xFF, time & 0xFF);
            q = ((void**)0x1F800000);
            vs_battle_renderTextRawColor(sp28,
                vs_getXY_2((selected * 16) - 40, 50 + j * 30), vs_getRGB(128, 128, 128),
                q[1] + 0x1C);
            sprintf(sp28, "ROUND    %d",
                vs_main_scoredata.bossTimeTrialScores[sp38][j].round + 1);
            vs_battle_renderTextRawColor(sp28,
                vs_getXY_2((selected * 16) - 60, 62 + j * 30), vs_getRGB(128, 128, 128),
                q[1] + 0x1C);
        } else {
            q = ((void**)0x1F800000);
            vs_battle_renderTextRawColor("$--:--:--",
                vs_getXY_2((selected * 16) - 40, 50 + j * 30), vs_getRGB(80, 80, 80),
                q[1] + 0x1C);
        }
    }

    _renderGradientQuad((selected * 0x10) - 0x70, 0x32, 0x80, 0x54, 2);
    r = ((void**)0x1F800000);
    vs_battle_renderTextRawColor("REFERENCE TIME", vs_getXY(selected * 16 - 0x78, 0x8C),
        vs_getRGB(128, 128, 128), r[1] + 0x1C);
    _renderGradientQuad((selected * 0x10) - 0x80, 0x8C, 0x70, 0xC, 1);

    if ((var_s7 == 8) && (selected == var_s7)) {
        if (sp3C->disabled != 0) {
            vs_battle_renderTextRawColor(
                "$--:--:--", vs_getXY(88, 158), vs_getRGB(80, 80, 80), r[1] + 0x1C);
        } else {
            vs_battle_renderTextRawColor(_timeAttackReferenceTimes[sp38],
                vs_getXY(88, 158), vs_getRGB(128, 128, 128), r[1] + 0x1C);
        }
    }
    _renderGradientQuad((selected * 0x10) - 0x70, 0x9E, 0x80, 0xC, 2);
}

/**
 * Calculates the rank based on the number of titles unlocked.
 */
void _determineCharacterRank(void)
{
    static short _characterRankTitleThresholds[16] = { 16, 12, 8 };
    static u_int _characterRankPointThresholds[] = { 100000000, 75000000, 60000000,
        40000000, 32000000, 24000000, 16000000, 12000000, 8000000, 5000000, 4000000,
        3000000, 2000000, 1000000, 500000, 0 };

    int i;
    int titleCount;
    int flag;

    for (i = 0, titleCount = 0, flag = 1; i < 16; ++i) {
        if (vs_main_scoredata.titles & (flag << i)) {
            ++titleCount;
        }
    }

    for (i = 0; i < 16; ++i) {
        if ((titleCount >= _characterRankTitleThresholds[i])
            && (_score >= _characterRankPointThresholds[i])) {
            _characterRank = i;
            return;
        }
    }
}

/**
 * Checks game conditions and updates the unlocked titles
 */
void _setTitleFlags(void)
{
    int i;

    if (_clearCount != 0) {
        vs_main_scoredata.titles |= 1;
    }

    if (vs_main_scoredata.openedChestCount >= 52) {
        vs_main_scoredata.titles |= 1 << 2;
    }

    if (vs_main_scoredata.mapCompletion > 360) {
        vs_main_scoredata.titles |= 1 << 3;
    }

    if (vs_main_stateFlags.damascusGolemDefeated != 0) {
        vs_main_scoredata.titles |= 1 << 4;
    }

    if (vs_main_stateFlags.damascusCrabDefeated != 0) {
        vs_main_scoredata.titles |= 1 << 5;
    }

    if (vs_main_stateFlags.ravanaDefeated != 0) {
        vs_main_scoredata.titles |= 1 << 6;
    }

    if (vs_main_stateFlags.dragonZombieDefeated != 0) {
        vs_main_scoredata.titles |= 1 << 7;
    }

    if (vs_main_stateFlags.deathAndOgreZombieDefeated != 0) {
        vs_main_scoredata.titles |= 1 << 8;
    }

    if (vs_main_stateFlags.asuraDefeated != 0) {
        vs_main_scoredata.titles |= 1 << 9;
    }

    for (i = 0; i < 8; ++i) {
        if (vs_main_scoredata.bossTimeTrialScores[i][0].time == 0x800000) {
            break;
        }
    }

    if (i == 8) {
        vs_main_scoredata.titles |= 1 << 10;
    }

    if (vs_main_scoredata.maxChain >= 30) {
        vs_main_scoredata.titles |= 1 << 11;
    }

    if (vs_main_stateFlags.goldKeyObtained != 0) {
        vs_main_scoredata.titles |= 1 << 12;
    }

    if (vs_main_stateFlags.chestKeyObtained != 0) {
        vs_main_scoredata.titles |= 1 << 13;
    }

    for (i = 184; i < 224; ++i) {
        if (!vs_main_skills[i].unlocked) {
            break;
        }
    }

    if (i == 224) {
        vs_main_scoredata.titles |= 1 << 14;
    }

    for (i = 22; i < 54; ++i) {
        if (((i != 33) && (i != 36) && (i != 38) && (i != 39)
                && !vs_main_skills[i].unlocked)) {
            break;
        }
    }

    if (i == 54) {
        vs_main_scoredata.titles |= 1 << 15;
    }

    for (i = 0; i < 6; ++i) {
        if (vs_main_scoredata.enemyKills[i] < 5000) {
            break;
        }
    }

    if (i == 6) {
        vs_main_scoredata.titles |= 1 << 20;
    }

    for (i = 0; i < 10; ++i) {
        if (vs_main_scoredata.weaponAttacks[i] < 5000) {
            break;
        }
    }

    if (i == 10) {
        vs_main_scoredata.titles |= 1 << 21;
    }

    for (i = 0; i < 9; ++i) {
        if (vs_main_scoredata.weaponAttacks[i + 1] >= 500) {
            vs_main_scoredata.titles |= 1 << (i + 22);
        }
    }

    if (vs_main_scoredata.weaponAttacks[0] >= 500) {
        vs_main_scoredata.titles |= 1 << 31;
    }
}

/**
 * Renders the L1 / R1 controls.
 *
 * @param direction 0 == left, 1 == right, 2 == left transitioning, 3 == right
 * transitioning
 */
void _renderEnemyNavigation(int direction)
{
    int x;
    int clut;
    POLY_FT4* poly;
    void** scratch;
    int new_var;

    if (_hideUi == 0) {

        clut = getClut(896, 223);

        if (direction >= 2) {
            direction -= 2;
            clut = getClut(912, 223);
        }

        if (direction != 0) {
            vs_battle_renderTextRawColor(
                "#R1", vs_getXY(286, 98), vs_getRGB888(128, 128, 128), NULL);

            if (_enemyNavigationState < 9) {
                x = (_enemyNavigationState >> 1) + 288;
            } else {
                x = -(_enemyNavigationState >> 2) + 294;
            }
        } else {
            vs_battle_renderTextRawColor(
                "L1", vs_getXY(34, 98), vs_getRGB888(128, 128, 128), NULL);

            if (_enemyNavigationState < 9) {
                new_var = 32;
                x = new_var - (_enemyNavigationState >> 1);
            } else {
                x = (_enemyNavigationState >> 2) + 26;
            }
        }

        x -= 8;
        scratch = (void**)getScratchAddr(0);
        poly = scratch[0];

        setPolyFT4(poly);
        setXY4(poly, x, 96, x + 16, 96, x, 112, x + 16, 112);
        setUV4(poly, direction * 16, 48, (direction * 16) + 16, 48, direction * 16, 64,
            (direction * 16) + 16, 64);
        setTPage(poly, 0, 0, 768, 0);
        poly->clut = clut;
        setShadeTex(poly, 1);

        AddPrim(scratch[1], poly++);

        scratch[0] = poly;
    }
}

/**
 * Determines the game score based on kills, attacks, boss rush scores
 * and other criteria.
 *
 */
void _calculateScore(void)
{
    short classPoints[6] = { 20, 20, 40, 80, 100, 60 };
    short weaponClassPoints[10] = { 20, 40, 20, 100, 60, 100, 60, 100, 80, 60 };
    int i;

    _score = 0;

    for (i = 0; i < 6; ++i) {
        _score += vs_main_scoredata.enemyKills[i] * classPoints[i];
    }

    for (i = 0; i < 10; ++i) {
        _score += vs_main_scoredata.weaponAttacks[i] * weaponClassPoints[i];
    }

    for (i = 0; i < 8; ++i) {
        if (vs_main_scoredata.bossTimeTrialScores[i][0].time != 0x800000) {
            _score += 20000;
        }
    }

    if (vs_main_scoredata.maxChain < 6) {
        _score += vs_main_scoredata.maxChain * 10;
    } else if (vs_main_scoredata.maxChain < 11) {
        _score += vs_main_scoredata.maxChain * 20;
    } else if (vs_main_scoredata.maxChain < 16) {
        _score += vs_main_scoredata.maxChain * 40;
    } else if (vs_main_scoredata.maxChain < 21) {
        _score += vs_main_scoredata.maxChain * 80;
    } else if (vs_main_scoredata.maxChain < 26) {
        _score += vs_main_scoredata.maxChain * 160;
    } else if (vs_main_scoredata.maxChain < 31) {
        _score += vs_main_scoredata.maxChain * 320;
    } else if (vs_main_scoredata.maxChain < 51) {
        _score += vs_main_scoredata.maxChain * 640;
    } else {
        _score += vs_main_scoredata.maxChain * 1280;
    }

    _score += _clearCount * 100000;

    if ((_clearCount != 0) && (vs_main_scoredata.completionTimeMinutes < 600)) {
        if (vs_main_scoredata.completionTimeMinutes >= 540) {
            _score += _score / 4;
        } else if (vs_main_scoredata.completionTimeMinutes >= 300) {
            _score += _score / 2;
        } else {
            _score *= 2;
        }
    }

    _score += vs_main_scoredata.streakScore;
    _score += vs_main_scoredata.enemyKillStreak;
    if (_score > 999999999) {
        _score = 999999999;
    }
}
