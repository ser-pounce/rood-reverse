nonmatching func_80016DA8, 0x50

glabel func_80016DA8
    /* 75A8 80016DA8 FF7F8430 */  andi       $a0, $a0, 0x7FFF
    /* 75AC 80016DAC 03008014 */  bnez       $a0, .L80016DBC
    /* 75B0 80016DB0 21180000 */   addu      $v1, $zero, $zero
    /* 75B4 80016DB4 0800E003 */  jr         $ra
    /* 75B8 80016DB8 21106000 */   addu      $v0, $v1, $zero
  .L80016DBC:
    /* 75BC 80016DBC 0380023C */  lui        $v0, %hi(D_800377E0)
    /* 75C0 80016DC0 E0774524 */  addiu      $a1, $v0, %lo(D_800377E0)
    /* 75C4 80016DC4 0400A28C */  lw         $v0, 0x4($a1)
    /* 75C8 80016DC8 00000000 */  nop
    /* 75CC 80016DCC 03008214 */  bne        $a0, $v0, .L80016DDC
    /* 75D0 80016DD0 00000000 */   nop
    /* 75D4 80016DD4 7C5B0008 */  j          .L80016DF0
    /* 75D8 80016DD8 01000324 */   addiu     $v1, $zero, 0x1
  .L80016DDC:
    /* 75DC 80016DDC 0800A28C */  lw         $v0, 0x8($a1)
    /* 75E0 80016DE0 00000000 */  nop
    /* 75E4 80016DE4 02008214 */  bne        $a0, $v0, .L80016DF0
    /* 75E8 80016DE8 00000000 */   nop
    /* 75EC 80016DEC 02000324 */  addiu      $v1, $zero, 0x2
  .L80016DF0:
    /* 75F0 80016DF0 0800E003 */  jr         $ra
    /* 75F4 80016DF4 21106000 */   addu      $v0, $v1, $zero
endlabel func_80016DA8
