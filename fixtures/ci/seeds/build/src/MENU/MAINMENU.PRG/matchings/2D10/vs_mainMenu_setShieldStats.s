nonmatching vs_mainMenu_setShieldStats, 0x160

glabel vs_mainMenu_setShieldStats
    /* 3DA0 800FD5A0 78FEBD27 */  addiu      $sp, $sp, -0x188
    /* 3DA4 800FD5A4 8001B2AF */  sw         $s2, 0x180($sp)
    /* 3DA8 800FD5A8 21908000 */  addu       $s2, $a0, $zero
    /* 3DAC 800FD5AC 7C01B1AF */  sw         $s1, 0x17C($sp)
    /* 3DB0 800FD5B0 1000B127 */  addiu      $s1, $sp, 0x10
    /* 3DB4 800FD5B4 8401BFAF */  sw         $ra, 0x184($sp)
    /* 3DB8 800FD5B8 88F4030C */  jal        vs_mainMenu_resetStats
    /* 3DBC 800FD5BC 7801B0AF */   sw        $s0, 0x178($sp)
    /* 3DC0 800FD5C0 42004012 */  beqz       $s2, .L800FD6CC
    /* 3DC4 800FD5C4 1080033C */   lui       $v1, %hi(vs_mainMenu_shields)
    /* 3DC8 800FD5C8 40101200 */  sll        $v0, $s2, 1
    /* 3DCC 800FD5CC 21105200 */  addu       $v0, $v0, $s2
    /* 3DD0 800FD5D0 6C24638C */  lw         $v1, %lo(vs_mainMenu_shields)($v1)
    /* 3DD4 800FD5D4 00290200 */  sll        $a1, $v0, 4
    /* 3DD8 800FD5D8 2110A300 */  addu       $v0, $a1, $v1
    /* 3DDC 800FD5DC D1FF4290 */  lbu        $v0, -0x2F($v0)
    /* 3DE0 800FD5E0 00000000 */  nop
    /* 3DE4 800FD5E4 06004010 */  beqz       $v0, .L800FD600
    /* 3DE8 800FD5E8 0F80023C */   lui       $v0, %hi(vs_battle_characterState)
    /* 3DEC 800FD5EC FC19428C */  lw         $v0, %lo(vs_battle_characterState)($v0)
    /* 3DF0 800FD5F0 00000000 */  nop
    /* 3DF4 800FD5F4 3C00428C */  lw         $v0, 0x3C($v0)
    /* 3DF8 800FD5F8 8EF50308 */  j          .L800FD638
    /* 3DFC 800FD5FC D4015124 */   addiu     $s1, $v0, 0x1D4
  .L800FD600:
    /* 3E00 800FD600 0680023C */  lui        $v0, %hi(D_80060268)
    /* 3E04 800FD604 68024224 */  addiu      $v0, $v0, %lo(D_80060268)
    /* 3E08 800FD608 06006214 */  bne        $v1, $v0, .L800FD624
    /* 3E0C 800FD60C 21202002 */   addu      $a0, $s1, $zero
    /* 3E10 800FD610 D0FFA524 */  addiu      $a1, $a1, -0x30
    /* 3E14 800FD614 0BAC010C */  jal        vs_battle_applyShield
    /* 3E18 800FD618 2128A300 */   addu      $a1, $a1, $v1
    /* 3E1C 800FD61C 8FF50308 */  j          .L800FD63C
    /* 3E20 800FD620 1080103C */   lui       $s0, %hi(vs_mainMenu_equipmentStats)
  .L800FD624:
    /* 3E24 800FD624 1180023C */  lui        $v0, %hi(vs_menuD_containerData)
    /* 3E28 800FD628 8C9A468C */  lw         $a2, %lo(vs_menuD_containerData)($v0)
    /* 3E2C 800FD62C D0FFA524 */  addiu      $a1, $a1, -0x30
    /* 3E30 800FD630 EC0A040C */  jal        vs_menuD_initUiShield
    /* 3E34 800FD634 21286500 */   addu      $a1, $v1, $a1
  .L800FD638:
    /* 3E38 800FD638 1080103C */  lui        $s0, %hi(vs_mainMenu_equipmentStats)
  .L800FD63C:
    /* 3E3C 800FD63C C0241026 */  addiu      $s0, $s0, %lo(vs_mainMenu_equipmentStats)
    /* 3E40 800FD640 21200002 */  addu       $a0, $s0, $zero
    /* 3E44 800FD644 F4002526 */  addiu      $a1, $s1, 0xF4
    /* 3E48 800FD648 7800030C */  jal        vs_battle_memcpy
    /* 3E4C 800FD64C 40000624 */   addiu     $a2, $zero, 0x40
    /* 3E50 800FD650 21200000 */  addu       $a0, $zero, $zero
    /* 3E54 800FD654 40000524 */  addiu      $a1, $zero, 0x40
  .L800FD658:
    /* 3E58 800FD658 2118B000 */  addu       $v1, $a1, $s0
    /* 3E5C 800FD65C 21102402 */  addu       $v0, $s1, $a0
    /* 3E60 800FD660 F0004290 */  lbu        $v0, 0xF0($v0)
    /* 3E64 800FD664 01008424 */  addiu      $a0, $a0, 0x1
    /* 3E68 800FD668 000062A4 */  sh         $v0, 0x0($v1)
    /* 3E6C 800FD66C 04008228 */  slti       $v0, $a0, 0x4
    /* 3E70 800FD670 F9FF4014 */  bnez       $v0, .L800FD658
    /* 3E74 800FD674 0200A524 */   addiu     $a1, $a1, 0x2
    /* 3E78 800FD678 E0002496 */  lhu        $a0, 0xE0($s1)
    /* 3E7C 800FD67C E2002596 */  lhu        $a1, 0xE2($s1)
    /* 3E80 800FD680 DC002696 */  lhu        $a2, 0xDC($s1)
    /* 3E84 800FD684 DE002796 */  lhu        $a3, 0xDE($s1)
    /* 3E88 800FD688 82F0030C */  jal        vs_mainMenu_setDpPp
    /* 3E8C 800FD68C 00000000 */   nop
    /* 3E90 800FD690 E4002486 */  lh         $a0, 0xE4($s1)
    /* 3E94 800FD694 E8002586 */  lh         $a1, 0xE8($s1)
    /* 3E98 800FD698 EC002686 */  lh         $a2, 0xEC($s1)
    /* 3E9C 800FD69C 4AEF030C */  jal        vs_mainMenu_setStrIntAgi
    /* 3EA0 800FD6A0 01000724 */   addiu     $a3, $zero, 0x1
    /* 3EA4 800FD6A4 1080033C */  lui        $v1, %hi(vs_mainMenu_strIntAgi)
    /* 3EA8 800FD6A8 E6002296 */  lhu        $v0, 0xE6($s1)
    /* 3EAC 800FD6AC A8246324 */  addiu      $v1, $v1, %lo(vs_mainMenu_strIntAgi)
    /* 3EB0 800FD6B0 080062A4 */  sh         $v0, 0x8($v1)
    /* 3EB4 800FD6B4 EA002296 */  lhu        $v0, 0xEA($s1)
    /* 3EB8 800FD6B8 00000000 */  nop
    /* 3EBC 800FD6BC 0A0062A4 */  sh         $v0, 0xA($v1)
    /* 3EC0 800FD6C0 EE002296 */  lhu        $v0, 0xEE($s1)
    /* 3EC4 800FD6C4 00000000 */  nop
    /* 3EC8 800FD6C8 0C0062A4 */  sh         $v0, 0xC($v1)
  .L800FD6CC:
    /* 3ECC 800FD6CC 07000424 */  addiu      $a0, $zero, 0x7
    /* 3ED0 800FD6D0 1080023C */  lui        $v0, %hi(vs_mainMenu_equipmentSubtype)
    /* 3ED4 800FD6D4 08000324 */  addiu      $v1, $zero, 0x8
    /* 3ED8 800FD6D8 452543A0 */  sb         $v1, %lo(vs_mainMenu_equipmentSubtype)($v0)
    /* 3EDC 800FD6DC 1080023C */  lui        $v0, %hi(D_801024A1)
    /* 3EE0 800FD6E0 E3EE030C */  jal        func_800FBB8C
    /* 3EE4 800FD6E4 A12452A0 */   sb        $s2, %lo(D_801024A1)($v0)
    /* 3EE8 800FD6E8 8401BF8F */  lw         $ra, 0x184($sp)
    /* 3EEC 800FD6EC 8001B28F */  lw         $s2, 0x180($sp)
    /* 3EF0 800FD6F0 7C01B18F */  lw         $s1, 0x17C($sp)
    /* 3EF4 800FD6F4 7801B08F */  lw         $s0, 0x178($sp)
    /* 3EF8 800FD6F8 0800E003 */  jr         $ra
    /* 3EFC 800FD6FC 8801BD27 */   addiu     $sp, $sp, 0x188
endlabel vs_mainMenu_setShieldStats
