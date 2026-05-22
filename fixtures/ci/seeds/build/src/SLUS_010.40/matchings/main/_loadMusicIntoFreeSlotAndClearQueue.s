nonmatching _loadMusicIntoFreeSlotAndClearQueue, 0x4C

glabel _loadMusicIntoFreeSlotAndClearQueue
    /* 35BF4 800453F4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 35BF8 800453F8 1400BFAF */  sw         $ra, 0x14($sp)
    /* 35BFC 800453FC 9C14010C */  jal        _loadMusicIntoFreeSlot
    /* 35C00 80045400 1000B0AF */   sw        $s0, 0x10($sp)
    /* 35C04 80045404 21804000 */  addu       $s0, $v0, $zero
    /* 35C08 80045408 09000012 */  beqz       $s0, .L80045430
    /* 35C0C 8004540C 21100002 */   addu      $v0, $s0, $zero
  .L80045410:
    /* 35C10 80045410 D414010C */  jal        vs_main_clearMusicLoadQueue
    /* 35C14 80045414 00000000 */   nop
    /* 35C18 80045418 05004010 */  beqz       $v0, .L80045430
    /* 35C1C 8004541C 21100002 */   addu      $v0, $s0, $zero
    /* 35C20 80045420 8709010C */  jal        vs_main_gametimeUpdate
    /* 35C24 80045424 21200000 */   addu      $a0, $zero, $zero
    /* 35C28 80045428 04150108 */  j          .L80045410
    /* 35C2C 8004542C 00000000 */   nop
  .L80045430:
    /* 35C30 80045430 1400BF8F */  lw         $ra, 0x14($sp)
    /* 35C34 80045434 1000B08F */  lw         $s0, 0x10($sp)
    /* 35C38 80045438 0800E003 */  jr         $ra
    /* 35C3C 8004543C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel _loadMusicIntoFreeSlotAndClearQueue
