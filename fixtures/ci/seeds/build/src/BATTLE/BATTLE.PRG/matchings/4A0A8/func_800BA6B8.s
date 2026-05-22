nonmatching func_800BA6B8, 0x28

glabel func_800BA6B8
    /* 51EB8 800BA6B8 0F80023C */  lui        $v0, %hi(D_800F4C69)
    /* 51EBC 800BA6BC 694C4490 */  lbu        $a0, %lo(D_800F4C69)($v0)
    /* 51EC0 800BA6C0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 51EC4 800BA6C4 1000BFAF */  sw         $ra, 0x10($sp)
    /* 51EC8 800BA6C8 7D13010C */  jal        func_80044DF4
    /* 51ECC 800BA6CC 00000000 */   nop
    /* 51ED0 800BA6D0 1000BF8F */  lw         $ra, 0x10($sp)
    /* 51ED4 800BA6D4 21100000 */  addu       $v0, $zero, $zero
    /* 51ED8 800BA6D8 0800E003 */  jr         $ra
    /* 51EDC 800BA6DC 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800BA6B8
