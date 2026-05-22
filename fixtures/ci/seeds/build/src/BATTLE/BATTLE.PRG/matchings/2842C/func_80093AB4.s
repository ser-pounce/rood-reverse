nonmatching func_80093AB4, 0x50

glabel func_80093AB4
    /* 2B2B4 80093AB4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 2B2B8 80093AB8 0F80023C */  lui        $v0, %hi(D_800F2270)
    /* 2B2BC 80093ABC 702240A4 */  sh         $zero, %lo(D_800F2270)($v0)
    /* 2B2C0 80093AC0 0F80023C */  lui        $v0, %hi(D_800F2272)
    /* 2B2C4 80093AC4 722240A4 */  sh         $zero, %lo(D_800F2272)($v0)
    /* 2B2C8 80093AC8 0F80023C */  lui        $v0, %hi(D_800F227E)
    /* 2B2CC 80093ACC 7E2240A4 */  sh         $zero, %lo(D_800F227E)($v0)
    /* 2B2D0 80093AD0 0F80023C */  lui        $v0, %hi(D_800F2278)
    /* 2B2D4 80093AD4 782240A4 */  sh         $zero, %lo(D_800F2278)($v0)
    /* 2B2D8 80093AD8 0F80023C */  lui        $v0, %hi(D_800F227A)
    /* 2B2DC 80093ADC 7A2240A4 */  sh         $zero, %lo(D_800F227A)($v0)
    /* 2B2E0 80093AE0 0F80023C */  lui        $v0, %hi(D_800F1BAC)
    /* 2B2E4 80093AE4 AC1B448C */  lw         $a0, %lo(D_800F1BAC)($v0)
    /* 2B2E8 80093AE8 1000BFAF */  sw         $ra, 0x10($sp)
    /* 2B2EC 80093AEC 4424010C */  jal        vs_main_bzero
    /* 2B2F0 80093AF0 00030524 */   addiu     $a1, $zero, 0x300
    /* 2B2F4 80093AF4 1000BF8F */  lw         $ra, 0x10($sp)
    /* 2B2F8 80093AF8 00000000 */  nop
    /* 2B2FC 80093AFC 0800E003 */  jr         $ra
    /* 2B300 80093B00 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80093AB4
