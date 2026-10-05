#include "common.h"

typedef struct {
    u_long addr;
    u_long size;
} SpuMallocRec;

extern int D_80030888; /* _spu_mem_mode_plus */
extern SpuMallocRec* D_800308C8; /* _spu_memList */

int _SpuIsInAllocateArea(u_long addr)
{
    SpuMallocRec* list;
    u_long start;
    int i;

    list = D_800308C8;
    if (list == NULL) {
        return 0;
    }
    for (i = 0;; i++) {
        if (list[i].addr & 0x80000000) {
            continue;
        }
        if (list[i].addr & 0x40000000) {
            break;
        }
        start = list[i].addr & 0x0FFFFFFF;
        if (start >= addr) {
            return 1;
        }
        if (start + list[i].size > addr) {
            return 1;
        }
    }
    return 0;
}

int _SpuIsInAllocateArea_(u_long addr)
{
    SpuMallocRec* list;
    u_long start;
    int i;

    addr <<= D_80030888;
    list = D_800308C8;
    if (list == NULL) {
        return 0;
    }
    for (i = 0;; i++) {
        if (list[i].addr & 0x80000000) {
            continue;
        }
        if (list[i].addr & 0x40000000) {
            break;
        }
        start = list[i].addr & 0x0FFFFFFF;
        if (start >= addr) {
            return 1;
        }
        if (start + list[i].size > addr) {
            return 1;
        }
    }
    return 0;
}
