#include "common.h"
#include "../../SLUS_010.40/main.h"
#include "146C.h"
#include "2842C.h"
#include "4A0A8.h"
#include <stdio.h>
#include <memory.h>

void func_800AACDC(void);
int func_800B9C58(u_char*, int);
void func_800BE3A0(void);
short func_800BFE00(u_char*);
int func_800C6BF0(int, u_short*);
void func_800CB79C(void);
int func_800CD064(int);

extern char D_800E9BE0[];
extern char D_800E9BE8[];
extern u_char D_800E9C30[];
extern u_int* D_800EB9BC;
extern int D_800F19C8;
extern char D_800F4BA0;
extern u_short* D_800F4BB0;
extern short* D_800F4BBC;
extern char D_800F4BE4;
extern char D_800F4C00[];
extern char D_800F4C20;
extern char D_800F4C2C;
extern char D_800F4C34;
extern int D_800F4C64;
extern char D_800F4C68;

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B28A8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B396C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B3A68);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B3CF0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B4594);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B4B14);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B516C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B5C30);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B63AC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B6404);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B6438);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B64A8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B64CC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B6500);

__asm__("glabel func_800B6530;"
        "ori     $t4, $zero, 0x4;"
        "addu    $a3, $a2, $zero;"
        "j       .L800B6540;"
        "endlabel func_800B6530;");

__asm__(".set push;"
        ".set noreorder;"
        "glabel func_800B653C;"
        "ori        $t4, $zero, 0x3;"
        ".L800B6540:"
        "la         $v0, D_800F4538;"
        "sll        $v1, $a0, 2;"
        "addu       $v0, $v1;"
        "lw         $v0, 0x0($v0);"
        "lw         $t2, 0x0($a1);"
        "lw         $t3, 0x4($a1);"
        "sw         $a2, 0x1850($v0);"
        "lb         $t1, 0xA($v0);"
        "sh         $a3, 0x184E($v0);"
        "sw         $t2, 0x1858($v0);"
        "sw         $t3, 0x185C($v0);"
        "or         $t1, 0x20;"
        "sb         $t1, 0xA($v0);"
        "sw         $t4, 0x1848($v0);"
        "j          $ra;"
        "endlabel func_800B653C;"
        ".set pop;");

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B6580);

__asm__(".set push;"
        ".set nomove;"
        "glabel func_800B65E8;"
        "ori     $t1,$zero,0x10;"
        "j       .L800B65F8;"
        "endlabel func_800B65E8;"
        ".set pop;");

__asm__(".set push;"
        ".set noreorder;"
        "glabel func_800B65F4;"
        "ori        $t1, $zero, 0x40;"
        ".L800B65F8:"
        "la         $v0, D_800F4538;"
        "sll        $v1, $a0, 2;"
        "addu       $v0, $v0, $v1;"
        "lw         $v0, 0x0($v0);"
        "lw         $t2, 0x0($a1);"
        "lw         $t3, 0x4($a1);"
        "lb         $t4, 0xB($v0);"
        "sw         $t2, 0x5EC($v0);"
        "sw         $t3, 0x5F0($v0);"
        "sh         $a2, 0x5F2($v0);"
        "and        $t4, 0x8F;"
        "or         $t1, $t4, $t1;"
        "sb         $t1, 0xB($v0);"
        "j          $ra;"
        "endlabel func_800B65F4;"
        ".set pop;");

void func_800B6634()
{
    __asm__("la         $v0, D_800F4538;"
            "sll        $v1, $a0, 2;"
            "addu       $v0, $v1;"
            "lw         $v0, 0x0($v0);"
            "addu       $sp, -0xC;"
            "lhu        $t0, 0x63C($v0);"
            "sw         $ra, 0x0($sp);"
            "ori        $a2, $zero, 0x80;"
            "sltu       $t0, 0x80;"
            "beqz       $t0, .L800B6668;"
            "sw         $a0, 0x4($sp);"
            "ori        $a2, $zero, 0x20;"
            ".L800B6668:;"
            "jal        func_800A9EB4;"
            "sw         $a1, 0x8($sp);"
            ".L800B6670:;"
            "lw         $a0, 0x4($sp);"
            "jal        func_800A249C;"
            "lw         $a1, 0x8($sp);"
            "lw         $ra, 0x0($sp);"
            "addu       $sp, 0xC;");
}

__asm__(".set push;"
        ".set reorder;"
        "glabel func_800B668C;"
        "addiu      $sp, $sp, -0xC;"
        "sw         $ra, 0x0($sp);"
        "sw         $a0, 0x4($sp);"
        "sw         $a1, 0x8($sp);"
        "jal        func_800AA8D0;"
        "j          .L800B6670;"
        "endlabel func_800B668C;"
        ".set pop;");

int _invalidOpcode(u_char* arg0, int arg1)
{
    char buf[64];

    sprintf(buf, "unknown code detected:%d,$%08x,$%02x", (short)arg1, (u_int)arg0, *arg0);
    // Debug printing presumably ifdef'd out
    return 0;
}

int func_800B66E4(u_char* arg0, int arg1) { return 0; }

int func_800B66EC(u_char* arg0, int arg1) { return 4; }

int func_800B66F4(u_char* arg0, int arg1)
{
    if ((D_800F4BBC != 0) && (*D_800F4BBC != 4)) {
        return 1;
    }
    return 0;
}

int func_800B6724(u_char* arg0, int arg1) { return (*D_800EB9BC >> 1) & 1; }

int func_800B6744(u_char* arg0, int arg1)
{
    D_800F4C2C = 1;
    D_800F4C20 = !(arg0[1] & 1);
    return (D_800F4C68 != 0) * 4;
}

int func_800B6778(u_char* arg0, int arg1)
{
    short i;

    for (i = 0; i < 3; ++i) {
        D_800E9BE0[1] = (i << 4) | 8;
        func_800B9C58(D_800E9BE0, 0);
    }

    func_800AACDC();

    i = 0xF;
    while (*arg0 != i) {
        if (memcmp(arg0, D_800E9BE8, 4) == 0) {
            vs_battle_setStateFlag(0xA8, 0);
            return;
        }
        arg0 = &arg0[D_800E9C30[*arg0]];
    }

    func_80093A70();
    vs_battle_setStateFlag(0xA8, 0);
    // No return value
}

int func_800B6868(u_char* arg0, int arg1)
{
    char temp_v1 = D_800F4C2C;
    D_800F4C2C = 0;
    if (temp_v1 == 2) {
        func_800B6778(arg0, arg1);
        return 4;
    }
    return (int)&arg0[func_800BFE00(arg0 + 1)];
}

int func_800B68C4(u_char* arg0, int arg1)
{
    char temp_v1 = D_800F4C2C;
    D_800F4C2C = 0;
    if (temp_v1 == 2) {
        func_800B6778(arg0, arg1);
        return 4;
    }
    return 0;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B6908);

int func_800B6AB0(u_char* arg0, int arg1)
{
    int temp_v0;

    if (D_800F4C00[arg0[1]] == 0) {
        func_800C6BF0(arg0[1], &D_800F4BB0[D_800F4BB0[arg0[2]]]);
        if (arg0[3] == 0) {
            D_800F4C00[arg0[1]] = 1;
            return 1;
        }
        return 0;
    }

    temp_v0 = func_800C6BF0(arg0[1], 0);

    if (temp_v0 >= 0) {
        if (temp_v0 > 0) {
            vs_main_stateFlags.unkF[1] = temp_v0;
        }
        D_800F4C00[arg0[1]] = 0;
        return 0;
    }
    return 1;
}

int func_800B6B74(u_char* arg0, int arg1)
{
    func_800CD064(arg0[1]);
    return 0;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B6B98);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B6D48);

int func_800B6F8C(char* arg0) { return func_800CD064(arg0[1]) != 0; }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B6FB0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B6FD8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B7014);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B70E8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B71C4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B71F4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B7218);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B7358);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B7398);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B7428);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B7490);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B7574);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B75F4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B76A8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B770C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B77DC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B784C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B792C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B7A98);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B7B58);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B7C90);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B7D10);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B7DC4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B7EF0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B7F84);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B804C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B80B4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B810C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B81A0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B822C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B8290);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B8360);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B83D4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B8438);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B849C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B8510);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B8590);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B860C);

int func_800B86E8(u_char* arg0, int arg1) { return func_8007CCAC() > 0; }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B8708);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B8764);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B8788);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B884C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B88D4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B8A10);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B8B5C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B8B90);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B8BC4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B8BF8);

int func_800B8C44(void) { return D_800F4C64; }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B8C54);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B8C7C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B8CE8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B8D1C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B8D50);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B8EDC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B9170);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B91C4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B91F0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B9230);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B9254);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B92A0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B92D0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B92F4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B94D8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B9564);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B9608);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B9670);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B96B0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B9724);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B9770);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B979C);

int func_800B97E4(u_char* arg0, int arg1)
{
    D_800F19C8 = arg0[1];
    return 0;
}

int func_800B97F8(u_char* arg0, int arg1)
{
    func_8007C31C();
    return 0;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B9818);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B983C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B9860);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B988C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B98C0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B9A40);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B9A94);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B9AC4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B9AE8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B9B18);

int func_800B9BF8(void) { return func_8007C398() != 0; }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B9C18);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B9C58);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B9D74);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B9DB4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B9F28);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B9F4C);

int func_800B9F70(u_char* arg0, int arg1) { return func_8008F0FC() == 0; }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B9F90);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B9FC0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800BA0E4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800BA108);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800BA194);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800BA218);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800BA264);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800BA288);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800BA2B4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800BA2E0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800BA35C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800BA39C);

int func_800BA3E4(u_char* arg0, int arg1)
{
    func_80045DC0();
    return 0;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800BA404);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800BA444);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800BA470);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800BA494);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800BA4C8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800BA4EC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800BA52C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800BA588);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800BA5B4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800BA5E8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800BA61C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800BA650);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800BA684);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800BA6B8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800BA6E0);

int func_800BA72C(void)
{
    func_80044DB4();
    return 0;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800BA74C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800BA774);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800BA798);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800BA7BC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800BA800);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800BA848);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800BA890);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800BA8BC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800BA90C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800BA94C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800BAA04);

int func_800BAA34(u_char* arg0, int arg1) { return func_8007BF0C() != 1; }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800BAA58);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800BAACC);

int func_800BAAF0(u_char* arg0, int arg1)
{
    func_80044DD4(arg0[1]);
    return 0;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800BAB14);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800BABCC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800BAC38);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800BAC5C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800BAD78);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800BADE0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800BAE74);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800BAEA0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800BAF6C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800BB028);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800BB288);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800BB2B8);

int func_800BB2E4(u_char* arg0, int arg1)
{
    func_800CB79C();
    return 0;
}

int func_800BB304(u_char* arg0, int arg1) { return 0; }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800BB30C);

int func_800BB33C(u_char* arg0, int arg1)
{
    func_800BE3A0();
    return 0;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800BB35C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800BB38C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800BB3BC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800BB41C);

int func_800BB450(u_char* arg0, int arg1)
{
    func_8007DD50(arg0[1]);
    return 0;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800BB474);

int func_800BB4CC(u_char* arg0, int arg1)
{
    func_8007C36C(arg0[1]);
    return 0;
}

int func_800BB4F0(u_char* arg0, int arg1)
{
    D_800F4BE4 = arg0[1];
    return 0;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800BB504);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800BB554);

int func_800BB5A4(u_char* arg0, int arg1) { return 3; }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800BB5AC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800BB604);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800BB668);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800BB68C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800BB788);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800BB7C4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800BB874);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800BB9B0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800BBAFC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800BBBE8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800BBDDC);

void func_800BBE04(int arg0) { D_800F4BA0 = arg0; }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800BBE10);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800BBE94);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800BBF14);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800BC1CC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800BC2E8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800BC9E0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800BCA8C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800BCFB4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800BD2B8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800BD444);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800BD57C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800BD610);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800BD6C4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800BDAB4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800BDBB4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800BDC9C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800BDF6C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800BE01C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800BE180);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800BE36C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800BE3A0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800BE3D0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800BE53C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800BE5A4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800BE628);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800BE66C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800BE6B0);

VECTOR* func_800BE71C(VECTOR* arg0, VECTOR* arg1)
{
    copyVector(arg0, arg1);
    return arg0;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800BE740);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800BE7B8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800BE824);

int func_800BE858(int arg0, int arg1)
{
    __asm__("mult       $a0, $a1;"
            "mflo       $t0;"
            "mfhi       $t1;"
            "srl        $t0, 12;"
            "sll        $t1, 20;"
            "or         $v0, $t0, $t1;");
}

int func_800BE878(int arg0, int arg1) { return ratan2(arg0 >> 6, arg1 >> 6); }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800BE89C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800BE940);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800BE98C);

int func_800BEB00(void) { return D_800F4C34; }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800BEB10);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800BEB34);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800BEB9C);

void func_800BEBEC(void) { }

char func_800BEBF4(short arg0)
{
    char* flags = (char*)&vs_main_stateFlags;
    return flags[arg0];
}

void vs_battle_setStateFlag(short arg0, char arg1)
{
    char* flags = (char*)&vs_main_stateFlags;
    flags[arg0] = arg1;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800BEC30);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800BEC58);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800BF5F0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800BF850);
