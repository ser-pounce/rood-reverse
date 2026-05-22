nonmatching func_800B9BF8, 0x20

glabel func_800B9BF8
    /* 513F8 800B9BF8 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 513FC 800B9BFC 1000BFAF */  sw         $ra, 0x10($sp)
    /* 51400 800B9C00 E6F0010C */  jal        func_8007C398
    /* 51404 800B9C04 00000000 */   nop
    /* 51408 800B9C08 1000BF8F */  lw         $ra, 0x10($sp)
    /* 5140C 800B9C0C 2B100200 */  sltu       $v0, $zero, $v0
    /* 51410 800B9C10 0800E003 */  jr         $ra
    /* 51414 800B9C14 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800B9BF8
