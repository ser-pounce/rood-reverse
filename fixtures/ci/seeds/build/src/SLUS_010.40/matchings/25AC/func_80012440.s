nonmatching func_80012440, 0x28

glabel func_80012440
    /* 2C40 80012440 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 2C44 80012444 0380023C */  lui        $v0, %hi(D_800378C0)
    /* 2C48 80012448 C07844AC */  sw         $a0, %lo(D_800378C0)($v0)
    /* 2C4C 8001244C 1000BFAF */  sw         $ra, 0x10($sp)
    /* 2C50 80012450 0C63000C */  jal        func_80018C30
    /* 2C54 80012454 90000424 */   addiu     $a0, $zero, 0x90
    /* 2C58 80012458 1000BF8F */  lw         $ra, 0x10($sp)
    /* 2C5C 8001245C 00000000 */  nop
    /* 2C60 80012460 0800E003 */  jr         $ra
    /* 2C64 80012464 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80012440
