nonmatching _resetMemcardEvents, 0x60

glabel _resetMemcardEvents
    /* 2DC 80102ADC E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 2E0 80102AE0 1800B2AF */  sw         $s2, 0x18($sp)
    /* 2E4 80102AE4 21908000 */  addu       $s2, $a0, $zero
    /* 2E8 80102AE8 1000B0AF */  sw         $s0, 0x10($sp)
    /* 2EC 80102AEC 21800000 */  addu       $s0, $zero, $zero
    /* 2F0 80102AF0 1180023C */  lui        $v0, %hi(_memcardEventDescriptors)
    /* 2F4 80102AF4 1400B1AF */  sw         $s1, 0x14($sp)
    /* 2F8 80102AF8 D0AD5124 */  addiu      $s1, $v0, %lo(_memcardEventDescriptors)
    /* 2FC 80102AFC 1C00BFAF */  sw         $ra, 0x1C($sp)
  .L80102B00:
    /* 300 80102B00 21101202 */  addu       $v0, $s0, $s2
    /* 304 80102B04 80100200 */  sll        $v0, $v0, 2
    /* 308 80102B08 21105100 */  addu       $v0, $v0, $s1
    /* 30C 80102B0C 0000448C */  lw         $a0, 0x0($v0)
    /* 310 80102B10 419A000C */  jal        TestEvent
    /* 314 80102B14 01001026 */   addiu     $s0, $s0, 0x1
    /* 318 80102B18 0400022A */  slti       $v0, $s0, 0x4
    /* 31C 80102B1C F8FF4014 */  bnez       $v0, .L80102B00
    /* 320 80102B20 00000000 */   nop
    /* 324 80102B24 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 328 80102B28 1800B28F */  lw         $s2, 0x18($sp)
    /* 32C 80102B2C 1400B18F */  lw         $s1, 0x14($sp)
    /* 330 80102B30 1000B08F */  lw         $s0, 0x10($sp)
    /* 334 80102B34 0800E003 */  jr         $ra
    /* 338 80102B38 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel _resetMemcardEvents
