nonmatching func_800735CC, 0x2C

glabel func_800735CC
    /* ADCC 800735CC E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* ADD0 800735D0 1000B0AF */  sw         $s0, 0x10($sp)
    /* ADD4 800735D4 1400BFAF */  sw         $ra, 0x14($sp)
    /* ADD8 800735D8 452C030C */  jal        func_800CB114
    /* ADDC 800735DC 21808000 */   addu      $s0, $a0, $zero
    /* ADE0 800735E0 03B1010C */  jal        func_8006C40C
    /* ADE4 800735E4 000000A6 */   sh        $zero, 0x0($s0)
    /* ADE8 800735E8 1400BF8F */  lw         $ra, 0x14($sp)
    /* ADEC 800735EC 1000B08F */  lw         $s0, 0x10($sp)
    /* ADF0 800735F0 0800E003 */  jr         $ra
    /* ADF4 800735F4 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800735CC
