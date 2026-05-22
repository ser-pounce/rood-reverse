nonmatching _deleteRedundantTempFiles, 0x98

glabel _deleteRedundantTempFiles
    /* 89C 8010309C D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 8A0 801030A0 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 8A4 801030A4 21988000 */  addu       $s3, $a0, $zero
    /* 8A8 801030A8 1400B1AF */  sw         $s1, 0x14($sp)
    /* 8AC 801030AC 21880000 */  addu       $s1, $zero, $zero
    /* 8B0 801030B0 1000B0AF */  sw         $s0, 0x10($sp)
    /* 8B4 801030B4 21802002 */  addu       $s0, $s1, $zero
    /* 8B8 801030B8 1800B2AF */  sw         $s2, 0x18($sp)
    /* 8BC 801030BC 01001224 */  addiu      $s2, $zero, 0x1
    /* 8C0 801030C0 2000BFAF */  sw         $ra, 0x20($sp)
  .L801030C4:
    /* 8C4 801030C4 030C040C */  jal        _memcardSaveIdExists
    /* 8C8 801030C8 31000426 */   addiu     $a0, $s0, 0x31
    /* 8CC 801030CC 0E004010 */  beqz       $v0, .L80103108
    /* 8D0 801030D0 00000000 */   nop
    /* 8D4 801030D4 030C040C */  jal        _memcardSaveIdExists
    /* 8D8 801030D8 41000426 */   addiu     $a0, $s0, 0x41
    /* 8DC 801030DC 0A004010 */  beqz       $v0, .L80103108
    /* 8E0 801030E0 21206002 */   addu      $a0, $s3, $zero
    /* 8E4 801030E4 0E0B040C */  jal        _memcardMakeTempFilename
    /* 8E8 801030E8 01000526 */   addiu     $a1, $s0, 0x1
    /* 8EC 801030EC 7D9A000C */  jal        erase
    /* 8F0 801030F0 21204000 */   addu      $a0, $v0, $zero
    /* 8F4 801030F4 03004014 */  bnez       $v0, .L80103104
    /* 8F8 801030F8 04101202 */   sllv      $v0, $s2, $s0
    /* 8FC 801030FC 460C0408 */  j          .L80103118
    /* 900 80103100 80000224 */   addiu     $v0, $zero, 0x80
  .L80103104:
    /* 904 80103104 25882202 */  or         $s1, $s1, $v0
  .L80103108:
    /* 908 80103108 01001026 */  addiu      $s0, $s0, 0x1
    /* 90C 8010310C 0500022A */  slti       $v0, $s0, 0x5
    /* 910 80103110 ECFF4014 */  bnez       $v0, .L801030C4
    /* 914 80103114 21102002 */   addu      $v0, $s1, $zero
  .L80103118:
    /* 918 80103118 2000BF8F */  lw         $ra, 0x20($sp)
    /* 91C 8010311C 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 920 80103120 1800B28F */  lw         $s2, 0x18($sp)
    /* 924 80103124 1400B18F */  lw         $s1, 0x14($sp)
    /* 928 80103128 1000B08F */  lw         $s0, 0x10($sp)
    /* 92C 8010312C 0800E003 */  jr         $ra
    /* 930 80103130 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel _deleteRedundantTempFiles
