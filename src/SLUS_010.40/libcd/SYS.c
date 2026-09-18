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

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libcd/SYS", CdFlush);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libcd/SYS", CdSetDebug);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libcd/SYS", CdComstr);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libcd/SYS", CdIntstr);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libcd/SYS", CdSync);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libcd/SYS", CdReady);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libcd/SYS", CdSyncCallback);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libcd/SYS", CdReadyCallback);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libcd/SYS", CdControl);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libcd/SYS", CdControlF);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libcd/SYS", CdControlB);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libcd/SYS", CdMix);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libcd/SYS", CdGetSector);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libcd/SYS", CdGetSector2);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libcd/SYS", CdDataCallback);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libcd/SYS", CdDataSync);

INCLUDE_RODATA("build/src/SLUS_010.40/nonmatchings/libcd/SYS", D_80010284);

INCLUDE_RODATA("build/src/SLUS_010.40/nonmatchings/libcd/SYS", D_800103D0);

INCLUDE_RODATA("build/src/SLUS_010.40/nonmatchings/libcd/SYS", D_800103E0);

INCLUDE_RODATA("build/src/SLUS_010.40/nonmatchings/libcd/SYS", D_800103FC);

INCLUDE_RODATA("build/src/SLUS_010.40/nonmatchings/libcd/SYS", D_80010408);

INCLUDE_RODATA("build/src/SLUS_010.40/nonmatchings/libcd/SYS", D_80010424);

INCLUDE_RODATA("build/src/SLUS_010.40/nonmatchings/libcd/SYS", D_80010438);
