#include "spu.h"

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
    _spu_RXX->spucnt = (_spu_RXX->spucnt & 0xC0FF) | ((clock & 0x3F) << 8);
    return clock;
}
