nonmatching GetClut, 0x18

glabel GetClut
    /* 1BCB4 8002B4B4 80110500 */  sll        $v0, $a1, 6
    /* 1BCB8 8002B4B8 03210400 */  sra        $a0, $a0, 4
    /* 1BCBC 8002B4BC 3F008430 */  andi       $a0, $a0, 0x3F
    /* 1BCC0 8002B4C0 25104400 */  or         $v0, $v0, $a0
    /* 1BCC4 8002B4C4 0800E003 */  jr         $ra
    /* 1BCC8 8002B4C8 FFFF4230 */   andi      $v0, $v0, 0xFFFF
endlabel GetClut
    /* 1BCCC 8002B4CC 00000000 */  nop
    /* 1BCD0 8002B4D0 00000000 */  nop
