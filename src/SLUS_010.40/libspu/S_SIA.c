#include "spu.h"

u_long SpuSetIRQAddr(u_long addr)
{
    if (addr > 0x7FFF8) {
        return 0;
    }

    return _spu_FsetRXXa(0xD2, addr);
}
