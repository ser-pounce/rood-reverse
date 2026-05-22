nonmatching func_800122C4, 0x2C

glabel func_800122C4
    /* 2AC4 800122C4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 2AC8 800122C8 0380023C */  lui        $v0, %hi(D_800378C0)
    /* 2ACC 800122CC FF038430 */  andi       $a0, $a0, 0x3FF
    /* 2AD0 800122D0 C07844AC */  sw         $a0, %lo(D_800378C0)($v0)
    /* 2AD4 800122D4 1000BFAF */  sw         $ra, 0x10($sp)
    /* 2AD8 800122D8 0C63000C */  jal        func_80018C30
    /* 2ADC 800122DC 30000424 */   addiu     $a0, $zero, 0x30
    /* 2AE0 800122E0 1000BF8F */  lw         $ra, 0x10($sp)
    /* 2AE4 800122E4 00000000 */  nop
    /* 2AE8 800122E8 0800E003 */  jr         $ra
    /* 2AEC 800122EC 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800122C4
