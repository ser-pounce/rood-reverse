#pragma once
#include "common.h"
#include "4DEA8.h"

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

char vs_battle_getStateFlag(short);
VS_HIDDEN(vs_battle_getStateFlag);

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

extern char vs_battle_textBoxStatuses[];
VS_HIDDEN(vs_battle_textBoxStatuses);

extern char D_800F4C20;
VS_HIDDEN(D_800F4C20);

extern char D_800F4C2C;
VS_HIDDEN(D_800F4C2C);

extern short D_800F4C58[];
VS_HIDDEN(D_800F4C58);

extern char D_800F4C68;
VS_HIDDEN(D_800F4C68);

extern u_char D_800E9C30[];
VS_HIDDEN(D_800E9C30);

extern u_char* D_800EB588[];
VS_HIDDEN(D_800EB588);

extern vs_Main_CdQueueSlot* evtCdSlot;
VS_HIDDEN(evtCdSlot);
