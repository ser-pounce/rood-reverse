nonmatching func_8007ACA0, 0x10

glabel func_8007ACA0
    /* 124A0 8007ACA0 801F023C */  lui        $v0, (0x1F80005C >> 16)
    /* 124A4 8007ACA4 5C00428C */  lw         $v0, (0x1F80005C & 0xFFFF)($v0)
    /* 124A8 8007ACA8 0800E003 */  jr         $ra
    /* 124AC 8007ACAC FF0F4230 */   andi      $v0, $v0, 0xFFF
endlabel func_8007ACA0
