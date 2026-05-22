nonmatching vs_main_loadAndWaitMusicSlot, 0x58

glabel vs_main_loadAndWaitMusicSlot
    /* 35B9C 8004539C E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 35BA0 800453A0 1000B0AF */  sw         $s0, 0x10($sp)
    /* 35BA4 800453A4 2180A000 */  addu       $s0, $a1, $zero
    /* 35BA8 800453A8 1800BFAF */  sw         $ra, 0x18($sp)
    /* 35BAC 800453AC 4414010C */  jal        vs_main_loadMusicSlot
    /* 35BB0 800453B0 1400B1AF */   sw        $s1, 0x14($sp)
    /* 35BB4 800453B4 21884000 */  addu       $s1, $v0, $zero
    /* 35BB8 800453B8 09002012 */  beqz       $s1, .L800453E0
    /* 35BBC 800453BC 21102002 */   addu      $v0, $s1, $zero
  .L800453C0:
    /* 35BC0 800453C0 B214010C */  jal        vs_main_clearMusicLoadSlot
    /* 35BC4 800453C4 21200002 */   addu      $a0, $s0, $zero
    /* 35BC8 800453C8 05004010 */  beqz       $v0, .L800453E0
    /* 35BCC 800453CC 21102002 */   addu      $v0, $s1, $zero
    /* 35BD0 800453D0 8709010C */  jal        vs_main_gametimeUpdate
    /* 35BD4 800453D4 21200000 */   addu      $a0, $zero, $zero
    /* 35BD8 800453D8 F0140108 */  j          .L800453C0
    /* 35BDC 800453DC 00000000 */   nop
  .L800453E0:
    /* 35BE0 800453E0 1800BF8F */  lw         $ra, 0x18($sp)
    /* 35BE4 800453E4 1400B18F */  lw         $s1, 0x14($sp)
    /* 35BE8 800453E8 1000B08F */  lw         $s0, 0x10($sp)
    /* 35BEC 800453EC 0800E003 */  jr         $ra
    /* 35BF0 800453F0 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel vs_main_loadAndWaitMusicSlot
