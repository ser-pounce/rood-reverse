nonmatching CdFlush, 0x20

glabel CdFlush
    /* 10C5C 8002045C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 10C60 80020460 1000BFAF */  sw         $ra, 0x10($sp)
    /* 10C64 80020464 4186000C */  jal        CD_flush
    /* 10C68 80020468 00000000 */   nop
    /* 10C6C 8002046C 1000BF8F */  lw         $ra, 0x10($sp)
    /* 10C70 80020470 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 10C74 80020474 0800E003 */  jr         $ra
    /* 10C78 80020478 00000000 */   nop
endlabel CdFlush
