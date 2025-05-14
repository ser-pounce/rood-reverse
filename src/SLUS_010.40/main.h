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
    short unk0[2];
    vs_main_CdFile cdFile;
    int unkC;
    void* vram;
} vs_main_CdQueueSlot;

extern int vs_main_frameBuf;
extern DRAWENV vs_main_drawEnv[2];
extern DISPENV vs_main_dispEnv[2];
extern int D_8004A528;
extern int D_8005E248;
extern char D_8006169D;

int vs_gametime_update(int);
void vs_main_enableReset(int);
void func_80042CA0();
void func_800436B4();
void func_800438C8(int);
int vs_main_processPadState();
void vs_main_freeHeap(void*);
u_long* vs_main_allocHeap(u_int);
void func_80045988(int, int);
void func_800468BC(int);
void func_80046C80(int, int, u_short* arg2, int arg3);
void func_800472D0();
void vs_main_bzero(void*, int);
void vs_main_memcpy(void* arg0, void* arg1, u_int words);
vs_main_CdQueueSlot* vs_main_getQueueSlot(vs_main_CdFile*);
void func_80044B80(vs_main_CdQueueSlot*);
void func_80044BC4(vs_main_CdQueueSlot* arg0, void* arg1);
void func_80048A64(u_short* img, u_int y, u_int x, u_int w);
int vs_main_diskLoadFile(int sector, int bytes, void* vram);
u_long* vs_main_allocHeapR(u_int size);
void vs_main_freeHeapR(void* block);
void vs_main_padDisconnectAll();
