nonmatching func_801072B0, 0x1E0

glabel func_801072B0
    /* 4AB0 801072B0 C8FFBD27 */  addiu      $sp, $sp, -0x38
    /* 4AB4 801072B4 3000BFAF */  sw         $ra, 0x30($sp)
    /* 4AB8 801072B8 2C00B1AF */  sw         $s1, 0x2C($sp)
    /* 4ABC 801072BC 0E008010 */  beqz       $a0, .L801072F8
    /* 4AC0 801072C0 2800B0AF */   sw        $s0, 0x28($sp)
    /* 4AC4 801072C4 8123030C */  jal        func_800C8E04
    /* 4AC8 801072C8 01000424 */   addiu     $a0, $zero, 0x1
    /* 4ACC 801072CC 21100000 */  addu       $v0, $zero, $zero
    /* 4AD0 801072D0 1180043C */  lui        $a0, %hi(D_80109A7D)
    /* 4AD4 801072D4 05000324 */  addiu      $v1, $zero, 0x5
    /* 4AD8 801072D8 7D9A83A0 */  sb         $v1, %lo(D_80109A7D)($a0)
    /* 4ADC 801072DC 1080033C */  lui        $v1, %hi(D_801023E3)
    /* 4AE0 801072E0 E32360A0 */  sb         $zero, %lo(D_801023E3)($v1)
    /* 4AE4 801072E4 1180033C */  lui        $v1, %hi(D_80109A58)
    /* 4AE8 801072E8 589A60AC */  sw         $zero, %lo(D_80109A58)($v1)
    /* 4AEC 801072EC 1180033C */  lui        $v1, %hi(D_80109A5C)
    /* 4AF0 801072F0 1F1D0408 */  j          .L8010747C
    /* 4AF4 801072F4 5C9A60A0 */   sb        $zero, %lo(D_80109A5C)($v1)
  .L801072F8:
    /* 4AF8 801072F8 1180023C */  lui        $v0, %hi(D_80109A5C)
    /* 4AFC 801072FC 5C9A5090 */  lbu        $s0, %lo(D_80109A5C)($v0)
    /* 4B00 80107300 01000224 */  addiu      $v0, $zero, 0x1
    /* 4B04 80107304 33000212 */  beq        $s0, $v0, .L801073D4
    /* 4B08 80107308 0200022A */   slti      $v0, $s0, 0x2
    /* 4B0C 8010730C 05004010 */  beqz       $v0, .L80107324
    /* 4B10 80107310 02000224 */   addiu     $v0, $zero, 0x2
    /* 4B14 80107314 07000012 */  beqz       $s0, .L80107334
    /* 4B18 80107318 21100000 */   addu      $v0, $zero, $zero
    /* 4B1C 8010731C 1F1D0408 */  j          .L8010747C
    /* 4B20 80107320 00000000 */   nop
  .L80107324:
    /* 4B24 80107324 4D000212 */  beq        $s0, $v0, .L8010745C
    /* 4B28 80107328 21100000 */   addu      $v0, $zero, $zero
    /* 4B2C 8010732C 1F1D0408 */  j          .L8010747C
    /* 4B30 80107330 00000000 */   nop
  .L80107334:
    /* 4B34 80107334 21480000 */  addu       $t1, $zero, $zero
    /* 4B38 80107338 2000A827 */  addiu      $t0, $sp, 0x20
    /* 4B3C 8010733C 04000724 */  addiu      $a3, $zero, 0x4
    /* 4B40 80107340 1000AA27 */  addiu      $t2, $sp, 0x10
    /* 4B44 80107344 21304001 */  addu       $a2, $t2, $zero
    /* 4B48 80107348 10000524 */  addiu      $a1, $zero, 0x10
    /* 4B4C 8010734C 1180033C */  lui        $v1, %hi(_menuText)
    /* 4B50 80107350 1180023C */  lui        $v0, %hi(D_80109A7A)
    /* 4B54 80107354 7A9A4290 */  lbu        $v0, %lo(D_80109A7A)($v0)
    /* 4B58 80107358 2C956424 */  addiu      $a0, $v1, %lo(_menuText)
    /* 4B5C 8010735C 0A004224 */  addiu      $v0, $v0, 0xA
    /* 4B60 80107360 40100200 */  sll        $v0, $v0, 1
    /* 4B64 80107364 21584400 */  addu       $t3, $v0, $a0
  .L80107368:
    /* 4B68 80107368 21184701 */  addu       $v1, $t2, $a3
    /* 4B6C 8010736C 0800E724 */  addiu      $a3, $a3, 0x8
    /* 4B70 80107370 2110A400 */  addu       $v0, $a1, $a0
    /* 4B74 80107374 0200A524 */  addiu      $a1, $a1, 0x2
    /* 4B78 80107378 00004294 */  lhu        $v0, 0x0($v0)
    /* 4B7C 8010737C 01002925 */  addiu      $t1, $t1, 0x1
    /* 4B80 80107380 40100200 */  sll        $v0, $v0, 1
    /* 4B84 80107384 21104400 */  addu       $v0, $v0, $a0
    /* 4B88 80107388 0000C2AC */  sw         $v0, 0x0($a2)
    /* 4B8C 8010738C 00006295 */  lhu        $v0, 0x0($t3)
    /* 4B90 80107390 0800C624 */  addiu      $a2, $a2, 0x8
    /* 4B94 80107394 40100200 */  sll        $v0, $v0, 1
    /* 4B98 80107398 21104400 */  addu       $v0, $v0, $a0
    /* 4B9C 8010739C 000062AC */  sw         $v0, 0x0($v1)
    /* 4BA0 801073A0 000000AD */  sw         $zero, 0x0($t0)
    /* 4BA4 801073A4 02002229 */  slti       $v0, $t1, 0x2
    /* 4BA8 801073A8 EFFF4014 */  bnez       $v0, .L80107368
    /* 4BAC 801073AC 04000825 */   addiu     $t0, $t0, 0x4
    /* 4BB0 801073B0 02000424 */  addiu      $a0, $zero, 0x2
    /* 4BB4 801073B4 03000524 */  addiu      $a1, $zero, 0x3
    /* 4BB8 801073B8 1000A627 */  addiu      $a2, $sp, 0x10
    /* 4BBC 801073BC 3BFC030C */  jal        vs_mainMenu_initSortUi
    /* 4BC0 801073C0 2000A727 */   addiu     $a3, $sp, 0x20
    /* 4BC4 801073C4 1180033C */  lui        $v1, %hi(D_80109A5C)
    /* 4BC8 801073C8 01000224 */  addiu      $v0, $zero, 0x1
    /* 4BCC 801073CC 1E1D0408 */  j          .L80107478
    /* 4BD0 801073D0 5C9A62A0 */   sb        $v0, %lo(D_80109A5C)($v1)
  .L801073D4:
    /* 4BD4 801073D4 0FFD030C */  jal        vs_mainMenu_processItemActionMenu
    /* 4BD8 801073D8 1180113C */   lui       $s1, %hi(D_80109A58)
    /* 4BDC 801073DC D8FC030C */  jal        vs_mainMenu_getSelectedItemAction
    /* 4BE0 801073E0 00000000 */   nop
    /* 4BE4 801073E4 01004224 */  addiu      $v0, $v0, 0x1
    /* 4BE8 801073E8 23004010 */  beqz       $v0, .L80107478
    /* 4BEC 801073EC 589A22AE */   sw        $v0, %lo(D_80109A58)($s1)
    /* 4BF0 801073F0 04EA030C */  jal        vs_mainMenu_menuItemFlyoutLeft
    /* 4BF4 801073F4 21200000 */   addu      $a0, $zero, $zero
    /* 4BF8 801073F8 04EA030C */  jal        vs_mainMenu_menuItemFlyoutLeft
    /* 4BFC 801073FC 01000424 */   addiu     $a0, $zero, 0x1
    /* 4C00 80107400 589A228E */  lw         $v0, %lo(D_80109A58)($s1)
    /* 4C04 80107404 00000000 */  nop
    /* 4C08 80107408 09005014 */  bne        $v0, $s0, .L80107430
    /* 4C0C 8010740C 00000000 */   nop
    /* 4C10 80107410 BC00030C */  jal        vs_battle_playMenuSelectSfx
    /* 4C14 80107414 00000000 */   nop
    /* 4C18 80107418 38EA030C */  jal        vs_mainMenu_clearMenuExcept
    /* 4C1C 8010741C 21200000 */   addu      $a0, $zero, $zero
    /* 4C20 80107420 540F040C */  jal        func_80103D50
    /* 4C24 80107424 21200000 */   addu      $a0, $zero, $zero
    /* 4C28 80107428 141D0408 */  j          .L80107450
    /* 4C2C 8010742C 1180033C */   lui       $v1, %hi(D_80109A5C)
  .L80107430:
    /* 4C30 80107430 BA00030C */  jal        vs_battle_playMenuLeaveSfx
    /* 4C34 80107434 00000000 */   nop
    /* 4C38 80107438 589A238E */  lw         $v1, %lo(D_80109A58)($s1)
    /* 4C3C 8010743C 02000224 */  addiu      $v0, $zero, 0x2
    /* 4C40 80107440 03006214 */  bne        $v1, $v0, .L80107450
    /* 4C44 80107444 1180033C */   lui       $v1, %hi(D_80109A5C)
    /* 4C48 80107448 FFFF0224 */  addiu      $v0, $zero, -0x1
    /* 4C4C 8010744C 589A22AE */  sw         $v0, %lo(D_80109A58)($s1)
  .L80107450:
    /* 4C50 80107450 02000224 */  addiu      $v0, $zero, 0x2
    /* 4C54 80107454 1E1D0408 */  j          .L80107478
    /* 4C58 80107458 5C9A62A0 */   sb        $v0, %lo(D_80109A5C)($v1)
  .L8010745C:
    /* 4C5C 8010745C 74EA030C */  jal        vs_mainmenu_ready
    /* 4C60 80107460 00000000 */   nop
    /* 4C64 80107464 04004010 */  beqz       $v0, .L80107478
    /* 4C68 80107468 1180023C */   lui       $v0, %hi(D_80109A58)
    /* 4C6C 8010746C 589A428C */  lw         $v0, %lo(D_80109A58)($v0)
    /* 4C70 80107470 1F1D0408 */  j          .L8010747C
    /* 4C74 80107474 00000000 */   nop
  .L80107478:
    /* 4C78 80107478 21100000 */  addu       $v0, $zero, $zero
  .L8010747C:
    /* 4C7C 8010747C 3000BF8F */  lw         $ra, 0x30($sp)
    /* 4C80 80107480 2C00B18F */  lw         $s1, 0x2C($sp)
    /* 4C84 80107484 2800B08F */  lw         $s0, 0x28($sp)
    /* 4C88 80107488 0800E003 */  jr         $ra
    /* 4C8C 8010748C 3800BD27 */   addiu     $sp, $sp, 0x38
endlabel func_801072B0
