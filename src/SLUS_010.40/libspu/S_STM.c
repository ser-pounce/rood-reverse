#include "common.h"
#include <libspu.h>

extern long D_800307F0; /* _spu_trans_mode */
extern long D_8003087C; /* _spu_transMode */

long SpuSetTransferMode(long mode)
{
    long transMode;

    switch (mode) {
    case 0:
        transMode = 0;
        break;
    case 1:
        transMode = 1;
        break;
    default:
        transMode = 0;
        break;
    }
    D_800307F0 = mode;
    D_8003087C = transMode;
    return transMode;
}
