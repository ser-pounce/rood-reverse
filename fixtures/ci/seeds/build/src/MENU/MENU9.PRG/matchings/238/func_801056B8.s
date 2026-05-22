nonmatching func_801056B8, 0xE4

glabel func_801056B8
    /* 2EB8 801056B8 21280000 */  addu       $a1, $zero, $zero
    /* 2EBC 801056BC 1180023C */  lui        $v0, %hi(_gazetteRows)
    /* 2EC0 801056C0 30A24624 */  addiu      $a2, $v0, %lo(_gazetteRows)
    /* 2EC4 801056C4 3C000F24 */  addiu      $t7, $zero, 0x3C
    /* 2EC8 801056C8 06800E3C */  lui        $t6, %hi(vs_main_scoredata)
    /* 2ECC 801056CC 01000A24 */  addiu      $t2, $zero, 0x1
    /* 2ED0 801056D0 11800D3C */  lui        $t5, %hi(_miscInfo)
    /* 2ED4 801056D4 DC97A925 */  addiu      $t1, $t5, %lo(_miscInfo)
    /* 2ED8 801056D8 0C00C424 */  addiu      $a0, $a2, 0xC
    /* 2EDC 801056DC 1180023C */  lui        $v0, %hi(_titleDescriptions)
    /* 2EE0 801056E0 BC894C24 */  addiu      $t4, $v0, %lo(_titleDescriptions)
    /* 2EE4 801056E4 21408001 */  addu       $t0, $t4, $zero
    /* 2EE8 801056E8 1180023C */  lui        $v0, %hi(_titleText)
    /* 2EEC 801056EC E4864B24 */  addiu      $t3, $v0, %lo(_titleText)
    /* 2EF0 801056F0 21386001 */  addu       $a3, $t3, $zero
  .L801056F4:
    /* 2EF4 801056F4 0100A224 */  addiu      $v0, $a1, 0x1
    /* 2EF8 801056F8 F8FF8FA4 */  sh         $t7, -0x8($a0)
    /* 2EFC 801056FC FAFF82A4 */  sh         $v0, -0x6($a0)
    /* 2F00 80105700 0000C0A0 */  sb         $zero, 0x0($a2)
    /* 2F04 80105704 F6FF80A0 */  sb         $zero, -0xA($a0)
    /* 2F08 80105708 F7FF80A0 */  sb         $zero, -0x9($a0)
    /* 2F0C 8010570C A0FEC28D */  lw         $v0, %lo(vs_main_scoredata)($t6)
    /* 2F10 80105710 0418AA00 */  sllv       $v1, $t2, $a1
    /* 2F14 80105714 24104300 */  and        $v0, $v0, $v1
    /* 2F18 80105718 0C004010 */  beqz       $v0, .L8010574C
    /* 2F1C 8010571C 00000000 */   nop
    /* 2F20 80105720 F5FF8AA0 */  sb         $t2, -0xB($a0)
    /* 2F24 80105724 0000E294 */  lhu        $v0, 0x0($a3)
    /* 2F28 80105728 00000000 */  nop
    /* 2F2C 8010572C 40100200 */  sll        $v0, $v0, 1
    /* 2F30 80105730 21104B00 */  addu       $v0, $v0, $t3
    /* 2F34 80105734 FCFF82AC */  sw         $v0, -0x4($a0)
    /* 2F38 80105738 00000295 */  lhu        $v0, 0x0($t0)
    /* 2F3C 8010573C 00000000 */  nop
    /* 2F40 80105740 40100200 */  sll        $v0, $v0, 1
    /* 2F44 80105744 DD150408 */  j          .L80105774
    /* 2F48 80105748 21104C00 */   addu      $v0, $v0, $t4
  .L8010574C:
    /* 2F4C 8010574C F5FF80A0 */  sb         $zero, -0xB($a0)
    /* 2F50 80105750 DC97A295 */  lhu        $v0, %lo(_miscInfo)($t5)
    /* 2F54 80105754 00000000 */  nop
    /* 2F58 80105758 40100200 */  sll        $v0, $v0, 1
    /* 2F5C 8010575C 21104900 */  addu       $v0, $v0, $t1
    /* 2F60 80105760 FCFF82AC */  sw         $v0, -0x4($a0)
    /* 2F64 80105764 02002295 */  lhu        $v0, 0x2($t1)
    /* 2F68 80105768 00000000 */  nop
    /* 2F6C 8010576C 40100200 */  sll        $v0, $v0, 1
    /* 2F70 80105770 21104900 */  addu       $v0, $v0, $t1
  .L80105774:
    /* 2F74 80105774 000082AC */  sw         $v0, 0x0($a0)
    /* 2F78 80105778 02000825 */  addiu      $t0, $t0, 0x2
    /* 2F7C 8010577C 0200E724 */  addiu      $a3, $a3, 0x2
    /* 2F80 80105780 0100A524 */  addiu      $a1, $a1, 0x1
    /* 2F84 80105784 10008424 */  addiu      $a0, $a0, 0x10
    /* 2F88 80105788 2000A228 */  slti       $v0, $a1, 0x20
    /* 2F8C 8010578C D9FF4014 */  bnez       $v0, .L801056F4
    /* 2F90 80105790 1000C624 */   addiu     $a2, $a2, 0x10
    /* 2F94 80105794 0800E003 */  jr         $ra
    /* 2F98 80105798 00000000 */   nop
endlabel func_801056B8
