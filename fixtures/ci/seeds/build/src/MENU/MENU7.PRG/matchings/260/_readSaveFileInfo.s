nonmatching _readSaveFileInfo, 0x118

glabel _readSaveFileInfo
    /* 6F4 80102EF4 D0FDBD27 */  addiu      $sp, $sp, -0x230
    /* 6F8 80102EF8 1402B1AF */  sw         $s1, 0x214($sp)
    /* 6FC 80102EFC 21888000 */  addu       $s1, $a0, $zero
    /* 700 80102F00 2002B4AF */  sw         $s4, 0x220($sp)
    /* 704 80102F04 03A31100 */  sra        $s4, $s1, 12
    /* 708 80102F08 07003132 */  andi       $s1, $s1, 0x7
    /* 70C 80102F0C 1802B2AF */  sw         $s2, 0x218($sp)
    /* 710 80102F10 21900000 */  addu       $s2, $zero, $zero
    /* 714 80102F14 2402B5AF */  sw         $s5, 0x224($sp)
    /* 718 80102F18 1180153C */  lui        $s5, %hi(_saveFileInfo)
    /* 71C 80102F1C C0111100 */  sll        $v0, $s1, 7
    /* 720 80102F20 1C02B3AF */  sw         $s3, 0x21C($sp)
    /* 724 80102F24 80FF5324 */  addiu      $s3, $v0, -0x80
    /* 728 80102F28 2802BFAF */  sw         $ra, 0x228($sp)
    /* 72C 80102F2C 1002B0AF */  sw         $s0, 0x210($sp)
  .L80102F30:
    /* 730 80102F30 21208002 */  addu       $a0, $s4, $zero
    /* 734 80102F34 EF0A040C */  jal        _memcardMakeFilename
    /* 738 80102F38 21282002 */   addu      $a1, $s1, $zero
    /* 73C 80102F3C 21204000 */  addu       $a0, $v0, $zero
    /* 740 80102F40 659A000C */  jal        open
    /* 744 80102F44 01000524 */   addiu     $a1, $zero, 0x1
    /* 748 80102F48 21804000 */  addu       $s0, $v0, $zero
    /* 74C 80102F4C FFFF0224 */  addiu      $v0, $zero, -0x1
    /* 750 80102F50 19000212 */  beq        $s0, $v0, .L80102FB8
    /* 754 80102F54 21200002 */   addu      $a0, $s0, $zero
    /* 758 80102F58 1000A527 */  addiu      $a1, $sp, 0x10
    /* 75C 80102F5C 699A000C */  jal        read
    /* 760 80102F60 00020624 */   addiu     $a2, $zero, 0x200
    /* 764 80102F64 21200002 */  addu       $a0, $s0, $zero
    /* 768 80102F68 719A000C */  jal        close
    /* 76C 80102F6C 21804000 */   addu      $s0, $v0, $zero
    /* 770 80102F70 00020224 */  addiu      $v0, $zero, 0x200
    /* 774 80102F74 10000216 */  bne        $s0, $v0, .L80102FB8
    /* 778 80102F78 9401A527 */   addiu     $a1, $sp, 0x194
    /* 77C 80102F7C 9001A48F */  lw         $a0, 0x190($sp)
    /* 780 80102F80 AF0B040C */  jal        _decode
    /* 784 80102F84 7C000624 */   addiu     $a2, $zero, 0x7C
    /* 788 80102F88 1000A427 */  addiu      $a0, $sp, 0x10
    /* 78C 80102F8C 8A0B040C */  jal        _verifySaveChecksums
    /* 790 80102F90 02000524 */   addiu     $a1, $zero, 0x2
    /* 794 80102F94 09004014 */  bnez       $v0, .L80102FBC
    /* 798 80102F98 01005226 */   addiu     $s2, $s2, 0x1
    /* 79C 80102F9C 9001A527 */  addiu      $a1, $sp, 0x190
    /* 7A0 80102FA0 40AEA48E */  lw         $a0, %lo(_saveFileInfo)($s5)
    /* 7A4 80102FA4 80000624 */  addiu      $a2, $zero, 0x80
    /* 7A8 80102FA8 E70A040C */  jal        _rMemcpy
    /* 7AC 80102FAC 21209300 */   addu      $a0, $a0, $s3
    /* 7B0 80102FB0 FA0B0408 */  j          .L80102FE8
    /* 7B4 80102FB4 21100000 */   addu      $v0, $zero, $zero
  .L80102FB8:
    /* 7B8 80102FB8 01005226 */  addiu      $s2, $s2, 0x1
  .L80102FBC:
    /* 7BC 80102FBC 0300422A */  slti       $v0, $s2, 0x3
    /* 7C0 80102FC0 DBFF4014 */  bnez       $v0, .L80102F30
    /* 7C4 80102FC4 21280000 */   addu      $a1, $zero, $zero
    /* 7C8 80102FC8 80000624 */  addiu      $a2, $zero, 0x80
    /* 7CC 80102FCC 1180023C */  lui        $v0, %hi(_saveFileInfo)
    /* 7D0 80102FD0 C0211100 */  sll        $a0, $s1, 7
    /* 7D4 80102FD4 40AE428C */  lw         $v0, %lo(_saveFileInfo)($v0)
    /* 7D8 80102FD8 80FF8424 */  addiu      $a0, $a0, -0x80
    /* 7DC 80102FDC AD9B000C */  jal        memset
    /* 7E0 80102FE0 21204400 */   addu      $a0, $v0, $a0
    /* 7E4 80102FE4 01000224 */  addiu      $v0, $zero, 0x1
  .L80102FE8:
    /* 7E8 80102FE8 2802BF8F */  lw         $ra, 0x228($sp)
    /* 7EC 80102FEC 2402B58F */  lw         $s5, 0x224($sp)
    /* 7F0 80102FF0 2002B48F */  lw         $s4, 0x220($sp)
    /* 7F4 80102FF4 1C02B38F */  lw         $s3, 0x21C($sp)
    /* 7F8 80102FF8 1802B28F */  lw         $s2, 0x218($sp)
    /* 7FC 80102FFC 1402B18F */  lw         $s1, 0x214($sp)
    /* 800 80103000 1002B08F */  lw         $s0, 0x210($sp)
    /* 804 80103004 0800E003 */  jr         $ra
    /* 808 80103008 3002BD27 */   addiu     $sp, $sp, 0x230
endlabel _readSaveFileInfo
