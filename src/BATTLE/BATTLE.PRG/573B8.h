#pragma once

void vs_battle_copyAligned(void* dst, const void* src, int numBytes);
void vs_battle_memcpy(void* dst, const void* src, int numBytes);
u_long* vs_battle_setSprite(int, int x, int wh, u_long* nextPrim);
int func_800BFE50(u_short);
void func_800C00E8(int, void*);
u_long* func_800C0214(int, int);
u_long* func_800C0224(int, int, int, u_long*);
void vs_battle_playInvalidSfx(void);
void func_800C031C(void);
void func_800C05B4(void);
void func_800C06E0(void);
void func_800C0738(void);
void vs_battle_playMenuLeaveSfx(void);
void vs_battle_playMenuSelectSfx(void);
void vs_battle_playMenuChangeSfx(void);
void vs_battle_playSfx10(void);

extern void* D_800F4C28;
extern short _evtFile;
