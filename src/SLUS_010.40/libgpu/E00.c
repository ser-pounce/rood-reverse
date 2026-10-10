#include "common.h"
#include <libgte.h>
#include <libgpu.h>
#include <libetc.h>

u_short LoadTPage(u_long* pix, int tp, int abr, int x, int y, int w, int h)
{
    RECT rect;

    rect.x = x;
    rect.y = y;
    rect.h = h;
    switch (tp) {
    case 0:
        rect.w = w / 4;
        break;
    case 1:
        rect.w = w / 2;
        break;
    case 2:
        rect.w = w;
        break;
    }
    LoadImage(&rect, pix);
    return GetTPage(tp, abr, x, y);
}
