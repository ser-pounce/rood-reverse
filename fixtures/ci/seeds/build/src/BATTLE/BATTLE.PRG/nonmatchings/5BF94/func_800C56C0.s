nonmatching func_800C56C0, 0xD8

glabel func_800C56C0
    /* 5CEC0 800C56C0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 5CEC4 800C56C4 1000BFAF */  sw         $ra, 0x10($sp)
    /* 5CEC8 800C56C8 6D14030C */  jal        func_800C51B4
    /* 5CECC 800C56CC 01000424 */   addiu     $a0, $zero, 0x1
    /* 5CED0 800C56D0 0F80053C */  lui        $a1, %hi(D_800F4CB1)
    /* 5CED4 800C56D4 B14CA290 */  lbu        $v0, %lo(D_800F4CB1)($a1)
    /* 5CED8 800C56D8 00000000 */  nop
    /* 5CEDC 800C56DC 13004010 */  beqz       $v0, .L800C572C
    /* 5CEE0 800C56E0 21200000 */   addu      $a0, $zero, $zero
    /* 5CEE4 800C56E4 0F80083C */  lui        $t0, %hi(D_800EB9B8)
    /* 5CEE8 800C56E8 0F80023C */  lui        $v0, %hi(D_800F4C70)
    /* 5CEEC 800C56EC 704C4724 */  addiu      $a3, $v0, %lo(D_800F4C70)
    /* 5CEF0 800C56F0 03000624 */  addiu      $a2, $zero, 0x3
    /* 5CEF4 800C56F4 21108700 */  addu       $v0, $a0, $a3
  .L800C56F8:
    /* 5CEF8 800C56F8 00004390 */  lbu        $v1, 0x0($v0)
    /* 5CEFC 800C56FC 00000000 */  nop
    /* 5CF00 800C5700 80100300 */  sll        $v0, $v1, 2
    /* 5CF04 800C5704 21104300 */  addu       $v0, $v0, $v1
    /* 5CF08 800C5708 B8B9038D */  lw         $v1, %lo(D_800EB9B8)($t0)
    /* 5CF0C 800C570C 80100200 */  sll        $v0, $v0, 2
    /* 5CF10 800C5710 21186200 */  addu       $v1, $v1, $v0
    /* 5CF14 800C5714 900966A0 */  sb         $a2, 0x990($v1)
    /* 5CF18 800C5718 B14CA290 */  lbu        $v0, %lo(D_800F4CB1)($a1)
    /* 5CF1C 800C571C 01008424 */  addiu      $a0, $a0, 0x1
    /* 5CF20 800C5720 2A108200 */  slt        $v0, $a0, $v0
    /* 5CF24 800C5724 F4FF4014 */  bnez       $v0, .L800C56F8
    /* 5CF28 800C5728 21108700 */   addu      $v0, $a0, $a3
  .L800C572C:
    /* 5CF2C 800C572C 0F80053C */  lui        $a1, %hi(D_800F4CB0)
    /* 5CF30 800C5730 B04CA290 */  lbu        $v0, %lo(D_800F4CB0)($a1)
    /* 5CF34 800C5734 00000000 */  nop
    /* 5CF38 800C5738 13004010 */  beqz       $v0, .L800C5788
    /* 5CF3C 800C573C 21200000 */   addu      $a0, $zero, $zero
    /* 5CF40 800C5740 0F80083C */  lui        $t0, %hi(D_800EB9B8)
    /* 5CF44 800C5744 0F80023C */  lui        $v0, %hi(D_800F4C70)
    /* 5CF48 800C5748 704C4724 */  addiu      $a3, $v0, %lo(D_800F4C70)
    /* 5CF4C 800C574C 02000624 */  addiu      $a2, $zero, 0x2
    /* 5CF50 800C5750 21108700 */  addu       $v0, $a0, $a3
  .L800C5754:
    /* 5CF54 800C5754 10004390 */  lbu        $v1, 0x10($v0)
    /* 5CF58 800C5758 00000000 */  nop
    /* 5CF5C 800C575C 80100300 */  sll        $v0, $v1, 2
    /* 5CF60 800C5760 21104300 */  addu       $v0, $v0, $v1
    /* 5CF64 800C5764 B8B9038D */  lw         $v1, %lo(D_800EB9B8)($t0)
    /* 5CF68 800C5768 80100200 */  sll        $v0, $v0, 2
    /* 5CF6C 800C576C 21186200 */  addu       $v1, $v1, $v0
    /* 5CF70 800C5770 900966A0 */  sb         $a2, 0x990($v1)
    /* 5CF74 800C5774 B04CA290 */  lbu        $v0, %lo(D_800F4CB0)($a1)
    /* 5CF78 800C5778 01008424 */  addiu      $a0, $a0, 0x1
    /* 5CF7C 800C577C 2A108200 */  slt        $v0, $a0, $v0
    /* 5CF80 800C5780 F4FF4014 */  bnez       $v0, .L800C5754
    /* 5CF84 800C5784 21108700 */   addu      $v0, $a0, $a3
  .L800C5788:
    /* 5CF88 800C5788 1000BF8F */  lw         $ra, 0x10($sp)
    /* 5CF8C 800C578C 00000000 */  nop
    /* 5CF90 800C5790 0800E003 */  jr         $ra
    /* 5CF94 800C5794 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800C56C0
