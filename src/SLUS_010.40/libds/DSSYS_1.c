#include "common.h"

extern int CD_sync(int, u_char*);
extern int CD_ready(int, u_char*);

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

int DS_sync(u_char* result) { return CD_sync(1, result); }

int DS_ready(u_char* result) { return CD_ready(1, result); }

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

void parcpy(u_char* dst, u_char* src)
{
    int i;
    if (src) {
        if (dst) {
            for (i = 0; i < 4; i++)
                *dst++ = *src++;
        }
    } else if (dst) {
        *dst = 0;
    }
}

void rescpy(u_char* dst, u_char* src)
{
    int i;
    if (src) {
        if (dst) {
            for (i = 0; i < 8; i++)
                *dst++ = *src++;
        }
    } else if (dst) {
        *dst = 0;
    }
}

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSSYS_1", tipDsSystem);
