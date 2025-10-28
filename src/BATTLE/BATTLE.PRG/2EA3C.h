#pragma once
#include "146C.h"

typedef struct {
    int x;
    int y;
} vs_battle_geomOffset;

vs_battle_roomName* vs_battle_initSceneAndGetRoomNames(void*);
void vs_battle_getGeomOffset(vs_battle_geomOffset*);
void vs_battle_setGeomOffset(vs_battle_geomOffset*);
