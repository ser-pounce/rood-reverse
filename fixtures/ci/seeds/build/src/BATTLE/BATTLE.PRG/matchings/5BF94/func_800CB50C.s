nonmatching func_800CB50C, 0x44

glabel func_800CB50C
    /* 62D0C 800CB50C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 62D10 800CB510 1000B0AF */  sw         $s0, 0x10($sp)
    /* 62D14 800CB514 0F80103C */  lui        $s0, %hi(D_800EB9D8)
    /* 62D18 800CB518 D8B9028E */  lw         $v0, %lo(D_800EB9D8)($s0)
    /* 62D1C 800CB51C 00000000 */  nop
    /* 62D20 800CB520 07004010 */  beqz       $v0, .L800CB540
    /* 62D24 800CB524 1400BFAF */   sw        $ra, 0x14($sp)
    /* 62D28 800CB528 1934030C */  jal        vs_battle_dismissTextBox
    /* 62D2C 800CB52C 07000424 */   addiu     $a0, $zero, 0x7
    /* 62D30 800CB530 D8B9048E */  lw         $a0, %lo(D_800EB9D8)($s0)
    /* 62D34 800CB534 180F010C */  jal        vs_main_freeHeapR
    /* 62D38 800CB538 00000000 */   nop
    /* 62D3C 800CB53C D8B900AE */  sw         $zero, %lo(D_800EB9D8)($s0)
  .L800CB540:
    /* 62D40 800CB540 1400BF8F */  lw         $ra, 0x14($sp)
    /* 62D44 800CB544 1000B08F */  lw         $s0, 0x10($sp)
    /* 62D48 800CB548 0800E003 */  jr         $ra
    /* 62D4C 800CB54C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800CB50C
