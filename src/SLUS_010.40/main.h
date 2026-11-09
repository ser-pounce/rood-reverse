#pragma once
#include <sys/types.h>

extern int vs_main_titleScreenCount;
extern int vs_main_debugPause;
extern u_short vs_main_actorNames[];

// Avoids breaking .bss order
#ifndef VS_MAIN_INCLUDE
extern u_char vs_main_actorExtraShp[256];
extern int vs_main_startState;
extern int vs_main_unused0;
extern int vs_main_unused1;
extern int vs_main_saveGameClearData;
extern int vs_main_unused2;
#endif

int vs_main_execTitle(void);
void vs_main_exec(void);
int vs_main_gametimeUpdate(int mode);
void vs_main_jumpToBattle(void);
void vs_main_showEndingAndReturnToTitle(void);
int vs_main_getRand(int max);
int vs_main_getRandSmoothed(int max);
void vs_main_enableReset(int enable);
void vs_main_nop9(int code, int unused);
void vs_main_nop10(int code, int unused);
void vs_main_wait(void);
void vs_main_resetGame(void);
