nonmatching _resetMemcardEvents, 0x60

glabel _resetMemcardEvents
    /* 37C 80068B7C E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 380 80068B80 1800B2AF */  sw         $s2, 0x18($sp)
    /* 384 80068B84 21908000 */  addu       $s2, $a0, $zero
    /* 388 80068B88 1000B0AF */  sw         $s0, 0x10($sp)
    /* 38C 80068B8C 21800000 */  addu       $s0, $zero, $zero
    /* 390 80068B90 0E80023C */  lui        $v0, %hi(_memcardEventDescriptors)
    /* 394 80068B94 1400B1AF */  sw         $s1, 0x14($sp)
    /* 398 80068B98 98EA5124 */  addiu      $s1, $v0, %lo(_memcardEventDescriptors)
    /* 39C 80068B9C 1C00BFAF */  sw         $ra, 0x1C($sp)
  .L80068BA0:
    /* 3A0 80068BA0 21101202 */  addu       $v0, $s0, $s2
    /* 3A4 80068BA4 80100200 */  sll        $v0, $v0, 2
    /* 3A8 80068BA8 21105100 */  addu       $v0, $v0, $s1
    /* 3AC 80068BAC 0000448C */  lw         $a0, 0x0($v0)
    /* 3B0 80068BB0 419A000C */  jal        TestEvent
    /* 3B4 80068BB4 01001026 */   addiu     $s0, $s0, 0x1
    /* 3B8 80068BB8 0400022A */  slti       $v0, $s0, 0x4
    /* 3BC 80068BBC F8FF4014 */  bnez       $v0, .L80068BA0
    /* 3C0 80068BC0 00000000 */   nop
    /* 3C4 80068BC4 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 3C8 80068BC8 1800B28F */  lw         $s2, 0x18($sp)
    /* 3CC 80068BCC 1400B18F */  lw         $s1, 0x14($sp)
    /* 3D0 80068BD0 1000B08F */  lw         $s0, 0x10($sp)
    /* 3D4 80068BD4 0800E003 */  jr         $ra
    /* 3D8 80068BD8 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel _resetMemcardEvents
