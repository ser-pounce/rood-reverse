nonmatching func_800A0BA0, 0x40

glabel func_800A0BA0
    /* 383A0 800A0BA0 0F80023C */  lui        $v0, %hi(D_800F4538)
    /* 383A4 800A0BA4 38454224 */  addiu      $v0, $v0, %lo(D_800F4538)
    /* 383A8 800A0BA8 80200400 */  sll        $a0, $a0, 2
    /* 383AC 800A0BAC 21208200 */  addu       $a0, $a0, $v0
    /* 383B0 800A0BB0 0000848C */  lw         $a0, 0x0($a0)
    /* 383B4 800A0BB4 00000000 */  nop
    /* 383B8 800A0BB8 07008010 */  beqz       $a0, .L800A0BD8
    /* 383BC 800A0BBC 00000000 */   nop
    /* 383C0 800A0BC0 C2058294 */  lhu        $v0, 0x5C2($a0)
    /* 383C4 800A0BC4 00000000 */  nop
    /* 383C8 800A0BC8 0000A2AC */  sw         $v0, 0x0($a1)
    /* 383CC 800A0BCC C0058294 */  lhu        $v0, 0x5C0($a0)
    /* 383D0 800A0BD0 00000000 */  nop
    /* 383D4 800A0BD4 0000C2AC */  sw         $v0, 0x0($a2)
  .L800A0BD8:
    /* 383D8 800A0BD8 0800E003 */  jr         $ra
    /* 383DC 800A0BDC 00000000 */   nop
endlabel func_800A0BA0
