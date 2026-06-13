#pragma once
#include <stddef.h>

void _setMPCostDirect(int costDecimal, int disabled);
int _getTeleportCost(int targetSavePointId);
int _warlockMagicMenu(u_int initCursorMemory);
int _shamanMagicMenu(u_int initCursorMemory);
int _sorcererMagicMenu(u_int initCursorMemory);
int _enchanterMagicMenu(u_int initCursorMemory);

extern u_short _magicStrings[];
extern u_short _teleportationStrings[];
extern int _savePointData[];
