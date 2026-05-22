nonmatching func_800B6724, 0x20

glabel func_800B6724
    /* 4DF24 800B6724 0F80023C */  lui        $v0, %hi(D_800EB9BC)
    /* 4DF28 800B6728 BCB9428C */  lw         $v0, %lo(D_800EB9BC)($v0)
    /* 4DF2C 800B672C 00000000 */  nop
    /* 4DF30 800B6730 0000428C */  lw         $v0, 0x0($v0)
    /* 4DF34 800B6734 00000000 */  nop
    /* 4DF38 800B6738 42100200 */  srl        $v0, $v0, 1
    /* 4DF3C 800B673C 0800E003 */  jr         $ra
    /* 4DF40 800B6740 01004230 */   andi      $v0, $v0, 0x1
endlabel func_800B6724
