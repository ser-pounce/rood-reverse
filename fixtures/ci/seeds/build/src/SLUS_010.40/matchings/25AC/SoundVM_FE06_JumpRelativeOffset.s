nonmatching SoundVM_FE06_JumpRelativeOffset, 0x2C

glabel SoundVM_FE06_JumpRelativeOffset
    /* BC24 8001B424 0000858C */  lw         $a1, 0x0($a0)
    /* BC28 8001B428 00000000 */  nop
    /* BC2C 8001B42C 0100A390 */  lbu        $v1, 0x1($a1)
    /* BC30 8001B430 0000A290 */  lbu        $v0, 0x0($a1)
    /* BC34 8001B434 001A0300 */  sll        $v1, $v1, 8
    /* BC38 8001B438 25104300 */  or         $v0, $v0, $v1
    /* BC3C 8001B43C 00140200 */  sll        $v0, $v0, 16
    /* BC40 8001B440 03140200 */  sra        $v0, $v0, 16
    /* BC44 8001B444 2128A200 */  addu       $a1, $a1, $v0
    /* BC48 8001B448 0800E003 */  jr         $ra
    /* BC4C 8001B44C 000085AC */   sw        $a1, 0x0($a0)
endlabel SoundVM_FE06_JumpRelativeOffset
