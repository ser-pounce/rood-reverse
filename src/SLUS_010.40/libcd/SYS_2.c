#include "common.h"
#include <libcd.h>

int CD_vol(CdlATV* vol);
int CD_getsector(void* madr, int size);
int CD_getsector2(void* madr, int size);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libcd/SYS_2", CdFlush);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libcd/SYS_2", CdSetDebug);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libcd/SYS_2", CdComstr);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libcd/SYS_2", CdIntstr);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libcd/SYS_2", CdSync);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libcd/SYS_2", CdReady);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libcd/SYS_2", CdSyncCallback);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libcd/SYS_2", CdReadyCallback);

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

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libcd/SYS_2", CdDataCallback);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libcd/SYS_2", CdDataSync);

INCLUDE_RODATA("build/src/SLUS_010.40/nonmatchings/libcd/SYS_2", D_80010284);

INCLUDE_RODATA("build/src/SLUS_010.40/nonmatchings/libcd/SYS_2", D_800103D0);

INCLUDE_RODATA("build/src/SLUS_010.40/nonmatchings/libcd/SYS_2", D_800103E0);

INCLUDE_RODATA("build/src/SLUS_010.40/nonmatchings/libcd/SYS_2", D_800103FC);

INCLUDE_RODATA("build/src/SLUS_010.40/nonmatchings/libcd/SYS_2", D_80010408);

INCLUDE_RODATA("build/src/SLUS_010.40/nonmatchings/libcd/SYS_2", D_80010424);

INCLUDE_RODATA("build/src/SLUS_010.40/nonmatchings/libcd/SYS_2", D_80010438);
