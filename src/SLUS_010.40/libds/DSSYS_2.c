#include "DSSYS_2_internal.h"

DS_CQ* func_80023360(void)
{
    int len = D_80039CF0.len;
    int index;
    if (len >= DslMaxCOMMANDS) {
        return NULL;
    }
    index = D_80039CF0.head + len;
    if (index >= DslMaxCOMMANDS) {
        index -= DslMaxCOMMANDS;
    }
    return &D_80039CF0.q[index];
}

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSSYS_2", func_800233B4);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSSYS_2", func_800235A4);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSSYS_2", func_80023614);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSSYS_2", func_80023838);

typedef struct {
    DslCB sync;
    DslCB ready;
    DslCB start;
} DS_CBS;

extern DS_CBS D_80039E60;
extern DS_RDY D_80039CC0[3];
extern int DS_system_active(void);
extern void func_800231E4(DS_CQ*);
extern void DS_init(void);
extern void DS_sync_callback(DslCB);
extern void DS_ready_callback(DslCB);
extern void DS_start_callback(DslCB);
extern void DS_vsync_callback(DslCB);
extern void ER_clear(void);
extern void func_80023614(u_char, u_char*);
extern void func_80024590(u_char, u_char*);
extern void func_80024664(u_char, u_char*);
extern void func_800244EC(void);

int DsInit(void)
{
    DS_CBS* cbs;
    DS_RDY* rdy;
    int i;
    int j;
    int k;

    if (DS_system_active()) {
        return 0;
    }
    cbs = &D_80039E60;
    cbs->sync = NULL;
    cbs->ready = NULL;
    cbs->start = NULL;
    rdy = D_80039CC0;
    rdy[2].flag = 0;
    rdy[1].flag = 0;
    rdy[0].flag = 0;
    rdy[2].intr = 0;
    rdy[1].intr = 0;
    rdy[0].intr = 0;
    for (i = 0; i < 8; i++) {
        D_80039CC0[0].result[i] = 0;
        D_80039CC0[1].result[i] = 0;
        D_80039CC0[2].result[i] = 0;
    }
    for (j = 0; j < DslMaxCOMMANDS; j++) {
        func_800231E4(&D_80039CF0.q[j]);
    }
    D_80039DB4 = 0;
    D_80039DB0 = 0;
    D_80039DB8 = 0;
    for (k = 0; k < 8; k++) {
        D_80039DC0.ent[k].id = 0;
    }
    D_80039DC0.idx = 0;
    DS_init();
    DS_sync_callback((DslCB)func_80023614);
    DS_ready_callback((DslCB)func_80024590);
    DS_start_callback((DslCB)func_80024664);
    DS_vsync_callback((DslCB)func_800244EC);
    ER_clear();
    DsReadySystemMode(0);
    return 1;
}

int DsReset(void)
{
    DS_CBS* cbs;
    DS_RDY* rdy;
    int i;
    int j;
    int k;

    DS_stop();
    cbs = &D_80039E60;
    cbs->sync = NULL;
    cbs->ready = NULL;
    cbs->start = NULL;
    rdy = D_80039CC0;
    rdy[2].flag = 0;
    rdy[1].flag = 0;
    rdy[0].flag = 0;
    rdy[2].intr = 0;
    rdy[1].intr = 0;
    rdy[0].intr = 0;
    for (i = 0; i < 8; i++) {
        D_80039CC0[0].result[i] = 0;
        D_80039CC0[1].result[i] = 0;
        D_80039CC0[2].result[i] = 0;
    }
    for (j = 0; j < DslMaxCOMMANDS; j++) {
        func_800231E4(&D_80039CF0.q[j]);
    }
    D_80039DB4 = 0;
    D_80039DB0 = 0;
    D_80039DB8 = 0;
    for (k = 0; k < 8; k++) {
        D_80039DC0.ent[k].id = 0;
    }
    D_80039DC0.idx = 0;
    ER_clear();
    DsReadySystemMode(0);
    DS_restart();
    return 1;
}

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSSYS_2", DsClose);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSSYS_2", DsCommand);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSSYS_2", DsPacket);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSSYS_2", _DsPacket2);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSSYS_2", DsSync);

int DsReady(u_char* result)
{
    int intr;
    DS_ready(NULL);
    intr = D_80039CE0.flag == 1 ? 4 : D_80039CD0.flag == 1;
    if (intr == 4) {
        D_80039CE0.flag = 0;
        rescpy(result, D_80039CE0.result);
        return D_80039CE0.intr;
    }
    if (intr == 1) {
        D_80039CD0.flag = 0;
        rescpy(result, D_80039CD0.result);
        return D_80039CD0.intr;
    }
    return 0;
}

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSSYS_2", DsFlush);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSSYS_2", DsSystemStatus);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSSYS_2", DsQueueLen);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSSYS_2", DsStatus);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSSYS_2", DsShellOpen);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSSYS_2", DsLastCom);
