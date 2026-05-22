nonmatching _decodeNextMovieFrame, 0x88

glabel _decodeNextMovieFrame
    /* 6AA0 8006F2A0 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 6AA4 8006F2A4 1800B2AF */  sw         $s2, 0x18($sp)
    /* 6AA8 8006F2A8 21908000 */  addu       $s2, $a0, $zero
    /* 6AAC 8006F2AC 1400B1AF */  sw         $s1, 0x14($sp)
    /* 6AB0 8006F2B0 D0071124 */  addiu      $s1, $zero, 0x7D0
    /* 6AB4 8006F2B4 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 6AB8 8006F2B8 1000B0AF */  sw         $s0, 0x10($sp)
  .L8006F2BC:
    /* 6ABC 8006F2BC CABC010C */  jal        _getNextMovieFrame
    /* 6AC0 8006F2C0 21204002 */   addu      $a0, $s2, $zero
    /* 6AC4 8006F2C4 21804000 */  addu       $s0, $v0, $zero
    /* 6AC8 8006F2C8 0E000012 */  beqz       $s0, .L8006F304
    /* 6ACC 8006F2CC 21200002 */   addu      $a0, $s0, $zero
    /* 6AD0 8006F2D0 0800428E */  lw         $v0, 0x8($s2)
    /* 6AD4 8006F2D4 0E80063C */  lui        $a2, %hi(_vlcTable)
    /* 6AD8 8006F2D8 0100422C */  sltiu      $v0, $v0, 0x1
    /* 6ADC 8006F2DC 080042AE */  sw         $v0, 0x8($s2)
    /* 6AE0 8006F2E0 80100200 */  sll        $v0, $v0, 2
    /* 6AE4 8006F2E4 21104202 */  addu       $v0, $s2, $v0
    /* 6AE8 8006F2E8 0000458C */  lw         $a1, 0x0($v0)
    /* 6AEC 8006F2EC 13C9010C */  jal        DecDCTvlc2
    /* 6AF0 8006F2F0 E8EDC624 */   addiu     $a2, $a2, %lo(_vlcTable)
    /* 6AF4 8006F2F4 E588000C */  jal        StFreeRing
    /* 6AF8 8006F2F8 21200002 */   addu      $a0, $s0, $zero
    /* 6AFC 8006F2FC C4BC0108 */  j          .L8006F310
    /* 6B00 8006F300 21100000 */   addu      $v0, $zero, $zero
  .L8006F304:
    /* 6B04 8006F304 FFFF3126 */  addiu      $s1, $s1, -0x1
    /* 6B08 8006F308 ECFF2016 */  bnez       $s1, .L8006F2BC
    /* 6B0C 8006F30C FFFF0224 */   addiu     $v0, $zero, -0x1
  .L8006F310:
    /* 6B10 8006F310 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 6B14 8006F314 1800B28F */  lw         $s2, 0x18($sp)
    /* 6B18 8006F318 1400B18F */  lw         $s1, 0x14($sp)
    /* 6B1C 8006F31C 1000B08F */  lw         $s0, 0x10($sp)
    /* 6B20 8006F320 0800E003 */  jr         $ra
    /* 6B24 8006F324 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel _decodeNextMovieFrame
