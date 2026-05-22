nonmatching _SpuCallback, 0x24

glabel _SpuCallback
    /* F2D4 8001EAD4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* F2D8 8001EAD8 1000BFAF */  sw         $ra, 0x10($sp)
    /* F2DC 8001EADC 21288000 */  addu       $a1, $a0, $zero
    /* F2E0 8001EAE0 417E000C */  jal        InterruptCallback
    /* F2E4 8001EAE4 09000424 */   addiu     $a0, $zero, 0x9
    /* F2E8 8001EAE8 1000BF8F */  lw         $ra, 0x10($sp)
    /* F2EC 8001EAEC 1800BD27 */  addiu      $sp, $sp, 0x18
    /* F2F0 8001EAF0 0800E003 */  jr         $ra
    /* F2F4 8001EAF4 00000000 */   nop
endlabel _SpuCallback
    /* F2F8 8001EAF8 00000000 */  nop
    /* F2FC 8001EAFC 00000000 */  nop
    /* F300 8001EB00 00000000 */  nop
