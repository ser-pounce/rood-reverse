nonmatching vs_overlay_jumpToTitle, 0x10

glabel vs_overlay_jumpToTitle
    /* 12B4 80010AB4 21408000 */  addu       $t0, $a0, $zero
    /* 12B8 80010AB8 00001D8D */  lw         $sp, 0x0($t0)
    /* 12BC 80010ABC EB0A0108 */  j          func_80042BAC
    /* 12C0 80010AC0 00000000 */   nop
endlabel vs_overlay_jumpToTitle
