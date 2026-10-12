#include "PADMAIN_internal.h"

int func_8002BDE8(void);
int func_8002BE50(void);

void _padSetVsyncParam(void)
{
    int (**callback)() = &D_8003FC00.func2;
    *callback = func_8002BE50;
    D_8003FC00.func1 = func_8002BDE8;
    D_8003FC00.next = NULL;
    D_8003FC00.unk = 0;
}
