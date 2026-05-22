nonmatching func_8007CF80, 0x4C

glabel func_8007CF80
    /* 14780 8007CF80 21300000 */  addu       $a2, $zero, $zero
    /* 14784 8007CF84 2128C000 */  addu       $a1, $a2, $zero
    /* 14788 8007CF88 0F80023C */  lui        $v0, %hi(vs_battle_actors)
    /* 1478C 8007CF8C 28194324 */  addiu      $v1, $v0, %lo(vs_battle_actors)
  .L8007CF90:
    /* 14790 8007CF90 0000628C */  lw         $v0, 0x0($v1)
    /* 14794 8007CF94 00000000 */  nop
    /* 14798 8007CF98 06004010 */  beqz       $v0, .L8007CFB4
    /* 1479C 8007CF9C 00000000 */   nop
    /* 147A0 8007CFA0 1C004294 */  lhu        $v0, 0x1C($v0)
    /* 147A4 8007CFA4 00000000 */  nop
    /* 147A8 8007CFA8 02004414 */  bne        $v0, $a0, .L8007CFB4
    /* 147AC 8007CFAC 00000000 */   nop
    /* 147B0 8007CFB0 0100C624 */  addiu      $a2, $a2, 0x1
  .L8007CFB4:
    /* 147B4 8007CFB4 0100A524 */  addiu      $a1, $a1, 0x1
    /* 147B8 8007CFB8 1000A22C */  sltiu      $v0, $a1, 0x10
    /* 147BC 8007CFBC F4FF4014 */  bnez       $v0, .L8007CF90
    /* 147C0 8007CFC0 04006324 */   addiu     $v1, $v1, 0x4
    /* 147C4 8007CFC4 0800E003 */  jr         $ra
    /* 147C8 8007CFC8 2110C000 */   addu      $v0, $a2, $zero
endlabel func_8007CF80
