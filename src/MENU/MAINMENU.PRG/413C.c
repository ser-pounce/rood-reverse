#include "common.h"
#include "413C.h"
#include "../../BATTLE/BATTLE.PRG/573B8.h"
#include "../../BATTLE/BATTLE.PRG/5BF94.h"

extern char D_8010231A[];
extern int D_801023D4;
extern int D_801023D8;

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_800FD93C);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_800FDB04);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_800FDB60);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_800FDBAC);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_800FDCD0);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_800FDD24);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_800FDD78);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_800FDD88);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_800FDEBC);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_800FE360);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_800FE3A0);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_800FE3E0);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_800FE5CC);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_800FE694);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_800FE6EC);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_800FE7E0);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_800FE848);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_800FE8B0);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_800FEA6C);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_800FEB08);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_800FEB94);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_800FF0EC);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_800FF348);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_800FF360);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_800FF388);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_800FF43C);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_800FF9E4);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_800FFA88);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_800FFA94);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_800FFB68);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_800FFB90);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_800FFBA8);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_800FFBC8);

void vs_mainmenu_setMessage(char* arg0)
{
    vs_battle_memcpy(&D_8010231A, arg0, 0x60);
    D_800F4FE0[7].unk0 = ((D_800F4FE0[7].unk0 & 0xC0FFFFFF) | 0x20000000);
    func_800C6BF0(7, D_8010231A - 2, D_800F4FE0);
}

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_800FFC68);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_800FFCDC);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_800FFD64);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_800FFE20);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_800FFE70);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_800FFE98);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_800FFF38);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_800FFFBC);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_80100004);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_80100100);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_80100164);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_80100344);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_80100414);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_8010044C);

// https://decomp.me/scratch/Oo0p8
INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_801005E0);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_80100814);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_801008B0);

int func_801008C8() {
    return D_801023D4 != 0 ? -1 : D_801023D8;
}

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_801008F0);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_80100A5C);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_80101118);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_80101268);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_801013F8);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_8010154C);

INCLUDE_RODATA("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", D_800F99F8);

INCLUDE_RODATA("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", D_800F9A04);

INCLUDE_RODATA("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", D_800F9A08);
