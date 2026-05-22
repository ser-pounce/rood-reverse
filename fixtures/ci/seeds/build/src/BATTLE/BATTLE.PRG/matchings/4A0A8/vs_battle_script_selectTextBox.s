nonmatching vs_battle_script_selectTextBox, 0x90

glabel vs_battle_script_selectTextBox
    /* 4EB98 800B7398 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 4EB9C 800B739C 0F80023C */  lui        $v0, %hi(D_800F4C2C)
    /* 4EBA0 800B73A0 2C4C4390 */  lbu        $v1, %lo(D_800F4C2C)($v0)
    /* 4EBA4 800B73A4 02000224 */  addiu      $v0, $zero, 0x2
    /* 4EBA8 800B73A8 1400BFAF */  sw         $ra, 0x14($sp)
    /* 4EBAC 800B73AC 03006214 */  bne        $v1, $v0, .L800B73BC
    /* 4EBB0 800B73B0 1000B0AF */   sw        $s0, 0x10($sp)
    /* 4EBB4 800B73B4 06DD0208 */  j          .L800B7418
    /* 4EBB8 800B73B8 21100000 */   addu      $v0, $zero, $zero
  .L800B73BC:
    /* 4EBBC 800B73BC 0F80103C */  lui        $s0, %hi(_textBoxSelectionPending)
    /* 4EBC0 800B73C0 604C0292 */  lbu        $v0, %lo(_textBoxSelectionPending)($s0)
    /* 4EBC4 800B73C4 00000000 */  nop
    /* 4EBC8 800B73C8 0D004010 */  beqz       $v0, .L800B7400
    /* 4EBCC 800B73CC 00000000 */   nop
    /* 4EBD0 800B73D0 01008490 */  lbu        $a0, 0x1($a0)
    /* 4EBD4 800B73D4 231B030C */  jal        vs_battle_selectTextBox
    /* 4EBD8 800B73D8 00000000 */   nop
    /* 4EBDC 800B73DC 21284000 */  addu       $a1, $v0, $zero
    /* 4EBE0 800B73E0 00140200 */  sll        $v0, $v0, 16
    /* 4EBE4 800B73E4 0B004010 */  beqz       $v0, .L800B7414
    /* 4EBE8 800B73E8 10000424 */   addiu     $a0, $zero, 0x10
    /* 4EBEC 800B73EC 05FB020C */  jal        vs_battle_setStateFlag
    /* 4EBF0 800B73F0 FF00A530 */   andi      $a1, $a1, 0xFF
    /* 4EBF4 800B73F4 604C00A2 */  sb         $zero, %lo(_textBoxSelectionPending)($s0)
    /* 4EBF8 800B73F8 06DD0208 */  j          .L800B7418
    /* 4EBFC 800B73FC 21100000 */   addu      $v0, $zero, $zero
  .L800B7400:
    /* 4EC00 800B7400 01008490 */  lbu        $a0, 0x1($a0)
    /* 4EC04 800B7404 231B030C */  jal        vs_battle_selectTextBox
    /* 4EC08 800B7408 00000000 */   nop
    /* 4EC0C 800B740C 01000224 */  addiu      $v0, $zero, 0x1
    /* 4EC10 800B7410 604C02A2 */  sb         $v0, %lo(_textBoxSelectionPending)($s0)
  .L800B7414:
    /* 4EC14 800B7414 01000224 */  addiu      $v0, $zero, 0x1
  .L800B7418:
    /* 4EC18 800B7418 1400BF8F */  lw         $ra, 0x14($sp)
    /* 4EC1C 800B741C 1000B08F */  lw         $s0, 0x10($sp)
    /* 4EC20 800B7420 0800E003 */  jr         $ra
    /* 4EC24 800B7424 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel vs_battle_script_selectTextBox
