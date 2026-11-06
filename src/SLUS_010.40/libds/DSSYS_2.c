#include "common.h"

typedef struct {
    int unk0;
    u_char unk4;
    u_char unk5[4];
    int unkC;
    int unk10;
    int unk14;
} func_80023360_t;

typedef struct {
    func_80023360_t unk0[8];
    int unkC0;
    int unkC4;
    int unkC8;
} D_80039CF0_t;

extern D_80039CF0_t D_80039CF0;

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSSYS_2", func_800231E4);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSSYS_2", func_80023214);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSSYS_2", DS_CQ_flush);

func_80023360_t* func_80023360(void)
{
    int i;

    if (D_80039CF0.unkC8 >= 8) {
        return NULL;
    }

    do {
    } while (0);

    i = D_80039CF0.unkC0 + D_80039CF0.unkC8;

    if (i >= 8) {
        i -= 8;
    }

    return &D_80039CF0.unk0[i];
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

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSSYS_2", DsReady);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSSYS_2", DsFlush);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSSYS_2", DsSystemStatus);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSSYS_2", DsQueueLen);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSSYS_2", DsStatus);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSSYS_2", DsShellOpen);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSSYS_2", DsLastCom);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSSYS_2", func_800244EC);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSSYS_2", func_80024590);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libds/DSSYS_2", func_80024664);
