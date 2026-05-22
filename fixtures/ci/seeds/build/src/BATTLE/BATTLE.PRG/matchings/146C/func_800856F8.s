nonmatching func_800856F8, 0x20

glabel func_800856F8
    /* 1CEF8 800856F8 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1CEFC 800856FC 1000BFAF */  sw         $ra, 0x10($sp)
    /* 1CF00 80085700 4424010C */  jal        vs_main_bzero
    /* 1CF04 80085704 4C080524 */   addiu     $a1, $zero, 0x84C
    /* 1CF08 80085708 1000BF8F */  lw         $ra, 0x10($sp)
    /* 1CF0C 8008570C 00000000 */  nop
    /* 1CF10 80085710 0800E003 */  jr         $ra
    /* 1CF14 80085714 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800856F8
