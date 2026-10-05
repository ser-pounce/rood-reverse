#include "common.h"
#include <libds.h>

extern int CD_vol(DslATV*);
extern int CD_getsector(void*, int);
extern int CD_getsector2(void*, int);
extern int CD_datasync(int);

int DsMix(DslATV* vol)
{
    CD_vol(vol);
    return 1;
}

int DsGetSector(void* madr, int size) { return CD_getsector(madr, size) == 0; }

int DsGetSector2(void* madr, int size) { return CD_getsector2(madr, size) == 0; }

int DsDataSync(int mode) { return CD_datasync(mode); }

DslLOC* DsIntToPos(int i, DslLOC* p)
{
    int sec, min;

    i += 150;
    sec = i / 75;
    min = sec / 60;
    p->sector = itob(i % 75);
    p->second = itob(sec % 60);
    p->minute = itob(min);
    return p;
}

int DsPosToInt(DslLOC* p)
{
    return (btoi(p->minute) * 60 + btoi(p->second)) * 75 + btoi(p->sector) - 150;
}

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSSYS_3", DsSetDebug);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSSYS_3", DsLastPos);
