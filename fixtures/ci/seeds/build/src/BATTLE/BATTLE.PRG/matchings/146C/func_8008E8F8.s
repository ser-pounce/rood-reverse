nonmatching func_8008E8F8, 0x40

glabel func_8008E8F8
    /* 260F8 8008E8F8 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 260FC 8008E8FC 1000B0AF */  sw         $s0, 0x10($sp)
    /* 26100 8008E900 0F80103C */  lui        $s0, %hi(D_800F1DD4)
    /* 26104 8008E904 D41D048E */  lw         $a0, %lo(D_800F1DD4)($s0)
    /* 26108 8008E908 00000000 */  nop
    /* 2610C 8008E90C 03008010 */  beqz       $a0, .L8008E91C
    /* 26110 8008E910 1400BFAF */   sw        $ra, 0x14($sp)
    /* 26114 8008E914 540F010C */  jal        vs_main_freeHeap
    /* 26118 8008E918 00000000 */   nop
  .L8008E91C:
    /* 2611C 8008E91C B10F010C */  jal        vs_main_allocHeap
    /* 26120 8008E920 00080424 */   addiu     $a0, $zero, 0x800
    /* 26124 8008E924 1400BF8F */  lw         $ra, 0x14($sp)
    /* 26128 8008E928 D41D02AE */  sw         $v0, %lo(D_800F1DD4)($s0)
    /* 2612C 8008E92C 1000B08F */  lw         $s0, 0x10($sp)
    /* 26130 8008E930 0800E003 */  jr         $ra
    /* 26134 8008E934 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8008E8F8
