nonmatching func_800D48A4, 0x40

glabel func_800D48A4
    /* 6C0A4 800D48A4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 6C0A8 800D48A8 1000B0AF */  sw         $s0, 0x10($sp)
    /* 6C0AC 800D48AC 1400BFAF */  sw         $ra, 0x14($sp)
    /* 6C0B0 800D48B0 5C54030C */  jal        func_800D5170
    /* 6C0B4 800D48B4 21808000 */   addu      $s0, $a0, $zero
    /* 6C0B8 800D48B8 21200002 */  addu       $a0, $s0, $zero
    /* 6C0BC 800D48BC FF004530 */  andi       $a1, $v0, 0xFF
    /* 6C0C0 800D48C0 6955030C */  jal        func_800D55A4
    /* 6C0C4 800D48C4 21300000 */   addu      $a2, $zero, $zero
    /* 6C0C8 800D48C8 B7000224 */  addiu      $v0, $zero, 0xB7
    /* 6C0CC 800D48CC 0A0002A6 */  sh         $v0, 0xA($s0)
    /* 6C0D0 800D48D0 1400BF8F */  lw         $ra, 0x14($sp)
    /* 6C0D4 800D48D4 1000B08F */  lw         $s0, 0x10($sp)
    /* 6C0D8 800D48D8 01000224 */  addiu      $v0, $zero, 0x1
    /* 6C0DC 800D48DC 0800E003 */  jr         $ra
    /* 6C0E0 800D48E0 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800D48A4
