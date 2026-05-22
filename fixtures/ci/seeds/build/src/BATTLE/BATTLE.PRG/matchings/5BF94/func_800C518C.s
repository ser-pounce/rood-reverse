nonmatching func_800C518C, 0x28

glabel func_800C518C
    /* 5C98C 800C518C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 5C990 800C5190 F0008230 */  andi       $v0, $a0, 0xF0
    /* 5C994 800C5194 03004014 */  bnez       $v0, .L800C51A4
    /* 5C998 800C5198 1000BFAF */   sw        $ra, 0x10($sp)
    /* 5C99C 800C519C FF81020C */  jal        func_800A07FC
    /* 5C9A0 800C51A0 00000000 */   nop
  .L800C51A4:
    /* 5C9A4 800C51A4 1000BF8F */  lw         $ra, 0x10($sp)
    /* 5C9A8 800C51A8 00000000 */  nop
    /* 5C9AC 800C51AC 0800E003 */  jr         $ra
    /* 5C9B0 800C51B0 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800C518C
