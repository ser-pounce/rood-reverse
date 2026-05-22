nonmatching _canPerformAttack, 0x84

glabel _canPerformAttack
    /* 175D8 8007FDD8 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 175DC 8007FDDC 0F00C010 */  beqz       $a2, .L8007FE1C
    /* 175E0 8007FDE0 1000BFAF */   sw        $ra, 0x10($sp)
    /* 175E4 8007FDE4 80100600 */  sll        $v0, $a2, 2
    /* 175E8 8007FDE8 21108200 */  addu       $v0, $a0, $v0
    /* 175EC 8007FDEC 1400428C */  lw         $v0, 0x14($v0)
    /* 175F0 8007FDF0 01000324 */  addiu      $v1, $zero, 0x1
    /* 175F4 8007FDF4 C2110200 */  srl        $v0, $v0, 7
    /* 175F8 8007FDF8 3F004230 */  andi       $v0, $v0, 0x3F
    /* 175FC 8007FDFC 08004314 */  bne        $v0, $v1, .L8007FE20
    /* 17600 8007FE00 0F80033C */   lui       $v1, %hi(_attackPrerequisiteFunctions)
    /* 17604 8007FE04 0300A390 */  lbu        $v1, 0x3($a1)
    /* 17608 8007FE08 04000224 */  addiu      $v0, $zero, 0x4
    /* 1760C 8007FE0C 04006214 */  bne        $v1, $v0, .L8007FE20
    /* 17610 8007FE10 0F80033C */   lui       $v1, %hi(_attackPrerequisiteFunctions)
    /* 17614 8007FE14 93FF0108 */  j          .L8007FE4C
    /* 17618 8007FE18 21100000 */   addu      $v0, $zero, $zero
  .L8007FE1C:
    /* 1761C 8007FE1C 0F80033C */  lui        $v1, %hi(_attackPrerequisiteFunctions)
  .L8007FE20:
    /* 17620 8007FE20 80100600 */  sll        $v0, $a2, 2
    /* 17624 8007FE24 21108200 */  addu       $v0, $a0, $v0
    /* 17628 8007FE28 1400428C */  lw         $v0, 0x14($v0)
    /* 1762C 8007FE2C 54826324 */  addiu      $v1, $v1, %lo(_attackPrerequisiteFunctions)
    /* 17630 8007FE30 42110200 */  srl        $v0, $v0, 5
    /* 17634 8007FE34 FC004230 */  andi       $v0, $v0, 0xFC
    /* 17638 8007FE38 21104300 */  addu       $v0, $v0, $v1
    /* 1763C 8007FE3C 0000428C */  lw         $v0, 0x0($v0)
    /* 17640 8007FE40 00000000 */  nop
    /* 17644 8007FE44 09F84000 */  jalr       $v0
    /* 17648 8007FE48 00000000 */   nop
  .L8007FE4C:
    /* 1764C 8007FE4C 1000BF8F */  lw         $ra, 0x10($sp)
    /* 17650 8007FE50 00000000 */  nop
    /* 17654 8007FE54 0800E003 */  jr         $ra
    /* 17658 8007FE58 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel _canPerformAttack
