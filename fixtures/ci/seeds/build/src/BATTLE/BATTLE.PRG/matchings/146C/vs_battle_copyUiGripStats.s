nonmatching vs_battle_copyUiGripStats, 0x7C

glabel vs_battle_copyUiGripStats
    /* 2EAC 8006B6AC 0000A294 */  lhu        $v0, 0x0($a1)
    /* 2EB0 8006B6B0 00000000 */  nop
    /* 2EB4 8006B6B4 000082A4 */  sh         $v0, 0x0($a0)
    /* 2EB8 8006B6B8 0200A290 */  lbu        $v0, 0x2($a1)
    /* 2EBC 8006B6BC 00000000 */  nop
    /* 2EC0 8006B6C0 020082A0 */  sb         $v0, 0x2($a0)
    /* 2EC4 8006B6C4 0400A290 */  lbu        $v0, 0x4($a1)
    /* 2EC8 8006B6C8 00000000 */  nop
    /* 2ECC 8006B6CC 030082A0 */  sb         $v0, 0x3($a0)
    /* 2ED0 8006B6D0 1500A290 */  lbu        $v0, 0x15($a1)
    /* 2ED4 8006B6D4 00000000 */  nop
    /* 2ED8 8006B6D8 040082A0 */  sb         $v0, 0x4($a0)
    /* 2EDC 8006B6DC 0500A290 */  lbu        $v0, 0x5($a1)
    /* 2EE0 8006B6E0 00000000 */  nop
    /* 2EE4 8006B6E4 050082A0 */  sb         $v0, 0x5($a0)
    /* 2EE8 8006B6E8 0600A290 */  lbu        $v0, 0x6($a1)
    /* 2EEC 8006B6EC 00000000 */  nop
    /* 2EF0 8006B6F0 060082A0 */  sb         $v0, 0x6($a0)
    /* 2EF4 8006B6F4 0700A290 */  lbu        $v0, 0x7($a1)
    /* 2EF8 8006B6F8 21300000 */  addu       $a2, $zero, $zero
    /* 2EFC 8006B6FC 070082A0 */  sb         $v0, 0x7($a0)
    /* 2F00 8006B700 21188600 */  addu       $v1, $a0, $a2
  .L8006B704:
    /* 2F04 8006B704 2110A600 */  addu       $v0, $a1, $a2
    /* 2F08 8006B708 1C004290 */  lbu        $v0, 0x1C($v0)
    /* 2F0C 8006B70C 0100C624 */  addiu      $a2, $a2, 0x1
    /* 2F10 8006B710 080062A0 */  sb         $v0, 0x8($v1)
    /* 2F14 8006B714 0400C228 */  slti       $v0, $a2, 0x4
    /* 2F18 8006B718 FAFF4014 */  bnez       $v0, .L8006B704
    /* 2F1C 8006B71C 21188600 */   addu      $v1, $a0, $a2
    /* 2F20 8006B720 0800E003 */  jr         $ra
    /* 2F24 8006B724 00000000 */   nop
endlabel vs_battle_copyUiGripStats
