nonmatching func_80012780, 0x2C

glabel func_80012780
    /* 2F80 80012780 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 2F84 80012784 0380023C */  lui        $v0, %hi(D_800378C0)
    /* 2F88 80012788 FF008430 */  andi       $a0, $a0, 0xFF
    /* 2F8C 8001278C C07844AC */  sw         $a0, %lo(D_800378C0)($v0)
    /* 2F90 80012790 1000BFAF */  sw         $ra, 0x10($sp)
    /* 2F94 80012794 0C63000C */  jal        func_80018C30
    /* 2F98 80012798 AC000424 */   addiu     $a0, $zero, 0xAC
    /* 2F9C 8001279C 1000BF8F */  lw         $ra, 0x10($sp)
    /* 2FA0 800127A0 00000000 */  nop
    /* 2FA4 800127A4 0800E003 */  jr         $ra
    /* 2FA8 800127A8 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80012780
