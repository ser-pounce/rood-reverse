nonmatching _getNewestSaveFile, 0x60

glabel _getNewestSaveFile
    /* 4B4 80102CB4 21300000 */  addu       $a2, $zero, $zero
    /* 4B8 80102CB8 2138C000 */  addu       $a3, $a2, $zero
    /* 4BC 80102CBC 2128C000 */  addu       $a1, $a2, $zero
    /* 4C0 80102CC0 1180023C */  lui        $v0, %hi(_saveFileInfo)
    /* 4C4 80102CC4 40AE448C */  lw         $a0, %lo(_saveFileInfo)($v0)
  .L80102CC8:
    /* 4C8 80102CC8 00000000 */  nop
    /* 4CC 80102CCC 0400828C */  lw         $v0, 0x4($a0)
    /* 4D0 80102CD0 00000000 */  nop
    /* 4D4 80102CD4 0300422C */  sltiu      $v0, $v0, 0x3
    /* 4D8 80102CD8 08004014 */  bnez       $v0, .L80102CFC
    /* 4DC 80102CDC 00000000 */   nop
    /* 4E0 80102CE0 0800838C */  lw         $v1, 0x8($a0)
    /* 4E4 80102CE4 00000000 */  nop
    /* 4E8 80102CE8 2B10C300 */  sltu       $v0, $a2, $v1
    /* 4EC 80102CEC 03004010 */  beqz       $v0, .L80102CFC
    /* 4F0 80102CF0 00000000 */   nop
    /* 4F4 80102CF4 21306000 */  addu       $a2, $v1, $zero
    /* 4F8 80102CF8 2138A000 */  addu       $a3, $a1, $zero
  .L80102CFC:
    /* 4FC 80102CFC 0100A524 */  addiu      $a1, $a1, 0x1
    /* 500 80102D00 0500A22C */  sltiu      $v0, $a1, 0x5
    /* 504 80102D04 F0FF4014 */  bnez       $v0, .L80102CC8
    /* 508 80102D08 80008424 */   addiu     $a0, $a0, 0x80
    /* 50C 80102D0C 0800E003 */  jr         $ra
    /* 510 80102D10 2110E000 */   addu      $v0, $a3, $zero
endlabel _getNewestSaveFile
