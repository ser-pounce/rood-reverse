nonmatching vs_main_bzero, 0x20

glabel vs_main_bzero
    /* 39910 80049110 FCFFA830 */  andi       $t0, $a1, 0xFFFC
    /* 39914 80049114 04000011 */  beqz       $t0, .L80049128
  .L80049118:
    /* 39918 80049118 000080AC */   sw        $zero, 0x0($a0)
    /* 3991C 8004911C FCFF0825 */  addiu      $t0, $t0, -0x4
    /* 39920 80049120 FDFF0015 */  bnez       $t0, .L80049118
    /* 39924 80049124 04008424 */   addiu     $a0, $a0, 0x4
  .L80049128:
    /* 39928 80049128 0800E003 */  jr         $ra
    /* 3992C 8004912C 00000000 */   nop
endlabel vs_main_bzero
