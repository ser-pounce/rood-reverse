nonmatching func_800A01C8, 0x3C

glabel func_800A01C8
    /* 379C8 800A01C8 0F80023C */  lui        $v0, %hi(D_800F4538)
    /* 379CC 800A01CC 38454224 */  addiu      $v0, $v0, %lo(D_800F4538)
    /* 379D0 800A01D0 80200400 */  sll        $a0, $a0, 2
    /* 379D4 800A01D4 21208200 */  addu       $a0, $a0, $v0
    /* 379D8 800A01D8 0000848C */  lw         $a0, 0x0($a0)
    /* 379DC 800A01DC 00000000 */  nop
    /* 379E0 800A01E0 05008010 */  beqz       $a0, .L800A01F8
    /* 379E4 800A01E4 21100000 */   addu      $v0, $zero, $zero
    /* 379E8 800A01E8 E00685A0 */  sb         $a1, 0x6E0($a0)
    /* 379EC 800A01EC E10686A0 */  sb         $a2, 0x6E1($a0)
    /* 379F0 800A01F0 7F800208 */  j          .L800A01FC
    /* 379F4 800A01F4 E20687A0 */   sb        $a3, 0x6E2($a0)
  .L800A01F8:
    /* 379F8 800A01F8 FFFF0224 */  addiu      $v0, $zero, -0x1
  .L800A01FC:
    /* 379FC 800A01FC 0800E003 */  jr         $ra
    /* 37A00 800A0200 00000000 */   nop
endlabel func_800A01C8
