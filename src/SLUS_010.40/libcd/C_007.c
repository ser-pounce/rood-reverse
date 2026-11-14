#include "common.h"
#include <libcd.h>

extern u_long* D_80039C48;
extern u_long D_80039C4C;
extern int D_80039C34;

u_long StFreeRing(u_long* base)
{
    int i;
    int idx;
    short n;
    short* hdr;

    idx = (base - (D_80039C48 + D_80039C4C * HEADER_SIZE)) / (SECTOR_SIZE - HEADER_SIZE);
    hdr = (short*)(D_80039C48 + idx * HEADER_SIZE);
    n = hdr[3];
    if (hdr[0] == StLOCK) {
        i = 0;
        if (n > 0) {
            do {
                short* p = (short*)(D_80039C48 + (i + idx) * HEADER_SIZE);
                *p = 0;
            } while (++i < n);
        }
        D_80039C34 = i + idx;
        return 0;
    }
    return 1;
}
