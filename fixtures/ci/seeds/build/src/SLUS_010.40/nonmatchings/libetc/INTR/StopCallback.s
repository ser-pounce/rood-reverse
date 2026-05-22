nonmatching StopCallback, 0x30

glabel StopCallback
    /* 101C8 8001F9C8 0380023C */  lui        $v0, %hi(D_800320D4)
    /* 101CC 8001F9CC D420428C */  lw         $v0, %lo(D_800320D4)($v0)
    /* 101D0 8001F9D0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 101D4 8001F9D4 1000BFAF */  sw         $ra, 0x10($sp)
    /* 101D8 8001F9D8 1000428C */  lw         $v0, 0x10($v0)
    /* 101DC 8001F9DC 00000000 */  nop
    /* 101E0 8001F9E0 09F84000 */  jalr       $v0
    /* 101E4 8001F9E4 00000000 */   nop
    /* 101E8 8001F9E8 1000BF8F */  lw         $ra, 0x10($sp)
    /* 101EC 8001F9EC 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 101F0 8001F9F0 0800E003 */  jr         $ra
    /* 101F4 8001F9F4 00000000 */   nop
endlabel StopCallback
