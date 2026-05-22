nonmatching func_8008B6B4, 0x38

glabel func_8008B6B4
    /* 22EB4 8008B6B4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 22EB8 8008B6B8 0F80023C */  lui        $v0, %hi(D_800F1D6A)
    /* 22EBC 8008B6BC 6A1D40A4 */  sh         $zero, %lo(D_800F1D6A)($v0)
    /* 22EC0 8008B6C0 0F80023C */  lui        $v0, %hi(D_800F1D6C)
    /* 22EC4 8008B6C4 0F80043C */  lui        $a0, %hi(D_800F1D28)
    /* 22EC8 8008B6C8 281D8424 */  addiu      $a0, $a0, %lo(D_800F1D28)
    /* 22ECC 8008B6CC 40000524 */  addiu      $a1, $zero, 0x40
    /* 22ED0 8008B6D0 1000BFAF */  sw         $ra, 0x10($sp)
    /* 22ED4 8008B6D4 4424010C */  jal        vs_main_bzero
    /* 22ED8 8008B6D8 6C1D40A4 */   sh        $zero, %lo(D_800F1D6C)($v0)
    /* 22EDC 8008B6DC 1000BF8F */  lw         $ra, 0x10($sp)
    /* 22EE0 8008B6E0 00000000 */  nop
    /* 22EE4 8008B6E4 0800E003 */  jr         $ra
    /* 22EE8 8008B6E8 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8008B6B4
