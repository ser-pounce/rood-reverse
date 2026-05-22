nonmatching func_80103D8C, 0x38

glabel func_80103D8C
    /* 158C 80103D8C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1590 80103D90 1000BFAF */  sw         $ra, 0x10($sp)
    /* 1594 80103D94 9223030C */  jal        vs_battle_getMenuItem
    /* 1598 80103D98 00000000 */   nop
    /* 159C 80103D9C 04000324 */  addiu      $v1, $zero, 0x4
    /* 15A0 80103DA0 000043A0 */  sb         $v1, 0x0($v0)
    /* 15A4 80103DA4 9B000324 */  addiu      $v1, $zero, 0x9B
    /* 15A8 80103DA8 180043A4 */  sh         $v1, 0x18($v0)
    /* 15AC 80103DAC 12000324 */  addiu      $v1, $zero, 0x12
    /* 15B0 80103DB0 1A0043A4 */  sh         $v1, 0x1A($v0)
    /* 15B4 80103DB4 1000BF8F */  lw         $ra, 0x10($sp)
    /* 15B8 80103DB8 00000000 */  nop
    /* 15BC 80103DBC 0800E003 */  jr         $ra
    /* 15C0 80103DC0 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80103D8C
