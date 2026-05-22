nonmatching func_800B7358, 0x40

glabel func_800B7358
    /* 4EB58 800B7358 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 4EB5C 800B735C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 4EB60 800B7360 21808000 */  addu       $s0, $a0, $zero
    /* 4EB64 800B7364 1400BFAF */  sw         $ra, 0x14($sp)
    /* 4EB68 800B7368 01000492 */  lbu        $a0, 0x1($s0)
    /* 4EB6C 800B736C 7D33030C */  jal        vs_battle_getTextBox
    /* 4EB70 800B7370 42210400 */   srl       $a0, $a0, 5
    /* 4EB74 800B7374 01000392 */  lbu        $v1, 0x1($s0)
    /* 4EB78 800B7378 00000000 */  nop
    /* 4EB7C 800B737C 1F006330 */  andi       $v1, $v1, 0x1F
    /* 4EB80 800B7380 220043A0 */  sb         $v1, 0x22($v0)
    /* 4EB84 800B7384 1400BF8F */  lw         $ra, 0x14($sp)
    /* 4EB88 800B7388 1000B08F */  lw         $s0, 0x10($sp)
    /* 4EB8C 800B738C 21100000 */  addu       $v0, $zero, $zero
    /* 4EB90 800B7390 0800E003 */  jr         $ra
    /* 4EB94 800B7394 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800B7358
