nonmatching vs_main_resetGame, 0xBC

glabel vs_main_resetGame
    /* 32B64 80042364 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 32B68 80042368 21200000 */  addu       $a0, $zero, $zero
    /* 32B6C 8004236C 1400BFAF */  sw         $ra, 0x14($sp)
    /* 32B70 80042370 94A1000C */  jal        DrawSync
    /* 32B74 80042374 1000B0AF */   sw        $s0, 0x10($sp)
    /* 32B78 80042378 94A1000C */  jal        DrawSync
    /* 32B7C 8004237C 21200000 */   addu      $a0, $zero, $zero
    /* 32B80 80042380 6EA1000C */  jal        SetDispMask
    /* 32B84 80042384 21200000 */   addu      $a0, $zero, $zero
  .L80042388:
    /* 32B88 80042388 09000424 */  addiu      $a0, $zero, 0x9
    /* 32B8C 8004238C 21280000 */  addu       $a1, $zero, $zero
    /* 32B90 80042390 F996000C */  jal        DsControlB
    /* 32B94 80042394 2130A000 */   addu      $a2, $a1, $zero
    /* 32B98 80042398 FBFF4010 */  beqz       $v0, .L80042388
    /* 32B9C 8004239C 00000000 */   nop
    /* 32BA0 800423A0 E890000C */  jal        DsFlush
    /* 32BA4 800423A4 0680103C */   lui       $s0, %hi(vs_main_padBuffer)
    /* 32BA8 800423A8 21200000 */  addu       $a0, $zero, $zero
    /* 32BAC 800423AC 21288000 */  addu       $a1, $a0, $zero
    /* 32BB0 800423B0 C80C010C */  jal        padSetActData
    /* 32BB4 800423B4 21308000 */   addu      $a2, $a0, $zero
    /* 32BB8 800423B8 21200000 */  addu       $a0, $zero, $zero
    /* 32BBC 800423BC 01000524 */  addiu      $a1, $zero, 0x1
    /* 32BC0 800423C0 C80C010C */  jal        padSetActData
    /* 32BC4 800423C4 21308000 */   addu      $a2, $a0, $zero
    /* 32BC8 800423C8 21200000 */  addu       $a0, $zero, $zero
    /* 32BCC 800423CC F0DF1026 */  addiu      $s0, $s0, %lo(vs_main_padBuffer)
    /* 32BD0 800423D0 940C010C */  jal        vs_main_padConnect
    /* 32BD4 800423D4 21280002 */   addu      $a1, $s0, $zero
    /* 32BD8 800423D8 10000424 */  addiu      $a0, $zero, 0x10
    /* 32BDC 800423DC 940C010C */  jal        vs_main_padConnect
    /* 32BE0 800423E0 22000526 */   addiu     $a1, $s0, 0x22
    /* 32BE4 800423E4 7347000C */  jal        TeardownSound
    /* 32BE8 800423E8 00000000 */   nop
    /* 32BEC 800423EC 8179000C */  jal        SpuQuit
    /* 32BF0 800423F0 00000000 */   nop
    /* 32BF4 800423F4 B5A0000C */  jal        ResetGraph
    /* 32BF8 800423F8 03000424 */   addiu     $a0, $zero, 0x3
    /* 32BFC 800423FC B17D000C */  jal        VSync
    /* 32C00 80042400 0A000424 */   addiu     $a0, $zero, 0xA
    /* 32C04 80042404 0580043C */  lui        $a0, %hi(sp2)
    /* 32C08 80042408 AD42000C */  jal        vs_overlay_jumpToTitle
    /* 32C0C 8004240C 74048424 */   addiu     $a0, $a0, %lo(sp2)
    /* 32C10 80042410 1400BF8F */  lw         $ra, 0x14($sp)
    /* 32C14 80042414 1000B08F */  lw         $s0, 0x10($sp)
    /* 32C18 80042418 0800E003 */  jr         $ra
    /* 32C1C 8004241C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel vs_main_resetGame
