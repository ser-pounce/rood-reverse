nonmatching func_80084A8C, 0x4C

glabel func_80084A8C
    /* 1C28C 80084A8C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1C290 80084A90 1000B0AF */  sw         $s0, 0x10($sp)
    /* 1C294 80084A94 2180C000 */  addu       $s0, $a2, $zero
    /* 1C298 80084A98 1400BFAF */  sw         $ra, 0x14($sp)
    /* 1C29C 80084A9C EA09010C */  jal        vs_main_getRand
    /* 1C2A0 80084AA0 04000424 */   addiu     $a0, $zero, 0x4
    /* 1C2A4 80084AA4 3FFF0324 */  addiu      $v1, $zero, -0xC1
    /* 1C2A8 80084AA8 1C00048E */  lw         $a0, 0x1C($s0)
    /* 1C2AC 80084AAC 01004224 */  addiu      $v0, $v0, 0x1
    /* 1C2B0 80084AB0 24208300 */  and        $a0, $a0, $v1
    /* 1C2B4 80084AB4 0A000396 */  lhu        $v1, 0xA($s0)
    /* 1C2B8 80084AB8 40008434 */  ori        $a0, $a0, 0x40
    /* 1C2BC 80084ABC 1C0004AE */  sw         $a0, 0x1C($s0)
    /* 1C2C0 80084AC0 21186200 */  addu       $v1, $v1, $v0
    /* 1C2C4 80084AC4 0A0003A6 */  sh         $v1, 0xA($s0)
    /* 1C2C8 80084AC8 1400BF8F */  lw         $ra, 0x14($sp)
    /* 1C2CC 80084ACC 1000B08F */  lw         $s0, 0x10($sp)
    /* 1C2D0 80084AD0 0800E003 */  jr         $ra
    /* 1C2D4 80084AD4 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80084A8C
