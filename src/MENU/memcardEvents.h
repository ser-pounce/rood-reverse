#pragma once

/* Memorycard event helpers shared by the title and menu overlays. */

static long _memcardEventDescriptors[8];

enum memcardEvents_e { memcardEventsSw, memcardEventsHw = 4 };

enum testMemcardEvents_e {
    memcardInternalEventIoEnd,
    memcardInternalEventError,
    memcardInternalEventTimeout,
    memcardInternalEventUnformatted,
    memcardInternalEventNone,
};

enum memcardEventHandler_e {
    memcardEventPending = 0,
    memcardEventIoEnd = 1,
    memcardEventTimeout = 2,
    memcardEventUnformatted = 3
};

/**
 * Returns the first signalled memorycard event of the requested type, or
 * memcardInternalEventNone when none of the four events is signalled.
 */
static enum testMemcardEvents_e _testMemcardEvents(enum memcardEvents_e type)
{
    int i;

    for (i = 0; i < 4; ++i) {
        if (TestEvent(_memcardEventDescriptors[i + type]) == 1) {
            return i;
        }
    }
    return i;
}

/**
 * Tests each event in the selected memorycard event group to clear its signal.
 */
static void _resetMemcardEvents(enum memcardEvents_e type)
{
    int i;

    for (i = 0; i < 4; ++i) {
        TestEvent(_memcardEventDescriptors[i + type]);
    }
}
