#pragma once

/* Confirmation prompt shared by the title and menu overlays. */

/**
 * Initializes or advances the shared Yes/No confirmation prompt.
 *
 * A nonzero arg0 initializes the prompt; polling returns 1 for Yes, -1 for No,
 * or zero while the prompt is active.
 */
static int _promptConfirm(int arg0)
{
    enum state {
        initYes = 0,
        initNo = 1,
        waitForAnimation = 2,
        handleInput = 3,
    };

    static char state;
    static char cancelled;
    static char _[2] __attribute__((unused));

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
        temp_v0 = _initFileMenuElement(state + 3,
            vs_getXY(-126 & 0xFFFF, state * 16 + 18), vs_getWH(126, 12),
            (char*)&_textTable[_textTable[state + VS_MCMAN_BIN_INDEX_yesIndent]]);
        temp_v0->state = 4;
        temp_v0->targetPosition = 0;
        ++state;
        break;
    case waitForAnimation:
        state += _fileMenuElementsActive();
        break;
    case handleInput:
        _fileMenuElements[cancelled + 3].selected = 1;
        _fileMenuElements[4 - cancelled].selected = 0;
        if (vs_main_buttonsPressed.all & (PADRdown | PADRright)) {
            _selectCursorXy = 0;
            for (i = 3; i < 5; ++i) {
                _fileMenuElements[i].state = 4;
                _fileMenuElements[i].targetPosition = -126;
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
        _selectCursorXy = (cancelled * 16 + 10) << 16;
        break;
    }
    return 0;
}

/**
 * Initializes or advances the overwrite confirmation using _promptConfirm.
 *
 * Returns the prompt's selection after its exit animation, or zero while
 * pending.
 */
static int _promptOverwrite(int init)
{
    static int confirmed;
    static char state;
    static char initialized;

    if (init != 0) {
        initialized = 1;
        _memoryCardMessage = (char*)(_textTable + VS_MCMAN_BIN_OFFSET_overwritePrompt);
        _promptConfirm(1);
        state = 0;
        return 0;
    }
    switch (state) {
    case 0:
        confirmed = _promptConfirm(0);
        if (confirmed != 0) {
            state = 1;
        }
        return 0;
    case 1:
        if (_fileMenuElementsActive() != 0) {
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
static int _promptFormat(int initPort)
{
    enum state { promptConfirm = 0, initEvents = 1, handleEvents = 2, format = 3 };

    static char state;
    static char port;
    static char _[PROMPT_FORMAT_PAD] __attribute__((unused));

    int val;

    if (initPort != 0) {
        port = initPort;
        _memoryCardMessage = (char*)(_textTable + VS_MCMAN_BIN_OFFSET_formatPrompt);
        _promptConfirm(1);
        state = promptConfirm;
        return 0;
    }

    switch (state) {
    case promptConfirm:
        val = _promptConfirm(0);

        if (val != 0) {
            if (val < 0) {
                _memoryCardMessage =
                    (char*)(_textTable + VS_MCMAN_BIN_OFFSET_formatCancelled);
                return -1;
            }

            state = initEvents;
        }
        return 0;
    case initEvents:
        if (_fileMenuElementsActive() != 0) {
            _memcardEventHandler(port);
            state = handleEvents;
        }
        return 0;
    case handleEvents:
        val = _memcardEventHandler(0);

        if (val != 0) {
            if (val == memcardEventUnformatted) {
                state = format;
                _memoryCardMessage = (char*)(_textTable + VS_MCMAN_BIN_OFFSET_formatting);
            } else {
                if (val == memcardEventTimeout) {
                    _memoryCardMessage =
                        (char*)(_textTable + VS_MCMAN_BIN_OFFSET_insertError);
                } else {
                    _memoryCardMessage =
                        (char*)(_textTable + VS_MCMAN_BIN_OFFSET_removed);
                }
                return -1;
            }
        }
        return 0;
    case format:
        if (_card_format((port - 1) * 16) == 0) {
            _memoryCardMessage = (char*)(_textTable + VS_MCMAN_BIN_OFFSET_formatFailed);
            return -1;
        }
        return 1;
    default:
        return 0;
    }
}
