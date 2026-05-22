nonmatching func_800C9F98, 0x50

glabel func_800C9F98
    /* 61798 800C9F98 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 6179C 800C9F9C 21188000 */  addu       $v1, $a0, $zero
    /* 617A0 800C9FA0 0600063C */  lui        $a2, (0x60006 >> 16)
    /* 617A4 800C9FA4 0600C634 */  ori        $a2, $a2, (0x60006 & 0xFFFF)
    /* 617A8 800C9FA8 801F023C */  lui        $v0, (0x1F800008 >> 16)
    /* 617AC 800C9FAC 2120A000 */  addu       $a0, $a1, $zero
    /* 617B0 800C9FB0 0800478C */  lw         $a3, (0x1F800008 & 0xFFFF)($v0)
    /* 617B4 800C9FB4 1000BFAF */  sw         $ra, 0x10($sp)
    /* 617B8 800C9FB8 8900030C */  jal        func_800C0224
    /* 617BC 800C9FBC 21286000 */   addu      $a1, $v1, $zero
    /* 617C0 800C9FC0 00E1043C */  lui        $a0, (0xE1000017 >> 16)
    /* 617C4 800C9FC4 17008434 */  ori        $a0, $a0, (0xE1000017 & 0xFFFF)
    /* 617C8 800C9FC8 3D37033C */  lui        $v1, (0x373D80C0 >> 16)
    /* 617CC 800C9FCC C0806334 */  ori        $v1, $v1, (0x373D80C0 & 0xFFFF)
    /* 617D0 800C9FD0 040044AC */  sw         $a0, 0x4($v0)
    /* 617D4 800C9FD4 100043AC */  sw         $v1, 0x10($v0)
    /* 617D8 800C9FD8 1000BF8F */  lw         $ra, 0x10($sp)
    /* 617DC 800C9FDC 00000000 */  nop
    /* 617E0 800C9FE0 0800E003 */  jr         $ra
    /* 617E4 800C9FE4 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800C9F98
