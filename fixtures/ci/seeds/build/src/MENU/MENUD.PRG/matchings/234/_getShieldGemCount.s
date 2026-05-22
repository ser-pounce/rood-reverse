nonmatching _getShieldGemCount, 0x58

glabel _getShieldGemCount
    /* 3E84 80106684 21280000 */  addu       $a1, $zero, $zero
    /* 3E88 80106688 1180023C */  lui        $v0, %hi(vs_menuD_containerData)
    /* 3E8C 8010668C 40180400 */  sll        $v1, $a0, 1
    /* 3E90 80106690 21186400 */  addu       $v1, $v1, $a0
    /* 3E94 80106694 00190300 */  sll        $v1, $v1, 4
    /* 3E98 80106698 8C9A428C */  lw         $v0, %lo(vs_menuD_containerData)($v0)
    /* 3E9C 8010669C 00046324 */  addiu      $v1, $v1, 0x400
    /* 3EA0 801066A0 21304300 */  addu       $a2, $v0, $v1
    /* 3EA4 801066A4 1000C490 */  lbu        $a0, 0x10($a2)
    /* 3EA8 801066A8 00000000 */  nop
    /* 3EAC 801066AC 09008010 */  beqz       $a0, .L801066D4
    /* 3EB0 801066B0 2118A000 */   addu      $v1, $a1, $zero
    /* 3EB4 801066B4 2110C500 */  addu       $v0, $a2, $a1
  .L801066B8:
    /* 3EB8 801066B8 2C004290 */  lbu        $v0, 0x2C($v0)
    /* 3EBC 801066BC 0100A524 */  addiu      $a1, $a1, 0x1
    /* 3EC0 801066C0 2B100200 */  sltu       $v0, $zero, $v0
    /* 3EC4 801066C4 21186200 */  addu       $v1, $v1, $v0
    /* 3EC8 801066C8 2A10A400 */  slt        $v0, $a1, $a0
    /* 3ECC 801066CC FAFF4014 */  bnez       $v0, .L801066B8
    /* 3ED0 801066D0 2110C500 */   addu      $v0, $a2, $a1
  .L801066D4:
    /* 3ED4 801066D4 0800E003 */  jr         $ra
    /* 3ED8 801066D8 21106000 */   addu      $v0, $v1, $zero
endlabel _getShieldGemCount
