nonmatching vs_main_transformClutSlot, 0x50

glabel vs_main_transformClutSlot
    /* 37A80 80047280 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 37A84 80047284 0580023C */  lui        $v0, %hi(_clutState + 0x2)
    /* 37A88 80047288 3000A38F */  lw         $v1, 0x30($sp)
    /* 37A8C 8004728C 5A5D4294 */  lhu        $v0, %lo(_clutState + 0x2)($v0)
    /* 37A90 80047290 3400A88F */  lw         $t0, 0x34($sp)
    /* 37A94 80047294 0A004010 */  beqz       $v0, .L800472C0
    /* 37A98 80047298 1800BFAF */   sw        $ra, 0x18($sp)
    /* 37A9C 8004729C 00140300 */  sll        $v0, $v1, 16
    /* 37AA0 800472A0 03140200 */  sra        $v0, $v0, 16
    /* 37AA4 800472A4 1000A2AF */  sw         $v0, 0x10($sp)
    /* 37AA8 800472A8 00140800 */  sll        $v0, $t0, 16
    /* 37AAC 800472AC 03140200 */  sra        $v0, $v0, 16
    /* 37AB0 800472B0 003C0700 */  sll        $a3, $a3, 16
    /* 37AB4 800472B4 033C0700 */  sra        $a3, $a3, 16
    /* 37AB8 800472B8 701B010C */  jal        _transformClutSlot
    /* 37ABC 800472BC 1400A2AF */   sw        $v0, 0x14($sp)
  .L800472C0:
    /* 37AC0 800472C0 1800BF8F */  lw         $ra, 0x18($sp)
    /* 37AC4 800472C4 00000000 */  nop
    /* 37AC8 800472C8 0800E003 */  jr         $ra
    /* 37ACC 800472CC 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel vs_main_transformClutSlot
