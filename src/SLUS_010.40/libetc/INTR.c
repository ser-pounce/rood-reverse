#include "common.h"

typedef struct {
    int unk0;
    int unk4;
    int unk8;
    void (*unkC)();
} D_800320D4_t;

extern D_800320D4_t* D_800320D4;

void ResetCallback(void) { D_800320D4->unkC(); }

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libetc/INTR", InterruptCallback);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libetc/INTR", DMACallback);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libetc/INTR", VSyncCallback);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libetc/INTR", VSyncCallbacks);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libetc/INTR", StopCallback);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libetc/INTR", RestartCallback);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libetc/INTR", CheckCallback);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libetc/INTR", GetIntrMask);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libetc/INTR", SetIntrMask);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libetc/INTR", func_8001FA68);

INCLUDE_RODATA("build/src/SLUS_010.40/nonmatchings/libetc/INTR", D_800101E4);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libetc/INTR", func_8001FB40);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libetc/INTR", func_8001FD10);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libetc/INTR", func_8001FE58);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libetc/INTR", func_8001FEF8);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libetc/INTR", memzero);
