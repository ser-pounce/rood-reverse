nonmatching _memcardMaskedHandler, 0xDC

glabel _memcardMaskedHandler
    /* 2A88 8006B288 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 2A8C 8006B28C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 2A90 8006B290 21808000 */  addu       $s0, $a0, $zero
    /* 2A94 8006B294 07000012 */  beqz       $s0, .L8006B2B4
    /* 2A98 8006B298 1400BFAF */   sw        $ra, 0x14($sp)
    /* 2A9C 8006B29C 1FA5010C */  jal        _memcardEventHandler
    /* 2AA0 8006B2A0 03000432 */   andi      $a0, $s0, 0x3
    /* 2AA4 8006B2A4 0E80033C */  lui        $v1, %hi(_memcardEventMask)
    /* 2AA8 8006B2A8 03111000 */  sra        $v0, $s0, 4
    /* 2AAC 8006B2AC D4AC0108 */  j          .L8006B350
    /* 2AB0 8006B2B0 CEC862A0 */   sb        $v0, %lo(_memcardEventMask)($v1)
  .L8006B2B4:
    /* 2AB4 8006B2B4 1FA5010C */  jal        _memcardEventHandler
    /* 2AB8 8006B2B8 21200000 */   addu      $a0, $zero, $zero
    /* 2ABC 8006B2BC 21184000 */  addu       $v1, $v0, $zero
    /* 2AC0 8006B2C0 23006010 */  beqz       $v1, .L8006B350
    /* 2AC4 8006B2C4 0E80023C */   lui       $v0, %hi(_memcardEventMask)
    /* 2AC8 8006B2C8 CEC84290 */  lbu        $v0, %lo(_memcardEventMask)($v0)
    /* 2ACC 8006B2CC 00000000 */  nop
    /* 2AD0 8006B2D0 24186200 */  and        $v1, $v1, $v0
    /* 2AD4 8006B2D4 02000224 */  addiu      $v0, $zero, 0x2
    /* 2AD8 8006B2D8 0F006210 */  beq        $v1, $v0, .L8006B318
    /* 2ADC 8006B2DC 0E80023C */   lui       $v0, %hi(_textTable)
    /* 2AE0 8006B2E0 03006228 */  slti       $v0, $v1, 0x3
    /* 2AE4 8006B2E4 05004010 */  beqz       $v0, .L8006B2FC
    /* 2AE8 8006B2E8 01000224 */   addiu     $v0, $zero, 0x1
    /* 2AEC 8006B2EC 08006210 */  beq        $v1, $v0, .L8006B310
    /* 2AF0 8006B2F0 0E80023C */   lui       $v0, %hi(_textTable)
    /* 2AF4 8006B2F4 CEAC0108 */  j          .L8006B338
    /* 2AF8 8006B2F8 00000000 */   nop
  .L8006B2FC:
    /* 2AFC 8006B2FC 03000224 */  addiu      $v0, $zero, 0x3
    /* 2B00 8006B300 09006210 */  beq        $v1, $v0, .L8006B328
    /* 2B04 8006B304 0E80033C */   lui       $v1, %hi(_selectSaveMemoryCardMessage)
    /* 2B08 8006B308 CEAC0108 */  j          .L8006B338
    /* 2B0C 8006B30C 0E80023C */   lui       $v0, %hi(_textTable)
  .L8006B310:
    /* 2B10 8006B310 D5AC0108 */  j          .L8006B354
    /* 2B14 8006B314 01000224 */   addiu     $v0, $zero, 0x1
  .L8006B318:
    /* 2B18 8006B318 C0EA428C */  lw         $v0, %lo(_textTable)($v0)
    /* 2B1C 8006B31C 0E80033C */  lui        $v1, %hi(_selectSaveMemoryCardMessage)
    /* 2B20 8006B320 D1AC0108 */  j          .L8006B344
    /* 2B24 8006B324 C6014224 */   addiu     $v0, $v0, 0x1C6
  .L8006B328:
    /* 2B28 8006B328 0E80023C */  lui        $v0, %hi(_textTable)
    /* 2B2C 8006B32C C0EA428C */  lw         $v0, %lo(_textTable)($v0)
    /* 2B30 8006B330 D1AC0108 */  j          .L8006B344
    /* 2B34 8006B334 C4054224 */   addiu     $v0, $v0, 0x5C4
  .L8006B338:
    /* 2B38 8006B338 C0EA428C */  lw         $v0, %lo(_textTable)($v0)
    /* 2B3C 8006B33C 0E80033C */  lui        $v1, %hi(_selectSaveMemoryCardMessage)
    /* 2B40 8006B340 BC034224 */  addiu      $v0, $v0, 0x3BC
  .L8006B344:
    /* 2B44 8006B344 6CED62AC */  sw         $v0, %lo(_selectSaveMemoryCardMessage)($v1)
    /* 2B48 8006B348 D5AC0108 */  j          .L8006B354
    /* 2B4C 8006B34C FFFF0224 */   addiu     $v0, $zero, -0x1
  .L8006B350:
    /* 2B50 8006B350 21100000 */  addu       $v0, $zero, $zero
  .L8006B354:
    /* 2B54 8006B354 1400BF8F */  lw         $ra, 0x14($sp)
    /* 2B58 8006B358 1000B08F */  lw         $s0, 0x10($sp)
    /* 2B5C 8006B35C 0800E003 */  jr         $ra
    /* 2B60 8006B360 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel _memcardMaskedHandler
