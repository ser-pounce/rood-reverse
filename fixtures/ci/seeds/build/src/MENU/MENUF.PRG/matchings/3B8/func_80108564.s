nonmatching func_80108564, 0x70

glabel func_80108564
    /* 5D64 80108564 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 5D68 80108568 1400B1AF */  sw         $s1, 0x14($sp)
    /* 5D6C 8010856C 21888000 */  addu       $s1, $a0, $zero
    /* 5D70 80108570 1000B0AF */  sw         $s0, 0x10($sp)
    /* 5D74 80108574 2180A000 */  addu       $s0, $a1, $zero
    /* 5D78 80108578 02000106 */  bgez       $s0, .L80108584
    /* 5D7C 8010857C 1800BFAF */   sw        $ra, 0x18($sp)
    /* 5D80 80108580 21800000 */  addu       $s0, $zero, $zero
  .L80108584:
    /* 5D84 80108584 4100022A */  slti       $v0, $s0, 0x41
    /* 5D88 80108588 02004014 */  bnez       $v0, .L80108594
    /* 5D8C 8010858C 00000000 */   nop
    /* 5D90 80108590 40001024 */  addiu      $s0, $zero, 0x40
  .L80108594:
    /* 5D94 80108594 0A00001A */  blez       $s0, .L801085C0
    /* 5D98 80108598 21200000 */   addu      $a0, $zero, $zero
    /* 5D9C 8010859C 21282002 */  addu       $a1, $s1, $zero
    /* 5DA0 801085A0 7D000624 */  addiu      $a2, $zero, 0x7D
    /* 5DA4 801085A4 0D17040C */  jal        func_80105C34
    /* 5DA8 801085A8 21380002 */   addu      $a3, $s0, $zero
    /* 5DAC 801085AC A0000424 */  addiu      $a0, $zero, 0xA0
    /* 5DB0 801085B0 21282002 */  addu       $a1, $s1, $zero
    /* 5DB4 801085B4 7E000624 */  addiu      $a2, $zero, 0x7E
    /* 5DB8 801085B8 0D17040C */  jal        func_80105C34
    /* 5DBC 801085BC 21380002 */   addu      $a3, $s0, $zero
  .L801085C0:
    /* 5DC0 801085C0 1800BF8F */  lw         $ra, 0x18($sp)
    /* 5DC4 801085C4 1400B18F */  lw         $s1, 0x14($sp)
    /* 5DC8 801085C8 1000B08F */  lw         $s0, 0x10($sp)
    /* 5DCC 801085CC 0800E003 */  jr         $ra
    /* 5DD0 801085D0 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_80108564
