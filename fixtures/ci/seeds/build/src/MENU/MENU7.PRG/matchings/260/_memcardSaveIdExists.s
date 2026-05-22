nonmatching _memcardSaveIdExists, 0x90

glabel _memcardSaveIdExists
    /* 80C 8010300C D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 810 80103010 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 814 80103014 21988000 */  addu       $s3, $a0, $zero
    /* 818 80103018 1800B2AF */  sw         $s2, 0x18($sp)
    /* 81C 8010301C 21900000 */  addu       $s2, $zero, $zero
    /* 820 80103020 1180023C */  lui        $v0, %hi(_memcardFiles)
    /* 824 80103024 1400B1AF */  sw         $s1, 0x14($sp)
    /* 828 80103028 00AE5124 */  addiu      $s1, $v0, %lo(_memcardFiles)
    /* 82C 8010302C 2000BFAF */  sw         $ra, 0x20($sp)
    /* 830 80103030 1000B0AF */  sw         $s0, 0x10($sp)
  .L80103034:
    /* 834 80103034 0000308E */  lw         $s0, 0x0($s1)
    /* 838 80103038 00000000 */  nop
    /* 83C 8010303C 0B000012 */  beqz       $s0, .L8010306C
    /* 840 80103040 00000000 */   nop
    /* 844 80103044 6B0B040C */  jal        _memcardFileNumberFromFilename
    /* 848 80103048 21200002 */   addu      $a0, $s0, $zero
    /* 84C 8010304C 07004010 */  beqz       $v0, .L8010306C
    /* 850 80103050 00000000 */   nop
    /* 854 80103054 0F000292 */  lbu        $v0, 0xF($s0)
    /* 858 80103058 00000000 */  nop
    /* 85C 8010305C 04005314 */  bne        $v0, $s3, .L80103070
    /* 860 80103060 01005226 */   addiu     $s2, $s2, 0x1
    /* 864 80103064 200C0408 */  j          .L80103080
    /* 868 80103068 01000224 */   addiu     $v0, $zero, 0x1
  .L8010306C:
    /* 86C 8010306C 01005226 */  addiu      $s2, $s2, 0x1
  .L80103070:
    /* 870 80103070 0F00422A */  slti       $v0, $s2, 0xF
    /* 874 80103074 EFFF4014 */  bnez       $v0, .L80103034
    /* 878 80103078 04003126 */   addiu     $s1, $s1, 0x4
    /* 87C 8010307C 21100000 */  addu       $v0, $zero, $zero
  .L80103080:
    /* 880 80103080 2000BF8F */  lw         $ra, 0x20($sp)
    /* 884 80103084 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 888 80103088 1800B28F */  lw         $s2, 0x18($sp)
    /* 88C 8010308C 1400B18F */  lw         $s1, 0x14($sp)
    /* 890 80103090 1000B08F */  lw         $s0, 0x10($sp)
    /* 894 80103094 0800E003 */  jr         $ra
    /* 898 80103098 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel _memcardSaveIdExists
