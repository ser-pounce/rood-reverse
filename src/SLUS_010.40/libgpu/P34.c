#include "common.h"
#include <libgte.h>
#include <libgpu.h>

void SetDrawMove(DR_MOVE* p, RECT* rect, int x, int y)
{
    int length = 5;
    if (!rect->w || !rect->h) {
        length = 0;
    }
    setlen(p, length);
    p->code[0] = 0x01000000;
    p->code[1] = 0x80000000;
    p->code[2] = *(u_long*)&rect->x;
    p->code[3] = (y << 16) | (x & 0xFFFF);
    p->code[4] = *(u_long*)&rect->w;
}

void SetDrawStp(DR_STP* stp, int enable)
{
    ((char*)stp)[3] = 2;
    if (enable) {
        stp->code[0] = 0xE6000001;
    } else {
        stp->code[0] = 0xE6000000;
    }
    stp->code[1] = 0;
}
