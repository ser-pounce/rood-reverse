nonmatching func_800A3500, 0xA8

glabel func_800A3500
    /* 3AD00 800A3500 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 3AD04 800A3504 1000B0AF */  sw         $s0, 0x10($sp)
    /* 3AD08 800A3508 21808000 */  addu       $s0, $a0, $zero
    /* 3AD0C 800A350C 1400B1AF */  sw         $s1, 0x14($sp)
    /* 3AD10 800A3510 1800BFAF */  sw         $ra, 0x18($sp)
    /* 3AD14 800A3514 8936020C */  jal        func_8008DA24
    /* 3AD18 800A3518 2188A000 */   addu      $s1, $a1, $zero
    /* 3AD1C 800A351C 40240200 */  sll        $a0, $v0, 17
    /* 3AD20 800A3520 43240400 */  sra        $a0, $a0, 17
    /* 3AD24 800A3524 21300000 */  addu       $a2, $zero, $zero
    /* 3AD28 800A3528 0F80023C */  lui        $v0, %hi(D_800F45E0)
    /* 3AD2C 800A352C E0454524 */  addiu      $a1, $v0, %lo(D_800F45E0)
  .L800A3530:
    /* 3AD30 800A3530 0000A38C */  lw         $v1, 0x0($a1)
    /* 3AD34 800A3534 00000000 */  nop
    /* 3AD38 800A3538 10006010 */  beqz       $v1, .L800A357C
    /* 3AD3C 800A353C 00000000 */   nop
    /* 3AD40 800A3540 1C006284 */  lh         $v0, 0x1C($v1)
    /* 3AD44 800A3544 00000000 */  nop
    /* 3AD48 800A3548 0C005014 */  bne        $v0, $s0, .L800A357C
    /* 3AD4C 800A354C 00000000 */   nop
    /* 3AD50 800A3550 20006284 */  lh         $v0, 0x20($v1)
    /* 3AD54 800A3554 00000000 */  nop
    /* 3AD58 800A3558 08005114 */  bne        $v0, $s1, .L800A357C
    /* 3AD5C 800A355C 00000000 */   nop
    /* 3AD60 800A3560 1E006284 */  lh         $v0, 0x1E($v1)
    /* 3AD64 800A3564 00000000 */  nop
    /* 3AD68 800A3568 80FF4324 */  addiu      $v1, $v0, -0x80
    /* 3AD6C 800A356C 2A106400 */  slt        $v0, $v1, $a0
    /* 3AD70 800A3570 02004010 */  beqz       $v0, .L800A357C
    /* 3AD74 800A3574 00000000 */   nop
    /* 3AD78 800A3578 21206000 */  addu       $a0, $v1, $zero
  .L800A357C:
    /* 3AD7C 800A357C 0100C624 */  addiu      $a2, $a2, 0x1
    /* 3AD80 800A3580 1000C228 */  slti       $v0, $a2, 0x10
    /* 3AD84 800A3584 EAFF4014 */  bnez       $v0, .L800A3530
    /* 3AD88 800A3588 0400A524 */   addiu     $a1, $a1, 0x4
    /* 3AD8C 800A358C 21108000 */  addu       $v0, $a0, $zero
    /* 3AD90 800A3590 1800BF8F */  lw         $ra, 0x18($sp)
    /* 3AD94 800A3594 1400B18F */  lw         $s1, 0x14($sp)
    /* 3AD98 800A3598 1000B08F */  lw         $s0, 0x10($sp)
    /* 3AD9C 800A359C 2000BD27 */  addiu      $sp, $sp, 0x20
    /* 3ADA0 800A35A0 0800E003 */  jr         $ra
    /* 3ADA4 800A35A4 00000000 */   nop
endlabel func_800A3500
