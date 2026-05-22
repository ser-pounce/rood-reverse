nonmatching vs_battle_script_setFlagIfItemInInventory, 0x54

glabel vs_battle_script_setFlagIfItemInInventory
    /* 50970 800B9170 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 50974 800B9174 1000B0AF */  sw         $s0, 0x10($sp)
    /* 50978 800B9178 21808000 */  addu       $s0, $a0, $zero
    /* 5097C 800B917C 1400BFAF */  sw         $ra, 0x14($sp)
    /* 50980 800B9180 80FF020C */  jal        vs_battle_getShort
    /* 50984 800B9184 03000426 */   addiu     $a0, $s0, 0x3
    /* 50988 800B9188 01000426 */  addiu      $a0, $s0, 0x1
    /* 5098C 800B918C 00840200 */  sll        $s0, $v0, 16
    /* 50990 800B9190 80FF020C */  jal        vs_battle_getShort
    /* 50994 800B9194 03841000 */   sra       $s0, $s0, 16
    /* 50998 800B9198 00140200 */  sll        $v0, $v0, 16
    /* 5099C 800B919C 15F9010C */  jal        vs_battle_itemIdIsInInventory
    /* 509A0 800B91A0 03240200 */   sra       $a0, $v0, 16
    /* 509A4 800B91A4 21200002 */  addu       $a0, $s0, $zero
    /* 509A8 800B91A8 05FB020C */  jal        vs_battle_setStateFlag
    /* 509AC 800B91AC FF004530 */   andi      $a1, $v0, 0xFF
    /* 509B0 800B91B0 1400BF8F */  lw         $ra, 0x14($sp)
    /* 509B4 800B91B4 1000B08F */  lw         $s0, 0x10($sp)
    /* 509B8 800B91B8 21100000 */  addu       $v0, $zero, $zero
    /* 509BC 800B91BC 0800E003 */  jr         $ra
    /* 509C0 800B91C0 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel vs_battle_script_setFlagIfItemInInventory
