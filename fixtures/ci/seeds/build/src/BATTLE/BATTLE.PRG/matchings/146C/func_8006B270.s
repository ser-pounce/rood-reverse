nonmatching func_8006B270, 0x64

glabel func_8006B270
    /* 2A70 8006B270 0F80023C */  lui        $v0, %hi(vs_battle_characterState)
    /* 2A74 8006B274 FC19428C */  lw         $v0, %lo(vs_battle_characterState)($v0)
    /* 2A78 8006B278 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 2A7C 8006B27C 1800BFAF */  sw         $ra, 0x18($sp)
    /* 2A80 8006B280 1400B1AF */  sw         $s1, 0x14($sp)
    /* 2A84 8006B284 1000B0AF */  sw         $s0, 0x10($sp)
    /* 2A88 8006B288 3C00508C */  lw         $s0, 0x3C($v0)
    /* 2A8C 8006B28C 00000000 */  nop
    /* 2A90 8006B290 4809028E */  lw         $v0, 0x948($s0)
    /* 2A94 8006B294 E001113C */  lui        $s1, (0x1E00000 >> 16)
    /* 2A98 8006B298 24305100 */  and        $a2, $v0, $s1
    /* 2A9C 8006B29C 0800C010 */  beqz       $a2, .L8006B2C0
    /* 2AA0 8006B2A0 21280000 */   addu      $a1, $zero, $zero
    /* 2AA4 8006B2A4 57090492 */  lbu        $a0, 0x957($s0)
    /* 2AA8 8006B2A8 FB4F020C */  jal        func_80093FEC
    /* 2AAC 8006B2AC 01000724 */   addiu     $a3, $zero, 0x1
    /* 2AB0 8006B2B0 4809048E */  lw         $a0, 0x948($s0)
    /* 2AB4 8006B2B4 21280002 */  addu       $a1, $s0, $zero
    /* 2AB8 8006B2B8 D519020C */  jal        func_80086754
    /* 2ABC 8006B2BC 24209100 */   and       $a0, $a0, $s1
  .L8006B2C0:
    /* 2AC0 8006B2C0 1800BF8F */  lw         $ra, 0x18($sp)
    /* 2AC4 8006B2C4 1400B18F */  lw         $s1, 0x14($sp)
    /* 2AC8 8006B2C8 1000B08F */  lw         $s0, 0x10($sp)
    /* 2ACC 8006B2CC 0800E003 */  jr         $ra
    /* 2AD0 8006B2D0 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8006B270
