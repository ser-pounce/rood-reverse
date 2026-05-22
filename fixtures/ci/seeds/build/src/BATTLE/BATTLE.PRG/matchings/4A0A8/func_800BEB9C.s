nonmatching func_800BEB9C, 0x50

glabel func_800BEB9C
    /* 5639C 800BEB9C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 563A0 800BEBA0 1400BFAF */  sw         $ra, 0x14($sp)
    /* 563A4 800BEBA4 0D008014 */  bnez       $a0, .L800BEBDC
    /* 563A8 800BEBA8 1000B0AF */   sw        $s0, 0x10($sp)
    /* 563AC 800BEBAC 40001024 */  addiu      $s0, $zero, 0x40
    /* 563B0 800BEBB0 00241000 */  sll        $a0, $s0, 16
  .L800BEBB4:
    /* 563B4 800BEBB4 03240400 */  sra        $a0, $a0, 16
    /* 563B8 800BEBB8 05FB020C */  jal        vs_battle_setStateFlag
    /* 563BC 800BEBBC 21280000 */   addu      $a1, $zero, $zero
    /* 563C0 800BEBC0 01000226 */  addiu      $v0, $s0, 0x1
    /* 563C4 800BEBC4 21804000 */  addu       $s0, $v0, $zero
    /* 563C8 800BEBC8 00140200 */  sll        $v0, $v0, 16
    /* 563CC 800BEBCC 03140200 */  sra        $v0, $v0, 16
    /* 563D0 800BEBD0 80004228 */  slti       $v0, $v0, 0x80
    /* 563D4 800BEBD4 F7FF4014 */  bnez       $v0, .L800BEBB4
    /* 563D8 800BEBD8 00241000 */   sll       $a0, $s0, 16
  .L800BEBDC:
    /* 563DC 800BEBDC 1400BF8F */  lw         $ra, 0x14($sp)
    /* 563E0 800BEBE0 1000B08F */  lw         $s0, 0x10($sp)
    /* 563E4 800BEBE4 0800E003 */  jr         $ra
    /* 563E8 800BEBE8 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800BEB9C
