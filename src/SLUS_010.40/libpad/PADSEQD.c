#include "pad.h"

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libpad/PADSEQD", _padInitDirSeq);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libpad/PADSEQD", func_8002E368);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libpad/PADSEQD", func_8002E478);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libpad/PADSEQD", func_8002E6DC);

int func_8002E7BC(padPort* port)
{
    int ret;

    if ((port->unkE6 == 0) || (port->unk46 != 0xFF)) {
        ret = 1;
    } else {
        ret = 0;
    }

    return ret;
}
