nonmatching func_8007CFF8, 0x44

glabel func_8007CFF8
    /* 147F8 8007CFF8 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 147FC 8007CFFC 1400B1AF */  sw         $s1, 0x14($sp)
    /* 14800 8007D000 21888000 */  addu       $s1, $a0, $zero
    /* 14804 8007D004 1000B0AF */  sw         $s0, 0x10($sp)
    /* 14808 8007D008 2180A000 */  addu       $s0, $a1, $zero
    /* 1480C 8007D00C 1800BFAF */  sw         $ra, 0x18($sp)
    /* 14810 8007D010 8782020C */  jal        func_800A0A1C
    /* 14814 8007D014 02000524 */   addiu     $a1, $zero, 0x2
    /* 14818 8007D018 00000586 */  lh         $a1, 0x0($s0)
    /* 1481C 8007D01C 04000686 */  lh         $a2, 0x4($s0)
    /* 14820 8007D020 9F94030C */  jal        func_800E527C
    /* 14824 8007D024 21202002 */   addu      $a0, $s1, $zero
    /* 14828 8007D028 1800BF8F */  lw         $ra, 0x18($sp)
    /* 1482C 8007D02C 1400B18F */  lw         $s1, 0x14($sp)
    /* 14830 8007D030 1000B08F */  lw         $s0, 0x10($sp)
    /* 14834 8007D034 0800E003 */  jr         $ra
    /* 14838 8007D038 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8007CFF8
