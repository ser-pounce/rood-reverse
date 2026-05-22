nonmatching DsEndReadySystem, 0x64

glabel DsEndReadySystem
    /* 16AE8 800262E8 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 16AEC 800262EC 1000B0AF */  sw         $s0, 0x10($sp)
    /* 16AF0 800262F0 0380103C */  lui        $s0, %hi(D_80032824)
    /* 16AF4 800262F4 24281026 */  addiu      $s0, $s0, %lo(D_80032824)
    /* 16AF8 800262F8 1400BFAF */  sw         $ra, 0x14($sp)
    /* 16AFC 800262FC 0000038E */  lw         $v1, 0x0($s0)
    /* 16B00 80026300 01000224 */  addiu      $v0, $zero, 0x1
    /* 16B04 80026304 0C006214 */  bne        $v1, $v0, .L80026338
    /* 16B08 80026308 00000000 */   nop
    /* 16B0C 8002630C F4FF048E */  lw         $a0, -0xC($s0)
    /* 16B10 80026310 069A000C */  jal        DsReadyCallback
    /* 16B14 80026314 00000000 */   nop
    /* 16B18 80026318 F8FF048E */  lw         $a0, -0x8($s0)
    /* 16B1C 8002631C 0B9A000C */  jal        DsStartCallback
    /* 16B20 80026320 00000000 */   nop
    /* 16B24 80026324 09000424 */  addiu      $a0, $zero, 0x9
    /* 16B28 80026328 21280000 */  addu       $a1, $zero, $zero
    /* 16B2C 8002632C 21300000 */  addu       $a2, $zero, $zero
    /* 16B30 80026330 CD8E000C */  jal        DsCommand
    /* 16B34 80026334 FFFF0724 */   addiu     $a3, $zero, -0x1
  .L80026338:
    /* 16B38 80026338 000000AE */  sw         $zero, 0x0($s0)
    /* 16B3C 8002633C 1400BF8F */  lw         $ra, 0x14($sp)
    /* 16B40 80026340 1000B08F */  lw         $s0, 0x10($sp)
    /* 16B44 80026344 0800E003 */  jr         $ra
    /* 16B48 80026348 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel DsEndReadySystem
