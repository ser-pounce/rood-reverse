#pragma once
#include <stddef.h>

void vs_battle_copyAligned(void* dst, const void* src, int numBytes);
void vs_battle_memcpy(void* dst, const void* src, int numBytes);
int func_800BFE50(u_short);
void func_800C00E8(int, void*);

/**
 * Same as vs_battle_setSpriteDefault, but the next
 * chained primitive is read from 0x1F800008 and
 * brightness is set to midpoint (0x80) and transparency is disabled.
 *
 * @return Primitive pointer at 0x1F800000
 */
u_long* vs_battle_setSpriteDefault(int wh, int xy);

/**
 * Same as vs_battle_setSpriteDefaultTexPage, but presets the
 * texpage command to 0xE100000C i.e. x offset 768
 *
 * @return Primitive pointer at 0x1F800000
 */
u_long* vs_battle_setSpriteDefaultTexPage(
    int brightnessTransparency, int xy, int wh, u_long* nextPrim);

/**
 * Initializes a texpage command to the OT at 0x1F800000.
 * Actual 0xE1 command must be set by caller at return[1].
 *
 * @param brightnessTransparency Packed value
 * - Bits 0-7: Brightness
 * - Bit 8: Transparency
 * @return Primitive pointer at 0x1F800000
 */
u_long* vs_battle_setSprite(int brightnessTransparency, int xy, int wh, u_long* nextPrim);

void func_800C031C(void);
void func_800C05B4(void);
void func_800C06E0(void);
void func_800C0738(void);

/**
 * Plays SFX ID 7
 */
void vs_battle_playInvalidSfx(void);

/**
 * Plays SFX ID 6
 */
void vs_battle_playMenuLeaveSfx(void);

/**
 * Plays SFX ID 5
 */
void vs_battle_playMenuSelectSfx(void);

/**
 * Plays SFX ID 4
 */
void vs_battle_playMenuChangeSfx(void);
void vs_battle_playSfx10(void);

extern void* D_800F4C28;
extern short _evtFile;
