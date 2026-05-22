nonmatching DecDCTinSync, 0x3C

glabel DecDCTinSync
    /* 9790 80071F90 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 9794 80071F94 05008014 */  bnez       $a0, .L80071FAC
    /* 9798 80071F98 1000BFAF */   sw        $ra, 0x10($sp)
    /* 979C 80071F9C 97C8010C */  jal        func_8007225C
    /* 97A0 80071FA0 00000000 */   nop
    /* 97A4 80071FA4 EFC70108 */  j          .L80071FBC
    /* 97A8 80071FA8 00000000 */   nop
  .L80071FAC:
    /* 97AC 80071FAC E1C8010C */  jal        func_80072384
    /* 97B0 80071FB0 00000000 */   nop
    /* 97B4 80071FB4 42170200 */  srl        $v0, $v0, 29
    /* 97B8 80071FB8 01004230 */  andi       $v0, $v0, 0x1
  .L80071FBC:
    /* 97BC 80071FBC 1000BF8F */  lw         $ra, 0x10($sp)
    /* 97C0 80071FC0 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 97C4 80071FC4 0800E003 */  jr         $ra
    /* 97C8 80071FC8 00000000 */   nop
endlabel DecDCTinSync
