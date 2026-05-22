nonmatching func_800D4E5C, 0x34

glabel func_800D4E5C
    /* 6C65C 800D4E5C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 6C660 800D4E60 1000B0AF */  sw         $s0, 0x10($sp)
    /* 6C664 800D4E64 1400BFAF */  sw         $ra, 0x14($sp)
    /* 6C668 800D4E68 6654030C */  jal        func_800D5198
    /* 6C66C 800D4E6C 21808000 */   addu      $s0, $a0, $zero
    /* 6C670 800D4E70 21200002 */  addu       $a0, $s0, $zero
    /* 6C674 800D4E74 BB5A030C */  jal        func_800D6AEC
    /* 6C678 800D4E78 FFFF4530 */   andi      $a1, $v0, 0xFFFF
    /* 6C67C 800D4E7C 1400BF8F */  lw         $ra, 0x14($sp)
    /* 6C680 800D4E80 1000B08F */  lw         $s0, 0x10($sp)
    /* 6C684 800D4E84 01000224 */  addiu      $v0, $zero, 0x1
    /* 6C688 800D4E88 0800E003 */  jr         $ra
    /* 6C68C 800D4E8C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800D4E5C
