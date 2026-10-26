#pragma once

/* Save memory card selection shared by the title and menu overlays. */

/**
 * Runs card selection and then opens the slot menu for that card.
 *
 * A nonzero initPort starts selection; polling returns one when the save flow
 * completes, -1 when cancelled, or zero while active.
 */
static int _selectSaveMemoryCard(int initPort)
{
    enum state {
        init = 0,
        waitForUnselectedAnimation = 1,
        waitForAnimation = 2,
        handleEvents = 3,
        animateLeave = 4,
        leave = 5,
        initSaveMenu = 6,
        showSaveMenu = 7
    };

    static char state;
    static u_char port;

    int i, j;

    if (initPort != 0) {
        port = initPort;
        _memoryCardMessage = (char*)(_textTable + VS_MCMAN_BIN_OFFSET_checking);
        state = init;
        return 0;
    }

    switch (state) {
    case init:
        _fileMenuElements[port].state = fileMenuElementStateAnimateX;
        _fileMenuElements[port].targetPosition = 180;
        _fileMenuElements[port].innertextBlendFactor = 1;
        _fileMenuElements[3 - port].state = fileMenuElementStateAnimateX;
        _fileMenuElements[3 - port].targetPosition = 320;
        state = waitForUnselectedAnimation;
        break;
    case waitForUnselectedAnimation:
        if (_fileMenuElementsActive() == 0) {
            break;
        }
        if (port == 2) {
            _fileMenuElements[2].state = fileMenuElementStateAnimateY;
            _fileMenuElements[2].targetPosition = 50;
        }
        state = waitForAnimation;
        break;
    case waitForAnimation:
        if (_fileMenuElementsActive() != 0) {
            _memcardEventHandler(port);
            state = handleEvents;
        }
        break;
    case handleEvents:
        i = _memcardEventHandler(0) & 3;
        if (i == 0) {
            break;
        }
        switch (i) {
        case memcardEventIoEnd:
            state = initSaveMenu;
            break;
        case memcardEventTimeout:
            state = animateLeave;
            _memoryCardMessage = (char*)(_textTable + VS_MCMAN_BIN_OFFSET_insertError);
            break;
        case memcardEventUnformatted:
            memset(_saveFileInfo, 0, sizeof *_saveFileInfo * 5);
            for (i = 14; i >= 0; --i) {
                _memcardFiles[i] = NULL;
            }
            j = slotStateAvailable;
            for (i = 4; i >= 0; --i) {
                _saveFileInfo[i].unk4.base.slotState = j;
            }
            _showSaveFilesMenu(port);
            state = showSaveMenu;
            break;
        }
        break;
    case animateLeave:
        if (vs_main_buttonsPressed.pad[0].low == 0) {
            break;
        }
        vs_main_playSfxDefault(0x7E, VS_SFX_MENULEAVE);
        for (i = 1; i < 3; ++i) {
            _fileMenuElements[i].state = fileMenuElementStateAnimateX;
            _fileMenuElements[i].targetPosition = 320;
        }
        state = leave;
        break;
    case leave:
        if (_fileMenuElementsActive() != 0) {
            return -1;
        }
        break;
    case initSaveMenu:
        if (_initSaveFileInfo(port) != 0) {
            state = animateLeave;
            _memoryCardMessage = (char*)(_textTable + VS_MCMAN_BIN_OFFSET_loadfailed);
            break;
        }
        for (i = 0; i < 5; ++i) {
            if (_saveFileInfo[i].unk4.base.slotState != slotStateUnavailable) {
                break;
            }
        }
        if (i == 5) {
            state = animateLeave;
            _memoryCardMessage = (char*)(_textTable + VS_MCMAN_BIN_OFFSET_cardFull);
            break;
        }
        _showSaveFilesMenu(port);
        state = showSaveMenu;
        break;
    case showSaveMenu:
        i = _showSaveFilesMenu(0);
        if (i == 0) {
            break;
        }
        if (i < 0) {
            for (i = 1; i < 3; ++i) {
                _fileMenuElements[i].state = fileMenuElementStateAnimateX;
                _fileMenuElements[i].targetPosition = 320;
            }
            state = leave;
            break;
        }
        return 1;
    }
    return 0;
}
