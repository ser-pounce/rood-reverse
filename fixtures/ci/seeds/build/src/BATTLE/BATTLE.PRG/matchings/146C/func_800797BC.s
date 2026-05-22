nonmatching func_800797BC, 0x50

glabel func_800797BC
    /* 10FBC 800797BC E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 10FC0 800797C0 1000BFAF */  sw         $ra, 0x10($sp)
    /* 10FC4 800797C4 EF25030C */  jal        func_800C97BC
    /* 10FC8 800797C8 00000000 */   nop
    /* 10FCC 800797CC 9B2D030C */  jal        func_800CB66C
    /* 10FD0 800797D0 00000000 */   nop
    /* 10FD4 800797D4 00004384 */  lh         $v1, 0x0($v0)
    /* 10FD8 800797D8 01000224 */  addiu      $v0, $zero, 0x1
    /* 10FDC 800797DC 07006210 */  beq        $v1, $v0, .L800797FC
    /* 10FE0 800797E0 00000000 */   nop
    /* 10FE4 800797E4 03B1010C */  jal        func_8006C40C
    /* 10FE8 800797E8 00000000 */   nop
    /* 10FEC 800797EC 452C030C */  jal        func_800CB114
    /* 10FF0 800797F0 00000000 */   nop
    /* 10FF4 800797F4 27BE010C */  jal        func_8006F89C
    /* 10FF8 800797F8 00000000 */   nop
  .L800797FC:
    /* 10FFC 800797FC 1000BF8F */  lw         $ra, 0x10($sp)
    /* 11000 80079800 00000000 */  nop
    /* 11004 80079804 0800E003 */  jr         $ra
    /* 11008 80079808 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800797BC
