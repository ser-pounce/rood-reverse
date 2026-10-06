#include "common.h"

extern u_short* D_80030860; /* _spu_RXX */

long SpuSetNoiseClock(long n_clock)
{
    long clock;

    if (n_clock < 0) {
        clock = 0;
    } else if (n_clock >= 0x40) {
        clock = 0x3F;
    } else {
        clock = n_clock;
    }
    D_80030860[0xD5] = (D_80030860[0xD5] & 0xC0FF) | ((clock & 0x3F) << 8);
    return clock;
}
