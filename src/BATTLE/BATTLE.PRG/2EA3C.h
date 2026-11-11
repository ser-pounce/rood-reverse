#pragma once
#include "mpd.h"

typedef struct {
    signed char unk0;
    signed char unk1;
    signed char unk2;
    char unk3;
    short unk4;
    short unk6;
} D_800F1BB0_t;

typedef struct {
    int x;
    int y;
} vs_GeomOffset;

vs_RoomName* vs_battle_initSceneAndGetRoomNames(void*);
void vs_battle_getGeomOffset(vs_GeomOffset*);
void vs_battle_setGeomOffset(vs_GeomOffset*);
