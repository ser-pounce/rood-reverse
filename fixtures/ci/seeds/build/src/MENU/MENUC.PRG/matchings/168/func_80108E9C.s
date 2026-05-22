nonmatching func_80108E9C, 0x28

glabel func_80108E9C
    /* 669C 80108E9C 0F000224 */  addiu      $v0, $zero, 0xF
    /* 66A0 80108EA0 090082A0 */  sb         $v0, 0x9($a0)
    /* 66A4 80108EA4 2800A290 */  lbu        $v0, 0x28($a1)
    /* 66A8 80108EA8 00000000 */  nop
    /* 66AC 80108EAC 0C0082A0 */  sb         $v0, 0xC($a0)
    /* 66B0 80108EB0 0100A290 */  lbu        $v0, 0x1($a1)
    /* 66B4 80108EB4 00000000 */  nop
    /* 66B8 80108EB8 2B100200 */  sltu       $v0, $zero, $v0
    /* 66BC 80108EBC 0800E003 */  jr         $ra
    /* 66C0 80108EC0 0D0082A0 */   sb        $v0, 0xD($a0)
endlabel func_80108E9C
