nonmatching func_800D1718, 0x60

glabel func_800D1718
    /* 68F18 800D1718 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 68F1C 800D171C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 68F20 800D1720 21808000 */  addu       $s0, $a0, $zero
    /* 68F24 800D1724 C0220700 */  sll        $a0, $a3, 11
    /* 68F28 800D1728 1A008600 */  div        $zero, $a0, $a2
    /* 68F2C 800D172C 12200000 */  mflo       $a0
    /* 68F30 800D1730 1400B1AF */  sw         $s1, 0x14($sp)
    /* 68F34 800D1734 3000B18F */  lw         $s1, 0x30($sp)
    /* 68F38 800D1738 1800B2AF */  sw         $s2, 0x18($sp)
    /* 68F3C 800D173C 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 68F40 800D1740 C903010C */  jal        rcos
    /* 68F44 800D1744 2190A000 */   addu      $s2, $a1, $zero
    /* 68F48 800D1748 21200002 */  addu       $a0, $s0, $zero
    /* 68F4C 800D174C 00100624 */  addiu      $a2, $zero, 0x1000
    /* 68F50 800D1750 21284002 */  addu       $a1, $s2, $zero
    /* 68F54 800D1754 2330C200 */  subu       $a2, $a2, $v0
    /* 68F58 800D1758 A745030C */  jal        func_800D169C
    /* 68F5C 800D175C 21382002 */   addu      $a3, $s1, $zero
    /* 68F60 800D1760 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 68F64 800D1764 1800B28F */  lw         $s2, 0x18($sp)
    /* 68F68 800D1768 1400B18F */  lw         $s1, 0x14($sp)
    /* 68F6C 800D176C 1000B08F */  lw         $s0, 0x10($sp)
    /* 68F70 800D1770 0800E003 */  jr         $ra
    /* 68F74 800D1774 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_800D1718
