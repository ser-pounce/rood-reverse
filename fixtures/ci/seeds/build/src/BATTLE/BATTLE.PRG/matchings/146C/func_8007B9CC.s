nonmatching func_8007B9CC, 0x30

glabel func_8007B9CC
    /* 131CC 8007B9CC E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 131D0 8007B9D0 0F80023C */  lui        $v0, %hi(D_800F1860)
    /* 131D4 8007B9D4 0F80033C */  lui        $v1, %hi(D_800F1864)
    /* 131D8 8007B9D8 601840AC */  sw         $zero, %lo(D_800F1860)($v0)
    /* 131DC 8007B9DC 01000224 */  addiu      $v0, $zero, 0x1
    /* 131E0 8007B9E0 1000BFAF */  sw         $ra, 0x10($sp)
    /* 131E4 8007B9E4 D9ED010C */  jal        func_8007B764
    /* 131E8 8007B9E8 641862AC */   sw        $v0, %lo(D_800F1864)($v1)
    /* 131EC 8007B9EC 1000BF8F */  lw         $ra, 0x10($sp)
    /* 131F0 8007B9F0 00000000 */  nop
    /* 131F4 8007B9F4 0800E003 */  jr         $ra
    /* 131F8 8007B9F8 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8007B9CC
