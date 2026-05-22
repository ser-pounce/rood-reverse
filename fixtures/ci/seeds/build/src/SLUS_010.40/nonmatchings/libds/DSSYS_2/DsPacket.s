nonmatching DsPacket, 0x34

glabel DsPacket
    /* 14578 80023D78 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 1457C 80023D7C 01000224 */  addiu      $v0, $zero, 0x1
    /* 14580 80023D80 FF008430 */  andi       $a0, $a0, 0xFF
    /* 14584 80023D84 3000A38F */  lw         $v1, 0x30($sp)
    /* 14588 80023D88 FF00C630 */  andi       $a2, $a2, 0xFF
    /* 1458C 80023D8C 1800BFAF */  sw         $ra, 0x18($sp)
    /* 14590 80023D90 1400A2AF */  sw         $v0, 0x14($sp)
    /* 14594 80023D94 6B8F000C */  jal        _DsPacket2
    /* 14598 80023D98 1000A3AF */   sw        $v1, 0x10($sp)
    /* 1459C 80023D9C 1800BF8F */  lw         $ra, 0x18($sp)
    /* 145A0 80023DA0 2000BD27 */  addiu      $sp, $sp, 0x20
    /* 145A4 80023DA4 0800E003 */  jr         $ra
    /* 145A8 80023DA8 00000000 */   nop
endlabel DsPacket
