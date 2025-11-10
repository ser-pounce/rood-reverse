#pragma once
#include "../../BATTLE/BATTLE.PRG/146C.h"

extern int _currentRoomIndex;
extern vs_battle_roomName* _roomNamesTable;
extern u_short _mapNames[];
extern vs_main_CdFile _sceneArmFiles[];
extern vs_main_CdQueueSlot* _sceneCdQueueSlot;

void func_80102CD8(int arg0);
void func_80102D1C(int arg0, int arg1, int arg2, u_long* arg3);
void func_80102D90(int, int, char**);
int func_80102ED8();
void _setMenuItemMapName(char* mapName, char arg1);
