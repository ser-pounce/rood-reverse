nonmatching vs_battle_playMenuChangeSfx, 0x24

glabel vs_battle_playMenuChangeSfx
    /* 57AF8 800C02F8 04000524 */  addiu      $a1, $zero, 0x4
  .L800C02FC:
    /* 57AFC 800C02FC F8FFBD27 */  addiu      $sp, $sp, -0x8
    /* 57B00 800C0300 0000BFAF */  sw         $ra, 0x0($sp)
    /* 57B04 800C0304 6216010C */  jal        vs_main_playSfxDefault
    /* 57B08 800C0308 7E000424 */   addiu     $a0, $zero, 0x7E
    /* 57B0C 800C030C 0000BF8F */  lw         $ra, 0x0($sp)
    /* 57B10 800C0310 00000000 */  nop
    /* 57B14 800C0314 0800E003 */  jr         $ra
    /* 57B18 800C0318 0800BD27 */   addiu     $sp, $sp, 0x8
endlabel vs_battle_playMenuChangeSfx
