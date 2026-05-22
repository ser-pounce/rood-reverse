nonmatching vs_battle_renderTextRaw, 0x28

glabel vs_battle_renderTextRaw
    /* 5E028 800C6828 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 5E02C 800C682C 2138C000 */  addu       $a3, $a2, $zero
    /* 5E030 800C6830 8000063C */  lui        $a2, (0x808080 >> 16)
    /* 5E034 800C6834 1000BFAF */  sw         $ra, 0x10($sp)
    /* 5E038 800C6838 5019030C */  jal        vs_battle_renderTextRawColor
    /* 5E03C 800C683C 8080C634 */   ori       $a2, $a2, (0x808080 & 0xFFFF)
    /* 5E040 800C6840 1000BF8F */  lw         $ra, 0x10($sp)
    /* 5E044 800C6844 00000000 */  nop
    /* 5E048 800C6848 0800E003 */  jr         $ra
    /* 5E04C 800C684C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel vs_battle_renderTextRaw
