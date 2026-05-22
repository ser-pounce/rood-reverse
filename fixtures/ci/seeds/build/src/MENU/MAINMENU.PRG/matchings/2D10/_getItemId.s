nonmatching _getItemId, 0xF4

glabel _getItemId
    /* 4EEC 800FE6EC 0300C014 */  bnez       $a2, .L800FE6FC
    /* 4EF0 800FE6F0 21380000 */   addu      $a3, $zero, $zero
    /* 4EF4 800FE6F4 0680023C */  lui        $v0, %hi(vs_battle_inventory)
    /* 4EF8 800FE6F8 68014624 */  addiu      $a2, $v0, %lo(vs_battle_inventory)
  .L800FE6FC:
    /* 4EFC 800FE6FC 0700822C */  sltiu      $v0, $a0, 0x7
    /* 4F00 800FE700 33004010 */  beqz       $v0, .L800FE7D0
    /* 4F04 800FE704 1080023C */   lui       $v0, %hi(jtbl_800F99BC)
    /* 4F08 800FE708 BC994224 */  addiu      $v0, $v0, %lo(jtbl_800F99BC)
    /* 4F0C 800FE70C 80180400 */  sll        $v1, $a0, 2
    /* 4F10 800FE710 21186200 */  addu       $v1, $v1, $v0
    /* 4F14 800FE714 0000628C */  lw         $v0, 0x0($v1)
    /* 4F18 800FE718 00000000 */  nop
    /* 4F1C 800FE71C 08004000 */  jr         $v0
    /* 4F20 800FE720 00000000 */   nop
    /* 4F24 800FE724 40110500 */  sll        $v0, $a1, 5
    /* 4F28 800FE728 2110C200 */  addu       $v0, $a2, $v0
    /* 4F2C 800FE72C 01004790 */  lbu        $a3, 0x1($v0)
    /* 4F30 800FE730 0800E003 */  jr         $ra
    /* 4F34 800FE734 2110E000 */   addu      $v0, $a3, $zero
    /* 4F38 800FE738 40100500 */  sll        $v0, $a1, 1
    /* 4F3C 800FE73C 21104500 */  addu       $v0, $v0, $a1
    /* 4F40 800FE740 80100200 */  sll        $v0, $v0, 2
    /* 4F44 800FE744 23104500 */  subu       $v0, $v0, $a1
    /* 4F48 800FE748 80100200 */  sll        $v0, $v0, 2
    /* 4F4C 800FE74C 2110C200 */  addu       $v0, $a2, $v0
    /* 4F50 800FE750 80024790 */  lbu        $a3, 0x280($v0)
    /* 4F54 800FE754 0800E003 */  jr         $ra
    /* 4F58 800FE758 2110E000 */   addu      $v0, $a3, $zero
    /* 4F5C 800FE75C 00110500 */  sll        $v0, $a1, 4
    /* 4F60 800FE760 2110C200 */  addu       $v0, $a2, $v0
    /* 4F64 800FE764 40054794 */  lhu        $a3, 0x540($v0)
    /* 4F68 800FE768 0800E003 */  jr         $ra
    /* 4F6C 800FE76C 2110E000 */   addu      $v0, $a3, $zero
    /* 4F70 800FE770 40100500 */  sll        $v0, $a1, 1
    /* 4F74 800FE774 21104500 */  addu       $v0, $v0, $a1
    /* 4F78 800FE778 00110200 */  sll        $v0, $v0, 4
    /* 4F7C 800FE77C 2110C200 */  addu       $v0, $a2, $v0
    /* 4F80 800FE780 04014790 */  lbu        $a3, 0x104($v0)
    /* 4F84 800FE784 0800E003 */  jr         $ra
    /* 4F88 800FE788 2110E000 */   addu      $v0, $a3, $zero
    /* 4F8C 800FE78C 80100500 */  sll        $v0, $a1, 2
    /* 4F90 800FE790 21104500 */  addu       $v0, $v0, $a1
    /* 4F94 800FE794 C0100200 */  sll        $v0, $v0, 3
    /* 4F98 800FE798 2110C200 */  addu       $v0, $a2, $v0
    /* 4F9C 800FE79C 40064790 */  lbu        $a3, 0x640($v0)
    /* 4FA0 800FE7A0 0800E003 */  jr         $ra
    /* 4FA4 800FE7A4 2110E000 */   addu      $v0, $a3, $zero
    /* 4FA8 800FE7A8 C0100500 */  sll        $v0, $a1, 3
    /* 4FAC 800FE7AC 23104500 */  subu       $v0, $v0, $a1
    /* 4FB0 800FE7B0 80100200 */  sll        $v0, $v0, 2
    /* 4FB4 800FE7B4 2110C200 */  addu       $v0, $a2, $v0
    /* 4FB8 800FE7B8 C0084794 */  lhu        $a3, 0x8C0($v0)
    /* 4FBC 800FE7BC 0800E003 */  jr         $ra
    /* 4FC0 800FE7C0 2110E000 */   addu      $v0, $a3, $zero
    /* 4FC4 800FE7C4 80100500 */  sll        $v0, $a1, 2
    /* 4FC8 800FE7C8 2110C200 */  addu       $v0, $a2, $v0
    /* 4FCC 800FE7CC 000E4794 */  lhu        $a3, 0xE00($v0)
  .L800FE7D0:
    /* 4FD0 800FE7D0 00000000 */  nop
    /* 4FD4 800FE7D4 2110E000 */  addu       $v0, $a3, $zero
    /* 4FD8 800FE7D8 0800E003 */  jr         $ra
    /* 4FDC 800FE7DC 00000000 */   nop
endlabel _getItemId
