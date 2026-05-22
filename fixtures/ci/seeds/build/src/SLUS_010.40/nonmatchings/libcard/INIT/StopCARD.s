nonmatching StopCARD, 0x28

glabel StopCARD
    /* 1F20C 8002EA0C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1F210 8002EA10 1000BFAF */  sw         $ra, 0x10($sp)
    /* 1F214 8002EA14 A9BB000C */  jal        StopCARD2
    /* 1F218 8002EA18 00000000 */   nop
    /* 1F21C 8002EA1C 35BC000C */  jal        _ExitCard
    /* 1F220 8002EA20 00000000 */   nop
    /* 1F224 8002EA24 1000BF8F */  lw         $ra, 0x10($sp)
    /* 1F228 8002EA28 21100000 */  addu       $v0, $zero, $zero
    /* 1F22C 8002EA2C 0800E003 */  jr         $ra
    /* 1F230 8002EA30 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel StopCARD
