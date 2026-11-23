#include "common.h"
#include "main.h"
#include "memory.h"
#include <memory.h>

#ifdef NON_MATCHING

void asmNop(void) { }

void nop8(void) { }

void vs_main_nop9(int code, int unused) { }

void vs_main_nop10(int code, int unused) { }

void nop11(void) { }

void vs_main_memcpy(void* dest, void* src, u_int sz)
{
    // The original copies whole words only, so the last sz % 4 bytes are not copied.
    memcpy(dest, src, sz & ~3);
}

void vs_main_bzero(void* dest, int sz)
{
    // Potential bug in original, needs investigating.
    // sz is masked with 0xFFFC, so the last sz % 4 bytes are not cleared and a size of
    // 0x10000 or more loses its upper bits.
    memset(dest, 0, sz & 0xFFFC);
}

void nop12(void) { }

#endif
