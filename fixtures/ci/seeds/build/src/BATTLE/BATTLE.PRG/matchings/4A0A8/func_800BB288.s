nonmatching func_800BB288, 0x30

glabel func_800BB288
    /* 52A88 800BB288 0F80023C */  lui        $v0, %hi(D_800EB9B4)
    /* 52A8C 800BB28C B4B9428C */  lw         $v0, %lo(D_800EB9B4)($v0)
    /* 52A90 800BB290 00000000 */  nop
    /* 52A94 800BB294 05004010 */  beqz       $v0, .L800BB2AC
    /* 52A98 800BB298 00000000 */   nop
    /* 52A9C 800BB29C 00004390 */  lbu        $v1, 0x0($v0)
    /* 52AA0 800BB2A0 00000000 */  nop
    /* 52AA4 800BB2A4 02006014 */  bnez       $v1, .L800BB2B0
    /* 52AA8 800BB2A8 01000224 */   addiu     $v0, $zero, 0x1
  .L800BB2AC:
    /* 52AAC 800BB2AC 21100000 */  addu       $v0, $zero, $zero
  .L800BB2B0:
    /* 52AB0 800BB2B0 0800E003 */  jr         $ra
    /* 52AB4 800BB2B4 00000000 */   nop
endlabel func_800BB288
