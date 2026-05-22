nonmatching func_8008388C, 0x30

glabel func_8008388C
    /* 1B08C 8008388C E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 1B090 80083890 3000A28F */  lw         $v0, 0x30($sp)
    /* 1B094 80083894 01000324 */  addiu      $v1, $zero, 0x1
    /* 1B098 80083898 1800BFAF */  sw         $ra, 0x18($sp)
    /* 1B09C 8008389C 1400A3AF */  sw         $v1, 0x14($sp)
    /* 1B0A0 800838A0 5204020C */  jal        func_80081148
    /* 1B0A4 800838A4 1000A2AF */   sw        $v0, 0x10($sp)
    /* 1B0A8 800838A8 00140200 */  sll        $v0, $v0, 16
    /* 1B0AC 800838AC 1800BF8F */  lw         $ra, 0x18($sp)
    /* 1B0B0 800838B0 03140200 */  sra        $v0, $v0, 16
    /* 1B0B4 800838B4 0800E003 */  jr         $ra
    /* 1B0B8 800838B8 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8008388C
