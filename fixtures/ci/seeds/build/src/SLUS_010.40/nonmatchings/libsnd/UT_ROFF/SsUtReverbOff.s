nonmatching SsUtReverbOff, 0x20

glabel SsUtReverbOff
    /* EDC4 8001E5C4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* EDC8 8001E5C8 1000BFAF */  sw         $ra, 0x10($sp)
    /* EDCC 8001E5CC 3D76000C */  jal        _SpuInit
    /* EDD0 8001E5D0 21200000 */   addu      $a0, $zero, $zero
    /* EDD4 8001E5D4 1000BF8F */  lw         $ra, 0x10($sp)
    /* EDD8 8001E5D8 1800BD27 */  addiu      $sp, $sp, 0x18
    /* EDDC 8001E5DC 0800E003 */  jr         $ra
    /* EDE0 8001E5E0 00000000 */   nop
endlabel SsUtReverbOff
