#pragma once

/* File menu background shared by the title and menu overlays. */

/**
 * Draws the static background texture for the file menu.
 */
static void _drawFileMenuBg(void)
{
    _drawSprt(vs_getXY(256, 0), vs_getUV0Clut(0, 0, 768, 227), vs_getWH(64, 176),
        getTPage(clut8Bit, semiTransparencyHalf, 768, 256));
    _drawSprt(vs_getXY(0, 0), vs_getUV0Clut(0, 0, 768, 227), vs_getWH(256, 176),
        getTPage(clut8Bit, semiTransparencyHalf, 640, 256));
}
