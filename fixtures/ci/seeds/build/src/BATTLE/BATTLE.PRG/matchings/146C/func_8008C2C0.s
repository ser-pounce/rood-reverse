nonmatching func_8008C2C0, 0x14C

glabel func_8008C2C0
    /* 23AC0 8008C2C0 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 23AC4 8008C2C4 1400B1AF */  sw         $s1, 0x14($sp)
    /* 23AC8 8008C2C8 21888000 */  addu       $s1, $a0, $zero
    /* 23ACC 8008C2CC 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 23AD0 8008C2D0 2198A000 */  addu       $s3, $a1, $zero
    /* 23AD4 8008C2D4 2000B4AF */  sw         $s4, 0x20($sp)
    /* 23AD8 8008C2D8 21A0C000 */  addu       $s4, $a2, $zero
    /* 23ADC 8008C2DC 0F80023C */  lui        $v0, %hi(vs_battle_roomData)
    /* 23AE0 8008C2E0 1000B0AF */  sw         $s0, 0x10($sp)
    /* 23AE4 8008C2E4 F81B5024 */  addiu      $s0, $v0, %lo(vs_battle_roomData)
    /* 23AE8 8008C2E8 2800BFAF */  sw         $ra, 0x28($sp)
    /* 23AEC 8008C2EC 2400B5AF */  sw         $s5, 0x24($sp)
    /* 23AF0 8008C2F0 1800B2AF */  sw         $s2, 0x18($sp)
    /* 23AF4 8008C2F4 A400028E */  lw         $v0, 0xA4($s0)
    /* 23AF8 8008C2F8 00000000 */  nop
    /* 23AFC 8008C2FC 39004010 */  beqz       $v0, .L8008C3E4
    /* 23B00 8008C300 21A8E000 */   addu      $s5, $a3, $zero
    /* 23B04 8008C304 0331020C */  jal        func_8008C40C
    /* 23B08 8008C308 00000000 */   nop
    /* 23B0C 8008C30C 21300000 */  addu       $a2, $zero, $zero
    /* 23B10 8008C310 801F023C */  lui        $v0, (0x1F800058 >> 16)
    /* 23B14 8008C314 5800428C */  lw         $v0, (0x1F800058 & 0xFFFF)($v0)
    /* 23B18 8008C318 A400058E */  lw         $a1, 0xA4($s0)
    /* 23B1C 8008C31C 4400078E */  lw         $a3, 0x44($s0)
    /* 23B20 8008C320 00094224 */  addiu      $v0, $v0, 0x900
    /* 23B24 8008C324 FF0F4230 */  andi       $v0, $v0, 0xFFF
    /* 23B28 8008C328 2E00E018 */  blez       $a3, .L8008C3E4
    /* 23B2C 8008C32C 43420200 */   sra       $t0, $v0, 9
  .L8008C330:
    /* 23B30 8008C330 0000A394 */  lhu        $v1, 0x0($a1)
    /* 23B34 8008C334 00000000 */  nop
    /* 23B38 8008C338 1F006230 */  andi       $v0, $v1, 0x1F
    /* 23B3C 8008C33C 1E005114 */  bne        $v0, $s1, .L8008C3B8
    /* 23B40 8008C340 2190A000 */   addu      $s2, $a1, $zero
    /* 23B44 8008C344 FFFF6330 */  andi       $v1, $v1, 0xFFFF
    /* 23B48 8008C348 42110300 */  srl        $v0, $v1, 5
    /* 23B4C 8008C34C 1F004230 */  andi       $v0, $v0, 0x1F
    /* 23B50 8008C350 19005314 */  bne        $v0, $s3, .L8008C3B8
    /* 23B54 8008C354 82120300 */   srl       $v0, $v1, 10
    /* 23B58 8008C358 01004230 */  andi       $v0, $v0, 0x1
    /* 23B5C 8008C35C 16005414 */  bne        $v0, $s4, .L8008C3B8
    /* 23B60 8008C360 82130300 */   srl       $v0, $v1, 14
    /* 23B64 8008C364 01004230 */  andi       $v0, $v0, 0x1
    /* 23B68 8008C368 13005514 */  bne        $v0, $s5, .L8008C3B8
    /* 23B6C 8008C36C C2120300 */   srl       $v0, $v1, 11
    /* 23B70 8008C370 07004230 */  andi       $v0, $v0, 0x7
    /* 23B74 8008C374 10004814 */  bne        $v0, $t0, .L8008C3B8
    /* 23B78 8008C378 00000000 */   nop
    /* 23B7C 8008C37C 0400B124 */  addiu      $s1, $a1, 0x4
    /* 23B80 8008C380 0200A294 */  lhu        $v0, 0x2($a1)
    /* 23B84 8008C384 00000000 */  nop
    /* 23B88 8008C388 09004010 */  beqz       $v0, .L8008C3B0
    /* 23B8C 8008C38C 21800000 */   addu      $s0, $zero, $zero
  .L8008C390:
    /* 23B90 8008C390 00002492 */  lbu        $a0, 0x0($s1)
    /* 23B94 8008C394 B046020C */  jal        func_80091AC0
    /* 23B98 8008C398 01001026 */   addiu     $s0, $s0, 0x1
    /* 23B9C 8008C39C 02004296 */  lhu        $v0, 0x2($s2)
    /* 23BA0 8008C3A0 00000000 */  nop
    /* 23BA4 8008C3A4 2A100202 */  slt        $v0, $s0, $v0
    /* 23BA8 8008C3A8 F9FF4014 */  bnez       $v0, .L8008C390
    /* 23BAC 8008C3AC 01003126 */   addiu     $s1, $s1, 0x1
  .L8008C3B0:
    /* 23BB0 8008C3B0 FA300208 */  j          .L8008C3E8
    /* 23BB4 8008C3B4 01000224 */   addiu     $v0, $zero, 0x1
  .L8008C3B8:
    /* 23BB8 8008C3B8 02004396 */  lhu        $v1, 0x2($s2)
    /* 23BBC 8008C3BC 04000224 */  addiu      $v0, $zero, 0x4
    /* 23BC0 8008C3C0 03006430 */  andi       $a0, $v1, 0x3
    /* 23BC4 8008C3C4 23104400 */  subu       $v0, $v0, $a0
    /* 23BC8 8008C3C8 03004230 */  andi       $v0, $v0, 0x3
    /* 23BCC 8008C3CC 21186200 */  addu       $v1, $v1, $v0
    /* 23BD0 8008C3D0 04007024 */  addiu      $s0, $v1, 0x4
    /* 23BD4 8008C3D4 2130D000 */  addu       $a2, $a2, $s0
    /* 23BD8 8008C3D8 2A10C700 */  slt        $v0, $a2, $a3
    /* 23BDC 8008C3DC D4FF4014 */  bnez       $v0, .L8008C330
    /* 23BE0 8008C3E0 2128B000 */   addu      $a1, $a1, $s0
  .L8008C3E4:
    /* 23BE4 8008C3E4 21100000 */  addu       $v0, $zero, $zero
  .L8008C3E8:
    /* 23BE8 8008C3E8 2800BF8F */  lw         $ra, 0x28($sp)
    /* 23BEC 8008C3EC 2400B58F */  lw         $s5, 0x24($sp)
    /* 23BF0 8008C3F0 2000B48F */  lw         $s4, 0x20($sp)
    /* 23BF4 8008C3F4 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 23BF8 8008C3F8 1800B28F */  lw         $s2, 0x18($sp)
    /* 23BFC 8008C3FC 1400B18F */  lw         $s1, 0x14($sp)
    /* 23C00 8008C400 1000B08F */  lw         $s0, 0x10($sp)
    /* 23C04 8008C404 0800E003 */  jr         $ra
    /* 23C08 8008C408 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel func_8008C2C0
