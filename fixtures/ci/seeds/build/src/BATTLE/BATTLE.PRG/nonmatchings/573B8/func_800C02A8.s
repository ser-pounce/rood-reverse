nonmatching func_800C02A8, 0x30

glabel func_800C02A8
    /* 57AA8 800C02A8 F8FFBD27 */  addiu      $sp, $sp, -0x8
    /* 57AAC 800C02AC 0000BFAF */  sw         $ra, 0x0($sp)
    /* 57AB0 800C02B0 801F043C */  lui        $a0, %hi(D_1F800014_mat)
    /* 57AB4 800C02B4 6605010C */  jal        SetRotMatrix
    /* 57AB8 800C02B8 14008424 */   addiu     $a0, $a0, %lo(D_1F800014_mat)
    /* 57ABC 800C02BC 801F043C */  lui        $a0, %hi(D_1F800014_mat)
    /* 57AC0 800C02C0 5E05010C */  jal        SetTransMatrix
    /* 57AC4 800C02C4 14008424 */   addiu     $a0, $a0, %lo(D_1F800014_mat)
    /* 57AC8 800C02C8 0000BF8F */  lw         $ra, 0x0($sp)
    /* 57ACC 800C02CC 00000000 */  nop
    /* 57AD0 800C02D0 0800E003 */  jr         $ra
    /* 57AD4 800C02D4 0800BD27 */   addiu     $sp, $sp, 0x8
endlabel func_800C02A8
