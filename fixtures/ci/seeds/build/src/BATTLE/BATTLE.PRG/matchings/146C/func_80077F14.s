nonmatching func_80077F14, 0x5C

glabel func_80077F14
    /* F714 80077F14 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* F718 80077F18 1000B0AF */  sw         $s0, 0x10($sp)
    /* F71C 80077F1C 21808000 */  addu       $s0, $a0, $zero
    /* F720 80077F20 1400B1AF */  sw         $s1, 0x14($sp)
    /* F724 80077F24 2188C000 */  addu       $s1, $a2, $zero
    /* F728 80077F28 FFFF0224 */  addiu      $v0, $zero, -0x1
    /* F72C 80077F2C 0300A214 */  bne        $a1, $v0, .L80077F3C
    /* F730 80077F30 1800BFAF */   sw        $ra, 0x18($sp)
    /* F734 80077F34 D2DF0108 */  j          .L80077F48
    /* F738 80077F38 21100000 */   addu      $v0, $zero, $zero
  .L80077F3C:
    /* F73C 80077F3C 21200002 */  addu       $a0, $s0, $zero
    /* F740 80077F40 4B85020C */  jal        func_800A152C
    /* F744 80077F44 02000624 */   addiu     $a2, $zero, 0x2
  .L80077F48:
    /* F748 80077F48 21200002 */  addu       $a0, $s0, $zero
    /* F74C 80077F4C 21284000 */  addu       $a1, $v0, $zero
    /* F750 80077F50 21302002 */  addu       $a2, $s1, $zero
    /* F754 80077F54 BE86020C */  jal        func_800A1AF8
    /* F758 80077F58 21380000 */   addu      $a3, $zero, $zero
    /* F75C 80077F5C 1800BF8F */  lw         $ra, 0x18($sp)
    /* F760 80077F60 1400B18F */  lw         $s1, 0x14($sp)
    /* F764 80077F64 1000B08F */  lw         $s0, 0x10($sp)
    /* F768 80077F68 0800E003 */  jr         $ra
    /* F76C 80077F6C 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_80077F14
