nonmatching func_8007C088, 0x24

glabel func_8007C088
    /* 13888 8007C088 0F80023C */  lui        $v0, %hi(vs_battle_actors)
    /* 1388C 8007C08C 28194224 */  addiu      $v0, $v0, %lo(vs_battle_actors)
    /* 13890 8007C090 80200400 */  sll        $a0, $a0, 2
    /* 13894 8007C094 21208200 */  addu       $a0, $a0, $v0
    /* 13898 8007C098 0000828C */  lw         $v0, 0x0($a0)
    /* 1389C 8007C09C 00000000 */  nop
    /* 138A0 8007C0A0 2000428C */  lw         $v0, 0x20($v0)
    /* 138A4 8007C0A4 0800E003 */  jr         $ra
    /* 138A8 8007C0A8 01004230 */   andi      $v0, $v0, 0x1
endlabel func_8007C088
