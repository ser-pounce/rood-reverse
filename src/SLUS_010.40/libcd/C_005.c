#include "common.h"
#include <libcd.h>

extern int D_80039C38;
extern void (*D_80039C98)(void);
extern u_long D_80039C10;
extern int D_80039C20;
extern int D_80039C18;
extern u_short D_80039C0C;
extern int D_80039C08;
extern void (*D_80039C9C)(void);

void StSetStream(
    u_long mode, u_long start_frame, u_long end_frame, void (*func1)(), void (*func2)())
{
    StSetMask(1, start_frame, end_frame);
    D_80039C38 = 0;
    D_80039C98 = func1;
    D_80039C10 = mode & 1;
    D_80039C20 = 0;
    D_80039C18 = 0;
    D_80039C0C = 0;
    D_80039C08 = 0;
    D_80039C9C = func2;
}
