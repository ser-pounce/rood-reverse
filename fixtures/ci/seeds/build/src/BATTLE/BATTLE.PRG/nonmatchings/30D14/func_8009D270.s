nonmatching func_8009D270, 0x1E8

glabel func_8009D270
    /* 34A70 8009D270 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 34A74 8009D274 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 34A78 8009D278 21888000 */  addu       $s1, $a0, $zero
    /* 34A7C 8009D27C 1800B0AF */  sw         $s0, 0x18($sp)
    /* 34A80 8009D280 0F80103C */  lui        $s0, %hi(D_800E8F2D)
    /* 34A84 8009D284 2D8F0392 */  lbu        $v1, %lo(D_800E8F2D)($s0)
    /* 34A88 8009D288 01000424 */  addiu      $a0, $zero, 0x1
    /* 34A8C 8009D28C 2400BFAF */  sw         $ra, 0x24($sp)
    /* 34A90 8009D290 28006410 */  beq        $v1, $a0, .L8009D334
    /* 34A94 8009D294 2000B2AF */   sw        $s2, 0x20($sp)
    /* 34A98 8009D298 02000224 */  addiu      $v0, $zero, 0x2
    /* 34A9C 8009D29C 61006210 */  beq        $v1, $v0, .L8009D424
    /* 34AA0 8009D2A0 0F80023C */   lui       $v0, %hi(D_800E8C90)
    /* 34AA4 8009D2A4 02002386 */  lh         $v1, 0x2($s1)
    /* 34AA8 8009D2A8 908C4224 */  addiu      $v0, $v0, %lo(D_800E8C90)
    /* 34AAC 8009D2AC 2D8F04A2 */  sb         $a0, %lo(D_800E8F2D)($s0)
    /* 34AB0 8009D2B0 21186200 */  addu       $v1, $v1, $v0
    /* 34AB4 8009D2B4 00006490 */  lbu        $a0, 0x0($v1)
    /* 34AB8 8009D2B8 00000000 */  nop
    /* 34ABC 8009D2BC 04008014 */  bnez       $a0, .L8009D2D0
    /* 34AC0 8009D2C0 00000000 */   nop
    /* 34AC4 8009D2C4 2D8F00A2 */  sb         $zero, %lo(D_800E8F2D)($s0)
  .L8009D2C8:
    /* 34AC8 8009D2C8 0F750208 */  j          .L8009D43C
    /* 34ACC 8009D2CC FEFF0224 */   addiu     $v0, $zero, -0x2
  .L8009D2D0:
    /* 34AD0 8009D2D0 C0820400 */  sll        $s0, $a0, 11
    /* 34AD4 8009D2D4 8F0F010C */  jal        vs_main_allocHeapR
    /* 34AD8 8009D2D8 21200002 */   addu      $a0, $s0, $zero
    /* 34ADC 8009D2DC 0F80123C */  lui        $s2, %hi(D_800F22FC)
    /* 34AE0 8009D2E0 F9FF4010 */  beqz       $v0, .L8009D2C8
    /* 34AE4 8009D2E4 FC2242AE */   sw        $v0, %lo(D_800F22FC)($s2)
    /* 34AE8 8009D2E8 0100063C */  lui        $a2, (0x1979F >> 16)
    /* 34AEC 8009D2EC 9F97C634 */  ori        $a2, $a2, (0x1979F & 0xFFFF)
    /* 34AF0 8009D2F0 0F80053C */  lui        $a1, %hi(D_800F2300)
    /* 34AF4 8009D2F4 0F80033C */  lui        $v1, %hi(D_800E8BB0)
    /* 34AF8 8009D2F8 02002286 */  lh         $v0, 0x2($s1)
    /* 34AFC 8009D2FC B08B6324 */  addiu      $v1, $v1, %lo(D_800E8BB0)
    /* 34B00 8009D300 40100200 */  sll        $v0, $v0, 1
    /* 34B04 8009D304 21104300 */  addu       $v0, $v0, $v1
    /* 34B08 8009D308 00004294 */  lhu        $v0, 0x0($v0)
    /* 34B0C 8009D30C 0023A424 */  addiu      $a0, $a1, %lo(D_800F2300)
    /* 34B10 8009D310 040090AC */  sw         $s0, 0x4($a0)
    /* 34B14 8009D314 21104600 */  addu       $v0, $v0, $a2
    /* 34B18 8009D318 C412010C */  jal        vs_main_allocateCdQueueSlot
    /* 34B1C 8009D31C 0023A2AC */   sw        $v0, %lo(D_800F2300)($a1)
    /* 34B20 8009D320 21204000 */  addu       $a0, $v0, $zero
    /* 34B24 8009D324 FC22458E */  lw         $a1, %lo(D_800F22FC)($s2)
    /* 34B28 8009D328 0F80023C */  lui        $v0, %hi(D_800F2308)
    /* 34B2C 8009D32C F112010C */  jal        vs_main_cdEnqueue
    /* 34B30 8009D330 082344AC */   sw        $a0, %lo(D_800F2308)($v0)
  .L8009D334:
    /* 34B34 8009D334 0F80023C */  lui        $v0, %hi(D_800F2308)
    /* 34B38 8009D338 0823448C */  lw         $a0, %lo(D_800F2308)($v0)
    /* 34B3C 8009D33C 00000000 */  nop
    /* 34B40 8009D340 00008384 */  lh         $v1, 0x0($a0)
    /* 34B44 8009D344 04000224 */  addiu      $v0, $zero, 0x4
    /* 34B48 8009D348 3C006214 */  bne        $v1, $v0, .L8009D43C
    /* 34B4C 8009D34C FFFF0224 */   addiu     $v0, $zero, -0x1
    /* 34B50 8009D350 E012010C */  jal        vs_main_freeCdQueueSlot
    /* 34B54 8009D354 00000000 */   nop
    /* 34B58 8009D358 0F80023C */  lui        $v0, %hi(D_800F244F)
    /* 34B5C 8009D35C 01002382 */  lb         $v1, 0x1($s1)
    /* 34B60 8009D360 4F245024 */  addiu      $s0, $v0, %lo(D_800F244F)
    /* 34B64 8009D364 21187000 */  addu       $v1, $v1, $s0
    /* 34B68 8009D368 00006290 */  lbu        $v0, 0x0($v1)
    /* 34B6C 8009D36C 00000000 */  nop
    /* 34B70 8009D370 0A004010 */  beqz       $v0, .L8009D39C
    /* 34B74 8009D374 21204000 */   addu      $a0, $v0, $zero
    /* 34B78 8009D378 01000524 */  addiu      $a1, $zero, 0x1
    /* 34B7C 8009D37C 2AF8010C */  jal        func_8007E0A8
    /* 34B80 8009D380 04000624 */   addiu     $a2, $zero, 0x4
    /* 34B84 8009D384 2D004010 */  beqz       $v0, .L8009D43C
    /* 34B88 8009D388 FDFF0224 */   addiu     $v0, $zero, -0x3
    /* 34B8C 8009D38C 01002282 */  lb         $v0, 0x1($s1)
    /* 34B90 8009D390 00000000 */  nop
    /* 34B94 8009D394 21105000 */  addu       $v0, $v0, $s0
    /* 34B98 8009D398 000040A0 */  sb         $zero, 0x0($v0)
  .L8009D39C:
    /* 34B9C 8009D39C 11002492 */  lbu        $a0, 0x11($s1)
    /* 34BA0 8009D3A0 01000524 */  addiu      $a1, $zero, 0x1
    /* 34BA4 8009D3A4 FCF7010C */  jal        func_8007DFF0
    /* 34BA8 8009D3A8 04000624 */   addiu     $a2, $zero, 0x4
    /* 34BAC 8009D3AC C6FF4010 */  beqz       $v0, .L8009D2C8
    /* 34BB0 8009D3B0 0F80033C */   lui       $v1, %hi(D_800F244F)
    /* 34BB4 8009D3B4 4F246324 */  addiu      $v1, $v1, %lo(D_800F244F)
    /* 34BB8 8009D3B8 0F80063C */  lui        $a2, %hi(D_800F22FC)
    /* 34BBC 8009D3BC 01002282 */  lb         $v0, 0x1($s1)
    /* 34BC0 8009D3C0 11002492 */  lbu        $a0, 0x11($s1)
    /* 34BC4 8009D3C4 21104300 */  addu       $v0, $v0, $v1
    /* 34BC8 8009D3C8 000044A0 */  sb         $a0, 0x0($v0)
    /* 34BCC 8009D3CC FC22C38C */  lw         $v1, %lo(D_800F22FC)($a2)
    /* 34BD0 8009D3D0 1000A427 */  addiu      $a0, $sp, 0x10
    /* 34BD4 8009D3D4 02006224 */  addiu      $v0, $v1, 0x2
    /* 34BD8 8009D3D8 FC22C2AC */  sw         $v0, %lo(D_800F22FC)($a2)
    /* 34BDC 8009D3DC 02006794 */  lhu        $a3, 0x2($v1)
    /* 34BE0 8009D3E0 04006524 */  addiu      $a1, $v1, 0x4
    /* 34BE4 8009D3E4 FC22C5AC */  sw         $a1, %lo(D_800F22FC)($a2)
    /* 34BE8 8009D3E8 11002392 */  lbu        $v1, 0x11($s1)
    /* 34BEC 8009D3EC 00010224 */  addiu      $v0, $zero, 0x100
    /* 34BF0 8009D3F0 1200A2A7 */  sh         $v0, 0x12($sp)
    /* 34BF4 8009D3F4 40000224 */  addiu      $v0, $zero, 0x40
    /* 34BF8 8009D3F8 1400A2A7 */  sh         $v0, 0x14($sp)
    /* 34BFC 8009D3FC 0F006330 */  andi       $v1, $v1, 0xF
    /* 34C00 8009D400 80190300 */  sll        $v1, $v1, 6
    /* 34C04 8009D404 1000A3A7 */  sh         $v1, 0x10($sp)
    /* 34C08 8009D408 3FA2000C */  jal        LoadImage
    /* 34C0C 8009D40C 1600A7A7 */   sh        $a3, 0x16($sp)
    /* 34C10 8009D410 FFFF0224 */  addiu      $v0, $zero, -0x1
    /* 34C14 8009D414 0F80043C */  lui        $a0, %hi(D_800E8F2D)
    /* 34C18 8009D418 02000324 */  addiu      $v1, $zero, 0x2
    /* 34C1C 8009D41C 0F750208 */  j          .L8009D43C
    /* 34C20 8009D420 2D8F83A0 */   sb        $v1, %lo(D_800E8F2D)($a0)
  .L8009D424:
    /* 34C24 8009D424 0F80023C */  lui        $v0, %hi(D_800F22FC)
    /* 34C28 8009D428 FC22448C */  lw         $a0, %lo(D_800F22FC)($v0)
    /* 34C2C 8009D42C 180F010C */  jal        vs_main_freeHeapR
    /* 34C30 8009D430 FCFF8424 */   addiu     $a0, $a0, -0x4
    /* 34C34 8009D434 21100000 */  addu       $v0, $zero, $zero
    /* 34C38 8009D438 2D8F00A2 */  sb         $zero, %lo(D_800E8F2D)($s0)
  .L8009D43C:
    /* 34C3C 8009D43C 2400BF8F */  lw         $ra, 0x24($sp)
    /* 34C40 8009D440 2000B28F */  lw         $s2, 0x20($sp)
    /* 34C44 8009D444 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 34C48 8009D448 1800B08F */  lw         $s0, 0x18($sp)
    /* 34C4C 8009D44C 2800BD27 */  addiu      $sp, $sp, 0x28
    /* 34C50 8009D450 0800E003 */  jr         $ra
    /* 34C54 8009D454 00000000 */   nop
endlabel func_8009D270
