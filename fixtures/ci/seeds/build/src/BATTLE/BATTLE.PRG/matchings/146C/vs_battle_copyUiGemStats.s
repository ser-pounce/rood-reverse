nonmatching vs_battle_copyUiGemStats, 0x94

glabel vs_battle_copyUiGemStats
    /* 2F28 8006B728 0000A294 */  lhu        $v0, 0x0($a1)
    /* 2F2C 8006B72C 00000000 */  nop
    /* 2F30 8006B730 000082A4 */  sh         $v0, 0x0($a0)
    /* 2F34 8006B734 0200A290 */  lbu        $v0, 0x2($a1)
    /* 2F38 8006B738 00000000 */  nop
    /* 2F3C 8006B73C 020082A0 */  sb         $v0, 0x2($a0)
    /* 2F40 8006B740 1600A290 */  lbu        $v0, 0x16($a1)
    /* 2F44 8006B744 00000000 */  nop
    /* 2F48 8006B748 040082A0 */  sb         $v0, 0x4($a0)
    /* 2F4C 8006B74C 0500A290 */  lbu        $v0, 0x5($a1)
    /* 2F50 8006B750 00000000 */  nop
    /* 2F54 8006B754 050082A0 */  sb         $v0, 0x5($a0)
    /* 2F58 8006B758 0600A290 */  lbu        $v0, 0x6($a1)
    /* 2F5C 8006B75C 00000000 */  nop
    /* 2F60 8006B760 060082A0 */  sb         $v0, 0x6($a0)
    /* 2F64 8006B764 0700A290 */  lbu        $v0, 0x7($a1)
    /* 2F68 8006B768 21300000 */  addu       $a2, $zero, $zero
    /* 2F6C 8006B76C 070082A0 */  sb         $v0, 0x7($a0)
    /* 2F70 8006B770 21188600 */  addu       $v1, $a0, $a2
  .L8006B774:
    /* 2F74 8006B774 2110A600 */  addu       $v0, $a1, $a2
    /* 2F78 8006B778 20004290 */  lbu        $v0, 0x20($v0)
    /* 2F7C 8006B77C 0100C624 */  addiu      $a2, $a2, 0x1
    /* 2F80 8006B780 080062A0 */  sb         $v0, 0x8($v1)
    /* 2F84 8006B784 0600C228 */  slti       $v0, $a2, 0x6
    /* 2F88 8006B788 FAFF4014 */  bnez       $v0, .L8006B774
    /* 2F8C 8006B78C 21188600 */   addu      $v1, $a0, $a2
    /* 2F90 8006B790 21300000 */  addu       $a2, $zero, $zero
    /* 2F94 8006B794 21188600 */  addu       $v1, $a0, $a2
  .L8006B798:
    /* 2F98 8006B798 2110A600 */  addu       $v0, $a1, $a2
    /* 2F9C 8006B79C 28004290 */  lbu        $v0, 0x28($v0)
    /* 2FA0 8006B7A0 0100C624 */  addiu      $a2, $a2, 0x1
    /* 2FA4 8006B7A4 100062A0 */  sb         $v0, 0x10($v1)
    /* 2FA8 8006B7A8 0700C228 */  slti       $v0, $a2, 0x7
    /* 2FAC 8006B7AC FAFF4014 */  bnez       $v0, .L8006B798
    /* 2FB0 8006B7B0 21188600 */   addu      $v1, $a0, $a2
    /* 2FB4 8006B7B4 0800E003 */  jr         $ra
    /* 2FB8 8006B7B8 00000000 */   nop
endlabel vs_battle_copyUiGemStats
