nonmatching func_800ACF54, 0x4C

glabel func_800ACF54
    /* 44754 800ACF54 21308000 */  addu       $a2, $a0, $zero
    /* 44758 800ACF58 5C00C28C */  lw         $v0, 0x5C($a2)
    /* 4475C 800ACF5C 00000000 */  nop
    /* 44760 800ACF60 6000C2AC */  sw         $v0, 0x60($a2)
    /* 44764 800ACF64 1C00C28C */  lw         $v0, 0x1C($a2)
    /* 44768 800ACF68 2000C38C */  lw         $v1, 0x20($a2)
    /* 4476C 800ACF6C 4C00C2AC */  sw         $v0, 0x4C($a2)
    /* 44770 800ACF70 5000C3AC */  sw         $v1, 0x50($a2)
    /* 44774 800ACF74 0C00C28C */  lw         $v0, 0xC($a2)
    /* 44778 800ACF78 00000000 */  nop
    /* 4477C 800ACF7C 0F004230 */  andi       $v0, $v0, 0xF
    /* 44780 800ACF80 04004014 */  bnez       $v0, .L800ACF94
    /* 44784 800ACF84 00000000 */   nop
    /* 44788 800ACF88 5C00C28C */  lw         $v0, 0x5C($a2)
    /* 4478C 800ACF8C 00000000 */  nop
    /* 44790 800ACF90 7818C2AC */  sw         $v0, 0x1878($a2)
  .L800ACF94:
    /* 44794 800ACF94 2600C294 */  lhu        $v0, 0x26($a2)
    /* 44798 800ACF98 0800E003 */  jr         $ra
    /* 4479C 800ACF9C 5200C2A4 */   sh        $v0, 0x52($a2)
endlabel func_800ACF54
