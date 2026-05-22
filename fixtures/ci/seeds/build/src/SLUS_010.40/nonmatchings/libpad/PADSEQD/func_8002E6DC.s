nonmatching func_8002E6DC, 0xE0

glabel func_8002E6DC
    /* 1EEDC 8002E6DC E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1EEE0 8002E6E0 1000B0AF */  sw         $s0, 0x10($sp)
    /* 1EEE4 8002E6E4 21808000 */  addu       $s0, $a0, $zero
    /* 1EEE8 8002E6E8 1400BFAF */  sw         $ra, 0x14($sp)
    /* 1EEEC 8002E6EC 4C00028E */  lw         $v0, 0x4C($s0)
    /* 1EEF0 8002E6F0 46000392 */  lbu        $v1, 0x46($s0)
    /* 1EEF4 8002E6F4 01004224 */  addiu      $v0, $v0, 0x1
    /* 1EEF8 8002E6F8 1E006010 */  beqz       $v1, .L8002E774
    /* 1EEFC 8002E6FC 4C0002AE */   sw        $v0, 0x4C($s0)
    /* 1EF00 8002E700 01000224 */  addiu      $v0, $zero, 0x1
    /* 1EF04 8002E704 0B006214 */  bne        $v1, $v0, .L8002E734
    /* 1EF08 8002E708 00000000 */   nop
    /* 1EF0C 8002E70C 4A000392 */  lbu        $v1, 0x4A($s0)
    /* 1EF10 8002E710 00000000 */  nop
    /* 1EF14 8002E714 0B00622C */  sltiu      $v0, $v1, 0xB
    /* 1EF18 8002E718 0B004014 */  bnez       $v0, .L8002E748
    /* 1EF1C 8002E71C 01006224 */   addiu     $v0, $v1, 0x1
    /* 1EF20 8002E720 02000224 */  addiu      $v0, $zero, 0x2
    /* 1EF24 8002E724 490002A2 */  sb         $v0, 0x49($s0)
    /* 1EF28 8002E728 FF000224 */  addiu      $v0, $zero, 0xFF
    /* 1EF2C 8002E72C EBB90008 */  j          .L8002E7AC
    /* 1EF30 8002E730 460002A2 */   sb        $v0, 0x46($s0)
  .L8002E734:
    /* 1EF34 8002E734 4A000392 */  lbu        $v1, 0x4A($s0)
    /* 1EF38 8002E738 00000000 */  nop
    /* 1EF3C 8002E73C 0B00622C */  sltiu      $v0, $v1, 0xB
    /* 1EF40 8002E740 03004010 */  beqz       $v0, .L8002E750
    /* 1EF44 8002E744 01006224 */   addiu     $v0, $v1, 0x1
  .L8002E748:
    /* 1EF48 8002E748 EBB90008 */  j          .L8002E7AC
    /* 1EF4C 8002E74C 4A0002A2 */   sb        $v0, 0x4A($s0)
  .L8002E750:
    /* 1EF50 8002E750 49000292 */  lbu        $v0, 0x49($s0)
    /* 1EF54 8002E754 00000000 */  nop
    /* 1EF58 8002E758 06004010 */  beqz       $v0, .L8002E774
    /* 1EF5C 8002E75C 00000000 */   nop
    /* 1EF60 8002E760 0380023C */  lui        $v0, %hi(D_800335A0)
    /* 1EF64 8002E764 A035428C */  lw         $v0, %lo(D_800335A0)($v0)
    /* 1EF68 8002E768 00000000 */  nop
    /* 1EF6C 8002E76C 09F84000 */  jalr       $v0
    /* 1EF70 8002E770 21200002 */   addu      $a0, $s0, $zero
  .L8002E774:
    /* 1EF74 8002E774 3C00028E */  lw         $v0, 0x3C($s0)
    /* 1EF78 8002E778 00000000 */  nop
    /* 1EF7C 8002E77C 00004390 */  lbu        $v1, 0x0($v0)
    /* 1EF80 8002E780 F3000224 */  addiu      $v0, $zero, 0xF3
    /* 1EF84 8002E784 09006210 */  beq        $v1, $v0, .L8002E7AC
    /* 1EF88 8002E788 FF000324 */   addiu     $v1, $zero, 0xFF
    /* 1EF8C 8002E78C 3000028E */  lw         $v0, 0x30($s0)
    /* 1EF90 8002E790 00000000 */  nop
    /* 1EF94 8002E794 000043A0 */  sb         $v1, 0x0($v0)
    /* 1EF98 8002E798 3000028E */  lw         $v0, 0x30($s0)
    /* 1EF9C 8002E79C 00000000 */  nop
    /* 1EFA0 8002E7A0 010040A0 */  sb         $zero, 0x1($v0)
    /* 1EFA4 8002E7A4 E80000A2 */  sb         $zero, 0xE8($s0)
    /* 1EFA8 8002E7A8 350000A2 */  sb         $zero, 0x35($s0)
  .L8002E7AC:
    /* 1EFAC 8002E7AC 1400BF8F */  lw         $ra, 0x14($sp)
    /* 1EFB0 8002E7B0 1000B08F */  lw         $s0, 0x10($sp)
    /* 1EFB4 8002E7B4 0800E003 */  jr         $ra
    /* 1EFB8 8002E7B8 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8002E6DC
