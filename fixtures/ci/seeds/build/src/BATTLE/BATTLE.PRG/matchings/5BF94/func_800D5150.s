nonmatching func_800D5150, 0x20

glabel func_800D5150
    /* 6C950 800D5150 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 6C954 800D5154 1000BFAF */  sw         $ra, 0x10($sp)
    /* 6C958 800D5158 9139030C */  jal        func_800CE644
    /* 6C95C 800D515C 1E000424 */   addiu     $a0, $zero, 0x1E
    /* 6C960 800D5160 1000BF8F */  lw         $ra, 0x10($sp)
    /* 6C964 800D5164 00000000 */  nop
    /* 6C968 800D5168 0800E003 */  jr         $ra
    /* 6C96C 800D516C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800D5150
