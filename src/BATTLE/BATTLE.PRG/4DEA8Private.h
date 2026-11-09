#pragma once
#include "4DEA8.h"

void func_800BBDDC(void);
short func_800BEB00(void);
short func_800BEB10(void);
void func_800BEB34(void);
void func_800BEB9C(int);
void func_800BEBEC(void);
char vs_battle_getStateFlag(short);
int func_800BEC30(void);
short func_800BEC58(short, int, int, short);
int loadMpdClearedScriptDoorSections(void* clearedSection, u_short clearedSectionLen,
    void* scriptSection, u_short scriptSectionLen, void* doorSection,
    u_short doorSectionLen, int startState);
int func_800BF850(void);
extern char vs_battle_textBoxStatuses[];
extern char D_800F4C20;
extern char D_800F4C2C;
extern short D_800F4C58[];
extern char D_800F4C68;
extern u_char D_800E9C30[];
extern u_char* D_800EB588[];
extern vs_Main_CdQueueSlot* D_800F4BBC;
