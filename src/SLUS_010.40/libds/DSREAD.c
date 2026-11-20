#include "common.h"
#include <libds.h>

typedef struct {
    int sectsize;
    u_long* addr;
    int nsector;
    int mode;
    u_char* result;
    DslCB oldcb;
    int starttime;
    int lasttime;
    int state;
} DsReadCtx;

extern DsReadCtx D_800327D4;
extern DslCB D_800327F8;

void func_80025DB8(u_char intr, u_char* result, u_long* buf);
void func_80025F30(u_char intr, u_char* result);
void func_800260A8(int abort);
void func_80025D84(u_char intr, u_char* result);
extern int ER_active(void);
extern void ER_clear(void);
extern int VSync(int);
extern void DS_stop(void);
extern void DS_CQ_flush(void);
extern void DS_restart(void);
extern int DS_cw_system(int, int);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSREAD", DsRead);

void func_80025D84(u_char intr, u_char* result)
{
    if (intr == DslComplete) {
        DsStartReadySystem((DslRCB)func_80025DB8, -1);
    }
}

void func_80025DB8(u_char intr, u_char* result, u_long* buf)
{
    D_800327D4.lasttime = VSync(-1);
    if (D_800327D4.mode & 1) {
        if (D_800327D4.nsector > 0) {
            DsGetSector2(D_800327D4.addr, D_800327D4.sectsize);
            D_800327D4.result = result;
            return;
        }
        func_800260A8(1);
        if (D_800327F8 != NULL) {
            if (D_800327D4.nsector < 0) {
                intr = DslDiskError;
            }
            D_800327F8(intr, result);
        }
    } else {
        if (D_800327D4.nsector > 0) {
            DsGetSector(D_800327D4.addr, D_800327D4.sectsize);
            D_800327D4.addr += D_800327D4.sectsize;
            D_800327D4.nsector--;
        }
        if (VSync(-1) > D_800327D4.starttime + 1200) {
            D_800327D4.nsector = -1;
        }
        if (D_800327D4.nsector == 0 || VSync(-1) > D_800327D4.starttime + 1200) {
            func_800260A8(1);
            if (D_800327F8 != NULL) {
                intr = DslComplete;
                if (D_800327D4.nsector < 0) {
                    intr = DslDiskError;
                }
                D_800327F8(intr, result);
            }
        }
    }
}

void func_80025F30(u_char intr, u_char* result)
{
    D_800327D4.addr += D_800327D4.sectsize;
    D_800327D4.nsector--;
    if (VSync(-1) > D_800327D4.starttime + 1200) {
        D_800327D4.nsector = -1;
    }
    if (D_800327D4.nsector == 0 || VSync(-1) > D_800327D4.starttime + 1200) {
        func_800260A8(1);
        if (D_800327F8 != NULL) {
            D_800327F8(
                D_800327D4.nsector < 0 ? DslDiskError : DslComplete, D_800327D4.result);
        }
    }
}

int DsReadSync(u_char* result)
{
    int ret;
    if (VSync(-1) > D_800327D4.starttime + 1200) {
        ret = -1;
        func_800260A8(1);
    } else {
        ret = D_800327D4.nsector;
    }
    DsReady(result);
    return ret;
}

DslCB DsReadCallback(DslCB func)
{
    DslCB old = D_800327F8;
    D_800327F8 = func;
    return old;
}

void DsReadBreak(void) { func_800260A8(0); }

void func_800260A8(int abort)
{
    if (D_800327D4.state == 1) {
        if (abort) {
            DS_stop();
            DS_CQ_flush();
            ER_clear();
            DS_restart();
            DS_cw_system(9, 0);
        } else {
            DsFlush();
        }
        if (D_800327D4.mode & 1) {
            DsDataCallback(D_800327D4.oldcb);
        }
    }
    D_800327D4.state = 0;
}

void DsReadMode(u_int mode)
{
    if (mode < 2) {
        D_800327D4.mode = mode;
    }
}
