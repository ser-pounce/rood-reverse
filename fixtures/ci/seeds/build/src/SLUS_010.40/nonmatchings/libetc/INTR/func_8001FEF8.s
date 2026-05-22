nonmatching func_8001FEF8, 0x78

glabel func_8001FEF8
    /* 106F8 8001FEF8 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 106FC 8001FEFC 1000B0AF */  sw         $s0, 0x10($sp)
    /* 10700 8001FF00 0380103C */  lui        $s0, %hi(D_8003104C)
    /* 10704 8001FF04 4C101026 */  addiu      $s0, $s0, %lo(D_8003104C)
    /* 10708 8001FF08 1400BFAF */  sw         $ra, 0x14($sp)
    /* 1070C 8001FF0C 00000296 */  lhu        $v0, 0x0($s0)
    /* 10710 8001FF10 00000000 */  nop
    /* 10714 8001FF14 11004014 */  bnez       $v0, .L8001FF5C
    /* 10718 8001FF18 00000000 */   nop
    /* 1071C 8001FF1C 559A000C */  jal        HookEntryInt
    /* 10720 8001FF20 38000426 */   addiu     $a0, $s0, 0x38
    /* 10724 8001FF24 0380043C */  lui        $a0, %hi(D_800320DC)
    /* 10728 8001FF28 DC20848C */  lw         $a0, %lo(D_800320DC)($a0)
    /* 1072C 8001FF2C 32000396 */  lhu        $v1, 0x32($s0)
    /* 10730 8001FF30 01000224 */  addiu      $v0, $zero, 0x1
    /* 10734 8001FF34 000002A6 */  sh         $v0, 0x0($s0)
    /* 10738 8001FF38 000083A4 */  sh         $v1, 0x0($a0)
    /* 1073C 8001FF3C 0380033C */  lui        $v1, %hi(D_800320E0)
    /* 10740 8001FF40 E020638C */  lw         $v1, %lo(D_800320E0)($v1)
    /* 10744 8001FF44 3400028E */  lw         $v0, 0x34($s0)
    /* 10748 8001FF48 00000000 */  nop
    /* 1074C 8001FF4C 619A000C */  jal        ExitCriticalSection
    /* 10750 8001FF50 000062AC */   sw        $v0, 0x0($v1)
    /* 10754 8001FF54 D87F0008 */  j          .L8001FF60
    /* 10758 8001FF58 21100002 */   addu      $v0, $s0, $zero
  .L8001FF5C:
    /* 1075C 8001FF5C 21100000 */  addu       $v0, $zero, $zero
  .L8001FF60:
    /* 10760 8001FF60 1400BF8F */  lw         $ra, 0x14($sp)
    /* 10764 8001FF64 1000B08F */  lw         $s0, 0x10($sp)
    /* 10768 8001FF68 0800E003 */  jr         $ra
    /* 1076C 8001FF6C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8001FEF8
