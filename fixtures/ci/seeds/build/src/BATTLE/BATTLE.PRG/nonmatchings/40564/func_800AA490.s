nonmatching func_800AA490, 0x170

glabel func_800AA490
    /* 41C90 800AA490 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 41C94 800AA494 2140A000 */  addu       $t0, $a1, $zero
    /* 41C98 800AA498 1400B1AF */  sw         $s1, 0x14($sp)
    /* 41C9C 800AA49C 2188C000 */  addu       $s1, $a2, $zero
    /* 41CA0 800AA4A0 0F80023C */  lui        $v0, %hi(D_800F4538)
    /* 41CA4 800AA4A4 38454224 */  addiu      $v0, $v0, %lo(D_800F4538)
    /* 41CA8 800AA4A8 80200400 */  sll        $a0, $a0, 2
    /* 41CAC 800AA4AC 21208200 */  addu       $a0, $a0, $v0
    /* 41CB0 800AA4B0 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 41CB4 800AA4B4 1800B2AF */  sw         $s2, 0x18($sp)
    /* 41CB8 800AA4B8 1000B0AF */  sw         $s0, 0x10($sp)
    /* 41CBC 800AA4BC 0000908C */  lw         $s0, 0x0($a0)
    /* 41CC0 800AA4C0 00000000 */  nop
    /* 41CC4 800AA4C4 47000012 */  beqz       $s0, .L800AA5E4
    /* 41CC8 800AA4C8 2190E000 */   addu      $s2, $a3, $zero
    /* 41CCC 800AA4CC 00000591 */  lbu        $a1, 0x0($t0)
    /* 41CD0 800AA4D0 5C000392 */  lbu        $v1, 0x5C($s0)
    /* 41CD4 800AA4D4 02000491 */  lbu        $a0, 0x2($t0)
    /* 41CD8 800AA4D8 5E000292 */  lbu        $v0, 0x5E($s0)
    /* 41CDC 800AA4DC 2328A300 */  subu       $a1, $a1, $v1
    /* 41CE0 800AA4E0 0600A014 */  bnez       $a1, .L800AA4FC
    /* 41CE4 800AA4E4 23208200 */   subu      $a0, $a0, $v0
    /* 41CE8 800AA4E8 04008014 */  bnez       $a0, .L800AA4FC
    /* 41CEC 800AA4EC 00000000 */   nop
    /* 41CF0 800AA4F0 03000291 */  lbu        $v0, 0x3($t0)
    /* 41CF4 800AA4F4 49A90208 */  j          .L800AA524
    /* 41CF8 800AA4F8 00290200 */   sll       $a1, $v0, 4
  .L800AA4FC:
    /* 41CFC 800AA4FC DF04010C */  jal        ratan2
    /* 41D00 800AA500 00000000 */   nop
    /* 41D04 800AA504 000C0324 */  addiu      $v1, $zero, 0xC00
    /* 41D08 800AA508 23286200 */  subu       $a1, $v1, $v0
    /* 41D0C 800AA50C 0200A104 */  bgez       $a1, .L800AA518
    /* 41D10 800AA510 2110A000 */   addu      $v0, $a1, $zero
    /* 41D14 800AA514 FF0FA224 */  addiu      $v0, $a1, 0xFFF
  .L800AA518:
    /* 41D18 800AA518 03130200 */  sra        $v0, $v0, 12
    /* 41D1C 800AA51C 00130200 */  sll        $v0, $v0, 12
    /* 41D20 800AA520 2328A200 */  subu       $a1, $a1, $v0
  .L800AA524:
    /* 41D24 800AA524 26000286 */  lh         $v0, 0x26($s0)
    /* 41D28 800AA528 00000000 */  nop
    /* 41D2C 800AA52C 2328A200 */  subu       $a1, $a1, $v0
    /* 41D30 800AA530 0008A228 */  slti       $v0, $a1, 0x800
    /* 41D34 800AA534 03004014 */  bnez       $v0, .L800AA544
    /* 41D38 800AA538 00F8A228 */   slti      $v0, $a1, -0x800
    /* 41D3C 800AA53C 00F0A524 */  addiu      $a1, $a1, -0x1000
    /* 41D40 800AA540 00F8A228 */  slti       $v0, $a1, -0x800
  .L800AA544:
    /* 41D44 800AA544 02004010 */  beqz       $v0, .L800AA550
    /* 41D48 800AA548 00000000 */   nop
    /* 41D4C 800AA54C 0010A524 */  addiu      $a1, $a1, 0x1000
  .L800AA550:
    /* 41D50 800AA550 3E0005A6 */  sh         $a1, 0x3E($s0)
    /* 41D54 800AA554 3C0000A6 */  sh         $zero, 0x3C($s0)
    /* 41D58 800AA558 2200A010 */  beqz       $a1, .L800AA5E4
    /* 41D5C 800AA55C 400000A6 */   sh        $zero, 0x40($s0)
    /* 41D60 800AA560 09002016 */  bnez       $s1, .L800AA588
    /* 41D64 800AA564 FFFF0224 */   addiu     $v0, $zero, -0x1
    /* 41D68 800AA568 180000A6 */  sh         $zero, 0x18($s0)
  .L800AA56C:
    /* 41D6C 800AA56C 26000296 */  lhu        $v0, 0x26($s0)
    /* 41D70 800AA570 3E000396 */  lhu        $v1, 0x3E($s0)
    /* 41D74 800AA574 00000000 */  nop
    /* 41D78 800AA578 21104300 */  addu       $v0, $v0, $v1
    /* 41D7C 800AA57C FF0F4230 */  andi       $v0, $v0, 0xFFF
    /* 41D80 800AA580 79A90208 */  j          .L800AA5E4
    /* 41D84 800AA584 260002A6 */   sh        $v0, 0x26($s0)
  .L800AA588:
    /* 41D88 800AA588 15002216 */  bne        $s1, $v0, .L800AA5E0
    /* 41D8C 800AA58C 00000000 */   nop
    /* 41D90 800AA590 0300A104 */  bgez       $a1, .L800AA5A0
    /* 41D94 800AA594 1800B200 */   mult      $a1, $s2
    /* 41D98 800AA598 23280500 */  negu       $a1, $a1
    /* 41D9C 800AA59C 1800B200 */  mult       $a1, $s2
  .L800AA5A0:
    /* 41DA0 800AA5A0 12280000 */  mflo       $a1
    /* 41DA4 800AA5A4 0200A104 */  bgez       $a1, .L800AA5B0
    /* 41DA8 800AA5A8 2110A000 */   addu      $v0, $a1, $zero
    /* 41DAC 800AA5AC FF0FA224 */  addiu      $v0, $a1, 0xFFF
  .L800AA5B0:
    /* 41DB0 800AA5B0 031B0200 */  sra        $v1, $v0, 12
    /* 41DB4 800AA5B4 FF0FA230 */  andi       $v0, $a1, 0xFFF
    /* 41DB8 800AA5B8 03004010 */  beqz       $v0, .L800AA5C8
    /* 41DBC 800AA5BC 180003A6 */   sh        $v1, 0x18($s0)
    /* 41DC0 800AA5C0 01006224 */  addiu      $v0, $v1, 0x1
    /* 41DC4 800AA5C4 180002A6 */  sh         $v0, 0x18($s0)
  .L800AA5C8:
    /* 41DC8 800AA5C8 18000296 */  lhu        $v0, 0x18($s0)
    /* 41DCC 800AA5CC 00000000 */  nop
    /* 41DD0 800AA5D0 E6FF4010 */  beqz       $v0, .L800AA56C
    /* 41DD4 800AA5D4 00000000 */   nop
    /* 41DD8 800AA5D8 79A90208 */  j          .L800AA5E4
    /* 41DDC 800AA5DC 00000000 */   nop
  .L800AA5E0:
    /* 41DE0 800AA5E0 180011A6 */  sh         $s1, 0x18($s0)
  .L800AA5E4:
    /* 41DE4 800AA5E4 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 41DE8 800AA5E8 1800B28F */  lw         $s2, 0x18($sp)
    /* 41DEC 800AA5EC 1400B18F */  lw         $s1, 0x14($sp)
    /* 41DF0 800AA5F0 1000B08F */  lw         $s0, 0x10($sp)
    /* 41DF4 800AA5F4 2000BD27 */  addiu      $sp, $sp, 0x20
    /* 41DF8 800AA5F8 0800E003 */  jr         $ra
    /* 41DFC 800AA5FC 00000000 */   nop
endlabel func_800AA490
