#include "common.h"
#include <libgte.h>
#include <libgpu.h>
#include <libetc.h>

DRAWENV* SetDefDrawEnv(DRAWENV* env, int x, int y, int w, int h)
{
    int mode = GetVideoMode();

    env->clip.x = x;
    env->clip.y = y;
    env->clip.w = w;
    env->tw.x = 0;
    env->tw.y = 0;
    env->tw.w = 0;
    env->tw.h = 0;
    env->r0 = 0;
    env->g0 = 0;
    env->b0 = 0;
    env->dtd = 1;
    env->clip.h = h;
    env->dfe = mode ? h < 289 : h < 257;
    env->ofs[0] = x;
    env->ofs[1] = y;
    env->tpage = 10;
    env->isbg = 0;
    return env;
}
