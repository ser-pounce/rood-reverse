nonmatching func_8007C5C0, 0x94

glabel func_8007C5C0
    /* 13DC0 8007C5C0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 13DC4 8007C5C4 0F80023C */  lui        $v0, %hi(D_800F1AB0)
    /* 13DC8 8007C5C8 0F80033C */  lui        $v1, %hi(vs_battle_screenTransitionStep)
    /* 13DCC 8007C5CC 1000BFAF */  sw         $ra, 0x10($sp)
    /* 13DD0 8007C5D0 B01A4A24 */  addiu      $t2, $v0, %lo(D_800F1AB0)
    /* 13DD4 8007C5D4 03008788 */  lwl        $a3, 0x3($a0)
    /* 13DD8 8007C5D8 00008798 */  lwr        $a3, 0x0($a0)
    /* 13DDC 8007C5DC 07008888 */  lwl        $t0, 0x7($a0)
    /* 13DE0 8007C5E0 04008898 */  lwr        $t0, 0x4($a0)
    /* 13DE4 8007C5E4 0B008988 */  lwl        $t1, 0xB($a0)
    /* 13DE8 8007C5E8 08008998 */  lwr        $t1, 0x8($a0)
    /* 13DEC 8007C5EC 030047A9 */  swl        $a3, 0x3($t2)
    /* 13DF0 8007C5F0 000047B9 */  swr        $a3, 0x0($t2)
    /* 13DF4 8007C5F4 070048A9 */  swl        $t0, 0x7($t2)
    /* 13DF8 8007C5F8 040048B9 */  swr        $t0, 0x4($t2)
    /* 13DFC 8007C5FC 0B0049A9 */  swl        $t1, 0xB($t2)
    /* 13E00 8007C600 080049B9 */  swr        $t1, 0x8($t2)
    /* 13E04 8007C604 02000224 */  addiu      $v0, $zero, 0x2
    /* 13E08 8007C608 481A62AC */  sw         $v0, %lo(vs_battle_screenTransitionStep)($v1)
    /* 13E0C 8007C60C 0F80023C */  lui        $v0, %hi(vs_battle_screenTransitionEffect)
    /* 13E10 8007C610 981A45AC */  sw         $a1, %lo(vs_battle_screenTransitionEffect)($v0)
    /* 13E14 8007C614 0F80023C */  lui        $v0, %hi(vs_battle_screenTransitionSpeed)
    /* 13E18 8007C618 A81A46AC */  sw         $a2, %lo(vs_battle_screenTransitionSpeed)($v0)
    /* 13E1C 8007C61C 00008490 */  lbu        $a0, 0x0($a0)
    /* 13E20 8007C620 8223020C */  jal        _loadZnd
    /* 13E24 8007C624 00000000 */   nop
    /* 13E28 8007C628 7179020C */  jal        func_8009E5C4
    /* 13E2C 8007C62C 21200000 */   addu      $a0, $zero, $zero
    /* 13E30 8007C630 21200000 */  addu       $a0, $zero, $zero
    /* 13E34 8007C634 8782020C */  jal        func_800A0A1C
    /* 13E38 8007C638 01000524 */   addiu     $a1, $zero, 0x1
    /* 13E3C 8007C63C 3E2E020C */  jal        func_8008B8F8
    /* 13E40 8007C640 21200000 */   addu      $a0, $zero, $zero
    /* 13E44 8007C644 1000BF8F */  lw         $ra, 0x10($sp)
    /* 13E48 8007C648 01000224 */  addiu      $v0, $zero, 0x1
    /* 13E4C 8007C64C 0800E003 */  jr         $ra
    /* 13E50 8007C650 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8007C5C0
