#include "common.h"

extern u_char D_800326A8;
extern u_char D_800326A9;
extern u_char D_800326AE;
extern u_char D_800326AF;
extern u_char D_80032694;
extern int D_800326B8;
extern int D_8003267C;

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSSYS_1", DS_init);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSSYS_1", DS_reset_members);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSSYS_1", DS_close);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSSYS_1", func_8002480C);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSSYS_1", DS_cw);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSSYS_1", DS_vsync_callback);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSSYS_1", DS_sync_callback);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSSYS_1", DS_ready_callback);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSSYS_1", DS_start_callback);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSSYS_1", DS_system_status);

int DS_lastcom(void) { return D_800326A8; }

int DS_lastmode(void) { return D_800326A9; }

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSSYS_1", DS_lastpos);

int DS_lastseek(void) { return D_800326AE; }

int DS_lastread(void) { return D_800326AF; }

int DS_status(void) { return D_80032694; }

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSSYS_1", DS_sync);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSSYS_1", DS_ready);

int DS_shell_open(void) { return D_800326B8; }

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSSYS_1", DS_cw_system);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSSYS_1", func_80024A04);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSSYS_1", func_80024BDC);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSSYS_1", func_80024EAC);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSSYS_1", func_80024F34);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSSYS_1", func_80025044);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSSYS_1", func_80025228);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSSYS_1", func_800254B0);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSSYS_1", func_8002559C);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSSYS_1", func_80025630);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSSYS_1", DS_stop);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSSYS_1", DS_restart);

int DS_system_active(void) { return D_8003267C; }

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSSYS_1", parcpy);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSSYS_1", rescpy);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSSYS_1", tipDsSystem);
