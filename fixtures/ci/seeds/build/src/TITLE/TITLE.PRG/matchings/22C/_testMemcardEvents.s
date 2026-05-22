nonmatching _testMemcardEvents, 0x7C

glabel _testMemcardEvents
    /* 300 80068B00 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 304 80068B04 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 308 80068B08 21988000 */  addu       $s3, $a0, $zero
    /* 30C 80068B0C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 310 80068B10 21800000 */  addu       $s0, $zero, $zero
    /* 314 80068B14 0E80023C */  lui        $v0, %hi(_memcardEventDescriptors)
    /* 318 80068B18 1800B2AF */  sw         $s2, 0x18($sp)
    /* 31C 80068B1C 98EA5224 */  addiu      $s2, $v0, %lo(_memcardEventDescriptors)
    /* 320 80068B20 1400B1AF */  sw         $s1, 0x14($sp)
    /* 324 80068B24 01001124 */  addiu      $s1, $zero, 0x1
    /* 328 80068B28 2000BFAF */  sw         $ra, 0x20($sp)
    /* 32C 80068B2C 21101302 */  addu       $v0, $s0, $s3
  .L80068B30:
    /* 330 80068B30 80100200 */  sll        $v0, $v0, 2
    /* 334 80068B34 21105200 */  addu       $v0, $v0, $s2
    /* 338 80068B38 0000448C */  lw         $a0, 0x0($v0)
    /* 33C 80068B3C 419A000C */  jal        TestEvent
    /* 340 80068B40 00000000 */   nop
    /* 344 80068B44 06005110 */  beq        $v0, $s1, .L80068B60
    /* 348 80068B48 21100002 */   addu      $v0, $s0, $zero
    /* 34C 80068B4C 01001026 */  addiu      $s0, $s0, 0x1
    /* 350 80068B50 0400022A */  slti       $v0, $s0, 0x4
    /* 354 80068B54 F6FF4014 */  bnez       $v0, .L80068B30
    /* 358 80068B58 21101302 */   addu      $v0, $s0, $s3
    /* 35C 80068B5C 21100002 */  addu       $v0, $s0, $zero
  .L80068B60:
    /* 360 80068B60 2000BF8F */  lw         $ra, 0x20($sp)
    /* 364 80068B64 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 368 80068B68 1800B28F */  lw         $s2, 0x18($sp)
    /* 36C 80068B6C 1400B18F */  lw         $s1, 0x14($sp)
    /* 370 80068B70 1000B08F */  lw         $s0, 0x10($sp)
    /* 374 80068B74 0800E003 */  jr         $ra
    /* 378 80068B78 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel _testMemcardEvents
