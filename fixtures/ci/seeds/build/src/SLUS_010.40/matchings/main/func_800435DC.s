nonmatching func_800435DC, 0x2C

glabel func_800435DC
    /* 33DDC 800435DC 21108000 */  addu       $v0, $a0, $zero
    /* 33DE0 800435E0 FFFF4524 */  addiu      $a1, $v0, -0x1
    /* 33DE4 800435E4 0580043C */  lui        $a0, %hi(_padAct)
    /* 33DE8 800435E8 18018424 */  addiu      $a0, $a0, %lo(_padAct)
    /* 33DEC 800435EC C0180500 */  sll        $v1, $a1, 3
    /* 33DF0 800435F0 23186500 */  subu       $v1, $v1, $a1
    /* 33DF4 800435F4 C0180300 */  sll        $v1, $v1, 3
    /* 33DF8 800435F8 21186400 */  addu       $v1, $v1, $a0
    /* 33DFC 800435FC 01000424 */  addiu      $a0, $zero, 0x1
    /* 33E00 80043600 0800E003 */  jr         $ra
    /* 33E04 80043604 080064A4 */   sh        $a0, 0x8($v1)
endlabel func_800435DC
