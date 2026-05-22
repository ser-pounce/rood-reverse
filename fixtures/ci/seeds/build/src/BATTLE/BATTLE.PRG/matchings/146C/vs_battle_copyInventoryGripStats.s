nonmatching vs_battle_copyInventoryGripStats, 0x88

glabel vs_battle_copyInventoryGripStats
    /* 2474 8006AC74 0000A294 */  lhu        $v0, 0x0($a1)
    /* 2478 8006AC78 00000000 */  nop
    /* 247C 8006AC7C 000082A4 */  sh         $v0, 0x0($a0)
    /* 2480 8006AC80 0200A290 */  lbu        $v0, 0x2($a1)
    /* 2484 8006AC84 00000000 */  nop
    /* 2488 8006AC88 020082A0 */  sb         $v0, 0x2($a0)
    /* 248C 8006AC8C 0300A290 */  lbu        $v0, 0x3($a1)
    /* 2490 8006AC90 00000000 */  nop
    /* 2494 8006AC94 040082A0 */  sb         $v0, 0x4($a0)
    /* 2498 8006AC98 0400A290 */  lbu        $v0, 0x4($a1)
    /* 249C 8006AC9C 00000000 */  nop
    /* 24A0 8006ACA0 150082A0 */  sb         $v0, 0x15($a0)
    /* 24A4 8006ACA4 0500A290 */  lbu        $v0, 0x5($a1)
    /* 24A8 8006ACA8 00000000 */  nop
    /* 24AC 8006ACAC 050082A0 */  sb         $v0, 0x5($a0)
    /* 24B0 8006ACB0 0600A290 */  lbu        $v0, 0x6($a1)
    /* 24B4 8006ACB4 00000000 */  nop
    /* 24B8 8006ACB8 060082A0 */  sb         $v0, 0x6($a0)
    /* 24BC 8006ACBC 0700A290 */  lbu        $v0, 0x7($a1)
    /* 24C0 8006ACC0 00000000 */  nop
    /* 24C4 8006ACC4 070082A0 */  sb         $v0, 0x7($a0)
    /* 24C8 8006ACC8 0E00A290 */  lbu        $v0, 0xE($a1)
    /* 24CC 8006ACCC 21300000 */  addu       $a2, $zero, $zero
    /* 24D0 8006ACD0 170082A0 */  sb         $v0, 0x17($a0)
    /* 24D4 8006ACD4 21188600 */  addu       $v1, $a0, $a2
  .L8006ACD8:
    /* 24D8 8006ACD8 2110A600 */  addu       $v0, $a1, $a2
    /* 24DC 8006ACDC 08004290 */  lbu        $v0, 0x8($v0)
    /* 24E0 8006ACE0 0100C624 */  addiu      $a2, $a2, 0x1
    /* 24E4 8006ACE4 1C0062A0 */  sb         $v0, 0x1C($v1)
    /* 24E8 8006ACE8 0400C228 */  slti       $v0, $a2, 0x4
    /* 24EC 8006ACEC FAFF4014 */  bnez       $v0, .L8006ACD8
    /* 24F0 8006ACF0 21188600 */   addu      $v1, $a0, $a2
    /* 24F4 8006ACF4 0800E003 */  jr         $ra
    /* 24F8 8006ACF8 00000000 */   nop
endlabel vs_battle_copyInventoryGripStats
