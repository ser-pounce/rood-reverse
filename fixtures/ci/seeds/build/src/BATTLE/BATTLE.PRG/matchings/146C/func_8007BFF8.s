nonmatching func_8007BFF8, 0x58

glabel func_8007BFF8
    /* 137F8 8007BFF8 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 137FC 8007BFFC 1000B0AF */  sw         $s0, 0x10($sp)
    /* 13800 8007C000 21808000 */  addu       $s0, $a0, $zero
    /* 13804 8007C004 0F80023C */  lui        $v0, %hi(vs_battle_actors)
    /* 13808 8007C008 28194224 */  addiu      $v0, $v0, %lo(vs_battle_actors)
    /* 1380C 8007C00C 80181000 */  sll        $v1, $s0, 2
    /* 13810 8007C010 21186200 */  addu       $v1, $v1, $v0
    /* 13814 8007C014 1400BFAF */  sw         $ra, 0x14($sp)
    /* 13818 8007C018 0000628C */  lw         $v0, 0x0($v1)
    /* 1381C 8007C01C 00000000 */  nop
    /* 13820 8007C020 07004010 */  beqz       $v0, .L8007C040
    /* 13824 8007C024 00000000 */   nop
    /* 13828 8007C028 F882020C */  jal        func_800A0BE0
    /* 1382C 8007C02C 00000000 */   nop
    /* 13830 8007C030 21200002 */  addu       $a0, $s0, $zero
    /* 13834 8007C034 FEFF0524 */  addiu      $a1, $zero, -0x2
    /* 13838 8007C038 1F82020C */  jal        func_800A087C
    /* 1383C 8007C03C 24284500 */   and       $a1, $v0, $a1
  .L8007C040:
    /* 13840 8007C040 1400BF8F */  lw         $ra, 0x14($sp)
    /* 13844 8007C044 1000B08F */  lw         $s0, 0x10($sp)
    /* 13848 8007C048 0800E003 */  jr         $ra
    /* 1384C 8007C04C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8007BFF8
