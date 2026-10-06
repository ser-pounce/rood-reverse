#include "common.h"
#include <libds.h>
#include <libetc.h>

extern DslCB D_80039E60;
extern DslCB D_80039E64;
extern DslCB D_80039E68;

DslCB DsSyncCallback(DslCB func)
{
    DslCB* p = &D_80039E60;
    DslCB old = *p;
    *p = func;
    return old;
}

DslCB DsReadyCallback(DslCB func)
{
    DslCB* p = &D_80039E64;
    DslCB old = *p;
    *p = func;
    return old;
}

DslCB DsStartCallback(DslCB func)
{
    DslCB* p = &D_80039E68;
    DslCB old = *p;
    *p = func;
    return old;
}

void(*DsDataCallback(void (*func)())) { return DMACallback(3, func); }
