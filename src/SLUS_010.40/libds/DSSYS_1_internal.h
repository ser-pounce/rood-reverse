#pragma once
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
