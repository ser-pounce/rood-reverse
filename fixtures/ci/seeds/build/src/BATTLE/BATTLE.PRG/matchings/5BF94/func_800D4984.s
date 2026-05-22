nonmatching func_800D4984, 0x20

glabel func_800D4984
    /* 6C184 800D4984 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 6C188 800D4988 1000BFAF */  sw         $ra, 0x10($sp)
    /* 6C18C 800D498C 4243030C */  jal        func_800D0D08
    /* 6C190 800D4990 00000000 */   nop
    /* 6C194 800D4994 1000BF8F */  lw         $ra, 0x10($sp)
    /* 6C198 800D4998 01000224 */  addiu      $v0, $zero, 0x1
    /* 6C19C 800D499C 0800E003 */  jr         $ra
    /* 6C1A0 800D49A0 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800D4984
