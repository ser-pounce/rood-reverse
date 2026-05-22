nonmatching func_80105674, 0x148

glabel func_80105674
    /* 2E74 80105674 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 2E78 80105678 21688000 */  addu       $t5, $a0, $zero
    /* 2E7C 8010567C 1180023C */  lui        $v0, %hi(_combiningItem)
    /* 2E80 80105680 0680033C */  lui        $v1, %hi(vs_battle_inventory)
    /* 2E84 80105684 81BC4490 */  lbu        $a0, %lo(_combiningItem)($v0)
    /* 2E88 80105688 68016324 */  addiu      $v1, $v1, %lo(vs_battle_inventory)
    /* 2E8C 8010568C 1000BFAF */  sw         $ra, 0x10($sp)
    /* 2E90 80105690 40110400 */  sll        $v0, $a0, 5
    /* 2E94 80105694 21504300 */  addu       $t2, $v0, $v1
    /* 2E98 80105698 40100400 */  sll        $v0, $a0, 1
    /* 2E9C 8010569C 21104400 */  addu       $v0, $v0, $a0
    /* 2EA0 801056A0 00110200 */  sll        $v0, $v0, 4
    /* 2EA4 801056A4 00016324 */  addiu      $v1, $v1, 0x100
    /* 2EA8 801056A8 0300A010 */  beqz       $a1, .L801056B8
    /* 2EAC 801056AC 21204300 */   addu      $a0, $v0, $v1
    /* 2EB0 801056B0 AF150408 */  j          .L801056BC
    /* 2EB4 801056B4 2C008924 */   addiu     $t1, $a0, 0x2C
  .L801056B8:
    /* 2EB8 801056B8 04004925 */  addiu      $t1, $t2, 0x4
  .L801056BC:
    /* 2EBC 801056BC 21380000 */  addu       $a3, $zero, $zero
    /* 2EC0 801056C0 0680023C */  lui        $v0, %hi(vs_battle_inventory)
    /* 2EC4 801056C4 68014B24 */  addiu      $t3, $v0, %lo(vs_battle_inventory)
    /* 2EC8 801056C8 21402701 */  addu       $t0, $t1, $a3
  .L801056CC:
    /* 2ECC 801056CC 00000691 */  lbu        $a2, 0x0($t0)
    /* 2ED0 801056D0 00000000 */  nop
    /* 2ED4 801056D4 0700C010 */  beqz       $a2, .L801056F4
    /* 2ED8 801056D8 FFFFC324 */   addiu     $v1, $a2, -0x1
    /* 2EDC 801056DC C0100300 */  sll        $v0, $v1, 3
    /* 2EE0 801056E0 23104300 */  subu       $v0, $v0, $v1
    /* 2EE4 801056E4 80100200 */  sll        $v0, $v0, 2
    /* 2EE8 801056E8 21104B00 */  addu       $v0, $v0, $t3
    /* 2EEC 801056EC D80840A4 */  sh         $zero, 0x8D8($v0)
    /* 2EF0 801056F0 000000A1 */  sb         $zero, 0x0($t0)
  .L801056F4:
    /* 2EF4 801056F4 0100E724 */  addiu      $a3, $a3, 0x1
    /* 2EF8 801056F8 0300E228 */  slti       $v0, $a3, 0x3
    /* 2EFC 801056FC F3FF4014 */  bnez       $v0, .L801056CC
    /* 2F00 80105700 21402701 */   addu      $t0, $t1, $a3
    /* 2F04 80105704 21380000 */  addu       $a3, $zero, $zero
    /* 2F08 80105708 0680023C */  lui        $v0, %hi(vs_battle_inventory)
    /* 2F0C 8010570C 68014C24 */  addiu      $t4, $v0, %lo(vs_battle_inventory)
    /* 2F10 80105710 11800B3C */  lui        $t3, %hi(_combiningItem)
    /* 2F14 80105714 C0110500 */  sll        $v0, $a1, 7
    /* 2F18 80105718 01004824 */  addiu      $t0, $v0, 0x1
    /* 2F1C 8010571C 2110A701 */  addu       $v0, $t5, $a3
  .L80105720:
    /* 2F20 80105720 00004690 */  lbu        $a2, 0x0($v0)
    /* 2F24 80105724 00000000 */  nop
    /* 2F28 80105728 0A00C010 */  beqz       $a2, .L80105754
    /* 2F2C 8010572C FFFFC324 */   addiu     $v1, $a2, -0x1
    /* 2F30 80105730 C0100300 */  sll        $v0, $v1, 3
    /* 2F34 80105734 23104300 */  subu       $v0, $v0, $v1
    /* 2F38 80105738 80100200 */  sll        $v0, $v0, 2
    /* 2F3C 8010573C 81BC6391 */  lbu        $v1, %lo(_combiningItem)($t3)
    /* 2F40 80105740 21104C00 */  addu       $v0, $v0, $t4
    /* 2F44 80105744 21186800 */  addu       $v1, $v1, $t0
    /* 2F48 80105748 D80843A4 */  sh         $v1, 0x8D8($v0)
    /* 2F4C 8010574C 21102701 */  addu       $v0, $t1, $a3
    /* 2F50 80105750 000046A0 */  sb         $a2, 0x0($v0)
  .L80105754:
    /* 2F54 80105754 0100E724 */  addiu      $a3, $a3, 0x1
    /* 2F58 80105758 0300E228 */  slti       $v0, $a3, 0x3
    /* 2F5C 8010575C F0FF4014 */  bnez       $v0, .L80105720
    /* 2F60 80105760 2110A701 */   addu      $v0, $t5, $a3
    /* 2F64 80105764 0900A010 */  beqz       $a1, .L8010578C
    /* 2F68 80105768 00000000 */   nop
    /* 2F6C 8010576C 01008290 */  lbu        $v0, 0x1($a0)
    /* 2F70 80105770 00000000 */  nop
    /* 2F74 80105774 0B004010 */  beqz       $v0, .L801057A4
    /* 2F78 80105778 00000000 */   nop
    /* 2F7C 8010577C 18AD010C */  jal        vs_battle_equipShield
    /* 2F80 80105780 00000000 */   nop
    /* 2F84 80105784 E9150408 */  j          .L801057A4
    /* 2F88 80105788 00000000 */   nop
  .L8010578C:
    /* 2F8C 8010578C 03004291 */  lbu        $v0, 0x3($t2)
    /* 2F90 80105790 00000000 */  nop
    /* 2F94 80105794 03004010 */  beqz       $v0, .L801057A4
    /* 2F98 80105798 00000000 */   nop
    /* 2F9C 8010579C CEAC010C */  jal        vs_battle_equipWeapon
    /* 2FA0 801057A0 21204001 */   addu      $a0, $t2, $zero
  .L801057A4:
    /* 2FA4 801057A4 E00C040C */  jal        func_80103380
    /* 2FA8 801057A8 01000424 */   addiu     $a0, $zero, 0x1
    /* 2FAC 801057AC 1000BF8F */  lw         $ra, 0x10($sp)
    /* 2FB0 801057B0 00000000 */  nop
    /* 2FB4 801057B4 0800E003 */  jr         $ra
    /* 2FB8 801057B8 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80105674
