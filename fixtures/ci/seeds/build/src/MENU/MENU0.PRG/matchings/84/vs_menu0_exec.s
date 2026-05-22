nonmatching vs_menu0_exec, 0x790

glabel vs_menu0_exec
    /* 1AC8 801042C8 78FFBD27 */  addiu      $sp, $sp, -0x88
    /* 1ACC 801042CC 8400BFAF */  sw         $ra, 0x84($sp)
    /* 1AD0 801042D0 8000BEAF */  sw         $fp, 0x80($sp)
    /* 1AD4 801042D4 7C00B7AF */  sw         $s7, 0x7C($sp)
    /* 1AD8 801042D8 7800B6AF */  sw         $s6, 0x78($sp)
    /* 1ADC 801042DC 7400B5AF */  sw         $s5, 0x74($sp)
    /* 1AE0 801042E0 7000B4AF */  sw         $s4, 0x70($sp)
    /* 1AE4 801042E4 6C00B3AF */  sw         $s3, 0x6C($sp)
    /* 1AE8 801042E8 6800B2AF */  sw         $s2, 0x68($sp)
    /* 1AEC 801042EC 6400B1AF */  sw         $s1, 0x64($sp)
    /* 1AF0 801042F0 6000B0AF */  sw         $s0, 0x60($sp)
    /* 1AF4 801042F4 8800A4AF */  sw         $a0, 0x88($sp)
    /* 1AF8 801042F8 00008290 */  lbu        $v0, 0x0($a0)
    /* 1AFC 801042FC 00000000 */  nop
    /* 1B00 80104300 FDFF4324 */  addiu      $v1, $v0, -0x3
    /* 1B04 80104304 0F00622C */  sltiu      $v0, $v1, 0xF
    /* 1B08 80104308 C6014010 */  beqz       $v0, .L80104A24
    /* 1B0C 8010430C 1080023C */   lui       $v0, %hi(jtbl_80102830)
    /* 1B10 80104310 30284224 */  addiu      $v0, $v0, %lo(jtbl_80102830)
    /* 1B14 80104314 80180300 */  sll        $v1, $v1, 2
    /* 1B18 80104318 21186200 */  addu       $v1, $v1, $v0
    /* 1B1C 8010431C 0000628C */  lw         $v0, 0x0($v1)
    /* 1B20 80104320 00000000 */  nop
    /* 1B24 80104324 08004000 */  jr         $v0
    /* 1B28 80104328 00000000 */   nop
    /* 1B2C 8010432C 74EA030C */  jal        vs_mainmenu_ready
    /* 1B30 80104330 00000000 */   nop
    /* 1B34 80104334 BC014010 */  beqz       $v0, .L80104A28
    /* 1B38 80104338 21100000 */   addu      $v0, $zero, $zero
    /* 1B3C 8010433C F2FE030C */  jal        func_800FFBC8
    /* 1B40 80104340 00000000 */   nop
    /* 1B44 80104344 0F80023C */  lui        $v0, %hi(vs_battle_shortcutInvoked)
    /* 1B48 80104348 6A4E5190 */  lbu        $s1, %lo(vs_battle_shortcutInvoked)($v0)
    /* 1B4C 8010434C 00000000 */  nop
    /* 1B50 80104350 24002012 */  beqz       $s1, .L801043E4
    /* 1B54 80104354 09002426 */   addiu     $a0, $s1, 0x9
    /* 1B58 80104358 40010524 */  addiu      $a1, $zero, 0x140
    /* 1B5C 8010435C 22000624 */  addiu      $a2, $zero, 0x22
    /* 1B60 80104360 08000224 */  addiu      $v0, $zero, 0x8
    /* 1B64 80104364 1080033C */  lui        $v1, %hi(_baseStrings)
    /* 1B68 80104368 584A6324 */  addiu      $v1, $v1, %lo(_baseStrings)
    /* 1B6C 8010436C 1000A2AF */  sw         $v0, 0x10($sp)
    /* 1B70 80104370 40101100 */  sll        $v0, $s1, 1
    /* 1B74 80104374 21105100 */  addu       $v0, $v0, $s1
    /* 1B78 80104378 FDFF4224 */  addiu      $v0, $v0, -0x3
    /* 1B7C 8010437C 40100200 */  sll        $v0, $v0, 1
    /* 1B80 80104380 21104300 */  addu       $v0, $v0, $v1
    /* 1B84 80104384 00004294 */  lhu        $v0, 0x0($v0)
    /* 1B88 80104388 8C000724 */  addiu      $a3, $zero, 0x8C
    /* 1B8C 8010438C 40100200 */  sll        $v0, $v0, 1
    /* 1B90 80104390 21104300 */  addu       $v0, $v0, $v1
    /* 1B94 80104394 9723030C */  jal        vs_battle_setMenuItem
    /* 1B98 80104398 1400A2AF */   sw        $v0, 0x14($sp)
    /* 1B9C 8010439C 01000324 */  addiu      $v1, $zero, 0x1
    /* 1BA0 801043A0 060043A0 */  sb         $v1, 0x6($v0)
    /* 1BA4 801043A4 02000224 */  addiu      $v0, $zero, 0x2
    /* 1BA8 801043A8 AC002212 */  beq        $s1, $v0, .L8010465C
    /* 1BAC 801043AC 0300222A */   slti      $v0, $s1, 0x3
    /* 1BB0 801043B0 05004010 */  beqz       $v0, .L801043C8
    /* 1BB4 801043B4 01000224 */   addiu     $v0, $zero, 0x1
    /* 1BB8 801043B8 A1002212 */  beq        $s1, $v0, .L80104640
    /* 1BBC 801043BC 21100000 */   addu      $v0, $zero, $zero
    /* 1BC0 801043C0 8A120408 */  j          .L80104A28
    /* 1BC4 801043C4 00000000 */   nop
  .L801043C8:
    /* 1BC8 801043C8 03000224 */  addiu      $v0, $zero, 0x3
    /* 1BCC 801043CC AA002212 */  beq        $s1, $v0, .L80104678
    /* 1BD0 801043D0 04000224 */   addiu     $v0, $zero, 0x4
    /* 1BD4 801043D4 94012216 */  bne        $s1, $v0, .L80104A28
    /* 1BD8 801043D8 21100000 */   addu      $v0, $zero, $zero
    /* 1BDC 801043DC A6110408 */  j          .L80104698
    /* 1BE0 801043E0 0D000224 */   addiu     $v0, $zero, 0xD
  .L801043E4:
    /* 1BE4 801043E4 21880000 */  addu       $s1, $zero, $zero
    /* 1BE8 801043E8 04001E24 */  addiu      $fp, $zero, 0x4
    /* 1BEC 801043EC 02001724 */  addiu      $s7, $zero, 0x2
    /* 1BF0 801043F0 21B0C003 */  addu       $s6, $fp, $zero
    /* 1BF4 801043F4 1800A827 */  addiu      $t0, $sp, 0x18
    /* 1BF8 801043F8 5800A8AF */  sw         $t0, 0x58($sp)
    /* 1BFC 801043FC 21A80001 */  addu       $s5, $t0, $zero
    /* 1C00 80104400 1080023C */  lui        $v0, %hi(_baseStrings)
    /* 1C04 80104404 584A5324 */  addiu      $s3, $v0, %lo(_baseStrings)
    /* 1C08 80104408 21A06002 */  addu       $s4, $s3, $zero
  .L8010440C:
    /* 1C0C 8010440C 21202002 */  addu       $a0, $s1, $zero
    /* 1C10 80104410 00008296 */  lhu        $v0, 0x0($s4)
    /* 1C14 80104414 80181100 */  sll        $v1, $s1, 2
    /* 1C18 80104418 40100200 */  sll        $v0, $v0, 1
    /* 1C1C 8010441C 21105300 */  addu       $v0, $v0, $s3
    /* 1C20 80104420 0000A2AE */  sw         $v0, 0x0($s5)
    /* 1C24 80104424 2110F302 */  addu       $v0, $s7, $s3
    /* 1C28 80104428 5800A88F */  lw         $t0, 0x58($sp)
    /* 1C2C 8010442C 00004294 */  lhu        $v0, 0x0($v0)
    /* 1C30 80104430 21901601 */  addu       $s2, $t0, $s6
    /* 1C34 80104434 40100200 */  sll        $v0, $v0, 1
    /* 1C38 80104438 21105300 */  addu       $v0, $v0, $s3
    /* 1C3C 8010443C 000042AE */  sw         $v0, 0x0($s2)
    /* 1C40 80104440 4000A227 */  addiu      $v0, $sp, 0x40
    /* 1C44 80104444 21804300 */  addu       $s0, $v0, $v1
    /* 1C48 80104448 AB2B030C */  jal        vs_battle_spellClassUnlocked
    /* 1C4C 8010444C 000000AE */   sw        $zero, 0x0($s0)
    /* 1C50 80104450 0B004014 */  bnez       $v0, .L80104480
    /* 1C54 80104454 00000000 */   nop
    /* 1C58 80104458 0000028E */  lw         $v0, 0x0($s0)
    /* 1C5C 8010445C 00000000 */  nop
    /* 1C60 80104460 01004234 */  ori        $v0, $v0, 0x1
    /* 1C64 80104464 000002AE */  sw         $v0, 0x0($s0)
    /* 1C68 80104468 2110D303 */  addu       $v0, $fp, $s3
    /* 1C6C 8010446C 00004294 */  lhu        $v0, 0x0($v0)
    /* 1C70 80104470 00000000 */  nop
    /* 1C74 80104474 40100200 */  sll        $v0, $v0, 1
    /* 1C78 80104478 21105300 */  addu       $v0, $v0, $s3
    /* 1C7C 8010447C 000042AE */  sw         $v0, 0x0($s2)
  .L80104480:
    /* 1C80 80104480 0600DE27 */  addiu      $fp, $fp, 0x6
    /* 1C84 80104484 0600F726 */  addiu      $s7, $s7, 0x6
    /* 1C88 80104488 0800D626 */  addiu      $s6, $s6, 0x8
    /* 1C8C 8010448C 0800B526 */  addiu      $s5, $s5, 0x8
    /* 1C90 80104490 01003126 */  addiu      $s1, $s1, 0x1
    /* 1C94 80104494 0400222A */  slti       $v0, $s1, 0x4
    /* 1C98 80104498 DCFF4014 */  bnez       $v0, .L8010440C
    /* 1C9C 8010449C 06009426 */   addiu     $s4, $s4, 0x6
    /* 1CA0 801044A0 0680023C */  lui        $v0, %hi(vs_main_stateFlags)
    /* 1CA4 801044A4 98154324 */  addiu      $v1, $v0, %lo(vs_main_stateFlags)
    /* 1CA8 801044A8 B5006290 */  lbu        $v0, 0xB5($v1)
    /* 1CAC 801044AC 00000000 */  nop
    /* 1CB0 801044B0 3F004010 */  beqz       $v0, .L801045B0
    /* 1CB4 801044B4 21800000 */   addu      $s0, $zero, $zero
    /* 1CB8 801044B8 21906000 */  addu       $s2, $v1, $zero
    /* 1CBC 801044BC 21101202 */  addu       $v0, $s0, $s2
  .L801044C0:
    /* 1CC0 801044C0 56014290 */  lbu        $v0, 0x156($v0)
    /* 1CC4 801044C4 00000000 */  nop
    /* 1CC8 801044C8 06004014 */  bnez       $v0, .L801044E4
    /* 1CCC 801044CC C0181100 */   sll       $v1, $s1, 3
    /* 1CD0 801044D0 01001026 */  addiu      $s0, $s0, 0x1
    /* 1CD4 801044D4 3000022A */  slti       $v0, $s0, 0x30
    /* 1CD8 801044D8 F9FF4014 */  bnez       $v0, .L801044C0
    /* 1CDC 801044DC 21101202 */   addu      $v0, $s0, $s2
    /* 1CE0 801044E0 C0181100 */  sll        $v1, $s1, 3
  .L801044E4:
    /* 1CE4 801044E4 1800A427 */  addiu      $a0, $sp, 0x18
    /* 1CE8 801044E8 21188300 */  addu       $v1, $a0, $v1
    /* 1CEC 801044EC 1080023C */  lui        $v0, %hi(D_80105E5A)
    /* 1CF0 801044F0 5A5E5424 */  addiu      $s4, $v0, %lo(D_80105E5A)
    /* 1CF4 801044F4 000074AC */  sw         $s4, 0x0($v1)
    /* 1CF8 801044F8 C0101100 */  sll        $v0, $s1, 3
    /* 1CFC 801044FC 04004234 */  ori        $v0, $v0, 0x4
    /* 1D00 80104500 3F29020C */  jal        func_8008A4FC
    /* 1D04 80104504 21988200 */   addu      $s3, $a0, $v0
    /* 1D08 80104508 07004010 */  beqz       $v0, .L80104528
    /* 1D0C 8010450C 02000224 */   addiu     $v0, $zero, 0x2
    /* 1D10 80104510 B5004392 */  lbu        $v1, 0xB5($s2)
    /* 1D14 80104514 00000000 */  nop
    /* 1D18 80104518 04006214 */  bne        $v1, $v0, .L8010452C
    /* 1D1C 8010451C 1080023C */   lui       $v0, %hi(D_80105E68)
    /* 1D20 80104520 4C110408 */  j          .L80104530
    /* 1D24 80104524 5A008226 */   addiu     $v0, $s4, 0x5A
  .L80104528:
    /* 1D28 80104528 1080023C */  lui        $v0, %hi(D_80105E68)
  .L8010452C:
    /* 1D2C 8010452C 685E4224 */  addiu      $v0, $v0, %lo(D_80105E68)
  .L80104530:
    /* 1D30 80104530 3F29020C */  jal        func_8008A4FC
    /* 1D34 80104534 000062AE */   sw        $v0, 0x0($s3)
    /* 1D38 80104538 0B004010 */  beqz       $v0, .L80104568
    /* 1D3C 8010453C 0680023C */   lui       $v0, %hi(vs_main_stateFlags + 0xB5)
    /* 1D40 80104540 4D164390 */  lbu        $v1, %lo(vs_main_stateFlags + 0xB5)($v0)
    /* 1D44 80104544 02000224 */  addiu      $v0, $zero, 0x2
    /* 1D48 80104548 08006214 */  bne        $v1, $v0, .L8010456C
    /* 1D4C 8010454C 21900000 */   addu      $s2, $zero, $zero
    /* 1D50 80104550 C0101100 */  sll        $v0, $s1, 3
    /* 1D54 80104554 04004234 */  ori        $v0, $v0, 0x4
    /* 1D58 80104558 2118A203 */  addu       $v1, $sp, $v0
    /* 1D5C 8010455C 1080023C */  lui        $v0, %hi(D_80105EB4)
    /* 1D60 80104560 B45E4224 */  addiu      $v0, $v0, %lo(D_80105EB4)
    /* 1D64 80104564 180062AC */  sw         $v0, 0x18($v1)
  .L80104568:
    /* 1D68 80104568 21900000 */  addu       $s2, $zero, $zero
  .L8010456C:
    /* 1D6C 8010456C 80101100 */  sll        $v0, $s1, 2
    /* 1D70 80104570 4000A327 */  addiu      $v1, $sp, 0x40
    /* 1D74 80104574 21986200 */  addu       $s3, $v1, $v0
    /* 1D78 80104578 30000224 */  addiu      $v0, $zero, 0x30
    /* 1D7C 8010457C 0A000212 */  beq        $s0, $v0, .L801045A8
    /* 1D80 80104580 01003126 */   addiu     $s1, $s1, 0x1
    /* 1D84 80104584 0680023C */  lui        $v0, %hi(vs_main_stateFlags + 0xB5)
    /* 1D88 80104588 4D164390 */  lbu        $v1, %lo(vs_main_stateFlags + 0xB5)($v0)
    /* 1D8C 8010458C 02000224 */  addiu      $v0, $zero, 0x2
    /* 1D90 80104590 05006210 */  beq        $v1, $v0, .L801045A8
    /* 1D94 80104594 00000000 */   nop
    /* 1D98 80104598 3F29020C */  jal        func_8008A4FC
    /* 1D9C 8010459C 00000000 */   nop
    /* 1DA0 801045A0 02004014 */  bnez       $v0, .L801045AC
    /* 1DA4 801045A4 00000000 */   nop
  .L801045A8:
    /* 1DA8 801045A8 01001224 */  addiu      $s2, $zero, 0x1
  .L801045AC:
    /* 1DAC 801045AC 000072AE */  sw         $s2, 0x0($s3)
  .L801045B0:
    /* 1DB0 801045B0 0680023C */  lui        $v0, %hi(vs_main_settings)
    /* 1DB4 801045B4 20005224 */  addiu      $s2, $v0, %lo(vs_main_settings)
    /* 1DB8 801045B8 8800A88F */  lw         $t0, 0x88($sp)
    /* 1DBC 801045BC 03000224 */  addiu      $v0, $zero, 0x3
    /* 1DC0 801045C0 00000391 */  lbu        $v1, 0x0($t0)
    /* 1DC4 801045C4 01005092 */  lbu        $s0, 0x1($s2)
    /* 1DC8 801045C8 02006210 */  beq        $v1, $v0, .L801045D4
    /* 1DCC 801045CC 01000224 */   addiu     $v0, $zero, 0x1
    /* 1DD0 801045D0 010042A2 */  sb         $v0, 0x1($s2)
  .L801045D4:
    /* 1DD4 801045D4 21202002 */  addu       $a0, $s1, $zero
    /* 1DD8 801045D8 05010524 */  addiu      $a1, $zero, 0x105
    /* 1DDC 801045DC 1800A627 */  addiu      $a2, $sp, 0x18
    /* 1DE0 801045E0 7801040C */  jal        vs_mainmenu_setMenuRows
    /* 1DE4 801045E4 4000A727 */   addiu     $a3, $sp, 0x40
    /* 1DE8 801045E8 010050A2 */  sb         $s0, 0x1($s2)
    /* 1DEC 801045EC 8800A88F */  lw         $t0, 0x88($sp)
    /* 1DF0 801045F0 05000224 */  addiu      $v0, $zero, 0x5
    /* 1DF4 801045F4 89120408 */  j          .L80104A24
    /* 1DF8 801045F8 000002A1 */   sb        $v0, 0x0($t0)
    /* 1DFC 801045FC 3202040C */  jal        vs_mainmenu_getSelectedRow
    /* 1E00 80104600 00000000 */   nop
    /* 1E04 80104604 21184000 */  addu       $v1, $v0, $zero
    /* 1E08 80104608 01007124 */  addiu      $s1, $v1, 0x1
    /* 1E0C 8010460C 06012012 */  beqz       $s1, .L80104A28
    /* 1E10 80104610 21100000 */   addu      $v0, $zero, $zero
    /* 1E14 80104614 2D00201A */  blez       $s1, .L801046CC
    /* 1E18 80104618 0500622C */   sltiu     $v0, $v1, 0x5
    /* 1E1C 8010461C 01014010 */  beqz       $v0, .L80104A24
    /* 1E20 80104620 1080023C */   lui       $v0, %hi(jtbl_80102870)
    /* 1E24 80104624 70284224 */  addiu      $v0, $v0, %lo(jtbl_80102870)
    /* 1E28 80104628 80180300 */  sll        $v1, $v1, 2
    /* 1E2C 8010462C 21186200 */  addu       $v1, $v1, $v0
    /* 1E30 80104630 0000628C */  lw         $v0, 0x0($v1)
    /* 1E34 80104634 00000000 */  nop
    /* 1E38 80104638 08004000 */  jr         $v0
    /* 1E3C 8010463C 00000000 */   nop
  .L80104640:
    /* 1E40 80104640 07000224 */  addiu      $v0, $zero, 0x7
    /* 1E44 80104644 8800A88F */  lw         $t0, 0x88($sp)
    /* 1E48 80104648 01000424 */  addiu      $a0, $zero, 0x1
    /* 1E4C 8010464C C20A040C */  jal        _warlockMagicMenu
    /* 1E50 80104650 000002A1 */   sb        $v0, 0x0($t0)
    /* 1E54 80104654 8A120408 */  j          .L80104A28
    /* 1E58 80104658 21100000 */   addu      $v0, $zero, $zero
  .L8010465C:
    /* 1E5C 8010465C 09000224 */  addiu      $v0, $zero, 0x9
    /* 1E60 80104660 8800A88F */  lw         $t0, 0x88($sp)
    /* 1E64 80104664 01000424 */  addiu      $a0, $zero, 0x1
    /* 1E68 80104668 190D040C */  jal        _shamanMagicMenu
    /* 1E6C 8010466C 000002A1 */   sb        $v0, 0x0($t0)
    /* 1E70 80104670 8A120408 */  j          .L80104A28
    /* 1E74 80104674 21100000 */   addu      $v0, $zero, $zero
  .L80104678:
    /* 1E78 80104678 0B000224 */  addiu      $v0, $zero, 0xB
    /* 1E7C 8010467C 8800A88F */  lw         $t0, 0x88($sp)
    /* 1E80 80104680 01000424 */  addiu      $a0, $zero, 0x1
    /* 1E84 80104684 EA0D040C */  jal        _sorcererMagicMenu
    /* 1E88 80104688 000002A1 */   sb        $v0, 0x0($t0)
    /* 1E8C 8010468C 8A120408 */  j          .L80104A28
    /* 1E90 80104690 21100000 */   addu      $v0, $zero, $zero
    /* 1E94 80104694 0D000224 */  addiu      $v0, $zero, 0xD
  .L80104698:
    /* 1E98 80104698 8800A88F */  lw         $t0, 0x88($sp)
    /* 1E9C 8010469C 01000424 */  addiu      $a0, $zero, 0x1
    /* 1EA0 801046A0 BB0E040C */  jal        _enchanterMagicMenu
    /* 1EA4 801046A4 000002A1 */   sb        $v0, 0x0($t0)
    /* 1EA8 801046A8 8A120408 */  j          .L80104A28
    /* 1EAC 801046AC 21100000 */   addu      $v0, $zero, $zero
    /* 1EB0 801046B0 0E000224 */  addiu      $v0, $zero, 0xE
    /* 1EB4 801046B4 8800A88F */  lw         $t0, 0x88($sp)
    /* 1EB8 801046B8 01000424 */  addiu      $a0, $zero, 0x1
    /* 1EBC 801046BC 8C0F040C */  jal        _teleportMenu
    /* 1EC0 801046C0 000002A1 */   sb        $v0, 0x0($t0)
    /* 1EC4 801046C4 8A120408 */  j          .L80104A28
    /* 1EC8 801046C8 21100000 */   addu      $v0, $zero, $zero
  .L801046CC:
    /* 1ECC 801046CC FEFF0224 */  addiu      $v0, $zero, -0x2
    /* 1ED0 801046D0 05002216 */  bne        $s1, $v0, .L801046E8
    /* 1ED4 801046D4 00000000 */   nop
    /* 1ED8 801046D8 38EA030C */  jal        vs_mainMenu_clearMenuExcept
    /* 1EDC 801046DC 28000424 */   addiu     $a0, $zero, 0x28
    /* 1EE0 801046E0 58120408 */  j          .L80104960
    /* 1EE4 801046E4 00000000 */   nop
  .L801046E8:
    /* 1EE8 801046E8 38EA030C */  jal        vs_mainMenu_clearMenuExcept
    /* 1EEC 801046EC 28000424 */   addiu     $a0, $zero, 0x28
    /* 1EF0 801046F0 8800A88F */  lw         $t0, 0x88($sp)
    /* 1EF4 801046F4 0F000224 */  addiu      $v0, $zero, 0xF
    /* 1EF8 801046F8 89120408 */  j          .L80104A24
    /* 1EFC 801046FC 000002A1 */   sb        $v0, 0x0($t0)
    /* 1F00 80104700 9510040C */  jal        _drawMagicMenuHeader
    /* 1F04 80104704 00000000 */   nop
    /* 1F08 80104708 0A000424 */  addiu      $a0, $zero, 0xA
    /* 1F0C 8010470C 40010524 */  addiu      $a1, $zero, 0x140
    /* 1F10 80104710 22000624 */  addiu      $a2, $zero, 0x22
    /* 1F14 80104714 7E000724 */  addiu      $a3, $zero, 0x7E
    /* 1F18 80104718 08000224 */  addiu      $v0, $zero, 0x8
    /* 1F1C 8010471C 1000A2AF */  sw         $v0, 0x10($sp)
    /* 1F20 80104720 1080023C */  lui        $v0, %hi(D_80104AF8)
    /* 1F24 80104724 F84A4224 */  addiu      $v0, $v0, %lo(D_80104AF8)
    /* 1F28 80104728 9723030C */  jal        vs_battle_setMenuItem
    /* 1F2C 8010472C 1400A2AF */   sw        $v0, 0x14($sp)
    /* 1F30 80104730 02000424 */  addiu      $a0, $zero, 0x2
    /* 1F34 80104734 01000324 */  addiu      $v1, $zero, 0x1
    /* 1F38 80104738 C20A040C */  jal        _warlockMagicMenu
    /* 1F3C 8010473C 060043A0 */   sb        $v1, 0x6($v0)
    /* 1F40 80104740 8800A88F */  lw         $t0, 0x88($sp)
    /* 1F44 80104744 07000224 */  addiu      $v0, $zero, 0x7
    /* 1F48 80104748 89120408 */  j          .L80104A24
    /* 1F4C 8010474C 000002A1 */   sb        $v0, 0x0($t0)
    /* 1F50 80104750 C20A040C */  jal        _warlockMagicMenu
    /* 1F54 80104754 21200000 */   addu      $a0, $zero, $zero
    /* 1F58 80104758 21884000 */  addu       $s1, $v0, $zero
    /* 1F5C 8010475C B1002012 */  beqz       $s1, .L80104A24
    /* 1F60 80104760 00000000 */   nop
    /* 1F64 80104764 0600201A */  blez       $s1, .L80104780
    /* 1F68 80104768 0F80023C */   lui       $v0, %hi(D_800F4E98 + 0x4)
    /* 1F6C 8010476C 8800A88F */  lw         $t0, 0x88($sp)
    /* 1F70 80104770 0F80033C */  lui        $v1, %hi(vs_battle_executeAbilityType)
    /* 1F74 80104774 9C4E51AC */  sw         $s1, %lo(D_800F4E98 + 0x4)($v0)
    /* 1F78 80104778 44120408 */  j          .L80104910
    /* 1F7C 8010477C 06000224 */   addiu     $v0, $zero, 0x6
  .L80104780:
    /* 1F80 80104780 FEFF0224 */  addiu      $v0, $zero, -0x2
    /* 1F84 80104784 76002212 */  beq        $s1, $v0, .L80104960
    /* 1F88 80104788 00000000 */   nop
    /* 1F8C 8010478C 5C120408 */  j          .L80104970
    /* 1F90 80104790 00000000 */   nop
    /* 1F94 80104794 9510040C */  jal        _drawMagicMenuHeader
    /* 1F98 80104798 00000000 */   nop
    /* 1F9C 8010479C 0B000424 */  addiu      $a0, $zero, 0xB
    /* 1FA0 801047A0 40010524 */  addiu      $a1, $zero, 0x140
    /* 1FA4 801047A4 22000624 */  addiu      $a2, $zero, 0x22
    /* 1FA8 801047A8 7E000724 */  addiu      $a3, $zero, 0x7E
    /* 1FAC 801047AC 08000224 */  addiu      $v0, $zero, 0x8
    /* 1FB0 801047B0 1000A2AF */  sw         $v0, 0x10($sp)
    /* 1FB4 801047B4 1080023C */  lui        $v0, %hi(D_80104B64)
    /* 1FB8 801047B8 644B4224 */  addiu      $v0, $v0, %lo(D_80104B64)
    /* 1FBC 801047BC 9723030C */  jal        vs_battle_setMenuItem
    /* 1FC0 801047C0 1400A2AF */   sw        $v0, 0x14($sp)
    /* 1FC4 801047C4 02000424 */  addiu      $a0, $zero, 0x2
    /* 1FC8 801047C8 01000324 */  addiu      $v1, $zero, 0x1
    /* 1FCC 801047CC 190D040C */  jal        _shamanMagicMenu
    /* 1FD0 801047D0 060043A0 */   sb        $v1, 0x6($v0)
    /* 1FD4 801047D4 8800A88F */  lw         $t0, 0x88($sp)
    /* 1FD8 801047D8 09000224 */  addiu      $v0, $zero, 0x9
    /* 1FDC 801047DC 89120408 */  j          .L80104A24
    /* 1FE0 801047E0 000002A1 */   sb        $v0, 0x0($t0)
    /* 1FE4 801047E4 190D040C */  jal        _shamanMagicMenu
    /* 1FE8 801047E8 21200000 */   addu      $a0, $zero, $zero
    /* 1FEC 801047EC 21884000 */  addu       $s1, $v0, $zero
    /* 1FF0 801047F0 8C002012 */  beqz       $s1, .L80104A24
    /* 1FF4 801047F4 00000000 */   nop
    /* 1FF8 801047F8 E1FF201A */  blez       $s1, .L80104780
    /* 1FFC 801047FC 0F80023C */   lui       $v0, %hi(D_800F4E98 + 0x4)
    /* 2000 80104800 8800A88F */  lw         $t0, 0x88($sp)
    /* 2004 80104804 0F80033C */  lui        $v1, %hi(vs_battle_executeAbilityType)
    /* 2008 80104808 9C4E51AC */  sw         $s1, %lo(D_800F4E98 + 0x4)($v0)
    /* 200C 8010480C 44120408 */  j          .L80104910
    /* 2010 80104810 08000224 */   addiu     $v0, $zero, 0x8
    /* 2014 80104814 9510040C */  jal        _drawMagicMenuHeader
    /* 2018 80104818 00000000 */   nop
    /* 201C 8010481C 0C000424 */  addiu      $a0, $zero, 0xC
    /* 2020 80104820 40010524 */  addiu      $a1, $zero, 0x140
    /* 2024 80104824 22000624 */  addiu      $a2, $zero, 0x22
    /* 2028 80104828 7E000724 */  addiu      $a3, $zero, 0x7E
    /* 202C 8010482C 08000224 */  addiu      $v0, $zero, 0x8
    /* 2030 80104830 1000A2AF */  sw         $v0, 0x10($sp)
    /* 2034 80104834 1080023C */  lui        $v0, %hi(D_80104BEC)
    /* 2038 80104838 EC4B4224 */  addiu      $v0, $v0, %lo(D_80104BEC)
    /* 203C 8010483C 9723030C */  jal        vs_battle_setMenuItem
    /* 2040 80104840 1400A2AF */   sw        $v0, 0x14($sp)
    /* 2044 80104844 02000424 */  addiu      $a0, $zero, 0x2
    /* 2048 80104848 01000324 */  addiu      $v1, $zero, 0x1
    /* 204C 8010484C EA0D040C */  jal        _sorcererMagicMenu
    /* 2050 80104850 060043A0 */   sb        $v1, 0x6($v0)
    /* 2054 80104854 8800A88F */  lw         $t0, 0x88($sp)
    /* 2058 80104858 0B000224 */  addiu      $v0, $zero, 0xB
    /* 205C 8010485C 89120408 */  j          .L80104A24
    /* 2060 80104860 000002A1 */   sb        $v0, 0x0($t0)
    /* 2064 80104864 EA0D040C */  jal        _sorcererMagicMenu
    /* 2068 80104868 21200000 */   addu      $a0, $zero, $zero
    /* 206C 8010486C 21884000 */  addu       $s1, $v0, $zero
    /* 2070 80104870 6C002012 */  beqz       $s1, .L80104A24
    /* 2074 80104874 00000000 */   nop
    /* 2078 80104878 C1FF201A */  blez       $s1, .L80104780
    /* 207C 8010487C 0F80023C */   lui       $v0, %hi(D_800F4E98 + 0x4)
    /* 2080 80104880 8800A88F */  lw         $t0, 0x88($sp)
    /* 2084 80104884 0F80033C */  lui        $v1, %hi(vs_battle_executeAbilityType)
    /* 2088 80104888 9C4E51AC */  sw         $s1, %lo(D_800F4E98 + 0x4)($v0)
    /* 208C 8010488C 44120408 */  j          .L80104910
    /* 2090 80104890 0A000224 */   addiu     $v0, $zero, 0xA
    /* 2094 80104894 9510040C */  jal        _drawMagicMenuHeader
    /* 2098 80104898 00000000 */   nop
    /* 209C 8010489C 0D000424 */  addiu      $a0, $zero, 0xD
    /* 20A0 801048A0 40010524 */  addiu      $a1, $zero, 0x140
    /* 20A4 801048A4 22000624 */  addiu      $a2, $zero, 0x22
    /* 20A8 801048A8 7E000724 */  addiu      $a3, $zero, 0x7E
    /* 20AC 801048AC 08000224 */  addiu      $v0, $zero, 0x8
    /* 20B0 801048B0 1000A2AF */  sw         $v0, 0x10($sp)
    /* 20B4 801048B4 1080023C */  lui        $v0, %hi(D_80104C8E)
    /* 20B8 801048B8 8E4C4224 */  addiu      $v0, $v0, %lo(D_80104C8E)
    /* 20BC 801048BC 9723030C */  jal        vs_battle_setMenuItem
    /* 20C0 801048C0 1400A2AF */   sw        $v0, 0x14($sp)
    /* 20C4 801048C4 02000424 */  addiu      $a0, $zero, 0x2
    /* 20C8 801048C8 01000324 */  addiu      $v1, $zero, 0x1
    /* 20CC 801048CC BB0E040C */  jal        _enchanterMagicMenu
    /* 20D0 801048D0 060043A0 */   sb        $v1, 0x6($v0)
    /* 20D4 801048D4 8800A88F */  lw         $t0, 0x88($sp)
    /* 20D8 801048D8 0D000224 */  addiu      $v0, $zero, 0xD
    /* 20DC 801048DC 89120408 */  j          .L80104A24
    /* 20E0 801048E0 000002A1 */   sb        $v0, 0x0($t0)
    /* 20E4 801048E4 BB0E040C */  jal        _enchanterMagicMenu
    /* 20E8 801048E8 21200000 */   addu      $a0, $zero, $zero
    /* 20EC 801048EC 21884000 */  addu       $s1, $v0, $zero
    /* 20F0 801048F0 4D002012 */  beqz       $s1, .L80104A28
    /* 20F4 801048F4 21100000 */   addu      $v0, $zero, $zero
    /* 20F8 801048F8 A1FF201A */  blez       $s1, .L80104780
    /* 20FC 801048FC 0F80023C */   lui       $v0, %hi(D_800F4E98 + 0x4)
    /* 2100 80104900 8800A88F */  lw         $t0, 0x88($sp)
    /* 2104 80104904 0F80033C */  lui        $v1, %hi(vs_battle_executeAbilityType)
    /* 2108 80104908 9C4E51AC */  sw         $s1, %lo(D_800F4E98 + 0x4)($v0)
    /* 210C 8010490C 0C000224 */  addiu      $v0, $zero, 0xC
  .L80104910:
    /* 2110 80104910 C25162A0 */  sb         $v0, %lo(vs_battle_executeAbilityType)($v1)
    /* 2114 80104914 10000224 */  addiu      $v0, $zero, 0x10
    /* 2118 80104918 89120408 */  j          .L80104A24
    /* 211C 8010491C 000002A1 */   sb        $v0, 0x0($t0)
    /* 2120 80104920 8C0F040C */  jal        _teleportMenu
    /* 2124 80104924 21200000 */   addu      $a0, $zero, $zero
    /* 2128 80104928 21884000 */  addu       $s1, $v0, $zero
    /* 212C 8010492C 3E002012 */  beqz       $s1, .L80104A28
    /* 2130 80104930 21100000 */   addu      $v0, $zero, $zero
    /* 2134 80104934 0700201A */  blez       $s1, .L80104954
    /* 2138 80104938 0F80023C */   lui       $v0, %hi(D_800F4E98)
    /* 213C 8010493C 984E4224 */  addiu      $v0, $v0, %lo(D_800F4E98)
    /* 2140 80104940 0A000324 */  addiu      $v1, $zero, 0xA
    /* 2144 80104944 020043A4 */  sh         $v1, 0x2($v0)
    /* 2148 80104948 FFFF2326 */  addiu      $v1, $s1, -0x1
    /* 214C 8010494C 58120408 */  j          .L80104960
    /* 2150 80104950 040043AC */   sw        $v1, 0x4($v0)
  .L80104954:
    /* 2154 80104954 FEFF0224 */  addiu      $v0, $zero, -0x2
    /* 2158 80104958 05002216 */  bne        $s1, $v0, .L80104970
    /* 215C 8010495C 00000000 */   nop
  .L80104960:
    /* 2160 80104960 8800A88F */  lw         $t0, 0x88($sp)
    /* 2164 80104964 11000224 */  addiu      $v0, $zero, 0x11
    /* 2168 80104968 89120408 */  j          .L80104A24
    /* 216C 8010496C 000002A1 */   sb        $v0, 0x0($t0)
  .L80104970:
    /* 2170 80104970 8800A88F */  lw         $t0, 0x88($sp)
    /* 2174 80104974 04000224 */  addiu      $v0, $zero, 0x4
    /* 2178 80104978 89120408 */  j          .L80104A24
    /* 217C 8010497C 000002A1 */   sb        $v0, 0x0($t0)
    /* 2180 80104980 EAFE030C */  jal        func_800FFBA8
    /* 2184 80104984 00000000 */   nop
    /* 2188 80104988 A2FE030C */  jal        func_800FFA88
    /* 218C 8010498C 21200000 */   addu      $a0, $zero, $zero
    /* 2190 80104990 74EA030C */  jal        vs_mainmenu_ready
    /* 2194 80104994 00000000 */   nop
    /* 2198 80104998 22004010 */  beqz       $v0, .L80104A24
    /* 219C 8010499C 01000224 */   addiu     $v0, $zero, 0x1
    /* 21A0 801049A0 8800A88F */  lw         $t0, 0x88($sp)
    /* 21A4 801049A4 8A120408 */  j          .L80104A28
    /* 21A8 801049A8 000000A1 */   sb        $zero, 0x0($t0)
    /* 21AC 801049AC 74EA030C */  jal        vs_mainmenu_ready
    /* 21B0 801049B0 00000000 */   nop
    /* 21B4 801049B4 1B004010 */  beqz       $v0, .L80104A24
    /* 21B8 801049B8 01000224 */   addiu     $v0, $zero, 0x1
    /* 21BC 801049BC 0F80043C */  lui        $a0, %hi(D_800F4E98 + 0x2)
    /* 21C0 801049C0 07000324 */  addiu      $v1, $zero, 0x7
    /* 21C4 801049C4 9A4E83A4 */  sh         $v1, %lo(D_800F4E98 + 0x2)($a0)
    /* 21C8 801049C8 0F80033C */  lui        $v1, %hi(vs_battle_menuState)
    /* 21CC 801049CC C0516590 */  lbu        $a1, %lo(vs_battle_menuState)($v1)
    /* 21D0 801049D0 21204000 */  addu       $a0, $v0, $zero
    /* 21D4 801049D4 C05164A0 */  sb         $a0, %lo(vs_battle_menuState)($v1)
    /* 21D8 801049D8 C0516324 */  addiu      $v1, $v1, %lo(vs_battle_menuState)
    /* 21DC 801049DC 010065A0 */  sb         $a1, 0x1($v1)
    /* 21E0 801049E0 8800A88F */  lw         $t0, 0x88($sp)
    /* 21E4 801049E4 8A120408 */  j          .L80104A28
    /* 21E8 801049E8 000000A1 */   sb        $zero, 0x0($t0)
    /* 21EC 801049EC EAFE030C */  jal        func_800FFBA8
    /* 21F0 801049F0 00000000 */   nop
    /* 21F4 801049F4 A2FE030C */  jal        func_800FFA88
    /* 21F8 801049F8 21200000 */   addu      $a0, $zero, $zero
    /* 21FC 801049FC 74EA030C */  jal        vs_mainmenu_ready
    /* 2200 80104A00 00000000 */   nop
    /* 2204 80104A04 07004010 */  beqz       $v0, .L80104A24
    /* 2208 80104A08 01000224 */   addiu     $v0, $zero, 0x1
    /* 220C 80104A0C 0F80043C */  lui        $a0, %hi(vs_battle_menuState)
    /* 2210 80104A10 8800A88F */  lw         $t0, 0x88($sp)
    /* 2214 80104A14 21184000 */  addu       $v1, $v0, $zero
    /* 2218 80104A18 C05183A0 */  sb         $v1, %lo(vs_battle_menuState)($a0)
    /* 221C 80104A1C 8A120408 */  j          .L80104A28
    /* 2220 80104A20 000000A1 */   sb        $zero, 0x0($t0)
  .L80104A24:
    /* 2224 80104A24 21100000 */  addu       $v0, $zero, $zero
  .L80104A28:
    /* 2228 80104A28 8400BF8F */  lw         $ra, 0x84($sp)
    /* 222C 80104A2C 8000BE8F */  lw         $fp, 0x80($sp)
    /* 2230 80104A30 7C00B78F */  lw         $s7, 0x7C($sp)
    /* 2234 80104A34 7800B68F */  lw         $s6, 0x78($sp)
    /* 2238 80104A38 7400B58F */  lw         $s5, 0x74($sp)
    /* 223C 80104A3C 7000B48F */  lw         $s4, 0x70($sp)
    /* 2240 80104A40 6C00B38F */  lw         $s3, 0x6C($sp)
    /* 2244 80104A44 6800B28F */  lw         $s2, 0x68($sp)
    /* 2248 80104A48 6400B18F */  lw         $s1, 0x64($sp)
    /* 224C 80104A4C 6000B08F */  lw         $s0, 0x60($sp)
    /* 2250 80104A50 0800E003 */  jr         $ra
    /* 2254 80104A54 8800BD27 */   addiu     $sp, $sp, 0x88
endlabel vs_menu0_exec
