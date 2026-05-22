nonmatching _setMenuTitle, 0x74

glabel _setMenuTitle
    /* 9FC 801031FC E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* A00 80103200 01000424 */  addiu      $a0, $zero, 0x1
    /* A04 80103204 0F80053C */  lui        $a1, %hi(vs_battle_menuStrings)
    /* A08 80103208 DCB9A524 */  addiu      $a1, $a1, %lo(vs_battle_menuStrings)
    /* A0C 8010320C 08000324 */  addiu      $v1, $zero, 0x8
    /* A10 80103210 12000624 */  addiu      $a2, $zero, 0x12
    /* A14 80103214 1800BFAF */  sw         $ra, 0x18($sp)
    /* A18 80103218 0200A294 */  lhu        $v0, 0x2($a1)
    /* A1C 8010321C 8C000724 */  addiu      $a3, $zero, 0x8C
    /* A20 80103220 1000A3AF */  sw         $v1, 0x10($sp)
    /* A24 80103224 04108200 */  sllv       $v0, $v0, $a0
    /* A28 80103228 21104500 */  addu       $v0, $v0, $a1
    /* A2C 8010322C 40010524 */  addiu      $a1, $zero, 0x140
    /* A30 80103230 9723030C */  jal        vs_battle_setMenuItem
    /* A34 80103234 1400A2AF */   sw        $v0, 0x14($sp)
    /* A38 80103238 02000424 */  addiu      $a0, $zero, 0x2
    /* A3C 8010323C 21188000 */  addu       $v1, $a0, $zero
    /* A40 80103240 000043A0 */  sb         $v1, 0x0($v0)
    /* A44 80103244 B4000324 */  addiu      $v1, $zero, 0xB4
    /* A48 80103248 180043A4 */  sh         $v1, 0x18($v0)
    /* A4C 8010324C 01000324 */  addiu      $v1, $zero, 0x1
    /* A50 80103250 A2FE030C */  jal        func_800FFA88
    /* A54 80103254 060043A0 */   sb        $v1, 0x6($v0)
    /* A58 80103258 F2FE030C */  jal        func_800FFBC8
    /* A5C 8010325C 00000000 */   nop
    /* A60 80103260 1800BF8F */  lw         $ra, 0x18($sp)
    /* A64 80103264 00000000 */  nop
    /* A68 80103268 0800E003 */  jr         $ra
    /* A6C 8010326C 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel _setMenuTitle
