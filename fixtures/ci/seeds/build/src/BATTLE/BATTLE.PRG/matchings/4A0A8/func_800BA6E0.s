nonmatching func_800BA6E0, 0x4C

glabel func_800BA6E0
    /* 51EE0 800BA6E0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 51EE4 800BA6E4 1400BFAF */  sw         $ra, 0x14($sp)
    /* 51EE8 800BA6E8 1000B0AF */  sw         $s0, 0x10($sp)
    /* 51EEC 800BA6EC 01009090 */  lbu        $s0, 0x1($a0)
    /* 51EF0 800BA6F0 4315010C */  jal        func_8004550C
    /* 51EF4 800BA6F4 21200002 */   addu      $a0, $s0, $zero
    /* 51EF8 800BA6F8 08004010 */  beqz       $v0, .L800BA71C
    /* 51EFC 800BA6FC 21100000 */   addu      $v0, $zero, $zero
    /* 51F00 800BA700 2E15010C */  jal        func_800454B8
    /* 51F04 800BA704 21200002 */   addu      $a0, $s0, $zero
    /* 51F08 800BA708 04004014 */  bnez       $v0, .L800BA71C
    /* 51F0C 800BA70C 01000224 */   addiu     $v0, $zero, 0x1
    /* 51F10 800BA710 7D13010C */  jal        func_80044DF4
    /* 51F14 800BA714 21200002 */   addu      $a0, $s0, $zero
    /* 51F18 800BA718 21100000 */  addu       $v0, $zero, $zero
  .L800BA71C:
    /* 51F1C 800BA71C 1400BF8F */  lw         $ra, 0x14($sp)
    /* 51F20 800BA720 1000B08F */  lw         $s0, 0x10($sp)
    /* 51F24 800BA724 0800E003 */  jr         $ra
    /* 51F28 800BA728 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800BA6E0
