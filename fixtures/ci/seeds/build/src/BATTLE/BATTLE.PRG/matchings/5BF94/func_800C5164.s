nonmatching func_800C5164, 0x28

glabel func_800C5164
    /* 5C964 800C5164 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 5C968 800C5168 F0008230 */  andi       $v0, $a0, 0xF0
    /* 5C96C 800C516C 03004014 */  bnez       $v0, .L800C517C
    /* 5C970 800C5170 1000BFAF */   sw        $ra, 0x10($sp)
    /* 5C974 800C5174 577F020C */  jal        func_8009FD5C
    /* 5C978 800C5178 00000000 */   nop
  .L800C517C:
    /* 5C97C 800C517C 1000BF8F */  lw         $ra, 0x10($sp)
    /* 5C980 800C5180 00000000 */  nop
    /* 5C984 800C5184 0800E003 */  jr         $ra
    /* 5C988 800C5188 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800C5164
