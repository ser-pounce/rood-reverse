nonmatching func_801066DC, 0xA8

glabel func_801066DC
    /* 3EDC 801066DC E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 3EE0 801066E0 1800B2AF */  sw         $s2, 0x18($sp)
    /* 3EE4 801066E4 21908000 */  addu       $s2, $a0, $zero
    /* 3EE8 801066E8 1400B1AF */  sw         $s1, 0x14($sp)
    /* 3EEC 801066EC 2188A000 */  addu       $s1, $a1, $zero
    /* 3EF0 801066F0 1180023C */  lui        $v0, %hi(D_80109A88)
    /* 3EF4 801066F4 889A458C */  lw         $a1, %lo(D_80109A88)($v0)
    /* 3EF8 801066F8 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 3EFC 801066FC 1C0C040C */  jal        _countContainerItems
    /* 3F00 80106700 1000B0AF */   sw        $s0, 0x10($sp)
    /* 3F04 80106704 21204002 */  addu       $a0, $s2, $zero
    /* 3F08 80106708 1080033C */  lui        $v1, %hi(vs_menu_inventoryStorage)
    /* 3F0C 8010670C B0870534 */  ori        $a1, $zero, 0x87B0
    /* 3F10 80106710 5C24638C */  lw         $v1, %lo(vs_menu_inventoryStorage)($v1)
    /* 3F14 80106714 21804000 */  addu       $s0, $v0, $zero
    /* 3F18 80106718 1C0C040C */  jal        _countContainerItems
    /* 3F1C 8010671C 21286500 */   addu      $a1, $v1, $a1
    /* 3F20 80106720 21800202 */  addu       $s0, $s0, $v0
    /* 3F24 80106724 1180023C */  lui        $v0, %hi(D_80109A7A)
    /* 3F28 80106728 7A9A4290 */  lbu        $v0, %lo(D_80109A7A)($v0)
    /* 3F2C 8010672C 00000000 */  nop
    /* 3F30 80106730 07004014 */  bnez       $v0, .L80106750
    /* 3F34 80106734 21883002 */   addu      $s1, $s1, $s0
    /* 3F38 80106738 1080023C */  lui        $v0, %hi(vs_mainMenu_inventoryItemCapacities)
    /* 3F3C 8010673C A0224224 */  addiu      $v0, $v0, %lo(vs_mainMenu_inventoryItemCapacities)
    /* 3F40 80106740 21104202 */  addu       $v0, $s2, $v0
    /* 3F44 80106744 00004290 */  lbu        $v0, 0x0($v0)
    /* 3F48 80106748 DB190408 */  j          .L8010676C
    /* 3F4C 8010674C 2A105100 */   slt       $v0, $v0, $s1
  .L80106750:
    /* 3F50 80106750 1180023C */  lui        $v0, %hi(_containerItemCapacities)
    /* 3F54 80106754 44994224 */  addiu      $v0, $v0, %lo(_containerItemCapacities)
    /* 3F58 80106758 40181200 */  sll        $v1, $s2, 1
    /* 3F5C 8010675C 21186200 */  addu       $v1, $v1, $v0
    /* 3F60 80106760 00006294 */  lhu        $v0, 0x0($v1)
    /* 3F64 80106764 00000000 */  nop
    /* 3F68 80106768 2A105100 */  slt        $v0, $v0, $s1
  .L8010676C:
    /* 3F6C 8010676C 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 3F70 80106770 1800B28F */  lw         $s2, 0x18($sp)
    /* 3F74 80106774 1400B18F */  lw         $s1, 0x14($sp)
    /* 3F78 80106778 1000B08F */  lw         $s0, 0x10($sp)
    /* 3F7C 8010677C 0800E003 */  jr         $ra
    /* 3F80 80106780 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_801066DC
