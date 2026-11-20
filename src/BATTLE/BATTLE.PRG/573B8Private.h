#pragma once
#include "common.h"
#include "573B8.h"

short func_800BFBB8(u_char**, short);
VS_HIDDEN(func_800BFBB8);

void releaseScriptControl(void);
VS_HIDDEN(releaseScriptControl);

int resolveActorId(u_short);
VS_HIDDEN(resolveActorId);

int evaluateEasing(short mode, short frame, short duration);
VS_HIDDEN(evaluateEasing);

void loadEvt(int file, void* buffer);
VS_HIDDEN(loadEvt);

short getShort(u_char* arg0);
VS_HIDDEN(getShort);

extern short evtFile;
VS_HIDDEN(evtFile);
