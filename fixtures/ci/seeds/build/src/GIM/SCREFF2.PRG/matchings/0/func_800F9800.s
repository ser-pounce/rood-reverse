nonmatching func_800F9800, 0x6C

glabel func_800F9800
    /* 0 800F9800 0F80023C */  lui        $v0, %hi(D_800EB9B4)
    /* 4 800F9804 B4B9438C */  lw         $v1, %lo(D_800EB9B4)($v0)
    /* 8 800F9808 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* C 800F980C 1000BFAF */  sw         $ra, 0x10($sp)
    /* 10 800F9810 01006290 */  lbu        $v0, 0x1($v1)
    /* 14 800F9814 00000000 */  nop
    /* 18 800F9818 0A004014 */  bnez       $v0, .L800F9844
    /* 1C 800F981C 020064A4 */   sh        $a0, 0x2($v1)
    /* 20 800F9820 0E008010 */  beqz       $a0, .L800F985C
    /* 24 800F9824 01000224 */   addiu     $v0, $zero, 0x1
    /* 28 800F9828 010062A0 */  sb         $v0, 0x1($v1)
    /* 2C 800F982C 1B000424 */  addiu      $a0, $zero, 0x1B
    /* 30 800F9830 05000524 */  addiu      $a1, $zero, 0x5
    /* 34 800F9834 FCF7010C */  jal        func_8007DFF0
    /* 38 800F9838 06000624 */   addiu     $a2, $zero, 0x6
    /* 3C 800F983C 17E60308 */  j          .L800F985C
    /* 40 800F9840 00000000 */   nop
  .L800F9844:
    /* 44 800F9844 05008014 */  bnez       $a0, .L800F985C
    /* 48 800F9848 1B000424 */   addiu     $a0, $zero, 0x1B
    /* 4C 800F984C 010060A0 */  sb         $zero, 0x1($v1)
    /* 50 800F9850 05000524 */  addiu      $a1, $zero, 0x5
    /* 54 800F9854 2AF8010C */  jal        func_8007E0A8
    /* 58 800F9858 06000624 */   addiu     $a2, $zero, 0x6
  .L800F985C:
    /* 5C 800F985C 1000BF8F */  lw         $ra, 0x10($sp)
    /* 60 800F9860 00000000 */  nop
    /* 64 800F9864 0800E003 */  jr         $ra
    /* 68 800F9868 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800F9800
