/* SPDX-License-Identifier: MIT
 * Adapted from Xeeynamo/psyz, decomp/src/libcd/c_009.c and libcd_stream.h,
 * commit bed6ece8becbc6fae3a41285018c47fb1914c2d6.
 * Copyright (c) 2024 github.com/psyqz members
 * Copyright (c) 2025 github.com/xeeynamo/sotn-decomp contributors
 * See LICENSES/psyz-MIT.txt.
 */
#include "common.h"
#include <libcd.h>
extern StHEADER* D_80039C48;
extern volatile u_long D_80039C4C;
extern int D_80039C34;
extern u_long D_80039C3C;

u_long StGetNext(u_long** addr, u_long** header)
{
    volatile StHEADER* ptr;
    ptr = &D_80039C48[D_80039C34];
    if (ptr->id == StREWIND) {
        D_80039C34 = 0;
        if (D_80039C3C != 0) {
            ptr->id = 0;
        }
        ptr = &D_80039C48[D_80039C34];
    }
    if (ptr->id == StCOMPLETE) {
        ptr->id = StLOCK;
        *addr = (u_long*)(&D_80039C48[D_80039C4C]
                          + (D_80039C34 * ((SECTOR_SIZE - HEADER_SIZE) / HEADER_SIZE)));
        *header = (u_long*)ptr;
        return 0;
    } else {
        return 1;
    }
}
