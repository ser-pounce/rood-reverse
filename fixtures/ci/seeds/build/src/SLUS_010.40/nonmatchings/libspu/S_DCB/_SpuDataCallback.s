nonmatching _SpuDataCallback, 0x24

glabel _SpuDataCallback
    /* ED94 8001E594 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* ED98 8001E598 1000BFAF */  sw         $ra, 0x10($sp)
    /* ED9C 8001E59C 21288000 */  addu       $a1, $a0, $zero
    /* EDA0 8001E5A0 4D7E000C */  jal        DMACallback
    /* EDA4 8001E5A4 04000424 */   addiu     $a0, $zero, 0x4
    /* EDA8 8001E5A8 1000BF8F */  lw         $ra, 0x10($sp)
    /* EDAC 8001E5AC 1800BD27 */  addiu      $sp, $sp, 0x18
    /* EDB0 8001E5B0 0800E003 */  jr         $ra
    /* EDB4 8001E5B4 00000000 */   nop
endlabel _SpuDataCallback
    /* EDB8 8001E5B8 00000000 */  nop
    /* EDBC 8001E5BC 00000000 */  nop
    /* EDC0 8001E5C0 00000000 */  nop
