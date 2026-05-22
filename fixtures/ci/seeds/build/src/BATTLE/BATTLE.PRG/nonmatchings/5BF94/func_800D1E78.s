nonmatching func_800D1E78, 0x78

glabel func_800D1E78
    /* 69678 800D1E78 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 6967C 800D1E7C 21188000 */  addu       $v1, $a0, $zero
    /* 69680 800D1E80 1400BFAF */  sw         $ra, 0x14($sp)
    /* 69684 800D1E84 1000B0AF */  sw         $s0, 0x10($sp)
    /* 69688 800D1E88 01006290 */  lbu        $v0, 0x1($v1)
    /* 6968C 800D1E8C 00000000 */  nop
    /* 69690 800D1E90 40004230 */  andi       $v0, $v0, 0x40
    /* 69694 800D1E94 07004010 */  beqz       $v0, .L800D1EB4
    /* 69698 800D1E98 00000000 */   nop
    /* 6969C 800D1E9C 03006490 */  lbu        $a0, 0x3($v1)
    /* 696A0 800D1EA0 00006590 */  lbu        $a1, 0x0($v1)
    /* 696A4 800D1EA4 6344030C */  jal        func_800D118C
    /* 696A8 800D1EA8 00000000 */   nop
    /* 696AC 800D1EAC AE470308 */  j          .L800D1EB8
    /* 696B0 800D1EB0 21804000 */   addu      $s0, $v0, $zero
  .L800D1EB4:
    /* 696B4 800D1EB4 03007090 */  lbu        $s0, 0x3($v1)
  .L800D1EB8:
    /* 696B8 800D1EB8 00000000 */  nop
    /* 696BC 800D1EBC 07000012 */  beqz       $s0, .L800D1EDC
    /* 696C0 800D1EC0 00000000 */   nop
    /* 696C4 800D1EC4 B19B000C */  jal        rand
    /* 696C8 800D1EC8 00000000 */   nop
    /* 696CC 800D1ECC 1A005000 */  div        $zero, $v0, $s0
    /* 696D0 800D1ED0 10100000 */  mfhi       $v0
    /* 696D4 800D1ED4 B8470308 */  j          .L800D1EE0
    /* 696D8 800D1ED8 FF004230 */   andi      $v0, $v0, 0xFF
  .L800D1EDC:
    /* 696DC 800D1EDC 21100000 */  addu       $v0, $zero, $zero
  .L800D1EE0:
    /* 696E0 800D1EE0 1400BF8F */  lw         $ra, 0x14($sp)
    /* 696E4 800D1EE4 1000B08F */  lw         $s0, 0x10($sp)
    /* 696E8 800D1EE8 0800E003 */  jr         $ra
    /* 696EC 800D1EEC 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800D1E78
