#pragma once

/* Sprite, save info and number drawing shared by the title and menu overlays. */

static fileMenuElements_t _fileMenuElements[10];
static char _2[8] __attribute__((unused));
static primBuf_t _primBuf;

/**
 * Draws a textured sprite using packed coordinates, UV/CLUT, size and tpage.
 */
static void _drawSprt(int xy, int uvClut, int wh, int tpage)
{
    DrawSync(0);
    _primBuf.tag = vs_getTag(_primBuf.prim.sprt, primAddrNull);
    _primBuf.prim.sprt.tpage = vs_getTpageRaw(tpage & 0x9FF);
    _primBuf.prim.sprt.r0g0b0code =
        vs_getRGB0Raw(primSprt, ((0x80 - (tpage >> 16)) * 0x010101));
    _primBuf.prim.sprt.x0y0 = xy;
    _primBuf.prim.sprt.u0v0clut = uvClut;
    _primBuf.prim.sprt.wh = wh;
    DrawPrim(&_primBuf);
}

static char _menuElementStops[] = { 0, 1, 2, 4, 8, 16, 32, 56, 80, 104, 128, 152, 176,
    200, 224, 248, 255, 255, 255, 255 };
static signed char _cursorFileOpSaturation[] = { 0, -56, -112, -104, -96, -88, -80, -72,
    -64, -56, -48, -40, -32, -24, -16, -8 };

enum vs_fileMenuUiIds_e {
    vs_uiids_colon = 0,
    vs_uiids_number = 1,
    vs_uiids_map = 2,
    vs_uiids_save = 3,
    vs_uiids_clear = 4,
    vs_uiids_time = 5,
    vs_uiids_percent = 6,
    vs_uiids_hp = 7,
    vs_uiids_mp = 8,
    vs_uiids_dot = 9,
};

/**
 * Draws the selected UI element at the desired position.
 */
static void _drawSaveInfoUI(int xy, enum vs_fileMenuUiIds_e id)
{
    static int _saveInfoUVClut[] = { vs_getUV0Clut(248, 8, 832, 223),
        vs_getUV0Clut(242, 0, 832, 223), vs_getUV0Clut(224, 120, 848, 223),
        vs_getUV0Clut(128, 56, 848, 223), vs_getUV0Clut(224, 112, 848, 223),
        vs_getUV0Clut(104, 56, 848, 223), vs_getUV0Clut(170, 76, 864, 223),
        vs_getUV0Clut(144, 0, 864, 223), vs_getUV0Clut(160, 0, 864, 223),
        vs_getUV0Clut(32, 9, 832, 223) };
    static int _saveInfoWh[] = { vs_getXY(3, 8), vs_getXY(13, 8), vs_getXY(17, 8),
        vs_getXY(22, 8), vs_getXY(26, 8), vs_getXY(19, 8), vs_getXY(10, 10),
        vs_getXY(16, 9), vs_getXY(18, 9), vs_getXY(5, 7) };
    _drawSprt(xy, _saveInfoUVClut[id], _saveInfoWh[id], 0xC);
}

/**
 * Draws value starting at its requested decimal place and advancing right.
 */
static void _drawInteger(int xy, u_int value, u_int placeDivisor)
{
    do {
        _drawSprt(xy, vs_getUV0Clut(((value / placeDivisor) * 6), 0, 832, 223),
            vs_getWH(6, 10), getTPage(0, 0, 768, 0));
        value = value % placeDivisor;
        placeDivisor /= 10;
        xy += 5;
    } while (placeDivisor != 0);
}

/**
 * Returns the number of decimal digits in a nonnegative integer.
 */
static int _countDigits(int val)
{
    int i;

    i = 0;
    do {
        val /= 10;
        ++i;
    } while (val != 0);
    return i;
}

enum statType_e { statTypeHP = 0, statTypeMP = 1 };

/**
 * Draws the HP or MP label, current/max values, and proportional status bar.
 */
static void _drawHPMP(int xy, enum statType_e stat, u_int currentValue, u_int maxValue)
{
    static char _digitDivisors[] = { 0, 1, 10, 100 };

    int currentValueFactor;
    int maxValueDigits;
    u_int rgb1;
    u_int currentValueDigits;
    u_int rgb0;
    int wh;
    u_int placeDivisor;
    int x1y1;
    int red;
    int new_var4;

    if (maxValue != 0) {
        currentValueDigits = (((currentValue * 64) + maxValue) - 1) / maxValue;
    } else {
        currentValueDigits = 0;
    }

    rgb0 = ((207 << 16) | (224 << 8)) | 45;
    if (stat != statTypeHP) {
        rgb0 = ((159 << 16) | (120 << 8)) | 220;
    }

    red = (rgb0 & 0xFF);
    currentValueFactor = 64 - currentValueDigits;
    rgb1 =
        ((((currentValueDigits * 255) + (red * currentValueFactor)) >> 6)
            | ((((currentValueDigits * 240) + (((rgb0 >> 8) & 0xFF) * currentValueFactor))
                   >> 6)
                << 8))
        | ((((2 * (currentValueDigits * 79)) + ((rgb0 >> 16) * currentValueFactor)) >> 6)
            << 16);

    DrawSync(0);
    _primBuf.tag = vs_getTag(_primBuf.prim.tilePoly, primAddrNull);
    _primBuf.prim.tilePoly.tile.tpage =
        vs_getTpage(0, 0, clut4Bit, semiTransparencyHalf, ditheringOn);
    _primBuf.prim.tilePoly.tile.r0g0b0code = vs_getRGB0(primTile, 0, 40, 64);
    wh = vs_getWH(66, 5);
    x1y1 = (currentValueDigits + vs_getXY(0, 9));
    _primBuf.prim.tilePoly.tile.x0y0 = xy++ + vs_getXY(0, 8);
    _primBuf.prim.tilePoly.tile.wh = wh;
    _primBuf.prim.tilePoly.polyG4.r0g0b0code = vs_getRGB0Raw(primPolyG4, rgb1);
    _primBuf.prim.tilePoly.polyG4.x0y0 = xy + vs_getXY(0, 9);
    _primBuf.prim.tilePoly.polyG4.r1g1b1 = rgb0;
    _primBuf.prim.tilePoly.polyG4.x1y1 = xy + x1y1;
    _primBuf.prim.tilePoly.polyG4.r2g2b2 = rgb1;
    _primBuf.prim.tilePoly.polyG4.x2y2 = xy + vs_getXY(0, 12);
    _primBuf.prim.tilePoly.polyG4.r3g3b3 = rgb0;
    _primBuf.prim.tilePoly.polyG4.x3y3 = vs_getXY(0, 12);
    _primBuf.prim.tilePoly.polyG4.x3y3 =
        xy + (currentValueDigits + _primBuf.prim.tilePoly.polyG4.x3y3);
    DrawPrim(&_primBuf);

    currentValueDigits = _countDigits(currentValue);
    maxValueDigits = _countDigits(maxValue);
    _drawSaveInfoUI(xy - 1, stat + vs_uiids_hp);
    wh = currentValueDigits * 6;
    new_var4 = 55;
    xy = (xy - (wh - new_var4)) - (maxValueDigits * 5);
    placeDivisor = _digitDivisors[currentValueDigits];
    do {
        _drawSprt(xy - vs_getXY(0, 1),
            (((currentValue / placeDivisor) << 3) + 64) | (getClut(832, 223) << 16),
            vs_getWH(7, 12), getTPage(0, 0, 768, 0));
        currentValue = currentValue % placeDivisor;
        placeDivisor /= 10;
        xy += 6;
    } while (placeDivisor != 0);
    _drawSaveInfoUI(xy + 1, vs_uiids_dot);
    _drawInteger(xy + 6, maxValue, _digitDivisors[maxValueDigits]);
}
