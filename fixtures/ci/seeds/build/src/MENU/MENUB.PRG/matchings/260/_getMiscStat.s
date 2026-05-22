nonmatching _getMiscStat, 0x20

glabel _getMiscStat
    /* 1944 80104144 04008010 */  beqz       $a0, .L80104158
    /* 1948 80104148 00000000 */   nop
    /* 194C 8010414C 0200A290 */  lbu        $v0, 0x2($a1)
    /* 1950 80104150 0800E003 */  jr         $ra
    /* 1954 80104154 00000000 */   nop
  .L80104158:
    /* 1958 80104158 0000A294 */  lhu        $v0, 0x0($a1)
    /* 195C 8010415C 0800E003 */  jr         $ra
    /* 1960 80104160 23100200 */   negu      $v0, $v0
endlabel _getMiscStat
