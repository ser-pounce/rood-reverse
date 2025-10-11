#include "common.h"
#include <malloc.h>

static int __initialised = 0;
static u_long* __heapbase = NULL;
static int __heapsize = 0;
static int __text = 0x80010AA4;
static int __textlen = 0x0001EA90;
static int __data = 0x8002F534;
static int __datalen = 0x00004140;
static int __bss = 0x80033680;
static int __bsslen = 0x0000CB28;
static int _[] = {
    0x00067350, 0x00450000 //  ??
};
__asm__(".pushsection .sbss;"
        "__ra_temp:;"
        ".size __ra_temp, 4;"
        ".space 8;"
        ".popsection");

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libsn/SNMAIN", __SN_ENTRY_POINT);

void __main(void)
{
    __asm__(";"
            "lw         $t0, __initialised;"
            "addu       $sp, -0x10;"
            "sw         $s0, 0x4($sp);"
            "sw         $s1, 0x8($sp);"
            "sw         $ra, 0xC($sp);"
            "bnez       $t0, 1f;"
            "ori        $t0, $zero, 0x1;"
            "sw         $t0, __initialised;"
            "la         $s0, .ctors;"
            "la         $s1, __nCtors;"
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
