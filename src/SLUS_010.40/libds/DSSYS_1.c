#include "common.h"
#include <libds.h>

typedef struct {
    int active; /* 8003267C */
    u_char com; /* 80032680 */
    u_char param[4]; /* 80032681 */
    u_char* pparam; /* 80032688 */
    u_char result[8]; /* 8003268C */
    u_char status; /* 80032694 */
    int state; /* 80032698 */
    int sys[3]; /* 8003269C */
    u_char lastcom; /* 800326A8 */
    u_char lastmode; /* 800326A9 */
    DslLOC lastpos; /* 800326AA */
    u_char lastseek; /* 800326AE */
    u_char lastread; /* 800326AF */
    u_char stat[4]; /* 800326B0 */
    int u38; /* 800326B4 */
    int shell_open; /* 800326B8 */
    int timer; /* 800326BC */
    int remain; /* 800326C0 */
    int retry; /* 800326C4 */
    int u4C; /* 800326C8 */
    u_char u50; /* 800326CC */
    u_char u51; /* 800326CD */
} DS_SYS;

extern int CD_sync(int, u_char*);
extern int CD_ready(int, u_char*);
extern int CD_cw(u_char, u_char*, u_char*, int);
extern int printf(const char*, ...);
extern int ER_active(void);

extern DS_SYS D_8003267C;
extern int D_800326D0[]; /* per-command timeout (seconds) */
extern int D_80032750[]; /* per-command result count */
extern volatile DslCB D_80039E50;
extern volatile DslCB D_80039E54;
extern volatile DslCB D_80039E58;
extern volatile DslCB D_80039E5C;

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
extern int func_80024A04(u_char, u_char*);
extern void rescpy(u_char*, u_char*);
extern void func_80025630(u_char, u_char*);
extern void func_80024F34(u_char, u_char*);
extern void func_8002559C(u_char, u_char*);

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
    D_8003267C.active = 1;
}

void DS_reset_members(void)
{
    u_char* p;
    int i;

    D_8003267C.active = 0;
    D_8003267C.com = 0;
    p = D_8003267C.param;
    for (i = 0; i < 4; i++) {
        p[i] = 0;
    }
    D_8003267C.pparam = NULL;
    p = D_8003267C.result;
    for (i = 0; i < 8; i++) {
        p[i] = 0;
    }
    D_8003267C.status = 0;
    D_8003267C.state = 0;
    D_8003267C.sys[0] = 2;
    D_8003267C.sys[1] = 14;
    D_8003267C.sys[2] = 21;
    D_8003267C.lastcom = 0;
    D_8003267C.lastmode = 0;
    DsIntToPos(0, &D_8003267C.lastpos);
    D_8003267C.lastseek = 0;
    D_8003267C.lastread = 0;
    D_8003267C.stat[0] = 0;
    D_8003267C.stat[1] = 0;
    D_8003267C.stat[2] = 0;
    D_8003267C.stat[3] = 0;
    D_8003267C.u38 = 0;
    D_8003267C.shell_open = 1;
    D_8003267C.timer = 0;
    D_8003267C.retry = 0;
    D_8003267C.remain = 0;
    D_8003267C.u4C = 0;
    D_8003267C.u50 = 0;
    D_8003267C.u51 = 0;
}

void func_8002480C(void)
{
    D_8003267C.active = 0;
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

int DS_system_status(int i) { return D_8003267C.sys[i]; }

int DS_lastcom(void) { return D_8003267C.lastcom; }

int DS_lastmode(void) { return D_8003267C.lastmode; }

DslLOC* DS_lastpos(void) { return &D_8003267C.lastpos; }

int DS_lastseek(void) { return D_8003267C.lastseek; }

int DS_lastread(void) { return D_8003267C.lastread; }

int DS_status(void) { return D_8003267C.status; }

int DS_sync(u_char* result) { return CD_sync(1, result); }

int DS_ready(u_char* result) { return CD_ready(1, result); }

int DS_shell_open(void) { return D_8003267C.shell_open; }

int DS_cw_system(u_char com, u_char* param)
{
    if (D_8003267C.remain > 0) {
        return 0;
    }
    D_8003267C.state = 32;
    return func_80024A04(com, param);
}

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSSYS_1", func_80024A04);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSSYS_1", func_80024BDC);

int func_80024EAC(void)
{
    CD_flush();
    D_8003267C.retry++;
    D_8003267C.remain = D_800326D0[D_8003267C.com] ? D_800326D0[D_8003267C.com] * 60 : 30;
    CD_cw(D_8003267C.com, D_8003267C.pparam, 0, 1);
    return 0;
}

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSSYS_1", func_80024F34);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSSYS_1", func_80025044);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSSYS_1", func_80025228);

void func_800254B0(u_char intr, u_char* result)
{
    u_char mode;
    u_char old;

    if (intr == DslComplete && D_8003267C.com == DslSetmode) {
        old = D_8003267C.lastmode;
        mode = D_8003267C.param[0];
        if ((old ^ mode) & DslModeSpeed) {
            D_8003267C.sys[0] = intr;
            D_8003267C.sys[1] = 15;
            D_8003267C.timer = 3;
        }
        D_8003267C.lastmode = mode;
    }
    if (intr == DslDiskError) {
        if (D_8003267C.status & DslStatShellOpen) {
            D_8003267C.sys[0] = 2;
            D_8003267C.sys[1] = 12;
            if (D_80039E54 && D_8003267C.active) {
                D_80039E54(DslDiskError, result);
            }
        } else {
            D_8003267C.sys[0] = 1;
            D_8003267C.sys[1] = 11;
        }
    }
}

void func_8002559C(u_char intr, u_char* result)
{
    func_80025630(intr, result);
    if (D_8003267C.status & DslStatShellOpen) {
        D_8003267C.sys[0] = 2;
        D_8003267C.sys[1] = 12;
    }
    if (D_80039E58 && D_8003267C.active) {
        D_80039E58(intr, result);
    }
}

void func_80025630(u_char intr, u_char* result)
{
    int n;
    u_char st;
    if (intr != DslDiskError) {
        n = D_80032750[D_8003267C.com] - 1;
        if (n < 0) {
            return;
        }
    } else {
        n = 0;
    }
    st = result[n];
    D_8003267C.stat[0] = st >> 7;
    D_8003267C.stat[1] = (st >> 6) & 1;
    D_8003267C.stat[2] = (st >> 5) & 1;
    D_8003267C.stat[3] = (st >> 1) & 1;
    D_8003267C.status = st;
    rescpy(D_8003267C.result, result);
}

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSSYS_1", DS_stop);

void DS_restart(void) { D_8003267C.active = 1; }

int DS_system_active(void) { return D_8003267C.active; }

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

void tipDsSystem(void)
{
    printf("*** STATUS of DS system ***\n");
    printf("\tcommand status: %d %d %d\n", D_8003267C.sys[0], D_8003267C.sys[1],
        D_8003267C.sys[2]);
    printf("\tlast command: %02x %02x%02x%02x%02x\n", D_8003267C.com, D_8003267C.param[0],
        D_8003267C.param[1], D_8003267C.param[2], D_8003267C.param[3]);
    printf("\tcommand execution(remain): %d\n", D_8003267C.remain);
    printf("\tsystem timer: %d\n", D_8003267C.timer);
    printf("\tcallbacks vsync: %08x sync: %08x ready: %08x\n", D_80039E50, D_80039E54,
        D_80039E58);
    printf("\tready system: %s\n", ER_active() ? "active" : "none");
}
