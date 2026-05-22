nonmatching vs_overlay_getSp, 0x10

glabel vs_overlay_getSp
    /* 12A4 80010AA4 21408000 */  addu       $t0, $a0, $zero
    /* 12A8 80010AA8 00001DAD */  sw         $sp, 0x0($t0)
    /* 12AC 80010AAC 0800E003 */  jr         $ra
    /* 12B0 80010AB0 00000000 */   nop
endlabel vs_overlay_getSp
