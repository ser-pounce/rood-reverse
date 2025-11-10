#include "common.h"
#include "4D8.h"
#include "../../assets/MENU/MENU5.PRG/mapNames.h"
#include "../MAINMENU.PRG/C48.h"
#include "../MAINMENU.PRG/413C.h"
#include "../MAINMENU.PRG/8170.h"
#include "../../BATTLE/BATTLE.PRG/2EA3C.h"
#include "../../BATTLE/BATTLE.PRG/573B8.h"
#include "../../BATTLE/BATTLE.PRG/5BF94.h"
#include "../../SLUS_010.40/32154.h"
#include "lbas.h"
#include "gpu.h"
#include <libetc.h>

int func_80103418(void);
int func_80103684();
void _snapMapToRoom(void*, int);
void _scaleRoomVertices(void*, int);
int _getCurrentRoomIndex(void*);

extern u_long* D_1F800000[];

static int D_801083F8 = -1;
u_short _mapNames[] = {
#include "../../assets/MENU/MENU5.PRG/mapNames.vsString"
};

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
extern int _geomOffsetX;
extern int _geomOffsetY;
extern int D_80108D7C;
extern int _currentScene;
extern int D_80108D88;
extern int D_80108D8C;
extern int D_80108D90;
extern int D_80108D94;
extern vs_battle_roomName* _roomNamesTable;
extern short D_80108D9C;
extern short D_80108D9E;
extern short D_80108DA4[4];
extern short D_80108DAC[4];
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

    vs_main_stateFlags.mapPaling[0] = 1;
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
        D_80108DA4[2] = D_80108DA4[1] = 0x800 - *(u_short*)getScratchAddr(22);
        _currentScene = vs_battle_getCurrentSceneId();
        if (_currentScene >= 32) {
            _currentScene = 0;
        }
        a1 = vs_main_stateFlags.mapPaling[_currentScene];
        D_80108D90 = _currentScene;
        D_80108D60 = 0;
        D_80108D68 = 0x80;
        D_80108D6C = 0;
        _geomOffsetX = -0x180;
        _geomOffsetY = 0;
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
    _snapMapToRoom(vs_battle_sceneBuffer, _currentRoomIndex);
    vs_gte_setDepthCueDefault(0x300, vs_main_projectionDistance);
    SetFarColor(0, 0, 0);
    _setMenuItemMapName((char*)&_mapNames[_mapNames[_currentScene]], 1);
    return 1;
}

// Unused vertex data, seems to be a miscopying, perhaps through a header.
// The same data is defined and used in BATTLE.PRG
static u_int const _0[] __attribute__((unused)) = { 0xFFEAFFFA, 0xFFEA0012, 0x0001FFFA,
    0x00010012, 0xFFEAFFEF, 0xFFEA0007, 0x0001FFEF, 0x00010007, 0xFFE3FFF6, 0xFFE30014,
    0x0001FFF6, 0x00010014, 0xFFE3FFED, 0xFFE30009, 0x0001FFED, 0x00010009, 0xFFF0FFF7,
    0xFFF0000B, 0xFFFDFFF7, 0xFFFD000B, 0xFFF0FFF6, 0xFFF0000A, 0xFFFDFFF6, 0xFFFD000A,
    0x10581040, 0x27582740, 0x103F1057, 0x273F2757, 0x11971179, 0x2F972F79, 0x11781196,
    0x2F782F96, 0x11B411A0, 0x1EB41EA0, 0x119F11B3, 0x1E9F1EB3, 0xFFF0FFFE, 0xFFF0FFF2,
    0xFFEB0000, 0xFFEBFFF9, 0xFFF50003, 0xFFF50003, 0x00400000, 0x000C0024, 0x00400000,
    0x000C0018, 0x00400018, 0x000C0014, 0x0040002C, 0x000C0018, 0x004000E0, 0x000C0010,
    0x004C00D4, 0x000C0020, 0x00400096, 0x000C001A, 0x00400044, 0x000C0028, 0x0040006C,
    0x000C001E, 0x0040008A, 0x000C0032, 0x004000BC, 0x000C0024, 0x004C0000, 0x000C0034,
    0x004C0034, 0x000C001E, 0x00580090, 0x000C003A, 0x004C0078, 0x000C003C, 0x004C00B4,
    0x000C001E, 0x00580088, 0x000C0008, 0x00580068, 0x000C0020, 0x0058004C, 0x000C0028,
    0x00580000, 0x000C0010, 0x00580014, 0x000C0014, 0x00580028, 0x000C001E, 0x00580048,
    0x000C0020, 0x004C0066, 0x000C0010, 0x006400DC, 0x000C0012, 0x00340098, 0x000C001A,
    0x002800B6, 0x000C001E, 0x002800D6, 0x000C0018, 0x00340098, 0x000C001C, 0x003400B4,
    0x000C0028, 0x003400DC, 0x000C001E, 0x0040006C, 0x000C001E, 0x001C00D8, 0x000C001C,
    0x00001F01, 0x001B1D02, 0x001B1E02, 0x001A1C02, 0x001B2002, 0x00050102, 0x01040102,
    0x00050202, 0x01040202, 0x00050302, 0x01040302, 0x02000701, 0x02000801, 0x02000901,
    0x02000A01, 0x02000B01, 0x02000C01, 0x03000D01, 0x03000E01, 0x00050F02, 0x01040F02,
    0x02131002, 0x02141002, 0x02151002, 0x02161002, 0x02131102, 0x02141102, 0x02151102,
    0x02161102, 0x00000000, 0x00000000, 0x00000000, 0x00D0D0D0, 0x00FFC040, 0x0030D0FF,
    0x0060E0A0, 0x00A00048, 0x00080020, 0x00A8004C, 0x0008001C, 0x00B0004E, 0x0008001A,
    0x00B8004E, 0x0008001A, 0x00C00052, 0x00080016, 0x00C80052, 0x00080016, 0x00D00052,
    0x00080016, 0x00A00068, 0x0008001C, 0x00A80068, 0x0008001A, 0x00B00068, 0x0008001E,
    0x00B80068, 0x00080024, 0x00C00068, 0x00080020, 0x00C80068, 0x00080012, 0x00A00090,
    0x0008001E, 0x00A80090, 0x0008000E, 0x00B00090, 0x00080012, 0x00B80090, 0x0008001A,
    0x00C00090, 0x0008001A, 0x00C80090, 0x00080016, 0x00D00090, 0x00080024 };

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
