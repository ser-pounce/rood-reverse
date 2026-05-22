nonmatching func_8007B3D0, 0x20

glabel func_8007B3D0
    /* 12BD0 8007B3D0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 12BD4 8007B3D4 1000BFAF */  sw         $ra, 0x10($sp)
    /* 12BD8 8007B3D8 201B010C */  jal        vs_main_loadClutTransition
    /* 12BDC 8007B3DC 0400A524 */   addiu     $a1, $a1, 0x4
    /* 12BE0 8007B3E0 1000BF8F */  lw         $ra, 0x10($sp)
    /* 12BE4 8007B3E4 00000000 */  nop
    /* 12BE8 8007B3E8 0800E003 */  jr         $ra
    /* 12BEC 8007B3EC 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8007B3D0
