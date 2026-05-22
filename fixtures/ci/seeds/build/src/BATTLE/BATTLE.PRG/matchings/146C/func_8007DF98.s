nonmatching func_8007DF98, 0x58

glabel func_8007DF98
    /* 15798 8007DF98 21200000 */  addu       $a0, $zero, $zero
    /* 1579C 8007DF9C 0F80023C */  lui        $v0, %hi(D_800F19A8)
    /* 157A0 8007DFA0 A8194724 */  addiu      $a3, $v0, %lo(D_800F19A8)
    /* 157A4 8007DFA4 FE000524 */  addiu      $a1, $zero, 0xFE
    /* 157A8 8007DFA8 FD000624 */  addiu      $a2, $zero, 0xFD
    /* 157AC 8007DFAC 21188700 */  addu       $v1, $a0, $a3
  .L8007DFB0:
    /* 157B0 8007DFB0 00006290 */  lbu        $v0, 0x0($v1)
    /* 157B4 8007DFB4 00000000 */  nop
    /* 157B8 8007DFB8 03004514 */  bne        $v0, $a1, .L8007DFC8
    /* 157BC 8007DFBC 00000000 */   nop
    /* 157C0 8007DFC0 000060A0 */  sb         $zero, 0x0($v1)
    /* 157C4 8007DFC4 00006290 */  lbu        $v0, 0x0($v1)
  .L8007DFC8:
    /* 157C8 8007DFC8 00000000 */  nop
    /* 157CC 8007DFCC 02004614 */  bne        $v0, $a2, .L8007DFD8
    /* 157D0 8007DFD0 00000000 */   nop
    /* 157D4 8007DFD4 000065A0 */  sb         $a1, 0x0($v1)
  .L8007DFD8:
    /* 157D8 8007DFD8 01008424 */  addiu      $a0, $a0, 0x1
    /* 157DC 8007DFDC 20008228 */  slti       $v0, $a0, 0x20
    /* 157E0 8007DFE0 F3FF4014 */  bnez       $v0, .L8007DFB0
    /* 157E4 8007DFE4 21188700 */   addu      $v1, $a0, $a3
    /* 157E8 8007DFE8 0800E003 */  jr         $ra
    /* 157EC 8007DFEC 00000000 */   nop
endlabel func_8007DF98
