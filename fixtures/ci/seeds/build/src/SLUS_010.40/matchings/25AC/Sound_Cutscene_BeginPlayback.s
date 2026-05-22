nonmatching Sound_Cutscene_BeginPlayback, 0xD0

glabel Sound_Cutscene_BeginPlayback
    /* DAA0 8001D2A0 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* DAA4 8001D2A4 2000B4AF */  sw         $s4, 0x20($sp)
    /* DAA8 8001D2A8 21A08000 */  addu       $s4, $a0, $zero
    /* DAAC 8001D2AC 1800B2AF */  sw         $s2, 0x18($sp)
    /* DAB0 8001D2B0 2190A000 */  addu       $s2, $a1, $zero
    /* DAB4 8001D2B4 1400B1AF */  sw         $s1, 0x14($sp)
    /* DAB8 8001D2B8 0480113C */  lui        $s1, %hi(g_Sound_Cutscene_StreamState)
    /* DABC 8001D2BC 1000B0AF */  sw         $s0, 0x10($sp)
    /* DAC0 8001D2C0 089B3026 */  addiu      $s0, $s1, %lo(g_Sound_Cutscene_StreamState)
    /* DAC4 8001D2C4 2400BFAF */  sw         $ra, 0x24($sp)
    /* DAC8 8001D2C8 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* DACC 8001D2CC 0C00028E */  lw         $v0, 0xC($s0)
    /* DAD0 8001D2D0 00000000 */  nop
    /* DAD4 8001D2D4 1E004010 */  beqz       $v0, .L8001D350
    /* DAD8 8001D2D8 2198C000 */   addu      $s3, $a2, $zero
    /* DADC 8001D2DC 157B000C */  jal        SpuSetTransferCallback
    /* DAE0 8001D2E0 21200000 */   addu      $a0, $zero, $zero
    /* DAE4 8001D2E4 1400038E */  lw         $v1, 0x14($s0)
    /* DAE8 8001D2E8 0380023C */  lui        $v0, %hi(_isSpuTransfer)
    /* DAEC 8001D2EC F07740AC */  sw         $zero, %lo(_isSpuTransfer)($v0)
    /* DAF0 8001D2F0 0110622C */  sltiu      $v0, $v1, 0x1001
    /* DAF4 8001D2F4 09004014 */  bnez       $v0, .L8001D31C
    /* DAF8 8001D2F8 00F06324 */   addiu     $v1, $v1, -0x1000
    /* DAFC 8001D2FC 21206002 */  addu       $a0, $s3, $zero
    /* DB00 8001D300 089B228E */  lw         $v0, %lo(g_Sound_Cutscene_StreamState)($s1)
    /* DB04 8001D304 140003AE */  sw         $v1, 0x14($s0)
    /* DB08 8001D308 21105400 */  addu       $v0, $v0, $s4
    /* DB0C 8001D30C A57A000C */  jal        SpuSetIRQCallback
    /* DB10 8001D310 089B22AE */   sw        $v0, %lo(g_Sound_Cutscene_StreamState)($s1)
    /* DB14 8001D314 CC740008 */  j          .L8001D330
    /* DB18 8001D318 00000000 */   nop
  .L8001D31C:
    /* DB1C 8001D31C 0280043C */  lui        $a0, %hi(IRQCallbackProc)
    /* DB20 8001D320 A57A000C */  jal        SpuSetIRQCallback
    /* DB24 8001D324 4CCD8424 */   addiu     $a0, $a0, %lo(IRQCallbackProc)
    /* DB28 8001D328 30101224 */  addiu      $s2, $zero, 0x1030
    /* DB2C 8001D32C 140000AE */  sw         $zero, 0x14($s0)
  .L8001D330:
    /* DB30 8001D330 957A000C */  jal        SpuSetIRQAddr
    /* DB34 8001D334 08004426 */   addiu     $a0, $s2, 0x8
    /* DB38 8001D338 0480023C */  lui        $v0, %hi(D_80039B14)
    /* DB3C 8001D33C 149B448C */  lw         $a0, %lo(D_80039B14)($v0)
    /* DB40 8001D340 B34E000C */  jal        SetVoiceKeyOn
    /* DB44 8001D344 00000000 */   nop
    /* DB48 8001D348 457A000C */  jal        SpuSetIRQ
    /* DB4C 8001D34C 01000424 */   addiu     $a0, $zero, 0x1
  .L8001D350:
    /* DB50 8001D350 2400BF8F */  lw         $ra, 0x24($sp)
    /* DB54 8001D354 2000B48F */  lw         $s4, 0x20($sp)
    /* DB58 8001D358 1C00B38F */  lw         $s3, 0x1C($sp)
    /* DB5C 8001D35C 1800B28F */  lw         $s2, 0x18($sp)
    /* DB60 8001D360 1400B18F */  lw         $s1, 0x14($sp)
    /* DB64 8001D364 1000B08F */  lw         $s0, 0x10($sp)
    /* DB68 8001D368 0800E003 */  jr         $ra
    /* DB6C 8001D36C 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel Sound_Cutscene_BeginPlayback
