nonmatching _dropMiscRand, 0x74

glabel _dropMiscRand
    /* 35F0 8006BDF0 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 35F4 8006BDF4 1400B1AF */  sw         $s1, 0x14($sp)
    /* 35F8 8006BDF8 2188A000 */  addu       $s1, $a1, $zero
    /* 35FC 8006BDFC 1800BFAF */  sw         $ra, 0x18($sp)
    /* 3600 8006BE00 1000B0AF */  sw         $s0, 0x10($sp)
    /* 3604 8006BE04 00002296 */  lhu        $v0, 0x0($s1)
    /* 3608 8006BE08 21808000 */  addu       $s0, $a0, $zero
    /* 360C 8006BE0C 1C0202A6 */  sh         $v0, 0x21C($s0)
    /* 3610 8006BE10 FFFF4230 */  andi       $v0, $v0, 0xFFFF
    /* 3614 8006BE14 0E004010 */  beqz       $v0, .L8006BE50
    /* 3618 8006BE18 21100000 */   addu      $v0, $zero, $zero
    /* 361C 8006BE1C EA09010C */  jal        vs_main_getRand
    /* 3620 8006BE20 FF000424 */   addiu     $a0, $zero, 0xFF
    /* 3624 8006BE24 02002392 */  lbu        $v1, 0x2($s1)
    /* 3628 8006BE28 00000000 */  nop
    /* 362C 8006BE2C 2A104300 */  slt        $v0, $v0, $v1
    /* 3630 8006BE30 06004010 */  beqz       $v0, .L8006BE4C
    /* 3634 8006BE34 01000224 */   addiu     $v0, $zero, 0x1
    /* 3638 8006BE38 21184000 */  addu       $v1, $v0, $zero
    /* 363C 8006BE3C 1F0203A2 */  sb         $v1, 0x21F($s0)
    /* 3640 8006BE40 03000324 */  addiu      $v1, $zero, 0x3
    /* 3644 8006BE44 94AF0108 */  j          .L8006BE50
    /* 3648 8006BE48 1E0203A2 */   sb        $v1, 0x21E($s0)
  .L8006BE4C:
    /* 364C 8006BE4C 21100000 */  addu       $v0, $zero, $zero
  .L8006BE50:
    /* 3650 8006BE50 1800BF8F */  lw         $ra, 0x18($sp)
    /* 3654 8006BE54 1400B18F */  lw         $s1, 0x14($sp)
    /* 3658 8006BE58 1000B08F */  lw         $s0, 0x10($sp)
    /* 365C 8006BE5C 0800E003 */  jr         $ra
    /* 3660 8006BE60 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel _dropMiscRand
