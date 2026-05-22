nonmatching func_801084E4, 0x30

glabel func_801084E4
    /* 5CE4 801084E4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 5CE8 801084E8 1000B0AF */  sw         $s0, 0x10($sp)
    /* 5CEC 801084EC 1180103C */  lui        $s0, %hi(D_8010A4AC)
    /* 5CF0 801084F0 ACA4048E */  lw         $a0, %lo(D_8010A4AC)($s0)
    /* 5CF4 801084F4 1400BFAF */  sw         $ra, 0x14($sp)
    /* 5CF8 801084F8 180F010C */  jal        vs_main_freeHeapR
    /* 5CFC 801084FC 00000000 */   nop
    /* 5D00 80108500 1400BF8F */  lw         $ra, 0x14($sp)
    /* 5D04 80108504 ACA400AE */  sw         $zero, %lo(D_8010A4AC)($s0)
    /* 5D08 80108508 1000B08F */  lw         $s0, 0x10($sp)
    /* 5D0C 8010850C 0800E003 */  jr         $ra
    /* 5D10 80108510 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_801084E4
