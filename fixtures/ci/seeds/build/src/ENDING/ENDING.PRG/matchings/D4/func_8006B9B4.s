nonmatching func_8006B9B4, 0x28

glabel func_8006B9B4
    /* 31B4 8006B9B4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 31B8 8006B9B8 0400043C */  lui        $a0, (0x41EB0 >> 16)
    /* 31BC 8006B9BC B01E8434 */  ori        $a0, $a0, (0x41EB0 & 0xFFFF)
    /* 31C0 8006B9C0 1000BFAF */  sw         $ra, 0x10($sp)
    /* 31C4 8006B9C4 7A12010C */  jal        vs_main_streamXa
    /* 31C8 8006B9C8 FF7F0524 */   addiu     $a1, $zero, 0x7FFF
    /* 31CC 8006B9CC 1000BF8F */  lw         $ra, 0x10($sp)
    /* 31D0 8006B9D0 00000000 */  nop
    /* 31D4 8006B9D4 0800E003 */  jr         $ra
    /* 31D8 8006B9D8 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8006B9B4
