nonmatching func_801072FC, 0x408

glabel func_801072FC
    /* 4AFC 801072FC E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 4B00 80107300 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 4B04 80107304 1800B2AF */  sw         $s2, 0x18($sp)
    /* 4B08 80107308 1400B1AF */  sw         $s1, 0x14($sp)
    /* 4B0C 8010730C 07008010 */  beqz       $a0, .L8010732C
    /* 4B10 80107310 1000B0AF */   sw        $s0, 0x10($sp)
    /* 4B14 80107314 04000424 */  addiu      $a0, $zero, 0x4
    /* 4B18 80107318 4BEA030C */  jal        func_800FA92C
    /* 4B1C 8010731C 01000524 */   addiu     $a1, $zero, 0x1
    /* 4B20 80107320 1180023C */  lui        $v0, %hi(D_8010BC50)
    /* 4B24 80107324 BA1D0408 */  j          .L801076E8
    /* 4B28 80107328 50BC40A0 */   sb        $zero, %lo(D_8010BC50)($v0)
  .L8010732C:
    /* 4B2C 8010732C 1180023C */  lui        $v0, %hi(D_8010BC50)
    /* 4B30 80107330 50BC4390 */  lbu        $v1, %lo(D_8010BC50)($v0)
    /* 4B34 80107334 00000000 */  nop
    /* 4B38 80107338 0500622C */  sltiu      $v0, $v1, 0x5
    /* 4B3C 8010733C EA004010 */  beqz       $v0, .L801076E8
    /* 4B40 80107340 1080023C */   lui       $v0, %hi(jtbl_80102898)
    /* 4B44 80107344 98284224 */  addiu      $v0, $v0, %lo(jtbl_80102898)
    /* 4B48 80107348 80180300 */  sll        $v1, $v1, 2
    /* 4B4C 8010734C 21186200 */  addu       $v1, $v1, $v0
    /* 4B50 80107350 0000628C */  lw         $v0, 0x0($v1)
    /* 4B54 80107354 00000000 */  nop
    /* 4B58 80107358 08004000 */  jr         $v0
    /* 4B5C 8010735C 00000000 */   nop
    /* 4B60 80107360 74EA030C */  jal        vs_mainmenu_ready
    /* 4B64 80107364 00000000 */   nop
    /* 4B68 80107368 E0004010 */  beqz       $v0, .L801076EC
    /* 4B6C 8010736C 21100000 */   addu      $v0, $zero, $zero
    /* 4B70 80107370 160B040C */  jal        func_80102C58
    /* 4B74 80107374 01000424 */   addiu     $a0, $zero, 0x1
    /* 4B78 80107378 1080023C */  lui        $v0, %hi(vs_mainMenu_menu12Text)
    /* 4B7C 8010737C A424448C */  lw         $a0, %lo(vs_mainMenu_menu12Text)($v0)
    /* 4B80 80107380 01FF030C */  jal        vs_mainmenu_setInformationMessage
    /* 4B84 80107384 04068424 */   addiu     $a0, $a0, 0x604
    /* 4B88 80107388 1180033C */  lui        $v1, %hi(D_8010BC50)
    /* 4B8C 8010738C 01000224 */  addiu      $v0, $zero, 0x1
    /* 4B90 80107390 BA1D0408 */  j          .L801076E8
    /* 4B94 80107394 50BC62A0 */   sb        $v0, %lo(D_8010BC50)($v1)
    /* 4B98 80107398 160B040C */  jal        func_80102C58
    /* 4B9C 8010739C 21200000 */   addu      $a0, $zero, $zero
    /* 4BA0 801073A0 21804000 */  addu       $s0, $v0, $zero
    /* 4BA4 801073A4 D0000012 */  beqz       $s0, .L801076E8
    /* 4BA8 801073A8 1180023C */   lui       $v0, %hi(D_8010BC4C)
    /* 4BAC 801073AC FFFF0324 */  addiu      $v1, $zero, -0x1
    /* 4BB0 801073B0 4CBC43AC */  sw         $v1, %lo(D_8010BC4C)($v0)
    /* 4BB4 801073B4 01000224 */  addiu      $v0, $zero, 0x1
    /* 4BB8 801073B8 08000216 */  bne        $s0, $v0, .L801073DC
    /* 4BBC 801073BC 03000224 */   addiu     $v0, $zero, 0x3
    /* 4BC0 801073C0 7E000424 */  addiu      $a0, $zero, 0x7E
    /* 4BC4 801073C4 6216010C */  jal        vs_main_playSfxDefault
    /* 4BC8 801073C8 0D000524 */   addiu     $a1, $zero, 0xD
    /* 4BCC 801073CC 1180033C */  lui        $v1, %hi(D_8010BC50)
    /* 4BD0 801073D0 02000224 */  addiu      $v0, $zero, 0x2
    /* 4BD4 801073D4 BA1D0408 */  j          .L801076E8
    /* 4BD8 801073D8 50BC62A0 */   sb        $v0, %lo(D_8010BC50)($v1)
  .L801073DC:
    /* 4BDC 801073DC 05000216 */  bne        $s0, $v0, .L801073F4
    /* 4BE0 801073E0 00000000 */   nop
    /* 4BE4 801073E4 BA00030C */  jal        vs_battle_playMenuLeaveSfx
    /* 4BE8 801073E8 00000000 */   nop
    /* 4BEC 801073EC BB1D0408 */  j          .L801076EC
    /* 4BF0 801073F0 FEFF0224 */   addiu     $v0, $zero, -0x2
  .L801073F4:
    /* 4BF4 801073F4 F2FE030C */  jal        func_800FFBC8
    /* 4BF8 801073F8 00000000 */   nop
    /* 4BFC 801073FC 28EA030C */  jal        vs_mainMenu_menuItemFlyoutRight
    /* 4C00 80107400 0E000424 */   addiu     $a0, $zero, 0xE
    /* 4C04 80107404 B01D0408 */  j          .L801076C0
    /* 4C08 80107408 1180033C */   lui       $v1, %hi(D_8010BC50)
    /* 4C0C 8010740C 8123030C */  jal        func_800C8E04
    /* 4C10 80107410 03000424 */   addiu     $a0, $zero, 0x3
    /* 4C14 80107414 1080023C */  lui        $v0, %hi(vs_mainMenu_menu12Text)
    /* 4C18 80107418 A424448C */  lw         $a0, %lo(vs_mainMenu_menu12Text)($v0)
    /* 4C1C 8010741C 21800000 */  addu       $s0, $zero, $zero
    /* 4C20 80107420 01FF030C */  jal        vs_mainmenu_setInformationMessage
    /* 4C24 80107424 1A068424 */   addiu     $a0, $a0, 0x61A
    /* 4C28 80107428 0680023C */  lui        $v0, %hi(vs_main_inventoryIndices)
    /* 4C2C 8010742C D8194924 */  addiu      $t1, $v0, %lo(vs_main_inventoryIndices)
    /* 4C30 80107430 0680023C */  lui        $v0, %hi(D_800603BC)
    /* 4C34 80107434 BC034824 */  addiu      $t0, $v0, %lo(D_800603BC)
    /* 4C38 80107438 EB51073C */  lui        $a3, (0x51EB851F >> 16)
    /* 4C3C 8010743C 1F85E734 */  ori        $a3, $a3, (0x51EB851F & 0xFFFF)
    /* 4C40 80107440 21100902 */  addu       $v0, $s0, $t1
  .L80107444:
    /* 4C44 80107444 08004390 */  lbu        $v1, 0x8($v0)
    /* 4C48 80107448 00000000 */  nop
    /* 4C4C 8010744C 17006010 */  beqz       $v1, .L801074AC
    /* 4C50 80107450 40100300 */   sll       $v0, $v1, 1
    /* 4C54 80107454 21104300 */  addu       $v0, $v0, $v1
    /* 4C58 80107458 80100200 */  sll        $v0, $v0, 2
    /* 4C5C 8010745C 23104300 */  subu       $v0, $v0, $v1
    /* 4C60 80107460 80100200 */  sll        $v0, $v0, 2
    /* 4C64 80107464 21284800 */  addu       $a1, $v0, $t0
    /* 4C68 80107468 0400A394 */  lhu        $v1, 0x4($a1)
    /* 4C6C 8010746C 0800A294 */  lhu        $v0, 0x8($a1)
    /* 4C70 80107470 00000000 */  nop
    /* 4C74 80107474 23306200 */  subu       $a2, $v1, $v0
    /* 4C78 80107478 1800C700 */  mult       $a2, $a3
    /* 4C7C 8010747C 0A00A494 */  lhu        $a0, 0xA($a1)
    /* 4C80 80107480 0800A3A4 */  sh         $v1, 0x8($a1)
    /* 4C84 80107484 C31F0600 */  sra        $v1, $a2, 31
    /* 4C88 80107488 10500000 */  mfhi       $t2
    /* 4C8C 8010748C 43110A00 */  sra        $v0, $t2, 5
    /* 4C90 80107490 23104300 */  subu       $v0, $v0, $v1
    /* 4C94 80107494 23308200 */  subu       $a2, $a0, $v0
    /* 4C98 80107498 0300C004 */  bltz       $a2, .L801074A8
    /* 4C9C 8010749C 00000000 */   nop
    /* 4CA0 801074A0 2B1D0408 */  j          .L801074AC
    /* 4CA4 801074A4 0A00A6A4 */   sh        $a2, 0xA($a1)
  .L801074A8:
    /* 4CA8 801074A8 0A00A0A4 */  sh         $zero, 0xA($a1)
  .L801074AC:
    /* 4CAC 801074AC 01001026 */  addiu      $s0, $s0, 0x1
    /* 4CB0 801074B0 1000022A */  slti       $v0, $s0, 0x10
    /* 4CB4 801074B4 E3FF4014 */  bnez       $v0, .L80107444
    /* 4CB8 801074B8 21100902 */   addu      $v0, $s0, $t1
    /* 4CBC 801074BC 21800000 */  addu       $s0, $zero, $zero
    /* 4CC0 801074C0 0680023C */  lui        $v0, %hi(vs_main_inventoryIndices)
    /* 4CC4 801074C4 D8195224 */  addiu      $s2, $v0, %lo(vs_main_inventoryIndices)
    /* 4CC8 801074C8 0680023C */  lui        $v0, %hi(D_80060148)
    /* 4CCC 801074CC 48015124 */  addiu      $s1, $v0, %lo(D_80060148)
    /* 4CD0 801074D0 21101202 */  addu       $v0, $s0, $s2
  .L801074D4:
    /* 4CD4 801074D4 00004390 */  lbu        $v1, 0x0($v0)
    /* 4CD8 801074D8 00000000 */  nop
    /* 4CDC 801074DC 08006010 */  beqz       $v1, .L80107500
    /* 4CE0 801074E0 40110300 */   sll       $v0, $v1, 5
    /* 4CE4 801074E4 21205100 */  addu       $a0, $v0, $s1
    /* 4CE8 801074E8 03008290 */  lbu        $v0, 0x3($a0)
    /* 4CEC 801074EC 00000000 */  nop
    /* 4CF0 801074F0 03004010 */  beqz       $v0, .L80107500
    /* 4CF4 801074F4 00000000 */   nop
    /* 4CF8 801074F8 CEAC010C */  jal        vs_battle_equipWeapon
    /* 4CFC 801074FC 00000000 */   nop
  .L80107500:
    /* 4D00 80107500 01001026 */  addiu      $s0, $s0, 0x1
    /* 4D04 80107504 0800022A */  slti       $v0, $s0, 0x8
    /* 4D08 80107508 F2FF4014 */  bnez       $v0, .L801074D4
    /* 4D0C 8010750C 21101202 */   addu      $v0, $s0, $s2
    /* 4D10 80107510 21800000 */  addu       $s0, $zero, $zero
    /* 4D14 80107514 0680023C */  lui        $v0, %hi(vs_main_inventoryIndices)
    /* 4D18 80107518 D8195224 */  addiu      $s2, $v0, %lo(vs_main_inventoryIndices)
    /* 4D1C 8010751C 0680023C */  lui        $v0, %hi(D_80060238)
    /* 4D20 80107520 38025124 */  addiu      $s1, $v0, %lo(D_80060238)
    /* 4D24 80107524 21101202 */  addu       $v0, $s0, $s2
  .L80107528:
    /* 4D28 80107528 28004390 */  lbu        $v1, 0x28($v0)
    /* 4D2C 8010752C 00000000 */  nop
    /* 4D30 80107530 1C006010 */  beqz       $v1, .L801075A4
    /* 4D34 80107534 40100300 */   sll       $v0, $v1, 1
    /* 4D38 80107538 EB51043C */  lui        $a0, (0x51EB851F >> 16)
    /* 4D3C 8010753C 21104300 */  addu       $v0, $v0, $v1
    /* 4D40 80107540 00110200 */  sll        $v0, $v0, 4
    /* 4D44 80107544 21285100 */  addu       $a1, $v0, $s1
    /* 4D48 80107548 0800A394 */  lhu        $v1, 0x8($a1)
    /* 4D4C 8010754C 0C00A294 */  lhu        $v0, 0xC($a1)
    /* 4D50 80107550 1F858434 */  ori        $a0, $a0, (0x51EB851F & 0xFFFF)
    /* 4D54 80107554 23306200 */  subu       $a2, $v1, $v0
    /* 4D58 80107558 1800C400 */  mult       $a2, $a0
    /* 4D5C 8010755C 0C00A3A4 */  sh         $v1, 0xC($a1)
    /* 4D60 80107560 C31F0600 */  sra        $v1, $a2, 31
    /* 4D64 80107564 0E00A494 */  lhu        $a0, 0xE($a1)
    /* 4D68 80107568 10500000 */  mfhi       $t2
    /* 4D6C 8010756C 43110A00 */  sra        $v0, $t2, 5
    /* 4D70 80107570 23104300 */  subu       $v0, $v0, $v1
    /* 4D74 80107574 23308200 */  subu       $a2, $a0, $v0
    /* 4D78 80107578 0300C004 */  bltz       $a2, .L80107588
    /* 4D7C 8010757C 00000000 */   nop
    /* 4D80 80107580 631D0408 */  j          .L8010758C
    /* 4D84 80107584 0E00A6A4 */   sh        $a2, 0xE($a1)
  .L80107588:
    /* 4D88 80107588 0E00A0A4 */  sh         $zero, 0xE($a1)
  .L8010758C:
    /* 4D8C 8010758C 0100A290 */  lbu        $v0, 0x1($a1)
    /* 4D90 80107590 00000000 */  nop
    /* 4D94 80107594 03004010 */  beqz       $v0, .L801075A4
    /* 4D98 80107598 00000000 */   nop
    /* 4D9C 8010759C 18AD010C */  jal        vs_battle_equipShield
    /* 4DA0 801075A0 2120A000 */   addu      $a0, $a1, $zero
  .L801075A4:
    /* 4DA4 801075A4 01001026 */  addiu      $s0, $s0, 0x1
    /* 4DA8 801075A8 0800022A */  slti       $v0, $s0, 0x8
    /* 4DAC 801075AC DEFF4014 */  bnez       $v0, .L80107528
    /* 4DB0 801075B0 21101202 */   addu      $v0, $s0, $s2
    /* 4DB4 801075B4 21800000 */  addu       $s0, $zero, $zero
    /* 4DB8 801075B8 0680023C */  lui        $v0, %hi(vs_main_inventoryIndices)
    /* 4DBC 801075BC D8195224 */  addiu      $s2, $v0, %lo(vs_main_inventoryIndices)
    /* 4DC0 801075C0 0680023C */  lui        $v0, %hi(D_80060780)
    /* 4DC4 801075C4 80075124 */  addiu      $s1, $v0, %lo(D_80060780)
    /* 4DC8 801075C8 21101202 */  addu       $v0, $s0, $s2
  .L801075CC:
    /* 4DCC 801075CC 30004390 */  lbu        $v1, 0x30($v0)
    /* 4DD0 801075D0 00000000 */  nop
    /* 4DD4 801075D4 21006010 */  beqz       $v1, .L8010765C
    /* 4DD8 801075D8 80100300 */   sll       $v0, $v1, 2
    /* 4DDC 801075DC 21104300 */  addu       $v0, $v0, $v1
    /* 4DE0 801075E0 C0100200 */  sll        $v0, $v0, 3
    /* 4DE4 801075E4 21285100 */  addu       $a1, $v0, $s1
    /* 4DE8 801075E8 0300A390 */  lbu        $v1, 0x3($a1)
    /* 4DEC 801075EC 07000224 */  addiu      $v0, $zero, 0x7
    /* 4DF0 801075F0 1A006210 */  beq        $v1, $v0, .L8010765C
    /* 4DF4 801075F4 00000000 */   nop
    /* 4DF8 801075F8 EB51043C */  lui        $a0, (0x51EB851F >> 16)
    /* 4DFC 801075FC 0400A394 */  lhu        $v1, 0x4($a1)
    /* 4E00 80107600 0800A294 */  lhu        $v0, 0x8($a1)
    /* 4E04 80107604 1F858434 */  ori        $a0, $a0, (0x51EB851F & 0xFFFF)
    /* 4E08 80107608 23306200 */  subu       $a2, $v1, $v0
    /* 4E0C 8010760C 1800C400 */  mult       $a2, $a0
    /* 4E10 80107610 0800A3A4 */  sh         $v1, 0x8($a1)
    /* 4E14 80107614 C31F0600 */  sra        $v1, $a2, 31
    /* 4E18 80107618 0A00A494 */  lhu        $a0, 0xA($a1)
    /* 4E1C 8010761C 10500000 */  mfhi       $t2
    /* 4E20 80107620 43110A00 */  sra        $v0, $t2, 5
    /* 4E24 80107624 23104300 */  subu       $v0, $v0, $v1
    /* 4E28 80107628 23308200 */  subu       $a2, $a0, $v0
    /* 4E2C 8010762C 0300C004 */  bltz       $a2, .L8010763C
    /* 4E30 80107630 00000000 */   nop
    /* 4E34 80107634 901D0408 */  j          .L80107640
    /* 4E38 80107638 0A00A6A4 */   sh        $a2, 0xA($a1)
  .L8010763C:
    /* 4E3C 8010763C 0A00A0A4 */  sh         $zero, 0xA($a1)
  .L80107640:
    /* 4E40 80107640 2600A290 */  lbu        $v0, 0x26($a1)
    /* 4E44 80107644 00000000 */  nop
    /* 4E48 80107648 04004010 */  beqz       $v0, .L8010765C
    /* 4E4C 8010764C 00000000 */   nop
    /* 4E50 80107650 21204000 */  addu       $a0, $v0, $zero
    /* 4E54 80107654 2EAD010C */  jal        vs_battle_equipArmor
    /* 4E58 80107658 FFFF8424 */   addiu     $a0, $a0, -0x1
  .L8010765C:
    /* 4E5C 8010765C 01001026 */  addiu      $s0, $s0, 0x1
    /* 4E60 80107660 1000022A */  slti       $v0, $s0, 0x10
    /* 4E64 80107664 D9FF4014 */  bnez       $v0, .L801075CC
    /* 4E68 80107668 21101202 */   addu      $v0, $s0, $s2
    /* 4E6C 8010766C 1180033C */  lui        $v1, %hi(D_8010BC50)
    /* 4E70 80107670 03000224 */  addiu      $v0, $zero, 0x3
    /* 4E74 80107674 BA1D0408 */  j          .L801076E8
    /* 4E78 80107678 50BC62A0 */   sb        $v0, %lo(D_8010BC50)($v1)
    /* 4E7C 8010767C 0680103C */  lui        $s0, %hi(vs_main_buttonsPressed)
    /* 4E80 80107680 D0E10292 */  lbu        $v0, %lo(vs_main_buttonsPressed)($s0)
    /* 4E84 80107684 00000000 */  nop
    /* 4E88 80107688 18004010 */  beqz       $v0, .L801076EC
    /* 4E8C 8010768C 21100000 */   addu      $v0, $zero, $zero
    /* 4E90 80107690 BA00030C */  jal        vs_battle_playMenuLeaveSfx
    /* 4E94 80107694 00000000 */   nop
    /* 4E98 80107698 28EA030C */  jal        vs_mainMenu_menuItemFlyoutRight
    /* 4E9C 8010769C 0E000424 */   addiu     $a0, $zero, 0xE
    /* 4EA0 801076A0 D0E1028E */  lw         $v0, %lo(vs_main_buttonsPressed)($s0)
    /* 4EA4 801076A4 00000000 */  nop
    /* 4EA8 801076A8 10004230 */  andi       $v0, $v0, 0x10
    /* 4EAC 801076AC 0F004014 */  bnez       $v0, .L801076EC
    /* 4EB0 801076B0 FEFF0224 */   addiu     $v0, $zero, -0x2
    /* 4EB4 801076B4 F2FE030C */  jal        func_800FFBC8
    /* 4EB8 801076B8 00000000 */   nop
    /* 4EBC 801076BC 1180033C */  lui        $v1, %hi(D_8010BC50)
  .L801076C0:
    /* 4EC0 801076C0 04000224 */  addiu      $v0, $zero, 0x4
    /* 4EC4 801076C4 BA1D0408 */  j          .L801076E8
    /* 4EC8 801076C8 50BC62A0 */   sb        $v0, %lo(D_8010BC50)($v1)
    /* 4ECC 801076CC 74EA030C */  jal        vs_mainmenu_ready
    /* 4ED0 801076D0 00000000 */   nop
    /* 4ED4 801076D4 04004010 */  beqz       $v0, .L801076E8
    /* 4ED8 801076D8 1180023C */   lui       $v0, %hi(D_8010BC4C)
    /* 4EDC 801076DC 4CBC428C */  lw         $v0, %lo(D_8010BC4C)($v0)
    /* 4EE0 801076E0 BB1D0408 */  j          .L801076EC
    /* 4EE4 801076E4 00000000 */   nop
  .L801076E8:
    /* 4EE8 801076E8 21100000 */  addu       $v0, $zero, $zero
  .L801076EC:
    /* 4EEC 801076EC 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 4EF0 801076F0 1800B28F */  lw         $s2, 0x18($sp)
    /* 4EF4 801076F4 1400B18F */  lw         $s1, 0x14($sp)
    /* 4EF8 801076F8 1000B08F */  lw         $s0, 0x10($sp)
    /* 4EFC 801076FC 0800E003 */  jr         $ra
    /* 4F00 80107700 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_801072FC
