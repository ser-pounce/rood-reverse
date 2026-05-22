nonmatching _insertTpage, 0x68

glabel _insertTpage
    /* 2158 8006A958 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 215C 8006A95C 1400B1AF */  sw         $s1, 0x14($sp)
    /* 2160 8006A960 2188A000 */  addu       $s1, $a1, $zero
    /* 2164 8006A964 21280000 */  addu       $a1, $zero, $zero
    /* 2168 8006A968 1800B2AF */  sw         $s2, 0x18($sp)
    /* 216C 8006A96C 801F123C */  lui        $s2, (0x1F800004 >> 16)
    /* 2170 8006A970 FFFF8730 */  andi       $a3, $a0, 0xFFFF
    /* 2174 8006A974 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 2178 8006A978 1000B0AF */  sw         $s0, 0x10($sp)
    /* 217C 8006A97C 0000508E */  lw         $s0, (0x1F800000 & 0xFFFF)($s2)
    /* 2180 8006A980 01000624 */  addiu      $a2, $zero, 0x1
    /* 2184 8006A984 A1AD000C */  jal        SetDrawTPage
    /* 2188 8006A988 21200002 */   addu      $a0, $s0, $zero
    /* 218C 8006A98C 21280002 */  addu       $a1, $s0, $zero
    /* 2190 8006A990 08001026 */  addiu      $s0, $s0, 0x8
    /* 2194 8006A994 0400448E */  lw         $a0, (0x1F800004 & 0xFFFF)($s2)
    /* 2198 8006A998 80881100 */  sll        $s1, $s1, 2
    /* 219C 8006A99C 35AD000C */  jal        AddPrim
    /* 21A0 8006A9A0 21209100 */   addu      $a0, $a0, $s1
    /* 21A4 8006A9A4 21100002 */  addu       $v0, $s0, $zero
    /* 21A8 8006A9A8 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 21AC 8006A9AC 1800B28F */  lw         $s2, 0x18($sp)
    /* 21B0 8006A9B0 1400B18F */  lw         $s1, 0x14($sp)
    /* 21B4 8006A9B4 1000B08F */  lw         $s0, 0x10($sp)
    /* 21B8 8006A9B8 0800E003 */  jr         $ra
    /* 21BC 8006A9BC 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel _insertTpage
