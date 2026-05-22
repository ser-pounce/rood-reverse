nonmatching func_80012B08, 0x34

glabel func_80012B08
    /* 3308 80012B08 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 330C 80012B0C 0380023C */  lui        $v0, %hi(D_800378C0)
    /* 3310 80012B10 C07844AC */  sw         $a0, %lo(D_800378C0)($v0)
    /* 3314 80012B14 C0784224 */  addiu      $v0, $v0, %lo(D_800378C0)
    /* 3318 80012B18 FF00A530 */  andi       $a1, $a1, 0xFF
    /* 331C 80012B1C D9000424 */  addiu      $a0, $zero, 0xD9
    /* 3320 80012B20 1000BFAF */  sw         $ra, 0x10($sp)
    /* 3324 80012B24 0C63000C */  jal        func_80018C30
    /* 3328 80012B28 040045AC */   sw        $a1, 0x4($v0)
    /* 332C 80012B2C 1000BF8F */  lw         $ra, 0x10($sp)
    /* 3330 80012B30 00000000 */  nop
    /* 3334 80012B34 0800E003 */  jr         $ra
    /* 3338 80012B38 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80012B08
