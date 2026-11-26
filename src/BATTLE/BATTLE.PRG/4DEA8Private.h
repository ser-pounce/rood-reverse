#pragma once
#include "common.h"
#include "4DEA8.h"

enum ScriptSkipMode {
    scriptSkipOff = 0,
    scriptSkippable = 1, // set by opcode 0x0D; START (or skipRequested) skips
    scriptSkipping = 2, // dispatching through the skip table
};

enum ScriptMenuState {
    scriptMenuClosed = 0,
    scriptMenuOpen = 1,
};

enum ScriptWarpState {
    scriptWarpIdle = 0,
    scriptWarpResume = 1, // warp requested, the script carries on in the new room
    scriptWarpArrived = 2, // the new room is loaded
    scriptWarpEnd = 3, // warp requested, the event ends in the new room
};

// Actor selectors, as taken by many script opcodes: the top nibble is the kind, the rest
// the operand (see resolveActorId and expandActorSelector)
enum ActorSelector {
    actorSelectorById = 0x0000, // | id of the actor to find (Actor.id)
    actorSelectorSlot = 0x1000, // | slot in vs_battle_actors
    actorSelectorNone = 0x2000, // where a single actor is expected: no actor
    actorSelectorAll = 0x2000, // where a list of actors is expected: every actor
};

// Return values of script opcode handlers, as interpreted by runScript. Any other value
// is the address of the opcode to jump to.
enum ScriptResult {
    scriptNext = 0, // advance to the next opcode and keep running
    scriptWait = 1, // not finished: stop and run this opcode again next frame
    scriptFinish = 2, // the main script has finished, which ends the scene
    scriptEnd = 3, // terminate this script
    scriptYield = 4, // advance past this opcode, resume next frame
};

void freeScriptCamera(void);
VS_HIDDEN(freeScriptCamera);

// States of the event that is being started or run, see updateEvent
enum EventState {
    eventIdle = 0,
    eventRequested = 1, // waiting for the game to be ready to start it
    eventStarting = 2,
    eventLoading = 3, // waiting for the EVT file to load from disc
    eventRunning = 4, // the scripts are running
};

short getEventState(void);
VS_HIDDEN(getEventState);

enum EventSource {
    eventFromEvt,
    eventFromEntryScript,
    eventFromTriggeredScripts,
};

short getEventId(void);
VS_HIDDEN(getEventId);

void unloadMpdEventSections(void);
VS_HIDDEN(unloadMpdEventSections);

void resetZoneFlags(int firstLoad);
VS_HIDDEN(resetZoneFlags);

void zoneUnloadNop(void);
VS_HIDDEN(zoneUnloadNop);

char getStateFlag(short id);
VS_HIDDEN(getStateFlag);

int signalEventReady(void);
VS_HIDDEN(signalEventReady);

enum EventTrigger {
    eventTriggerMapLoad = 1,
    eventTriggerStep = 2,
    eventTriggerInteract = 4,
    eventTriggerDefeat = 8,
    eventTriggerTimer = 0x10,
    eventTriggerIdle = 0x20,
    eventTriggerForced = 0x40,
    eventTriggerPoll = 0xFF,
};

enum EventRequestResult {
    eventRequestNone,
    eventRequestMade,
    eventRequestBusy,
};

short requestEvent(short trigger, int arg1, int arg2, short mode);
VS_HIDDEN(requestEvent);

int loadMpdEventSections(void* triggerSection, u_short triggerSectionLen,
    void* entryScript, u_short entryScriptLen, void* triggeredScripts,
    u_short triggeredScriptsLen, int firstLoad);
VS_HIDDEN(loadMpdEventSections);

int updateEvent(void);
VS_HIDDEN(updateEvent);

extern char textBoxStatuses[];
VS_HIDDEN(textBoxStatuses);

extern char stopMusicOnSkip;
VS_HIDDEN(stopMusicOnSkip);

extern char scriptSkipMode;
VS_HIDDEN(scriptSkipMode);

// Easing curves. The first four are built in, the rest are configured with opcode 5F.
enum Easing {
    easingLinear,
    easingSineOut,
    easingSineInOut,
    easingSineIn,
    easingCustom0,
    easingCustom1,
    easingCustom2,
    easingCustom3,
};

typedef struct {
    u_char curve;
    signed char power;
} CustomEasing;

extern CustomEasing customEasings[4];
VS_HIDDEN(customEasings);

extern short scriptWaitFrames[];
VS_HIDDEN(scriptWaitFrames);

extern char skipRequested;
VS_HIDDEN(skipRequested);

extern u_char opcodeLengths[];
VS_HIDDEN(opcodeLengths);

extern u_char* textBoxShapes[];
VS_HIDDEN(textBoxShapes);

extern vs_CdQueueSlot* evtCdSlot;
VS_HIDDEN(evtCdSlot);
