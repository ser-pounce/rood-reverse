#include "common.h"
#include "168.h"
#include "../../BATTLE/BATTLE.PRG/5BF94.h"

extern void* _sydData;
extern int _sydLbas[];
extern int _sydSizes[];
extern vs_main_CdQueueSlot* _sydCdQueueSlot;
extern char _sydFileLoading;

INCLUDE_ASM("build/src/MENU/MENUC.PRG/nonmatchings/168", func_80102968);

INCLUDE_ASM("build/src/MENU/MENUC.PRG/nonmatchings/168", func_801029D0);

INCLUDE_ASM("build/src/MENU/MENUC.PRG/nonmatchings/168", func_80102A34);

INCLUDE_ASM("build/src/MENU/MENUC.PRG/nonmatchings/168", func_80102AB8);

INCLUDE_ASM("build/src/MENU/MENUC.PRG/nonmatchings/168", func_80102B50);

INCLUDE_ASM("build/src/MENU/MENUC.PRG/nonmatchings/168", func_80102C0C);

INCLUDE_ASM("build/src/MENU/MENUC.PRG/nonmatchings/168", func_80102C58);

INCLUDE_ASM("build/src/MENU/MENUC.PRG/nonmatchings/168", func_80102E40);

INCLUDE_ASM("build/src/MENU/MENUC.PRG/nonmatchings/168", func_8010306C);

INCLUDE_ASM("build/src/MENU/MENUC.PRG/nonmatchings/168", func_80103188);

INCLUDE_ASM("build/src/MENU/MENUC.PRG/nonmatchings/168", func_801032CC);

INCLUDE_ASM("build/src/MENU/MENUC.PRG/nonmatchings/168", func_8010333C);

INCLUDE_ASM("build/src/MENU/MENUC.PRG/nonmatchings/168", func_80103380);

INCLUDE_ASM("build/src/MENU/MENUC.PRG/nonmatchings/168", func_801033FC);

INCLUDE_ASM("build/src/MENU/MENUC.PRG/nonmatchings/168", func_801035E0);

INCLUDE_ASM("build/src/MENU/MENUC.PRG/nonmatchings/168", func_80103608);

INCLUDE_ASM("build/src/MENU/MENUC.PRG/nonmatchings/168", func_80103C20);

INCLUDE_ASM("build/src/MENU/MENUC.PRG/nonmatchings/168", func_80103CEC);

INCLUDE_ASM("build/src/MENU/MENUC.PRG/nonmatchings/168", func_80103D8C);

INCLUDE_ASM("build/src/MENU/MENUC.PRG/nonmatchings/168", func_80103DC4);

INCLUDE_ASM("build/src/MENU/MENUC.PRG/nonmatchings/168", func_8010418C);

INCLUDE_ASM("build/src/MENU/MENUC.PRG/nonmatchings/168", func_80104534);

INCLUDE_ASM("build/src/MENU/MENUC.PRG/nonmatchings/168", func_80104868);

INCLUDE_ASM("build/src/MENU/MENUC.PRG/nonmatchings/168", func_80104898);

INCLUDE_ASM("build/src/MENU/MENUC.PRG/nonmatchings/168", func_80105618);

INCLUDE_ASM("build/src/MENU/MENUC.PRG/nonmatchings/168", func_80105674);

INCLUDE_ASM("build/src/MENU/MENUC.PRG/nonmatchings/168", func_801057BC);

INCLUDE_ASM("build/src/MENU/MENUC.PRG/nonmatchings/168", func_801063E4);

INCLUDE_ASM("build/src/MENU/MENUC.PRG/nonmatchings/168", func_80106610);

INCLUDE_ASM("build/src/MENU/MENUC.PRG/nonmatchings/168", func_80106C64);

INCLUDE_ASM("build/src/MENU/MENUC.PRG/nonmatchings/168", func_80106ECC);

INCLUDE_ASM("build/src/MENU/MENUC.PRG/nonmatchings/168", func_801072FC);

int vs_menuC_loadSyd(int id)
{
    vs_main_CdFile cdFile;

    if (id != 0) {
        --id;
        _sydData = vs_main_allocHeapR(_sydSizes[id]);
        cdFile.lba = _sydLbas[id];
        cdFile.size = _sydSizes[id];
        _sydCdQueueSlot = vs_main_allocateCdQueueSlot(&cdFile);
        vs_main_cdEnqueue(_sydCdQueueSlot, _sydData);
        _sydFileLoading = 1;
        return 0;
    }
    if (_sydFileLoading == 0) {
        return 1;
    }

    if (_sydCdQueueSlot->state == 4) {
        vs_main_freeCdQueueSlot(_sydCdQueueSlot);
        _sydFileLoading = 0;
        return 1;
    }
    return 0;
}

INCLUDE_ASM("build/src/MENU/MENUC.PRG/nonmatchings/168", func_801077DC);

INCLUDE_ASM("build/src/MENU/MENUC.PRG/nonmatchings/168", func_8010785C);

INCLUDE_ASM("build/src/MENU/MENUC.PRG/nonmatchings/168", func_80107894);

INCLUDE_ASM("build/src/MENU/MENUC.PRG/nonmatchings/168", func_80107AD4);

INCLUDE_ASM("build/src/MENU/MENUC.PRG/nonmatchings/168", func_80107EBC);

INCLUDE_ASM("build/src/MENU/MENUC.PRG/nonmatchings/168", func_80107F14);

INCLUDE_ASM("build/src/MENU/MENUC.PRG/nonmatchings/168", func_801087E4);

INCLUDE_ASM("build/src/MENU/MENUC.PRG/nonmatchings/168", func_80108908);

INCLUDE_ASM("build/src/MENU/MENUC.PRG/nonmatchings/168", func_80108A9C);

INCLUDE_ASM("build/src/MENU/MENUC.PRG/nonmatchings/168", func_80108AD4);

void func_80108E9C(char* arg0, char* arg1)
{
    arg0[9] = 0xF;
    arg0[12] = arg1[40];
    arg0[13] = arg1[1] != 0;
}

INCLUDE_ASM("build/src/MENU/MENUC.PRG/nonmatchings/168", func_80108EC4);

INCLUDE_ASM("build/src/MENU/MENUC.PRG/nonmatchings/168", func_80109790);

INCLUDE_ASM("build/src/MENU/MENUC.PRG/nonmatchings/168", func_801099FC);

INCLUDE_ASM("build/src/MENU/MENUC.PRG/nonmatchings/168", func_80109DBC);

INCLUDE_ASM("build/src/MENU/MENUC.PRG/nonmatchings/168", func_80109DEC);

INCLUDE_ASM("build/src/MENU/MENUC.PRG/nonmatchings/168", func_8010A63C);

INCLUDE_ASM("build/src/MENU/MENUC.PRG/nonmatchings/168", func_8010A6BC);

INCLUDE_ASM("build/src/MENU/MENUC.PRG/nonmatchings/168", func_8010A978);

INCLUDE_ASM("build/src/MENU/MENUC.PRG/nonmatchings/168", func_8010AE38);

INCLUDE_ASM("build/src/MENU/MENUC.PRG/nonmatchings/168", func_8010B150);

INCLUDE_ASM("build/src/MENU/MENUC.PRG/nonmatchings/168", func_8010B2B4);

INCLUDE_ASM("build/src/MENU/MENUC.PRG/nonmatchings/168", func_8010B598);

INCLUDE_ASM("build/src/MENU/MENUC.PRG/nonmatchings/168", func_8010B80C);

INCLUDE_ASM("build/src/MENU/MENUC.PRG/nonmatchings/168", func_8010BA58);
