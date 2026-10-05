#include "common.h"
#include <libds.h>

extern int D_8003267C;
extern volatile DslCB D_80039E50;
extern volatile DslCB D_80039E54;
extern volatile DslCB D_80039E58;
extern volatile DslCB D_80039E5C;
extern DslLOC D_800326AA;
extern int D_8003269C[];
extern void DsReadMode(u_int);
extern int VSyncCallbacks(int, void (*)());
extern void (*D_800321FC)();
extern void (*D_80032200)();
extern int D_8003221C;
extern void CD_init(void);
extern void CD_initvol(void);
extern void CD_flush(void);
extern void DS_reset_members(void);
extern void func_80024BDC();
extern void func_80024F34();
extern void func_8002559C();

void DS_init(void)
{
    CD_init();
    CD_initvol();
    D_80039E54 = D_80039E58 = NULL;
    D_80039E50 = NULL;
    DS_reset_members();
    DsReadMode(0);
    D_800321FC = func_80024F34;
    D_80032200 = func_8002559C;
    VSyncCallbacks(0, func_80024BDC);
    D_8003221C = 1;
    D_8003267C = 1;
}

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSSYS_1", DS_reset_members);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSSYS_1", DS_close);

void func_8002480C(void)
{
    D_8003267C = 0;
    CD_flush();
    D_800321FC = NULL;
    D_80032200 = NULL;
    VSyncCallbacks(0, NULL);
}

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSSYS_1", DS_cw);

void DS_vsync_callback(DslCB func) { D_80039E50 = func; }

void DS_sync_callback(DslCB func) { D_80039E54 = func; }

void DS_ready_callback(DslCB func) { D_80039E58 = func; }

void DS_start_callback(DslCB func) { D_80039E5C = func; }

int DS_system_status(int i) { return D_8003269C[i]; }

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSSYS_1", DS_lastcom);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSSYS_1", DS_lastmode);

DslLOC* DS_lastpos(void) { return &D_800326AA; }

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSSYS_1", DS_lastseek);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSSYS_1", DS_lastread);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSSYS_1", DS_status);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSSYS_1", DS_sync);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSSYS_1", DS_ready);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSSYS_1", DS_shell_open);

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

void DS_restart(void) { D_8003267C = 1; }

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSSYS_1", DS_system_active);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSSYS_1", parcpy);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSSYS_1", rescpy);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSSYS_1", tipDsSystem);
