#pragma once
#include "common.h"
#include <libcd.h>
#include <libetc.h>

/* CD-ROM controller registers 0x1F801800-0x1F801803 */
extern volatile u_char* D_800324C0; /* index/status */
extern volatile u_char* D_800324C4;
extern volatile u_char* D_800324C8;
extern volatile u_char* D_800324CC;
extern u_int* D_800324D0; /* COM delay */
extern volatile u_short* D_800324D4; /* SPU registers */
extern volatile u_int* D_800324F4; /* CD-ROM delay/size */
extern volatile u_int* D_800324F8; /* DMA DPCR */
extern volatile u_int* D_800324FC; /* DMA3 MADR */
extern volatile u_int* D_80032500; /* DMA3 BCR */
extern volatile u_int* D_80032504; /* DMA3 CHCR */

typedef struct {
    u_char sync;
    u_char ready;
    u_char unk2;
} CdIntrState;

extern volatile CdIntrState D_800324D8;
extern CdlCB D_800321FC; /* sync callback */
extern CdlCB D_80032200; /* ready callback */
extern int D_80032208; /* CD status */
extern int D_8003220C;
extern int D_800324A4;
extern int D_80032204; /* debug level */
extern int D_80032210; /* shell open count */
extern u_char D_80032219; /* last command */
extern char* D_80032220[]; /* command names */
extern int D_800322C0[]; /* commands answered with Acknowledge only */
extern int D_800323C0[]; /* commands whose Acknowledge carries the status */
extern u_char D_80039C50[]; /* sync result */
extern u_char D_80039C58[]; /* ready result */
extern u_char D_80039C60[]; /* data-end result */
extern char D_800103FC[]; /* "DiskError: " */
extern char D_80010408[]; /* "com=%s,code=(%02x:%02x)\n" */
extern char D_80010424[]; /* "CDROM: unknown intr" */
extern char D_80010438[]; /* "(%d)\n" */

int func_800209C4(void);
void func_80022054(void);
void std_out_puts(char*);
int printf(char*, ...);

static inline void CD_memcpy(u_char* dst, u_char* src, int n)
{
    if (dst != NULL) {
        while (n-- != 0) {
            *dst++ = *src++;
        }
    }
}

void CD_flush(void);
int CD_cw(u_char com, u_char* param, u_char* result, int async);
int CD_sync(int mode, u_char* result);

typedef struct {
    int time; /* VSync(-1) deadline */
    int count; /* poll count */
    char* name; /* caller name for the timeout report */
} CdAlarm;
extern CdAlarm D_80039C68; /* command-timeout alarm */
extern char D_800103D0[]; /* "CD timeout: " */
extern char D_800103E0[]; /* "%s:(%s) Sync=%s, Ready=%s\n" */
extern char* D_800322A0[]; /* interrupt names */
extern u_char D_80032214[4]; /* last CdlSetloc position */
extern u_char D_80032218; /* last CdlSetmode mode */
extern int
    D_80032340[]; /* per command: clears the ready state; [com + 0x40]: parameter count */
extern int D_80032440[]; /* per command: needs parameters */
extern u_char D_800324DC[];
