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

extern PadPort D_8003FCC0[2];

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libpad/PADPORTD", PadInitDirect);

void func_8002DE24(PadPort* p)
{
    int i;
    u_char* align;

    if (p->loadState != 0) {
        p->loadState = 0;
        p->cmdState = 0;
        p->curExId = 0;
        p->sendFunc = NULL;
        p->recvFunc = NULL;
        p->numIds = 0;
        p->curMode = 0;
        p->curExId = 0;
        p->numActs = 0;
        p->numCombs = 0;
        p->idTable = NULL;
        p->actInfo = NULL;
        p->comb = NULL;
        for (align = p->actAlignBuf, i = 0; i < 6; i++) {
            *align++ = 0xFF;
        }
    }
}

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libpad/PADPORTD", func_8002DE8C);

void func_8002DF80(PadPort* p)
{
    p->lastCmd = p->cmd;
    p->cmd = 0;
}

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libpad/PADPORTD", func_8002DF90);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libpad/PADPORTD", func_8002E04C);

int func_8002E2C8(PadPort* p)
{
    int i;

    for (i = 0; i < 2; i++) {
        if (p == &D_8003FCC0[i]) {
            return (i + 1) << 4;
        }
    }
    return 0xFF;
}

PadPort* func_8002E300(int port)
{
    PadPort* p = D_8003FCC0;

    if (port & 0xF0) {
        p++;
    }
    return p;
}
