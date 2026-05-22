nonmatching func_800A3394, 0x16C

glabel func_800A3394
    /* 3AB94 800A3394 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 3AB98 800A3398 2000B2AF */  sw         $s2, 0x20($sp)
    /* 3AB9C 800A339C 21908000 */  addu       $s2, $a0, $zero
    /* 3ABA0 800A33A0 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 3ABA4 800A33A4 2188A000 */  addu       $s1, $a1, $zero
    /* 3ABA8 800A33A8 1800B0AF */  sw         $s0, 0x18($sp)
    /* 3ABAC 800A33AC 0F80103C */  lui        $s0, %hi(D_800F4538)
    /* 3ABB0 800A33B0 38451026 */  addiu      $s0, $s0, %lo(D_800F4538)
    /* 3ABB4 800A33B4 80101200 */  sll        $v0, $s2, 2
    /* 3ABB8 800A33B8 21105000 */  addu       $v0, $v0, $s0
    /* 3ABBC 800A33BC 2800BFAF */  sw         $ra, 0x28($sp)
    /* 3ABC0 800A33C0 2400B3AF */  sw         $s3, 0x24($sp)
    /* 3ABC4 800A33C4 00002396 */  lhu        $v1, 0x0($s1)
    /* 3ABC8 800A33C8 0000538C */  lw         $s3, 0x0($v0)
    /* 3ABCC 800A33CC 1000A3A7 */  sh         $v1, 0x10($sp)
    /* 3ABD0 800A33D0 04002296 */  lhu        $v0, 0x4($s1)
    /* 3ABD4 800A33D4 00000000 */  nop
    /* 3ABD8 800A33D8 1400A2A7 */  sh         $v0, 0x14($sp)
    /* 3ABDC 800A33DC 02002296 */  lhu        $v0, 0x2($s1)
    /* 3ABE0 800A33E0 00000000 */  nop
    /* 3ABE4 800A33E4 40FF4224 */  addiu      $v0, $v0, -0xC0
    /* 3ABE8 800A33E8 7B9D030C */  jal        func_800E75EC
    /* 3ABEC 800A33EC 1200A2A7 */   sh        $v0, 0x12($sp)
    /* 3ABF0 800A33F0 21484000 */  addu       $t1, $v0, $zero
    /* 3ABF4 800A33F4 21400000 */  addu       $t0, $zero, $zero
    /* 3ABF8 800A33F8 1000A727 */  addiu      $a3, $sp, 0x10
    /* 3ABFC 800A33FC 20000A3C */  lui        $t2, (0x200000 >> 16)
  .L800A3400:
    /* 3AC00 800A3400 02000524 */  addiu      $a1, $zero, 0x2
    /* 3AC04 800A3404 2A10B200 */  slt        $v0, $a1, $s2
    /* 3AC08 800A3408 1B004010 */  beqz       $v0, .L800A3478
    /* 3AC0C 800A340C 21100000 */   addu      $v0, $zero, $zero
    /* 3AC10 800A3410 08000626 */  addiu      $a2, $s0, 0x8
  .L800A3414:
    /* 3AC14 800A3414 0000C48C */  lw         $a0, 0x0($a2)
    /* 3AC18 800A3418 00000000 */  nop
    /* 3AC1C 800A341C 11008010 */  beqz       $a0, .L800A3464
    /* 3AC20 800A3420 00000000 */   nop
    /* 3AC24 800A3424 0800828C */  lw         $v0, 0x8($a0)
    /* 3AC28 800A3428 00000000 */  nop
    /* 3AC2C 800A342C 24104A00 */  and        $v0, $v0, $t2
    /* 3AC30 800A3430 0C004010 */  beqz       $v0, .L800A3464
    /* 3AC34 800A3434 00000000 */   nop
    /* 3AC38 800A3438 1C00838C */  lw         $v1, 0x1C($a0)
    /* 3AC3C 800A343C 0000E28C */  lw         $v0, 0x0($a3)
    /* 3AC40 800A3440 00000000 */  nop
    /* 3AC44 800A3444 07006214 */  bne        $v1, $v0, .L800A3464
    /* 3AC48 800A3448 00000000 */   nop
    /* 3AC4C 800A344C 0400E294 */  lhu        $v0, 0x4($a3)
    /* 3AC50 800A3450 20008384 */  lh         $v1, 0x20($a0)
    /* 3AC54 800A3454 00140200 */  sll        $v0, $v0, 16
    /* 3AC58 800A3458 03140200 */  sra        $v0, $v0, 16
    /* 3AC5C 800A345C 06006210 */  beq        $v1, $v0, .L800A3478
    /* 3AC60 800A3460 2110A000 */   addu      $v0, $a1, $zero
  .L800A3464:
    /* 3AC64 800A3464 0100A524 */  addiu      $a1, $a1, 0x1
    /* 3AC68 800A3468 2A10B200 */  slt        $v0, $a1, $s2
    /* 3AC6C 800A346C E9FF4014 */  bnez       $v0, .L800A3414
    /* 3AC70 800A3470 0400C624 */   addiu     $a2, $a2, 0x4
    /* 3AC74 800A3474 21100000 */  addu       $v0, $zero, $zero
  .L800A3478:
    /* 3AC78 800A3478 06004010 */  beqz       $v0, .L800A3494
    /* 3AC7C 800A347C 00000000 */   nop
    /* 3AC80 800A3480 1200A297 */  lhu        $v0, 0x12($sp)
    /* 3AC84 800A3484 00000000 */  nop
    /* 3AC88 800A3488 40FF4224 */  addiu      $v0, $v0, -0xC0
    /* 3AC8C 800A348C 008D0208 */  j          .L800A3400
    /* 3AC90 800A3490 1200A2A7 */   sh        $v0, 0x12($sp)
  .L800A3494:
    /* 3AC94 800A3494 0F002011 */  beqz       $t1, .L800A34D4
    /* 3AC98 800A3498 00000000 */   nop
    /* 3AC9C 800A349C 1200A287 */  lh         $v0, 0x12($sp)
    /* 3ACA0 800A34A0 3E066396 */  lhu        $v1, 0x63E($s3)
    /* 3ACA4 800A34A4 00000000 */  nop
    /* 3ACA8 800A34A8 23104300 */  subu       $v0, $v0, $v1
    /* 3ACAC 800A34AC 2A104900 */  slt        $v0, $v0, $t1
    /* 3ACB0 800A34B0 08004010 */  beqz       $v0, .L800A34D4
    /* 3ACB4 800A34B4 00000000 */   nop
    /* 3ACB8 800A34B8 09000015 */  bnez       $t0, .L800A34E0
    /* 3ACBC 800A34BC 01000824 */   addiu     $t0, $zero, 0x1
    /* 3ACC0 800A34C0 02002296 */  lhu        $v0, 0x2($s1)
    /* 3ACC4 800A34C4 00000000 */  nop
    /* 3ACC8 800A34C8 A0FF4224 */  addiu      $v0, $v0, -0x60
    /* 3ACCC 800A34CC 008D0208 */  j          .L800A3400
    /* 3ACD0 800A34D0 1200A2A7 */   sh        $v0, 0x12($sp)
  .L800A34D4:
    /* 3ACD4 800A34D4 1200A297 */  lhu        $v0, 0x12($sp)
    /* 3ACD8 800A34D8 00000000 */  nop
    /* 3ACDC 800A34DC 020022A6 */  sh         $v0, 0x2($s1)
  .L800A34E0:
    /* 3ACE0 800A34E0 2800BF8F */  lw         $ra, 0x28($sp)
    /* 3ACE4 800A34E4 2400B38F */  lw         $s3, 0x24($sp)
    /* 3ACE8 800A34E8 2000B28F */  lw         $s2, 0x20($sp)
    /* 3ACEC 800A34EC 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 3ACF0 800A34F0 1800B08F */  lw         $s0, 0x18($sp)
    /* 3ACF4 800A34F4 3000BD27 */  addiu      $sp, $sp, 0x30
    /* 3ACF8 800A34F8 0800E003 */  jr         $ra
    /* 3ACFC 800A34FC 00000000 */   nop
endlabel func_800A3394
