#include "common.h"
#include <libds.h>

int DsControlF(u_char com, u_char* param) { return DsCommand(com, param, NULL, 0); }

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSSYS_4", DsControl);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSSYS_4", DsControlB);
