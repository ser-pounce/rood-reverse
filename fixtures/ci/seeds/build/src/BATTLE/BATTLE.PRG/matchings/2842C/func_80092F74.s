nonmatching func_80092F74, 0x24

glabel func_80092F74
    /* 2A774 80092F74 08008284 */  lh         $v0, 0x8($a0)
    /* 2A778 80092F78 00000000 */  nop
    /* 2A77C 80092F7C 04004004 */  bltz       $v0, .L80092F90
    /* 2A780 80092F80 00010224 */   addiu     $v0, $zero, 0x100
    /* 2A784 80092F84 0000838C */  lw         $v1, 0x0($a0)
    /* 2A788 80092F88 00000000 */  nop
    /* 2A78C 80092F8C 000062AC */  sw         $v0, 0x0($v1)
  .L80092F90:
    /* 2A790 80092F90 0800E003 */  jr         $ra
    /* 2A794 80092F94 21100000 */   addu      $v0, $zero, $zero
endlabel func_80092F74
