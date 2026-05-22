nonmatching _initCubePuzzleStart, 0x2C0

glabel _initCubePuzzleStart
    /* 528C 80107A8C C0FFBD27 */  addiu      $sp, $sp, -0x40
    /* 5290 80107A90 2C00B1AF */  sw         $s1, 0x2C($sp)
    /* 5294 80107A94 0F80113C */  lui        $s1, %hi(_submenuState)
    /* 5298 80107A98 D81C238E */  lw         $v1, %lo(_submenuState)($s1)
    /* 529C 80107A9C 3800BFAF */  sw         $ra, 0x38($sp)
    /* 52A0 80107AA0 3400B3AF */  sw         $s3, 0x34($sp)
    /* 52A4 80107AA4 3000B2AF */  sw         $s2, 0x30($sp)
    /* 52A8 80107AA8 1F006014 */  bnez       $v1, .L80107B28
    /* 52AC 80107AAC 2800B0AF */   sw        $s0, 0x28($sp)
    /* 52B0 80107AB0 1D000424 */  addiu      $a0, $zero, 0x1D
    /* 52B4 80107AB4 02000524 */  addiu      $a1, $zero, 0x2
    /* 52B8 80107AB8 FCF7010C */  jal        func_8007DFF0
    /* 52BC 80107ABC 05000624 */   addiu     $a2, $zero, 0x5
    /* 52C0 80107AC0 1080103C */  lui        $s0, %hi(_disFiles)
    /* 52C4 80107AC4 E02A1026 */  addiu      $s0, $s0, %lo(_disFiles)
    /* 52C8 80107AC8 1C00048E */  lw         $a0, 0x1C($s0)
    /* 52CC 80107ACC 8F0F010C */  jal        vs_main_allocHeapR
    /* 52D0 80107AD0 00000000 */   nop
    /* 52D4 80107AD4 18000426 */  addiu      $a0, $s0, 0x18
    /* 52D8 80107AD8 1180103C */  lui        $s0, %hi(_iqDisData)
    /* 52DC 80107ADC C412010C */  jal        vs_main_allocateCdQueueSlot
    /* 52E0 80107AE0 6C9802AE */   sw        $v0, %lo(_iqDisData)($s0)
    /* 52E4 80107AE4 21204000 */  addu       $a0, $v0, $zero
    /* 52E8 80107AE8 6C98058E */  lw         $a1, %lo(_iqDisData)($s0)
    /* 52EC 80107AEC 1180023C */  lui        $v0, %hi(_iqDisCdSlot)
    /* 52F0 80107AF0 F112010C */  jal        vs_main_cdEnqueue
    /* 52F4 80107AF4 689844AC */   sw        $a0, %lo(_iqDisCdSlot)($v0)
    /* 52F8 80107AF8 D81C228E */  lw         $v0, %lo(_submenuState)($s1)
    /* 52FC 80107AFC 00000000 */  nop
    /* 5300 80107B00 01004224 */  addiu      $v0, $v0, 0x1
    /* 5304 80107B04 4B1F0408 */  j          .L80107D2C
    /* 5308 80107B08 D81C22AE */   sw        $v0, %lo(_submenuState)($s1)
  .L80107B0C:
    /* 530C 80107B0C 04008394 */  lhu        $v1, 0x4($a0)
    /* 5310 80107B10 00000000 */  nop
    /* 5314 80107B14 F49943A4 */  sh         $v1, %lo(D_801099F4)($v0)
    /* 5318 80107B18 06008394 */  lhu        $v1, 0x6($a0)
    /* 531C 80107B1C 1180023C */  lui        $v0, %hi(D_801099F6)
    /* 5320 80107B20 2E1F0408 */  j          .L80107CB8
    /* 5324 80107B24 F69943A4 */   sh        $v1, %lo(D_801099F6)($v0)
  .L80107B28:
    /* 5328 80107B28 01000224 */  addiu      $v0, $zero, 0x1
    /* 532C 80107B2C 6C006214 */  bne        $v1, $v0, .L80107CE0
    /* 5330 80107B30 1180023C */   lui       $v0, %hi(_iqDisData)
    /* 5334 80107B34 1180023C */  lui        $v0, %hi(_iqDisCdSlot)
    /* 5338 80107B38 6898428C */  lw         $v0, %lo(_iqDisCdSlot)($v0)
    /* 533C 80107B3C 00000000 */  nop
    /* 5340 80107B40 00004384 */  lh         $v1, 0x0($v0)
    /* 5344 80107B44 04000224 */  addiu      $v0, $zero, 0x4
    /* 5348 80107B48 79006214 */  bne        $v1, $v0, .L80107D30
    /* 534C 80107B4C 21100000 */   addu      $v0, $zero, $zero
    /* 5350 80107B50 21800000 */  addu       $s0, $zero, $zero
    /* 5354 80107B54 1180133C */  lui        $s3, %hi(_iqDisData)
    /* 5358 80107B58 40031224 */  addiu      $s2, $zero, 0x340
    /* 535C 80107B5C 21880002 */  addu       $s1, $s0, $zero
  .L80107B60:
    /* 5360 80107B60 6C98648E */  lw         $a0, %lo(_iqDisData)($s3)
    /* 5364 80107B64 1000A527 */  addiu      $a1, $sp, 0x10
    /* 5368 80107B68 0836020C */  jal        vs_battle_setTimImage
    /* 536C 80107B6C 21209100 */   addu      $a0, $a0, $s1
    /* 5370 80107B70 2000A28F */  lw         $v0, 0x20($sp)
    /* 5374 80107B74 00000000 */  nop
    /* 5378 80107B78 0E004010 */  beqz       $v0, .L80107BB4
    /* 537C 80107B7C 00000000 */   nop
    /* 5380 80107B80 1C00A28F */  lw         $v0, 0x1C($sp)
    /* 5384 80107B84 00000000 */  nop
    /* 5388 80107B88 000052A4 */  sh         $s2, 0x0($v0)
    /* 538C 80107B8C 1C00A38F */  lw         $v1, 0x1C($sp)
    /* 5390 80107B90 00010224 */  addiu      $v0, $zero, 0x100
    /* 5394 80107B94 020062A4 */  sh         $v0, 0x2($v1)
    /* 5398 80107B98 1C00A38F */  lw         $v1, 0x1C($sp)
    /* 539C 80107B9C FF000224 */  addiu      $v0, $zero, 0xFF
    /* 53A0 80107BA0 060062A4 */  sh         $v0, 0x6($v1)
    /* 53A4 80107BA4 1C00A48F */  lw         $a0, 0x1C($sp)
    /* 53A8 80107BA8 2000A58F */  lw         $a1, 0x20($sp)
    /* 53AC 80107BAC 3FA2000C */  jal        LoadImage
    /* 53B0 80107BB0 00000000 */   nop
  .L80107BB4:
    /* 53B4 80107BB4 1E000016 */  bnez       $s0, .L80107C30
    /* 53B8 80107BB8 20820234 */   ori       $v0, $zero, 0x8220
    /* 53BC 80107BBC 1800A28F */  lw         $v0, 0x18($sp)
    /* 53C0 80107BC0 00000000 */  nop
    /* 53C4 80107BC4 19004010 */  beqz       $v0, .L80107C2C
    /* 53C8 80107BC8 00030224 */   addiu     $v0, $zero, 0x300
    /* 53CC 80107BCC 1400A38F */  lw         $v1, 0x14($sp)
    /* 53D0 80107BD0 00000000 */  nop
    /* 53D4 80107BD4 000062A4 */  sh         $v0, 0x0($v1)
    /* 53D8 80107BD8 1400A38F */  lw         $v1, 0x14($sp)
    /* 53DC 80107BDC FF010224 */  addiu      $v0, $zero, 0x1FF
    /* 53E0 80107BE0 020062A4 */  sh         $v0, 0x2($v1)
    /* 53E4 80107BE4 1400A38F */  lw         $v1, 0x14($sp)
    /* 53E8 80107BE8 A0000224 */  addiu      $v0, $zero, 0xA0
    /* 53EC 80107BEC 040062A4 */  sh         $v0, 0x4($v1)
    /* 53F0 80107BF0 1400A38F */  lw         $v1, 0x14($sp)
    /* 53F4 80107BF4 01000224 */  addiu      $v0, $zero, 0x1
    /* 53F8 80107BF8 060062A4 */  sh         $v0, 0x6($v1)
    /* 53FC 80107BFC 1800A28F */  lw         $v0, 0x18($sp)
    /* 5400 80107C00 00000000 */  nop
    /* 5404 80107C04 000040AC */  sw         $zero, 0x0($v0)
    /* 5408 80107C08 1400A48F */  lw         $a0, 0x14($sp)
    /* 540C 80107C0C 1800A58F */  lw         $a1, 0x18($sp)
    /* 5410 80107C10 3FA2000C */  jal        LoadImage
    /* 5414 80107C14 00000000 */   nop
    /* 5418 80107C18 1180043C */  lui        $a0, %hi(D_801098AC)
    /* 541C 80107C1C AC988424 */  addiu      $a0, $a0, %lo(D_801098AC)
    /* 5420 80107C20 1800A58F */  lw         $a1, 0x18($sp)
    /* 5424 80107C24 2C24010C */  jal        vs_main_memcpy
    /* 5428 80107C28 40010624 */   addiu     $a2, $zero, 0x140
  .L80107C2C:
    /* 542C 80107C2C 20820234 */  ori        $v0, $zero, 0x8220
  .L80107C30:
    /* 5430 80107C30 21882202 */  addu       $s1, $s1, $v0
    /* 5434 80107C34 01001026 */  addiu      $s0, $s0, 0x1
    /* 5438 80107C38 0200022A */  slti       $v0, $s0, 0x2
    /* 543C 80107C3C C8FF4014 */  bnez       $v0, .L80107B60
    /* 5440 80107C40 40005226 */   addiu     $s2, $s2, 0x40
    /* 5444 80107C44 0100043C */  lui        $a0, (0x10440 >> 16)
    /* 5448 80107C48 40048434 */  ori        $a0, $a0, (0x10440 & 0xFFFF)
    /* 544C 80107C4C 21800000 */  addu       $s0, $zero, $zero
    /* 5450 80107C50 1180033C */  lui        $v1, %hi(D_801099F4)
    /* 5454 80107C54 58020224 */  addiu      $v0, $zero, 0x258
    /* 5458 80107C58 F49962A4 */  sh         $v0, %lo(D_801099F4)($v1)
    /* 545C 80107C5C 1180033C */  lui        $v1, %hi(D_801099F6)
    /* 5460 80107C60 01000224 */  addiu      $v0, $zero, 0x1
    /* 5464 80107C64 F69962A4 */  sh         $v0, %lo(D_801099F6)($v1)
    /* 5468 80107C68 0F80033C */  lui        $v1, %hi(vs_battle_roomData + 0x9C)
    /* 546C 80107C6C 1180023C */  lui        $v0, %hi(_iqDisData)
    /* 5470 80107C70 6C98428C */  lw         $v0, %lo(_iqDisData)($v0)
    /* 5474 80107C74 941C638C */  lw         $v1, %lo(vs_battle_roomData + 0x9C)($v1)
    /* 5478 80107C78 21204400 */  addu       $a0, $v0, $a0
    /* 547C 80107C7C 04006524 */  addiu      $a1, $v1, 0x4
    /* 5480 80107C80 0800A684 */  lh         $a2, 0x8($a1)
  .L80107C84:
    /* 5484 80107C84 00008284 */  lh         $v0, 0x0($a0)
    /* 5488 80107C88 00000000 */  nop
    /* 548C 80107C8C 06004614 */  bne        $v0, $a2, .L80107CA8
    /* 5490 80107C90 00000000 */   nop
    /* 5494 80107C94 02008384 */  lh         $v1, 0x2($a0)
    /* 5498 80107C98 0A00A284 */  lh         $v0, 0xA($a1)
    /* 549C 80107C9C 00000000 */  nop
    /* 54A0 80107CA0 9AFF6210 */  beq        $v1, $v0, .L80107B0C
    /* 54A4 80107CA4 1180023C */   lui       $v0, %hi(D_801099F4)
  .L80107CA8:
    /* 54A8 80107CA8 01001026 */  addiu      $s0, $s0, 0x1
    /* 54AC 80107CAC 4000022A */  slti       $v0, $s0, 0x40
    /* 54B0 80107CB0 F4FF4014 */  bnez       $v0, .L80107C84
    /* 54B4 80107CB4 08008424 */   addiu     $a0, $a0, 0x8
  .L80107CB8:
    /* 54B8 80107CB8 1180023C */  lui        $v0, %hi(_iqDisCdSlot)
    /* 54BC 80107CBC 6898448C */  lw         $a0, %lo(_iqDisCdSlot)($v0)
    /* 54C0 80107CC0 E012010C */  jal        vs_main_freeCdQueueSlot
    /* 54C4 80107CC4 00000000 */   nop
    /* 54C8 80107CC8 0F80033C */  lui        $v1, %hi(_submenuState)
    /* 54CC 80107CCC D81C628C */  lw         $v0, %lo(_submenuState)($v1)
    /* 54D0 80107CD0 00000000 */  nop
    /* 54D4 80107CD4 01004224 */  addiu      $v0, $v0, 0x1
    /* 54D8 80107CD8 4B1F0408 */  j          .L80107D2C
    /* 54DC 80107CDC D81C62AC */   sw        $v0, %lo(_submenuState)($v1)
  .L80107CE0:
    /* 54E0 80107CE0 6C98448C */  lw         $a0, %lo(_iqDisData)($v0)
    /* 54E4 80107CE4 180F010C */  jal        vs_main_freeHeapR
    /* 54E8 80107CE8 00000000 */   nop
    /* 54EC 80107CEC 1180023C */  lui        $v0, %hi(D_80109894)
    /* 54F0 80107CF0 949840AC */  sw         $zero, %lo(D_80109894)($v0)
    /* 54F4 80107CF4 1180023C */  lui        $v0, %hi(D_80109898)
    /* 54F8 80107CF8 989840AC */  sw         $zero, %lo(D_80109898)($v0)
    /* 54FC 80107CFC 1180023C */  lui        $v0, %hi(D_8010989C)
    /* 5500 80107D00 9C9840AC */  sw         $zero, %lo(D_8010989C)($v0)
    /* 5504 80107D04 1180023C */  lui        $v0, %hi(D_801098A0)
    /* 5508 80107D08 A09840AC */  sw         $zero, %lo(D_801098A0)($v0)
    /* 550C 80107D0C 1180023C */  lui        $v0, %hi(D_8010988C)
    /* 5510 80107D10 8C9840AC */  sw         $zero, %lo(D_8010988C)($v0)
    /* 5514 80107D14 1180023C */  lui        $v0, %hi(_buffReelSelection)
    /* 5518 80107D18 789840AC */  sw         $zero, %lo(_buffReelSelection)($v0)
    /* 551C 80107D1C 8E23040C */  jal        func_80108E38
    /* 5520 80107D20 D81C20AE */   sw        $zero, %lo(_submenuState)($s1)
    /* 5524 80107D24 4C1F0408 */  j          .L80107D30
    /* 5528 80107D28 01000224 */   addiu     $v0, $zero, 0x1
  .L80107D2C:
    /* 552C 80107D2C 21100000 */  addu       $v0, $zero, $zero
  .L80107D30:
    /* 5530 80107D30 3800BF8F */  lw         $ra, 0x38($sp)
    /* 5534 80107D34 3400B38F */  lw         $s3, 0x34($sp)
    /* 5538 80107D38 3000B28F */  lw         $s2, 0x30($sp)
    /* 553C 80107D3C 2C00B18F */  lw         $s1, 0x2C($sp)
    /* 5540 80107D40 2800B08F */  lw         $s0, 0x28($sp)
    /* 5544 80107D44 0800E003 */  jr         $ra
    /* 5548 80107D48 4000BD27 */   addiu     $sp, $sp, 0x40
endlabel _initCubePuzzleStart
