nonmatching VSyncCallbacks, 0x30

glabel VSyncCallbacks
    /* 10198 8001F998 0380023C */  lui        $v0, %hi(D_800320D4)
    /* 1019C 8001F99C D420428C */  lw         $v0, %lo(D_800320D4)($v0)
    /* 101A0 8001F9A0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 101A4 8001F9A4 1000BFAF */  sw         $ra, 0x10($sp)
    /* 101A8 8001F9A8 1400428C */  lw         $v0, 0x14($v0)
    /* 101AC 8001F9AC 00000000 */  nop
    /* 101B0 8001F9B0 09F84000 */  jalr       $v0
    /* 101B4 8001F9B4 00000000 */   nop
    /* 101B8 8001F9B8 1000BF8F */  lw         $ra, 0x10($sp)
    /* 101BC 8001F9BC 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 101C0 8001F9C0 0800E003 */  jr         $ra
    /* 101C4 8001F9C4 00000000 */   nop
endlabel VSyncCallbacks
