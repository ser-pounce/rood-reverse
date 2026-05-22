nonmatching DecDCToutSync, 0x3C

glabel DecDCToutSync
    /* 97CC 80071FCC E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 97D0 80071FD0 05008014 */  bnez       $a0, .L80071FE8
    /* 97D4 80071FD4 1000BFAF */   sw        $ra, 0x10($sp)
    /* 97D8 80071FD8 BCC8010C */  jal        func_800722F0
    /* 97DC 80071FDC 00000000 */   nop
    /* 97E0 80071FE0 FEC70108 */  j          .L80071FF8
    /* 97E4 80071FE4 00000000 */   nop
  .L80071FE8:
    /* 97E8 80071FE8 E1C8010C */  jal        func_80072384
    /* 97EC 80071FEC 00000000 */   nop
    /* 97F0 80071FF0 02160200 */  srl        $v0, $v0, 24
    /* 97F4 80071FF4 01004230 */  andi       $v0, $v0, 0x1
  .L80071FF8:
    /* 97F8 80071FF8 1000BF8F */  lw         $ra, 0x10($sp)
    /* 97FC 80071FFC 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 9800 80072000 0800E003 */  jr         $ra
    /* 9804 80072004 00000000 */   nop
endlabel DecDCToutSync
