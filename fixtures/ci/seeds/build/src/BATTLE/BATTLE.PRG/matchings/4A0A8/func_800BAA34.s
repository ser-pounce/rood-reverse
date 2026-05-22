nonmatching func_800BAA34, 0x24

glabel func_800BAA34
    /* 52234 800BAA34 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 52238 800BAA38 1000BFAF */  sw         $ra, 0x10($sp)
    /* 5223C 800BAA3C C3EF010C */  jal        func_8007BF0C
    /* 52240 800BAA40 00000000 */   nop
    /* 52244 800BAA44 01004238 */  xori       $v0, $v0, 0x1
    /* 52248 800BAA48 1000BF8F */  lw         $ra, 0x10($sp)
    /* 5224C 800BAA4C 2B100200 */  sltu       $v0, $zero, $v0
    /* 52250 800BAA50 0800E003 */  jr         $ra
    /* 52254 800BAA54 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800BAA34
