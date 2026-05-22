nonmatching vs_main_loadAndWaitSoundSlot, 0x40

glabel vs_main_loadAndWaitSoundSlot
    /* 3707C 8004687C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 37080 80046880 1000BFAF */  sw         $ra, 0x10($sp)
    /* 37084 80046884 DC19010C */  jal        vs_main_loadSoundFile
    /* 37088 80046888 00000000 */   nop
  .L8004688C:
    /* 3708C 8004688C E819010C */  jal        vs_main_processSoundQueue
    /* 37090 80046890 00000000 */   nop
    /* 37094 80046894 05004010 */  beqz       $v0, .L800468AC
    /* 37098 80046898 00000000 */   nop
    /* 3709C 8004689C 8709010C */  jal        vs_main_gametimeUpdate
    /* 370A0 800468A0 21200000 */   addu      $a0, $zero, $zero
    /* 370A4 800468A4 231A0108 */  j          .L8004688C
    /* 370A8 800468A8 00000000 */   nop
  .L800468AC:
    /* 370AC 800468AC 1000BF8F */  lw         $ra, 0x10($sp)
    /* 370B0 800468B0 00000000 */  nop
    /* 370B4 800468B4 0800E003 */  jr         $ra
    /* 370B8 800468B8 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel vs_main_loadAndWaitSoundSlot
