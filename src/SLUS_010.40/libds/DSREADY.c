#include "common.h"
#include <libds.h>

/* ready-system state (DsStartReadySystem) */
typedef struct {
    int pos; /* 0x00: expected position */
    int lastPos; /* 0x04: last position reported to func */
    DslRCB func; /* 0x08 */
    int request; /* 0x0C: resend the packet */
    int count; /* 0x10 */
    DslCB oldReady; /* 0x14 */
    DslCB oldStart; /* 0x18 */
    int mode; /* 0x1C */
    int active; /* 0x20 */
} ERSystem;

extern ERSystem D_80032804;

void func_80026360(u_char intr, u_char* result);
void func_8002676C(u_char intr, u_char* result);
int DS_lastmode(void);
DslLOC* DS_lastpos(void);
int DS_lastread(void);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSREADY", DsStartReadySystem);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSREADY", DsEndReadySystem);

int DsReadySystemMode(int mode)
{
    int old = D_80032804.mode;

    D_80032804.mode = mode;
    return old;
}

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSREADY", func_80026360);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSREADY", func_8002663C);

void func_800266F4(void)
{
    int mode;
    DslLOC* pos;

    DsReadyCallback(NULL);
    D_80032804.pos = DsPosToInt(DS_lastpos());
    mode = (u_char)DS_lastmode();
    pos = DS_lastpos();
    DsPacket(mode, pos, DS_lastread(), func_8002676C, -1);
}

void func_8002676C(u_char intr, u_char* result)
{
    if (intr == DslComplete) {
        DsReadyCallback(func_80026360);
    }
}

int ER_active(void) { return D_80032804.active; }

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSREADY", ER_clear);
