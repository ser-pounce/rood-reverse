nonmatching _deleteRedundantTempFiles, 0x98

glabel _deleteRedundantTempFiles
    /* 93C 8006913C D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 940 80069140 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 944 80069144 21988000 */  addu       $s3, $a0, $zero
    /* 948 80069148 1400B1AF */  sw         $s1, 0x14($sp)
    /* 94C 8006914C 21880000 */  addu       $s1, $zero, $zero
    /* 950 80069150 1000B0AF */  sw         $s0, 0x10($sp)
    /* 954 80069154 21802002 */  addu       $s0, $s1, $zero
    /* 958 80069158 1800B2AF */  sw         $s2, 0x18($sp)
    /* 95C 8006915C 01001224 */  addiu      $s2, $zero, 0x1
    /* 960 80069160 2000BFAF */  sw         $ra, 0x20($sp)
  .L80069164:
    /* 964 80069164 2BA4010C */  jal        _memcardSaveIdExists
    /* 968 80069168 31000426 */   addiu     $a0, $s0, 0x31
    /* 96C 8006916C 0E004010 */  beqz       $v0, .L800691A8
    /* 970 80069170 00000000 */   nop
    /* 974 80069174 2BA4010C */  jal        _memcardSaveIdExists
    /* 978 80069178 41000426 */   addiu     $a0, $s0, 0x41
    /* 97C 8006917C 0A004010 */  beqz       $v0, .L800691A8
    /* 980 80069180 21206002 */   addu      $a0, $s3, $zero
    /* 984 80069184 36A3010C */  jal        _memcardMakeTempFilename
    /* 988 80069188 01000526 */   addiu     $a1, $s0, 0x1
    /* 98C 8006918C 7D9A000C */  jal        erase
    /* 990 80069190 21204000 */   addu      $a0, $v0, $zero
    /* 994 80069194 03004014 */  bnez       $v0, .L800691A4
    /* 998 80069198 04101202 */   sllv      $v0, $s2, $s0
    /* 99C 8006919C 6EA40108 */  j          .L800691B8
    /* 9A0 800691A0 80000224 */   addiu     $v0, $zero, 0x80
  .L800691A4:
    /* 9A4 800691A4 25882202 */  or         $s1, $s1, $v0
  .L800691A8:
    /* 9A8 800691A8 01001026 */  addiu      $s0, $s0, 0x1
    /* 9AC 800691AC 0500022A */  slti       $v0, $s0, 0x5
    /* 9B0 800691B0 ECFF4014 */  bnez       $v0, .L80069164
    /* 9B4 800691B4 21102002 */   addu      $v0, $s1, $zero
  .L800691B8:
    /* 9B8 800691B8 2000BF8F */  lw         $ra, 0x20($sp)
    /* 9BC 800691BC 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 9C0 800691C0 1800B28F */  lw         $s2, 0x18($sp)
    /* 9C4 800691C4 1400B18F */  lw         $s1, 0x14($sp)
    /* 9C8 800691C8 1000B08F */  lw         $s0, 0x10($sp)
    /* 9CC 800691CC 0800E003 */  jr         $ra
    /* 9D0 800691D0 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel _deleteRedundantTempFiles
