#include "common.h"
#include <libspu.h>

typedef struct {
    u_long addr;
    u_long size;
} SpuMallocRec;

extern int D_80030888; /* _spu_mem_mode_plus */
extern SpuMallocRec* D_800308C8; /* _spu_memList */
extern int D_800308C4; /* _spu_AllocLastNum */
extern int D_800308C0; /* _spu_AllocBlockNum */

long SpuInitMalloc(long num, char* top)
{
    SpuMallocRec* rec = (SpuMallocRec*)top;

    if (num > 0) {
        rec->addr = 0x40001010;
        D_800308C8 = rec;
        D_800308C4 = 0;
        D_800308C0 = num;
        rec->size = (0x10000 << D_80030888) - 0x1010;
        return num;
    }
    return 0;
}
