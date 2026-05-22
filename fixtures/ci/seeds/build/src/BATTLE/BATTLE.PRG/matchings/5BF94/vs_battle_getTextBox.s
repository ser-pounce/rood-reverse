nonmatching vs_battle_getTextBox, 0x1C

glabel vs_battle_getTextBox
    /* 645F4 800CCDF4 40180400 */  sll        $v1, $a0, 1
    /* 645F8 800CCDF8 21186400 */  addu       $v1, $v1, $a0
    /* 645FC 800CCDFC 00190300 */  sll        $v1, $v1, 4
    /* 64600 800CCE00 0F80023C */  lui        $v0, %hi(vs_battle_textBoxes)
    /* 64604 800CCE04 E04F4224 */  addiu      $v0, $v0, %lo(vs_battle_textBoxes)
    /* 64608 800CCE08 0800E003 */  jr         $ra
    /* 6460C 800CCE0C 21106200 */   addu      $v0, $v1, $v0
endlabel vs_battle_getTextBox
