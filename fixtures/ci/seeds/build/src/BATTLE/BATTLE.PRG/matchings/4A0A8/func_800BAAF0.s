nonmatching func_800BAAF0, 0x24

glabel func_800BAAF0
    /* 522F0 800BAAF0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 522F4 800BAAF4 1000BFAF */  sw         $ra, 0x10($sp)
    /* 522F8 800BAAF8 01008490 */  lbu        $a0, 0x1($a0)
    /* 522FC 800BAAFC 7513010C */  jal        func_80044DD4
    /* 52300 800BAB00 00000000 */   nop
    /* 52304 800BAB04 1000BF8F */  lw         $ra, 0x10($sp)
    /* 52308 800BAB08 21100000 */  addu       $v0, $zero, $zero
    /* 5230C 800BAB0C 0800E003 */  jr         $ra
    /* 52310 800BAB10 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800BAAF0
