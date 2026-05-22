nonmatching func_80102C58, 0x1E8

glabel func_80102C58
    /* 458 80102C58 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 45C 80102C5C 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 460 80102C60 21880000 */  addu       $s1, $zero, $zero
    /* 464 80102C64 2400BFAF */  sw         $ra, 0x24($sp)
    /* 468 80102C68 2000B2AF */  sw         $s2, 0x20($sp)
    /* 46C 80102C6C 09008010 */  beqz       $a0, .L80102C94
    /* 470 80102C70 1800B0AF */   sw        $s0, 0x18($sp)
    /* 474 80102C74 8123030C */  jal        func_800C8E04
    /* 478 80102C78 01000424 */   addiu     $a0, $zero, 0x1
    /* 47C 80102C7C 21102002 */  addu       $v0, $s1, $zero
    /* 480 80102C80 1180033C */  lui        $v1, %hi(D_8010BBF5)
    /* 484 80102C84 F5BB60A0 */  sb         $zero, %lo(D_8010BBF5)($v1)
    /* 488 80102C88 1180033C */  lui        $v1, %hi(D_8010BBF4)
    /* 48C 80102C8C 8A0B0408 */  j          .L80102E28
    /* 490 80102C90 F4BB60A0 */   sb        $zero, %lo(D_8010BBF4)($v1)
  .L80102C94:
    /* 494 80102C94 1180103C */  lui        $s0, %hi(D_8010BBF4)
    /* 498 80102C98 F4BB0692 */  lbu        $a2, %lo(D_8010BBF4)($s0)
    /* 49C 80102C9C 02001224 */  addiu      $s2, $zero, 0x2
    /* 4A0 80102CA0 1E00D210 */  beq        $a2, $s2, .L80102D1C
    /* 4A4 80102CA4 0300C228 */   slti      $v0, $a2, 0x3
    /* 4A8 80102CA8 05004014 */  bnez       $v0, .L80102CC0
    /* 4AC 80102CAC 03000224 */   addiu     $v0, $zero, 0x3
    /* 4B0 80102CB0 2100C210 */  beq        $a2, $v0, .L80102D38
    /* 4B4 80102CB4 21800000 */   addu      $s0, $zero, $zero
    /* 4B8 80102CB8 7D0B0408 */  j          .L80102DF4
    /* 4BC 80102CBC 00000000 */   nop
  .L80102CC0:
    /* 4C0 80102CC0 4C00C004 */  bltz       $a2, .L80102DF4
    /* 4C4 80102CC4 1D00C424 */   addiu     $a0, $a2, 0x1D
    /* 4C8 80102CC8 1080023C */  lui        $v0, %hi(vs_mainMenu_menu12Text)
    /* 4CC 80102CCC A424438C */  lw         $v1, %lo(vs_mainMenu_menu12Text)($v0)
    /* 4D0 80102CD0 40100600 */  sll        $v0, $a2, 1
    /* 4D4 80102CD4 40010524 */  addiu      $a1, $zero, 0x140
    /* 4D8 80102CD8 00310600 */  sll        $a2, $a2, 4
    /* 4DC 80102CDC 9200C624 */  addiu      $a2, $a2, 0x92
    /* 4E0 80102CE0 1000A0AF */  sw         $zero, 0x10($sp)
    /* 4E4 80102CE4 21104300 */  addu       $v0, $v0, $v1
    /* 4E8 80102CE8 44004294 */  lhu        $v0, 0x44($v0)
    /* 4EC 80102CEC 7E000724 */  addiu      $a3, $zero, 0x7E
    /* 4F0 80102CF0 40100200 */  sll        $v0, $v0, 1
    /* 4F4 80102CF4 21186200 */  addu       $v1, $v1, $v0
    /* 4F8 80102CF8 9723030C */  jal        vs_battle_setMenuItem
    /* 4FC 80102CFC 1400A3AF */   sw        $v1, 0x14($sp)
    /* 500 80102D00 000052A0 */  sb         $s2, 0x0($v0)
    /* 504 80102D04 F4BB0392 */  lbu        $v1, %lo(D_8010BBF4)($s0)
    /* 508 80102D08 C2000424 */  addiu      $a0, $zero, 0xC2
    /* 50C 80102D0C 180044A4 */  sh         $a0, 0x18($v0)
    /* 510 80102D10 01006324 */  addiu      $v1, $v1, 0x1
    /* 514 80102D14 7D0B0408 */  j          .L80102DF4
    /* 518 80102D18 F4BB03A2 */   sb        $v1, %lo(D_8010BBF4)($s0)
  .L80102D1C:
    /* 51C 80102D1C 74EA030C */  jal        vs_mainmenu_ready
    /* 520 80102D20 00000000 */   nop
    /* 524 80102D24 F4BB0392 */  lbu        $v1, %lo(D_8010BBF4)($s0)
    /* 528 80102D28 00000000 */  nop
    /* 52C 80102D2C 21186200 */  addu       $v1, $v1, $v0
    /* 530 80102D30 7D0B0408 */  j          .L80102DF4
    /* 534 80102D34 F4BB03A2 */   sb        $v1, %lo(D_8010BBF4)($s0)
  .L80102D38:
    /* 538 80102D38 1180123C */  lui        $s2, %hi(D_8010BBF5)
  .L80102D3C:
    /* 53C 80102D3C 9223030C */  jal        vs_battle_getMenuItem
    /* 540 80102D40 1D000426 */   addiu     $a0, $s0, 0x1D
    /* 544 80102D44 F5BB4392 */  lbu        $v1, %lo(D_8010BBF5)($s2)
    /* 548 80102D48 00000000 */  nop
    /* 54C 80102D4C 26180302 */  xor        $v1, $s0, $v1
    /* 550 80102D50 01001026 */  addiu      $s0, $s0, 0x1
    /* 554 80102D54 0100632C */  sltiu      $v1, $v1, 0x1
    /* 558 80102D58 060043A0 */  sb         $v1, 0x6($v0)
    /* 55C 80102D5C 0200022A */  slti       $v0, $s0, 0x2
    /* 560 80102D60 F6FF4014 */  bnez       $v0, .L80102D3C
    /* 564 80102D64 0680023C */   lui       $v0, %hi(vs_main_buttonsPressed)
    /* 568 80102D68 D0E1438C */  lw         $v1, %lo(vs_main_buttonsPressed)($v0)
    /* 56C 80102D6C 00000000 */  nop
    /* 570 80102D70 10006230 */  andi       $v0, $v1, 0x10
    /* 574 80102D74 03004010 */  beqz       $v0, .L80102D84
    /* 578 80102D78 40006230 */   andi      $v0, $v1, 0x40
    /* 57C 80102D7C 7D0B0408 */  j          .L80102DF4
    /* 580 80102D80 03001124 */   addiu     $s1, $zero, 0x3
  .L80102D84:
    /* 584 80102D84 03004010 */  beqz       $v0, .L80102D94
    /* 588 80102D88 20006230 */   andi      $v0, $v1, 0x20
    /* 58C 80102D8C 7D0B0408 */  j          .L80102DF4
    /* 590 80102D90 02001124 */   addiu     $s1, $zero, 0x2
  .L80102D94:
    /* 594 80102D94 04004010 */  beqz       $v0, .L80102DA8
    /* 598 80102D98 1180023C */   lui       $v0, %hi(D_8010BBF5)
    /* 59C 80102D9C F5BB4290 */  lbu        $v0, %lo(D_8010BBF5)($v0)
    /* 5A0 80102DA0 7D0B0408 */  j          .L80102DF4
    /* 5A4 80102DA4 01005124 */   addiu     $s1, $v0, 0x1
  .L80102DA8:
    /* 5A8 80102DA8 0680023C */  lui        $v0, %hi(vs_main_buttonRepeat)
    /* 5AC 80102DAC DCDF428C */  lw         $v0, %lo(vs_main_buttonRepeat)($v0)
    /* 5B0 80102DB0 00000000 */  nop
    /* 5B4 80102DB4 00504230 */  andi       $v0, $v0, 0x5000
    /* 5B8 80102DB8 08004010 */  beqz       $v0, .L80102DDC
    /* 5BC 80102DBC 1180103C */   lui       $s0, %hi(func_8010BB20)
    /* 5C0 80102DC0 BE00030C */  jal        vs_battle_playMenuChangeSfx
    /* 5C4 80102DC4 00000000 */   nop
    /* 5C8 80102DC8 1180043C */  lui        $a0, %hi(D_8010BBF5)
    /* 5CC 80102DCC F5BB8390 */  lbu        $v1, %lo(D_8010BBF5)($a0)
    /* 5D0 80102DD0 01000224 */  addiu      $v0, $zero, 0x1
    /* 5D4 80102DD4 23104300 */  subu       $v0, $v0, $v1
    /* 5D8 80102DD8 F5BB82A0 */  sb         $v0, %lo(D_8010BBF5)($a0)
  .L80102DDC:
    /* 5DC 80102DDC 1180023C */  lui        $v0, %hi(D_8010BBF5)
    /* 5E0 80102DE0 F5BB4590 */  lbu        $a1, %lo(D_8010BBF5)($v0)
    /* 5E4 80102DE4 20BB0492 */  lbu        $a0, %lo(func_8010BB20)($s0)
    /* 5E8 80102DE8 5033030C */  jal        vs_battle_drawCursor
    /* 5EC 80102DEC 0800A524 */   addiu     $a1, $a1, 0x8
    /* 5F0 80102DF0 20BB02A2 */  sb         $v0, %lo(func_8010BB20)($s0)
  .L80102DF4:
    /* 5F4 80102DF4 0B002012 */  beqz       $s1, .L80102E24
    /* 5F8 80102DF8 02000224 */   addiu     $v0, $zero, 0x2
    /* 5FC 80102DFC 03002216 */  bne        $s1, $v0, .L80102E0C
    /* 600 80102E00 1D001024 */   addiu     $s0, $zero, 0x1D
    /* 604 80102E04 BA00030C */  jal        vs_battle_playMenuLeaveSfx
    /* 608 80102E08 00000000 */   nop
  .L80102E0C:
    /* 60C 80102E0C 28EA030C */  jal        vs_mainMenu_menuItemFlyoutRight
    /* 610 80102E10 21200002 */   addu      $a0, $s0, $zero
    /* 614 80102E14 01001026 */  addiu      $s0, $s0, 0x1
    /* 618 80102E18 1F00022A */  slti       $v0, $s0, 0x1F
    /* 61C 80102E1C FBFF4014 */  bnez       $v0, .L80102E0C
    /* 620 80102E20 00000000 */   nop
  .L80102E24:
    /* 624 80102E24 21102002 */  addu       $v0, $s1, $zero
  .L80102E28:
    /* 628 80102E28 2400BF8F */  lw         $ra, 0x24($sp)
    /* 62C 80102E2C 2000B28F */  lw         $s2, 0x20($sp)
    /* 630 80102E30 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 634 80102E34 1800B08F */  lw         $s0, 0x18($sp)
    /* 638 80102E38 0800E003 */  jr         $ra
    /* 63C 80102E3C 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_80102C58
