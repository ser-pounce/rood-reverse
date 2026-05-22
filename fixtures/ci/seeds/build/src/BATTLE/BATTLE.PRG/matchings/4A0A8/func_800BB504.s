nonmatching func_800BB504, 0x50

glabel func_800BB504
    /* 52D04 800BB504 01008290 */  lbu        $v0, 0x1($a0)
    /* 52D08 800BB508 00000000 */  nop
    /* 52D0C 800BB50C 03004330 */  andi       $v1, $v0, 0x3
    /* 52D10 800BB510 80004230 */  andi       $v0, $v0, 0x80
    /* 52D14 800BB514 08004014 */  bnez       $v0, .L800BB538
    /* 52D18 800BB518 FF006430 */   andi      $a0, $v1, 0xFF
    /* 52D1C 800BB51C 0F80023C */  lui        $v0, %hi(D_800F4C38)
    /* 52D20 800BB520 384C4224 */  addiu      $v0, $v0, %lo(D_800F4C38)
    /* 52D24 800BB524 80180400 */  sll        $v1, $a0, 2
    /* 52D28 800BB528 21186200 */  addu       $v1, $v1, $v0
    /* 52D2C 800BB52C 0000628C */  lw         $v0, 0x0($v1)
    /* 52D30 800BB530 0800E003 */  jr         $ra
    /* 52D34 800BB534 2B100200 */   sltu      $v0, $zero, $v0
  .L800BB538:
    /* 52D38 800BB538 0F80033C */  lui        $v1, %hi(D_800F4C38)
    /* 52D3C 800BB53C 384C6324 */  addiu      $v1, $v1, %lo(D_800F4C38)
    /* 52D40 800BB540 80100400 */  sll        $v0, $a0, 2
    /* 52D44 800BB544 21104300 */  addu       $v0, $v0, $v1
    /* 52D48 800BB548 000040AC */  sw         $zero, 0x0($v0)
    /* 52D4C 800BB54C 0800E003 */  jr         $ra
    /* 52D50 800BB550 21100000 */   addu      $v0, $zero, $zero
endlabel func_800BB504
