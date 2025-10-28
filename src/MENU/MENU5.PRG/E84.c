#include "common.h"
#include "../../SLUS_010.40/main.h"
#include "../../SLUS_010.40/31724.h"
#include "../../BATTLE/BATTLE.PRG/146C.h"
#include "../../BATTLE/BATTLE.PRG/5BF94.h"
#include <libetc.h>

typedef struct {
    char unk0;
    char unk1;
    char unk2;
    char unk3;
    char unk4;
    char unk5;
    char unk6;
    char unk7;
    short unk8;
    short unkA;
    short unkC;
    short unkE;
} func_80107A9C_t;

void func_80107A9C(int arg0, int arg1, int arg2, int arg3);
void func_8010815C(int, int, int);
void func_80106178(MATRIX* arg0, short arg1);
void func_801061EC(MATRIX* arg0, short arg1);

extern u_short D_80108630[];
extern u_short D_801088B0[];
extern int _isCurrentScene;
extern int D_80108D8C;
extern short D_80108D9C;
extern SVECTOR _centerPoint;
extern int D_80108E48;
extern int D_80108E54[4][2];
extern short D_80108E74[][4];
extern int D_80108EB4;

INCLUDE_ASM("build/src/MENU/MENU5.PRG/nonmatchings/E84", func_80103684);

INCLUDE_ASM("build/src/MENU/MENU5.PRG/nonmatchings/E84", func_801042B0);

void func_80041C68(MATRIX*, MATRIX*);
extern int D_80108D7C;
extern short D_80108DA4[];
extern short D_80108DAC[];

void func_80041C68(MATRIX*, MATRIX*);
extern int D_80108D7C;
extern short D_80108DA4[];
extern short D_80108DAC[];

void func_80104384(void)
{
    SVECTOR sp10;
    MATRIX sp18;
    MATRIX sp38;
    int temp_s0;
    int temp_v1;
    int var_v0;
    short* new_var;

    temp_s0 = vs_math_sine(D_80108DA4[1]);
    temp_v1 = vs_math_cosine(D_80108DA4[0]);
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
    temp_s0 = vs_math_cosine(D_80108DA4[1]);
    temp_v1 = vs_math_cosine(D_80108DA4[0]);
    temp_s0 *= -D_80108D7C;
    if (temp_s0 < 0) {
        temp_s0 += 0xFFF;
    }
    var_v0 = (temp_s0 >> 0xC) * temp_v1;
    if (var_v0 < 0) {
        var_v0 += 0xFFF;
    }
    D_80108DAC[2] = var_v0 >> 0xC;
    var_v0 = vs_math_sine(D_80108DA4[0]) * -D_80108D7C;
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

INCLUDE_ASM("build/src/MENU/MENU5.PRG/nonmatchings/E84", func_8010451C);

void func_8010467C(int* arg0)
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

INCLUDE_ASM("build/src/MENU/MENU5.PRG/nonmatchings/E84", func_801046B0);

INCLUDE_ASM("build/src/MENU/MENU5.PRG/nonmatchings/E84", func_80104780);

void _recenterMapToRoom(vs_battle_scene* scene, int roomId)
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

INCLUDE_ASM("build/src/MENU/MENU5.PRG/nonmatchings/E84", func_80105D3C);

INCLUDE_ASM("build/src/MENU/MENU5.PRG/nonmatchings/E84", func_80105EC0);

void _scaleRoomVertices(vs_battle_scene* scene, int factor)
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

void func_80106178(MATRIX* arg0, short arg1)
{
    int temp_s0 = vs_math_sine(-arg1);
    int temp_v0 = vs_math_cosine(-arg1);

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

void func_801061EC(MATRIX* arg0, short arg1)
{
    int temp_s0 = vs_math_sine(arg1);
    int temp_v0 = vs_math_cosine(arg1);

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

INCLUDE_ASM("build/src/MENU/MENU5.PRG/nonmatchings/E84", func_8010625C);

int _getCurrentRoomIndex(vs_battle_scene* scene)
{
    int i;

    int roomCount = scene->roomCount;
    vs_battle_room* room = vs_battle_currentScene->rooms;
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
        if (room->unk0 != 0) {
            return i;
        }
    }
    return 0;
}

INCLUDE_ASM("build/src/MENU/MENU5.PRG/nonmatchings/E84", func_80106618);

INCLUDE_ASM("build/src/MENU/MENU5.PRG/nonmatchings/E84", func_801066E0);

INCLUDE_ASM("build/src/MENU/MENU5.PRG/nonmatchings/E84", func_80106AF4);

INCLUDE_ASM("build/src/MENU/MENU5.PRG/nonmatchings/E84", func_80106C84);

INCLUDE_ASM("build/src/MENU/MENU5.PRG/nonmatchings/E84", func_801074AC);

INCLUDE_ASM("build/src/MENU/MENU5.PRG/nonmatchings/E84", func_80107630);

void func_801079B8(int arg0, int arg1, int arg2)
{
    int var_a0;
    int var_s1;
    vs_battle_menuItem_t* temp_v0;

    var_a0 = 0xBA - arg0;
    if (var_a0 < 0) {
        var_a0 += 3;
    }
    var_s1 = var_a0 >> 2;
    if (var_s1 >= 0) {
        var_s1 = 0xBA - var_s1;
    } else {
        var_s1 = 0xBA;
    }
    func_80107A9C(arg0, arg1, var_s1, D_80108E48 + 8);
    func_80107A9C(var_s1, D_80108E48 + 8, 0xC2, D_80108E48 + 8);
    temp_v0 = vs_battle_setMenuItem(
        0, 0xC2, D_80108E48, 0x80, 0, (char*)&D_801088B0[D_801088B0[arg2]]);
    temp_v0->unk2 = 0x10;
    D_80108E48 -= 0x10;
    func_800C9078(temp_v0);
    vs_battle_getMenuItem(0)->state = 0;
}

void func_80107A9C(int arg0, int arg1, int arg2, int arg3)
{
    u_long** p = (u_long**)getScratchAddr(0);
    func_80107A9C_t* temp_s0 = *(func_80107A9C_t**)p;

    temp_s0->unk3 = 3;
    temp_s0->unk7 = 0x40;
    temp_s0->unk8 = arg0;
    temp_s0->unkA = arg1;
    temp_s0->unkC = arg2;
    temp_s0->unkE = arg3;
    temp_s0->unk4 = 0x80;
    temp_s0->unk5 = 0x80;
    temp_s0->unk6 = 0x80;
    AddPrim(p[1] + 8, temp_s0++);
    p[0] = (u_long*)temp_s0;
}

INCLUDE_ASM("build/src/MENU/MENU5.PRG/nonmatchings/E84", func_80107B10);

void func_8010800C(int arg0, int arg1, int arg2, int arg3, int arg4)
{
    int temp_s1;
    int temp_v0;
    int i;
    int var_v0;
    int var_v1;

    temp_s1 = vs_math_sine(arg4);
    temp_v0 = vs_math_cosine(arg4);

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

void func_8010815C(int arg0, int arg1, int arg2)
{
    int temp_s0;
    int var_a0;
    vs_battle_menuItem_t* temp_v0;
    int new_var;

    var_a0 = 0xAA - arg0;
    if (var_a0 < 0) {
        var_a0 += 3;
    }
    temp_s0 = var_a0 >> 2;
    if (temp_s0 < 0) {
        temp_s0 = 0xAA;
    } else {
        temp_s0 = 0xAA - temp_s0;
    }

    func_80107A9C(arg0, arg1, temp_s0, D_80108E48 + 8);
    func_80107A9C(temp_s0, D_80108E48 + 8, 0xC2, D_80108E48 + 8);
    new_var = D_8005FFD8.unk40[arg2 >> 5] & (1 << (arg2 & 0x1F));
    if (!new_var) {
        arg2 = 0x20;
    }
    temp_v0 = vs_battle_setMenuItem(
        0, 0xB2, D_80108E48, 0x90, 0, (char*)&D_80108630[D_80108630[arg2]]);
    temp_v0->unk2 = 8;
    D_80108E48 -= 16;
    func_800C9078(temp_v0);
    vs_battle_getMenuItem(0)->state = 0;
}

void func_80108274(int arg0, int arg1, int arg2, int arg3)
{
    D_80108E74[D_80108EB4][0] = arg0;
    D_80108E74[D_80108EB4][1] = arg1;
    D_80108E74[D_80108EB4][2] = arg2;
    D_80108E74[D_80108EB4][3] = arg3;
    ++D_80108EB4;
}

void func_801082A8(void)
{
    int i;

    if ((D_80108D9C != 5) && (D_80108D8C == 0)) {
        for (i = 0; i < D_80108EB4; ++i) {
            if (D_80108E74[i][2] == 0) {
                func_801079B8(D_80108E74[i][0], D_80108E74[i][1], D_80108E74[i][3]);
            }
        }

        for (i = 0; i < D_80108EB4; ++i) {
            if (D_80108E74[i][2] != 0) {
                func_8010815C(D_80108E74[i][0], D_80108E74[i][1], D_80108E74[i][3]);
            }
        }
    }
}

int func_8010839C(int arg0, int arg1, int arg2)
{
    u_int temp_a2 = arg0 - 0x41;

    if ((temp_a2 < 7) && ((func_8008E7BC(arg1, arg2, temp_a2) != 0))) {
        return 0;
    }
    return vs_main_stateFlags.unk33F[arg0] < 2;
}
