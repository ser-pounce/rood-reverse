nonmatching vs_battle_copyInventoryGemStats, 0xA0

glabel vs_battle_copyInventoryGemStats
    /* 260C 8006AE0C 0000A294 */  lhu        $v0, 0x0($a1)
    /* 2610 8006AE10 00000000 */  nop
    /* 2614 8006AE14 000082A4 */  sh         $v0, 0x0($a0)
    /* 2618 8006AE18 0200A290 */  lbu        $v0, 0x2($a1)
    /* 261C 8006AE1C 00000000 */  nop
    /* 2620 8006AE20 020082A0 */  sb         $v0, 0x2($a0)
    /* 2624 8006AE24 0400A290 */  lbu        $v0, 0x4($a1)
    /* 2628 8006AE28 00000000 */  nop
    /* 262C 8006AE2C 160082A0 */  sb         $v0, 0x16($a0)
    /* 2630 8006AE30 0500A290 */  lbu        $v0, 0x5($a1)
    /* 2634 8006AE34 00000000 */  nop
    /* 2638 8006AE38 050082A0 */  sb         $v0, 0x5($a0)
    /* 263C 8006AE3C 0600A290 */  lbu        $v0, 0x6($a1)
    /* 2640 8006AE40 00000000 */  nop
    /* 2644 8006AE44 060082A0 */  sb         $v0, 0x6($a0)
    /* 2648 8006AE48 0700A290 */  lbu        $v0, 0x7($a1)
    /* 264C 8006AE4C 00000000 */  nop
    /* 2650 8006AE50 070082A0 */  sb         $v0, 0x7($a0)
    /* 2654 8006AE54 1A00A290 */  lbu        $v0, 0x1A($a1)
    /* 2658 8006AE58 21300000 */  addu       $a2, $zero, $zero
    /* 265C 8006AE5C 170082A0 */  sb         $v0, 0x17($a0)
    /* 2660 8006AE60 21188600 */  addu       $v1, $a0, $a2
  .L8006AE64:
    /* 2664 8006AE64 2110A600 */  addu       $v0, $a1, $a2
    /* 2668 8006AE68 08004290 */  lbu        $v0, 0x8($v0)
    /* 266C 8006AE6C 0100C624 */  addiu      $a2, $a2, 0x1
    /* 2670 8006AE70 200062A0 */  sb         $v0, 0x20($v1)
    /* 2674 8006AE74 0600C228 */  slti       $v0, $a2, 0x6
    /* 2678 8006AE78 FAFF4014 */  bnez       $v0, .L8006AE64
    /* 267C 8006AE7C 21188600 */   addu      $v1, $a0, $a2
    /* 2680 8006AE80 21300000 */  addu       $a2, $zero, $zero
    /* 2684 8006AE84 21188600 */  addu       $v1, $a0, $a2
  .L8006AE88:
    /* 2688 8006AE88 2110A600 */  addu       $v0, $a1, $a2
    /* 268C 8006AE8C 10004290 */  lbu        $v0, 0x10($v0)
    /* 2690 8006AE90 0100C624 */  addiu      $a2, $a2, 0x1
    /* 2694 8006AE94 280062A0 */  sb         $v0, 0x28($v1)
    /* 2698 8006AE98 0700C228 */  slti       $v0, $a2, 0x7
    /* 269C 8006AE9C FAFF4014 */  bnez       $v0, .L8006AE88
    /* 26A0 8006AEA0 21188600 */   addu      $v1, $a0, $a2
    /* 26A4 8006AEA4 0800E003 */  jr         $ra
    /* 26A8 8006AEA8 00000000 */   nop
endlabel vs_battle_copyInventoryGemStats
