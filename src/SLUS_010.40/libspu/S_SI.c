#include "spu.h"

extern int printf(const char* fmt, ...);

long SpuSetIRQ(long on_off)
{
    u_int count;

    if (on_off == 0 || on_off == 3) {
        _spu_RXX->spucnt &= ~0x40;
        count = 0;
        while (_spu_RXX->spucnt & 0x40) {
            if (++count > 0xF00) {
                printf("SPU:T/O [%s]\n", "wait (IRQ/ON)");
                return -1;
            }
        }
    }
    if (on_off == 1 || on_off == 3) {
        _spu_RXX->spucnt |= 0x40;
        count = 0;
        while (!(_spu_RXX->spucnt & 0x40)) {
            if (++count > 0xF00) {
                printf("SPU:T/O [%s]\n", "wait (IRQ/OFF)");
                return -1;
            }
        }
    }
    return on_off;
}
