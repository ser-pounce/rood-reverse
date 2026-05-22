nonmatching func_8002EEF8, 0x2C

glabel func_8002EEF8
    /* 1F6F8 8002EEF8 0A006F94 */  lhu        $t7, 0xA($v1)
    /* 1F6FC 8002EEFC 0000083C */  lui        $t0, (0x0 >> 16)
    /* 1F700 8002EF00 25C0E201 */  or         $t8, $t7, $v0
    /* 1F704 8002EF04 12001937 */  ori        $t9, $t8, 0x12
    /* 1F708 8002EF08 0A0079A4 */  sh         $t9, 0xA($v1)
    /* 1F70C 8002EF0C 28000824 */  addiu      $t0, $zero, 0x28
  .L8002EF10:
    /* 1F710 8002EF10 FFFF0825 */  addiu      $t0, $t0, -0x1
    /* 1F714 8002EF14 FEFF0015 */  bnez       $t0, .L8002EF10
    /* 1F718 8002EF18 00000000 */   nop
    /* 1F71C 8002EF1C 0800E003 */  jr         $ra
    /* 1F720 8002EF20 00000000 */   nop
endlabel func_8002EEF8
