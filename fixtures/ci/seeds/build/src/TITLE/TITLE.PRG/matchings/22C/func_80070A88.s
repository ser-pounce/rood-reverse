nonmatching func_80070A88, 0x3DC

glabel func_80070A88
    /* 8288 80070A88 C8FFBD27 */  addiu      $sp, $sp, -0x38
    /* 828C 80070A8C 06000424 */  addiu      $a0, $zero, 0x6
    /* 8290 80070A90 40000524 */  addiu      $a1, $zero, 0x40
    /* 8294 80070A94 1400B1AF */  sw         $s1, 0x14($sp)
    /* 8298 80070A98 01001124 */  addiu      $s1, $zero, 0x1
    /* 829C 80070A9C 0F80023C */  lui        $v0, %hi(_menuItemStates)
    /* 82A0 80070AA0 F8FD4224 */  addiu      $v0, $v0, %lo(_menuItemStates)
    /* 82A4 80070AA4 1800B2AF */  sw         $s2, 0x18($sp)
    /* 82A8 80070AA8 21904000 */  addu       $s2, $v0, $zero
    /* 82AC 80070AAC 21102002 */  addu       $v0, $s1, $zero
    /* 82B0 80070AB0 3000BFAF */  sw         $ra, 0x30($sp)
    /* 82B4 80070AB4 2C00B7AF */  sw         $s7, 0x2C($sp)
    /* 82B8 80070AB8 2800B6AF */  sw         $s6, 0x28($sp)
    /* 82BC 80070ABC 2400B5AF */  sw         $s5, 0x24($sp)
    /* 82C0 80070AC0 2000B4AF */  sw         $s4, 0x20($sp)
    /* 82C4 80070AC4 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 82C8 80070AC8 1000B0AF */  sw         $s0, 0x10($sp)
    /* 82CC 80070ACC 090042A2 */  sb         $v0, 0x9($s2)
    /* 82D0 80070AD0 02000224 */  addiu      $v0, $zero, 0x2
    /* 82D4 80070AD4 190042A2 */  sb         $v0, 0x19($s2)
    /* 82D8 80070AD8 80000224 */  addiu      $v0, $zero, 0x80
    /* 82DC 80070ADC 1D0042A2 */  sb         $v0, 0x1D($s2)
    /* 82E0 80070AE0 0680023C */  lui        $v0, %hi(D_8006002B)
    /* 82E4 80070AE4 0D0040A2 */  sb         $zero, 0xD($s2)
    /* 82E8 80070AE8 2B004290 */  lbu        $v0, %lo(D_8006002B)($v0)
    /* 82EC 80070AEC 03001024 */  addiu      $s0, $zero, 0x3
    /* 82F0 80070AF0 110050A2 */  sb         $s0, 0x11($s2)
    /* 82F4 80070AF4 0DBF010C */  jal        func_8006FC34
    /* 82F8 80070AF8 05005424 */   addiu     $s4, $v0, 0x5
    /* 82FC 80070AFC 05000424 */  addiu      $a0, $zero, 0x5
    /* 8300 80070B00 0DBF010C */  jal        func_8006FC34
    /* 8304 80070B04 60000524 */   addiu     $a1, $zero, 0x60
    /* 8308 80070B08 05000424 */  addiu      $a0, $zero, 0x5
    /* 830C 80070B0C 21280000 */  addu       $a1, $zero, $zero
    /* 8310 80070B10 2130A000 */  addu       $a2, $a1, $zero
    /* 8314 80070B14 2138A000 */  addu       $a3, $a1, $zero
    /* 8318 80070B18 290050A2 */  sb         $s0, 0x29($s2)
    /* 831C 80070B1C ABC0010C */  jal        _setMenuItemClut
    /* 8320 80070B20 310050A2 */   sb        $s0, 0x31($s2)
    /* 8324 80070B24 06000424 */  addiu      $a0, $zero, 0x6
    /* 8328 80070B28 21280000 */  addu       $a1, $zero, $zero
    /* 832C 80070B2C 2130A000 */  addu       $a2, $a1, $zero
    /* 8330 80070B30 ABC0010C */  jal        _setMenuItemClut
    /* 8334 80070B34 2138A000 */   addu      $a3, $a1, $zero
    /* 8338 80070B38 02000424 */  addiu      $a0, $zero, 0x2
  .L80070B3C:
    /* 833C 80070B3C 40281100 */  sll        $a1, $s1, 1
    /* 8340 80070B40 01000624 */  addiu      $a2, $zero, 0x1
    /* 8344 80070B44 ABC0010C */  jal        _setMenuItemClut
    /* 8348 80070B48 03000724 */   addiu     $a3, $zero, 0x3
    /* 834C 80070B4C 14004292 */  lbu        $v0, 0x14($s2)
    /* 8350 80070B50 01003126 */  addiu      $s1, $s1, 0x1
    /* 8354 80070B54 FCFF4224 */  addiu      $v0, $v0, -0x4
    /* 8358 80070B58 96C2010C */  jal        _drawAndSyncTitleMenu
    /* 835C 80070B5C 140042A2 */   sb        $v0, 0x14($s2)
    /* 8360 80070B60 0900222A */  slti       $v0, $s1, 0x9
    /* 8364 80070B64 F5FF4014 */  bnez       $v0, .L80070B3C
    /* 8368 80070B68 02000424 */   addiu     $a0, $zero, 0x2
    /* 836C 80070B6C 01001124 */  addiu      $s1, $zero, 0x1
    /* 8370 80070B70 0F80023C */  lui        $v0, %hi(_menuItemStates)
    /* 8374 80070B74 F8FD4224 */  addiu      $v0, $v0, %lo(_menuItemStates)
    /* 8378 80070B78 010040A0 */  sb         $zero, 0x1($v0)
    /* 837C 80070B7C 090040A0 */  sb         $zero, 0x9($v0)
    /* 8380 80070B80 190040A0 */  sb         $zero, 0x19($v0)
  .L80070B84:
    /* 8384 80070B84 96C2010C */  jal        _drawAndSyncTitleMenu
    /* 8388 80070B88 01003126 */   addiu     $s1, $s1, 0x1
    /* 838C 80070B8C 0900222A */  slti       $v0, $s1, 0x9
    /* 8390 80070B90 FCFF4014 */  bnez       $v0, .L80070B84
    /* 8394 80070B94 0F80023C */   lui       $v0, %hi(_menuItemStates)
    /* 8398 80070B98 21880000 */  addu       $s1, $zero, $zero
    /* 839C 80070B9C F8FD4224 */  addiu      $v0, $v0, %lo(_menuItemStates)
    /* 83A0 80070BA0 C0181400 */  sll        $v1, $s4, 3
    /* 83A4 80070BA4 21806200 */  addu       $s0, $v1, $v0
    /* 83A8 80070BA8 21208002 */  addu       $a0, $s4, $zero
  .L80070BAC:
    /* 83AC 80070BAC 40281100 */  sll        $a1, $s1, 1
    /* 83B0 80070BB0 21300000 */  addu       $a2, $zero, $zero
    /* 83B4 80070BB4 ABC0010C */  jal        _setMenuItemClut
    /* 83B8 80070BB8 01000724 */   addiu     $a3, $zero, 0x1
    /* 83BC 80070BBC 0400222A */  slti       $v0, $s1, 0x4
    /* 83C0 80070BC0 04004014 */  bnez       $v0, .L80070BD4
    /* 83C4 80070BC4 80111100 */   sll       $v0, $s1, 6
    /* 83C8 80070BC8 03000292 */  lbu        $v0, 0x3($s0)
    /* 83CC 80070BCC 00000000 */  nop
    /* 83D0 80070BD0 F0FF4224 */  addiu      $v0, $v0, -0x10
  .L80070BD4:
    /* 83D4 80070BD4 96C2010C */  jal        _drawAndSyncTitleMenu
    /* 83D8 80070BD8 030002A2 */   sb        $v0, 0x3($s0)
    /* 83DC 80070BDC 01003126 */  addiu      $s1, $s1, 0x1
    /* 83E0 80070BE0 0800222A */  slti       $v0, $s1, 0x8
    /* 83E4 80070BE4 F1FF4014 */  bnez       $v0, .L80070BAC
    /* 83E8 80070BE8 21208002 */   addu      $a0, $s4, $zero
    /* 83EC 80070BEC 0680023C */  lui        $v0, %hi(vs_main_settings)
    /* 83F0 80070BF0 20005724 */  addiu      $s7, $v0, %lo(vs_main_settings)
    /* 83F4 80070BF4 0B001524 */  addiu      $s5, $zero, 0xB
    /* 83F8 80070BF8 0F80023C */  lui        $v0, %hi(_menuItemStates)
    /* 83FC 80070BFC F8FD5624 */  addiu      $s6, $v0, %lo(_menuItemStates)
  .L80070C00:
    /* 8400 80070C00 96C2010C */  jal        _drawAndSyncTitleMenu
    /* 8404 80070C04 00000000 */   nop
    /* 8408 80070C08 0680023C */  lui        $v0, %hi(vs_main_buttonsState)
    /* 840C 80070C0C 38E2438C */  lw         $v1, %lo(vs_main_buttonsState)($v0)
    /* 8410 80070C10 00000000 */  nop
    /* 8414 80070C14 20086230 */  andi       $v0, $v1, 0x820
    /* 8418 80070C18 0C004010 */  beqz       $v0, .L80070C4C
    /* 841C 80070C1C 40006230 */   andi      $v0, $v1, 0x40
    /* 8420 80070C20 A3A2010C */  jal        _playMenuSelectSfx
    /* 8424 80070C24 00000000 */   nop
    /* 8428 80070C28 FBFF8226 */  addiu      $v0, $s4, -0x5
    /* 842C 80070C2C 0B00E2A2 */  sb         $v0, 0xB($s7)
    /* 8430 80070C30 06000224 */  addiu      $v0, $zero, 0x6
    /* 8434 80070C34 38008216 */  bne        $s4, $v0, .L80070D18
    /* 8438 80070C38 01000424 */   addiu     $a0, $zero, 0x1
    /* 843C 80070C3C 320E010C */  jal        func_800438C8
    /* 8440 80070C40 21200000 */   addu      $a0, $zero, $zero
    /* 8444 80070C44 46C30108 */  j          .L80070D18
    /* 8448 80070C48 01000424 */   addiu     $a0, $zero, 0x1
  .L80070C4C:
    /* 844C 80070C4C 05004010 */  beqz       $v0, .L80070C64
    /* 8450 80070C50 0680023C */   lui       $v0, %hi(vs_main_buttonsPressed)
    /* 8454 80070C54 ACA2010C */  jal        _playMenuLeaveSfx
    /* 8458 80070C58 00000000 */   nop
    /* 845C 80070C5C 46C30108 */  j          .L80070D18
    /* 8460 80070C60 01000424 */   addiu     $a0, $zero, 0x1
  .L80070C64:
    /* 8464 80070C64 D0E1428C */  lw         $v0, %lo(vs_main_buttonsPressed)($v0)
    /* 8468 80070C68 00000000 */  nop
    /* 846C 80070C6C 00514230 */  andi       $v0, $v0, 0x5100
    /* 8470 80070C70 E3FF4010 */  beqz       $v0, .L80070C00
    /* 8474 80070C74 00000000 */   nop
    /* 8478 80070C78 9AA2010C */  jal        _playMenuChangeSfx
    /* 847C 80070C7C 23A0B402 */   subu      $s4, $s5, $s4
    /* 8480 80070C80 01001124 */  addiu      $s1, $zero, 0x1
    /* 8484 80070C84 C0101400 */  sll        $v0, $s4, 3
    /* 8488 80070C88 21905600 */  addu       $s2, $v0, $s6
    /* 848C 80070C8C 2310B402 */  subu       $v0, $s5, $s4
    /* 8490 80070C90 C0100200 */  sll        $v0, $v0, 3
    /* 8494 80070C94 21985600 */  addu       $s3, $v0, $s6
    /* 8498 80070C98 21208002 */  addu       $a0, $s4, $zero
  .L80070C9C:
    /* 849C 80070C9C 40801100 */  sll        $s0, $s1, 1
    /* 84A0 80070CA0 21280002 */  addu       $a1, $s0, $zero
    /* 84A4 80070CA4 21300000 */  addu       $a2, $zero, $zero
    /* 84A8 80070CA8 ABC0010C */  jal        _setMenuItemClut
    /* 84AC 80070CAC 01000724 */   addiu     $a3, $zero, 0x1
    /* 84B0 80070CB0 2320B402 */  subu       $a0, $s5, $s4
    /* 84B4 80070CB4 21280002 */  addu       $a1, $s0, $zero
    /* 84B8 80070CB8 01000624 */  addiu      $a2, $zero, 0x1
    /* 84BC 80070CBC ABC0010C */  jal        _setMenuItemClut
    /* 84C0 80070CC0 21380000 */   addu      $a3, $zero, $zero
    /* 84C4 80070CC4 0400222A */  slti       $v0, $s1, 0x4
    /* 84C8 80070CC8 04004014 */  bnez       $v0, .L80070CDC
    /* 84CC 80070CCC 80111100 */   sll       $v0, $s1, 6
    /* 84D0 80070CD0 03004292 */  lbu        $v0, 0x3($s2)
    /* 84D4 80070CD4 00000000 */  nop
    /* 84D8 80070CD8 F0FF4224 */  addiu      $v0, $v0, -0x10
  .L80070CDC:
    /* 84DC 80070CDC 030042A2 */  sb         $v0, 0x3($s2)
    /* 84E0 80070CE0 03006292 */  lbu        $v0, 0x3($s3)
    /* 84E4 80070CE4 00000000 */  nop
    /* 84E8 80070CE8 F0FF4224 */  addiu      $v0, $v0, -0x10
    /* 84EC 80070CEC 030062A2 */  sb         $v0, 0x3($s3)
    /* 84F0 80070CF0 07000224 */  addiu      $v0, $zero, 0x7
    /* 84F4 80070CF4 C2FF2212 */  beq        $s1, $v0, .L80070C00
    /* 84F8 80070CF8 00000000 */   nop
    /* 84FC 80070CFC 96C2010C */  jal        _drawAndSyncTitleMenu
    /* 8500 80070D00 01003126 */   addiu     $s1, $s1, 0x1
    /* 8504 80070D04 0800222A */  slti       $v0, $s1, 0x8
    /* 8508 80070D08 E4FF4014 */  bnez       $v0, .L80070C9C
    /* 850C 80070D0C 21208002 */   addu      $a0, $s4, $zero
    /* 8510 80070D10 00C30108 */  j          .L80070C00
    /* 8514 80070D14 00000000 */   nop
  .L80070D18:
    /* 8518 80070D18 0DBF010C */  jal        func_8006FC34
    /* 851C 80070D1C 21280000 */   addu      $a1, $zero, $zero
    /* 8520 80070D20 03000424 */  addiu      $a0, $zero, 0x3
    /* 8524 80070D24 0DBF010C */  jal        func_8006FC34
    /* 8528 80070D28 80000524 */   addiu     $a1, $zero, 0x80
    /* 852C 80070D2C 01001124 */  addiu      $s1, $zero, 0x1
    /* 8530 80070D30 0F80023C */  lui        $v0, %hi(_menuItemStates)
    /* 8534 80070D34 F8FD4224 */  addiu      $v0, $v0, %lo(_menuItemStates)
    /* 8538 80070D38 21804000 */  addu       $s0, $v0, $zero
    /* 853C 80070D3C 02000224 */  addiu      $v0, $zero, 0x2
    /* 8540 80070D40 090002A2 */  sb         $v0, 0x9($s0)
    /* 8544 80070D44 20000224 */  addiu      $v0, $zero, 0x20
    /* 8548 80070D48 0D0002A2 */  sb         $v0, 0xD($s0)
    /* 854C 80070D4C 21102002 */  addu       $v0, $s1, $zero
    /* 8550 80070D50 190002A2 */  sb         $v0, 0x19($s0)
    /* 8554 80070D54 60000224 */  addiu      $v0, $zero, 0x60
    /* 8558 80070D58 1D0002A2 */  sb         $v0, 0x1D($s0)
    /* 855C 80070D5C 02000424 */  addiu      $a0, $zero, 0x2
  .L80070D60:
    /* 8560 80070D60 40281100 */  sll        $a1, $s1, 1
    /* 8564 80070D64 03000624 */  addiu      $a2, $zero, 0x3
    /* 8568 80070D68 ABC0010C */  jal        _setMenuItemClut
    /* 856C 80070D6C 01000724 */   addiu     $a3, $zero, 0x1
    /* 8570 80070D70 14000292 */  lbu        $v0, 0x14($s0)
    /* 8574 80070D74 2A000392 */  lbu        $v1, 0x2A($s0)
    /* 8578 80070D78 04004224 */  addiu      $v0, $v0, 0x4
    /* 857C 80070D7C 140002A2 */  sb         $v0, 0x14($s0)
    /* 8580 80070D80 1800622C */  sltiu      $v0, $v1, 0x18
    /* 8584 80070D84 03004010 */  beqz       $v0, .L80070D94
    /* 8588 80070D88 E8FF6224 */   addiu     $v0, $v1, -0x18
    /* 858C 80070D8C 66C30108 */  j          .L80070D98
    /* 8590 80070D90 2A0000A2 */   sb        $zero, 0x2A($s0)
  .L80070D94:
    /* 8594 80070D94 2A0002A2 */  sb         $v0, 0x2A($s0)
  .L80070D98:
    /* 8598 80070D98 32000392 */  lbu        $v1, 0x32($s0)
    /* 859C 80070D9C 00000000 */  nop
    /* 85A0 80070DA0 1800622C */  sltiu      $v0, $v1, 0x18
    /* 85A4 80070DA4 03004010 */  beqz       $v0, .L80070DB4
    /* 85A8 80070DA8 E8FF6224 */   addiu     $v0, $v1, -0x18
    /* 85AC 80070DAC 6EC30108 */  j          .L80070DB8
    /* 85B0 80070DB0 320000A2 */   sb        $zero, 0x32($s0)
  .L80070DB4:
    /* 85B4 80070DB4 320002A2 */  sb         $v0, 0x32($s0)
  .L80070DB8:
    /* 85B8 80070DB8 2B000292 */  lbu        $v0, 0x2B($s0)
    /* 85BC 80070DBC 00000000 */  nop
    /* 85C0 80070DC0 02004010 */  beqz       $v0, .L80070DCC
    /* 85C4 80070DC4 F0FF4224 */   addiu     $v0, $v0, -0x10
    /* 85C8 80070DC8 2B0002A2 */  sb         $v0, 0x2B($s0)
  .L80070DCC:
    /* 85CC 80070DCC 33000292 */  lbu        $v0, 0x33($s0)
    /* 85D0 80070DD0 00000000 */  nop
    /* 85D4 80070DD4 02004010 */  beqz       $v0, .L80070DE0
    /* 85D8 80070DD8 F0FF4224 */   addiu     $v0, $v0, -0x10
    /* 85DC 80070DDC 330002A2 */  sb         $v0, 0x33($s0)
  .L80070DE0:
    /* 85E0 80070DE0 96C2010C */  jal        _drawAndSyncTitleMenu
    /* 85E4 80070DE4 01003126 */   addiu     $s1, $s1, 0x1
    /* 85E8 80070DE8 0900222A */  slti       $v0, $s1, 0x9
    /* 85EC 80070DEC DCFF4014 */  bnez       $v0, .L80070D60
    /* 85F0 80070DF0 02000424 */   addiu     $a0, $zero, 0x2
    /* 85F4 80070DF4 0F80103C */  lui        $s0, %hi(_menuItemStates)
    /* 85F8 80070DF8 F8FD1026 */  addiu      $s0, $s0, %lo(_menuItemStates)
    /* 85FC 80070DFC 40000224 */  addiu      $v0, $zero, 0x40
    /* 8600 80070E00 280000A2 */  sb         $zero, 0x28($s0)
    /* 8604 80070E04 300000A2 */  sb         $zero, 0x30($s0)
    /* 8608 80070E08 160002A2 */  sb         $v0, 0x16($s0)
    /* 860C 80070E0C 96C2010C */  jal        _drawAndSyncTitleMenu
    /* 8610 80070E10 130002A2 */   sb        $v0, 0x13($s0)
    /* 8614 80070E14 80000224 */  addiu      $v0, $zero, 0x80
    /* 8618 80070E18 96C2010C */  jal        _drawAndSyncTitleMenu
    /* 861C 80070E1C 130002A2 */   sb        $v0, 0x13($s0)
    /* 8620 80070E20 C0000224 */  addiu      $v0, $zero, 0xC0
    /* 8624 80070E24 4FC2010C */  jal        _drawTitleMenu
    /* 8628 80070E28 130002A2 */   sb        $v0, 0x13($s0)
    /* 862C 80070E2C 10000224 */  addiu      $v0, $zero, 0x10
    /* 8630 80070E30 170002A2 */  sb         $v0, 0x17($s0)
    /* 8634 80070E34 110000A2 */  sb         $zero, 0x11($s0)
    /* 8638 80070E38 3000BF8F */  lw         $ra, 0x30($sp)
    /* 863C 80070E3C 2C00B78F */  lw         $s7, 0x2C($sp)
    /* 8640 80070E40 2800B68F */  lw         $s6, 0x28($sp)
    /* 8644 80070E44 2400B58F */  lw         $s5, 0x24($sp)
    /* 8648 80070E48 2000B48F */  lw         $s4, 0x20($sp)
    /* 864C 80070E4C 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 8650 80070E50 1800B28F */  lw         $s2, 0x18($sp)
    /* 8654 80070E54 1400B18F */  lw         $s1, 0x14($sp)
    /* 8658 80070E58 1000B08F */  lw         $s0, 0x10($sp)
    /* 865C 80070E5C 0800E003 */  jr         $ra
    /* 8660 80070E60 3800BD27 */   addiu     $sp, $sp, 0x38
endlabel func_80070A88
