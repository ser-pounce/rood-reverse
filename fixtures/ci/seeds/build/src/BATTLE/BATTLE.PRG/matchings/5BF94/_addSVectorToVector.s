nonmatching _addSVectorToVector, 0x3C

glabel _addSVectorToVector
    /* 67640 800CFE40 00008784 */  lh         $a3, 0x0($a0)
    /* 67644 800CFE44 0000A28C */  lw         $v0, 0x0($a1)
    /* 67648 800CFE48 02008384 */  lh         $v1, 0x2($a0)
    /* 6764C 800CFE4C 21104700 */  addu       $v0, $v0, $a3
    /* 67650 800CFE50 0000C2AC */  sw         $v0, 0x0($a2)
    /* 67654 800CFE54 0400A28C */  lw         $v0, 0x4($a1)
    /* 67658 800CFE58 00000000 */  nop
    /* 6765C 800CFE5C 21104300 */  addu       $v0, $v0, $v1
    /* 67660 800CFE60 0400C2AC */  sw         $v0, 0x4($a2)
    /* 67664 800CFE64 04008384 */  lh         $v1, 0x4($a0)
    /* 67668 800CFE68 0800A28C */  lw         $v0, 0x8($a1)
    /* 6766C 800CFE6C 00000000 */  nop
    /* 67670 800CFE70 21104300 */  addu       $v0, $v0, $v1
    /* 67674 800CFE74 0800E003 */  jr         $ra
    /* 67678 800CFE78 0800C2AC */   sw        $v0, 0x8($a2)
endlabel _addSVectorToVector
