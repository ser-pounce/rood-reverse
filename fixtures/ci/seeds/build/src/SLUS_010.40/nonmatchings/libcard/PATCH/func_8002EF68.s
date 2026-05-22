nonmatching func_8002EF68, 0x24

glabel func_8002EF68
    /* 1F768 8002EF68 01A0023C */  lui        $v0, %hi(D_A000DFAC)
    /* 1F76C 8002EF6C ACDF4224 */  addiu      $v0, $v0, %lo(D_A000DFAC)
    /* 1F770 8002EF70 08004000 */  jr         $v0
    /* 1F774 8002EF74 00000000 */   nop
    /* 1F778 8002EF78 00000000 */  nop
    /* 1F77C 8002EF7C 01A0083C */  lui        $t0, %hi(D_A000DF80)
    /* 1F780 8002EF80 80DF0825 */  addiu      $t0, $t0, %lo(D_A000DF80)
    /* 1F784 8002EF84 09F80001 */  jalr       $t0
    /* 1F788 8002EF88 00000000 */   nop
endlabel func_8002EF68
    /* 1F78C 8002EF8C 00000000 */  nop
