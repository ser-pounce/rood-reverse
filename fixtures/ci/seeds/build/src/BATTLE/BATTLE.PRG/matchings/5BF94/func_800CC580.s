nonmatching func_800CC580, 0x40

glabel func_800CC580
    /* 63D80 800CC580 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 63D84 800CC584 2138A000 */  addu       $a3, $a1, $zero
    /* 63D88 800CC588 07E4033C */  lui        $v1, (0xE407FC00 >> 16)
    /* 63D8C 800CC58C 00FC6334 */  ori        $v1, $v1, (0xE407FC00 & 0xFFFF)
    /* 63D90 800CC590 04E3053C */  lui        $a1, (0xE3040000 >> 16)
    /* 63D94 800CC594 3F00E624 */  addiu      $a2, $a3, 0x3F
    /* 63D98 800CC598 08E5023C */  lui        $v0, (0xE5080000 >> 16)
    /* 63D9C 800CC59C 2528E500 */  or         $a1, $a3, $a1
    /* 63DA0 800CC5A0 2530C300 */  or         $a2, $a2, $v1
    /* 63DA4 800CC5A4 1000BFAF */  sw         $ra, 0x10($sp)
    /* 63DA8 800CC5A8 2E33030C */  jal        func_800CCCB8
    /* 63DAC 800CC5AC 2538E200 */   or        $a3, $a3, $v0
    /* 63DB0 800CC5B0 1000BF8F */  lw         $ra, 0x10($sp)
    /* 63DB4 800CC5B4 00000000 */  nop
    /* 63DB8 800CC5B8 0800E003 */  jr         $ra
    /* 63DBC 800CC5BC 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800CC580
