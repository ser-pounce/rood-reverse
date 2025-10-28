#include "common.h"
#include "../MAINMENU.PRG/C48.h"
#include "../MAINMENU.PRG/413C.h"
#include "../MAINMENU.PRG/8170.h"
#include "../../BATTLE/BATTLE.PRG/146C.h"
#include "../../BATTLE/BATTLE.PRG/2EA3C.h"
#include "../../BATTLE/BATTLE.PRG/573B8.h"
#include "../../BATTLE/BATTLE.PRG/5BF94.h"
#include "../../SLUS_010.40/32154.h"
#include "lbas.h"
#include "gpu.h"

int func_80103418(void);
int func_80103684();
void _recenterMapToRoom(void*, int);
void _scaleRoomVertices(void*, int);
int _getCurrentRoomIndex(void*);

extern u_long* D_1F800000[];

extern vs_main_CdFile _sceneArmFiles[];
extern int D_801083F8;
extern u_short _mapNames[];
extern vs_main_CdQueueSlot* D_80108D24;
extern u_short* D_80108D28;
extern int D_80108D2C;
extern int D_80108D30;
extern int D_80108D34;
extern int D_80108D38;
extern u_long* D_80108D3C;
extern RECT D_80108D44[];
extern int D_80108D60;
extern int _currentRoomIndex;
extern int D_80108D68;
extern int D_80108D6C;
extern int D_80108D70;
extern int D_80108D74;
extern int D_80108D7C;
extern int _currentScene;
extern int D_80108D88;
extern int D_80108D8C;
extern int D_80108D90;
extern int D_80108D94;
extern int _roomNamesTable;
extern short D_80108D9C;
extern short D_80108D9E;
extern short D_80108DA4[4];
extern short D_80108DAC[4];
extern vs_main_CdQueueSlot* _sceneCdQueueSlot;
extern int D_80108E44;

void func_80102CD8(int arg0)
{
    if (arg0 != 0) {
        func_800FFA88(2);
        D_801022D6 = 0;
        return;
    }
    func_800FFA88(0);
    D_801022D6 = 1;
}

void func_80102D1C(int arg0, int arg1, int arg2, u_long* arg3)
{
    u_long* var_a3;

    var_a3 = arg3;
    if (var_a3 == 0) {
        var_a3 = D_1F800000[2];
    }
    func_800C0224(0x80, arg1, 0x100010, var_a3)->unk10 = ((arg0 + 4) * 0x10) | 0x37FD8000;
    D_1F800000[0][-4] = (int)(arg2 | 0x64000000);
}

void func_80102D90(int arg0, int arg1, char** arg2)
{
    int sp10[arg0];
    int var_v1;
    int temp_a1;
    int temp_s1;

    if (D_801083F8 == -1) {
        D_801083F8 = arg1;
    }

    for (var_v1 = 0; var_v1 < arg0; ++var_v1) {
        sp10[var_v1] = 0;
    }

    if (!(arg1 & 0x80)) {
        if (D_801083F8 < arg0) {
            sp10[D_801083F8] |= 4;
        }
    }

    temp_a1 = arg1 & 0x7F;

    if ((arg0 < 9) || (temp_a1 < 8)) {
        D_800F4EE8.unk0[0] = temp_a1;
        D_800F4EE8.unk0[1] = 0;
    } else if (temp_a1 >= (arg0 - 8)) {
        D_800F4EE8.unk0[0] = temp_a1 - (arg0 - 9);
        D_800F4EE8.unk0[1] = arg0 - 9;
    } else {
        D_800F4EE8.unk0[0] = 4;
        D_800F4EE8.unk0[1] = temp_a1 - 4;
    }
    temp_s1 = vs_main_settings.cursorMemory;
    vs_main_settings.cursorMemory = 1;
    vs_mainmenu_setMenuRows(arg0, 0x100, arg2, sp10);
    vs_main_settings.cursorMemory = temp_s1;
}

int func_80102ED8(void)
{
    int temp_v0;

    temp_v0 = vs_mainmenu_getSelectedRow();
    if (temp_v0 < -1) {
        func_800FA8E0(5);
        return temp_v0;
    }
    if (temp_v0 >= 0) {
        func_800FA92C(D_800F4EE8.unk0[0], 1);
    }
    return temp_v0;
}

void _setMenuItemMapName(char* mapName, char arg1)
{
    vs_battle_menuItem_t* menuItem;

    menuItem = vs_battle_setMenuItem(10, 320, 34, 0x8C, 8, mapName);
    menuItem->state = 2;
    menuItem->x = 0xB4;
    menuItem->selected = 1;
    menuItem->unkA = arg1;
}

void func_80102F8C(void) { func_800FA8E0(5); }

void func_80102FAC(void) { vs_mainmenu_ready(); }

int func_80102FCC(int arg0)
{
    vs_main_CdFile cdFile;

    if (arg0 != 0) {
        cdFile.lba = VS_MAPBG_BIN_LBA;
        cdFile.size = VS_MAPBG_BIN_SIZE;
        D_80108D24 = vs_main_allocateCdQueueSlot(&cdFile);
        D_80108D28 = vs_main_allocHeapR(VS_MAPBG_BIN_SIZE);
        vs_main_cdEnqueue(D_80108D24, D_80108D28);
        D_80108D2C = 0;
        return 0;
    }
    switch (D_80108D2C) {
    case 0:
        if (D_80108D24->state == 4) {
            vs_main_freeCdQueueSlot(D_80108D24);
            func_80048A64(D_80108D28, 3, 0, 0x100);
            vs_battle_drawImage(
                vs_getXY(640, 256), D_80108D28 + 0x100, vs_getWH(160, 240));
            func_80100414(-4, 0x80);
            D_80108D2C = 1;
        }
        return 0;
    case 1:
        vs_main_freeHeapR(D_80108D28);
        return 1;
    default:
        return 0;
    }
}

int func_801030F4(char* state)
{
    int temp_v0_2;
    u_long* temp_a1;
    char temp_v0;

    temp_v0 = *state;
    switch (temp_v0) {
    case 3:
        D_801083F8 = -1;
        temp_a1 = vs_main_allocHeapR(0xB600);
        D_80108D3C = temp_a1;
        D_80108D44[0].x = 0x300;
        D_80108D44[0].y = 0xE3;
        D_80108D44[0].w = 0x100;
        D_80108D44[0].h = 1;
        (&D_80108D44[1])->x = 0x2A0;
        (&D_80108D44[1])->y = 0x100;
        (&D_80108D44[1])->w = 0x60;
        (&D_80108D44[1])->h = 0xF0;
        StoreImage(D_80108D44, temp_a1);
        StoreImage(&D_80108D44[1], D_80108D3C + 0x80);
        func_80102FCC(1);
        *state = 4;
        break;
    case 4:
        if (func_80102FCC(0) == 0) {
            break;
        }
        *state = 5;
        func_800FFB68(1);
        D_80108D30 = 8;
        D_80108D34 = 0;
        // Fallthrough
    case 5:
        if (D_80108D34 == 0) {
            D_80108D34 = func_80103418();
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
        temp_v0_2 = func_80103684();
        D_80108D38 = temp_v0_2;
        if (temp_v0_2 != 0) {
            func_80100414(-4, 0x80);
            func_800CB654(0);
            D_800EB9B0 = 0;
            func_8008A4DC(1);
            func_800FFA88(0);
            func_800FA8E0(0x28);
            D_80108D30 = 0xA;
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
            func_80048A64((u_short*)D_80108D3C, 3U, 0U, 0x100U);
            vs_battle_drawImage(0x010002A0, D_80108D3C + 0x80, 0xF00060);
            *state = 0xA;
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

int func_80103418(void)
{
    int a1;

    vs_main_stateFlags.unk135[0] = 1;
    if (vs_battle_sceneBuffer == NULL) {
        if (D_8005FFD8.unk0[1] & 0x800000) {
            D_8005FFD8.unk0[1] |= 0x400000;
        }
        D_80108D8C = 0;
        D_80108D94 = 0;
        vs_main_bzero(D_80108DA4, sizeof D_80108DA4);
        vs_main_bzero(D_80108DAC, sizeof D_80108DAC);
        D_80108DA4[0] = 0x238;
        _currentRoomIndex = 0;
        D_80108DA4[2] = D_80108DA4[1] = 0x800 - *(u_short*)0x1F800058;
        _currentScene = vs_battle_getCurrentSceneId();
        if (_currentScene >= 32) {
            _currentScene = 0;
        }
        a1 = vs_main_stateFlags.unk135[_currentScene];
        D_80108D90 = _currentScene;
        D_80108D60 = 0;
        D_80108D68 = 0x80;
        D_80108D6C = 0;
        D_80108D70 = -0x180;
        D_80108D74 = 0;
        D_80108E44 = 1;
        D_80108D7C = 0x300;
        D_80108D9C = 5;
        D_80108D9E = 0;
        D_80108D88 = a1;
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
    _recenterMapToRoom(vs_battle_sceneBuffer, _currentRoomIndex);
    vs_gte_setDepthCueDefault(0x300, vs_main_projectionDistance);
    SetFarColor(0, 0, 0);
    _setMenuItemMapName((char*)&_mapNames[_mapNames[_currentScene]], 1);
    return 1;
}

INCLUDE_RODATA("build/src/MENU/MENU5.PRG/nonmatchings/4D8", D_80102820);

INCLUDE_RODATA("build/src/MENU/MENU5.PRG/nonmatchings/4D8", _sceneArmFiles);

INCLUDE_RODATA("build/src/MENU/MENU5.PRG/nonmatchings/4D8", D_80102C00);
