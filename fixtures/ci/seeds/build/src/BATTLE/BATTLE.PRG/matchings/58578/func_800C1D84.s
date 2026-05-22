nonmatching func_800C1D84, 0x40

glabel func_800C1D84
    /* 59584 800C1D84 21200000 */  addu       $a0, $zero, $zero
    /* 59588 800C1D88 0F80023C */  lui        $v0, %hi(D_800EB9B8)
    /* 5958C 800C1D8C B8B9438C */  lw         $v1, %lo(D_800EB9B8)($v0)
  .L800C1D90:
    /* 59590 800C1D90 00000000 */  nop
    /* 59594 800C1D94 90096290 */  lbu        $v0, 0x990($v1)
    /* 59598 800C1D98 00000000 */  nop
    /* 5959C 800C1D9C 0200422C */  sltiu      $v0, $v0, 0x2
    /* 595A0 800C1DA0 03004014 */  bnez       $v0, .L800C1DB0
    /* 595A4 800C1DA4 01008424 */   addiu     $a0, $a0, 0x1
    /* 595A8 800C1DA8 0800E003 */  jr         $ra
    /* 595AC 800C1DAC 21100000 */   addu      $v0, $zero, $zero
  .L800C1DB0:
    /* 595B0 800C1DB0 18008228 */  slti       $v0, $a0, 0x18
    /* 595B4 800C1DB4 F6FF4014 */  bnez       $v0, .L800C1D90
    /* 595B8 800C1DB8 14006324 */   addiu     $v1, $v1, 0x14
    /* 595BC 800C1DBC 0800E003 */  jr         $ra
    /* 595C0 800C1DC0 01000224 */   addiu     $v0, $zero, 0x1
endlabel func_800C1D84
