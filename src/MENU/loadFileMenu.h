#pragma once

/* Load menu shared by the title and menu overlays. The including file defines
 * LOAD_FILE_MENU_PAD, the size of the alignment filler after the menu state, and
 * FILE_MENU_RESTORE_CURSOR and FILE_MENU_STORE_CURSOR (cursor memory, using
 * selectedFile). */


/**
 * Runs the initial slot chooser and asynchronous load flow for game over/data
 * menus.
 *
 * A nonzero initFadeout initializes the menu; returns one when a save is
 * selected, -1 when cancelled, or zero while active.
 */
static int _loadFileMenu(int initFadeout)
{
    enum state {
        init = 0,
        displaySlot1 = 1,
        displaySlot2 = 2,
        waitForSlotAnimation = 3,
        handleInput = 4,
        slotSelected = 5,
        exit = 6,
        fadeAndReturnSelected = 7,
        fadeAndReturnNotSelected = 8,
    };

    static char state;
    static u_char selectedFile;
    static char fadeout;
    static char _[LOAD_FILE_MENU_PAD] __attribute__((unused));

    fileMenuElements_t* element;
    int i;

    if (initFadeout != 0) {
        fadeout = initFadeout - 1;
        selectedFile = 1;

        FILE_MENU_RESTORE_CURSOR();
        _isSaving = 0;
        state = init;
        return 0;
    }
    switch (state) {
    case init:
        element = _initFileMenuElement(0, vs_getXY(320, 34), vs_getWH(140, 12),
            (char*)(_textTable + VS_MCMAN_BIN_OFFSET_load));
        element->state = fileMenuElementStateAnimateX;
        element->targetPosition = 180;
        element->selected = 1;
        element->innertextBlendFactor = 8;
        state = displaySlot1;
        break;
    case displaySlot1:
        if (_fileMenuElementsActive() != 0) {
            element = _initFileMenuElement(1, vs_getXY(320, 50), vs_getWH(126, 12),
                (char*)(_textTable + VS_MCMAN_BIN_OFFSET_slot1));
            element->state = fileMenuElementStateAnimateX;
            element->targetPosition = 194;
            state = displaySlot2;
        }
        break;
    case displaySlot2:
        element = _initFileMenuElement(2, vs_getXY(320, 66), vs_getWH(126, 12),
            (char*)(_textTable + VS_MCMAN_BIN_OFFSET_slot2));
        element->state = fileMenuElementStateAnimateX;
        element->targetPosition = 194;
        state = waitForSlotAnimation;
        break;
    case waitForSlotAnimation:
        if (_fileMenuElementsActive() != 0) {
            state = handleInput;
            _memoryCardMessage = (char*)(_textTable + VS_MCMAN_BIN_OFFSET_selectSlot);
        }
        break;
    case handleInput:
        _fileMenuElements[selectedFile].selected = 1;
        _fileMenuElements[3 - selectedFile].selected = 0;
        if (vs_main_buttonsPressed.all & PADRdown) {
            vs_main_playSfxDefault(0x7E, VS_SFX_MENULEAVE);
            _selectCursorXy = 0;
            for (i = 0; i < 3; ++i) {
                _fileMenuElements[i].state = fileMenuElementStateAnimateX;
                _fileMenuElements[i].targetPosition = 320;
            }
            state = exit;
        } else if (vs_main_buttonsPressed.all & PADRright) {
            vs_main_playSfxDefault(0x7E, VS_SFX_MENUSELECT);
            _selectLoadMemoryCard(selectedFile);
            _selectCursorXy = 0;
            state = slotSelected;
        } else {
            if (vs_main_buttonRepeat & (PADLup | PADLdown)) {
                vs_main_playSfxDefault(0x7E, VS_SFX_MENUCHANGE);
                selectedFile = 3 - selectedFile;
                FILE_MENU_STORE_CURSOR();
            }
            _selectCursorXy = ((((selectedFile + 1) * 16) + 10) << 16) | 180;
        }
        break;
    case slotSelected:
        element = (fileMenuElements_t*)_selectLoadMemoryCard(0);
        if (element != 0) {
            if ((long)element < 0) {
                state = displaySlot1;
            } else {
                state = fadeAndReturnSelected;
            }
        }
        break;
    case exit:
        if (_fileMenuElementsActive() != 0) {
            if (fadeout == 0) {
                return -1;
            }
            state = fadeAndReturnNotSelected;
        }
        break;
    case fadeAndReturnSelected:
        if (++_fileMenuScreenFade > 30) {
            return 1;
        }
        break;
    case fadeAndReturnNotSelected:
        if (++_fileMenuScreenFade < 31) {
            break;
        }
        return -1;
    }
    return 0;
}
