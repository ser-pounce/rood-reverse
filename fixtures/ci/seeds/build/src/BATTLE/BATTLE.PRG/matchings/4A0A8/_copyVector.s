nonmatching _copyVector, 0x24

glabel _copyVector
    /* 55F1C 800BE71C 0000A38C */  lw         $v1, 0x0($a1)
    /* 55F20 800BE720 21108000 */  addu       $v0, $a0, $zero
    /* 55F24 800BE724 000043AC */  sw         $v1, 0x0($v0)
    /* 55F28 800BE728 0400A38C */  lw         $v1, 0x4($a1)
    /* 55F2C 800BE72C 00000000 */  nop
    /* 55F30 800BE730 040043AC */  sw         $v1, 0x4($v0)
    /* 55F34 800BE734 0800A38C */  lw         $v1, 0x8($a1)
    /* 55F38 800BE738 0800E003 */  jr         $ra
    /* 55F3C 800BE73C 080043AC */   sw        $v1, 0x8($v0)
endlabel _copyVector
