nonmatching vs_mainMenu_initUiArmor, 0x5C

glabel vs_mainMenu_initUiArmor
    /* 3884 800FD084 20FFBD27 */  addiu      $sp, $sp, -0xE0
    /* 3888 800FD088 21108000 */  addu       $v0, $a0, $zero
    /* 388C 800FD08C D000B0AF */  sw         $s0, 0xD0($sp)
    /* 3890 800FD090 2180A000 */  addu       $s0, $a1, $zero
    /* 3894 800FD094 D400B1AF */  sw         $s1, 0xD4($sp)
    /* 3898 800FD098 2188C000 */  addu       $s1, $a2, $zero
    /* 389C 800FD09C D800B2AF */  sw         $s2, 0xD8($sp)
    /* 38A0 800FD0A0 2190E000 */  addu       $s2, $a3, $zero
    /* 38A4 800FD0A4 1000A427 */  addiu      $a0, $sp, 0x10
    /* 38A8 800FD0A8 DC00BFAF */  sw         $ra, 0xDC($sp)
    /* 38AC 800FD0AC 44AC010C */  jal        vs_battle_applyArmor
    /* 38B0 800FD0B0 21284000 */   addu      $a1, $v0, $zero
    /* 38B4 800FD0B4 1000A427 */  addiu      $a0, $sp, 0x10
    /* 38B8 800FD0B8 21280002 */  addu       $a1, $s0, $zero
    /* 38BC 800FD0BC 21302002 */  addu       $a2, $s1, $zero
    /* 38C0 800FD0C0 B3F3030C */  jal        vs_mainMenu_setUiArmor
    /* 38C4 800FD0C4 21384002 */   addu      $a3, $s2, $zero
    /* 38C8 800FD0C8 DC00BF8F */  lw         $ra, 0xDC($sp)
    /* 38CC 800FD0CC D800B28F */  lw         $s2, 0xD8($sp)
    /* 38D0 800FD0D0 D400B18F */  lw         $s1, 0xD4($sp)
    /* 38D4 800FD0D4 D000B08F */  lw         $s0, 0xD0($sp)
    /* 38D8 800FD0D8 0800E003 */  jr         $ra
    /* 38DC 800FD0DC E000BD27 */   addiu     $sp, $sp, 0xE0
endlabel vs_mainMenu_initUiArmor
