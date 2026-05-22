nonmatching func_8007BCCC, 0x70

glabel func_8007BCCC
    /* 134CC 8007BCCC E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 134D0 8007BCD0 A0000424 */  addiu      $a0, $zero, 0xA0
    /* 134D4 8007BCD4 21280000 */  addu       $a1, $zero, $zero
    /* 134D8 8007BCD8 1000B0AF */  sw         $s0, 0x10($sp)
    /* 134DC 8007BCDC 0580103C */  lui        $s0, %hi(D_80050468)
    /* 134E0 8007BCE0 680400A2 */  sb         $zero, %lo(D_80050468)($s0)
    /* 134E4 8007BCE4 68041026 */  addiu      $s0, $s0, %lo(D_80050468)
    /* 134E8 8007BCE8 1400BFAF */  sw         $ra, 0x14($sp)
    /* 134EC 8007BCEC 070000A2 */  sb         $zero, 0x7($s0)
    /* 134F0 8007BCF0 060000A2 */  sb         $zero, 0x6($s0)
    /* 134F4 8007BCF4 050000A2 */  sb         $zero, 0x5($s0)
    /* 134F8 8007BCF8 05FB020C */  jal        vs_battle_setStateFlag
    /* 134FC 8007BCFC 040000A2 */   sb        $zero, 0x4($s0)
    /* 13500 8007BD00 05000592 */  lbu        $a1, 0x5($s0)
    /* 13504 8007BD04 05FB020C */  jal        vs_battle_setStateFlag
    /* 13508 8007BD08 A1000424 */   addiu     $a0, $zero, 0xA1
    /* 1350C 8007BD0C 06000592 */  lbu        $a1, 0x6($s0)
    /* 13510 8007BD10 05FB020C */  jal        vs_battle_setStateFlag
    /* 13514 8007BD14 A2000424 */   addiu     $a0, $zero, 0xA2
    /* 13518 8007BD18 07000592 */  lbu        $a1, 0x7($s0)
    /* 1351C 8007BD1C 05FB020C */  jal        vs_battle_setStateFlag
    /* 13520 8007BD20 A3000424 */   addiu     $a0, $zero, 0xA3
    /* 13524 8007BD24 582D030C */  jal        func_800CB560
    /* 13528 8007BD28 00000000 */   nop
    /* 1352C 8007BD2C 1400BF8F */  lw         $ra, 0x14($sp)
    /* 13530 8007BD30 1000B08F */  lw         $s0, 0x10($sp)
    /* 13534 8007BD34 0800E003 */  jr         $ra
    /* 13538 8007BD38 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8007BCCC
