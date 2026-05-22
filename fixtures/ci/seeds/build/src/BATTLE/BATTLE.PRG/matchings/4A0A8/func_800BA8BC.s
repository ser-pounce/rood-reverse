nonmatching func_800BA8BC, 0x50

glabel func_800BA8BC
    /* 520BC 800BA8BC E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 520C0 800BA8C0 1000B0AF */  sw         $s0, 0x10($sp)
    /* 520C4 800BA8C4 21808000 */  addu       $s0, $a0, $zero
    /* 520C8 800BA8C8 1400BFAF */  sw         $ra, 0x14($sp)
    /* 520CC 800BA8CC 80FF020C */  jal        vs_battle_getShort
    /* 520D0 800BA8D0 01000426 */   addiu     $a0, $s0, 0x1
    /* 520D4 800BA8D4 03000426 */  addiu      $a0, $s0, 0x3
    /* 520D8 800BA8D8 00840200 */  sll        $s0, $v0, 16
    /* 520DC 800BA8DC 80FF020C */  jal        vs_battle_getShort
    /* 520E0 800BA8E0 03841000 */   sra       $s0, $s0, 16
    /* 520E4 800BA8E4 94FF020C */  jal        func_800BFE50
    /* 520E8 800BA8E8 FFFF4430 */   andi      $a0, $v0, 0xFFFF
    /* 520EC 800BA8EC 21200002 */  addu       $a0, $s0, $zero
    /* 520F0 800BA8F0 88EF010C */  jal        func_8007BE20
    /* 520F4 800BA8F4 21284000 */   addu      $a1, $v0, $zero
    /* 520F8 800BA8F8 1400BF8F */  lw         $ra, 0x14($sp)
    /* 520FC 800BA8FC 1000B08F */  lw         $s0, 0x10($sp)
    /* 52100 800BA900 21100000 */  addu       $v0, $zero, $zero
    /* 52104 800BA904 0800E003 */  jr         $ra
    /* 52108 800BA908 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800BA8BC
