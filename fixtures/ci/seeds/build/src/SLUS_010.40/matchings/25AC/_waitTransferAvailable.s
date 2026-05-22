nonmatching _waitTransferAvailable, 0x2C

glabel _waitTransferAvailable
    /* 3D5C 8001355C 0380043C */  lui        $a0, %hi(_isSpuTransfer)
    /* 3D60 80013560 F077838C */  lw         $v1, %lo(_isSpuTransfer)($a0)
    /* 3D64 80013564 01000224 */  addiu      $v0, $zero, 0x1
    /* 3D68 80013568 05006214 */  bne        $v1, $v0, .L80013580
    /* 3D6C 8001356C 21184000 */   addu      $v1, $v0, $zero
  .L80013570:
    /* 3D70 80013570 F077828C */  lw         $v0, %lo(_isSpuTransfer)($a0)
    /* 3D74 80013574 00000000 */  nop
    /* 3D78 80013578 FDFF4310 */  beq        $v0, $v1, .L80013570
    /* 3D7C 8001357C 00000000 */   nop
  .L80013580:
    /* 3D80 80013580 0800E003 */  jr         $ra
    /* 3D84 80013584 00000000 */   nop
endlabel _waitTransferAvailable
