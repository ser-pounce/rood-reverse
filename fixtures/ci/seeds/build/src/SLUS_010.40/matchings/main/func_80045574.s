nonmatching func_80045574, 0x38

glabel func_80045574
    /* 35D74 80045574 0680023C */  lui        $v0, %hi(vs_main_soundData)
    /* 35D78 80045578 38E0428C */  lw         $v0, %lo(vs_main_soundData)($v0)
    /* 35D7C 8004557C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 35D80 80045580 03004410 */  beq        $v0, $a0, .L80045590
    /* 35D84 80045584 1000BFAF */   sw        $ra, 0x10($sp)
    /* 35D88 80045588 67150108 */  j          .L8004559C
    /* 35D8C 8004558C 21100000 */   addu      $v0, $zero, $zero
  .L80045590:
    /* 35D90 80045590 744A000C */  jal        func_800129D0
    /* 35D94 80045594 2120C000 */   addu      $a0, $a2, $zero
    /* 35D98 80045598 01000224 */  addiu      $v0, $zero, 0x1
  .L8004559C:
    /* 35D9C 8004559C 1000BF8F */  lw         $ra, 0x10($sp)
    /* 35DA0 800455A0 00000000 */  nop
    /* 35DA4 800455A4 0800E003 */  jr         $ra
    /* 35DA8 800455A8 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80045574
