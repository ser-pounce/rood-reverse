#pragma once
#include <sys/types.h>
#include <libgte.h>

// Parameters left undeclared due to misuse in unused func_8007B378
void vs_main_loadClutTransition(
    /*int duration, int slot, u_short* sourceClut, int clutOffset*/);

void vs_main_transformClutSlot(
    int mode, int duration, int slot, short rOffset, int gOffset, int bOffset);

void vs_main_fadeBgColors(int frames, CVECTOR* target);

void vs_main_transformBgColors(
    int mode, int frames, int rOffset, int gOffset, int bOffset);

void vs_main_transformColorSlot(
    int mode, int frames, int slot, int rOffset, int gOffset, int bOffset);

void vs_main_updateBgColors(void);
void vs_main_updateClutSlots(void);
void vs_main_updateColorSlots(void);
void vs_main_loadClut(u_short const* img, u_int slot, u_int colorOffset, u_int count);
void vs_main_loadBgColors(void);
void vs_main_commitClut(void);
void vs_main_setClutState(int active);
void vs_main_clutInit(void);
