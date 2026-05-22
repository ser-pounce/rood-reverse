nonmatching func_8007DECC, 0x34

glabel func_8007DECC
    /* 156CC 8007DECC 0F80023C */  lui        $v0, %hi(D_800F1A68)
    /* 156D0 8007DED0 681A4724 */  addiu      $a3, $v0, %lo(D_800F1A68)
    /* 156D4 8007DED4 0000E38C */  lw         $v1, 0x0($a3)
    /* 156D8 8007DED8 0400E58C */  lw         $a1, 0x4($a3)
    /* 156DC 8007DEDC 0800E68C */  lw         $a2, 0x8($a3)
    /* 156E0 8007DEE0 000083AC */  sw         $v1, 0x0($a0)
    /* 156E4 8007DEE4 040085AC */  sw         $a1, 0x4($a0)
    /* 156E8 8007DEE8 080086AC */  sw         $a2, 0x8($a0)
    /* 156EC 8007DEEC 0C00E38C */  lw         $v1, 0xC($a3)
    /* 156F0 8007DEF0 00000000 */  nop
    /* 156F4 8007DEF4 0C0083AC */  sw         $v1, 0xC($a0)
    /* 156F8 8007DEF8 0800E003 */  jr         $ra
    /* 156FC 8007DEFC 00000000 */   nop
endlabel func_8007DECC
