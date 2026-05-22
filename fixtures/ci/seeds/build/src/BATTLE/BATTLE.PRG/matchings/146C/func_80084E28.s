nonmatching func_80084E28, 0x78

glabel func_80084E28
    /* 1C628 80084E28 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 1C62C 80084E2C 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 1C630 80084E30 21888000 */  addu       $s1, $a0, $zero
    /* 1C634 80084E34 1800B0AF */  sw         $s0, 0x18($sp)
    /* 1C638 80084E38 2180C000 */  addu       $s0, $a2, $zero
    /* 1C63C 80084E3C 3800A28F */  lw         $v0, 0x38($sp)
    /* 1C640 80084E40 2000BFAF */  sw         $ra, 0x20($sp)
    /* 1C644 80084E44 3B0E020C */  jal        _calculateDamage
    /* 1C648 80084E48 1000A2AF */   sw        $v0, 0x10($sp)
    /* 1C64C 80084E4C FCFF0324 */  addiu      $v1, $zero, -0x4
    /* 1C650 80084E50 21304000 */  addu       $a2, $v0, $zero
    /* 1C654 80084E54 1C00048E */  lw         $a0, 0x1C($s0)
    /* 1C658 80084E58 04000296 */  lhu        $v0, 0x4($s0)
    /* 1C65C 80084E5C 24208300 */  and        $a0, $a0, $v1
    /* 1C660 80084E60 02008434 */  ori        $a0, $a0, 0x2
    /* 1C664 80084E64 4000038E */  lw         $v1, 0x40($s0)
    /* 1C668 80084E68 21104600 */  addu       $v0, $v0, $a2
    /* 1C66C 80084E6C 040002A6 */  sh         $v0, 0x4($s0)
    /* 1C670 80084E70 06006014 */  bnez       $v1, .L80084E8C
    /* 1C674 80084E74 1C0004AE */   sw        $a0, 0x1C($s0)
    /* 1C678 80084E78 21202002 */  addu       $a0, $s1, $zero
    /* 1C67C 80084E7C 21280002 */  addu       $a1, $s0, $zero
    /* 1C680 80084E80 00340600 */  sll        $a2, $a2, 16
    /* 1C684 80084E84 7800020C */  jal        func_800801E0
    /* 1C688 80084E88 03340600 */   sra       $a2, $a2, 16
  .L80084E8C:
    /* 1C68C 80084E8C 2000BF8F */  lw         $ra, 0x20($sp)
    /* 1C690 80084E90 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 1C694 80084E94 1800B08F */  lw         $s0, 0x18($sp)
    /* 1C698 80084E98 0800E003 */  jr         $ra
    /* 1C69C 80084E9C 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_80084E28
