nonmatching _rMemcpy, 0x20

glabel _rMemcpy
    /* 43C 80068C3C FFFFC624 */  addiu      $a2, $a2, -0x1
    /* 440 80068C40 2110A600 */  addu       $v0, $a1, $a2
    /* 444 80068C44 00004390 */  lbu        $v1, 0x0($v0)
    /* 448 80068C48 21108600 */  addu       $v0, $a0, $a2
    /* 44C 80068C4C FBFFC014 */  bnez       $a2, _rMemcpy
    /* 450 80068C50 000043A0 */   sb        $v1, 0x0($v0)
    /* 454 80068C54 0800E003 */  jr         $ra
    /* 458 80068C58 00000000 */   nop
endlabel _rMemcpy
