nonmatching SsUtReverbOn, 0x20

glabel SsUtReverbOn
    /* EDE4 8001E5E4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* EDE8 8001E5E8 1000BFAF */  sw         $ra, 0x10($sp)
    /* EDEC 8001E5EC 3D76000C */  jal        _SpuInit
    /* EDF0 8001E5F0 01000424 */   addiu     $a0, $zero, 0x1
    /* EDF4 8001E5F4 1000BF8F */  lw         $ra, 0x10($sp)
    /* EDF8 8001E5F8 1800BD27 */  addiu      $sp, $sp, 0x18
    /* EDFC 8001E5FC 0800E003 */  jr         $ra
    /* EE00 8001E600 00000000 */   nop
endlabel SsUtReverbOn
