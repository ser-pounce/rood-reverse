#include "common.h"
#include <libcd.h>

void CD_flush(void);
int CD_sync(int mode, u_char* result);
int CD_ready(int mode, u_char* result);
int CD_vol(CdlATV* vol);
int CD_getsector(void* madr, int size);
int CD_getsector2(void* madr, int size);
int CD_datasync(int mode);
void* DMACallback(int dma, void (*func)());

extern CdlCB D_800321FC;
extern CdlCB D_80032200;
extern int D_80032204;
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

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libcd/SYS_2", CdControl);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libcd/SYS_2", CdControlF);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libcd/SYS_2", CdControlB);

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
