nonmatching func_800D1904, 0x2C

glabel func_800D1904
    /* 69104 800D1904 403B0700 */  sll        $a3, $a3, 13
    /* 69108 800D1908 1A00E600 */  div        $zero, $a3, $a2
    /* 6910C 800D190C 12380000 */  mflo       $a3
    /* 69110 800D1910 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 69114 800D1914 1000BFAF */  sw         $ra, 0x10($sp)
    /* 69118 800D1918 9E45030C */  jal        vs_battle_lerp
    /* 6911C 800D191C 2130E000 */   addu      $a2, $a3, $zero
    /* 69120 800D1920 1000BF8F */  lw         $ra, 0x10($sp)
    /* 69124 800D1924 00000000 */  nop
    /* 69128 800D1928 0800E003 */  jr         $ra
    /* 6912C 800D192C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800D1904
