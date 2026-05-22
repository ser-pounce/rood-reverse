nonmatching func_80048A3C, 0x28

glabel func_80048A3C
    /* 3923C 80048A3C 0580053C */  lui        $a1, %hi(_clutState)
    /* 39240 80048A40 585DA524 */  addiu      $a1, $a1, %lo(_clutState)
    /* 39244 80048A44 C0100400 */  sll        $v0, $a0, 3
    /* 39248 80048A48 21104400 */  addu       $v0, $v0, $a0
    /* 3924C 80048A4C 001A0200 */  sll        $v1, $v0, 8
    /* 39250 80048A50 21104300 */  addu       $v0, $v0, $v1
    /* 39254 80048A54 21104400 */  addu       $v0, $v0, $a0
    /* 39258 80048A58 21104500 */  addu       $v0, $v0, $a1
    /* 3925C 80048A5C 0800E003 */  jr         $ra
    /* 39260 80048A60 060040A0 */   sb        $zero, 0x6($v0)
endlabel func_80048A3C
