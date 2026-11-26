#pragma once
#include "common.h"
#include "573B8.h"

short runScript(u_char** next, short slot);
VS_HIDDEN(runScript);

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
