#pragma once

/* File menu helpers shared by the title and menu overlays. The including file defines
 * MEMCARD_MASKED_HANDLER_PAD, the size of the alignment filler after the masked handler
 * state, since the data that follows differs between overlays, and
 * FIND_SAVE_ACCESSING_HOOK, overlay specific work done when starting to access a card.
 * Also contains the file processing animation, menu elements and background. */

static int _selectCursorXy;
static char* _memoryCardMessage;
static char _isSaving;

/**
 * Draws the save / load progress bar.
 */
static void _fileProcessingAnim(int x, int y)
{
    char* new_var __attribute__((unused));
    int gradientColor1;
    int gradientColor2;
    u_int leftEdge;
    u_int i;

    leftEdge = x - 48;
    new_var = &_isSaving;

    if (leftEdge < 64) {
        leftEdge = 64;
    }

    gradientColor1 = 0;
    gradientColor2 = vs_getRGB888(224, 255, 0);

    if (_isSaving != 0) {
        gradientColor2 = vs_getRGB888(255, 0, 127);
    }

    for (i = 0; i < 2; ++i) {
        DrawSync(0);
        _primBuf.tag = vs_getTag(_primBuf.prim.polyG4_tpage, primAddrNull);
        _primBuf.prim.polyG4_tpage.r0g0b0code =
            vs_getRGB0Raw(primPolyG4SemiTrans, gradientColor1);
        _primBuf.prim.polyG4_tpage.x0y0 = leftEdge | y;
        _primBuf.prim.polyG4_tpage.x1y1 = x | y;
        _primBuf.prim.polyG4_tpage.x2y2 = leftEdge | (y + vs_getXY(0, 32));
        _primBuf.prim.polyG4_tpage.tpage =
            vs_getTpage(0, 0, clut4Bit, semiTransparencyFull, ditheringOn);
        _primBuf.prim.polyG4_tpage.r1g1b1 = gradientColor2;
        _primBuf.prim.polyG4_tpage.r2g2b2 = gradientColor1;
        _primBuf.prim.polyG4_tpage.r3g3b3 = gradientColor2;
        _primBuf.prim.polyG4_tpage.x3y3 = x | (y + vs_getXY(0, 32));
        DrawPrim(&_primBuf);
        leftEdge = x;
        x += 16;
        gradientColor1 = gradientColor2;
        gradientColor2 = 0;
    }
}

/**
 * Draws the completion flash for a file operation.
 */
static void _fileProcessingCompleteAnim(int colour, int y)
{
    int yOfst;
    int colour0;
    u_int i;
    int colour1 = 0;

    if (_isSaving != 0) {
        colour0 = colour + (colour << 15);
    } else {
        colour0 = (colour - (colour >> 3)) + (colour << 8);
    }

    DrawSync(0);
    _primBuf.tag = vs_getTag(_primBuf.prim.tile_tpage, primAddrNull);
    _primBuf.prim.tile_tpage.tpage =
        vs_getTpage(0, 0, clut4Bit, semiTransparencyFull, ditheringOn);
    _primBuf.prim.tile_tpage.r0g0b0code = vs_getRGB0Raw(primTileSemiTrans, colour0);
    _primBuf.prim.tile_tpage.x0y0 = y | 64;
    _primBuf.prim.tile_tpage.wh = vs_getWH(256, 32);
    DrawPrim(&_primBuf);

    for (i = 0; i < 2; ++i) {
        DrawSync(0);
        _primBuf.tag = vs_getTag(_primBuf.prim.polyG4, primAddrNull);
        yOfst = y + vs_getXY(0, -8);
        _primBuf.prim.polyG4.r0g0b0code = vs_getRGB0Raw(primPolyG4SemiTrans, colour1);
        _primBuf.prim.polyG4.x0y0 = yOfst | 64;
        _primBuf.prim.polyG4.r1g1b1 = colour1;
        _primBuf.prim.polyG4.x1y1 = yOfst | 320;
        _primBuf.prim.polyG4.r2g2b2 = colour0;
        _primBuf.prim.polyG4.x2y2 = y | 64;
        _primBuf.prim.polyG4.r3g3b3 = colour0;
        _primBuf.prim.polyG4.x3y3 = y | 320;
        DrawPrim(&_primBuf);
        y += vs_getXY(0, 40);
        colour1 = colour0;
        colour0 = 0;
    }
}

static u_char _selectCursorColor;
static char _fileMenuScreenFade;

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

enum _findCurrentSave_e {
    findSaveTimeout = -2,
    findSaveNotFound = -1,
    findSavePending = 0
};

/**
 * Searches both cards asynchronously for the save matching current settings.
 *
 * A nonzero init restarts the search; subsequent calls return the current state.
 */
static int _findCurrentSave(int init)
{
    static char state;
    static char subState;

    int port;
    int currentSave;
    int event;
    int realPort;

    if (init != 0) {
        state = 0;
        subState = 0;
        return 0;
    }

    realPort = state >> 1;
    port = realPort + 1;

    if ((state & 1) == 0) {
        FIND_SAVE_ACCESSING_HOOK(
            (char*)(_textTable + _textTable[VS_MCMAN_BIN_INDEX_accessing0 - 1 + port]));
        _memoryCardMessage =
            (char*)(_textTable + _textTable[VS_MCMAN_BIN_INDEX_accessing0 - 1 + port]);
        _memcardEventHandler(realPort + 1);
        ++state;
    } else {
        event = _memcardEventHandler(0) & 3;

        if (event != memcardEventPending) {
            if (event == memcardEventIoEnd) {
                if (_initSaveFileInfo(realPort + 1) == 0) {
                    currentSave = _findCurrentSaveOnActiveMemcard();
                    if (currentSave != 0) {
                        return currentSave + (realPort * 16);
                    }
                }
            } else if (event == memcardEventTimeout) {
                if (state != 1) {
                    if (subState != 0) {
                        return findSaveTimeout;
                    }
                } else {
                    subState = state;
                }
            }
            ++state;
        }
    }
    return state != 4 ? findSavePending : findSaveNotFound;
}

enum _memcardEventMask_e {
    memcardEventMaskIgnoreNoEvent = 0x30,
    memcardEventMaskAll = 0x70
};

enum _memcardMaskedHandler_e {
    memcardMaskedHandlerError = -1,
    memcardMaskedHandlerPending = 0,
    memcardMaskedHandlerComplete = 1
};

/**
 * Starts or polls a card operation, mapping its result through a stored mask.
 *
 * A nonzero portMask starts polling; zero advances the operation.
 */
static enum _memcardMaskedHandler_e _memcardMaskedHandler(int portMask)
{
    static char mask;
    static char _[MEMCARD_MASKED_HANDLER_PAD] __attribute__((unused));

    int event;

    if (portMask != 0) {
        _memcardEventHandler(portMask & 3);
        mask = (portMask >> 4);
        return memcardMaskedHandlerPending;
    }
    event = _memcardEventHandler(0);
    if (event != memcardEventPending) {
        switch (event & mask) {
        case memcardEventIoEnd:
            return memcardMaskedHandlerComplete;
        case memcardEventTimeout:
            _memoryCardMessage = (char*)(_textTable + VS_MCMAN_BIN_OFFSET_insertError);
            break;
        case memcardEventUnformatted:
            _memoryCardMessage = (char*)(_textTable + VS_MCMAN_BIN_OFFSET_noData);
            break;
        default:
            _memoryCardMessage = (char*)(_textTable + VS_MCMAN_BIN_OFFSET_removed);
            break;
        }
        return memcardMaskedHandlerError;
    }
    return memcardMaskedHandlerPending;
}

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

/**
 * Draws a menu element and updates its animation state.
 */
static void _drawFileMenuElement(fileMenuElements_t* element)
{
    u_long clut[130];
    saveFileInfo_t* saveInfo;
    int xy;
    int var_a3;
    int location;
    int x;
    int y;
    int var1;
    int var2;
    int uvClut;
    int slotState;
    u_short* locationClut;
    int new_var;

    if (element->selected != 0) {
        element->outertextBlendFactor = 8;
    } else if (element->outertextBlendFactor != 0) {
        --element->outertextBlendFactor;
    }
    if (element->slotUnavailable != 0) {
        element->outertextBlendFactor = 0;
    }
    if ((element->slotId >= 5) || ((element->y - 72) < 0x51U)) {
        y = element->innertextBlendFactor;
        var1 = _intepolateMenuItemBgColour(8 - element->outertextBlendFactor, y);
        var2 = _intepolateMenuItemBgColour(element->outertextBlendFactor, y);
        if (y & 7) {
            element->innertextBlendFactor = y + 1;
        }
        y = element->y << 16;

        DrawSync(0);
        _primBuf.tag = vs_getTag(_primBuf.prim.tilePoly, primAddrNull);
        _primBuf.prim.tilePoly.tile.tpage =
            vs_getTpage(0, 0, clut4Bit, semiTransparencyHalf, ditheringOn);
        _primBuf.prim.tilePoly.tile.r0g0b0code = vs_getRGB0(primTile, 0, 0, 0);
        _primBuf.prim.tilePoly.tile.x0y0 =
            ((element->x + 2) & 0xFFFF) | (element->y + 2) << 16;
        _primBuf.prim.tilePoly.tile.wh = element->w | (element->h << 0x10);
        _primBuf.prim.tilePoly.polyG4.r0g0b0code = vs_getRGB0Raw(primPolyG4, var1);
        _primBuf.prim.tilePoly.polyG4.x0y0 = (u_short)element->x | y;
        _primBuf.prim.tilePoly.polyG4.r1g1b1 = var2;
        _primBuf.prim.tilePoly.polyG4.x1y1 = ((element->x + element->w) & 0xFFFF) | y;
        _primBuf.prim.tilePoly.polyG4.r2g2b2 = var1;
        _primBuf.prim.tilePoly.polyG4.x2y2 =
            (u_short)element->x | ((element->y + element->h) << 0x10);
        _primBuf.prim.tilePoly.polyG4.r3g3b3 = var2;
        _primBuf.prim.tilePoly.polyG4.x3y3 =
            ((element->x + element->w) & 0xFFFF) | ((element->y + element->h) << 0x10);
        DrawPrim(&_primBuf);

        x = element->x + 6;
        for (var1 = 0; var1 < 32; ++var1) {
            var2 = element->text[var1];
            if (var2 == vs_char_spacing) {
                x += element->text[++var1];
            } else if (var2 != 0xFF) {
                x = _printCharacter(var2, x, element->y, 0);
            } else {
                break;
            }
        }
        var2 = element->slotId;
        if (var2 < 5) {
            _readImage(vs_getXY(768, 227), clut, vs_getWH(256, 1));
            saveInfo = &_saveFileInfo[var2];
            location = element->saveLocation - 1;
            var1 = saveInfo->unk4.base.slotState;
            if (saveInfo->unk4.base.slotState < 3) {
                if (saveInfo->unk4.base.slotState == 0) {
                    location = -2;
                } else if (saveInfo->unk4.base.slotState == 2) {
                    location = -4;
                } else if (_isSaving != 0) {
                    location = -1;
                } else {
                    location = -5;
                }
            } else if (location >= 48) {
                location = -3;
            }
            if (location >= 32u) {
                locationClut = _mcData->locationCluts[1];
            } else {
                locationClut = _mcData->locationCluts[0];
            }
            _drawImage(vs_getXY(768, 227), locationClut, vs_getWH(256, 1));
            if (location < 0) {
                uvClut = (~location << 13) | vs_getUV0Clut(64, 0, 768, 227);
                xy = (element->x - 64) | y;
                _drawSprt(xy, uvClut, vs_getWH(64, 32),
                    ((8 - element->outertextBlendFactor) << 19) | 0x9C);
            } else {
                int v0;
                uvClut = ((location & 8) * 8) | ((location & 7) << 0xD)
                       | vs_getUV0Clut(0, 0, 768, 227);
                xy = (element->x - 64) | y;
                new_var = (((location & 0x30) * 4) + 832) & 0x3FF;
                v0 = new_var >> 6;
                var_a3 = (((8 - element->outertextBlendFactor) << 19) | 0x90);
                _drawSprt(xy, uvClut, vs_getWH(64, 32), v0 | var_a3);
            }
            _drawImage(vs_getXY(768, 227), clut, vs_getWH(256, 1));
            _drawSaveInfoUI((element->x - 22) | y, vs_uiids_number);
            _drawInteger((element->x - 9) | y, var2 + 1, 0xAU);
            slotState = saveInfo->unk4.base.slotState;
            if (slotState == slotStateUnavailable) {
                _printString((char*)(_textTable + VS_MCMAN_BIN_OFFSET_inUse),
                    element->x + 6, element->y + 10, 3);
            } else if (slotState == slotStateAvailable) {
                if (_isSaving == 0) {
                    _printString((char*)(_textTable + VS_MCMAN_BIN_OFFSET_empty),
                        element->x + 6, element->y + 10, 3);
                } else {
                    _printString((char*)(_textTable + VS_MCMAN_BIN_OFFSET_new),
                        element->x + 6, element->y + 10, 0);
                }
            } else {
                y += 4 << 16;
                _printString(
                    (char*)&_textTable[_textTable[element->saveLocation
                                                  + VS_MCMAN_BIN_INDEX_saveLocations]],
                    element->x + 6, element->y + 4, 0);
                _drawSaveInfoUI(y | 172, vs_uiids_map);
                _drawSaveInfoUI(y | 189, vs_uiids_colon);
                var1 = saveInfo->unk4.stats.mapCompletion;

                if (var1 == 100) {
                    _drawInteger(y | 192, 100, 100);
                    _drawSaveInfoUI((y + 0xFFFF0000) | 207, vs_uiids_percent);
                } else {
                    _drawInteger(y | 192, var1, 10);
                    _drawSaveInfoUI((y + 0xFFFF0000) | 202, vs_uiids_percent);
                }
                _drawSaveInfoUI(y | 217, vs_uiids_save);
                _drawSaveInfoUI(y | 239, vs_uiids_colon);
                _drawInteger(y | 242, saveInfo->unk4.stats.cumulativeSaveCount, 1000);
                _drawSaveInfoUI(y | 267, vs_uiids_clear);
                _drawSaveInfoUI(y | 293, vs_uiids_colon);
                _drawInteger(y | 296, saveInfo->unk4.stats.clearCount, 10);
                y += 13 << 16;
                if (saveInfo->unk4.stats.clearCount != 0) {
                    _drawSprt(y | 69, vs_getUV0Clut(240, 16, 912, 223), vs_getWH(16, 16),
                        getTPage(clut4Bit, semiTransparencyHalf, 768, 0));
                }
                _drawSaveInfoUI(y | 240, vs_uiids_time);
                var1 = saveInfo->unk4.stats.gameTime.t.h;
                if (var1 == 100) {
                    _drawInteger(y | 263, var1, 100);
                } else {
                    _drawInteger(y | 268, var1, 10);
                }
                _drawSaveInfoUI(y | 279, vs_uiids_colon);
                _drawInteger(y | 282, saveInfo->unk4.stats.gameTime.t.m, 10);
                _drawSaveInfoUI(y | 293, vs_uiids_colon);
                _drawInteger(y | 296, saveInfo->unk4.stats.gameTime.t.s, 10);
                _drawHPMP(y | 88, statTypeHP, saveInfo->unk4.stats.currentHP,
                    saveInfo->unk4.stats.maxHP);
                _drawHPMP(y | 158, statTypeMP, saveInfo->unk4.stats.currentMP,
                    saveInfo->unk4.stats.maxMP);
                y -= 17 << 16;
            }
            if ((element->selected != 0) && (_fileProgressCounter != 0)) {
                if (_fileProgressCounter < 0) {
                    signed char* p = (_cursorFileOpSaturation + _fileProgressCounter++);
                    _fileProcessingCompleteAnim(-p[17], y);
                } else {
                    int new_var3 = 0x140;
                    _fileProcessingAnim(
                        _fileProgressPosition
                            + (((_fileProgressCounter - _filePreviousProgressCounter)
                                   * ((_loadSaveDataErrorOffset * 0x14)
                                       - (_fileProgressPosition - new_var3)))
                                / _fileProgressTarget),
                        y);
                }
            }
        }
    }
}

/**
 * Draws the menu elements, message area, cursor and fade.
 */
static void _drawFileMenu(int framebuf)
{
    int _[2];
    fileMenuElements_t* element;
    int j;
    int i;
    u_int x;
    int state;
    int new_var;

    element = _fileMenuElements;
    x = 0;
    if (framebuf != 0) {
        x = 320;
    }
    _drawSprt(vs_getXY(256, 176), vs_getUV0Clut(0, 176, 768, 227), vs_getWH(64, 64),
        getTPage(clut8Bit, semiTransparencyHalf, 768, 256));
    _drawSprt(vs_getXY(0, 176), vs_getUV0Clut(0, 176, 768, 227), vs_getWH(256, 64),
        getTPage(clut8Bit, semiTransparencyHalf, 640, 256));

    for (i = 0; i < 10; ++i, ++element) {
        state = element->state;
        if (state == fileMenuElementStateAnimateX) {
            if (element->x < element->targetPosition) {
                element->x += 32;
                if (element->x >= element->targetPosition) {
                    element->x = element->targetPosition;
                    element->state = fileMenuElementStateStatic;
                }
            } else {

                for (j = 1; j < 16; ++j) {
                    if ((element->targetPosition + _menuElementStops[j]) >= element->x) {
                        break;
                    }
                }
                element->x = element->targetPosition + _menuElementStops[j - 1];
                if (element->w < (320 - element->x)) {
                    element->w = 320 - element->x;
                }
                if (element->x == element->targetPosition) {
                    element->state = fileMenuElementStateStatic;
                }
            }
        }
        if (state == fileMenuElementStateAnimateY) {
            if (element->y > element->targetPosition) {
                for (j = 1; j < 16; ++j) {
                    if ((element->targetPosition + _menuElementStops[j]) >= element->y) {
                        break;
                    }
                }
                element->y = (element->targetPosition + _menuElementStops[j - 1]);
            }
            if (element->y == element->targetPosition) {
                element->state = fileMenuElementStateStatic;
            }
        }
        if (state == fileMenuElementStateAnimateNegX) {
            if (element->x < element->targetPosition) {
                for (j = 1; j < 16; ++j) {
                    if (element->x >= -_menuElementStops[j]) {
                        break;
                    }
                }
                element->x = -_menuElementStops[j - 1];
                if (element->x == 0) {
                    element->state = fileMenuElementStateStatic;
                }
            } else {
                element->x = element->x - 32;
                if (element->targetPosition >= element->x) {
                    element->x = element->targetPosition;
                    element->state = fileMenuElementStateStatic;
                }
            }
        }
        if (state != fileMenuElementStateInactive) {
            _drawFileMenuElement(element);
        }
    }

    for (i = 1; i < 4; ++i) {
        new_var = 256;
        _drawSprt(vs_getXY(0, 187 - i), (187 - i) << 8, vs_getWH(256, 1),
            (x >> 6) | (((4 - i) << 21) | new_var));
        _drawSprt(vs_getXY(256, 187 - i), (187 - i) << 8, vs_getWH(64, 1),
            (((int)(x + new_var)) >> 6) | (((4 - i) << 21) | new_var));
    }
    _drawSprt(vs_getXY(10, 181), vs_getUV0Clut(64, 145, 848, 223), vs_getWH(33, 7),
        getTPage(clut4Bit, semiTransparencyHalf, 768, 0)); // "Caution"
    DrawSync(0);
    _primBuf.tag = vs_getTag(_primBuf.prim.tile, primAddrNull);
    _primBuf.prim.tile.r0g0b0code = vs_getRGB0(primTile, 0, 0, 0);
    _primBuf.prim.tile.x0y0 = vs_getXY(0, 187);
    _primBuf.prim.tile.wh = vs_getWH(320, 52);
    DrawPrim(&_primBuf); // Message dialog background
    if (_selectCursorXy != 0) {
        _drawSprt(_selectCursorXy, vs_getUV0Clut(32, 48, 896, 223), vs_getWH(16, 16),
            (_cursorFileOpSaturation[_selectCursorColor] << 16)
                | getTPage(clut4Bit, semiTransparencyHalf, 768, 0));
        _selectCursorColor = (_selectCursorColor + 1) & 0xF;
        if (vs_main_buttonsPressed.all & PADRup) {
            vs_main_playSfxDefault(0x7E, VS_SFX_INVALID);
        }
    } else {
        _selectCursorColor = 0;
    }
    if (_memoryCardMessage != NULL) {
        _printString(_memoryCardMessage, 16, 192, 0);
    }
    if (_fileMenuScreenFade != 0) {
        DrawSync(0);
        _primBuf.tag = vs_getTag(_primBuf.prim.tile_tpage, primAddrNull);
        _primBuf.prim.tile_tpage.tpage =
            vs_getTpage(0, 0, direct16Bit, semiTransparencySubtract, ditheringOff);
        _primBuf.prim.tile_tpage.x0y0 = vs_getXY(0, 0);
        _primBuf.prim.tile_tpage.wh = vs_getWH(320, 224);
        _primBuf.prim.tile_tpage.r0g0b0code =
            vs_getRGB0Raw(primTileSemiTrans, _fileMenuScreenFade * vs_getRGB888(8, 8, 8));
        DrawPrim(&_primBuf);
    }
}

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
