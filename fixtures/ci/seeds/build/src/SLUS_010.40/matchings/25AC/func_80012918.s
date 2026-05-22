nonmatching func_80012918, 0x28

glabel func_80012918
    /* 3118 80012918 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 311C 8001291C 0380023C */  lui        $v0, %hi(D_800378C0)
    /* 3120 80012920 C07844AC */  sw         $a0, %lo(D_800378C0)($v0)
    /* 3124 80012924 1000BFAF */  sw         $ra, 0x10($sp)
    /* 3128 80012928 0C63000C */  jal        func_80018C30
    /* 312C 8001292C C8000424 */   addiu     $a0, $zero, 0xC8
    /* 3130 80012930 1000BF8F */  lw         $ra, 0x10($sp)
    /* 3134 80012934 00000000 */  nop
    /* 3138 80012938 0800E003 */  jr         $ra
    /* 313C 8001293C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80012918
