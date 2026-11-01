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
} vs_battle_geomOffset;

vs_battle_roomName* vs_battle_initSceneAndGetRoomNames(void*);
void vs_battle_getGeomOffset(vs_battle_geomOffset*);
void vs_battle_setGeomOffset(vs_battle_geomOffset*);

void func_8009820C(void*);
void func_800985AC(VECTOR*, VECTOR*, MATRIX*);
void func_80098648(VECTOR*, VECTOR*, MATRIX*);
void func_80098F8C(void*);
void func_8009723C(void*, int);
void func_800983F8(void*);
void func_80098D6C(void*, void*, D_800F1BB0_t*, int);
void func_80098160(int);
void func_80098194(int);
void func_80098B38(int, int);
u_char func_80099514(u_int, int, int);
