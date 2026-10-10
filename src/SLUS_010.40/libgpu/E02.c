#include "common.h"
#include <libgte.h>
#include <libgpu.h>
#include <libetc.h>

u_short LoadClut2(u_long* clut, int x, int y)
{
    RECT rect;

    rect.w = 16;
    rect.x = x;
    rect.y = y;
    rect.h = 1;
    LoadImage(&rect, clut);
    return GetClut(x, y);
}
