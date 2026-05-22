nonmatching _getNewestSaveFile, 0x60

glabel _getNewestSaveFile
    /* 554 80068D54 21300000 */  addu       $a2, $zero, $zero
    /* 558 80068D58 2138C000 */  addu       $a3, $a2, $zero
    /* 55C 80068D5C 2128C000 */  addu       $a1, $a2, $zero
    /* 560 80068D60 0E80023C */  lui        $v0, %hi(_saveFileInfo)
    /* 564 80068D64 08EB448C */  lw         $a0, %lo(_saveFileInfo)($v0)
  .L80068D68:
    /* 568 80068D68 00000000 */  nop
    /* 56C 80068D6C 0400828C */  lw         $v0, 0x4($a0)
    /* 570 80068D70 00000000 */  nop
    /* 574 80068D74 0300422C */  sltiu      $v0, $v0, 0x3
    /* 578 80068D78 08004014 */  bnez       $v0, .L80068D9C
    /* 57C 80068D7C 00000000 */   nop
    /* 580 80068D80 0800838C */  lw         $v1, 0x8($a0)
    /* 584 80068D84 00000000 */  nop
    /* 588 80068D88 2B10C300 */  sltu       $v0, $a2, $v1
    /* 58C 80068D8C 03004010 */  beqz       $v0, .L80068D9C
    /* 590 80068D90 00000000 */   nop
    /* 594 80068D94 21306000 */  addu       $a2, $v1, $zero
    /* 598 80068D98 2138A000 */  addu       $a3, $a1, $zero
  .L80068D9C:
    /* 59C 80068D9C 0100A524 */  addiu      $a1, $a1, 0x1
    /* 5A0 80068DA0 0500A22C */  sltiu      $v0, $a1, 0x5
    /* 5A4 80068DA4 F0FF4014 */  bnez       $v0, .L80068D68
    /* 5A8 80068DA8 80008424 */   addiu     $a0, $a0, 0x80
    /* 5AC 80068DAC 0800E003 */  jr         $ra
    /* 5B0 80068DB0 2110E000 */   addu      $v0, $a3, $zero
endlabel _getNewestSaveFile
