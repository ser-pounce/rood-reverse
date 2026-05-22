nonmatching func_8007B764, 0x78

glabel func_8007B764
    /* 12F64 8007B764 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 12F68 8007B768 1000BFAF */  sw         $ra, 0x10($sp)
    /* 12F6C 8007B76C FDFA020C */  jal        vs_battle_getStateFlag
    /* 12F70 8007B770 AB000424 */   addiu     $a0, $zero, 0xAB
    /* 12F74 8007B774 FF004230 */  andi       $v0, $v0, 0xFF
    /* 12F78 8007B778 0300422C */  sltiu      $v0, $v0, 0x3
    /* 12F7C 8007B77C 11004014 */  bnez       $v0, .L8007B7C4
    /* 12F80 8007B780 0F80023C */   lui       $v0, %hi(_lootListHead)
    /* 12F84 8007B784 0019448C */  lw         $a0, %lo(_lootListHead)($v0)
    /* 12F88 8007B788 00000000 */  nop
    /* 12F8C 8007B78C 09008010 */  beqz       $a0, .L8007B7B4
    /* 12F90 8007B790 00000000 */   nop
    /* 12F94 8007B794 562C030C */  jal        func_800CB158
    /* 12F98 8007B798 00000000 */   nop
    /* 12F9C 8007B79C 0F80033C */  lui        $v1, %hi(_cameraMode)
    /* 12FA0 8007B7A0 04000224 */  addiu      $v0, $zero, 0x4
    /* 12FA4 8007B7A4 04ED010C */  jal        func_8007B410
    /* 12FA8 8007B7A8 F01862AC */   sw        $v0, %lo(_cameraMode)($v1)
    /* 12FAC 8007B7AC F3ED0108 */  j          .L8007B7CC
    /* 12FB0 8007B7B0 00000000 */   nop
  .L8007B7B4:
    /* 12FB4 8007B7B4 42ED010C */  jal        func_8007B508
    /* 12FB8 8007B7B8 00000000 */   nop
    /* 12FBC 8007B7BC F3ED0108 */  j          .L8007B7CC
    /* 12FC0 8007B7C0 00000000 */   nop
  .L8007B7C4:
    /* 12FC4 8007B7C4 31ED010C */  jal        func_8007B4C4
    /* 12FC8 8007B7C8 00000000 */   nop
  .L8007B7CC:
    /* 12FCC 8007B7CC 1000BF8F */  lw         $ra, 0x10($sp)
    /* 12FD0 8007B7D0 00000000 */  nop
    /* 12FD4 8007B7D4 0800E003 */  jr         $ra
    /* 12FD8 8007B7D8 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8007B764
