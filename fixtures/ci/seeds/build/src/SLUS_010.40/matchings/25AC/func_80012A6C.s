nonmatching func_80012A6C, 0x34

glabel func_80012A6C
    /* 326C 80012A6C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 3270 80012A70 0380023C */  lui        $v0, %hi(D_800378C0)
    /* 3274 80012A74 C07844AC */  sw         $a0, %lo(D_800378C0)($v0)
    /* 3278 80012A78 C0784224 */  addiu      $v0, $v0, %lo(D_800378C0)
    /* 327C 80012A7C FF00A530 */  andi       $a1, $a1, 0xFF
    /* 3280 80012A80 D5000424 */  addiu      $a0, $zero, 0xD5
    /* 3284 80012A84 1000BFAF */  sw         $ra, 0x10($sp)
    /* 3288 80012A88 0C63000C */  jal        func_80018C30
    /* 328C 80012A8C 040045AC */   sw        $a1, 0x4($v0)
    /* 3290 80012A90 1000BF8F */  lw         $ra, 0x10($sp)
    /* 3294 80012A94 00000000 */  nop
    /* 3298 80012A98 0800E003 */  jr         $ra
    /* 329C 80012A9C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80012A6C
