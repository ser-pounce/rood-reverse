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

int func_800209C4(void)
{
    volatile u_char intr;
    volatile u_char result[8];
    int i;
    int j;
    int err;

    *D_800324C0 = 1;
    intr = *D_800324CC & 7;
    err = 0;
    if (intr == 0) {
        return 0;
    }
    while (intr != (*D_800324CC & 7)) {
        intr = *D_800324CC & 7;
    }
    for (i = 0; i < 8 && (*D_800324C0 & 0x20); i++) {
        result[i] = *D_800324C4;
    }
    for (j = i; j < 8; j++) {
        result[j] = 0;
    }
    *D_800324C0 = 1;
    *D_800324CC = 7;
    *D_800324C8 = 7;
    if (intr != CdlAcknowledge || D_800323C0[D_80032219] != 0) {
        if (!(D_80032208 & CdlStatShellOpen) && (result[0] & CdlStatShellOpen)) {
            D_80032210++;
        }
        D_80032208 = result[0];
        D_8003220C = result[1];
        err = D_80032208;
        err &= 0x1D;
    }
    if (intr == CdlDiskError) {
        if (D_80032204 > 2) {
            printf(D_800103FC);
        }
        if (D_80032204 > 2) {
            printf(D_80010408, D_80032220[D_80032219], D_80032208, D_8003220C);
        }
    }
    switch (intr) {
    case CdlAcknowledge:
        if (err) {
            D_800324D8.sync = CdlDiskError;
            CD_memcpy(D_80039C50, (u_char*)result, 8);
            return 2;
        }
        if (D_800322C0[D_80032219] != 0) {
            D_800324D8.sync = CdlAcknowledge;
            CD_memcpy(D_80039C50, (u_char*)result, 8);
            return 1;
        }
        D_800324D8.sync = CdlComplete;
        CD_memcpy(D_80039C50, (u_char*)result, 8);
        return 2;
    case CdlComplete:
        D_800324D8.sync = err ? CdlDiskError : CdlComplete;
        CD_memcpy(D_80039C50, (u_char*)result, 8);
        return 2;
    case CdlDataReady:
        if (err && i == 1) {
            err = 0;
        }
        D_800324D8.ready = err ? CdlDiskError : CdlDataReady;
        CD_memcpy(D_80039C58, (u_char*)result, 8);
        *D_800324C0 = 0;
        *D_800324CC = 0;
        return 4;
    case CdlDataEnd:
        D_800324D8.ready = D_800324D8.unk2 = CdlDataEnd;
        CD_memcpy(D_80039C60, (u_char*)result, 8);
        CD_memcpy(D_80039C58, (u_char*)result, 8);
        return 4;
    case CdlDiskError:
        D_800324D8.sync = D_800324D8.ready = CdlDiskError;
        CD_memcpy(D_80039C50, (u_char*)result, 8);
        CD_memcpy(D_80039C58, (u_char*)result, 8);
        return 6;
    default:
        std_out_puts(D_80010424);
        printf(D_80010438, intr);
        return 0;
    }
}

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libcd/BIOS", CD_sync);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libcd/BIOS", CD_ready);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libcd/BIOS", CD_cw);

int CD_vol(CdlATV* vol)
{
    *D_800324C0 = 2;
    *D_800324C8 = vol->val0;
    *D_800324CC = vol->val1;
    *D_800324C0 = 3;
    *D_800324C4 = vol->val2;
    *D_800324C8 = vol->val3;
    *D_800324CC = 0x20;
    return 0;
}

void CD_flush(void)
{
    *D_800324C0 = 1;
    while (*D_800324CC & 7) {
        *D_800324C0 = 1;
        *D_800324CC = 7;
        *D_800324C8 = 7;
    }
    D_800324D8.ready = D_800324D8.unk2 = CdlNoIntr;
    D_800324D8.sync = CdlComplete;
    *D_800324C0 = 0;
    *D_800324CC = 0;
    *D_800324D0 = 0x1325;
}

int CD_initvol(void)
{
    CdlATV vol;

    if (D_800324D4[0x1B8 / 2] == 0 && D_800324D4[0x1BA / 2] == 0) {
        D_800324D4[0x180 / 2] = 0x3FFF;
        D_800324D4[0x182 / 2] = 0x3FFF;
    }
    D_800324D4[0x1B0 / 2] = 0x3FFF;
    D_800324D4[0x1B2 / 2] = 0x3FFF;
    D_800324D4[0x1AA / 2] = 0xC001;
    vol.val2 = 0x80;
    vol.val0 = 0x80;
    vol.val3 = 0;
    vol.val1 = 0;
    *D_800324C0 = 2;
    *D_800324C8 = vol.val0;
    *D_800324CC = vol.val1;
    *D_800324C0 = 3;
    *D_800324C4 = vol.val2;
    *D_800324C8 = vol.val3;
    *D_800324CC = 0x20;
    return 0;
}

void CD_initintr(void)
{
    D_80032200 = 0;
    D_800321FC = 0;
    D_8003220C = 0;
    D_80032208 = 0;
    ResetCallback();
    InterruptCallback(2, func_80022054);
}

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libcd/BIOS", CD_init);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libcd/BIOS", CD_datasync);

int CD_getsector(void* madr, int size)
{
    *D_800324C0 = 0;
    *D_800324CC = 0x80;
    *D_800324F4 = 0x20943;
    *D_800324D0 = 0x1323;
    *D_800324F8 |= 0x8000;
    *D_800324FC = (u_int)madr;
    *D_80032500 = size | 0x10000;
    while (!(*D_800324C0 & 0x40)) { }
    *D_80032504 = 0x11000000;
    while (*D_80032504 & 0x01000000) { }
    *D_800324D0 = 0x1325;
    return 0;
}

int CD_getsector2(void* madr, int size)
{
    volatile u_int chcr;

    *D_800324C0 = 0;
    *D_800324CC = 0x80;
    *D_800324F4 = 0x21020843;
    *D_800324D0 = 0x1325;
    *D_800324F8 |= 0x8000;
    *D_800324FC = (u_int)madr;
    *D_80032500 = size | 0x10000;
    while (!(*D_800324C0 & 0x40)) { }
    *D_80032504 = 0x11400100;
    chcr = *D_80032504;
    return 0;
}

void CD_set_test_parmnum(int num) { D_800324A4 = num; }

void func_80022054(void)
{
    u_char index = *D_800324C0 & 3;
    int intr;

    while ((intr = func_800209C4()) != 0) {
        if (intr & 4) {
            if (D_80032200 != NULL) {
                D_80032200(D_800324D8.ready, D_80039C58);
            }
        }
        if (intr & 2) {
            if (D_800321FC != NULL) {
                D_800321FC(D_800324D8.sync, D_80039C50);
            }
        }
    }
    *D_800324C0 = index;
}
