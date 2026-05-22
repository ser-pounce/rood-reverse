nonmatching func_8002A3C4, 0x24

glabel func_8002A3C4
    /* 1ABC4 8002A3C4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1ABC8 8002A3C8 1000BFAF */  sw         $ra, 0x10($sp)
    /* 1ABCC 8002A3CC 2138C000 */  addu       $a3, $a2, $zero
    /* 1ABD0 8002A3D0 FAA8000C */  jal        func_8002A3E8
    /* 1ABD4 8002A3D4 21300000 */   addu      $a2, $zero, $zero
    /* 1ABD8 8002A3D8 1000BF8F */  lw         $ra, 0x10($sp)
    /* 1ABDC 8002A3DC 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 1ABE0 8002A3E0 0800E003 */  jr         $ra
    /* 1ABE4 8002A3E4 00000000 */   nop
endlabel func_8002A3C4
