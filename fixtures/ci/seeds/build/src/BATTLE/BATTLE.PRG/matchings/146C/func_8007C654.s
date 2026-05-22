nonmatching func_8007C654, 0x40

glabel func_8007C654
    /* 13E54 8007C654 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 13E58 8007C658 2000BFAF */  sw         $ra, 0x20($sp)
    /* 13E5C 8007C65C 70F1010C */  jal        func_8007C5C0
    /* 13E60 8007C660 00000000 */   nop
    /* 13E64 8007C664 21200000 */  addu       $a0, $zero, $zero
    /* 13E68 8007C668 4284020C */  jal        func_800A1108
    /* 13E6C 8007C66C 1000A527 */   addiu     $a1, $sp, 0x10
    /* 13E70 8007C670 1000A493 */  lbu        $a0, 0x10($sp)
    /* 13E74 8007C674 1200A593 */  lbu        $a1, 0x12($sp)
    /* 13E78 8007C678 1100A693 */  lbu        $a2, 0x11($sp)
    /* 13E7C 8007C67C 582E020C */  jal        func_8008B960
    /* 13E80 8007C680 00000000 */   nop
    /* 13E84 8007C684 2000BF8F */  lw         $ra, 0x20($sp)
    /* 13E88 8007C688 00000000 */  nop
    /* 13E8C 8007C68C 0800E003 */  jr         $ra
    /* 13E90 8007C690 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_8007C654
