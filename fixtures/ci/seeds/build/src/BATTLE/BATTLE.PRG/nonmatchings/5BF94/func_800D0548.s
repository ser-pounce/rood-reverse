nonmatching func_800D0548, 0xAC

glabel func_800D0548
    /* 67D48 800D0548 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 67D4C 800D054C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 67D50 800D0550 21808000 */  addu       $s0, $a0, $zero
    /* 67D54 800D0554 1800BFAF */  sw         $ra, 0x18($sp)
    /* 67D58 800D0558 1400B1AF */  sw         $s1, 0x14($sp)
    /* 67D5C 800D055C 00000296 */  lhu        $v0, 0x0($s0)
    /* 67D60 800D0560 00000000 */  nop
    /* 67D64 800D0564 00304330 */  andi       $v1, $v0, 0x3000
    /* 67D68 800D0568 00100224 */  addiu      $v0, $zero, 0x1000
    /* 67D6C 800D056C 08006210 */  beq        $v1, $v0, .L800D0590
    /* 67D70 800D0570 2188A000 */   addu      $s1, $a1, $zero
    /* 67D74 800D0574 01106228 */  slti       $v0, $v1, 0x1001
    /* 67D78 800D0578 0C004014 */  bnez       $v0, .L800D05AC
    /* 67D7C 800D057C 00200224 */   addiu     $v0, $zero, 0x2000
    /* 67D80 800D0580 08006210 */  beq        $v1, $v0, .L800D05A4
    /* 67D84 800D0584 21200002 */   addu      $a0, $s0, $zero
    /* 67D88 800D0588 6B410308 */  j          .L800D05AC
    /* 67D8C 800D058C 00000000 */   nop
  .L800D0590:
    /* 67D90 800D0590 21200002 */  addu       $a0, $s0, $zero
    /* 67D94 800D0594 7940030C */  jal        func_800D01E4
    /* 67D98 800D0598 21282002 */   addu      $a1, $s1, $zero
    /* 67D9C 800D059C 6B410308 */  j          .L800D05AC
    /* 67DA0 800D05A0 00000000 */   nop
  .L800D05A4:
    /* 67DA4 800D05A4 DF40030C */  jal        func_800D037C
    /* 67DA8 800D05A8 21282002 */   addu      $a1, $s1, $zero
  .L800D05AC:
    /* 67DAC 800D05AC 06002296 */  lhu        $v0, 0x6($s1)
    /* 67DB0 800D05B0 00000000 */  nop
    /* 67DB4 800D05B4 04004230 */  andi       $v0, $v0, 0x4
    /* 67DB8 800D05B8 09004010 */  beqz       $v0, .L800D05E0
    /* 67DBC 800D05BC 00000000 */   nop
    /* 67DC0 800D05C0 0E000292 */  lbu        $v0, 0xE($s0)
    /* 67DC4 800D05C4 0E002386 */  lh         $v1, 0xE($s1)
    /* 67DC8 800D05C8 00000000 */  nop
    /* 67DCC 800D05CC 2A104300 */  slt        $v0, $v0, $v1
    /* 67DD0 800D05D0 0E002396 */  lhu        $v1, 0xE($s1)
    /* 67DD4 800D05D4 02004014 */  bnez       $v0, .L800D05E0
    /* 67DD8 800D05D8 01006224 */   addiu     $v0, $v1, 0x1
    /* 67DDC 800D05DC 0E0022A6 */  sh         $v0, 0xE($s1)
  .L800D05E0:
    /* 67DE0 800D05E0 1800BF8F */  lw         $ra, 0x18($sp)
    /* 67DE4 800D05E4 1400B18F */  lw         $s1, 0x14($sp)
    /* 67DE8 800D05E8 1000B08F */  lw         $s0, 0x10($sp)
    /* 67DEC 800D05EC 0800E003 */  jr         $ra
    /* 67DF0 800D05F0 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_800D0548
