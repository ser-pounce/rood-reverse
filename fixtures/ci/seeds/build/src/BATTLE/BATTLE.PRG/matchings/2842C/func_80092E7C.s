nonmatching func_80092E7C, 0x60

glabel func_80092E7C
    /* 2A67C 80092E7C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 2A680 80092E80 1000BFAF */  sw         $ra, 0x10($sp)
    /* 2A684 80092E84 0400A28C */  lw         $v0, 0x4($a1)
    /* 2A688 80092E88 00000000 */  nop
    /* 2A68C 80092E8C 0C0082AC */  sw         $v0, 0xC($a0)
    /* 2A690 80092E90 0800A28C */  lw         $v0, 0x8($a1)
    /* 2A694 80092E94 00000000 */  nop
    /* 2A698 80092E98 100082AC */  sw         $v0, 0x10($a0)
    /* 2A69C 80092E9C 0C00A28C */  lw         $v0, 0xC($a1)
    /* 2A6A0 80092EA0 00000000 */  nop
    /* 2A6A4 80092EA4 140082AC */  sw         $v0, 0x14($a0)
    /* 2A6A8 80092EA8 1000A294 */  lhu        $v0, 0x10($a1)
    /* 2A6AC 80092EAC 00000000 */  nop
    /* 2A6B0 80092EB0 1C0082A4 */  sh         $v0, 0x1C($a0)
    /* 2A6B4 80092EB4 1400A294 */  lhu        $v0, 0x14($a1)
    /* 2A6B8 80092EB8 00000000 */  nop
    /* 2A6BC 80092EBC 1E0082A4 */  sh         $v0, 0x1E($a0)
    /* 2A6C0 80092EC0 1800A294 */  lhu        $v0, 0x18($a1)
    /* 2A6C4 80092EC4 B74B020C */  jal        func_80092EDC
    /* 2A6C8 80092EC8 200082A4 */   sh        $v0, 0x20($a0)
    /* 2A6CC 80092ECC 1000BF8F */  lw         $ra, 0x10($sp)
    /* 2A6D0 80092ED0 21100000 */  addu       $v0, $zero, $zero
    /* 2A6D4 80092ED4 0800E003 */  jr         $ra
    /* 2A6D8 80092ED8 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80092E7C
