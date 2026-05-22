nonmatching func_8001A22C, 0x2C

glabel func_8001A22C
    /* AA2C 8001A22C 40008430 */  andi       $a0, $a0, 0x40
    /* AA30 8001A230 05008010 */  beqz       $a0, .L8001A248
    /* AA34 8001A234 4000A22C */   sltiu     $v0, $a1, 0x40
    /* AA38 8001A238 03004014 */  bnez       $v0, .L8001A248
    /* AA3C 8001A23C 8000A22C */   sltiu     $v0, $a1, 0x80
    /* AA40 8001A240 03004014 */  bnez       $v0, .L8001A250
    /* AA44 8001A244 2000A224 */   addiu     $v0, $a1, 0x20
  .L8001A248:
    /* AA48 8001A248 0800E003 */  jr         $ra
    /* AA4C 8001A24C 2110A000 */   addu      $v0, $a1, $zero
  .L8001A250:
    /* AA50 8001A250 0800E003 */  jr         $ra
    /* AA54 8001A254 00000000 */   nop
endlabel func_8001A22C
