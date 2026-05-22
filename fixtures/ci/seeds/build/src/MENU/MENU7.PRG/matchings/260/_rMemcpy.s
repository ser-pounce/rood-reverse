nonmatching _rMemcpy, 0x20

glabel _rMemcpy
    /* 39C 80102B9C FFFFC624 */  addiu      $a2, $a2, -0x1
    /* 3A0 80102BA0 2110A600 */  addu       $v0, $a1, $a2
    /* 3A4 80102BA4 00004390 */  lbu        $v1, 0x0($v0)
    /* 3A8 80102BA8 21108600 */  addu       $v0, $a0, $a2
    /* 3AC 80102BAC FBFFC014 */  bnez       $a2, _rMemcpy
    /* 3B0 80102BB0 000043A0 */   sb        $v1, 0x0($v0)
    /* 3B4 80102BB4 0800E003 */  jr         $ra
    /* 3B8 80102BB8 00000000 */   nop
endlabel _rMemcpy
