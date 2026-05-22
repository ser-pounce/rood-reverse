nonmatching func_8006B2D4, 0x64

glabel func_8006B2D4
    /* 2AD4 8006B2D4 0F80023C */  lui        $v0, %hi(vs_battle_characterState)
    /* 2AD8 8006B2D8 FC19428C */  lw         $v0, %lo(vs_battle_characterState)($v0)
    /* 2ADC 8006B2DC E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 2AE0 8006B2E0 1800BFAF */  sw         $ra, 0x18($sp)
    /* 2AE4 8006B2E4 1400B1AF */  sw         $s1, 0x14($sp)
    /* 2AE8 8006B2E8 1000B0AF */  sw         $s0, 0x10($sp)
    /* 2AEC 8006B2EC 3C00508C */  lw         $s0, 0x3C($v0)
    /* 2AF0 8006B2F0 00000000 */  nop
    /* 2AF4 8006B2F4 4809028E */  lw         $v0, 0x948($s0)
    /* 2AF8 8006B2F8 001E113C */  lui        $s1, (0x1E000000 >> 16)
    /* 2AFC 8006B2FC 24305100 */  and        $a2, $v0, $s1
    /* 2B00 8006B300 0800C010 */  beqz       $a2, .L8006B324
    /* 2B04 8006B304 21280000 */   addu      $a1, $zero, $zero
    /* 2B08 8006B308 57090492 */  lbu        $a0, 0x957($s0)
    /* 2B0C 8006B30C FB4F020C */  jal        func_80093FEC
    /* 2B10 8006B310 01000724 */   addiu     $a3, $zero, 0x1
    /* 2B14 8006B314 4809048E */  lw         $a0, 0x948($s0)
    /* 2B18 8006B318 21280002 */  addu       $a1, $s0, $zero
    /* 2B1C 8006B31C D519020C */  jal        func_80086754
    /* 2B20 8006B320 24209100 */   and       $a0, $a0, $s1
  .L8006B324:
    /* 2B24 8006B324 1800BF8F */  lw         $ra, 0x18($sp)
    /* 2B28 8006B328 1400B18F */  lw         $s1, 0x14($sp)
    /* 2B2C 8006B32C 1000B08F */  lw         $s0, 0x10($sp)
    /* 2B30 8006B330 0800E003 */  jr         $ra
    /* 2B34 8006B334 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8006B2D4
