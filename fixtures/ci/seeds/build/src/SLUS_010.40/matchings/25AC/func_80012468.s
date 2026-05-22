nonmatching func_80012468, 0x28

glabel func_80012468
    /* 2C68 80012468 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 2C6C 8001246C 0380023C */  lui        $v0, %hi(D_800378C0)
    /* 2C70 80012470 C07844AC */  sw         $a0, %lo(D_800378C0)($v0)
    /* 2C74 80012474 1000BFAF */  sw         $ra, 0x10($sp)
    /* 2C78 80012478 0C63000C */  jal        func_80018C30
    /* 2C7C 8001247C 92000424 */   addiu     $a0, $zero, 0x92
    /* 2C80 80012480 1000BF8F */  lw         $ra, 0x10($sp)
    /* 2C84 80012484 00000000 */  nop
    /* 2C88 80012488 0800E003 */  jr         $ra
    /* 2C8C 8001248C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80012468
