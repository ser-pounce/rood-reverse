nonmatching func_800D0B08, 0x28

glabel func_800D0B08
    /* 68308 800D0B08 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 6830C 800D0B0C 21288000 */  addu       $a1, $a0, $zero
    /* 68310 800D0B10 0F80043C */  lui        $a0, %hi(D_800F5310)
    /* 68314 800D0B14 1000BFAF */  sw         $ra, 0x10($sp)
    /* 68318 800D0B18 A63F030C */  jal        func_800CFE98
    /* 6831C 800D0B1C 10538424 */   addiu     $a0, $a0, %lo(D_800F5310)
    /* 68320 800D0B20 1000BF8F */  lw         $ra, 0x10($sp)
    /* 68324 800D0B24 00000000 */  nop
    /* 68328 800D0B28 0800E003 */  jr         $ra
    /* 6832C 800D0B2C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800D0B08
