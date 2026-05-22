nonmatching func_800D4A94, 0x20

glabel func_800D4A94
    /* 6C294 800D4A94 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 6C298 800D4A98 1000BFAF */  sw         $ra, 0x10($sp)
    /* 6C29C 800D4A9C BC3F030C */  jal        func_800CFEF0
    /* 6C2A0 800D4AA0 00000000 */   nop
    /* 6C2A4 800D4AA4 1000BF8F */  lw         $ra, 0x10($sp)
    /* 6C2A8 800D4AA8 01000224 */  addiu      $v0, $zero, 0x1
    /* 6C2AC 800D4AAC 0800E003 */  jr         $ra
    /* 6C2B0 800D4AB0 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800D4A94
