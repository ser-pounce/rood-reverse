nonmatching func_800A6EE8, 0x1F4

glabel func_800A6EE8
    /* 3E6E8 800A6EE8 C8FFBD27 */  addiu      $sp, $sp, -0x38
    /* 3E6EC 800A6EEC 2C00B5AF */  sw         $s5, 0x2C($sp)
    /* 3E6F0 800A6EF0 21A88000 */  addu       $s5, $a0, $zero
    /* 3E6F4 800A6EF4 1000A427 */  addiu      $a0, $sp, 0x10
    /* 3E6F8 800A6EF8 3000BFAF */  sw         $ra, 0x30($sp)
    /* 3E6FC 800A6EFC 2800B4AF */  sw         $s4, 0x28($sp)
    /* 3E700 800A6F00 2400B3AF */  sw         $s3, 0x24($sp)
    /* 3E704 800A6F04 2000B2AF */  sw         $s2, 0x20($sp)
    /* 3E708 800A6F08 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 3E70C 800A6F0C 1800B0AF */  sw         $s0, 0x18($sp)
    /* 3E710 800A6F10 0000A286 */  lh         $v0, 0x0($s5)
    /* 3E714 800A6F14 21A0E000 */  addu       $s4, $a3, $zero
    /* 3E718 800A6F18 2190A200 */  addu       $s2, $a1, $v0
    /* 3E71C 800A6F1C 0400A286 */  lh         $v0, 0x4($s5)
    /* 3E720 800A6F20 21280000 */  addu       $a1, $zero, $zero
    /* 3E724 800A6F24 1000B2A7 */  sh         $s2, 0x10($sp)
    /* 3E728 800A6F28 2188C200 */  addu       $s1, $a2, $v0
    /* 3E72C 800A6F2C 59A3020C */  jal        func_800A8D64
    /* 3E730 800A6F30 1400B1A7 */   sh        $s1, 0x14($sp)
    /* 3E734 800A6F34 21984000 */  addu       $s3, $v0, $zero
    /* 3E738 800A6F38 5A006012 */  beqz       $s3, .L800A70A4
    /* 3E73C 800A6F3C 0F80023C */   lui       $v0, %hi(D_800F49F0)
    /* 3E740 800A6F40 06008016 */  bnez       $s4, .L800A6F5C
    /* 3E744 800A6F44 F04953AC */   sw        $s3, %lo(D_800F49F0)($v0)
    /* 3E748 800A6F48 21204002 */  addu       $a0, $s2, $zero
    /* 3E74C 800A6F4C 1F37020C */  jal        func_8008DC7C
    /* 3E750 800A6F50 21282002 */   addu      $a1, $s1, $zero
    /* 3E754 800A6F54 DB9B0208 */  j          .L800A6F6C
    /* 3E758 800A6F58 00140200 */   sll       $v0, $v0, 16
  .L800A6F5C:
    /* 3E75C 800A6F5C 21204002 */  addu       $a0, $s2, $zero
    /* 3E760 800A6F60 8936020C */  jal        func_8008DA24
    /* 3E764 800A6F64 21282002 */   addu      $a1, $s1, $zero
    /* 3E768 800A6F68 00140200 */  sll        $v0, $v0, 16
  .L800A6F6C:
    /* 3E76C 800A6F6C 03840200 */  sra        $s0, $v0, 16
    /* 3E770 800A6F70 4C000006 */  bltz       $s0, .L800A70A4
    /* 3E774 800A6F74 40841000 */   sll       $s0, $s0, 17
    /* 3E778 800A6F78 02000224 */  addiu      $v0, $zero, 0x2
    /* 3E77C 800A6F7C 0D008216 */  bne        $s4, $v0, .L800A6FB4
    /* 3E780 800A6F80 43841000 */   sra       $s0, $s0, 17
    /* 3E784 800A6F84 02004106 */  bgez       $s2, .L800A6F90
    /* 3E788 800A6F88 21204002 */   addu      $a0, $s2, $zero
    /* 3E78C 800A6F8C 7F004426 */  addiu      $a0, $s2, 0x7F
  .L800A6F90:
    /* 3E790 800A6F90 21282002 */  addu       $a1, $s1, $zero
    /* 3E794 800A6F94 02002106 */  bgez       $s1, .L800A6FA0
    /* 3E798 800A6F98 C3210400 */   sra       $a0, $a0, 7
    /* 3E79C 800A6F9C 7F002526 */  addiu      $a1, $s1, 0x7F
  .L800A6FA0:
    /* 3E7A0 800A6FA0 0200A686 */  lh         $a2, 0x2($s5)
    /* 3E7A4 800A6FA4 F3C4020C */  jal        func_800B13CC
    /* 3E7A8 800A6FA8 C3290500 */   sra       $a1, $a1, 7
    /* 3E7AC 800A6FAC F79B0208 */  j          .L800A6FDC
    /* 3E7B0 800A6FB0 21204000 */   addu      $a0, $v0, $zero
  .L800A6FB4:
    /* 3E7B4 800A6FB4 02004106 */  bgez       $s2, .L800A6FC0
    /* 3E7B8 800A6FB8 21204002 */   addu      $a0, $s2, $zero
    /* 3E7BC 800A6FBC 7F004426 */  addiu      $a0, $s2, 0x7F
  .L800A6FC0:
    /* 3E7C0 800A6FC0 21282002 */  addu       $a1, $s1, $zero
    /* 3E7C4 800A6FC4 02002106 */  bgez       $s1, .L800A6FD0
    /* 3E7C8 800A6FC8 C3210400 */   sra       $a0, $a0, 7
    /* 3E7CC 800A6FCC 7F002526 */  addiu      $a1, $s1, 0x7F
  .L800A6FD0:
    /* 3E7D0 800A6FD0 AEA4020C */  jal        func_800A92B8
    /* 3E7D4 800A6FD4 C3290500 */   sra       $a1, $a1, 7
    /* 3E7D8 800A6FD8 21204000 */  addu       $a0, $v0, $zero
  .L800A6FDC:
    /* 3E7DC 800A6FDC 02008010 */  beqz       $a0, .L800A6FE8
    /* 3E7E0 800A6FE0 00000000 */   nop
    /* 3E7E4 800A6FE4 21808000 */  addu       $s0, $a0, $zero
  .L800A6FE8:
    /* 3E7E8 800A6FE8 0000638E */  lw         $v1, 0x0($s3)
    /* 3E7EC 800A6FEC 00000000 */  nop
    /* 3E7F0 800A6FF0 42140300 */  srl        $v0, $v1, 17
    /* 3E7F4 800A6FF4 01004230 */  andi       $v0, $v0, 0x1
    /* 3E7F8 800A6FF8 0F004010 */  beqz       $v0, .L800A7038
    /* 3E7FC 800A6FFC 02000224 */   addiu     $v0, $zero, 0x2
    /* 3E800 800A7000 0C000006 */  bltz       $s0, .L800A7034
    /* 3E804 800A7004 03000224 */   addiu     $v0, $zero, 0x3
    /* 3E808 800A7008 0A008216 */  bne        $s4, $v0, .L800A7034
    /* 3E80C 800A700C B80B1024 */   addiu     $s0, $zero, 0xBB8
    /* 3E810 800A7010 1F006230 */  andi       $v0, $v1, 0x1F
    /* 3E814 800A7014 0F80033C */  lui        $v1, %hi(D_800E9278)
    /* 3E818 800A7018 78926324 */  addiu      $v1, $v1, %lo(D_800E9278)
    /* 3E81C 800A701C 21104300 */  addu       $v0, $v0, $v1
    /* 3E820 800A7020 00004390 */  lbu        $v1, 0x0($v0)
    /* 3E824 800A7024 14000224 */  addiu      $v0, $zero, 0x14
    /* 3E828 800A7028 03006214 */  bne        $v1, $v0, .L800A7038
    /* 3E82C 800A702C 02000224 */   addiu     $v0, $zero, 0x2
    /* 3E830 800A7030 21800000 */  addu       $s0, $zero, $zero
  .L800A7034:
    /* 3E834 800A7034 02000224 */  addiu      $v0, $zero, 0x2
  .L800A7038:
    /* 3E838 800A7038 18008212 */  beq        $s4, $v0, .L800A709C
    /* 3E83C 800A703C 04000224 */   addiu     $v0, $zero, 0x4
    /* 3E840 800A7040 16008212 */  beq        $s4, $v0, .L800A709C
    /* 3E844 800A7044 21204002 */   addu      $a0, $s2, $zero
    /* 3E848 800A7048 0200A586 */  lh         $a1, 0x2($s5)
    /* 3E84C 800A704C 21302002 */  addu       $a2, $s1, $zero
    /* 3E850 800A7050 DEA4020C */  jal        func_800A9378
    /* 3E854 800A7054 21380000 */   addu      $a3, $zero, $zero
    /* 3E858 800A7058 21184000 */  addu       $v1, $v0, $zero
    /* 3E85C 800A705C 05006010 */  beqz       $v1, .L800A7074
    /* 3E860 800A7060 21200002 */   addu      $a0, $s0, $zero
    /* 3E864 800A7064 2A107000 */  slt        $v0, $v1, $s0
    /* 3E868 800A7068 03004010 */  beqz       $v0, .L800A7078
    /* 3E86C 800A706C 03000224 */   addiu     $v0, $zero, 0x3
    /* 3E870 800A7070 21806000 */  addu       $s0, $v1, $zero
  .L800A7074:
    /* 3E874 800A7074 03000224 */  addiu      $v0, $zero, 0x3
  .L800A7078:
    /* 3E878 800A7078 0E008216 */  bne        $s4, $v0, .L800A70B4
    /* 3E87C 800A707C 21100002 */   addu      $v0, $s0, $zero
    /* 3E880 800A7080 0200A286 */  lh         $v0, 0x2($s5)
    /* 3E884 800A7084 00000000 */  nop
    /* 3E888 800A7088 C0FF4224 */  addiu      $v0, $v0, -0x40
    /* 3E88C 800A708C 2A100202 */  slt        $v0, $s0, $v0
    /* 3E890 800A7090 08004010 */  beqz       $v0, .L800A70B4
    /* 3E894 800A7094 21100002 */   addu      $v0, $s0, $zero
    /* 3E898 800A7098 21808000 */  addu       $s0, $a0, $zero
  .L800A709C:
    /* 3E89C 800A709C 2D9C0208 */  j          .L800A70B4
    /* 3E8A0 800A70A0 21100002 */   addu      $v0, $s0, $zero
  .L800A70A4:
    /* 3E8A4 800A70A4 03000224 */  addiu      $v0, $zero, 0x3
    /* 3E8A8 800A70A8 02008216 */  bne        $s4, $v0, .L800A70B4
    /* 3E8AC 800A70AC 48F40224 */   addiu     $v0, $zero, -0xBB8
    /* 3E8B0 800A70B0 0200A286 */  lh         $v0, 0x2($s5)
  .L800A70B4:
    /* 3E8B4 800A70B4 3000BF8F */  lw         $ra, 0x30($sp)
    /* 3E8B8 800A70B8 2C00B58F */  lw         $s5, 0x2C($sp)
    /* 3E8BC 800A70BC 2800B48F */  lw         $s4, 0x28($sp)
    /* 3E8C0 800A70C0 2400B38F */  lw         $s3, 0x24($sp)
    /* 3E8C4 800A70C4 2000B28F */  lw         $s2, 0x20($sp)
    /* 3E8C8 800A70C8 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 3E8CC 800A70CC 1800B08F */  lw         $s0, 0x18($sp)
    /* 3E8D0 800A70D0 3800BD27 */  addiu      $sp, $sp, 0x38
    /* 3E8D4 800A70D4 0800E003 */  jr         $ra
    /* 3E8D8 800A70D8 00000000 */   nop
endlabel func_800A6EE8
