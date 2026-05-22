nonmatching func_800B64CC, 0x34

glabel func_800B64CC
    /* 4DCCC 800B64CC 0F80023C */  lui        $v0, %hi(D_800F4538)
    /* 4DCD0 800B64D0 38454224 */  addiu      $v0, $v0, %lo(D_800F4538)
    /* 4DCD4 800B64D4 80180400 */  sll        $v1, $a0, 2
    /* 4DCD8 800B64D8 21104300 */  addu       $v0, $v0, $v1
    /* 4DCDC 800B64DC 0000428C */  lw         $v0, 0x0($v0)
    /* 4DCE0 800B64E0 01000334 */  ori        $v1, $zero, 0x1
    /* 4DCE4 800B64E4 00440700 */  sll        $t0, $a3, 16
    /* 4DCE8 800B64E8 25400501 */  or         $t0, $t0, $a1
    /* 4DCEC 800B64EC 4C1848AC */  sw         $t0, 0x184C($v0)
    /* 4DCF0 800B64F0 501846AC */  sw         $a2, 0x1850($v0)
  .L800B64F4:
    /* 4DCF4 800B64F4 481843AC */  sw         $v1, 0x1848($v0)
    /* 4DCF8 800B64F8 0800E003 */  jr         $ra
    /* 4DCFC 800B64FC 00000000 */   nop
endlabel func_800B64CC
