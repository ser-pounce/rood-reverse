nonmatching _fileMenuElementsActive, 0x3C

glabel _fileMenuElementsActive
    /* 27BC 8006AFBC 21180000 */  addu       $v1, $zero, $zero
    /* 27C0 8006AFC0 0E80023C */  lui        $v0, %hi(_fileMenuElements)
    /* 27C4 8006AFC4 18EB4424 */  addiu      $a0, $v0, %lo(_fileMenuElements)
  .L8006AFC8:
    /* 27C8 8006AFC8 00008290 */  lbu        $v0, 0x0($a0)
    /* 27CC 8006AFCC 00000000 */  nop
    /* 27D0 8006AFD0 0200422C */  sltiu      $v0, $v0, 0x2
    /* 27D4 8006AFD4 06004010 */  beqz       $v0, .L8006AFF0
    /* 27D8 8006AFD8 0A006238 */   xori      $v0, $v1, 0xA
    /* 27DC 8006AFDC 01006324 */  addiu      $v1, $v1, 0x1
    /* 27E0 8006AFE0 0A006228 */  slti       $v0, $v1, 0xA
    /* 27E4 8006AFE4 F8FF4014 */  bnez       $v0, .L8006AFC8
    /* 27E8 8006AFE8 34008424 */   addiu     $a0, $a0, 0x34
    /* 27EC 8006AFEC 0A006238 */  xori       $v0, $v1, 0xA
  .L8006AFF0:
    /* 27F0 8006AFF0 0800E003 */  jr         $ra
    /* 27F4 8006AFF4 0100422C */   sltiu     $v0, $v0, 0x1
endlabel _fileMenuElementsActive
