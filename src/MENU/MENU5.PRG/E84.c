#include "common.h"
#include "4D8.h"
#include "../MAINMENU.PRG/413C.h"
#include "../../SLUS_010.40/main.h"
#include "../../SLUS_010.40/31724.h"
#include "../../BATTLE/BATTLE.PRG/2EA3C.h"
#include "../../BATTLE/BATTLE.PRG/5BF94.h"
#include "gpu.h"
#include <libetc.h>
#include <abs.h>

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

void func_80104384(void);
void func_801046B0(vs_battle_scene* arg0);
void func_80104780(int, void*, int, int);
void func_80106178(MATRIX* arg0, short arg1);
void func_801061EC(MATRIX* arg0, short arg1);
void _darkenBackground();
void _applyPalingScreenEffect();
void func_80106C84();
void func_80107A9C(int arg0, int arg1, int arg2, int arg3);
void func_80107B10(int arg0, int arg1, int arg2);
void func_8010800C(int arg0, int arg1, int arg2, int arg3, int arg4);
void func_8010815C(int, int, int);
void func_80108274(int arg0, int arg1, int arg2, int arg3);
void func_801082A8(void);

extern u_short D_80108630[];
extern u_short D_801088B0[];
extern int _isCurrentScene;
extern int _geomOffsetX;
extern int _geomOffsetY;
extern u_short D_80108CC4[];
extern RECT _icons[];
extern int _currentScene;
extern RECT D_80108D04[];
extern RECT D_80108D14[];
extern int D_80108D54;
extern int D_80108D58;
extern int D_80108D5C;
extern int D_80108D6C;
extern int D_80108D7C;
extern int D_80108D88;
extern int D_80108D8C;
extern int D_80108D90;
extern short D_80108D9C;
extern short D_80108D9E;
extern short D_80108DA4[];
extern short D_80108DA6;
extern short D_80108DAC[];
extern int D_80108DC4[32];
extern SVECTOR _centerPoint;
extern int D_80108E48;
extern int D_80108E54[4][2];
extern short D_80108E74[][4];
extern int D_80108EB4;

INCLUDE_ASM("build/src/MENU/MENU5.PRG/nonmatchings/E84", func_80103684);

void func_801042B0(void)
{
    DR_STP* stp;
    void** pScratch = (void**)getScratchAddr(0);
    vs_main_flags_t* flags;
    int scene;

    func_80106C84();
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
        func_800C6BF0(0, &D_80108CC4[D_80108CC4[0]]); // Paling warning
        return;
    }
    func_80104384();
    _darkenBackground();
    if (D_80108D88 == 0) {
        func_801046B0(vs_battle_sceneBuffer);
    }
}

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

int func_8010451C(int arg0)
{
    char* sp10[64];
    int var_a0;
    int var_a1;
    int i;
    int new_var;

    if (arg0 != 0) {
        D_80108D54 = 0;
        D_80108D58 = 0;
    }
    switch (D_80108D54) {
    case 0:
        var_a1 = 0;
        for (i = 1, var_a0 = 0; i < 32; ++i) {
            new_var = D_8005FFD8.unk40[i >> 5] & (1 << (i & 0x1F));
            if (new_var) {
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

void func_801046B0(vs_battle_scene* arg0)
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
    D_80108EB4 = 0;
    new_var = &arg0->roomCount;
    roomCount = *new_var;
    room = (vs_battle_room*)arg0;
    room = (vs_battle_room*)((int*)room + 1);
    for (i = 0; i < roomCount; ++i, ++room) {
        if (room->unk0 != 0) {
            func_80104780(i, room->dataAddress, room->zoneId, room->mapId);
        }
    }
    func_801082A8();
    vs_battle_setGeomOffset(&prevOffset);
}

INCLUDE_ASM("build/src/MENU/MENU5.PRG/nonmatchings/E84", func_80104780);

void _snapMapToRoom(vs_battle_scene* scene, int roomId)
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

void _setCenterpoint(vs_battle_scene* scene, int roomId)
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

void _smoothMapToCenterpoint(vs_battle_scene* scene)
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

#define _insertTpage(after, arg1)                                                        \
    __asm__("scratch = $t3;"                                                             \
            "tpageOp = $t4;"                                                             \
            "li         scratch, 0x1F800000;"                                            \
            "sll        $t0, %0, 2;"                                                     \
            "lw         $t4, 4(scratch);"                                                \
            "lw         $t7, 0(scratch);"                                                \
            "addu       $t0, $t4;"                                                       \
            "lw         $t1, 0($t0);"                                                    \
            "li         tpageOp, 0xE1000000;"                                            \
            "and        $t6, %1, 0x1FF;"                                                 \
            "or         tpageOp, 0x200;"                                                 \
            "or         tpageOp, $t6;"                                                   \
            "sw         tpageOp, 4($t7);"                                                \
            "sw         $zero, 8($t7);"                                                  \
            "li         $t5, 0xFFFFFF;"                                                  \
            "li         $t4, 0x2000000;"                                                 \
            "li         $t6, 0xFF000000;"                                                \
            "and        $t2, $t1, $t5;"                                                  \
            "or         $t4, $t2;"                                                       \
            "sw         $t4, 0($t7);"                                                    \
            "and        $t2, $t1, $t6;"                                                  \
            "and        $t4, $t7, $t5;"                                                  \
            "or         $t4, $t2;"                                                       \
            "sw         $t4, 0($t0);"                                                    \
            "addu       $t2, $t7, 0xC;"                                                  \
            "sw         $t2, 0(scratch);"                                                \
            :                                                                            \
            : "r"(after), "r"(arg1)                                                      \
            : "t0", "t1", "t2", "t3", "t4", "t5", "t6", "t7")

void _darkenBackground(void)
{
    SPRT* sprt;
    u_long* pScratch1;
    u_long* pScratch2;

    _insertTpage(0x7FE, getTPage(0, 3, 0, 0));

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
        _insertTpage(0x7FE, getTPage(2, 0, 320, 0));
    } else {
        _insertTpage(0x7FE, getTPage(2, 0, 0, 0));
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
        _insertTpage(0x7FE, getTPage(2, 0, 512, 0));
    } else {
        _insertTpage(0x7FE, getTPage(2, 0, 192, 0));
    }
}

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

void _updateRoomIndex(int searchForward)
{
    int currentIndex = _currentRoomIndex;
    vs_battle_room* room = ((vs_battle_scene*)vs_battle_sceneBuffer)->rooms;

    do {
        if (searchForward > 0) {
            _currentRoomIndex = _roomNamesTable[_currentRoomIndex].next;
        } else {
            _currentRoomIndex = _roomNamesTable[_currentRoomIndex].prev;
        }
    } while (room[_currentRoomIndex].unk0 == 0);

    if (currentIndex != _currentRoomIndex) {
        vs_main_playSfxDefault(0x7E, 0xB);
    }
}

void _applyPalingScreenEffect(void)
{
    int y;

    _insertTpage(0x7FE, getTPage(0, 3, 0, 0));

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
            x = vs_math_sine((D_80108D6C + y) << 6);
            if (x < 0) {
                x += 127;
            }
            x = x >> 7;
        } else {
            x = vs_math_sine((D_80108D6C + y) << 6);
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
            _insertTpage(8, getTPage(2, 0, 320, 0));
        } else {
            _insertTpage(8, getTPage(2, 0, 0, 0));
        }

        sprt = *(void**)getScratchAddr(0);
        setSprt(sprt);
        setSemiTrans(sprt, 1);
        setRGB0(sprt, 128, 128, 128);

        if (y & 1) {
            x = vs_math_sine((D_80108D6C + y) << 6);
            if (x < 0) {
                x += 127;
            }
            x = (x >> 7) + 192;
        } else {
            int offset;
            x = vs_math_sine((D_80108D6C + y) << 6);
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
            _insertTpage(8, getTPage(2, 0, 512, 0));
        } else {
            _insertTpage(8, getTPage(2, 0, 192, 0));
        }
    }
}

void _drawControlsUIBackground(int x, int y, int w, int h)
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
    AddPrim(pScratch[1] + 0x1C, poly++);
    pScratch[0] = (void*)poly;
}

void func_80106C84(void)
{
    D_800F4FE0_t* temp_a0;

    temp_a0 = func_800CCDF4(0);

    if (D_80108D9E == 0) {
        D_80108D5C = -0x80;
        ++D_80108D9E;
    } else if (D_80108D9E == 1) {
        if (D_80108D5C < 0) {
            D_80108D5C += 0x10;
            if (temp_a0 != NULL) {
                temp_a0->unk4[9] = temp_a0->unk4[9] - 8;
                temp_a0->unk4[7] = temp_a0->unk4[7] - 8;
            }
        }
    } else if (D_80108D9E == 2) {
        if (D_80108D5C >= -0x7F) {
            D_80108D5C -= 0x10;
            if (temp_a0 != NULL) {
                temp_a0->unk4[9] = temp_a0->unk4[9] + 8;
                temp_a0->unk4[7] = temp_a0->unk4[7] + 8;
            }
        }
    }

    if (D_80108D8C == 0) {
        if (vs_main_stateFlags.mapPaling[_currentScene] == 0) {
            int index = D_80108D5C;
            void** s1 = (void**)0x1F800000;
            vs_mainmenu_drawButton(4, index + 8, 0xF, s1[1] + 0x18);
            vs_mainmenu_drawButton(5, D_80108D5C + 0x40, 0xF, s1[1] + 0x18);
            vs_mainmenu_drawButton(6, D_80108D5C + 8, 0x21, s1[1] + 0x18);
            vs_mainmenu_drawButton(7, D_80108D5C + 8, 0x34, s1[1] + 0x18);
            vs_mainmenu_drawButton(2, D_80108D5C + 8, 0x46, s1[1] + 0x18);
            switch (D_80108D9C) {
            case 0: {
                int v = ((D_80108D5C + 0x1C) & 0xFFFF) | 0x120000;
                void** s0 = (void**)0x1F800000;
                func_800C6540("BACK", v, 0x808080, s0[1] + 0x18);
                func_800C6540("NEXT", ((D_80108D5C + 0x54) & 0xFFFF) | 0x120000, 0x808080,
                    s0[1] + 0x18);
                func_800C6540("ROTATION", ((D_80108D5C + 0x1C) & 0xFFFF) | 0x240000,
                    0x808080, s0[1] + 0x18);
                func_800C6540("ZOOM", ((D_80108D5C + 0x1C) & 0xFFFF) | 0x360000, 0x808080,
                    s0[1] + 0x18);
                func_800C6540("MENU", ((D_80108D5C + 0x1C) & 0xFFFF) | 0x480000, 0x808080,
                    s0[1] + 0x18);
                break;
            }
            case 1: {
                int v = ((D_80108D5C + 0x1C) & 0xFFFF) | 0x120000;
                void** s0 = (void**)0x1F800000;
                func_800C6540("BACK", v, 0x808080, s0[1] + 0x18);
                func_800C6540("NEXT", ((D_80108D5C + 0x54) & 0xFFFF) | 0x120000, 0x808080,
                    s0[1] + 0x18);
                func_800C6540("ROTATION", ((D_80108D5C + 0x1C) & 0xFFFF) | 0x240000,
                    0x202020, s0[1] + 0x18);
                func_800C6540("ZOOM", ((D_80108D5C + 0x1C) & 0xFFFF) | 0x360000, 0x202020,
                    s0[1] + 0x18);
                func_800C6540("MENU", ((D_80108D5C + 0x1C) & 0xFFFF) | 0x480000, 0x808080,
                    s0[1] + 0x18);
                break;
            }
            case 2: {
                int v = ((D_80108D5C + 0x1C) & 0xFFFF) | 0x120000;
                void** s0 = (void**)0x1F800000;
                func_800C6540("BACK", v, 0x202020, s0[1] + 0x18);
                func_800C6540("NEXT", ((D_80108D5C + 0x54) & 0xFFFF) | 0x120000, 0x202020,
                    s0[1] + 0x18);
                func_800C6540("ROTATION", ((D_80108D5C + 0x1C) & 0xFFFF) | 0x240000,
                    0x202020, s0[1] + 0x18);
                func_800C6540("ZOOM", ((D_80108D5C + 0x1C) & 0xFFFF) | 0x360000, 0x808080,
                    s0[1] + 0x18);
                func_800C6540("MENU", ((D_80108D5C + 0x1C) & 0xFFFF) | 0x480000, 0x808080,
                    s0[1] + 0x18);
                break;
            }
            case 3: {
                int v = ((D_80108D5C + 0x1C) & 0xFFFF) | 0x120000;
                void** s0 = (void**)0x1F800000;
                func_800C6540("BACK", v, 0x202020, s0[1] + 0x18);
                func_800C6540("NEXT", ((D_80108D5C + 0x54) & 0xFFFF) | 0x120000, 0x202020,
                    s0[1] + 0x18);
                func_800C6540("ROTATION", ((D_80108D5C + 0x1C) & 0xFFFF) | 0x240000,
                    0x808080, s0[1] + 0x18);
                func_800C6540("ZOOM", ((D_80108D5C + 0x1C) & 0xFFFF) | 0x360000, 0x202020,
                    s0[1] + 0x18);
                func_800C6540("MENU", ((D_80108D5C + 0x1C) & 0xFFFF) | 0x480000, 0x808080,
                    s0[1] + 0x18);
                break;
            }
            case 4: {
                int v = ((D_80108D5C + 0x1C) & 0xFFFF) | 0x120000;
                void** s0 = (void**)0x1F800000;
                func_800C6540("BACK", v, 0x202020, s0[1] + 0x18);
                func_800C6540("NEXT", ((D_80108D5C + 0x54) & 0xFFFF) | 0x120000, 0x202020,
                    s0[1] + 0x18);
                func_800C6540("ROTATION", ((D_80108D5C + 0x1C) & 0xFFFF) | 0x240000,
                    0x202020, s0[1] + 0x18);
                func_800C6540("ZOOM", ((D_80108D5C + 0x1C) & 0xFFFF) | 0x360000, 0x202020,
                    s0[1] + 0x18);
                func_800C6540("MENU", ((D_80108D5C + 0x1C) & 0xFFFF) | 0x480000, 0x808080,
                    s0[1] + 0x18);
                break;
            }
            case 5: {
                int v = ((D_80108D5C + 0x1C) & 0xFFFF) | 0x120000;
                void** s0 = (void**)0x1F800000;
                func_800C6540("BACK", v, 0x202020, s0[1] + 0x18);
                func_800C6540("NEXT", ((D_80108D5C + 0x54) & 0xFFFF) | 0x120000, 0x202020,
                    s0[1] + 0x18);
                func_800C6540("ROTATION", ((D_80108D5C + 0x1C) & 0xFFFF) | 0x240000,
                    0x202020, s0[1] + 0x18);
                func_800C6540("ZOOM", ((D_80108D5C + 0x1C) & 0xFFFF) | 0x360000, 0x202020,
                    s0[1] + 0x18);
                func_800C6540("MENU", ((D_80108D5C + 0x1C) & 0xFFFF) | 0x480000, 0x202020,
                    s0[1] + 0x18);
                break;
            }
            }
            _drawControlsUIBackground(D_80108D5C + 0x10, 0x12, 0x72, 0xC);
            _drawControlsUIBackground(D_80108D5C + 0x10, 0x24, 0x60, 0xC);
            _drawControlsUIBackground(D_80108D5C + 0x10, 0x36, 0x4E, 0xC);
            _drawControlsUIBackground(D_80108D5C + 0x10, 0x48, 0x3C, 0xC);
            _insertTpage(7, 0x103);
            func_80107B10(0x3E, 0xB8, D_80108DA6);
            return;
        }
        func_800C6540("JAMMING", ((D_80108D5C + 0x1C) & 0xFFFF) | 0x120000, 0x808080,
            *(void**)0x1F800004 + 0x18);
    }
}

void _drawIcon(int id, int x, int y)
{
    RECT* icon;
    void** scratch = (void**)getScratchAddr(0);
    POLY_FT4* poly = scratch[0];

    setPolyFT4(poly);
    setShadeTex(poly, 1);
    icon = &_icons[id];
    setXY4(poly, x - icon->w / 2, y, icon->w + (x - icon->w / 2), y, x - icon->w / 2,
        y + 8, icon->w + (x - icon->w / 2), y + 8);
    setUV4(poly, icon->x, icon->y, icon->x + icon->w, icon->y, icon->x, icon->y + 8,
        icon->x + icon->w, icon->y + 8);
    setTPage(poly, 0, 0, 768, 0);
    setClut(poly, 848, 223);

    AddPrim(scratch[1] + 0x1C, poly++);
    scratch[0] = poly;
}

void func_80107630(int x, int y, int arg2)
{
    POLY_FT4* poly;
    RECT* rect0;
    RECT* rect1;
    int s6;
    int temp;
    void** new_var = (void**)getScratchAddr(0);

    poly = new_var[0];
    s6 = (arg2 - 1);
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
    AddPrim(new_var[1] + 0x1C, poly++);

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

    AddPrim(new_var[1] + 0x1C, poly++);
    new_var[0] = poly;
    func_80108274(x, y, 0, temp);
}

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

void func_80107B10(int arg0, int arg1, int arg2)
{
    int i;
    POLY_FT4* poly;
    int sp18[] = { 0x30, 0x40, 0x48, 0x38 };
    void** new_var2;
    void** new_var3;
    int new_var;
    int new_var4;

    poly = *(void**)0x1F800000;

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
        AddPrim(new_var3[1] + 0x1C, poly++);
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
