#include "common.h"
#include <libds.h>

typedef struct {
    int id;
    u_char com;
    u_char param[4];
    u_char* pparam;
    int x10;
    int x14;
} DS_CQ;

typedef struct {
    DS_CQ q[DslMaxCOMMANDS]; /* 80039CF0 */
    int head; /* 80039DB0 */
    int tail; /* 80039DB4 */
    int len; /* 80039DB8 */
} DS_CQS;

extern DS_CQS D_80039CF0;
extern int D_80039DB4;
extern int D_80039DB0;
extern int DS_system_status(int);
extern int DS_cw(u_char, u_char*);
extern void (*D_80039E68)(u_char);
extern void func_8002480C(void);
extern int DS_lastcom(void);
extern int DS_status(void);
extern int DS_shell_open(void);
extern void DS_stop(void);
extern int DsQueueLen(void);
extern void DS_restart(void);
extern int _DsPacket2(u_char, DslLOC*, u_char, DslCB, int, int);

extern int D_80039DB8;

typedef struct {
    int id;
    u_char intr;
    u_char result[8];
} DS_RES;

typedef struct {
    DS_RES ent[8]; /* 80039DC0 */
    int idx; /* 80039E40 */
} DS_RESQ;

extern DS_RESQ D_80039DC0;

typedef struct {
    int flag;
    u_char intr;
    u_char result[8];
} DS_RDY;

extern DS_RDY D_80039CD0; /* DslDataReady / DslDiskError */
extern DS_RDY D_80039CE0; /* DslDataEnd */
extern DslCB D_80039E64;
extern void func_800233B4(u_char, u_char*);
extern void rescpy(u_char*, u_char*);

void func_800231E4(DS_CQ* p)
{
    int i;
    p->id = 0;
    p->com = 0;
    for (i = 0; i < 4; i++) {
        p->param[i] = 0;
    }
    p->pparam = 0;
    p->x10 = 0;
    p->x14 = 0;
}

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSSYS_2", func_80023214);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSSYS_2", DS_CQ_flush);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSSYS_2", func_80023360);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSSYS_2", func_800233B4);

int func_800235A4(void)
{
    DS_CQ* e;
    if (DS_system_status(0) != 1) {
        return 0;
    }
    e = &D_80039CF0.q[D_80039CF0.tail];
    if (e->id != 0) {
        return DS_cw(e->com, e->pparam) != 0;
    }
    return 0;
}

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSSYS_2", func_80023614);

void func_80023838(int id, u_char intr, u_char* result)
{
    D_80039DC0.ent[D_80039DC0.idx].id = id;
    D_80039DC0.ent[D_80039DC0.idx].intr = intr;
    rescpy(D_80039DC0.ent[D_80039DC0.idx].result, result);
    if (++D_80039DC0.idx >= 8) {
        D_80039DC0.idx = 0;
    }
}

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSSYS_2", DsInit);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSSYS_2", DsReset);

void DsClose(void) { func_8002480C(); }

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSSYS_2", DsCommand);

int DsPacket(u_char mode, DslLOC* pos, u_char com, DslCB func, int count)
{
    return _DsPacket2(mode, pos, com, func, count, 1);
}

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSSYS_2", _DsPacket2);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSSYS_2", DsSync);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSSYS_2", DsReady);

void DsFlush(void)
{
    int i, j;
    DS_stop();
    D_80039DB8 = 0;
    D_80039DB4 = 0;
    D_80039DB0 = 0;
    for (i = 0; i < DslMaxCOMMANDS; i++) {
        DS_CQ* e = &D_80039CF0.q[i];
        e->id = 0;
        e->com = 0;
        for (j = 0; j < 4; j++) {
            e->param[j] = 0;
        }
        e->pparam = 0;
        e->x10 = 0;
        e->x14 = 0;
    }
    DsEndReadySystem();
    DS_restart();
}

int DsSystemStatus(void)
{
    int status = DS_system_status(0);

    if (status == 1 && DsQueueLen() > 0) {
        status = 2;
    }
    return status;
}

int DsQueueLen(void) { return D_80039DB8; }

u_char DsStatus(void) { return DS_status(); }

int DsShellOpen(void) { return DS_shell_open(); }

u_char DsLastCom(void) { return DS_lastcom(); }

void func_800244EC(void)
{
    DS_CQ* e;
    int status = DS_system_status(0);

    if (status == 1 && D_80039CF0.len > 0 && DS_system_status(0) == status) {
        e = &D_80039CF0.q[D_80039CF0.tail];
        if (e->id != 0) {
            DS_cw(e->com, e->pparam);
        }
    }
}

void func_80024590(u_char intr, u_char* result)
{
    DS_RDY* p;
    if (intr == DslDiskError && (result[0] & DslStatShellOpen)) {
        func_800233B4(DslDiskError, result);
    }
    switch (intr) {
    case DslDataReady:
    case DslDiskError:
        p = &D_80039CD0;
        break;
    case DslDataEnd:
        p = &D_80039CE0;
        break;
    default:
        goto end;
    }
    p->flag = 1;
    p->intr = intr;
    rescpy(p->result, result);
end:
    if (D_80039E64) {
        D_80039E64(intr, result);
    }
}

void func_80024664(u_char a)
{
    if (D_80039E68) {
        D_80039E68(a);
    }
}
