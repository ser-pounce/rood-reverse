#include "common.h"
#include "579C0.h"
#include "battleUi.h"
#include "gpu.h"
#include "scratch.h"
#include "src/SLUS_010.40/sfx.h"
#include "src/SLUS_010.40/sound.h"
#include <memory.h>

#ifdef NON_MATCHING

void vs_battle_copyAligned(void* dst, const void* src, int numBytes)
{
    memcpy(dst, src, numBytes);
}

void vs_battle_memcpy(void* dst, const void* src, int numBytes)
{
    memcpy(dst, src, numBytes);
}

u_long* vs_battle_setSpriteDefault(int wh, int xy)
{
    return vs_battle_setSpriteDefaultTexPage(128, xy, wh, vs_scratch.unk8);
}

u_long* vs_battle_setSpriteDefaultTexPage(
    int brightnessTransparency, int xy, int wh, u_long* nextPrim)
{
    u_long* prim = vs_battle_setSprite(brightnessTransparency, xy, wh, nextPrim);
    prim[1] = _get_mode(0, 0, getTPage(0, 0, 768, 0));
    return prim;
}

u_long* vs_battle_setSprite(int brightnessTransparency, int xy, int wh, u_long* nextPrim)
{
    int brightness = brightnessTransparency & 0xFF;
    int code = brightnessTransparency & 0x100 ? primSprtSemtTrans : primSprt;
    u_long* prim = vs_scratch.unk0;

    prim[0] = vs_getTag(VS_SPRT, *nextPrim);
    prim[1] = 0;
    prim[2] = vs_getRGB0(code, brightness, brightness, brightness);
    prim[3] = xy;
    prim[4] = 0;
    prim[5] = wh;
    *nextPrim = ((u_long)prim << 8) >> 8;
    vs_scratch.unk0 = prim + 6;
    return prim;
}

void func_800C02A8(void)
{
    SetRotMatrix(&vs_scratch.viewMatrix);
    SetTransMatrix(&vs_scratch.viewMatrix);
}

void vs_battle_playSfx10(void) { vs_main_playSfxDefault(0x7E, 10); }

void vs_battle_playInvalidSfx(void) { vs_main_playSfxDefault(0x7E, VS_SFX_INVALID); }

void vs_battle_playMenuLeaveSfx(void) { vs_main_playSfxDefault(0x7E, VS_SFX_MENULEAVE); }

void vs_battle_playMenuSelectSfx(void)
{
    vs_main_playSfxDefault(0x7E, VS_SFX_MENUSELECT);
}

void vs_battle_playMenuChangeSfx(void)
{
    vs_main_playSfxDefault(0x7E, VS_SFX_MENUCHANGE);
}

#endif
