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

// Actor selectors, as taken by many script opcodes: the top nibble is the kind, the rest
// the operand (see resolveActorId and expandActorSelector)
enum ActorSelector {
    actorSelectorById = 0x0000, // | id of the actor to find (Actor.unk18)
    actorSelectorSlot = 0x1000, // | slot in vs_battle_actors
    actorSelectorNone = 0x2000, // where a single actor is expected: no actor
    actorSelectorAll = 0x2000, // where a list of actors is expected: every actor
};

// Return values of script opcode handlers, as interpreted by func_800BFBB8
enum ScriptResult {
    scriptNext = 0, // advance to the next opcode and keep running
    scriptRepeat = 1, // not finished: stop and run this opcode again next frame
    scriptEnd = 3, // terminate this script
    scriptYield = 4, // advance past this opcode, resume next frame
};

void func_800BBDDC(void);
VS_HIDDEN(func_800BBDDC);

short func_800BEB00(void);
VS_HIDDEN(func_800BEB00);

short func_800BEB10(void);
VS_HIDDEN(func_800BEB10);

void func_800BEB34(void);
VS_HIDDEN(func_800BEB34);

void func_800BEB9C(int);
VS_HIDDEN(func_800BEB9C);

void func_800BEBEC(void);
VS_HIDDEN(func_800BEBEC);

char getStateFlag(short);
VS_HIDDEN(getStateFlag);

int func_800BEC30(void);
VS_HIDDEN(func_800BEC30);

short func_800BEC58(short, int, int, short);
VS_HIDDEN(func_800BEC58);

int loadMpdClearedScriptDoorSections(void* clearedSection, u_short clearedSectionLen,
    void* scriptSection, u_short scriptSectionLen, void* doorSection,
    u_short doorSectionLen, int startState);
VS_HIDDEN(loadMpdClearedScriptDoorSections);

int func_800BF850(void);
VS_HIDDEN(func_800BF850);

extern char textBoxStatuses[];
VS_HIDDEN(textBoxStatuses);

extern char stopMusicOnSkip;
VS_HIDDEN(stopMusicOnSkip);

extern char scriptSkipMode;
VS_HIDDEN(scriptSkipMode);

extern short D_800F4C58[];
VS_HIDDEN(D_800F4C58);

extern char skipRequested;
VS_HIDDEN(skipRequested);

extern u_char D_800E9C30[];
VS_HIDDEN(D_800E9C30);

extern u_char* D_800EB588[];
VS_HIDDEN(D_800EB588);

extern vs_CdQueueSlot* evtCdSlot;
VS_HIDDEN(evtCdSlot);
