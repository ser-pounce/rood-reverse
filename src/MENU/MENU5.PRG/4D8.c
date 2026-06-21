#include "4D8.h"
#include "src/SLUS_010.40/main.h"
#include "src/SLUS_010.40/31724.h"
#include "src/SLUS_010.40/32154.h"
#include "src/BATTLE/BATTLE.PRG/146C.h"
#include "src/BATTLE/BATTLE.PRG/2EA3C.h"
#include "src/BATTLE/BATTLE.PRG/573B8.h"
#include "src/BATTLE/BATTLE.PRG/5BF94.h"
#include "src/MENU/MAINMENU.PRG/C48.h"
#include "src/MENU/MAINMENU.PRG/2D10.h"
#include "src/MENU/MAINMENU.PRG/58EC.h"
#include "build/assets/MENU/MENU5.PRG/mapNames.h"
#include "build/assets/MENU/MENU5.PRG/connectingMaps.h"
#include "build/assets/MENU/MENU5.PRG/doors.h"
#include "build/assets/MENU/MENU5.PRG/paling.h"
#include "build/src/include/lbas.h"
#include "gpu.h"
#include "insertTPage.h"
#include <libetc.h>
#include <abs.h>

extern u_long* D_1F800000[];

static int _loadArmFile(void);
static int func_80103684(void);
static void _snapMapToRoom(vs_battle_scene* scene, int roomId);
static void _scaleRoomVertices(vs_battle_scene* scene, int factor);
static int _getCurrentRoomIndex(vs_battle_scene* scene);
static void _updateRoomIndex(int searchForward);
static void _setCenterpoint(vs_battle_scene* scene, int roomId);
static void _smoothMapToCenterpoint(vs_battle_scene* scene);
static void func_801042B0(void);
static void func_80104384(void);
static int func_8010451C(int arg0);
static void func_801046B0(vs_battle_scene* arg0);
static int _drawRoom(int arg0, void* arg1, int arg2, int arg3);
static void func_80106178(MATRIX* arg0, short arg1);
static void func_801061EC(MATRIX* arg0, short arg1);
static void _darkenBackground(void);
static void _applyPalingScreenEffect(void);

/**
 * Renders the map controls based on availability.
 */
static void _drawUIControls(void);
static void func_80107630(int x, int y, int arg2);

/**
 * Prepends a line to the ot at the top of the scratch memory.
 */
static void _insertLine(int x0, int y0, int x1, int y1);

static void func_80107B10(int arg0, int arg1, int arg2);
static void func_8010800C(int arg0, int arg1, int arg2, int arg3, int arg4);

/**
 * Adds a label to the label list.
 *
 * @param type 0 == door, 1 == connecting map.
 */
static void _addMapLabel(int x, int y, int type, int doorId);

/**
 * Enumerates and renders the map label list.
 */
static void renderMapLabels(void);

static int func_8010839C(int arg0, int arg1, int arg2);
static void _renderIcon(int id, int x, int y);

static void func_80102CD8(int arg0)
{
    if (arg0 != 0) {
        vs_mainMenu_setNextMenuAction(menuActionMenu);
        D_801022D6 = 0;
        return;
    }

    vs_mainMenu_setNextMenuAction(menuActionNone);
    D_801022D6 = 1;
}

/**
 * Renders icon from default texpage. In practice only used with
 * Ashley's current position icon == 0.
 */
static void _renderDefaultIcon(int id, int xy, int brightness, u_long* nextPrim)
{
    if (nextPrim == 0) {
        nextPrim = D_1F800000[2];
    }

    vs_battle_setSpriteDefaultTexPage(128, xy, vs_getWH(16, 16), nextPrim)[4] =
        ((id + 4) << 4) | (getClut(976, 223) << 16) | 0x8000;

    D_1F800000[0][-4] = (int)(brightness | 0x64000000);
}

static int D_801083F8 = -1;

static void func_80102D90(int rowCount, int arg1, char** strings)
{
    int rowTypes[rowCount];
    int i;
    int cursorMemory;

    if (D_801083F8 == -1) {
        D_801083F8 = arg1;
    }

    for (i = 0; i < rowCount; ++i) {
        rowTypes[i] = 0;
    }

    if (!(arg1 & 0x80)) {
        if (D_801083F8 < rowCount) {
            rowTypes[D_801083F8] |= 4;
        }
    }

    arg1 &= 0x7F;

    if ((rowCount < 9) || (arg1 < 8)) {
        D_800F4EE8.cursorMemories[0] = arg1;
        D_800F4EE8.cursorMemories[1] = 0;
    } else if (arg1 >= (rowCount - 8)) {
        D_800F4EE8.cursorMemories[0] = arg1 - (rowCount - 9);
        D_800F4EE8.cursorMemories[1] = rowCount - 9;
    } else {
        D_800F4EE8.cursorMemories[0] = 4;
        D_800F4EE8.cursorMemories[1] = arg1 - 4;
    }

    cursorMemory = vs_main_settings.cursorMemory;
    vs_main_settings.cursorMemory = 1;
    vs_mainmenu_setMenuRows(rowCount, 0x100, strings, rowTypes);
    vs_main_settings.cursorMemory = cursorMemory;
}

static int func_80102ED8(void)
{
    int row = vs_mainmenu_getSelectedRow();

    if (row < -1) {
        vs_mainMenu_clearMenuExcept(5);
    } else if (row >= 0) {
        vs_mainMenu_flyoutMenuRightAndHoistSelection(D_800F4EE8.cursorMemories[0], 1);
    }

    return row;
}

static void _setMenuItemMapName(char* mapName, char arg1)
{
    vs_battle_menuItem_t* menuItem = vs_battle_setMenuItem(10, 320, 34, 0x8C, 8, mapName);

    menuItem->state = 2;
    menuItem->targetPosition0 = 0xB4;
    menuItem->selected = 1;
    menuItem->unkA = arg1;
}

static void func_80102F8C(void) { vs_mainMenu_clearMenuExcept(5); }

static void _menuReady(void) { vs_mainmenu_ready(); }

static int _loadMapBackground(int arg0)
{
    static vs_main_CdQueueSlot* slot;
    static u_short* buf;
    static int state;

    if (arg0 != 0) {
        vs_main_CdFile cdFile;
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
            vs_battle_drawImage(vs_getXY(640, 256), buf + 256, vs_getWH(160, 240));
            func_80100414(-4, 0x80);
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

int vs_menu5_exec(char* state)
{
    static int D_80108D30;
    static int D_80108D34;
    static int D_80108D38;
    static u_long* D_80108D3C;
    static int _ __attribute__((unused));
    static RECT D_80108D44[2];

    switch (*state) {
    case 3:
        D_801083F8 = -1;
        D_80108D3C = vs_main_allocHeapR(0xB600);
        D_80108D44[0].x = 0x300;
        D_80108D44[0].y = 0xE3;
        D_80108D44[0].w = 0x100;
        D_80108D44[0].h = 1;
        (&D_80108D44[1])->x = 0x2A0;
        (&D_80108D44[1])->y = 0x100;
        (&D_80108D44[1])->w = 0x60;
        (&D_80108D44[1])->h = 0xF0;
        StoreImage(&D_80108D44[0], D_80108D3C);
        StoreImage(&D_80108D44[1], D_80108D3C + 0x80);
        _loadMapBackground(1);
        *state = 4;
        break;
    case 4:
        if (_loadMapBackground(0) == 0) {
            break;
        }
        *state = 5;
        func_800FFB68(1);
        D_80108D30 = 8;
        D_80108D34 = 0;
        // Fallthrough
    case 5:
        if (D_80108D34 == 0) {
            D_80108D34 = _loadArmFile();
        }
        if (D_80108D30 != 0) {
            --D_80108D30;
            break;
        } else if (D_80108D34 != 0) {
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
        D_80108D38 = func_80103684();
        if (D_80108D38 != 0) {
            func_80100414(-4, 0x80);
            func_800CB654(0);
            D_800EB9B0 = 0;
            func_8008A4DC(1);
            vs_mainMenu_setNextMenuAction(menuActionNone);
            vs_mainMenu_clearMenuExcept(vs_mainMenu_menuItemIds_none);
            D_80108D30 = 10;
            *state = 8;
        }
        break;
    case 8:
        func_800FFB68(0);
        *state = 9;
        break;
    case 9:
        if (D_801022D8 == 0) {
            D_80108D44[0].x = 0x280;
            D_80108D44[0].y = 0x100;
            D_80108D44[0].w = 0x20;
            D_80108D44[0].h = 0xF0;
            (&D_80108D44[1])->x = 0x300;
            (&D_80108D44[1])->y = 0x100;
            (&D_80108D44[1])->w = 0x20;
            (&D_80108D44[1])->h = 0xF0;
            ClearImage(D_80108D44, 0, 0, 0);
            ClearImage(&D_80108D44[1], 0, 0, 0);
            vs_main_loadClut((u_short*)D_80108D3C, 3, 0, 0x100);
            vs_battle_drawImage(0x010002A0, D_80108D3C + 0x80, 0xF00060);
            *state = 10;
        }
        break;
    case 10:
        if (D_80108D38 == 2) {
            vs_battle_menuState.currentState = 6;
        }
        vs_main_freeHeapR(D_80108D3C);
        D_801022D6 = 0;
        *state = 0;
        return 1;
    }
    return 0;
}

#include "src/MENU/unused_vertices.h"

vs_main_CdFile const _sceneArmFiles[] = { { VS_DUMMY_ARM_LBA, VS_DUMMY_ARM_SIZE },
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

int const D_80102C00[] = { 0x00404040, 0x00505050, 0x00606060, 0x00707070, 0x00808080,
    0x00808080, 0x00808080, 0x00808080, 0x00808080, 0x00808080, 0x00808080, 0x00808080,
    0x00707070, 0x00606060, 0x00505050, 0x00404040, 0x006B4100, 0x006C8219, 0x00663040,
    0x00203840, 0x00330500, 0x00262801, 0x00200808, 0x00081010 };

u_short _mapNames[] = {
#include "build/assets/MENU/MENU5.PRG/mapNames.vsString"
};

static int D_80108D60;
static int _currentRoomIndex;
static int D_80108D68;
static int D_80108D6C;
static int _geomOffsetX;
static int _geomOffsetY;
static int _isCurrentScene;
static int D_80108D7C;
static int _currentScene;
static int D_80108D84;
static int _isPaling;
static int D_80108D8C;
static int D_80108D90;
static int D_80108D94;
static vs_battle_roomName* _roomNamesTable;
static short _menuCommandsState;
static short D_80108D9E;
static short _1[2] __attribute__((unused));
static short D_80108DA4[4];
static short D_80108DAC[4];
static SVECTOR _centerPoint;
static vs_main_CdQueueSlot* _sceneCdQueueSlot;
static void* D_80108DC0;
static int D_80108DC4[32];
static int D_80108E44;
static int _mapLabelY;
static int _2[2] __attribute__((unused));

/**
 *
 *
 * @return True if arm file is loaded.
 */
static int _loadArmFile(void)
{

    vs_main_stateFlags.mapPaling[0] = 1;

    if (vs_battle_sceneBuffer == NULL) {
        int paling;

        if (vs_main_mapStatus.roomFlags[1] & 0x800000) {
            vs_main_mapStatus.roomFlags[1] |= 0x400000;
        }

        D_80108D8C = 0;
        D_80108D94 = 0;

        vs_main_bzero(D_80108DA4, sizeof D_80108DA4);
        vs_main_bzero(D_80108DAC, sizeof D_80108DAC);

        D_80108DA4[0] = 568;
        _currentRoomIndex = 0;
        D_80108DA4[2] = D_80108DA4[1] = 2048 - *(u_short*)getScratchAddr(22);

        _currentScene = vs_battle_getCurrentSceneId();

        if (_currentScene >= 32) {
            _currentScene = 0;
        }

        paling = vs_main_stateFlags.mapPaling[_currentScene];

        D_80108D90 = _currentScene;
        D_80108D60 = 0;
        D_80108D68 = 128;
        D_80108D6C = 0;
        _geomOffsetX = -384;
        _geomOffsetY = 0;
        D_80108E44 = 1;
        D_80108D7C = 768;
        _menuCommandsState = 5;
        D_80108D9E = 0;
        _isPaling = paling;

        vs_battle_sceneBuffer = vs_main_allocHeapR(_sceneArmFiles[_currentScene].size);
        _sceneCdQueueSlot = vs_main_allocateCdQueueSlot(&_sceneArmFiles[_currentScene]);
        vs_main_cdEnqueue(_sceneCdQueueSlot, vs_battle_sceneBuffer);

        return 0;
    }

    if (_sceneCdQueueSlot->state != vs_main_CdQueueStateLoaded) {
        return 0;
    }

    vs_main_freeCdQueueSlot(_sceneCdQueueSlot);

    _roomNamesTable = vs_battle_initSceneAndGetRoomNames(vs_battle_sceneBuffer);

    vs_battle_setRoomsUnk0(vs_battle_sceneBuffer);
    _scaleRoomVertices(vs_battle_sceneBuffer, 4);

    _currentRoomIndex = _getCurrentRoomIndex(vs_battle_sceneBuffer);

    _snapMapToRoom(vs_battle_sceneBuffer, _currentRoomIndex);
    SetFogNear(768, vs_main_projectionDistance);
    SetFarColor(0, 0, 0);
    _setMenuItemMapName((char*)&_mapNames[_mapNames[_currentScene]], 1);

    return 1;
}

static int func_80103684(void)
{
    int var_s2;
    int roomIndex;
    int new_var2;

    SetFarColor(0, 0, 0);

    _mapLabelY = 188;
    roomIndex = _currentRoomIndex;

    if (vs_main_buttonsPressed.all & PADselect) {
        D_80108D8C ^= 1;
    }

    if (vs_main_stateFlags.mapPaling[_currentScene] != 0) {
        func_80100414(0x7FE, 0x80);
    } else {
        func_80100414(0x7FE, (D_80108D68 + 0x80) / 2);
    }

    if (D_80108D60 != 1) {
        _menuCommandsState = 5;
    }

    switch (D_80108D60) {
    case 0:
        if (D_80108D68 > 32) {
            D_80108D68 -= 16;
            _geomOffsetX += 64;
        } else {
            vs_battle_initTextBox(0, 0, 60, 224, 16, 1, 60, 224);
            vs_battle_setTextBox(0, _roomNamesTable[_currentRoomIndex].name);
            ++D_80108D60;
        }

        func_801042B0();
        break;

    case 1:
        var_s2 = 0;

        if (D_80108D8C != D_80108D94) {
            D_80108D94 = D_80108D8C;
            func_80102CD8(D_80108D8C == 0);
        }

        if (vs_main_buttonsPressed.all & PADRright) {
            var_s2 = 5;

            vs_main_playSfxDefault(0x7E, 5);

            D_80108D60 = 2;

            if (D_80108D94 != 0) {
                D_80108D94 = 0;
                func_80102CD8(1);
            }

            func_8010451C(1);

        } else if (vs_main_buttonsPressed.all & (PADRup | PADRdown)) {

            vs_main_playSfxDefault(0x7E, 6);

            if (vs_main_buttonsPressed.all & PADRup) {
                D_80108E44 = 2;
            }

            D_80108D60 = 3;

            vs_battle_dismissTextBox(0);

        } else if (vs_main_stateFlags.mapPaling[_currentScene] != 0) {
            var_s2 = 5;
        } else {
            int lStickX;
            int lStickY;

            if ((lStickX = vs_main_stickPosBuf.lStickX - 128, ABS(lStickX)) > 64
                || (lStickY = vs_main_stickPosBuf.lStickY - 128, ABS(lStickY) > 64)) {

                var_s2 = 3;

                if ((vs_main_stickPosBuf.lStickX - 128) < -64) {
                    D_80108DA4[1] -= 64;
                } else if ((vs_main_stickPosBuf.lStickX - 128) > 64) {
                    D_80108DA4[1] += 64;
                }

                if ((vs_main_stickPosBuf.lStickY - 128) < -64) {
                    D_80108DA4[0] += 64;
                } else if ((vs_main_stickPosBuf.lStickY - 128) > 64) {
                    D_80108DA4[0] -= 64;
                }

                if (D_80108DA4[0] >= 0) {
                    if (D_80108DA4[0] > 1024) {
                        D_80108DA4[0] = 1024;
                    }
                } else {
                    D_80108DA4[0] = 0;
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
                            D_80108DA4[1] -= 64;
                        } else if ((vs_main_stickPosBuf.rStickX - 128) > 64) {
                            D_80108DA4[1] += 64;
                        }
                        if ((vs_main_stickPosBuf.rStickY - 128) < -64) {
                            D_80108DA4[0] += 64;
                        } else if ((vs_main_stickPosBuf.rStickY - 128) > 64) {
                            D_80108DA4[0] -= 64;
                        }
                        if (D_80108DA4[0] < 0) {
                            D_80108DA4[0] = 0;
                            // dummy assignment to break deduplication optimization around
                            // line 184
                        } else if ((lStickX = D_80108DA4[0]) > 1024) {
                            D_80108DA4[0] = 1024;
                        }
                    } else {
                        if (vs_main_buttonsPreviousState & PADLleft) {
                            D_80108DA4[1] -= 64;
                        } else if (vs_main_buttonsPreviousState & PADLright) {
                            D_80108DA4[1] += 64;
                        }
                        if ((vs_main_buttonsPreviousState & PADLdown)
                            && (D_80108DA4[0] > 0)) {
                            D_80108DA4[0] -= 64;
                        } else if ((vs_main_buttonsPreviousState & PADLup)
                                   && (D_80108DA4[0] < 1024)) {
                            D_80108DA4[0] += 64;
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
                            D_80108D7C -= 16;
                        } else if ((vs_main_stickPosBuf.rStickY - 128) > 64) {
                            D_80108D7C += 16;
                        }

                        if (D_80108D7C < 512) {
                            D_80108D7C = 512;
                        } else if (D_80108D7C > 1024) {
                            D_80108D7C = 1024;
                        }

                    } else {
                        if (vs_main_buttonsPreviousState & PADLup && (D_80108D7C > 512)) {
                            D_80108D7C -= 16;
                        } else if ((vs_main_buttonsPreviousState & PADLdown)
                                   && (D_80108D7C < 1024)) {
                            D_80108D7C += 16;
                        }
                    }
                } else if (vs_main_buttonsPreviousState & PADstart) {

                    _geomOffsetX = 0;
                    _geomOffsetY = 0;
                    D_80108D7C = 0x300;
                    D_80108DA4[0] = 0x238;
                    D_80108DA4[1] = 0x800 - *(u_short*)getScratchAddr(22);
                    _currentRoomIndex = _getCurrentRoomIndex(vs_battle_sceneBuffer);

                    _snapMapToRoom(vs_battle_sceneBuffer, _currentRoomIndex);

                } else {
                    int rstickX;
                    int rstickY;

                    if ((rstickX = vs_main_stickPosBuf.rStickX - 128, ABS(rstickX) > 64)
                        || (rstickY = vs_main_stickPosBuf.rStickY - 128,
                            ABS(rstickY) > 64)) {

                        if (rstickX < -64) {
                            _geomOffsetX -= 4;
                        } else if (rstickX > 64) {
                            _geomOffsetX += 4;
                        }

                        if ((vs_main_stickPosBuf.rStickY - 128) < -64) {
                            _geomOffsetY -= 4;
                        } else if ((vs_main_stickPosBuf.rStickY - 128) > 64) {
                            _geomOffsetY += 4;
                        }

                        if (_geomOffsetY < -80) {
                            _geomOffsetY = -80;
                        } else if (_geomOffsetY > 80) {
                            _geomOffsetY = 80;
                        }

                        if (_geomOffsetX < -96) {
                            _geomOffsetX = -96;
                        } else if (_geomOffsetX > 96) {
                            _geomOffsetX = 96;
                        }

                    } else {
                        if ((vs_main_buttonsPreviousState & PADLup)
                            && (_geomOffsetY > -80)) {
                            _geomOffsetY -= 4;
                        } else if ((vs_main_buttonsPreviousState & PADLdown)
                                   && (_geomOffsetY < 80)) {
                            _geomOffsetY += 4;
                        }

                        if ((vs_main_buttonsPreviousState & PADLleft)
                            && (_geomOffsetX > -96)) {
                            _geomOffsetX -= 4;
                        } else if ((vs_main_buttonsPreviousState & PADLright)
                                   && (_geomOffsetX < 96)) {
                            _geomOffsetX += 4;
                        }
                    }

                    if ((vs_main_buttonsPreviousState & (PADL1 | PADR1))
                        != (PADL1 | PADR1)) {

                        if (vs_main_buttonRepeat & 8) {
                            _updateRoomIndex(1);
                            _setCenterpoint(vs_battle_sceneBuffer, _currentRoomIndex);
                        } else if (vs_main_buttonRepeat & 4) {
                            _updateRoomIndex(-1);
                            _setCenterpoint(vs_battle_sceneBuffer, _currentRoomIndex);
                        }
                    }

                    if (roomIndex != _currentRoomIndex) {
                        vs_battle_setTextBox(0, _roomNamesTable[_currentRoomIndex].name);
                    }
                }
            }
        }

        _menuCommandsState = var_s2;

        func_801042B0();
        break;

    case 2:
        func_801042B0();

        D_80108D84 = new_var2 = func_8010451C(0);

        if (new_var2 == -1) {
            break;
        } else if (new_var2 == -3) {

            D_80108D60 = 3;
            D_80108E44 = 2;

            vs_battle_dismissTextBox(0);

        } else if (new_var2 == -2) {
            D_80108D60 = 1;

            _setMenuItemMapName(
                (char*)&_mapNames[_mapNames[_currentScene]], _currentScene == D_80108D90);
        } else {

            _isPaling = vs_main_stateFlags.mapPaling[_currentScene];
            _currentScene = D_80108DC4[new_var2];
            D_80108D60 = 4;

            D_80108DC0 = vs_main_allocHeapR(_sceneArmFiles[_currentScene].size);
            _sceneCdQueueSlot =
                vs_main_allocateCdQueueSlot(&_sceneArmFiles[_currentScene]);
            vs_main_cdEnqueue(_sceneCdQueueSlot, D_80108DC0);
        }
        break;

    case 3:
        D_80108D9E = 2;

        if (D_80108D68 >= 128) {
            vs_main_freeHeapR(vs_battle_sceneBuffer);

            vs_battle_sceneBuffer = NULL;
            return D_80108E44;
        }

        D_80108D68 += 16;
        _geomOffsetX += 64;

        func_801042B0();
        break;

    case 4:
        _geomOffsetX += 64;

        if ((_sceneCdQueueSlot->state == 4) && (_geomOffsetX >= 0x180)) {

            _isPaling = 0;

            vs_main_freeCdQueueSlot(_sceneCdQueueSlot);
            vs_main_freeHeapR(vs_battle_sceneBuffer);

            vs_battle_sceneBuffer =
                vs_main_allocHeapR(_sceneArmFiles[_currentScene].size);

            vs_main_memcpy(
                vs_battle_sceneBuffer, D_80108DC0, _sceneArmFiles[_currentScene].size);
            vs_main_freeHeapR(D_80108DC0);

            _roomNamesTable = vs_battle_initSceneAndGetRoomNames(vs_battle_sceneBuffer);

            vs_battle_setRoomsUnk0(vs_battle_sceneBuffer);
            _scaleRoomVertices(vs_battle_sceneBuffer, 4);

            _currentRoomIndex = _getCurrentRoomIndex(vs_battle_sceneBuffer);

            _snapMapToRoom(vs_battle_sceneBuffer, _currentRoomIndex);
            vs_battle_setTextBox(0, _roomNamesTable[_currentRoomIndex].name);

            _geomOffsetX = -384;
            _geomOffsetY = 0;
            D_80108D60 = 5;
        }

        func_801042B0();
        break;

    case 5:
        _geomOffsetX += 64;

        if (_geomOffsetX >= 0) {
            D_80108D60 = 1;
        }

        func_801042B0();
        break;
    }

    ++D_80108D6C;

    _smoothMapToCenterpoint(vs_battle_sceneBuffer);

    return 0;
}

static u_short _connectingMaps[] = {
#include "build/assets/MENU/MENU5.PRG/connectingMaps.vsString"
};
static u_short _doors[] = {
#include "build/assets/MENU/MENU5.PRG/doors.vsString"
};

static void func_801042B0(void)
{
    static u_short _paling[] = {
#include "build/assets/MENU/MENU5.PRG/paling.vsString"
    };

    DR_STP* stp;
    void** pScratch = (void**)getScratchAddr(0);
    vs_main_flags_t* flags;
    int scene;

    _drawUIControls();

    stp = (DR_STP*)(pScratch[0]);

    SetDrawStp(stp, 1);
    AddPrim((DR_STP*)(pScratch[1] + 0x1FFC), stp++);

    flags = &vs_main_stateFlags;
    scene = _currentScene;

    do {
    } while (0);

    *(DR_STP**)pScratch = stp;

    if (flags->mapPaling[scene] != 0) {
        _applyPalingScreenEffect();
        vs_battle_setTextBox(0, (char*)&_paling[_paling[0]]);
        return;
    }

    func_80104384();
    _darkenBackground();

    if (_isPaling == 0) {
        func_801046B0(vs_battle_sceneBuffer);
    }
}

static void func_80104384(void)
{
    SVECTOR sp10;
    MATRIX sp18;
    MATRIX sp38;
    int temp_s0;
    int temp_v1;
    int var_v0;
    short* new_var;

    temp_s0 = rsin(D_80108DA4[1]);
    temp_v1 = rcos(D_80108DA4[0]);
    new_var = D_80108DAC;
    temp_s0 *= D_80108D7C;
    if (temp_s0 < 0) {
        temp_s0 += 0xFFF;
    }
    var_v0 = (temp_s0 >> 0xC) * temp_v1;
    if (var_v0 < 0) {
        var_v0 += 0xFFF;
    }
    D_80108DAC[0] = var_v0 >> 0xC;
    temp_s0 = rcos(D_80108DA4[1]);
    temp_v1 = rcos(D_80108DA4[0]);
    temp_s0 *= -D_80108D7C;
    if (temp_s0 < 0) {
        temp_s0 += 0xFFF;
    }
    var_v0 = (temp_s0 >> 0xC) * temp_v1;
    if (var_v0 < 0) {
        var_v0 += 0xFFF;
    }
    D_80108DAC[2] = var_v0 >> 0xC;
    var_v0 = rsin(D_80108DA4[0]) * -D_80108D7C;
    if (var_v0 < 0) {
        var_v0 += 0xFFF;
    }
    D_80108DAC[1] = var_v0 >> 0xC;
    func_80106178(&sp18, D_80108DA4[1]);
    func_801061EC(&sp38, D_80108DA4[0]);
    func_80041C68(&sp38, &sp18);
    sp10.vx = -new_var[0];
    sp10.vy = -new_var[1];
    sp10.vz = -new_var[2];
    ApplyMatrix(&sp18, &sp10, (VECTOR*)sp38.t);
    SetRotMatrix(&sp18);
    SetTransMatrix(&sp38);
}

static int func_8010451C(int arg0)
{
    static int D_80108D54;
    static int D_80108D58;

    char* sp10[64];
    int var_a0;
    int var_a1;
    int i;
    int areaVisited;

    if (arg0 != 0) {
        D_80108D54 = 0;
        D_80108D58 = 0;
    }
    switch (D_80108D54) {
    case 0:
        var_a1 = 0;
        for (i = 1, var_a0 = 0; i < 32; ++i) {
            areaVisited = vs_main_mapStatus.areaFlags[i >> 5] & (1 << (i & 0x1F));
            if (areaVisited) {
                D_80108DC4[var_a0] = i;
                sp10[var_a0 * 2] = (char*)&_mapNames[_mapNames[i]];
                sp10[var_a0 * 2 + 1] = 0;
                if (_currentScene == i) {
                    var_a1 = var_a0;
                }
                ++var_a0;
            }
        }
        if (var_a0 == 0) {
            return -2;
        }
        if (D_80108D90 == 0) {
            var_a1 = 0x80;
        }
        func_80102D90(var_a0, var_a1, sp10);
        ++D_80108D54;
        break;
    case 1:
        D_80108D58 = func_80102ED8();
        if (D_80108D58 == -1) {
            break;
        }
        return D_80108D58;
    }
    return -1;
}

static void func_8010467C(int* arg0)
{
    int temp_a0;
    int i;
    int* var_a1;

    var_a1 = arg0 + 1;
    temp_a0 = *arg0;

    for (i = 0; i < temp_a0; ++i) {
        *var_a1 = 1;
        var_a1 += 3;
    }
}

typedef struct {
    short x;
    short y;
    short type;
    short doorId;
} mapLabel;

static int D_80108E54[4][2];
static mapLabel _mapLabels[8];
static int _mapLabelCount;

static void func_801046B0(vs_battle_scene* arg0)
{
    vs_battle_geomOffset prevOffset;
    vs_battle_geomOffset tmpOffset;
    int roomCount;
    int i;
    vs_battle_room* room;
    int* new_var;

    tmpOffset.x = _geomOffsetX + 0x90;
    tmpOffset.y = _geomOffsetY + 0x88;
    vs_battle_getGeomOffset(&prevOffset);
    vs_battle_setGeomOffset(&tmpOffset);
    _mapLabelCount = 0;
    new_var = &arg0->roomCount;
    roomCount = *new_var;
    room = (vs_battle_room*)arg0;
    room = (vs_battle_room*)((int*)room + 1);
    for (i = 0; i < roomCount; ++i, ++room) {
        if (room->visited != 0) {
            _drawRoom(i, room->dataAddress, room->zoneId, room->mapId);
        }
    }
    renderMapLabels();
    vs_battle_setGeomOffset(&prevOffset);
}

static int _drawRoom(int roomIndex, void* roomData, int arg2, int arg3)
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

    short(*var_s1)[4] = (void*)getScratchAddr(64);
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
    if (roomIndex == _currentRoomIndex) {
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

        if (roomIndex == _currentRoomIndex) {
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
        if (roomIndex == _currentRoomIndex) {
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
            && (roomIndex == _currentRoomIndex)) {
            func_80107630(var_s1[var_s3[0]][0], var_s1[var_s3[0]][1] - 0xE, var_s3[3]);
            tile = *(void**)getScratchAddr(0);
            sp3C = 1;
        }

        if (sp3C == 0) {
            if ((var_s3[2] & 4) && (roomIndex == _currentRoomIndex)) {

                _renderIcon(0, var_s1[var_s3[0]][0], var_s1[var_s3[0]][1] - 0xE);
                _addMapLabel(var_s1[var_s3[0]][0], var_s1[var_s3[0]][1], 1, var_s3[1]);

                if ((roomIndex == _isCurrentScene) && (i == vs_battle_doorEntered)) {
                    if (D_80108D6C & 0x10) {
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

            if ((roomIndex == _currentRoomIndex) && (var_s3[2] == 0)) {
                if ((roomIndex == _isCurrentScene) && (i == vs_battle_doorEntered)) {
                    if (D_80108D6C & 0x10) {
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
            if ((var_s3[2] & 0xB) && (roomIndex == _isCurrentScene)) {
                sp28[j++] = 0;
            }
            if ((var_s3[2] & 2) && (roomIndex == _currentRoomIndex)) {
                sp28[j++] = 1;
            }
            if ((var_s3[2] & 8) && (roomIndex == _currentRoomIndex)) {
                sp28[j++] = 2;
                sp28[j++] = 1;
                sp28[j++] = 3;
            }
            if ((var_s3[2] & 0x10) && (roomIndex == _currentRoomIndex)) {
                sp28[j++] = 3;
            }
            if (j > 0) {
                colorIn.r = 0xA0;
                colorIn.g = 0xA0;
                colorIn.b = 0;
                sp3C = 1;
                switch (sp28[(D_80108D6C >> 5) % j]) {
                case 0:
                    _renderDefaultIcon(0,
                        ((var_s1[var_s3[0]][0] - 8) & 0xFFFF)
                            | ((var_s1[var_s3[0]][1] << 16) + 0xFFF80000),
                        *((D_80108D6C & 0xF) + (new_var = D_80102C00)),
                        ((void**)getScratchAddr(0))[1] + 32);
                    break;
                case 1:
                    _renderIcon(2, var_s1[var_s3[0]][0], var_s1[var_s3[0]][1] - 0xE);
                    break;
                case 2:
                    _renderIcon(1, var_s1[var_s3[0]][0], var_s1[var_s3[0]][1] - 0xE);
                    break;
                case 3:
                    _renderIcon(3, var_s1[var_s3[0]][0], var_s1[var_s3[0]][1] - 0xE);
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

static void _snapMapToRoom(vs_battle_scene* scene, int roomId)
{
    SVECTOR maxCorner;
    SVECTOR minCorner;
    int roomCount;
    int vertexCount;
    int i;
    int j;
    vs_battle_roomVertices* roomVertices;
    SVECTOR* vector;
    u_int zSum;
    vs_battle_room* room = scene->rooms;

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

    _centerPoint.vx = ((maxCorner.vx + minCorner.vx) / 2);
    zSum = maxCorner.vz + minCorner.vz;
    _centerPoint.vz = (int)(zSum + ((u_int)zSum >> 0x1F)) >> 1;
    _centerPoint.vy = minCorner.vy;

    for (j = 0; j < roomCount; ++j, ++room) {
        roomVertices = room->dataAddress;
        vertexCount = roomVertices->vertexCount;
        vector = (SVECTOR*)roomVertices;
        vector = (SVECTOR*)((short*)vector + 2);
        for (i = 0; i < vertexCount; ++i, ++vector) {
            vector->vx -= _centerPoint.vx;
            vector->vy -= _centerPoint.vy;
            vector->vz -= _centerPoint.vz;
        }
    }
    _centerPoint.vx = 0;
    _centerPoint.vz = 0;
    _centerPoint.vy = 0;
}

static void _setCenterpoint(vs_battle_scene* scene, int roomId)
{
    SVECTOR maxCorner;
    SVECTOR minCorner;
    int roomCount;
    int vertexCount;
    int i;
    vs_battle_roomVertices* roomVertices;
    SVECTOR* vector;
    u_int zSum;
    vs_battle_room* room = scene->rooms;

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

    _centerPoint.vx = ((maxCorner.vx + minCorner.vx) / 2);
    zSum = maxCorner.vz + minCorner.vz;
    _centerPoint.vz = (int)(zSum + ((u_int)zSum >> 0x1F)) >> 1;
    _centerPoint.vy = minCorner.vy;
}

static void _smoothMapToCenterpoint(vs_battle_scene* scene)
{
    SVECTOR svector;
    int coord;
    int roomCount;
    int vertexCount;
    int j;
    int i;
    vs_battle_roomVertices* dataAddress;
    SVECTOR* vector;
    vs_battle_room* room;

    if (_centerPoint.vx == 0 && _centerPoint.vy == 0 && _centerPoint.vz == 0) {
        return;
    }

    coord = ABS(_centerPoint.vx);

    if (coord < 8) {
        svector.vx = _centerPoint.vx;
    } else {
        if (coord >= 0x81) {
            int var_v0 = _centerPoint.vx;
            if (_centerPoint.vx < 0) {
                var_v0 = _centerPoint.vx + 7;
            }
            svector.vx = var_v0 >> 3;
        } else if (_centerPoint.vx <= 0) {
            if (_centerPoint.vx < 0) {
                svector.vx = -8;
            }
        } else {
            svector.vx = 8;
        }
    }

    coord = ABS(_centerPoint.vy);

    if (coord < 8) {
        svector.vy = _centerPoint.vy;
    } else {
        if (coord >= 0x81) {
            int var_v0 = _centerPoint.vy;
            if (_centerPoint.vy < 0) {
                var_v0 = _centerPoint.vy + 7;
            }
            svector.vy = var_v0 >> 3;
        } else if (_centerPoint.vy <= 0) {
            if (_centerPoint.vy < 0) {
                svector.vy = -8;
            }
        } else {
            svector.vy = 8;
        }
    }

    coord = ABS(_centerPoint.vz);

    if (coord < 8) {
        svector.vz = _centerPoint.vz;
    } else {
        if (coord >= 0x81) {
            int var_v0 = _centerPoint.vz;
            do {
                if (_centerPoint.vz < 0) {
                    var_v0 = _centerPoint.vz + 7;
                }
                svector.vz = var_v0 >> 3;
            } while (0);
        } else if (_centerPoint.vz <= 0) {
            if (_centerPoint.vz < 0) {
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
    _centerPoint.vx -= svector.vx;
    _centerPoint.vy -= svector.vy;
    _centerPoint.vz -= svector.vz;
}

static void _scaleRoomVertices(vs_battle_scene* scene, int factor)
{
    SVECTOR* vector;
    int roomCount;
    int vertextCount;
    int j;
    int i;
    vs_battle_roomVertices* roomVertices;
    vs_battle_room* room;

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

static void func_80106178(MATRIX* arg0, short arg1)
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

static void func_801061EC(MATRIX* arg0, short arg1)
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

static void _darkenBackground(void)
{
    SPRT* sprt;
    u_long* pScratch1;
    u_long* pScratch2;

    _insertTPage(0x7FE, getTPage(0, 3, 0, 0));

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
        _insertTPage(0x7FE, getTPage(2, 0, 320, 0));
    } else {
        _insertTPage(0x7FE, getTPage(2, 0, 0, 0));
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
        _insertTPage(0x7FE, getTPage(2, 0, 512, 0));
    } else {
        _insertTPage(0x7FE, getTPage(2, 0, 192, 0));
    }
}

static int _getCurrentRoomIndex(vs_battle_scene* scene)
{
    int i;

    int roomCount = scene->roomCount;
    vs_battle_room* room = vs_battle_roomData.sectionF->rooms;
    int zoneId = room->zoneId;
    int mapId = room->mapId;
    room = scene->rooms;

    for (i = 0; i < roomCount; ++i, ++room) {
        if ((room->zoneId == zoneId) && (room->mapId == mapId)) {
            return _isCurrentScene = i;
        }
    }

    room = scene->rooms;
    _isCurrentScene = -1;
    mapId = 0;

    for (i = 0; i < roomCount; ++i, ++room) {
        if (room->visited != 0) {
            return i;
        }
    }
    return 0;
}

static void _updateRoomIndex(int searchForward)
{
    int currentIndex = _currentRoomIndex;
    vs_battle_room* room = ((vs_battle_scene*)vs_battle_sceneBuffer)->rooms;

    do {
        if (searchForward > 0) {
            _currentRoomIndex = _roomNamesTable[_currentRoomIndex].next;
        } else {
            _currentRoomIndex = _roomNamesTable[_currentRoomIndex].prev;
        }
    } while (room[_currentRoomIndex].visited == 0);

    if (currentIndex != _currentRoomIndex) {
        vs_main_playSfxDefault(0x7E, 0xB);
    }
}

static void _applyPalingScreenEffect(void)
{
    int y;

    _insertTPage(0x7FE, getTPage(0, 3, 0, 0));

    for (y = 0; y < 239; ++y) {
        int x;
        void** new_var;
        int v;
        SPRT* sprt = *(void**)getScratchAddr(0);

        setSprt(sprt);
        setSemiTrans(sprt, 1);
        setRGB0(sprt, 128, 128, 128);

        v = D_80108D6C;
        new_var = (void**)getScratchAddr(0);

        if (y & 1) {
            x = rsin((D_80108D6C + y) << 6);
            if (x < 0) {
                x += 127;
            }
            x = x >> 7;
        } else {
            x = rsin((D_80108D6C + y) << 6);
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
            _insertTPage(8, getTPage(2, 0, 320, 0));
        } else {
            _insertTPage(8, getTPage(2, 0, 0, 0));
        }

        sprt = *(void**)getScratchAddr(0);
        setSprt(sprt);
        setSemiTrans(sprt, 1);
        setRGB0(sprt, 128, 128, 128);

        if (y & 1) {
            x = rsin((D_80108D6C + y) << 6);
            if (x < 0) {
                x += 127;
            }
            x = (x >> 7) + 192;
        } else {
            int offset;
            x = rsin((D_80108D6C + y) << 6);
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
            _insertTPage(8, getTPage(2, 0, 512, 0));
        } else {
            _insertTPage(8, getTPage(2, 0, 192, 0));
        }
    }
}

static void _drawUIControlsBackground(int x, int y, int w, int h)
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

static void _drawUIControls(void)
{
    static int uiXOffset;

    vs_battle_textBox* textBox = vs_battle_getTextBox(0);

    if (D_80108D9E == 0) {

        uiXOffset = -128;
        ++D_80108D9E;

    } else if (D_80108D9E == 1) {
        if (uiXOffset < 0) {

            uiXOffset += 16;

            if (textBox != NULL) {
                textBox->y -= 8;
                textBox->yIndent -= 8;
            }
        }
    } else if (D_80108D9E == 2) {
        if (uiXOffset >= -127) {

            uiXOffset -= 16;

            if (textBox != NULL) {
                textBox->y += 8;
                textBox->yIndent += 8;
            }
        }
    }

    if (D_80108D8C != 0) {
        return;
    }

    if (vs_main_stateFlags.mapPaling[_currentScene] == 0) {
        int index = uiXOffset;
        void** s1 = (void**)0x1F800000;

        vs_mainmenu_drawButton(4, index + 8, 15, s1[1] + 24);
        vs_mainmenu_drawButton(5, uiXOffset + 64, 15, s1[1] + 24);
        vs_mainmenu_drawButton(6, uiXOffset + 8, 33, s1[1] + 24);
        vs_mainmenu_drawButton(7, uiXOffset + 8, 52, s1[1] + 24);
        vs_mainmenu_drawButton(2, uiXOffset + 8, 70, s1[1] + 24);

        switch (_menuCommandsState) {
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

        _drawUIControlsBackground(uiXOffset + 16, 18, 114, 12);
        _drawUIControlsBackground(uiXOffset + 16, 36, 96, 12);
        _drawUIControlsBackground(uiXOffset + 16, 54, 78, 12);
        _drawUIControlsBackground(uiXOffset + 16, 72, 60, 12);

        _insertTPage(7, getTPage(2, 0, 192, 0));

        func_80107B10(0x3E, 0xB8, D_80108DA4[1]);

    } else {
        vs_battle_renderTextRawColor("JAMMING", vs_getXY(uiXOffset + 28, 18),
            vs_getRGB888(128, 128, 128), *(void**)0x1F800004 + 24);
    }
}

static RECT _iconRects[] = { { 104, 144, 18, 8 }, { 144, 216, 44, 7 }, { 128, 56, 22, 8 },
    { 218, 144, 36, 8 } };
static RECT D_80108D04[] = { { 160, 144, 16, 16 }, { 176, 144, 16, 16 } };
static RECT D_80108D14[] = { { 192, 144, 26, 8 }, { 216, 160, 39, 8 } };

/**
 * Renders icons that require size control, unlike _renderDefaultIcon.
 */
static void _renderIcon(int id, int x, int y)
{
    RECT* icon;
    void** scratch = (void**)getScratchAddr(0);
    POLY_FT4* poly = scratch[0];

    setPolyFT4(poly);
    setShadeTex(poly, 1);

    icon = &_iconRects[id];

    setXY4(poly, x - icon->w / 2, y, icon->w + (x - icon->w / 2), y, x - icon->w / 2,
        y + 8, icon->w + (x - icon->w / 2), y + 8);
    setUV4(poly, icon->x, icon->y, icon->x + icon->w, icon->y, icon->x, icon->y + 8,
        icon->x + icon->w, icon->y + 8);
    setTPage(poly, 0, 0, 768, 0);
    setClut(poly, 848, 223);

    AddPrim(scratch[1] + 28, poly++);
    scratch[0] = poly;
}

static void func_80107630(int x, int y, int arg2)
{
    RECT* rect0;
    RECT* rect1;
    int temp;
    void** new_var = (void**)getScratchAddr(0);
    POLY_FT4* poly = new_var[0];

    int s6 = (arg2 - 1);
    arg2 = vs_main_stateFlags.unk33F[arg2] & 1;
    rect0 = &D_80108D04[arg2];

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
    rect1 = &D_80108D14[arg2];

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
    _addMapLabel(x, y, 0, temp);
}

/**
 * Renders the door name and line.
 */
static void _renderDoorName(int x, int y, int doorId)
{
    int linePivotX;
    int xOffset = 186 - x;
    vs_battle_menuItem_t* menuItem;

    if (xOffset < 0) {
        xOffset += 3;
    }

    linePivotX = xOffset >> 2;

    if (linePivotX >= 0) {
        linePivotX = 186 - linePivotX;
    } else {
        linePivotX = 186;
    }

    _insertLine(x, y, linePivotX, _mapLabelY + 8);
    _insertLine(linePivotX, _mapLabelY + 8, 194, _mapLabelY + 8);

    menuItem =
        vs_battle_setMenuItem(0, 194, _mapLabelY, 128, 0, (char*)&_doors[_doors[doorId]]);
    menuItem->backgroundWidth = 16;

    _mapLabelY -= 16;

    func_800C9078(menuItem);
    vs_battle_getMenuItem(0)->state = 0;
}

static void _insertLine(int x0, int y0, int x1, int y1)
{
    u_long** p = (u_long**)getScratchAddr(0);
    LINE_F2* line = *(LINE_F2**)p;

    setLineF2(line);
    setXY2(line, x0, y0, x1, y1);
    setRGB0(line, 128, 128, 128);

    AddPrim(p[1] + 8, line++);

    p[0] = (u_long*)line;
}

static void func_80107B10(int arg0, int arg1, int arg2)
{
    int i;
    int sp18[] = { 0x30, 0x40, 0x48, 0x38 };
    void** new_var2;
    void** new_var3;
    int new_var;
    int new_var4;

    POLY_FT4* poly = *(void**)0x1F800000;

    for (i = 0; i < 8; ++i) {

        func_8010800C(arg0, arg1, 0x2B, 3, arg2 + (i << 8));

        setPolyFT4(poly);
        setSemiTrans(poly, 1);
        setShadeTex(poly, 1);

        new_var4 = 0x2D;

        if (!(i & 3)) {
            new_var = 0x80;
            setUV4(poly, 2, new_var, new_var4, new_var, 2, 0x83, new_var4, 0x83);
        } else {
            new_var = 0x84;
            setUV4(poly, 2, new_var, new_var4, new_var, 2, 0x87, new_var4, 0x87);
        }

        setXY4(poly, D_80108E54[0][0], D_80108E54[0][1], D_80108E54[1][0],
            D_80108E54[1][1], D_80108E54[2][0], D_80108E54[2][1], D_80108E54[3][0],
            D_80108E54[3][1]);
        setTPage(poly, 0, 1, 448, 256);
        setClut(poly, 960, 222);

        new_var3 = (void**)0x1F800000;

        AddPrim(new_var3[1] + 28, poly++);
    }

    func_8010800C(arg0, arg1, 0x27, 0x27, arg2 + 0x200);

    for (i = 0; i < 4; ++i) {

        setPolyFT4(poly);
        setShadeTex(poly, 1);
        setXY4(poly, D_80108E54[i][0] - 3, D_80108E54[i][1] - 3, D_80108E54[i][0] + 4,
            D_80108E54[i][1] - 3, D_80108E54[i][0] - 3, D_80108E54[i][1] + 4,
            D_80108E54[i][0] + 4, D_80108E54[i][1] + 4);
        setUV4(poly, sp18[i], 0x80, sp18[i] + 7, 0x80, sp18[i], 0x87, sp18[i] + 7, 0x87);
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
        setXY4(poly, D_80108E54[i][0] - 6, D_80108E54[i][1] - 6, D_80108E54[i][0] + 7,
            D_80108E54[i][1] - 6, D_80108E54[i][0] - 6, D_80108E54[i][1] + 7,
            D_80108E54[i][0] + 7, D_80108E54[i][1] + 7);
        setUV4(poly, 1, 0x89, 0xE, 0x89, 1, 0x96, 0xE, 0x96);
        setTPage(poly, 0, 1, 448, 256);

        if (i == 0) {
            setClut(poly, 976, 222);
        } else {
            setClut(poly, 960, 222);
        }

        new_var3 = (void**)0x1F800000;

        AddPrim(new_var3[1] + 0x18, poly++);
    }

    func_8010800C(arg0, arg1, 0xF, 0xF, (arg2 - D_80108DA4[2]) + 0x200);
    func_8010800C(D_80108E54[0][0], D_80108E54[0][1], 0xF, 0x11, arg2 - D_80108DA4[2]);

    setPolyFT4(poly);
    setSemiTrans(poly, 1);
    setShadeTex(poly, 1);
    setXY4(poly, D_80108E54[0][0], D_80108E54[0][1], D_80108E54[1][0], D_80108E54[1][1],
        D_80108E54[2][0], D_80108E54[2][1], D_80108E54[3][0], D_80108E54[3][1]);
    setUV4(poly, 0x14, 0x88, 0x23, 0x88, 0x14, 0x99, 0x23, 0x99);
    setTPage(poly, 0, 0, 448, 256);
    setClut(poly, 992, 222);

    new_var2 = (void**)0x1F800000;
    new_var3 = (void**)0x1F800000;

    AddPrim(new_var3[1] + 0x18, poly++);

    new_var2[0] = (void*)poly;
}

static void func_8010800C(int arg0, int arg1, int arg2, int arg3, int arg4)
{
    int i;
    int var_v0;
    int var_v1;
    int temp_s1 = rsin(arg4);
    int temp_v0 = rcos(arg4);

    D_80108E54[0][0] = (-arg2 * temp_v0) + (arg3 * temp_s1);
    D_80108E54[0][1] = (-arg3 * temp_v0) - (arg2 * temp_s1);
    D_80108E54[1][0] = (arg2 * temp_v0) + (arg3 * temp_s1);
    D_80108E54[1][1] = (-arg3 * temp_v0) + (arg2 * temp_s1);
    D_80108E54[2][0] = -D_80108E54[1][0];
    D_80108E54[2][1] = -D_80108E54[1][1];
    D_80108E54[3][0] = -D_80108E54[0][0];
    D_80108E54[3][1] = -D_80108E54[0][1];

    for (i = 0; i < 4; ++i) {
        var_v0 = D_80108E54[i][0];
        if (var_v0 < 0) {
            var_v0 += 0x1FFF;
        }
        var_v1 = D_80108E54[i][1];
        D_80108E54[i][0] = var_v0 >> 0xD;
        if (var_v1 < 0) {
            var_v1 += 0x1FFF;
        }
        D_80108E54[i][1] = var_v1 >> 0xD;
        D_80108E54[i][0] = D_80108E54[i][0] + arg0;
        D_80108E54[i][1] = D_80108E54[i][1] + arg1;
    }
}

/**
 * Renders the map name and line.
 */
static void _renderConnectingMapName(int x, int y, int mapId)
{
    int linePivotX;
    vs_battle_menuItem_t* menuItem;
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

    _insertLine(x, y, linePivotX, _mapLabelY + 8);
    _insertLine(linePivotX, _mapLabelY + 8, 194, _mapLabelY + 8);

    areaVisited = vs_main_mapStatus.areaFlags[mapId >> 5] & (1 << (mapId & 0x1F));

    if (!areaVisited) {
        mapId = VS_connectingMaps_INDEX_notVisited;
    }

    menuItem = vs_battle_setMenuItem(
        0, 178, _mapLabelY, 144, 0, (char*)&_connectingMaps[_connectingMaps[mapId]]);
    menuItem->backgroundWidth = 8;

    _mapLabelY -= 16;

    func_800C9078(menuItem);
    vs_battle_getMenuItem(0)->state = 0;
}

static void _addMapLabel(int x, int y, int type, int doorId)
{
    _mapLabels[_mapLabelCount].x = x;
    _mapLabels[_mapLabelCount].y = y;
    _mapLabels[_mapLabelCount].type = type;
    _mapLabels[_mapLabelCount].doorId = doorId;
    ++_mapLabelCount;
}

static void renderMapLabels(void)
{
    int i;

    if ((_menuCommandsState == 5) || (D_80108D8C != 0)) {
        return;
    }

    for (i = 0; i < _mapLabelCount; ++i) {
        if (_mapLabels[i].type == 0) {
            _renderDoorName(_mapLabels[i].x, _mapLabels[i].y, _mapLabels[i].doorId);
        }
    }

    for (i = 0; i < _mapLabelCount; ++i) {
        if (_mapLabels[i].type != 0) {
            _renderConnectingMapName(
                _mapLabels[i].x, _mapLabels[i].y, _mapLabels[i].doorId);
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
