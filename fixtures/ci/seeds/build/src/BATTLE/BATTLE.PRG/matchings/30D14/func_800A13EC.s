nonmatching func_800A13EC, 0x30

glabel func_800A13EC
    /* 38BEC 800A13EC E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 38BF0 800A13F0 1000BFAF */  sw         $ra, 0x10($sp)
    /* 38BF4 800A13F4 0785020C */  jal        func_800A141C
    /* 38BF8 800A13F8 00000000 */   nop
    /* 38BFC 800A13FC 21184000 */  addu       $v1, $v0, $zero
    /* 38C00 800A1400 02006004 */  bltz       $v1, .L800A140C
    /* 38C04 800A1404 00000000 */   nop
    /* 38C08 800A1408 21100000 */  addu       $v0, $zero, $zero
  .L800A140C:
    /* 38C0C 800A140C 1000BF8F */  lw         $ra, 0x10($sp)
    /* 38C10 800A1410 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 38C14 800A1414 0800E003 */  jr         $ra
    /* 38C18 800A1418 00000000 */   nop
endlabel func_800A13EC
