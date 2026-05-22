nonmatching _initMenuLayout, 0x50

glabel _initMenuLayout
    /* 51C 80102D1C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 520 80102D20 1000B0AF */  sw         $s0, 0x10($sp)
    /* 524 80102D24 2180A000 */  addu       $s0, $a1, $zero
    /* 528 80102D28 1180033C */  lui        $v1, %hi(D_8010A50C)
    /* 52C 80102D2C 01000224 */  addiu      $v0, $zero, 0x1
    /* 530 80102D30 0CA562AC */  sw         $v0, %lo(D_8010A50C)($v1)
    /* 534 80102D34 1180023C */  lui        $v0, %hi(D_8010A6BA)
    /* 538 80102D38 BAA640A0 */  sb         $zero, %lo(D_8010A6BA)($v0)
    /* 53C 80102D3C 1180023C */  lui        $v0, %hi(D_8010A6BB)
    /* 540 80102D40 1400BFAF */  sw         $ra, 0x14($sp)
    /* 544 80102D44 2F0B040C */  jal        _transitionToSubMenu
    /* 548 80102D48 BBA640A0 */   sb        $zero, %lo(D_8010A6BB)($v0)
    /* 54C 80102D4C F5EE030C */  jal        vs_mainMenu_drawClassAffinityType
    /* 550 80102D50 21200002 */   addu      $a0, $s0, $zero
    /* 554 80102D54 A9EF030C */  jal        vs_mainMenu_renderEquipStats
    /* 558 80102D58 01000424 */   addiu     $a0, $zero, 0x1
    /* 55C 80102D5C 1400BF8F */  lw         $ra, 0x14($sp)
    /* 560 80102D60 1000B08F */  lw         $s0, 0x10($sp)
    /* 564 80102D64 0800E003 */  jr         $ra
    /* 568 80102D68 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel _initMenuLayout
