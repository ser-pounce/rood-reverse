#include "common.h"
#include <libpress.h>
#include <libetc.h>
#include <stdio.h>

void func_80072050(int);
void func_80072140(u_long* arg0, u_int arg1);
void func_800721D0(u_long* buf, int size);
int func_8007225C(void);
int func_800722F0(void);
u_int func_80072384(void);
int DMACallback(int, void (*)(void));

// Commented out functions have delay slot manipulation, probably due to custom linkage
// used in later PSY-Q versions

/*void DecDCTReset(int mode) {
    if (mode == 0) {
        ResetCallback();
    }
    func_80072050(mode);
}*/

__asm__(".set push;"
        ".set noreorder;"
        "glabel DecDCTReset;"
        "addu    $sp, -0x18;"
        "sw      $s0, 0x10($sp);"
        "addu    $s0, $a0, $zero;"
        "bnez    $s0, 0f;"
        "sw      $ra, 0x14($sp);"
        "jal     ResetCallback;"
        "nop;"
        "0:"
        "jal     func_80072050;"
        "addu    $a0, $s0, $zero;"
        "lw      $ra, 0x14($sp);"
        "lw      $s0, 0x10($sp);"
        "j       $ra;"
        "addu    $sp, 0x18;"
        "endlabel DecDCTReset;"
        ".set pop;");

static int D_80075B44 = 0x40000001;
static char D_80075B48[] = { 0x02, 0x10, 0x10, 0x13, 0x10, 0x13, 0x16, 0x16, 0x16, 0x16,
    0x16, 0x16, 0x1A, 0x18, 0x1A, 0x1B, 0x1B, 0x1B, 0x1A, 0x1A, 0x1A, 0x1A, 0x1B, 0x1B,
    0x1B, 0x1D, 0x1D, 0x1D, 0x22, 0x22, 0x22, 0x1D, 0x1D, 0x1D, 0x1B, 0x1B, 0x1D, 0x1D,
    0x20, 0x20, 0x22, 0x22, 0x25, 0x26, 0x25, 0x23, 0x23, 0x22, 0x23, 0x26, 0x26, 0x28,
    0x28, 0x28, 0x30, 0x30, 0x2E, 0x2E, 0x38, 0x38, 0x3A, 0x45, 0x45, 0x53 };
static char D_80075B88[] = { 0x02, 0x10, 0x10, 0x13, 0x10, 0x13, 0x16, 0x16, 0x16, 0x16,
    0x16, 0x16, 0x1A, 0x18, 0x1A, 0x1B, 0x1B, 0x1B, 0x1A, 0x1A, 0x1A, 0x1A, 0x1B, 0x1B,
    0x1B, 0x1D, 0x1D, 0x1D, 0x22, 0x22, 0x22, 0x1D, 0x1D, 0x1D, 0x1B, 0x1B, 0x1D, 0x1D,
    0x20, 0x20, 0x22, 0x22, 0x25, 0x26, 0x25, 0x23, 0x23, 0x22, 0x23, 0x26, 0x26, 0x28,
    0x28, 0x28, 0x30, 0x30, 0x2E, 0x2E, 0x38, 0x38, 0x3A, 0x45, 0x45, 0x53 };
static int D_80075BC8 = 0x60000000;

DECDCTENV* DecDCTGetEnv(DECDCTENV* env)
{
    static short D_80075BCC[] = { 0x5A82, 0x5A82, 0x5A82, 0x5A82, 0x5A82, 0x5A82, 0x5A82,
        0x5A82, 0x7D8A, 0x6A6D, 0x471C, 0x18F8, 0xE707, 0xB8E3, 0x9592, 0x8275, 0x7641,
        0x30FB, 0xCF04, 0x89BE, 0x89BE, 0xCF04, 0x30FB, 0x7641, 0x6A6D, 0xE707, 0x8275,
        0xB8E3, 0x471C, 0x7D8A, 0x18F8, 0x9592, 0x5A82, 0xA57D, 0xA57D, 0x5A82, 0x5A82,
        0xA57D, 0xA57D, 0x5A82, 0x471C, 0x8275, 0x18F8, 0x6A6D, 0x9592, 0xE707, 0x7D8A,
        0xB8E3, 0x30FB, 0x89BE, 0x7641, 0xCF04, 0xCF04, 0x7641, 0x89BE, 0x30FB, 0x18F8,
        0xB8E3, 0x6A6D, 0x8275, 0x7D8A, 0x9592, 0x471C, 0xE707, 0x7350, 0x000E, 0x0000,
        0x0045 };

    int* var_a2;
    int i;
    int* var_a1;

    var_a2 = (int*)env->iq_y;
    var_a1 = (int*)D_80075B48;
    for (i = 15; i != -1; --i) {
        *var_a2++ = *var_a1++;
    }
    var_a2 = (int*)env->iq_c;
    var_a1 = (int*)D_80075B88;
    for (i = 15; i != -1; --i) {
        *var_a2++ = *var_a1++;
    }
    var_a2 = (int*)env->dct;
    var_a1 = (int*)D_80075BCC;
    for (i = 31; i != -1; --i) {
        *var_a2++ = *var_a1++;
    }
    return env;
}

/*DECDCTENV* DecDCTPutEnv(DECDCTENV* arg0) {
    int i;
    int *src1, *dst1;
    int *src2, *dst2;

    dst1 = D_80075B48;
    src1 = (int*)&arg0->iq_y;
    for (i = 15; i != -1; i--) {
        *dst1++ = *src1++;
    }

    dst2 = D_80075B88;
    src2 = (int*)&arg0->iq_c;
    for (i = 15; i != -1; i--) {
        *dst2++ = *src2++;
    }

    func_80072140(D_80075B44, 32);
    func_80072140(D_80075BC8, 32);

    return arg0;
}*/

__asm__(".set push;"
        ".set noreorder;"
        "glabel DecDCTPutEnv;"
        "addu     $sp, -0x18;"
        "sw       $s0, 0x10($sp);"
        "addu     $s0, $a0, $zero;"
        "lui      $a1, %hi(D_80075B48);"
        "addiu    $a1, %lo(D_80075B48);"
        "addu     $v1, $zero, 0xF;"
        "addu     $a2, $zero, -0x1;"
        "sw       $ra, 0x14($sp);"
        "0:"
        "lw       $v0, 0x0($a0);"
        "addu     $a0, 4;"
        "addu     $v1, -0x1;"
        "sw       $v0, 0x0($a1);"
        "bne      $v1, $a2, 0b;"
        "addu     $a1, 4;"
        "lui      $a1, %hi(D_80075B88);"
        "addiu    $a1, %lo(D_80075B88);"
        "addu     $a0, $s0, 64;"
        "li       $v1, 15;"
        "li       $a2, -1;"
        "1:"
        "lw       $v0, 0x0($a0);"
        "addu     $a0, 4;"
        "addu     $v1, -1;"
        "sw       $v0, 0x0($a1);"
        "bne      $v1, $a2, 1b;"
        "addu     $a1, 4;"
        "lui      $a0, %hi(D_80075B44);"
        "addiu    $a0, %lo(D_80075B44);"
        "jal      func_80072140;"
        "li       $a1, 32;"
        "lui      $a0, %hi(D_80075BC8);"
        "addiu    $a0, %lo(D_80075BC8);"
        "jal      func_80072140;"
        "li       $a1,32;"
        "addu     $v0, $s0, $zero;"
        "lw       $ra, 0x14($sp);"
        "lw       $s0, 0x10($sp);"
        "j        $ra;"
        "addu     $sp, 0x18;"
        "endlabel DecDCTPutEnv;"
        ".set pop;");

void DecDCTin(u_long* buf, int mode)
{
    if (mode & 1) {
        *buf &= 0xF7FFFFFF;
    } else {
        *buf |= 0x08000000;
    }

    if (mode & 2) {
        *buf |= 0x02000000;
    } else {
        *buf &= 0xFDFFFFFF;
    }

    func_80072140(buf, (u_short)*buf);
}

void DecDCTout(u_long* buf, int size) { func_800721D0(buf, size); }

int DecDCTinSync(int mode)
{
    if (mode != 0) {
        return (func_80072384() >> 0x1D) & 1;
    }
    return func_8007225C();
}

int DecDCToutSync(int mode)
{
    if (mode != 0) {
        return (func_80072384() >> 0x18) & 1;
    }
    return func_800722F0();
}

int DecDCTinCallback(void (*func)(void)) { return DMACallback(0, func); }

int DecDCToutCallback(void (*func)(void)) { return DMACallback(1, func); }

static u_int volatile* D_80075C54 = (u_int volatile*)0x1F801080;
static u_int volatile* D_80075C58 = (u_int volatile*)0x1F801084;
static u_int volatile* D_80075C5C = (u_int volatile*)0x1F801088;
static u_int volatile* D_80075C60 = (u_int volatile*)0x1F801090;
static u_int volatile* D_80075C64 = (u_int volatile*)0x1F801094;

static u_int volatile* D_80075C68[] = { (u_int volatile*)0x1F801098,
    (u_int volatile*)0x1F8010A0, (u_int volatile*)0x1F8010A4, (u_int volatile*)0x1F8010A8,
    (u_int volatile*)0x1F8010B0, (u_int volatile*)0x1F8010B4,
    (u_int volatile*)0x1F8010B8 };

/*extern int* D_80075C5C;
extern int volatile* D_80075C68;
extern int * D_80075C88;

void func_80072050(int arg0) {
    switch (arg0) {
    case 0:
        *D_80075C88 = 0x80000000;
        *D_80075C5C = 0;
        *D_80075C68 = 0;
        *D_80075C88 = 0x60000000;
        func_80072140(D_80075B44, 32);
        func_80072140(D_80075BC8, 32);
        return;
    case 1:
        *D_80075C88 = 0x80000000;
        *D_80075C5C = 0;
        *D_80075C68 = 0;
        *D_80075C68;
        *D_80075C88 = 0x60000000;
        return;
    default:
        printf("MDEC_rest:bad option(%d)\n", arg0);
        return;
    }
}
*/

static char const D_800689DC[] = "MDEC_rest:bad option(%d)\n";

__asm__(".section .text;"
        ".set push;"
        ".set noreorder;"
        "glabel func_80072050;"
        "addu     $sp, -0x18;"
        "addu     $a1, $a0, $zero;"
        "beqz     $a1, 0f;"
        "sw       $ra, 0x10($sp);"
        "addu     $v0, $zero, 0x1;"
        "beq      $a1, $v0, 1f;"
        "lui      $v0, (0x8000);"
        "j        2f;"
        "nop;"
        "0:"
        "lui      $v1, %hi(D_80075C88);"
        "lw       $v1, %lo(D_80075C88)($v1);"
        "lui      $v0, (0x8000);"
        "sw       $v0, 0x0($v1);"
        "lui      $v0, %hi(D_80075C5C);"
        "lw       $v0, %lo(D_80075C5C)($v0);"
        "lui      $a0, %hi(D_80075B44);"
        "addiu    $a0, %lo(D_80075B44);"
        "sw       $zero, 0x0($v0);"
        "lui      $v0, %hi(D_80075C68);"
        "lw       $v0, %lo(D_80075C68)($v0);"
        "addu     $a1, $zero, 0x20;"
        "sw       $zero, 0x0($v0);"
        "lui      $v1, %hi(D_80075C88);"
        "lw       $v1, %lo(D_80075C88)($v1);"
        "lui      $v0, (0x6000);"
        "jal      func_80072140;"
        "sw       $v0, 0x0($v1);"
        "lui      $a0, %hi(D_80075BC8);"
        "addiu    $a0, %lo(D_80075BC8);"
        "jal      func_80072140;"
        "addiu    $a1, $zero, 0x20;"
        "j        3f;"
        "nop;"
        "1:"
        "lui      $v1, %hi(D_80075C88);"
        "lw       $v1, %lo(D_80075C88)($v1);"
        "nop;"
        "sw       $v0, 0x0($v1);"
        "lui      $v0, %hi(D_80075C5C);"
        "lw       $v0, %lo(D_80075C5C)($v0);"
        "nop;"
        "sw       $zero, 0x0($v0);"
        "lui      $v0, %hi(D_80075C68);"
        "lw       $v0, %lo(D_80075C68)($v0);"
        "nop;"
        "sw       $zero, 0x0($v0);"
        "lui      $v0, %hi(D_80075C68);"
        "lw       $v0, %lo(D_80075C68)($v0);"
        "lui      $v1, %hi(D_80075C88);"
        "lw       $v1, %lo(D_80075C88)($v1);"
        "lw       $v0, 0x0($v0);"
        "lui      $v0, (0x6000);"
        "j        3f;"
        "sw       $v0, 0x0($v1);"
        "2:"
        "lui      $a0, %hi(D_800689DC);"
        "jal      printf;"
        "addiu    $a0, %lo(D_800689DC);"
        "3:"
        "lw       $ra, 0x10($sp);"
        "addu     $sp, 0x18;"
        "j        $ra;"
        "nop;"
        "endlabel func_80072050;"
        ".set pop;");

static u_int volatile* D_80075C84 = (u_int volatile*)0x1F801820;
static u_int volatile* D_80075C88 = (u_int volatile*)0x1F801824;
static u_int volatile* D_80075C8C = (u_int volatile*)0x1F8010F0;

/*extern int** D_80075C54;
extern int* D_80075C58;
extern int* D_80075C5C;
extern int* D_80075C84;
extern int* D_80075C8C;

void func_80072140(int* arg0, u_int arg1) {
    func_8007225C();
    *D_80075C8C |= 0x88;
    *D_80075C54 = arg0 + 1;
    *D_80075C58 = ((arg1 >> 5) << 0x10) | 0x20;
    *D_80075C84 = *arg0;
    *D_80075C5C = 0x01000201;
}
*/

__asm__(".section .text;"
        ".set push;"
        ".set noreorder;"
        "glabel func_80072140;"
        "addu     $sp, -0x20;"
        "sw       $s1, 0x14($sp);"
        "addu     $s1, $a0, $zero;"
        "sw       $s0, 0x10($sp);"
        "sw       $ra, 0x18($sp);"
        "jal      func_8007225C;"
        "addu     $s0, $a1, $zero;"
        "lui      $v1, %hi(D_80075C8C);"
        "lw       $v1, %lo(D_80075C8C)($v1);"
        "srl      $s0, 5;"
        "lw       $v0, 0x0($v1);"
        "sll      $s0, 16;"
        "or       $v0, 0x88;"
        "sw       $v0, 0x0($v1);"
        "lui      $v1, %hi(D_80075C54);"
        "lw       $v1, %lo(D_80075C54)($v1);"
        "addu     $v0, $s1, 0x4;"
        "sw       $v0, 0x0($v1);"
        "lui      $v0, %hi(D_80075C58);"
        "lw       $v0, %lo(D_80075C58)($v0);"
        "or       $s0, 0x20;"
        "sw       $s0, 0x0($v0);"
        "lui      $v1, %hi(D_80075C84);"
        "lw       $v1, %lo(D_80075C84)($v1);"
        "lw       $v0, 0x0($s1);"
        "lui      $a0, (0x100);"
        "sw       $v0, 0x0($v1);"
        "lui      $v0, %hi(D_80075C5C);"
        "lw       $v0, %lo(D_80075C5C)($v0);"
        "or       $a0, (0x0201);"
        "sw       $a0, 0x0($v0);"
        "lw       $ra, 0x18($sp);"
        "lw       $s1, 0x14($sp);"
        "lw       $s0, 0x10($sp);"
        "j        $ra;"
        "addu     $sp, 0x20;"
        "endlabel func_80072140;"
        ".set pop;");

/*extern int* D_80075C60;
extern int* D_80075C64;
extern int* D_80075C68;
extern int* D_80075C8C;

void func_800721D0(int arg0, u_int arg1) {
    func_800722F0();
    *D_80075C8C |= 0x88;
    *D_80075C68 = 0;
    *D_80075C60 = arg0;
    *D_80075C64 = ((arg1 >> 5) << 0x10) | 0x20;
    *D_80075C68 = 0x01000200;
}
*/

__asm__(".set push;"
        ".set noreorder;"
        "glabel func_800721D0;"
        "addu     $sp, -0x20;"
        "sw       $s1, 0x14($sp);"
        "addu     $s1, $a0, $zero;"
        "sw       $s0, 0x10($sp);"
        "sw       $ra, 0x18($sp);"
        "jal      func_800722F0;"
        "addu     $s0, $a1, $zero;"
        "lui      $v1, %hi(D_80075C8C);"
        "lw       $v1, %lo(D_80075C8C)($v1);"
        "nop;"
        "lw       $v0, 0x0($v1);"
        "srl      $s0, 5;"
        "or       $v0, 0x88;"
        "sw       $v0, 0x0($v1);"
        "lui      $v0, %hi(D_80075C68);"
        "lw       $v0, %lo(D_80075C68)($v0);"
        "sll      $s0, 16;"
        "sw       $zero, 0x0($v0);"
        "lui      $v0, %hi(D_80075C60);"
        "lw       $v0, %lo(D_80075C60)($v0);"
        "or       $s0, 0x20;"
        "sw       $s1, 0x0($v0);"
        "lui      $v0, %hi(D_80075C64);"
        "lw       $v0, %lo(D_80075C64)($v0);"
        "lui      $v1, (0x100);"
        "sw       $s0, 0x0($v0);"
        "lui      $v0, %hi(D_80075C68);"
        "lw       $v0, %lo(D_80075C68)($v0);"
        "or       $v1, (0x0200);"
        "sw       $v1, 0x0($v0);"
        "lw       $ra, 0x18($sp);"
        "lw       $s1, 0x14($sp);"
        "lw       $s0, 0x10($sp);"
        "j        $ra;"
        "addu     $sp, 0x20;"
        "endlabel func_800721D0;"
        ".set pop;");

/*void func_8007239C(signed char const*);
extern int* D_80075C88;

int func_8007225C(void) {
    volatile int sp10;

    sp10 = 0x100000;
    while (*D_80075C88 & 0x20000000) {
        if (--sp10 == -1) {
            func_8007239C("MDEC_in_sync");
            return -1;
        }
    }
    return 0;
}
*/

static char const D_800689F8[] = "MDEC_in_sync";

__asm__(".section .text;"
        ".set push;"
        "glabel func_8007225C;"
        ".set noreorder;"
        "addu      $sp, -0x20;"
        "lui       $v1, %hi(D_80075C88);"
        "lw        $v1, %lo(D_80075C88)($v1);"
        "lui       $v0, (0x10);"
        "sw        $ra, 0x18($sp);"
        "sw        $v0, 0x10($sp);"
        "lw        $v0, 0x0($v1);"
        "lui       $v1, (0x2000);"
        "and       $v0, $v1;"
        "beqz      $v0, 2f;"
        "addu      $v0, $zero, $zero;"
        "li        $a0, -1;"
        "0:"
        "lw        $v0, 0x10($sp);"
        "nop;"
        "addu      $v0, -1;"
        "sw        $v0, 0x10($sp);"
        "lw        $v0, 0x10($sp);"
        "nop;"
        "bne       $v0, $a0, 1f;"
        "nop;"
        "lui       $a0, %hi(D_800689F8);"
        "jal       func_8007239C;"
        "addiu     $a0, %lo(D_800689F8);"
        "j         2f;"
        "li        $v0, -1;"
        "1:"
        "lui       $v0, %hi(D_80075C88);"
        "lw        $v0, %lo(D_80075C88)($v0);"
        "nop;"
        "lw        $v0, 0x0($v0);"
        "nop;"
        "and       $v0, $v1;"
        "bnez      $v0, 0b;"
        "addu      $v0, $zero, $zero;"
        "2:"
        "lw        $ra, 0x18($sp);"
        "addu      $sp, 0x20;"
        "j         $ra;"
        "nop;"
        "endlabel func_8007225C;"
        ".set pop;");

INCLUDE_ASM("build/src/TITLE/TITLE.PRG/nonmatchings/libpress/LIBPRESS", func_800722F0);
/*void func_8007239C(signed char const*);
extern int* D_80075C68;

int func_800722F0(void) {
    volatile int sp10;

    sp10 = 0x100000;
    while (*D_80075C68 & 0x01000000) {
        if (--sp10 == -1) {
            func_8007239C("MDEC_out_sync");
            return -1;
        }
    }
    return 0;
}
*/

u_int func_80072384(void) { return *D_80075C88; }

int func_8007239C(char* arg0)
{
    printf("%s timeout:\n", arg0);
    *D_80075C88 = 0x80000000;
    *D_80075C5C = 0;
    *D_80075C68[0] = 0;
    *D_80075C68[0];
    *D_80075C88 = 0x60000000;
    return 0;
}

static const char _[4] = { 0 };