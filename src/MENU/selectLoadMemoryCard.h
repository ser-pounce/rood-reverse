#pragma once
#include "src/SLUS_010.40/pad.h"
#include "src/SLUS_010.40/sound.h"

/* Load memory card selection shared by the title and menu overlays. */

/**
 * Runs memorycard selection and opens the load slot menu for that card.
 *
 * A nonzero initPort initializes selection; polling returns a positive result
 * after a load, a negative result on cancel/error, or zero while pending.
 */
static long selectLoadMemoryCard(int initPort)
{
    enum state {
        init = 0,
        waitForUnselectedAnimation = 1,
        pollEventsInit = 2,
        pollEvents = 3,
        leave = 4,
        returnNotSelected = 5,
        pollSuccess = 6,
        selectFile = 7
    };

    static char state;
    static u_char port;

    int i;

    if (initPort != 0) {
        port = initPort;
        memoryCardMessage = (char*)(textTable + VS_MCMAN_BIN_OFFSET_checking);
        state = init;
        return 0;
    }
    switch (state) {
    case init:
        fileMenuElements[port].state = fileMenuElementStateAnimateX;
        fileMenuElements[port].targetPosition = 180;
        fileMenuElements[port].innertextBlendFactor = 1;
        fileMenuElements[3 - port].state = fileMenuElementStateAnimateX;
        fileMenuElements[3 - port].targetPosition = 320;
        state = waitForUnselectedAnimation;
        break;

    case waitForUnselectedAnimation:
        if (fileMenuElementsActive() == 0) {
            break;
        }
        if (port == 2) {
            fileMenuElements[2].state = fileMenuElementStateAnimateY;
            fileMenuElements[2].targetPosition = 50;
        }
        state = pollEventsInit;
        break;

    case pollEventsInit:
        if (fileMenuElementsActive() == 0) {
            break;
        }
        memcardMaskedHandler(port + memcardEventMaskIgnoreNoEvent);
        state = pollEvents;
        break;

    case pollEvents:
        i = memcardMaskedHandler(0);
        if (i != memcardMaskedHandlerPending) {
            state = i + leave + 1;
        }
        break;

    case leave:
        if ((vs_main_buttonsPressed.pad[0].low) == 0) {
            break;
        }
        vs_main_playSfxDefault(0x7E, VS_SFX_MENULEAVE);
        for (i = 1; i < 3; ++i) {
            fileMenuElements[i].state = fileMenuElementStateAnimateX;
            fileMenuElements[i].targetPosition = 320;
        }
        state = returnNotSelected;
        break;

    case returnNotSelected:
        if (fileMenuElementsActive() != 0) {
            return -1;
        }
        break;

    case pollSuccess:
        if (initSaveFileInfo(port) != 0) {
            memoryCardMessage = (char*)(textTable + VS_MCMAN_BIN_OFFSET_loadfailed);
            state = leave;
            break;
        }
        for (i = 0; i < 5; ++i) {
            if (saveSlotInfo[i].identity.base.slotState > slotStateAvailable) {
                break;
            }
        }

        if (i == 5) {
            memoryCardMessage = (char*)(textTable + VS_MCMAN_BIN_OFFSET_noData);
            state = leave;
        } else {
            showLoadFilesMenu(port);
            state = 7;
        }
        break;

    case selectFile:
        i = showLoadFilesMenu(0);
        if (i == 0) {
            break;
        }
        if (i < 0) {
            for (i = 1; i < 3; ++i) {
                fileMenuElements[i].state = fileMenuElementStateAnimateX;
                fileMenuElements[i].targetPosition = 320;
            }
            state = returnNotSelected;
            break;
        }
        return 1;
    }
    return 0;
}
