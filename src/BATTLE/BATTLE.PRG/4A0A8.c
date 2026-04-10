#include "common.h"
#include "146C.h"
#include "2842C.h"
#include "30D14.h"
#include "3A1A0.h"
#include "40564.h"
#include "4A0A8.h"
#include "573B8.h"
#include "5BF94.h"
#include "../../SLUS_010.40/main.h"
#include "../../SLUS_010.40/32154.h"
#include "../../GIM/SCREFF2.PRG/0.h"
#include <stdio.h>
#include <memory.h>
#include <stddef.h>

typedef struct {
    char unk0;
    char unk1;
    char unk2;
    char unk3;
    char unk4;
    char unk5;
    char unk6;
    char unk7;
    char unk8[0x1C];
    VECTOR unk24;
    char unk34[0x60];
    VECTOR unk94;
    VECTOR unkA4;
} D_800F4BA4_t2;

typedef struct {
    char unk0;
    char unk1;
    short unk2;
    short unk4;
    short unk6;
    short unk8;
    short unkA;
} func_800BD57C_t;

typedef struct {
    char unk0;
    char unk1;
    short unk2;
    short unk4;
    short unk6;
    char unk8;
    char unk9;
    char unkA;
    char unkB;
} func_800BDF6C_t;

typedef struct {
    D_800F4BA4_t2 unk0[2];
    func_800BD57C_t unk168;
    func_800BD57C_t unk174;
    func_800BDF6C_t unk180;
    func_800BDF6C_t unk18C;
    func_800BDF6C_t unk198;
    func_800BDF6C_t unk1A4;
    func_800BDF6C_t unk1B0;
    int unk1BC[11];
    u_short unk1E8;
    u_short unk1EA;
    VECTOR unk1EC;
    char unk1FC[0x7C];
    short unk278;
    short unk27A;
    int unk27C;
} D_800F4BA4_t;

typedef struct {
    u_int unk0_0 : 1;
    u_int unk0_1 : 1;
    u_int unk0_2 : 1;
    u_int unk0_3 : 3;
    u_int unk0_6 : 18;
    u_int unk0_24 : 8;
    int unk4;
    short unk8;
    short unkA;
    short unkC;
    int unk10[0xFA];
} D_800EB9BC_t;

void func_800AACDC(void);
int func_800B9C58(u_char*, short);
void func_800BB68C(u_short, char*);
u_short func_800BB788(char* arg0);
void func_800BBE10(u_short);
void func_800BBE94(void);
void func_800BCA8C(D_800F4BA4_t2*, D_800F4BA4_t2*);
void func_800BC1CC(short, int);
void func_800BD57C(func_800BD57C_t* arg0);
int func_800BD610(void);
void func_800BDF6C(func_800BDF6C_t* arg0);
void func_800BE180(void);
void func_800BE36C(int, int);
void func_800BE3A0(void);
VECTOR* func_800BE628(VECTOR* arg0, VECTOR* arg1, VECTOR* arg2);
VECTOR* func_800BE66C(VECTOR* arg0, VECTOR* arg1, VECTOR* arg2);
static int _fixedPointMult(int a, int b);
void func_800BFD9C();
short func_800BFE00(u_char*);
int func_800BFEBC(int, int, int);
int func_800C6BF0(int, char*);
void func_800CB79C(void);
int func_800CD064(int);
void func_800CEF38(int);
static int _vectorMagnitude(VECTOR*);

extern int D_800E9B34[];
extern int D_800E9B4C[];
extern char D_800E9B58[];
extern char D_800E9BE0[];
extern char D_800E9BE8[];
extern short D_800E9BF4[];
extern short D_800E9BF8[];
extern u_char D_800E9C30[];
extern u_char* D_800EB9B4;
extern D_800EB9BC_t* D_800EB9BC;
extern int D_800F19C8;
extern u_short D_800F4B28[];
extern char D_800F4B30[];
extern char D_800F4B70[];
extern char D_800F4BA0;
extern D_800F4BA4_t* D_800F4BA4;
extern void* D_800F4BAC;
extern u_short* D_800F4BB0;
extern char D_800F4BB4;
extern short D_800F4BB6;
extern char D_800F4BB8;
extern u_char D_800F4BB9;
extern short* D_800F4BBC;
extern char* D_800F4BC0[];
extern u_short D_800F4BE0;
extern char D_800F4BE4;
extern void* D_800F4BE8;
extern char D_800F4BF8;
extern char D_800F4C00[];
extern char D_800F4C10[];
extern char D_800F4C20;
extern void* D_800F4C24;
extern char D_800F4C2C;
extern char D_800F4C34;
extern u_char* D_800F4C38[];
extern short D_800F4C4C;
extern short D_800F4C54;
extern short D_800F4C58[];
extern char D_800F4C60;
extern int D_800F4C64;
extern char D_800F4C68;
extern char D_800F4C69;
extern char D_800F4C6A;

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B28A8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B396C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B3A68);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B3CF0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B4594);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B4B14);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B516C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B5C30);

__asm__(".set push;"
        ".set noreorder;"
        "glabel func_800B63AC;"
        "la         $v0, D_800F4538;"
        "sll        $v1, $a0, 2;"
        "addu       $v0, $v1;"
        "lw         $v0, 0x0($v0);"
        "nop;"
        "lb         $v1, 0xA($v0);"
        "lb         $t1, 0x5B0($v0);"
        "and        $t0, $v1, 0x40;"
        "bnez       $t0, .L800B6424;"
        "and        $t0, $v1, 0x20;"
        "bnez       $t0, .L800B6454;"
        "and        $t1, 0xFC;"
        "or         $t1, 0x1;"
        "sb         $t1, 0x5B0($v0);"
        ".L800B63E8:"
        "addu       $sp, -0x4;"
        "sw         $ra, 0x0($sp);"
        "jal        func_800A208C;"
        "addu       $a0, $v0, $zero;"
        "lw         $ra, 0x0($sp);"
        "addu       $sp, 0x4;"
        "jr         $ra;"
        "endlabel func_800B63AC;"
        ".set pop");

__asm__(".set push;"
        ".set reorder;"
        "glabel func_800B6404;"
        "la         $v0, D_800F4538;"
        "sll        $v1, $a0, 2;"
        "addu       $v0, $v1;"
        "lw         $v0, 0x0($v0);"
        "lb         $v1, 0xA($v0);"
        ".L800B6424:"
        "and        $v1, 0x9F;"
        "or         $v1, 0x40;"
        "sb         $v1, 0xA($v0);"
        ".set nomove;"
        "j          .L800B63E8;"
        "endlabel func_800B6404;"
        ".set pop");

void func_800B6438(int arg0, int arg1, int arg2, int arg3)
{
    __asm__("la         $v0, D_800F4538;"
            "sll        $v1, $a0, 2;"
            "addu       $v0, $v1;"
            "lw         $v0, 0x0($v0);"
            "nop;"
            "lb         $v1, 0xA($v0);"
            ".L800B6454:"
            "addu       $sp, -0x14;"
            "sw         $v0, 0x0($sp);"
            "sw         $a1, 0x4($sp);"
            "sw         $a2, 0x8($sp);"
            "sw         $a3, 0xC($sp);"
            "sw         $ra, 0x10($sp);"
            "or         $v1, 0x60;"
            "sb         $v1, 0xA($v0);"
            "or         $a1, $zero, 0x1F;"
            "addu       $a2, $zero, $zero;"
            "jal        func_800A0204;"
            "or         $a3, $zero, 0x8;"
            "lw         $a0, 0x0($sp);"
            "lw         $a1, 0x4($sp);"
            "lw         $a2, 0x8($sp);"
            "jal        func_800A208C;"
            "lw         $a3, 0xC($sp);"
            "lw         $ra, 0x10($sp);"
            "addu       $sp, 0x14;");
}

__asm__(".set push;"
        ".set noreorder;"
        "glabel func_800B64A8;"
        "addu       $sp, -0x4;"
        "sw         $ra, 0x0($sp);"
        "jal        func_800B64CC;"
        "addu       $a3, $a1, $zero;"
        "or         $v1, $zero, 0x0;"
        "sb         $v1, 0x1848($v0);"
        "lw         $ra, 0x0($sp);"
        "addu       $sp, 0x4;"
        "j          $ra;"
        "endlabel func_800B64A8;"
        ".set pop");

void func_800B64CC(int arg0, int arg1, int arg2, int arg3)
{
    __asm__("la         $v0, D_800F4538;"
            "sll        $v1, %0, 2;"
            "addu       $v0, $v1;"
            "lw         $v0, 0x0($v0);"
            "or         $v1, $zero, 0x1;"
            "sll        $t0, %3, 16;"
            "or         $t0, %1;"
            "sw         $t0, 0x184C($v0);"
            "sw         %2, 0x1850($v0);"
            ".L800B64F4:"
            "sw         $v1, 0x1848($v0);"
            :
            : "r"(arg0), "r"(arg1), "r"(arg2), "r"(arg3));
}

__asm__("glabel func_800B6500;"
        "la         $v0, D_800F4538;"
        "sll        $v1, $a0, 2;"
        "addu       $v0, $v1;"
        "lw         $v0, 0x0($v0);"
        "lw         $t2, 0x0($a1);"
        "lw         $t3, 0x4($a1);"
        "sw         $t2, 0x1858($v0);"
        "sw         $t3, 0x185C($v0);"
        "lb         $t1, 0xA($v0);"
        "j          .L800B64F4;"
        "or         $v1, $zero, 0x2;"
        "endlabel func_800B6500;");

__asm__("glabel func_800B6530;"
        "ori     $t4, $zero, 0x4;"
        "j       .L800B6540;"
        "addu    $a3, $a2, $zero;"
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

__asm__(".set push;"
        ".set noreorder;"
        "glabel func_800B6580;"
        "la         $v0, D_800F4538;"
        "sll        $v1, $a0, 2;"
        "addu       $v0, $v1;"
        "lw         $v0, 0x0($v0);"
        "lw         $t2, 0x0($a1);"
        "lb         $t1, 0xB($v0);"
        "sll        $t0, $a2, 16;"
        "and        $t1, 0xF;"
        "bnez       $t1, .L800B65E4;"
        "or         $t1, 0x1;"
        "lbu        $a0, 0x17FD($v0);"
        "sh         $zero, 0x1A($v0);"
        "sw         $t2, 0x5EC($v0);"
        "sw         $t0, 0x5F0($v0);"
        "sb         $t1, 0xB($v0);"
        "slt        $t3, $a0, 0x2;"
        "bnez       $t3, .L800B65E4;"
        ".nop;"
        "addu       $sp, -0x4;"
        "sw         $ra, 0x0($sp);"
        "jal        func_800B6580;"
        ".nop;"
        "lw         $ra, 0x0($sp);"
        "addu       $sp, 0x4;"
        ".L800B65E4:"
        "jr         $ra;"
        "endlabel func_800B6580;"
        ".set pop;");

__asm__(".set push;"
        ".set noreorder;"
        "glabel func_800B65E8;"
        "ori     $t1,$zero,0x10;"
        "j       .L800B65F8;"
        ".nop;"
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
            "or         $a2, $zero, 0x80;"
            "sltu       $t0, 0x80;"
            "beqz       $t0, .L800B6668;"
            "sw         $a0, 0x4($sp);"
            "or         $a2, $zero, 0x20;"
            ".L800B6668:"
            "jal        func_800A9EB4;"
            "sw         $a1, 0x8($sp);"
            ".L800B6670:"
            "lw         $a0, 0x4($sp);"
            "jal        func_800A249C;"
            "lw         $a1, 0x8($sp);"
            "lw         $ra, 0x0($sp);"
            "addu       $sp, 0xC;");
}

__asm__(".set push;"
        ".set reorder;"
        "glabel func_800B668C;"
        "addu       $sp, -0xC;"
        "sw         $ra, 0x0($sp);"
        "sw         $a0, 0x4($sp);"
        "sw         $a1, 0x8($sp);"
        "jal        func_800AA8D0;"
        "j          .L800B6670;"
        "endlabel func_800B668C;"
        ".set pop;");

int _invalidOpcode(u_char* arg0, short arg1)
{
    char buf[64];

    sprintf(buf, "unknown code detected:%d,$%08x,$%02x", arg1, (u_int)arg0, *arg0);
    // Debug printing presumably ifdef'd out
    return 0;
}

int func_800B66E4(u_char* arg0, short arg1) { return 0; }

int func_800B66EC(u_char* arg0, short arg1) { return 4; }

int func_800B66F4(u_char* arg0, short arg1)
{
    if ((D_800F4BBC != 0) && (*D_800F4BBC != 4)) {
        return 1;
    }
    return 0;
}

int func_800B6724(u_char* arg0, short arg1) { return D_800EB9BC->unk0_1; }

int func_800B6744(u_char* arg0, short arg1)
{
    D_800F4C2C = 1;
    D_800F4C20 = !(arg0[1] & 1);
    return (D_800F4C68 != 0) * 4;
}

int func_800B6778(u_char* arg0)
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

int func_800B6868(u_char* arg0, short arg1)
{
    char temp_v1 = D_800F4C2C;
    D_800F4C2C = 0;
    if (temp_v1 == 2) {
        func_800B6778(arg0);
        return 4;
    }
    return (int)&arg0[func_800BFE00(arg0 + 1)];
}

int func_800B68C4(u_char* arg0, short arg1)
{
    char temp_v1 = D_800F4C2C;
    D_800F4C2C = 0;
    if (temp_v1 == 2) {
        func_800B6778(arg0);
        return 4;
    }
    return 0;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B6908);

int func_800B6AB0(u_char* arg0, short arg1)
{
    int temp_v0;

    if (D_800F4C00[arg0[1]] == 0) {
        func_800C6BF0(arg0[1], (char*)&D_800F4BB0[D_800F4BB0[arg0[2]]]);
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

int func_800B6B74(u_char* arg0, short arg1)
{
    func_800CD064(arg0[1]);
    return 0;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B6B98);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B6D48);

int func_800B6F8C(u_char* arg0, short arg1) { return func_800CD064(arg0[1]) != 0; }

int func_800B6FB0(u_char* arg0, short arg1)
{
    if (vs_main_buttonsPressed.all & arg0[1]) {
        return 4;
    }
    return 1;
}

int func_800B6FD8(u_char* arg0, short arg1)
{
    vs_battle_loadGim(func_800BFE00(arg0 + 1), arg0[3]);
    return 0;
}

int func_800B7014(u_char* arg0, short arg1)
{
    char* new_var;

    D_800EB9BC_t* temp_a1 = D_800EB9BC;

    if (temp_a1 == NULL) {
        return 0;
    }

    new_var = (arg0[1] >> 6) * 0x14 + D_800F4B30;
    new_var[3] = 0;
    temp_a1 = temp_a1 + ((arg0[1] >> 6));
    temp_a1->unk0_3 = arg0[1] & 3;
    temp_a1->unk8 = (signed char)arg0[2] * 2;
    temp_a1->unkA = (signed char)arg0[3] * 2;
    temp_a1->unkC = arg0[4] << 7;
    temp_a1->unk0_24 = arg0[5];
    func_800C8550(arg0[1] >> 6, temp_a1, arg0);
    return 0;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B70E8);

int func_800B71C4(u_char* arg0, short arg1)
{
    func_800C86AC();
    return (D_800F4C2C == 2) * 4;
}

int func_800B71F4(u_char* arg0, short arg1)
{
    return (D_800F4B30[0x2B] | (D_800F4B30[3] | D_800F4B30[0x17])) != 0;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B7218);

int func_800B7358(u_char* arg0, short arg1)
{
    func_800CCDF4(arg0[1] >> 5)->unk22 = arg0[1] & 0x1F;
    return 0;
}

int func_800B7398(u_char* arg0)
{
    if (D_800F4C2C == 2) {
        return 0;
    }

    if (D_800F4C60 != 0) {
        short temp_v0 = func_800C6C8C(arg0[1]);
        if ((temp_v0 << 0x10) != 0) {
            vs_battle_setStateFlag(0x10, temp_v0);
            D_800F4C60 = 0;
            return 0;
        }
    } else {
        func_800C6C8C(arg0[1]);
        D_800F4C60 = 1;
    }
    return 1;
}

int func_800B7428(u_char* arg0, short arg1)
{
    char sp10[24];

    func_800BB68C(func_800BFE00(arg0 + 1), sp10);
    while (1) {
        int temp_a0 = func_800BB788(sp10);
        if (temp_a0 == 1) {
            break;
        }
        func_8007C348(temp_a0, arg0[3]);
    }
    return 0;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B7490);

int func_800B7574(u_char* arg0, short arg1)
{
    u_char sp10[12];

    sp10[0] = arg0[5];
    sp10[1] = arg0[6];
    sp10[2] = arg0[7];
    sp10[3] = arg0[8];
    func_8007C928(func_800BFE50(func_800BFE00(arg0 + 1)), func_800BFE00(arg0 + 3),
        (func_8007C8F8_t_flags*)(sp10));
    return 0;
}

int func_800B75F4(u_char* arg0, short arg1)
{
    RECT sp10;
    u_short temp_v0 = func_800BFE50(func_800BFE00(arg0 + 1));
    sp10.x = (arg0[3] << 7) + 0x40;
    sp10.y = 0;
    sp10.w = (arg0[5] << 7) + 0x40;
    if (D_800F4C2C == 2) {
        sp10.h = -0x8000;
        func_800A9D90(temp_v0, &sp10, 0);
    } else {
        func_8007CFF8(temp_v0, &sp10);
    }
    func_8009DC8C(temp_v0);
    D_800F4B70[temp_v0] = 1;
    return 0;
}

int func_800B76A8(u_char* arg0)
{
    func_800A0204(func_800BFE50(func_800BFE00(arg0 + 1)),
        D_800E9B58[arg0[5] >> 6] + arg0[3], arg0[4], arg0[5] & 0x3F);
    return 0;
}

int func_800B770C(u_char* arg0, short arg1)
{
    char sp10[24];
    int temp_s0;
    int var_s1;
    int var_s2;
    int temp_v0;
    u_int a1;

    func_800BB68C(func_800BFE00(arg0 + 1), sp10);

    while (1) {
        temp_s0 = func_800BB788(sp10);
        if (temp_s0 == 1) {
            break;
        }
        temp_v0 = func_800A0BE0(temp_s0);
        var_s2 = temp_v0 & 0x800;
        var_s1 = temp_v0 & 0x1000;
        a1 = arg0[4];
        if (!(a1 & 2)) {
            var_s2 = (a1 & 1) << 0xB;
        }
        if (!(a1 & 8)) {
            var_s1 = (a1 << 0xA) & 0x1000;
        }
        func_8007D1A8(temp_s0, (a1 >> 5) & 1);
        func_800A087C(temp_s0, var_s2 | var_s1 | arg0[3]);
        func_8009D88C(temp_s0);
    }
    return 0;
}

int func_800B77DC(u_char* arg0, short arg1)
{
    char sp10[4];
    int var_a0;

    sp10[0] = arg0[3];
    sp10[1] = arg0[4];
    sp10[2] = arg0[5];
    sp10[3] = arg0[6];
    var_a0 = func_800BFE50(func_800BFE00(arg0 + 1));
    if (var_a0 == 0x2001) {
        var_a0 = -1;
    }
    func_8009F990(var_a0, sp10);
    return 0;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B784C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B792C);

int func_800B7A98(u_char* arg0, short arg1)
{
    u_char sp10[16];
    u_short temp_s0 = func_800BFE50(func_800BFE00(arg0 + 1));
    sp10[0] = arg0[3];
    sp10[1] = arg0[4];
    sp10[2] = arg0[5];
    sp10[3] = 0xFF;
    if (D_800F4C2C == 2) {
        func_800A9C54(temp_s0, sp10, 0);
    } else {
        func_800A9C54(temp_s0, sp10, arg0[6] != 0xFF ? arg0[6] : -1);
    }
    func_8009DC8C(temp_s0);
    D_800F4B70[temp_s0] = 1;
    return 0;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B7B58);

int func_800B7C90(u_char* arg0, short arg1)
{
    u_short temp_s1 = func_800BFE50(func_800BFE00(arg0 + 1));
    u_int temp_a1 = func_800BFE50(func_800BFE00(arg0 + 3)) & 0xFFFF;
    if (temp_a1 >= 0x2000) {
        func_8009FFA8(temp_s1, temp_a1);
    } else {
        func_8009FF08(temp_s1, temp_a1, arg0[5], arg0[6]);
    }
    return 0;
}

int func_800B7D10(u_char* arg0, short arg1)
{
    RECT sp10;
    u_short temp_s1 = func_800BFE50(func_800BFE00(arg0 + 1) & 0xFFFF);
    sp10.x = func_800BFE00(arg0 + 3);
    sp10.y = 0;
    sp10.w = func_800BFE00(arg0 + 5);
    if (D_800F4C2C == 2) {
        sp10.h = -0x8000;
        func_800A9D90(temp_s1, &sp10, 0);
    } else {
        func_8007CFF8(temp_s1, &sp10);
    }
    func_8009DC8C(temp_s1);
    D_800F4B70[temp_s1] = 1;
    return 0;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B7DC4);

int func_800B7EF0(u_char* arg0, short arg1)
{
    func_8006EBF8_t sp10;
    int temp_s0;
    int temp_s0_2;
    int var_a2;

    temp_s0 = func_800BFE50(func_800BFE00(arg0 + 1));
    func_800A1108(func_800BFE50(func_800BFE00(arg0 + 3)), &sp10);
    var_a2 = -1;
    temp_s0_2 = temp_s0 & 0xFFFF;
    if (arg0[5] != 0xFF) {
        var_a2 = arg0[5];
    }
    func_800A9CDC(temp_s0_2, &sp10.unk0.unk0.fields, var_a2);
    D_800F4B70[temp_s0_2] = 1;
    return 0;
}

int func_800B7F84(u_char* arg0, short arg1)
{
    func_8006EBF8_t_fields sp10;
    int temp_s0 = func_800BFE50(func_800BFE00(arg0 + 1)) & 0xFFFF;

    sp10.unk0_0 = arg0[3];
    sp10.unk0_8 = arg0[4];
    sp10.unk0_16 = arg0[5];

    func_800A9CDC(temp_s0, &sp10, arg0[6] != 0xFF ? arg0[6] : -1);
    D_800F4B70[temp_s0] = 1;
    return 0;
}

int func_800B804C(u_char* arg0, short arg1)
{
    SVECTOR sp10;

    setVector(
        &sp10, func_800BFE00(arg0 + 3), func_800BFE00(arg0 + 5), func_800BFE00(arg0 + 7));
    func_800AABD0(func_800BFE50(func_800BFE00(arg0 + 1)), &sp10, arg0[9]);
    return 0;
}

int func_800B80B4(u_char* arg0, short arg1)
{
    char sp10[24];

    func_800BB68C(func_800BFE00(arg0 + 1), sp10);
    while (1) {
        int temp_a0 = func_800BB788(sp10);
        if (temp_a0 == 1) {
            break;
        }
        func_8007D340(temp_a0);
    }
    return 0;
}

int func_800B810C(u_char* arg0)
{
    short temp_v0;
    u_short temp_s3;
    int temp_s2;
    u_short var_v0;

    temp_s2 = func_800BFE50(func_800BFE00(arg0 + 1)) & 0xFFFF;
    temp_s3 = func_800A0BE0(temp_s2) ^ 0x81;
    temp_v0 = func_800BFE00(arg0 + 3);

    if (temp_v0 & 1) {
        if (func_8007D03C(temp_s2) == 0) {
            temp_s3 |= 1;
        }
    }
    var_v0 = (temp_s3 & temp_v0);
    return var_v0 != 0;
}

int func_800B81A0(u_char* arg0, short arg1)
{
    u_char sp10[4];

    sp10[0] = arg0[3];
    sp10[1] = arg0[4];
    sp10[2] = arg0[5];

    if (sp10[0] | sp10[1] | sp10[2]) {
        func_800A07FC(func_800BFE50(func_800BFE00(arg0 + 1)), &sp10);
    } else {
        func_800A07FC(func_800BFE50(func_800BFE00(arg0 + 1)), 0);
    }
    return 0;
}

int func_800B822C(u_char* arg0)
{
    func_800A01C8(func_800BFE50(func_800BFE00(arg0 + 1)),
        D_800E9B58[arg0[5] >> 6] + arg0[3], arg0[5] & 0x3F, 0);
    return 0;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B8290);

void func_8009FC60(int, int, SVECTOR*, int);

int func_800B8360(u_char* arg0, short arg1)
{
    SVECTOR sp10;
    int temp_v0;
    int var_a3;

    sp10.vx = func_800BFE00(arg0 + 3);
    sp10.vy = func_800BFE00(arg0 + 5);
    sp10.vz = 0;
    temp_v0 = func_800BFE50(func_800BFE00(arg0 + 1));
    var_a3 = 0x1000;
    if (arg0[7] != 0) {
        var_a3 = arg0[7];
    }
    func_8009FC60(temp_v0, -4, &sp10, var_a3);
    return 0;
}

int func_800B83D4(u_char* arg0)
{
    func_800A0618(func_800BFE50(func_800BFE00(arg0 + 1)),
        D_800E9B58[arg0[6] >> 6] + arg0[3], arg0[6] & 0x3F, arg0[4]);
    return 0;
}

int func_800B8438(u_char* arg0)
{
    func_800A01C8(func_800BFE50(func_800BFE00(arg0 + 1)),
        D_800E9B58[arg0[6] >> 6] + arg0[3], arg0[6] & 0x3F, arg0[4]);
    return 0;
}

int func_800B849C(u_char* arg0, short arg1)
{
    int temp_a0 = func_800BFE50(func_800BFE00(arg0 + 1));

    if (arg0[4] == 0xFF) {
        func_8009FBD8(temp_a0, -1);
    } else {
        func_8009FBD8(temp_a0, D_800E9B58[arg0[3]] + arg0[4]);
    }
    return 0;
}

int func_800B8510(u_char* arg0, short arg1)
{
    int var_a3;

    int temp_s0 = func_800BFE50(func_800BFE00(arg0 + 3) & 0xFFFF);
    int temp_a0 = func_800BFE50(func_800BFE00(arg0 + 1) & 0xFFFF);

    int var_a1 = -2;
    if (temp_s0 != 0x2000) {
        var_a1 = temp_s0;
    }

    var_a3 = 0x1000;
    if (arg0[5] != 0) {
        var_a3 = arg0[5];
    }
    func_8009FC60(temp_a0, var_a1, 0, var_a3);
    return 0;
}

int func_800B8590(u_char* arg0, short arg1)
{
    SVECTOR sp10;
    int temp_v0;
    int var_a3;

    setVector(
        &sp10, func_800BFE00(arg0 + 3), func_800BFE00(arg0 + 5), func_800BFE00(arg0 + 7));
    temp_v0 = func_800BFE50(func_800BFE00(arg0 + 1) & 0xFFFF);
    var_a3 = 0x1000;
    if (arg0[9] != 0) {
        var_a3 = arg0[9];
    }
    func_8009FC60(temp_v0, -1, &sp10, var_a3);
    return 0;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B860C);

int func_800B86E8(u_char* arg0, short arg1) { return func_8007CCAC() > 0; }

int func_800B8708(u_char* arg0, short arg1)
{
    if (arg0[1] & 4) {
        func_8007CC4C(arg0[1] & 3);
    } else {
        func_8007CBBC(arg0[1]);
    }
    return (D_800F4C2C == 2) * 4;
}

int func_800B8764(u_char* arg0, short arg1)
{
    func_8007CC6C(arg0[1]);
    return 0;
}

int func_800B8788(u_char* arg0, short arg1)
{
    char sp10[24];

    sp10[0] = arg0[7];
    sp10[1] = arg0[8];
    sp10[2] = arg0[9];

    if (sp10[0] | sp10[1] | sp10[2]) {
        sp10[8] = arg0[3];
        sp10[9] = arg0[4];
        sp10[10] = arg0[5];
        sp10[11] = arg0[6];
        func_8009F940(func_800BFE50(func_800BFE00(arg0 + 1)), 1, (int*)(sp10 + 8), sp10);
    } else {
        func_8009F940(func_800BFE50(func_800BFE00(arg0 + 1)), 0, 0, 0);
    }
    return 0;
}

int func_800B884C(u_char* arg0, short arg1)
{
    char sp10[24];
    int temp_a0;

    func_800BB68C(func_800BFE00(arg0 + 1), sp10);

    while (1) {
        temp_a0 = func_800BB788(sp10) & 0xFFFF;
        if (temp_a0 == 1) {
            break;
        }
        func_8007C0AC(temp_a0, D_800E9B4C[arg0[3]]);
    }
    return 0;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B88D4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B8A10);

int func_800B8B5C(u_char* arg0, short arg1)
{
    return (int)&arg0[func_800BFE00(arg0 + 1)];
}

int func_800B8B90(u_char* arg0, short arg1)
{
    return (int)&arg0[func_800BFE00(arg0 + 1)];
}

int func_800B8BC4(u_char* arg0, short arg1)
{
    D_800F4BB4 = func_800BEBF4(func_800BFE00(arg0 + 1));
    return 0;
}

int func_800B8BF8(u_char* arg0, short arg1)
{
    if (D_800F4BB4 == arg0[1]) {
        return (int)&arg0[func_800BFE00(arg0 + 2)];
    }
    return 0;
}

int func_800B8C44(void) { return D_800F4C64; }

int func_800B8C54(u_char* arg0, short arg1)
{
    if (arg0[1] != 0xFF) {
        D_800F4C10[arg0[1]] = arg0[2];
    }
    return 0;
}

int func_800B8C7C(u_char* arg0, short arg1)
{
    if (arg0[1] == 0xFF) {
        return (int)(arg0 - func_800BFE00(arg0 + 2));
    }
    if (--D_800F4C10[arg0[1]] != 0) {
        return (int)(arg0 - func_800BFE00(arg0 + 2));
    }
    return 0;
}

int func_800B8CE8(u_char* arg0, short arg1)
{
    return (int)&arg0[func_800BFE00(arg0 + 1)];
}

int func_800B8D1C(u_char* arg0, short arg1)
{
    return (int)&arg0[func_800BFE00(arg0 + 1)];
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B8D50);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B8EDC);

int func_800B9170(u_char* arg0, short arg1)
{
    vs_battle_setStateFlag(
        func_800BFE00(arg0 + 3), vs_battle_itemIdIsInInventory(func_800BFE00(arg0 + 1)));
    return 0;
}

int func_800B91C4(u_char* arg0, short arg1)
{
    func_8007BBB8(arg0[2], arg0[1]);
    return 0;
}

int func_800B91F0(u_char* arg0, short arg1)
{
    func_8009DBDC(func_800BFE50(func_800BFE00(arg0 + 1)), arg0[3]);
    return 0;
}

int func_800B9230(u_char* arg0, short arg1)
{
    func_8007D15C(arg0[1]);
    return 0;
}

int func_800B9254(u_char* arg0, short arg1)
{
    short temp_v0 = func_800BFE00(arg0 + 1);
    vs_battle_setStateFlag(temp_v0 & 0x3FF, temp_v0 & 0x8000
                                                ? vs_main_buttonsPressed.pad[0].low
                                                : vs_main_buttonsPreviousState);
    return 0;
}

int func_800B92A0(u_char* arg0, short arg1)
{
    func_8007C28C(func_800BFE50(func_800BFE00(arg0 + 1)));
    return 0;
}

int func_800B92D0(u_char* arg0, short arg1)
{
    func_8007BD8C(arg0[1] ^ 1);
    return 0;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B92F4);

int func_800B94D8(u_char* arg0, short arg1)
{
    if (arg0[1] != 0) {
        func_8007BBD8(D_800E9BF4[arg0[3]], D_800E9BF8[arg0[2]],
            (arg0[4] << 0x18) | (arg0[5] << 0x10) | (arg0[6] << 8));
    } else {
        func_8007BCCC();
    }
    return 0;
}

int func_800B9564(u_char* arg0, short arg1)
{
    D_800F4FE0_t* temp_s1;
    u_short temp_s0;
    int var_a0;

    temp_s0 = func_800BFE00(arg0 + 2);
    temp_s1 = func_800CCDF4(arg0[1] & 0xF);

    if (temp_s0 < 0x2000) {
        var_a0 = func_800BFE50(temp_s0);
    } else {
        var_a0 = 0x20;
    }
    temp_s1->unk0.fields.unk3_0 = var_a0;
    temp_s1->unk2E = arg0[1] >> 4;
    return 0;
}

int func_800B9608(u_char* arg0, short arg1)
{
    u_short temp_a0 = func_800BFE50(func_800BFE00(arg0 + 1));

    if (arg0[3] == 0xFE) {
        func_8007CAA4(temp_a0);
    } else {
        func_8007CA20(temp_a0, arg0[3], arg0[5]);
    }
    return 0;
}

int func_800B9670(u_char* arg0, short arg1)
{
    func_8009D7E8(func_800BFE50(func_800BFE00(arg0 + 1)), arg0[3]);
    return 0;
}

int func_800B96B0(u_char* arg0, short arg1)
{
    if (D_800F4C58[arg1] == 0) {
        D_800F4C58[arg1] = arg0[2];
        return 1;
    }
    if ((vs_main_buttonsPressed.all & arg0[1]) || (--D_800F4C58[arg1] <= 0)) {
        D_800F4C58[arg1] = 0;
        vs_main_buttonsPressed.all = 0;
        return 0;
    }
    return 1;
}

int func_800B9724(u_char* arg0, short arg1)
{
    int var_v1;
    u_char* temp_a1;
    u_short* new_var;

    new_var = D_800F4B28;
    temp_a1 = (u_char*)((arg0[1] >> 6) + new_var);
    temp_a1[0] = ((arg0[1] >> 4) & 3);

    var_v1 = arg0[1] & 7;
    if (arg0[1] & 8) {
        var_v1 |= 0xF8;
    }
    temp_a1[1] = var_v1;
    return 0;
}

int func_800B9770(u_char* arg0, short arg1)
{
    func_8008E224(arg0[1], arg0[2]);
    return 0;
}

int func_800B979C(u_char* arg0, short arg1)
{
    short temp_v0 = func_800BFE00(arg0 + 1);
    D_800F4C6A = (temp_v0 << 0x10) >> 0x1F;
    if (D_800F4C6A) {
        func_80098194(temp_v0 & 0x7FF);
    }
    return 0;
}

int func_800B97E4(u_char* arg0, short arg1)
{
    D_800F19C8 = arg0[1];
    return 0;
}

int func_800B97F8(u_char* arg0, short arg1)
{
    func_8007C31C();
    return 0;
}

int func_800B9818(u_char* arg0, short arg1)
{
    func_80091998(arg0[1]);
    return 0;
}

int func_800B983C(u_char* arg0, short arg1)
{
    func_800919D8(arg0[1]);
    return 0;
}

int func_800B9860(u_char* arg0, short arg1)
{
    func_80091A1C(arg0[1], arg0[2]);
    return 0;
}

int func_800B988C(u_char* arg0, short arg1)
{
    func_8008B808(arg0[1], arg0[3], arg0[2], arg0[4]);
    return 0;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B98C0);

int func_800B9A40(u_char* arg0, short arg1)
{
    int temp_v0 = func_8007C398();
    if (temp_v0 != 5) {
        if (temp_v0 == 0) {
            func_8007C46C(arg0[1], arg0[2], arg0[3] * 0x10);
        }
        return 1;
    }
    return 0;
}

int func_800B9A94(u_char* arg0)
{
    func_8007C4AC(arg0[1], arg0[2], arg0[3] * 0x10);
    return 0;
}

int func_800B9AC4(u_char* arg0, short arg1)
{
    func_8007C460(arg0[1] * 0x10);
    return 0;
}

int func_800B9AE8(u_char* arg0, short arg1)
{
    func_8007C444(arg0[1], arg0[2], arg0[3] * 0x10);
    return 0;
}

int func_800B9B18(u_char* arg0, short arg1)
{
    switch (arg0[1] & 3) {
    case 0:
        func_8007C424();
        break;
    case 1:
        func_8007C404();
        break;
    }

    switch ((arg0[1] >> 2) & 3) {
    case 0:
        func_8007BF4C();
        break;
    case 1:
        func_8007BF2C();
        break;
    }

    switch ((arg0[1] >> 4) & 3) {
    case 0:
        func_8007C050();
        break;
    case 1:
        func_8007BFC0();
        break;
    }
    return 0;
}

int func_800B9BF8(void) { return func_8007C398() != 0; }

int func_800B9C18(u_char* arg0, short arg1)
{
    if (arg0[1] != 0) {
        func_8007B104();
    } else {
        func_8007B0FC();
    }
    return 0;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B9C58);

int func_800B9D74(u_char* arg0, short arg1)
{
    func_800AC37C(func_800BFE50(func_800BFE00(arg0 + 1)), arg0[3]);
    return 0;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B9DB4);

int func_800B9F28(u_char* arg0, short arg1)
{
    func_8008EAF8(arg0[1]);
    return 0;
}

int func_800B9F4C(u_char* arg0, short arg1)
{
    func_8008EFCC(arg0[1]);
    return 0;
}

int func_800B9F70(u_char* arg0, short arg1) { return func_8008F0FC() == 0; }

int func_800B9F90(u_char* arg0, short arg1)
{
    func_8008F234();
    return (D_800F4C2C == 2) * 4;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800B9FC0);

int func_800BA0E4(u_char* arg0, short arg1)
{
    func_80091314(arg0[1] ^ 1);
    return 0;
}

int func_800BA108(u_char* arg0, short arg1)
{
    if (arg0[1] != 0) {
        if (D_800F4C08 != 0) {
            return 0;
        }

        D_800F4C08 = func_8008E470();

        if (D_800F4C08) {
            D_800F4C4C = func_800913BC(-1);
        }

    } else if (D_800F4C08 != 0) {
        func_800913BC(D_800F4C4C);
        D_800F4C08 = 0;
    }

    return 0;
}

int func_800BA194(u_char* arg0, short arg1)
{
    int temp_s0 = arg0[2];

    switch (arg0[1]) {
    case 0:
        if ((D_800F4C2C == 2) && (func_80093764(temp_s0) != 0)) {
            func_80093788(temp_s0);
        }
        func_8009291C(temp_s0);
        break;
    case 1:
        func_800936F8(temp_s0);
        break;
    }
    return 0;
}

int func_800BA218(u_char* arg0, short arg1)
{
    func_80091468(func_800BFE00(arg0 + 1), func_800BFE00(arg0 + 3));
    return 0;
}

int func_800BA264(u_char* arg0, short arg1)
{
    func_8007BDD8(arg0[1] != 0);
    return 0;
}

int func_800BA288(u_char* arg0, short arg1)
{
    func_80091A78(arg0[1], (signed char)arg0[2]);
    return 0;
}

int func_800BA2B4(u_char* arg0, short arg1)
{
    func_8008EAE4((signed char)arg0[1] << 7, (signed char)arg0[2] << 7);
    return 0;
}

int func_800BA2E0(u_char* arg0)
{
    if (arg0[1] == 2 && D_800F4C08 == 0) {
        return 0;
    }
    if (arg0[1] == 2) {
        D_800F4C4C = arg0[2];
    }
    vs_main_playSfx(D_800E9B34[arg0[1]], arg0[2], arg0[3], arg0[4]);
    return 0;
}

int func_800BA35C(u_char* arg0, short arg1)
{
    func_8007C8A4(func_800BFE50(func_800BFE00(arg0 + 1)), arg0[3]);
    return 0;
}

int func_800BA39C(u_char* arg0, short arg1)
{
    func_80045BFC(D_800E9B34[arg0[1]], arg0[2], arg0[3], arg0[4]);
    return 0;
}

int func_800BA3E4(u_char* arg0, short arg1)
{
    func_80045DC0();
    return 0;
}

int func_800BA404(u_char* arg0, short arg1)
{
    func_80045D64(D_800E9B34[arg0[1]], arg0[2]);
    return 0;
}

int func_800BA444(u_char* arg0, short arg1)
{
    vs_main_loadSfxSlot(arg0[1], arg0[2]);
    return 0;
}

int func_800BA470(u_char* arg0, short arg1)
{
    return vs_main_freeSfxQueueSlot(arg0[1]) != 0;
}

int func_800BA494(u_char* arg0, short arg1)
{
    vs_main_freeSfx(arg0[1]);
    return (D_800F4C2C == 2) * 4;
}

int func_800BA4C8(u_char* arg0, short arg1)
{
    vs_main_setCurrentSfx(arg0[1]);
    return 0;
}

int func_800BA4EC(u_char* arg0, short arg1)
{
    short temp_v0 = func_80089104();
    vs_main_loadMusicSlot(temp_v0, 3);
    vs_main_loadSoundFile(temp_v0);
    return 0;
}

int func_800BA52C(u_char* arg0)
{
    func_8004552C(D_800F4C69, 0, arg0[4]);
    func_80044F60(D_800F4C69 = arg0[1], arg0[2], arg0[3]);
    return 0;
}

int func_800BA588(u_char* arg0, short arg1)
{
    vs_main_loadMusicSlot(arg0[1], arg0[2]);
    return 0;
}

int func_800BA5B4(u_char* arg0, short arg1)
{
    vs_main_freeMusic(arg0[1]);
    return (D_800F4C2C == 2) * 4;
}

int func_800BA5E8(u_char* arg0, short arg1)
{
    func_80045000(D_800F4C69 = arg0[1], arg0[2], arg0[3]);
    return 0;
}

int func_800BA61C(u_char* arg0, short arg1)
{
    func_8004552C(D_800F4C69, arg0[1], arg0[2]);
    return 0;
}

int func_800BA650(u_char* arg0, short arg1)
{
    func_80045574(D_800F4C69, (signed char)arg0[1], arg0[2]);
    return 0;
}

int func_800BA684(u_char* arg0, short arg1)
{
    func_800455AC(D_800F4C69, (signed char)arg0[1], arg0[2]);
    return 0;
}

int func_800BA6B8(u_char* arg0, short arg1)
{
    func_80044DF4(D_800F4C69);
    return 0;
}

int func_800BA6E0(u_char* arg0, short arg1)
{
    int temp_s0 = arg0[1];
    if (func_8004550C(temp_s0) != 0) {
        if (func_800454B8(temp_s0) != 0) {
            return 1;
        }
        func_80044DF4(temp_s0);
    }
    return 0;
}

int func_800BA72C(u_char* arg0, short arg1)
{
    func_80044DB4();
    return 0;
}

int func_800BA74C(u_char* arg0, short arg1)
{
    return vs_main_clearMusicLoadSlot(arg0[1]) == 1;
}

int func_800BA774(u_char* arg0, short arg1)
{
    vs_main_loadSoundFile(arg0[1]);
    return 0;
}

int func_800BA798(u_char* arg0, short arg1) { return vs_main_processSoundQueue() == 1; }

int func_800BA7BC(u_char* arg0, short arg1)
{
    int temp_s1 = func_80044D94() >> 0x10;
    return temp_s1 < func_800BFE00(arg0 + 1);
}

int func_800BA800(u_char* arg0, short arg1)
{
    func_80045C74(D_800E9B34[arg0[1]], arg0[2], (signed char)arg0[3], arg0[4]);
    return 0;
}

int func_800BA848(u_char* arg0, short arg1)
{
    func_80045CEC(D_800E9B34[arg0[1]], arg0[2], arg0[3], arg0[4]);
    return 0;
}

int func_800BA890(u_char* arg0, short arg1)
{
    func_80044EC8(D_800F4C69 = arg0[1]);
    return 0;
}

int func_800BA8BC(u_char* arg0, short arg1)
{
    func_8007BE20(func_800BFE00(arg0 + 1), func_800BFE50(func_800BFE00(arg0 + 3)));
    return 0;
}

int func_800BA90C(u_char* arg0, short arg1)
{
    func_8007BEC4(arg0[1]);
    if (D_800F4C2C == 2) {
        func_800CF1A8();
    }
    return 0;
}

int func_800BA94C(u_char* arg0, short arg1)
{
    if ((D_800F4C2C == 2) && ((arg0[1] == 0) || (arg0[1] == 5))) {
        if (D_800F4BB9 != 0) {
            if (func_8007BEE4() == arg0[1]) {
                D_800F4BB9 = 0;
                return 0;
            }
        } else {
            func_800CF1A8();
            D_800F4BB9 = 1;
        }
        return 1;
    }
    return func_8007BEE4() != arg0[1];
}

int func_800BAA04(u_char* arg0, short arg1)
{
    func_8007BF04();
    return (D_800F4C2C == 2) * 4;
}

int func_800BAA34(u_char* arg0, short arg1) { return func_8007BF0C() != 1; }

int func_800BAA58(u_char* arg0, short arg1)
{
    if (D_800F4BB9 == 0) {
        func_800CF1A8();
        D_800F4BB9 = 1;
    } else if ((func_8007BEE4() == 0) || (func_8007BEE4() == 5)) {
        D_800F4BB9 = 0;
        return 0;
    }
    return 1;
}

int func_800BAACC(u_char* arg0, short arg1)
{
    func_800CEF38(arg0[1]);
    return 0;
}

int func_800BAAF0(u_char* arg0, short arg1)
{
    func_80044DD4(arg0[1]);
    return 0;
}

int func_800BAB14(u_char* arg0)
{
    short a0 = arg0[1];
    if (a0 == 0xFF) {
        func_800434A4(0, 2);
    } else {
        if (a0 & 8) {
            vs_main_memcpy(D_800F4C48, D_800F4BC0[a0 & 7], 0x80);
            func_800433B4(D_800F4C48 + 8, 0xFF, 2);
        } else {
            if (D_800F4BC0[a0] != 0) {
                func_800433B4(D_800F4BC0[a0] + 8, 0xFF, 2);
            }
        }
    }
    return 0;
}

int func_800BABCC(u_char* arg0, short arg1)
{
    short temp_v0 = func_800BFE50(func_800BFE00(arg0 + 2));

    if (arg0[1] != 0) {
        func_8006C480(temp_v0, arg0[4]);
    } else {
        func_8006C4A4(temp_v0, arg0[4]);
    }
    return 0;
}

int func_800BAC38(u_char* arg0, short arg1)
{
    vs_battle_setDoorEntered2(arg0[1]);
    return 0;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800BAC5C);

int func_800BAD78(u_char* arg0, short arg1)
{
    char sp10[24];

    func_800BB68C(func_800BFE00(arg0 + 1), sp10);
    while (1) {
        int temp_a0 = func_800BB788(sp10);
        if (temp_a0 == 1) {
            break;
        }
        func_8007D08C(temp_a0, arg0[3]);
    }
    return 0;
}

int func_800BADE0(u_char* arg0)
{
    if (D_800F4BF8 == 0) {
        func_8007BA98(func_800BFE00(arg0 + 1), arg0[3], func_800BFE00(arg0 + 4), arg0[6]);
        D_800F4BF8 = 1;
        return 1;
    }

    if (func_8007B9FC() == 0) {
        D_800F4BF8 = 0;
        return 4;
    }
    return 1;
}

int func_800BAE74(u_char* arg0, short arg1)
{
    func_800CCB9C(func_800BFE00(arg0 + 1));
    return 0;
}

int func_800BAEA0(u_char* arg0, short arg1)
{
    func_8006EBF8_t sp10;
    func_8006EBF8_t sp20;
    short temp_s0;
    int temp_s0_2;
    short temp_s1;
    int var_v0;

    func_800A1108(func_800BFE50(func_800BFE00(arg0 + 1)), &sp10);
    func_800A1108(func_800BFE50(func_800BFE00(arg0 + 3)), &sp20);
    temp_s0 = sp10.unk0.unk4.vx - sp20.unk0.unk4.vx;
    temp_s1 = sp10.unk0.unk4.vz - sp20.unk0.unk4.vz;
    temp_s0_2 = func_800BFE00(arg0 + 5);
    var_v0 = vs_gte_rsqrt((temp_s0 * temp_s0) + (temp_s1 * temp_s1));
    if (var_v0 < 0) {
        var_v0 += 0x7F;
    }
    vs_battle_setStateFlag(temp_s0_2, (var_v0 >> 7) & 0xFF);
    return 0;
}

void func_800BAF6C(short arg0)
{
    short actorId;

    for (actorId = 1; actorId < 17; ++actorId) {
        if (func_8007CF64(actorId) != NULL) {
            if (arg0 != 0) {
                func_800A087C(actorId, func_800A0BE0(actorId) | 1);
            } else {
                func_800A087C(actorId, func_800A0BE0(actorId) & ~1);
            }
        }
    }

    func_8007D15C(arg0);
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800BB028);

int func_800BB288(u_char* arg0, short arg1)
{
    if ((D_800EB9B4 != 0) && ((*D_800EB9B4) != 0)) {
        return 1;
    }
    return 0;
}

int func_800BB2B8(u_char* arg0, short arg1)
{
    func_800F9800(func_800BFE00(arg0 + 1));
    return 0;
}

int func_800BB2E4(u_char* arg0, short arg1)
{
    func_800CB79C();
    return 0;
}

int func_800BB304(u_char* arg0, short arg1) { return 0; }

int func_800BB30C(u_char* arg0, short arg1)
{
    func_800CB7DC();
    return (D_800F4C2C == 2) * 4;
}

int func_800BB33C(u_char* arg0, short arg1)
{
    func_800BE3A0();
    return 0;
}

int func_800BB35C(u_char* arg0, short arg1)
{
    int new_var = arg0[1] & 2;
    func_800BE36C(arg0[1] & 1, new_var != 0);
    return 0;
}

int func_800BB38C(u_char* arg0, short arg1)
{
    func_800BBE10(func_800BFE50(func_800BFE00(arg0 + 1)));
    return 0;
}

int func_800BB3BC(u_char* arg0, short arg1)
{
    func_800BC1CC(
        arg0[1] != 0xFF ? ((arg0[1] + 4) & 7) : -1, arg0[2] != 0 ? arg0[2] : -1);
    D_800F4BB6 = 1;
    return 0;
}

int func_800BB41C(u_char* arg0, short arg1)
{
    return arg0[1] != (arg0[1] & func_800BD610());
}

int func_800BB450(u_char* arg0, short arg1)
{
    func_8007DD50(arg0[1]);
    return 0;
}

int func_800BB474(u_char* arg0, short arg1)
{
    if (D_800F4C58[arg1] == 0) {
        D_800F4C58[arg1] = arg0[1];
        return 1;
    }

    --D_800F4C58[arg1];

    if ((D_800F4C58[arg1] << 0x10) <= 0) {
        D_800F4C58[arg1] = 0;
        return 0;
    }
    return 1;
}

int func_800BB4CC(u_char* arg0, short arg1)
{
    func_8007C36C(arg0[1]);
    return 0;
}

int func_800BB4F0(u_char* arg0, short arg1)
{
    D_800F4BE4 = arg0[1];
    return 0;
}

int func_800BB504(u_char* arg0, short arg1)
{
    u_short temp_a0 = arg0[1] & 3;
    if ((arg0[1] & 0x80)) {
        D_800F4C38[temp_a0] = 0;
        return 0;
    }
    return D_800F4C38[temp_a0] != 0;
}

int func_800BB554(u_char* arg0, short arg1)
{
    D_800F4C38[arg0[1]] = arg0 + 4;
    return (int)&arg0[func_800BFE00(arg0 + 2)];
}

int func_800BB5A4(u_char* arg0, short arg1) { return 3; }

int func_800BB5AC(u_char* arg0, short arg1)
{
    _evtFile = func_800BFE00(arg0 + 1);
    D_800F4C24 = vs_main_allocHeapR(0x1800);
    func_800C00E8(_evtFile, D_800F4C24);
    D_800F4C54 = 1;
    return 0;
}

int func_800BB604(u_char* arg0, short arg1)
{
    int i;
    int var_s1;

    var_s1 = 0;

    for (i = 0; i < 8; ++i) {
        if (func_800CD064(i) != 0) {
            ++var_s1;
        }
    }

    if (var_s1 == 0) {
        func_8007C36C(2);
        return 2;
    }
    return 1;
}

int func_800BB668(u_char* arg0, short arg1)
{
    vs_main_playSfxDefault(0x7E, 5);
    return 0;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800BB68C);

u_short func_800BB788(char* arg0)
{
    if (arg0[0] == 0) {
        return 1;
    }

    --arg0[0];
    return arg0[(u_int)(arg0[1]++ + 2)];
}

int func_800BB7C4(int arg0, SVECTOR* arg1)
{
    MATRIX sp10;
    long sp30[5];

    arg1->vx = 0;
    arg1->vy = -0x3E8;
    arg1->vz = 0;
    func_800A1178(arg0, 1, &sp10, &sp30[2]);
    SetRotMatrix(&sp10);
    SetTransMatrix(&sp10);
    RotTransPers(arg1, sp30, &sp30[3], &sp30[4]);
    func_800A1280(arg0, 1, arg1, sp30[2]);
    arg1->vz = ratan2(((short*)&sp30)[1] - arg1->vy, (short)sp30[0] - arg1->vx);
    return arg1->vz;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800BB874);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800BB9B0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800BBAFC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800BBBE8);

void func_800BBDDC(void) { vs_main_freeHeapR(D_800F4BA4); }

void func_800BBE04(int arg0) { D_800F4BA0 = arg0; }

void func_800BBE10(u_short arg0)
{
    int _[4];
    if (arg0 == 0x2000) {
        if (D_800F4BA4->unk1E8 != arg0) {
            func_800BE628(&D_800F4BA4->unk0[1].unk94, &D_800F4BA4->unk0[1].unk94,
                &D_800F4BA4->unk1EC);
            func_800BE628(&D_800F4BA4->unk0[0].unk94, &D_800F4BA4->unk0[0].unk94,
                &D_800F4BA4->unk1EC);
        }
    }
    D_800F4BA4->unk1E8 = arg0;
    func_800BBE94();
}

void func_800BBE94(void)
{
    func_8006EBF8_t sp10;

    if (D_800F4BA4->unk1E8 == 0x2000) {
        D_800F4BA4->unk1EC.vz = 0;
        D_800F4BA4->unk1EC.vy = 0;
        D_800F4BA4->unk1EC.vx = 0;
        return;
    }
    func_800A1108(D_800F4BA4->unk1E8, &sp10);
    D_800F4BA4->unk1EC.vx = sp10.unk0.unk4.vx * ONE;
    D_800F4BA4->unk1EC.vy = sp10.unk0.unk4.vy * ONE;
    D_800F4BA4->unk1EC.vz = sp10.unk0.unk4.vz * ONE;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800BBF14);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800BC1CC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800BC2E8);

void func_800BC9E0(void)
{
    D_800F4BA4->unk0[1].unkA4.vx = D_800F4BA4->unk0[0].unk94.vx;
    D_800F4BA4->unk0[1].unkA4.vy = D_800F4BA4->unk0[0].unk94.vy;
    D_800F4BA4->unk0[1].unkA4.vz = D_800F4BA4->unk0[0].unk94.vz;
    D_800F4BA4->unk0[0].unkA4.vx = D_800F4BA4->unk0[1].unk94.vx;
    D_800F4BA4->unk0[0].unkA4.vy = D_800F4BA4->unk0[1].unk94.vy;
    D_800F4BA4->unk0[0].unkA4.vz = D_800F4BA4->unk0[1].unk94.vz;
    func_800BCA8C(&D_800F4BA4->unk0[0], &D_800F4BA4->unk0[1]);
    func_800BCA8C(&D_800F4BA4->unk0[1], &D_800F4BA4->unk0[0]);
    func_800BD57C(&D_800F4BA4->unk168);
    func_800BD57C(&D_800F4BA4->unk174);
    func_800BDF6C(&D_800F4BA4->unk180);
    func_800BDF6C(&D_800F4BA4->unk18C);
    func_800BDF6C(&D_800F4BA4->unk198);
    func_800BE180();
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800BCA8C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800BCFB4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800BD2B8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800BD444);

void func_800BD57C(func_800BD57C_t* arg0)
{
    if (arg0->unkA > 0) {
        arg0->unk8 += vs_gametime_tickspeed >> 1;

        arg0->unk2 = (arg0->unk4
                      + ((arg0->unk6 * func_800BFEBC(arg0->unk1, arg0->unk8, arg0->unkA))
                          >> 0xC));

        if (arg0->unk8 >= arg0->unkA) {
            arg0->unkA = 0;
        }
        arg0->unk0 = 1;
    }
}

int func_800BD610(void)
{
    char temp_a2 = D_800F4BA4->unk0[0].unk0 == 0xF;

    if (D_800F4BA4->unk0[1].unk0 == 0xF) {
        temp_a2 = temp_a2 | 2;
    }
    if (D_800F4BA4->unk168.unkA == 0) {
        temp_a2 |= 4;
    }
    if (D_800F4BA4->unk180.unk9 == 0) {
        temp_a2 |= 8;
    }
    if (D_800F4BA4->unk18C.unk9 == 0) {
        temp_a2 |= 0x10;
    }
    if (D_800F4BA4->unk198.unk9 == 0) {
        temp_a2 |= 0x20;
    }
    if (D_800F4BA4->unk27A == 0) {
        temp_a2 |= 0x40;
    }
    if ((D_800F4BA4->unk1A4.unkB + D_800F4BA4->unk1B0.unkB) == 0) {
        temp_a2 |= 0x80;
    }
    return temp_a2;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800BD6C4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800BDAB4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800BDBB4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800BDC9C);

void func_800BDF6C(func_800BDF6C_t* arg0)
{
    if (arg0->unk9 != 0) {
        short* new_var;
        arg0->unk8 += vs_gametime_tickspeed >> 1;
        if (arg0->unk9 < arg0->unk8) {
            arg0->unk8 = arg0->unk9;
        }
        *(int*)0x1F800088 = func_800BFEBC(arg0->unk1, arg0->unk8, arg0->unk9);
        new_var = &arg0->unk6;
        arg0->unk2 = arg0->unk4 + ((*new_var * *(int*)0x1F800088) >> 0xC);
        if (arg0->unk8 == arg0->unk9) {
            arg0->unk9 = 0;
        }
        arg0->unk0 = 1;
    }
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800BE01C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800BE180);

void func_800BE36C(int arg0, int arg1)
{
    D_800F4BA4->unk0[0].unk6 = arg0;
    D_800F4BA4->unk0[0].unk7 = 0;
    D_800F4BA4->unk0[1].unk6 = arg1;
    D_800F4BA4->unk0[1].unk7 = 0;
}

void func_800BE3A0(void)
{
    D_800F4BA4_t* c1 = D_800F4BA4;
    D_800F4BA4_t* c2;
    c1->unk0[1].unk0 = 0xF;
    c1->unk0[0].unk0 = 0xF;
    c2 = D_800F4BA4;
    c2->unk0[1].unk7 = 0;
    c2->unk0[1].unk6 = 0;
    c2->unk0[0].unk7 = 0;
    c2->unk0[0].unk6 = 0;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800BE3D0);

void func_800BE53C(D_800F4BA4_t2* arg0)
{
    VECTOR sp10;

    func_800BE66C(&sp10, &arg0->unk94, &arg0->unk24);
    arg0->unk5 = ((_vectorMagnitude(&sp10) >> 0xC) * arg0->unk5) / 1000;
}

void func_800BE5A4(short arg0)
{
    D_800F4BA4_t2* temp_s0;
    D_800F4BA4_t2* var_a0;
    D_800F4BA4_t2* temp_s1;

    temp_s0 = &D_800F4BA4->unk0[0];
    temp_s1 = &D_800F4BA4->unk0[1];

    if (arg0 == 2) {
        func_800BE53C(temp_s0);
        func_800BE53C(temp_s1);
        temp_s0->unk5 = temp_s1->unk5 = (temp_s0->unk5 + temp_s1->unk5) >> 1;

        return;
    }
    var_a0 = temp_s0;
    if (arg0 != 0) {
        var_a0 = temp_s1;
    }
    func_800BE53C(var_a0);
}

VECTOR* func_800BE628(VECTOR* arg0, VECTOR* arg1, VECTOR* arg2)
{
    setVector(arg0, arg1->vx + arg2->vx, arg1->vy + arg2->vy, arg1->vz + arg2->vz);
    return arg0;
}

VECTOR* func_800BE66C(VECTOR* arg0, VECTOR* arg1, VECTOR* arg2)
{
    setVector(arg0, arg1->vx - arg2->vx, arg1->vy - arg2->vy, arg1->vz - arg2->vz);
    return arg0;
}

VECTOR* func_800BE6B0(VECTOR* arg0, VECTOR* arg1, int arg2)
{
    setVector(arg0, _fixedPointMult(arg1->vx, arg2), _fixedPointMult(arg1->vy, arg2),
        _fixedPointMult(arg1->vz, arg2));
    return arg0;
}

static VECTOR* _copyVector(VECTOR* arg0, VECTOR* arg1)
{
    copyVector(arg0, arg1);
    return arg0;
}

static int _vectorMagnitude(VECTOR* arg0)
{
    VECTOR sp10;
    int temp_lo;
    int temp_lo_2;
    int temp_v0;

    _copyVector(&sp10, arg0);
    temp_lo = (sp10.vx >> 0xC) * (sp10.vx >> 0xC);
    temp_lo_2 = (sp10.vy >> 0xC) * (sp10.vy >> 0xC);
    temp_v0 = (sp10.vz >> 0xC) * (sp10.vz >> 0xC);
    sp10.vx = sp10.vx >> 0xC;
    sp10.vy = sp10.vy >> 0xC;
    sp10.vz = sp10.vz >> 0xC;
    return vs_gte_rsqrt(temp_lo + temp_lo_2 + temp_v0) * ONE;
}

VECTOR* func_800BE7B8(VECTOR* arg0, u_char* arg1)
{
    setVector(arg0, func_800BFE00(arg1) * ONE, func_800BFE00(arg1 + 2) * ONE,
        func_800BFE00(arg1 + 4) * ONE);
    return arg0;
}

static VECTOR* _sVectorToFixedPointVector(VECTOR* arg0, SVECTOR* arg1)
{
    arg0->vx = arg1->vx * ONE;
    arg0->vy = arg1->vy * ONE;
    arg0->vz = arg1->vz * ONE;
    return arg0;
}

static int _fixedPointMult(int a, int b)
{
    int result;
    __asm__("mult       %1, %2;"
            "mflo       $t0;"
            "mfhi       $t1;"
            "srl        $t0, 12;"
            "sll        $t1, 20;"
            "or         %0, $t0, $t1;"
            : "=r"(result)
            : "r"(a), "r"(b));
    return result;
}

int func_800BE878(int arg0, int arg1) { return ratan2(arg0 >> 6, arg1 >> 6); }

void _vecToRotMatrix(VECTOR* arg0, MATRIX* arg1)
{
    SVECTOR sp10;
    SVECTOR sp18;

    sp18.vx = arg0->vx >> 0xC;
    sp18.vy = arg0->vy >> 0xC;
    sp18.vz = arg0->vz >> 0xC;
    sp10.vy = ratan2(sp18.vx, sp18.vz);
    sp10.vx = ratan2(sp18.vy, vs_gte_rsqrt((sp18.vx * sp18.vx) + (sp18.vz * sp18.vz)));
    sp10.vz = 0;
    RotMatrix_gte(&sp10, arg1);
}

static void _toNormalIntegerVector(VECTOR* arg0, VECTOR* arg1)
{
    VECTOR sp10;

    setVector(&sp10, arg0->vx >> 0xC, arg0->vy >> 0xC, arg0->vz >> 0xC);
    VectorNormal(&sp10, arg1);
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800BE98C);

int func_800BEB00(void) { return D_800F4C34; }

short func_800BEB10(void) { return (D_800F4BE0 << 0xC) | _evtFile; }

void func_800BEB34(void)
{
    if (D_800F4BE2 == 3) {
        func_800BFD9C();
    }
    if (D_800F4BAC != 0) {
        vs_main_freeHeap(D_800F4BAC);
    }
    if (D_800F4BE8 != 0) {
        vs_main_freeHeap(D_800F4BE8);
    }
}

void func_800BEB9C(int arg0)
{
    if (arg0 == 0) {
        short i;
        for (i = 64; i < 128; ++i) {
            vs_battle_setStateFlag(i, 0);
        }
    }
}

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

int func_800BEC30(void)
{
    if (D_800F4C34 == 1) {
        D_800F4BB8 = D_800F4C34;
        return 1;
    }
    return 1;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800BEC58);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800BF5F0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/4A0A8", func_800BF850);
