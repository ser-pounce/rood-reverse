nonmatching VSyncCallback, 0x34

glabel VSyncCallback
    /* 10164 8001F964 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 10168 8001F968 0380023C */  lui        $v0, %hi(D_800320D4)
    /* 1016C 8001F96C D420428C */  lw         $v0, %lo(D_800320D4)($v0)
    /* 10170 8001F970 21288000 */  addu       $a1, $a0, $zero
    /* 10174 8001F974 1000BFAF */  sw         $ra, 0x10($sp)
    /* 10178 8001F978 1400428C */  lw         $v0, 0x14($v0)
    /* 1017C 8001F97C 00000000 */  nop
    /* 10180 8001F980 09F84000 */  jalr       $v0
    /* 10184 8001F984 04000424 */   addiu     $a0, $zero, 0x4
    /* 10188 8001F988 1000BF8F */  lw         $ra, 0x10($sp)
    /* 1018C 8001F98C 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 10190 8001F990 0800E003 */  jr         $ra
    /* 10194 8001F994 00000000 */   nop
endlabel VSyncCallback
