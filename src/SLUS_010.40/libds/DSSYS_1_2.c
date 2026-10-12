#include "DSSYS_1_internal.h"

int DS_cw(u_char com, u_char* param)
{
    int* remain = &D_8003267C.remain;
    int* sys = D_8003267C.sys;
    if (*remain > 0) {
        return 0;
    }
    if (D_8003267C.active != 0) {
        if (sys[0] != 1) {
            return 0;
        }
        D_8003267C.state = 31;
        sys[0] = 2;
        D_8003267C.sys[1] = 11;
        return func_80024A04(com, param);
    }
    return 0;
}

void DS_vsync_callback(DslCB func) { D_80039E50 = func; }

void DS_sync_callback(DslCB func) { D_80039E54 = func; }

void DS_ready_callback(DslCB func) { D_80039E58 = func; }

void DS_start_callback(DslCB func) { D_80039E5C = func; }

int DS_system_status(int i) { return D_8003267C.sys[i]; }

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSSYS_1_2", DS_lastcom);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSSYS_1_2", DS_lastmode);

DslLOC* DS_lastpos(void) { return &D_8003267C.lastpos; }

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSSYS_1_2", DS_lastseek);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSSYS_1_2", DS_lastread);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSSYS_1_2", DS_status);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSSYS_1_2", DS_sync);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSSYS_1_2", DS_ready);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSSYS_1_2", DS_shell_open);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSSYS_1_2", DS_cw_system);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSSYS_1_2", func_80024A04);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSSYS_1_2", func_80024BDC);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSSYS_1_2", func_80024EAC);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSSYS_1_2", func_80024F34);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSSYS_1_2", func_80025044);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSSYS_1_2", func_80025228);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSSYS_1_2", func_800254B0);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSSYS_1_2", func_8002559C);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSSYS_1_2", func_80025630);

/* System-state words also have a separate symbol in the original object. */
extern int D_8003269C[3];
void DS_stop(void)
{
    D_8003267C.active = 0;
    CD_flush();
    D_8003267C.retry = 0;
    D_8003267C.remain = 0;
    if (D_8003267C.sys[0] == 2
        && (D_8003267C.sys[1] == 11 || D_8003267C.sys[1] == 17
            || D_8003267C.sys[1] == 16)) {
        D_8003269C[0] = 1;
        D_8003269C[1] = 11;
    }
}

void DS_restart(void) { D_8003267C.active = 1; }

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSSYS_1_2", DS_system_active);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSSYS_1_2", parcpy);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSSYS_1_2", rescpy);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSSYS_1_2", tipDsSystem);
