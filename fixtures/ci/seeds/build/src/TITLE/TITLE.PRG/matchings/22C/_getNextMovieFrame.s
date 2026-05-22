nonmatching _getNextMovieFrame, 0x104

glabel _getNextMovieFrame
    /* 6B28 8006F328 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 6B2C 8006F32C 2400B1AF */  sw         $s1, 0x24($sp)
    /* 6B30 8006F330 21888000 */  addu       $s1, $a0, $zero
    /* 6B34 8006F334 2000B0AF */  sw         $s0, 0x20($sp)
    /* 6B38 8006F338 D0071024 */  addiu      $s0, $zero, 0x7D0
    /* 6B3C 8006F33C 2800BFAF */  sw         $ra, 0x28($sp)
    /* 6B40 8006F340 1800A427 */  addiu      $a0, $sp, 0x18
  .L8006F344:
    /* 6B44 8006F344 2189000C */  jal        StGetNext
    /* 6B48 8006F348 1C00A527 */   addiu     $a1, $sp, 0x1C
    /* 6B4C 8006F34C 05004010 */  beqz       $v0, .L8006F364
    /* 6B50 8006F350 FFFF1026 */   addiu     $s0, $s0, -0x1
    /* 6B54 8006F354 FBFF0016 */  bnez       $s0, .L8006F344
    /* 6B58 8006F358 1800A427 */   addiu     $a0, $sp, 0x18
    /* 6B5C 8006F35C 06BD0108 */  j          .L8006F418
    /* 6B60 8006F360 21100000 */   addu      $v0, $zero, $zero
  .L8006F364:
    /* 6B64 8006F364 0780103C */  lui        $s0, %hi(_movieWidth)
    /* 6B68 8006F368 1C00A48F */  lw         $a0, 0x1C($sp)
    /* 6B6C 8006F36C AC4A028E */  lw         $v0, %lo(_movieWidth)($s0)
    /* 6B70 8006F370 10008394 */  lhu        $v1, 0x10($a0)
    /* 6B74 8006F374 00000000 */  nop
    /* 6B78 8006F378 06004314 */  bne        $v0, $v1, .L8006F394
    /* 6B7C 8006F37C 0780023C */   lui       $v0, %hi(_movieHeight)
    /* 6B80 8006F380 12008394 */  lhu        $v1, 0x12($a0)
    /* 6B84 8006F384 B04A428C */  lw         $v0, %lo(_movieHeight)($v0)
    /* 6B88 8006F388 00000000 */  nop
    /* 6B8C 8006F38C 14004310 */  beq        $v0, $v1, .L8006F3E0
    /* 6B90 8006F390 0780023C */   lui       $v0, %hi(_movieWidth)
  .L8006F394:
    /* 6B94 8006F394 1000A427 */  addiu      $a0, $sp, 0x10
    /* 6B98 8006F398 21280000 */  addu       $a1, $zero, $zero
    /* 6B9C 8006F39C E0010224 */  addiu      $v0, $zero, 0x1E0
    /* 6BA0 8006F3A0 1400A2A7 */  sh         $v0, 0x14($sp)
    /* 6BA4 8006F3A4 C0010224 */  addiu      $v0, $zero, 0x1C0
    /* 6BA8 8006F3A8 2130A000 */  addu       $a2, $a1, $zero
    /* 6BAC 8006F3AC 2138A000 */  addu       $a3, $a1, $zero
    /* 6BB0 8006F3B0 1000A0A7 */  sh         $zero, 0x10($sp)
    /* 6BB4 8006F3B4 1200A0A7 */  sh         $zero, 0x12($sp)
    /* 6BB8 8006F3B8 F5A1000C */  jal        ClearImage
    /* 6BBC 8006F3BC 1600A2A7 */   sh        $v0, 0x16($sp)
    /* 6BC0 8006F3C0 1C00A38F */  lw         $v1, 0x1C($sp)
    /* 6BC4 8006F3C4 00000000 */  nop
    /* 6BC8 8006F3C8 10006294 */  lhu        $v0, 0x10($v1)
    /* 6BCC 8006F3CC 12006394 */  lhu        $v1, 0x12($v1)
    /* 6BD0 8006F3D0 AC4A02AE */  sw         $v0, %lo(_movieWidth)($s0)
    /* 6BD4 8006F3D4 0780023C */  lui        $v0, %hi(_movieHeight)
    /* 6BD8 8006F3D8 B04A43AC */  sw         $v1, %lo(_movieHeight)($v0)
    /* 6BDC 8006F3DC 0780023C */  lui        $v0, %hi(_movieWidth)
  .L8006F3E0:
    /* 6BE0 8006F3E0 AC4A448C */  lw         $a0, %lo(_movieWidth)($v0)
    /* 6BE4 8006F3E4 1800A28F */  lw         $v0, 0x18($sp)
    /* 6BE8 8006F3E8 40180400 */  sll        $v1, $a0, 1
    /* 6BEC 8006F3EC 21186400 */  addu       $v1, $v1, $a0
    /* 6BF0 8006F3F0 C2270300 */  srl        $a0, $v1, 31
    /* 6BF4 8006F3F4 21186400 */  addu       $v1, $v1, $a0
    /* 6BF8 8006F3F8 0780043C */  lui        $a0, %hi(_movieHeight)
    /* 6BFC 8006F3FC B04A8494 */  lhu        $a0, %lo(_movieHeight)($a0)
    /* 6C00 8006F400 43180300 */  sra        $v1, $v1, 1
    /* 6C04 8006F404 240023A6 */  sh         $v1, 0x24($s1)
    /* 6C08 8006F408 1C0023A6 */  sh         $v1, 0x1C($s1)
    /* 6C0C 8006F40C 260024A6 */  sh         $a0, 0x26($s1)
    /* 6C10 8006F410 1E0024A6 */  sh         $a0, 0x1E($s1)
    /* 6C14 8006F414 320024A6 */  sh         $a0, 0x32($s1)
  .L8006F418:
    /* 6C18 8006F418 2800BF8F */  lw         $ra, 0x28($sp)
    /* 6C1C 8006F41C 2400B18F */  lw         $s1, 0x24($sp)
    /* 6C20 8006F420 2000B08F */  lw         $s0, 0x20($sp)
    /* 6C24 8006F424 0800E003 */  jr         $ra
    /* 6C28 8006F428 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel _getNextMovieFrame
