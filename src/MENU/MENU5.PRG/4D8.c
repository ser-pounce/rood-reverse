#include "common.h"
#include "4D8.h"
#include "src/SLUS_010.40/31724.h"
#include "src/SLUS_010.40/32154.h"
#include "src/SLUS_010.40/cd.h"
#include "src/SLUS_010.40/clut.h"
#include "src/SLUS_010.40/gameFlags.h"
#include "src/SLUS_010.40/gameState.h"
#include "src/SLUS_010.40/graphics.h"
#include "src/SLUS_010.40/memory.h"
#include "src/SLUS_010.40/pad.h"
#include "src/SLUS_010.40/sound.h"
#include "src/BATTLE/BATTLE.PRG/2EA3C.h"
#include "src/BATTLE/BATTLE.PRG/573B8.h"
#include "src/BATTLE/BATTLE.PRG/battleUi.h"
#include "src/BATTLE/BATTLE.PRG/menuState.h"
#include "src/BATTLE/BATTLE.PRG/mpd.h"
#include "src/MENU/MAINMENU.PRG/2D10.h"
#include "src/MENU/MAINMENU.PRG/58EC.h"
#include "src/MENU/MAINMENU.PRG/C48.h"
#include "build/assets/MENU/MENU5.PRG/connectingMaps.h"
#include "build/assets/MENU/MENU5.PRG/doors.h"
#include "build/assets/MENU/MENU5.PRG/mapNames.h"
#include "build/assets/MENU/MENU5.PRG/paling.h"
#include "build/src/include/lbas.h"
#include "gpu.h"
#include "insertTPage.h"
#include "scratch.h"
#include <libetc.h>
#include <abs.h>

static int loadArmFile(void);
static int menuManager(void);
static void snapMapToRoom(vs_battle_Scene* scene, int roomId);
static void scaleRoomVertices(vs_battle_Scene* scene, int factor);
static int getCurrentRoomIndex(vs_battle_Scene* scene);
static void updateRoomIndex(int searchForward);
static void setCenterpoint(vs_battle_Scene* scene, int roomId);
static void smoothMapToCenterpoint(vs_battle_Scene* scene);
static void renderScreen(void);
static void setCamera(void);
static int mapSelectionMenu(int arg0);
static void renderMap(vs_battle_Scene* arg0);
static int renderRoom(int arg0, void* arg1, int arg2, int arg3);
static void buildYawMatrix(MATRIX* arg0, short arg1);
static void buildPitchMatrix(MATRIX* arg0, short arg1);
static void darkenBackground(void);
static void applyPalingScreenEffect(void);

/**
 * Renders the map controls based on availability.
 */
static void drawUIControls(void);

/**
 * Unclear special rendering.
 */
static void func_80107630(int x, int y, int arg2);

/**
 * Prepends a line to the ot at the top of the scratch memory.
 */
static void insertLine(int x0, int y0, int x1, int y1);

/**
 * Renders the rotated compass.
 */
static void renderCompass(int x, int y, int angle);

/**
 * Used to render the compass elements.
 */
static void computeRotatedRect(int x, int y, int w, int h, int angle);

/**
 * Adds a label to the label list.
 *
 * @param type 0 == door, 1 == connecting map.
 */
static void addMapLabel(int x, int y, int type, int doorId);

/**
 * Enumerates and renders the map label list.
 */
static void renderMapLabels(void);

/**
 * Some sort of flag retrieval, related to func_80107630.
 */
static int func_8010839C(int arg0, int arg1, int arg2);

/**
 * Renders icons that require size control, unlike renderDefaultIcon.
 */
static void renderIcon(int id, int x, int y);

/**
 * Sets or clears the action at the top of the menu.
 */
static void setNextAction(int display)
{
    if (display != 0) {
        vs_mainMenu_setMenuCommand(menuActionMenu);
        vs_mainMenu_hideMenu = 0;
        return;
    }

    vs_mainMenu_setMenuCommand(menuActionNone);
    vs_mainMenu_hideMenu = 1;
}

/**
 * Renders icon from default texpage. In practice only used with
 * Ashley's current position icon == 0.
 */
static void renderDefaultIcon(int id, int xy, int brightness, u_long* nextPrim)
{
    if (nextPrim == 0) {
        nextPrim = vs_scratch.unk8;
    }

    vs_battle_setSpriteDefaultTexPage(128, xy, vs_getWH(16, 16), nextPrim)[4] =
        ((id + 4) << 4) | (getClut(976, 223) << 16) | 0x8000;

    ((u_long*)vs_scratch.unk0)[-4] = (int)(brightness | 0x64000000);
}

static int currentMapRow = -1;

/**
 * Sets up the map selection menu.
 *
 * @param currentMap Packed value:
 *
 * - Bits 0-6: Current map ID
 *
 * - Bit 7: Disables highlighting the current map
 */
static void configureMapMenu(int rowCount, int currentMap, char* menuText[])
{
    int rowTypes[rowCount];
    int i;
    int cursorMemory;

    if (currentMapRow == -1) {
        currentMapRow = currentMap;
    }

    for (i = 0; i < rowCount; ++i) {
        rowTypes[i] = 0;
    }

    if (!(currentMap & 0x80)) {
        if (currentMapRow < rowCount) {
            rowTypes[currentMapRow] |= 4;
        }
    }

    currentMap &= 0x7F;

    if ((rowCount < 9) || (currentMap < 8)) {
        D_800F4EE8.cursorMemories[0] = currentMap;
        D_800F4EE8.cursorMemories[1] = 0;
    } else if (currentMap >= (rowCount - 8)) {
        D_800F4EE8.cursorMemories[0] = currentMap - (rowCount - 9);
        D_800F4EE8.cursorMemories[1] = rowCount - 9;
    } else {
        D_800F4EE8.cursorMemories[0] = 4;
        D_800F4EE8.cursorMemories[1] = currentMap - 4;
    }

    cursorMemory = vs_main_settings.cursorMemory;
    vs_main_settings.cursorMemory = 1;

    vs_mainmenu_setMenuRows(rowCount, 256, menuText, rowTypes);

    vs_main_settings.cursorMemory = cursorMemory;
}

/**
 * Processes user input in the map selection menu.
 *
 * @return Negative if user cancels, or the selected row.
 */
static int mapSelection(void)
{
    int row = vs_mainmenu_getSelectedRow();

    if (row < -1) {
        vs_mainMenu_clearMenuExcept(5);
    } else if (row >= 0) {
        vs_mainMenu_flyoutMenuRightAndHoistSelection(D_800F4EE8.cursorMemories[0], 1);
    }

    return row;
}

void setMenuItemMapName(char* mapName, char fontColor)
{
    vs_battle_MenuItem* menuItem = vs_battle_setMenuItem(10, 320, 34, 0x8C, 8, mapName);

    menuItem->state = 2;
    menuItem->targetPosition0 = 0xB4;
    menuItem->selected = 1;
    menuItem->fontColor = fontColor;
}

/**
 * Clears all rows except the title, unused.
 */
static UNUSED void clearMenu(void);
static void clearMenu(void) { vs_mainMenu_clearMenuExcept(5); }

static void menuReady(void) { vs_mainmenu_ready(); }

static int loadMapBackground(int arg0)
{
    static vs_Main_CdQueueSlot* slot;
    static u_short* buf;
    static int state;

    if (arg0 != 0) {
        vs_Main_CdFile cdFile;
        cdFile.lba = VS_MAPBG_BIN_LBA;
        cdFile.size = VS_MAPBG_BIN_SIZE;
        slot = vs_main_allocateCdQueueSlot(&cdFile);
        buf = vs_main_allocHeapR(VS_MAPBG_BIN_SIZE);
        vs_main_cdEnqueue(slot, buf);
        state = 0;
        return 0;
    }
    switch (state) {
    case 0:
        if (slot->state == 4) {
            vs_main_freeCdQueueSlot(slot);
            vs_main_loadClut(buf, 3, 0, 256);
            vs_battle_renderImage(vs_getXY(640, 256), buf + 256, vs_getWH(160, 240));
            vs_mainMenu_setBackgroundRenderPriority(-4, 128);
            state = 1;
        }
        return 0;
    case 1:
        vs_main_freeHeapR(buf);
        return 1;
    default:
        return 0;
    }
}

int vs_menu5_exec(u_char* state)
{
    enum state { init = 3 };

    static int armfileLoadDelay;
    static int armFileLoaded;
    static int D_80108D38;
    static u_long* menuBgBackup;
    static UNUSED int _;
    static RECT menuBgBackRects[2];

    switch (*state) {
    case init:
        currentMapRow = -1;
        menuBgBackup = vs_main_allocHeapR(0xB600);
        menuBgBackRects[0].x = 768;
        menuBgBackRects[0].y = 227;
        menuBgBackRects[0].w = 256;
        menuBgBackRects[0].h = 1;
        (&menuBgBackRects[1])->x = 672;
        (&menuBgBackRects[1])->y = 256;
        (&menuBgBackRects[1])->w = 96;
        (&menuBgBackRects[1])->h = 240;

        StoreImage(&menuBgBackRects[0], menuBgBackup);
        StoreImage(&menuBgBackRects[1], menuBgBackup + 128);
        loadMapBackground(1);

        *state = 4;
        break;

    case 4:
        if (loadMapBackground(0) == 0) {
            break;
        }

        *state = 5;

        vs_mainMenu_toggleBackgroundFade(1);

        armfileLoadDelay = 8;
        armFileLoaded = 0;
        // Fallthrough

    case 5:
        if (armFileLoaded == 0) {
            armFileLoaded = loadArmFile();
        }

        if (armfileLoadDelay != 0) {
            --armfileLoadDelay;
            break;
        } else if (armFileLoaded) {
            func_8008A4DC(0);
            func_800CB654(1);

            D_800EB9B0 = 0x200000;
            *state = 6;
        } else {
            break;
        }

        // Fallthrough

    case 6:
        *state += vs_mainmenu_ready();
        break;

    case 7:
        D_80108D38 = menuManager();

        if (D_80108D38 != 0) {
            vs_mainMenu_setBackgroundRenderPriority(-4, 128);
            func_800CB654(0);

            D_800EB9B0 = 0;

            func_8008A4DC(1);
            vs_mainMenu_setMenuCommand(menuActionNone);
            vs_mainMenu_clearMenuExcept(vs_mainMenu_menuItemIds_none);

            armfileLoadDelay = 10;
            *state = 8;
        }

        break;

    case 8:
        vs_mainMenu_toggleBackgroundFade(0);
        *state = 9;
        break;

    case 9:
        if (vs_mainMenu_backgroundFadeStep == 0) {

            menuBgBackRects[0].x = 640;
            menuBgBackRects[0].y = 256;
            menuBgBackRects[0].w = 32;
            menuBgBackRects[0].h = 240;

            (&menuBgBackRects[1])->x = 768;
            (&menuBgBackRects[1])->y = 256;
            (&menuBgBackRects[1])->w = 32;
            (&menuBgBackRects[1])->h = 240;

            ClearImage(menuBgBackRects, 0, 0, 0);
            ClearImage(&menuBgBackRects[1], 0, 0, 0);
            vs_main_loadClut((u_short*)menuBgBackup, 3, 0, 0x100);
            vs_battle_renderImage(0x010002A0, menuBgBackup + 0x80, 0xF00060);

            *state = 10;
        }
        break;

    case 10:
        if (D_80108D38 == 2) {
            vs_battle_menuState.currentMenu = 6;
        }

        vs_main_freeHeapR(menuBgBackup);

        vs_mainMenu_hideMenu = 0;
        *state = 0;
        return 1;
    }
    return 0;
}

#include "src/MENU/unused_vertices.h"

static vs_Main_CdFile const sceneArmFiles[] = { { VS_DUMMY_ARM_LBA, VS_DUMMY_ARM_SIZE },
    { VS_SCEN001_ARM_LBA, VS_SCEN001_ARM_SIZE },
    { VS_SCEN002_ARM_LBA, VS_SCEN002_ARM_SIZE },
    { VS_SCEN003_ARM_LBA, VS_SCEN003_ARM_SIZE },
    { VS_SCEN004_ARM_LBA, VS_SCEN004_ARM_SIZE },
    { VS_SCEN005_ARM_LBA, VS_SCEN005_ARM_SIZE },
    { VS_SCEN006_ARM_LBA, VS_SCEN006_ARM_SIZE },
    { VS_SCEN007_ARM_LBA, VS_SCEN007_ARM_SIZE },
    { VS_SCEN008_ARM_LBA, VS_SCEN008_ARM_SIZE },
    { VS_SCEN009_ARM_LBA, VS_SCEN009_ARM_SIZE },
    { VS_SCEN010_ARM_LBA, VS_SCEN010_ARM_SIZE },
    { VS_SCEN011_ARM_LBA, VS_SCEN011_ARM_SIZE },
    { VS_SCEN012_ARM_LBA, VS_SCEN012_ARM_SIZE },
    { VS_SCEN013_ARM_LBA, VS_SCEN013_ARM_SIZE },
    { VS_SCEN014_ARM_LBA, VS_SCEN014_ARM_SIZE },
    { VS_SCEN015_ARM_LBA, VS_SCEN015_ARM_SIZE },
    { VS_SCEN016_ARM_LBA, VS_SCEN016_ARM_SIZE },
    { VS_SCEN017_ARM_LBA, VS_SCEN017_ARM_SIZE },
    { VS_SCEN018_ARM_LBA, VS_SCEN018_ARM_SIZE },
    { VS_SCEN019_ARM_LBA, VS_SCEN019_ARM_SIZE },
    { VS_SCEN020_ARM_LBA, VS_SCEN020_ARM_SIZE },
    { VS_SCEN021_ARM_LBA, VS_SCEN021_ARM_SIZE },
    { VS_SCEN022_ARM_LBA, VS_SCEN022_ARM_SIZE },
    { VS_SCEN023_ARM_LBA, VS_SCEN023_ARM_SIZE },
    { VS_SCEN024_ARM_LBA, VS_SCEN024_ARM_SIZE },
    { VS_SCEN025_ARM_LBA, VS_SCEN025_ARM_SIZE },
    { VS_SCEN026_ARM_LBA, VS_SCEN026_ARM_SIZE },
    { VS_SCEN027_ARM_LBA, VS_SCEN027_ARM_SIZE },
    { VS_SCEN028_ARM_LBA, VS_SCEN028_ARM_SIZE },
    { VS_SCEN029_ARM_LBA, VS_SCEN029_ARM_SIZE },
    { VS_SCEN030_ARM_LBA, VS_SCEN030_ARM_SIZE },
    { VS_SCEN031_ARM_LBA, VS_SCEN031_ARM_SIZE } };

static int const ashleyIconBrightness[] = { 0x00404040, 0x00505050, 0x00606060,
    0x00707070, 0x00808080, 0x00808080, 0x00808080, 0x00808080, 0x00808080, 0x00808080,
    0x00808080, 0x00808080, 0x00707070, 0x00606060, 0x00505050, 0x00404040 };

// Junk? Same values are used elsewhere for gradient lerping.
static UNUSED int const D_80102C40[] = { 0x006B4100, 0x006C8219, 0x00663040, 0x00203840,
    0x00330500, 0x00262801, 0x00200808, 0x00081010 };

u_short mapNames[] = {
#include "build/assets/MENU/MENU5.PRG/mapNames.vsString"
};

static int menuState;
static int currentRoomIndex;
static int backgroundBrightness;
static int menuFramesCounter;
static int geomOffsetX;
static int geomOffsetY;
static int isCurrentScene;
static int cameraDistance;
static int currentScene;
static int chosenMap;
static int isPaling;
static int triggerHideUi;
static int currentSceneRow;
static int hideUi;
static vs_battle_RoomName* roomNamesTable;
static short menuCommandsState;
static short uiAnimationState;
static UNUSED short _1[2];
static SVECTOR cameraAngles;
static SVECTOR cameraPos;
static SVECTOR centerPoint;
static vs_Main_CdQueueSlot* sceneCdQueueSlot;
static void* armFileBuff;
static int sceneRowIdMap[32];
static int quitState;
static int mapLabelY;
static UNUSED int _2[2];

/**
 *
 *
 * @return True if arm file is loaded.
 */
static int loadArmFile(void)
{

    vs_main_stateFlags.mapPaling[0] = 1;

    if (vs_battle_sceneBuffer == NULL) {
        int paling;

        if (vs_main_mapStatus.roomFlags[1] & 0x800000) {
            vs_main_mapStatus.roomFlags[1] |= 0x400000;
        }

        triggerHideUi = 0;
        hideUi = 0;

        vs_main_bzero(&cameraAngles, sizeof cameraAngles);
        vs_main_bzero(&cameraPos, sizeof cameraPos);

        cameraAngles.vx = 568;
        currentRoomIndex = 0;
        cameraAngles.vz = cameraAngles.vy = 2048 - *(u_short*)getScratchAddr(22);

        currentScene = vs_battle_getCurrentSceneId();

        if (currentScene >= 32) {
            currentScene = 0;
        }

        paling = vs_main_stateFlags.mapPaling[currentScene];

        currentSceneRow = currentScene;
        menuState = 0;
        backgroundBrightness = 128;
        menuFramesCounter = 0;
        geomOffsetX = -384;
        geomOffsetY = 0;
        quitState = 1;
        cameraDistance = ONE * 3 / 16;
        menuCommandsState = 5;
        uiAnimationState = 0;
        isPaling = paling;

        vs_battle_sceneBuffer = vs_main_allocHeapR(sceneArmFiles[currentScene].size);
        sceneCdQueueSlot = vs_main_allocateCdQueueSlot(&sceneArmFiles[currentScene]);
        vs_main_cdEnqueue(sceneCdQueueSlot, vs_battle_sceneBuffer);

        return 0;
    }

    if (sceneCdQueueSlot->state != vs_main_CdQueueStateLoaded) {
        return 0;
    }

    vs_main_freeCdQueueSlot(sceneCdQueueSlot);

    roomNamesTable = vs_battle_initSceneAndGetRoomNames(vs_battle_sceneBuffer);

    vs_battle_setRoomsUnk0(vs_battle_sceneBuffer);
    scaleRoomVertices(vs_battle_sceneBuffer, 4);

    currentRoomIndex = getCurrentRoomIndex(vs_battle_sceneBuffer);

    snapMapToRoom(vs_battle_sceneBuffer, currentRoomIndex);
    SetFogNear(768, vs_main_projectionDistance);
    SetFarColor(0, 0, 0);
    setMenuItemMapName((char*)&mapNames[mapNames[currentScene]], 1);

    return 1;
}

/**
 * Processes most of the menu's logic including input.
 *
 * @return int
 */
static int menuManager(void)
{
    enum state {
        init,
        processInput,
        displayMapMenu,
        quit,
        initNewMap,
        waitForMapAnimation
    };

    int var_s2;
    int roomIndex;
    int new_var2;

    SetFarColor(0, 0, 0);

    mapLabelY = 188;
    roomIndex = currentRoomIndex;

    if (vs_main_buttonsPressed.all & PADselect) {
        triggerHideUi ^= 1;
    }

    if (vs_main_stateFlags.mapPaling[currentScene] != 0) {
        vs_mainMenu_setBackgroundRenderPriority(2046, 128);
    } else {
        vs_mainMenu_setBackgroundRenderPriority(2046, (backgroundBrightness + 128) / 2);
    }

    if (menuState != 1) {
        menuCommandsState = 5;
    }

    switch (menuState) {
    case init:
        if (backgroundBrightness > 32) {
            backgroundBrightness -= 16;
            geomOffsetX += 64;
        } else {
            vs_battle_initTextBox(0, 0, 60, 224, 16, 1, 60, 224);
            vs_battle_setTextBox(0, roomNamesTable[currentRoomIndex].name);
            ++menuState;
        }

        renderScreen();
        break;

    case processInput:
        var_s2 = 0;

        if (triggerHideUi != hideUi) {
            hideUi = triggerHideUi;
            setNextAction(triggerHideUi == 0);
        }

        if (vs_main_buttonsPressed.all & PADRright) {
            var_s2 = 5;

            vs_main_playSfxDefault(0x7E, 5);

            menuState = displayMapMenu;

            if (hideUi != 0) {
                hideUi = 0;
                setNextAction(1);
            }

            mapSelectionMenu(1);

        } else if (vs_main_buttonsPressed.all & (PADRup | PADRdown)) {

            vs_main_playSfxDefault(0x7E, 6);

            if (vs_main_buttonsPressed.all & PADRup) {
                quitState = 2;
            }

            menuState = quit;

            vs_battle_dismissTextBox(0);

        } else if (vs_main_stateFlags.mapPaling[currentScene] != 0) {
            var_s2 = 5;
        } else {
            int lStickX;
            int lStickY;

            if ((lStickX = vs_main_stickPosBuf.lStickX - 128, ABS(lStickX)) > 64
                || (lStickY = vs_main_stickPosBuf.lStickY - 128, ABS(lStickY) > 64)) {

                var_s2 = 3;

                if ((vs_main_stickPosBuf.lStickX - 128) < -64) {
                    cameraAngles.vy -= 64;
                } else if ((vs_main_stickPosBuf.lStickX - 128) > 64) {
                    cameraAngles.vy += 64;
                }

                if ((vs_main_stickPosBuf.lStickY - 128) < -64) {
                    cameraAngles.vx += 64;
                } else if ((vs_main_stickPosBuf.lStickY - 128) > 64) {
                    cameraAngles.vx -= 64;
                }

                if (cameraAngles.vx >= 0) {
                    if (cameraAngles.vx > 1024) {
                        cameraAngles.vx = 1024;
                    }
                } else {
                    cameraAngles.vx = 0;
                }

            } else {
                if (vs_main_buttonsPreviousState & PADL2) {
                    int rstickX;
                    int rstickY;

                    var_s2 = 3;

                    if ((rstickX = vs_main_stickPosBuf.rStickX - 128, ABS(rstickX) > 64)
                        || (rstickY = vs_main_stickPosBuf.rStickY - 128,
                            ABS(rstickY) > 64)) {
                        if ((vs_main_stickPosBuf.rStickX - 128) < -64) {
                            cameraAngles.vy -= 64;
                        } else if ((vs_main_stickPosBuf.rStickX - 128) > 64) {
                            cameraAngles.vy += 64;
                        }
                        if ((vs_main_stickPosBuf.rStickY - 128) < -64) {
                            cameraAngles.vx += 64;
                        } else if ((vs_main_stickPosBuf.rStickY - 128) > 64) {
                            cameraAngles.vx -= 64;
                        }
                        if (cameraAngles.vx < 0) {
                            cameraAngles.vx = 0;
                            // dummy assignment to break deduplication optimization around
                            // line 184
                        } else if ((lStickX = cameraAngles.vx) > 1024) {
                            cameraAngles.vx = 1024;
                        }
                    } else {
                        if (vs_main_buttonsPreviousState & PADLleft) {
                            cameraAngles.vy -= 64;
                        } else if (vs_main_buttonsPreviousState & PADLright) {
                            cameraAngles.vy += 64;
                        }
                        if ((vs_main_buttonsPreviousState & PADLdown)
                            && (cameraAngles.vx > 0)) {
                            cameraAngles.vx -= 64;
                        } else if ((vs_main_buttonsPreviousState & PADLup)
                                   && (cameraAngles.vx < 1024)) {
                            cameraAngles.vx += 64;
                        }
                    }
                } else if (vs_main_buttonsPreviousState & PADR2) {
                    int rstickX;
                    int rstickY;

                    var_s2 = 2;

                    if ((rstickX = vs_main_stickPosBuf.rStickX - 128, ABS(rstickX) > 64)
                        || (rstickY = vs_main_stickPosBuf.rStickY - 128,
                            ABS(rstickY) > 64)) {

                        if ((vs_main_stickPosBuf.rStickY - 128) < -0x40) {
                            cameraDistance -= ONE / 256;
                        } else if ((vs_main_stickPosBuf.rStickY - 128) > 64) {
                            cameraDistance += ONE / 256;
                        }

                        if (cameraDistance < ONE / 8) {
                            cameraDistance = ONE / 8;
                        } else if (cameraDistance > ONE / 4) {
                            cameraDistance = ONE / 4;
                        }

                    } else {
                        if (vs_main_buttonsPreviousState & PADLup
                            && (cameraDistance > ONE / 8)) {
                            cameraDistance -= ONE / 256;
                        } else if ((vs_main_buttonsPreviousState & PADLdown)
                                   && (cameraDistance < ONE / 4)) {
                            cameraDistance += ONE / 256;
                        }
                    }
                } else if (vs_main_buttonsPreviousState & PADstart) {

                    geomOffsetX = 0;
                    geomOffsetY = 0;
                    cameraDistance = ONE * 3 / 16;
                    cameraAngles.vx = 0x238;
                    cameraAngles.vy = 0x800 - *(u_short*)getScratchAddr(22);
                    currentRoomIndex = getCurrentRoomIndex(vs_battle_sceneBuffer);

                    snapMapToRoom(vs_battle_sceneBuffer, currentRoomIndex);

                } else {
                    int rstickX;
                    int rstickY;

                    if ((rstickX = vs_main_stickPosBuf.rStickX - 128, ABS(rstickX) > 64)
                        || (rstickY = vs_main_stickPosBuf.rStickY - 128,
                            ABS(rstickY) > 64)) {

                        if (rstickX < -64) {
                            geomOffsetX -= 4;
                        } else if (rstickX > 64) {
                            geomOffsetX += 4;
                        }

                        if ((vs_main_stickPosBuf.rStickY - 128) < -64) {
                            geomOffsetY -= 4;
                        } else if ((vs_main_stickPosBuf.rStickY - 128) > 64) {
                            geomOffsetY += 4;
                        }

                        if (geomOffsetY < -80) {
                            geomOffsetY = -80;
                        } else if (geomOffsetY > 80) {
                            geomOffsetY = 80;
                        }

                        if (geomOffsetX < -96) {
                            geomOffsetX = -96;
                        } else if (geomOffsetX > 96) {
                            geomOffsetX = 96;
                        }

                    } else {
                        if ((vs_main_buttonsPreviousState & PADLup)
                            && (geomOffsetY > -80)) {
                            geomOffsetY -= 4;
                        } else if ((vs_main_buttonsPreviousState & PADLdown)
                                   && (geomOffsetY < 80)) {
                            geomOffsetY += 4;
                        }

                        if ((vs_main_buttonsPreviousState & PADLleft)
                            && (geomOffsetX > -96)) {
                            geomOffsetX -= 4;
                        } else if ((vs_main_buttonsPreviousState & PADLright)
                                   && (geomOffsetX < 96)) {
                            geomOffsetX += 4;
                        }
                    }

                    if ((vs_main_buttonsPreviousState & (PADL1 | PADR1))
                        != (PADL1 | PADR1)) {

                        if (vs_main_buttonRepeat & 8) {
                            updateRoomIndex(1);
                            setCenterpoint(vs_battle_sceneBuffer, currentRoomIndex);
                        } else if (vs_main_buttonRepeat & 4) {
                            updateRoomIndex(-1);
                            setCenterpoint(vs_battle_sceneBuffer, currentRoomIndex);
                        }
                    }

                    if (roomIndex != currentRoomIndex) {
                        vs_battle_setTextBox(0, roomNamesTable[currentRoomIndex].name);
                    }
                }
            }
        }

        menuCommandsState = var_s2;

        renderScreen();
        break;

    case displayMapMenu:
        renderScreen();

        chosenMap = new_var2 = mapSelectionMenu(0);

        if (new_var2 == -1) {
            break;
        } else if (new_var2 == -3) {

            menuState = quit;
            quitState = 2;

            vs_battle_dismissTextBox(0);

        } else if (new_var2 == -2) {
            menuState = processInput;

            setMenuItemMapName((char*)&mapNames[mapNames[currentScene]],
                currentScene == currentSceneRow);
        } else {

            isPaling = vs_main_stateFlags.mapPaling[currentScene];
            currentScene = sceneRowIdMap[new_var2];
            menuState = initNewMap;

            armFileBuff = vs_main_allocHeapR(sceneArmFiles[currentScene].size);
            sceneCdQueueSlot = vs_main_allocateCdQueueSlot(&sceneArmFiles[currentScene]);
            vs_main_cdEnqueue(sceneCdQueueSlot, armFileBuff);
        }
        break;

    case quit:
        uiAnimationState = 2;

        if (backgroundBrightness >= 128) {
            vs_main_freeHeapR(vs_battle_sceneBuffer);

            vs_battle_sceneBuffer = NULL;
            return quitState;
        }

        backgroundBrightness += 16;
        geomOffsetX += 64;

        renderScreen();
        break;

    case initNewMap:
        geomOffsetX += 64;

        if ((sceneCdQueueSlot->state == vs_main_CdQueueStateLoaded)
            && (geomOffsetX >= 384)) {

            isPaling = 0;

            vs_main_freeCdQueueSlot(sceneCdQueueSlot);
            vs_main_freeHeapR(vs_battle_sceneBuffer);

            vs_battle_sceneBuffer = vs_main_allocHeapR(sceneArmFiles[currentScene].size);

            vs_main_memcpy(
                vs_battle_sceneBuffer, armFileBuff, sceneArmFiles[currentScene].size);
            vs_main_freeHeapR(armFileBuff);

            roomNamesTable = vs_battle_initSceneAndGetRoomNames(vs_battle_sceneBuffer);

            vs_battle_setRoomsUnk0(vs_battle_sceneBuffer);
            scaleRoomVertices(vs_battle_sceneBuffer, 4);

            currentRoomIndex = getCurrentRoomIndex(vs_battle_sceneBuffer);

            snapMapToRoom(vs_battle_sceneBuffer, currentRoomIndex);
            vs_battle_setTextBox(0, roomNamesTable[currentRoomIndex].name);

            geomOffsetX = -384;
            geomOffsetY = 0;
            menuState = waitForMapAnimation;
        }

        renderScreen();
        break;

    case waitForMapAnimation:
        geomOffsetX += 64;

        if (geomOffsetX >= 0) {
            menuState = processInput;
        }

        renderScreen();
        break;
    }

    ++menuFramesCounter;

    smoothMapToCenterpoint(vs_battle_sceneBuffer);

    return 0;
}

static u_short connectingMaps[] = {
#include "build/assets/MENU/MENU5.PRG/connectingMaps.vsString"
};
static u_short doors[] = {
#include "build/assets/MENU/MENU5.PRG/doors.vsString"
};

/**
 * Updates the whole screen.
 */
static void renderScreen(void)
{
    static u_short paling[] = {
#include "build/assets/MENU/MENU5.PRG/paling.vsString"
    };

    DR_STP* stp;
    void** pScratch = (void**)getScratchAddr(0);
    vs_main_Flags* flags;
    int scene;

    drawUIControls();

    stp = (DR_STP*)(pScratch[0]);

    SetDrawStp(stp, 1);
    AddPrim((DR_STP*)(pScratch[1] + 0x1FFC), stp++);

    flags = &vs_main_stateFlags;
    scene = currentScene;

    do {
    } while (0);

    *(DR_STP**)pScratch = stp;

    if (flags->mapPaling[scene] != 0) {
        applyPalingScreenEffect();
        vs_battle_setTextBox(0, (char*)&paling[paling[0]]);
        return;
    }

    setCamera();
    darkenBackground();

    if (isPaling == 0) {
        renderMap(vs_battle_sceneBuffer);
    }
}

/**
 * Applies the current camera values.
 */
static void setCamera(void)
{
    SVECTOR sp10;
    MATRIX sp18;
    MATRIX sp38;

    cameraPos.vx =
        (((rsin(cameraAngles.vy) * cameraDistance) / ONE) * rcos(cameraAngles.vx)) / ONE;
    cameraPos.vz =
        (((rcos(cameraAngles.vy) * -cameraDistance) / ONE) * rcos(cameraAngles.vx)) / ONE;
    cameraPos.vy = (rsin(cameraAngles.vx) * -cameraDistance) / ONE;

    buildYawMatrix(&sp18, cameraAngles.vy);
    buildPitchMatrix(&sp38, cameraAngles.vx);
    func_80041C68(&sp38, &sp18);

    applyVector(&sp10, cameraPos.vx, cameraPos.vy, cameraPos.vz, = -);

    ApplyMatrix(&sp18, &sp10, (VECTOR*)sp38.t);
    SetRotMatrix(&sp18);
    SetTransMatrix(&sp38);
}

/**
 * Manages map selection.
 *
 * @return The selected map if user has chosen, -2 if there are no maps
 * for some reason, -1 otherwise.
 */
static int mapSelectionMenu(int initialize)
{
    enum state { init, getSelection };

    static int state;
    static int selectedMap;

    char* menuText[64];
    int mapCount;
    int currentMap;
    int i;
    int areaVisited;

    if (initialize != 0) {
        state = init;
        selectedMap = 0;
    }

    switch (state) {
    case init:
        currentMap = 0;

        for (i = 1, mapCount = 0; i < 32; ++i) {

            areaVisited = vs_main_mapStatus.areaFlags[i >> 5] & (1 << (i & 0x1F));

            if (areaVisited) {

                sceneRowIdMap[mapCount] = i;
                menuText[mapCount * 2] = (char*)&mapNames[mapNames[i]];
                menuText[mapCount * 2 + 1] = NULL;

                if (currentScene == i) {
                    currentMap = mapCount;
                }

                ++mapCount;
            }
        }

        if (mapCount == 0) {
            return -2;
        }

        if (currentSceneRow == 0) {
            currentMap = 0x80;
        }

        configureMapMenu(mapCount, currentMap, menuText);

        ++state;
        break;

    case getSelection:
        selectedMap = mapSelection();

        if (selectedMap != -1) {
            return selectedMap;
        }

        break;
    }

    return -1;
}

/**
 * Unused, purpose unclear.
 */
static UNUSED void func_8010467C(int* data);
static void func_8010467C(int* data)
{
    int count;
    int i;
    int* ptr;

    ptr = data + 1;
    count = *data;

    for (i = 0; i < count; ++i) {
        *ptr = 1;
        ptr += 3;
    }
}

static struct {
    int x;
    int y;
} compassBounds[4];

static struct {
    short x;
    short y;
    short type;
    short id;
} mapLabels[8];

static int mapLabelCount;

/**
 * Enumerates and renders visited rooms.
 */
static void renderMap(vs_battle_Scene* scene)
{
    int roomCount;
    int i;
    vs_battle_Room* room;
    int* new_var;
    vs_battle_GeomOffset prevOffset;
    vs_battle_GeomOffset tmpOffset;

    tmpOffset.x = geomOffsetX + 0x90;
    tmpOffset.y = geomOffsetY + 0x88;

    vs_battle_getGeomOffset(&prevOffset);
    vs_battle_setGeomOffset(&tmpOffset);

    mapLabelCount = 0;
    new_var = &scene->roomCount;
    roomCount = *new_var;
    room = (vs_battle_Room*)scene;
    room = scene->rooms;

    for (i = 0; i < roomCount; ++i, ++room) {
        if (room->visited != 0) {
            renderRoom(i, room->dataAddress, room->zoneId, room->mapId);
        }
    }

    renderMapLabels();
    vs_battle_setGeomOffset(&prevOffset);
}

static int renderRoom(int roomIndex, void* roomData, int arg2, int arg3)
{
    CVECTOR colorIn;
    CVECTOR colorOut0;
    CVECTOR colorOut1;
    int sp28[4];
    long sp38;
    long sp3C;
    u_char* var_s3;
    int i;
    int j;
    POLY_G3* polyG3;
    POLY_G4* polyG4;
    LINE_G2* lineG2;
    TILE* tile;
    int const* new_var;

    short (*var_s1)[4] = (void*)getScratchAddr(64);
    int elementCount = *(int*)roomData;
    roomData += 4;

    for (i = 0; i < elementCount; ++i) {
        u_int v0 = RotTransPers(roomData, (long*)var_s1[i], &sp38, &sp3C);
        var_s1[i][2] = v0;
        v0 -= 0x40;
        var_s1[i][3] = sp38;

        if (v0 >= 0x7BF) {
            return 0;
        }

        roomData += 8;
    }

    if (roomIndex == currentRoomIndex) {
        colorIn.r = 0;
        colorIn.g = 0x80;
        colorIn.b = 0x40;
    } else {
        colorIn.r = 0;
        colorIn.g = 0x40;
        colorIn.b = 0x80;
    }

    var_s3 = roomData;
    var_s3 += 4;
    elementCount = *(int*)roomData;
    polyG3 = *(void**)getScratchAddr(0);

    for (i = 0; i < elementCount; ++i) {

        sp38 = var_s1[var_s3[0]][2];

        if (sp38 < var_s1[var_s3[1]][2]) {
            sp38 = var_s1[var_s3[1]][2];
        }

        if (sp38 < var_s1[var_s3[2]][2]) {
            sp38 = var_s1[var_s3[2]][2];
        }

        setPolyG3(polyG3);
        polyG3->x0 = var_s1[var_s3[0]][0];
        polyG3->x1 = var_s1[var_s3[1]][0];
        polyG3->x2 = var_s1[var_s3[2]][0];
        polyG3->y0 = var_s1[var_s3[0]][1];
        polyG3->y1 = var_s1[var_s3[1]][1];
        polyG3->y2 = var_s1[var_s3[2]][1];

        DpqColor(&colorIn, var_s1[var_s3[0]][3], &colorOut0);
        setRGB0(polyG3, colorOut0.r, colorOut0.g, colorOut0.b);

        DpqColor(&colorIn, var_s1[var_s3[1]][3], &colorOut0);
        setRGB1(polyG3, colorOut0.r, colorOut0.g, colorOut0.b);

        DpqColor(&colorIn, var_s1[var_s3[2]][3], &colorOut0);
        setRGB2(polyG3, colorOut0.r, colorOut0.g, colorOut0.b);

        AddPrim(((int**)getScratchAddr(0))[1] + sp38, polyG3++);

        var_s3 += 4;
    }

    elementCount = *(int*)var_s3;
    var_s3 += 4;
    polyG4 = (POLY_G4*)polyG3;

    for (i = 0; i < elementCount; ++i) {
        sp38 = var_s1[var_s3[0]][2];

        if (sp38 < var_s1[var_s3[1]][2]) {
            sp38 = var_s1[var_s3[1]][2];
        }

        if (sp38 < var_s1[var_s3[2]][2]) {
            sp38 = var_s1[var_s3[2]][2];
        }

        if (sp38 < var_s1[var_s3[3]][2]) {
            sp38 = var_s1[var_s3[3]][2];
        }

        setPolyG4(polyG4);
        polyG4->x0 = var_s1[var_s3[0]][0];
        polyG4->x1 = var_s1[var_s3[1]][0];
        polyG4->x2 = var_s1[var_s3[3]][0];
        polyG4->x3 = var_s1[var_s3[2]][0];
        polyG4->y0 = var_s1[var_s3[0]][1];
        polyG4->y1 = var_s1[var_s3[1]][1];
        polyG4->y2 = var_s1[var_s3[3]][1];
        polyG4->y3 = var_s1[var_s3[2]][1];

        DpqColor(&colorIn, var_s1[var_s3[0]][3], &colorOut0);
        setRGB0(polyG4, colorOut0.r, colorOut0.g, colorOut0.b);

        DpqColor(&colorIn, var_s1[var_s3[1]][3], &colorOut0);
        setRGB1(polyG4, colorOut0.r, colorOut0.g, colorOut0.b);

        DpqColor(&colorIn, var_s1[var_s3[3]][3], &colorOut0);
        setRGB2(polyG4, colorOut0.r, colorOut0.g, colorOut0.b);

        DpqColor(&colorIn, var_s1[var_s3[2]][3], &colorOut0);
        setRGB3(polyG4, colorOut0.r, colorOut0.g, colorOut0.b);

        AddPrim(((int**)getScratchAddr(0))[1] + sp38, polyG4++);

        var_s3 += 4;
    }

    new_var = (int*)var_s3;
    elementCount = *new_var;
    var_s3 += 4;
    lineG2 = (LINE_G2*)polyG4;

    for (i = 0; i < elementCount; ++i) {
        long scratch = 0;
        sp38 = var_s1[var_s3[0]][2] - 1;

        if (sp38 < var_s1[var_s3[1]][2]) {
            sp38 = var_s1[var_s3[1]][2] - 1;
        }

        colorIn.g = 0x80;
        colorIn.r = 0;
        colorIn.b = 0xFF;

        DpqColor(&colorIn, var_s1[var_s3[0]][3], &colorOut0);
        DpqColor(&colorIn, var_s1[var_s3[1]][3], &colorOut1);

        setLineG2(lineG2);
        setSemiTrans(lineG2, 1);

        lineG2->x0 = var_s1[var_s3[0]][0] - 1;
        lineG2->x1 = var_s1[var_s3[1]][0] - 1;
        lineG2->y0 = var_s1[var_s3[0]][1];
        lineG2->y1 = var_s1[var_s3[1]][1];

        setRGB0(lineG2, colorOut0.r, colorOut0.g, colorOut0.b);
        setRGB1(lineG2, colorOut1.r, colorOut1.g, colorOut1.b);

        AddPrim(((int**)(0x1f800000 + scratch))[1] + sp38, lineG2++);

        setLineG2(lineG2);
        setSemiTrans(lineG2, 1);

        lineG2->x0 = var_s1[var_s3[0]][0];
        lineG2->x1 = var_s1[var_s3[1]][0];
        lineG2->y0 = var_s1[var_s3[0]][1] - 1;
        lineG2->y1 = var_s1[var_s3[1]][1] - 1;

        setRGB0(lineG2, colorOut0.r, colorOut0.g, colorOut0.b);
        setRGB1(lineG2, colorOut1.r, colorOut1.g, colorOut1.b);

        AddPrim(((int**)(0x1f800000 + scratch))[1] + sp38, lineG2++);

        setLineG2(lineG2);
        setSemiTrans(lineG2, 1);

        lineG2->x0 = var_s1[var_s3[0]][0] + 1;
        lineG2->x1 = var_s1[var_s3[1]][0] + 1;
        lineG2->y0 = var_s1[var_s3[0]][1];
        lineG2->y1 = var_s1[var_s3[1]][1];

        setRGB0(lineG2, colorOut0.r, colorOut0.g, colorOut0.b);
        setRGB1(lineG2, colorOut1.r, colorOut1.g, colorOut1.b);

        AddPrim(((int**)(0x1f800000 + scratch))[1] + sp38, lineG2++);

        setLineG2(lineG2);
        setSemiTrans(lineG2, 1);

        lineG2->x0 = var_s1[var_s3[0]][0];
        lineG2->x1 = var_s1[var_s3[1]][0];
        lineG2->y0 = var_s1[var_s3[0]][1] + 1;
        lineG2->y1 = var_s1[var_s3[1]][1] + 1;

        setRGB0(lineG2, colorOut0.r, colorOut0.g, colorOut0.b);
        setRGB1(lineG2, colorOut1.r, colorOut1.g, colorOut1.b);

        AddPrim(((int**)(0x1f800000 + scratch))[1] + sp38, lineG2++);

        if (roomIndex == currentRoomIndex) {
            colorIn.g = 0xFF;
            colorIn.r = 0;
            colorIn.b = 0x80;
            DpqColor(&colorIn, var_s1[var_s3[0]][3], &colorOut0);
            DpqColor(&colorIn, var_s1[var_s3[1]][3], &colorOut1);
        }

        setLineG2(lineG2);

        lineG2->x0 = var_s1[var_s3[0]][0];
        lineG2->x1 = var_s1[var_s3[1]][0];
        lineG2->y0 = var_s1[var_s3[0]][1];
        lineG2->y1 = var_s1[var_s3[1]][1];

        setRGB0(lineG2, colorOut0.r, colorOut0.g, colorOut0.b);
        setRGB1(lineG2, colorOut1.r, colorOut1.g, colorOut1.b);

        AddPrim(((int**)(0x1f800000 + scratch))[1] + sp38, lineG2++);

        var_s3 += 4;
    }

    elementCount = *(int*)var_s3;
    var_s3 += 4;

    for (i = 0; i < elementCount; ++i, var_s3 += 4) {

        sp38 = var_s1[var_s3[0]][2] - 1;

        if (sp38 < var_s1[var_s3[1]][2]) {
            sp38 = var_s1[var_s3[1]][2] - 1;
        }

        if (roomIndex == currentRoomIndex) {
            colorIn.g = 0xFF;
        } else {
            colorIn.g = 0x40;
        }

        colorIn.r = 0;
        colorIn.b = 0x80;

        DpqColor(&colorIn, var_s1[var_s3[0]][3], &colorOut0);
        DpqColor(&colorIn, var_s1[var_s3[1]][3], &colorOut1);

        setLineG2(lineG2);

        do {
            setSemiTrans(lineG2, 1);
        } while (0);

        lineG2->x0 = var_s1[var_s3[0]][0];
        lineG2->x1 = var_s1[var_s3[1]][0];
        lineG2->y0 = var_s1[var_s3[0]][1];
        lineG2->y1 = var_s1[var_s3[1]][1];

        setRGB0(lineG2, colorOut0.r, colorOut0.g, colorOut0.b);
        setRGB1(lineG2, colorOut1.r, colorOut1.g, colorOut1.b);

        AddPrim(((int**)getScratchAddr(0))[1] + sp38, lineG2++);
    }

    tile = (TILE*)lineG2;
    elementCount = *(int*)var_s3;
    var_s3 += 4;

    for (i = 0; i < elementCount; ++i, var_s3 += 4) {

        sp3C = 0;
        *(void**)getScratchAddr(0) = tile;

        if ((var_s3[3] != 0) && (func_8010839C(var_s3[3], arg2, arg3) != 0)
            && (roomIndex == currentRoomIndex)) {

            func_80107630(var_s1[var_s3[0]][0], var_s1[var_s3[0]][1] - 0xE, var_s3[3]);

            tile = *(void**)getScratchAddr(0);
            sp3C = 1;
        }

        if (sp3C == 0) {
            if ((var_s3[2] & 4) && (roomIndex == currentRoomIndex)) {

                renderIcon(0, var_s1[var_s3[0]][0], var_s1[var_s3[0]][1] - 0xE);
                addMapLabel(var_s1[var_s3[0]][0], var_s1[var_s3[0]][1], 1, var_s3[1]);

                if ((roomIndex == isCurrentScene) && (i == vs_battle_doorEntered)) {
                    if (menuFramesCounter & 0x10) {
                        colorIn.r = 0xFF;
                        colorIn.g = 0;
                        colorIn.b = 0x80;
                        sp3C = 1;
                    }
                } else {
                    colorIn.r = 0;
                    colorIn.g = 0xC0;
                    colorIn.b = 0xC0;
                    sp3C = 1;
                }
            }

            if ((roomIndex == currentRoomIndex) && (var_s3[2] == 0)) {
                if ((roomIndex == isCurrentScene) && (i == vs_battle_doorEntered)) {
                    if (menuFramesCounter & 0x10) {
                        colorIn.r = 0xFF;
                        colorIn.g = 0;
                        colorIn.b = 0x80;
                        sp3C = 1;
                    }
                } else {
                    colorIn.r = 0xC0;
                    colorIn.g = 0xC0;
                    colorIn.b = 0xC0;
                    sp3C = 1;
                }
            }

            j = 0;

            if ((var_s3[2] & 0xB) && (roomIndex == isCurrentScene)) {
                sp28[j++] = 0;
            }

            if ((var_s3[2] & 2) && (roomIndex == currentRoomIndex)) {
                sp28[j++] = 1;
            }

            if ((var_s3[2] & 8) && (roomIndex == currentRoomIndex)) {
                sp28[j++] = 2;
                sp28[j++] = 1;
                sp28[j++] = 3;
            }

            if ((var_s3[2] & 0x10) && (roomIndex == currentRoomIndex)) {
                sp28[j++] = 3;
            }

            if (j > 0) {

                colorIn.r = 0xA0;
                colorIn.g = 0xA0;
                colorIn.b = 0;
                sp3C = 1;

                switch (sp28[(menuFramesCounter >> 5) % j]) {
                case 0:
                    renderDefaultIcon(0,
                        ((var_s1[var_s3[0]][0] - 8) & 0xFFFF)
                            | ((var_s1[var_s3[0]][1] << 16) + 0xFFF80000),
                        *((menuFramesCounter & 0xF) + (new_var = ashleyIconBrightness)),
                        ((void**)getScratchAddr(0))[1] + 32);
                    break;

                case 1:
                    renderIcon(2, var_s1[var_s3[0]][0], var_s1[var_s3[0]][1] - 0xE);
                    break;

                case 2:
                    renderIcon(1, var_s1[var_s3[0]][0], var_s1[var_s3[0]][1] - 0xE);
                    break;

                case 3:
                    renderIcon(3, var_s1[var_s3[0]][0], var_s1[var_s3[0]][1] - 0xE);
                    break;
                }
            }

            tile = *(void**)getScratchAddr(0);

            if (sp3C != 0) {
                int** s2;
                sp38 = var_s1[var_s3[0]][2] - 1;

                setTile(tile);
                setXY0(tile, var_s1[var_s3[0]][0] - 1, var_s1[var_s3[0]][1]);
                setWH(tile, 3, 1);
                setRGB0(tile, colorIn.r, colorIn.g, colorIn.b);

                AddPrim(((int**)getScratchAddr(0))[1] + sp38, tile++);

                setTile(tile);
                setXY0(tile, var_s1[var_s3[0]][0], var_s1[var_s3[0]][1] - 1);
                setWH(tile, 1, 3);
                setRGB0(tile, colorIn.r, colorIn.g, colorIn.b);

                s2 = ((int**)getScratchAddr(0));

                AddPrim(s2[1] + sp38, tile++);
            }
        }
    }

    *(void**)getScratchAddr(0) = tile;

    return 1;
}

static void snapMapToRoom(vs_battle_Scene* scene, int roomId)
{
    SVECTOR maxCorner;
    SVECTOR minCorner;
    int roomCount;
    int vertexCount;
    int i;
    int j;
    vs_battle_RoomVertices* roomVertices;
    SVECTOR* vector;
    u_int zSum;
    vs_battle_Room* room = scene->rooms;

    maxCorner.vx = 0x7FFF;
    maxCorner.vy = 0x7FFF;
    maxCorner.vz = 0x7FFF;
    minCorner.vx = -0x8000;
    minCorner.vy = -0x8000;
    minCorner.vz = -0x8000;

    roomVertices = room[roomId].dataAddress;
    roomCount = scene->roomCount;
    vertexCount = roomVertices->vertexCount;
    vector = roomVertices->vertices;

    for (i = 0; i < vertexCount; ++i, ++vector) {
        if (maxCorner.vx > vector->vx) {
            maxCorner.vx = vector->vx;
        }
        if (maxCorner.vy > vector->vy) {
            maxCorner.vy = vector->vy;
        }
        if (maxCorner.vz > vector->vz) {
            maxCorner.vz = vector->vz;
        }
        if (minCorner.vx < vector->vx) {
            minCorner.vx = vector->vx;
        }
        if (minCorner.vy < vector->vy) {
            minCorner.vy = vector->vy;
        }
        if (minCorner.vz < vector->vz) {
            minCorner.vz = vector->vz;
        }
    }

    centerPoint.vx = ((maxCorner.vx + minCorner.vx) / 2);
    zSum = maxCorner.vz + minCorner.vz;
    centerPoint.vz = (int)(zSum + ((u_int)zSum >> 0x1F)) >> 1;
    centerPoint.vy = minCorner.vy;

    for (j = 0; j < roomCount; ++j, ++room) {
        roomVertices = room->dataAddress;
        vertexCount = roomVertices->vertexCount;
        vector = (SVECTOR*)roomVertices;
        vector = (SVECTOR*)((short*)vector + 2);
        for (i = 0; i < vertexCount; ++i, ++vector) {
            vector->vx -= centerPoint.vx;
            vector->vy -= centerPoint.vy;
            vector->vz -= centerPoint.vz;
        }
    }
    centerPoint.vx = 0;
    centerPoint.vz = 0;
    centerPoint.vy = 0;
}

static void setCenterpoint(vs_battle_Scene* scene, int roomId)
{
    SVECTOR maxCorner;
    SVECTOR minCorner;
    int roomCount;
    int vertexCount;
    int i;
    vs_battle_RoomVertices* roomVertices;
    SVECTOR* vector;
    u_int zSum;
    vs_battle_Room* room = scene->rooms;

    maxCorner.vx = 0x7FFF;
    maxCorner.vy = 0x7FFF;
    maxCorner.vz = 0x7FFF;
    minCorner.vx = -0x8000;
    minCorner.vy = -0x8000;
    minCorner.vz = -0x8000;

    roomVertices = room[roomId].dataAddress;
    roomCount = scene->roomCount;
    vertexCount = roomVertices->vertexCount;
    vector = roomVertices->vertices;

    for (i = 0; i < vertexCount; ++i, ++vector) {
        if (maxCorner.vx > vector->vx) {
            maxCorner.vx = vector->vx;
        }
        if (maxCorner.vy > vector->vy) {
            maxCorner.vy = vector->vy;
        }
        if (maxCorner.vz > vector->vz) {
            maxCorner.vz = vector->vz;
        }
        if (minCorner.vx < vector->vx) {
            minCorner.vx = vector->vx;
        }
        if (minCorner.vy < vector->vy) {
            minCorner.vy = vector->vy;
        }
        if (minCorner.vz < vector->vz) {
            minCorner.vz = vector->vz;
        }
    }

    centerPoint.vx = ((maxCorner.vx + minCorner.vx) / 2);
    zSum = maxCorner.vz + minCorner.vz;
    centerPoint.vz = (int)(zSum + ((u_int)zSum >> 0x1F)) >> 1;
    centerPoint.vy = minCorner.vy;
}

static void smoothMapToCenterpoint(vs_battle_Scene* scene)
{
    SVECTOR svector;
    int coord;
    int roomCount;
    int vertexCount;
    int j;
    int i;
    vs_battle_RoomVertices* dataAddress;
    SVECTOR* vector;
    vs_battle_Room* room;

    if (centerPoint.vx == 0 && centerPoint.vy == 0 && centerPoint.vz == 0) {
        return;
    }

    coord = ABS(centerPoint.vx);

    if (coord < 8) {
        svector.vx = centerPoint.vx;
    } else {
        if (coord >= 0x81) {
            int var_v0 = centerPoint.vx;
            if (centerPoint.vx < 0) {
                var_v0 = centerPoint.vx + 7;
            }
            svector.vx = var_v0 >> 3;
        } else if (centerPoint.vx <= 0) {
            if (centerPoint.vx < 0) {
                svector.vx = -8;
            }
        } else {
            svector.vx = 8;
        }
    }

    coord = ABS(centerPoint.vy);

    if (coord < 8) {
        svector.vy = centerPoint.vy;
    } else {
        if (coord >= 0x81) {
            int var_v0 = centerPoint.vy;
            if (centerPoint.vy < 0) {
                var_v0 = centerPoint.vy + 7;
            }
            svector.vy = var_v0 >> 3;
        } else if (centerPoint.vy <= 0) {
            if (centerPoint.vy < 0) {
                svector.vy = -8;
            }
        } else {
            svector.vy = 8;
        }
    }

    coord = ABS(centerPoint.vz);

    if (coord < 8) {
        svector.vz = centerPoint.vz;
    } else {
        if (coord >= 0x81) {
            int var_v0 = centerPoint.vz;
            do {
                if (centerPoint.vz < 0) {
                    var_v0 = centerPoint.vz + 7;
                }
                svector.vz = var_v0 >> 3;
            } while (0);
        } else if (centerPoint.vz <= 0) {
            if (centerPoint.vz < 0) {
                svector.vz = -8;
            }
        } else {
            svector.vz = 8;
        }
    }

    room = scene->rooms;
    roomCount = scene->roomCount;

    for (i = 0; i < roomCount; ++i) {
        dataAddress = room->dataAddress;
        vertexCount = dataAddress->vertexCount;
        vector = (SVECTOR*)dataAddress;
        vector = dataAddress->vertices;
        for (j = 0; j < vertexCount; ++j) {
            vector->vx -= svector.vx;
            vector->vy -= svector.vy;
            vector->vz -= svector.vz;
            ++vector;
        }
        ++room;
    }
    centerPoint.vx -= svector.vx;
    centerPoint.vy -= svector.vy;
    centerPoint.vz -= svector.vz;
}

static void scaleRoomVertices(vs_battle_Scene* scene, int factor)
{
    SVECTOR* vector;
    int roomCount;
    int vertextCount;
    int j;
    int i;
    vs_battle_RoomVertices* roomVertices;
    vs_battle_Room* room;

    room = scene->rooms;
    roomCount = scene->roomCount;

    for (i = 0; i < roomCount; ++i) {
        roomVertices = room->dataAddress;
        vertextCount = roomVertices->vertexCount;
        vector = (SVECTOR*)roomVertices;
        vector = (SVECTOR*)((int*)vector + 1);
        for (j = 0; j < vertextCount; ++j) {
            vector->vx *= factor;
            vector->vy *= factor;
            vector->vz *= factor;
            ++vector;
        }
        ++room;
    }
}

static void buildYawMatrix(MATRIX* arg0, short arg1)
{
    int temp_s0 = rsin(-arg1);
    int temp_v0 = rcos(-arg1);

    arg0->m[0][0] = temp_v0;
    arg0->m[0][1] = 0;
    arg0->m[0][2] = -temp_s0;
    arg0->m[1][0] = 0;
    arg0->m[1][1] = 0x1000;
    arg0->m[1][2] = 0;
    arg0->m[2][0] = temp_s0;
    arg0->m[2][1] = 0;
    arg0->m[2][2] = temp_v0;
}

static void buildPitchMatrix(MATRIX* arg0, short arg1)
{
    int temp_s0 = rsin(arg1);
    int temp_v0 = rcos(arg1);

    arg0->m[0][0] = 0x1000;
    arg0->m[0][1] = 0;
    arg0->m[0][2] = 0;
    arg0->m[1][0] = 0;
    arg0->m[1][1] = temp_v0;
    arg0->m[1][2] = -temp_s0;
    arg0->m[2][0] = 0;
    arg0->m[2][1] = temp_s0;
    arg0->m[2][2] = temp_v0;
}

static void darkenBackground(void)
{
    SPRT* sprt;
    u_long* pScratch1;
    u_long* pScratch2;

    insertTPage(0x7FE, getTPage(0, 3, 0, 0));

    pScratch1 = getScratchAddr(0);
    sprt = (SPRT*)pScratch1[0];
    setSprt(sprt);
    setSemiTrans(sprt, 1);
    setShadeTex(sprt, 1);
    setXY0(sprt, 0, 0);
    setWH(sprt, 192, 240);
    setUV0(sprt, 0, 0);
    setClut(sprt, 0, 0);
    AddPrim((void*)(pScratch1[1] + 0x7FE * 4), sprt++);
    *getScratchAddr(0) = (u_long)sprt;

    if (vs_main_frameBuf != 0) {
        insertTPage(0x7FE, getTPage(2, 0, 320, 0));
    } else {
        insertTPage(0x7FE, getTPage(2, 0, 0, 0));
    }

    sprt = (SPRT*)*getScratchAddr(0);
    setSprt(sprt);
    setSemiTrans(sprt, 1);
    setShadeTex(sprt, 1);
    setXY0(sprt, 192, 0);
    setWH(sprt, 128, 240);
    setUV0(sprt, 0, 0);
    setClut(sprt, 0, 0);

    pScratch2 = getScratchAddr(0);
    AddPrim((void*)(pScratch2[1] + 0x7FE * 4), sprt++);
    pScratch2[0] = (u_long)sprt;

    if (vs_main_frameBuf != 0) {
        insertTPage(0x7FE, getTPage(2, 0, 512, 0));
    } else {
        insertTPage(0x7FE, getTPage(2, 0, 192, 0));
    }
}

static int getCurrentRoomIndex(vs_battle_Scene* scene)
{
    int i;

    int roomCount = scene->roomCount;
    vs_battle_Room* room = vs_battle_roomData.sectionF->rooms;
    int zoneId = room->zoneId;
    int mapId = room->mapId;
    room = scene->rooms;

    for (i = 0; i < roomCount; ++i, ++room) {
        if ((room->zoneId == zoneId) && (room->mapId == mapId)) {
            return isCurrentScene = i;
        }
    }

    room = scene->rooms;
    isCurrentScene = -1;
    mapId = 0;

    for (i = 0; i < roomCount; ++i, ++room) {
        if (room->visited != 0) {
            return i;
        }
    }
    return 0;
}

static void updateRoomIndex(int searchForward)
{
    int currentIndex = currentRoomIndex;
    vs_battle_Room* room = ((vs_battle_Scene*)vs_battle_sceneBuffer)->rooms;

    do {
        if (searchForward > 0) {
            currentRoomIndex = roomNamesTable[currentRoomIndex].next;
        } else {
            currentRoomIndex = roomNamesTable[currentRoomIndex].prev;
        }
    } while (room[currentRoomIndex].visited == 0);

    if (currentIndex != currentRoomIndex) {
        vs_main_playSfxDefault(0x7E, 0xB);
    }
}

static void applyPalingScreenEffect(void)
{
    int y;

    insertTPage(0x7FE, getTPage(0, 3, 0, 0));

    for (y = 0; y < 239; ++y) {
        int x;
        void** new_var;
        int v;
        SPRT* sprt = *(void**)getScratchAddr(0);

        setSprt(sprt);
        setSemiTrans(sprt, 1);
        setRGB0(sprt, 128, 128, 128);

        v = menuFramesCounter;
        new_var = (void**)getScratchAddr(0);

        if (y & 1) {
            x = rsin((menuFramesCounter + y) << 6);
            if (x < 0) {
                x += 127;
            }
            x = x >> 7;
        } else {
            x = rsin((menuFramesCounter + y) << 6);
            if (x < 0) {
                x += 127;
            }
            x = -(x >> 7);
        }

        setXY0(sprt, x, y);
        setWH(sprt, 192, 1);
        setUV0(sprt, 0, y);
        setClut(sprt, 0, 0);

        AddPrim(new_var[1] + 0x20, sprt++);

        new_var[0] = (void*)sprt;

        if (vs_main_frameBuf != 0) {
            insertTPage(8, getTPage(2, 0, 320, 0));
        } else {
            insertTPage(8, getTPage(2, 0, 0, 0));
        }

        sprt = *(void**)getScratchAddr(0);
        setSprt(sprt);
        setSemiTrans(sprt, 1);
        setRGB0(sprt, 128, 128, 128);

        if (y & 1) {
            x = rsin((menuFramesCounter + y) << 6);
            if (x < 0) {
                x += 127;
            }
            x = (x >> 7) + 192;
        } else {
            int offset;
            x = rsin((menuFramesCounter + y) << 6);
            offset = x >> 7;
            if (x < 0) {
                offset = (x + 127) >> 7;
            }
            x = 192 - offset;
        }

        setXY0(sprt, x, y);
        setWH(sprt, 128, 1);
        setUV0(sprt, 0, y);

        AddPrim(new_var[1] + 0x20, sprt++);

        new_var[0] = (void*)sprt;

        if (vs_main_frameBuf != 0) {
            insertTPage(8, getTPage(2, 0, 512, 0));
        } else {
            insertTPage(8, getTPage(2, 0, 192, 0));
        }
    }
}

static void drawUIControlsBackground(int x, int y, int w, int h)
{
    int i;
    int lineW;
    POLY_F4* poly;
    void** pScratch;
    LINE_G2* line = *(void**)getScratchAddr(0);

    for (i = y, lineW = w; i < (y + h - 1); ++i, --lineW) {
        setLineG2(line);
        setXY2(line, x, i, x + lineW - 1, i);
        setRGB0(line, 0x40, 0x38, 0x20);
        setRGB1(line, 0x10, 0x10, 8);
        AddPrim(*(int**)getScratchAddr(1) + 7, line++);
    }
    x += 2;
    y += 2;
    poly = (POLY_F4*)line;
    setPolyF4(poly);
    setXY4(poly, x, y, x + w - 1, y, x, y + h - 1, x + w - h, y + h - 1);
    setRGB0(poly, 0, 0, 0);
    pScratch = (void**)getScratchAddr(0);
    AddPrim(pScratch[1] + 28, poly++);
    pScratch[0] = (void*)poly;
}

static void drawUIControls(void)
{
    static int uiXOffset;

    vs_battle_TextBox* textBox = vs_battle_getTextBox(0);

    if (uiAnimationState == 0) {

        uiXOffset = -128;
        ++uiAnimationState;

    } else if (uiAnimationState == 1) {
        if (uiXOffset < 0) {

            uiXOffset += 16;

            if (textBox != NULL) {
                textBox->y -= 8;
                textBox->yIndent -= 8;
            }
        }
    } else if (uiAnimationState == 2) {
        if (uiXOffset >= -127) {

            uiXOffset -= 16;

            if (textBox != NULL) {
                textBox->y += 8;
                textBox->yIndent += 8;
            }
        }
    }

    if (triggerHideUi != 0) {
        return;
    }

    if (vs_main_stateFlags.mapPaling[currentScene] == 0) {
        int index = uiXOffset;
        void** s1 = (void**)0x1F800000;

        vs_mainmenu_renderButton(buttonIdL1, index + 8, 15, s1[1] + 24);
        vs_mainmenu_renderButton(buttonIdR1, uiXOffset + 64, 15, s1[1] + 24);
        vs_mainmenu_renderButton(buttonIdL2, uiXOffset + 8, 33, s1[1] + 24);
        vs_mainmenu_renderButton(buttonIdR2, uiXOffset + 8, 52, s1[1] + 24);
        vs_mainmenu_renderButton(buttonIdCircle, uiXOffset + 8, 70, s1[1] + 24);

        switch (menuCommandsState) {
        case 0: {
            int v = ((uiXOffset + 28) & 0xFFFF) | 0x120000;
            void** s0 = (void**)0x1F800000;

            vs_battle_renderTextRawColor(
                "BACK", v, vs_getRGB888(128, 128, 128), s0[1] + 24);
            vs_battle_renderTextRawColor("NEXT", vs_getXY(uiXOffset + 84, 18),
                vs_getRGB888(128, 128, 128), s0[1] + 24);
            vs_battle_renderTextRawColor("ROTATION", vs_getXY(uiXOffset + 28, 36),
                vs_getRGB888(128, 128, 128), s0[1] + 24);
            vs_battle_renderTextRawColor("ZOOM", vs_getXY(uiXOffset + 28, 54),
                vs_getRGB888(128, 128, 128), s0[1] + 24);
            vs_battle_renderTextRawColor("MENU", vs_getXY(uiXOffset + 28, 72),
                vs_getRGB888(128, 128, 128), s0[1] + 24);
            break;
        }

        case 1: {
            int v = ((uiXOffset + 28) & 0xFFFF) | 0x120000;
            void** s0 = (void**)0x1F800000;

            vs_battle_renderTextRawColor(
                "BACK", v, vs_getRGB888(128, 128, 128), s0[1] + 24);
            vs_battle_renderTextRawColor("NEXT", vs_getXY(uiXOffset + 84, 18),
                vs_getRGB888(128, 128, 128), s0[1] + 24);
            vs_battle_renderTextRawColor("ROTATION", vs_getXY(uiXOffset + 28, 36),
                vs_getRGB888(32, 32, 32), s0[1] + 24);
            vs_battle_renderTextRawColor("ZOOM", vs_getXY(uiXOffset + 28, 54),
                vs_getRGB888(32, 32, 32), s0[1] + 24);
            vs_battle_renderTextRawColor("MENU", vs_getXY(uiXOffset + 28, 72),
                vs_getRGB888(128, 128, 128), s0[1] + 24);
            break;
        }

        case 2: {
            int v = ((uiXOffset + 28) & 0xFFFF) | 0x120000;
            void** s0 = (void**)0x1F800000;

            vs_battle_renderTextRawColor("BACK", v, vs_getRGB888(32, 32, 32), s0[1] + 24);
            vs_battle_renderTextRawColor("NEXT", vs_getXY(uiXOffset + 84, 18),
                vs_getRGB888(32, 32, 32), s0[1] + 24);
            vs_battle_renderTextRawColor("ROTATION", vs_getXY(uiXOffset + 28, 36),
                vs_getRGB888(32, 32, 32), s0[1] + 24);
            vs_battle_renderTextRawColor("ZOOM", vs_getXY(uiXOffset + 28, 54),
                vs_getRGB888(128, 128, 128), s0[1] + 24);
            vs_battle_renderTextRawColor("MENU", vs_getXY(uiXOffset + 28, 72),
                vs_getRGB888(128, 128, 128), s0[1] + 24);
            break;
        }

        case 3: {
            int v = ((uiXOffset + 28) & 0xFFFF) | 0x120000;
            void** s0 = (void**)0x1F800000;

            vs_battle_renderTextRawColor("BACK", v, vs_getRGB888(32, 32, 32), s0[1] + 24);
            vs_battle_renderTextRawColor("NEXT", vs_getXY(uiXOffset + 84, 18),
                vs_getRGB888(32, 32, 32), s0[1] + 24);
            vs_battle_renderTextRawColor("ROTATION", vs_getXY(uiXOffset + 28, 36),
                vs_getRGB888(128, 128, 128), s0[1] + 24);
            vs_battle_renderTextRawColor("ZOOM", vs_getXY(uiXOffset + 28, 54),
                vs_getRGB888(32, 32, 32), s0[1] + 24);
            vs_battle_renderTextRawColor("MENU", vs_getXY(uiXOffset + 28, 72),
                vs_getRGB888(128, 128, 128), s0[1] + 24);
            break;
        }

        case 4: {
            int v = ((uiXOffset + 28) & 0xFFFF) | 0x120000;
            void** s0 = (void**)0x1F800000;

            vs_battle_renderTextRawColor("BACK", v, vs_getRGB888(32, 32, 32), s0[1] + 24);
            vs_battle_renderTextRawColor("NEXT", vs_getXY(uiXOffset + 84, 18),
                vs_getRGB888(32, 32, 32), s0[1] + 24);
            vs_battle_renderTextRawColor("ROTATION", vs_getXY(uiXOffset + 28, 36),
                vs_getRGB888(32, 32, 32), s0[1] + 24);
            vs_battle_renderTextRawColor("ZOOM", vs_getXY(uiXOffset + 28, 54),
                vs_getRGB888(32, 32, 32), s0[1] + 24);
            vs_battle_renderTextRawColor("MENU", vs_getXY(uiXOffset + 28, 72),
                vs_getRGB888(128, 128, 128), s0[1] + 24);
            break;
        }

        case 5: {
            int v = ((uiXOffset + 28) & 0xFFFF) | 0x120000;
            void** s0 = (void**)0x1F800000;

            vs_battle_renderTextRawColor("BACK", v, vs_getRGB888(32, 32, 32), s0[1] + 24);
            vs_battle_renderTextRawColor("NEXT", vs_getXY(uiXOffset + 84, 18),
                vs_getRGB888(32, 32, 32), s0[1] + 24);
            vs_battle_renderTextRawColor("ROTATION", vs_getXY(uiXOffset + 28, 36),
                vs_getRGB888(32, 32, 32), s0[1] + 24);
            vs_battle_renderTextRawColor("ZOOM", vs_getXY(uiXOffset + 28, 54),
                vs_getRGB888(32, 32, 32), s0[1] + 24);
            vs_battle_renderTextRawColor("MENU", vs_getXY(uiXOffset + 28, 72),
                vs_getRGB888(32, 32, 32), s0[1] + 24);
            break;
        }
        }

        drawUIControlsBackground(uiXOffset + 16, 18, 114, 12);
        drawUIControlsBackground(uiXOffset + 16, 36, 96, 12);
        drawUIControlsBackground(uiXOffset + 16, 54, 78, 12);
        drawUIControlsBackground(uiXOffset + 16, 72, 60, 12);

        insertTPage(7, getTPage(2, 0, 192, 0));

        renderCompass(62, 184, cameraAngles.vy);

    } else {
        vs_battle_renderTextRawColor("JAMMING", vs_getXY(uiXOffset + 28, 18),
            vs_getRGB888(128, 128, 128), *(void**)0x1F800004 + 24);
    }
}

static RECT iconRects[] = { { 104, 144, 18, 8 }, { 144, 216, 44, 7 }, { 128, 56, 22, 8 },
    { 218, 144, 36, 8 } };
static RECT D_80108D04[] = { { 160, 144, 16, 16 }, { 176, 144, 16, 16 } };
static RECT D_80108D14[] = { { 192, 144, 26, 8 }, { 216, 160, 39, 8 } };

static void renderIcon(int id, int x, int y)
{
    RECT* icon;
    void** scratch = (void**)getScratchAddr(0);
    POLY_FT4* poly = scratch[0];

    setPolyFT4(poly);
    setShadeTex(poly, 1);

    icon = &iconRects[id];

    setXY4(poly, x - icon->w / 2, y, icon->w + (x - icon->w / 2), y, x - icon->w / 2,
        y + 8, icon->w + (x - icon->w / 2), y + 8);
    setUV4(poly, icon->x, icon->y, icon->x + icon->w, icon->y, icon->x, icon->y + 8,
        icon->x + icon->w, icon->y + 8);
    setTPage(poly, 0, 0, 768, 0);
    setClut(poly, 848, 223);

    AddPrim(scratch[1] + 28, poly++);
    scratch[0] = poly;
}

static void func_80107630(int x, int y, int id)
{
    RECT* rect0;
    RECT* rect1;
    int temp;
    void** new_var = (void**)getScratchAddr(0);
    POLY_FT4* poly = new_var[0];
    int s6 = (id - 1);

    id = vs_main_stateFlags.unk33F[id] & 1;
    rect0 = &D_80108D04[id];

    setPolyFT4(poly);
    setShadeTex(poly, 1);
    setXY4(poly, x - (rect0->w / 2), y, rect0->w + (x - rect0->w / 2), y,
        x - (rect0->w / 2), rect0->h + y, rect0->w + (x - rect0->w / 2), rect0->h + y);
    setUV4(poly, rect0->x, rect0->y, rect0->x + rect0->w, rect0->y, rect0->x,
        rect0->y + rect0->h, rect0->x + rect0->w, rect0->y + rect0->h);
    setTPage(poly, 0, 0, 768, 0);
    setClut(poly, 976, 223);

    temp = s6 & 0x7F;

    AddPrim(new_var[1] + 28, poly++);

    y += rect0->h;
    rect1 = &D_80108D14[id];

    setPolyFT4(poly);
    setShadeTex(poly, 1);
    setXY4(poly, x - (rect1->w / 2), y, rect1->w + (x - rect1->w / 2), y,
        x - (rect1->w / 2), rect1->h + y, rect1->w + (x - rect1->w / 2), rect1->h + y);
    setUV4(poly, rect1->x, rect1->y, rect1->x + rect1->w, rect1->y, rect1->x,
        rect1->y + rect1->h, rect1->x + rect1->w, rect1->y + rect1->h);
    setTPage(poly, 0, 0, 768, 0);
    setClut(poly, 864, 223);

    AddPrim(new_var[1] + 28, poly++);

    new_var[0] = poly;

    addMapLabel(x, y, 0, temp);
}

/**
 * Renders the door name and line.
 */
static void renderDoorName(int x, int y, int doorId)
{
    int linePivotX;
    int xOffset = 186 - x;
    vs_battle_MenuItem* menuItem;

    if (xOffset < 0) {
        xOffset += 3;
    }

    linePivotX = xOffset >> 2;

    if (linePivotX >= 0) {
        linePivotX = 186 - linePivotX;
    } else {
        linePivotX = 186;
    }

    insertLine(x, y, linePivotX, mapLabelY + 8);
    insertLine(linePivotX, mapLabelY + 8, 194, mapLabelY + 8);

    menuItem =
        vs_battle_setMenuItem(0, 194, mapLabelY, 128, 0, (char*)&doors[doors[doorId]]);
    menuItem->backgroundWidth = 16;

    mapLabelY -= 16;

    vs_battle_renderMenuItem(menuItem);
    vs_battle_getMenuItem(0)->state = 0;
}

static void insertLine(int x0, int y0, int x1, int y1)
{
    u_long** p = (u_long**)getScratchAddr(0);
    LINE_F2* line = *(LINE_F2**)p;

    setLineF2(line);
    setXY2(line, x0, y0, x1, y1);
    setRGB0(line, 128, 128, 128);

    AddPrim(p[1] + 8, line++);

    p[0] = (u_long*)line;
}

static void renderCompass(int x, int y, int angle)
{
    int i;
    int uCoords[] = { 0x30, 0x40, 0x48, 0x38 };
    void** new_var2;
    void** new_var3;
    int v;
    int new_var4;

    POLY_FT4* poly = *(void**)0x1F800000;

    for (i = 0; i < 8; ++i) {

        computeRotatedRect(x, y, 43, 3, angle + (i * 256));

        setPolyFT4(poly);
        setSemiTrans(poly, 1);
        setShadeTex(poly, 1);

        new_var4 = 45;

        if (!(i & 3)) {
            v = 128;
            setUV4(poly, 2, v, new_var4, v, 2, 131, new_var4, 131);
        } else {
            v = 132;
            setUV4(poly, 2, v, new_var4, v, 2, 135, new_var4, 135);
        }

        setXY4(poly, compassBounds[0].x, compassBounds[0].y, compassBounds[1].x,
            compassBounds[1].y, compassBounds[2].x, compassBounds[2].y,
            compassBounds[3].x, compassBounds[3].y);
        setTPage(poly, 0, 1, 448, 256);
        setClut(poly, 960, 222);

        new_var3 = (void**)0x1F800000;

        AddPrim(new_var3[1] + 28, poly++);
    }

    computeRotatedRect(x, y, 39, 39, angle + 0x200);

    for (i = 0; i < 4; ++i) {

        setPolyFT4(poly);
        setShadeTex(poly, 1);
        setXY4(poly, compassBounds[i].x - 3, compassBounds[i].y - 3,
            compassBounds[i].x + 4, compassBounds[i].y - 3, compassBounds[i].x - 3,
            compassBounds[i].y + 4, compassBounds[i].x + 4, compassBounds[i].y + 4);
        setUV4(poly, uCoords[i], 128, uCoords[i] + 7, 128, uCoords[i], 135,
            uCoords[i] + 7, 135);
        setTPage(poly, 0, 0, 448, 256);

        if (i == 0) {
            setClut(poly, 960, 221);
        } else {
            setClut(poly, 1008, 220);
        }

        new_var3 = (void**)0x1F800000;

        AddPrim(new_var3[1] + 0x18, poly++);

        setPolyFT4(poly);
        setSemiTrans(poly, 1);
        setShadeTex(poly, 1);
        setXY4(poly, compassBounds[i].x - 6, compassBounds[i].y - 6,
            compassBounds[i].x + 7, compassBounds[i].y - 6, compassBounds[i].x - 6,
            compassBounds[i].y + 7, compassBounds[i].x + 7, compassBounds[i].y + 7);
        setUV4(poly, 1, 137, 14, 137, 1, 150, 14, 150);
        setTPage(poly, 0, 1, 448, 256);

        if (i == 0) {
            setClut(poly, 976, 222);
        } else {
            setClut(poly, 960, 222);
        }

        new_var3 = (void**)0x1F800000;

        AddPrim(new_var3[1] + 0x18, poly++);
    }

    computeRotatedRect(x, y, 15, 15, (angle - cameraAngles.vz) + 0x200);
    computeRotatedRect(
        compassBounds[0].x, compassBounds[0].y, 15, 17, angle - cameraAngles.vz);

    setPolyFT4(poly);
    setSemiTrans(poly, 1);
    setShadeTex(poly, 1);
    setXY4(poly, compassBounds[0].x, compassBounds[0].y, compassBounds[1].x,
        compassBounds[1].y, compassBounds[2].x, compassBounds[2].y,
        compassBounds[3].x, compassBounds[3].y);
    setUV4(poly, 0x14, 0x88, 0x23, 0x88, 0x14, 0x99, 0x23, 0x99);
    setTPage(poly, 0, 0, 448, 256);
    setClut(poly, 992, 222);

    new_var2 = (void**)0x1F800000;
    new_var3 = (void**)0x1F800000;

    AddPrim(new_var3[1] + 0x18, poly++);

    new_var2[0] = (void*)poly;
}

static void computeRotatedRect(int arg0, int arg1, int arg2, int arg3, int arg4)
{
    int i;
    int temp_s1 = rsin(arg4);
    int temp_v0 = rcos(arg4);

    compassBounds[0].x = (-arg2 * temp_v0) + (arg3 * temp_s1);
    compassBounds[0].y = (-arg3 * temp_v0) - (arg2 * temp_s1);
    compassBounds[1].x = (arg2 * temp_v0) + (arg3 * temp_s1);
    compassBounds[1].y = (-arg3 * temp_v0) + (arg2 * temp_s1);
    compassBounds[2].x = -compassBounds[1].x;
    compassBounds[2].y = -compassBounds[1].y;
    compassBounds[3].x = -compassBounds[0].x;
    compassBounds[3].y = -compassBounds[0].y;

    for (i = 0; i < 4; ++i) {
        compassBounds[i].x = compassBounds[i].x / ONE / 2;
        compassBounds[i].y = compassBounds[i].y / ONE / 2;
        compassBounds[i].x = compassBounds[i].x + arg0;
        compassBounds[i].y = compassBounds[i].y + arg1;
    }
}

/**
 * Renders the map name and line.
 */
static void renderConnectingMapName(int x, int y, int mapId)
{
    int linePivotX;
    vs_battle_MenuItem* menuItem;
    int areaVisited;
    int xOffset = 170 - x;

    if (xOffset < 0) {
        xOffset += 3;
    }

    linePivotX = xOffset >> 2;

    if (linePivotX < 0) {
        linePivotX = 170;
    } else {
        linePivotX = 170 - linePivotX;
    }

    insertLine(x, y, linePivotX, mapLabelY + 8);
    insertLine(linePivotX, mapLabelY + 8, 194, mapLabelY + 8);

    areaVisited = vs_main_mapStatus.areaFlags[mapId >> 5] & (1 << (mapId & 0x1F));

    if (!areaVisited) {
        mapId = VS_connectingMaps_INDEX_notVisited;
    }

    menuItem = vs_battle_setMenuItem(
        0, 178, mapLabelY, 144, 0, (char*)&connectingMaps[connectingMaps[mapId]]);
    menuItem->backgroundWidth = 8;

    mapLabelY -= 16;

    vs_battle_renderMenuItem(menuItem);
    vs_battle_getMenuItem(0)->state = 0;
}

static void addMapLabel(int x, int y, int type, int labelId)
{
    mapLabels[mapLabelCount].x = x;
    mapLabels[mapLabelCount].y = y;
    mapLabels[mapLabelCount].type = type;
    mapLabels[mapLabelCount].id = labelId;
    ++mapLabelCount;
}

static void renderMapLabels(void)
{
    int i;

    if ((menuCommandsState == 5) || (triggerHideUi != 0)) {
        return;
    }

    for (i = 0; i < mapLabelCount; ++i) {
        if (mapLabels[i].type == 0) {
            renderDoorName(mapLabels[i].x, mapLabels[i].y, mapLabels[i].id);
        }
    }

    for (i = 0; i < mapLabelCount; ++i) {
        if (mapLabels[i].type != 0) {
            renderConnectingMapName(
                mapLabels[i].x, mapLabels[i].y, mapLabels[i].id);
        }
    }
}

static int func_8010839C(int arg0, int arg1, int arg2)
{
    u_int temp_a2 = arg0 - 0x41;

    if ((temp_a2 < 7) && ((func_8008E7BC(arg1, arg2, temp_a2) != 0))) {
        return 0;
    }
    return vs_main_stateFlags.unk33F[arg0] < 2;
}
