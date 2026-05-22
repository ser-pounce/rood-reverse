nonmatching vs_battle_rMemcpy, 0x20

glabel vs_battle_rMemcpy
    /* 64434 800CCC34 FFFFC624 */  addiu      $a2, $a2, -0x1
    /* 64438 800CCC38 2110A600 */  addu       $v0, $a1, $a2
    /* 6443C 800CCC3C 00004390 */  lbu        $v1, 0x0($v0)
    /* 64440 800CCC40 21108600 */  addu       $v0, $a0, $a2
    /* 64444 800CCC44 FBFFC014 */  bnez       $a2, vs_battle_rMemcpy
    /* 64448 800CCC48 000043A0 */   sb        $v1, 0x0($v0)
    /* 6444C 800CCC4C 0800E003 */  jr         $ra
    /* 64450 800CCC50 00000000 */   nop
endlabel vs_battle_rMemcpy
