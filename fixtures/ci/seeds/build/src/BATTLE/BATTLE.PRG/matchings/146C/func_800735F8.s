nonmatching func_800735F8, 0x120

glabel func_800735F8
    /* ADF8 800735F8 C8FFBD27 */  addiu      $sp, $sp, -0x38
    /* ADFC 800735FC 2800B0AF */  sw         $s0, 0x28($sp)
    /* AE00 80073600 21808000 */  addu       $s0, $a0, $zero
    /* AE04 80073604 01000424 */  addiu      $a0, $zero, 0x1
    /* AE08 80073608 3000BFAF */  sw         $ra, 0x30($sp)
    /* AE0C 8007360C 322D020C */  jal        func_8008B4C8
    /* AE10 80073610 2C00B1AF */   sw        $s1, 0x2C($sp)
    /* AE14 80073614 0F80113C */  lui        $s1, %hi(vs_battle_characterState)
    /* AE18 80073618 FC19228E */  lw         $v0, %lo(vs_battle_characterState)($s1)
    /* AE1C 8007361C 00000000 */  nop
    /* AE20 80073620 2000448C */  lw         $a0, 0x20($v0)
    /* AE24 80073624 982D030C */  jal        func_800CB660
    /* AE28 80073628 01008430 */   andi      $a0, $a0, 0x1
    /* AE2C 8007362C 02000386 */  lh         $v1, 0x2($s0)
    /* AE30 80073630 00000000 */  nop
    /* AE34 80073634 09006228 */  slti       $v0, $v1, 0x9
    /* AE38 80073638 05004010 */  beqz       $v0, .L80073650
    /* AE3C 8007363C 06006228 */   slti      $v0, $v1, 0x6
    /* AE40 80073640 08004010 */  beqz       $v0, .L80073664
    /* AE44 80073644 00000000 */   nop
    /* AE48 80073648 BDCD0108 */  j          .L800736F4
    /* AE4C 8007364C 00000000 */   nop
  .L80073650:
    /* AE50 80073650 0A000224 */  addiu      $v0, $zero, 0xA
    /* AE54 80073654 08006210 */  beq        $v1, $v0, .L80073678
    /* AE58 80073658 21200000 */   addu      $a0, $zero, $zero
    /* AE5C 8007365C BDCD0108 */  j          .L800736F4
    /* AE60 80073660 00000000 */   nop
  .L80073664:
    /* AE64 80073664 04000596 */  lhu        $a1, 0x4($s0)
    /* AE68 80073668 B1CB010C */  jal        func_80072EC4
    /* AE6C 8007366C 21200000 */   addu      $a0, $zero, $zero
    /* AE70 80073670 C1CD0108 */  j          .L80073704
    /* AE74 80073674 00000000 */   nop
  .L80073678:
    /* AE78 80073678 4284020C */  jal        func_800A1108
    /* AE7C 8007367C 1800A527 */   addiu     $a1, $sp, 0x18
    /* AE80 80073680 2CBD010C */  jal        func_8006F4B0
    /* AE84 80073684 1800A427 */   addiu     $a0, $sp, 0x18
    /* AE88 80073688 B7000424 */  addiu      $a0, $zero, 0xB7
    /* AE8C 8007368C 05FB020C */  jal        vs_battle_setStateFlag
    /* AE90 80073690 01000524 */   addiu     $a1, $zero, 0x1
    /* AE94 80073694 08000224 */  addiu      $v0, $zero, 0x8
    /* AE98 80073698 0400068E */  lw         $a2, 0x4($s0)
    /* AE9C 8007369C 21380000 */  addu       $a3, $zero, $zero
    /* AEA0 800736A0 1000A2AF */  sw         $v0, 0x10($sp)
    /* AEA4 800736A4 FF01C430 */  andi       $a0, $a2, 0x1FF
    /* AEA8 800736A8 422A0600 */  srl        $a1, $a2, 9
    /* AEAC 800736AC 1F00A530 */  andi       $a1, $a1, 0x1F
    /* AEB0 800736B0 82330600 */  srl        $a2, $a2, 14
    /* AEB4 800736B4 A5F1010C */  jal        func_8007C694
    /* AEB8 800736B8 1F00C630 */   andi      $a2, $a2, 0x1F
    /* AEBC 800736BC FC19228E */  lw         $v0, %lo(vs_battle_characterState)($s1)
    /* AEC0 800736C0 0400038E */  lw         $v1, 0x4($s0)
    /* AEC4 800736C4 3C00458C */  lw         $a1, 0x3C($v0)
    /* AEC8 800736C8 C21C0300 */  srl        $v1, $v1, 19
    /* AECC 800736CC 1C00A284 */  lh         $v0, 0x1C($a1)
    /* AED0 800736D0 1C00A494 */  lhu        $a0, 0x1C($a1)
    /* AED4 800736D4 2A104300 */  slt        $v0, $v0, $v1
    /* AED8 800736D8 02004014 */  bnez       $v0, .L800736E4
    /* AEDC 800736DC 23108300 */   subu      $v0, $a0, $v1
    /* AEE0 800736E0 1C00A2A4 */  sh         $v0, 0x1C($a1)
  .L800736E4:
    /* AEE4 800736E4 21200000 */  addu       $a0, $zero, $zero
    /* AEE8 800736E8 21288000 */  addu       $a1, $a0, $zero
    /* AEEC 800736EC 1C78020C */  jal        func_8009E070
    /* AEF0 800736F0 07000624 */   addiu     $a2, $zero, 0x7
  .L800736F4:
    /* AEF4 800736F4 73BD010C */  jal        func_8006F5CC
    /* AEF8 800736F8 00000000 */   nop
    /* AEFC 800736FC 73CD010C */  jal        func_800735CC
    /* AF00 80073700 21200002 */   addu      $a0, $s0, $zero
  .L80073704:
    /* AF04 80073704 3000BF8F */  lw         $ra, 0x30($sp)
    /* AF08 80073708 2C00B18F */  lw         $s1, 0x2C($sp)
    /* AF0C 8007370C 2800B08F */  lw         $s0, 0x28($sp)
    /* AF10 80073710 0800E003 */  jr         $ra
    /* AF14 80073714 3800BD27 */   addiu     $sp, $sp, 0x38
endlabel func_800735F8
