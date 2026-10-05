#include "common.h"
#include <libspu.h>

extern u_int _spu_FsetRXXa(int reg, u_int addr);

u_long SpuSetIRQAddr(u_long addr)
{
    if (addr > 0x7FFF8) {
        return 0;
    }
    return _spu_FsetRXXa(0xD2, addr);
}
