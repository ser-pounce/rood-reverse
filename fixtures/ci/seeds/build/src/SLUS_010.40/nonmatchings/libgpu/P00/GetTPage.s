nonmatching GetTPage, 0x3C

glabel GetTPage
    /* 1BC74 8002B474 03008230 */  andi       $v0, $a0, 0x3
    /* 1BC78 8002B478 C0110200 */  sll        $v0, $v0, 7
    /* 1BC7C 8002B47C 0300A530 */  andi       $a1, $a1, 0x3
    /* 1BC80 8002B480 40290500 */  sll        $a1, $a1, 5
    /* 1BC84 8002B484 25104500 */  or         $v0, $v0, $a1
    /* 1BC88 8002B488 0001E330 */  andi       $v1, $a3, 0x100
    /* 1BC8C 8002B48C 03190300 */  sra        $v1, $v1, 4
    /* 1BC90 8002B490 25104300 */  or         $v0, $v0, $v1
    /* 1BC94 8002B494 FF03C630 */  andi       $a2, $a2, 0x3FF
    /* 1BC98 8002B498 83310600 */  sra        $a2, $a2, 6
    /* 1BC9C 8002B49C 25104600 */  or         $v0, $v0, $a2
    /* 1BCA0 8002B4A0 0002E730 */  andi       $a3, $a3, 0x200
    /* 1BCA4 8002B4A4 80380700 */  sll        $a3, $a3, 2
    /* 1BCA8 8002B4A8 0800E003 */  jr         $ra
    /* 1BCAC 8002B4AC 25104700 */   or        $v0, $v0, $a3
endlabel GetTPage
    /* 1BCB0 8002B4B0 00000000 */  nop
