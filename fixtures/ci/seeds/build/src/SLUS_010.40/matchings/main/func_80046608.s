nonmatching func_80046608, 0x2C

glabel func_80046608
    /* 36E08 80046608 0680023C */  lui        $v0, %hi(vs_main_soundData)
    /* 36E0C 8004660C 38E04324 */  addiu      $v1, $v0, %lo(vs_main_soundData)
    /* 36E10 80046610 6C00628C */  lw         $v0, 0x6C($v1)
    /* 36E14 80046614 00000000 */  nop
    /* 36E18 80046618 04004014 */  bnez       $v0, .L8004662C
    /* 36E1C 8004661C 21100000 */   addu      $v0, $zero, $zero
    /* 36E20 80046620 6C0064AC */  sw         $a0, 0x6C($v1)
    /* 36E24 80046624 0800E003 */  jr         $ra
    /* 36E28 80046628 03000224 */   addiu     $v0, $zero, 0x3
  .L8004662C:
    /* 36E2C 8004662C 0800E003 */  jr         $ra
    /* 36E30 80046630 00000000 */   nop
endlabel func_80046608
