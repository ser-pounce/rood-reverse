nonmatching _card_clear, 0x34

glabel _card_clear
    /* 1F0D4 8002E8D4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1F0D8 8002E8D8 1000B0AF */  sw         $s0, 0x10($sp)
    /* 1F0DC 8002E8DC 1400BFAF */  sw         $ra, 0x14($sp)
    /* 1F0E0 8002E8E0 49BA000C */  jal        _new_card
    /* 1F0E4 8002E8E4 21808000 */   addu      $s0, $a0, $zero
    /* 1F0E8 8002E8E8 21200002 */  addu       $a0, $s0, $zero
    /* 1F0EC 8002E8EC 3F000524 */  addiu      $a1, $zero, 0x3F
    /* 1F0F0 8002E8F0 45BA000C */  jal        _card_write
    /* 1F0F4 8002E8F4 21300000 */   addu      $a2, $zero, $zero
    /* 1F0F8 8002E8F8 1400BF8F */  lw         $ra, 0x14($sp)
    /* 1F0FC 8002E8FC 1000B08F */  lw         $s0, 0x10($sp)
    /* 1F100 8002E900 0800E003 */  jr         $ra
    /* 1F104 8002E904 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel _card_clear
    /* 1F108 8002E908 00000000 */  nop
    /* 1F10C 8002E90C 00000000 */  nop
    /* 1F110 8002E910 00000000 */  nop
