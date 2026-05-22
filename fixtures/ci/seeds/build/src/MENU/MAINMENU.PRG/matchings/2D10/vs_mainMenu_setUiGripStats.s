nonmatching vs_mainMenu_setUiGripStats, 0x9C

glabel vs_mainMenu_setUiGripStats
    /* 3D04 800FD504 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 3D08 800FD508 1000B0AF */  sw         $s0, 0x10($sp)
    /* 3D0C 800FD50C 21808000 */  addu       $s0, $a0, $zero
    /* 3D10 800FD510 21200000 */  addu       $a0, $zero, $zero
    /* 3D14 800FD514 1080023C */  lui        $v0, %hi(vs_mainMenu_equipmentStats)
    /* 3D18 800FD518 C0244724 */  addiu      $a3, $v0, %lo(vs_mainMenu_equipmentStats)
    /* 3D1C 800FD51C 40000524 */  addiu      $a1, $zero, 0x40
    /* 3D20 800FD520 1080033C */  lui        $v1, %hi(vs_mainMenu_grips)
    /* 3D24 800FD524 00111000 */  sll        $v0, $s0, 4
    /* 3D28 800FD528 6024638C */  lw         $v1, %lo(vs_mainMenu_grips)($v1)
    /* 3D2C 800FD52C F0FF4224 */  addiu      $v0, $v0, -0x10
    /* 3D30 800FD530 1400BFAF */  sw         $ra, 0x14($sp)
    /* 3D34 800FD534 21306200 */  addu       $a2, $v1, $v0
  .L800FD538:
    /* 3D38 800FD538 2118A700 */  addu       $v1, $a1, $a3
    /* 3D3C 800FD53C 2110C400 */  addu       $v0, $a2, $a0
    /* 3D40 800FD540 08004290 */  lbu        $v0, 0x8($v0)
    /* 3D44 800FD544 01008424 */  addiu      $a0, $a0, 0x1
    /* 3D48 800FD548 00160200 */  sll        $v0, $v0, 24
    /* 3D4C 800FD54C 03160200 */  sra        $v0, $v0, 24
    /* 3D50 800FD550 000062A4 */  sh         $v0, 0x0($v1)
    /* 3D54 800FD554 04008228 */  slti       $v0, $a0, 0x4
    /* 3D58 800FD558 F7FF4014 */  bnez       $v0, .L800FD538
    /* 3D5C 800FD55C 0200A524 */   addiu     $a1, $a1, 0x2
    /* 3D60 800FD560 0500C480 */  lb         $a0, 0x5($a2)
    /* 3D64 800FD564 0600C580 */  lb         $a1, 0x6($a2)
    /* 3D68 800FD568 0700C680 */  lb         $a2, 0x7($a2)
    /* 3D6C 800FD56C 4AEF030C */  jal        vs_mainMenu_setStrIntAgi
    /* 3D70 800FD570 01000724 */   addiu     $a3, $zero, 0x1
    /* 3D74 800FD574 04000424 */  addiu      $a0, $zero, 0x4
    /* 3D78 800FD578 1080023C */  lui        $v0, %hi(vs_mainMenu_equipmentSubtype)
    /* 3D7C 800FD57C 21188000 */  addu       $v1, $a0, $zero
    /* 3D80 800FD580 452543A0 */  sb         $v1, %lo(vs_mainMenu_equipmentSubtype)($v0)
    /* 3D84 800FD584 1080023C */  lui        $v0, %hi(D_801024A1)
    /* 3D88 800FD588 E3EE030C */  jal        func_800FBB8C
    /* 3D8C 800FD58C A12450A0 */   sb        $s0, %lo(D_801024A1)($v0)
    /* 3D90 800FD590 1400BF8F */  lw         $ra, 0x14($sp)
    /* 3D94 800FD594 1000B08F */  lw         $s0, 0x10($sp)
    /* 3D98 800FD598 0800E003 */  jr         $ra
    /* 3D9C 800FD59C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel vs_mainMenu_setUiGripStats
