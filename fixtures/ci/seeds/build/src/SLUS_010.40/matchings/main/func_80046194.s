nonmatching func_80046194, 0x38

glabel func_80046194
    /* 36994 80046194 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 36998 80046198 FEFF0424 */  addiu      $a0, $zero, -0x2
    /* 3699C 8004619C 1000BFAF */  sw         $ra, 0x10($sp)
    /* 369A0 800461A0 A248000C */  jal        func_80012288
    /* 369A4 800461A4 21280000 */   addu      $a1, $zero, $zero
    /* 369A8 800461A8 21200000 */  addu       $a0, $zero, $zero
    /* 369AC 800461AC A248000C */  jal        func_80012288
    /* 369B0 800461B0 F000053C */   lui       $a1, (0xF00000 >> 16)
    /* 369B4 800461B4 1000BF8F */  lw         $ra, 0x10($sp)
    /* 369B8 800461B8 0680023C */  lui        $v0, %hi(vs_main_soundData + 0x54)
    /* 369BC 800461BC 8CE040AC */  sw         $zero, %lo(vs_main_soundData + 0x54)($v0)
    /* 369C0 800461C0 01000224 */  addiu      $v0, $zero, 0x1
    /* 369C4 800461C4 0800E003 */  jr         $ra
    /* 369C8 800461C8 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80046194
