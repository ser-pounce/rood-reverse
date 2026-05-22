nonmatching VSync, 0x178

glabel VSync
    /* FEC4 8001F6C4 0380023C */  lui        $v0, %hi(D_80030FDC)
    /* FEC8 8001F6C8 DC0F428C */  lw         $v0, %lo(D_80030FDC)($v0)
    /* FECC 8001F6CC 0380053C */  lui        $a1, %hi(D_80030FE0)
    /* FED0 8001F6D0 E00FA58C */  lw         $a1, %lo(D_80030FE0)($a1)
    /* FED4 8001F6D4 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* FED8 8001F6D8 2000BFAF */  sw         $ra, 0x20($sp)
    /* FEDC 8001F6DC 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* FEE0 8001F6E0 1800B0AF */  sw         $s0, 0x18($sp)
    /* FEE4 8001F6E4 0000508C */  lw         $s0, 0x0($v0)
  .L8001F6E8:
    /* FEE8 8001F6E8 0000A28C */  lw         $v0, 0x0($a1)
    /* FEEC 8001F6EC 00000000 */  nop
    /* FEF0 8001F6F0 1000A2AF */  sw         $v0, 0x10($sp)
    /* FEF4 8001F6F4 1000A38F */  lw         $v1, 0x10($sp)
    /* FEF8 8001F6F8 0000A28C */  lw         $v0, 0x0($a1)
    /* FEFC 8001F6FC 00000000 */  nop
    /* FF00 8001F700 F9FF6214 */  bne        $v1, $v0, .L8001F6E8
    /* FF04 8001F704 00000000 */   nop
    /* FF08 8001F708 1000A28F */  lw         $v0, 0x10($sp)
    /* FF0C 8001F70C 0380033C */  lui        $v1, %hi(D_80030FE4)
    /* FF10 8001F710 E40F638C */  lw         $v1, %lo(D_80030FE4)($v1)
    /* FF14 8001F714 00000000 */  nop
    /* FF18 8001F718 23104300 */  subu       $v0, $v0, $v1
    /* FF1C 8001F71C 05008104 */  bgez       $a0, .L8001F734
    /* FF20 8001F720 FFFF5130 */   andi      $s1, $v0, 0xFFFF
    /* FF24 8001F724 0380023C */  lui        $v0, %hi(D_80032114)
    /* FF28 8001F728 1421428C */  lw         $v0, %lo(D_80032114)($v0)
    /* FF2C 8001F72C 0A7E0008 */  j          .L8001F828
    /* FF30 8001F730 00000000 */   nop
  .L8001F734:
    /* FF34 8001F734 01000224 */  addiu      $v0, $zero, 0x1
    /* FF38 8001F738 3A008210 */  beq        $a0, $v0, .L8001F824
    /* FF3C 8001F73C 00000000 */   nop
    /* FF40 8001F740 07008018 */  blez       $a0, .L8001F760
    /* FF44 8001F744 00000000 */   nop
    /* FF48 8001F748 0380023C */  lui        $v0, %hi(D_80030FE8)
    /* FF4C 8001F74C E80F428C */  lw         $v0, %lo(D_80030FE8)($v0)
    /* FF50 8001F750 00000000 */  nop
    /* FF54 8001F754 FFFF4224 */  addiu      $v0, $v0, -0x1
    /* FF58 8001F758 DA7D0008 */  j          .L8001F768
    /* FF5C 8001F75C 21104400 */   addu      $v0, $v0, $a0
  .L8001F760:
    /* FF60 8001F760 0380023C */  lui        $v0, %hi(D_80030FE8)
    /* FF64 8001F764 E80F428C */  lw         $v0, %lo(D_80030FE8)($v0)
  .L8001F768:
    /* FF68 8001F768 02008018 */  blez       $a0, .L8001F774
    /* FF6C 8001F76C 21280000 */   addu      $a1, $zero, $zero
    /* FF70 8001F770 FFFF8524 */  addiu      $a1, $a0, -0x1
  .L8001F774:
    /* FF74 8001F774 0F7E000C */  jal        func_8001F83C
    /* FF78 8001F778 21204000 */   addu      $a0, $v0, $zero
    /* FF7C 8001F77C 0380023C */  lui        $v0, %hi(D_80030FDC)
    /* FF80 8001F780 DC0F428C */  lw         $v0, %lo(D_80030FDC)($v0)
    /* FF84 8001F784 00000000 */  nop
    /* FF88 8001F788 0000508C */  lw         $s0, 0x0($v0)
    /* FF8C 8001F78C 0380043C */  lui        $a0, %hi(D_80032114)
    /* FF90 8001F790 1421848C */  lw         $a0, %lo(D_80032114)($a0)
    /* FF94 8001F794 01000524 */  addiu      $a1, $zero, 0x1
    /* FF98 8001F798 0F7E000C */  jal        func_8001F83C
    /* FF9C 8001F79C 01008424 */   addiu     $a0, $a0, 0x1
    /* FFA0 8001F7A0 4000023C */  lui        $v0, (0x400000 >> 16)
    /* FFA4 8001F7A4 24100202 */  and        $v0, $s0, $v0
    /* FFA8 8001F7A8 0F004010 */  beqz       $v0, .L8001F7E8
    /* FFAC 8001F7AC 00000000 */   nop
    /* FFB0 8001F7B0 0380033C */  lui        $v1, %hi(D_80030FDC)
    /* FFB4 8001F7B4 DC0F638C */  lw         $v1, %lo(D_80030FDC)($v1)
    /* FFB8 8001F7B8 00000000 */  nop
    /* FFBC 8001F7BC 0000628C */  lw         $v0, 0x0($v1)
    /* FFC0 8001F7C0 00000000 */  nop
    /* FFC4 8001F7C4 26100202 */  xor        $v0, $s0, $v0
    /* FFC8 8001F7C8 07004004 */  bltz       $v0, .L8001F7E8
    /* FFCC 8001F7CC 0080043C */   lui       $a0, (0x80000000 >> 16)
  .L8001F7D0:
    /* FFD0 8001F7D0 0000628C */  lw         $v0, 0x0($v1)
    /* FFD4 8001F7D4 00000000 */  nop
    /* FFD8 8001F7D8 26100202 */  xor        $v0, $s0, $v0
    /* FFDC 8001F7DC 24104400 */  and        $v0, $v0, $a0
    /* FFE0 8001F7E0 FBFF4010 */  beqz       $v0, .L8001F7D0
    /* FFE4 8001F7E4 00000000 */   nop
  .L8001F7E8:
    /* FFE8 8001F7E8 0380023C */  lui        $v0, %hi(D_80032114)
    /* FFEC 8001F7EC 1421428C */  lw         $v0, %lo(D_80032114)($v0)
    /* FFF0 8001F7F0 0380043C */  lui        $a0, %hi(D_80030FE0)
    /* FFF4 8001F7F4 E00F848C */  lw         $a0, %lo(D_80030FE0)($a0)
    /* FFF8 8001F7F8 0380013C */  lui        $at, %hi(D_80030FE8)
    /* FFFC 8001F7FC E80F22AC */  sw         $v0, %lo(D_80030FE8)($at)
  .L8001F800:
    /* 10000 8001F800 0000828C */  lw         $v0, 0x0($a0)
    /* 10004 8001F804 0380013C */  lui        $at, %hi(D_80030FE4)
    /* 10008 8001F808 E40F22AC */  sw         $v0, %lo(D_80030FE4)($at)
    /* 1000C 8001F80C 0380033C */  lui        $v1, %hi(D_80030FE4)
    /* 10010 8001F810 E40F638C */  lw         $v1, %lo(D_80030FE4)($v1)
    /* 10014 8001F814 0000828C */  lw         $v0, 0x0($a0)
    /* 10018 8001F818 00000000 */  nop
    /* 1001C 8001F81C F8FF6214 */  bne        $v1, $v0, .L8001F800
    /* 10020 8001F820 00000000 */   nop
  .L8001F824:
    /* 10024 8001F824 21102002 */  addu       $v0, $s1, $zero
  .L8001F828:
    /* 10028 8001F828 2000BF8F */  lw         $ra, 0x20($sp)
    /* 1002C 8001F82C 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 10030 8001F830 1800B08F */  lw         $s0, 0x18($sp)
    /* 10034 8001F834 0800E003 */  jr         $ra
    /* 10038 8001F838 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel VSync
