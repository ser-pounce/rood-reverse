nonmatching Sound_CopyInstrumentInfoToChannel, 0x34

glabel Sound_CopyInstrumentInfoToChannel
    /* B860 8001B060 FC0086AC */  sw         $a2, 0xFC($a0)
    /* B864 8001B064 0400A28C */  lw         $v0, 0x4($a1)
    /* B868 8001B068 0100063C */  lui        $a2, (0x1FF80 >> 16)
    /* B86C 8001B06C 000182AC */  sw         $v0, 0x100($a0)
    /* B870 8001B070 0C00A294 */  lhu        $v0, 0xC($a1)
    /* B874 8001B074 80FFC634 */  ori        $a2, $a2, (0x1FF80 & 0xFFFF)
    /* B878 8001B078 060182A4 */  sh         $v0, 0x106($a0)
    /* B87C 8001B07C F800828C */  lw         $v0, 0xF8($a0)
    /* B880 8001B080 0E00A394 */  lhu        $v1, 0xE($a1)
    /* B884 8001B084 25104600 */  or         $v0, $v0, $a2
    /* B888 8001B088 F80082AC */  sw         $v0, 0xF8($a0)
    /* B88C 8001B08C 0800E003 */  jr         $ra
    /* B890 8001B090 080183A4 */   sh        $v1, 0x108($a0)
endlabel Sound_CopyInstrumentInfoToChannel
