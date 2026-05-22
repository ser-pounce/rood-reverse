nonmatching vs_battle_drawCursor, 0x68

glabel vs_battle_drawCursor
    /* 64540 800CCD40 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 64544 800CCD44 1000B0AF */  sw         $s0, 0x10($sp)
    /* 64548 800CCD48 21808000 */  addu       $s0, $a0, $zero
    /* 6454C 800CCD4C 1000063C */  lui        $a2, (0x100010 >> 16)
    /* 64550 800CCD50 1000C634 */  ori        $a2, $a2, (0x100010 & 0xFFFF)
    /* 64554 800CCD54 0F80023C */  lui        $v0, %hi(D_800EC270)
    /* 64558 800CCD58 70C24224 */  addiu      $v0, $v0, %lo(D_800EC270)
    /* 6455C 800CCD5C 21100202 */  addu       $v0, $s0, $v0
    /* 64560 800CCD60 00290500 */  sll        $a1, $a1, 4
    /* 64564 800CCD64 0A00A524 */  addiu      $a1, $a1, 0xA
    /* 64568 800CCD68 002C0500 */  sll        $a1, $a1, 16
    /* 6456C 800CCD6C 801F033C */  lui        $v1, (0x1F800008 >> 16)
    /* 64570 800CCD70 1400BFAF */  sw         $ra, 0x14($sp)
    /* 64574 800CCD74 00004490 */  lbu        $a0, 0x0($v0)
    /* 64578 800CCD78 0800678C */  lw         $a3, (0x1F800008 & 0xFFFF)($v1)
    /* 6457C 800CCD7C 8900030C */  jal        func_800C0224
    /* 64580 800CCD80 B400A534 */   ori       $a1, $a1, 0xB4
    /* 64584 800CCD84 F837033C */  lui        $v1, (0x37F83020 >> 16)
    /* 64588 800CCD88 20306334 */  ori        $v1, $v1, (0x37F83020 & 0xFFFF)
    /* 6458C 800CCD8C 01001026 */  addiu      $s0, $s0, 0x1
    /* 64590 800CCD90 100043AC */  sw         $v1, 0x10($v0)
    /* 64594 800CCD94 0F000232 */  andi       $v0, $s0, 0xF
    /* 64598 800CCD98 1400BF8F */  lw         $ra, 0x14($sp)
    /* 6459C 800CCD9C 1000B08F */  lw         $s0, 0x10($sp)
    /* 645A0 800CCDA0 0800E003 */  jr         $ra
    /* 645A4 800CCDA4 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel vs_battle_drawCursor
