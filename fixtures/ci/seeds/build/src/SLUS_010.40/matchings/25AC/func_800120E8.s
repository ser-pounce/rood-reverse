nonmatching func_800120E8, 0x28

glabel func_800120E8
    /* 28E8 800120E8 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 28EC 800120EC 0380023C */  lui        $v0, %hi(D_800378C0)
    /* 28F0 800120F0 C07844AC */  sw         $a0, %lo(D_800378C0)($v0)
    /* 28F4 800120F4 1000BFAF */  sw         $ra, 0x10($sp)
    /* 28F8 800120F8 0C63000C */  jal        func_80018C30
    /* 28FC 800120FC 14000424 */   addiu     $a0, $zero, 0x14
    /* 2900 80012100 1000BF8F */  lw         $ra, 0x10($sp)
    /* 2904 80012104 00000000 */  nop
    /* 2908 80012108 0800E003 */  jr         $ra
    /* 290C 8001210C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800120E8
