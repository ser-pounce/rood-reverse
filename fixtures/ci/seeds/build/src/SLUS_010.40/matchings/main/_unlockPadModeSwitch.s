nonmatching _unlockPadModeSwitch, 0x44

glabel _unlockPadModeSwitch
    /* 337F0 80042FF0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 337F4 80042FF4 1000BFAF */  sw         $ra, 0x10($sp)
    /* 337F8 80042FF8 F70B010C */  jal        vs_main_padDisconnectAll
    /* 337FC 80042FFC 00000000 */   nop
    /* 33800 80043000 21200000 */  addu       $a0, $zero, $zero
    /* 33804 80043004 02000524 */  addiu      $a1, $zero, 0x2
    /* 33808 80043008 57AE000C */  jal        PadInfoMode
    /* 3380C 8004300C 21308000 */   addu      $a2, $a0, $zero
    /* 33810 80043010 04004010 */  beqz       $v0, .L80043024
    /* 33814 80043014 21200000 */   addu      $a0, $zero, $zero
    /* 33818 80043018 01000524 */  addiu      $a1, $zero, 0x1
    /* 3381C 8004301C 02AF000C */  jal        PadSetMainMode
    /* 33820 80043020 02000624 */   addiu     $a2, $zero, 0x2
  .L80043024:
    /* 33824 80043024 1000BF8F */  lw         $ra, 0x10($sp)
    /* 33828 80043028 00000000 */  nop
    /* 3382C 8004302C 0800E003 */  jr         $ra
    /* 33830 80043030 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel _unlockPadModeSwitch
