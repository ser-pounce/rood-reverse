nonmatching func_8008D710, 0x110

glabel func_8008D710
    /* 24F10 8008D710 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 24F14 8008D714 0F80023C */  lui        $v0, %hi(vs_battle_roomData)
    /* 24F18 8008D718 F81B4224 */  addiu      $v0, $v0, %lo(vs_battle_roomData)
    /* 24F1C 8008D71C 2800BFAF */  sw         $ra, 0x28($sp)
    /* 24F20 8008D720 2400B5AF */  sw         $s5, 0x24($sp)
    /* 24F24 8008D724 2000B4AF */  sw         $s4, 0x20($sp)
    /* 24F28 8008D728 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 24F2C 8008D72C 1800B2AF */  sw         $s2, 0x18($sp)
    /* 24F30 8008D730 1400B1AF */  sw         $s1, 0x14($sp)
    /* 24F34 8008D734 1000B0AF */  sw         $s0, 0x10($sp)
    /* 24F38 8008D738 AC00448C */  lw         $a0, 0xAC($v0)
    /* 24F3C 8008D73C 00000000 */  nop
    /* 24F40 8008D740 2E008010 */  beqz       $a0, .L8008D7FC
    /* 24F44 8008D744 193A033C */   lui       $v1, (0x3A196B1F >> 16)
    /* 24F48 8008D748 4C00428C */  lw         $v0, 0x4C($v0)
    /* 24F4C 8008D74C 1F6B6334 */  ori        $v1, $v1, (0x3A196B1F & 0xFFFF)
    /* 24F50 8008D750 19004300 */  multu      $v0, $v1
    /* 24F54 8008D754 21988000 */  addu       $s3, $a0, $zero
    /* 24F58 8008D758 10380000 */  mfhi       $a3
    /* 24F5C 8008D75C C2A10700 */  srl        $s4, $a3, 7
    /* 24F60 8008D760 26008012 */  beqz       $s4, .L8008D7FC
    /* 24F64 8008D764 21900000 */   addu      $s2, $zero, $zero
    /* 24F68 8008D768 FFE31524 */  addiu      $s5, $zero, -0x1C01
    /* 24F6C 8008D76C 08007126 */  addiu      $s1, $s3, 0x8
  .L8008D770:
    /* 24F70 8008D770 00006486 */  lh         $a0, 0x0($s3)
    /* 24F74 8008D774 FAFF2586 */  lh         $a1, -0x6($s1)
    /* 24F78 8008D778 FCFF2686 */  lh         $a2, -0x4($s1)
    /* 24F7C 8008D77C D92D020C */  jal        func_8008B764
    /* 24F80 8008D780 00000000 */   nop
    /* 24F84 8008D784 08002496 */  lhu        $a0, 0x8($s1)
    /* 24F88 8008D788 21804000 */  addu       $s0, $v0, $zero
    /* 24F8C 8008D78C C0038424 */  addiu      $a0, $a0, 0x3C0
    /* 24F90 8008D790 00240400 */  sll        $a0, $a0, 16
    /* 24F94 8008D794 FDFA020C */  jal        vs_battle_getStateFlag
    /* 24F98 8008D798 03240400 */   sra       $a0, $a0, 16
    /* 24F9C 8008D79C FF004230 */  andi       $v0, $v0, 0xFF
    /* 24FA0 8008D7A0 0B004010 */  beqz       $v0, .L8008D7D0
    /* 24FA4 8008D7A4 01000224 */   addiu     $v0, $zero, 0x1
    /* 24FA8 8008D7A8 FEFF2486 */  lh         $a0, -0x2($s1)
    /* 24FAC 8008D7AC 094E020C */  jal        func_80093824
    /* 24FB0 8008D7B0 000022A6 */   sh        $v0, 0x0($s1)
    /* 24FB4 8008D7B4 0C000012 */  beqz       $s0, .L8008D7E8
    /* 24FB8 8008D7B8 00000000 */   nop
    /* 24FBC 8008D7BC 0000028E */  lw         $v0, 0x0($s0)
    /* 24FC0 8008D7C0 00000000 */  nop
    /* 24FC4 8008D7C4 24105500 */  and        $v0, $v0, $s5
    /* 24FC8 8008D7C8 F9350208 */  j          .L8008D7E4
    /* 24FCC 8008D7CC 00144234 */   ori       $v0, $v0, 0x1400
  .L8008D7D0:
    /* 24FD0 8008D7D0 05000012 */  beqz       $s0, .L8008D7E8
    /* 24FD4 8008D7D4 000020A6 */   sh        $zero, 0x0($s1)
    /* 24FD8 8008D7D8 0000028E */  lw         $v0, 0x0($s0)
    /* 24FDC 8008D7DC 00000000 */  nop
    /* 24FE0 8008D7E0 24105500 */  and        $v0, $v0, $s5
  .L8008D7E4:
    /* 24FE4 8008D7E4 000002AE */  sw         $v0, 0x0($s0)
  .L8008D7E8:
    /* 24FE8 8008D7E8 01005226 */  addiu      $s2, $s2, 0x1
    /* 24FEC 8008D7EC 34023126 */  addiu      $s1, $s1, 0x234
    /* 24FF0 8008D7F0 2A105402 */  slt        $v0, $s2, $s4
    /* 24FF4 8008D7F4 DEFF4014 */  bnez       $v0, .L8008D770
    /* 24FF8 8008D7F8 34027326 */   addiu     $s3, $s3, 0x234
  .L8008D7FC:
    /* 24FFC 8008D7FC 2800BF8F */  lw         $ra, 0x28($sp)
    /* 25000 8008D800 2400B58F */  lw         $s5, 0x24($sp)
    /* 25004 8008D804 2000B48F */  lw         $s4, 0x20($sp)
    /* 25008 8008D808 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 2500C 8008D80C 1800B28F */  lw         $s2, 0x18($sp)
    /* 25010 8008D810 1400B18F */  lw         $s1, 0x14($sp)
    /* 25014 8008D814 1000B08F */  lw         $s0, 0x10($sp)
    /* 25018 8008D818 0800E003 */  jr         $ra
    /* 2501C 8008D81C 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel func_8008D710
