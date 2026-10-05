#include "common.h"
#include <libspu.h>

extern volatile SpuIRQCallbackProc D_8003089C; /* _spu_IRQCallback */
extern void _SpuCallback(void (*func)(void));

SpuIRQCallbackProc SpuSetIRQCallback(SpuIRQCallbackProc func)
{
    SpuIRQCallbackProc old = D_8003089C;

    if (func != old) {
        D_8003089C = func;
        _SpuCallback(func);
    }
    return old;
}
