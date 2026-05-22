nonmatching func_800834E4, 0x40

glabel func_800834E4
    /* 1ACE4 800834E4 0F80033C */  lui        $v1, %hi(vs_battle_actors)
    /* 1ACE8 800834E8 0000C290 */  lbu        $v0, 0x0($a2)
    /* 1ACEC 800834EC 28196324 */  addiu      $v1, $v1, %lo(vs_battle_actors)
    /* 1ACF0 800834F0 80100200 */  sll        $v0, $v0, 2
    /* 1ACF4 800834F4 21104300 */  addu       $v0, $v0, $v1
    /* 1ACF8 800834F8 0000428C */  lw         $v0, 0x0($v0)
    /* 1ACFC 800834FC 00000000 */  nop
    /* 1AD00 80083500 3C00438C */  lw         $v1, 0x3C($v0)
    /* 1AD04 80083504 00000000 */  nop
    /* 1AD08 80083508 1E006294 */  lhu        $v0, 0x1E($v1)
    /* 1AD0C 8008350C 1C006394 */  lhu        $v1, 0x1C($v1)
    /* 1AD10 80083510 00000000 */  nop
    /* 1AD14 80083514 23104300 */  subu       $v0, $v0, $v1
    /* 1AD18 80083518 00140200 */  sll        $v0, $v0, 16
    /* 1AD1C 8008351C 0800E003 */  jr         $ra
    /* 1AD20 80083520 03140200 */   sra       $v0, $v0, 16
endlabel func_800834E4
