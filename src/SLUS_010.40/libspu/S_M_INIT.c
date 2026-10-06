#include "spu.h"

long SpuInitMalloc(long num, char* top)
{
    SpuMallocRec* rec = (SpuMallocRec*)top;

    if (num > 0) {
        rec->addr = 0x40001010;
        _spu_memList = rec;
        _spu_AllocLastNum = 0;
        _spu_AllocBlockNum = num;
        rec->size = (0x10000 << _spu_mem_mode_plus) - 0x1010;
        return num;
    }
    return 0;
}
