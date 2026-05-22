nonmatching func_800A9E38, 0x7C

glabel func_800A9E38
    /* 41638 800A9E38 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 4163C 800A9E3C 2138C000 */  addu       $a3, $a2, $zero
    /* 41640 800A9E40 0F80023C */  lui        $v0, %hi(D_800F4538)
    /* 41644 800A9E44 38454224 */  addiu      $v0, $v0, %lo(D_800F4538)
    /* 41648 800A9E48 80180400 */  sll        $v1, $a0, 2
    /* 4164C 800A9E4C 21186200 */  addu       $v1, $v1, $v0
    /* 41650 800A9E50 FFFF0224 */  addiu      $v0, $zero, -0x1
    /* 41654 800A9E54 1800BFAF */  sw         $ra, 0x18($sp)
    /* 41658 800A9E58 1400B1AF */  sw         $s1, 0x14($sp)
    /* 4165C 800A9E5C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 41660 800A9E60 0000718C */  lw         $s1, 0x0($v1)
    /* 41664 800A9E64 0700E214 */  bne        $a3, $v0, .L800A9E84
    /* 41668 800A9E68 FFFF0624 */   addiu     $a2, $zero, -0x1
    /* 4166C 800A9E6C 002C0500 */  sll        $a1, $a1, 16
    /* 41670 800A9E70 032C0500 */  sra        $a1, $a1, 16
    /* 41674 800A9E74 61AA020C */  jal        func_800AA984
    /* 41678 800A9E78 21304000 */   addu      $a2, $v0, $zero
    /* 4167C 800A9E7C A7A70208 */  j          .L800A9E9C
    /* 41680 800A9E80 00000000 */   nop
  .L800A9E84:
    /* 41684 800A9E84 002C0500 */  sll        $a1, $a1, 16
    /* 41688 800A9E88 032C0500 */  sra        $a1, $a1, 16
    /* 4168C 800A9E8C C0053096 */  lhu        $s0, 0x5C0($s1)
    /* 41690 800A9E90 61AA020C */  jal        func_800AA984
    /* 41694 800A9E94 C00527A6 */   sh        $a3, 0x5C0($s1)
    /* 41698 800A9E98 C00530A6 */  sh         $s0, 0x5C0($s1)
  .L800A9E9C:
    /* 4169C 800A9E9C 1800BF8F */  lw         $ra, 0x18($sp)
    /* 416A0 800A9EA0 1400B18F */  lw         $s1, 0x14($sp)
    /* 416A4 800A9EA4 1000B08F */  lw         $s0, 0x10($sp)
    /* 416A8 800A9EA8 2000BD27 */  addiu      $sp, $sp, 0x20
    /* 416AC 800A9EAC 0800E003 */  jr         $ra
    /* 416B0 800A9EB0 00000000 */   nop
endlabel func_800A9E38
