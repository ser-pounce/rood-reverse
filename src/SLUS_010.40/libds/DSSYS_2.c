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

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSSYS_2", DsInit);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSSYS_2", DsReset);

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
