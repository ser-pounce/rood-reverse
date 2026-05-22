nonmatching SoundVM_B1_SustainRate, 0x44

glabel SoundVM_B1_SustainRate
    /* CCE8 8001C4E8 0008053C */  lui        $a1, (0x8000000 >> 16)
    /* CCEC 8001C4EC 0000828C */  lw         $v0, 0x0($a0)
    /* CCF0 8001C4F0 F800838C */  lw         $v1, 0xF8($a0)
    /* CCF4 8001C4F4 00004690 */  lbu        $a2, 0x0($v0)
    /* CCF8 8001C4F8 01004224 */  addiu      $v0, $v0, 0x1
    /* CCFC 8001C4FC 000082AC */  sw         $v0, 0x0($a0)
    /* CD00 8001C500 3400828C */  lw         $v0, 0x34($a0)
    /* CD04 8001C504 00226334 */  ori        $v1, $v1, 0x2200
    /* CD08 8001C508 F80083AC */  sw         $v1, 0xF8($a0)
    /* CD0C 8001C50C 08018394 */  lhu        $v1, 0x108($a0)
    /* CD10 8001C510 25104500 */  or         $v0, $v0, $a1
    /* CD14 8001C514 3FE06330 */  andi       $v1, $v1, 0xE03F
    /* CD18 8001C518 80310600 */  sll        $a2, $a2, 6
    /* CD1C 8001C51C 25186600 */  or         $v1, $v1, $a2
    /* CD20 8001C520 340082AC */  sw         $v0, 0x34($a0)
    /* CD24 8001C524 0800E003 */  jr         $ra
    /* CD28 8001C528 080183A4 */   sh        $v1, 0x108($a0)
endlabel SoundVM_B1_SustainRate
