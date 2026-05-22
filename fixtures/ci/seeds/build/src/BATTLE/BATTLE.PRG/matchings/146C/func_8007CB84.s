nonmatching func_8007CB84, 0x38

glabel func_8007CB84
    /* 14384 8007CB84 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 14388 8007CB88 07000224 */  addiu      $v0, $zero, 0x7
    /* 1438C 8007CB8C 1000A2A3 */  sb         $v0, 0x10($sp)
    /* 14390 8007CB90 01000224 */  addiu      $v0, $zero, 0x1
    /* 14394 8007CB94 1100A4A3 */  sb         $a0, 0x11($sp)
    /* 14398 8007CB98 1000A427 */  addiu      $a0, $sp, 0x10
    /* 1439C 8007CB9C 2800BFAF */  sw         $ra, 0x28($sp)
    /* 143A0 8007CBA0 1200A5A7 */  sh         $a1, 0x12($sp)
    /* 143A4 8007CBA4 7A65020C */  jal        vs_battle_populateDataSlot
    /* 143A8 8007CBA8 2000A2A3 */   sb        $v0, 0x20($sp)
    /* 143AC 8007CBAC 2800BF8F */  lw         $ra, 0x28($sp)
    /* 143B0 8007CBB0 00000000 */  nop
    /* 143B4 8007CBB4 0800E003 */  jr         $ra
    /* 143B8 8007CBB8 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel func_8007CB84
