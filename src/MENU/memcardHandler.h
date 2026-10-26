#pragma once

/* Memorycard file creation and event state machine shared by the title and menu
 * overlays. */

/**
 * Creates an empty permanent save file, first erasing any existing file.
 *
 * @return Zero on success, or -1 if the file cannot be created.
 */
static int _createSaveFile(int port, int id)
{
    long file;
    char* fileName = _memcardMakeFilename((port - 1) * 16, id);

    erase(fileName);
    file = open(fileName, O_CREAT | (3 << 16));
    if (file != -1) {
        close(file);
        return 0;
    }
    return -1;
}

/**
 * Initializes or advances the stateful memorycard detect/load operation.
 *
 * A nonzero initPort starts polling that card (1 or 2); subsequent calls with
 * zero advance the state and report pending, completion, timeout, or unformatted state.
 */
static enum memcardEventHandler_e _memcardEventHandler(int initPort)
{
    enum state {
        init = 0,
        ready = 1,
        unformatted = 2,
        confirmed = 3,
        loadReady = 4,
        loaded = 5,
    };

    static char state;
    static char port;
    static char initTimeout;
    static char timeout;
    static char eventType;

    int event;

    if (initPort != 0) {
        port = (initPort - 1) * 16;
        state = init;
        initTimeout = 0;
        return memcardEventPending;
    }
    switch (state) {
    case init:
        if (++initTimeout >= 4) {
            return memcardEventTimeout;
        }
        _resetMemcardEvents(memcardEventsSw);
        if (_card_info(port) == 0) {
            break;
        }
        state = ready;
        timeout = 0;
        eventType = memcardEventsSw;
        // fallthrough
    case ready:
        switch (_testMemcardEvents(memcardEventsSw)) {
        case memcardInternalEventIoEnd:
            state = loadReady;
            break;
        case memcardInternalEventError:
        case memcardInternalEventTimeout:
            state = init;
            break;
        case memcardInternalEventUnformatted:
            state = unformatted;
            break;
        case memcardInternalEventNone:
            if (timeout++ > 64) {
                state = init;
            }
            break;
        }
        break;
    case unformatted:
        _resetMemcardEvents(memcardEventsHw);
        if (_card_clear(port) == 0) {
            break;
        }
        state = confirmed;
        timeout = 0;
        eventType = memcardEventsHw;
        // fallthrough
    case confirmed:
        do {
            event = _testMemcardEvents(memcardEventsHw);
        } while (event == memcardInternalEventNone);
        if (event == memcardInternalEventIoEnd) {
            state = loadReady;
            break;
        }
        if (event < memcardInternalEventIoEnd) {
            break;
        }
        if (event >= memcardInternalEventNone) {
            break;
        }
        state = init;
        break;
    case loadReady:
        _resetMemcardEvents(memcardEventsSw);
        if (_card_load(port) == 0) {
            break;
        }
        state = loaded;
        timeout = 0;
        // fallthrough
    case loaded:
        event = _testMemcardEvents(memcardEventsSw);
        switch (event) {
        case memcardInternalEventIoEnd:
            return eventType + memcardEventIoEnd;
        case memcardInternalEventError:
        case memcardInternalEventTimeout:
            state = init;
            break;
        case memcardInternalEventUnformatted:
            return eventType + memcardEventUnformatted;
        case memcardInternalEventNone:
            if (timeout++ > 64) {
                state = init;
            }
            break;
        }
        break;
    }
    return memcardEventPending;
}
