#include "common.h"
#include <libspu.h>

typedef struct {
    u_short unk0[0xD5];
    volatile u_short spucnt; /* 0x1AA */
} SpuRegs;

typedef union {
    u_short rxx[0x100];
    SpuRegs regs;
} SpuRXX;

extern SpuRXX* D_80030860; /* _spu_RXX */
extern int printf(const char* fmt, ...);

long SpuSetIRQ(long on_off)
{
    u_int count;

    if (on_off == 0 || on_off == 3) {
        D_80030860->regs.spucnt &= ~0x40;
        count = 0;
        while (D_80030860->regs.spucnt & 0x40) {
            if (++count > 0xF00) {
                printf("SPU:T/O [%s]\n", "wait (IRQ/ON)");
                return -1;
            }
        }
    }
    if (on_off == 1 || on_off == 3) {
        D_80030860->regs.spucnt |= 0x40;
        count = 0;
        while (!(D_80030860->regs.spucnt & 0x40)) {
            if (++count > 0xF00) {
                printf("SPU:T/O [%s]\n", "wait (IRQ/OFF)");
                return -1;
            }
        }
    }
    return on_off;
}
