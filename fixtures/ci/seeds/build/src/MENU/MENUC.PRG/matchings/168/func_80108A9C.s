nonmatching func_80108A9C, 0x38

glabel func_80108A9C
    /* 629C 80108A9C E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 62A0 80108AA0 1000B0AF */  sw         $s0, 0x10($sp)
    /* 62A4 80108AA4 21808000 */  addu       $s0, $a0, $zero
    /* 62A8 80108AA8 1800BFAF */  sw         $ra, 0x18($sp)
    /* 62AC 80108AAC 1400B1AF */  sw         $s1, 0x14($sp)
    /* 62B0 80108AB0 2C00118E */  lw         $s1, 0x2C($s0)
    /* 62B4 80108AB4 90F3030C */  jal        vs_mainMenu_initUiShield
    /* 62B8 80108AB8 2C0000AE */   sw        $zero, 0x2C($s0)
    /* 62BC 80108ABC 2C0011AE */  sw         $s1, 0x2C($s0)
    /* 62C0 80108AC0 1800BF8F */  lw         $ra, 0x18($sp)
    /* 62C4 80108AC4 1400B18F */  lw         $s1, 0x14($sp)
    /* 62C8 80108AC8 1000B08F */  lw         $s0, 0x10($sp)
    /* 62CC 80108ACC 0800E003 */  jr         $ra
    /* 62D0 80108AD0 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_80108A9C
