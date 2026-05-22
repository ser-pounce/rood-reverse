nonmatching _combineArmor, 0x24C

glabel _combineArmor
    /* 900C 8010B80C C8FFBD27 */  addiu      $sp, $sp, -0x38
    /* 9010 8010B810 2800B4AF */  sw         $s4, 0x28($sp)
    /* 9014 8010B814 21A08000 */  addu       $s4, $a0, $zero
    /* 9018 8010B818 2C00B5AF */  sw         $s5, 0x2C($sp)
    /* 901C 8010B81C 21A8A000 */  addu       $s5, $a1, $zero
    /* 9020 8010B820 2400B3AF */  sw         $s3, 0x24($sp)
    /* 9024 8010B824 2198C000 */  addu       $s3, $a2, $zero
    /* 9028 8010B828 21206002 */  addu       $a0, $s3, $zero
    /* 902C 8010B82C 21288002 */  addu       $a1, $s4, $zero
    /* 9030 8010B830 28000624 */  addiu      $a2, $zero, 0x28
    /* 9034 8010B834 3000BFAF */  sw         $ra, 0x30($sp)
    /* 9038 8010B838 2000B2AF */  sw         $s2, 0x20($sp)
    /* 903C 8010B83C 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 9040 8010B840 1800B0AF */  sw         $s0, 0x18($sp)
    /* 9044 8010B844 0000E28C */  lw         $v0, 0x0($a3)
    /* 9048 8010B848 1180113C */  lui        $s1, %hi(_combinationResults)
    /* 904C 8010B84C 2110E200 */  addu       $v0, $a3, $v0
    /* 9050 8010B850 80BD22AE */  sw         $v0, %lo(_combinationResults)($s1)
    /* 9054 8010B854 0400E28C */  lw         $v0, 0x4($a3)
    /* 9058 8010B858 1180103C */  lui        $s0, %hi(_materialResults)
    /* 905C 8010B85C 2110E200 */  addu       $v0, $a3, $v0
    /* 9060 8010B860 84BD02AE */  sw         $v0, %lo(_materialResults)($s0)
    /* 9064 8010B864 0800E28C */  lw         $v0, 0x8($a3)
    /* 9068 8010B868 1180123C */  lui        $s2, %hi(_combinationInitData)
    /* 906C 8010B86C 2138E200 */  addu       $a3, $a3, $v0
    /* 9070 8010B870 2C24010C */  jal        vs_main_memcpy
    /* 9074 8010B874 90BD47AE */   sw        $a3, %lo(_combinationInitData)($s2)
    /* 9078 8010B878 2400A396 */  lhu        $v1, 0x24($s5)
    /* 907C 8010B87C 24008496 */  lhu        $a0, 0x24($s4)
    /* 9080 8010B880 03008292 */  lbu        $v0, 0x3($s4)
    /* 9084 8010B884 80180300 */  sll        $v1, $v1, 2
    /* 9088 8010B888 C0210400 */  sll        $a0, $a0, 7
    /* 908C 8010B88C 40110200 */  sll        $v0, $v0, 5
    /* 9090 8010B890 21208200 */  addu       $a0, $a0, $v0
    /* 9094 8010B894 21186400 */  addu       $v1, $v1, $a0
    /* 9098 8010B898 0300A292 */  lbu        $v0, 0x3($s5)
    /* 909C 8010B89C 84BD048E */  lw         $a0, %lo(_materialResults)($s0)
    /* 90A0 8010B8A0 21186200 */  addu       $v1, $v1, $v0
    /* 90A4 8010B8A4 21186400 */  addu       $v1, $v1, $a0
    /* 90A8 8010B8A8 BEFF6290 */  lbu        $v0, -0x42($v1)
    /* 90AC 8010B8AC 00000000 */  nop
    /* 90B0 8010B8B0 240062A6 */  sh         $v0, 0x24($s3)
    /* 90B4 8010B8B4 01008392 */  lbu        $v1, 0x1($s4)
    /* 90B8 8010B8B8 00000000 */  nop
    /* 90BC 8010B8BC 80110300 */  sll        $v0, $v1, 6
    /* 90C0 8010B8C0 21104300 */  addu       $v0, $v0, $v1
    /* 90C4 8010B8C4 0100A392 */  lbu        $v1, 0x1($s5)
    /* 90C8 8010B8C8 80BD248E */  lw         $a0, %lo(_combinationResults)($s1)
    /* 90CC 8010B8CC 21104300 */  addu       $v0, $v0, $v1
    /* 90D0 8010B8D0 21104400 */  addu       $v0, $v0, $a0
    /* 90D4 8010B8D4 E0FB4290 */  lbu        $v0, -0x420($v0)
    /* 90D8 8010B8D8 24006396 */  lhu        $v1, 0x24($s3)
    /* 90DC 8010B8DC 0580053C */  lui        $a1, %hi(vs_main_materialModifiers)
    /* 90E0 8010B8E0 010062A2 */  sb         $v0, 0x1($s3)
    /* 90E4 8010B8E4 7E004224 */  addiu      $v0, $v0, 0x7E
    /* 90E8 8010B8E8 000062A2 */  sb         $v0, 0x0($s3)
    /* 90EC 8010B8EC 01006292 */  lbu        $v0, 0x1($s3)
    /* 90F0 8010B8F0 90BD468E */  lw         $a2, %lo(_combinationInitData)($s2)
    /* 90F4 8010B8F4 C0100200 */  sll        $v0, $v0, 3
    /* 90F8 8010B8F8 2130C200 */  addu       $a2, $a2, $v0
    /* 90FC 8010B8FC 0200C290 */  lbu        $v0, 0x2($a2)
    /* 9100 8010B900 DCEDA524 */  addiu      $a1, $a1, %lo(vs_main_materialModifiers)
    /* 9104 8010B904 030062A2 */  sb         $v0, 0x3($s3)
    /* 9108 8010B908 00110300 */  sll        $v0, $v1, 4
    /* 910C 8010B90C 23104300 */  subu       $v0, $v0, $v1
    /* 9110 8010B910 40100200 */  sll        $v0, $v0, 1
    /* 9114 8010B914 21104500 */  addu       $v0, $v0, $a1
    /* 9118 8010B918 0400C390 */  lbu        $v1, 0x4($a2)
    /* 911C 8010B91C 18004290 */  lbu        $v0, 0x18($v0)
    /* 9120 8010B920 24006496 */  lhu        $a0, 0x24($s3)
    /* 9124 8010B924 21186200 */  addu       $v1, $v1, $v0
    /* 9128 8010B928 00110400 */  sll        $v0, $a0, 4
    /* 912C 8010B92C 23104400 */  subu       $v0, $v0, $a0
    /* 9130 8010B930 40100200 */  sll        $v0, $v0, 1
    /* 9134 8010B934 21104500 */  addu       $v0, $v0, $a1
    /* 9138 8010B938 0D0063A2 */  sb         $v1, 0xD($s3)
    /* 913C 8010B93C 0500C390 */  lbu        $v1, 0x5($a2)
    /* 9140 8010B940 1A004290 */  lbu        $v0, 0x1A($v0)
    /* 9144 8010B944 00000000 */  nop
    /* 9148 8010B948 21186200 */  addu       $v1, $v1, $v0
    /* 914C 8010B94C 00110400 */  sll        $v0, $a0, 4
    /* 9150 8010B950 23104400 */  subu       $v0, $v0, $a0
    /* 9154 8010B954 40100200 */  sll        $v0, $v0, 1
    /* 9158 8010B958 21104500 */  addu       $v0, $v0, $a1
    /* 915C 8010B95C 0E0063A2 */  sb         $v1, 0xE($s3)
    /* 9160 8010B960 0600C390 */  lbu        $v1, 0x6($a2)
    /* 9164 8010B964 1C004290 */  lbu        $v0, 0x1C($v0)
    /* 9168 8010B968 00000000 */  nop
    /* 916C 8010B96C 21186200 */  addu       $v1, $v1, $v0
    /* 9170 8010B970 0F0063A2 */  sb         $v1, 0xF($s3)
    /* 9174 8010B974 04008296 */  lhu        $v0, 0x4($s4)
    /* 9178 8010B978 0400A396 */  lhu        $v1, 0x4($s5)
    /* 917C 8010B97C 00000000 */  nop
    /* 9180 8010B980 21104300 */  addu       $v0, $v0, $v1
    /* 9184 8010B984 43100200 */  sra        $v0, $v0, 1
    /* 9188 8010B988 080062A6 */  sh         $v0, 0x8($s3)
    /* 918C 8010B98C 040062A6 */  sh         $v0, 0x4($s3)
    /* 9190 8010B990 24008396 */  lhu        $v1, 0x24($s4)
    /* 9194 8010B994 2400A296 */  lhu        $v0, 0x24($s5)
    /* 9198 8010B998 00000000 */  nop
    /* 919C 8010B99C 12006214 */  bne        $v1, $v0, .L8010B9E8
    /* 91A0 8010B9A0 14008426 */   addiu     $a0, $s4, 0x14
    /* 91A4 8010B9A4 1400A526 */  addiu      $a1, $s5, 0x14
    /* 91A8 8010B9A8 14006626 */  addiu      $a2, $s3, 0x14
    /* 91AC 8010B9AC 21380000 */  addu       $a3, $zero, $zero
    /* 91B0 8010B9B0 8E2B040C */  jal        _setClassAffinities
    /* 91B4 8010B9B4 1000A0AF */   sw        $zero, 0x10($sp)
    /* 91B8 8010B9B8 1C008426 */  addiu      $a0, $s4, 0x1C
    /* 91BC 8010B9BC 1C00A526 */  addiu      $a1, $s5, 0x1C
    /* 91C0 8010B9C0 1C006626 */  addiu      $a2, $s3, 0x1C
    /* 91C4 8010B9C4 21380000 */  addu       $a3, $zero, $zero
    /* 91C8 8010B9C8 01000224 */  addiu      $v0, $zero, 0x1
    /* 91CC 8010B9CC 8E2B040C */  jal        _setClassAffinities
    /* 91D0 8010B9D0 1000A2AF */   sw        $v0, 0x10($sp)
    /* 91D4 8010B9D4 10008426 */  addiu      $a0, $s4, 0x10
    /* 91D8 8010B9D8 1000A526 */  addiu      $a1, $s5, 0x10
    /* 91DC 8010B9DC 10006626 */  addiu      $a2, $s3, 0x10
    /* 91E0 8010B9E0 8A2E0408 */  j          .L8010BA28
    /* 91E4 8010B9E4 21380000 */   addu      $a3, $zero, $zero
  .L8010B9E8:
    /* 91E8 8010B9E8 1400A526 */  addiu      $a1, $s5, 0x14
    /* 91EC 8010B9EC 14006626 */  addiu      $a2, $s3, 0x14
    /* 91F0 8010B9F0 01000724 */  addiu      $a3, $zero, 0x1
    /* 91F4 8010B9F4 8E2B040C */  jal        _setClassAffinities
    /* 91F8 8010B9F8 1000A0AF */   sw        $zero, 0x10($sp)
    /* 91FC 8010B9FC 1C008426 */  addiu      $a0, $s4, 0x1C
    /* 9200 8010BA00 1C00A526 */  addiu      $a1, $s5, 0x1C
    /* 9204 8010BA04 1C006626 */  addiu      $a2, $s3, 0x1C
    /* 9208 8010BA08 01000724 */  addiu      $a3, $zero, 0x1
    /* 920C 8010BA0C 2110E000 */  addu       $v0, $a3, $zero
    /* 9210 8010BA10 8E2B040C */  jal        _setClassAffinities
    /* 9214 8010BA14 1000A2AF */   sw        $v0, 0x10($sp)
    /* 9218 8010BA18 10008426 */  addiu      $a0, $s4, 0x10
    /* 921C 8010BA1C 1000A526 */  addiu      $a1, $s5, 0x10
    /* 9220 8010BA20 10006626 */  addiu      $a2, $s3, 0x10
    /* 9224 8010BA24 01000724 */  addiu      $a3, $zero, 0x1
  .L8010BA28:
    /* 9228 8010BA28 542C040C */  jal        _setTypeValues
    /* 922C 8010BA2C 00000000 */   nop
    /* 9230 8010BA30 21106002 */  addu       $v0, $s3, $zero
    /* 9234 8010BA34 3000BF8F */  lw         $ra, 0x30($sp)
    /* 9238 8010BA38 2C00B58F */  lw         $s5, 0x2C($sp)
    /* 923C 8010BA3C 2800B48F */  lw         $s4, 0x28($sp)
    /* 9240 8010BA40 2400B38F */  lw         $s3, 0x24($sp)
    /* 9244 8010BA44 2000B28F */  lw         $s2, 0x20($sp)
    /* 9248 8010BA48 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 924C 8010BA4C 1800B08F */  lw         $s0, 0x18($sp)
    /* 9250 8010BA50 0800E003 */  jr         $ra
    /* 9254 8010BA54 3800BD27 */   addiu     $sp, $sp, 0x38
endlabel _combineArmor
