#pragma once

/* File menu text and colour helpers shared by the title and menu overlays. */

/**
 * Prints a vs-encoded string.
 */
static void _printString(char* text, int x, int y, int clut)
{
    static char arrowState = 0;

    char tempArrowState;
    u_int c;
    int startX = x;
    int nextX = x;

    while (1) {
        c = *text++;
        if (c < vs_char_control) {
            if (c < vs_char_nonPrinting) {
                nextX = _printCharacter(c, nextX, y, clut);
            } else if (c == vs_char_confirm) {
                tempArrowState = (arrowState + 1) % 12;
                c = vs_char_arrow - (tempArrowState >> 2);
                arrowState = tempArrowState;
                nextX = _printCharacter(c, nextX, y, clut);
            } else if (c != vs_char_terminator) {
                if (c == vs_char_newline) {
                    y += 13;
                    nextX = startX;
                }
            } else {
                break;
            }
        } else {
            u_int control = *text++;
            if (c == vs_char_spacing) {
                if (control >= 0xF0) {
                    nextX -= 256 - control;
                } else {
                    nextX += control;
                }
            }
        }
    }
}

/**
 * Linearly blends RGB channels; factor ranges from zero to eight.
 */
static u_int _interpolateRGB(u_int colour1, u_int colour2, u_int factor)
{
    int component;
    u_int i;
    u_int colourOut;

    colourOut = 0;
    for (i = 0; i < 3; ++i) {
        component = ((colour1 >> 16) & 0xFF) * (8 - factor);
        colour1 <<= 8;
        colourOut =
            (colourOut << 8) + ((component + (((colour2 >> 16) & 0xFF) * factor)) >> 3);
        colour2 <<= 8;
    }
    return colourOut;
}

/**
 * Selects and blends the background colours for the two animation factors.
 */
static u_int _intepolateMenuItemBgColour(u_int outerFactor, u_int innerFactor)
{
    static int colors1[] = { vs_getRGB888(0x40, 0x30, 0x66),
        vs_getRGB888(0x40, 0x38, 0x20) };
    static int colors2[] = {
        vs_getRGB888(0x08, 0x08, 0x20),
        vs_getRGB888(0x10, 0x10, 0x08),
    };

    u_int color1;
    u_int color2;

    if (innerFactor < 9) {
        color1 = _interpolateRGB(
            vs_getRGB888(0, 65, 107), vs_getRGB888(25, 130, 108), innerFactor);
        color2 =
            _interpolateRGB(vs_getRGB888(0, 5, 51), vs_getRGB888(1, 40, 38), innerFactor);
    } else {
        color1 = colors1[((innerFactor >> 3) - 2)];
        color2 = colors2[((innerFactor >> 3) - 2)];
    }
    return _interpolateRGB(color1, color2, outerFactor);
}
