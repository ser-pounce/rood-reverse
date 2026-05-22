nonmatching DMACallback, 0x30

glabel DMACallback
    /* 10134 8001F934 0380023C */  lui        $v0, %hi(D_800320D4)
    /* 10138 8001F938 D420428C */  lw         $v0, %lo(D_800320D4)($v0)
    /* 1013C 8001F93C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 10140 8001F940 1000BFAF */  sw         $ra, 0x10($sp)
    /* 10144 8001F944 0400428C */  lw         $v0, 0x4($v0)
    /* 10148 8001F948 00000000 */  nop
    /* 1014C 8001F94C 09F84000 */  jalr       $v0
    /* 10150 8001F950 00000000 */   nop
    /* 10154 8001F954 1000BF8F */  lw         $ra, 0x10($sp)
    /* 10158 8001F958 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 1015C 8001F95C 0800E003 */  jr         $ra
    /* 10160 8001F960 00000000 */   nop
endlabel DMACallback
