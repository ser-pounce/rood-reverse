#pragma once

/* Save slot menu shared by the title and menu overlays. The including file defines
 * PLAY_INVALID_SFX. */

static char _dataNotSaved;
static char _containerDataEmpty;
static char _backupMainSetting;

/**
 * Runs the paged save-slot menu and its overwrite, save and verification flow.
 *
 * A nonzero initPort initializes the menu; polling returns one after a save,
 * -1 when leaving without saving, or zero while active.
 */
static int _showSaveFilesMenu(int initPort)
{
    enum state {
        init = 0,
        handleInput = 1,
        slotSelected = 2,
        overwritePrompt = 3,
        initOverwrite = 4,
        save = 5,
        validate = 6,
        leaveWithTimer = 7,
        leave = 8,
        format = 9,
        leaveError = 10
    };

    static vs_main_settings_t settingsBackup;
    static int saveSuccessful;
    static char state;
    static char port;
    static char page;
    static char slot;
    static char leaveTimer;

    fileMenuElements_t* element;
    int val;
    int saveId;
    int i;

    if (initPort != 0) {
        port = initPort;
        slot = _findCurrentSaveOnActiveMemcard();
        if (slot) {
            --slot;
        }
        page = 0;
        if (slot == 4) {
            page = 2;
            slot = 2;
        } else if (slot != 0) {
            page = slot - 1;
            slot = 1;
        }
        saveSuccessful = -1;
        leaveTimer = 0;
        state = init;
        return 0;
    }
    switch (state) {
    case init:
        for (i = 0; i < 5; ++i) {
            element = _initFileMenuElement(
                i + 5, vs_getXY(64, i * 40 + 72), vs_getWH(256, 32), 0);
            element->slotId = i;
            element->slotUnavailable =
                _saveFileInfo[i].unk4.base.slotState == slotStateUnavailable;
            element->saveLocation = _saveFileInfo[i].unk4.stats.saveLocation;
        }
        state = handleInput;
        /* fallthrough */
    case handleInput:
        _memoryCardMessage = (char*)(_textTable + VS_MCMAN_BIN_OFFSET_selectFile);
        if (vs_main_buttonsPressed.all & PADRdown) {
            vs_main_playSfxDefault(0x7E, VS_SFX_MENULEAVE);
            _selectCursorXy = 0;
            state = leave;
        } else {
            for (i = 0; i < 5; ++i) {
                _fileMenuElements[i + 5].y = ((i - page) * 40) + 72;
                _fileMenuElements[i + 5].selected = 0;
            }
            val = slot + page;
            if (vs_main_buttonsPressed.all & PADRright) {
                if (_saveFileInfo[val].unk4.base.slotState != slotStateUnavailable) {
                    vs_main_playSfxDefault(0x7E, VS_SFX_MENUSELECT);
                    _fileMenuElements[val + 5].selected = 1;
                    _selectCursorXy = 0;
                    _memcardMaskedHandler(port + memcardEventMaskAll);
                    state = slotSelected;
                    break;
                } else {
                    PLAY_INVALID_SFX();
                }
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
            if (val != (slot + page)) {
                vs_main_playSfxDefault(0x7E, VS_SFX_MENUCHANGE);
            }
            _selectCursorXy = vs_getXY(24, slot * 40 + 62);
            _fileMenuElements[val + 5].selected = 1;
        }
        break;
    case slotSelected:
        val = _memcardMaskedHandler(0);
        if (val != memcardMaskedHandlerPending) {
            if (_memoryCardMessage == (char*)(_textTable + VS_MCMAN_BIN_OFFSET_noData)) {
                _promptFormat(port);
                state = format;
            } else if (val > memcardMaskedHandlerError) {
                val = slot + page;
                if (_saveFileInfo[val].unk4.base.slotState == slotStateAvailable) {
                    if (_createSaveFile(port, val + 1) != 0) {
                        state = leaveWithTimer;
                        _memoryCardMessage =
                            (char*)(_textTable + VS_MCMAN_BIN_OFFSET_saveFailed);
                    } else {
                        state = save;
                    }
                } else {
                    _promptOverwrite(1);
                    state = overwritePrompt;
                }
            } else {
                state = leaveWithTimer;
            }
        }
        break;
    case overwritePrompt:
        val = _promptOverwrite(0);
        if (val != 0) {
            if (val == 1) {
                _memcardMaskedHandler(port + memcardEventMaskAll);
                state = initOverwrite;
            } else {
                state = handleInput;
            }
        }
        break;
    case initOverwrite:
        val = _memcardMaskedHandler(0);
        if (val != memcardMaskedHandlerPending) {
            if (val > memcardMaskedHandlerError) {
                _dataNotSaved |= (_findCurrentSaveOnActiveMemcard() == (slot + page + 1));
                state = save;
            } else {
                state = leaveWithTimer;
            }
        }
        break;
    case save:
        val = slot + page;
        _memoryCardMessage = (char*)(_textTable + VS_MCMAN_BIN_OFFSET_saving);
        _rMemcpy(&settingsBackup, &vs_main_settings, sizeof settingsBackup);
        _rMemcpy(
            (savedata_t*)_spmcimg + 2, (savedata_t*)_spmcimg + 1, sizeof(savedata_t));
        if (_containerDataEmpty != 0) {
            _backupMainSetting = (*(u_int*)&vs_main_settings >> 4) & 1;
            *(int*)&vs_main_settings |= 0x10;
        }
        _packageGameSaveData(val);
        _saveFile((val + 1) | ((port - 1) << 0x10));
        state = validate;
        break;
    case validate:
        val = _saveFile(0);
        ++_fileProgressCounter;
        if (val != 0) {
            vs_main_stateFlags.doorEntered = 0;
            saveId = slot + page;
            if (val < 0) {
                if (_containerDataEmpty != 0) {
                    char v = _backupMainSetting & 1;
                    *(int*)&vs_main_settings =
                        (*(int*)&vs_main_settings & ~0x10) | (v * 0x10);
                }
                memset(&_saveFileInfo[saveId], 0, sizeof _saveFileInfo[saveId]);
                _saveFileInfo[saveId].unk4.base.slotState = slotStateTemporary;
                _fileMenuElements[saveId + 5].saveLocation = 0;
                _rMemcpy((savedata_t*)_spmcimg + 1, (savedata_t*)_spmcimg + 2,
                    sizeof(savedata_t));
                _fileProgressCounter = 0;
                _rMemcpy(&vs_main_settings, &settingsBackup, sizeof vs_main_settings);
                _memoryCardMessage = (char*)(_textTable + VS_MCMAN_BIN_OFFSET_saveFailed);
            } else {
                _dataNotSaved = 0;
                _fileProgressCounter = -16;
                _rMemcpy(&_saveFileInfo[saveId],
                    _spmcimg + sizeof _saveFileInfo[saveId] * 3,
                    sizeof _saveFileInfo[saveId]);
                _decode(_saveFileInfo[saveId].key,
                    &_saveFileInfo[saveId].unk4.base.slotState,
                    sizeof _saveFileInfo[saveId] - sizeof(int));
                _fileMenuElements[saveId + 5].saveLocation =
                    _saveFileInfo[saveId].unk4.stats.saveLocation;
                vs_main_playSfxDefault(0x7E, VS_SFX_FILEOPCOMPLETE);
                saveSuccessful = 1;
                _memoryCardMessage = (char*)(_textTable + VS_MCMAN_BIN_OFFSET_saved);
            }
            state = leaveWithTimer;
        }
        break;
    case leaveWithTimer:
        if (saveSuccessful == 1) {
            ++leaveTimer;
        }
        if (vs_main_buttonsPressed.pad[0].low == 0) {
            if (leaveTimer != 150) {
                break;
            }
        }
        vs_main_playSfxDefault(0x7E, VS_SFX_MENULEAVE);
        state = leave;
        break;
    case leave:
        if (_fileProgressCounter == 0) {
            for (i = 5; i < 10; ++i) {
                _clearFileMenuElement(i);
            }
            return saveSuccessful;
        }
        break;
    case format:
        val = _promptFormat(0);
        if (val != 0) {
            if (val < 0) {
                state = leaveError;
            } else if (_createSaveFile(port, page + slot + 1) != 0) {
                state = leaveWithTimer;
                _memoryCardMessage = (char*)(_textTable + VS_MCMAN_BIN_OFFSET_saveFailed);
            } else {
                state = save;
            }
        }
        break;
    case leaveError:
        if (vs_main_buttonsPressed.pad[0].low != 0) {
            vs_main_playSfxDefault(0x7E, VS_SFX_MENULEAVE);
            for (i = 5; i < 10; ++i) {
                _clearFileMenuElement(i);
            }
            return -1;
        }
        break;
    }
    return 0;
}
