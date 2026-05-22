nonmatching func_800787F0, 0x38

glabel func_800787F0
    /* FFF0 800787F0 0F80023C */  lui        $v0, %hi(D_800F1868)
    /* FFF4 800787F4 6818428C */  lw         $v0, %lo(D_800F1868)($v0)
    /* FFF8 800787F8 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* FFFC 800787FC 02004230 */  andi       $v0, $v0, 0x2
    /* 10000 80078800 05004014 */  bnez       $v0, .L80078818
    /* 10004 80078804 1000BFAF */   sw        $ra, 0x10($sp)
    /* 10008 80078808 9EC0010C */  jal        func_80070278
    /* 1000C 8007880C 00000000 */   nop
    /* 10010 80078810 DD3B030C */  jal        func_800CEF74
    /* 10014 80078814 21200000 */   addu      $a0, $zero, $zero
  .L80078818:
    /* 10018 80078818 1000BF8F */  lw         $ra, 0x10($sp)
    /* 1001C 8007881C 00000000 */  nop
    /* 10020 80078820 0800E003 */  jr         $ra
    /* 10024 80078824 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800787F0
