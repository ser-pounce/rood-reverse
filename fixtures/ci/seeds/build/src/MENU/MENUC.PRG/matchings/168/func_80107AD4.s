nonmatching func_80107AD4, 0x3E8

glabel func_80107AD4
    /* 52D4 80107AD4 C0FFBD27 */  addiu      $sp, $sp, -0x40
    /* 52D8 80107AD8 21188000 */  addu       $v1, $a0, $zero
    /* 52DC 80107ADC 2000B2AF */  sw         $s2, 0x20($sp)
    /* 52E0 80107AE0 21900000 */  addu       $s2, $zero, $zero
    /* 52E4 80107AE4 3C00BFAF */  sw         $ra, 0x3C($sp)
    /* 52E8 80107AE8 3800BEAF */  sw         $fp, 0x38($sp)
    /* 52EC 80107AEC 3400B7AF */  sw         $s7, 0x34($sp)
    /* 52F0 80107AF0 3000B6AF */  sw         $s6, 0x30($sp)
    /* 52F4 80107AF4 2C00B5AF */  sw         $s5, 0x2C($sp)
    /* 52F8 80107AF8 2800B4AF */  sw         $s4, 0x28($sp)
    /* 52FC 80107AFC 2400B3AF */  sw         $s3, 0x24($sp)
    /* 5300 80107B00 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 5304 80107B04 09006010 */  beqz       $v1, .L80107B2C
    /* 5308 80107B08 1800B0AF */   sw        $s0, 0x18($sp)
    /* 530C 80107B0C 0A006424 */  addiu      $a0, $v1, 0xA
    /* 5310 80107B10 1180023C */  lui        $v0, %hi(D_8010BC61)
    /* 5314 80107B14 630F040C */  jal        func_80103D8C
    /* 5318 80107B18 61BC43A0 */   sb        $v1, %lo(D_8010BC61)($v0)
    /* 531C 80107B1C 21104002 */  addu       $v0, $s2, $zero
    /* 5320 80107B20 1180033C */  lui        $v1, %hi(D_8010BC60)
    /* 5324 80107B24 A31F0408 */  j          .L80107E8C
    /* 5328 80107B28 60BC60A0 */   sb        $zero, %lo(D_8010BC60)($v1)
  .L80107B2C:
    /* 532C 80107B2C 1180023C */  lui        $v0, %hi(D_8010BD10)
    /* 5330 80107B30 1180033C */  lui        $v1, %hi(D_8010BC61)
    /* 5334 80107B34 61BC6390 */  lbu        $v1, %lo(D_8010BC61)($v1)
    /* 5338 80107B38 10BD4224 */  addiu      $v0, $v0, %lo(D_8010BD10)
    /* 533C 80107B3C 21186200 */  addu       $v1, $v1, $v0
    /* 5340 80107B40 FFFF7090 */  lbu        $s0, -0x1($v1)
    /* 5344 80107B44 00000000 */  nop
    /* 5348 80107B48 08000012 */  beqz       $s0, .L80107B6C
    /* 534C 80107B4C 40101000 */   sll       $v0, $s0, 1
    /* 5350 80107B50 21105000 */  addu       $v0, $v0, $s0
    /* 5354 80107B54 80100200 */  sll        $v0, $v0, 2
    /* 5358 80107B58 23105000 */  subu       $v0, $v0, $s0
    /* 535C 80107B5C 80100200 */  sll        $v0, $v0, 2
    /* 5360 80107B60 0680033C */  lui        $v1, %hi(D_800603BC)
    /* 5364 80107B64 BC036324 */  addiu      $v1, $v1, %lo(D_800603BC)
    /* 5368 80107B68 21904300 */  addu       $s2, $v0, $v1
  .L80107B6C:
    /* 536C 80107B6C 1180023C */  lui        $v0, %hi(D_8010BC60)
    /* 5370 80107B70 60BC4390 */  lbu        $v1, %lo(D_8010BC60)($v0)
    /* 5374 80107B74 01001124 */  addiu      $s1, $zero, 0x1
    /* 5378 80107B78 85007110 */  beq        $v1, $s1, .L80107D90
    /* 537C 80107B7C 02006228 */   slti      $v0, $v1, 0x2
    /* 5380 80107B80 05004010 */  beqz       $v0, .L80107B98
    /* 5384 80107B84 02000224 */   addiu     $v0, $zero, 0x2
    /* 5388 80107B88 07006010 */  beqz       $v1, .L80107BA8
    /* 538C 80107B8C 21100000 */   addu      $v0, $zero, $zero
    /* 5390 80107B90 A31F0408 */  j          .L80107E8C
    /* 5394 80107B94 00000000 */   nop
  .L80107B98:
    /* 5398 80107B98 B4006210 */  beq        $v1, $v0, .L80107E6C
    /* 539C 80107B9C 21100000 */   addu      $v0, $zero, $zero
    /* 53A0 80107BA0 A31F0408 */  j          .L80107E8C
    /* 53A4 80107BA4 00000000 */   nop
  .L80107BA8:
    /* 53A8 80107BA8 74EA030C */  jal        vs_mainmenu_ready
    /* 53AC 80107BAC 00000000 */   nop
    /* 53B0 80107BB0 B6004010 */  beqz       $v0, .L80107E8C
    /* 53B4 80107BB4 21100000 */   addu      $v0, $zero, $zero
    /* 53B8 80107BB8 8F0F010C */  jal        vs_main_allocHeapR
    /* 53BC 80107BBC 2C070424 */   addiu     $a0, $zero, 0x72C
    /* 53C0 80107BC0 21B84000 */  addu       $s7, $v0, $zero
    /* 53C4 80107BC4 0C004016 */  bnez       $s2, .L80107BF8
    /* 53C8 80107BC8 A406FE26 */   addiu     $fp, $s7, 0x6A4
    /* 53CC 80107BCC 1080023C */  lui        $v0, %hi(vs_mainMenu_menu12Text)
    /* 53D0 80107BD0 A424438C */  lw         $v1, %lo(vs_mainMenu_menu12Text)($v0)
    /* 53D4 80107BD4 00000000 */  nop
    /* 53D8 80107BD8 6C086224 */  addiu      $v0, $v1, 0x86C
    /* 53DC 80107BDC A406E2AE */  sw         $v0, 0x6A4($s7)
    /* 53E0 80107BE0 0F80023C */  lui        $v0, %hi(vs_battle_rowTypeBuf)
    /* 53E4 80107BE4 844E428C */  lw         $v0, %lo(vs_battle_rowTypeBuf)($v0)
    /* 53E8 80107BE8 B2086324 */  addiu      $v1, $v1, 0x8B2
    /* 53EC 80107BEC 0400C3AF */  sw         $v1, 0x4($fp)
    /* 53F0 80107BF0 041F0408 */  j          .L80107C10
    /* 53F4 80107BF4 000051AC */   sw        $s1, 0x0($v0)
  .L80107BF8:
    /* 53F8 80107BF8 21204002 */  addu       $a0, $s2, $zero
    /* 53FC 80107BFC 2128C003 */  addu       $a1, $fp, $zero
    /* 5400 80107C00 0F80023C */  lui        $v0, %hi(vs_battle_rowTypeBuf)
    /* 5404 80107C04 844E468C */  lw         $a2, %lo(vs_battle_rowTypeBuf)($v0)
    /* 5408 80107C08 A9F2030C */  jal        vs_mainMenu_setUiBlade
    /* 540C 80107C0C 2138E002 */   addu      $a3, $s7, $zero
  .L80107C10:
    /* 5410 80107C10 1180023C */  lui        $v0, %hi(D_8010BCA4)
    /* 5414 80107C14 A4BC50A0 */  sb         $s0, %lo(D_8010BCA4)($v0)
    /* 5418 80107C18 01001424 */  addiu      $s4, $zero, 0x1
    /* 541C 80107C1C 21A80000 */  addu       $s5, $zero, $zero
    /* 5420 80107C20 0F80083C */  lui        $t0, %hi(vs_battle_rowTypeBuf)
    /* 5424 80107C24 6000F626 */  addiu      $s6, $s7, 0x60
    /* 5428 80107C28 0800D327 */  addiu      $s3, $fp, 0x8
    /* 542C 80107C2C 0680093C */  lui        $t1, %hi(vs_main_inventoryIndices)
  .L80107C30:
    /* 5430 80107C30 D8192925 */  addiu      $t1, $t1, %lo(vs_main_inventoryIndices)
    /* 5434 80107C34 2110A902 */  addu       $v0, $s5, $t1
    /* 5438 80107C38 08005090 */  lbu        $s0, 0x8($v0)
    /* 543C 80107C3C 00000000 */  nop
    /* 5440 80107C40 44000012 */  beqz       $s0, .L80107D54
    /* 5444 80107C44 1180023C */   lui       $v0, %hi(D_8010BD10)
    /* 5448 80107C48 10BD4390 */  lbu        $v1, %lo(D_8010BD10)($v0)
    /* 544C 80107C4C 00000000 */  nop
    /* 5450 80107C50 40000312 */  beq        $s0, $v1, .L80107D54
    /* 5454 80107C54 10BD4224 */   addiu     $v0, $v0, %lo(D_8010BD10)
    /* 5458 80107C58 01004290 */  lbu        $v0, 0x1($v0)
    /* 545C 80107C5C 00000000 */  nop
    /* 5460 80107C60 3C000212 */  beq        $s0, $v0, .L80107D54
    /* 5464 80107C64 40101000 */   sll       $v0, $s0, 1
    /* 5468 80107C68 21105000 */  addu       $v0, $v0, $s0
    /* 546C 80107C6C 80100200 */  sll        $v0, $v0, 2
    /* 5470 80107C70 23105000 */  subu       $v0, $v0, $s0
    /* 5474 80107C74 80100200 */  sll        $v0, $v0, 2
    /* 5478 80107C78 0680093C */  lui        $t1, %hi(D_800603BC)
    /* 547C 80107C7C BC032925 */  addiu      $t1, $t1, %lo(D_800603BC)
    /* 5480 80107C80 21904900 */  addu       $s2, $v0, $t1
    /* 5484 80107C84 21204002 */  addu       $a0, $s2, $zero
    /* 5488 80107C88 21286002 */  addu       $a1, $s3, $zero
    /* 548C 80107C8C 2138C002 */  addu       $a3, $s6, $zero
    /* 5490 80107C90 844E068D */  lw         $a2, %lo(vs_battle_rowTypeBuf)($t0)
    /* 5494 80107C94 80881400 */  sll        $s1, $s4, 2
    /* 5498 80107C98 1000A8AF */  sw         $t0, 0x10($sp)
    /* 549C 80107C9C A9F2030C */  jal        vs_mainMenu_setUiBlade
    /* 54A0 80107CA0 2130D100 */   addu      $a2, $a2, $s1
    /* 54A4 80107CA4 1180023C */  lui        $v0, %hi(_inWorkshop)
    /* 54A8 80107CA8 1180093C */  lui        $t1, %hi(D_8010BB30)
    /* 54AC 80107CAC 30BB2925 */  addiu      $t1, $t1, %lo(D_8010BB30)
    /* 54B0 80107CB0 80BC4290 */  lbu        $v0, %lo(_inWorkshop)($v0)
    /* 54B4 80107CB4 28004396 */  lhu        $v1, 0x28($s2)
    /* 54B8 80107CB8 21104900 */  addu       $v0, $v0, $t1
    /* 54BC 80107CBC 00004290 */  lbu        $v0, 0x0($v0)
    /* 54C0 80107CC0 1000A88F */  lw         $t0, 0x10($sp)
    /* 54C4 80107CC4 07106200 */  srav       $v0, $v0, $v1
    /* 54C8 80107CC8 01004230 */  andi       $v0, $v0, 0x1
    /* 54CC 80107CCC 0A004014 */  bnez       $v0, .L80107CF8
    /* 54D0 80107CD0 1080023C */   lui       $v0, %hi(vs_mainMenu_menu12Text)
    /* 54D4 80107CD4 A424428C */  lw         $v0, %lo(vs_mainMenu_menu12Text)($v0)
    /* 54D8 80107CD8 844E038D */  lw         $v1, 0x4E84($t0)
    /* 54DC 80107CDC DA024224 */  addiu      $v0, $v0, 0x2DA
    /* 54E0 80107CE0 21182302 */  addu       $v1, $s1, $v1
    /* 54E4 80107CE4 040062AE */  sw         $v0, 0x4($s3)
    /* 54E8 80107CE8 0000628C */  lw         $v0, 0x0($v1)
    /* 54EC 80107CEC 00000000 */  nop
    /* 54F0 80107CF0 01004234 */  ori        $v0, $v0, 0x1
    /* 54F4 80107CF4 000062AC */  sw         $v0, 0x0($v1)
  .L80107CF8:
    /* 54F8 80107CF8 2A004492 */  lbu        $a0, 0x2A($s2)
    /* 54FC 80107CFC 00000000 */  nop
    /* 5500 80107D00 0D008010 */  beqz       $a0, .L80107D38
    /* 5504 80107D04 0680093C */   lui       $t1, %hi(vs_battle_inventory)
    /* 5508 80107D08 844E028D */  lw         $v0, 0x4E84($t0)
    /* 550C 80107D0C 68012925 */  addiu      $t1, $t1, %lo(vs_battle_inventory)
    /* 5510 80107D10 21182202 */  addu       $v1, $s1, $v0
    /* 5514 80107D14 FFFF8224 */  addiu      $v0, $a0, -0x1
    /* 5518 80107D18 40110200 */  sll        $v0, $v0, 5
    /* 551C 80107D1C 21104900 */  addu       $v0, $v0, $t1
    /* 5520 80107D20 03004290 */  lbu        $v0, 0x3($v0)
    /* 5524 80107D24 0000648C */  lw         $a0, 0x0($v1)
    /* 5528 80107D28 02004014 */  bnez       $v0, .L80107D34
    /* 552C 80107D2C 00CA8234 */   ori       $v0, $a0, 0xCA00
    /* 5530 80107D30 00CC8234 */  ori        $v0, $a0, 0xCC00
  .L80107D34:
    /* 5534 80107D34 000062AC */  sw         $v0, 0x0($v1)
  .L80107D38:
    /* 5538 80107D38 1180023C */  lui        $v0, %hi(D_8010BCA4)
    /* 553C 80107D3C A4BC4224 */  addiu      $v0, $v0, %lo(D_8010BCA4)
    /* 5540 80107D40 21108202 */  addu       $v0, $s4, $v0
    /* 5544 80107D44 000050A0 */  sb         $s0, 0x0($v0)
    /* 5548 80107D48 6000D626 */  addiu      $s6, $s6, 0x60
    /* 554C 80107D4C 08007326 */  addiu      $s3, $s3, 0x8
    /* 5550 80107D50 01009426 */  addiu      $s4, $s4, 0x1
  .L80107D54:
    /* 5554 80107D54 0100B526 */  addiu      $s5, $s5, 0x1
    /* 5558 80107D58 1000A22A */  slti       $v0, $s5, 0x10
    /* 555C 80107D5C B4FF4014 */  bnez       $v0, .L80107C30
    /* 5560 80107D60 0680093C */   lui       $t1, %hi(vs_main_inventoryIndices)
    /* 5564 80107D64 21208002 */  addu       $a0, $s4, $zero
    /* 5568 80107D68 0F80023C */  lui        $v0, %hi(vs_battle_rowTypeBuf)
    /* 556C 80107D6C 844E468C */  lw         $a2, %lo(vs_battle_rowTypeBuf)($v0)
    /* 5570 80107D70 FF0C040C */  jal        _populateItemsList
    /* 5574 80107D74 2128C003 */   addu      $a1, $fp, $zero
    /* 5578 80107D78 180F010C */  jal        vs_main_freeHeapR
    /* 557C 80107D7C 2120E002 */   addu      $a0, $s7, $zero
    /* 5580 80107D80 1180033C */  lui        $v1, %hi(D_8010BC60)
    /* 5584 80107D84 01000224 */  addiu      $v0, $zero, 0x1
    /* 5588 80107D88 A21F0408 */  j          .L80107E88
    /* 558C 80107D8C 60BC62A0 */   sb        $v0, %lo(D_8010BC60)($v1)
  .L80107D90:
    /* 5590 80107D90 1180033C */  lui        $v1, %hi(D_8010BCA4)
    /* 5594 80107D94 1180023C */  lui        $v0, %hi(D_8010BCA2)
    /* 5598 80107D98 1180043C */  lui        $a0, %hi(D_8010BC9C)
    /* 559C 80107D9C A2BC4290 */  lbu        $v0, %lo(D_8010BCA2)($v0)
    /* 55A0 80107DA0 9CBC848C */  lw         $a0, %lo(D_8010BC9C)($a0)
    /* 55A4 80107DA4 A4BC6324 */  addiu      $v1, $v1, %lo(D_8010BCA4)
    /* 55A8 80107DA8 21104400 */  addu       $v0, $v0, $a0
    /* 55AC 80107DAC 21104300 */  addu       $v0, $v0, $v1
    /* 55B0 80107DB0 00005090 */  lbu        $s0, 0x0($v0)
    /* 55B4 80107DB4 00000000 */  nop
    /* 55B8 80107DB8 05000012 */  beqz       $s0, .L80107DD0
    /* 55BC 80107DBC 00000000 */   nop
    /* 55C0 80107DC0 01F5030C */  jal        vs_mainMenu_setUiBladeStats
    /* 55C4 80107DC4 21200002 */   addu      $a0, $s0, $zero
    /* 55C8 80107DC8 7C1F0408 */  j          .L80107DF0
    /* 55CC 80107DCC 1180043C */   lui       $a0, %hi(D_8010BC9C)
  .L80107DD0:
    /* 55D0 80107DD0 88F4030C */  jal        vs_mainMenu_resetStats
    /* 55D4 80107DD4 00000000 */   nop
    /* 55D8 80107DD8 21200000 */  addu       $a0, $zero, $zero
    /* 55DC 80107DDC 21288000 */  addu       $a1, $a0, $zero
    /* 55E0 80107DE0 21308000 */  addu       $a2, $a0, $zero
    /* 55E4 80107DE4 43EF030C */  jal        vs_mainMenu_setRangeRisk
    /* 55E8 80107DE8 01000724 */   addiu     $a3, $zero, 0x1
    /* 55EC 80107DEC 1180043C */  lui        $a0, %hi(D_8010BC9C)
  .L80107DF0:
    /* 55F0 80107DF0 1180023C */  lui        $v0, %hi(D_8010BCA2)
    /* 55F4 80107DF4 1180033C */  lui        $v1, %hi(D_8010BCA0)
    /* 55F8 80107DF8 A2BC4290 */  lbu        $v0, %lo(D_8010BCA2)($v0)
    /* 55FC 80107DFC 9CBC848C */  lw         $a0, %lo(D_8010BC9C)($a0)
    /* 5600 80107E00 A0BC6590 */  lbu        $a1, %lo(D_8010BCA0)($v1)
    /* 5604 80107E04 79FE030C */  jal        vs_mainMenu_printInformation
    /* 5608 80107E08 21208200 */   addu      $a0, $a0, $v0
    /* 560C 80107E0C 820D040C */  jal        func_80103608
    /* 5610 80107E10 02000424 */   addiu     $a0, $zero, 0x2
    /* 5614 80107E14 780D040C */  jal        func_801035E0
    /* 5618 80107E18 1180103C */   lui       $s0, %hi(D_8010BC5C)
    /* 561C 80107E1C 01004224 */  addiu      $v0, $v0, 0x1
    /* 5620 80107E20 19004010 */  beqz       $v0, .L80107E88
    /* 5624 80107E24 5CBC02AE */   sw        $v0, %lo(D_8010BC5C)($s0)
    /* 5628 80107E28 38EA030C */  jal        vs_mainMenu_clearMenuExcept
    /* 562C 80107E2C 28000424 */   addiu     $a0, $zero, 0x28
    /* 5630 80107E30 5CBC038E */  lw         $v1, %lo(D_8010BC5C)($s0)
    /* 5634 80107E34 FEFF0224 */  addiu      $v0, $zero, -0x2
    /* 5638 80107E38 14006210 */  beq        $v1, $v0, .L80107E8C
    /* 563C 80107E3C 00000000 */   nop
    /* 5640 80107E40 06006018 */  blez       $v1, .L80107E5C
    /* 5644 80107E44 1180023C */   lui       $v0, %hi(D_8010BCA4)
    /* 5648 80107E48 A4BC4224 */  addiu      $v0, $v0, %lo(D_8010BCA4)
    /* 564C 80107E4C 21106200 */  addu       $v0, $v1, $v0
    /* 5650 80107E50 FFFF4290 */  lbu        $v0, -0x1($v0)
    /* 5654 80107E54 00000000 */  nop
    /* 5658 80107E58 5CBC02AE */  sw         $v0, %lo(D_8010BC5C)($s0)
  .L80107E5C:
    /* 565C 80107E5C 1180033C */  lui        $v1, %hi(D_8010BC60)
    /* 5660 80107E60 02000224 */  addiu      $v0, $zero, 0x2
    /* 5664 80107E64 A21F0408 */  j          .L80107E88
    /* 5668 80107E68 60BC62A0 */   sb        $v0, %lo(D_8010BC60)($v1)
  .L80107E6C:
    /* 566C 80107E6C 74EA030C */  jal        vs_mainmenu_ready
    /* 5670 80107E70 00000000 */   nop
    /* 5674 80107E74 04004010 */  beqz       $v0, .L80107E88
    /* 5678 80107E78 1180023C */   lui       $v0, %hi(D_8010BC5C)
    /* 567C 80107E7C 5CBC428C */  lw         $v0, %lo(D_8010BC5C)($v0)
    /* 5680 80107E80 A31F0408 */  j          .L80107E8C
    /* 5684 80107E84 00000000 */   nop
  .L80107E88:
    /* 5688 80107E88 21100000 */  addu       $v0, $zero, $zero
  .L80107E8C:
    /* 568C 80107E8C 3C00BF8F */  lw         $ra, 0x3C($sp)
    /* 5690 80107E90 3800BE8F */  lw         $fp, 0x38($sp)
    /* 5694 80107E94 3400B78F */  lw         $s7, 0x34($sp)
    /* 5698 80107E98 3000B68F */  lw         $s6, 0x30($sp)
    /* 569C 80107E9C 2C00B58F */  lw         $s5, 0x2C($sp)
    /* 56A0 80107EA0 2800B48F */  lw         $s4, 0x28($sp)
    /* 56A4 80107EA4 2400B38F */  lw         $s3, 0x24($sp)
    /* 56A8 80107EA8 2000B28F */  lw         $s2, 0x20($sp)
    /* 56AC 80107EAC 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 56B0 80107EB0 1800B08F */  lw         $s0, 0x18($sp)
    /* 56B4 80107EB4 0800E003 */  jr         $ra
    /* 56B8 80107EB8 4000BD27 */   addiu     $sp, $sp, 0x40
endlabel func_80107AD4
