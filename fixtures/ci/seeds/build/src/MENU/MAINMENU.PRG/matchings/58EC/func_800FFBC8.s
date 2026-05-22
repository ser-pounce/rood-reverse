nonmatching func_800FFBC8, 0x3C

glabel func_800FFBC8
    /* 63C8 800FFBC8 0680023C */  lui        $v0, %hi(D_80060028)
    /* 63CC 800FFBCC 28004290 */  lbu        $v0, %lo(D_80060028)($v0)
    /* 63D0 800FFBD0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 63D4 800FFBD4 05004010 */  beqz       $v0, .L800FFBEC
    /* 63D8 800FFBD8 1000BFAF */   sw        $ra, 0x10($sp)
    /* 63DC 800FFBDC 8123030C */  jal        func_800C8E04
    /* 63E0 800FFBE0 02000424 */   addiu     $a0, $zero, 0x2
    /* 63E4 800FFBE4 FDFE0308 */  j          .L800FFBF4
    /* 63E8 800FFBE8 00000000 */   nop
  .L800FFBEC:
    /* 63EC 800FFBEC EAFE030C */  jal        func_800FFBA8
    /* 63F0 800FFBF0 00000000 */   nop
  .L800FFBF4:
    /* 63F4 800FFBF4 1000BF8F */  lw         $ra, 0x10($sp)
    /* 63F8 800FFBF8 00000000 */  nop
    /* 63FC 800FFBFC 0800E003 */  jr         $ra
    /* 6400 800FFC00 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800FFBC8
