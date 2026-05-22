nonmatching vs_battle_memcpy, 0x34

glabel vs_battle_memcpy
    /* 579E0 800C01E0 2130A600 */  addu       $a2, $a1, $a2
  .L800C01E4:
    /* 579E4 800C01E4 0000A884 */  lh         $t0, 0x0($a1)
    /* 579E8 800C01E8 0200A984 */  lh         $t1, 0x2($a1)
    /* 579EC 800C01EC 0400AA84 */  lh         $t2, 0x4($a1)
    /* 579F0 800C01F0 0600AB84 */  lh         $t3, 0x6($a1)
    /* 579F4 800C01F4 0800A524 */  addiu      $a1, $a1, 0x8
    /* 579F8 800C01F8 000088A4 */  sh         $t0, 0x0($a0)
    /* 579FC 800C01FC 020089A4 */  sh         $t1, 0x2($a0)
    /* 57A00 800C0200 04008AA4 */  sh         $t2, 0x4($a0)
    /* 57A04 800C0204 06008BA4 */  sh         $t3, 0x6($a0)
    /* 57A08 800C0208 F6FFA614 */  bne        $a1, $a2, .L800C01E4
    /* 57A0C 800C020C 08008424 */   addiu     $a0, $a0, 0x8
    /* 57A10 800C0210 0800E003 */  jr         $ra
endlabel vs_battle_memcpy
