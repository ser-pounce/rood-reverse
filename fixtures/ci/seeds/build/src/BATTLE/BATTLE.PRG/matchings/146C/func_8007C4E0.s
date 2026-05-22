nonmatching func_8007C4E0, 0xA0

glabel func_8007C4E0
    /* 13CE0 8007C4E0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 13CE4 8007C4E4 0F80073C */  lui        $a3, %hi(D_800F1AB0)
    /* 13CE8 8007C4E8 0F80033C */  lui        $v1, %hi(vs_battle_screenTransitionStep)
    /* 13CEC 8007C4EC 01000224 */  addiu      $v0, $zero, 0x1
    /* 13CF0 8007C4F0 481A62AC */  sw         $v0, %lo(vs_battle_screenTransitionStep)($v1)
    /* 13CF4 8007C4F4 0F80023C */  lui        $v0, %hi(vs_battle_screenTransitionEffect)
    /* 13CF8 8007C4F8 981A45AC */  sw         $a1, %lo(vs_battle_screenTransitionEffect)($v0)
    /* 13CFC 8007C4FC 0F80023C */  lui        $v0, %hi(_zoneContext)
    /* 13D00 8007C500 80184390 */  lbu        $v1, %lo(_zoneContext)($v0)
    /* 13D04 8007C504 0F80023C */  lui        $v0, %hi(vs_battle_screenTransitionSpeed)
    /* 13D08 8007C508 1000BFAF */  sw         $ra, 0x10($sp)
    /* 13D0C 8007C50C B01AEB24 */  addiu      $t3, $a3, %lo(D_800F1AB0)
    /* 13D10 8007C510 03008888 */  lwl        $t0, 0x3($a0)
    /* 13D14 8007C514 00008898 */  lwr        $t0, 0x0($a0)
    /* 13D18 8007C518 07008988 */  lwl        $t1, 0x7($a0)
    /* 13D1C 8007C51C 04008998 */  lwr        $t1, 0x4($a0)
    /* 13D20 8007C520 0B008A88 */  lwl        $t2, 0xB($a0)
    /* 13D24 8007C524 08008A98 */  lwr        $t2, 0x8($a0)
    /* 13D28 8007C528 030068A9 */  swl        $t0, 0x3($t3)
    /* 13D2C 8007C52C 000068B9 */  swr        $t0, 0x0($t3)
    /* 13D30 8007C530 070069A9 */  swl        $t1, 0x7($t3)
    /* 13D34 8007C534 040069B9 */  swr        $t1, 0x4($t3)
    /* 13D38 8007C538 0B006AA9 */  swl        $t2, 0xB($t3)
    /* 13D3C 8007C53C 08006AB9 */  swr        $t2, 0x8($t3)
    /* 13D40 8007C540 A81A46AC */  sw         $a2, %lo(vs_battle_screenTransitionSpeed)($v0)
    /* 13D44 8007C544 B01AE3A0 */  sb         $v1, %lo(D_800F1AB0)($a3)
    /* 13D48 8007C548 01008490 */  lbu        $a0, 0x1($a0)
    /* 13D4C 8007C54C 4927020C */  jal        _loadMpd
    /* 13D50 8007C550 00000000 */   nop
    /* 13D54 8007C554 7179020C */  jal        func_8009E5C4
    /* 13D58 8007C558 21200000 */   addu      $a0, $zero, $zero
    /* 13D5C 8007C55C 21200000 */  addu       $a0, $zero, $zero
    /* 13D60 8007C560 8782020C */  jal        func_800A0A1C
    /* 13D64 8007C564 01000524 */   addiu     $a1, $zero, 0x1
    /* 13D68 8007C568 3E2E020C */  jal        func_8008B8F8
    /* 13D6C 8007C56C 21200000 */   addu      $a0, $zero, $zero
    /* 13D70 8007C570 1000BF8F */  lw         $ra, 0x10($sp)
    /* 13D74 8007C574 01000224 */  addiu      $v0, $zero, 0x1
    /* 13D78 8007C578 0800E003 */  jr         $ra
    /* 13D7C 8007C57C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8007C4E0
