#include "common.h"

/* libpad per-port control block (layout from field accesses in PADCMD/PADMAIN) */
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
    u_char unkC[8];
    void (*sendFunc)(PadPort*); /* 0x14 */
    int (*recvFunc)(PadPort*); /* 0x18 */
    u_char unk1C[4];
    u_char* actAlign; /* 0x20 */
    u_char cmdParam[4]; /* 0x24 */
    int act; /* 0x28 */
    u_char* cmdData; /* 0x2C */
    u_char unk30[4];
    u_char actSize; /* 0x34 */
    u_char unk35;
    u_char cmdLen; /* 0x36 */
    u_char cmd; /* 0x37 */
    u_char unk38[4];
    u_char* recvBuf; /* 0x3C */
    u_char unk40[6];
    u_char cmdState; /* 0x46 */
    u_char index;
    u_char remain;
    u_char loadState;
    u_char unk4A[7];
    u_char mainMode[2]; /* 0x51 */
    u_char modeChange; /* 0x53 */
    u_char unk54[9];
    u_char actAlignBuf[6]; /* 0x5D */
    u_char unk63[0x80];
    u_char numIds;
    u_char curMode; /* 0xE4 */
    u_char unkE5[4];
    u_char numActs;
    u_char numCombs;
    u_char unkEB;
    u_short unkEC;
    u_short unkEE;
};

extern void (*D_800335A0)(PadPort*);
extern int (*D_800335B8)(PadPort*);

void func_8002CEB0(PadPort* p);
int func_8002CF58(PadPort* p);
void func_8002D3B8(PadPort* p);
int func_8002D3D4(PadPort* p);
void func_8002D534(PadPort* p);
int func_8002D588(PadPort* p);
void func_8002D608(PadPort* p);
void func_8002D61C(PadPort* p, int param);
void func_8002D63C(PadPort* p, int param);
void func_8002D65C(PadPort* p, int param);
void func_8002D67C(PadPort* p);

void _padSetAct(PadPort* p, int act, int size)
{
    p->act = act;
    p->actSize = size;
}

void _padSetCmd(PadPort* p, int cmd, u_char* data, int len)
{
    p->cmd = cmd;
    p->cmdData = data;
    p->cmdLen = len;
}

void _padSendAtLoadInfo(PadPort* p)
{
    switch (p->cmdState) {
    case 2:
        func_8002D608(p);
        break;
    case 3:
        func_8002D61C(p, p->curMode);
        break;
    case 4:
        func_8002D65C(p, p->index);
        break;
    }
}

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libpad/PADCMD", _padRecvAtLoadInfo);

int _padGetActSize(PadPort* p)
{
    int funcSize = ((p->numIds + 1) >> 1) << 2;
    int subSize = (((p->numActs * 5 + 3) >> 2) << 2) + 4;

    return funcSize + subSize + p->unkEC;
}

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libpad/PADCMD", _padLoadActInfo);

void func_8002CEB0(PadPort* p)
{
    switch (p->cmdState) {
    case 2:
        func_8002D61C(p, p->index);
        break;
    case 3:
        func_8002D63C(p, p->index);
        break;
    case 4:
        if (p->remain == 0) {
            func_8002D65C(p, p->index);
        } else {
            func_8002D67C(p);
        }
        break;
    }
}

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libpad/PADCMD", func_8002CF58);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libpad/PADCMD", _padSetActAlign);

void func_8002D3B8(PadPort* p)
{
    p->cmd = 0x4D;
    p->cmdData = p->actAlign;
    p->cmdLen = 6;
}

int func_8002D3D4(PadPort* p)
{
    int act;
    int i;
    int count;
    int max;
    u_char* align;

    act = 0;
    if (p->numActs != 0) {
        do {
            align = p->actAlign;
            count = 0;
            for (i = 0; i < 6; i++) {
                if (*align++ == act) {
                    count++;
                }
            }
            max = p->actInfo[act * 5 + 2];
            align = p->actAlign;
            if (max == 0) {
                max = 1;
            }
            for (i = 0; i < 6; i++) {
                if (*align++ == act) {
                    if (count < max) {
                        p->actAlignBuf[i] = 0xFF;
                        count--;
                    } else {
                        p->actAlignBuf[i] = act;
                    }
                }
            }
            act++;
        } while (act < p->numActs);
    }
    p->cmdState = 0xFE;
    return 0;
}

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libpad/PADCMD", _padSetMainMode);

void func_8002D534(PadPort* p)
{
    int state = p->cmdState;

    switch (state) {
    case 2:
        p->cmd = 0x44;
        p->cmdData = p->mainMode;
        p->cmdLen = state;
        break;
    case 3:
        p->cmd = 0x4D;
        p->cmdData = p->actAlignBuf;
        p->cmdLen = 6;
        break;
    }
}

int func_8002D588(PadPort* p)
{
    if (p->modeChange) {
        if (p->cmdState == 2) {
            return 1;
        }
        p->cmdState = 0xFE;
    } else {
        D_800335A0(p);
    }
    return 0;
}

void _padCmdParaMode(PadPort* p, int param)
{
    p->cmd = 0x43;
    p->cmdData = p->cmdParam;
    p->cmdParam[0] = param;
    p->cmdLen = 1;
}

void func_8002D608(PadPort* p)
{
    p->cmd = 0x45;
    p->cmdData = NULL;
    p->cmdLen = 0;
}

void func_8002D61C(PadPort* p, int param)
{
    p->cmd = 0x4C;
    p->cmdData = p->cmdParam;
    p->cmdParam[0] = param;
    p->cmdLen = 1;
}

void func_8002D63C(PadPort* p, int param)
{
    p->cmd = 0x46;
    p->cmdData = p->cmdParam;
    p->cmdParam[0] = param;
    p->cmdLen = 1;
}

void func_8002D65C(PadPort* p, int param)
{
    p->cmd = 0x47;
    p->cmdData = p->cmdParam;
    p->cmdParam[0] = param;
    p->cmdLen = 1;
}

void func_8002D67C(PadPort* p)
{
    p->cmd = 0x4B;
    p->cmdData = NULL;
    p->cmdLen = 0;
}
