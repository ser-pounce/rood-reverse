#include "common.h"
#include "168.h"
#include "../MAINMENU.PRG/C48.h"
#include "../MAINMENU.PRG/413C.h"
#include "../../BATTLE/BATTLE.PRG/5BF94.h"

void func_8010306C(int);
void func_80103380(int);
void* func_801077DC(void);

extern void* _sydData;
extern int _sydLbas[];
extern int _sydSizes[];
extern vs_main_CdQueueSlot* _sydCdQueueSlot;
extern char _sydFileLoading;

extern u_short D_8010BB24[];
extern char D_8010BC81;
extern int D_8010BC98;
extern int D_8010BC9C;

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

int func_8010333C(char* arg0, char* arg1)
{
    if ((arg0 == NULL) || (arg1 == NULL)) {
        return 1;
    }
    return (1 << arg0[3]) & D_8010BB24[arg1[3]];
}

INCLUDE_ASM("build/src/MENU/MENUC.PRG/nonmatchings/168", func_80103380);

INCLUDE_ASM("build/src/MENU/MENUC.PRG/nonmatchings/168", func_801033FC);

int func_801035E0(void) { return D_8010BC98 == 0 ? D_8010BC9C : -1; }

INCLUDE_ASM("build/src/MENU/MENUC.PRG/nonmatchings/168", func_80103608);

INCLUDE_ASM("build/src/MENU/MENUC.PRG/nonmatchings/168", func_80103C20);

INCLUDE_ASM("build/src/MENU/MENUC.PRG/nonmatchings/168", func_80103CEC);

void func_80103D8C(int arg0)
{
    vs_battle_menuItem_t* temp_v0;

    temp_v0 = vs_battle_getMenuItem(arg0);
    temp_v0->state = 4;
    temp_v0->x = 0x9B;
    temp_v0->unk1A = 0x12;
}

INCLUDE_ASM("build/src/MENU/MENUC.PRG/nonmatchings/168", func_80103DC4);

INCLUDE_ASM("build/src/MENU/MENUC.PRG/nonmatchings/168", func_8010418C);

INCLUDE_ASM("build/src/MENU/MENUC.PRG/nonmatchings/168", func_80104534);

void func_80104868(void)
{
    func_8010306C(D_8010BC81);
    func_80103380(1);
}

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

void func_8010785C(void)
{
    vs_battle_menuItem_t* temp_v0;

    temp_v0 = func_801077DC();
    temp_v0->state = 2;
    temp_v0->x = 0x9B;
    temp_v0->animSpeed = 0x140;
}

INCLUDE_ASM("build/src/MENU/MENUC.PRG/nonmatchings/168", func_80107894);

INCLUDE_ASM("build/src/MENU/MENUC.PRG/nonmatchings/168", func_80107AD4);

INCLUDE_ASM("build/src/MENU/MENUC.PRG/nonmatchings/168", func_80107EBC);

INCLUDE_ASM("build/src/MENU/MENUC.PRG/nonmatchings/168", func_80107F14);

INCLUDE_ASM("build/src/MENU/MENUC.PRG/nonmatchings/168", func_801087E4);

INCLUDE_ASM("build/src/MENU/MENUC.PRG/nonmatchings/168", func_80108908);

void func_80108A9C(vs_battle_inventoryShield* arg0, char** arg1, int* arg2, char* arg3)
{
    int temp_s1;

    temp_s1 = *(int*)arg0->gems;
    *(int*)arg0->gems = 0;
    func_800FCE40(arg0, arg1, arg2, arg3);
    *(int*)arg0->gems = temp_s1;
}

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
