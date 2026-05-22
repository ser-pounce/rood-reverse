nonmatching func_800AA698, 0x194

glabel func_800AA698
    /* 41E98 800AA698 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 41E9C 800AA69C 0F80023C */  lui        $v0, %hi(D_800F4538)
    /* 41EA0 800AA6A0 38454224 */  addiu      $v0, $v0, %lo(D_800F4538)
    /* 41EA4 800AA6A4 80200400 */  sll        $a0, $a0, 2
    /* 41EA8 800AA6A8 21208200 */  addu       $a0, $a0, $v0
    /* 41EAC 800AA6AC 1800BFAF */  sw         $ra, 0x18($sp)
    /* 41EB0 800AA6B0 1400B1AF */  sw         $s1, 0x14($sp)
    /* 41EB4 800AA6B4 1000B0AF */  sw         $s0, 0x10($sp)
    /* 41EB8 800AA6B8 0000908C */  lw         $s0, 0x0($a0)
    /* 41EBC 800AA6BC 00000000 */  nop
    /* 41EC0 800AA6C0 54000012 */  beqz       $s0, .L800AA814
    /* 41EC4 800AA6C4 2188A000 */   addu      $s1, $a1, $zero
    /* 41EC8 800AA6C8 00002296 */  lhu        $v0, 0x0($s1)
    /* 41ECC 800AA6CC 00000000 */  nop
    /* 41ED0 800AA6D0 340002A6 */  sh         $v0, 0x34($s0)
    /* 41ED4 800AA6D4 02002296 */  lhu        $v0, 0x2($s1)
    /* 41ED8 800AA6D8 00000000 */  nop
    /* 41EDC 800AA6DC 360002A6 */  sh         $v0, 0x36($s0)
    /* 41EE0 800AA6E0 04002396 */  lhu        $v1, 0x4($s1)
    /* 41EE4 800AA6E4 1B00C014 */  bnez       $a2, .L800AA754
    /* 41EE8 800AA6E8 380003A6 */   sh        $v1, 0x38($s0)
    /* 41EEC 800AA6EC 1A0000A6 */  sh         $zero, 0x1A($s0)
  .L800AA6F0:
    /* 41EF0 800AA6F0 1C000296 */  lhu        $v0, 0x1C($s0)
    /* 41EF4 800AA6F4 00002396 */  lhu        $v1, 0x0($s1)
    /* 41EF8 800AA6F8 00000000 */  nop
    /* 41EFC 800AA6FC 21104300 */  addu       $v0, $v0, $v1
    /* 41F00 800AA700 1C0002A6 */  sh         $v0, 0x1C($s0)
    /* 41F04 800AA704 1E000296 */  lhu        $v0, 0x1E($s0)
    /* 41F08 800AA708 02002396 */  lhu        $v1, 0x2($s1)
    /* 41F0C 800AA70C 00000000 */  nop
    /* 41F10 800AA710 21104300 */  addu       $v0, $v0, $v1
    /* 41F14 800AA714 1E0002A6 */  sh         $v0, 0x1E($s0)
    /* 41F18 800AA718 20000296 */  lhu        $v0, 0x20($s0)
    /* 41F1C 800AA71C 04002396 */  lhu        $v1, 0x4($s1)
    /* 41F20 800AA720 1C000486 */  lh         $a0, 0x1C($s0)
    /* 41F24 800AA724 21104300 */  addu       $v0, $v0, $v1
    /* 41F28 800AA728 02008104 */  bgez       $a0, .L800AA734
    /* 41F2C 800AA72C 200002A6 */   sh        $v0, 0x20($s0)
    /* 41F30 800AA730 7F008424 */  addiu      $a0, $a0, 0x7F
  .L800AA734:
    /* 41F34 800AA734 20000386 */  lh         $v1, 0x20($s0)
    /* 41F38 800AA738 C3110400 */  sra        $v0, $a0, 7
    /* 41F3C 800AA73C 02006104 */  bgez       $v1, .L800AA748
    /* 41F40 800AA740 5C0002A2 */   sb        $v0, 0x5C($s0)
    /* 41F44 800AA744 7F006324 */  addiu      $v1, $v1, 0x7F
  .L800AA748:
    /* 41F48 800AA748 C3110300 */  sra        $v0, $v1, 7
    /* 41F4C 800AA74C 05AA0208 */  j          .L800AA814
    /* 41F50 800AA750 5E0002A2 */   sb        $v0, 0x5E($s0)
  .L800AA754:
    /* 41F54 800AA754 FFFF0224 */  addiu      $v0, $zero, -0x1
    /* 41F58 800AA758 2D00C214 */  bne        $a2, $v0, .L800AA810
    /* 41F5C 800AA75C 00000000 */   nop
    /* 41F60 800AA760 34000286 */  lh         $v0, 0x34($s0)
    /* 41F64 800AA764 00000000 */  nop
    /* 41F68 800AA768 18004200 */  mult       $v0, $v0
    /* 41F6C 800AA76C 12100000 */  mflo       $v0
    /* 41F70 800AA770 03004104 */  bgez       $v0, .L800AA780
    /* 41F74 800AA774 21204000 */   addu      $a0, $v0, $zero
    /* 41F78 800AA778 23100200 */  negu       $v0, $v0
    /* 41F7C 800AA77C 21204000 */  addu       $a0, $v0, $zero
  .L800AA780:
    /* 41F80 800AA780 00140300 */  sll        $v0, $v1, 16
    /* 41F84 800AA784 03140200 */  sra        $v0, $v0, 16
    /* 41F88 800AA788 18004200 */  mult       $v0, $v0
    /* 41F8C 800AA78C 12100000 */  mflo       $v0
    /* 41F90 800AA790 02004104 */  bgez       $v0, .L800AA79C
    /* 41F94 800AA794 00000000 */   nop
    /* 41F98 800AA798 23100200 */  negu       $v0, $v0
  .L800AA79C:
    /* 41F9C 800AA79C 21208200 */  addu       $a0, $a0, $v0
    /* 41FA0 800AA7A0 36000286 */  lh         $v0, 0x36($s0)
    /* 41FA4 800AA7A4 00000000 */  nop
    /* 41FA8 800AA7A8 18004200 */  mult       $v0, $v0
    /* 41FAC 800AA7AC 12100000 */  mflo       $v0
    /* 41FB0 800AA7B0 02004104 */  bgez       $v0, .L800AA7BC
    /* 41FB4 800AA7B4 00000000 */   nop
    /* 41FB8 800AA7B8 23100200 */  negu       $v0, $v0
  .L800AA7BC:
    /* 41FBC 800AA7BC E506010C */  jal        vs_gte_rsqrt
    /* 41FC0 800AA7C0 21208200 */   addu      $a0, $a0, $v0
    /* 41FC4 800AA7C4 C2050396 */  lhu        $v1, 0x5C2($s0)
    /* 41FC8 800AA7C8 00000000 */  nop
    /* 41FCC 800AA7CC 18004300 */  mult       $v0, $v1
    /* 41FD0 800AA7D0 12200000 */  mflo       $a0
    /* 41FD4 800AA7D4 02008104 */  bgez       $a0, .L800AA7E0
    /* 41FD8 800AA7D8 21108000 */   addu      $v0, $a0, $zero
    /* 41FDC 800AA7DC 7F008224 */  addiu      $v0, $a0, 0x7F
  .L800AA7E0:
    /* 41FE0 800AA7E0 C3190200 */  sra        $v1, $v0, 7
    /* 41FE4 800AA7E4 7F008230 */  andi       $v0, $a0, 0x7F
    /* 41FE8 800AA7E8 03004010 */  beqz       $v0, .L800AA7F8
    /* 41FEC 800AA7EC 1A0003A6 */   sh        $v1, 0x1A($s0)
    /* 41FF0 800AA7F0 01006224 */  addiu      $v0, $v1, 0x1
    /* 41FF4 800AA7F4 1A0002A6 */  sh         $v0, 0x1A($s0)
  .L800AA7F8:
    /* 41FF8 800AA7F8 1A000296 */  lhu        $v0, 0x1A($s0)
    /* 41FFC 800AA7FC 00000000 */  nop
    /* 42000 800AA800 BBFF4010 */  beqz       $v0, .L800AA6F0
    /* 42004 800AA804 00000000 */   nop
    /* 42008 800AA808 05AA0208 */  j          .L800AA814
    /* 4200C 800AA80C 00000000 */   nop
  .L800AA810:
    /* 42010 800AA810 1A0006A6 */  sh         $a2, 0x1A($s0)
  .L800AA814:
    /* 42014 800AA814 1800BF8F */  lw         $ra, 0x18($sp)
    /* 42018 800AA818 1400B18F */  lw         $s1, 0x14($sp)
    /* 4201C 800AA81C 1000B08F */  lw         $s0, 0x10($sp)
    /* 42020 800AA820 2000BD27 */  addiu      $sp, $sp, 0x20
    /* 42024 800AA824 0800E003 */  jr         $ra
    /* 42028 800AA828 00000000 */   nop
endlabel func_800AA698
