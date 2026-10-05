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

extern int (*D_800335B4)(PadPort*);
extern void (*D_800335A8)(PadPort*);
extern int (*D_800335A4)(PadPort*, int);
extern void (*D_800335C8)(void);
extern void (*D_800335CC)(void);
extern int D_800335D8;
extern int D_800335DC;
extern int D_800335E8;
extern int D_800335EC;
extern int D_80033614;
extern int D_8003361C;
extern int D_80033620;

int _padSioRW(PadPort*, int);
int _padSioRW2(PadPort*, int);

void func_8002D694(PadPort* p)
{
    D_8003361C = D_800335B4(p);
    p->recvBuf[0] = 0;
    _padSioRW(p, -2);
}

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libpad/PADIF", func_8002D6DC);

int func_8002D7B4(PadPort* p)
{
    int ret;

    if (D_8003361C != 0) {
        D_800335B4(p->unkC + 2);
        D_800335B4(p->unkC + 3);
    }
    ret = _padSioRW2(p, p->cmd != 0 ? 0 : D_800335E8);
    if (ret >= 0) {
        D_80033614 = (ret & 0xF) * 2;
        if (D_80033614 == 0) {
            D_80033614 = 0x20;
        }
        ret = 0;
    }
    return ret;
}

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libpad/PADIF", func_8002D860);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libpad/PADIF", func_8002D924);
