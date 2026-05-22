nonmatching func_800126C0, 0x34

glabel func_800126C0
    /* 2EC0 800126C0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 2EC4 800126C4 0380023C */  lui        $v0, %hi(D_800378C0)
    /* 2EC8 800126C8 C07844AC */  sw         $a0, %lo(D_800378C0)($v0)
    /* 2ECC 800126CC C0784224 */  addiu      $v0, $v0, %lo(D_800378C0)
    /* 2ED0 800126D0 FF00A530 */  andi       $a1, $a1, 0xFF
    /* 2ED4 800126D4 AB000424 */  addiu      $a0, $zero, 0xAB
    /* 2ED8 800126D8 1000BFAF */  sw         $ra, 0x10($sp)
    /* 2EDC 800126DC 0C63000C */  jal        func_80018C30
    /* 2EE0 800126E0 040045AC */   sw        $a1, 0x4($v0)
    /* 2EE4 800126E4 1000BF8F */  lw         $ra, 0x10($sp)
    /* 2EE8 800126E8 00000000 */  nop
    /* 2EEC 800126EC 0800E003 */  jr         $ra
    /* 2EF0 800126F0 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800126C0
