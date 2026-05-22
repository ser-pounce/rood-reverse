nonmatching _getParentItem, 0x90

glabel _getParentItem
    /* 27B4 80104FB4 01000224 */  addiu      $v0, $zero, 0x1
    /* 27B8 80104FB8 0A008214 */  bne        $a0, $v0, .L80104FE4
    /* 27BC 80104FBC 21180000 */   addu      $v1, $zero, $zero
    /* 27C0 80104FC0 0680033C */  lui        $v1, %hi(vs_battle_inventory)
    /* 27C4 80104FC4 68016324 */  addiu      $v1, $v1, %lo(vs_battle_inventory)
    /* 27C8 80104FC8 04104500 */  sllv       $v0, $a1, $v0
    /* 27CC 80104FCC 21104500 */  addu       $v0, $v0, $a1
    /* 27D0 80104FD0 80100200 */  sll        $v0, $v0, 2
    /* 27D4 80104FD4 23104500 */  subu       $v0, $v0, $a1
    /* 27D8 80104FD8 80100200 */  sll        $v0, $v0, 2
    /* 27DC 80104FDC 21104300 */  addu       $v0, $v0, $v1
    /* 27E0 80104FE0 AA024390 */  lbu        $v1, 0x2AA($v0)
  .L80104FE4:
    /* 27E4 80104FE4 02000224 */  addiu      $v0, $zero, 0x2
    /* 27E8 80104FE8 07008214 */  bne        $a0, $v0, .L80105008
    /* 27EC 80104FEC 05000224 */   addiu     $v0, $zero, 0x5
    /* 27F0 80104FF0 0680033C */  lui        $v1, %hi(vs_battle_inventory)
    /* 27F4 80104FF4 68016324 */  addiu      $v1, $v1, %lo(vs_battle_inventory)
    /* 27F8 80104FF8 00110500 */  sll        $v0, $a1, 4
    /* 27FC 80104FFC 21104300 */  addu       $v0, $v0, $v1
    /* 2800 80105000 4C054394 */  lhu        $v1, 0x54C($v0)
    /* 2804 80105004 05000224 */  addiu      $v0, $zero, 0x5
  .L80105008:
    /* 2808 80105008 0C008214 */  bne        $a0, $v0, .L8010503C
    /* 280C 8010500C 0680023C */   lui       $v0, %hi(vs_battle_inventory)
    /* 2810 80105010 68014224 */  addiu      $v0, $v0, %lo(vs_battle_inventory)
    /* 2814 80105014 C0180500 */  sll        $v1, $a1, 3
    /* 2818 80105018 23186500 */  subu       $v1, $v1, $a1
    /* 281C 8010501C 80180300 */  sll        $v1, $v1, 2
    /* 2820 80105020 21186200 */  addu       $v1, $v1, $v0
    /* 2824 80105024 D8086394 */  lhu        $v1, 0x8D8($v1)
    /* 2828 80105028 00000000 */  nop
    /* 282C 8010502C 80006230 */  andi       $v0, $v1, 0x80
    /* 2830 80105030 02004010 */  beqz       $v0, .L8010503C
    /* 2834 80105034 00000000 */   nop
    /* 2838 80105038 21180000 */  addu       $v1, $zero, $zero
  .L8010503C:
    /* 283C 8010503C 0800E003 */  jr         $ra
    /* 2840 80105040 21106000 */   addu      $v0, $v1, $zero
endlabel _getParentItem
