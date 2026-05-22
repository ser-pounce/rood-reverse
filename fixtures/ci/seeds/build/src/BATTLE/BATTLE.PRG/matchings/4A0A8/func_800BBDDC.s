nonmatching func_800BBDDC, 0x28

glabel func_800BBDDC
    /* 535DC 800BBDDC 0F80023C */  lui        $v0, %hi(D_800F4BA4)
    /* 535E0 800BBDE0 A44B448C */  lw         $a0, %lo(D_800F4BA4)($v0)
    /* 535E4 800BBDE4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 535E8 800BBDE8 1000BFAF */  sw         $ra, 0x10($sp)
    /* 535EC 800BBDEC 180F010C */  jal        vs_main_freeHeapR
    /* 535F0 800BBDF0 00000000 */   nop
    /* 535F4 800BBDF4 1000BF8F */  lw         $ra, 0x10($sp)
    /* 535F8 800BBDF8 00000000 */  nop
    /* 535FC 800BBDFC 0800E003 */  jr         $ra
    /* 53600 800BBE00 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800BBDDC
