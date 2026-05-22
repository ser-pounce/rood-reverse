nonmatching _testMemcardEvents, 0x7C

glabel _testMemcardEvents
    /* 260 80102A60 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 264 80102A64 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 268 80102A68 21988000 */  addu       $s3, $a0, $zero
    /* 26C 80102A6C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 270 80102A70 21800000 */  addu       $s0, $zero, $zero
    /* 274 80102A74 1180023C */  lui        $v0, %hi(_memcardEventDescriptors)
    /* 278 80102A78 1800B2AF */  sw         $s2, 0x18($sp)
    /* 27C 80102A7C D0AD5224 */  addiu      $s2, $v0, %lo(_memcardEventDescriptors)
    /* 280 80102A80 1400B1AF */  sw         $s1, 0x14($sp)
    /* 284 80102A84 01001124 */  addiu      $s1, $zero, 0x1
    /* 288 80102A88 2000BFAF */  sw         $ra, 0x20($sp)
    /* 28C 80102A8C 21101302 */  addu       $v0, $s0, $s3
  .L80102A90:
    /* 290 80102A90 80100200 */  sll        $v0, $v0, 2
    /* 294 80102A94 21105200 */  addu       $v0, $v0, $s2
    /* 298 80102A98 0000448C */  lw         $a0, 0x0($v0)
    /* 29C 80102A9C 419A000C */  jal        TestEvent
    /* 2A0 80102AA0 00000000 */   nop
    /* 2A4 80102AA4 06005110 */  beq        $v0, $s1, .L80102AC0
    /* 2A8 80102AA8 21100002 */   addu      $v0, $s0, $zero
    /* 2AC 80102AAC 01001026 */  addiu      $s0, $s0, 0x1
    /* 2B0 80102AB0 0400022A */  slti       $v0, $s0, 0x4
    /* 2B4 80102AB4 F6FF4014 */  bnez       $v0, .L80102A90
    /* 2B8 80102AB8 21101302 */   addu      $v0, $s0, $s3
    /* 2BC 80102ABC 21100002 */  addu       $v0, $s0, $zero
  .L80102AC0:
    /* 2C0 80102AC0 2000BF8F */  lw         $ra, 0x20($sp)
    /* 2C4 80102AC4 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 2C8 80102AC8 1800B28F */  lw         $s2, 0x18($sp)
    /* 2CC 80102ACC 1400B18F */  lw         $s1, 0x14($sp)
    /* 2D0 80102AD0 1000B08F */  lw         $s0, 0x10($sp)
    /* 2D4 80102AD4 0800E003 */  jr         $ra
    /* 2D8 80102AD8 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel _testMemcardEvents
