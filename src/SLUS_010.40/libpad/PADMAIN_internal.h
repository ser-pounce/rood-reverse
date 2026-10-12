#pragma once
#include "common.h"

/* libpad per-port control block (layout from field accesses in
 * PADCMD/PADMAIN/PADPORTD)
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

typedef struct {
    int stat; /* I_STAT */
    int mask; /* I_MASK */
} PadIntrRegs;

extern volatile PadIntrRegs* D_800335FC; /* interrupt status/mask registers */
extern volatile u_short* D_80033600; /* SIO0 registers */

#define SIO_DATA (*(volatile u_char *)D_80033600)
#define SIO_SET_BAUD(x)                                                        \
  do {                                                                         \
    D_80033600[7] = (x);                                                       \
  } while (0)

#define RCNT2_COUNT (*(volatile u_short *)0x1F801120)
#define RCNT2_MODE (*(volatile u_short *)0x1F801124)
#define RCNT2_TARGET (*(volatile u_short *)0x1F801128)

extern u_int D_8003FEA0; /* counter value at setRC2wait */
extern u_int D_8003FEA4; /* wait length */
extern void setRC2wait(u_int wait);
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
