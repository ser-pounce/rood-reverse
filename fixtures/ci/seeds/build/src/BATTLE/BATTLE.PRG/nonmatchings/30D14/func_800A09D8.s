nonmatching func_800A09D8, 0x44

glabel func_800A09D8
    /* 381D8 800A09D8 0F80023C */  lui        $v0, %hi(D_800F4538)
    /* 381DC 800A09DC 38454224 */  addiu      $v0, $v0, %lo(D_800F4538)
    /* 381E0 800A09E0 80200400 */  sll        $a0, $a0, 2
    /* 381E4 800A09E4 21208200 */  addu       $a0, $a0, $v0
    /* 381E8 800A09E8 0000848C */  lw         $a0, 0x0($a0)
    /* 381EC 800A09EC 00000000 */  nop
    /* 381F0 800A09F0 08008010 */  beqz       $a0, .L800A0A14
    /* 381F4 800A09F4 FFFE023C */   lui       $v0, (0xFEFFFFFF >> 16)
    /* 381F8 800A09F8 AC05838C */  lw         $v1, 0x5AC($a0)
    /* 381FC 800A09FC FFFF4234 */  ori        $v0, $v0, (0xFEFFFFFF & 0xFFFF)
    /* 38200 800A0A00 24186200 */  and        $v1, $v1, $v0
    /* 38204 800A0A04 0100A230 */  andi       $v0, $a1, 0x1
    /* 38208 800A0A08 00160200 */  sll        $v0, $v0, 24
    /* 3820C 800A0A0C 25186200 */  or         $v1, $v1, $v0
    /* 38210 800A0A10 AC0583AC */  sw         $v1, 0x5AC($a0)
  .L800A0A14:
    /* 38214 800A0A14 0800E003 */  jr         $ra
    /* 38218 800A0A18 00000000 */   nop
endlabel func_800A09D8
