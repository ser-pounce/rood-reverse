#include "common.h"
#include "3A1A0.h"
#include "4A0A8.h"
#include "5BF94.h"
#include "6E644.h"
#include "src/SLUS_010.40/32154.h"
#include "src/SLUS_010.40/main.h"
#include "src/SLUS_010.40/overlay.h"
#include "build/src/include/lbas.h"
#include <abs.h>
#include <stdlib.h>

typedef union {
    unsigned int raw;
    struct {
        unsigned int x : 8, y : 8, z : 8, status : 8;
    } p;
} vs_battle_movementPosition;

typedef union {
    u_int raw;
    struct {
        u_int unk0 : 1;
        u_int direction : 3;
        u_int clockwise : 1;
        u_int count : 7;
        u_int visited : 4;
        u_int stop : 1;
        u_int changed : 1;
        u_int cell : 4;
        u_int boundX : 5;
        u_int boundZ : 5;
    } bits;
} movementPath;

typedef struct {
    char unk0;
    u_char unk1;
    char unk2[2];
    u_char unk4;
    u_char unk5;
    char unk6[0x2E];
    vs_battle_movementPosition tile;
    char unk38[0x14];
    short x;
    char unk4E[2];
    short z;
    char unk52[0x92];
    u_char unkE4;
    char unkE5[2];
    u_char unkE7;
    u_char unkE8;
    char unkE9[0x75];
    u_short flags;
    char unk160[8];
    vs_battle_movementPosition destination;
    char unk16C[4];
    vs_battle_movementPosition next;
    char unk174[0x1C];
    movementPath path;
    char unk194[5];
    u_char unk199;
    u_char waitTimer;
} movementPathState;

typedef int (*movementPathTest)(movementPathState*, int);
int func_800E3D5C(movementPathState*, movementPathTest);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/7B55C", func_800E3D5C);
