#include "common.h"

extern int D_80032824;

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSREADY", DsStartReadySystem);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSREADY", DsEndReadySystem);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSREADY", DsReadySystemMode);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSREADY", func_80026360);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSREADY", func_8002663C);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSREADY", func_800266F4);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSREADY", func_8002676C);

int ER_active(void) { return D_80032824; }

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSREADY", ER_clear);
