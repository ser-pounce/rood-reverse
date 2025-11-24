#include "common.h"

typedef struct {
    u_short unk0;
    char unk2;
} func_8010406C_t;

extern char D_80109711;
extern char D_80109712;
extern char D_80109713;
extern int D_8010975C;
extern int D_80109760;

void func_8010296C(char arg0)
{
    D_80109711 = arg0;
    D_80109712 = arg0;
    D_80109713 = arg0;
}

INCLUDE_ASM("build/src/MENU/MENU3.PRG/nonmatchings/16C", func_80102988);

INCLUDE_ASM("build/src/MENU/MENU3.PRG/nonmatchings/16C", func_80102A3C);

INCLUDE_ASM("build/src/MENU/MENU3.PRG/nonmatchings/16C", func_80102B78);

INCLUDE_ASM("build/src/MENU/MENU3.PRG/nonmatchings/16C", func_80102BE4);

INCLUDE_ASM("build/src/MENU/MENU3.PRG/nonmatchings/16C", func_80102C44);

INCLUDE_ASM("build/src/MENU/MENU3.PRG/nonmatchings/16C", func_80102C94);

INCLUDE_ASM("build/src/MENU/MENU3.PRG/nonmatchings/16C", func_80102D30);

INCLUDE_ASM("build/src/MENU/MENU3.PRG/nonmatchings/16C", func_80102D7C);

INCLUDE_ASM("build/src/MENU/MENU3.PRG/nonmatchings/16C", func_80102DEC);

INCLUDE_ASM("build/src/MENU/MENU3.PRG/nonmatchings/16C", func_80103034);

INCLUDE_ASM("build/src/MENU/MENU3.PRG/nonmatchings/16C", func_80103220);

INCLUDE_ASM("build/src/MENU/MENU3.PRG/nonmatchings/16C", func_80103460);

INCLUDE_ASM("build/src/MENU/MENU3.PRG/nonmatchings/16C", func_801036BC);

INCLUDE_ASM("build/src/MENU/MENU3.PRG/nonmatchings/16C", func_801038E4);

INCLUDE_ASM("build/src/MENU/MENU3.PRG/nonmatchings/16C", func_80103AD0);

INCLUDE_RODATA("build/src/MENU/MENU3.PRG/nonmatchings/16C", D_80102800);

INCLUDE_ASM("build/src/MENU/MENU3.PRG/nonmatchings/16C", func_80103BE4);

INCLUDE_ASM("build/src/MENU/MENU3.PRG/nonmatchings/16C", func_80103CC8);

INCLUDE_ASM("build/src/MENU/MENU3.PRG/nonmatchings/16C", func_80103E24);

INCLUDE_ASM("build/src/MENU/MENU3.PRG/nonmatchings/16C", func_80103F00);

int func_8010406C(int arg0, func_8010406C_t* arg1)
{
    if (arg0 == 0) {
        return -arg1->unk0;
    }
    return arg1->unk2;
}

INCLUDE_ASM("build/src/MENU/MENU3.PRG/nonmatchings/16C", func_8010408C);

INCLUDE_ASM("build/src/MENU/MENU3.PRG/nonmatchings/16C", func_801041CC);

INCLUDE_ASM("build/src/MENU/MENU3.PRG/nonmatchings/16C", func_801042C4);

INCLUDE_ASM("build/src/MENU/MENU3.PRG/nonmatchings/16C", func_8010439C);

INCLUDE_ASM("build/src/MENU/MENU3.PRG/nonmatchings/16C", func_80104530);

INCLUDE_ASM("build/src/MENU/MENU3.PRG/nonmatchings/16C", func_80104788);

INCLUDE_ASM("build/src/MENU/MENU3.PRG/nonmatchings/16C", func_80104EC0);

INCLUDE_ASM("build/src/MENU/MENU3.PRG/nonmatchings/16C", func_80104F50);

INCLUDE_ASM("build/src/MENU/MENU3.PRG/nonmatchings/16C", func_80104F94);

INCLUDE_ASM("build/src/MENU/MENU3.PRG/nonmatchings/16C", func_80105314);

INCLUDE_ASM("build/src/MENU/MENU3.PRG/nonmatchings/16C", func_801053EC);

INCLUDE_ASM("build/src/MENU/MENU3.PRG/nonmatchings/16C", func_80106390);

int func_80106574(void) { return D_8010975C != 0 ? -1 : D_80109760; }

INCLUDE_ASM("build/src/MENU/MENU3.PRG/nonmatchings/16C", func_8010659C);

INCLUDE_ASM("build/src/MENU/MENU3.PRG/nonmatchings/16C", func_80106BB4);

INCLUDE_ASM("build/src/MENU/MENU3.PRG/nonmatchings/16C", func_80106C94);

INCLUDE_ASM("build/src/MENU/MENU3.PRG/nonmatchings/16C", func_80107148);

INCLUDE_ASM("build/src/MENU/MENU3.PRG/nonmatchings/16C", func_80107620);

INCLUDE_ASM("build/src/MENU/MENU3.PRG/nonmatchings/16C", func_80107B14);

INCLUDE_ASM("build/src/MENU/MENU3.PRG/nonmatchings/16C", func_80108010);

INCLUDE_ASM("build/src/MENU/MENU3.PRG/nonmatchings/16C", func_80108088);

INCLUDE_ASM("build/src/MENU/MENU3.PRG/nonmatchings/16C", func_80108518);

INCLUDE_ASM("build/src/MENU/MENU3.PRG/nonmatchings/16C", func_80108970);

INCLUDE_ASM("build/src/MENU/MENU3.PRG/nonmatchings/16C", func_801090C4);

INCLUDE_ASM("build/src/MENU/MENU3.PRG/nonmatchings/16C", func_80109320);

INCLUDE_ASM("build/src/MENU/MENU3.PRG/nonmatchings/16C", func_80109344);
