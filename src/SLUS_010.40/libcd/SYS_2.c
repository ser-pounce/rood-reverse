#include "common.h"
#include <libcd.h>
#include <libetc.h>

void CD_flush(void);
int CD_sync(int mode, u_char* result);
int CD_ready(int mode, u_char* result);
int CD_vol(CdlATV* vol);
int CD_getsector(void* madr, int size);
int CD_getsector2(void* madr, int size);
int CD_datasync(int mode);
int CD_cw(u_char com, u_char* param, u_char* result, int async);

extern CdlCB D_800321FC;
extern CdlCB D_80032200;
extern int D_80032204;
extern u_char D_80032208; /* CD status */
extern int D_80032174[]; /* commands that take a CdlLOC parameter */
extern char* D_80032220[];
extern char* D_800322A0[];
extern char D_80010284[];

void CdFlush(void) { CD_flush(); }

int CdSetDebug(int level)
{
    int old;

    old = D_80032204;
    D_80032204 = level;
    return old;
}

char* CdComstr(u_char com)
{
    if (com > 27) {
        return D_80010284;
    }
    return D_80032220[com];
}

char* CdIntstr(u_char intr)
{
    if (intr > 6) {
        return D_80010284;
    }
    return D_800322A0[intr];
}

int CdSync(int mode, u_char* result) { return CD_sync(mode, result); }

int CdReady(int mode, u_char* result) { return CD_ready(mode, result); }

CdlCB CdSyncCallback(CdlCB func)
{
    CdlCB old = D_800321FC;

    D_800321FC = func;
    return old;
}

CdlCB CdReadyCallback(CdlCB func)
{
    CdlCB old = D_80032200;

    D_80032200 = func;
    return old;
}

/* Retries a command up to four times, issuing CdlSetloc first when the command takes a
 * position. */
static inline int CD_controlRetry(u_char com, u_char* param, u_char* result, int async)
{
    CdlCB old = D_800321FC;
    int count = 4;

    while (count--) {
        D_800321FC = NULL;
        if (com != CdlNop && (D_80032208 & CdlStatShellOpen)) {
            CD_cw(CdlNop, NULL, NULL, 0);
        }
        if (param == NULL || D_80032174[com] == 0
            || CD_cw(CdlSetloc, param, result, 0) == 0) {
            D_800321FC = old;
            if (CD_cw(com, param, result, async) == 0) {
                return 0;
            }
        }
    }
    D_800321FC = old;
    return -1;
}

int CdControl(u_char com, u_char* param, u_char* result)
{
    return CD_controlRetry(com, param, result, 0) + 1;
}

int CdControlF(u_char com, u_char* param)
{
    return CD_controlRetry(com, param, NULL, 1) + 1;
}

int CdControlB(u_char com, u_char* param, u_char* result)
{
    if (CD_controlRetry(com, param, result, 0) != 0) {
        return 0;
    }
    return CD_sync(0, result) == CdlComplete;
}

int CdMix(CdlATV* vol)
{
    CD_vol(vol);
    return 1;
}

int CdGetSector(void* madr, int size) { return CD_getsector(madr, size) == 0; }

int CdGetSector2(void* madr, int size) { return CD_getsector2(madr, size) == 0; }

void(*CdDataCallback(void (*func)())) { return DMACallback(3, func); }

int CdDataSync(int mode) { return CD_datasync(mode); }

INCLUDE_RODATA("build/src/SLUS_010.40/nonmatchings/libcd/SYS_2", D_80010284);

INCLUDE_RODATA("build/src/SLUS_010.40/nonmatchings/libcd/SYS_2", D_800103D0);

INCLUDE_RODATA("build/src/SLUS_010.40/nonmatchings/libcd/SYS_2", D_800103E0);

INCLUDE_RODATA("build/src/SLUS_010.40/nonmatchings/libcd/SYS_2", D_800103FC);

INCLUDE_RODATA("build/src/SLUS_010.40/nonmatchings/libcd/SYS_2", D_80010408);

INCLUDE_RODATA("build/src/SLUS_010.40/nonmatchings/libcd/SYS_2", D_80010424);

INCLUDE_RODATA("build/src/SLUS_010.40/nonmatchings/libcd/SYS_2", D_80010438);
