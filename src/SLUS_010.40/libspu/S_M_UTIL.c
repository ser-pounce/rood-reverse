#include "spu.h"

inline int _SpuIsInAllocateArea(u_long addr)
{
    SpuMallocRec* list = _spu_memList;
    int i;

    if (list == NULL) {
        return 0;
    }

    for (i = 0;; ++i) {
        u_long start;

        if (list[i].addr & 0x80000000) {
            continue;
        }
        if (list[i].addr & 0x40000000) {
            break;
        }

        start = list[i].addr & 0x0FFFFFFF;

        if (start >= addr) {
            return 1;
        }
        if (start + list[i].size > addr) {
            return 1;
        }
    }

    return 0;
}

int _SpuIsInAllocateArea_(u_long addr)
{
    return _SpuIsInAllocateArea(addr << _spu_mem_mode_plus);
}
