nonmatching func_80073ACC, 0x30

glabel func_80073ACC
    /* B2CC 80073ACC E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* B2D0 80073AD0 1000BFAF */  sw         $ra, 0x10($sp)
    /* B2D4 80073AD4 432D030C */  jal        func_800CB50C
    /* B2D8 80073AD8 00000000 */   nop
    /* B2DC 80073ADC 03B1010C */  jal        func_8006C40C
    /* B2E0 80073AE0 00000000 */   nop
    /* B2E4 80073AE4 73BD010C */  jal        func_8006F5CC
    /* B2E8 80073AE8 00000000 */   nop
    /* B2EC 80073AEC 1000BF8F */  lw         $ra, 0x10($sp)
    /* B2F0 80073AF0 00000000 */  nop
    /* B2F4 80073AF4 0800E003 */  jr         $ra
    /* B2F8 80073AF8 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80073ACC
