nonmatching StartPAD, 0x30

glabel StartPAD
    /* 1F370 8002EB70 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1F374 8002EB74 1000BFAF */  sw         $ra, 0x10($sp)
    /* 1F378 8002EB78 51BB000C */  jal        StartPAD2
    /* 1F37C 8002EB7C 00000000 */   nop
    /* 1F380 8002EB80 819A000C */  jal        ChangeClearPAD
    /* 1F384 8002EB84 21200000 */   addu      $a0, $zero, $zero
    /* 1F388 8002EB88 5DBB000C */  jal        EnablePAD
    /* 1F38C 8002EB8C 00000000 */   nop
    /* 1F390 8002EB90 1000BF8F */  lw         $ra, 0x10($sp)
    /* 1F394 8002EB94 01000224 */  addiu      $v0, $zero, 0x1
    /* 1F398 8002EB98 0800E003 */  jr         $ra
    /* 1F39C 8002EB9C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel StartPAD
