nonmatching func_80109DBC, 0x30

glabel func_80109DBC
    /* 75BC 80109DBC 0300A290 */  lbu        $v0, 0x3($a1)
    /* 75C0 80109DC0 00000000 */  nop
    /* 75C4 80109DC4 0E004224 */  addiu      $v0, $v0, 0xE
    /* 75C8 80109DC8 090082A0 */  sb         $v0, 0x9($a0)
    /* 75CC 80109DCC 2400A290 */  lbu        $v0, 0x24($a1)
    /* 75D0 80109DD0 00000000 */  nop
    /* 75D4 80109DD4 0C0082A0 */  sb         $v0, 0xC($a0)
    /* 75D8 80109DD8 2600A290 */  lbu        $v0, 0x26($a1)
    /* 75DC 80109DDC 00000000 */  nop
    /* 75E0 80109DE0 2B100200 */  sltu       $v0, $zero, $v0
    /* 75E4 80109DE4 0800E003 */  jr         $ra
    /* 75E8 80109DE8 0D0082A0 */   sb        $v0, 0xD($a0)
endlabel func_80109DBC
