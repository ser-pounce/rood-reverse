nonmatching func_80104EC0, 0x90

glabel func_80104EC0
    /* 26C0 80104EC0 01000224 */  addiu      $v0, $zero, 0x1
    /* 26C4 80104EC4 0A008214 */  bne        $a0, $v0, .L80104EF0
    /* 26C8 80104EC8 21180000 */   addu      $v1, $zero, $zero
    /* 26CC 80104ECC 0680033C */  lui        $v1, %hi(vs_battle_inventory)
    /* 26D0 80104ED0 68016324 */  addiu      $v1, $v1, %lo(vs_battle_inventory)
    /* 26D4 80104ED4 04104500 */  sllv       $v0, $a1, $v0
    /* 26D8 80104ED8 21104500 */  addu       $v0, $v0, $a1
    /* 26DC 80104EDC 80100200 */  sll        $v0, $v0, 2
    /* 26E0 80104EE0 23104500 */  subu       $v0, $v0, $a1
    /* 26E4 80104EE4 80100200 */  sll        $v0, $v0, 2
    /* 26E8 80104EE8 21104300 */  addu       $v0, $v0, $v1
    /* 26EC 80104EEC AA024390 */  lbu        $v1, 0x2AA($v0)
  .L80104EF0:
    /* 26F0 80104EF0 02000224 */  addiu      $v0, $zero, 0x2
    /* 26F4 80104EF4 07008214 */  bne        $a0, $v0, .L80104F14
    /* 26F8 80104EF8 05000224 */   addiu     $v0, $zero, 0x5
    /* 26FC 80104EFC 0680033C */  lui        $v1, %hi(vs_battle_inventory)
    /* 2700 80104F00 68016324 */  addiu      $v1, $v1, %lo(vs_battle_inventory)
    /* 2704 80104F04 00110500 */  sll        $v0, $a1, 4
    /* 2708 80104F08 21104300 */  addu       $v0, $v0, $v1
    /* 270C 80104F0C 4C054394 */  lhu        $v1, 0x54C($v0)
    /* 2710 80104F10 05000224 */  addiu      $v0, $zero, 0x5
  .L80104F14:
    /* 2714 80104F14 0C008214 */  bne        $a0, $v0, .L80104F48
    /* 2718 80104F18 0680023C */   lui       $v0, %hi(vs_battle_inventory)
    /* 271C 80104F1C 68014224 */  addiu      $v0, $v0, %lo(vs_battle_inventory)
    /* 2720 80104F20 C0180500 */  sll        $v1, $a1, 3
    /* 2724 80104F24 23186500 */  subu       $v1, $v1, $a1
    /* 2728 80104F28 80180300 */  sll        $v1, $v1, 2
    /* 272C 80104F2C 21186200 */  addu       $v1, $v1, $v0
    /* 2730 80104F30 D8086394 */  lhu        $v1, 0x8D8($v1)
    /* 2734 80104F34 00000000 */  nop
    /* 2738 80104F38 80006230 */  andi       $v0, $v1, 0x80
    /* 273C 80104F3C 02004010 */  beqz       $v0, .L80104F48
    /* 2740 80104F40 00000000 */   nop
    /* 2744 80104F44 21180000 */  addu       $v1, $zero, $zero
  .L80104F48:
    /* 2748 80104F48 0800E003 */  jr         $ra
    /* 274C 80104F4C 21106000 */   addu      $v0, $v1, $zero
endlabel func_80104EC0
