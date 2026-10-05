#include "common.h"
#include <libspu.h>

typedef struct {
    long mode;
    SpuVolume depth;
    long delay;
    long feedback;
} SpuRevAttr;

typedef struct {
    u_long mask;
    u_short param[32];
} SpuRevParam;

typedef struct {
    u_short unk0[0xD5];
    volatile u_short spucnt; /* 0x1AA */
} SpuRegs;

typedef union {
    u_short rxx[0x100];
    SpuRegs regs;
} SpuRXX;

extern SpuRXX* D_80030860; /* _spu_RXX */
extern SpuRevAttr D_80030804; /* _spu_rev_attr */
extern long D_800307FC; /* _spu_rev_offsetaddr */
extern u_long D_80030CD0[]; /* _spu_rev_startaddr */
extern SpuRevParam D_80030D00[]; /* _spu_rev_param */
extern int _SpuIsInAllocateArea_(u_long addr);
extern void _spu_setReverbAttr(SpuRevParam* param);
extern long SpuClearReverbWorkArea(long rev_mode);
extern void _spu_FsetRXX(int reg, u_int addr, int flag);

long SpuSetReverbModeType(long mode)
{
    SpuRevParam param;
    u_char* src;
    u_char* dst;
    int n;
    int reverbOn;
    int clear;

    clear = 0;
    if (mode & 0x100) {
        mode &= ~0x100;
        clear = 1;
    }
    if ((u_long)mode >= 10 || _SpuIsInAllocateArea_(D_80030CD0[mode])) {
        return -1;
    }
    dst = (u_char*)&param;
    src = (u_char*)&D_80030D00[mode];
    D_80030804.mode = mode;
    D_800307FC = D_80030CD0[mode];
    n = sizeof(SpuRevParam);
    while (n--) {
        *dst++ = *src++;
    }
    param.mask = 0;
    switch (mode) {
    case 7:
        D_80030804.feedback = 0x7F;
        D_80030804.delay = 0x7F;
        break;
    case 8:
        D_80030804.feedback = 0;
        D_80030804.delay = 0x7F;
        break;
    default:
        D_80030804.feedback = 0;
        D_80030804.delay = 0;
        break;
    }
    reverbOn = (D_80030860->regs.spucnt & 0x80) != 0;
    if (reverbOn) {
        D_80030860->regs.spucnt &= ~0x80;
    }
    D_80030860->rxx[0xC2] = 0;
    D_80030860->rxx[0xC3] = 0;
    D_80030804.depth.left = 0;
    D_80030804.depth.right = 0;
    _spu_setReverbAttr(&param);
    if (clear) {
        SpuClearReverbWorkArea(mode);
    }
    _spu_FsetRXX(0xD1, D_800307FC, 0);
    if (reverbOn) {
        D_80030860->regs.spucnt |= 0x80;
    }
    return 0;
}
