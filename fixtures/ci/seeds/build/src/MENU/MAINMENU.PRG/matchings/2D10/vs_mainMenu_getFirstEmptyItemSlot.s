nonmatching vs_mainMenu_getFirstEmptyItemSlot, 0x8C

glabel vs_mainMenu_getFirstEmptyItemSlot
    /* 5308 800FEB08 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 530C 800FEB0C 1800B2AF */  sw         $s2, 0x18($sp)
    /* 5310 800FEB10 21908000 */  addu       $s2, $a0, $zero
    /* 5314 800FEB14 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 5318 800FEB18 2198A000 */  addu       $s3, $a1, $zero
    /* 531C 800FEB1C 1080023C */  lui        $v0, %hi(vs_mainMenu_inventoryItemCapacities)
    /* 5320 800FEB20 A0224224 */  addiu      $v0, $v0, %lo(vs_mainMenu_inventoryItemCapacities)
    /* 5324 800FEB24 21184202 */  addu       $v1, $s2, $v0
    /* 5328 800FEB28 2000BFAF */  sw         $ra, 0x20($sp)
    /* 532C 800FEB2C 1400B1AF */  sw         $s1, 0x14($sp)
    /* 5330 800FEB30 1000B0AF */  sw         $s0, 0x10($sp)
    /* 5334 800FEB34 00006290 */  lbu        $v0, 0x0($v1)
    /* 5338 800FEB38 00000000 */  nop
    /* 533C 800FEB3C 0D004010 */  beqz       $v0, .L800FEB74
    /* 5340 800FEB40 21800000 */   addu      $s0, $zero, $zero
    /* 5344 800FEB44 21886000 */  addu       $s1, $v1, $zero
    /* 5348 800FEB48 21204002 */  addu       $a0, $s2, $zero
  .L800FEB4C:
    /* 534C 800FEB4C 21280002 */  addu       $a1, $s0, $zero
    /* 5350 800FEB50 BBF9030C */  jal        _getItemId
    /* 5354 800FEB54 21306002 */   addu      $a2, $s3, $zero
    /* 5358 800FEB58 07004010 */  beqz       $v0, .L800FEB78
    /* 535C 800FEB5C 21100002 */   addu      $v0, $s0, $zero
    /* 5360 800FEB60 00002292 */  lbu        $v0, 0x0($s1)
    /* 5364 800FEB64 01001026 */  addiu      $s0, $s0, 0x1
    /* 5368 800FEB68 2A100202 */  slt        $v0, $s0, $v0
    /* 536C 800FEB6C F7FF4014 */  bnez       $v0, .L800FEB4C
    /* 5370 800FEB70 21204002 */   addu      $a0, $s2, $zero
  .L800FEB74:
    /* 5374 800FEB74 21100002 */  addu       $v0, $s0, $zero
  .L800FEB78:
    /* 5378 800FEB78 2000BF8F */  lw         $ra, 0x20($sp)
    /* 537C 800FEB7C 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 5380 800FEB80 1800B28F */  lw         $s2, 0x18($sp)
    /* 5384 800FEB84 1400B18F */  lw         $s1, 0x14($sp)
    /* 5388 800FEB88 1000B08F */  lw         $s0, 0x10($sp)
    /* 538C 800FEB8C 0800E003 */  jr         $ra
    /* 5390 800FEB90 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel vs_mainMenu_getFirstEmptyItemSlot
