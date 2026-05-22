nonmatching func_800BA194, 0x84

glabel func_800BA194
    /* 51994 800BA194 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 51998 800BA198 1400BFAF */  sw         $ra, 0x14($sp)
    /* 5199C 800BA19C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 519A0 800BA1A0 01008390 */  lbu        $v1, 0x1($a0)
    /* 519A4 800BA1A4 02009090 */  lbu        $s0, 0x2($a0)
    /* 519A8 800BA1A8 05006010 */  beqz       $v1, .L800BA1C0
    /* 519AC 800BA1AC 01000224 */   addiu     $v0, $zero, 0x1
    /* 519B0 800BA1B0 12006210 */  beq        $v1, $v0, .L800BA1FC
    /* 519B4 800BA1B4 00000000 */   nop
    /* 519B8 800BA1B8 81E80208 */  j          .L800BA204
    /* 519BC 800BA1BC 00000000 */   nop
  .L800BA1C0:
    /* 519C0 800BA1C0 0F80023C */  lui        $v0, %hi(D_800F4C2C)
    /* 519C4 800BA1C4 2C4C4390 */  lbu        $v1, %lo(D_800F4C2C)($v0)
    /* 519C8 800BA1C8 02000224 */  addiu      $v0, $zero, 0x2
    /* 519CC 800BA1CC 07006214 */  bne        $v1, $v0, .L800BA1EC
    /* 519D0 800BA1D0 00000000 */   nop
    /* 519D4 800BA1D4 D94D020C */  jal        func_80093764
    /* 519D8 800BA1D8 21200002 */   addu      $a0, $s0, $zero
    /* 519DC 800BA1DC 03004010 */  beqz       $v0, .L800BA1EC
    /* 519E0 800BA1E0 00000000 */   nop
    /* 519E4 800BA1E4 E24D020C */  jal        func_80093788
    /* 519E8 800BA1E8 21200002 */   addu      $a0, $s0, $zero
  .L800BA1EC:
    /* 519EC 800BA1EC 474A020C */  jal        func_8009291C
    /* 519F0 800BA1F0 21200002 */   addu      $a0, $s0, $zero
    /* 519F4 800BA1F4 81E80208 */  j          .L800BA204
    /* 519F8 800BA1F8 00000000 */   nop
  .L800BA1FC:
    /* 519FC 800BA1FC BE4D020C */  jal        func_800936F8
    /* 51A00 800BA200 21200002 */   addu      $a0, $s0, $zero
  .L800BA204:
    /* 51A04 800BA204 1400BF8F */  lw         $ra, 0x14($sp)
    /* 51A08 800BA208 1000B08F */  lw         $s0, 0x10($sp)
    /* 51A0C 800BA20C 21100000 */  addu       $v0, $zero, $zero
    /* 51A10 800BA210 0800E003 */  jr         $ra
    /* 51A14 800BA214 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800BA194
