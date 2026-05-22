nonmatching func_800C4734, 0x60

glabel func_800C4734
    /* 5BF34 800C4734 0F80023C */  lui        $v0, %hi(D_800EB9B8)
    /* 5BF38 800C4738 B8B9438C */  lw         $v1, %lo(D_800EB9B8)($v0)
    /* 5BF3C 800C473C 00000000 */  nop
    /* 5BF40 800C4740 05006010 */  beqz       $v1, .L800C4758
    /* 5BF44 800C4744 00000000 */   nop
    /* 5BF48 800C4748 2A006284 */  lh         $v0, 0x2A($v1)
    /* 5BF4C 800C474C 00000000 */  nop
    /* 5BF50 800C4750 03004010 */  beqz       $v0, .L800C4760
    /* 5BF54 800C4754 00000000 */   nop
  .L800C4758:
    /* 5BF58 800C4758 0800E003 */  jr         $ra
    /* 5BF5C 800C475C 21100000 */   addu      $v0, $zero, $zero
  .L800C4760:
    /* 5BF60 800C4760 3E006284 */  lh         $v0, 0x3E($v1)
    /* 5BF64 800C4764 00000000 */  nop
    /* 5BF68 800C4768 06004010 */  beqz       $v0, .L800C4784
    /* 5BF6C 800C476C 0680023C */   lui       $v0, %hi(vs_main_buttonsState)
    /* 5BF70 800C4770 38E2428C */  lw         $v0, %lo(vs_main_buttonsState)($v0)
    /* 5BF74 800C4774 00000000 */  nop
    /* 5BF78 800C4778 80004230 */  andi       $v0, $v0, 0x80
    /* 5BF7C 800C477C 03004010 */  beqz       $v0, .L800C478C
    /* 5BF80 800C4780 00000000 */   nop
  .L800C4784:
    /* 5BF84 800C4784 0800E003 */  jr         $ra
    /* 5BF88 800C4788 01000224 */   addiu     $v0, $zero, 0x1
  .L800C478C:
    /* 5BF8C 800C478C 0800E003 */  jr         $ra
    /* 5BF90 800C4790 02000224 */   addiu     $v0, $zero, 0x2
endlabel func_800C4734
