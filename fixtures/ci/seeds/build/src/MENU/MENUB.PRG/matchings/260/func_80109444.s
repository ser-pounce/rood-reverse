nonmatching func_80109444, 0x30C

glabel func_80109444
    /* 6C44 80109444 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 6C48 80109448 1800B0AF */  sw         $s0, 0x18($sp)
    /* 6C4C 8010944C 21808000 */  addu       $s0, $a0, $zero
    /* 6C50 80109450 2400BFAF */  sw         $ra, 0x24($sp)
    /* 6C54 80109454 2000B2AF */  sw         $s2, 0x20($sp)
    /* 6C58 80109458 3E000012 */  beqz       $s0, .L80109554
    /* 6C5C 8010945C 1C00B1AF */   sw        $s1, 0x1C($sp)
    /* 6C60 80109460 F2FE030C */  jal        func_800FFBC8
    /* 6C64 80109464 00000000 */   nop
    /* 6C68 80109468 00000392 */  lbu        $v1, 0x0($s0)
    /* 6C6C 8010946C 1180023C */  lui        $v0, %hi(D_8010A698)
    /* 6C70 80109470 98A640A0 */  sb         $zero, %lo(D_8010A698)($v0)
    /* 6C74 80109474 1180023C */  lui        $v0, %hi(D_8010A69A)
    /* 6C78 80109478 1180043C */  lui        $a0, %hi(D_8010A69B)
    /* 6C7C 8010947C 9AA640A0 */  sb         $zero, %lo(D_8010A69A)($v0)
    /* 6C80 80109480 1180023C */  lui        $v0, %hi(D_8010A699)
    /* 6C84 80109484 9BA680A0 */  sb         $zero, %lo(D_8010A69B)($a0)
    /* 6C88 80109488 99A643A0 */  sb         $v1, %lo(D_8010A699)($v0)
    /* 6C8C 8010948C FF006330 */  andi       $v1, $v1, 0xFF
    /* 6C90 80109490 03006010 */  beqz       $v1, .L801094A0
    /* 6C94 80109494 03000224 */   addiu     $v0, $zero, 0x3
    /* 6C98 80109498 04006214 */  bne        $v1, $v0, .L801094AC
    /* 6C9C 8010949C 06000224 */   addiu     $v0, $zero, 0x6
  .L801094A0:
    /* 6CA0 801094A0 01000224 */  addiu      $v0, $zero, 0x1
    /* 6CA4 801094A4 3C250408 */  j          .L801094F0
    /* 6CA8 801094A8 9BA682A0 */   sb        $v0, %lo(D_8010A69B)($a0)
  .L801094AC:
    /* 6CAC 801094AC 0E006214 */  bne        $v1, $v0, .L801094E8
    /* 6CB0 801094B0 1180033C */   lui       $v1, %hi(D_8010A69A)
    /* 6CB4 801094B4 1180033C */  lui        $v1, %hi(_inventory)
    /* 6CB8 801094B8 01000292 */  lbu        $v0, 0x1($s0)
    /* 6CBC 801094BC A8A6638C */  lw         $v1, %lo(_inventory)($v1)
    /* 6CC0 801094C0 80100200 */  sll        $v0, $v0, 2
    /* 6CC4 801094C4 21186200 */  addu       $v1, $v1, $v0
    /* 6CC8 801094C8 000E6294 */  lhu        $v0, 0xE00($v1)
    /* 6CCC 801094CC 00000000 */  nop
    /* 6CD0 801094D0 CA01422C */  sltiu      $v0, $v0, 0x1CA
    /* 6CD4 801094D4 03004010 */  beqz       $v0, .L801094E4
    /* 6CD8 801094D8 02000224 */   addiu     $v0, $zero, 0x2
    /* 6CDC 801094DC 3C250408 */  j          .L801094F0
    /* 6CE0 801094E0 9BA682A0 */   sb        $v0, %lo(D_8010A69B)($a0)
  .L801094E4:
    /* 6CE4 801094E4 1180033C */  lui        $v1, %hi(D_8010A69A)
  .L801094E8:
    /* 6CE8 801094E8 01000224 */  addiu      $v0, $zero, 0x1
    /* 6CEC 801094EC 9AA662A0 */  sb         $v0, %lo(D_8010A69A)($v1)
  .L801094F0:
    /* 6CF0 801094F0 1180073C */  lui        $a3, %hi(D_8010A69B)
    /* 6CF4 801094F4 9BA6E290 */  lbu        $v0, %lo(D_8010A69B)($a3)
    /* 6CF8 801094F8 00000000 */  nop
    /* 6CFC 801094FC 8D004010 */  beqz       $v0, .L80109734
    /* 6D00 80109500 1E000424 */   addiu     $a0, $zero, 0x1E
    /* 6D04 80109504 40010524 */  addiu      $a1, $zero, 0x140
    /* 6D08 80109508 92000624 */  addiu      $a2, $zero, 0x92
    /* 6D0C 8010950C 1180033C */  lui        $v1, %hi(_menuText)
    /* 6D10 80109510 80A26324 */  addiu      $v1, $v1, %lo(_menuText)
    /* 6D14 80109514 04004224 */  addiu      $v0, $v0, 0x4
    /* 6D18 80109518 80100200 */  sll        $v0, $v0, 2
    /* 6D1C 8010951C 21104300 */  addu       $v0, $v0, $v1
    /* 6D20 80109520 1000A0AF */  sw         $zero, 0x10($sp)
    /* 6D24 80109524 00004294 */  lhu        $v0, 0x0($v0)
    /* 6D28 80109528 7E000724 */  addiu      $a3, $zero, 0x7E
    /* 6D2C 8010952C 40100200 */  sll        $v0, $v0, 1
    /* 6D30 80109530 21104300 */  addu       $v0, $v0, $v1
    /* 6D34 80109534 9723030C */  jal        vs_battle_setMenuItem
    /* 6D38 80109538 1400A2AF */   sw        $v0, 0x14($sp)
    /* 6D3C 8010953C 21184000 */  addu       $v1, $v0, $zero
    /* 6D40 80109540 02000224 */  addiu      $v0, $zero, 0x2
    /* 6D44 80109544 000062A0 */  sb         $v0, 0x0($v1)
    /* 6D48 80109548 C2000224 */  addiu      $v0, $zero, 0xC2
    /* 6D4C 8010954C CD250408 */  j          .L80109734
    /* 6D50 80109550 180062A4 */   sh        $v0, 0x18($v1)
  .L80109554:
    /* 6D54 80109554 1180103C */  lui        $s0, %hi(D_8010A698)
    /* 6D58 80109558 98A60392 */  lbu        $v1, %lo(D_8010A698)($s0)
    /* 6D5C 8010955C 01001224 */  addiu      $s2, $zero, 0x1
    /* 6D60 80109560 1B007210 */  beq        $v1, $s2, .L801095D0
    /* 6D64 80109564 02006228 */   slti      $v0, $v1, 0x2
    /* 6D68 80109568 05004010 */  beqz       $v0, .L80109580
    /* 6D6C 8010956C 02000224 */   addiu     $v0, $zero, 0x2
    /* 6D70 80109570 07006010 */  beqz       $v1, .L80109590
    /* 6D74 80109574 21100000 */   addu      $v0, $zero, $zero
    /* 6D78 80109578 CE250408 */  j          .L80109738
    /* 6D7C 8010957C 00000000 */   nop
  .L80109580:
    /* 6D80 80109580 1A006210 */  beq        $v1, $v0, .L801095EC
    /* 6D84 80109584 21100000 */   addu      $v0, $zero, $zero
    /* 6D88 80109588 CE250408 */  j          .L80109738
    /* 6D8C 8010958C 00000000 */   nop
  .L80109590:
    /* 6D90 80109590 1F000424 */  addiu      $a0, $zero, 0x1F
    /* 6D94 80109594 40010524 */  addiu      $a1, $zero, 0x140
    /* 6D98 80109598 A2000624 */  addiu      $a2, $zero, 0xA2
    /* 6D9C 8010959C 7E000724 */  addiu      $a3, $zero, 0x7E
    /* 6DA0 801095A0 1180023C */  lui        $v0, %hi(D_8010A3FC)
    /* 6DA4 801095A4 FCA34224 */  addiu      $v0, $v0, %lo(D_8010A3FC)
    /* 6DA8 801095A8 1000A0AF */  sw         $zero, 0x10($sp)
    /* 6DAC 801095AC 9723030C */  jal        vs_battle_setMenuItem
    /* 6DB0 801095B0 1400A2AF */   sw        $v0, 0x14($sp)
    /* 6DB4 801095B4 21184000 */  addu       $v1, $v0, $zero
    /* 6DB8 801095B8 02000224 */  addiu      $v0, $zero, 0x2
    /* 6DBC 801095BC 000062A0 */  sb         $v0, 0x0($v1)
    /* 6DC0 801095C0 C2000224 */  addiu      $v0, $zero, 0xC2
    /* 6DC4 801095C4 180062A4 */  sh         $v0, 0x18($v1)
    /* 6DC8 801095C8 CD250408 */  j          .L80109734
    /* 6DCC 801095CC 98A612A2 */   sb        $s2, %lo(D_8010A698)($s0)
  .L801095D0:
    /* 6DD0 801095D0 74EA030C */  jal        vs_mainmenu_ready
    /* 6DD4 801095D4 00000000 */   nop
    /* 6DD8 801095D8 98A60392 */  lbu        $v1, %lo(D_8010A698)($s0)
    /* 6DDC 801095DC 00000000 */  nop
    /* 6DE0 801095E0 21186200 */  addu       $v1, $v1, $v0
    /* 6DE4 801095E4 CD250408 */  j          .L80109734
    /* 6DE8 801095E8 98A603A2 */   sb        $v1, %lo(D_8010A698)($s0)
  .L801095EC:
    /* 6DEC 801095EC 1180103C */  lui        $s0, %hi(D_8010A69A)
    /* 6DF0 801095F0 9AA60492 */  lbu        $a0, %lo(D_8010A69A)($s0)
    /* 6DF4 801095F4 9223030C */  jal        vs_battle_getMenuItem
    /* 6DF8 801095F8 1E008424 */   addiu     $a0, $a0, 0x1E
    /* 6DFC 801095FC 060052A0 */  sb         $s2, 0x6($v0)
    /* 6E00 80109600 9AA60292 */  lbu        $v0, %lo(D_8010A69A)($s0)
    /* 6E04 80109604 1F000424 */  addiu      $a0, $zero, 0x1F
    /* 6E08 80109608 9223030C */  jal        vs_battle_getMenuItem
    /* 6E0C 8010960C 23208200 */   subu      $a0, $a0, $v0
    /* 6E10 80109610 0680113C */  lui        $s1, %hi(vs_main_buttonsPressed)
    /* 6E14 80109614 060040A0 */  sb         $zero, 0x6($v0)
    /* 6E18 80109618 D0E1228E */  lw         $v0, %lo(vs_main_buttonsPressed)($s1)
    /* 6E1C 8010961C 00000000 */  nop
    /* 6E20 80109620 60004230 */  andi       $v0, $v0, 0x60
    /* 6E24 80109624 1C004010 */  beqz       $v0, .L80109698
    /* 6E28 80109628 1180023C */   lui       $v0, %hi(D_8010A69B)
    /* 6E2C 8010962C 28EA030C */  jal        vs_mainMenu_menuItemFlyoutRight
    /* 6E30 80109630 1E000424 */   addiu     $a0, $zero, 0x1E
    /* 6E34 80109634 28EA030C */  jal        vs_mainMenu_menuItemFlyoutRight
    /* 6E38 80109638 1F000424 */   addiu     $a0, $zero, 0x1F
    /* 6E3C 8010963C D0E1228E */  lw         $v0, %lo(vs_main_buttonsPressed)($s1)
    /* 6E40 80109640 00000000 */  nop
    /* 6E44 80109644 40004230 */  andi       $v0, $v0, 0x40
    /* 6E48 80109648 05004010 */  beqz       $v0, .L80109660
    /* 6E4C 8010964C 00000000 */   nop
    /* 6E50 80109650 BA00030C */  jal        vs_battle_playMenuLeaveSfx
    /* 6E54 80109654 00000000 */   nop
    /* 6E58 80109658 CE250408 */  j          .L80109738
    /* 6E5C 8010965C FFFF0224 */   addiu     $v0, $zero, -0x1
  .L80109660:
    /* 6E60 80109660 BC00030C */  jal        vs_battle_playMenuSelectSfx
    /* 6E64 80109664 00000000 */   nop
    /* 6E68 80109668 9AA60292 */  lbu        $v0, %lo(D_8010A69A)($s0)
    /* 6E6C 8010966C 00000000 */  nop
    /* 6E70 80109670 31004014 */  bnez       $v0, .L80109738
    /* 6E74 80109674 00000000 */   nop
    /* 6E78 80109678 1180023C */  lui        $v0, %hi(D_8010A69B)
    /* 6E7C 8010967C 9BA64290 */  lbu        $v0, %lo(D_8010A69B)($v0)
    /* 6E80 80109680 00000000 */  nop
    /* 6E84 80109684 01004224 */  addiu      $v0, $v0, 0x1
    /* 6E88 80109688 9AA602A2 */  sb         $v0, %lo(D_8010A69A)($s0)
    /* 6E8C 8010968C 9AA60292 */  lbu        $v0, %lo(D_8010A69A)($s0)
    /* 6E90 80109690 CE250408 */  j          .L80109738
    /* 6E94 80109694 00000000 */   nop
  .L80109698:
    /* 6E98 80109698 9BA64290 */  lbu        $v0, %lo(D_8010A69B)($v0)
    /* 6E9C 8010969C 00000000 */  nop
    /* 6EA0 801096A0 0C004010 */  beqz       $v0, .L801096D4
    /* 6EA4 801096A4 0680023C */   lui       $v0, %hi(vs_main_buttonRepeat)
    /* 6EA8 801096A8 DCDF428C */  lw         $v0, %lo(vs_main_buttonRepeat)($v0)
    /* 6EAC 801096AC 00000000 */  nop
    /* 6EB0 801096B0 00504230 */  andi       $v0, $v0, 0x5000
    /* 6EB4 801096B4 08004010 */  beqz       $v0, .L801096D8
    /* 6EB8 801096B8 1180023C */   lui       $v0, %hi(D_8010A69A)
    /* 6EBC 801096BC BE00030C */  jal        vs_battle_playMenuChangeSfx
    /* 6EC0 801096C0 00000000 */   nop
    /* 6EC4 801096C4 9AA60292 */  lbu        $v0, %lo(D_8010A69A)($s0)
    /* 6EC8 801096C8 00000000 */  nop
    /* 6ECC 801096CC 23104202 */  subu       $v0, $s2, $v0
    /* 6ED0 801096D0 9AA602A2 */  sb         $v0, %lo(D_8010A69A)($s0)
  .L801096D4:
    /* 6ED4 801096D4 1180023C */  lui        $v0, %hi(D_8010A69A)
  .L801096D8:
    /* 6ED8 801096D8 9AA64290 */  lbu        $v0, %lo(D_8010A69A)($v0)
    /* 6EDC 801096DC 00000000 */  nop
    /* 6EE0 801096E0 03004010 */  beqz       $v0, .L801096F0
    /* 6EE4 801096E4 1180043C */   lui       $a0, %hi(D_8010A410)
    /* 6EE8 801096E8 C5250408 */  j          .L80109714
    /* 6EEC 801096EC 10A48424 */   addiu     $a0, $a0, %lo(D_8010A410)
  .L801096F0:
    /* 6EF0 801096F0 1180023C */  lui        $v0, %hi(D_8010A69B)
    /* 6EF4 801096F4 9BA64390 */  lbu        $v1, %lo(D_8010A69B)($v0)
    /* 6EF8 801096F8 01000224 */  addiu      $v0, $zero, 0x1
    /* 6EFC 801096FC 03006214 */  bne        $v1, $v0, .L8010970C
    /* 6F00 80109700 1180043C */   lui       $a0, %hi(D_8010A37A)
    /* 6F04 80109704 C5250408 */  j          .L80109714
    /* 6F08 80109708 7AA38424 */   addiu     $a0, $a0, %lo(D_8010A37A)
  .L8010970C:
    /* 6F0C 8010970C 1180043C */  lui        $a0, %hi(D_8010A3B6)
    /* 6F10 80109710 B6A38424 */  addiu      $a0, $a0, %lo(D_8010A3B6)
  .L80109714:
    /* 6F14 80109714 01FF030C */  jal        vs_mainmenu_setInformationMessage
    /* 6F18 80109718 1180103C */   lui       $s0, %hi(D_8010A5E9)
    /* 6F1C 8010971C 1180023C */  lui        $v0, %hi(D_8010A69A)
    /* 6F20 80109720 9AA64590 */  lbu        $a1, %lo(D_8010A69A)($v0)
    /* 6F24 80109724 E9A50492 */  lbu        $a0, %lo(D_8010A5E9)($s0)
    /* 6F28 80109728 5033030C */  jal        vs_battle_drawCursor
    /* 6F2C 8010972C 0800A524 */   addiu     $a1, $a1, 0x8
    /* 6F30 80109730 E9A502A2 */  sb         $v0, %lo(D_8010A5E9)($s0)
  .L80109734:
    /* 6F34 80109734 21100000 */  addu       $v0, $zero, $zero
  .L80109738:
    /* 6F38 80109738 2400BF8F */  lw         $ra, 0x24($sp)
    /* 6F3C 8010973C 2000B28F */  lw         $s2, 0x20($sp)
    /* 6F40 80109740 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 6F44 80109744 1800B08F */  lw         $s0, 0x18($sp)
    /* 6F48 80109748 0800E003 */  jr         $ra
    /* 6F4C 8010974C 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_80109444
