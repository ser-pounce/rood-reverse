#include "common.h"
#include <libcd.h>

int CD_init(void);
void CD_initintr(void);
int CD_initvol(void);

extern u_char D_80032208;
extern CdlLOC D_80032214;
extern u_char D_80032218;
extern u_char D_80032219;

int CdStatus(void) { return D_80032208; }

int CdMode(void) { return D_80032218; }

int CdLastCom(void) { return D_80032219; }

CdlLOC* CdLastPos(void) { return &D_80032214; }

int CdReset(int mode)
{
    if (mode == 2) {
        CD_initintr();
        return 1;
    }

    if (CD_init() != 0) {
        return 0;
    }

    if (mode == 1) {
        if (CD_initvol() != 0) {
            return 0;
        }
    }
    return 1;
}
