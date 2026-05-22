nonmatching _sortItemsByStat, 0x15C

glabel _sortItemsByStat
    /* 2DF0 801055F0 C0FDBD27 */  addiu      $sp, $sp, -0x240
    /* 2DF4 801055F4 3802BEAF */  sw         $fp, 0x238($sp)
    /* 2DF8 801055F8 21F08000 */  addu       $fp, $a0, $zero
    /* 2DFC 801055FC 06000424 */  addiu      $a0, $zero, 0x6
    /* 2E00 80105600 2C02B5AF */  sw         $s5, 0x22C($sp)
    /* 2E04 80105604 21A80000 */  addu       $s5, $zero, $zero
    /* 2E08 80105608 1180023C */  lui        $v0, %hi(vs_menuD_containerData)
    /* 2E0C 8010560C 8C9A458C */  lw         $a1, %lo(vs_menuD_containerData)($v0)
    /* 2E10 80105610 1000A727 */  addiu      $a3, $sp, 0x10
    /* 2E14 80105614 3C02BFAF */  sw         $ra, 0x23C($sp)
    /* 2E18 80105618 3402B7AF */  sw         $s7, 0x234($sp)
    /* 2E1C 8010561C 3002B6AF */  sw         $s6, 0x230($sp)
    /* 2E20 80105620 2802B4AF */  sw         $s4, 0x228($sp)
    /* 2E24 80105624 2402B3AF */  sw         $s3, 0x224($sp)
    /* 2E28 80105628 2002B2AF */  sw         $s2, 0x220($sp)
    /* 2E2C 8010562C 1C02B1AF */  sw         $s1, 0x21C($sp)
    /* 2E30 80105630 1802B0AF */  sw         $s0, 0x218($sp)
    /* 2E34 80105634 1002A7AF */  sw         $a3, 0x210($sp)
    /* 2E38 80105638 250B040C */  jal        _getContainerIndicesOffset
    /* 2E3C 8010563C 0038B624 */   addiu     $s6, $a1, 0x3800
    /* 2E40 80105640 1000A427 */  addiu      $a0, $sp, 0x10
    /* 2E44 80105644 00020524 */  addiu      $a1, $zero, 0x200
    /* 2E48 80105648 0733030C */  jal        vs_battle_rMemzero
    /* 2E4C 8010564C 21B84000 */   addu      $s7, $v0, $zero
    /* 2E50 80105650 0080143C */  lui        $s4, (0x80000000 >> 16)
  .L80105654:
    /* 2E54 80105654 21880000 */  addu       $s1, $zero, $zero
    /* 2E58 80105658 2190E002 */  addu       $s2, $s7, $zero
  .L8010565C:
    /* 2E5C 8010565C 00005096 */  lhu        $s0, 0x0($s2)
    /* 2E60 80105660 00000000 */  nop
    /* 2E64 80105664 0A000012 */  beqz       $s0, .L80105690
    /* 2E68 80105668 2120C003 */   addu      $a0, $fp, $zero
    /* 2E6C 8010566C 80281000 */  sll        $a1, $s0, 2
    /* 2E70 80105670 FCFFA524 */  addiu      $a1, $a1, -0x4
    /* 2E74 80105674 7415040C */  jal        _getItemStat
    /* 2E78 80105678 2128C502 */   addu      $a1, $s6, $a1
    /* 2E7C 8010567C 21184000 */  addu       $v1, $v0, $zero
    /* 2E80 80105680 2A108302 */  slt        $v0, $s4, $v1
    /* 2E84 80105684 02004010 */  beqz       $v0, .L80105690
    /* 2E88 80105688 00000000 */   nop
    /* 2E8C 8010568C 21A06000 */  addu       $s4, $v1, $zero
  .L80105690:
    /* 2E90 80105690 01003126 */  addiu      $s1, $s1, 0x1
    /* 2E94 80105694 0001222A */  slti       $v0, $s1, 0x100
    /* 2E98 80105698 F0FF4014 */  bnez       $v0, .L8010565C
    /* 2E9C 8010569C 02005226 */   addiu     $s2, $s2, 0x2
    /* 2EA0 801056A0 0080023C */  lui        $v0, (0x80000000 >> 16)
    /* 2EA4 801056A4 19008212 */  beq        $s4, $v0, .L8010570C
    /* 2EA8 801056A8 21880000 */   addu      $s1, $zero, $zero
    /* 2EAC 801056AC 2190E002 */  addu       $s2, $s7, $zero
    /* 2EB0 801056B0 1002A78F */  lw         $a3, 0x210($sp)
    /* 2EB4 801056B4 40101500 */  sll        $v0, $s5, 1
    /* 2EB8 801056B8 21984700 */  addu       $s3, $v0, $a3
  .L801056BC:
    /* 2EBC 801056BC 00005096 */  lhu        $s0, 0x0($s2)
    /* 2EC0 801056C0 00000000 */  nop
    /* 2EC4 801056C4 0B000012 */  beqz       $s0, .L801056F4
    /* 2EC8 801056C8 2120C003 */   addu      $a0, $fp, $zero
    /* 2ECC 801056CC 80281000 */  sll        $a1, $s0, 2
    /* 2ED0 801056D0 FCFFA524 */  addiu      $a1, $a1, -0x4
    /* 2ED4 801056D4 7415040C */  jal        _getItemStat
    /* 2ED8 801056D8 2128C502 */   addu      $a1, $s6, $a1
    /* 2EDC 801056DC 05005414 */  bne        $v0, $s4, .L801056F4
    /* 2EE0 801056E0 00000000 */   nop
    /* 2EE4 801056E4 000070A6 */  sh         $s0, 0x0($s3)
    /* 2EE8 801056E8 02007326 */  addiu      $s3, $s3, 0x2
    /* 2EEC 801056EC 0100B526 */  addiu      $s5, $s5, 0x1
    /* 2EF0 801056F0 000040A6 */  sh         $zero, 0x0($s2)
  .L801056F4:
    /* 2EF4 801056F4 01003126 */  addiu      $s1, $s1, 0x1
    /* 2EF8 801056F8 0001222A */  slti       $v0, $s1, 0x100
    /* 2EFC 801056FC EFFF4014 */  bnez       $v0, .L801056BC
    /* 2F00 80105700 02005226 */   addiu     $s2, $s2, 0x2
    /* 2F04 80105704 95150408 */  j          .L80105654
    /* 2F08 80105708 0080143C */   lui       $s4, (0x80000000 >> 16)
  .L8010570C:
    /* 2F0C 8010570C 2120E002 */  addu       $a0, $s7, $zero
    /* 2F10 80105710 1000A527 */  addiu      $a1, $sp, 0x10
    /* 2F14 80105714 7800030C */  jal        vs_battle_memcpy
    /* 2F18 80105718 00020624 */   addiu     $a2, $zero, 0x200
    /* 2F1C 8010571C 3C02BF8F */  lw         $ra, 0x23C($sp)
    /* 2F20 80105720 3802BE8F */  lw         $fp, 0x238($sp)
    /* 2F24 80105724 3402B78F */  lw         $s7, 0x234($sp)
    /* 2F28 80105728 3002B68F */  lw         $s6, 0x230($sp)
    /* 2F2C 8010572C 2C02B58F */  lw         $s5, 0x22C($sp)
    /* 2F30 80105730 2802B48F */  lw         $s4, 0x228($sp)
    /* 2F34 80105734 2402B38F */  lw         $s3, 0x224($sp)
    /* 2F38 80105738 2002B28F */  lw         $s2, 0x220($sp)
    /* 2F3C 8010573C 1C02B18F */  lw         $s1, 0x21C($sp)
    /* 2F40 80105740 1802B08F */  lw         $s0, 0x218($sp)
    /* 2F44 80105744 0800E003 */  jr         $ra
    /* 2F48 80105748 4002BD27 */   addiu     $sp, $sp, 0x240
endlabel _sortItemsByStat
