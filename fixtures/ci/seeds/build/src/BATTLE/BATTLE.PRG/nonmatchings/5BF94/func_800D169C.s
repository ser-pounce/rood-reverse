nonmatching func_800D169C, 0x7C

glabel func_800D169C
    /* 68E9C 800D169C D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 68EA0 800D16A0 1000B0AF */  sw         $s0, 0x10($sp)
    /* 68EA4 800D16A4 21808000 */  addu       $s0, $a0, $zero
    /* 68EA8 800D16A8 1400B1AF */  sw         $s1, 0x14($sp)
    /* 68EAC 800D16AC 2188A000 */  addu       $s1, $a1, $zero
    /* 68EB0 800D16B0 1800B2AF */  sw         $s2, 0x18($sp)
    /* 68EB4 800D16B4 2190C000 */  addu       $s2, $a2, $zero
    /* 68EB8 800D16B8 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 68EBC 800D16BC 2000BFAF */  sw         $ra, 0x20($sp)
    /* 68EC0 800D16C0 00000486 */  lh         $a0, 0x0($s0)
    /* 68EC4 800D16C4 00002586 */  lh         $a1, 0x0($s1)
    /* 68EC8 800D16C8 9E45030C */  jal        vs_battle_lerp
    /* 68ECC 800D16CC 2198E000 */   addu      $s3, $a3, $zero
    /* 68ED0 800D16D0 000062A6 */  sh         $v0, 0x0($s3)
    /* 68ED4 800D16D4 02000486 */  lh         $a0, 0x2($s0)
    /* 68ED8 800D16D8 02002586 */  lh         $a1, 0x2($s1)
    /* 68EDC 800D16DC 9E45030C */  jal        vs_battle_lerp
    /* 68EE0 800D16E0 21304002 */   addu      $a2, $s2, $zero
    /* 68EE4 800D16E4 020062A6 */  sh         $v0, 0x2($s3)
    /* 68EE8 800D16E8 04000486 */  lh         $a0, 0x4($s0)
    /* 68EEC 800D16EC 04002586 */  lh         $a1, 0x4($s1)
    /* 68EF0 800D16F0 9E45030C */  jal        vs_battle_lerp
    /* 68EF4 800D16F4 21304002 */   addu      $a2, $s2, $zero
    /* 68EF8 800D16F8 040062A6 */  sh         $v0, 0x4($s3)
    /* 68EFC 800D16FC 2000BF8F */  lw         $ra, 0x20($sp)
    /* 68F00 800D1700 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 68F04 800D1704 1800B28F */  lw         $s2, 0x18($sp)
    /* 68F08 800D1708 1400B18F */  lw         $s1, 0x14($sp)
    /* 68F0C 800D170C 1000B08F */  lw         $s0, 0x10($sp)
    /* 68F10 800D1710 0800E003 */  jr         $ra
    /* 68F14 800D1714 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_800D169C
