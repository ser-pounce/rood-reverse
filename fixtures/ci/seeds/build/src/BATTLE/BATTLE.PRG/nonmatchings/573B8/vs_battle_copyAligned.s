/* Handwritten function */
nonmatching vs_battle_copyAligned, 0x20

glabel vs_battle_copyAligned
    /* 579C0 800C01C0 0700C830 */  andi       $t0, $a2, 0x7
    /* 579C4 800C01C4 06000011 */  beqz       $t0, vs_battle_memcpy
    /* 579C8 800C01C8 0000A884 */   lh        $t0, 0x0($a1)
    /* 579CC 800C01CC 0200A524 */  addiu      $a1, $a1, 0x2
    /* 579D0 800C01D0 000088A4 */  sh         $t0, 0x0($a0)
    /* 579D4 800C01D4 02008424 */  addiu      $a0, $a0, 0x2
    /* 579D8 800C01D8 70000308 */  j          vs_battle_copyAligned
    /* 579DC 800C01DC FEFFC620 */   addi      $a2, $a2, -0x2 /* handwritten instruction */
endlabel vs_battle_copyAligned
