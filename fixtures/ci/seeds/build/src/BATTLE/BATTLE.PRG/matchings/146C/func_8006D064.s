nonmatching func_8006D064, 0x40

glabel func_8006D064
    /* 4864 8006D064 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 4868 8006D068 1800B0AF */  sw         $s0, 0x18($sp)
    /* 486C 8006D06C 0F80103C */  lui        $s0, %hi(D_800F185C)
    /* 4870 8006D070 08000424 */  addiu      $a0, $zero, 0x8
    /* 4874 8006D074 04000524 */  addiu      $a1, $zero, 0x4
    /* 4878 8006D078 5C18068E */  lw         $a2, %lo(D_800F185C)($s0)
    /* 487C 8006D07C 21380000 */  addu       $a3, $zero, $zero
    /* 4880 8006D080 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 4884 8006D084 1000A0AF */  sw         $zero, 0x10($sp)
    /* 4888 8006D088 A7EC010C */  jal        func_8007B29C
    /* 488C 8006D08C 1400A0AF */   sw        $zero, 0x14($sp)
    /* 4890 8006D090 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 4894 8006D094 5C1800AE */  sw         $zero, %lo(D_800F185C)($s0)
    /* 4898 8006D098 1800B08F */  lw         $s0, 0x18($sp)
    /* 489C 8006D09C 0800E003 */  jr         $ra
    /* 48A0 8006D0A0 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8006D064
