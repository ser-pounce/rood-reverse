nonmatching Sound_Cutscene_LoadNextBuffer, 0x14C

glabel Sound_Cutscene_LoadNextBuffer
    /* DC38 8001D438 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* DC3C 8001D43C 1400B1AF */  sw         $s1, 0x14($sp)
    /* DC40 8001D440 21888000 */  addu       $s1, $a0, $zero
    /* DC44 8001D444 2000B4AF */  sw         $s4, 0x20($sp)
    /* DC48 8001D448 21A0A000 */  addu       $s4, $a1, $zero
    /* DC4C 8001D44C 2400B5AF */  sw         $s5, 0x24($sp)
    /* DC50 8001D450 21A8C000 */  addu       $s5, $a2, $zero
    /* DC54 8001D454 1800B2AF */  sw         $s2, 0x18($sp)
    /* DC58 8001D458 0480123C */  lui        $s2, %hi(g_Sound_Cutscene_StreamState)
    /* DC5C 8001D45C 1000B0AF */  sw         $s0, 0x10($sp)
    /* DC60 8001D460 089B5026 */  addiu      $s0, $s2, %lo(g_Sound_Cutscene_StreamState)
    /* DC64 8001D464 2800BFAF */  sw         $ra, 0x28($sp)
    /* DC68 8001D468 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* DC6C 8001D46C 0C00028E */  lw         $v0, 0xC($s0)
    /* DC70 8001D470 00000000 */  nop
    /* DC74 8001D474 3A004010 */  beqz       $v0, .L8001D560
    /* DC78 8001D478 2198E000 */   addu      $s3, $a3, $zero
    /* DC7C 8001D47C 1400028E */  lw         $v0, 0x14($s0)
    /* DC80 8001D480 00000000 */  nop
    /* DC84 8001D484 36004010 */  beqz       $v0, .L8001D560
    /* DC88 8001D488 00000000 */   nop
    /* DC8C 8001D48C F17A000C */  jal        SpuSetTransferStartAddr
    /* DC90 8001D490 00000000 */   nop
    /* DC94 8001D494 284D000C */  jal        spuSetTransferCallback
    /* DC98 8001D498 00000000 */   nop
    /* DC9C 8001D49C 089B448E */  lw         $a0, %lo(g_Sound_Cutscene_StreamState)($s2)
    /* DCA0 8001D4A0 D97A000C */  jal        SpuWrite
    /* DCA4 8001D4A4 2128A002 */   addu      $a1, $s5, $zero
    /* DCA8 8001D4A8 457A000C */  jal        SpuSetIRQ
    /* DCAC 8001D4AC 21200000 */   addu      $a0, $zero, $zero
    /* DCB0 8001D4B0 1400028E */  lw         $v0, 0x14($s0)
    /* DCB4 8001D4B4 00000000 */  nop
    /* DCB8 8001D4B8 0108422C */  sltiu      $v0, $v0, 0x801
    /* DCBC 8001D4BC 0A004014 */  bnez       $v0, .L8001D4E8
    /* DCC0 8001D4C0 00000000 */   nop
    /* DCC4 8001D4C4 A57A000C */  jal        SpuSetIRQCallback
    /* DCC8 8001D4C8 21206002 */   addu      $a0, $s3, $zero
    /* DCCC 8001D4CC 1400028E */  lw         $v0, 0x14($s0)
    /* DCD0 8001D4D0 089B438E */  lw         $v1, %lo(g_Sound_Cutscene_StreamState)($s2)
    /* DCD4 8001D4D4 00F84224 */  addiu      $v0, $v0, -0x800
    /* DCD8 8001D4D8 21187500 */  addu       $v1, $v1, $s5
    /* DCDC 8001D4DC 140002AE */  sw         $v0, 0x14($s0)
    /* DCE0 8001D4E0 4B750008 */  j          .L8001D52C
    /* DCE4 8001D4E4 089B43AE */   sw        $v1, %lo(g_Sound_Cutscene_StreamState)($s2)
  .L8001D4E8:
    /* DCE8 8001D4E8 0400028E */  lw         $v0, 0x4($s0)
    /* DCEC 8001D4EC 00000000 */  nop
    /* DCF0 8001D4F0 08004010 */  beqz       $v0, .L8001D514
    /* DCF4 8001D4F4 00000000 */   nop
    /* DCF8 8001D4F8 A57A000C */  jal        SpuSetIRQCallback
    /* DCFC 8001D4FC 21206002 */   addu      $a0, $s3, $zero
    /* DD00 8001D500 0400028E */  lw         $v0, 0x4($s0)
    /* DD04 8001D504 1C00038E */  lw         $v1, 0x1C($s0)
    /* DD08 8001D508 089B42AE */  sw         $v0, %lo(g_Sound_Cutscene_StreamState)($s2)
    /* DD0C 8001D50C 4B750008 */  j          .L8001D52C
    /* DD10 8001D510 140003AE */   sw        $v1, 0x14($s0)
  .L8001D514:
    /* DD14 8001D514 0280043C */  lui        $a0, %hi(IRQCallbackProc)
    /* DD18 8001D518 A57A000C */  jal        SpuSetIRQCallback
    /* DD1C 8001D51C 4CCD8424 */   addiu     $a0, $a0, %lo(IRQCallbackProc)
    /* DD20 8001D520 30101424 */  addiu      $s4, $zero, 0x1030
    /* DD24 8001D524 21888002 */  addu       $s1, $s4, $zero
    /* DD28 8001D528 140000AE */  sw         $zero, 0x14($s0)
  .L8001D52C:
    /* DD2C 8001D52C 0480103C */  lui        $s0, %hi(g_Sound_Cutscene_StreamState)
    /* DD30 8001D530 089B1026 */  addiu      $s0, $s0, %lo(g_Sound_Cutscene_StreamState)
    /* DD34 8001D534 1000048E */  lw         $a0, 0x10($s0)
    /* DD38 8001D538 F54E000C */  jal        SetVoiceRepeatAddr
    /* DD3C 8001D53C 21282002 */   addu      $a1, $s1, $zero
    /* DD40 8001D540 1000048E */  lw         $a0, 0x10($s0)
    /* DD44 8001D544 21288002 */  addu       $a1, $s4, $zero
    /* DD48 8001D548 F54E000C */  jal        SetVoiceRepeatAddr
    /* DD4C 8001D54C 01008424 */   addiu     $a0, $a0, 0x1
    /* DD50 8001D550 957A000C */  jal        SpuSetIRQAddr
    /* DD54 8001D554 08002426 */   addiu     $a0, $s1, 0x8
    /* DD58 8001D558 457A000C */  jal        SpuSetIRQ
    /* DD5C 8001D55C 01000424 */   addiu     $a0, $zero, 0x1
  .L8001D560:
    /* DD60 8001D560 2800BF8F */  lw         $ra, 0x28($sp)
    /* DD64 8001D564 2400B58F */  lw         $s5, 0x24($sp)
    /* DD68 8001D568 2000B48F */  lw         $s4, 0x20($sp)
    /* DD6C 8001D56C 1C00B38F */  lw         $s3, 0x1C($sp)
    /* DD70 8001D570 1800B28F */  lw         $s2, 0x18($sp)
    /* DD74 8001D574 1400B18F */  lw         $s1, 0x14($sp)
    /* DD78 8001D578 1000B08F */  lw         $s0, 0x10($sp)
    /* DD7C 8001D57C 0800E003 */  jr         $ra
    /* DD80 8001D580 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel Sound_Cutscene_LoadNextBuffer
