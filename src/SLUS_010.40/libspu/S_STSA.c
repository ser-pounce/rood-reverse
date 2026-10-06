#include "spu.h"

u_long SpuSetTransferStartAddr(u_long addr)
{
    if ((addr < 0x1010) || (addr > 0x7FFF8)) {
        return 0;
    }
    _spu_tsa = _spu_FsetRXXa(-1, addr);
    return _spu_tsa << _spu_mem_mode_plus;
}
