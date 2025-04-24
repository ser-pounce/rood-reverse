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

int func_8004261C(int);
void func_80042C94(int);
void func_80042CA0();
void func_800436B4();
int func_80043940();
void freeHeap(void*);
u_long* allocHeap(u_int);
void func_80045988(int, int);
void func_800468BC(int);
void bzero_impl(void*, int);
void memcpy_impl(void* arg0, void* arg1, u_int words);
vs_main_CdQueueSlot* vs_main_getQueueSlot(vs_main_CdFile*);
void func_80044B80(vs_main_CdQueueSlot*);
void func_80044BC4(vs_main_CdQueueSlot* arg0, void* arg1);
