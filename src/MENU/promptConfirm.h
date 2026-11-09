#pragma once
#include "common.h"
#include "src/SLUS_010.40/pad.h"
#include "src/SLUS_010.40/sound.h"

/* Confirmation prompt shared by the title and menu overlays. */

/**
 * Initializes or advances the shared Yes/No confirmation prompt.
 *
 * A nonzero arg0 initializes the prompt; polling returns 1 for Yes, -1 for No,
 * or zero while the prompt is active.
 */
static int promptConfirm(int arg0)
{
    enum state {
        initYes = 0,
        initNo = 1,
        waitForAnimation = 2,
        handleInput = 3,
    };

    static char state;
    static char cancelled;
    static UNUSED char _[2];

    fileMenuElements_t* temp_v0;
    int i;

    if (arg0 != 0) {
        cancelled = 1;
        state = initYes;
        return 0;
    }

    switch (state) {
    case initYes:
    case initNo:
        temp_v0 = initFileMenuElement(state + 3, vs_getXY(-126 & 0xFFFF, state * 16 + 18),
            vs_getWH(126, 12),
            (char*)&textTable[textTable[state + VS_MCMAN_BIN_INDEX_yesIndent]]);
        temp_v0->state = 4;
        temp_v0->targetPosition = 0;
        ++state;
        break;
    case waitForAnimation:
        state += fileMenuElementsActive();
        break;
    case handleInput:
        fileMenuElements[cancelled + 3].selected = 1;
        fileMenuElements[4 - cancelled].selected = 0;
        if (vs_main_buttonsPressed.all & (PADRdown | PADRright)) {
            selectCursorXy = 0;
            for (i = 3; i < 5; ++i) {
                fileMenuElements[i].state = 4;
                fileMenuElements[i].targetPosition = -126;
            }
            if (vs_main_buttonsPressed.all & PADRright) {
                if (cancelled == 0) {
                    vs_main_playSfxDefault(0x7E, VS_SFX_MENUSELECT);
                    return 1;
                }
            }
            vs_main_playSfxDefault(0x7E, VS_SFX_MENULEAVE);
            return -1;
        }
        if (vs_main_buttonRepeat & (PADLup | PADLdown)) {
            vs_main_playSfxDefault(0x7E, VS_SFX_MENUCHANGE);
            cancelled = 1 - cancelled;
        }
        selectCursorXy = (cancelled * 16 + 10) << 16;
        break;
    }
    return 0;
}

/**
 * Initializes or advances the overwrite confirmation using promptConfirm.
 *
 * Returns the prompt's selection after its exit animation, or zero while
 * pending.
 */
static int promptOverwrite(int init)
{
    static int confirmed;
    static char state;
    static char initialized;

    if (init != 0) {
        initialized = 1;
        memoryCardMessage = (char*)(textTable + VS_MCMAN_BIN_OFFSET_overwritePrompt);
        promptConfirm(1);
        state = 0;
        return 0;
    }
    switch (state) {
    case 0:
        confirmed = promptConfirm(0);
        if (confirmed != 0) {
            state = 1;
        }
        return 0;
    case 1:
        if (fileMenuElementsActive() != 0) {
            return confirmed;
        }
        return 0;
    default:
        return 0;
    }
}

/**
 * Confirms and formats a memory card through the asynchronous card event flow.
 *
 * A nonzero initPort starts the prompt; returns one on format success, -1 on
 * cancellation/error, or zero while pending.
 */
static int promptFormat(int initPort)
{
    enum state { promptConfirmState = 0, initEvents = 1, handleEvents = 2, format = 3 };

    static char state;
    static char port;
    static UNUSED char _[PROMPT_FORMAT_PAD];

    int val;

    if (initPort != 0) {
        port = initPort;
        memoryCardMessage = (char*)(textTable + VS_MCMAN_BIN_OFFSET_formatPrompt);
        promptConfirm(1);
        state = promptConfirmState;
        return 0;
    }

    switch (state) {
    case promptConfirmState:
        val = promptConfirm(0);

        if (val != 0) {
            if (val < 0) {
                memoryCardMessage =
                    (char*)(textTable + VS_MCMAN_BIN_OFFSET_formatCancelled);
                return -1;
            }

            state = initEvents;
        }
        return 0;
    case initEvents:
        if (fileMenuElementsActive() != 0) {
            memcardEventHandler(port);
            state = handleEvents;
        }
        return 0;
    case handleEvents:
        val = memcardEventHandler(0);

        if (val != 0) {
            if (val == memcardEventUnformatted) {
                state = format;
                memoryCardMessage = (char*)(textTable + VS_MCMAN_BIN_OFFSET_formatting);
            } else {
                if (val == memcardEventTimeout) {
                    memoryCardMessage =
                        (char*)(textTable + VS_MCMAN_BIN_OFFSET_insertError);
                } else {
                    memoryCardMessage = (char*)(textTable + VS_MCMAN_BIN_OFFSET_removed);
                }
                return -1;
            }
        }
        return 0;
    case format:
        if (_card_format((port - 1) * 16) == 0) {
            memoryCardMessage = (char*)(textTable + VS_MCMAN_BIN_OFFSET_formatFailed);
            return -1;
        }
        return 1;
    default:
        return 0;
    }
}
