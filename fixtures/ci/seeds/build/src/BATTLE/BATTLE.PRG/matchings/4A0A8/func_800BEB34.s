nonmatching func_800BEB34, 0x68

glabel func_800BEB34
    /* 56334 800BEB34 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 56338 800BEB38 0F80023C */  lui        $v0, %hi(D_800F4BE2)
    /* 5633C 800BEB3C E24B4384 */  lh         $v1, %lo(D_800F4BE2)($v0)
    /* 56340 800BEB40 03000224 */  addiu      $v0, $zero, 0x3
    /* 56344 800BEB44 03006214 */  bne        $v1, $v0, .L800BEB54
    /* 56348 800BEB48 1000BFAF */   sw        $ra, 0x10($sp)
    /* 5634C 800BEB4C 67FF020C */  jal        func_800BFD9C
    /* 56350 800BEB50 00000000 */   nop
  .L800BEB54:
    /* 56354 800BEB54 0F80023C */  lui        $v0, %hi(_mpdClearedSection)
    /* 56358 800BEB58 AC4B448C */  lw         $a0, %lo(_mpdClearedSection)($v0)
    /* 5635C 800BEB5C 00000000 */  nop
    /* 56360 800BEB60 04008010 */  beqz       $a0, .L800BEB74
    /* 56364 800BEB64 0F80023C */   lui       $v0, %hi(_mpdRoomDoorSection)
    /* 56368 800BEB68 540F010C */  jal        vs_main_freeHeap
    /* 5636C 800BEB6C 00000000 */   nop
    /* 56370 800BEB70 0F80023C */  lui        $v0, %hi(_mpdRoomDoorSection)
  .L800BEB74:
    /* 56374 800BEB74 E84B448C */  lw         $a0, %lo(_mpdRoomDoorSection)($v0)
    /* 56378 800BEB78 00000000 */  nop
    /* 5637C 800BEB7C 03008010 */  beqz       $a0, .L800BEB8C
    /* 56380 800BEB80 00000000 */   nop
    /* 56384 800BEB84 540F010C */  jal        vs_main_freeHeap
    /* 56388 800BEB88 00000000 */   nop
  .L800BEB8C:
    /* 5638C 800BEB8C 1000BF8F */  lw         $ra, 0x10($sp)
    /* 56390 800BEB90 00000000 */  nop
    /* 56394 800BEB94 0800E003 */  jr         $ra
    /* 56398 800BEB98 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800BEB34
