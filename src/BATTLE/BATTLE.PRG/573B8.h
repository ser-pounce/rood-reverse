#pragma once
#include "146C.h"

void vs_battle_copyAligned(short* dst, const short* src, int numBytes);
void vs_battle_memcpy(void* dst, const void* src, int numBytes);
u_long* vs_battle_setSprite(int, int x, int wh, u_long* nextPrim);
u_long* func_800C0214(int, int);
vs_battle_actor2* func_800C0224(int, int, int, u_long*);
void func_800C02E0(void);
void vs_battle_playMenuLeaveSfx(void);
void vs_battle_playMenuSelectSfx(void);
void vs_battle_playMenuChangeSfx(void);
void vs_battle_playSfx10(void);

extern void* D_800F4C28;
