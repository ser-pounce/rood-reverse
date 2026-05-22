nonmatching _GPU_ResetCallback, 0x28

glabel _GPU_ResetCallback
    /* 1B9B4 8002B1B4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1B9B8 8002B1B8 1000BFAF */  sw         $ra, 0x10($sp)
    /* 1B9BC 8002B1BC 0380053C */  lui        $a1, %hi(func_8002A698)
    /* 1B9C0 8002B1C0 98A6A524 */  addiu      $a1, $a1, %lo(func_8002A698)
    /* 1B9C4 8002B1C4 4D7E000C */  jal        DMACallback
    /* 1B9C8 8002B1C8 02000424 */   addiu     $a0, $zero, 0x2
    /* 1B9CC 8002B1CC 1000BF8F */  lw         $ra, 0x10($sp)
    /* 1B9D0 8002B1D0 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 1B9D4 8002B1D4 0800E003 */  jr         $ra
    /* 1B9D8 8002B1D8 00000000 */   nop
endlabel _GPU_ResetCallback
