nonmatching func_800D64E4, 0x24

glabel func_800D64E4
    /* 6DCE4 800D64E4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 6DCE8 800D64E8 21200000 */  addu       $a0, $zero, $zero
    /* 6DCEC 800D64EC 1000BFAF */  sw         $ra, 0x10($sp)
    /* 6DCF0 800D64F0 0C3E030C */  jal        func_800CF830
    /* 6DCF4 800D64F4 21288000 */   addu      $a1, $a0, $zero
    /* 6DCF8 800D64F8 1000BF8F */  lw         $ra, 0x10($sp)
    /* 6DCFC 800D64FC 00000000 */  nop
    /* 6DD00 800D6500 0800E003 */  jr         $ra
    /* 6DD04 800D6504 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800D64E4
