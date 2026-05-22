nonmatching func_800120B8, 0x30

glabel func_800120B8
    /* 28B8 800120B8 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 28BC 800120BC 0380023C */  lui        $v0, %hi(D_800378C0)
    /* 28C0 800120C0 C07844AC */  sw         $a0, %lo(D_800378C0)($v0)
    /* 28C4 800120C4 C0784224 */  addiu      $v0, $v0, %lo(D_800378C0)
    /* 28C8 800120C8 12000424 */  addiu      $a0, $zero, 0x12
    /* 28CC 800120CC 1000BFAF */  sw         $ra, 0x10($sp)
    /* 28D0 800120D0 0C63000C */  jal        func_80018C30
    /* 28D4 800120D4 040045AC */   sw        $a1, 0x4($v0)
    /* 28D8 800120D8 1000BF8F */  lw         $ra, 0x10($sp)
    /* 28DC 800120DC 00000000 */  nop
    /* 28E0 800120E0 0800E003 */  jr         $ra
    /* 28E4 800120E4 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800120B8
