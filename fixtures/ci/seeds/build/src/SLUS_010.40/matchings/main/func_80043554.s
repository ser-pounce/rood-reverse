nonmatching func_80043554, 0x28

glabel func_80043554
    /* 33D54 80043554 21108000 */  addu       $v0, $a0, $zero
    /* 33D58 80043558 FFFF4524 */  addiu      $a1, $v0, -0x1
    /* 33D5C 8004355C 0580043C */  lui        $a0, %hi(_padAct)
    /* 33D60 80043560 18018424 */  addiu      $a0, $a0, %lo(_padAct)
    /* 33D64 80043564 C0180500 */  sll        $v1, $a1, 3
    /* 33D68 80043568 23186500 */  subu       $v1, $v1, $a1
    /* 33D6C 8004356C C0180300 */  sll        $v1, $v1, 3
    /* 33D70 80043570 21186400 */  addu       $v1, $v1, $a0
    /* 33D74 80043574 0800E003 */  jr         $ra
    /* 33D78 80043578 080060A4 */   sh        $zero, 0x8($v1)
endlabel func_80043554
