nonmatching vs_main_freeCdQueueSlot, 0x44

glabel vs_main_freeCdQueueSlot
    /* 35380 80044B80 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 35384 80044B84 1000B0AF */  sw         $s0, 0x10($sp)
    /* 35388 80044B88 21808000 */  addu       $s0, $a0, $zero
    /* 3538C 80044B8C 1400BFAF */  sw         $ra, 0x14($sp)
    /* 35390 80044B90 00000296 */  lhu        $v0, 0x0($s0)
    /* 35394 80044B94 00000000 */  nop
    /* 35398 80044B98 FEFF4224 */  addiu      $v0, $v0, -0x2
    /* 3539C 80044B9C 0200422C */  sltiu      $v0, $v0, 0x2
    /* 353A0 80044BA0 03004010 */  beqz       $v0, .L80044BB0
    /* 353A4 80044BA4 A3000424 */   addiu     $a0, $zero, 0xA3
    /* 353A8 80044BA8 2624010C */  jal        vs_main_nop9
    /* 353AC 80044BAC 21280000 */   addu      $a1, $zero, $zero
  .L80044BB0:
    /* 353B0 80044BB0 000000A6 */  sh         $zero, 0x0($s0)
    /* 353B4 80044BB4 1400BF8F */  lw         $ra, 0x14($sp)
    /* 353B8 80044BB8 1000B08F */  lw         $s0, 0x10($sp)
    /* 353BC 80044BBC 0800E003 */  jr         $ra
    /* 353C0 80044BC0 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel vs_main_freeCdQueueSlot
