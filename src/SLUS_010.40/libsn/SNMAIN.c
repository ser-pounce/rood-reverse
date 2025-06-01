#include "common.h"

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libsn/SNMAIN", __SN_ENTRY_POINT);

extern int D_80030FB0;
extern void (*vs_overlay_slots)();

void __main()
{
    __asm__(";"
            "lw         $t0, D_80030FB0;"
            "addu       $sp, -0x10;"
            "sw         $s0, 0x4($sp);"
            "sw         $s1, 0x8($sp);"
            "sw         $ra, 0xC($sp);"
            "bnez       $t0, 1f;"
            "ori        $t0, $zero, 0x1;"
            "sw         $t0, D_80030FB0;"
            "la         $s0, _exec_start;"
            "la         $s1, _main_patch;"
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
