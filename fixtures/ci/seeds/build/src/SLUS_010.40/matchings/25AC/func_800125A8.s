nonmatching func_800125A8, 0x2C

glabel func_800125A8
    /* 2DA8 800125A8 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 2DAC 800125AC 0380023C */  lui        $v0, %hi(D_800378C0)
    /* 2DB0 800125B0 7F008430 */  andi       $a0, $a0, 0x7F
    /* 2DB4 800125B4 C07844AC */  sw         $a0, %lo(D_800378C0)($v0)
    /* 2DB8 800125B8 1000BFAF */  sw         $ra, 0x10($sp)
    /* 2DBC 800125BC 0C63000C */  jal        func_80018C30
    /* 2DC0 800125C0 A8000424 */   addiu     $a0, $zero, 0xA8
    /* 2DC4 800125C4 1000BF8F */  lw         $ra, 0x10($sp)
    /* 2DC8 800125C8 00000000 */  nop
    /* 2DCC 800125CC 0800E003 */  jr         $ra
    /* 2DD0 800125D0 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800125A8
