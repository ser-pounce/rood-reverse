nonmatching func_8007CF18, 0x4C

glabel func_8007CF18
    /* 14718 8007CF18 21180000 */  addu       $v1, $zero, $zero
    /* 1471C 8007CF1C 0F80023C */  lui        $v0, %hi(vs_battle_actors)
    /* 14720 8007CF20 28194524 */  addiu      $a1, $v0, %lo(vs_battle_actors)
  .L8007CF24:
    /* 14724 8007CF24 0000A28C */  lw         $v0, 0x0($a1)
    /* 14728 8007CF28 00000000 */  nop
    /* 1472C 8007CF2C 05004010 */  beqz       $v0, .L8007CF44
    /* 14730 8007CF30 00000000 */   nop
    /* 14734 8007CF34 18004294 */  lhu        $v0, 0x18($v0)
    /* 14738 8007CF38 00000000 */  nop
    /* 1473C 8007CF3C 07004410 */  beq        $v0, $a0, .L8007CF5C
    /* 14740 8007CF40 21106000 */   addu      $v0, $v1, $zero
  .L8007CF44:
    /* 14744 8007CF44 01006324 */  addiu      $v1, $v1, 0x1
    /* 14748 8007CF48 1000622C */  sltiu      $v0, $v1, 0x10
    /* 1474C 8007CF4C F5FF4014 */  bnez       $v0, .L8007CF24
    /* 14750 8007CF50 0400A524 */   addiu     $a1, $a1, 0x4
    /* 14754 8007CF54 0800E003 */  jr         $ra
    /* 14758 8007CF58 01000224 */   addiu     $v0, $zero, 0x1
  .L8007CF5C:
    /* 1475C 8007CF5C 0800E003 */  jr         $ra
    /* 14760 8007CF60 00000000 */   nop
endlabel func_8007CF18
