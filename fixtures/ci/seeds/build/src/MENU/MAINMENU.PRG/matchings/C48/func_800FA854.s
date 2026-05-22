nonmatching func_800FA854, 0x4C

glabel func_800FA854
    /* 1054 800FA854 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 1058 800FA858 1400B1AF */  sw         $s1, 0x14($sp)
    /* 105C 800FA85C 21888000 */  addu       $s1, $a0, $zero
    /* 1060 800FA860 1000B0AF */  sw         $s0, 0x10($sp)
    /* 1064 800FA864 21800000 */  addu       $s0, $zero, $zero
    /* 1068 800FA868 1800BFAF */  sw         $ra, 0x18($sp)
  .L800FA86C:
    /* 106C 800FA86C 03001112 */  beq        $s0, $s1, .L800FA87C
    /* 1070 800FA870 00000000 */   nop
    /* 1074 800FA874 04EA030C */  jal        vs_mainMenu_menuItemFlyoutLeft
    /* 1078 800FA878 21200002 */   addu      $a0, $s0, $zero
  .L800FA87C:
    /* 107C 800FA87C 01001026 */  addiu      $s0, $s0, 0x1
    /* 1080 800FA880 0800022A */  slti       $v0, $s0, 0x8
    /* 1084 800FA884 F9FF4014 */  bnez       $v0, .L800FA86C
    /* 1088 800FA888 00000000 */   nop
    /* 108C 800FA88C 1800BF8F */  lw         $ra, 0x18($sp)
    /* 1090 800FA890 1400B18F */  lw         $s1, 0x14($sp)
    /* 1094 800FA894 1000B08F */  lw         $s0, 0x10($sp)
    /* 1098 800FA898 0800E003 */  jr         $ra
    /* 109C 800FA89C 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_800FA854
