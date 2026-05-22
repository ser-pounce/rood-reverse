nonmatching _getTeleportCost, 0xA0

glabel _getTeleportCost
    /* 268 80102A68 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 26C 80102A6C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 270 80102A70 1400BFAF */  sw         $ra, 0x14($sp)
    /* 274 80102A74 1DF2010C */  jal        vs_battle_getCurrentRoomId
    /* 278 80102A78 21808000 */   addu      $s0, $a0, $zero
    /* 27C 80102A7C 21284000 */  addu       $a1, $v0, $zero
    /* 280 80102A80 21200000 */  addu       $a0, $zero, $zero
    /* 284 80102A84 1080023C */  lui        $v0, %hi(_savePointData)
    /* 288 80102A88 DC674324 */  addiu      $v1, $v0, %lo(_savePointData)
  .L80102A8C:
    /* 28C 80102A8C 00006294 */  lhu        $v0, 0x0($v1)
    /* 290 80102A90 00000000 */  nop
    /* 294 80102A94 06004510 */  beq        $v0, $a1, .L80102AB0
    /* 298 80102A98 2A100402 */   slt       $v0, $s0, $a0
    /* 29C 80102A9C 01008424 */  addiu      $a0, $a0, 0x1
    /* 2A0 80102AA0 30008228 */  slti       $v0, $a0, 0x30
    /* 2A4 80102AA4 F9FF4014 */  bnez       $v0, .L80102A8C
    /* 2A8 80102AA8 04006324 */   addiu     $v1, $v1, 0x4
    /* 2AC 80102AAC 2A100402 */  slt        $v0, $s0, $a0
  .L80102AB0:
    /* 2B0 80102AB0 03004010 */  beqz       $v0, .L80102AC0
    /* 2B4 80102AB4 21188000 */   addu      $v1, $a0, $zero
    /* 2B8 80102AB8 21200002 */  addu       $a0, $s0, $zero
    /* 2BC 80102ABC 21806000 */  addu       $s0, $v1, $zero
  .L80102AC0:
    /* 2C0 80102AC0 21188000 */  addu       $v1, $a0, $zero
    /* 2C4 80102AC4 2A107000 */  slt        $v0, $v1, $s0
    /* 2C8 80102AC8 0A004010 */  beqz       $v0, .L80102AF4
    /* 2CC 80102ACC 0F000524 */   addiu     $a1, $zero, 0xF
    /* 2D0 80102AD0 1080023C */  lui        $v0, %hi(savePointCosts)
    /* 2D4 80102AD4 9C684424 */  addiu      $a0, $v0, %lo(savePointCosts)
    /* 2D8 80102AD8 21106400 */  addu       $v0, $v1, $a0
  .L80102ADC:
    /* 2DC 80102ADC 00004290 */  lbu        $v0, 0x0($v0)
    /* 2E0 80102AE0 01006324 */  addiu      $v1, $v1, 0x1
    /* 2E4 80102AE4 2128A200 */  addu       $a1, $a1, $v0
    /* 2E8 80102AE8 2A107000 */  slt        $v0, $v1, $s0
    /* 2EC 80102AEC FBFF4014 */  bnez       $v0, .L80102ADC
    /* 2F0 80102AF0 21106400 */   addu      $v0, $v1, $a0
  .L80102AF4:
    /* 2F4 80102AF4 1400BF8F */  lw         $ra, 0x14($sp)
    /* 2F8 80102AF8 1000B08F */  lw         $s0, 0x10($sp)
    /* 2FC 80102AFC 2110A000 */  addu       $v0, $a1, $zero
    /* 300 80102B00 0800E003 */  jr         $ra
    /* 304 80102B04 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel _getTeleportCost
