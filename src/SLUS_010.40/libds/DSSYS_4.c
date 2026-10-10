#include "common.h"
#include <libds.h>

int DsControlF(u_char com, u_char* param) { return DsCommand(com, param, NULL, 0); }

int DsControl(u_char com, u_char* param, u_char* result)
{
    int id;
    u_char ret;

    id = DsCommand(com, param, NULL, 0);
    if (id == 0) {
        return 0;
    }
    while ((ret = DsSync(id, result)) == DslNoIntr)
        ;
    return ret == DslComplete;
}

int DsControlB(u_char com, u_char* param, u_char* result)
{
    int id;
    u_char ret;

    id = DsCommand(com, param, NULL, 0);
    if (id == 0) {
        return 0;
    }
    while ((ret = DsSync(id, result)) == DslNoIntr)
        ;
    return ret == DslComplete;
}
