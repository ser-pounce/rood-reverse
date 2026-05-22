nonmatching func_800D17A8, 0x7C

glabel func_800D17A8
    /* 68FA8 800D17A8 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 68FAC 800D17AC 1000B0AF */  sw         $s0, 0x10($sp)
    /* 68FB0 800D17B0 21808000 */  addu       $s0, $a0, $zero
    /* 68FB4 800D17B4 1400B1AF */  sw         $s1, 0x14($sp)
    /* 68FB8 800D17B8 2188A000 */  addu       $s1, $a1, $zero
    /* 68FBC 800D17BC 1800B2AF */  sw         $s2, 0x18($sp)
    /* 68FC0 800D17C0 2190C000 */  addu       $s2, $a2, $zero
    /* 68FC4 800D17C4 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 68FC8 800D17C8 2000BFAF */  sw         $ra, 0x20($sp)
    /* 68FCC 800D17CC 0000048E */  lw         $a0, 0x0($s0)
    /* 68FD0 800D17D0 0000258E */  lw         $a1, 0x0($s1)
    /* 68FD4 800D17D4 9E45030C */  jal        vs_battle_lerp
    /* 68FD8 800D17D8 2198E000 */   addu      $s3, $a3, $zero
    /* 68FDC 800D17DC 000062AE */  sw         $v0, 0x0($s3)
    /* 68FE0 800D17E0 0400048E */  lw         $a0, 0x4($s0)
    /* 68FE4 800D17E4 0400258E */  lw         $a1, 0x4($s1)
    /* 68FE8 800D17E8 9E45030C */  jal        vs_battle_lerp
    /* 68FEC 800D17EC 21304002 */   addu      $a2, $s2, $zero
    /* 68FF0 800D17F0 040062AE */  sw         $v0, 0x4($s3)
    /* 68FF4 800D17F4 0800048E */  lw         $a0, 0x8($s0)
    /* 68FF8 800D17F8 0800258E */  lw         $a1, 0x8($s1)
    /* 68FFC 800D17FC 9E45030C */  jal        vs_battle_lerp
    /* 69000 800D1800 21304002 */   addu      $a2, $s2, $zero
    /* 69004 800D1804 080062AE */  sw         $v0, 0x8($s3)
    /* 69008 800D1808 2000BF8F */  lw         $ra, 0x20($sp)
    /* 6900C 800D180C 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 69010 800D1810 1800B28F */  lw         $s2, 0x18($sp)
    /* 69014 800D1814 1400B18F */  lw         $s1, 0x14($sp)
    /* 69018 800D1818 1000B08F */  lw         $s0, 0x10($sp)
    /* 6901C 800D181C 0800E003 */  jr         $ra
    /* 69020 800D1820 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_800D17A8
