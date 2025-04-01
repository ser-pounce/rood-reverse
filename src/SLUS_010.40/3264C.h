#pragma once
#include "25AC.h"
#include <sys/types.h>
#include <libgte.h>
#include <libgpu.h>

typedef struct {
    int lba;
    int size;
} CdFile;

typedef struct {
    short unk0[2];
    CdFile cdFile;
    int unkC;
    void* vram;
} vs_main_cdQueue_t;

extern int frameBuf;
extern DRAWENV drawEnv[2];
extern DISPENV dispEnv[2];
extern int D_8004A528;

int func_8004261C(int);
void func_80042C94(int);
void func_80042CA0();
void func_800436B4();
void func_80043940();
void freeHeap(void*);
unsigned long* allocHeap(unsigned int);
void func_80045988(int, int);
void func_800468BC(int);
void bzero_impl(void*, int);
void memcpy_impl(void* arg0, void* arg1, unsigned int words);
vs_main_cdQueue_t* func_80044B10(CdFile*);
void func_80044B80(vs_main_cdQueue_t*);
void func_80044BC4(vs_main_cdQueue_t* arg0, void* arg1);
