#include "common.h"
#include <libspu.h>

extern volatile u_short D_80030878; /* _spu_tsa */
extern int D_80030888; /* _spu_mem_mode_plus */
extern u_int _spu_FsetRXXa(int reg, u_int addr);

u_long SpuSetTransferStartAddr(u_long addr)
{
    if (addr - 0x1010 > 0x7EFE8) {
        return 0;
    }
    D_80030878 = _spu_FsetRXXa(-1, addr);
    return D_80030878 << D_80030888;
}
