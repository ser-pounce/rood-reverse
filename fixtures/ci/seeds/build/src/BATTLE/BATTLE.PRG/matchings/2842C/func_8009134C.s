nonmatching func_8009134C, 0x2C

glabel func_8009134C
    /* 28B4C 8009134C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 28B50 80091350 0F80023C */  lui        $v0, %hi(D_800F1D98)
    /* 28B54 80091354 981D4224 */  addiu      $v0, $v0, %lo(D_800F1D98)
    /* 28B58 80091358 1000BFAF */  sw         $ra, 0x10($sp)
    /* 28B5C 8009135C 0A0044A4 */  sh         $a0, 0xA($v0)
    /* 28B60 80091360 CA42020C */  jal        func_80090B28
    /* 28B64 80091364 080045A4 */   sh        $a1, 0x8($v0)
    /* 28B68 80091368 1000BF8F */  lw         $ra, 0x10($sp)
    /* 28B6C 8009136C 00000000 */  nop
    /* 28B70 80091370 0800E003 */  jr         $ra
    /* 28B74 80091374 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8009134C
