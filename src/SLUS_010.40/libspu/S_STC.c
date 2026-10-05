#include "common.h"
#include <libspu.h>

extern volatile SpuTransferCallbackProc D_80030898; /* _spu_transferCallback */

SpuTransferCallbackProc SpuSetTransferCallback(SpuTransferCallbackProc func)
{
    SpuTransferCallbackProc old = D_80030898;

    if (func != old) {
        D_80030898 = func;
    }
    return old;
}
