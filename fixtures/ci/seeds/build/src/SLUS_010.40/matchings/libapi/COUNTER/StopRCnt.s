nonmatching StopRCnt, 0x34

glabel StopRCnt
    /* 17328 80026B28 FFFF8430 */  andi       $a0, $a0, 0xFFFF
    /* 1732C 80026B2C 80200400 */  sll        $a0, $a0, 2
    /* 17330 80026B30 0380053C */  lui        $a1, %hi(_interruptReg)
    /* 17334 80026B34 3428A58C */  lw         $a1, %lo(_interruptReg)($a1)
    /* 17338 80026B38 0380023C */  lui        $v0, %hi(_interruptMasks)
    /* 1733C 80026B3C 21104400 */  addu       $v0, $v0, $a0
    /* 17340 80026B40 3C28428C */  lw         $v0, %lo(_interruptMasks)($v0)
    /* 17344 80026B44 0400A38C */  lw         $v1, 0x4($a1)
    /* 17348 80026B48 27100200 */  nor        $v0, $zero, $v0
    /* 1734C 80026B4C 24186200 */  and        $v1, $v1, $v0
    /* 17350 80026B50 01000224 */  addiu      $v0, $zero, 0x1
    /* 17354 80026B54 0800E003 */  jr         $ra
    /* 17358 80026B58 0400A3AC */   sw        $v1, 0x4($a1)
endlabel StopRCnt
