#include "common.h"
#include <libgte.h>

extern u_char D_80040A14[];

long ratan2(long y, long x)
{
    long c = 0;
    long ay, ax, t;

    t = y | x;
    if (t != 0) {
        ax = x < 0 ? -x : x;
        ay = y < 0 ? -y : y;
        t = 512;
        if (ax < ay) {
            c = ax << 9;
            c /= ay;
            c = D_80040A14[c];
            c = t - c;
        } else {
            c = ay << 9;
            c /= ax;
            c = D_80040A14[c];
        }
        t = 1024;
        if (ax != x) {
            c = t - c;
        }
        c <<= 1;
        if (ay != y) {
            c = -c;
        }
    }
    return c;
}
