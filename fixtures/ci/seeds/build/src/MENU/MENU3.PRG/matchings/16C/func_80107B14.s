nonmatching func_80107B14, 0x4FC

glabel func_80107B14
    /* 5314 80107B14 C0FFBD27 */  addiu      $sp, $sp, -0x40
    /* 5318 80107B18 3800BEAF */  sw         $fp, 0x38($sp)
    /* 531C 80107B1C 21F0A003 */  addu       $fp, $sp, $zero
    /* 5320 80107B20 3C00BFAF */  sw         $ra, 0x3C($sp)
    /* 5324 80107B24 3400B7AF */  sw         $s7, 0x34($sp)
    /* 5328 80107B28 3000B6AF */  sw         $s6, 0x30($sp)
    /* 532C 80107B2C 2C00B5AF */  sw         $s5, 0x2C($sp)
    /* 5330 80107B30 2800B4AF */  sw         $s4, 0x28($sp)
    /* 5334 80107B34 2400B3AF */  sw         $s3, 0x24($sp)
    /* 5338 80107B38 2000B2AF */  sw         $s2, 0x20($sp)
    /* 533C 80107B3C 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 5340 80107B40 2B008010 */  beqz       $a0, .L80107BF0
    /* 5344 80107B44 1800B0AF */   sw        $s0, 0x18($sp)
    /* 5348 80107B48 1180023C */  lui        $v0, %hi(D_801096A2)
    /* 534C 80107B4C A29644A0 */  sb         $a0, %lo(D_801096A2)($v0)
    /* 5350 80107B50 21880000 */  addu       $s1, $zero, $zero
    /* 5354 80107B54 0680023C */  lui        $v0, %hi(vs_main_inventoryIndices)
    /* 5358 80107B58 D8194624 */  addiu      $a2, $v0, %lo(vs_main_inventoryIndices)
    /* 535C 80107B5C 0680023C */  lui        $v0, %hi(vs_battle_inventory)
    /* 5360 80107B60 68014524 */  addiu      $a1, $v0, %lo(vs_battle_inventory)
    /* 5364 80107B64 21102602 */  addu       $v0, $s1, $a2
  .L80107B68:
    /* 5368 80107B68 30005090 */  lbu        $s0, 0x30($v0)
    /* 536C 80107B6C 00000000 */  nop
    /* 5370 80107B70 09000012 */  beqz       $s0, .L80107B98
    /* 5374 80107B74 FFFF0226 */   addiu     $v0, $s0, -0x1
    /* 5378 80107B78 80180200 */  sll        $v1, $v0, 2
    /* 537C 80107B7C 21186200 */  addu       $v1, $v1, $v0
    /* 5380 80107B80 C0180300 */  sll        $v1, $v1, 3
    /* 5384 80107B84 21186500 */  addu       $v1, $v1, $a1
    /* 5388 80107B88 66066290 */  lbu        $v0, 0x666($v1)
    /* 538C 80107B8C 00000000 */  nop
    /* 5390 80107B90 06004410 */  beq        $v0, $a0, .L80107BAC
    /* 5394 80107B94 10000224 */   addiu     $v0, $zero, 0x10
  .L80107B98:
    /* 5398 80107B98 01003126 */  addiu      $s1, $s1, 0x1
    /* 539C 80107B9C 1000222A */  slti       $v0, $s1, 0x10
    /* 53A0 80107BA0 F1FF4014 */  bnez       $v0, .L80107B68
    /* 53A4 80107BA4 21102602 */   addu      $v0, $s1, $a2
    /* 53A8 80107BA8 10000224 */  addiu      $v0, $zero, 0x10
  .L80107BAC:
    /* 53AC 80107BAC 03002216 */  bne        $s1, $v0, .L80107BBC
    /* 53B0 80107BB0 21200002 */   addu      $a0, $s0, $zero
    /* 53B4 80107BB4 21800000 */  addu       $s0, $zero, $zero
    /* 53B8 80107BB8 21200002 */  addu       $a0, $s0, $zero
  .L80107BBC:
    /* 53BC 80107BBC 1180023C */  lui        $v0, %hi(D_801096A1)
    /* 53C0 80107BC0 C0F5030C */  jal        vs_mainMenu_setArmorStats
    /* 53C4 80107BC4 A19644A0 */   sb        $a0, %lo(D_801096A1)($v0)
    /* 53C8 80107BC8 F5EE030C */  jal        vs_mainMenu_drawClassAffinityType
    /* 53CC 80107BCC 07000424 */   addiu     $a0, $zero, 0x7
    /* 53D0 80107BD0 9AF0030C */  jal        vs_mainMenu_drawDpPpbars
    /* 53D4 80107BD4 01000424 */   addiu     $a0, $zero, 0x1
    /* 53D8 80107BD8 A9EF030C */  jal        vs_mainMenu_renderEquipStats
    /* 53DC 80107BDC 01000424 */   addiu     $a0, $zero, 0x1
    /* 53E0 80107BE0 21100000 */  addu       $v0, $zero, $zero
    /* 53E4 80107BE4 1180033C */  lui        $v1, %hi(D_801096A0)
    /* 53E8 80107BE8 F71F0408 */  j          .L80107FDC
    /* 53EC 80107BEC A09660A0 */   sb        $zero, %lo(D_801096A0)($v1)
  .L80107BF0:
    /* 53F0 80107BF0 1180123C */  lui        $s2, %hi(D_801096A0)
    /* 53F4 80107BF4 A0965092 */  lbu        $s0, %lo(D_801096A0)($s2)
    /* 53F8 80107BF8 01000224 */  addiu      $v0, $zero, 0x1
    /* 53FC 80107BFC AD000212 */  beq        $s0, $v0, .L80107EB4
    /* 5400 80107C00 0200022A */   slti      $v0, $s0, 0x2
    /* 5404 80107C04 05004010 */  beqz       $v0, .L80107C1C
    /* 5408 80107C08 02000224 */   addiu     $v0, $zero, 0x2
    /* 540C 80107C0C 09000012 */  beqz       $s0, .L80107C34
    /* 5410 80107C10 21100000 */   addu      $v0, $zero, $zero
    /* 5414 80107C14 F71F0408 */  j          .L80107FDC
    /* 5418 80107C18 00000000 */   nop
  .L80107C1C:
    /* 541C 80107C1C E5000212 */  beq        $s0, $v0, .L80107FB4
    /* 5420 80107C20 03000224 */   addiu     $v0, $zero, 0x3
    /* 5424 80107C24 E5000212 */  beq        $s0, $v0, .L80107FBC
    /* 5428 80107C28 21100000 */   addu      $v0, $zero, $zero
    /* 542C 80107C2C F71F0408 */  j          .L80107FDC
    /* 5430 80107C30 00000000 */   nop
  .L80107C34:
    /* 5434 80107C34 74EA030C */  jal        vs_mainmenu_ready
    /* 5438 80107C38 00000000 */   nop
    /* 543C 80107C3C E6004010 */  beqz       $v0, .L80107FD8
    /* 5440 80107C40 04000424 */   addiu     $a0, $zero, 0x4
    /* 5444 80107C44 9BFA030C */  jal        vs_mainMenu_getItemCount
    /* 5448 80107C48 21280000 */   addu      $a1, $zero, $zero
    /* 544C 80107C4C 21B84000 */  addu       $s7, $v0, $zero
    /* 5450 80107C50 21280000 */  addu       $a1, $zero, $zero
    /* 5454 80107C54 2188A000 */  addu       $s1, $a1, $zero
    /* 5458 80107C58 1180023C */  lui        $v0, %hi(D_801096A2)
    /* 545C 80107C5C A2964490 */  lbu        $a0, %lo(D_801096A2)($v0)
    /* 5460 80107C60 0680023C */  lui        $v0, %hi(vs_battle_inventory)
    /* 5464 80107C64 68014324 */  addiu      $v1, $v0, %lo(vs_battle_inventory)
  .L80107C68:
    /* 5468 80107C68 66066290 */  lbu        $v0, 0x666($v1)
    /* 546C 80107C6C 00000000 */  nop
    /* 5470 80107C70 02004414 */  bne        $v0, $a0, .L80107C7C
    /* 5474 80107C74 00000000 */   nop
    /* 5478 80107C78 01000524 */  addiu      $a1, $zero, 0x1
  .L80107C7C:
    /* 547C 80107C7C 01003126 */  addiu      $s1, $s1, 0x1
    /* 5480 80107C80 1000222A */  slti       $v0, $s1, 0x10
    /* 5484 80107C84 F8FF4014 */  bnez       $v0, .L80107C68
    /* 5488 80107C88 28006324 */   addiu     $v1, $v1, 0x28
    /* 548C 80107C8C 0100E226 */  addiu      $v0, $s7, 0x1
    /* 5490 80107C90 40180200 */  sll        $v1, $v0, 1
    /* 5494 80107C94 21186200 */  addu       $v1, $v1, $v0
    /* 5498 80107C98 001A0300 */  sll        $v1, $v1, 8
    /* 549C 80107C9C C2180300 */  srl        $v1, $v1, 3
    /* 54A0 80107CA0 23E8A303 */  subu       $sp, $sp, $v1
    /* 54A4 80107CA4 1000B327 */  addiu      $s3, $sp, 0x10
    /* 54A8 80107CA8 80190200 */  sll        $v1, $v0, 6
    /* 54AC 80107CAC C2180300 */  srl        $v1, $v1, 3
    /* 54B0 80107CB0 23E8A303 */  subu       $sp, $sp, $v1
    /* 54B4 80107CB4 1000A827 */  addiu      $t0, $sp, 0x10
    /* 54B8 80107CB8 1000C8AF */  sw         $t0, 0x10($fp)
    /* 54BC 80107CBC 40110200 */  sll        $v0, $v0, 5
    /* 54C0 80107CC0 C2100200 */  srl        $v0, $v0, 3
    /* 54C4 80107CC4 07004224 */  addiu      $v0, $v0, 0x7
    /* 54C8 80107CC8 C2100200 */  srl        $v0, $v0, 3
    /* 54CC 80107CCC C0100200 */  sll        $v0, $v0, 3
    /* 54D0 80107CD0 23E8A203 */  subu       $sp, $sp, $v0
    /* 54D4 80107CD4 1300A014 */  bnez       $a1, .L80107D24
    /* 54D8 80107CD8 1000B527 */   addiu     $s5, $sp, 0x10
    /* 54DC 80107CDC 21880000 */  addu       $s1, $zero, $zero
    /* 54E0 80107CE0 1180023C */  lui        $v0, %hi(_menuText)
    /* 54E4 80107CE4 B8934524 */  addiu      $a1, $v0, %lo(_menuText)
    /* 54E8 80107CE8 21200001 */  addu       $a0, $t0, $zero
    /* 54EC 80107CEC 28000324 */  addiu      $v1, $zero, 0x28
  .L80107CF0:
    /* 54F0 80107CF0 21106500 */  addu       $v0, $v1, $a1
    /* 54F4 80107CF4 02006324 */  addiu      $v1, $v1, 0x2
    /* 54F8 80107CF8 00004294 */  lhu        $v0, 0x0($v0)
    /* 54FC 80107CFC 01003126 */  addiu      $s1, $s1, 0x1
    /* 5500 80107D00 40100200 */  sll        $v0, $v0, 1
    /* 5504 80107D04 21104500 */  addu       $v0, $v0, $a1
    /* 5508 80107D08 000082AC */  sw         $v0, 0x0($a0)
    /* 550C 80107D0C 0200222A */  slti       $v0, $s1, 0x2
    /* 5510 80107D10 F7FF4014 */  bnez       $v0, .L80107CF0
    /* 5514 80107D14 04008424 */   addiu     $a0, $a0, 0x4
    /* 5518 80107D18 01000224 */  addiu      $v0, $zero, 0x1
    /* 551C 80107D1C 6E1F0408 */  j          .L80107DB8
    /* 5520 80107D20 0000A2AE */   sw        $v0, 0x0($s5)
  .L80107D24:
    /* 5524 80107D24 2400E01A */  blez       $s7, .L80107DB8
    /* 5528 80107D28 21880000 */   addu      $s1, $zero, $zero
    /* 552C 80107D2C 0680023C */  lui        $v0, %hi(vs_main_inventoryIndices)
    /* 5530 80107D30 D8195624 */  addiu      $s6, $v0, %lo(vs_main_inventoryIndices)
    /* 5534 80107D34 0680023C */  lui        $v0, %hi(vs_battle_inventory)
    /* 5538 80107D38 68015224 */  addiu      $s2, $v0, %lo(vs_battle_inventory)
    /* 553C 80107D3C 18065426 */  addiu      $s4, $s2, 0x618
    /* 5540 80107D40 21103602 */  addu       $v0, $s1, $s6
  .L80107D44:
    /* 5544 80107D44 30005090 */  lbu        $s0, 0x30($v0)
    /* 5548 80107D48 00000000 */  nop
    /* 554C 80107D4C 16000012 */  beqz       $s0, .L80107DA8
    /* 5550 80107D50 FFFF0326 */   addiu     $v1, $s0, -0x1
    /* 5554 80107D54 80100300 */  sll        $v0, $v1, 2
    /* 5558 80107D58 21104300 */  addu       $v0, $v0, $v1
    /* 555C 80107D5C C0100200 */  sll        $v0, $v0, 3
    /* 5560 80107D60 21105200 */  addu       $v0, $v0, $s2
    /* 5564 80107D64 1180033C */  lui        $v1, %hi(D_801096A2)
    /* 5568 80107D68 66064490 */  lbu        $a0, 0x666($v0)
    /* 556C 80107D6C A2966290 */  lbu        $v0, %lo(D_801096A2)($v1)
    /* 5570 80107D70 00000000 */  nop
    /* 5574 80107D74 0C008214 */  bne        $a0, $v0, .L80107DA8
    /* 5578 80107D78 80201000 */   sll       $a0, $s0, 2
    /* 557C 80107D7C 21209000 */  addu       $a0, $a0, $s0
    /* 5580 80107D80 C0200400 */  sll        $a0, $a0, 3
    /* 5584 80107D84 21209400 */  addu       $a0, $a0, $s4
    /* 5588 80107D88 2130A002 */  addu       $a2, $s5, $zero
    /* 558C 80107D8C 1000C58F */  lw         $a1, 0x10($fp)
    /* 5590 80107D90 21F4030C */  jal        vs_mainMenu_initUiArmor
    /* 5594 80107D94 21386002 */   addu      $a3, $s3, $zero
    /* 5598 80107D98 0000A28E */  lw         $v0, 0x0($s5)
    /* 559C 80107D9C C01C1000 */  sll        $v1, $s0, 19
    /* 55A0 80107DA0 25104300 */  or         $v0, $v0, $v1
    /* 55A4 80107DA4 0000A2AE */  sw         $v0, 0x0($s5)
  .L80107DA8:
    /* 55A8 80107DA8 01003126 */  addiu      $s1, $s1, 0x1
    /* 55AC 80107DAC 2A103702 */  slt        $v0, $s1, $s7
    /* 55B0 80107DB0 E4FF4014 */  bnez       $v0, .L80107D44
    /* 55B4 80107DB4 21103602 */   addu      $v0, $s1, $s6
  .L80107DB8:
    /* 55B8 80107DB8 01001624 */  addiu      $s6, $zero, 0x1
    /* 55BC 80107DBC 3500E01A */  blez       $s7, .L80107E94
    /* 55C0 80107DC0 21880000 */   addu      $s1, $zero, $zero
    /* 55C4 80107DC4 0400B226 */  addiu      $s2, $s5, 0x4
    /* 55C8 80107DC8 1000C88F */  lw         $t0, 0x10($fp)
    /* 55CC 80107DCC 60007426 */  addiu      $s4, $s3, 0x60
    /* 55D0 80107DD0 08001325 */  addiu      $s3, $t0, 0x8
    /* 55D4 80107DD4 0680083C */  lui        $t0, %hi(vs_main_inventoryIndices)
  .L80107DD8:
    /* 55D8 80107DD8 D8190825 */  addiu      $t0, $t0, %lo(vs_main_inventoryIndices)
    /* 55DC 80107DDC 21102802 */  addu       $v0, $s1, $t0
    /* 55E0 80107DE0 30005090 */  lbu        $s0, 0x30($v0)
    /* 55E4 80107DE4 00000000 */  nop
    /* 55E8 80107DE8 26000012 */  beqz       $s0, .L80107E84
    /* 55EC 80107DEC FFFF0226 */   addiu     $v0, $s0, -0x1
    /* 55F0 80107DF0 80180200 */  sll        $v1, $v0, 2
    /* 55F4 80107DF4 21186200 */  addu       $v1, $v1, $v0
    /* 55F8 80107DF8 C0180300 */  sll        $v1, $v1, 3
    /* 55FC 80107DFC 1180023C */  lui        $v0, %hi(D_801096A2)
    /* 5600 80107E00 0680083C */  lui        $t0, %hi(vs_battle_inventory)
    /* 5604 80107E04 68010825 */  addiu      $t0, $t0, %lo(vs_battle_inventory)
    /* 5608 80107E08 21206800 */  addu       $a0, $v1, $t0
    /* 560C 80107E0C 1180083C */  lui        $t0, %hi(D_80109624)
    /* 5610 80107E10 24960825 */  addiu      $t0, $t0, %lo(D_80109624)
    /* 5614 80107E14 A2964290 */  lbu        $v0, %lo(D_801096A2)($v0)
    /* 5618 80107E18 43068390 */  lbu        $v1, 0x643($a0)
    /* 561C 80107E1C 21104800 */  addu       $v0, $v0, $t0
    /* 5620 80107E20 00004290 */  lbu        $v0, 0x0($v0)
    /* 5624 80107E24 00000000 */  nop
    /* 5628 80107E28 16006214 */  bne        $v1, $v0, .L80107E84
    /* 562C 80107E2C 00000000 */   nop
    /* 5630 80107E30 66068290 */  lbu        $v0, 0x666($a0)
    /* 5634 80107E34 00000000 */  nop
    /* 5638 80107E38 12004014 */  bnez       $v0, .L80107E84
    /* 563C 80107E3C 80201000 */   sll       $a0, $s0, 2
    /* 5640 80107E40 21209000 */  addu       $a0, $a0, $s0
    /* 5644 80107E44 C0200400 */  sll        $a0, $a0, 3
    /* 5648 80107E48 0680083C */  lui        $t0, %hi(D_80060780)
    /* 564C 80107E4C 80070825 */  addiu      $t0, $t0, %lo(D_80060780)
    /* 5650 80107E50 21208800 */  addu       $a0, $a0, $t0
    /* 5654 80107E54 21286002 */  addu       $a1, $s3, $zero
    /* 5658 80107E58 21304002 */  addu       $a2, $s2, $zero
    /* 565C 80107E5C 21F4030C */  jal        vs_mainMenu_initUiArmor
    /* 5660 80107E60 21388002 */   addu      $a3, $s4, $zero
    /* 5664 80107E64 60009426 */  addiu      $s4, $s4, 0x60
    /* 5668 80107E68 08007326 */  addiu      $s3, $s3, 0x8
    /* 566C 80107E6C 0100D626 */  addiu      $s6, $s6, 0x1
    /* 5670 80107E70 0000428E */  lw         $v0, 0x0($s2)
    /* 5674 80107E74 C01C1000 */  sll        $v1, $s0, 19
    /* 5678 80107E78 25104300 */  or         $v0, $v0, $v1
    /* 567C 80107E7C 000042AE */  sw         $v0, 0x0($s2)
    /* 5680 80107E80 04005226 */  addiu      $s2, $s2, 0x4
  .L80107E84:
    /* 5684 80107E84 01003126 */  addiu      $s1, $s1, 0x1
    /* 5688 80107E88 2A103702 */  slt        $v0, $s1, $s7
    /* 568C 80107E8C D2FF4014 */  bnez       $v0, .L80107DD8
    /* 5690 80107E90 0680083C */   lui       $t0, %hi(vs_main_inventoryIndices)
  .L80107E94:
    /* 5694 80107E94 2120C002 */  addu       $a0, $s6, $zero
    /* 5698 80107E98 1000C58F */  lw         $a1, 0x10($fp)
    /* 569C 80107E9C E418040C */  jal        func_80106390
    /* 56A0 80107EA0 2130A002 */   addu      $a2, $s5, $zero
    /* 56A4 80107EA4 1180033C */  lui        $v1, %hi(D_801096A0)
    /* 56A8 80107EA8 01000224 */  addiu      $v0, $zero, 0x1
    /* 56AC 80107EAC F61F0408 */  j          .L80107FD8
    /* 56B0 80107EB0 A09662A0 */   sb        $v0, %lo(D_801096A0)($v1)
  .L80107EB4:
    /* 56B4 80107EB4 1180133C */  lui        $s3, %hi(D_80109767)
    /* 56B8 80107EB8 67976492 */  lbu        $a0, %lo(D_80109767)($s3)
    /* 56BC 80107EBC C0F5030C */  jal        vs_mainMenu_setArmorStats
    /* 56C0 80107EC0 1180113C */   lui       $s1, %hi(D_8010969C)
    /* 56C4 80107EC4 6719040C */  jal        func_8010659C
    /* 56C8 80107EC8 01000424 */   addiu     $a0, $zero, 0x1
    /* 56CC 80107ECC 5D19040C */  jal        func_80106574
    /* 56D0 80107ED0 00000000 */   nop
    /* 56D4 80107ED4 01004224 */  addiu      $v0, $v0, 0x1
    /* 56D8 80107ED8 3F004010 */  beqz       $v0, .L80107FD8
    /* 56DC 80107EDC 9C9622AE */   sw        $v0, %lo(D_8010969C)($s1)
    /* 56E0 80107EE0 38EA030C */  jal        vs_mainMenu_clearMenuExcept
    /* 56E4 80107EE4 28000424 */   addiu     $a0, $zero, 0x28
    /* 56E8 80107EE8 04EA030C */  jal        vs_mainMenu_menuItemFlyoutLeft
    /* 56EC 80107EEC FFFF0424 */   addiu     $a0, $zero, -0x1
    /* 56F0 80107EF0 F5EE030C */  jal        vs_mainMenu_drawClassAffinityType
    /* 56F4 80107EF4 FFFF0424 */   addiu     $a0, $zero, -0x1
    /* 56F8 80107EF8 9AF0030C */  jal        vs_mainMenu_drawDpPpbars
    /* 56FC 80107EFC 04000424 */   addiu     $a0, $zero, 0x4
    /* 5700 80107F00 A9EF030C */  jal        vs_mainMenu_renderEquipStats
    /* 5704 80107F04 02000424 */   addiu     $a0, $zero, 0x2
    /* 5708 80107F08 9C96228E */  lw         $v0, %lo(D_8010969C)($s1)
    /* 570C 80107F0C 00000000 */  nop
    /* 5710 80107F10 04004104 */  bgez       $v0, .L80107F24
    /* 5714 80107F14 1180033C */   lui       $v1, %hi(D_801096A1)
    /* 5718 80107F18 03000224 */  addiu      $v0, $zero, 0x3
    /* 571C 80107F1C F61F0408 */  j          .L80107FD8
    /* 5720 80107F20 A09642A2 */   sb        $v0, %lo(D_801096A0)($s2)
  .L80107F24:
    /* 5724 80107F24 A1966290 */  lbu        $v0, %lo(D_801096A1)($v1)
    /* 5728 80107F28 00000000 */  nop
    /* 572C 80107F2C 09004010 */  beqz       $v0, .L80107F54
    /* 5730 80107F30 0680043C */   lui       $a0, %hi(vs_battle_inventory)
    /* 5734 80107F34 21184000 */  addu       $v1, $v0, $zero
    /* 5738 80107F38 68018424 */  addiu      $a0, $a0, %lo(vs_battle_inventory)
    /* 573C 80107F3C FFFF6324 */  addiu      $v1, $v1, -0x1
    /* 5740 80107F40 80100300 */  sll        $v0, $v1, 2
    /* 5744 80107F44 21104300 */  addu       $v0, $v0, $v1
    /* 5748 80107F48 C0100200 */  sll        $v0, $v0, 3
    /* 574C 80107F4C 21104400 */  addu       $v0, $v0, $a0
    /* 5750 80107F50 660640A0 */  sb         $zero, 0x666($v0)
  .L80107F54:
    /* 5754 80107F54 9C96228E */  lw         $v0, %lo(D_8010969C)($s1)
    /* 5758 80107F58 00000000 */  nop
    /* 575C 80107F5C 04005014 */  bne        $v0, $s0, .L80107F70
    /* 5760 80107F60 1180023C */   lui       $v0, %hi(D_801096A2)
    /* 5764 80107F64 A2964490 */  lbu        $a0, %lo(D_801096A2)($v0)
    /* 5768 80107F68 E71F0408 */  j          .L80107F9C
    /* 576C 80107F6C 21280000 */   addu      $a1, $zero, $zero
  .L80107F70:
    /* 5770 80107F70 1180043C */  lui        $a0, %hi(D_801096A2)
    /* 5774 80107F74 67976292 */  lbu        $v0, %lo(D_80109767)($s3)
    /* 5778 80107F78 A2968390 */  lbu        $v1, %lo(D_801096A2)($a0)
    /* 577C 80107F7C 80280200 */  sll        $a1, $v0, 2
    /* 5780 80107F80 2128A200 */  addu       $a1, $a1, $v0
    /* 5784 80107F84 C0280500 */  sll        $a1, $a1, 3
    /* 5788 80107F88 0680023C */  lui        $v0, %hi(D_80060780)
    /* 578C 80107F8C 80074224 */  addiu      $v0, $v0, %lo(D_80060780)
    /* 5790 80107F90 2128A200 */  addu       $a1, $a1, $v0
    /* 5794 80107F94 2600A3A0 */  sb         $v1, 0x26($a1)
    /* 5798 80107F98 A2968490 */  lbu        $a0, %lo(D_801096A2)($a0)
  .L80107F9C:
    /* 579C 80107F9C 2EAD010C */  jal        vs_battle_equipArmor
    /* 57A0 80107FA0 FFFF8424 */   addiu     $a0, $a0, -0x1
    /* 57A4 80107FA4 1180033C */  lui        $v1, %hi(D_801096A0)
    /* 57A8 80107FA8 02000224 */  addiu      $v0, $zero, 0x2
    /* 57AC 80107FAC F61F0408 */  j          .L80107FD8
    /* 57B0 80107FB0 A09662A0 */   sb        $v0, %lo(D_801096A0)($v1)
  .L80107FB4:
    /* 57B4 80107FB4 03000224 */  addiu      $v0, $zero, 0x3
    /* 57B8 80107FB8 A09642A2 */  sb         $v0, %lo(D_801096A0)($s2)
  .L80107FBC:
    /* 57BC 80107FBC 74EA030C */  jal        vs_mainmenu_ready
    /* 57C0 80107FC0 00000000 */   nop
    /* 57C4 80107FC4 04004010 */  beqz       $v0, .L80107FD8
    /* 57C8 80107FC8 1180023C */   lui       $v0, %hi(D_8010969C)
    /* 57CC 80107FCC 9C96428C */  lw         $v0, %lo(D_8010969C)($v0)
    /* 57D0 80107FD0 F71F0408 */  j          .L80107FDC
    /* 57D4 80107FD4 00000000 */   nop
  .L80107FD8:
    /* 57D8 80107FD8 21100000 */  addu       $v0, $zero, $zero
  .L80107FDC:
    /* 57DC 80107FDC 21E8C003 */  addu       $sp, $fp, $zero
    /* 57E0 80107FE0 3C00BF8F */  lw         $ra, 0x3C($sp)
    /* 57E4 80107FE4 3800BE8F */  lw         $fp, 0x38($sp)
    /* 57E8 80107FE8 3400B78F */  lw         $s7, 0x34($sp)
    /* 57EC 80107FEC 3000B68F */  lw         $s6, 0x30($sp)
    /* 57F0 80107FF0 2C00B58F */  lw         $s5, 0x2C($sp)
    /* 57F4 80107FF4 2800B48F */  lw         $s4, 0x28($sp)
    /* 57F8 80107FF8 2400B38F */  lw         $s3, 0x24($sp)
    /* 57FC 80107FFC 2000B28F */  lw         $s2, 0x20($sp)
    /* 5800 80108000 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 5804 80108004 1800B08F */  lw         $s0, 0x18($sp)
    /* 5808 80108008 0800E003 */  jr         $ra
    /* 580C 8010800C 4000BD27 */   addiu     $sp, $sp, 0x40
endlabel func_80107B14
