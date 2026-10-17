#include "spu.h"

extern long D_800307F4; /* _spu_rev_flag */
extern long D_800307F8; /* _spu_rev_reserve_wa */
extern long D_800307FC; /* _spu_rev_offsetaddr */
extern int _SpuIsInAllocateArea_(u_long addr);

long SpuSetReverb(long on_off)
{
    switch (on_off) {
    case 0:
        D_800307F4 = 0;
        _spu_RXX->spucnt &= ~0x80;
        break;
    case 1:
        if (D_800307F8 != on_off && _SpuIsInAllocateArea_(D_800307FC)) {
            D_800307F4 = 0;
            _spu_RXX->spucnt &= ~0x80;
        } else {
            D_800307F4 = on_off;
            _spu_RXX->spucnt |= 0x80;
        }
        break;
    }
    return D_800307F4;
}
