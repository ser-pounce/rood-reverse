#include "common.h"
#include <libcd.h>

extern u_long* D_80039C48;

void init_ring_status(int start, u_int count)
{
    u_int i = 0;

    if (count != 0) {
        do {
            u_long* p = D_80039C48 + (i + start) * HEADER_SIZE;
            *p = 0;
        } while (++i < count);
    }
}
