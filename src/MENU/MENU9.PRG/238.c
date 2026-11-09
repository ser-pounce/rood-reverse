#include "common.h"
#include "238.h"
#include "57BC.h"
#include "src/SLUS_010.40/31724.h"
#include "src/SLUS_010.40/actions.h"
#include "src/SLUS_010.40/cd.h"
#include "src/SLUS_010.40/gameFlags.h"
#include "src/SLUS_010.40/gameState.h"
#include "src/SLUS_010.40/graphics.h"
#include "src/SLUS_010.40/memory.h"
#include "src/SLUS_010.40/pad.h"
#include "src/SLUS_010.40/sfx.h"
#include "src/SLUS_010.40/sound.h"
#include "src/BATTLE/BATTLE.PRG/2EA3C.h"
#include "src/BATTLE/BATTLE.PRG/40564.h"
#include "src/BATTLE/BATTLE.PRG/573B8.h"
#include "src/BATTLE/BATTLE.PRG/battleUi.h"
#include "src/BATTLE/BATTLE.PRG/menuState.h"
#include "src/BATTLE/BATTLE.PRG/mpd.h"
#include "src/MENU/MAINMENU.PRG/224.h"
#include "src/MENU/MAINMENU.PRG/2D10.h"
#include "src/MENU/MAINMENU.PRG/58EC.h"
#include "src/MENU/MAINMENU.PRG/C48.h"
#include "build/assets/MENU/MENU9.PRG/menuText.h"
#include "build/assets/MENU/MENU9.PRG/miscInfo.h"
#include "build/assets/MENU/MENU9.PRG/rankText.h"
#include "build/assets/MENU/MENU9.PRG/statDescriptions.h"
#include "build/assets/MENU/MENU9.PRG/statHeaders.h"
#include "build/assets/MENU/MENU9.PRG/timeAttackDescriptions.h"
#include "build/assets/MENU/MENU9.PRG/timeAttacks.h"
#include "build/assets/MENU/MENU9.PRG/titleDescriptions.h"
#include "build/assets/MENU/MENU9.PRG/titleText.h"
#include "build/src/include/lbas.h"
#include "gpu.h"
#include "insertTPage.h"
#include "scratch.h"
#include "vs_string.h"
#include <libetc.h>
#include <stdio.h>
#include <strings.h>
#include <libgpu.h>
#include <abs.h>

/**
 * Hides or shows the menu action at the very top of the menu.
 */
void toggleMenuAction(int enable)
{
    if (enable != 0) {
        vs_mainMenu_setMenuCommand(menuActionMenu);
        vs_mainMenu_hideMenu = 0;
    } else {
        vs_mainMenu_setMenuCommand(menuActionNone);
        vs_mainMenu_hideMenu = 1;
    }
}

/**
 * Feathers the top or bottom of the item and adds the scroll arrows.
 */
void renderScrollableMenuItem(vs_battle_menuItem_t* menuItem)
{
    static char previousFrameBuf = 0;
    static char navigationAnimState = 0;

    int w;
    int frameBuf;
    int animState;
    int bgWidth;
    int isScrollable;
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
    before = vs_scratch.unk8 + 8;
    w = menuItem->w;
    animState = menuItem->gradientState;
    isScrollable = menuItem->isScrollable - 1;
    bgWidth = menuItem->backgroundWidth;

    if (vs_main_frameBuf != previousFrameBuf) {

        ++navigationAnimState;
        previousFrameBuf = vs_main_frameBuf;

        if (navigationAnimState >= 12) {
            navigationAnimState = 0;
        }
    }

    state = menuItem->state;

    if ((state == 1) && (menuItem->x < 128u)) {

        var_s0 = navigationAnimState >> 2;

        if (isScrollable == 0) {
            var_s0 -= 5;
        } else {
            var_s0 = state - var_s0;
        }

        vs_battle_setSpriteDefaultTexPage(128,
            (menuItem->x - 14) | ((menuItem->y + var_s0) << 0x10), vs_getWH(16, 16),
            before - 1)[4] = (isScrollable << 4) | vs_getUV0Clut(0, 48, 912, 223);
    }

    i = menuItem->x + 6;

    while ((var_s0 = *menuText++) != vs_char_printString) {
        if (var_s0 == vs_char_spacing) {
            i += *menuText++;
        } else {
            i = vs_mainMenu_renderRowLabel(
                var_s0 | (isScrollable << 0x1F), i, menuItem, before);
        }
    }

    if (w == 0) {
        return;
    }

    prim = vs_scratch.unk0;

    for (i = 0, s5 = 0; i < 12; s5 += 8, ++i) {
        if (isScrollable == 0) {
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

    vs_scratch.unk0 = prim;

    if (isScrollable == 0) {
        vs_battle_addTile(before, vs_getRGB0(primTile, 0, 0, 0),
            ((xy + 2) & 0xFFFF) | ((xy >> 0x10) << 0x10), w | vs_getWH(0, 2));
    }

    if (animState != 0) {
        menuItem->gradientState = animState - 1;
    }

    xy += -12 << 16;
    w |= vs_getWH(0, 1);
    var_s0 = (menuItem->x >= 128) << 7;

    for (i = 0; i < 12; ++i) {

        if (isScrollable == 0) {
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
void setRows(int rowCount, int absoluteRow, char* text[])
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
int getSelectedRow(void)
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
UNUSED void setMenuRow10(char* text);
void setMenuRow10(char* text)
{
    vs_battle_menuItem_t* menuItem = vs_battle_setMenuItem(10, 320, 34, 140, 9, text);
    menuItem->state = menuItemStateSlideX;
    menuItem->targetPosition0 = 180;
    menuItem->selected = 1;
    menuItem->fontColor = 1;
}

/**
 * Unused, possibly copied from another menu.
 */
UNUSED void clearMenuExceptRow8(void);
void clearMenuExceptRow8(void) { vs_mainMenu_clearMenuExcept(8); }

/**
 * Unused, possibly copied from another menu.
 */
UNUSED void menuReady(void);
void menuReady(void) { vs_mainmenu_ready(); }

int calculateProgress(void);
int menuInput(void);

int vs_menu9_exec(u_char* state)
{
    static int initDelay;
    static int calculateProgressComplete;
    static int selectedRow;

    enum state {
        init = 3,
        initData,
        waitMenuReady,
    };

    switch (*state) {
    case init:
        vs_mainMenu_toggleBackgroundFade(1);
        initDelay = 8;
        calculateProgressComplete = 0;
        *state = initData;
        break;

    case initData:
        if (calculateProgressComplete == 0) {
            calculateProgressComplete = calculateProgress();
        }

        if (initDelay != 0) {
            --initDelay;
            break;
        }

        if (calculateProgressComplete == 0) {
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
        selectedRow = menuInput();

        if (selectedRow != 0) {

            vs_mainMenu_setBackgroundRenderPriority(-4, 128);
            func_800CB654(0);

            D_800EB9B0 = 0;

            func_8008A4DC(1);
            vs_mainMenu_setMenuCommand(menuActionNone);
            vs_mainMenu_clearMenuExcept(vs_mainMenu_menuItemIds_none);

            *state = 7;
        }
        break;

    case 7:
        vs_mainMenu_toggleBackgroundFade(0);
        *state = 8;
        break;

    case 8:
        if (vs_mainMenu_backgroundFadeStep == 0) {

            if (selectedRow == 2) {
                vs_battle_menuState.currentMenu = 9;
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
} gazetteRow_t;

typedef struct {
    short zudIndex;
    short classId;
    short killFlagsOffset;
    short killFlagsCount;
    short selected;
    short animationState;
    u_char unlocked;
    u_char prev;
    u_char next;
    UNUSED u_char _;
    char name[28];
} monBinData_t;

static void determineCharacterRank(void);
void setTitleFlags(void);
void calculateScore(void);

static UNUSED int _0;
static gazetteRow_t gazetteRows[32];
static SVECTOR cameraAngles;
static int enemyNavigationState;
static int menuState;
static int nextState;
static int cameraDistance;
static int buttonHeld;

/**
 * Never read.
 */
static u_short initCameraDistance;

static short cameraHeightOffset;
static short selectedEnemy;
static short enemySkipDelay;
static int zoomColor;
static int rotationColor;
static int hideUi;
static u_long score;
static u_short characterRank;
static u_short clearCount;
static u_short openedChestCount;
static u_short mapCompletion;
static vs_main_CdQueueSlot* monBinCdQueueSlot;
static monBinData_t* monBinData;
static u_short* enemyDescriptions;
static UNUSED int _1[2];
static VECTOR cameraPositionBackup;
static VECTOR cameraAnglesBackup;

/**
 * Recalculates the base game stats and stores the previous camera state.
 */
int calculateProgress(void)
{
    int i;
    int j;

    if (vs_main_mapStatus.roomFlags[1] & 0x800000) {
        vs_main_mapStatus.roomFlags[1] |= 0x400000;
    }

    menuState = 0;
    hideUi = 0;

    if (vs_main_settings.cursorMemory == 0) {
        vs_main_bzero(&vs_battle_menu9CursorMemory, sizeof vs_battle_menu9CursorMemory);
    }

    mapCompletion = 0;

    for (i = 0; i < 16; ++i) {
        for (j = 0; j < 32; ++j) {
            int v = 1;
            if (vs_main_mapStatus.roomFlags[i] & vs_battle_mapCompletionFlags[i]
                & (v << j)) {
                ++mapCompletion;
            }
        }
    }

    openedChestCount = 0;

    for (i = 0; i < 64; ++i) {
        if (vs_main_stateFlags.chestsOpened[i] != 0) {
            ++openedChestCount;
        }
    }

    clearCount = vs_main_stateFlags.clearCount;

    if (mapCompletion > vs_main_scoredata.mapCompletion) {
        vs_main_scoredata.mapCompletion = mapCompletion;
    }
    if (openedChestCount > vs_main_scoredata.openedChestCount) {
        vs_main_scoredata.openedChestCount = openedChestCount;
    }

    vs_main_memcpy(&cameraPositionBackup,
        &((vs_scratch_t*)getScratchAddr(0))->camera.position,
        sizeof cameraPositionBackup);
    vs_main_memcpy(&cameraAnglesBackup,
        &((vs_scratch_t*)getScratchAddr(0))->camera.angles.vx, sizeof cameraAnglesBackup);
    setTitleFlags();
    calculateScore();
    determineCharacterRank();

    return 1;
}

static const vs_main_CdFile monBinFile = { VS_MON_BIN_LBA, VS_MON_BIN_SIZE };

/**
 * Stops used for the green and purple UI backgrounds
 */
static const CVECTOR bgColorStops0[] = { { 0, 65, 107 }, { 25, 130, 108 },
    { 64, 48, 102 }, { 64, 56, 32 } };

static const CVECTOR bgColorStops1[] = { { 0, 5, 51 }, { 1, 40, 38 }, { 8, 8, 32 },
    { 16, 16, 8 } };

static u_short menuTextTable[] = {
#include "build/assets/MENU/MENU9.PRG/menuText.vsString"
};
static u_short rankText[] = {
#include "build/assets/MENU/MENU9.PRG/rankText.vsString"
};
static u_short titleText[] = {
#include "build/assets/MENU/MENU9.PRG/titleText.vsString"
};
static u_short titleDescriptions[] = {
#include "build/assets/MENU/MENU9.PRG/titleDescriptions.vsString"
};
static u_short statHeaders[] = {
#include "build/assets/MENU/MENU9.PRG/statHeaders.vsString"
};
static u_short statDescriptions[] = {
#include "build/assets/MENU/MENU9.PRG/statDescriptions.vsString"
};
static u_short timeAttacks[] = {
#include "build/assets/MENU/MENU9.PRG/timeAttacks.vsString"
};
static u_short timeAttackDescriptions[] = {
#include "build/assets/MENU/MENU9.PRG/timeAttackDescriptions.vsString"
};
static u_short miscInfo[] = {
#include "build/assets/MENU/MENU9.PRG/miscInfo.vsString"
};

// Probably imported accidentally
#pragma vsstring(start)
static UNUSED char yesString[] = "YES\0";
static UNUSED char noString[] = "NO\0";
#pragma vsstring(end)

/**
 * Default boss rush times to beat.
 */
static char const* timeAttackReferenceTimes[] = { "$00:25:00", "$00:30:00", "$00:40:00",
    "$00:50:00", "$01:00:00", "$01:15:00", "$01:00:00", "$01:25:00" };

void restoreCamera(void);
void setEnemyDescription(void);
int topMenu(int arg0);
void renderTopMenu(int arg0);
void setTitleRows(void);
void renderTitleMenu(int arg0);
void initEnemyList(void);
void renderEnemyMenu(int arg0);
void renderEnemyDetailScreen(int arg0, int arg1);
void setStatText(void);
void renderBossRushDetails(int);
void printBossRushMenuRow(void);
void leaveBossRushMenu(void);
void renderBossRushRecords(int);
void renderEnemyNavigation(int arg0);

/**
 * Manages user input
 *
 * @return 1 == menu selected, 2 == exit, 0 otherwise
 */
int menuInput(void)
{
    static int menuAnimState;

    enum state {
        init,
        initData,
        topMenuState,
    };

    UNUSED int _[8];
    vs_battle_textBox* textBox;
    gazetteRow_t* var_s0;
    int lStickX;
    int lStickY;
    int selectedRow;

    switch (menuState) {
    case init:
        vs_mainMenu_setBackgroundRenderPriority(2047, 128);

        ++menuState;
        break;

    case initData:
        func_800F9A24(0);
        func_801080C8();

        cameraDistance = 0x150;
        cameraHeightOffset = 0x6B;
        initCameraDistance = D_800F4538[1]->menuCameraDistance;
        cameraAngles.vx = 0xF40;
        cameraAngles.vy = 0xE47;
        cameraAngles.vz = 0;

        vs_battle_initTextBox(0, 0, 0xB, 0xF8, 0x10, 1, 0xB, 0xF8);
        vs_battle_setTextBox(0, (char*)&rankText[rankText[characterRank]]);
        topMenu(1);

        menuAnimState = 0;
        ++menuState;
        break;

    case topMenuState:
        renderTopMenu(menuAnimState);

        if (menuAnimState < 8) {
            textBox = vs_battle_getTextBox(0);
            textBox->y -= 6;
            textBox->yIndent -= 6;
            ++menuAnimState;
        }

        selectedRow = topMenu(0);

        if (selectedRow == -1) {
            return 0;
        }

        if (selectedRow == -3) {
            nextState = 2;
        } else if (selectedRow == -2) {
            nextState = 1;
        } else if (selectedRow == 3) {
            monBinData = vs_main_allocHeapR(monBinFile.size);
            monBinCdQueueSlot = vs_main_allocateCdQueueSlot(&monBinFile);

            vs_main_cdEnqueue(monBinCdQueueSlot, monBinData);

            nextState = 0;
        } else {
            nextState = 0;
        }

        vs_battle_menu9CursorMemory.gazetteRow =
            D_800F4EE8.cursorMemories[2] + D_800F4EE8.cursorMemories[3];

        vs_battle_dismissTextBox(0);

        ++menuState;
        break;

    case 3:
        renderTopMenu(menuAnimState);

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

        if (nextState == 0) {
            menuState = (vs_battle_menu9CursorMemory.gazetteRow * 3) + 4;
            break;
        }

        restoreCamera();

        return nextState;

    case 4:
        vs_mainMenu_initInformationBox();
        setTitleRows();

        menuAnimState = 0;
        ++menuState;
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
            vs_mainMenu_dismissInformationBox();

            ++menuState;

            if (vs_main_buttonsPressed.all & PADRup) {
                nextState = 1;
            } else {
                nextState = 0;
            }
        }

        renderTitleMenu(menuAnimState);

        if (menuAnimState < 8) {
            ++menuAnimState;
        }

        break;

    case 6:
        renderTitleMenu(menuAnimState);

        if (menuAnimState <= 0) {
            if (nextState == 0) {
                menuState = 1;
                break;
            }

            restoreCamera();

            return 2;
        }

        --menuAnimState;
        break;

    case 7:
        vs_mainMenu_initInformationBox();
        setStatText();

        menuAnimState = 0;
        ++menuState;
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
            vs_mainMenu_dismissInformationBox();

            ++menuState;

            if (vs_main_buttonsPressed.all & PADRup) {
                nextState = 1;
            } else {
                nextState = 0;
            }
        }

        renderBossRushDetails(menuAnimState);

        if (menuAnimState < 8) {
            ++menuAnimState;
        }
        break;

    case 9:
        renderBossRushDetails(menuAnimState);

        if (menuAnimState <= 0) {
            if (nextState == 0) {
                menuState = 1;
                break;
            }
            restoreCamera();
            return 2;
        }

        --menuAnimState;
        break;

    case 10:
        vs_mainMenu_initInformationBox();
        printBossRushMenuRow();

        ++menuState;
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
            vs_mainMenu_dismissInformationBox();
            leaveBossRushMenu();

            ++menuState;

            if (vs_main_buttonsPressed.all & PADRup) {
                nextState = 1;
            } else {
                nextState = 0;
            }
        }

        renderBossRushRecords(menuAnimState);

        if (menuAnimState < 8) {
            ++menuAnimState;
        }
        break;

    case 12:
        renderBossRushRecords(menuAnimState);

        if (menuAnimState > 0) {
            --menuAnimState;
            break;
        }

        for (menuAnimState = 0, var_s0 = gazetteRows; menuAnimState < 8;
            ++menuAnimState, ++var_s0) {
            if (var_s0->animationState == 0) {
                vs_mainMenu_deactivateMenuItem(menuAnimState);
            }
        }

        menuAnimState = 0;

        if (nextState == 0) {
            menuState = 1;
            break;
        }

        restoreCamera();
        return 2;

    case 13:
        if (monBinCdQueueSlot->state == vs_main_CdQueueStateLoaded) {

            vs_main_freeCdQueueSlot(monBinCdQueueSlot);

            enemyDescriptions = (u_short*)(monBinData + 150);

            vs_mainMenu_initInformationBox();
            initEnemyList();

            menuAnimState = 0;
            ++menuState;
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
            if (monBinData[vs_battle_menu9CursorMemory.encyclopaediaPage
                           + vs_battle_menu9CursorMemory.encyclopaediaRow]
                    .unlocked
                != 0) {

                vs_main_playSfxDefault(0x7E, 5);
                vs_menu9_loadZud(
                    monBinData[vs_battle_menu9CursorMemory.encyclopaediaPage
                               + vs_battle_menu9CursorMemory.encyclopaediaRow]
                        .zudIndex);

                ++menuState;
                nextState = 2;

            } else {
                vs_main_playSfxDefault(0x7E, 7);
            }

        } else if (vs_main_buttonsPressed.all & (PADRup | PADRdown)) {

            vs_main_playSfxDefault(0x7E, 6);
            vs_mainMenu_dismissInformationBox();

            ++menuState;

            if (vs_main_buttonsPressed.all & PADRup) {
                nextState = 1;
            } else {
                nextState = 0;
            }
        }

        renderEnemyMenu(menuAnimState);

        if (menuAnimState < 8) {
            ++menuAnimState;
        }

        break;

    case 15:
        renderEnemyMenu(menuAnimState);

        if (menuAnimState <= 0) {

            if (nextState == 2) {
                menuState = 19;
                break;
            }

            if (nextState != 1) {
                vs_main_freeHeapR(monBinData);
                menuState = 1;
                break;
            }

            vs_main_freeHeapR(monBinData);
            restoreCamera();
            return 2;
        }

        --menuAnimState;
        break;

    case 19:
        if (vs_menu9_loadZud(monBinData[vs_battle_menu9CursorMemory.encyclopaediaPage
                                        + vs_battle_menu9CursorMemory.encyclopaediaRow]
                    .zudIndex)
            == 0) {

            int temp_v1_4 = D_800F4538[1]->menuCameraDistance;
            initCameraDistance = temp_v1_4;
            cameraHeightOffset = D_800F4538[1]->menuCameraHeightOffset;
            cameraDistance = (temp_v1_4 << 0x10) >> 0xE;

            if (cameraDistance < 0x280) {
                cameraDistance = 0x280;
            } else if (cameraDistance > 0x1800) {
                cameraDistance = 0x1800;
            }

            cameraAngles.vy = 0x100;
            buttonHeld = 0;
            cameraAngles.vx = 0;
            cameraAngles.vz = 0;
            selectedEnemy = vs_battle_menu9CursorMemory.encyclopaediaPage
                          + vs_battle_menu9CursorMemory.encyclopaediaRow;

            setEnemyDescription();
            toggleMenuAction(hideUi == 0);

            ++menuState;
        }
        break;

    case 20:
        if (monBinData[selectedEnemy].prev != selectedEnemy) {
            enemyNavigationState = (enemyNavigationState + 1) & 0xF;

            renderEnemyNavigation(0);
            renderEnemyNavigation(1);
        }

        if (vs_main_buttonsPressed.all & (PADRup | PADRdown)) {

            vs_main_playSfxDefault(0x7E, 6);

            if (hideUi != 0) {
                toggleMenuAction(1);
            }

            ++menuState;

            if (vs_main_buttonsPressed.all & PADRup) {
                vs_mainMenu_dismissInformationBox();
                nextState = 1;
            } else {
                nextState = 0;
            }
        }

        rotationColor = vs_getRGB888(128, 128, 128);
        zoomColor = vs_getRGB888(128, 128, 128);

        if ((lStickX = vs_main_stickPosBuf.lStickX - 0x80, ABS(lStickX) > 0x40)
            || (lStickY = vs_main_stickPosBuf.lStickY - 0x80, ABS(lStickY) > 0x40)) {

            zoomColor = vs_getRGB888(32, 32, 32);

            if (lStickX < -0x40) {
                cameraAngles.vy -= 0x40;
            } else if (lStickX > 0x40) {
                cameraAngles.vy += 0x40;
            }

            if ((vs_main_stickPosBuf.lStickY - 0x80) < -0x40) {
                cameraAngles.vx += 0x40;
            } else if ((vs_main_stickPosBuf.lStickY - 0x80) > 0x40) {
                cameraAngles.vx -= 0x40;
            }

            if (cameraAngles.vx < 0) {
                cameraAngles.vx = 0;
            }

            if (cameraAngles.vx > 0x400) {
                cameraAngles.vx = 0x400;
            }

        } else {
            if (vs_main_buttonsPreviousState & PADL2) {
                int rStickX;
                int rStickY;
                zoomColor = vs_getRGB888(32, 32, 32);

                if ((rStickX = vs_main_stickPosBuf.rStickX - 0x80, ABS(rStickX) > 0x40)
                    || (rStickY = vs_main_stickPosBuf.rStickY - 0x80,
                        ABS(rStickY) > 0x40)) {

                    if (rStickX < -0x40) {
                        cameraAngles.vy -= 0x40;
                    } else if (rStickX > 0x40) {
                        cameraAngles.vy += 0x40;
                    }

                    if ((vs_main_stickPosBuf.rStickY - 0x80) < -0x40) {
                        cameraAngles.vx += 0x40;
                    } else if ((vs_main_stickPosBuf.rStickY - 0x80) > 0x40) {
                        cameraAngles.vx -= 0x40;
                    }

                    if (cameraAngles.vx < 0) {
                        cameraAngles.vx = 0;
                    }

                    if (cameraAngles.vx > 0x400) {
                        cameraAngles.vx = 0x400;
                    }

                } else {
                    if (vs_main_buttonsPreviousState & PADLup) {
                        cameraAngles.vx += 0x40;
                    } else if (vs_main_buttonsPreviousState & PADLdown) {
                        cameraAngles.vx -= 0x40;
                    }

                    if (vs_main_buttonsPreviousState & PADLright) {
                        cameraAngles.vy = cameraAngles.vy + 0x40;
                    } else if (vs_main_buttonsPreviousState & PADLleft) {
                        cameraAngles.vy = cameraAngles.vy - 0x40;
                    }

                    if (cameraAngles.vx < 0) {
                        cameraAngles.vx = 0;
                    }

                    if (cameraAngles.vx > 0x400) {
                        cameraAngles.vx = 0x400;
                    }
                }

            } else if (vs_main_buttonsPreviousState & PADR2) {
                int rStickX;
                int rStickY;
                rotationColor = vs_getRGB888(32, 32, 32);

                if ((rStickX = vs_main_stickPosBuf.rStickX - 0x80, ABS(rStickX) > 0x40)
                    || (rStickY = vs_main_stickPosBuf.rStickY - 0x80,
                        ABS(rStickY) > 0x40)) {

                    if ((vs_main_stickPosBuf.rStickY - 0x80) < -0x40) {
                        cameraDistance -= 4;
                    } else if ((vs_main_stickPosBuf.rStickY - 0x80) > 0x40) {
                        cameraDistance += 4;
                    }

                } else {
                    if (vs_main_buttonsPreviousState & PADLup) {
                        cameraDistance -= 0x40;
                    } else if (vs_main_buttonsPreviousState & PADLdown) {
                        cameraDistance += 0x40;
                    }
                }

                if (cameraDistance >= 0x280) {
                    if (cameraDistance > 0x1800) {
                        cameraDistance = 0x1800;
                    }
                } else {
                    cameraDistance = 0x280;
                }
            }
        }

        if (vs_main_buttonsPressed.all & PADselect) {
            toggleMenuAction(hideUi);
            hideUi ^= 1;
        }

        if ((vs_main_buttonsPreviousState & (PADL1 | PADR1)) != (PADL1 | PADR1)) {

            if (vs_main_buttonsPressed.all & (PADL1 | PADR1)) {
                enemySkipDelay = 0;
            }

            if (vs_main_buttonRepeat & PADR1) {
                if (enemySkipDelay == 0) {
                    if (monBinData[selectedEnemy].next != selectedEnemy) {

                        vs_main_playSfxDefault(0x7E, 11);

                        selectedEnemy = monBinData[selectedEnemy].next;
                        buttonHeld = PADR1;

                        setEnemyDescription();
                    }
                }
                enemySkipDelay = (enemySkipDelay + 1) & 3;
            }

            if (vs_main_buttonRepeat & PADL1) {
                if (enemySkipDelay == 0) {
                    if (monBinData[selectedEnemy].prev != selectedEnemy) {

                        vs_main_playSfxDefault(0x7E, 11);

                        selectedEnemy = monBinData[selectedEnemy].prev;
                        buttonHeld = PADL1;

                        setEnemyDescription();
                    }
                }

                enemySkipDelay = (enemySkipDelay + 1) & 3;
            }
        }

        renderEnemyDetailScreen(menuAnimState, 0);

        if (menuAnimState < 8) {
            textBox = vs_battle_getTextBox(0);
            textBox->x -= 0x10;
            textBox->xIndent -= 0x10;
            ++menuAnimState;
        }

        if (vs_main_buttonsReleased & buttonHeld) {

            if (buttonHeld == PADR1) {
                buttonHeld = 1;
            } else {
                buttonHeld = 2;
            }

            rotationColor = vs_getRGB888(32, 32, 32);
            zoomColor = vs_getRGB888(32, 32, 32);
            menuState = 0x19;
        }
        break;

    case 21:
        rotationColor = vs_getRGB888(32, 32, 32);
        zoomColor = vs_getRGB888(32, 32, 32);

        renderEnemyDetailScreen(menuAnimState, 0);

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

        if (nextState != 0) {
            vs_main_freeHeapR(monBinData);
            restoreCamera();
            return 2;
        }

        selectedEnemy = vs_battle_menu9CursorMemory.encyclopaediaPage
                      + vs_battle_menu9CursorMemory.encyclopaediaRow;

        vs_mainmenu_setInformationMessage(
            (char*)&enemyDescriptions[enemyDescriptions[selectedEnemy]]);

        menuState = 0xE;
        break;

    case 25:
        renderEnemyNavigation(2);
        renderEnemyNavigation(3);
        renderEnemyDetailScreen(menuAnimState, buttonHeld);

        if (menuAnimState > 0) {
            --menuAnimState;
            break;
        }

        vs_menu9_freeZud();
        vs_menu9_loadZud(monBinData[selectedEnemy].zudIndex);

        ++menuState;
        break;

    case 26:
        renderEnemyNavigation(2);
        renderEnemyNavigation(3);
        renderEnemyDetailScreen(menuAnimState, 3);

        if (vs_menu9_loadZud(monBinData[vs_battle_menu9CursorMemory.encyclopaediaPage
                                        + vs_battle_menu9CursorMemory.encyclopaediaRow]
                    .zudIndex)
            == 0) {

            int temp_v1_10 = D_800F4538[1]->menuCameraDistance;
            initCameraDistance = temp_v1_10;
            cameraHeightOffset = D_800F4538[1]->menuCameraHeightOffset;
            cameraDistance = (temp_v1_10 << 0x10) >> 0xE;

            if (cameraDistance < 0x280) {
                cameraDistance = 0x280;
            } else if (cameraDistance >= 0x1801) {
                cameraDistance = 0x1800;
            }
            ++menuState;
        }
        break;

    case 27:
        renderEnemyNavigation(2);
        renderEnemyNavigation(3);
        renderEnemyDetailScreen(menuAnimState, 3 - buttonHeld);

        if (menuAnimState < 8) {
            ++menuAnimState;
        } else {
            buttonHeld = 0;
            menuState = 0x14;
        }

        break;
    }

    return 0;
}

/**
 * Resets the camera back to the stored view.
 */
void restoreCamera(void)
{
    vs_main_memcpy(&((vs_scratch_t*)getScratchAddr(0))->camera.position,
        &cameraPositionBackup, sizeof cameraPositionBackup);
    vs_main_memcpy(&((vs_scratch_t*)getScratchAddr(0))->camera.angles.vx,
        &cameraAnglesBackup, sizeof cameraAnglesBackup);
}

/**
 * Set's the current enemy description or a generic message if the enemy
 * hasn't been defeated.
 */
void setEnemyDescription(void)
{
    if (monBinData[selectedEnemy].unlocked != 0) {
        vs_mainmenu_setInformationMessage(
            (char*)&enemyDescriptions[enemyDescriptions[selectedEnemy]]);
    } else {
        vs_mainmenu_setInformationMessage(
            (char*)&miscInfo[miscInfo[VS_miscInfo_INDEX_enemyNotDefeated]]);
    }
}

/**
 * Handles input for the top level menu.
 *
 * @return -1 if initializing or user exits, selected row otherwise.
 */
int topMenu(int initialize)
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
            menuText[i * 2] = (char*)&menuTextTable[menuTextTable[i]];
            menuText[i * 2 + 1] = NULL;
        }

        setRows(4, vs_battle_menu9CursorMemory.gazetteRow, menuText);

        ++state;
        break;

    case 1:
        selectedRow = getSelectedRow();

        if (selectedRow == -1) {
            break;
        }

        return selectedRow;
    }

    return -1;
}

void buildYawMatrix(MATRIX* arg0, short arg1);
void buildPitchMatrix(MATRIX* arg0, short arg1);

/**
 * Updates the camera with the adjusted parameters.
 */
void buildCameraMatrix(MATRIX* cameraMatrix)
{
    SVECTOR negPosition;
    SVECTOR position;
    MATRIX pitchMatrix;
    int angle0;
    int angle1;
    int angle2;
    vs_scratch_t* scratch;

    angle0 = (angle1 = rsin(cameraAngles.vy));
    angle1 = rcos(cameraAngles.vx);
    position.vx = (((angle0 * cameraDistance) / ONE) * angle1) / ONE;

    angle0 = rcos(cameraAngles.vy);
    angle1 = rcos(cameraAngles.vx);
    position.vz = (((angle0 * -cameraDistance) / ONE) * angle1) / ONE;

    angle2 = rsin(cameraAngles.vx) * -cameraDistance;
    position.vy = (angle2 / ONE) - (cameraHeightOffset / 2);

    scratch = (vs_scratch_t*)getScratchAddr(0);
    setVector(&scratch->camera.position, position.vx * ONE, position.vy * ONE,
        position.vz * ONE);
    scratch->camera.angles.vx = cameraAngles.vx;
    scratch->camera.angles.vy = cameraAngles.vy;
    scratch->camera.angles.vz = cameraAngles.vz;

    buildYawMatrix(cameraMatrix, cameraAngles.vy);
    buildPitchMatrix(&pitchMatrix, cameraAngles.vx);
    func_80041C68(&pitchMatrix, cameraMatrix);

    applyVector(&negPosition, position.vx, position.vy, position.vz, = -);

    ApplyMatrix(cameraMatrix, &negPosition, (VECTOR*)&cameraMatrix->t);
}

/**
 * Updates camera yaw angle.
 */
void buildYawMatrix(MATRIX* cameraMatrix, short angle)
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
void buildPitchMatrix(MATRIX* pitchMatrix, short angle)
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
 * The quads behind the enemy number and class / name.
 */
void renderEnemyInfoBg(int x, int y, int w, int h, int color)
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
            line, bgColorStops0[color].r, bgColorStops0[color].g, bgColorStops0[color].b);
        setRGB1(
            line, bgColorStops1[color].r, bgColorStops1[color].g, bgColorStops1[color].b);

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

    insertTPage(7, getTPage(0, 3, 0, 0));
}

/**
 * The quads behind "Score" and "Risk Breaker Rank".
 */
void renderGradientQuad(int x, int y, int w, int h, int color)
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
    r0 = bgColorStops0[color].r;
    g0 = bgColorStops0[color].g;
    b0 = bgColorStops0[color].b;
    r1 = bgColorStops1[color].r;
    g1 = bgColorStops1[color].g;
    b1 = bgColorStops1[color].b;

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

    insertTPage(7, getTPage(0, 3, 0, 0));
}

/**
 * The black footer background on the top menu
 * (replaced by an info box on other screens).
 */
void renderFooterBg(int x)
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

    insertTPage(7, getTPage(0, 2, 0, 0));
}

void renderScreenEdgeFade(void);

/**
 * Bundles camera update and non-menu UI elements.
 */
void renderTopMenu(int animStep)
{
    vs_battle_geomOffset sp18;
    vs_battle_geomOffset sp20;
    char sp28[128];
    MATRIX spA8;
    void** scratch;

    if (animStep < 8) {
        renderScreenEdgeFade();
    }

    vs_battle_getGeomOffset(&sp18);

    sp20.x = 0x80 - ((8 - animStep) << 5);
    sp20.y = 0xF0;

    vs_battle_setGeomOffset(&sp20);
    buildCameraMatrix(&spA8);
    func_800F9EB8(&spA8);
    vs_battle_setGeomOffset(&sp18);

    sprintf(sp28, "#%ld", score);

    scratch = (void**)getScratchAddr(0);

    vs_battle_renderTextRawColor("SCORE", (((animStep * 16) - 120) & 0xFFFF) | (16 << 16),
        vs_getRGB888(128, 128, 128), scratch[1] + 0x1C);
    vs_battle_renderTextRawColor(sp28, ((animStep * 16) & 0xFFFF) | (16 << 16),
        vs_getRGB888(128, 128, 128), scratch[1] + 0x1C);

    renderGradientQuad((animStep * 16) - 128, 16, 136, 12, 2);
    vs_battle_renderTextRawColor("RISK   BREAKER   RANK",
        (((animStep * 16) - 120) & 0xFFFF) | (184 << 16), vs_getRGB888(128, 128, 128),
        scratch[1] + 0x1C);

    renderGradientQuad((animStep * 16) - 128, 184, 136, 12, 1);
    renderFooterBg(236 - (animStep * 6));
}

/**
 * Configures the text and row status for the titles submenu.
 */
void setTitleRows(void)
{
    int i;
    gazetteRow_t* row;
    int new_var;

    for (i = 0, row = gazetteRows; i < 32; ++i, ++row) {

        row->x = 60;
        row->rowIndex = i + 1;
        row->selected = 0;
        row->animationState = 0;
        row->disabled = 0;

        if (vs_main_scoredata.titles & ((new_var = 1) << i)) {
            row->unk1 = 1;
            row->title = (char*)&titleText[titleText[i]];
            row->description = (char*)&titleDescriptions[titleDescriptions[i]];
        } else {
            row->unk1 = 0;
            row->title = (char*)&miscInfo[miscInfo[VS_miscInfo_INDEX_noneClear]];
            row->description =
                (char*)&miscInfo[miscInfo[VS_miscInfo_INDEX_conditionsNotMet]];
        }
    }
}

void renderTitleNo(int arg0, int arg1, int enemyNo, int arg3);

/**
 * Manages the title selection menu and its animation.
 *
 * @param animState Value from 0-8, incremented or decremented linearly.
 */
void renderTitleMenu(int animState)
{
    static char cursorAnimState = 0;

    int i;
    vs_battle_menuItem_t* menuItem;

    gazetteRow_t* row = gazetteRows;
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

    row = &gazetteRows[vs_battle_menu9CursorMemory.titlePage];

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
        menuItem->gradientState = row->animationState;

        if ((i == 0) && (vs_battle_menu9CursorMemory.titlePage != 0)) {
            menuItem->isScrollable = menuItem_scrollUp;
        }

        if ((i == 7) && (vs_battle_menu9CursorMemory.titlePage != 24)) {
            menuItem->isScrollable = menuItem_scrollDown;
        }

        renderTitleNo(row->x - 14, y, row->rowIndex, menuItem->isScrollable & 1);

        if ((menuItem->isScrollable != menuItem_scrollNone) && (animState == 8)) {
            renderScrollableMenuItem(menuItem);
        } else {
            vs_battle_renderMenuItem(menuItem);
        }
    }

    vs_battle_getMenuItem(0)->state = 0;
}

/**
 * Renders a title index.
 *
 * @param dimmed Renders the digit with a lower brightness.
 * De facto reserved for the first title when the window doesn't
 * start at index 01.
 */
void renderTitleNo(int x, int y, int titleNo, int dimmed)
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
void renderEnemyNo(int x, int y, int enemyNo, int dimmed)
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
void initEnemyList(void)
{
    int i;
    char index;
    monBinData_t* enemy;

    for (i = 0, enemy = monBinData; i < 78; ++i, ++enemy) {
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

    for (i = 0, enemy = monBinData, index = -1; i < 78; ++i, ++enemy) {
        if (enemy->unlocked != 0) {
            enemy->prev = index;
            index = i;
        }
    }

    for (i = 0, enemy = monBinData; i < 78; ++i, ++enemy) {
        if (enemy->unlocked != 0) {
            enemy->prev = index;
            break;
        }
    }

    for (i = 77, enemy = &monBinData[77], index = -1; i >= 0; --i, --enemy) {
        if (enemy->unlocked != 0) {
            enemy->next = index;
            index = i;
        }
    }

    for (i = 77, enemy = &monBinData[77]; i >= 0; --i, --enemy) {
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
void renderEnemyMenu(int animState)
{
    static char cursorAnimStep = 0;

    int i;
    int sp18;
    int selectedRow = vs_battle_menu9CursorMemory.encyclopaediaPage
                    + vs_battle_menu9CursorMemory.encyclopaediaRow;
    monBinData_t* enemy = monBinData;

    for (i = 0; i < 78; ++i) {

        if (i == selectedRow) {

            if (enemy->selected == 0) {
                if (enemy->unlocked != 0) {
                    vs_mainmenu_setInformationMessage(
                        (char*)&enemyDescriptions[enemyDescriptions[i]]);
                } else {
                    vs_mainmenu_setInformationMessage(
                        (char*)&miscInfo[miscInfo[VS_miscInfo_INDEX_enemyNotDefeated]]);
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
    enemy = &monBinData[vs_battle_menu9CursorMemory.encyclopaediaPage];

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
            cursorAnimStep =
                vs_mainMenu_renderCursor(cursorAnimStep, ((y - 8) << 0x10) | 48);
        }

        if (enemy->unlocked != 0) {
            menuItem = vs_battle_setMenuItem(0, x, y, 200, 0, enemy->name);
        } else {
            menuItem = vs_battle_setMenuItem(0, x, y, 0xC8, 0,
                (char*)&miscInfo[miscInfo[VS_miscInfo_INDEX_enemyNameNone]]);
            menuItem->fontColor = 3;
        }

        menuItem->gradientState = enemy->animationState;

        if ((i == 0) && (cursorMem->encyclopaediaPage != 0)) {
            menuItem->isScrollable = menuItem_scrollUp;
        }

        if ((i == 7) && (cursorMem->encyclopaediaPage != 70)) {
            menuItem->isScrollable = menuItem_scrollDown;
        }

        renderEnemyNo(
            x - 14, y, cursorMem->encyclopaediaPage + i + 1, menuItem->isScrollable & 1);

        if ((menuItem->isScrollable != 0) && (animState == 8)) {
            renderScrollableMenuItem(menuItem);
        } else {
            vs_battle_renderMenuItem(menuItem);
        }
    }

    vs_battle_getMenuItem(0)->state = 0;
}

/**
 * @brief Sets the camera and enemy details.
 */
void renderEnemyDetailScreen(int animState, int state)
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
        renderScreenEdgeFade();
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
        buildCameraMatrix(&sp30);
        func_800F9EB8(&sp30);
        vs_battle_setGeomOffset(&sp50);
    }

    if (state > 0) {
        animState = 8;
    }

    if (hideUi == 0) {
        temp_s2 = (8 - animState) * 16;

        vs_battle_renderMenuItem(vs_battle_setMenuItem(
            0, temp_s2 + 184, 166, 256, 0, &monBinData[selectedEnemy].name[2]));
        vs_battle_getMenuItem(0)->state = 0;

        temp_s4 = animState * 16;
        scratch = (void**)getScratchAddr(0);

        vs_mainmenu_renderButton(buttonIdL2, temp_s4 - 120, 15, scratch[1] + 24);

        temp_s0 = (temp_s4 - 100) & 0xFFFF;

        vs_battle_renderTextRawColor(
            "ROTATION", temp_s0 | (18 << 16), rotationColor, scratch[1] + 24);

        temp_s6 = temp_s4 - 112;

        renderEnemyInfoBg(temp_s6, 18, 96, 12, 3);
        vs_mainmenu_renderButton(buttonIdR2, temp_s4 - 120, 34, scratch[1] + 24);
        vs_battle_renderTextRawColor(
            "ZOOM", temp_s0 | (36 << 16), zoomColor, scratch[1] + 24);
        renderEnemyInfoBg(temp_s6, 36, 78, 12, 3);
        sprintf(sp60, "NO.   %03d/%03d", selectedEnemy + 1, 78);
        vs_battle_renderTextRawColor(
            sp60, ((temp_s4 - 120) & 0xFFFF) | 0xA00000, 0x808080, scratch[1] + 0x1C);
        renderGradientQuad(temp_s4 - 128, 160, 100, 12, 2);
        vs_battle_renderTextRawColor(enemyClassName[monBinData[selectedEnemy].classId],
            ((temp_s2 + 188) & 0xFFFF) | 0x9B0000, 0x808080, NULL);
        renderGradientQuad(temp_s2 + 180, 155, 140, 26, 1);
    }
}

/**
 * Draws a semitransparent gradient on the left and right edges of the screen.
 */
void renderScreenEdgeFade(void)
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

    insertTPage(8, getTPage(0, 2, 0, 0));
}

void stringCopy(u_char* dest, u_char* src)
{
    while (*src != vs_char_terminator) {
        *dest++ = *src++;
    }

    *dest = *src;
}

void stringConcat(char* dest, char* src)
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
void setStatText(void)
{
    int i;
    gazetteRow_t* p;

    for (i = 0, p = gazetteRows; i < 23; ++i, ++p) {
        p->x = 16;
        p->title = (void*)&statHeaders[statHeaders[i]];
        p->description = (void*)&statDescriptions[statDescriptions[i]];
        p->animationState = 0;
        p->rowIndex = i + 1;
        p->selected = 0;
        p->disabled = 0;
        p->unk1 = 1;
    }
}

void toVsStringInt(char* buf, int value);
void printFastestClearTime(char* buf, int rounds, int totalSeconds);
void toVsStringPercent(char* buf, int value);
void toVsStringPercentAlias(char* buf, int value);

/**
 * Formats and renders the boss rush data.
 */
void renderBossRushDetails(int animState)
{
    static char cursorAnimStep = 0;

    char sp18[32];
    gazetteRow_t* row;
    u_short temp_v1_4;
    int s5;
    int i;
    vs_battle_menuItem_t* menuItem;
    char* intBuf;
    vs_battle_menu9CursorMemory_t* new_var;
    int v1;

    row = gazetteRows;
    temp_v1_4 = vs_battle_menu9CursorMemory.recordTimePage
              + vs_battle_menu9CursorMemory.recordTimeRow;

    for (i = 0; i < 23; ++i, ++row) {
        if (i == temp_v1_4) {
            if (row->selected == 0) {
                vs_mainmenu_setInformationMessage(row->description);
            }
            row->selected = 1;
            row->animationState = 8;
        } else {
            row->selected = 0;
            if (row->animationState != 0) {
                --row->animationState;
            }
        }
    }

    row = &gazetteRows[vs_battle_menu9CursorMemory.recordTimePage];
    i = 0;
    new_var = &vs_battle_menu9CursorMemory;
    intBuf = &sp18[2];
    s5 = 0x30 * 6;

    for (; i < 8; ++i, ++row) {
        int var_s4 = 0xF0 - (animState * 0x17);

        if (var_s4 < ((i * 0x10) + 0x38)) {
            var_s4 = ((i * 0x10) + 0x38);
        }
        if ((row->selected != 0) && (animState == 8)) {
            cursorAnimStep = vs_mainMenu_renderCursor(
                cursorAnimStep, ((row->x - 0xC) & 0xFFFF) | ((var_s4 - 8) << 0x10));
        }

        menuItem = vs_battle_setMenuItem(0, row->x, var_s4, 0x8E, 0, row->title);
        menuItem->gradientState = row->animationState;

        if ((i == 0) && (new_var->recordTimePage != 0)) {
            menuItem->isScrollable = 1;
        }

        if ((i == 7) && (new_var->recordTimePage != 0xF)) {
            menuItem->isScrollable = 2;
        }

        if ((menuItem->isScrollable != 0) && (animState == 8)) {
            renderScrollableMenuItem(menuItem);
        } else {
            vs_battle_renderMenuItem(menuItem);
        }

        v1 = new_var->recordTimePage + i;

        if (v1 == 0) {
            toVsStringInt(intBuf, clearCount);
        } else if (v1 == 1) {
            printFastestClearTime(intBuf, vs_main_scoredata.clearCount,
                vs_main_scoredata.completionTimeMinutes);
        } else if (v1 == 2) {
            toVsStringPercent(intBuf, (openedChestCount * 100) / 52);
        } else if (v1 == 3) {
            toVsStringPercent(intBuf, (vs_main_scoredata.openedChestCount * 100) / 52);
        } else if (v1 == 4) {
            toVsStringPercentAlias(intBuf, (mapCompletion * 100) / 361);
        } else if (v1 == 5) {
            toVsStringPercentAlias(intBuf, vs_main_scoredata.mapCompletion * 100 / 361);
        } else if (v1 == 6) {
            toVsStringInt(intBuf, vs_main_scoredata.maxChain);
        } else if (v1 < 13) {
            toVsStringInt(intBuf, vs_main_scoredata.enemyKills[v1 - 7]);
        } else {
            v1 -= 12;
            if (v1 == 10) {
                v1 = 0;
            }
            toVsStringInt(intBuf, vs_main_scoredata.weaponAttacks[v1]);
        }

        v1 = s5 - (vs_battle_getTextLineLength(intBuf) * 6);
        ++s5;
        --s5;
        sp18[0] = 0xFA;
        sp18[1] = v1 - (row->x - 0x72);
        menuItem = vs_battle_setMenuItem(0, row->x + 0x8E, var_s4, 0x8E, 0, sp18);
        menuItem->gradientState = 8 - row->animationState;

        if ((i == 0) && (new_var->recordTimePage != 0)) {
            menuItem->isScrollable = 1;
        }
        if ((i == 7) && (new_var->recordTimePage != 0xF)) {
            menuItem->isScrollable = 2;
        }

        if ((menuItem->isScrollable != 0) && (animState == 8)) {
            renderScrollableMenuItem(menuItem);
        } else {
            vs_battle_renderMenuItem(menuItem);
        }
    }

    vs_battle_getMenuItem(0)->state = 0;
}

/**
 * Prints an integer in VS string encoding.
 */
void toVsStringInt(char* buf, int value)
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
 * Same as toVsStringInt but appends a %.
 */
void toVsStringPercent(char* buf, int value)
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
void printFastestClearTime(char* buf, int rounds, int totalSeconds)
{
    int len;
    int i;
    int minutes;
    int seconds;
    char* str;

    if (clearCount == 0) {
        stringCopy(
            (u_char*)buf, (u_char*)&miscInfo[miscInfo[VS_miscInfo_INDEX_noneClear]]);
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
void printBossRushMenuRow(void)
{
    int i;
    gazetteRow_t* row;

    for (i = 0, row = gazetteRows; i < 8; ++i, ++row) {
        row->x = 194;
        if ((vs_main_scoredata.bossTimeTrialScores[i][0].time) == 0x800000) {
            row->disabled = 1;
            row->title = (char*)&miscInfo[miscInfo[VS_miscInfo_INDEX_noneBossRush]];
            row->description =
                (char*)&miscInfo[miscInfo[VS_miscInfo_INDEX_noneBossRushDesc]];
        } else {
            row->disabled = 0;
            row->title = (char*)&timeAttacks[timeAttacks[i]];
            row->description = (char*)&timeAttackDescriptions[timeAttackDescriptions[i]];
        }
        row->selected = 0;
        row->animationState = i + 1;
        row->unk1 = 1;
    }
}

/**
 *  Row animation when leaving record time menu.
 */
void leaveBossRushMenu(void)
{
    int i;
    gazetteRow_t* p = gazetteRows;

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
void renderBossRushRecords(int selected)
{
    static char cursorAnimStep = 0;

    UNUSED char* difficulty[] = { "EASY", "NORMAL" };
    UNUSED int difficultyColors[] = { vs_getRGB(0, 128, 128), vs_getRGB(128, 128, 0) };

    char sp28[16];
    int sp38;
    gazetteRow_t* sp3C;
    gazetteRow_t* var_s1;
    int var_fp;
    int i;
    int j;
    int var_s7;
    int time;
    vs_battle_menuItem_t* menuItem;
    void** p;
    void** r;
    void** q;

    var_s1 = gazetteRows;
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

    var_s1 = gazetteRows;

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

            cursorAnimStep = vs_mainMenu_renderCursor(cursorAnimStep, var_fp);

            sp3C = var_s1;

        } else {
            var_s1->selected = 0;
            menuItem->selected = 0;
        }
    }

    p = ((void**)0x1F800000);
    vs_battle_renderTextRawColor(
        "PLAYER TIME", vs_getXY((selected * 0x10) - 0x78, 0x20), 0x808080, p[1] + 0x1C);
    renderGradientQuad((selected * 0x10) - 0x80, 0x20, 0x60, 0xC, 1);
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

    renderGradientQuad((selected * 0x10) - 0x70, 0x32, 0x80, 0x54, 2);
    r = ((void**)0x1F800000);
    vs_battle_renderTextRawColor("REFERENCE TIME", vs_getXY(selected * 16 - 0x78, 0x8C),
        vs_getRGB(128, 128, 128), r[1] + 0x1C);
    renderGradientQuad((selected * 0x10) - 0x80, 0x8C, 0x70, 0xC, 1);

    if ((var_s7 == 8) && (selected == var_s7)) {
        if (sp3C->disabled != 0) {
            vs_battle_renderTextRawColor(
                "$--:--:--", vs_getXY(88, 158), vs_getRGB(80, 80, 80), r[1] + 0x1C);
        } else {
            vs_battle_renderTextRawColor(timeAttackReferenceTimes[sp38],
                vs_getXY(88, 158), vs_getRGB(128, 128, 128), r[1] + 0x1C);
        }
    }
    renderGradientQuad((selected * 0x10) - 0x70, 0x9E, 0x80, 0xC, 2);
}

/**
 * Calculates the rank based on the number of titles unlocked.
 */
void determineCharacterRank(void)
{
    static short characterRankTitleThresholds[16] = { 16, 12, 8 };
    static u_int characterRankPointThresholds[] = { 100000000, 75000000, 60000000,
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
        if ((titleCount >= characterRankTitleThresholds[i])
            && (score >= characterRankPointThresholds[i])) {
            characterRank = i;
            return;
        }
    }
}

/**
 * Checks game conditions and updates the unlocked titles
 */
void setTitleFlags(void)
{
    int i;

    if (clearCount != 0) {
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
        if (!vs_main_actions[i].unlocked) {
            break;
        }
    }

    if (i == 224) {
        vs_main_scoredata.titles |= 1 << 14;
    }

    for (i = 22; i < 54; ++i) {
        if (((i != 33) && (i != 36) && (i != 38) && (i != 39)
                && !vs_main_actions[i].unlocked)) {
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
void renderEnemyNavigation(int direction)
{
    int x;
    int clut;
    POLY_FT4* poly;
    void** scratch;
    int new_var;

    if (hideUi == 0) {

        clut = getClut(896, 223);

        if (direction >= 2) {
            direction -= 2;
            clut = getClut(912, 223);
        }

        if (direction != 0) {
            vs_battle_renderTextRawColor(
                "#R1", vs_getXY(286, 98), vs_getRGB888(128, 128, 128), NULL);

            if (enemyNavigationState < 9) {
                x = (enemyNavigationState >> 1) + 288;
            } else {
                x = -(enemyNavigationState >> 2) + 294;
            }
        } else {
            vs_battle_renderTextRawColor(
                "L1", vs_getXY(34, 98), vs_getRGB888(128, 128, 128), NULL);

            if (enemyNavigationState < 9) {
                new_var = 32;
                x = new_var - (enemyNavigationState >> 1);
            } else {
                x = (enemyNavigationState >> 2) + 26;
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
 */
void calculateScore(void)
{
    short classPoints[6] = { 20, 20, 40, 80, 100, 60 };
    short weaponClassPoints[10] = { 20, 40, 20, 100, 60, 100, 60, 100, 80, 60 };
    int i;

    score = 0;

    for (i = 0; i < 6; ++i) {
        score += vs_main_scoredata.enemyKills[i] * classPoints[i];
    }

    for (i = 0; i < 10; ++i) {
        score += vs_main_scoredata.weaponAttacks[i] * weaponClassPoints[i];
    }

    for (i = 0; i < 8; ++i) {
        if (vs_main_scoredata.bossTimeTrialScores[i][0].time != 0x800000) {
            score += 20000;
        }
    }

    if (vs_main_scoredata.maxChain < 6) {
        score += vs_main_scoredata.maxChain * 10;
    } else if (vs_main_scoredata.maxChain < 11) {
        score += vs_main_scoredata.maxChain * 20;
    } else if (vs_main_scoredata.maxChain < 16) {
        score += vs_main_scoredata.maxChain * 40;
    } else if (vs_main_scoredata.maxChain < 21) {
        score += vs_main_scoredata.maxChain * 80;
    } else if (vs_main_scoredata.maxChain < 26) {
        score += vs_main_scoredata.maxChain * 160;
    } else if (vs_main_scoredata.maxChain < 31) {
        score += vs_main_scoredata.maxChain * 320;
    } else if (vs_main_scoredata.maxChain < 51) {
        score += vs_main_scoredata.maxChain * 640;
    } else {
        score += vs_main_scoredata.maxChain * 1280;
    }

    score += clearCount * 100000;

    if ((clearCount != 0) && (vs_main_scoredata.completionTimeMinutes < 600)) {
        if (vs_main_scoredata.completionTimeMinutes >= 540) {
            score += score / 4;
        } else if (vs_main_scoredata.completionTimeMinutes >= 300) {
            score += score / 2;
        } else {
            score *= 2;
        }
    }

    score += vs_main_scoredata.streakScore;
    score += vs_main_scoredata.miscScore;
    if (score > 999999999) {
        score = 999999999;
    }
}
