nonmatching vs_battle_script_showTextBox, 0xC4

glabel vs_battle_script_showTextBox
    /* 4E2B0 800B6AB0 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 4E2B4 800B6AB4 1000B0AF */  sw         $s0, 0x10($sp)
    /* 4E2B8 800B6AB8 21808000 */  addu       $s0, $a0, $zero
    /* 4E2BC 800B6ABC 0F80023C */  lui        $v0, %hi(vs_battle_textBoxStatuses)
    /* 4E2C0 800B6AC0 1800BFAF */  sw         $ra, 0x18($sp)
    /* 4E2C4 800B6AC4 1400B1AF */  sw         $s1, 0x14($sp)
    /* 4E2C8 800B6AC8 01000492 */  lbu        $a0, 0x1($s0)
    /* 4E2CC 800B6ACC 004C5124 */  addiu      $s1, $v0, %lo(vs_battle_textBoxStatuses)
    /* 4E2D0 800B6AD0 21109100 */  addu       $v0, $a0, $s1
    /* 4E2D4 800B6AD4 00004290 */  lbu        $v0, 0x0($v0)
    /* 4E2D8 800B6AD8 00000000 */  nop
    /* 4E2DC 800B6ADC 14004014 */  bnez       $v0, .L800B6B30
    /* 4E2E0 800B6AE0 0F80033C */   lui       $v1, %hi(D_800F4BB0)
    /* 4E2E4 800B6AE4 02000292 */  lbu        $v0, 0x2($s0)
    /* 4E2E8 800B6AE8 B04B638C */  lw         $v1, %lo(D_800F4BB0)($v1)
    /* 4E2EC 800B6AEC 40100200 */  sll        $v0, $v0, 1
    /* 4E2F0 800B6AF0 21104300 */  addu       $v0, $v0, $v1
    /* 4E2F4 800B6AF4 00004594 */  lhu        $a1, 0x0($v0)
    /* 4E2F8 800B6AF8 00000000 */  nop
    /* 4E2FC 800B6AFC 40280500 */  sll        $a1, $a1, 1
    /* 4E300 800B6B00 FC1A030C */  jal        vs_battle_setTextBox
    /* 4E304 800B6B04 21286500 */   addu      $a1, $v1, $a1
    /* 4E308 800B6B08 03000292 */  lbu        $v0, 0x3($s0)
    /* 4E30C 800B6B0C 00000000 */  nop
    /* 4E310 800B6B10 13004014 */  bnez       $v0, .L800B6B60
    /* 4E314 800B6B14 21100000 */   addu      $v0, $zero, $zero
    /* 4E318 800B6B18 01000224 */  addiu      $v0, $zero, 0x1
    /* 4E31C 800B6B1C 01000392 */  lbu        $v1, 0x1($s0)
    /* 4E320 800B6B20 21204000 */  addu       $a0, $v0, $zero
    /* 4E324 800B6B24 21187100 */  addu       $v1, $v1, $s1
    /* 4E328 800B6B28 D8DA0208 */  j          .L800B6B60
    /* 4E32C 800B6B2C 000064A0 */   sb        $a0, 0x0($v1)
  .L800B6B30:
    /* 4E330 800B6B30 FC1A030C */  jal        vs_battle_setTextBox
    /* 4E334 800B6B34 21280000 */   addu      $a1, $zero, $zero
    /* 4E338 800B6B38 21184000 */  addu       $v1, $v0, $zero
    /* 4E33C 800B6B3C 08006004 */  bltz       $v1, .L800B6B60
    /* 4E340 800B6B40 01000224 */   addiu     $v0, $zero, 0x1
    /* 4E344 800B6B44 02006018 */  blez       $v1, .L800B6B50
    /* 4E348 800B6B48 0680023C */   lui       $v0, %hi(vs_main_stateFlags + 0x10)
    /* 4E34C 800B6B4C A81543A0 */  sb         $v1, %lo(vs_main_stateFlags + 0x10)($v0)
  .L800B6B50:
    /* 4E350 800B6B50 01000392 */  lbu        $v1, 0x1($s0)
    /* 4E354 800B6B54 21100000 */  addu       $v0, $zero, $zero
    /* 4E358 800B6B58 21187100 */  addu       $v1, $v1, $s1
    /* 4E35C 800B6B5C 000060A0 */  sb         $zero, 0x0($v1)
  .L800B6B60:
    /* 4E360 800B6B60 1800BF8F */  lw         $ra, 0x18($sp)
    /* 4E364 800B6B64 1400B18F */  lw         $s1, 0x14($sp)
    /* 4E368 800B6B68 1000B08F */  lw         $s0, 0x10($sp)
    /* 4E36C 800B6B6C 0800E003 */  jr         $ra
    /* 4E370 800B6B70 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel vs_battle_script_showTextBox
