nonmatching func_800A1178, 0x60

glabel func_800A1178
    /* 38978 800A1178 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 3897C 800A117C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 38980 800A1180 21808000 */  addu       $s0, $a0, $zero
    /* 38984 800A1184 1800B2AF */  sw         $s2, 0x18($sp)
    /* 38988 800A1188 2190C000 */  addu       $s2, $a2, $zero
    /* 3898C 800A118C 21300000 */  addu       $a2, $zero, $zero
    /* 38990 800A1190 1400B1AF */  sw         $s1, 0x14($sp)
    /* 38994 800A1194 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 38998 800A1198 4B85020C */  jal        func_800A152C
    /* 3899C 800A119C 2188E000 */   addu      $s1, $a3, $zero
    /* 389A0 800A11A0 06004004 */  bltz       $v0, .L800A11BC
    /* 389A4 800A11A4 21200002 */   addu      $a0, $s0, $zero
    /* 389A8 800A11A8 21284000 */  addu       $a1, $v0, $zero
    /* 389AC 800A11AC 21304002 */  addu       $a2, $s2, $zero
    /* 389B0 800A11B0 7684020C */  jal        func_800A11D8
    /* 389B4 800A11B4 21382002 */   addu      $a3, $s1, $zero
    /* 389B8 800A11B8 21100000 */  addu       $v0, $zero, $zero
  .L800A11BC:
    /* 389BC 800A11BC 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 389C0 800A11C0 1800B28F */  lw         $s2, 0x18($sp)
    /* 389C4 800A11C4 1400B18F */  lw         $s1, 0x14($sp)
    /* 389C8 800A11C8 1000B08F */  lw         $s0, 0x10($sp)
    /* 389CC 800A11CC 2000BD27 */  addiu      $sp, $sp, 0x20
    /* 389D0 800A11D0 0800E003 */  jr         $ra
    /* 389D4 800A11D4 00000000 */   nop
endlabel func_800A1178
