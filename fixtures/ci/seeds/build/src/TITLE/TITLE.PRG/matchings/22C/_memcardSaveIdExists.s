nonmatching _memcardSaveIdExists, 0x90

glabel _memcardSaveIdExists
    /* 8AC 800690AC D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 8B0 800690B0 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 8B4 800690B4 21988000 */  addu       $s3, $a0, $zero
    /* 8B8 800690B8 1800B2AF */  sw         $s2, 0x18($sp)
    /* 8BC 800690BC 21900000 */  addu       $s2, $zero, $zero
    /* 8C0 800690C0 0E80023C */  lui        $v0, %hi(_memcardFiles)
    /* 8C4 800690C4 1400B1AF */  sw         $s1, 0x14($sp)
    /* 8C8 800690C8 C8EA5124 */  addiu      $s1, $v0, %lo(_memcardFiles)
    /* 8CC 800690CC 2000BFAF */  sw         $ra, 0x20($sp)
    /* 8D0 800690D0 1000B0AF */  sw         $s0, 0x10($sp)
  .L800690D4:
    /* 8D4 800690D4 0000308E */  lw         $s0, 0x0($s1)
    /* 8D8 800690D8 00000000 */  nop
    /* 8DC 800690DC 0B000012 */  beqz       $s0, .L8006910C
    /* 8E0 800690E0 00000000 */   nop
    /* 8E4 800690E4 93A3010C */  jal        _memcardFileNumberFromFilename
    /* 8E8 800690E8 21200002 */   addu      $a0, $s0, $zero
    /* 8EC 800690EC 07004010 */  beqz       $v0, .L8006910C
    /* 8F0 800690F0 00000000 */   nop
    /* 8F4 800690F4 0F000292 */  lbu        $v0, 0xF($s0)
    /* 8F8 800690F8 00000000 */  nop
    /* 8FC 800690FC 04005314 */  bne        $v0, $s3, .L80069110
    /* 900 80069100 01005226 */   addiu     $s2, $s2, 0x1
    /* 904 80069104 48A40108 */  j          .L80069120
    /* 908 80069108 01000224 */   addiu     $v0, $zero, 0x1
  .L8006910C:
    /* 90C 8006910C 01005226 */  addiu      $s2, $s2, 0x1
  .L80069110:
    /* 910 80069110 0F00422A */  slti       $v0, $s2, 0xF
    /* 914 80069114 EFFF4014 */  bnez       $v0, .L800690D4
    /* 918 80069118 04003126 */   addiu     $s1, $s1, 0x4
    /* 91C 8006911C 21100000 */  addu       $v0, $zero, $zero
  .L80069120:
    /* 920 80069120 2000BF8F */  lw         $ra, 0x20($sp)
    /* 924 80069124 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 928 80069128 1800B28F */  lw         $s2, 0x18($sp)
    /* 92C 8006912C 1400B18F */  lw         $s1, 0x14($sp)
    /* 930 80069130 1000B08F */  lw         $s0, 0x10($sp)
    /* 934 80069134 0800E003 */  jr         $ra
    /* 938 80069138 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel _memcardSaveIdExists
