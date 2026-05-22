nonmatching func_80093FEC, 0x80

glabel func_80093FEC
    /* 2B7EC 80093FEC D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 2B7F0 80093FF0 1800B2AF */  sw         $s2, 0x18($sp)
    /* 2B7F4 80093FF4 21908000 */  addu       $s2, $a0, $zero
    /* 2B7F8 80093FF8 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 2B7FC 80093FFC 2198C000 */  addu       $s3, $a2, $zero
    /* 2B800 80094000 2000B4AF */  sw         $s4, 0x20($sp)
    /* 2B804 80094004 21A0E000 */  addu       $s4, $a3, $zero
    /* 2B808 80094008 1000B0AF */  sw         $s0, 0x10($sp)
    /* 2B80C 8009400C 21800000 */  addu       $s0, $zero, $zero
    /* 2B810 80094010 1400B1AF */  sw         $s1, 0x14($sp)
    /* 2B814 80094014 01001124 */  addiu      $s1, $zero, 0x1
    /* 2B818 80094018 2400BFAF */  sw         $ra, 0x24($sp)
  .L8009401C:
    /* 2B81C 8009401C 24107102 */  and        $v0, $s3, $s1
    /* 2B820 80094020 05004010 */  beqz       $v0, .L80094038
    /* 2B824 80094024 21204002 */   addu      $a0, $s2, $zero
    /* 2B828 80094028 FB000524 */  addiu      $a1, $zero, 0xFB
    /* 2B82C 8009402C 21300002 */  addu       $a2, $s0, $zero
    /* 2B830 80094030 1B50020C */  jal        func_8009406C
    /* 2B834 80094034 21388002 */   addu      $a3, $s4, $zero
  .L80094038:
    /* 2B838 80094038 01001026 */  addiu      $s0, $s0, 0x1
    /* 2B83C 8009403C 1D00022A */  slti       $v0, $s0, 0x1D
    /* 2B840 80094040 F6FF4014 */  bnez       $v0, .L8009401C
    /* 2B844 80094044 40881100 */   sll       $s1, $s1, 1
    /* 2B848 80094048 2400BF8F */  lw         $ra, 0x24($sp)
    /* 2B84C 8009404C 2000B48F */  lw         $s4, 0x20($sp)
    /* 2B850 80094050 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 2B854 80094054 1800B28F */  lw         $s2, 0x18($sp)
    /* 2B858 80094058 1400B18F */  lw         $s1, 0x14($sp)
    /* 2B85C 8009405C 1000B08F */  lw         $s0, 0x10($sp)
    /* 2B860 80094060 21100000 */  addu       $v0, $zero, $zero
    /* 2B864 80094064 0800E003 */  jr         $ra
    /* 2B868 80094068 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_80093FEC
