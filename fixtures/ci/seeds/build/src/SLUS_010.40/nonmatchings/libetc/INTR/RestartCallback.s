nonmatching RestartCallback, 0x30

glabel RestartCallback
    /* 101F8 8001F9F8 0380023C */  lui        $v0, %hi(D_800320D4)
    /* 101FC 8001F9FC D420428C */  lw         $v0, %lo(D_800320D4)($v0)
    /* 10200 8001FA00 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 10204 8001FA04 1000BFAF */  sw         $ra, 0x10($sp)
    /* 10208 8001FA08 1800428C */  lw         $v0, 0x18($v0)
    /* 1020C 8001FA0C 00000000 */  nop
    /* 10210 8001FA10 09F84000 */  jalr       $v0
    /* 10214 8001FA14 00000000 */   nop
    /* 10218 8001FA18 1000BF8F */  lw         $ra, 0x10($sp)
    /* 1021C 8001FA1C 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 10220 8001FA20 0800E003 */  jr         $ra
    /* 10224 8001FA24 00000000 */   nop
endlabel RestartCallback
