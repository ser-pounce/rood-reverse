nonmatching func_8009DC8C, 0x74

glabel func_8009DC8C
    /* 3548C 8009DC8C 0F80023C */  lui        $v0, %hi(D_800F4538)
    /* 35490 8009DC90 38454224 */  addiu      $v0, $v0, %lo(D_800F4538)
    /* 35494 8009DC94 80200400 */  sll        $a0, $a0, 2
    /* 35498 8009DC98 21208200 */  addu       $a0, $a0, $v0
    /* 3549C 8009DC9C 0000878C */  lw         $a3, 0x0($a0)
    /* 354A0 8009DCA0 00000000 */  nop
    /* 354A4 8009DCA4 1400E010 */  beqz       $a3, .L8009DCF8
    /* 354A8 8009DCA8 F8FF033C */   lui       $v1, (0xFFF8FFFF >> 16)
    /* 354AC 8009DCAC FFFF6334 */  ori        $v1, $v1, (0xFFF8FFFF & 0xFFFF)
    /* 354B0 8009DCB0 EFFF053C */  lui        $a1, (0xFFEFFFFF >> 16)
    /* 354B4 8009DCB4 FFFFA534 */  ori        $a1, $a1, (0xFFEFFFFF & 0xFFFF)
    /* 354B8 8009DCB8 FF8F063C */  lui        $a2, (0x8FFFFFFF >> 16)
    /* 354BC 8009DCBC FFFFC634 */  ori        $a2, $a2, (0x8FFFFFFF & 0xFFFF)
    /* 354C0 8009DCC0 E7FF043C */  lui        $a0, (0xFFE7FFFF >> 16)
    /* 354C4 8009DCC4 0800E28C */  lw         $v0, 0x8($a3)
    /* 354C8 8009DCC8 FFFF8434 */  ori        $a0, $a0, (0xFFE7FFFF & 0xFFFF)
    /* 354CC 8009DCCC 1100E0A0 */  sb         $zero, 0x11($a3)
    /* 354D0 8009DCD0 24104300 */  and        $v0, $v0, $v1
    /* 354D4 8009DCD4 0800E2AC */  sw         $v0, 0x8($a3)
    /* 354D8 8009DCD8 24104600 */  and        $v0, $v0, $a2
    /* 354DC 8009DCDC AC05E38C */  lw         $v1, 0x5AC($a3)
    /* 354E0 8009DCE0 24104400 */  and        $v0, $v0, $a0
    /* 354E4 8009DCE4 24186500 */  and        $v1, $v1, $a1
    /* 354E8 8009DCE8 AC05E3AC */  sw         $v1, 0x5AC($a3)
    /* 354EC 8009DCEC FFBF0324 */  addiu      $v1, $zero, -0x4001
    /* 354F0 8009DCF0 24104300 */  and        $v0, $v0, $v1
    /* 354F4 8009DCF4 0800E2AC */  sw         $v0, 0x8($a3)
  .L8009DCF8:
    /* 354F8 8009DCF8 0800E003 */  jr         $ra
    /* 354FC 8009DCFC 00000000 */   nop
endlabel func_8009DC8C
