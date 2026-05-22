nonmatching func_80012B3C, 0x3C

glabel func_80012B3C
    /* 333C 80012B3C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 3340 80012B40 0380023C */  lui        $v0, %hi(D_800378C0)
    /* 3344 80012B44 C07844AC */  sw         $a0, %lo(D_800378C0)($v0)
    /* 3348 80012B48 C0784224 */  addiu      $v0, $v0, %lo(D_800378C0)
    /* 334C 80012B4C FF00A530 */  andi       $a1, $a1, 0xFF
    /* 3350 80012B50 FF00C630 */  andi       $a2, $a2, 0xFF
    /* 3354 80012B54 DA000424 */  addiu      $a0, $zero, 0xDA
    /* 3358 80012B58 1000BFAF */  sw         $ra, 0x10($sp)
    /* 335C 80012B5C 040045AC */  sw         $a1, 0x4($v0)
    /* 3360 80012B60 0C63000C */  jal        func_80018C30
    /* 3364 80012B64 080046AC */   sw        $a2, 0x8($v0)
    /* 3368 80012B68 1000BF8F */  lw         $ra, 0x10($sp)
    /* 336C 80012B6C 00000000 */  nop
    /* 3370 80012B70 0800E003 */  jr         $ra
    /* 3374 80012B74 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80012B3C
