#pragma once
#include "src/SLUS_010.40/gameState.h"
#include "src/SLUS_010.40/pad.h"
#include "src/SLUS_010.40/sound.h"

/* Load slot menu shared by the title and menu overlays. */

/**
 * Runs the paged load slot menu and applies the selected save asynchronously.
 *
 * A nonzero initPort initializes the menu; returns one after a successful
 * load, -1 on cancellation, or zero while active.
 */
static int showLoadFilesMenu(int initPort)
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
        slot = getNewestSaveFile();
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
            element = initFileMenuElement(
                i + 5, ((72 + i * 40) << 16) | 64, vs_getWH(256, 32), 0);
            element->slotId = i;
            element->slotUnavailable =
                saveSlotInfo[i].identity.base.slotState < slotStateInUse;
            element->saveLocation = saveSlotInfo[i].stats.saveLocation;
        }
        state = handleInput;
        memoryCardMessage = (char*)(textTable + VS_MCMAN_BIN_OFFSET_selectFile);
        // fallthrough
    case handleInput:
        if (vs_main_buttonsPressed.all & PADRdown) {
            vs_main_playSfxDefault(0x7E, VS_SFX_MENULEAVE);
            for (i = 5; i < 10; ++i) {
                clearFileMenuElement(i);
            }
            selectCursorXy = 0;
            return -1;
        }
        for (i = 0; i < 5; ++i) {
            fileMenuElements[i + 5].y = (((i - page) * 40) + 72);
            fileMenuElements[i + 5].selected = 0;
        }

        currentSlot = slot + page;

        if (vs_main_buttonsPressed.all & PADRright) {
            if (saveSlotInfo[currentSlot].identity.base.slotState >= slotStateInUse) {
                vs_main_playSfxDefault(0x7E, VS_SFX_MENUSELECT);
                fileMenuElements[currentSlot + 5].selected = 1;
                selectCursorXy = 0;
                memcardMaskedHandler(port + memcardEventMaskAll);
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
        selectCursorXy = ((slot * 40 + 62) << 16) | 24;
        fileMenuElements[currentSlot + 5].selected = 1;
        break;
    case startLoad:
        currentSlot = memcardMaskedHandler(0);
        if (currentSlot != memcardMaskedHandlerPending) {
            if (currentSlot >= memcardMaskedHandlerPending) {
                int new_var;
                loadSaveData(((slot + page) + 1) | (new_var = ((port - 1) << 16) | 256));
                state = applyLoad;
                memoryCardMessage = (char*)(textTable + VS_MCMAN_BIN_OFFSET_loading);
            } else {
                state = loaded;
            }
        }
        break;
    case applyLoad:
        currentSlot = loadSaveData(0);
        ++fileProgressCounter;
        if (currentSlot != 0) {
            fileProgressCounter = 0;
            do {
                leaveTimer = 0;
                if (currentSlot < 0) {
                    memoryCardMessage =
                        (char*)(textTable + VS_MCMAN_BIN_OFFSET_loadfailed);
                    break;
                }
                switch (applyLoadedSaveFile(1)) {
                case 0:
                    fileProgressCounter = -16;
                    vs_main_playSfxDefault(0x7E, VS_SFX_FILEOPCOMPLETE);
                    leaveTimer = 16;
                    fileLoaded = 1;
                    memoryCardMessage = (char*)(textTable + VS_MCMAN_BIN_OFFSET_loaded);
                    break;
                case 1:
                    memoryCardMessage =
                        (char*)(textTable + VS_MCMAN_BIN_OFFSET_fileCorruptDescription);
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
                clearFileMenuElement(i);
            }
        }
        return fileLoaded;
    }
    return 0;
}
