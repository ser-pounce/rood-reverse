nonmatching func_800BB2B8, 0x2C

glabel func_800BB2B8
    /* 52AB8 800BB2B8 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 52ABC 800BB2BC 1000BFAF */  sw         $ra, 0x10($sp)
    /* 52AC0 800BB2C0 80FF020C */  jal        vs_battle_getShort
    /* 52AC4 800BB2C4 01008424 */   addiu     $a0, $a0, 0x1
    /* 52AC8 800BB2C8 00140200 */  sll        $v0, $v0, 16
    /* 52ACC 800BB2CC 00E6030C */  jal        func_800F9800
    /* 52AD0 800BB2D0 03240200 */   sra       $a0, $v0, 16
    /* 52AD4 800BB2D4 1000BF8F */  lw         $ra, 0x10($sp)
    /* 52AD8 800BB2D8 21100000 */  addu       $v0, $zero, $zero
    /* 52ADC 800BB2DC 0800E003 */  jr         $ra
    /* 52AE0 800BB2E0 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800BB2B8
