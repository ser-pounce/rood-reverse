nonmatching func_8007B7DC, 0x58

glabel func_8007B7DC
    /* 12FDC 8007B7DC E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 12FE0 8007B7E0 1000BFAF */  sw         $ra, 0x10($sp)
    /* 12FE4 8007B7E4 FDFA020C */  jal        vs_battle_getStateFlag
    /* 12FE8 8007B7E8 AB000424 */   addiu     $a0, $zero, 0xAB
    /* 12FEC 8007B7EC FF004230 */  andi       $v0, $v0, 0xFF
    /* 12FF0 8007B7F0 0300422C */  sltiu      $v0, $v0, 0x3
    /* 12FF4 8007B7F4 09004014 */  bnez       $v0, .L8007B81C
    /* 12FF8 8007B7F8 00000000 */   nop
    /* 12FFC 8007B7FC 8F2C030C */  jal        func_800CB23C
    /* 13000 8007B800 00000000 */   nop
    /* 13004 8007B804 0F80033C */  lui        $v1, %hi(_cameraMode)
    /* 13008 8007B808 03000224 */  addiu      $v0, $zero, 0x3
    /* 1300C 8007B80C 04ED010C */  jal        func_8007B410
    /* 13010 8007B810 F01862AC */   sw        $v0, %lo(_cameraMode)($v1)
    /* 13014 8007B814 09EE0108 */  j          .L8007B824
    /* 13018 8007B818 00000000 */   nop
  .L8007B81C:
    /* 1301C 8007B81C D9ED010C */  jal        func_8007B764
    /* 13020 8007B820 00000000 */   nop
  .L8007B824:
    /* 13024 8007B824 1000BF8F */  lw         $ra, 0x10($sp)
    /* 13028 8007B828 00000000 */  nop
    /* 1302C 8007B82C 0800E003 */  jr         $ra
    /* 13030 8007B830 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8007B7DC
