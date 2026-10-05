#include "pad.h"
#include "PADMAIN.h"

extern padPort* (*D_800335B0)(int);
extern padPort* D_800335D0;
extern int D_800335E8;

int PadChkVsync(void) { return _padChkVsync(); }

void PadStartCom(void) { _padStartCom(); }

void PadStopCom(void) { _padStopCom(); }

int PadChkMtap(int port)
{
    int ret;

    if (D_800335E8 == 0) {
        ret = 0;
    } else {
        ret = D_800335D0[port >> 4].unkE8 == 8;
    }

    return ret;
}

int PadGetState(int port)
{
    padPort* pad = D_800335B0(port);

    if ((pad->unk37 == 0) && (pad->unk38 == 0)
        && ((pad == pad->unk10) || (pad->unk39 == 0)) && (pad->unk30[0] == 0)) {
        return pad->unk49;
    }

    switch (pad->unk49) {
    case 2:
        return 1;

    case 3:
        return 1;

    case 6:
        return 4;
    }

    return pad->unk49;
}

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libpad/PADENTRY", PadInfoMode);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libpad/PADENTRY", PadInfoAct);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libpad/PADENTRY", PadInfoComb);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libpad/PADENTRY", PadSetActAlign);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libpad/PADENTRY", PadSetMainMode);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libpad/PADENTRY", PadSetAct);
