nonmatching func_800B8590, 0x7C

glabel func_800B8590
    /* 4FD90 800B8590 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 4FD94 800B8594 1800B0AF */  sw         $s0, 0x18($sp)
    /* 4FD98 800B8598 21808000 */  addu       $s0, $a0, $zero
    /* 4FD9C 800B859C 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 4FDA0 800B85A0 80FF020C */  jal        vs_battle_getShort
    /* 4FDA4 800B85A4 03000426 */   addiu     $a0, $s0, 0x3
    /* 4FDA8 800B85A8 05000426 */  addiu      $a0, $s0, 0x5
    /* 4FDAC 800B85AC 80FF020C */  jal        vs_battle_getShort
    /* 4FDB0 800B85B0 1000A2A7 */   sh        $v0, 0x10($sp)
    /* 4FDB4 800B85B4 07000426 */  addiu      $a0, $s0, 0x7
    /* 4FDB8 800B85B8 80FF020C */  jal        vs_battle_getShort
    /* 4FDBC 800B85BC 1200A2A7 */   sh        $v0, 0x12($sp)
    /* 4FDC0 800B85C0 01000426 */  addiu      $a0, $s0, 0x1
    /* 4FDC4 800B85C4 80FF020C */  jal        vs_battle_getShort
    /* 4FDC8 800B85C8 1400A2A7 */   sh        $v0, 0x14($sp)
    /* 4FDCC 800B85CC 94FF020C */  jal        func_800BFE50
    /* 4FDD0 800B85D0 FFFF4430 */   andi      $a0, $v0, 0xFFFF
    /* 4FDD4 800B85D4 09000392 */  lbu        $v1, 0x9($s0)
    /* 4FDD8 800B85D8 00000000 */  nop
    /* 4FDDC 800B85DC 02006010 */  beqz       $v1, .L800B85E8
    /* 4FDE0 800B85E0 00100724 */   addiu     $a3, $zero, 0x1000
    /* 4FDE4 800B85E4 21386000 */  addu       $a3, $v1, $zero
  .L800B85E8:
    /* 4FDE8 800B85E8 21204000 */  addu       $a0, $v0, $zero
    /* 4FDEC 800B85EC FFFF0524 */  addiu      $a1, $zero, -0x1
    /* 4FDF0 800B85F0 187F020C */  jal        func_8009FC60
    /* 4FDF4 800B85F4 1000A627 */   addiu     $a2, $sp, 0x10
    /* 4FDF8 800B85F8 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 4FDFC 800B85FC 1800B08F */  lw         $s0, 0x18($sp)
    /* 4FE00 800B8600 21100000 */  addu       $v0, $zero, $zero
    /* 4FE04 800B8604 0800E003 */  jr         $ra
    /* 4FE08 800B8608 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_800B8590
