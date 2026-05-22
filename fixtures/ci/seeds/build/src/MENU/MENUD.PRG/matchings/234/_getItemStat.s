nonmatching _getItemStat, 0x20

glabel _getItemStat
    /* 2DD0 801055D0 04008010 */  beqz       $a0, .L801055E4
    /* 2DD4 801055D4 00000000 */   nop
    /* 2DD8 801055D8 0200A290 */  lbu        $v0, 0x2($a1)
    /* 2DDC 801055DC 0800E003 */  jr         $ra
    /* 2DE0 801055E0 00000000 */   nop
  .L801055E4:
    /* 2DE4 801055E4 0000A294 */  lhu        $v0, 0x0($a1)
    /* 2DE8 801055E8 0800E003 */  jr         $ra
    /* 2DEC 801055EC 23100200 */   negu      $v0, $v0
endlabel _getItemStat
