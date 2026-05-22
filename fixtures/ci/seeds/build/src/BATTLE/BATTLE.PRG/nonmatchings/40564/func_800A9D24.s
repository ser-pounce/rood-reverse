nonmatching func_800A9D24, 0x6C

glabel func_800A9D24
    /* 41524 800A9D24 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 41528 800A9D28 2138C000 */  addu       $a3, $a2, $zero
    /* 4152C 800A9D2C 0F80023C */  lui        $v0, %hi(D_800F4538)
    /* 41530 800A9D30 38454224 */  addiu      $v0, $v0, %lo(D_800F4538)
    /* 41534 800A9D34 80180400 */  sll        $v1, $a0, 2
    /* 41538 800A9D38 21186200 */  addu       $v1, $v1, $v0
    /* 4153C 800A9D3C FFFF0224 */  addiu      $v0, $zero, -0x1
    /* 41540 800A9D40 1800BFAF */  sw         $ra, 0x18($sp)
    /* 41544 800A9D44 1400B1AF */  sw         $s1, 0x14($sp)
    /* 41548 800A9D48 1000B0AF */  sw         $s0, 0x10($sp)
    /* 4154C 800A9D4C 0000718C */  lw         $s1, 0x0($v1)
    /* 41550 800A9D50 0500E214 */  bne        $a3, $v0, .L800A9D68
    /* 41554 800A9D54 FFFF0624 */   addiu     $a2, $zero, -0x1
    /* 41558 800A9D58 A6A9020C */  jal        func_800AA698
    /* 4155C 800A9D5C 21304000 */   addu      $a2, $v0, $zero
    /* 41560 800A9D60 5EA70208 */  j          .L800A9D78
    /* 41564 800A9D64 00000000 */   nop
  .L800A9D68:
    /* 41568 800A9D68 C2053096 */  lhu        $s0, 0x5C2($s1)
    /* 4156C 800A9D6C A6A9020C */  jal        func_800AA698
    /* 41570 800A9D70 C20527A6 */   sh        $a3, 0x5C2($s1)
    /* 41574 800A9D74 C20530A6 */  sh         $s0, 0x5C2($s1)
  .L800A9D78:
    /* 41578 800A9D78 1800BF8F */  lw         $ra, 0x18($sp)
    /* 4157C 800A9D7C 1400B18F */  lw         $s1, 0x14($sp)
    /* 41580 800A9D80 1000B08F */  lw         $s0, 0x10($sp)
    /* 41584 800A9D84 2000BD27 */  addiu      $sp, $sp, 0x20
    /* 41588 800A9D88 0800E003 */  jr         $ra
    /* 4158C 800A9D8C 00000000 */   nop
endlabel func_800A9D24
