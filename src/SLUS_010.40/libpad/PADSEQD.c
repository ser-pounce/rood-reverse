#include "common.h"

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

extern void (*D_800335A0)(PadPort*);
extern int (*D_800335B4)(PadPort*);
extern int (*D_800335B8)(PadPort*);
extern void (*D_800335BC)(PadPort*);

void _padSendAtLoadInfo(PadPort* p);
int _padRecvAtLoadInfo(PadPort* p);
void _padCmdParaMode(PadPort* p, int param);
int func_8002E368(PadPort* p);
void func_8002E478(PadPort* p);
void func_8002E6DC(PadPort* p);
int func_8002E7BC(PadPort* p);

void _padInitDirSeq(void)
{
    D_800335B4 = func_8002E368;
    D_800335B8 = func_8002E7BC;
    D_800335BC = func_8002E478;
}

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libpad/PADSEQD", func_8002E368);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libpad/PADSEQD", func_8002E478);

void func_8002E6DC(PadPort* p)
{
    p->vsyncCount++;
    if (p->cmdState != 0) {
        if (p->cmdState == 1) {
            if (p->retry < 11) {
                p->retry++;
                return;
            }
            p->loadState = 2;
            p->cmdState = 0xFF;
            return;
        }
        if (p->retry < 11) {
            p->retry++;
            return;
        }
        if (p->loadState != 0) {
            D_800335A0(p);
        }
    }
    if (p->recvBuf[0] != 0xF3) {
        p->sendBuf[0] = 0xFF;
        p->sendBuf[1] = 0;
        p->curId = 0;
        p->sendLen = 0;
    }
}

int func_8002E7BC(PadPort* p)
{
    if (p->curExId == 0 || p->cmdState != 0xFF) {
        return 1;
    }
    return 0;
}
