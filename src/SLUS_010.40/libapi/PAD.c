#include "common.h"
#include <libapi.h>

extern int D_80033664;

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libapi/PAD", SetInitPadFlag);

int ReadInitPadFlag(void) { return D_80033664; }

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libapi/PAD", PAD_init);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libapi/PAD", func_8002EAE0);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libapi/PAD", StartPAD);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libapi/PAD", StopPAD);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libapi/PAD", func_8002EBD8);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libapi/PAD", func_8002EC50);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libapi/PAD", func_8002EC88);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libapi/PAD", func_8002ECF0);
