nonmatching Sound_FindFreeVoice, 0x68

glabel Sound_FindFreeVoice
    /* 5508 80014D08 05008014 */  bnez       $a0, .L80014D20
    /* 550C 80014D0C 21200000 */   addu      $a0, $zero, $zero
    /* 5510 80014D10 0380023C */  lui        $v0, %hi(g_pActiveMusicConfig)
    /* 5514 80014D14 2078428C */  lw         $v0, %lo(g_pActiveMusicConfig)($v0)
    /* 5518 80014D18 00000000 */  nop
    /* 551C 80014D1C 4800448C */  lw         $a0, 0x48($v0)
  .L80014D20:
    /* 5520 80014D20 00000000 */  nop
    /* 5524 80014D24 C0100400 */  sll        $v0, $a0, 3
    /* 5528 80014D28 0380033C */  lui        $v1, %hi(g_SpuVoiceInfo)
    /* 552C 80014D2C 30666324 */  addiu      $v1, $v1, %lo(g_SpuVoiceInfo)
    /* 5530 80014D30 21184300 */  addu       $v1, $v0, $v1
    /* 5534 80014D34 04006284 */  lh         $v0, 0x4($v1)
    /* 5538 80014D38 00000000 */  nop
    /* 553C 80014D3C 0A004010 */  beqz       $v0, .L80014D68
    /* 5540 80014D40 00000000 */   nop
    /* 5544 80014D44 01008424 */  addiu      $a0, $a0, 0x1
  .L80014D48:
    /* 5548 80014D48 18008228 */  slti       $v0, $a0, 0x18
    /* 554C 80014D4C 06004010 */  beqz       $v0, .L80014D68
    /* 5550 80014D50 08006324 */   addiu     $v1, $v1, 0x8
    /* 5554 80014D54 04006284 */  lh         $v0, 0x4($v1)
    /* 5558 80014D58 00000000 */  nop
    /* 555C 80014D5C FAFF4014 */  bnez       $v0, .L80014D48
    /* 5560 80014D60 01008424 */   addiu     $a0, $a0, 0x1
    /* 5564 80014D64 FFFF8424 */  addiu      $a0, $a0, -0x1
  .L80014D68:
    /* 5568 80014D68 0800E003 */  jr         $ra
    /* 556C 80014D6C 21108000 */   addu      $v0, $a0, $zero
endlabel Sound_FindFreeVoice
