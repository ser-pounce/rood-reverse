nonmatching _fileMenuElementsActive, 0x3C

glabel _fileMenuElementsActive
    /* 2704 80104F04 21180000 */  addu       $v1, $zero, $zero
    /* 2708 80104F08 1180023C */  lui        $v0, %hi(_fileMenuElements)
    /* 270C 80104F0C 50AE4424 */  addiu      $a0, $v0, %lo(_fileMenuElements)
  .L80104F10:
    /* 2710 80104F10 00008290 */  lbu        $v0, 0x0($a0)
    /* 2714 80104F14 00000000 */  nop
    /* 2718 80104F18 0200422C */  sltiu      $v0, $v0, 0x2
    /* 271C 80104F1C 06004010 */  beqz       $v0, .L80104F38
    /* 2720 80104F20 0A006238 */   xori      $v0, $v1, 0xA
    /* 2724 80104F24 01006324 */  addiu      $v1, $v1, 0x1
    /* 2728 80104F28 0A006228 */  slti       $v0, $v1, 0xA
    /* 272C 80104F2C F8FF4014 */  bnez       $v0, .L80104F10
    /* 2730 80104F30 34008424 */   addiu     $a0, $a0, 0x34
    /* 2734 80104F34 0A006238 */  xori       $v0, $v1, 0xA
  .L80104F38:
    /* 2738 80104F38 0800E003 */  jr         $ra
    /* 273C 80104F3C 0100422C */   sltiu     $v0, $v0, 0x1
endlabel _fileMenuElementsActive
