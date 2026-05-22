nonmatching Sound_StealQuietestVoice, 0xB0

glabel Sound_StealQuietestVoice
    /* 5458 80014C58 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 545C 80014C5C 1400BFAF */  sw         $ra, 0x14($sp)
    /* 5460 80014C60 03008010 */  beqz       $a0, .L80014C70
    /* 5464 80014C64 1000B0AF */   sw        $s0, 0x10($sp)
    /* 5468 80014C68 20530008 */  j          .L80014C80
    /* 546C 80014C6C 21200000 */   addu      $a0, $zero, $zero
  .L80014C70:
    /* 5470 80014C70 0380023C */  lui        $v0, %hi(g_pActiveMusicConfig)
    /* 5474 80014C74 2078428C */  lw         $v0, %lo(g_pActiveMusicConfig)($v0)
    /* 5478 80014C78 00000000 */  nop
    /* 547C 80014C7C 4800448C */  lw         $a0, 0x48($v0)
  .L80014C80:
    /* 5480 80014C80 FF7F0624 */  addiu      $a2, $zero, 0x7FFF
    /* 5484 80014C84 18001024 */  addiu      $s0, $zero, 0x18
    /* 5488 80014C88 C0180400 */  sll        $v1, $a0, 3
    /* 548C 80014C8C 0380023C */  lui        $v0, %hi(g_SpuVoiceInfo)
    /* 5490 80014C90 30664224 */  addiu      $v0, $v0, %lo(g_SpuVoiceInfo)
    /* 5494 80014C94 21286200 */  addu       $a1, $v1, $v0
  .L80014C98:
    /* 5498 80014C98 00140600 */  sll        $v0, $a2, 16
    /* 549C 80014C9C 0400A384 */  lh         $v1, 0x4($a1)
    /* 54A0 80014CA0 03140200 */  sra        $v0, $v0, 16
    /* 54A4 80014CA4 2A186200 */  slt        $v1, $v1, $v0
    /* 54A8 80014CA8 0400A294 */  lhu        $v0, 0x4($a1)
    /* 54AC 80014CAC 03006010 */  beqz       $v1, .L80014CBC
    /* 54B0 80014CB0 00000000 */   nop
    /* 54B4 80014CB4 21304000 */  addu       $a2, $v0, $zero
    /* 54B8 80014CB8 21808000 */  addu       $s0, $a0, $zero
  .L80014CBC:
    /* 54BC 80014CBC 01008424 */  addiu      $a0, $a0, 0x1
    /* 54C0 80014CC0 18008228 */  slti       $v0, $a0, 0x18
    /* 54C4 80014CC4 F4FF4014 */  bnez       $v0, .L80014C98
    /* 54C8 80014CC8 0800A524 */   addiu     $a1, $a1, 0x8
    /* 54CC 80014CCC 00140600 */  sll        $v0, $a2, 16
    /* 54D0 80014CD0 03140200 */  sra        $v0, $v0, 16
    /* 54D4 80014CD4 FF7F0324 */  addiu      $v1, $zero, 0x7FFF
    /* 54D8 80014CD8 06004310 */  beq        $v0, $v1, .L80014CF4
    /* 54DC 80014CDC 0380043C */   lui       $a0, %hi(g_ActiveMusicChannels)
    /* 54E0 80014CE0 90368424 */  addiu      $a0, $a0, %lo(g_ActiveMusicChannels)
    /* 54E4 80014CE4 EF53000C */  jal        UnassignVoicesFromChannels
    /* 54E8 80014CE8 21280002 */   addu      $a1, $s0, $zero
    /* 54EC 80014CEC 3E530008 */  j          .L80014CF8
    /* 54F0 80014CF0 21100002 */   addu      $v0, $s0, $zero
  .L80014CF4:
    /* 54F4 80014CF4 18000224 */  addiu      $v0, $zero, 0x18
  .L80014CF8:
    /* 54F8 80014CF8 1400BF8F */  lw         $ra, 0x14($sp)
    /* 54FC 80014CFC 1000B08F */  lw         $s0, 0x10($sp)
    /* 5500 80014D00 0800E003 */  jr         $ra
    /* 5504 80014D04 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Sound_StealQuietestVoice
