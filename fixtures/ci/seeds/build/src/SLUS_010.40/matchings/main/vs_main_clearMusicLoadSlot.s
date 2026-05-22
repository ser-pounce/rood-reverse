nonmatching vs_main_clearMusicLoadSlot, 0x88

glabel vs_main_clearMusicLoadSlot
    /* 35AC8 800452C8 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 35ACC 800452CC FFFF8324 */  addiu      $v1, $a0, -0x1
    /* 35AD0 800452D0 0400622C */  sltiu      $v0, $v1, 0x4
    /* 35AD4 800452D4 1400BFAF */  sw         $ra, 0x14($sp)
    /* 35AD8 800452D8 18004010 */  beqz       $v0, .L8004533C
    /* 35ADC 800452DC 1000B0AF */   sw        $s0, 0x10($sp)
    /* 35AE0 800452E0 0680023C */  lui        $v0, %hi(vs_main_soundData)
    /* 35AE4 800452E4 38E04224 */  addiu      $v0, $v0, %lo(vs_main_soundData)
    /* 35AE8 800452E8 80180300 */  sll        $v1, $v1, 2
    /* 35AEC 800452EC 21806200 */  addu       $s0, $v1, $v0
    /* 35AF0 800452F0 3400048E */  lw         $a0, 0x34($s0)
    /* 35AF4 800452F4 00000000 */  nop
    /* 35AF8 800452F8 10008010 */  beqz       $a0, .L8004533C
    /* 35AFC 800452FC 04000224 */   addiu     $v0, $zero, 0x4
    /* 35B00 80045300 00008384 */  lh         $v1, 0x0($a0)
    /* 35B04 80045304 00000000 */  nop
    /* 35B08 80045308 05006214 */  bne        $v1, $v0, .L80045320
    /* 35B0C 8004530C 06000224 */   addiu     $v0, $zero, 0x6
    /* 35B10 80045310 E012010C */  jal        vs_main_freeCdQueueSlot
    /* 35B14 80045314 00000000 */   nop
    /* 35B18 80045318 CF140108 */  j          .L8004533C
    /* 35B1C 8004531C 340000AE */   sw        $zero, 0x34($s0)
  .L80045320:
    /* 35B20 80045320 07006214 */  bne        $v1, $v0, .L80045340
    /* 35B24 80045324 01000224 */   addiu     $v0, $zero, 0x1
    /* 35B28 80045328 E012010C */  jal        vs_main_freeCdQueueSlot
    /* 35B2C 8004532C 00000000 */   nop
    /* 35B30 80045330 FFFF0224 */  addiu      $v0, $zero, -0x1
    /* 35B34 80045334 D0140108 */  j          .L80045340
    /* 35B38 80045338 340002AE */   sw        $v0, 0x34($s0)
  .L8004533C:
    /* 35B3C 8004533C 21100000 */  addu       $v0, $zero, $zero
  .L80045340:
    /* 35B40 80045340 1400BF8F */  lw         $ra, 0x14($sp)
    /* 35B44 80045344 1000B08F */  lw         $s0, 0x10($sp)
    /* 35B48 80045348 0800E003 */  jr         $ra
    /* 35B4C 8004534C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel vs_main_clearMusicLoadSlot
