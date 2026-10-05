#include "common.h"
#include <libpad.h>

/* libpad per-port control block (same layout as PADCMD.c) */
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
    u_char unkC[4];
    PadPort* unk10; /* 0x10 */
    void (*sendFunc)(PadPort*); /* 0x14 */
    int (*recvFunc)(PadPort*); /* 0x18 */
    u_char unk1C[4];
    u_char* actAlign; /* 0x20 */
    u_char cmdParam[4]; /* 0x24 */
    int act; /* 0x28 */
    u_char* cmdData; /* 0x2C */
    u_char* sendBuf; /* 0x30 */
    u_char actSize; /* 0x34 */
    u_char sendLen; /* 0x35 */
    u_char cmdLen; /* 0x36 */
    u_char cmd; /* 0x37 */
    u_char unk38;
    u_char unk39;
    u_char unk3A[2];
    u_char* recvBuf; /* 0x3C */
    u_char unk40[4];
    u_char recvLen; /* 0x44 */
    u_char unk45;
    u_char cmdState; /* 0x46 */
    u_char index; /* 0x47 */
    u_char remain; /* 0x48 */
    u_char loadState; /* 0x49 */
    u_char retry; /* 0x4A */
    u_char unk4B;
    int vsyncCount; /* 0x4C */
    u_char unk50; /* 0x50 */
    u_char mainMode[2]; /* 0x51 */
    u_char modeChange; /* 0x53 */
    u_char unk54[9];
    u_char actAlignBuf[6]; /* 0x5D */
    u_char unk63[0x80];
    u_char numIds; /* 0xE3 */
    u_char curMode; /* 0xE4 */
    u_char unkE5;
    u_short curExId; /* 0xE6 */
    u_char curId; /* 0xE8 */
    u_char numActs; /* 0xE9 */
    u_char numCombs; /* 0xEA */
    u_char unkEB;
    u_short unkEC;
    u_short unkEE;
};

extern PadPort* (*D_800335B0)(int port);
extern int D_800335E8;
extern PadPort* D_800335D0;

int _padChkVsync(void);
void _padStartCom(void);
void _padStopCom(void);
int _padSetActAlign(PadPort* p, u_char* data);
int _padSetMainMode(PadPort* p, u_char offs, u_char lock);
void _padSetAct(PadPort* p, u_char* data, int len);

int PadChkVsync(void) { return _padChkVsync(); }

void PadStartCom(void) { _padStartCom(); }

void PadStopCom(void) { _padStopCom(); }

int PadChkMtap(int port)
{
    if (D_800335E8 != 0) {
        return D_800335D0[port >> 4].curId == 8;
    }
    return 0;
}

int PadGetState(int port)
{
    PadPort* p = D_800335B0(port);

    if (p->cmd || p->unk38 || (p != p->unk10 && p->unk39) || *p->sendBuf) {
        switch (p->loadState) {
        case 2:
            return 1;
        case 3:
            return 1;
        case 6:
            return 4;
        }
    }
    return p->loadState;
}

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libpad/PADENTRY", PadInfoMode);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libpad/PADENTRY", PadInfoAct);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libpad/PADENTRY", PadInfoComb);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libpad/PADENTRY", PadSetActAlign);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libpad/PADENTRY", PadSetMainMode);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libpad/PADENTRY", PadSetAct);
