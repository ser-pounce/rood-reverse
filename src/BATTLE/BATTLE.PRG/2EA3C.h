#pragma once
#include "146C.h"

typedef struct {
    int x;
    int y;
} vs_battle_geomOffset;

vs_battle_roomName* vs_battle_initSceneAndGetRoomNames(void*);
void vs_battle_getGeomOffset(vs_battle_geomOffset*);
void vs_battle_setGeomOffset(vs_battle_geomOffset*);

void func_8009820C(void*);
void func_800985AC(VECTOR*, VECTOR*, MATRIX*);
void func_80098648(VECTOR*, VECTOR*, MATRIX*);
