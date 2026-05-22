nonmatching func_8002ECF0, 0x40

glabel func_8002ECF0
    /* 1F4F0 8002ECF0 0380033C */  lui        $v1, %hi(D_8003366C)
    /* 1F4F4 8002ECF4 6C36638C */  lw         $v1, %lo(D_8003366C)($v1)
    /* 1F4F8 8002ECF8 00000000 */  nop
    /* 1F4FC 8002ECFC 0400628C */  lw         $v0, 0x4($v1)
    /* 1F500 8002ED00 00000000 */  nop
    /* 1F504 8002ED04 01004230 */  andi       $v0, $v0, 0x1
    /* 1F508 8002ED08 07004010 */  beqz       $v0, .L8002ED28
    /* 1F50C 8002ED0C 21100000 */   addu      $v0, $zero, $zero
    /* 1F510 8002ED10 0000628C */  lw         $v0, 0x0($v1)
    /* 1F514 8002ED14 00000000 */  nop
    /* 1F518 8002ED18 01004230 */  andi       $v0, $v0, 0x1
    /* 1F51C 8002ED1C 02004014 */  bnez       $v0, .L8002ED28
    /* 1F520 8002ED20 01000224 */   addiu     $v0, $zero, 0x1
    /* 1F524 8002ED24 21100000 */  addu       $v0, $zero, $zero
  .L8002ED28:
    /* 1F528 8002ED28 0800E003 */  jr         $ra
    /* 1F52C 8002ED2C 00000000 */   nop
endlabel func_8002ECF0
    /* 1F530 8002ED30 00000000 */  nop
