#include "pad.h"
#include "PADMAIN.h"
#include "WAITRC2.h"
#include <libapi.h>

int ChangeClearRCnt(int, int);
int SysDeqIntRP(int, void*);
int _padInitSioMode(padPort*);
void func_8002C438(padPort*);

extern void (*D_8003359C)(int);
extern void (*D_800335A0)(padPort*);
extern void (*D_800335C4)(void);
extern padPort* D_800335D0;
extern int D_800335D4;
extern int D_800335DC;
extern int D_800335E0;
extern int D_800335E4;
extern int D_800335EC;
extern int D_800335F0;
extern volatile padIntr* D_800335FC;
extern volatile padSio* D_80033600;
extern int D_80033604;
extern int (*D_80033624[])(padPort*);
extern int D_8003FC00[];
extern int D_8003FC10[2];
extern u_int D_8003FEA0;
extern u_int D_8003FEA4;

#define SIO_DATA (*(volatile u_char*)&D_80033600->data)
#define SIO_SET_BAUD(x)         \
    do {                        \
        D_80033600->baud = (x); \
    } while (0)

#define RCNT2_COUNT (*(volatile u_short*)0x1F801120)
#define RCNT2_MODE (*(volatile u_short*)0x1F801124)
#define RCNT2_TARGET (*(volatile u_short*)0x1F801128)

int PadEnableCom(int mode)
{
    int old = (D_800335F0 << 1) | (D_800335EC == 0);

    if (old == mode) {
        return old;
    }
    D_800335D4 = 0;
    if (mode & 1) {
        D_800335EC = 0;
        if (D_8003FC10[0] >= 150) {
            D_800335A0(D_800335D0);
        }
        D_8003FC10[0] = 0;
    } else {
        D_800335EC = 1;
    }
    if (mode & 2) {
        D_800335F0 = 1;
        if (D_8003FC10[1] >= 150) {
            D_800335A0(D_800335D0 + 1);
        }
        D_8003FC10[1] = 0;
    } else {
        D_800335F0 = 0;
    }
    D_800335D4 = 1;
    return old;
}

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libpad/PADMAIN", _padSetVsyncParam);

int func_8002BDE8(void)
{
    if (!(D_800335FC->mask & 1) || !(D_800335FC->stat & 1)) {
        return 0;
    }

    if (D_800335C4 != NULL) {
        D_800335C4();
    }

    return 1;
}

int func_8002BE50(void)
{
    if (D_80033600->ctrl & 2) {
        D_80033600->ctrl = 0;
        return 0;
    }
    D_80033604 = 1;
    if (D_800335EC != 0 && D_8003FC10[0] < 150) {
        D_8003FC10[0]++;
    }
    if (D_800335F0 == 0 && D_8003FC10[1] < 150) {
        D_8003FC10[1]++;
    }
    if (D_800335D4 != 0 && D_800335EC <= D_800335F0) {
        D_800335E0 = 0;
        D_800335DC = D_800335EC;
        if (_padInitSioMode(&D_800335D0[D_800335EC]) == 0) {
            D_8003359C(0xFFFF);
        }
        D_800335E4 = 0;
        while (D_800335DC <= D_800335F0) {
            func_8002C438(&D_800335D0[D_800335DC]);
        }
        D_80033600->baud = 0x88;
    }
    return 0;
}

int _padChkVsync(void)
{
    int ret = D_80033604;
    D_80033604 = 0;
    return ret;
}

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libpad/PADMAIN", _padStartCom);

void _padStopCom(void)
{
    EnterCriticalSection();
    ChangeClearRCnt(3, 1);
    SysDeqIntRP(2, D_8003FC00);
    ExitCriticalSection();
}

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libpad/PADMAIN", _padInitSioMode);

void func_8002C438(padPort* port)
{
    int ret;
    int* index;
    int (*func)(padPort*);

    index = &D_800335E0;

    do {
        func = D_80033624[*index];
    } while (0);

    *index += 1;
    ret = func(port);

    if (ret >= 0) {
        if ((D_800335E0 != 0) && ((D_800335E0 != 3) || (*port->unk3C != 128))) {
            setRC2wait(60);

            if (_padClrIntSio0() == 0) {
                D_8003359C(-3);
            }
        }
        if (D_800335E0 >= 5) {
            --D_800335E0;
        }
    } else {
        D_8003359C(ret);
    }
}

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libpad/PADMAIN", _padSioRW);

int _padSioRW2(padPort* port, int data)
{
    int recv;
    int baud;
    int type;
    int pos;
    u_int now;

    baud = 0x88;
    type = port->unk3C[0];
    if ((type >> 4) == 8 && port->unk44 >= 9) {
        baud = 0x22;
    }
    while (!(D_80033600->stat & 2)) { }
    setRC2wait(400);
    recv = SIO_DATA;
    if (port->unk44 != 0 || (recv >> 4) != 8) {
        SIO_SET_BAUD(baud);
    } else {
        SIO_SET_BAUD(0x22);
    }
    /* inlined chkRC2wait() timeout */
    while (!(D_800335FC->stat & 0x80)) {
        now = RCNT2_COUNT;
        if (now < D_8003FEA0) {
            if (RCNT2_TARGET != 0) {
                now += RCNT2_TARGET;
            } else {
                now += 0x10000;
            }
        }
        if (RCNT2_MODE & 0x200) {
            if ((now - D_8003FEA0) >= D_8003FEA4) {
                return -2;
            }
        } else if (((now - D_8003FEA0) >> 3) >= D_8003FEA4) {
            return -2;
        }
    }
    if (port->unkE8 != 8 && D_800335E0 == 2) {
        setRC2wait(60);
        while (!chkRC2wait()) { }
    }
    SIO_DATA = data;
    if (D_800335E0 == 3 && recv == 0x80) {
        D_800335FC->stat = ~0x80;
        D_80033600->ctrl |= 0x10;
    }
    pos = port->unk44;
    port->unk45++;
    if (pos != 0xFF) {
        port->unk3C[port->unk44] = recv;
    }
    port->unk44++;
    return recv;
}

int _padClrIntSio0(void)
{
    D_800335FC->stat = ~0x80;

    while (D_80033600->stat & 0x80) {
        if (chkRC2wait()) {
            return 0;
        }
    }

    D_80033600->ctrl |= 0x10;
    return 1;
}

void _padWaitRXready(void)
{
    while (!(D_80033600->stat & 2)) { }
}
