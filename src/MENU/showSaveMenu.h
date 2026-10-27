#pragma once

/* Save menu shared by the title and menu overlays. The including file defines
 * FILE_MENU_RESTORE_CURSOR, FILE_MENU_STORE_CURSOR (cursor memory, using selectedFile)
 * and SAVE_MENU_CLEAR_INFO (clears the info message using clear). */

/**
 * Runs the save/container slot chooser and handles unsaved container data.
 *
 * A nonzero initState initializes the requested entry state; returns one when
 * a card-save flow completes, -1 when leaving without saving, or zero pending.
 */
static int _showSaveMenu(int initState)
{
    enum state {
        init = 0,
        saveExists = 1,
        loadSave = 2,
        initSlot1 = 3,
        initSlot2 = 4,
        waitForSlotAnimation = 5,
        handleInput = 6,
        selectCard = 7,
        returnNoSave = 8,
        containerWarn = 9,
        eraseContainerData = 10,
        discardChanges = 11,
    };

    static char state;
    static u_char selectedFile;
    static char _[3] __attribute__((unused));

    u_short clear = vs_char_terminator | (vs_char_terminator << 8);
    fileMenuElements_t* element;
    int currentSave;
    int val;

    if (initState != 0) {
        selectedFile = 1;
        _containerDataEmpty = 0;
        FILE_MENU_RESTORE_CURSOR();
        _dataNotSaved = 0;
        _isSaving = 1;
        state = (initState - 1) * 3;
        element = _initFileMenuElement(0, vs_getXY(320, 34), vs_getWH(140, 12),
            (char*)(_textTable + VS_MCMAN_BIN_OFFSET_save));
        element->state = fileMenuElementStateAnimateX;
        element->targetPosition = 180;
        element->innertextBlendFactor = 8;
        element->selected = 1;
        _memoryCardMessage = 0;
        SAVE_MENU_CLEAR_INFO();
        return 0;
    }

    switch (state) {
    case init:
        if (*(int*)&vs_main_settings & 0x10) {
            memset(&((savedata_t*)_spmcimg + 1)->containerData, 0,
                sizeof((savedata_t*)_spmcimg + 1)->containerData);
            state = initSlot1;
        } else if (_fileMenuElementsActive() != 0) {
            if (vs_main_settings.slotState != slotStateUnavailable) {
                _findCurrentSave(1);
                state = saveExists;
            } else {
                state = initSlot1;
            }
        }
        break;
    case saveExists:
        currentSave = _findCurrentSave(0);
        if (currentSave == findSavePending) {
            break;
        }
        if (currentSave < findSavePending) {
            _memoryCardMessage = (char*)(_textTable
                                         + (currentSave == findSaveTimeout
                                                 ? VS_MCMAN_BIN_OFFSET_insertError
                                                 : VS_MCMAN_BIN_OFFSET_emptyCard));
            state = containerWarn;
        } else {
            _loadSaveData((currentSave & 7) | ((currentSave & 16) << 12));
            state = loadSave;
        }
        break;
    case loadSave:
        val = _loadSaveData(0);
        if (val != 0) {
            if ((val <= 0) || (_applyLoadedSaveFile(0) != 0)) {
                state = containerWarn;
                _memoryCardMessage = (char*)(_textTable + VS_MCMAN_BIN_OFFSET_emptyCard);
            } else {
                state = initSlot1;
            }
        }
        break;
    case initSlot1:
        if (_fileMenuElementsActive() != 0) {
            element = _initFileMenuElement(1, vs_getXY(320, 50), vs_getWH(126, 12),
                (char*)(_textTable + VS_MCMAN_BIN_OFFSET_slot1));
            element->state = fileMenuElementStateAnimateX;
            element->targetPosition = 194;
            state = initSlot2;
        }
        break;
    case initSlot2:
        element = _initFileMenuElement(2, vs_getXY(320, 66), vs_getWH(126, 12),
            (char*)(_textTable + VS_MCMAN_BIN_OFFSET_slot2));
        element->state = fileMenuElementStateAnimateX;
        element->targetPosition = 194;
        state = waitForSlotAnimation;
        break;
    case waitForSlotAnimation:
        if (_fileMenuElementsActive() != 0) {
            SAVE_MENU_CLEAR_INFO();
            state = handleInput;
            _memoryCardMessage = (char*)(_textTable + VS_MCMAN_BIN_OFFSET_selectSlot);
        }
        break;
    case handleInput:
        _fileMenuElements[selectedFile].selected = 1;
        _fileMenuElements[3 - selectedFile].selected = 0;
        if (vs_main_buttonsPressed.all & PADRdown) {
            vs_main_playSfxDefault(0x7E, VS_SFX_MENULEAVE);
            val = _dataNotSaved;
            _selectCursorXy = 0;
            if (val < 3) {
                do {
                    _fileMenuElements[val].state = fileMenuElementStateAnimateX;
                    _fileMenuElements[val].targetPosition = 320;
                    ++val;
                } while (val < 3);
            }
            if (_dataNotSaved != 0) {
                _memoryCardMessage =
                    (char*)(_textTable + VS_MCMAN_BIN_OFFSET_containerWarnDataLoss);
                _promptConfirm(1);
                state = discardChanges;
            } else {
                state = returnNoSave;
            }
        } else if (vs_main_buttonsPressed.all & PADRright) {
            vs_main_playSfxDefault(0x7E, VS_SFX_MENUSELECT);
            _selectSaveMemoryCard(selectedFile);
            _selectCursorXy = 0;
            state = selectCard;
        } else {
            if (vs_main_buttonRepeat & (PADLup | PADLdown)) {
                vs_main_playSfxDefault(0x7E, VS_SFX_MENUCHANGE);
                selectedFile = 3 - selectedFile;
                FILE_MENU_STORE_CURSOR();
            }
            _selectCursorXy = vs_getXY(180, (selectedFile + 1) * 16 + 10);
        }
        break;
    case selectCard:
        val = _selectSaveMemoryCard(0);
        if (val != 0) {
            if (val < 0) {
                state = initSlot1;
                break;
            }
            _initFileMenu();
            return 1;
        }
        break;
    case returnNoSave:
        if (_fileMenuElementsActive() != 0) {
            return -1;
        }
        break;
    case containerWarn:
        if (vs_main_buttonsPressed.pad[0].low != 0) {
            SAVE_MENU_CLEAR_INFO();
            _memoryCardMessage = (char*)(_textTable + VS_MCMAN_BIN_OFFSET_containerWarn);
            _promptConfirm(1);
            state = eraseContainerData;
        }
        break;
    case eraseContainerData:
    case discardChanges:
        val = _promptConfirm(0);
        if (val != 0) {
            if (state == discardChanges) {
                if (val > 0) {
                    *(int*)&vs_main_settings = *(int*)&vs_main_settings | 0x10;
                }
                val = -val;
            }
            if (val < 0) {
                _fileMenuElements[0].state = fileMenuElementStateAnimateX;
                _fileMenuElements[0].targetPosition = 320;
                state = returnNoSave;
                break;
            }
            if (state == eraseContainerData) {
                _containerDataEmpty = 1;
                memset(&((savedata_t*)_spmcimg + 1)->containerData, 0,
                    sizeof((savedata_t*)_spmcimg + 1)->containerData);
            }
            state = initSlot1;
        }
        break;
    }
    return 0;
}
