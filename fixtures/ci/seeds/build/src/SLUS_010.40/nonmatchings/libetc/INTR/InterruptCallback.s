nonmatching InterruptCallback, 0x30

glabel InterruptCallback
    /* 10104 8001F904 0380023C */  lui        $v0, %hi(D_800320D4)
    /* 10108 8001F908 D420428C */  lw         $v0, %lo(D_800320D4)($v0)
    /* 1010C 8001F90C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 10110 8001F910 1000BFAF */  sw         $ra, 0x10($sp)
    /* 10114 8001F914 0800428C */  lw         $v0, 0x8($v0)
    /* 10118 8001F918 00000000 */  nop
    /* 1011C 8001F91C 09F84000 */  jalr       $v0
    /* 10120 8001F920 00000000 */   nop
    /* 10124 8001F924 1000BF8F */  lw         $ra, 0x10($sp)
    /* 10128 8001F928 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 1012C 8001F92C 0800E003 */  jr         $ra
    /* 10130 8001F930 00000000 */   nop
endlabel InterruptCallback
