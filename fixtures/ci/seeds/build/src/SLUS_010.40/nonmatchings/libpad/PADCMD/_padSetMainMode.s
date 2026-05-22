nonmatching _padSetMainMode, 0x98

glabel _padSetMainMode
    /* 1DC9C 8002D49C D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 1DCA0 8002D4A0 1000B0AF */  sw         $s0, 0x10($sp)
    /* 1DCA4 8002D4A4 21808000 */  addu       $s0, $a0, $zero
    /* 1DCA8 8002D4A8 1400B1AF */  sw         $s1, 0x14($sp)
    /* 1DCAC 8002D4AC 2188A000 */  addu       $s1, $a1, $zero
    /* 1DCB0 8002D4B0 1800B2AF */  sw         $s2, 0x18($sp)
    /* 1DCB4 8002D4B4 2190C000 */  addu       $s2, $a2, $zero
    /* 1DCB8 8002D4B8 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 1DCBC 8002D4BC 0380023C */  lui        $v0, %hi(D_800335B8)
    /* 1DCC0 8002D4C0 B835428C */  lw         $v0, %lo(D_800335B8)($v0)
    /* 1DCC4 8002D4C4 2000BFAF */  sw         $ra, 0x20($sp)
    /* 1DCC8 8002D4C8 09F84000 */  jalr       $v0
    /* 1DCCC 8002D4CC 21982002 */   addu      $s3, $s1, $zero
    /* 1DCD0 8002D4D0 11004014 */  bnez       $v0, .L8002D518
    /* 1DCD4 8002D4D4 21100000 */   addu      $v0, $zero, $zero
    /* 1DCD8 8002D4D8 01000224 */  addiu      $v0, $zero, 0x1
    /* 1DCDC 8002D4DC E4000492 */  lbu        $a0, 0xE4($s0)
    /* 1DCE0 8002D4E0 01000324 */  addiu      $v1, $zero, 0x1
    /* 1DCE4 8002D4E4 460003A2 */  sb         $v1, 0x46($s0)
    /* 1DCE8 8002D4E8 0380033C */  lui        $v1, %hi(func_8002D534)
    /* 1DCEC 8002D4EC 34D56324 */  addiu      $v1, $v1, %lo(func_8002D534)
    /* 1DCF0 8002D4F0 140003AE */  sw         $v1, 0x14($s0)
    /* 1DCF4 8002D4F4 0380033C */  lui        $v1, %hi(func_8002D588)
    /* 1DCF8 8002D4F8 88D56324 */  addiu      $v1, $v1, %lo(func_8002D588)
    /* 1DCFC 8002D4FC 180003AE */  sw         $v1, 0x18($s0)
    /* 1DD00 8002D500 FF006332 */  andi       $v1, $s3, 0xFF
    /* 1DD04 8002D504 510011A2 */  sb         $s1, 0x51($s0)
    /* 1DD08 8002D508 520012A2 */  sb         $s2, 0x52($s0)
    /* 1DD0C 8002D50C 26186400 */  xor        $v1, $v1, $a0
    /* 1DD10 8002D510 0100632C */  sltiu      $v1, $v1, 0x1
    /* 1DD14 8002D514 530003A2 */  sb         $v1, 0x53($s0)
  .L8002D518:
    /* 1DD18 8002D518 2000BF8F */  lw         $ra, 0x20($sp)
    /* 1DD1C 8002D51C 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 1DD20 8002D520 1800B28F */  lw         $s2, 0x18($sp)
    /* 1DD24 8002D524 1400B18F */  lw         $s1, 0x14($sp)
    /* 1DD28 8002D528 1000B08F */  lw         $s0, 0x10($sp)
    /* 1DD2C 8002D52C 0800E003 */  jr         $ra
    /* 1DD30 8002D530 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel _padSetMainMode
