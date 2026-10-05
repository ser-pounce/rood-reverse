#include "common.h"

/* libpad per-port control block (layout from field accesses in PADCMD/PADMAIN/PADPORTD)
 */
typedef struct {
    u_char size;
    u_char unk1[3];
    u_char* data;
} PadComb;

typedef struct _PadPort PadPort;
struct _PadPort {
    u_short* idTable; /* 0x00 */
    u_char* actInfo; /* 0x04: 5 bytes per actuator */
    PadComb* comb; /* 0x08 */
    PadPort* unkC; /* 0x0C: port block array (multitap) */
    PadPort* self; /* 0x10 */
    void (*sendFunc)(PadPort*); /* 0x14 */
    int (*recvFunc)(PadPort*); /* 0x18 */
    u_char unk1C[4];
    u_char* actAlign; /* 0x20 */
    u_char cmdParam[4]; /* 0x24 */
    u_char* act; /* 0x28 */
    u_char* cmdData; /* 0x2C */
    u_char* sendBuf; /* 0x30 */
    u_char actSize; /* 0x34 */
    u_char unk35;
    u_char cmdLen; /* 0x36 */
    u_char cmd; /* 0x37 */
    u_char lastCmd; /* 0x38 */
    u_char unk39[3];
    u_char* recvBuf; /* 0x3C */
    u_char* unk40; /* 0x40 */
    u_char unk44;
    u_char sioIndex; /* 0x45 */
    u_char cmdState; /* 0x46 */
    u_char index;
    u_char remain;
    u_char loadState; /* 0x49 */
    u_char unk4A[7];
    u_char mainMode[2]; /* 0x51 */
    u_char modeChange; /* 0x53 */
    u_char unk54[3];
    u_char actEnable[6]; /* 0x57 */
    u_char actAlignBuf[6]; /* 0x5D */
    u_char unk63[0x80];
    u_char numIds; /* 0xE3 */
    u_char curMode; /* 0xE4 */
    u_char unkE5;
    u_short curExId; /* 0xE6 */
    u_char unkE8;
    u_char numActs; /* 0xE9 */
    u_char numCombs; /* 0xEA */
    u_char unkEB;
    u_short unkEC;
    u_short unkEE;
};

typedef struct {
    void* next;
    int (*func2)();
    int (*func1)();
    int unk;
} PadIntRP;

extern volatile int* D_800335FC; /* interrupt status/mask registers */
extern volatile u_short* D_80033600; /* SIO0 registers */
extern int (*D_800335C4)();
extern PadIntRP D_8003FC00;
extern int chkRC2wait(void);

extern void EnterCriticalSection(void);
extern void ExitCriticalSection(void);
extern int ChangeClearRCnt(int, int);
extern int D_80033604;
extern int SysDeqIntRP(int, PadIntRP*);
extern int D_8003FC10[2]; /* per-port vsync counters */
extern int D_800335D4;
extern int D_800335EC;
extern int D_800335F0;
extern PadPort* D_800335D0;
extern void (*D_800335A0)(PadPort*);
extern void (*D_8003359C)(int);
extern int D_800335DC; /* current port */
extern int D_800335E0; /* sequence step */
extern int D_800335E4;
int _padInitSioMode(PadPort*);
void func_8002C438(PadPort*);

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
    if (!(D_800335FC[1] & 1)) {
        return 0;
    }
    if (!(D_800335FC[0] & 1)) {
        return 0;
    }
    if (D_800335C4) {
        D_800335C4();
    }
    return 1;
}

int func_8002BE50(void)
{
    if (D_80033600[5] & 2) {
        D_80033600[5] = 0;
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
        D_80033600[7] = 0x88;
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
    SysDeqIntRP(2, &D_8003FC00);
    ExitCriticalSection();
}

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libpad/PADMAIN", _padInitSioMode);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libpad/PADMAIN", func_8002C438);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libpad/PADMAIN", _padSioRW);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libpad/PADMAIN", _padSioRW2);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libpad/PADMAIN", _padClrIntSio0);

void _padWaitRXready(void)
{
    while (!(D_80033600[2] & 2)) { }
}
