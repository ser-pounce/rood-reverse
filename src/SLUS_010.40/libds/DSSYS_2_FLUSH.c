#include "DSSYS_2_internal.h"

void DS_CQ_flush(void)
{
    int i;
    D_80039CF0.len = 0;
    D_80039CF0.tail = 0;
    D_80039CF0.head = 0;
    for (i = 0; i < DslMaxCOMMANDS; i++) {
        DS_CQ* p = &D_80039CF0.q[i];
        int j;
        p->id = 0;
        p->com = 0;
        for (j = 0; j < 4; j++) {
            p->param[j] = 0;
        }
        p->pparam = 0;
        p->x10 = 0;
        p->x14 = 0;
    }
}
