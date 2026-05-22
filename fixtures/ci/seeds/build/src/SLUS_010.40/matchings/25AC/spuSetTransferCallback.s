nonmatching spuSetTransferCallback, 0x30

glabel spuSetTransferCallback
    /* 3CA0 800134A0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 3CA4 800134A4 0380023C */  lui        $v0, %hi(_isSpuTransfer)
    /* 3CA8 800134A8 01000324 */  addiu      $v1, $zero, 0x1
    /* 3CAC 800134AC 0180043C */  lui        $a0, %hi(_spuWriteComplete)
    /* 3CB0 800134B0 1000BFAF */  sw         $ra, 0x10($sp)
    /* 3CB4 800134B4 F07743AC */  sw         $v1, %lo(_isSpuTransfer)($v0)
    /* 3CB8 800134B8 157B000C */  jal        SpuSetTransferCallback
    /* 3CBC 800134BC 7C348424 */   addiu     $a0, $a0, %lo(_spuWriteComplete)
    /* 3CC0 800134C0 1000BF8F */  lw         $ra, 0x10($sp)
    /* 3CC4 800134C4 00000000 */  nop
    /* 3CC8 800134C8 0800E003 */  jr         $ra
    /* 3CCC 800134CC 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel spuSetTransferCallback
