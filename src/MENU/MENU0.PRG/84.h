#pragma once
#include <stddef.h>

void setMPCostDirect(int costDecimal, int disabled);
int getTeleportCost(int targetSavePointId);
int warlockMagicMenu(u_int initCursorMemory);
int shamanMagicMenu(u_int initCursorMemory);
int sorcererMagicMenu(u_int initCursorMemory);
int enchanterMagicMenu(u_int initCursorMemory);

extern u_short magicStrings[];
extern u_short teleportationStrings[];
extern int savePointData[];
