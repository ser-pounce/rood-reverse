#include "common.h"

int memcmp(u_char* s1, u_char* s2, int n)
{
    while (*s1 == *s2) {
        s1++;
        s2++;
        if (--n <= 0) {
            return 0;
        }
    }
    return *s1 - *s2;
}
