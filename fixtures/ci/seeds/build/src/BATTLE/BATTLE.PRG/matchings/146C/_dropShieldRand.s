nonmatching _dropShieldRand, 0xC4

glabel _dropShieldRand
    /* 33EC 8006BBEC D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 33F0 8006BBF0 2400B5AF */  sw         $s5, 0x24($sp)
    /* 33F4 8006BBF4 21A88000 */  addu       $s5, $a0, $zero
    /* 33F8 8006BBF8 2000B4AF */  sw         $s4, 0x20($sp)
    /* 33FC 8006BBFC 21A0A000 */  addu       $s4, $a1, $zero
    /* 3400 8006BC00 FF000424 */  addiu      $a0, $zero, 0xFF
    /* 3404 8006BC04 2800BFAF */  sw         $ra, 0x28($sp)
    /* 3408 8006BC08 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 340C 8006BC0C 1800B2AF */  sw         $s2, 0x18($sp)
    /* 3410 8006BC10 1400B1AF */  sw         $s1, 0x14($sp)
    /* 3414 8006BC14 EA09010C */  jal        vs_main_getRand
    /* 3418 8006BC18 1000B0AF */   sw        $s0, 0x10($sp)
    /* 341C 8006BC1C D9008392 */  lbu        $v1, 0xD9($s4)
    /* 3420 8006BC20 00000000 */  nop
    /* 3424 8006BC24 2A104300 */  slt        $v0, $v0, $v1
    /* 3428 8006BC28 17004010 */  beqz       $v0, .L8006BC88
    /* 342C 8006BC2C 0400A426 */   addiu     $a0, $s5, 0x4
    /* 3430 8006BC30 EFAD010C */  jal        vs_battle_copyUiEquipmentStats
    /* 3434 8006BC34 18008526 */   addiu     $a1, $s4, 0x18
    /* 3438 8006BC38 21980000 */  addu       $s3, $zero, $zero
    /* 343C 8006BC3C 48001224 */  addiu      $s2, $zero, 0x48
    /* 3440 8006BC40 2C001124 */  addiu      $s1, $zero, 0x2C
    /* 3444 8006BC44 21808002 */  addu       $s0, $s4, $zero
  .L8006BC48:
    /* 3448 8006BC48 48000296 */  lhu        $v0, 0x48($s0)
    /* 344C 8006BC4C 00000000 */  nop
    /* 3450 8006BC50 03004010 */  beqz       $v0, .L8006BC60
    /* 3454 8006BC54 2120B102 */   addu      $a0, $s5, $s1
    /* 3458 8006BC58 CAAD010C */  jal        vs_battle_copyUiGemStats
    /* 345C 8006BC5C 21289202 */   addu      $a1, $s4, $s2
  .L8006BC60:
    /* 3460 8006BC60 30005226 */  addiu      $s2, $s2, 0x30
    /* 3464 8006BC64 1C003126 */  addiu      $s1, $s1, 0x1C
    /* 3468 8006BC68 01007326 */  addiu      $s3, $s3, 0x1
    /* 346C 8006BC6C 0300622A */  slti       $v0, $s3, 0x3
    /* 3470 8006BC70 F5FF4014 */  bnez       $v0, .L8006BC48
    /* 3474 8006BC74 30001026 */   addiu     $s0, $s0, 0x30
    /* 3478 8006BC78 03000224 */  addiu      $v0, $zero, 0x3
    /* 347C 8006BC7C 0000A2A2 */  sb         $v0, 0x0($s5)
    /* 3480 8006BC80 23AF0108 */  j          .L8006BC8C
    /* 3484 8006BC84 01000224 */   addiu     $v0, $zero, 0x1
  .L8006BC88:
    /* 3488 8006BC88 21100000 */  addu       $v0, $zero, $zero
  .L8006BC8C:
    /* 348C 8006BC8C 2800BF8F */  lw         $ra, 0x28($sp)
    /* 3490 8006BC90 2400B58F */  lw         $s5, 0x24($sp)
    /* 3494 8006BC94 2000B48F */  lw         $s4, 0x20($sp)
    /* 3498 8006BC98 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 349C 8006BC9C 1800B28F */  lw         $s2, 0x18($sp)
    /* 34A0 8006BCA0 1400B18F */  lw         $s1, 0x14($sp)
    /* 34A4 8006BCA4 1000B08F */  lw         $s0, 0x10($sp)
    /* 34A8 8006BCA8 0800E003 */  jr         $ra
    /* 34AC 8006BCAC 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel _dropShieldRand
