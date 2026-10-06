#pragma once
#include "common.h"
#include <libspu.h>

typedef struct {
    u_short volL;
    u_short volR;
    u_short pitch;
    u_short addr;
    u_short adsr1;
    u_short adsr2;
    u_short envx;
    u_short loopAddr;
} SpuVoiceRegs;

typedef struct {
    SpuVoiceRegs voice[24];
    u_short mvolL;
    u_short mvolR;
} SpuRegs;

typedef struct {
    u_long addr;
    u_long size;
} SpuMallocRec;

extern SpuReverbAttr _spu_rev_attr;
extern SpuRegs* _spu_RXX;
extern int _spu_mem_mode_plus;
extern int _spu_AllocBlockNum;
extern int _spu_AllocLastNum;
extern SpuMallocRec* _spu_memList;
