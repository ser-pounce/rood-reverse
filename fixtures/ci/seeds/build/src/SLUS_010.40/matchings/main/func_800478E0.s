nonmatching func_800478E0, 0x30

glabel func_800478E0
    /* 380E0 800478E0 0580023C */  lui        $v0, %hi(_clutState + 0x2)
    /* 380E4 800478E4 5A5D4294 */  lhu        $v0, %lo(_clutState + 0x2)($v0)
    /* 380E8 800478E8 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 380EC 800478EC 04004010 */  beqz       $v0, .L80047900
    /* 380F0 800478F0 1800BFAF */   sw        $ra, 0x18($sp)
    /* 380F4 800478F4 3000A28F */  lw         $v0, 0x30($sp)
    /* 380F8 800478F8 371D010C */  jal        func_800474DC
    /* 380FC 800478FC 1000A2AF */   sw        $v0, 0x10($sp)
  .L80047900:
    /* 38100 80047900 1800BF8F */  lw         $ra, 0x18($sp)
    /* 38104 80047904 00000000 */  nop
    /* 38108 80047908 0800E003 */  jr         $ra
    /* 3810C 8004790C 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_800478E0
