#include "common.h"

void* memmove(u_char* dst, u_char* src, int n)
{
    if (dst >= src) {
        while (n-- > 0) {
            dst[n] = src[n];
        }
    } else {
        while (n-- > 0) {
            *dst++ = *src++;
        }
    }
    return dst;
}
