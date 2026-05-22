nonmatching func_8009FD38, 0x24

glabel func_8009FD38
    /* 37538 8009FD38 3C068294 */  lhu        $v0, 0x63C($a0)
    /* 3753C 8009FD3C 1E000324 */  addiu      $v1, $zero, 0x1E
    /* 37540 8009FD40 8100422C */  sltiu      $v0, $v0, 0x81
    /* 37544 8009FD44 03004014 */  bnez       $v0, .L8009FD54
    /* 37548 8009FD48 FA1783A4 */   sh        $v1, 0x17FA($a0)
    /* 3754C 8009FD4C 14000224 */  addiu      $v0, $zero, 0x14
    /* 37550 8009FD50 FA1782A4 */  sh         $v0, 0x17FA($a0)
  .L8009FD54:
    /* 37554 8009FD54 0800E003 */  jr         $ra
    /* 37558 8009FD58 00000000 */   nop
endlabel func_8009FD38
