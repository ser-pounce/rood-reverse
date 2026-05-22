nonmatching StartRCnt, 0x30

glabel StartRCnt
    /* 172F8 80026AF8 FFFF8230 */  andi       $v0, $a0, 0xFFFF
    /* 172FC 80026AFC 80200200 */  sll        $a0, $v0, 2
    /* 17300 80026B00 0380053C */  lui        $a1, %hi(_interruptReg)
    /* 17304 80026B04 3428A58C */  lw         $a1, %lo(_interruptReg)($a1)
    /* 17308 80026B08 0380013C */  lui        $at, %hi(_interruptMasks)
    /* 1730C 80026B0C 21082400 */  addu       $at, $at, $a0
    /* 17310 80026B10 3C28248C */  lw         $a0, %lo(_interruptMasks)($at)
    /* 17314 80026B14 0400A38C */  lw         $v1, 0x4($a1)
    /* 17318 80026B18 03004228 */  slti       $v0, $v0, 0x3
    /* 1731C 80026B1C 25186400 */  or         $v1, $v1, $a0
    /* 17320 80026B20 0800E003 */  jr         $ra
    /* 17324 80026B24 0400A3AC */   sw        $v1, 0x4($a1)
endlabel StartRCnt
