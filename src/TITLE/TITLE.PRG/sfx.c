#include "sfx.h"
#include "../SLUS_010.40/main.h"
#include "../SLUS_010.40/sfx.h"

void _playNewGameSfx()
{
    vs_main_playSfxDefault(0x7E, 1);
    vs_main_playSfxDefault(0x7E, 2);
    vs_main_playSfxDefault(0x7E, 3);
}

void _playMenuChangeSfx() { vs_main_playSfxDefault(0x7E, VS_SFX_MENUCHANGE); }

void _playMenuSelectSfx() { vs_main_playSfxDefault(0x7E, VS_SFX_MENUSELECT); }

void _playMenuLeaveSfx() { vs_main_playSfxDefault(0x7E, VS_SFX_MENULEAVE); }
