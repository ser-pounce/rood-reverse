nonmatching _spuWriteComplete, 0x24

glabel _spuWriteComplete
    /* 3C7C 8001347C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 3C80 80013480 1000BFAF */  sw         $ra, 0x10($sp)
    /* 3C84 80013484 157B000C */  jal        SpuSetTransferCallback
    /* 3C88 80013488 21200000 */   addu      $a0, $zero, $zero
    /* 3C8C 8001348C 1000BF8F */  lw         $ra, 0x10($sp)
    /* 3C90 80013490 0380023C */  lui        $v0, %hi(_isSpuTransfer)
    /* 3C94 80013494 F07740AC */  sw         $zero, %lo(_isSpuTransfer)($v0)
    /* 3C98 80013498 0800E003 */  jr         $ra
    /* 3C9C 8001349C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel _spuWriteComplete
