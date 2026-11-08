#pragma once
#include <sys/types.h>

typedef struct {
    char mode;
    char exId;
    char states;
    char rStickX;
    char rStickY;
    char lStickX;
    char lStickY;
    char lock;
    char actData[2];
    char connected;
} portInfo_t;

typedef struct {
    int lStickX;
    int lStickY;
    int rStickX;
    int rStickY;
} vs_main_stickPos;

typedef union {
    u_int all;
    struct {
        char low;
        char hi;
    } pad[2];
} vs_main_buttonsPressed_t;

// Avoids breaking .bss order
#ifndef VS_MAIN_INCLUDE
extern portInfo_t vs_main_portInfo[2];
extern int vs_main_buttonsReleased;
extern vs_main_stickPos vs_main_stickPosBuf;
extern int vs_main_buttonRepeat;
extern char vs_main_padBuffer[2][34];
extern int vs_main_buttonsPreviousState;
extern vs_main_buttonsPressed_t vs_main_buttonsPressed;
extern int vs_main_buttonsState;
#endif

int vs_main_setVibrationBank(char const* script, u_int requestedSlot, int id);
int vs_main_stopVibration(u_int slot, int id);
void vs_main_padDisconnectAll(void);
int vs_main_updatePadState(int portID, char const padBuf[34]);
void vs_main_padConnect(int portID, char const padBuf[34]);
void vs_main_setVibrateParams(void);
void vs_main_vibrationOnEffect(int effect);
int vs_main_processPadState(void);
void vs_main_resetPadAct(void);
