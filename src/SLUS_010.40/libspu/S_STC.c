#include "spu.h"

SpuTransferCallbackProc SpuSetTransferCallback(SpuTransferCallbackProc func)
{
    SpuTransferCallbackProc old = _spu_transferCallback;

    if (func != old) {
        _spu_transferCallback = func;
    }

    return old;
}
