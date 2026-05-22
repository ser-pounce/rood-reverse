nonmatching _readSaveFileInfo, 0x118

glabel _readSaveFileInfo
    /* 794 80068F94 D0FDBD27 */  addiu      $sp, $sp, -0x230
    /* 798 80068F98 1402B1AF */  sw         $s1, 0x214($sp)
    /* 79C 80068F9C 21888000 */  addu       $s1, $a0, $zero
    /* 7A0 80068FA0 2002B4AF */  sw         $s4, 0x220($sp)
    /* 7A4 80068FA4 03A31100 */  sra        $s4, $s1, 12
    /* 7A8 80068FA8 07003132 */  andi       $s1, $s1, 0x7
    /* 7AC 80068FAC 1802B2AF */  sw         $s2, 0x218($sp)
    /* 7B0 80068FB0 21900000 */  addu       $s2, $zero, $zero
    /* 7B4 80068FB4 2402B5AF */  sw         $s5, 0x224($sp)
    /* 7B8 80068FB8 0E80153C */  lui        $s5, %hi(_saveFileInfo)
    /* 7BC 80068FBC C0111100 */  sll        $v0, $s1, 7
    /* 7C0 80068FC0 1C02B3AF */  sw         $s3, 0x21C($sp)
    /* 7C4 80068FC4 80FF5324 */  addiu      $s3, $v0, -0x80
    /* 7C8 80068FC8 2802BFAF */  sw         $ra, 0x228($sp)
    /* 7CC 80068FCC 1002B0AF */  sw         $s0, 0x210($sp)
  .L80068FD0:
    /* 7D0 80068FD0 21208002 */  addu       $a0, $s4, $zero
    /* 7D4 80068FD4 17A3010C */  jal        _memcardMakeFilename
    /* 7D8 80068FD8 21282002 */   addu      $a1, $s1, $zero
    /* 7DC 80068FDC 21204000 */  addu       $a0, $v0, $zero
    /* 7E0 80068FE0 659A000C */  jal        open
    /* 7E4 80068FE4 01000524 */   addiu     $a1, $zero, 0x1
    /* 7E8 80068FE8 21804000 */  addu       $s0, $v0, $zero
    /* 7EC 80068FEC FFFF0224 */  addiu      $v0, $zero, -0x1
    /* 7F0 80068FF0 19000212 */  beq        $s0, $v0, .L80069058
    /* 7F4 80068FF4 21200002 */   addu      $a0, $s0, $zero
    /* 7F8 80068FF8 1000A527 */  addiu      $a1, $sp, 0x10
    /* 7FC 80068FFC 699A000C */  jal        read
    /* 800 80069000 00020624 */   addiu     $a2, $zero, 0x200
    /* 804 80069004 21200002 */  addu       $a0, $s0, $zero
    /* 808 80069008 719A000C */  jal        close
    /* 80C 8006900C 21804000 */   addu      $s0, $v0, $zero
    /* 810 80069010 00020224 */  addiu      $v0, $zero, 0x200
    /* 814 80069014 10000216 */  bne        $s0, $v0, .L80069058
    /* 818 80069018 9401A527 */   addiu     $a1, $sp, 0x194
    /* 81C 8006901C 9001A48F */  lw         $a0, 0x190($sp)
    /* 820 80069020 D7A3010C */  jal        _decode
    /* 824 80069024 7C000624 */   addiu     $a2, $zero, 0x7C
    /* 828 80069028 1000A427 */  addiu      $a0, $sp, 0x10
    /* 82C 8006902C B2A3010C */  jal        _verifySaveChecksums
    /* 830 80069030 02000524 */   addiu     $a1, $zero, 0x2
    /* 834 80069034 09004014 */  bnez       $v0, .L8006905C
    /* 838 80069038 01005226 */   addiu     $s2, $s2, 0x1
    /* 83C 8006903C 9001A527 */  addiu      $a1, $sp, 0x190
    /* 840 80069040 08EBA48E */  lw         $a0, %lo(_saveFileInfo)($s5)
    /* 844 80069044 80000624 */  addiu      $a2, $zero, 0x80
    /* 848 80069048 0FA3010C */  jal        _rMemcpy
    /* 84C 8006904C 21209300 */   addu      $a0, $a0, $s3
    /* 850 80069050 22A40108 */  j          .L80069088
    /* 854 80069054 21100000 */   addu      $v0, $zero, $zero
  .L80069058:
    /* 858 80069058 01005226 */  addiu      $s2, $s2, 0x1
  .L8006905C:
    /* 85C 8006905C 0300422A */  slti       $v0, $s2, 0x3
    /* 860 80069060 DBFF4014 */  bnez       $v0, .L80068FD0
    /* 864 80069064 21280000 */   addu      $a1, $zero, $zero
    /* 868 80069068 80000624 */  addiu      $a2, $zero, 0x80
    /* 86C 8006906C 0E80023C */  lui        $v0, %hi(_saveFileInfo)
    /* 870 80069070 C0211100 */  sll        $a0, $s1, 7
    /* 874 80069074 08EB428C */  lw         $v0, %lo(_saveFileInfo)($v0)
    /* 878 80069078 80FF8424 */  addiu      $a0, $a0, -0x80
    /* 87C 8006907C AD9B000C */  jal        memset
    /* 880 80069080 21204400 */   addu      $a0, $v0, $a0
    /* 884 80069084 01000224 */  addiu      $v0, $zero, 0x1
  .L80069088:
    /* 888 80069088 2802BF8F */  lw         $ra, 0x228($sp)
    /* 88C 8006908C 2402B58F */  lw         $s5, 0x224($sp)
    /* 890 80069090 2002B48F */  lw         $s4, 0x220($sp)
    /* 894 80069094 1C02B38F */  lw         $s3, 0x21C($sp)
    /* 898 80069098 1802B28F */  lw         $s2, 0x218($sp)
    /* 89C 8006909C 1402B18F */  lw         $s1, 0x214($sp)
    /* 8A0 800690A0 1002B08F */  lw         $s0, 0x210($sp)
    /* 8A4 800690A4 0800E003 */  jr         $ra
    /* 8A8 800690A8 3002BD27 */   addiu     $sp, $sp, 0x230
endlabel _readSaveFileInfo
