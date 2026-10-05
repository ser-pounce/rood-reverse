#include "common.h"
#include <libspu.h>

extern volatile SpuTransferCallbackProc D_80030898; /* _spu_transferCallback */
extern long D_80030894; /* _spu_inTransfer */
extern void _spu_Fw(u_char* addr, u_int size);

u_long SpuWrite(u_char* addr, u_long size)
{
    if (size > 0x7EFF0) {
        size = 0x7EFF0;
    }
    _spu_Fw(addr, size);
    if (D_80030898 == NULL) {
        D_80030894 = 0;
    }
    return size;
}
