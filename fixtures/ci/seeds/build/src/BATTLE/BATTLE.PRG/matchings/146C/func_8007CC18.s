nonmatching func_8007CC18, 0x34

glabel func_8007CC18
    /* 14418 8007CC18 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 1441C 8007CC1C 09000224 */  addiu      $v0, $zero, 0x9
    /* 14420 8007CC20 1100A4A3 */  sb         $a0, 0x11($sp)
    /* 14424 8007CC24 1000A427 */  addiu      $a0, $sp, 0x10
    /* 14428 8007CC28 2800BFAF */  sw         $ra, 0x28($sp)
    /* 1442C 8007CC2C 1000A2A3 */  sb         $v0, 0x10($sp)
    /* 14430 8007CC30 1200A5A7 */  sh         $a1, 0x12($sp)
    /* 14434 8007CC34 7A65020C */  jal        vs_battle_populateDataSlot
    /* 14438 8007CC38 2100A6A3 */   sb        $a2, 0x21($sp)
    /* 1443C 8007CC3C 2800BF8F */  lw         $ra, 0x28($sp)
    /* 14440 8007CC40 00000000 */  nop
    /* 14444 8007CC44 0800E003 */  jr         $ra
    /* 14448 8007CC48 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel func_8007CC18
