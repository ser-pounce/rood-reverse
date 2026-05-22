nonmatching func_80043470, 0x34

glabel func_80043470
    /* 33C70 80043470 21108000 */  addu       $v0, $a0, $zero
    /* 33C74 80043474 FFFF4524 */  addiu      $a1, $v0, -0x1
    /* 33C78 80043478 0580043C */  lui        $a0, %hi(_padAct)
    /* 33C7C 8004347C 18018424 */  addiu      $a0, $a0, %lo(_padAct)
    /* 33C80 80043480 C0180500 */  sll        $v1, $a1, 3
    /* 33C84 80043484 23186500 */  subu       $v1, $v1, $a1
    /* 33C88 80043488 C0180300 */  sll        $v1, $v1, 3
    /* 33C8C 8004348C 21186400 */  addu       $v1, $v1, $a0
    /* 33C90 80043490 2C0060AC */  sw         $zero, 0x2C($v1)
    /* 33C94 80043494 140060AC */  sw         $zero, 0x14($v1)
    /* 33C98 80043498 0C0060AC */  sw         $zero, 0xC($v1)
    /* 33C9C 8004349C 0800E003 */  jr         $ra
    /* 33CA0 800434A0 080060A4 */   sh        $zero, 0x8($v1)
endlabel func_80043470
