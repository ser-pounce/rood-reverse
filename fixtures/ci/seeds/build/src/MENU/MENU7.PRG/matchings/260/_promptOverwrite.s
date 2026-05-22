nonmatching _promptOverwrite, 0xBC

glabel _promptOverwrite
    /* 3AE0 801062E0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 3AE4 801062E4 1400BFAF */  sw         $ra, 0x14($sp)
    /* 3AE8 801062E8 0F008010 */  beqz       $a0, .L80106328
    /* 3AEC 801062EC 1000B0AF */   sw        $s0, 0x10($sp)
    /* 3AF0 801062F0 01000424 */  addiu      $a0, $zero, 0x1
    /* 3AF4 801062F4 1180033C */  lui        $v1, %hi(_promptOverwriteInitialized)
    /* 3AF8 801062F8 21108000 */  addu       $v0, $a0, $zero
    /* 3AFC 801062FC B5AA62A0 */  sb         $v0, %lo(_promptOverwriteInitialized)($v1)
    /* 3B00 80106300 1180023C */  lui        $v0, %hi(_textTable)
    /* 3B04 80106304 F8AD428C */  lw         $v0, %lo(_textTable)($v0)
    /* 3B08 80106308 1180033C */  lui        $v1, %hi(_memoryCardMessage)
    /* 3B0C 8010630C B0054224 */  addiu      $v0, $v0, 0x5B0
    /* 3B10 80106310 3218040C */  jal        _promptConfirm
    /* 3B14 80106314 A4B062AC */   sw        $v0, %lo(_memoryCardMessage)($v1)
    /* 3B18 80106318 21100000 */  addu       $v0, $zero, $zero
    /* 3B1C 8010631C 1180033C */  lui        $v1, %hi(_promptOverwriteState)
    /* 3B20 80106320 E3180408 */  j          .L8010638C
    /* 3B24 80106324 B4AA60A0 */   sb        $zero, %lo(_promptOverwriteState)($v1)
  .L80106328:
    /* 3B28 80106328 1180103C */  lui        $s0, %hi(_promptOverwriteState)
    /* 3B2C 8010632C B4AA0392 */  lbu        $v1, %lo(_promptOverwriteState)($s0)
    /* 3B30 80106330 00000000 */  nop
    /* 3B34 80106334 05006010 */  beqz       $v1, .L8010634C
    /* 3B38 80106338 01000224 */   addiu     $v0, $zero, 0x1
    /* 3B3C 8010633C 0B006210 */  beq        $v1, $v0, .L8010636C
    /* 3B40 80106340 21100000 */   addu      $v0, $zero, $zero
    /* 3B44 80106344 E3180408 */  j          .L8010638C
    /* 3B48 80106348 00000000 */   nop
  .L8010634C:
    /* 3B4C 8010634C 3218040C */  jal        _promptConfirm
    /* 3B50 80106350 21200000 */   addu      $a0, $zero, $zero
    /* 3B54 80106354 1180033C */  lui        $v1, %hi(_promptOverwriteConfirmed)
    /* 3B58 80106358 0B004010 */  beqz       $v0, .L80106388
    /* 3B5C 8010635C B0AA62AC */   sw        $v0, %lo(_promptOverwriteConfirmed)($v1)
    /* 3B60 80106360 01000224 */  addiu      $v0, $zero, 0x1
    /* 3B64 80106364 E2180408 */  j          .L80106388
    /* 3B68 80106368 B4AA02A2 */   sb        $v0, %lo(_promptOverwriteState)($s0)
  .L8010636C:
    /* 3B6C 8010636C C113040C */  jal        _fileMenuElementsActive
    /* 3B70 80106370 00000000 */   nop
    /* 3B74 80106374 04004010 */  beqz       $v0, .L80106388
    /* 3B78 80106378 1180023C */   lui       $v0, %hi(_promptOverwriteConfirmed)
    /* 3B7C 8010637C B0AA428C */  lw         $v0, %lo(_promptOverwriteConfirmed)($v0)
    /* 3B80 80106380 E3180408 */  j          .L8010638C
    /* 3B84 80106384 00000000 */   nop
  .L80106388:
    /* 3B88 80106388 21100000 */  addu       $v0, $zero, $zero
  .L8010638C:
    /* 3B8C 8010638C 1400BF8F */  lw         $ra, 0x14($sp)
    /* 3B90 80106390 1000B08F */  lw         $s0, 0x10($sp)
    /* 3B94 80106394 0800E003 */  jr         $ra
    /* 3B98 80106398 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel _promptOverwrite
