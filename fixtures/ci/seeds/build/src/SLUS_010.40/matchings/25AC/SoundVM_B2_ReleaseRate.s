nonmatching SoundVM_B2_ReleaseRate, 0x40

glabel SoundVM_B2_ReleaseRate
    /* CD2C 8001C52C 0010053C */  lui        $a1, (0x10000000 >> 16)
    /* CD30 8001C530 0000828C */  lw         $v0, 0x0($a0)
    /* CD34 8001C534 F800838C */  lw         $v1, 0xF8($a0)
    /* CD38 8001C538 00004690 */  lbu        $a2, 0x0($v0)
    /* CD3C 8001C53C 01004224 */  addiu      $v0, $v0, 0x1
    /* CD40 8001C540 000082AC */  sw         $v0, 0x0($a0)
    /* CD44 8001C544 3400828C */  lw         $v0, 0x34($a0)
    /* CD48 8001C548 00446334 */  ori        $v1, $v1, 0x4400
    /* CD4C 8001C54C F80083AC */  sw         $v1, 0xF8($a0)
    /* CD50 8001C550 08018394 */  lhu        $v1, 0x108($a0)
    /* CD54 8001C554 25104500 */  or         $v0, $v0, $a1
    /* CD58 8001C558 E0FF6330 */  andi       $v1, $v1, 0xFFE0
    /* CD5C 8001C55C 25186600 */  or         $v1, $v1, $a2
    /* CD60 8001C560 340082AC */  sw         $v0, 0x34($a0)
    /* CD64 8001C564 0800E003 */  jr         $ra
    /* CD68 8001C568 080183A4 */   sh        $v1, 0x108($a0)
endlabel SoundVM_B2_ReleaseRate
