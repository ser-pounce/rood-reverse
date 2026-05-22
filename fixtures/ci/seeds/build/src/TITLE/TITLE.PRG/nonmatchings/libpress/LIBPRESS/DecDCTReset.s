nonmatching DecDCTReset, 0x34

glabel DecDCTReset
    /* 959C 80071D9C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 95A0 80071DA0 1000B0AF */  sw         $s0, 0x10($sp)
    /* 95A4 80071DA4 21808000 */  addu       $s0, $a0, $zero
    /* 95A8 80071DA8 03000016 */  bnez       $s0, .L80071DB8
    /* 95AC 80071DAC 1400BFAF */   sw        $ra, 0x14($sp)
    /* 95B0 80071DB0 357E000C */  jal        ResetCallback
    /* 95B4 80071DB4 00000000 */   nop
  .L80071DB8:
    /* 95B8 80071DB8 14C8010C */  jal        func_80072050
    /* 95BC 80071DBC 21200002 */   addu      $a0, $s0, $zero
    /* 95C0 80071DC0 1400BF8F */  lw         $ra, 0x14($sp)
    /* 95C4 80071DC4 1000B08F */  lw         $s0, 0x10($sp)
    /* 95C8 80071DC8 0800E003 */  jr         $ra
    /* 95CC 80071DCC 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel DecDCTReset
