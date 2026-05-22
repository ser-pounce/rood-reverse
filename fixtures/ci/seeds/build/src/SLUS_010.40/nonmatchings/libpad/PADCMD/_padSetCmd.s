nonmatching _padSetCmd, 0x10

glabel _padSetCmd
    /* 1D2A0 8002CAA0 370085A0 */  sb         $a1, 0x37($a0)
    /* 1D2A4 8002CAA4 2C0086AC */  sw         $a2, 0x2C($a0)
    /* 1D2A8 8002CAA8 0800E003 */  jr         $ra
    /* 1D2AC 8002CAAC 360087A0 */   sb        $a3, 0x36($a0)
endlabel _padSetCmd
