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
} PortInfo;

typedef struct {
    int lStickX;
    int lStickY;
    int rStickX;
    int rStickY;
} vs_main_StickPos;

typedef union {
    u_int all;
    struct {
        char low;
        char hi;
    } pad[2];
} vs_main_ButtonsPressed;

// Avoids breaking .bss order
#ifndef VS_MAIN_INCLUDE
extern PortInfo vs_main_portInfo[2];
extern u_int vs_main_buttonsReleased;
extern vs_main_StickPos vs_main_stickPosBuf;
extern u_int vs_main_buttonRepeat;
extern char vs_main_padBuffer[2][34];
extern u_int vs_main_buttonsPreviousState;
extern vs_main_ButtonsPressed vs_main_buttonsPressed;
extern u_int vs_main_buttonsState;
#endif

int vs_main_setVibrationBank(char const* script, u_int requestedSlot, int id);
int vs_main_stopVibration(u_int slot, int id);
void vs_main_padDisconnectAll(void);
u_int vs_main_updatePadState(int portID, char const padBuf[34]);
void vs_main_padConnect(int portID, char const padBuf[34]);
void vs_main_setVibrateParams(void);
void vs_main_vibrationOnEffect(int effect);
int vs_main_processPadState(void);
void vs_main_resetPadAct(void);
