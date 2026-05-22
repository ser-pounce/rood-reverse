nonmatching func_800D5170, 0x28

glabel func_800D5170
    /* 6C970 800D5170 0A008394 */  lhu        $v1, 0xA($a0)
    /* 6C974 800D5174 00000000 */  nop
    /* 6C978 800D5178 01006224 */  addiu      $v0, $v1, 0x1
    /* 6C97C 800D517C 0A0082A4 */  sh         $v0, 0xA($a0)
    /* 6C980 800D5180 0C00828C */  lw         $v0, 0xC($a0)
    /* 6C984 800D5184 FFFF6330 */  andi       $v1, $v1, 0xFFFF
    /* 6C988 800D5188 21104300 */  addu       $v0, $v0, $v1
    /* 6C98C 800D518C 00004290 */  lbu        $v0, 0x0($v0)
    /* 6C990 800D5190 0800E003 */  jr         $ra
    /* 6C994 800D5194 00000000 */   nop
endlabel func_800D5170
