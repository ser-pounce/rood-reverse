nonmatching _sVectorToFixedPointVector, 0x34

glabel _sVectorToFixedPointVector
    /* 56024 800BE824 0000A384 */  lh         $v1, 0x0($a1)
    /* 56028 800BE828 21108000 */  addu       $v0, $a0, $zero
    /* 5602C 800BE82C 001B0300 */  sll        $v1, $v1, 12
    /* 56030 800BE830 000043AC */  sw         $v1, 0x0($v0)
    /* 56034 800BE834 0200A384 */  lh         $v1, 0x2($a1)
    /* 56038 800BE838 00000000 */  nop
    /* 5603C 800BE83C 001B0300 */  sll        $v1, $v1, 12
    /* 56040 800BE840 040043AC */  sw         $v1, 0x4($v0)
    /* 56044 800BE844 0400A384 */  lh         $v1, 0x4($a1)
    /* 56048 800BE848 00000000 */  nop
    /* 5604C 800BE84C 001B0300 */  sll        $v1, $v1, 12
    /* 56050 800BE850 0800E003 */  jr         $ra
    /* 56054 800BE854 080043AC */   sw        $v1, 0x8($v0)
endlabel _sVectorToFixedPointVector
