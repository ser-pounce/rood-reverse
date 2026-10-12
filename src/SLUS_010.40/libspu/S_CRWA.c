/* SPDX-License-Identifier: MIT
 * Adapted from Xeeynamo/psyz, decomp/src/libspu/s_crwa.c,
 * commit bed6ece8becbc6fae3a41285018c47fb1914c2d6.
 * Copyright (c) 2024 github.com/psyqz members
 * Copyright (c) 2025 github.com/xeeynamo/sotn-decomp contributors
 * See LICENSES/psyz-MIT.txt.
 */
#include "common.h"
extern int D_80030CD0[];
extern int _spu_mem_mode_plus;
extern int D_8003087C;
extern void (*volatile _spu_transferCallback)(void);
extern int D_800308D0[];
extern int D_800307E8;
extern int _SpuIsInAllocateArea_(u_long);
extern int _spu_t(int, ...);
extern long WaitEvent(long);
long SpuClearReverbWorkArea(long rev_mode)
{
    void (*volatile callback)(void);
    int oldTransmode;
    int dstAddr;
    int moreBlocks;
    int transmodeCleared;
    unsigned size;
    unsigned length;

    callback = 0;
    transmodeCleared = 0;
    if (rev_mode < 0 || rev_mode >= 10 || _SpuIsInAllocateArea_(D_80030CD0[rev_mode])) {
        return -1;
    }
    if (rev_mode == 0) {
        length = 0x10 << _spu_mem_mode_plus;
        dstAddr = 0xFFF0 << _spu_mem_mode_plus;
    } else {
        length = (0x10000 - D_80030CD0[rev_mode]) << _spu_mem_mode_plus;
        dstAddr = D_80030CD0[rev_mode] << _spu_mem_mode_plus;
    }
    oldTransmode = D_8003087C;
    if (D_8003087C == 1) {
        D_8003087C = 0;
        transmodeCleared = 1;
    }
    moreBlocks = 1;
    if (_spu_transferCallback != 0) {
        callback = _spu_transferCallback;
        _spu_transferCallback = 0;
    }
    while (moreBlocks != 0) {
        size = 0x400;
        if (length <= 0x400) {
            size = length;
            moreBlocks = 0;
        }

        _spu_t(2, dstAddr);
        _spu_t(1);
        _spu_t(3, &D_800308D0[0], size);

        WaitEvent(D_800307E8);
        length -= 0x400;
        dstAddr += 0x400;
    }
    if (transmodeCleared != 0) {
        D_8003087C = oldTransmode;
    }
    if (callback != 0) {
        _spu_transferCallback = callback;
    }
    return 0;
}
