#pragma once
#include "src/SLUS_010.40/gameFlags.h"
#include "src/SLUS_010.40/gameState.h"
#include "src/SLUS_010.40/pad.h"
#include "src/SLUS_010.40/sound.h"

/* Save slot menu shared by the title and menu overlays. The including file defines
 * PLAY_INVALID_SFX. */

static char dataNotSaved;
static char containerDataEmpty;
static char backupMainSetting;

/**
 * Runs the paged save-slot menu and its overwrite, save and verification flow.
 *
 * A nonzero initPort initializes the menu; polling returns one after a save,
 * -1 when leaving without saving, or zero while active.
 */
static int showSaveFilesMenu(int initPort)
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

    static vs_Settings settingsBackup;
    static int saveSuccessful;
    static char state;
    static char port;
    static char page;
    static char slot;
    static char leaveTimer;

    vs_FileMenuElements* element;
    int val;
    int saveId;
    int i;

    if (initPort != 0) {
        port = initPort;
        slot = findCurrentSaveOnActiveMemcard();
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
            element = initFileMenuElement(
                i + 5, vs_getXY(64, i * 40 + 72), vs_getWH(256, 32), 0);
            element->slotId = i;
            element->slotUnavailable =
                saveSlotInfo[i].identity.base.slotState == slotStateUnavailable;
            element->saveLocation = saveSlotInfo[i].stats.saveLocation;
        }
        state = handleInput;
        /* fallthrough */
    case handleInput:
        memoryCardMessage = (char*)(textTable + VS_MCMAN_BIN_OFFSET_selectFile);
        if (vs_main_buttonsPressed.all & PADRdown) {
            vs_main_playSfxDefault(0x7E, VS_SFX_MENULEAVE);
            selectCursorXy = 0;
            state = leave;
        } else {
            for (i = 0; i < 5; ++i) {
                fileMenuElements[i + 5].y = ((i - page) * 40) + 72;
                fileMenuElements[i + 5].selected = 0;
            }
            val = slot + page;
            if (vs_main_buttonsPressed.all & PADRright) {
                if (saveSlotInfo[val].identity.base.slotState != slotStateUnavailable) {
                    vs_main_playSfxDefault(0x7E, VS_SFX_MENUSELECT);
                    fileMenuElements[val + 5].selected = 1;
                    selectCursorXy = 0;
                    memcardMaskedHandler(port + memcardEventMaskAll);
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
            selectCursorXy = vs_getXY(24, slot * 40 + 62);
            fileMenuElements[val + 5].selected = 1;
        }
        break;
    case slotSelected:
        val = memcardMaskedHandler(0);
        if (val != memcardMaskedHandlerPending) {
            if (memoryCardMessage == (char*)(textTable + VS_MCMAN_BIN_OFFSET_noData)) {
                promptFormat(port);
                state = format;
            } else if (val > memcardMaskedHandlerError) {
                val = slot + page;
                if (saveSlotInfo[val].identity.base.slotState == slotStateAvailable) {
                    if (createSaveFile(port, val + 1) != 0) {
                        state = leaveWithTimer;
                        memoryCardMessage =
                            (char*)(textTable + VS_MCMAN_BIN_OFFSET_saveFailed);
                    } else {
                        state = save;
                    }
                } else {
                    promptOverwrite(1);
                    state = overwritePrompt;
                }
            } else {
                state = leaveWithTimer;
            }
        }
        break;
    case overwritePrompt:
        val = promptOverwrite(0);
        if (val != 0) {
            if (val == 1) {
                memcardMaskedHandler(port + memcardEventMaskAll);
                state = initOverwrite;
            } else {
                state = handleInput;
            }
        }
        break;
    case initOverwrite:
        val = memcardMaskedHandler(0);
        if (val != memcardMaskedHandlerPending) {
            if (val > memcardMaskedHandlerError) {
                dataNotSaved |= (findCurrentSaveOnActiveMemcard() == (slot + page + 1));
                state = save;
            } else {
                state = leaveWithTimer;
            }
        }
        break;
    case save:
        val = slot + page;
        memoryCardMessage = (char*)(textTable + VS_MCMAN_BIN_OFFSET_saving);
        rMemcpy(&settingsBackup, &vs_main_settings, sizeof settingsBackup);
        rMemcpy((vs_Savedata*)mcImageBuf + 2, (vs_Savedata*)mcImageBuf + 1,
            sizeof(vs_Savedata));
        if (containerDataEmpty != 0) {
            backupMainSetting = vs_main_settings.containerEmpty;
            vs_main_settings.containerEmpty = 1;
        }
        packageGameSaveData(val);
        saveFile((val + 1) | ((port - 1) << 0x10));
        state = validate;
        break;
    case validate:
        val = saveFile(0);
        ++fileProgressCounter;
        if (val != 0) {
            vs_main_stateFlags.doorEntered = 0;
            saveId = slot + page;
            if (val < 0) {
                if (containerDataEmpty != 0) {
                    vs_main_settings.containerEmpty = backupMainSetting;
                }
                memset(&saveSlotInfo[saveId], 0, sizeof saveSlotInfo[saveId]);
                saveSlotInfo[saveId].identity.base.slotState = slotStateTemporary;
                fileMenuElements[saveId + 5].saveLocation = 0;
                rMemcpy((vs_Savedata*)mcImageBuf + 1, (vs_Savedata*)mcImageBuf + 2,
                    sizeof(vs_Savedata));
                fileProgressCounter = 0;
                rMemcpy(&vs_main_settings, &settingsBackup, sizeof vs_main_settings);
                memoryCardMessage = (char*)(textTable + VS_MCMAN_BIN_OFFSET_saveFailed);
            } else {
                dataNotSaved = 0;
                fileProgressCounter = -16;
                rMemcpy(&saveSlotInfo[saveId],
                    mcImageBuf + sizeof saveSlotInfo[saveId] * 3,
                    sizeof saveSlotInfo[saveId]);
                decode(saveSlotInfo[saveId].identity.key,
                    &saveSlotInfo[saveId].identity.base.slotState,
                    sizeof saveSlotInfo[saveId] - sizeof(int));
                fileMenuElements[saveId + 5].saveLocation =
                    saveSlotInfo[saveId].stats.saveLocation;
                vs_main_playSfxDefault(0x7E, VS_SFX_FILEOPCOMPLETE);
                saveSuccessful = 1;
                memoryCardMessage = (char*)(textTable + VS_MCMAN_BIN_OFFSET_saved);
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
        if (fileProgressCounter == 0) {
            for (i = 5; i < 10; ++i) {
                clearFileMenuElement(i);
            }
            return saveSuccessful;
        }
        break;
    case format:
        val = promptFormat(0);
        if (val != 0) {
            if (val < 0) {
                state = leaveError;
            } else if (createSaveFile(port, page + slot + 1) != 0) {
                state = leaveWithTimer;
                memoryCardMessage = (char*)(textTable + VS_MCMAN_BIN_OFFSET_saveFailed);
            } else {
                state = save;
            }
        }
        break;
    case leaveError:
        if (vs_main_buttonsPressed.pad[0].low != 0) {
            vs_main_playSfxDefault(0x7E, VS_SFX_MENULEAVE);
            for (i = 5; i < 10; ++i) {
                clearFileMenuElement(i);
            }
            return -1;
        }
        break;
    }
    return 0;
}
