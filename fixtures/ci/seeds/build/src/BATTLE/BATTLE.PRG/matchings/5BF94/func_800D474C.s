nonmatching func_800D474C, 0x2C

glabel func_800D474C
    /* 6BF4C 800D474C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 6BF50 800D4750 1000B0AF */  sw         $s0, 0x10($sp)
    /* 6BF54 800D4754 1400BFAF */  sw         $ra, 0x14($sp)
    /* 6BF58 800D4758 6654030C */  jal        func_800D5198
    /* 6BF5C 800D475C 21808000 */   addu      $s0, $a0, $zero
    /* 6BF60 800D4760 0A0002A6 */  sh         $v0, 0xA($s0)
    /* 6BF64 800D4764 1400BF8F */  lw         $ra, 0x14($sp)
    /* 6BF68 800D4768 1000B08F */  lw         $s0, 0x10($sp)
    /* 6BF6C 800D476C 01000224 */  addiu      $v0, $zero, 0x1
    /* 6BF70 800D4770 0800E003 */  jr         $ra
    /* 6BF74 800D4774 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800D474C
