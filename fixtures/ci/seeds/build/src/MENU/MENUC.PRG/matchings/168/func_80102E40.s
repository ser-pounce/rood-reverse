nonmatching func_80102E40, 0x22C

glabel func_80102E40
    /* 640 80102E40 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 644 80102E44 1800B0AF */  sw         $s0, 0x18($sp)
    /* 648 80102E48 21808000 */  addu       $s0, $a0, $zero
    /* 64C 80102E4C 2000B2AF */  sw         $s2, 0x20($sp)
    /* 650 80102E50 21900000 */  addu       $s2, $zero, $zero
    /* 654 80102E54 2400BFAF */  sw         $ra, 0x24($sp)
    /* 658 80102E58 0B000012 */  beqz       $s0, .L80102E88
    /* 65C 80102E5C 1C00B1AF */   sw        $s1, 0x1C($sp)
    /* 660 80102E60 8123030C */  jal        func_800C8E04
    /* 664 80102E64 01000424 */   addiu     $a0, $zero, 0x1
    /* 668 80102E68 21104002 */  addu       $v0, $s2, $zero
    /* 66C 80102E6C 1180033C */  lui        $v1, %hi(D_8010BBF8)
    /* 670 80102E70 F8BB70A0 */  sb         $s0, %lo(D_8010BBF8)($v1)
    /* 674 80102E74 1180033C */  lui        $v1, %hi(D_8010BBF7)
    /* 678 80102E78 F7BB60A0 */  sb         $zero, %lo(D_8010BBF7)($v1)
    /* 67C 80102E7C 1180033C */  lui        $v1, %hi(D_8010BBF6)
    /* 680 80102E80 150C0408 */  j          .L80103054
    /* 684 80102E84 F6BB60A0 */   sb        $zero, %lo(D_8010BBF6)($v1)
  .L80102E88:
    /* 688 80102E88 1180103C */  lui        $s0, %hi(D_8010BBF6)
    /* 68C 80102E8C F6BB0692 */  lbu        $a2, %lo(D_8010BBF6)($s0)
    /* 690 80102E90 03000224 */  addiu      $v0, $zero, 0x3
    /* 694 80102E94 2300C210 */  beq        $a2, $v0, .L80102F24
    /* 698 80102E98 0400C228 */   slti      $v0, $a2, 0x4
    /* 69C 80102E9C 05004014 */  bnez       $v0, .L80102EB4
    /* 6A0 80102EA0 04000224 */   addiu     $v0, $zero, 0x4
    /* 6A4 80102EA4 2600C210 */  beq        $a2, $v0, .L80102F40
    /* 6A8 80102EA8 21800000 */   addu      $s0, $zero, $zero
    /* 6AC 80102EAC 080C0408 */  j          .L80103020
    /* 6B0 80102EB0 00000000 */   nop
  .L80102EB4:
    /* 6B4 80102EB4 5A00C004 */  bltz       $a2, .L80103020
    /* 6B8 80102EB8 1080023C */   lui       $v0, %hi(vs_mainMenu_menu12Text)
    /* 6BC 80102EBC A424448C */  lw         $a0, %lo(vs_mainMenu_menu12Text)($v0)
    /* 6C0 80102EC0 40100600 */  sll        $v0, $a2, 1
    /* 6C4 80102EC4 1180033C */  lui        $v1, %hi(D_8010BBF8)
    /* 6C8 80102EC8 21104400 */  addu       $v0, $v0, $a0
    /* 6CC 80102ECC 44004294 */  lhu        $v0, 0x44($v0)
    /* 6D0 80102ED0 F8BB6390 */  lbu        $v1, %lo(D_8010BBF8)($v1)
    /* 6D4 80102ED4 40100200 */  sll        $v0, $v0, 1
    /* 6D8 80102ED8 0200C314 */  bne        $a2, $v1, .L80102EE4
    /* 6DC 80102EDC 21108200 */   addu      $v0, $a0, $v0
    /* 6E0 80102EE0 3E098224 */  addiu      $v0, $a0, 0x93E
  .L80102EE4:
    /* 6E4 80102EE4 1D00C424 */  addiu      $a0, $a2, 0x1D
    /* 6E8 80102EE8 40010524 */  addiu      $a1, $zero, 0x140
    /* 6EC 80102EEC 00310600 */  sll        $a2, $a2, 4
    /* 6F0 80102EF0 8200C624 */  addiu      $a2, $a2, 0x82
    /* 6F4 80102EF4 7E000724 */  addiu      $a3, $zero, 0x7E
    /* 6F8 80102EF8 1000A0AF */  sw         $zero, 0x10($sp)
    /* 6FC 80102EFC 9723030C */  jal        vs_battle_setMenuItem
    /* 700 80102F00 1400A2AF */   sw        $v0, 0x14($sp)
    /* 704 80102F04 02000324 */  addiu      $v1, $zero, 0x2
    /* 708 80102F08 000043A0 */  sb         $v1, 0x0($v0)
    /* 70C 80102F0C F6BB0392 */  lbu        $v1, %lo(D_8010BBF6)($s0)
    /* 710 80102F10 C2000424 */  addiu      $a0, $zero, 0xC2
    /* 714 80102F14 180044A4 */  sh         $a0, 0x18($v0)
    /* 718 80102F18 01006324 */  addiu      $v1, $v1, 0x1
    /* 71C 80102F1C 080C0408 */  j          .L80103020
    /* 720 80102F20 F6BB03A2 */   sb        $v1, %lo(D_8010BBF6)($s0)
  .L80102F24:
    /* 724 80102F24 74EA030C */  jal        vs_mainmenu_ready
    /* 728 80102F28 00000000 */   nop
    /* 72C 80102F2C F6BB0392 */  lbu        $v1, %lo(D_8010BBF6)($s0)
    /* 730 80102F30 00000000 */  nop
    /* 734 80102F34 21186200 */  addu       $v1, $v1, $v0
    /* 738 80102F38 080C0408 */  j          .L80103020
    /* 73C 80102F3C F6BB03A2 */   sb        $v1, %lo(D_8010BBF6)($s0)
  .L80102F40:
    /* 740 80102F40 1180113C */  lui        $s1, %hi(D_8010BBF7)
  .L80102F44:
    /* 744 80102F44 9223030C */  jal        vs_battle_getMenuItem
    /* 748 80102F48 1D000426 */   addiu     $a0, $s0, 0x1D
    /* 74C 80102F4C F7BB2392 */  lbu        $v1, %lo(D_8010BBF7)($s1)
    /* 750 80102F50 00000000 */  nop
    /* 754 80102F54 26180302 */  xor        $v1, $s0, $v1
    /* 758 80102F58 01001026 */  addiu      $s0, $s0, 0x1
    /* 75C 80102F5C 0100632C */  sltiu      $v1, $v1, 0x1
    /* 760 80102F60 060043A0 */  sb         $v1, 0x6($v0)
    /* 764 80102F64 0300022A */  slti       $v0, $s0, 0x3
    /* 768 80102F68 F6FF4014 */  bnez       $v0, .L80102F44
    /* 76C 80102F6C 0680023C */   lui       $v0, %hi(vs_main_buttonsPressed)
    /* 770 80102F70 D0E1438C */  lw         $v1, %lo(vs_main_buttonsPressed)($v0)
    /* 774 80102F74 00000000 */  nop
    /* 778 80102F78 10006230 */  andi       $v0, $v1, 0x10
    /* 77C 80102F7C 03004010 */  beqz       $v0, .L80102F8C
    /* 780 80102F80 40006230 */   andi      $v0, $v1, 0x40
    /* 784 80102F84 080C0408 */  j          .L80103020
    /* 788 80102F88 03001224 */   addiu     $s2, $zero, 0x3
  .L80102F8C:
    /* 78C 80102F8C 03004010 */  beqz       $v0, .L80102F9C
    /* 790 80102F90 20006230 */   andi      $v0, $v1, 0x20
    /* 794 80102F94 080C0408 */  j          .L80103020
    /* 798 80102F98 02001224 */   addiu     $s2, $zero, 0x2
  .L80102F9C:
    /* 79C 80102F9C 04004010 */  beqz       $v0, .L80102FB0
    /* 7A0 80102FA0 1180023C */   lui       $v0, %hi(D_8010BBF7)
    /* 7A4 80102FA4 F7BB4290 */  lbu        $v0, %lo(D_8010BBF7)($v0)
    /* 7A8 80102FA8 080C0408 */  j          .L80103020
    /* 7AC 80102FAC 01005224 */   addiu     $s2, $v0, 0x1
  .L80102FB0:
    /* 7B0 80102FB0 1180113C */  lui        $s1, %hi(D_8010BBF7)
    /* 7B4 80102FB4 0680023C */  lui        $v0, %hi(vs_main_buttonRepeat)
    /* 7B8 80102FB8 DCDF438C */  lw         $v1, %lo(vs_main_buttonRepeat)($v0)
    /* 7BC 80102FBC F7BB3092 */  lbu        $s0, %lo(D_8010BBF7)($s1)
    /* 7C0 80102FC0 00106230 */  andi       $v0, $v1, 0x1000
    /* 7C4 80102FC4 02004010 */  beqz       $v0, .L80102FD0
    /* 7C8 80102FC8 00406230 */   andi      $v0, $v1, 0x4000
    /* 7CC 80102FCC 02001026 */  addiu      $s0, $s0, 0x2
  .L80102FD0:
    /* 7D0 80102FD0 03004010 */  beqz       $v0, .L80102FE0
    /* 7D4 80102FD4 0300022A */   slti      $v0, $s0, 0x3
    /* 7D8 80102FD8 01001026 */  addiu      $s0, $s0, 0x1
    /* 7DC 80102FDC 0300022A */  slti       $v0, $s0, 0x3
  .L80102FE0:
    /* 7E0 80102FE0 02004014 */  bnez       $v0, .L80102FEC
    /* 7E4 80102FE4 00000000 */   nop
    /* 7E8 80102FE8 FDFF1026 */  addiu      $s0, $s0, -0x3
  .L80102FEC:
    /* 7EC 80102FEC F7BB2292 */  lbu        $v0, %lo(D_8010BBF7)($s1)
    /* 7F0 80102FF0 00000000 */  nop
    /* 7F4 80102FF4 04000212 */  beq        $s0, $v0, .L80103008
    /* 7F8 80102FF8 00000000 */   nop
    /* 7FC 80102FFC BE00030C */  jal        vs_battle_playMenuChangeSfx
    /* 800 80103000 00000000 */   nop
    /* 804 80103004 F7BB30A2 */  sb         $s0, %lo(D_8010BBF7)($s1)
  .L80103008:
    /* 808 80103008 1180103C */  lui        $s0, %hi(D_8010BB21)
    /* 80C 8010300C F7BB2592 */  lbu        $a1, %lo(D_8010BBF7)($s1)
    /* 810 80103010 21BB0492 */  lbu        $a0, %lo(D_8010BB21)($s0)
    /* 814 80103014 5033030C */  jal        vs_battle_drawCursor
    /* 818 80103018 0700A524 */   addiu     $a1, $a1, 0x7
    /* 81C 8010301C 21BB02A2 */  sb         $v0, %lo(D_8010BB21)($s0)
  .L80103020:
    /* 820 80103020 0B004012 */  beqz       $s2, .L80103050
    /* 824 80103024 02000224 */   addiu     $v0, $zero, 0x2
    /* 828 80103028 03004216 */  bne        $s2, $v0, .L80103038
    /* 82C 8010302C 1D001024 */   addiu     $s0, $zero, 0x1D
    /* 830 80103030 BA00030C */  jal        vs_battle_playMenuLeaveSfx
    /* 834 80103034 00000000 */   nop
  .L80103038:
    /* 838 80103038 28EA030C */  jal        vs_mainMenu_menuItemFlyoutRight
    /* 83C 8010303C 21200002 */   addu      $a0, $s0, $zero
    /* 840 80103040 01001026 */  addiu      $s0, $s0, 0x1
    /* 844 80103044 2000022A */  slti       $v0, $s0, 0x20
    /* 848 80103048 FBFF4014 */  bnez       $v0, .L80103038
    /* 84C 8010304C 00000000 */   nop
  .L80103050:
    /* 850 80103050 21104002 */  addu       $v0, $s2, $zero
  .L80103054:
    /* 854 80103054 2400BF8F */  lw         $ra, 0x24($sp)
    /* 858 80103058 2000B28F */  lw         $s2, 0x20($sp)
    /* 85C 8010305C 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 860 80103060 1800B08F */  lw         $s0, 0x18($sp)
    /* 864 80103064 0800E003 */  jr         $ra
    /* 868 80103068 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_80102E40
