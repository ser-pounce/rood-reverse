#pragma once

void vs_battle_copyAligned(short* dst, const short* src, int numBytes);
void vs_battle_memcpy(void* dst, const void* src, int numBytes);
u_int* vs_battle_setSprite(int, int rgb, int wh, u_int* nextPrim);
void func_800C02E0();
void func_800C02E8();
void func_800C02F0();
void func_800C02F8();
void vs_battle_playSfx10();

extern void* D_800F4C28;
