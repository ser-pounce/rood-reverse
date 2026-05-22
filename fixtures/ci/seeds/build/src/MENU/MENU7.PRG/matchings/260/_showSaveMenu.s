nonmatching _showSaveMenu, 0x614

glabel _showSaveMenu
    /* 4A68 80107268 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 4A6C 8010726C 21408000 */  addu       $t0, $a0, $zero
    /* 4A70 80107270 E7E70234 */  ori        $v0, $zero, 0xE7E7
    /* 4A74 80107274 2400BFAF */  sw         $ra, 0x24($sp)
    /* 4A78 80107278 2000B2AF */  sw         $s2, 0x20($sp)
    /* 4A7C 8010727C 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 4A80 80107280 1800B0AF */  sw         $s0, 0x18($sp)
    /* 4A84 80107284 2E000011 */  beqz       $t0, .L80107340
    /* 4A88 80107288 1000A2A7 */   sh        $v0, 0x10($sp)
    /* 4A8C 8010728C 1180043C */  lui        $a0, %hi(_showSaveMenuSelectedFile)
    /* 4A90 80107290 01001024 */  addiu      $s0, $zero, 0x1
    /* 4A94 80107294 0680023C */  lui        $v0, %hi(D_80060021)
    /* 4A98 80107298 21004390 */  lbu        $v1, %lo(D_80060021)($v0)
    /* 4A9C 8010729C 1180023C */  lui        $v0, %hi(_containerDataEmpty)
    /* 4AA0 801072A0 ECAA90A0 */  sb         $s0, %lo(_showSaveMenuSelectedFile)($a0)
    /* 4AA4 801072A4 06006010 */  beqz       $v1, .L801072C0
    /* 4AA8 801072A8 ACB040A0 */   sb        $zero, %lo(_containerDataEmpty)($v0)
    /* 4AAC 801072AC 0F80023C */  lui        $v0, %hi(D_800F4EE8 + 0x88)
    /* 4AB0 801072B0 704F4290 */  lbu        $v0, %lo(D_800F4EE8 + 0x88)($v0)
    /* 4AB4 801072B4 00000000 */  nop
    /* 4AB8 801072B8 01004224 */  addiu      $v0, $v0, 0x1
    /* 4ABC 801072BC ECAA82A0 */  sb         $v0, %lo(_showSaveMenuSelectedFile)($a0)
  .L801072C0:
    /* 4AC0 801072C0 21200000 */  addu       $a0, $zero, $zero
    /* 4AC4 801072C4 2200053C */  lui        $a1, (0x220140 >> 16)
    /* 4AC8 801072C8 4001A534 */  ori        $a1, $a1, (0x220140 & 0xFFFF)
    /* 4ACC 801072CC 0C00063C */  lui        $a2, (0xC008C >> 16)
    /* 4AD0 801072D0 8C00C634 */  ori        $a2, $a2, (0xC008C & 0xFFFF)
    /* 4AD4 801072D4 1180023C */  lui        $v0, %hi(_dataNotSaved)
    /* 4AD8 801072D8 ABB040A0 */  sb         $zero, %lo(_dataNotSaved)($v0)
    /* 4ADC 801072DC 1180023C */  lui        $v0, %hi(_isSaving)
    /* 4AE0 801072E0 1180093C */  lui        $t1, %hi(_showSaveMenuState)
    /* 4AE4 801072E4 FFFF0825 */  addiu      $t0, $t0, -0x1
    /* 4AE8 801072E8 A8B050A0 */  sb         $s0, %lo(_isSaving)($v0)
    /* 4AEC 801072EC 40100800 */  sll        $v0, $t0, 1
    /* 4AF0 801072F0 1180033C */  lui        $v1, %hi(_textTable)
    /* 4AF4 801072F4 F8AD678C */  lw         $a3, %lo(_textTable)($v1)
    /* 4AF8 801072F8 21104800 */  addu       $v0, $v0, $t0
    /* 4AFC 801072FC EBAA22A1 */  sb         $v0, %lo(_showSaveMenuState)($t1)
    /* 4B00 80107300 6E13040C */  jal        _initFileMenuElement
    /* 4B04 80107304 1201E724 */   addiu     $a3, $a3, 0x112
    /* 4B08 80107308 21184000 */  addu       $v1, $v0, $zero
    /* 4B0C 8010730C 1000A427 */  addiu      $a0, $sp, 0x10
    /* 4B10 80107310 02000224 */  addiu      $v0, $zero, 0x2
    /* 4B14 80107314 000062A0 */  sb         $v0, 0x0($v1)
    /* 4B18 80107318 B4000224 */  addiu      $v0, $zero, 0xB4
    /* 4B1C 8010731C 080062A4 */  sh         $v0, 0x8($v1)
    /* 4B20 80107320 08000224 */  addiu      $v0, $zero, 0x8
    /* 4B24 80107324 030062A0 */  sb         $v0, 0x3($v1)
    /* 4B28 80107328 1180023C */  lui        $v0, %hi(_memoryCardMessage)
    /* 4B2C 8010732C 040070A0 */  sb         $s0, 0x4($v1)
    /* 4B30 80107330 01FF030C */  jal        vs_mainmenu_setInformationMessage
    /* 4B34 80107334 A4B040AC */   sw        $zero, %lo(_memoryCardMessage)($v0)
    /* 4B38 80107338 191E0408 */  j          .L80107864
    /* 4B3C 8010733C 21100000 */   addu      $v0, $zero, $zero
  .L80107340:
    /* 4B40 80107340 1180023C */  lui        $v0, %hi(_showSaveMenuState)
    /* 4B44 80107344 EBAA4390 */  lbu        $v1, %lo(_showSaveMenuState)($v0)
    /* 4B48 80107348 00000000 */  nop
    /* 4B4C 8010734C 0C00622C */  sltiu      $v0, $v1, 0xC
    /* 4B50 80107350 43014010 */  beqz       $v0, .L80107860
    /* 4B54 80107354 1080023C */   lui       $v0, %hi(jtbl_80102918)
    /* 4B58 80107358 18294224 */  addiu      $v0, $v0, %lo(jtbl_80102918)
    /* 4B5C 8010735C 80180300 */  sll        $v1, $v1, 2
    /* 4B60 80107360 21186200 */  addu       $v1, $v1, $v0
    /* 4B64 80107364 0000628C */  lw         $v0, 0x0($v1)
    /* 4B68 80107368 00000000 */  nop
    /* 4B6C 8010736C 08004000 */  jr         $v0
    /* 4B70 80107370 00000000 */   nop
    /* 4B74 80107374 0680033C */  lui        $v1, %hi(vs_main_settings)
    /* 4B78 80107378 2000628C */  lw         $v0, %lo(vs_main_settings)($v1)
    /* 4B7C 8010737C 00000000 */  nop
    /* 4B80 80107380 10004230 */  andi       $v0, $v0, 0x10
    /* 4B84 80107384 09004010 */  beqz       $v0, .L801073AC
    /* 4B88 80107388 20007024 */   addiu     $s0, $v1, %lo(vs_main_settings)
    /* 4B8C 8010738C 21280000 */  addu       $a1, $zero, $zero
    /* 4B90 80107390 1180023C */  lui        $v0, %hi(_spmcimg)
    /* 4B94 80107394 F0AD448C */  lw         $a0, %lo(_spmcimg)($v0)
    /* 4B98 80107398 003C0624 */  addiu      $a2, $zero, 0x3C00
    /* 4B9C 8010739C AD9B000C */  jal        memset
    /* 4BA0 801073A0 E0798424 */   addiu     $a0, $a0, 0x79E0
    /* 4BA4 801073A4 CE1D0408 */  j          .L80107738
    /* 4BA8 801073A8 1180033C */   lui       $v1, %hi(_showSaveMenuState)
  .L801073AC:
    /* 4BAC 801073AC C113040C */  jal        _fileMenuElementsActive
    /* 4BB0 801073B0 00000000 */   nop
    /* 4BB4 801073B4 2B014010 */  beqz       $v0, .L80107864
    /* 4BB8 801073B8 21100000 */   addu      $v0, $zero, $zero
    /* 4BBC 801073BC 0400028E */  lw         $v0, 0x4($s0)
    /* 4BC0 801073C0 00000000 */  nop
    /* 4BC4 801073C4 DC004010 */  beqz       $v0, .L80107738
    /* 4BC8 801073C8 1180033C */   lui       $v1, %hi(_showSaveMenuState)
    /* 4BCC 801073CC 2014040C */  jal        _findCurrentSave
    /* 4BD0 801073D0 01000424 */   addiu     $a0, $zero, 0x1
    /* 4BD4 801073D4 1180033C */  lui        $v1, %hi(_showSaveMenuState)
    /* 4BD8 801073D8 01000224 */  addiu      $v0, $zero, 0x1
    /* 4BDC 801073DC 181E0408 */  j          .L80107860
    /* 4BE0 801073E0 EBAA62A0 */   sb        $v0, %lo(_showSaveMenuState)($v1)
    /* 4BE4 801073E4 2014040C */  jal        _findCurrentSave
    /* 4BE8 801073E8 21200000 */   addu      $a0, $zero, $zero
    /* 4BEC 801073EC 21204000 */  addu       $a0, $v0, $zero
    /* 4BF0 801073F0 1C018010 */  beqz       $a0, .L80107864
    /* 4BF4 801073F4 21100000 */   addu      $v0, $zero, $zero
    /* 4BF8 801073F8 11008104 */  bgez       $a0, .L80107440
    /* 4BFC 801073FC 07008230 */   andi      $v0, $a0, 0x7
    /* 4C00 80107400 1180023C */  lui        $v0, %hi(_memoryCardMessage)
    /* 4C04 80107404 A4B04324 */  addiu      $v1, $v0, %lo(_memoryCardMessage)
    /* 4C08 80107408 FEFF0224 */  addiu      $v0, $zero, -0x2
    /* 4C0C 8010740C 04008214 */  bne        $a0, $v0, .L80107420
    /* 4C10 80107410 1180023C */   lui       $v0, %hi(_textTable)
    /* 4C14 80107414 F8AD428C */  lw         $v0, %lo(_textTable)($v0)
    /* 4C18 80107418 0B1D0408 */  j          .L8010742C
    /* 4C1C 8010741C C6014224 */   addiu     $v0, $v0, 0x1C6
  .L80107420:
    /* 4C20 80107420 F8AD428C */  lw         $v0, %lo(_textTable)($v0)
    /* 4C24 80107424 00000000 */  nop
    /* 4C28 80107428 EE014224 */  addiu      $v0, $v0, 0x1EE
  .L8010742C:
    /* 4C2C 8010742C 000062AC */  sw         $v0, 0x0($v1)
    /* 4C30 80107430 1180033C */  lui        $v1, %hi(_showSaveMenuState)
    /* 4C34 80107434 09000224 */  addiu      $v0, $zero, 0x9
    /* 4C38 80107438 181E0408 */  j          .L80107860
    /* 4C3C 8010743C EBAA62A0 */   sb        $v0, %lo(_showSaveMenuState)($v1)
  .L80107440:
    /* 4C40 80107440 10008430 */  andi       $a0, $a0, 0x10
    /* 4C44 80107444 00230400 */  sll        $a0, $a0, 12
    /* 4C48 80107448 740F040C */  jal        _loadSaveData
    /* 4C4C 8010744C 25204400 */   or        $a0, $v0, $a0
    /* 4C50 80107450 1180033C */  lui        $v1, %hi(_showSaveMenuState)
    /* 4C54 80107454 02000224 */  addiu      $v0, $zero, 0x2
    /* 4C58 80107458 181E0408 */  j          .L80107860
    /* 4C5C 8010745C EBAA62A0 */   sb        $v0, %lo(_showSaveMenuState)($v1)
    /* 4C60 80107460 740F040C */  jal        _loadSaveData
    /* 4C64 80107464 21200000 */   addu      $a0, $zero, $zero
    /* 4C68 80107468 21204000 */  addu       $a0, $v0, $zero
    /* 4C6C 8010746C FD008010 */  beqz       $a0, .L80107864
    /* 4C70 80107470 21100000 */   addu      $v0, $zero, $zero
    /* 4C74 80107474 05008018 */  blez       $a0, .L8010748C
    /* 4C78 80107478 1180033C */   lui       $v1, %hi(_showSaveMenuState)
    /* 4C7C 8010747C 8C0D040C */  jal        _applyLoadedSaveFile
    /* 4C80 80107480 21200000 */   addu      $a0, $zero, $zero
    /* 4C84 80107484 AB004010 */  beqz       $v0, .L80107734
    /* 4C88 80107488 1180033C */   lui       $v1, %hi(_showSaveMenuState)
  .L8010748C:
    /* 4C8C 8010748C 09000224 */  addiu      $v0, $zero, 0x9
    /* 4C90 80107490 EBAA62A0 */  sb         $v0, %lo(_showSaveMenuState)($v1)
    /* 4C94 80107494 1180023C */  lui        $v0, %hi(_textTable)
    /* 4C98 80107498 F8AD428C */  lw         $v0, %lo(_textTable)($v0)
    /* 4C9C 8010749C 1180033C */  lui        $v1, %hi(_memoryCardMessage)
    /* 4CA0 801074A0 EE014224 */  addiu      $v0, $v0, 0x1EE
    /* 4CA4 801074A4 181E0408 */  j          .L80107860
    /* 4CA8 801074A8 A4B062AC */   sw        $v0, %lo(_memoryCardMessage)($v1)
    /* 4CAC 801074AC C113040C */  jal        _fileMenuElementsActive
    /* 4CB0 801074B0 00000000 */   nop
    /* 4CB4 801074B4 EA004010 */  beqz       $v0, .L80107860
    /* 4CB8 801074B8 3200053C */   lui       $a1, (0x320140 >> 16)
    /* 4CBC 801074BC 01000424 */  addiu      $a0, $zero, 0x1
    /* 4CC0 801074C0 4001A534 */  ori        $a1, $a1, (0x320140 & 0xFFFF)
    /* 4CC4 801074C4 0C00063C */  lui        $a2, (0xC007E >> 16)
    /* 4CC8 801074C8 1180023C */  lui        $v0, %hi(_textTable)
    /* 4CCC 801074CC F8AD478C */  lw         $a3, %lo(_textTable)($v0)
    /* 4CD0 801074D0 7E00C634 */  ori        $a2, $a2, (0xC007E & 0xFFFF)
    /* 4CD4 801074D4 6E13040C */  jal        _initFileMenuElement
    /* 4CD8 801074D8 4401E724 */   addiu     $a3, $a3, 0x144
    /* 4CDC 801074DC 21184000 */  addu       $v1, $v0, $zero
    /* 4CE0 801074E0 02000224 */  addiu      $v0, $zero, 0x2
    /* 4CE4 801074E4 000062A0 */  sb         $v0, 0x0($v1)
    /* 4CE8 801074E8 C2000224 */  addiu      $v0, $zero, 0xC2
    /* 4CEC 801074EC 080062A4 */  sh         $v0, 0x8($v1)
    /* 4CF0 801074F0 1180033C */  lui        $v1, %hi(_showSaveMenuState)
    /* 4CF4 801074F4 04000224 */  addiu      $v0, $zero, 0x4
    /* 4CF8 801074F8 181E0408 */  j          .L80107860
    /* 4CFC 801074FC EBAA62A0 */   sb        $v0, %lo(_showSaveMenuState)($v1)
    /* 4D00 80107500 02000424 */  addiu      $a0, $zero, 0x2
    /* 4D04 80107504 4200053C */  lui        $a1, (0x420140 >> 16)
    /* 4D08 80107508 4001A534 */  ori        $a1, $a1, (0x420140 & 0xFFFF)
    /* 4D0C 8010750C 0C00063C */  lui        $a2, (0xC007E >> 16)
    /* 4D10 80107510 1180023C */  lui        $v0, %hi(_textTable)
    /* 4D14 80107514 F8AD478C */  lw         $a3, %lo(_textTable)($v0)
    /* 4D18 80107518 7E00C634 */  ori        $a2, $a2, (0xC007E & 0xFFFF)
    /* 4D1C 8010751C 6E13040C */  jal        _initFileMenuElement
    /* 4D20 80107520 5801E724 */   addiu     $a3, $a3, 0x158
    /* 4D24 80107524 21184000 */  addu       $v1, $v0, $zero
    /* 4D28 80107528 02000224 */  addiu      $v0, $zero, 0x2
    /* 4D2C 8010752C 000062A0 */  sb         $v0, 0x0($v1)
    /* 4D30 80107530 C2000224 */  addiu      $v0, $zero, 0xC2
    /* 4D34 80107534 080062A4 */  sh         $v0, 0x8($v1)
    /* 4D38 80107538 1180033C */  lui        $v1, %hi(_showSaveMenuState)
    /* 4D3C 8010753C 05000224 */  addiu      $v0, $zero, 0x5
    /* 4D40 80107540 181E0408 */  j          .L80107860
    /* 4D44 80107544 EBAA62A0 */   sb        $v0, %lo(_showSaveMenuState)($v1)
    /* 4D48 80107548 C113040C */  jal        _fileMenuElementsActive
    /* 4D4C 8010754C 00000000 */   nop
    /* 4D50 80107550 C4004010 */  beqz       $v0, .L80107864
    /* 4D54 80107554 21100000 */   addu      $v0, $zero, $zero
    /* 4D58 80107558 01FF030C */  jal        vs_mainmenu_setInformationMessage
    /* 4D5C 8010755C 1000A427 */   addiu     $a0, $sp, 0x10
    /* 4D60 80107560 1180033C */  lui        $v1, %hi(_showSaveMenuState)
    /* 4D64 80107564 06000224 */  addiu      $v0, $zero, 0x6
    /* 4D68 80107568 EBAA62A0 */  sb         $v0, %lo(_showSaveMenuState)($v1)
    /* 4D6C 8010756C 1180023C */  lui        $v0, %hi(_textTable)
    /* 4D70 80107570 F8AD428C */  lw         $v0, %lo(_textTable)($v0)
    /* 4D74 80107574 1180033C */  lui        $v1, %hi(_memoryCardMessage)
    /* 4D78 80107578 6C014224 */  addiu      $v0, $v0, 0x16C
    /* 4D7C 8010757C 181E0408 */  j          .L80107860
    /* 4D80 80107580 A4B062AC */   sw        $v0, %lo(_memoryCardMessage)($v1)
    /* 4D84 80107584 1180023C */  lui        $v0, %hi(_fileMenuElements)
    /* 4D88 80107588 1180103C */  lui        $s0, %hi(_showSaveMenuSelectedFile)
    /* 4D8C 8010758C ECAA0392 */  lbu        $v1, %lo(_showSaveMenuSelectedFile)($s0)
    /* 4D90 80107590 50AE5124 */  addiu      $s1, $v0, %lo(_fileMenuElements)
    /* 4D94 80107594 40100300 */  sll        $v0, $v1, 1
    /* 4D98 80107598 21104300 */  addu       $v0, $v0, $v1
    /* 4D9C 8010759C 80100200 */  sll        $v0, $v0, 2
    /* 4DA0 801075A0 21104300 */  addu       $v0, $v0, $v1
    /* 4DA4 801075A4 80100200 */  sll        $v0, $v0, 2
    /* 4DA8 801075A8 21105100 */  addu       $v0, $v0, $s1
    /* 4DAC 801075AC 01000324 */  addiu      $v1, $zero, 0x1
    /* 4DB0 801075B0 040043A0 */  sb         $v1, 0x4($v0)
    /* 4DB4 801075B4 ECAA0392 */  lbu        $v1, %lo(_showSaveMenuSelectedFile)($s0)
    /* 4DB8 801075B8 03001224 */  addiu      $s2, $zero, 0x3
    /* 4DBC 801075BC 23184302 */  subu       $v1, $s2, $v1
    /* 4DC0 801075C0 40100300 */  sll        $v0, $v1, 1
    /* 4DC4 801075C4 21104300 */  addu       $v0, $v0, $v1
    /* 4DC8 801075C8 80100200 */  sll        $v0, $v0, 2
    /* 4DCC 801075CC 21104300 */  addu       $v0, $v0, $v1
    /* 4DD0 801075D0 80100200 */  sll        $v0, $v0, 2
    /* 4DD4 801075D4 21105100 */  addu       $v0, $v0, $s1
    /* 4DD8 801075D8 040040A0 */  sb         $zero, 0x4($v0)
    /* 4DDC 801075DC 0680023C */  lui        $v0, %hi(vs_main_buttonsPressed)
    /* 4DE0 801075E0 D0E1438C */  lw         $v1, %lo(vs_main_buttonsPressed)($v0)
    /* 4DE4 801075E4 00000000 */  nop
    /* 4DE8 801075E8 40006230 */  andi       $v0, $v1, 0x40
    /* 4DEC 801075EC 26004010 */  beqz       $v0, .L80107688
    /* 4DF0 801075F0 7E000424 */   addiu     $a0, $zero, 0x7E
    /* 4DF4 801075F4 6216010C */  jal        vs_main_playSfxDefault
    /* 4DF8 801075F8 06000524 */   addiu     $a1, $zero, 0x6
    /* 4DFC 801075FC 1180023C */  lui        $v0, %hi(_dataNotSaved)
    /* 4E00 80107600 ABB04490 */  lbu        $a0, %lo(_dataNotSaved)($v0)
    /* 4E04 80107604 1180023C */  lui        $v0, %hi(_selectCursorXy)
    /* 4E08 80107608 A0B040AC */  sw         $zero, %lo(_selectCursorXy)($v0)
    /* 4E0C 8010760C 2A109200 */  slt        $v0, $a0, $s2
    /* 4E10 80107610 0E004010 */  beqz       $v0, .L8010764C
    /* 4E14 80107614 40100400 */   sll       $v0, $a0, 1
    /* 4E18 80107618 02000624 */  addiu      $a2, $zero, 0x2
    /* 4E1C 8010761C 40010524 */  addiu      $a1, $zero, 0x140
    /* 4E20 80107620 21104400 */  addu       $v0, $v0, $a0
    /* 4E24 80107624 80100200 */  sll        $v0, $v0, 2
    /* 4E28 80107628 21104400 */  addu       $v0, $v0, $a0
    /* 4E2C 8010762C 80100200 */  sll        $v0, $v0, 2
    /* 4E30 80107630 21185100 */  addu       $v1, $v0, $s1
  .L80107634:
    /* 4E34 80107634 000066A0 */  sb         $a2, 0x0($v1)
    /* 4E38 80107638 080065A4 */  sh         $a1, 0x8($v1)
    /* 4E3C 8010763C 01008424 */  addiu      $a0, $a0, 0x1
    /* 4E40 80107640 03008228 */  slti       $v0, $a0, 0x3
    /* 4E44 80107644 FBFF4014 */  bnez       $v0, .L80107634
    /* 4E48 80107648 34006324 */   addiu     $v1, $v1, 0x34
  .L8010764C:
    /* 4E4C 8010764C 1180023C */  lui        $v0, %hi(_dataNotSaved)
    /* 4E50 80107650 ABB04290 */  lbu        $v0, %lo(_dataNotSaved)($v0)
    /* 4E54 80107654 00000000 */  nop
    /* 4E58 80107658 6E004010 */  beqz       $v0, .L80107814
    /* 4E5C 8010765C 01000424 */   addiu     $a0, $zero, 0x1
    /* 4E60 80107660 1180023C */  lui        $v0, %hi(_textTable)
    /* 4E64 80107664 F8AD428C */  lw         $v0, %lo(_textTable)($v0)
    /* 4E68 80107668 1180033C */  lui        $v1, %hi(_memoryCardMessage)
    /* 4E6C 8010766C 22064224 */  addiu      $v0, $v0, 0x622
    /* 4E70 80107670 3218040C */  jal        _promptConfirm
    /* 4E74 80107674 A4B062AC */   sw        $v0, %lo(_memoryCardMessage)($v1)
    /* 4E78 80107678 1180033C */  lui        $v1, %hi(_showSaveMenuState)
    /* 4E7C 8010767C 0B000224 */  addiu      $v0, $zero, 0xB
    /* 4E80 80107680 181E0408 */  j          .L80107860
    /* 4E84 80107684 EBAA62A0 */   sb        $v0, %lo(_showSaveMenuState)($v1)
  .L80107688:
    /* 4E88 80107688 20006230 */  andi       $v0, $v1, 0x20
    /* 4E8C 8010768C 0C004010 */  beqz       $v0, .L801076C0
    /* 4E90 80107690 0680023C */   lui       $v0, %hi(vs_main_buttonRepeat)
    /* 4E94 80107694 6216010C */  jal        vs_main_playSfxDefault
    /* 4E98 80107698 05000524 */   addiu     $a1, $zero, 0x5
    /* 4E9C 8010769C ECAA0492 */  lbu        $a0, %lo(_showSaveMenuSelectedFile)($s0)
    /* 4EA0 801076A0 9C1B040C */  jal        _selectSaveMemoryCard
    /* 4EA4 801076A4 00000000 */   nop
    /* 4EA8 801076A8 1180023C */  lui        $v0, %hi(_selectCursorXy)
    /* 4EAC 801076AC 1180033C */  lui        $v1, %hi(_showSaveMenuState)
    /* 4EB0 801076B0 A0B040AC */  sw         $zero, %lo(_selectCursorXy)($v0)
    /* 4EB4 801076B4 07000224 */  addiu      $v0, $zero, 0x7
    /* 4EB8 801076B8 181E0408 */  j          .L80107860
    /* 4EBC 801076BC EBAA62A0 */   sb        $v0, %lo(_showSaveMenuState)($v1)
  .L801076C0:
    /* 4EC0 801076C0 DCDF428C */  lw         $v0, %lo(vs_main_buttonRepeat)($v0)
    /* 4EC4 801076C4 00000000 */  nop
    /* 4EC8 801076C8 00504230 */  andi       $v0, $v0, 0x5000
    /* 4ECC 801076CC 09004010 */  beqz       $v0, .L801076F4
    /* 4ED0 801076D0 7E000424 */   addiu     $a0, $zero, 0x7E
    /* 4ED4 801076D4 6216010C */  jal        vs_main_playSfxDefault
    /* 4ED8 801076D8 04000524 */   addiu     $a1, $zero, 0x4
    /* 4EDC 801076DC ECAA0292 */  lbu        $v0, %lo(_showSaveMenuSelectedFile)($s0)
    /* 4EE0 801076E0 0F80033C */  lui        $v1, %hi(D_800F4EE8 + 0x88)
    /* 4EE4 801076E4 23104202 */  subu       $v0, $s2, $v0
    /* 4EE8 801076E8 ECAA02A2 */  sb         $v0, %lo(_showSaveMenuSelectedFile)($s0)
    /* 4EEC 801076EC FFFF4224 */  addiu      $v0, $v0, -0x1
    /* 4EF0 801076F0 704F62A0 */  sb         $v0, %lo(D_800F4EE8 + 0x88)($v1)
  .L801076F4:
    /* 4EF4 801076F4 ECAA0292 */  lbu        $v0, %lo(_showSaveMenuSelectedFile)($s0)
    /* 4EF8 801076F8 1180033C */  lui        $v1, %hi(_selectCursorXy)
    /* 4EFC 801076FC 01004224 */  addiu      $v0, $v0, 0x1
    /* 4F00 80107700 00110200 */  sll        $v0, $v0, 4
    /* 4F04 80107704 0A004224 */  addiu      $v0, $v0, 0xA
    /* 4F08 80107708 00140200 */  sll        $v0, $v0, 16
    /* 4F0C 8010770C B4004234 */  ori        $v0, $v0, 0xB4
    /* 4F10 80107710 181E0408 */  j          .L80107860
    /* 4F14 80107714 A0B062AC */   sw        $v0, %lo(_selectCursorXy)($v1)
    /* 4F18 80107718 9C1B040C */  jal        _selectSaveMemoryCard
    /* 4F1C 8010771C 21200000 */   addu      $a0, $zero, $zero
    /* 4F20 80107720 21204000 */  addu       $a0, $v0, $zero
    /* 4F24 80107724 4F008010 */  beqz       $a0, .L80107864
    /* 4F28 80107728 21100000 */   addu      $v0, $zero, $zero
    /* 4F2C 8010772C 05008104 */  bgez       $a0, .L80107744
    /* 4F30 80107730 00000000 */   nop
  .L80107734:
    /* 4F34 80107734 1180033C */  lui        $v1, %hi(_showSaveMenuState)
  .L80107738:
    /* 4F38 80107738 03000224 */  addiu      $v0, $zero, 0x3
    /* 4F3C 8010773C 181E0408 */  j          .L80107860
    /* 4F40 80107740 EBAA62A0 */   sb        $v0, %lo(_showSaveMenuState)($v1)
  .L80107744:
    /* 4F44 80107744 5613040C */  jal        _initFileMenu
    /* 4F48 80107748 00000000 */   nop
    /* 4F4C 8010774C 191E0408 */  j          .L80107864
    /* 4F50 80107750 01000224 */   addiu     $v0, $zero, 0x1
    /* 4F54 80107754 C113040C */  jal        _fileMenuElementsActive
    /* 4F58 80107758 00000000 */   nop
    /* 4F5C 8010775C 40004010 */  beqz       $v0, .L80107860
    /* 4F60 80107760 FFFF0224 */   addiu     $v0, $zero, -0x1
    /* 4F64 80107764 191E0408 */  j          .L80107864
    /* 4F68 80107768 00000000 */   nop
    /* 4F6C 8010776C 0680023C */  lui        $v0, %hi(vs_main_buttonsPressed)
    /* 4F70 80107770 D0E14290 */  lbu        $v0, %lo(vs_main_buttonsPressed)($v0)
    /* 4F74 80107774 00000000 */  nop
    /* 4F78 80107778 3A004010 */  beqz       $v0, .L80107864
    /* 4F7C 8010777C 21100000 */   addu      $v0, $zero, $zero
    /* 4F80 80107780 01FF030C */  jal        vs_mainmenu_setInformationMessage
    /* 4F84 80107784 1000A427 */   addiu     $a0, $sp, 0x10
    /* 4F88 80107788 01000424 */  addiu      $a0, $zero, 0x1
    /* 4F8C 8010778C 1180023C */  lui        $v0, %hi(_textTable)
    /* 4F90 80107790 F8AD428C */  lw         $v0, %lo(_textTable)($v0)
    /* 4F94 80107794 1180033C */  lui        $v1, %hi(_memoryCardMessage)
    /* 4F98 80107798 68044224 */  addiu      $v0, $v0, 0x468
    /* 4F9C 8010779C 3218040C */  jal        _promptConfirm
    /* 4FA0 801077A0 A4B062AC */   sw        $v0, %lo(_memoryCardMessage)($v1)
    /* 4FA4 801077A4 1180033C */  lui        $v1, %hi(_showSaveMenuState)
    /* 4FA8 801077A8 0A000224 */  addiu      $v0, $zero, 0xA
    /* 4FAC 801077AC 181E0408 */  j          .L80107860
    /* 4FB0 801077B0 EBAA62A0 */   sb        $v0, %lo(_showSaveMenuState)($v1)
    /* 4FB4 801077B4 3218040C */  jal        _promptConfirm
    /* 4FB8 801077B8 21200000 */   addu      $a0, $zero, $zero
    /* 4FBC 801077BC 21204000 */  addu       $a0, $v0, $zero
    /* 4FC0 801077C0 27008010 */  beqz       $a0, .L80107860
    /* 4FC4 801077C4 1180023C */   lui       $v0, %hi(_showSaveMenuState)
    /* 4FC8 801077C8 EBAA4390 */  lbu        $v1, %lo(_showSaveMenuState)($v0)
    /* 4FCC 801077CC 0B000224 */  addiu      $v0, $zero, 0xB
    /* 4FD0 801077D0 08006214 */  bne        $v1, $v0, .L801077F4
    /* 4FD4 801077D4 00000000 */   nop
    /* 4FD8 801077D8 05008018 */  blez       $a0, .L801077F0
    /* 4FDC 801077DC 0680033C */   lui       $v1, %hi(vs_main_settings)
    /* 4FE0 801077E0 2000628C */  lw         $v0, %lo(vs_main_settings)($v1)
    /* 4FE4 801077E4 00000000 */  nop
    /* 4FE8 801077E8 10004234 */  ori        $v0, $v0, 0x10
    /* 4FEC 801077EC 200062AC */  sw         $v0, %lo(vs_main_settings)($v1)
  .L801077F0:
    /* 4FF0 801077F0 23200400 */  negu       $a0, $a0
  .L801077F4:
    /* 4FF4 801077F4 0B008104 */  bgez       $a0, .L80107824
    /* 4FF8 801077F8 1180103C */   lui       $s0, %hi(_showSaveMenuState)
    /* 4FFC 801077FC 1180023C */  lui        $v0, %hi(_fileMenuElements)
    /* 5000 80107800 02000324 */  addiu      $v1, $zero, 0x2
    /* 5004 80107804 50AE43A0 */  sb         $v1, %lo(_fileMenuElements)($v0)
    /* 5008 80107808 50AE4224 */  addiu      $v0, $v0, %lo(_fileMenuElements)
    /* 500C 8010780C 40010324 */  addiu      $v1, $zero, 0x140
    /* 5010 80107810 080043A4 */  sh         $v1, 0x8($v0)
  .L80107814:
    /* 5014 80107814 1180033C */  lui        $v1, %hi(_showSaveMenuState)
    /* 5018 80107818 08000224 */  addiu      $v0, $zero, 0x8
    /* 501C 8010781C 181E0408 */  j          .L80107860
    /* 5020 80107820 EBAA62A0 */   sb        $v0, %lo(_showSaveMenuState)($v1)
  .L80107824:
    /* 5024 80107824 EBAA0392 */  lbu        $v1, %lo(_showSaveMenuState)($s0)
    /* 5028 80107828 0A000224 */  addiu      $v0, $zero, 0xA
    /* 502C 8010782C 0B006214 */  bne        $v1, $v0, .L8010785C
    /* 5030 80107830 03000224 */   addiu     $v0, $zero, 0x3
    /* 5034 80107834 21280000 */  addu       $a1, $zero, $zero
    /* 5038 80107838 003C0624 */  addiu      $a2, $zero, 0x3C00
    /* 503C 8010783C 1180033C */  lui        $v1, %hi(_containerDataEmpty)
    /* 5040 80107840 1180023C */  lui        $v0, %hi(_spmcimg)
    /* 5044 80107844 F0AD448C */  lw         $a0, %lo(_spmcimg)($v0)
    /* 5048 80107848 01000224 */  addiu      $v0, $zero, 0x1
    /* 504C 8010784C ACB062A0 */  sb         $v0, %lo(_containerDataEmpty)($v1)
    /* 5050 80107850 AD9B000C */  jal        memset
    /* 5054 80107854 E0798424 */   addiu     $a0, $a0, 0x79E0
    /* 5058 80107858 03000224 */  addiu      $v0, $zero, 0x3
  .L8010785C:
    /* 505C 8010785C EBAA02A2 */  sb         $v0, %lo(_showSaveMenuState)($s0)
  .L80107860:
    /* 5060 80107860 21100000 */  addu       $v0, $zero, $zero
  .L80107864:
    /* 5064 80107864 2400BF8F */  lw         $ra, 0x24($sp)
    /* 5068 80107868 2000B28F */  lw         $s2, 0x20($sp)
    /* 506C 8010786C 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 5070 80107870 1800B08F */  lw         $s0, 0x18($sp)
    /* 5074 80107874 0800E003 */  jr         $ra
    /* 5078 80107878 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel _showSaveMenu
