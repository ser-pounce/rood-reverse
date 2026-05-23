#include "common.h"

typedef void (*CdlCB)(unsigned char, unsigned char*);

extern unsigned char D_80032208;
extern unsigned char D_80032214[];
extern unsigned char D_80032218;
extern unsigned char D_80032219;
extern int D_80032204;
extern CdlCB D_800321FC;
extern CdlCB D_80032200;

int CdStatus(void) { return D_80032208; }

int CdMode(void) { return D_80032218; }

int CdLastCom(void) { return D_80032219; }

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libcd/SYS", CdLastPos);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libcd/SYS", CdReset);

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
