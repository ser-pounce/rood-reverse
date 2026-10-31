#include "spu.h"

typedef struct {
    u_long mask;
    u_short param[32];
} SpuRevParam;

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
    _spu_rev_attr.mode = mode;
    D_800307FC = D_80030CD0[mode];
    n = sizeof(SpuRevParam);
    while (n--) {
        *dst++ = *src++;
    }
    param.mask = 0;
    switch (mode) {
    case 7:
        _spu_rev_attr.feedback = 0x7F;
        _spu_rev_attr.delay = 0x7F;
        break;
    case 8:
        _spu_rev_attr.feedback = 0;
        _spu_rev_attr.delay = 0x7F;
        break;
    default:
        _spu_rev_attr.feedback = 0;
        _spu_rev_attr.delay = 0;
        break;
    }
    reverbOn = (_spu_RXX->spucnt & 0x80) != 0;
    if (reverbOn) {
        _spu_RXX->spucnt &= ~0x80;
    }
    _spu_RXX->rvolL = 0;
    _spu_RXX->rvolR = 0;
    _spu_rev_attr.depth.left = 0;
    _spu_rev_attr.depth.right = 0;
    _spu_setReverbAttr(&param);
    if (clear) {
        SpuClearReverbWorkArea(mode);
    }
    _spu_FsetRXX(0xD1, D_800307FC, 0);
    if (reverbOn) {
        _spu_RXX->spucnt |= 0x80;
    }
    return 0;
}
