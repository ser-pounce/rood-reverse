#pragma once
#include "common.h"
#include "src/SLUS_010.40/gameState.h"
#include "src/SLUS_010.40/pad.h"
#include "src/SLUS_010.40/sound.h"

/* Save menu shared by the title and menu overlays. The including file defines
 * FILE_MENU_RESTORE_CURSOR, FILE_MENU_STORE_CURSOR (cursor memory, using selectedFile)
 * and SAVE_MENU_CLEAR_INFO (clears the info message using clear). All default to doing
 * nothing. */

#ifndef FILE_MENU_RESTORE_CURSOR
#define FILE_MENU_RESTORE_CURSOR()
#endif
#ifndef FILE_MENU_STORE_CURSOR
#define FILE_MENU_STORE_CURSOR()
#endif
#ifndef SAVE_MENU_CLEAR_INFO
#define SAVE_MENU_CLEAR_INFO()
#endif

/**
 * Runs the save/container slot chooser and handles unsaved container data.
 *
 * A nonzero initState initializes the requested entry state; returns one when
 * a card-save flow completes, -1 when leaving without saving, or zero pending.
 */
static int showSaveMenu(int initState)
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
    static UNUSED char _[3];

    u_short clear = vs_char_terminator | (vs_char_terminator << 8);
    fileMenuElements_t* element;
    int currentSave;
    int val;

    if (initState != 0) {
        selectedFile = 1;
        containerDataEmpty = 0;
        FILE_MENU_RESTORE_CURSOR();
        dataNotSaved = 0;
        isSaving = 1;
        state = (initState - 1) * 3;
        element = initFileMenuElement(0, vs_getXY(320, 34), vs_getWH(140, 12),
            (char*)(textTable + VS_MCMAN_BIN_OFFSET_save));
        element->state = fileMenuElementStateAnimateX;
        element->targetPosition = 180;
        element->innertextBlendFactor = 8;
        element->selected = 1;
        memoryCardMessage = 0;
        SAVE_MENU_CLEAR_INFO();
        return 0;
    }

    switch (state) {
    case init:
        if (vs_main_settings.containerEmpty) {
            memset(&((savedata_t*)spmcimgStatic + 1)->containerData, 0,
                sizeof((savedata_t*)spmcimgStatic + 1)->containerData);
            state = initSlot1;
        } else if (fileMenuElementsActive() != 0) {
            if (vs_main_settings.slotState != slotStateUnavailable) {
                findCurrentSave(1);
                state = saveExists;
            } else {
                state = initSlot1;
            }
        }
        break;
    case saveExists:
        currentSave = findCurrentSave(0);
        if (currentSave == findSavePending) {
            break;
        }
        if (currentSave < findSavePending) {
            memoryCardMessage = (char*)(textTable
                                        + (currentSave == findSaveTimeout
                                                ? VS_MCMAN_BIN_OFFSET_insertError
                                                : VS_MCMAN_BIN_OFFSET_emptyCard));
            state = containerWarn;
        } else {
            loadSaveData((currentSave & 7) | ((currentSave & 16) << 12));
            state = loadSave;
        }
        break;
    case loadSave:
        val = loadSaveData(0);
        if (val != 0) {
            if ((val <= 0) || (applyLoadedSaveFile(0) != 0)) {
                state = containerWarn;
                memoryCardMessage = (char*)(textTable + VS_MCMAN_BIN_OFFSET_emptyCard);
            } else {
                state = initSlot1;
            }
        }
        break;
    case initSlot1:
        if (fileMenuElementsActive() != 0) {
            element = initFileMenuElement(1, vs_getXY(320, 50), vs_getWH(126, 12),
                (char*)(textTable + VS_MCMAN_BIN_OFFSET_slot1));
            element->state = fileMenuElementStateAnimateX;
            element->targetPosition = 194;
            state = initSlot2;
        }
        break;
    case initSlot2:
        element = initFileMenuElement(2, vs_getXY(320, 66), vs_getWH(126, 12),
            (char*)(textTable + VS_MCMAN_BIN_OFFSET_slot2));
        element->state = fileMenuElementStateAnimateX;
        element->targetPosition = 194;
        state = waitForSlotAnimation;
        break;
    case waitForSlotAnimation:
        if (fileMenuElementsActive() != 0) {
            SAVE_MENU_CLEAR_INFO();
            state = handleInput;
            memoryCardMessage = (char*)(textTable + VS_MCMAN_BIN_OFFSET_selectSlot);
        }
        break;
    case handleInput:
        fileMenuElements[selectedFile].selected = 1;
        fileMenuElements[3 - selectedFile].selected = 0;
        if (vs_main_buttonsPressed.all & PADRdown) {
            vs_main_playSfxDefault(0x7E, VS_SFX_MENULEAVE);
            val = dataNotSaved;
            selectCursorXy = 0;
            if (val < 3) {
                do {
                    fileMenuElements[val].state = fileMenuElementStateAnimateX;
                    fileMenuElements[val].targetPosition = 320;
                    ++val;
                } while (val < 3);
            }
            if (dataNotSaved != 0) {
                memoryCardMessage =
                    (char*)(textTable + VS_MCMAN_BIN_OFFSET_containerWarnDataLoss);
                promptConfirm(1);
                state = discardChanges;
            } else {
                state = returnNoSave;
            }
        } else if (vs_main_buttonsPressed.all & PADRright) {
            vs_main_playSfxDefault(0x7E, VS_SFX_MENUSELECT);
            selectSaveMemoryCard(selectedFile);
            selectCursorXy = 0;
            state = selectCard;
        } else {
            if (vs_main_buttonRepeat & (PADLup | PADLdown)) {
                vs_main_playSfxDefault(0x7E, VS_SFX_MENUCHANGE);
                selectedFile = 3 - selectedFile;
                FILE_MENU_STORE_CURSOR();
            }
            selectCursorXy = vs_getXY(180, (selectedFile + 1) * 16 + 10);
        }
        break;
    case selectCard:
        val = selectSaveMemoryCard(0);
        if (val != 0) {
            if (val < 0) {
                state = initSlot1;
                break;
            }
            initFileMenu();
            return 1;
        }
        break;
    case returnNoSave:
        if (fileMenuElementsActive() != 0) {
            return -1;
        }
        break;
    case containerWarn:
        if (vs_main_buttonsPressed.pad[0].low != 0) {
            SAVE_MENU_CLEAR_INFO();
            memoryCardMessage = (char*)(textTable + VS_MCMAN_BIN_OFFSET_containerWarn);
            promptConfirm(1);
            state = eraseContainerData;
        }
        break;
    case eraseContainerData:
    case discardChanges:
        val = promptConfirm(0);
        if (val != 0) {
            if (state == discardChanges) {
                if (val > 0) {
                    vs_main_settings.containerEmpty = 1;
                }
                val = -val;
            }
            if (val < 0) {
                fileMenuElements[0].state = fileMenuElementStateAnimateX;
                fileMenuElements[0].targetPosition = 320;
                state = returnNoSave;
                break;
            }
            if (state == eraseContainerData) {
                containerDataEmpty = 1;
                memset(&((savedata_t*)spmcimgStatic + 1)->containerData, 0,
                    sizeof((savedata_t*)spmcimgStatic + 1)->containerData);
            }
            state = initSlot1;
        }
        break;
    }
    return 0;
}
