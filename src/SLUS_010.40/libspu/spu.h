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

/* SPU reverb work registers, 0x1F801DC0-0x1F801DFF */
typedef struct {
    u_short dAPF1;
    u_short dAPF2;
    u_short vIIR;
    u_short vCOMB1;
    u_short vCOMB2;
    u_short vCOMB3;
    u_short vCOMB4;
    u_short vWALL;
    u_short vAPF1;
    u_short vAPF2;
    u_short mLSAME;
    u_short mRSAME;
    u_short mLCOMB1;
    u_short mRCOMB1;
    u_short mLCOMB2;
    u_short mRCOMB2;
    u_short dLSAME;
    u_short dRSAME;
    u_short mLDIFF;
    u_short mRDIFF;
    u_short mLCOMB3;
    u_short mRCOMB3;
    u_short mLCOMB4;
    u_short mRCOMB4;
    u_short dLDIFF;
    u_short dRDIFF;
    u_short mLAPF1;
    u_short mRAPF1;
    u_short mLAPF2;
    u_short mRAPF2;
    u_short vLIN;
    u_short vRIN;
} SpuReverbRegs;

typedef struct {
    SpuVoiceRegs voice[24];
    u_short mvolL;
    u_short mvolR;
    u_short rvolL;
    u_short rvolR;
    u_short unk188[0x11];
    volatile u_short spucnt;
    u_short unk1AC[0xA];
    SpuReverbRegs rev;
} SpuRegs;

typedef struct {
    u_long addr;
    u_long size;
} SpuMallocRec;

u_int _spu_FsetRXXa(int reg, u_int addr);

extern SpuReverbAttr _spu_rev_attr;
extern SpuRegs* _spu_RXX;
extern volatile u_short _spu_tsa;
extern int _spu_mem_mode_plus;
extern volatile SpuTransferCallbackProc _spu_transferCallback;
extern int _spu_AllocBlockNum;
extern int _spu_AllocLastNum;
extern SpuMallocRec* _spu_memList;
