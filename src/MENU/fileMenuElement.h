#pragma once

/* File menu element helpers shared by the title and menu overlays. */

/**
 * Resets menu elements, progress, fade, cursor and message state.
 */
static void _initFileMenu(void)
{
    _memoryCardMessage = NULL;
    _selectCursorColor = 0;
    _selectCursorXy = 0;
    _fileProgressCounter = 0;
    _fileMenuScreenFade = 0;
    _fileProgressTarget = 384;
    memset(_fileMenuElements, 0, sizeof _fileMenuElements);
}

/**
 * Initializes an element and performs some text preprocessing.
 *
 * @return The initialized element in the shared file-menu element array.
 */
static fileMenuElements_t* _initFileMenuElement(int id, int xy, int wh, char* text)
{
    fileMenuElements_t* element;
    int i;
    u_int c;

    element = &_fileMenuElements[id];
    memset(element, 0, sizeof *element);
    element->state = 1;
    element->slotId = -1;
    *(int*)&element->x = xy;
    *(int*)&element->w = wh;

    if (text != NULL) {
        for (i = 0; i < 32;) {
            c = *text++;
            if (c == vs_char_spacing) {
                element->text[i++] = c;
                do {
                    c = *(text++);
                } while (0);
            } else {
                if (c == vs_char_terminator) {
                    element->text[i] = vs_char_printString;
                    return element;
                }
                if (c >= vs_char_nonPrinting) {
                    continue;
                }
            }
            element->text[i++] = c;
        }
    } else {
        element->text[0] = vs_char_printString;
    }
    return element;
}

/**
 * Clears one element in menu element array.
 */
static void _clearFileMenuElement(int id)
{
    memset(&_fileMenuElements[id], 0, sizeof _fileMenuElements[id]);
}

/**
 * Reports whether all file-menu elements have finished their animations.
 */
static int _fileMenuElementsActive(void)
{
    int i;

    for (i = 0; i < 10 && _fileMenuElements[i].state < fileMenuElementStateAnimateX; ++i)
        ;
    return i == 10;
}

/**
 * Draws a glyph (or applies a spacing control) and returns the next x position.
 */
static int _printCharacter(u_int c, int x, int y, int clut)
{
    static int glyphWidths[] = { 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
        6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
        6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 12, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
        6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 12, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
        6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
        6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
        6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 12, 12, 12, 12, 12,
        12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 8, 5, 7, 8, 7, 7, 7, 6, 6, 6, 7, 7, 7, 9,
        7, 7, 7, 7, 6, 7, 7, 6, 8, 7, 8, 8, 9, 8, 8, 4, 7, 5, 7, 7, 6, 8, 7, 7, 7, 6, 8,
        6, 8, 8, 7, 6, 7, 6, 8, 8, 7, 7, 8, 7, 5, 6, 7, 6, 7, 7, 7, 8, 12, 7, 7, 7, 7, 7,
        7, 7, 7, 7, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7, 7, 7, 7, 12, 7, 7, 7, 7, 7, 8, 8, 8, 8,
        7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
        12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 6, 12, 12, 12, 12,
        12, 12, 8, 12, 6, 5, 4, 12, 12, 12, 12, 4, 6, 6, 12, 12, 6, 6, 3, 3, 3, 4, 6, 12,
        6, 6, 6, 12, 5, 6, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
        12, 12, 12 };

    if ((c >> 8) == 14) {
        return x + (char)c;
    }
    if (c != vs_char_space) {
        DrawSync(0);
        _primBuf.tag = vs_getTag(_primBuf.prim.sprt, primAddrNull);
        _primBuf.prim.sprt.tpage =
            vs_getTpage(832, 0, clut4Bit, semiTransparencyFull, ditheringOff);
        _primBuf.prim.sprt.r0g0b0code = vs_getRGB0(primSprtSemtTrans, 128, 128, 128);
        _primBuf.prim.sprt.x0y0 = (u_short)x | y << 16;
        _primBuf.prim.sprt.wh = vs_getWH(12, 12);
        _primBuf.prim.sprt.u0v0clut =
            vs_getUV0Clut((c % 21) * 12, (c / 21) * 12, clut * 16 + 896, 222);
        DrawPrim(&_primBuf);
    }
    return x + glyphWidths[c];
}
