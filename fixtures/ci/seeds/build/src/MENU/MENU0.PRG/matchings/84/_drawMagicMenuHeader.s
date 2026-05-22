nonmatching _drawMagicMenuHeader, 0x74

glabel _drawMagicMenuHeader
    /* 1A54 80104254 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 1A58 80104258 21200000 */  addu       $a0, $zero, $zero
    /* 1A5C 8010425C 08000224 */  addiu      $v0, $zero, 0x8
    /* 1A60 80104260 0F80033C */  lui        $v1, %hi(vs_battle_menuStrings)
    /* 1A64 80104264 1000A2AF */  sw         $v0, 0x10($sp)
    /* 1A68 80104268 DCB96294 */  lhu        $v0, %lo(vs_battle_menuStrings)($v1)
    /* 1A6C 8010426C DCB96324 */  addiu      $v1, $v1, %lo(vs_battle_menuStrings)
    /* 1A70 80104270 40010524 */  addiu      $a1, $zero, 0x140
    /* 1A74 80104274 12000624 */  addiu      $a2, $zero, 0x12
    /* 1A78 80104278 8C000724 */  addiu      $a3, $zero, 0x8C
    /* 1A7C 8010427C 1800BFAF */  sw         $ra, 0x18($sp)
    /* 1A80 80104280 40100200 */  sll        $v0, $v0, 1
    /* 1A84 80104284 21104300 */  addu       $v0, $v0, $v1
    /* 1A88 80104288 9723030C */  jal        vs_battle_setMenuItem
    /* 1A8C 8010428C 1400A2AF */   sw        $v0, 0x14($sp)
    /* 1A90 80104290 02000424 */  addiu      $a0, $zero, 0x2
    /* 1A94 80104294 21188000 */  addu       $v1, $a0, $zero
    /* 1A98 80104298 000043A0 */  sb         $v1, 0x0($v0)
    /* 1A9C 8010429C B4000324 */  addiu      $v1, $zero, 0xB4
    /* 1AA0 801042A0 180043A4 */  sh         $v1, 0x18($v0)
    /* 1AA4 801042A4 01000324 */  addiu      $v1, $zero, 0x1
    /* 1AA8 801042A8 A2FE030C */  jal        func_800FFA88
    /* 1AAC 801042AC 060043A0 */   sb        $v1, 0x6($v0)
    /* 1AB0 801042B0 F2FE030C */  jal        func_800FFBC8
    /* 1AB4 801042B4 00000000 */   nop
    /* 1AB8 801042B8 1800BF8F */  lw         $ra, 0x18($sp)
    /* 1ABC 801042BC 00000000 */  nop
    /* 1AC0 801042C0 0800E003 */  jr         $ra
    /* 1AC4 801042C4 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel _drawMagicMenuHeader
