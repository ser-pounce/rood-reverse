#pragma once

/* Load slot menu shared by the title and menu overlays. */

/**
 * Runs the paged load slot menu and applies the selected save asynchronously.
 *
 * A nonzero initPort initializes the menu; returns one after a successful
 * load, -1 on cancellation, or zero while active.
 */
static int _showLoadFilesMenu(int initPort)
{
    enum state {
        init = 0,
        handleInput = 1,
        startLoad = 2,
        applyLoad = 3,
        loaded = 4,
        exiting = 5
    };

    static vs_Gametime_t backupTime;
    static int fileLoaded;
    static char state;
    static char port;
    static char page;
    static char slot;
    static char leaveTimer;
    static char completeTimer;

    fileMenuElements_t* element;
    int currentSlot;
    int i;

    if (initPort != 0) {
        port = initPort;
        slot = _getNewestSaveFile();
        page = 0;
        if (slot == 4) {
            page = 2;
            slot = 2;
        } else if (slot != 0) {
            page = slot - 1;
            slot = 1;
        }
        fileLoaded = -1;
        completeTimer = 0;
        state = init;
        return 0;
    }
    switch (state) {
    case init:
        for (i = 0; i < 5; ++i) {
            element = _initFileMenuElement(
                i + 5, ((72 + i * 40) << 16) | 64, vs_getWH(256, 32), 0);
            element->slotId = i;
            element->slotUnavailable =
                _saveFileInfo[i].unk4.base.slotState < slotStateInUse;
            element->saveLocation = _saveFileInfo[i].unk4.stats.saveLocation;
        }
        state = handleInput;
        _memoryCardMessage = (char*)(_textTable + VS_MCMAN_BIN_OFFSET_selectFile);
        // fallthrough
    case handleInput:
        if (vs_main_buttonsPressed.all & PADRdown) {
            vs_main_playSfxDefault(0x7E, VS_SFX_MENULEAVE);
            for (i = 5; i < 10; ++i) {
                _clearFileMenuElement(i);
            }
            _selectCursorXy = 0;
            return -1;
        }
        for (i = 0; i < 5; ++i) {
            _fileMenuElements[i + 5].y = (((i - page) * 40) + 72);
            _fileMenuElements[i + 5].selected = 0;
        }

        currentSlot = slot + page;

        if (vs_main_buttonsPressed.all & PADRright) {
            if (_saveFileInfo[currentSlot].unk4.base.slotState >= slotStateInUse) {
                vs_main_playSfxDefault(0x7E, VS_SFX_MENUSELECT);
                _fileMenuElements[currentSlot + 5].selected = 1;
                _selectCursorXy = 0;
                _memcardMaskedHandler(port + memcardEventMaskAll);
                state = startLoad;
                break;
            }
            vs_main_playSfxDefault(0x7E, VS_SFX_INVALID);
        }
        if (vs_main_buttonRepeat & PADLup) {
            if (slot == 0) {
                if (page != 0) {
                    --page;
                }
            } else {
                --slot;
            }
        }
        if (vs_main_buttonRepeat & PADLdown) {
            if (slot == 2) {
                if (page < 2) {
                    ++page;
                }
            } else {
                ++slot;
            }
        }
        if (currentSlot != (slot + page)) {
            vs_main_playSfxDefault(0x7E, VS_SFX_MENUCHANGE);
        }
        _selectCursorXy = ((slot * 40 + 62) << 16) | 24;
        _fileMenuElements[currentSlot + 5].selected = 1;
        break;
    case startLoad:
        currentSlot = _memcardMaskedHandler(0);
        if (currentSlot != memcardMaskedHandlerPending) {
            if (currentSlot >= memcardMaskedHandlerPending) {
                int new_var;
                _loadSaveData(((slot + page) + 1) | (new_var = ((port - 1) << 16) | 256));
                state = applyLoad;
                _memoryCardMessage = (char*)(_textTable + VS_MCMAN_BIN_OFFSET_loading);
            } else {
                state = loaded;
            }
        }
        break;
    case applyLoad:
        currentSlot = _loadSaveData(0);
        ++_fileProgressCounter;
        if (currentSlot != 0) {
            _fileProgressCounter = 0;
            do {
                leaveTimer = 0;
                if (currentSlot < 0) {
                    _memoryCardMessage =
                        (char*)(_textTable + VS_MCMAN_BIN_OFFSET_loadfailed);
                    break;
                }
                switch (_applyLoadedSaveFile(1)) {
                case 0:
                    _fileProgressCounter = -16;
                    vs_main_playSfxDefault(0x7E, VS_SFX_FILEOPCOMPLETE);
                    leaveTimer = 16;
                    fileLoaded = 1;
                    _memoryCardMessage = (char*)(_textTable + VS_MCMAN_BIN_OFFSET_loaded);
                    break;
                case 1:
                    _memoryCardMessage =
                        (char*)(_textTable + VS_MCMAN_BIN_OFFSET_fileCorruptDescription);
                    break;
                }
            } while (0);

            backupTime.t = vs_main_gametime.t;
            state = loaded;
        }
        break;
    case loaded:
        if (leaveTimer != 0) {
            --leaveTimer;
        }
        if (fileLoaded == 1) {
            ++completeTimer;
        }
        if ((vs_main_buttonsPressed.pad[0].low != 0) || (completeTimer == 150)) {
            if (fileLoaded < 0) {
                vs_main_playSfxDefault(0x7E, VS_SFX_MENULEAVE);
            }
            state = exiting;
        }
        break;
    case exiting:
        if (leaveTimer != 0) {
            --leaveTimer;
            break;
        }
        if (fileLoaded == 1) {
            vs_main_gametime.t = backupTime.t;
        } else {
            for (i = 5; i < 10; ++i) {
                _clearFileMenuElement(i);
            }
        }
        return fileLoaded;
    }
    return 0;
}
