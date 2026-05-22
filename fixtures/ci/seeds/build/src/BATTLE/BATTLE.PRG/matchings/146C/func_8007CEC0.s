nonmatching func_8007CEC0, 0x58

glabel func_8007CEC0
    /* 146C0 8007CEC0 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 146C4 8007CEC4 1000B0AF */  sw         $s0, 0x10($sp)
    /* 146C8 8007CEC8 21800000 */  addu       $s0, $zero, $zero
    /* 146CC 8007CECC 0F80023C */  lui        $v0, %hi(vs_battle_actors)
    /* 146D0 8007CED0 1400B1AF */  sw         $s1, 0x14($sp)
    /* 146D4 8007CED4 28195124 */  addiu      $s1, $v0, %lo(vs_battle_actors)
    /* 146D8 8007CED8 1800BFAF */  sw         $ra, 0x18($sp)
  .L8007CEDC:
    /* 146DC 8007CEDC 0000228E */  lw         $v0, 0x0($s1)
    /* 146E0 8007CEE0 00000000 */  nop
    /* 146E4 8007CEE4 03004010 */  beqz       $v0, .L8007CEF4
    /* 146E8 8007CEE8 00000000 */   nop
    /* 146EC 8007CEEC A8F3010C */  jal        func_8007CEA0
    /* 146F0 8007CEF0 21200002 */   addu      $a0, $s0, $zero
  .L8007CEF4:
    /* 146F4 8007CEF4 01001026 */  addiu      $s0, $s0, 0x1
    /* 146F8 8007CEF8 1000022A */  slti       $v0, $s0, 0x10
    /* 146FC 8007CEFC F7FF4014 */  bnez       $v0, .L8007CEDC
    /* 14700 8007CF00 04003126 */   addiu     $s1, $s1, 0x4
    /* 14704 8007CF04 1800BF8F */  lw         $ra, 0x18($sp)
    /* 14708 8007CF08 1400B18F */  lw         $s1, 0x14($sp)
    /* 1470C 8007CF0C 1000B08F */  lw         $s0, 0x10($sp)
    /* 14710 8007CF10 0800E003 */  jr         $ra
    /* 14714 8007CF14 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8007CEC0
