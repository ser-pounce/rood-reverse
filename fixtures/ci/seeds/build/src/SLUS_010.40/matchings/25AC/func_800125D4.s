nonmatching func_800125D4, 0x34

glabel func_800125D4
    /* 2DD4 800125D4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 2DD8 800125D8 0380023C */  lui        $v0, %hi(D_800378C0)
    /* 2DDC 800125DC C07844AC */  sw         $a0, %lo(D_800378C0)($v0)
    /* 2DE0 800125E0 C0784224 */  addiu      $v0, $v0, %lo(D_800378C0)
    /* 2DE4 800125E4 7F00A530 */  andi       $a1, $a1, 0x7F
    /* 2DE8 800125E8 A9000424 */  addiu      $a0, $zero, 0xA9
    /* 2DEC 800125EC 1000BFAF */  sw         $ra, 0x10($sp)
    /* 2DF0 800125F0 0C63000C */  jal        func_80018C30
    /* 2DF4 800125F4 040045AC */   sw        $a1, 0x4($v0)
    /* 2DF8 800125F8 1000BF8F */  lw         $ra, 0x10($sp)
    /* 2DFC 800125FC 00000000 */  nop
    /* 2E00 80012600 0800E003 */  jr         $ra
    /* 2E04 80012604 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800125D4
