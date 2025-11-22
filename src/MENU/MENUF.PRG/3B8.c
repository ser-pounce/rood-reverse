#include "common.h"
#include "../../SLUS_010.40/main.h"
#include "../../BATTLE/BATTLE.PRG/146C.h"

void func_80105C34(int, int, int, int);
void func_8010664C(int, int, int, char*);
void func_80106A80(int, int, int, char*);
void func_80107A8C(void);

extern char D_801091D8[][8];
extern char D_8010923A;
extern char D_8010951A;
extern char D_80109764[];
extern char D_801097E4[];

INCLUDE_ASM("build/src/MENU/MENUF.PRG/nonmatchings/3B8", func_80102BB8);

INCLUDE_RODATA("build/src/MENU/MENUF.PRG/nonmatchings/3B8", D_80102800);

INCLUDE_RODATA("build/src/MENU/MENUF.PRG/nonmatchings/3B8", D_80102AE0);

INCLUDE_ASM("build/src/MENU/MENUF.PRG/nonmatchings/3B8", func_80102C54);

INCLUDE_ASM("build/src/MENU/MENUF.PRG/nonmatchings/3B8", func_80102D10);

INCLUDE_ASM("build/src/MENU/MENUF.PRG/nonmatchings/3B8", func_8010310C);

INCLUDE_ASM("build/src/MENU/MENUF.PRG/nonmatchings/3B8", func_80103530);

void func_80103748(void)
{
    if ((D_8005E040 != 7) && (((D_8005E040 - 0x1F) < 9) || ((D_8005E040 - 0x2D) < 5))) {
        vs_main_loadMusicSlot(D_8005E040 + 0x64, 2);
    } else {
        vs_main_loadMusicSlot(0x80, 2);
    }
}

INCLUDE_ASM("build/src/MENU/MENUF.PRG/nonmatchings/3B8", func_801037A0);

INCLUDE_ASM("build/src/MENU/MENUF.PRG/nonmatchings/3B8", func_8010384C);

INCLUDE_ASM("build/src/MENU/MENUF.PRG/nonmatchings/3B8", func_80103D88);

INCLUDE_ASM("build/src/MENU/MENUF.PRG/nonmatchings/3B8", func_8010412C);

INCLUDE_ASM("build/src/MENU/MENUF.PRG/nonmatchings/3B8", func_8010459C);

INCLUDE_ASM("build/src/MENU/MENUF.PRG/nonmatchings/3B8", func_80104650);

INCLUDE_ASM("build/src/MENU/MENUF.PRG/nonmatchings/3B8", func_801046F8);

INCLUDE_ASM("build/src/MENU/MENUF.PRG/nonmatchings/3B8", func_801047D4);

void func_8010489C(int arg0, int arg1, int arg2)
{
    int temp_a2 = (arg2 / 15) + 0x60;
    func_80105C34(arg0 - (D_801091D8[temp_a2][2] >> 1),
        arg1 - (D_801091D8[temp_a2][3] >> 1), temp_a2, arg2 % 15);
}

INCLUDE_ASM("build/src/MENU/MENUF.PRG/nonmatchings/3B8", func_80104914);

INCLUDE_ASM("build/src/MENU/MENUF.PRG/nonmatchings/3B8", func_80104A50);

INCLUDE_ASM("build/src/MENU/MENUF.PRG/nonmatchings/3B8", func_80104B8C);

INCLUDE_ASM("build/src/MENU/MENUF.PRG/nonmatchings/3B8", func_80104C40);

INCLUDE_ASM("build/src/MENU/MENUF.PRG/nonmatchings/3B8", func_80104DBC);

INCLUDE_ASM("build/src/MENU/MENUF.PRG/nonmatchings/3B8", func_80105020);

INCLUDE_ASM("build/src/MENU/MENUF.PRG/nonmatchings/3B8", func_8010516C);

void func_801053B0(int arg0, int arg1, int arg2)
{
    if (arg2 < 0) {
        arg2 = 0;
    }
    if (arg2 > 0x40) {
        arg2 = 0x40;
    }
    if (arg2 > 0) {
        D_80109764[3] = arg2;
        func_8010664C(arg0 - ((char)D_8010923A >> 1), arg1, 0xC, D_80109764);
    }
}

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
    if (arg2 > 0x40) {
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

void func_801084F4(int arg0, int arg1)
{
    if (arg1 < 0) {
        arg1 = 0;
    }
    if (arg1 > 0x40) {
        arg1 = 0x40;
    }
    if (arg1 > 0) {
        func_80105C34(0, arg0, 0x7B, arg1);
        func_80105C34(0xA0, arg0, 0x7C, arg1);
    }
}

void func_80108564(int arg0, int arg1)
{
    if (arg1 < 0) {
        arg1 = 0;
    }
    if (arg1 > 0x40) {
        arg1 = 0x40;
    }
    if (arg1 > 0) {
        func_80105C34(0, arg0, 0x7D, arg1);
        func_80105C34(0xA0, arg0, 0x7E, arg1);
    }
}

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

void func_8010880C(int arg0, int arg1, int arg2, int arg3)
{
    if (arg2 < 0) {
        arg2 = 0;
    }
    if (arg2 > 0x40) {
        arg2 = 0x40;
    }
    if (arg2 > 0) {
        D_801097E4[3] = arg2;
        func_80106A80(
            arg0 - (D_801091D8[arg3 + 0x6B][2] >> 1), arg1, arg3 + 0x6B, D_801097E4);
    }
}

INCLUDE_ASM("build/src/MENU/MENUF.PRG/nonmatchings/3B8", func_8010887C);

INCLUDE_ASM("build/src/MENU/MENUF.PRG/nonmatchings/3B8", func_80108A0C);

INCLUDE_ASM("build/src/MENU/MENUF.PRG/nonmatchings/3B8", func_80108AB0);

void func_80108E38(void) { }

void func_80108E40(void) { }

void func_80108E48(void)
{
    int new_var = D_8005FEA0.unk108 + 0x186A0;
    D_8005FEA0.unk108 = new_var - (D_8005FEA0.unk112 * 0x64);
    if (D_8005FEA0.unk108 > 0x3B9AC9FF) {
        D_8005FEA0.unk108 = 0x3B9AC9FF;
    }
    D_8005FEA0.unk112 = 0;
}

void func_80108EA0(void) { }

int func_80108EA8(void) { return vs_battle_characterState->unk3C->unk24; }

int func_80108EC8(void) { return vs_battle_characterState->unk3C->unk28; }

int func_80108EE8(void) { return vs_battle_characterState->unk3C->unk2C; }

INCLUDE_ASM("build/src/MENU/MENUF.PRG/nonmatchings/3B8", func_80108F08);

INCLUDE_ASM("build/src/MENU/MENUF.PRG/nonmatchings/3B8", func_80108F98);

INCLUDE_ASM("build/src/MENU/MENUF.PRG/nonmatchings/3B8", func_80109028);

void _raiseMaxHP(int amount)
{
    vs_battle_characterState->unk3C->maxHP += amount;
    if (vs_battle_characterState->unk3C->maxHP > 999) {
        vs_battle_characterState->unk3C->maxHP = 999;
    }
    vs_battle_characterState->unk3C->currentHP += amount;
    if (vs_battle_characterState->unk3C->currentHP > 999) {
        vs_battle_characterState->unk3C->currentHP = 999;
    }
}

void _raiseMaxMP(int amount)
{
    vs_battle_characterState->unk3C->maxMP += amount;
    if (vs_battle_characterState->unk3C->maxMP > 999) {
        vs_battle_characterState->unk3C->maxMP = 999;
    }
    vs_battle_characterState->unk3C->currentMP += amount;
    if (vs_battle_characterState->unk3C->currentMP > 999) {
        vs_battle_characterState->unk3C->currentMP = 999;
    }
}
