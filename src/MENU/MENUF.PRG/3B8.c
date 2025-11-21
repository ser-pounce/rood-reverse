#include "common.h"
#include "../../BATTLE/BATTLE.PRG/146C.h"

void func_80105C34(int, int, int, int);
void func_80107A8C(void);

extern char D_8010951A;

INCLUDE_ASM("build/src/MENU/MENUF.PRG/nonmatchings/3B8", func_80102BB8);

INCLUDE_RODATA("build/src/MENU/MENUF.PRG/nonmatchings/3B8", D_80102800);

INCLUDE_RODATA("build/src/MENU/MENUF.PRG/nonmatchings/3B8", D_80102AE0);

INCLUDE_ASM("build/src/MENU/MENUF.PRG/nonmatchings/3B8", func_80102C54);

INCLUDE_ASM("build/src/MENU/MENUF.PRG/nonmatchings/3B8", func_80102D10);

INCLUDE_ASM("build/src/MENU/MENUF.PRG/nonmatchings/3B8", func_8010310C);

INCLUDE_ASM("build/src/MENU/MENUF.PRG/nonmatchings/3B8", func_80103530);

INCLUDE_ASM("build/src/MENU/MENUF.PRG/nonmatchings/3B8", func_80103748);

INCLUDE_ASM("build/src/MENU/MENUF.PRG/nonmatchings/3B8", func_801037A0);

INCLUDE_ASM("build/src/MENU/MENUF.PRG/nonmatchings/3B8", func_8010384C);

INCLUDE_ASM("build/src/MENU/MENUF.PRG/nonmatchings/3B8", func_80103D88);

INCLUDE_ASM("build/src/MENU/MENUF.PRG/nonmatchings/3B8", func_8010412C);

INCLUDE_ASM("build/src/MENU/MENUF.PRG/nonmatchings/3B8", func_8010459C);

INCLUDE_ASM("build/src/MENU/MENUF.PRG/nonmatchings/3B8", func_80104650);

INCLUDE_ASM("build/src/MENU/MENUF.PRG/nonmatchings/3B8", func_801046F8);

INCLUDE_ASM("build/src/MENU/MENUF.PRG/nonmatchings/3B8", func_801047D4);

INCLUDE_ASM("build/src/MENU/MENUF.PRG/nonmatchings/3B8", func_8010489C);

INCLUDE_ASM("build/src/MENU/MENUF.PRG/nonmatchings/3B8", func_80104914);

INCLUDE_ASM("build/src/MENU/MENUF.PRG/nonmatchings/3B8", func_80104A50);

INCLUDE_ASM("build/src/MENU/MENUF.PRG/nonmatchings/3B8", func_80104B8C);

INCLUDE_ASM("build/src/MENU/MENUF.PRG/nonmatchings/3B8", func_80104C40);

INCLUDE_ASM("build/src/MENU/MENUF.PRG/nonmatchings/3B8", func_80104DBC);

INCLUDE_ASM("build/src/MENU/MENUF.PRG/nonmatchings/3B8", func_80105020);

INCLUDE_ASM("build/src/MENU/MENUF.PRG/nonmatchings/3B8", func_8010516C);

INCLUDE_ASM("build/src/MENU/MENUF.PRG/nonmatchings/3B8", func_801053B0);

INCLUDE_ASM("build/src/MENU/MENUF.PRG/nonmatchings/3B8", func_8010540C);

INCLUDE_ASM("build/src/MENU/MENUF.PRG/nonmatchings/3B8", func_8010559C);

INCLUDE_ASM("build/src/MENU/MENUF.PRG/nonmatchings/3B8", func_8010564C);

INCLUDE_ASM("build/src/MENU/MENUF.PRG/nonmatchings/3B8", func_801056E8);

INCLUDE_ASM("build/src/MENU/MENUF.PRG/nonmatchings/3B8", func_80105790);

INCLUDE_ASM("build/src/MENU/MENUF.PRG/nonmatchings/3B8", func_8010581C);

void func_801059B8(int arg0, int arg1, int arg2)
{
    if (arg2 < 0) {
        arg2 = 0;
    }
    if (arg2 >= 0x41) {
        arg2 = 0x40;
    }
    if (arg2 > 0) {
        func_80105C34(arg0, arg1, 0x45, arg2);
    }
}

INCLUDE_ASM("build/src/MENU/MENUF.PRG/nonmatchings/3B8", func_801059FC);

INCLUDE_ASM("build/src/MENU/MENUF.PRG/nonmatchings/3B8", func_80105B30);

INCLUDE_ASM("build/src/MENU/MENUF.PRG/nonmatchings/3B8", func_80105C34);

INCLUDE_ASM("build/src/MENU/MENUF.PRG/nonmatchings/3B8", func_80105DD8);

INCLUDE_RODATA("build/src/MENU/MENUF.PRG/nonmatchings/3B8", D_80102B5C);

INCLUDE_RODATA("build/src/MENU/MENUF.PRG/nonmatchings/3B8", D_80102B64);

INCLUDE_ASM("build/src/MENU/MENUF.PRG/nonmatchings/3B8", func_80105F6C);

INCLUDE_ASM("build/src/MENU/MENUF.PRG/nonmatchings/3B8", func_801060A8);

INCLUDE_ASM("build/src/MENU/MENUF.PRG/nonmatchings/3B8", func_801064D4);

INCLUDE_ASM("build/src/MENU/MENUF.PRG/nonmatchings/3B8", func_8010664C);

INCLUDE_ASM("build/src/MENU/MENUF.PRG/nonmatchings/3B8", func_80106A80);

INCLUDE_ASM("build/src/MENU/MENUF.PRG/nonmatchings/3B8", func_80107140);

INCLUDE_ASM("build/src/MENU/MENUF.PRG/nonmatchings/3B8", func_80107698);

INCLUDE_ASM("build/src/MENU/MENUF.PRG/nonmatchings/3B8", func_80107A8C);

void func_80107D4C(void)
{
    if (vs_main_stateFlags.unkF[0x94] != 0) {
        vs_main_stateFlags.unkF[0x93] = 0x3B;
        vs_main_stateFlags.unkF[0x92] = 0x3B;
        vs_main_stateFlags.unkF[0x94] = 0;
        vs_main_stateFlags.unkF[0x91] = 0x63;
    }
    func_80107A8C();
}

INCLUDE_ASM("build/src/MENU/MENUF.PRG/nonmatchings/3B8", func_80107D98);

INCLUDE_ASM("build/src/MENU/MENUF.PRG/nonmatchings/3B8", func_80107FC0);

INCLUDE_ASM("build/src/MENU/MENUF.PRG/nonmatchings/3B8", func_801080E4);

INCLUDE_ASM("build/src/MENU/MENUF.PRG/nonmatchings/3B8", func_801083AC);

INCLUDE_ASM("build/src/MENU/MENUF.PRG/nonmatchings/3B8", func_801084F4);

INCLUDE_ASM("build/src/MENU/MENUF.PRG/nonmatchings/3B8", func_80108564);

INCLUDE_ASM("build/src/MENU/MENUF.PRG/nonmatchings/3B8", func_801085D4);

INCLUDE_ASM("build/src/MENU/MENUF.PRG/nonmatchings/3B8", func_80108688);

void func_8010873C(int arg0, int arg1, int arg2)
{
    if (arg2 > 0x40) {
        arg2 = 0x40;
    }
    if (arg2 > 0) {
        func_80105C34(arg0 - (D_8010951A >> 1), arg1, 0x68, arg2);
    }
}

INCLUDE_ASM("build/src/MENU/MENUF.PRG/nonmatchings/3B8", func_80108784);

INCLUDE_ASM("build/src/MENU/MENUF.PRG/nonmatchings/3B8", func_8010880C);

INCLUDE_ASM("build/src/MENU/MENUF.PRG/nonmatchings/3B8", func_8010887C);

INCLUDE_ASM("build/src/MENU/MENUF.PRG/nonmatchings/3B8", func_80108A0C);

INCLUDE_ASM("build/src/MENU/MENUF.PRG/nonmatchings/3B8", func_80108AB0);

void func_80108E38(void) { }

void func_80108E40(void) { }

INCLUDE_ASM("build/src/MENU/MENUF.PRG/nonmatchings/3B8", func_80108E48);

void func_80108EA0(void) { }

int func_80108EA8(void) { return vs_battle_characterState->unk3C->unk24; }

int func_80108EC8(void) { return vs_battle_characterState->unk3C->unk28; }

int func_80108EE8(void) { return vs_battle_characterState->unk3C->unk2C; }

INCLUDE_ASM("build/src/MENU/MENUF.PRG/nonmatchings/3B8", func_80108F08);

INCLUDE_ASM("build/src/MENU/MENUF.PRG/nonmatchings/3B8", func_80108F98);

INCLUDE_ASM("build/src/MENU/MENUF.PRG/nonmatchings/3B8", func_80109028);

INCLUDE_ASM("build/src/MENU/MENUF.PRG/nonmatchings/3B8", func_801090B8);

INCLUDE_ASM("build/src/MENU/MENUF.PRG/nonmatchings/3B8", func_80109148);
