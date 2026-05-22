nonmatching vs_mainMenu_setArmorStats, 0x178

glabel vs_mainMenu_setArmorStats
    /* 3F00 800FD700 18FFBD27 */  addiu      $sp, $sp, -0xE8
    /* 3F04 800FD704 DC00B3AF */  sw         $s3, 0xDC($sp)
    /* 3F08 800FD708 21988000 */  addu       $s3, $a0, $zero
    /* 3F0C 800FD70C D400B1AF */  sw         $s1, 0xD4($sp)
    /* 3F10 800FD710 1000B127 */  addiu      $s1, $sp, 0x10
    /* 3F14 800FD714 D800B2AF */  sw         $s2, 0xD8($sp)
    /* 3F18 800FD718 21900000 */  addu       $s2, $zero, $zero
    /* 3F1C 800FD71C E000BFAF */  sw         $ra, 0xE0($sp)
    /* 3F20 800FD720 88F4030C */  jal        vs_mainMenu_resetStats
    /* 3F24 800FD724 D000B0AF */   sw        $s0, 0xD0($sp)
    /* 3F28 800FD728 42006012 */  beqz       $s3, .L800FD834
    /* 3F2C 800FD72C 1080033C */   lui       $v1, %hi(vs_mainMenu_armor)
    /* 3F30 800FD730 80101300 */  sll        $v0, $s3, 2
    /* 3F34 800FD734 21105300 */  addu       $v0, $v0, $s3
    /* 3F38 800FD738 6824638C */  lw         $v1, %lo(vs_mainMenu_armor)($v1)
    /* 3F3C 800FD73C C0280200 */  sll        $a1, $v0, 3
    /* 3F40 800FD740 2110A300 */  addu       $v0, $a1, $v1
    /* 3F44 800FD744 FEFF4290 */  lbu        $v0, -0x2($v0)
    /* 3F48 800FD748 00000000 */  nop
    /* 3F4C 800FD74C FFFF4424 */  addiu      $a0, $v0, -0x1
    /* 3F50 800FD750 0500822C */  sltiu      $v0, $a0, 0x5
    /* 3F54 800FD754 0B004010 */  beqz       $v0, .L800FD784
    /* 3F58 800FD758 C0100400 */   sll       $v0, $a0, 3
    /* 3F5C 800FD75C 0F80033C */  lui        $v1, %hi(vs_battle_characterState)
    /* 3F60 800FD760 23104400 */  subu       $v0, $v0, $a0
    /* 3F64 800FD764 C0100200 */  sll        $v0, $v0, 3
    /* 3F68 800FD768 FC19638C */  lw         $v1, %lo(vs_battle_characterState)($v1)
    /* 3F6C 800FD76C 23104400 */  subu       $v0, $v0, $a0
    /* 3F70 800FD770 3C00638C */  lw         $v1, 0x3C($v1)
    /* 3F74 800FD774 80100200 */  sll        $v0, $v0, 2
    /* 3F78 800FD778 21104300 */  addu       $v0, $v0, $v1
    /* 3F7C 800FD77C E5F50308 */  j          .L800FD794
    /* 3F80 800FD780 B8035124 */   addiu     $s1, $v0, 0x3B8
  .L800FD784:
    /* 3F84 800FD784 21202002 */  addu       $a0, $s1, $zero
    /* 3F88 800FD788 D8FFA524 */  addiu      $a1, $a1, -0x28
    /* 3F8C 800FD78C 44AC010C */  jal        vs_battle_applyArmor
    /* 3F90 800FD790 21286500 */   addu      $a1, $v1, $a1
  .L800FD794:
    /* 3F94 800FD794 1080103C */  lui        $s0, %hi(vs_mainMenu_equipmentStats)
    /* 3F98 800FD798 C0241026 */  addiu      $s0, $s0, %lo(vs_mainMenu_equipmentStats)
    /* 3F9C 800FD79C 21200002 */  addu       $a0, $s0, $zero
    /* 3FA0 800FD7A0 48002526 */  addiu      $a1, $s1, 0x48
    /* 3FA4 800FD7A4 04002292 */  lbu        $v0, 0x4($s1)
    /* 3FA8 800FD7A8 40000624 */  addiu      $a2, $zero, 0x40
    /* 3FAC 800FD7AC 07004238 */  xori       $v0, $v0, 0x7
    /* 3FB0 800FD7B0 7800030C */  jal        vs_battle_memcpy
    /* 3FB4 800FD7B4 0100522C */   sltiu     $s2, $v0, 0x1
    /* 3FB8 800FD7B8 21300000 */  addu       $a2, $zero, $zero
    /* 3FBC 800FD7BC 21282002 */  addu       $a1, $s1, $zero
    /* 3FC0 800FD7C0 40000424 */  addiu      $a0, $zero, 0x40
  .L800FD7C4:
    /* 3FC4 800FD7C4 4000A394 */  lhu        $v1, 0x40($a1)
    /* 3FC8 800FD7C8 0200A524 */  addiu      $a1, $a1, 0x2
    /* 3FCC 800FD7CC 21109000 */  addu       $v0, $a0, $s0
    /* 3FD0 800FD7D0 0100C624 */  addiu      $a2, $a2, 0x1
    /* 3FD4 800FD7D4 000043A4 */  sh         $v1, 0x0($v0)
    /* 3FD8 800FD7D8 0400C228 */  slti       $v0, $a2, 0x4
    /* 3FDC 800FD7DC F9FF4014 */  bnez       $v0, .L800FD7C4
    /* 3FE0 800FD7E0 02008424 */   addiu     $a0, $a0, 0x2
    /* 3FE4 800FD7E4 21300000 */  addu       $a2, $zero, $zero
    /* 3FE8 800FD7E8 30002496 */  lhu        $a0, 0x30($s1)
    /* 3FEC 800FD7EC 32002596 */  lhu        $a1, 0x32($s1)
    /* 3FF0 800FD7F0 82F0030C */  jal        vs_mainMenu_setDpPp
    /* 3FF4 800FD7F4 2138C000 */   addu      $a3, $a2, $zero
    /* 3FF8 800FD7F8 34002486 */  lh         $a0, 0x34($s1)
    /* 3FFC 800FD7FC 38002586 */  lh         $a1, 0x38($s1)
    /* 4000 800FD800 3C002686 */  lh         $a2, 0x3C($s1)
    /* 4004 800FD804 4AEF030C */  jal        vs_mainMenu_setStrIntAgi
    /* 4008 800FD808 01004726 */   addiu     $a3, $s2, 0x1
    /* 400C 800FD80C 1080033C */  lui        $v1, %hi(vs_mainMenu_strIntAgi)
    /* 4010 800FD810 36002296 */  lhu        $v0, 0x36($s1)
    /* 4014 800FD814 A8246324 */  addiu      $v1, $v1, %lo(vs_mainMenu_strIntAgi)
    /* 4018 800FD818 080062A4 */  sh         $v0, 0x8($v1)
    /* 401C 800FD81C 3A002296 */  lhu        $v0, 0x3A($s1)
    /* 4020 800FD820 00000000 */  nop
    /* 4024 800FD824 0A0062A4 */  sh         $v0, 0xA($v1)
    /* 4028 800FD828 3E002296 */  lhu        $v0, 0x3E($s1)
    /* 402C 800FD82C 00000000 */  nop
    /* 4030 800FD830 0C0062A4 */  sh         $v0, 0xC($v1)
  .L800FD834:
    /* 4034 800FD834 03004012 */  beqz       $s2, .L800FD844
    /* 4038 800FD838 1080033C */   lui       $v1, %hi(vs_mainMenu_equipmentSubtype)
    /* 403C 800FD83C 12F60308 */  j          .L800FD848
    /* 4040 800FD840 20000224 */   addiu     $v0, $zero, 0x20
  .L800FD844:
    /* 4044 800FD844 10000224 */  addiu      $v0, $zero, 0x10
  .L800FD848:
    /* 4048 800FD848 452562A0 */  sb         $v0, %lo(vs_mainMenu_equipmentSubtype)($v1)
    /* 404C 800FD84C 1080023C */  lui        $v0, %hi(D_801024A1)
    /* 4050 800FD850 07000424 */  addiu      $a0, $zero, 0x7
    /* 4054 800FD854 E3EE030C */  jal        func_800FBB8C
    /* 4058 800FD858 A12453A0 */   sb        $s3, %lo(D_801024A1)($v0)
    /* 405C 800FD85C E000BF8F */  lw         $ra, 0xE0($sp)
    /* 4060 800FD860 DC00B38F */  lw         $s3, 0xDC($sp)
    /* 4064 800FD864 D800B28F */  lw         $s2, 0xD8($sp)
    /* 4068 800FD868 D400B18F */  lw         $s1, 0xD4($sp)
    /* 406C 800FD86C D000B08F */  lw         $s0, 0xD0($sp)
    /* 4070 800FD870 0800E003 */  jr         $ra
    /* 4074 800FD874 E800BD27 */   addiu     $sp, $sp, 0xE8
endlabel vs_mainMenu_setArmorStats
