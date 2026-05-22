nonmatching func_8008E480, 0x2C

glabel func_8008E480
    /* 25C80 8008E480 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 25C84 8008E484 1000B0AF */  sw         $s0, 0x10($sp)
    /* 25C88 8008E488 1400BFAF */  sw         $ra, 0x14($sp)
    /* 25C8C 8008E48C 2B4E020C */  jal        func_800938AC
    /* 25C90 8008E490 21808000 */   addu      $s0, $a0, $zero
    /* 25C94 8008E494 3A46020C */  jal        func_800918E8
    /* 25C98 8008E498 21200002 */   addu      $a0, $s0, $zero
    /* 25C9C 8008E49C 1400BF8F */  lw         $ra, 0x14($sp)
    /* 25CA0 8008E4A0 1000B08F */  lw         $s0, 0x10($sp)
    /* 25CA4 8008E4A4 0800E003 */  jr         $ra
    /* 25CA8 8008E4A8 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8008E480
