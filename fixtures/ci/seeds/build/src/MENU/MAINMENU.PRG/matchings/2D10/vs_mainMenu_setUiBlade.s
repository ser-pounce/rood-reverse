nonmatching vs_mainMenu_setUiBlade, 0x168

glabel vs_mainMenu_setUiBlade
    /* 32A4 800FCAA4 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 32A8 800FCAA8 1000B0AF */  sw         $s0, 0x10($sp)
    /* 32AC 800FCAAC 21808000 */  addu       $s0, $a0, $zero
    /* 32B0 800FCAB0 2400B5AF */  sw         $s5, 0x24($sp)
    /* 32B4 800FCAB4 21A8C000 */  addu       $s5, $a2, $zero
    /* 32B8 800FCAB8 0F80043C */  lui        $a0, %hi(vs_battle_stringContext)
    /* 32BC 800FCABC 68518424 */  addiu      $a0, $a0, %lo(vs_battle_stringContext)
    /* 32C0 800FCAC0 1800B2AF */  sw         $s2, 0x18($sp)
    /* 32C4 800FCAC4 1080123C */  lui        $s2, %hi(vs_mainMenu_itemNames)
    /* 32C8 800FCAC8 2800BFAF */  sw         $ra, 0x28($sp)
    /* 32CC 800FCACC 2000B4AF */  sw         $s4, 0x20($sp)
    /* 32D0 800FCAD0 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 32D4 800FCAD4 1400B1AF */  sw         $s1, 0x14($sp)
    /* 32D8 800FCAD8 28000396 */  lhu        $v1, 0x28($s0)
    /* 32DC 800FCADC 1080113C */  lui        $s1, %hi(vs_mainMenu_itemHelp)
    /* 32E0 800FCAE0 40100300 */  sll        $v0, $v1, 1
    /* 32E4 800FCAE4 21104300 */  addu       $v0, $v0, $v1
    /* 32E8 800FCAE8 C0100200 */  sll        $v0, $v0, 3
    /* 32EC 800FCAEC 9C22438E */  lw         $v1, %lo(vs_mainMenu_itemNames)($s2)
    /* 32F0 800FCAF0 B8174224 */  addiu      $v0, $v0, 0x17B8
    /* 32F4 800FCAF4 21186200 */  addu       $v1, $v1, $v0
    /* 32F8 800FCAF8 4C0083AC */  sw         $v1, 0x4C($a0)
    /* 32FC 800FCAFC 03000292 */  lbu        $v0, 0x3($s0)
    /* 3300 800FCB00 4025268E */  lw         $a2, %lo(vs_mainMenu_itemHelp)($s1)
    /* 3304 800FCB04 40100200 */  sll        $v0, $v0, 1
    /* 3308 800FCB08 21104600 */  addu       $v0, $v0, $a2
    /* 330C 800FCB0C 1C034294 */  lhu        $v0, 0x31C($v0)
    /* 3310 800FCB10 00000000 */  nop
    /* 3314 800FCB14 40100200 */  sll        $v0, $v0, 1
    /* 3318 800FCB18 2110C200 */  addu       $v0, $a2, $v0
    /* 331C 800FCB1C 480082AC */  sw         $v0, 0x48($a0)
    /* 3320 800FCB20 10000292 */  lbu        $v0, 0x10($s0)
    /* 3324 800FCB24 00000000 */  nop
    /* 3328 800FCB28 03004230 */  andi       $v0, $v0, 0x3
    /* 332C 800FCB2C 40100200 */  sll        $v0, $v0, 1
    /* 3330 800FCB30 21104600 */  addu       $v0, $v0, $a2
    /* 3334 800FCB34 30034294 */  lhu        $v0, 0x330($v0)
    /* 3338 800FCB38 00000000 */  nop
    /* 333C 800FCB3C 40100200 */  sll        $v0, $v0, 1
    /* 3340 800FCB40 2110C200 */  addu       $v0, $a2, $v0
    /* 3344 800FCB44 440082AC */  sw         $v0, 0x44($a0)
    /* 3348 800FCB48 1080023C */  lui        $v0, %hi(vs_mainMenu_weaponHands)
    /* 334C 800FCB4C 03000392 */  lbu        $v1, 0x3($s0)
    /* 3350 800FCB50 40214224 */  addiu      $v0, $v0, %lo(vs_mainMenu_weaponHands)
    /* 3354 800FCB54 21186200 */  addu       $v1, $v1, $v0
    /* 3358 800FCB58 FFFF6290 */  lbu        $v0, -0x1($v1)
    /* 335C 800FCB5C 00000000 */  nop
    /* 3360 800FCB60 40100200 */  sll        $v0, $v0, 1
    /* 3364 800FCB64 21104600 */  addu       $v0, $v0, $a2
    /* 3368 800FCB68 38034294 */  lhu        $v0, 0x338($v0)
    /* 336C 800FCB6C 21A0A000 */  addu       $s4, $a1, $zero
    /* 3370 800FCB70 40100200 */  sll        $v0, $v0, 1
    /* 3374 800FCB74 2110C200 */  addu       $v0, $a2, $v0
    /* 3378 800FCB78 400082AC */  sw         $v0, 0x40($a0)
    /* 337C 800FCB7C 00000292 */  lbu        $v0, 0x0($s0)
    /* 3380 800FCB80 2198E000 */  addu       $s3, $a3, $zero
    /* 3384 800FCB84 40100200 */  sll        $v0, $v0, 1
    /* 3388 800FCB88 21104600 */  addu       $v0, $v0, $a2
    /* 338C 800FCB8C FEFF4594 */  lhu        $a1, -0x2($v0)
    /* 3390 800FCB90 21206002 */  addu       $a0, $s3, $zero
    /* 3394 800FCB94 40280500 */  sll        $a1, $a1, 1
    /* 3398 800FCB98 171A030C */  jal        vs_battle_printf
    /* 339C 800FCB9C 2128C500 */   addu      $a1, $a2, $a1
    /* 33A0 800FCBA0 4025258E */  lw         $a1, %lo(vs_mainMenu_itemHelp)($s1)
    /* 33A4 800FCBA4 21204000 */  addu       $a0, $v0, $zero
    /* 33A8 800FCBA8 171A030C */  jal        vs_battle_printf
    /* 33AC 800FCBAC F667A524 */   addiu     $a1, $a1, 0x67F6
    /* 33B0 800FCBB0 00000392 */  lbu        $v1, 0x0($s0)
    /* 33B4 800FCBB4 040093AE */  sw         $s3, 0x4($s4)
    /* 33B8 800FCBB8 40100300 */  sll        $v0, $v1, 1
    /* 33BC 800FCBBC 21104300 */  addu       $v0, $v0, $v1
    /* 33C0 800FCBC0 9C22438E */  lw         $v1, %lo(vs_mainMenu_itemNames)($s2)
    /* 33C4 800FCBC4 C0100200 */  sll        $v0, $v0, 3
    /* 33C8 800FCBC8 21186200 */  addu       $v1, $v1, $v0
    /* 33CC 800FCBCC 000083AE */  sw         $v1, 0x0($s4)
    /* 33D0 800FCBD0 03000392 */  lbu        $v1, 0x3($s0)
    /* 33D4 800FCBD4 28000296 */  lhu        $v0, 0x28($s0)
    /* 33D8 800FCBD8 801E0300 */  sll        $v1, $v1, 26
    /* 33DC 800FCBDC 00140200 */  sll        $v0, $v0, 16
    /* 33E0 800FCBE0 21186200 */  addu       $v1, $v1, $v0
    /* 33E4 800FCBE4 0000A3AE */  sw         $v1, 0x0($s5)
    /* 33E8 800FCBE8 2800BF8F */  lw         $ra, 0x28($sp)
    /* 33EC 800FCBEC 2400B58F */  lw         $s5, 0x24($sp)
    /* 33F0 800FCBF0 2000B48F */  lw         $s4, 0x20($sp)
    /* 33F4 800FCBF4 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 33F8 800FCBF8 1800B28F */  lw         $s2, 0x18($sp)
    /* 33FC 800FCBFC 1400B18F */  lw         $s1, 0x14($sp)
    /* 3400 800FCC00 1000B08F */  lw         $s0, 0x10($sp)
    /* 3404 800FCC04 0800E003 */  jr         $ra
    /* 3408 800FCC08 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel vs_mainMenu_setUiBlade
