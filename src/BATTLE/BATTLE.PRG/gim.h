#pragma once
#include "src/SLUS_010.40/cd.h"
#include <sys/types.h>

typedef struct {
    u_int visible : 1;
    u_int loading : 1;
    u_int unk0_2 : 1;
    u_int drawMode : 3;
    u_int loadState : 3;
    u_int pageCount : 3;
    u_int unk0_12 : 1;
    u_int unk0_13 : 3;
    char vramSlot;
    char brightness;
    u_char columns;
    u_char rows;
    short id;
    short x;
    short y;
    short scale;
    u_short unkE;
    u_short* data;
    vs_CdQueueSlot* cdQueueSlot;
    u_short widths[240];
    u_short imageTable[254];
    int unk3F4;
} Gim;
