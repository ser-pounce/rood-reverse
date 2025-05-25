#pragma once
#include "25AC.h"
#include <sys/types.h>
#include <libgte.h>
#include <libgpu.h>

typedef struct {
    int lba;
    int size;
} vs_main_CdFile;

typedef struct {
    short state;
    short priority;
    vs_main_CdFile cdFile;
    int unkC;
    void* vram;
} vs_main_CdQueueSlot;

typedef struct {
    unsigned char id;
    unsigned char effect;
    int unk2_0 : 1;
    int type : 3;
    int target : 4;
    unsigned char cost;
    unsigned char rangeX;
    unsigned char rangeY;
    unsigned char rangeZ;
    int shape : 3;
    int angle : 5;
    int aoe;
    u_int flags;
    unsigned char unkD[2];
    struct {
        int effect : 7;
        int hitrateFlags : 6;
        int hitrateAdj : 3;
        int damage : 6;
        int mult : 5;
        int type : 2;
        int affinity : 3;
    } hitParams[2];
    char name[24];
} vs_skill_t;

typedef struct {
    int currentMusicId;
    u_int unk4;
    int unk8;
    void* currentMusicData;
    u_char musicIds[4];
    u_int unk14[4];
    void* musicData[4];
    vs_main_CdQueueSlot* musicQueueSlot[4];
    u_int currentSfxId;
    u_char sfxIds[4];
    void* sfxData[3];
    vs_main_CdQueueSlot* sfxQueueSlot[3];
    void* unk64[3];
    int* unk70[3];
    int soundFileId;
    void* soundData;
    vs_main_CdQueueSlot* soundQueueSlot;
} soundData_t;

extern soundData_t vs_main_soundData;
extern vs_skill_t vs_main_skills[256];
extern u_char D_8004EDDC[8][30];
extern int vs_main_frameBuf;
extern DRAWENV vs_main_drawEnv[2];
extern DISPENV vs_main_dispEnv[2];
extern int D_8004A528;
extern int D_8004A52C;
extern vs_main_CdFile vs_main_zndFiles[256];
extern u_char D_8004FCCC[];
extern u_short D_8005046A;
extern u_int D_80055C80[];
extern void* D_8005E0C0[];
extern int D_8005E0C8;
extern int D_8005E248;
extern int D_80060064;
extern u_char D_80061078[0x520];
extern char D_8006169D;
extern int vs_gametime_tickspeed;
extern u_char vs_main_padBuffer[2][34];
extern u_int vs_main_buttonsPressed;
extern int vs_main_buttonsPreviousState;
extern int vs_main_buttonsReleased;
extern int vs_main_buttonsState;
extern int vs_main_saveBeforeTitle;

int vs_main_gametimeUpdate(int);
void vs_main_jumpToBattle();
void vs_main_showEndingAndReturnToTitle();
int vs_main_getRand(int);
int vs_main_getRandSmoothed(int);
int vs_main_execTitle();
void vs_main_exec();
void vs_main_enableReset(int);
void func_80042CA0();
void func_80042CB0();
void vs_main_padDisconnectAll();
int vs_main_updatePadState(int, u_char[34]);
void vs_main_padConnect(int, u_char[34]);
void func_800436B4();
void func_800438C8(int);
int vs_main_processPadState();
void vs_main_freeHeapR(void*);
void vs_main_freeHeap(void*);
u_long* vs_main_allocHeapR(u_int);
void* vs_main_allocHeap(u_int);
vs_main_CdQueueSlot* vs_main_allocateCdQueueSlot(vs_main_CdFile*);
void vs_main_freeCdQueueSlot(vs_main_CdQueueSlot*);
void vs_main_cdEnqueue(vs_main_CdQueueSlot* slot, void* vram);
void vs_main_cdEnqueueUrgent(vs_main_CdQueueSlot* slot, void* vram);
int vs_main_loadMusicSlot(int id, int targetSlot);
void vs_main_playSfxDefault(int, int);
void func_800468BC(int);
void func_80046C80(int, int, u_short*, int);
void func_800472D0();
void func_800478E0(int, int, int, int, int);
void vs_main_bzero(void*, int);
void vs_main_memcpy(void*, void*, u_int);
void vs_main_nop9(int, int);
void func_80048A64(u_short* img, u_int y, u_int x, u_int w);
void func_80048F8C();
int vs_main_diskLoadFile(int sector, int bytes, void* vram);
void vs_main_resetPadAct();
int vs_main_streamXa(int sector, int byteCount);
int vs_main_checkStreamXaEnd();
int func_8004552C(int id, int arg1, int arg2);
int func_800450E4();