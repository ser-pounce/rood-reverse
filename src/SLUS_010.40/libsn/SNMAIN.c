#include "common.h"

static int _main_called = 0;
static int D_80030FB4 = 0;

static int _execData[] = {
    0x00000000, 0x80010AA4, 0x0001EA90, // .text
    0x8002F534, 0x00004140, // .data
    0x80033680, 0x0000CB28, // .bss
    0x00067350, 0x00450000 // stack ??
};
static int D_80033678[2];

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libsn/SNMAIN", __SN_ENTRY_POINT);

void __main()
{
    __asm__(";"
            "lw         $t0, _main_called;"
            "addu       $sp, -0x10;"
            "sw         $s0, 0x4($sp);"
            "sw         $s1, 0x8($sp);"
            "sw         $ra, 0xC($sp);"
            "bnez       $t0, 1f;"
            "ori        $t0, $zero, 0x1;"
            "sw         $t0, _main_called;"
            "la         $s0, _exec_start;"
            "la         $s1, _globalCtorCount;"
            "beqz       $s1, 1f;"
            ".nop;"
            "0:"
            "lw         $t0, 0x0($s0);"
            "addu       $s0, 0x4;"
            "jal        $t0;"
            "addu       $s1, -0x1;"
            "bnez       $s1, 0b;"
            ".nop;"
            "1:"
            "lw         $ra, 0xC($sp);"
            "lw         $s1, 0x8($sp);"
            "lw         $s0, 0x4($sp);"
            "addu       $sp, 0x10;");
}

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libsn/SNMAIN", __do_global_dtors);
