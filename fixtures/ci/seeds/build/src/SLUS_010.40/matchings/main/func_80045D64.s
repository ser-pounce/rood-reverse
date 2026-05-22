nonmatching func_80045D64, 0x5C

glabel func_80045D64
    /* 36564 80045D64 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 36568 80045D68 21108000 */  addu       $v0, $a0, $zero
    /* 3656C 80045D6C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 36570 80045D70 2180A000 */  addu       $s0, $a1, $zero
    /* 36574 80045D74 0A000012 */  beqz       $s0, .L80045DA0
    /* 36578 80045D78 1400BFAF */   sw        $ra, 0x14($sp)
    /* 3657C 80045D7C CA16010C */  jal        func_80045B28
    /* 36580 80045D80 00000000 */   nop
    /* 36584 80045D84 03004010 */  beqz       $v0, .L80045D94
    /* 36588 80045D88 21204000 */   addu      $a0, $v0, $zero
    /* 3658C 80045D8C 6A170108 */  j          .L80045DA8
    /* 36590 80045D90 21280000 */   addu      $a1, $zero, $zero
  .L80045D94:
    /* 36594 80045D94 21200002 */  addu       $a0, $s0, $zero
    /* 36598 80045D98 6A170108 */  j          .L80045DA8
    /* 3659C 80045D9C 21280000 */   addu      $a1, $zero, $zero
  .L80045DA0:
    /* 365A0 80045DA0 21200000 */  addu       $a0, $zero, $zero
    /* 365A4 80045DA4 21284000 */  addu       $a1, $v0, $zero
  .L80045DA8:
    /* 365A8 80045DA8 A248000C */  jal        func_80012288
    /* 365AC 80045DAC 00000000 */   nop
    /* 365B0 80045DB0 1400BF8F */  lw         $ra, 0x14($sp)
    /* 365B4 80045DB4 1000B08F */  lw         $s0, 0x10($sp)
    /* 365B8 80045DB8 0800E003 */  jr         $ra
    /* 365BC 80045DBC 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80045D64
