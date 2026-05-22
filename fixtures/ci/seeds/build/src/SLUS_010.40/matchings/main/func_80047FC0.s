nonmatching func_80047FC0, 0x3C

glabel func_80047FC0
    /* 387C0 80047FC0 0580023C */  lui        $v0, %hi(_clutState + 0x2)
    /* 387C4 80047FC4 5A5D4294 */  lhu        $v0, %lo(_clutState + 0x2)($v0)
    /* 387C8 80047FC8 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 387CC 80047FCC 07004010 */  beqz       $v0, .L80047FEC
    /* 387D0 80047FD0 1800BFAF */   sw        $ra, 0x18($sp)
    /* 387D4 80047FD4 3000A28F */  lw         $v0, 0x30($sp)
    /* 387D8 80047FD8 00000000 */  nop
    /* 387DC 80047FDC 1000A2AF */  sw         $v0, 0x10($sp)
    /* 387E0 80047FE0 3400A28F */  lw         $v0, 0x34($sp)
    /* 387E4 80047FE4 CC1E010C */  jal        func_80047B30
    /* 387E8 80047FE8 1400A2AF */   sw        $v0, 0x14($sp)
  .L80047FEC:
    /* 387EC 80047FEC 1800BF8F */  lw         $ra, 0x18($sp)
    /* 387F0 80047FF0 00000000 */  nop
    /* 387F4 80047FF4 0800E003 */  jr         $ra
    /* 387F8 80047FF8 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_80047FC0
