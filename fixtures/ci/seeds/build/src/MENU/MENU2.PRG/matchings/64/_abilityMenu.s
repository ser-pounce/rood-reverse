nonmatching _abilityMenu, 0x850

glabel _abilityMenu
    /* 4AC 80102CAC C0FFBD27 */  addiu      $sp, $sp, -0x40
    /* 4B0 80102CB0 801F023C */  lui        $v0, (0x1F800008 >> 16)
    /* 4B4 80102CB4 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 4B8 80102CB8 1080113C */  lui        $s1, %hi(_abilityMenuState)
    /* 4BC 80102CBC 0800428C */  lw         $v0, (0x1F800008 & 0xFFFF)($v0)
    /* 4C0 80102CC0 BC4E288E */  lw         $t0, %lo(_abilityMenuState)($s1)
    /* 4C4 80102CC4 3800BEAF */  sw         $fp, 0x38($sp)
    /* 4C8 80102CC8 21F0A003 */  addu       $fp, $sp, $zero
    /* 4CC 80102CCC 3C00BFAF */  sw         $ra, 0x3C($sp)
    /* 4D0 80102CD0 3400B7AF */  sw         $s7, 0x34($sp)
    /* 4D4 80102CD4 3000B6AF */  sw         $s6, 0x30($sp)
    /* 4D8 80102CD8 2C00B5AF */  sw         $s5, 0x2C($sp)
    /* 4DC 80102CDC 2800B4AF */  sw         $s4, 0x28($sp)
    /* 4E0 80102CE0 2400B3AF */  sw         $s3, 0x24($sp)
    /* 4E4 80102CE4 2000B2AF */  sw         $s2, 0x20($sp)
    /* 4E8 80102CE8 08005324 */  addiu      $s3, $v0, 0x8
    /* 4EC 80102CEC 0A00022D */  sltiu      $v0, $t0, 0xA
    /* 4F0 80102CF0 34004010 */  beqz       $v0, .L80102DC4
    /* 4F4 80102CF4 1800B0AF */   sw        $s0, 0x18($sp)
    /* 4F8 80102CF8 14000425 */  addiu      $a0, $t0, 0x14
    /* 4FC 80102CFC 40010524 */  addiu      $a1, $zero, 0x140
    /* 500 80102D00 00310800 */  sll        $a2, $t0, 4
    /* 504 80102D04 3200C624 */  addiu      $a2, $a2, 0x32
    /* 508 80102D08 1080103C */  lui        $s0, %hi(_firstAbility)
    /* 50C 80102D0C 1080023C */  lui        $v0, %hi(_abilityText)
    /* 510 80102D10 C24E0392 */  lbu        $v1, %lo(_firstAbility)($s0)
    /* 514 80102D14 B44E428C */  lw         $v0, %lo(_abilityText)($v0)
    /* 518 80102D18 7E000724 */  addiu      $a3, $zero, 0x7E
    /* 51C 80102D1C 1000A0AF */  sw         $zero, 0x10($sp)
    /* 520 80102D20 21186800 */  addu       $v1, $v1, $t0
    /* 524 80102D24 C0190300 */  sll        $v1, $v1, 7
    /* 528 80102D28 21104300 */  addu       $v0, $v0, $v1
    /* 52C 80102D2C 9723030C */  jal        vs_battle_setMenuItem
    /* 530 80102D30 1400A2AF */   sw        $v0, 0x14($sp)
    /* 534 80102D34 21204000 */  addu       $a0, $v0, $zero
    /* 538 80102D38 02000224 */  addiu      $v0, $zero, 0x2
    /* 53C 80102D3C 000082A0 */  sb         $v0, 0x0($a0)
    /* 540 80102D40 BC4E238E */  lw         $v1, %lo(_abilityMenuState)($s1)
    /* 544 80102D44 C2000224 */  addiu      $v0, $zero, 0xC2
    /* 548 80102D48 06006014 */  bnez       $v1, .L80102D64
    /* 54C 80102D4C 180082A4 */   sh        $v0, 0x18($a0)
    /* 550 80102D50 C24E0292 */  lbu        $v0, %lo(_firstAbility)($s0)
    /* 554 80102D54 00000000 */  nop
    /* 558 80102D58 02004010 */  beqz       $v0, .L80102D64
    /* 55C 80102D5C 01000224 */   addiu     $v0, $zero, 0x1
    /* 560 80102D60 050082A0 */  sb         $v0, 0x5($a0)
  .L80102D64:
    /* 564 80102D64 1080053C */  lui        $a1, %hi(_abilityMenuState)
    /* 568 80102D68 1080033C */  lui        $v1, %hi(_abilityCount)
    /* 56C 80102D6C BC4EA28C */  lw         $v0, %lo(_abilityMenuState)($a1)
    /* 570 80102D70 C14E6690 */  lbu        $a2, %lo(_abilityCount)($v1)
    /* 574 80102D74 01004224 */  addiu      $v0, $v0, 0x1
    /* 578 80102D78 03004614 */  bne        $v0, $a2, .L80102D88
    /* 57C 80102D7C BC4EA2AC */   sw        $v0, %lo(_abilityMenuState)($a1)
    /* 580 80102D80 10000224 */  addiu      $v0, $zero, 0x10
    /* 584 80102D84 BC4EA2AC */  sw         $v0, %lo(_abilityMenuState)($a1)
  .L80102D88:
    /* 588 80102D88 BC4EA38C */  lw         $v1, %lo(_abilityMenuState)($a1)
    /* 58C 80102D8C 08000224 */  addiu      $v0, $zero, 0x8
    /* 590 80102D90 CD016214 */  bne        $v1, $v0, .L801034C8
    /* 594 80102D94 21100000 */   addu      $v0, $zero, $zero
    /* 598 80102D98 1080023C */  lui        $v0, %hi(_firstAbility)
    /* 59C 80102D9C C24E4290 */  lbu        $v0, %lo(_firstAbility)($v0)
    /* 5A0 80102DA0 00000000 */  nop
    /* 5A4 80102DA4 08004224 */  addiu      $v0, $v0, 0x8
    /* 5A8 80102DA8 2B104600 */  sltu       $v0, $v0, $a2
    /* 5AC 80102DAC 02004010 */  beqz       $v0, .L80102DB8
    /* 5B0 80102DB0 02000224 */   addiu     $v0, $zero, 0x2
    /* 5B4 80102DB4 050082A0 */  sb         $v0, 0x5($a0)
  .L80102DB8:
    /* 5B8 80102DB8 10000224 */  addiu      $v0, $zero, 0x10
    /* 5BC 80102DBC 310D0408 */  j          .L801034C4
    /* 5C0 80102DC0 BC4EA2AC */   sw        $v0, %lo(_abilityMenuState)($a1)
  .L80102DC4:
    /* 5C4 80102DC4 1080103C */  lui        $s0, %hi(_highlightedAbility)
    /* 5C8 80102DC8 B84E048E */  lw         $a0, %lo(_highlightedAbility)($s0)
    /* 5CC 80102DCC 9223030C */  jal        vs_battle_getMenuItem
    /* 5D0 80102DD0 14008424 */   addiu     $a0, $a0, 0x14
    /* 5D4 80102DD4 1080123C */  lui        $s2, %hi(_firstAbility)
    /* 5D8 80102DD8 C24E4292 */  lbu        $v0, %lo(_firstAbility)($s2)
    /* 5DC 80102DDC B84E048E */  lw         $a0, %lo(_highlightedAbility)($s0)
    /* 5E0 80102DE0 1080033C */  lui        $v1, %hi(_abilityText)
    /* 5E4 80102DE4 21208200 */  addu       $a0, $a0, $v0
    /* 5E8 80102DE8 C0210400 */  sll        $a0, $a0, 7
    /* 5EC 80102DEC B44E628C */  lw         $v0, %lo(_abilityText)($v1)
    /* 5F0 80102DF0 20008424 */  addiu      $a0, $a0, 0x20
    /* 5F4 80102DF4 01FF030C */  jal        vs_mainmenu_setInformationMessage
    /* 5F8 80102DF8 21204400 */   addu      $a0, $v0, $a0
    /* 5FC 80102DFC BC4E238E */  lw         $v1, %lo(_abilityMenuState)($s1)
    /* 600 80102E00 10000224 */  addiu      $v0, $zero, 0x10
    /* 604 80102E04 05006210 */  beq        $v1, $v0, .L80102E1C
    /* 608 80102E08 11000224 */   addiu     $v0, $zero, 0x11
    /* 60C 80102E0C 09006210 */  beq        $v1, $v0, .L80102E34
    /* 610 80102E10 21100000 */   addu      $v0, $zero, $zero
    /* 614 80102E14 320D0408 */  j          .L801034C8
    /* 618 80102E18 00000000 */   nop
  .L80102E1C:
    /* 61C 80102E1C 74EA030C */  jal        vs_mainmenu_ready
    /* 620 80102E20 00000000 */   nop
    /* 624 80102E24 A7014010 */  beqz       $v0, .L801034C4
    /* 628 80102E28 11000224 */   addiu     $v0, $zero, 0x11
    /* 62C 80102E2C 310D0408 */  j          .L801034C4
    /* 630 80102E30 BC4E22AE */   sw        $v0, %lo(_abilityMenuState)($s1)
  .L80102E34:
    /* 634 80102E34 C24E4492 */  lbu        $a0, %lo(_firstAbility)($s2)
    /* 638 80102E38 B84E038E */  lw         $v1, %lo(_highlightedAbility)($s0)
    /* 63C 80102E3C 1080023C */  lui        $v0, %hi(vs_mainMenu_isLevelledSpell)
    /* 640 80102E40 D42240A0 */  sb         $zero, %lo(vs_mainMenu_isLevelledSpell)($v0)
    /* 644 80102E44 21B06400 */  addu       $s6, $v1, $a0
    /* 648 80102E48 1080033C */  lui        $v1, %hi(_abilityCount)
    /* 64C 80102E4C C14E6290 */  lbu        $v0, %lo(_abilityCount)($v1)
    /* 650 80102E50 00000000 */  nop
    /* 654 80102E54 0900422C */  sltiu      $v0, $v0, 0x9
    /* 658 80102E58 48004010 */  beqz       $v0, .L80102F7C
    /* 65C 80102E5C 21B88000 */   addu      $s7, $a0, $zero
    /* 660 80102E60 C14E6290 */  lbu        $v0, %lo(_abilityCount)($v1)
    /* 664 80102E64 00000000 */  nop
    /* 668 80102E68 88004010 */  beqz       $v0, .L8010308C
    /* 66C 80102E6C 21880000 */   addu      $s1, $zero, $zero
    /* 670 80102E70 1080023C */  lui        $v0, %hi(_unlockedChainAbilities)
    /* 674 80102E74 D0505524 */  addiu      $s5, $v0, %lo(_unlockedChainAbilities)
    /* 678 80102E78 0680023C */  lui        $v0, %hi(vs_main_settings)
    /* 67C 80102E7C 20005424 */  addiu      $s4, $v0, %lo(vs_main_settings)
    /* 680 80102E80 30001224 */  addiu      $s2, $zero, 0x30
  .L80102E84:
    /* 684 80102E84 1080023C */  lui        $v0, %hi(_selectedAbilityType)
    /* 688 80102E88 C04E4390 */  lbu        $v1, %lo(_selectedAbilityType)($v0)
    /* 68C 80102E8C 18000224 */  addiu      $v0, $zero, 0x18
    /* 690 80102E90 16006214 */  bne        $v1, $v0, .L80102EEC
    /* 694 80102E94 1080023C */   lui       $v0, %hi(_unlockedDefenseAbilities)
    /* 698 80102E98 21103502 */  addu       $v0, $s1, $s5
    /* 69C 80102E9C 00005090 */  lbu        $s0, 0x0($v0)
    /* 6A0 80102EA0 0C008292 */  lbu        $v0, 0xC($s4)
    /* 6A4 80102EA4 00000000 */  nop
    /* 6A8 80102EA8 05005014 */  bne        $v0, $s0, .L80102EC0
    /* 6AC 80102EAC 02000424 */   addiu     $a0, $zero, 0x2
    /* 6B0 80102EB0 C7000524 */  addiu      $a1, $zero, 0xC7
    /* 6B4 80102EB4 21304002 */  addu       $a2, $s2, $zero
    /* 6B8 80102EB8 1AFF030C */  jal        vs_mainmenu_drawButton
    /* 6BC 80102EBC 21386002 */   addu      $a3, $s3, $zero
  .L80102EC0:
    /* 6C0 80102EC0 0D008292 */  lbu        $v0, 0xD($s4)
    /* 6C4 80102EC4 00000000 */  nop
    /* 6C8 80102EC8 05005014 */  bne        $v0, $s0, .L80102EE0
    /* 6CC 80102ECC 21200000 */   addu      $a0, $zero, $zero
    /* 6D0 80102ED0 C7000524 */  addiu      $a1, $zero, 0xC7
    /* 6D4 80102ED4 21304002 */  addu       $a2, $s2, $zero
    /* 6D8 80102ED8 1AFF030C */  jal        vs_mainmenu_drawButton
    /* 6DC 80102EDC 21386002 */   addu      $a3, $s3, $zero
  .L80102EE0:
    /* 6E0 80102EE0 0E008292 */  lbu        $v0, 0xE($s4)
    /* 6E4 80102EE4 CF0B0408 */  j          .L80102F3C
    /* 6E8 80102EE8 00000000 */   nop
  .L80102EEC:
    /* 6EC 80102EEC E0504224 */  addiu      $v0, $v0, %lo(_unlockedDefenseAbilities)
    /* 6F0 80102EF0 21102202 */  addu       $v0, $s1, $v0
    /* 6F4 80102EF4 00005090 */  lbu        $s0, 0x0($v0)
    /* 6F8 80102EF8 10008292 */  lbu        $v0, 0x10($s4)
    /* 6FC 80102EFC 00000000 */  nop
    /* 700 80102F00 05005014 */  bne        $v0, $s0, .L80102F18
    /* 704 80102F04 02000424 */   addiu     $a0, $zero, 0x2
    /* 708 80102F08 C7000524 */  addiu      $a1, $zero, 0xC7
    /* 70C 80102F0C 21304002 */  addu       $a2, $s2, $zero
    /* 710 80102F10 1AFF030C */  jal        vs_mainmenu_drawButton
    /* 714 80102F14 21386002 */   addu      $a3, $s3, $zero
  .L80102F18:
    /* 718 80102F18 11008292 */  lbu        $v0, 0x11($s4)
    /* 71C 80102F1C 00000000 */  nop
    /* 720 80102F20 05005014 */  bne        $v0, $s0, .L80102F38
    /* 724 80102F24 21200000 */   addu      $a0, $zero, $zero
    /* 728 80102F28 C7000524 */  addiu      $a1, $zero, 0xC7
    /* 72C 80102F2C 21304002 */  addu       $a2, $s2, $zero
    /* 730 80102F30 1AFF030C */  jal        vs_mainmenu_drawButton
    /* 734 80102F34 21386002 */   addu      $a3, $s3, $zero
  .L80102F38:
    /* 738 80102F38 12008292 */  lbu        $v0, 0x12($s4)
  .L80102F3C:
    /* 73C 80102F3C 00000000 */  nop
    /* 740 80102F40 07005014 */  bne        $v0, $s0, .L80102F60
    /* 744 80102F44 1080023C */   lui       $v0, %hi(_abilityCount)
    /* 748 80102F48 01000424 */  addiu      $a0, $zero, 0x1
    /* 74C 80102F4C C7000524 */  addiu      $a1, $zero, 0xC7
    /* 750 80102F50 21304002 */  addu       $a2, $s2, $zero
    /* 754 80102F54 1AFF030C */  jal        vs_mainmenu_drawButton
    /* 758 80102F58 21386002 */   addu      $a3, $s3, $zero
    /* 75C 80102F5C 1080023C */  lui        $v0, %hi(_abilityCount)
  .L80102F60:
    /* 760 80102F60 C14E4290 */  lbu        $v0, %lo(_abilityCount)($v0)
    /* 764 80102F64 01003126 */  addiu      $s1, $s1, 0x1
    /* 768 80102F68 2A102202 */  slt        $v0, $s1, $v0
    /* 76C 80102F6C C5FF4014 */  bnez       $v0, .L80102E84
    /* 770 80102F70 10005226 */   addiu     $s2, $s2, 0x10
    /* 774 80102F74 240C0408 */  j          .L80103090
    /* 778 80102F78 0680023C */   lui       $v0, %hi(vs_main_buttonsPressed)
  .L80102F7C:
    /* 77C 80102F7C 21880000 */  addu       $s1, $zero, $zero
    /* 780 80102F80 21A84002 */  addu       $s5, $s2, $zero
    /* 784 80102F84 0680023C */  lui        $v0, %hi(vs_main_settings)
    /* 788 80102F88 20005424 */  addiu      $s4, $v0, %lo(vs_main_settings)
    /* 78C 80102F8C 30001224 */  addiu      $s2, $zero, 0x30
  .L80102F90:
    /* 790 80102F90 1080023C */  lui        $v0, %hi(_selectedAbilityType)
    /* 794 80102F94 C04E4390 */  lbu        $v1, %lo(_selectedAbilityType)($v0)
    /* 798 80102F98 18000224 */  addiu      $v0, $zero, 0x18
    /* 79C 80102F9C 1A006214 */  bne        $v1, $v0, .L80103008
    /* 7A0 80102FA0 1080093C */   lui       $t1, %hi(_unlockedDefenseAbilities)
    /* 7A4 80102FA4 1080093C */  lui        $t1, %hi(_unlockedChainAbilities)
    /* 7A8 80102FA8 C24EA292 */  lbu        $v0, %lo(_firstAbility)($s5)
    /* 7AC 80102FAC D0502925 */  addiu      $t1, $t1, %lo(_unlockedChainAbilities)
    /* 7B0 80102FB0 21102202 */  addu       $v0, $s1, $v0
    /* 7B4 80102FB4 21104900 */  addu       $v0, $v0, $t1
    /* 7B8 80102FB8 00005090 */  lbu        $s0, 0x0($v0)
    /* 7BC 80102FBC 0C008292 */  lbu        $v0, 0xC($s4)
    /* 7C0 80102FC0 00000000 */  nop
    /* 7C4 80102FC4 05005014 */  bne        $v0, $s0, .L80102FDC
    /* 7C8 80102FC8 02000424 */   addiu     $a0, $zero, 0x2
    /* 7CC 80102FCC C7000524 */  addiu      $a1, $zero, 0xC7
    /* 7D0 80102FD0 21304002 */  addu       $a2, $s2, $zero
    /* 7D4 80102FD4 1AFF030C */  jal        vs_mainmenu_drawButton
    /* 7D8 80102FD8 21386002 */   addu      $a3, $s3, $zero
  .L80102FDC:
    /* 7DC 80102FDC 0D008292 */  lbu        $v0, 0xD($s4)
    /* 7E0 80102FE0 00000000 */  nop
    /* 7E4 80102FE4 05005014 */  bne        $v0, $s0, .L80102FFC
    /* 7E8 80102FE8 21200000 */   addu      $a0, $zero, $zero
    /* 7EC 80102FEC C7000524 */  addiu      $a1, $zero, 0xC7
    /* 7F0 80102FF0 21304002 */  addu       $a2, $s2, $zero
    /* 7F4 80102FF4 1AFF030C */  jal        vs_mainmenu_drawButton
    /* 7F8 80102FF8 21386002 */   addu      $a3, $s3, $zero
  .L80102FFC:
    /* 7FC 80102FFC 0E008292 */  lbu        $v0, 0xE($s4)
    /* 800 80103000 180C0408 */  j          .L80103060
    /* 804 80103004 00000000 */   nop
  .L80103008:
    /* 808 80103008 C24EA292 */  lbu        $v0, %lo(_firstAbility)($s5)
    /* 80C 8010300C E0502925 */  addiu      $t1, $t1, %lo(_unlockedDefenseAbilities)
    /* 810 80103010 21102202 */  addu       $v0, $s1, $v0
    /* 814 80103014 21104900 */  addu       $v0, $v0, $t1
    /* 818 80103018 00005090 */  lbu        $s0, 0x0($v0)
    /* 81C 8010301C 10008292 */  lbu        $v0, 0x10($s4)
    /* 820 80103020 00000000 */  nop
    /* 824 80103024 05005014 */  bne        $v0, $s0, .L8010303C
    /* 828 80103028 02000424 */   addiu     $a0, $zero, 0x2
    /* 82C 8010302C C7000524 */  addiu      $a1, $zero, 0xC7
    /* 830 80103030 21304002 */  addu       $a2, $s2, $zero
    /* 834 80103034 1AFF030C */  jal        vs_mainmenu_drawButton
    /* 838 80103038 21386002 */   addu      $a3, $s3, $zero
  .L8010303C:
    /* 83C 8010303C 11008292 */  lbu        $v0, 0x11($s4)
    /* 840 80103040 00000000 */  nop
    /* 844 80103044 05005014 */  bne        $v0, $s0, .L8010305C
    /* 848 80103048 21200000 */   addu      $a0, $zero, $zero
    /* 84C 8010304C C7000524 */  addiu      $a1, $zero, 0xC7
    /* 850 80103050 21304002 */  addu       $a2, $s2, $zero
    /* 854 80103054 1AFF030C */  jal        vs_mainmenu_drawButton
    /* 858 80103058 21386002 */   addu      $a3, $s3, $zero
  .L8010305C:
    /* 85C 8010305C 12008292 */  lbu        $v0, 0x12($s4)
  .L80103060:
    /* 860 80103060 00000000 */  nop
    /* 864 80103064 05005014 */  bne        $v0, $s0, .L8010307C
    /* 868 80103068 01000424 */   addiu     $a0, $zero, 0x1
    /* 86C 8010306C C7000524 */  addiu      $a1, $zero, 0xC7
    /* 870 80103070 21304002 */  addu       $a2, $s2, $zero
    /* 874 80103074 1AFF030C */  jal        vs_mainmenu_drawButton
    /* 878 80103078 21386002 */   addu      $a3, $s3, $zero
  .L8010307C:
    /* 87C 8010307C 01003126 */  addiu      $s1, $s1, 0x1
    /* 880 80103080 0800222A */  slti       $v0, $s1, 0x8
    /* 884 80103084 C2FF4014 */  bnez       $v0, .L80102F90
    /* 888 80103088 10005226 */   addiu     $s2, $s2, 0x10
  .L8010308C:
    /* 88C 8010308C 0680023C */  lui        $v0, %hi(vs_main_buttonsPressed)
  .L80103090:
    /* 890 80103090 D0E1438C */  lw         $v1, %lo(vs_main_buttonsPressed)($v0)
    /* 894 80103094 00000000 */  nop
    /* 898 80103098 20006230 */  andi       $v0, $v1, 0x20
    /* 89C 8010309C 04004010 */  beqz       $v0, .L801030B0
    /* 8A0 801030A0 1080023C */   lui       $v0, %hi(_selectedAbilityType)
    /* 8A4 801030A4 C04E4490 */  lbu        $a0, %lo(_selectedAbilityType)($v0)
    /* 8A8 801030A8 370C0408 */  j          .L801030DC
    /* 8AC 801030AC 21280000 */   addu      $a1, $zero, $zero
  .L801030B0:
    /* 8B0 801030B0 10006230 */  andi       $v0, $v1, 0x10
    /* 8B4 801030B4 04004010 */  beqz       $v0, .L801030C8
    /* 8B8 801030B8 1080023C */   lui       $v0, %hi(_selectedAbilityType)
    /* 8BC 801030BC C04E4490 */  lbu        $a0, %lo(_selectedAbilityType)($v0)
    /* 8C0 801030C0 370C0408 */  j          .L801030DC
    /* 8C4 801030C4 01000524 */   addiu     $a1, $zero, 0x1
  .L801030C8:
    /* 8C8 801030C8 80006230 */  andi       $v0, $v1, 0x80
    /* 8CC 801030CC 05004010 */  beqz       $v0, .L801030E4
    /* 8D0 801030D0 1080023C */   lui       $v0, %hi(_selectedAbilityType)
    /* 8D4 801030D4 C04E4490 */  lbu        $a0, %lo(_selectedAbilityType)($v0)
    /* 8D8 801030D8 02000524 */  addiu      $a1, $zero, 0x2
  .L801030DC:
    /* 8DC 801030DC D70A040C */  jal        _mapAbility
    /* 8E0 801030E0 2130C002 */   addu      $a2, $s6, $zero
  .L801030E4:
    /* 8E4 801030E4 1080113C */  lui        $s1, %hi(_highlightedAbility)
    /* 8E8 801030E8 B84E248E */  lw         $a0, %lo(_highlightedAbility)($s1)
    /* 8EC 801030EC 9223030C */  jal        vs_battle_getMenuItem
    /* 8F0 801030F0 14008424 */   addiu     $a0, $a0, 0x14
    /* 8F4 801030F4 060040A0 */  sb         $zero, 0x6($v0)
    /* 8F8 801030F8 0680023C */  lui        $v0, %hi(vs_main_buttonsPressed)
    /* 8FC 801030FC D0E1468C */  lw         $a2, %lo(vs_main_buttonsPressed)($v0)
    /* 900 80103100 00000000 */  nop
    /* 904 80103104 4000C230 */  andi       $v0, $a2, 0x40
    /* 908 80103108 18004010 */  beqz       $v0, .L8010316C
    /* 90C 8010310C 0680023C */   lui       $v0, %hi(vs_main_buttonRepeat)
    /* 910 80103110 BA00030C */  jal        vs_battle_playMenuLeaveSfx
    /* 914 80103114 1080103C */   lui       $s0, %hi(_abilityText)
    /* 918 80103118 B44E048E */  lw         $a0, %lo(_abilityText)($s0)
    /* 91C 8010311C 180F010C */  jal        vs_main_freeHeapR
    /* 920 80103120 00000000 */   nop
    /* 924 80103124 0F80053C */  lui        $a1, %hi(D_800F4EE8)
    /* 928 80103128 1080043C */  lui        $a0, %hi(_selectedAbilityType)
    /* 92C 8010312C C04E8290 */  lbu        $v0, %lo(_selectedAbilityType)($a0)
    /* 930 80103130 B84E2392 */  lbu        $v1, %lo(_highlightedAbility)($s1)
    /* 934 80103134 E84EA524 */  addiu      $a1, $a1, %lo(D_800F4EE8)
    /* 938 80103138 B44E00AE */  sw         $zero, %lo(_abilityText)($s0)
    /* 93C 8010313C 40100200 */  sll        $v0, $v0, 1
    /* 940 80103140 21104500 */  addu       $v0, $v0, $a1
    /* 944 80103144 000043A0 */  sb         $v1, 0x0($v0)
    /* 948 80103148 01000224 */  addiu      $v0, $zero, 0x1
    /* 94C 8010314C C04E8390 */  lbu        $v1, %lo(_selectedAbilityType)($a0)
    /* 950 80103150 1080043C */  lui        $a0, %hi(_firstAbility)
    /* 954 80103154 C24E8490 */  lbu        $a0, %lo(_firstAbility)($a0)
    /* 958 80103158 04184300 */  sllv       $v1, $v1, $v0
    /* 95C 8010315C 21186200 */  addu       $v1, $v1, $v0
    /* 960 80103160 21186500 */  addu       $v1, $v1, $a1
    /* 964 80103164 320D0408 */  j          .L801034C8
    /* 968 80103168 000064A0 */   sb        $a0, 0x0($v1)
  .L8010316C:
    /* 96C 8010316C DCDF428C */  lw         $v0, %lo(vs_main_buttonRepeat)($v0)
    /* 970 80103170 00000000 */  nop
    /* 974 80103174 00104230 */  andi       $v0, $v0, 0x1000
    /* 978 80103178 26004010 */  beqz       $v0, .L80103214
    /* 97C 8010317C 1080043C */   lui       $a0, %hi(_abilityCount)
    /* 980 80103180 C14E8390 */  lbu        $v1, %lo(_abilityCount)($a0)
    /* 984 80103184 00000000 */  nop
    /* 988 80103188 0900622C */  sltiu      $v0, $v1, 0x9
    /* 98C 8010318C 0A004010 */  beqz       $v0, .L801031B8
    /* 990 80103190 1080053C */   lui       $a1, %hi(_firstAbility)
    /* 994 80103194 B84E228E */  lw         $v0, %lo(_highlightedAbility)($s1)
    /* 998 80103198 00000000 */  nop
    /* 99C 8010319C 04004014 */  bnez       $v0, .L801031B0
    /* 9A0 801031A0 00000000 */   nop
    /* 9A4 801031A4 FF006230 */  andi       $v0, $v1, 0xFF
    /* 9A8 801031A8 840C0408 */  j          .L80103210
    /* 9AC 801031AC FFFF4224 */   addiu     $v0, $v0, -0x1
  .L801031B0:
    /* 9B0 801031B0 840C0408 */  j          .L80103210
    /* 9B4 801031B4 FFFF4224 */   addiu     $v0, $v0, -0x1
  .L801031B8:
    /* 9B8 801031B8 C24EA490 */  lbu        $a0, %lo(_firstAbility)($a1)
    /* 9BC 801031BC 00000000 */  nop
    /* 9C0 801031C0 0C008014 */  bnez       $a0, .L801031F4
    /* 9C4 801031C4 01000224 */   addiu     $v0, $zero, 0x1
    /* 9C8 801031C8 B84E228E */  lw         $v0, %lo(_highlightedAbility)($s1)
    /* 9CC 801031CC 00000000 */  nop
    /* 9D0 801031D0 0F004014 */  bnez       $v0, .L80103210
    /* 9D4 801031D4 FFFF4224 */   addiu     $v0, $v0, -0x1
    /* 9D8 801031D8 0010C230 */  andi       $v0, $a2, 0x1000
    /* 9DC 801031DC 0D004010 */  beqz       $v0, .L80103214
    /* 9E0 801031E0 07000224 */   addiu     $v0, $zero, 0x7
    /* 9E4 801031E4 B84E22AE */  sw         $v0, %lo(_highlightedAbility)($s1)
    /* 9E8 801031E8 F8FF6224 */  addiu      $v0, $v1, -0x8
    /* 9EC 801031EC 850C0408 */  j          .L80103214
    /* 9F0 801031F0 C24EA2A0 */   sb        $v0, %lo(_firstAbility)($a1)
  .L801031F4:
    /* 9F4 801031F4 B84E238E */  lw         $v1, %lo(_highlightedAbility)($s1)
    /* 9F8 801031F8 00000000 */  nop
    /* 9FC 801031FC 04006214 */  bne        $v1, $v0, .L80103210
    /* A00 80103200 FFFF6224 */   addiu     $v0, $v1, -0x1
    /* A04 80103204 FFFF8224 */  addiu      $v0, $a0, -0x1
    /* A08 80103208 850C0408 */  j          .L80103214
    /* A0C 8010320C C24EA2A0 */   sb        $v0, %lo(_firstAbility)($a1)
  .L80103210:
    /* A10 80103210 B84E22AE */  sw         $v0, %lo(_highlightedAbility)($s1)
  .L80103214:
    /* A14 80103214 0680023C */  lui        $v0, %hi(vs_main_buttonRepeat)
    /* A18 80103218 DCDF428C */  lw         $v0, %lo(vs_main_buttonRepeat)($v0)
    /* A1C 8010321C 00000000 */  nop
    /* A20 80103220 00404230 */  andi       $v0, $v0, 0x4000
    /* A24 80103224 2B004010 */  beqz       $v0, .L801032D4
    /* A28 80103228 1080033C */   lui       $v1, %hi(_abilityCount)
    /* A2C 8010322C C14E6290 */  lbu        $v0, %lo(_abilityCount)($v1)
    /* A30 80103230 00000000 */  nop
    /* A34 80103234 0900422C */  sltiu      $v0, $v0, 0x9
    /* A38 80103238 08004010 */  beqz       $v0, .L8010325C
    /* A3C 8010323C 1080043C */   lui       $a0, %hi(_highlightedAbility)
    /* A40 80103240 C14E6290 */  lbu        $v0, %lo(_abilityCount)($v1)
    /* A44 80103244 B84E838C */  lw         $v1, %lo(_highlightedAbility)($a0)
    /* A48 80103248 FFFF4224 */  addiu      $v0, $v0, -0x1
    /* A4C 8010324C 17006214 */  bne        $v1, $v0, .L801032AC
    /* A50 80103250 01006224 */   addiu     $v0, $v1, 0x1
    /* A54 80103254 B50C0408 */  j          .L801032D4
    /* A58 80103258 B84E80AC */   sw        $zero, %lo(_highlightedAbility)($a0)
  .L8010325C:
    /* A5C 8010325C 1080063C */  lui        $a2, %hi(_firstAbility)
    /* A60 80103260 C14E6290 */  lbu        $v0, %lo(_abilityCount)($v1)
    /* A64 80103264 C24EC490 */  lbu        $a0, %lo(_firstAbility)($a2)
    /* A68 80103268 F8FF4224 */  addiu      $v0, $v0, -0x8
    /* A6C 8010326C 11008214 */  bne        $a0, $v0, .L801032B4
    /* A70 80103270 1080053C */   lui       $a1, %hi(_highlightedAbility)
    /* A74 80103274 1080043C */  lui        $a0, %hi(_highlightedAbility)
    /* A78 80103278 B84E838C */  lw         $v1, %lo(_highlightedAbility)($a0)
    /* A7C 8010327C 07000224 */  addiu      $v0, $zero, 0x7
    /* A80 80103280 0A006214 */  bne        $v1, $v0, .L801032AC
    /* A84 80103284 01006224 */   addiu     $v0, $v1, 0x1
    /* A88 80103288 0680023C */  lui        $v0, %hi(vs_main_buttonsPressed)
    /* A8C 8010328C D0E1428C */  lw         $v0, %lo(vs_main_buttonsPressed)($v0)
    /* A90 80103290 00000000 */  nop
    /* A94 80103294 00404230 */  andi       $v0, $v0, 0x4000
    /* A98 80103298 0F004010 */  beqz       $v0, .L801032D8
    /* A9C 8010329C 1080023C */   lui       $v0, %hi(_highlightedAbility)
    /* AA0 801032A0 B84E80AC */  sw         $zero, %lo(_highlightedAbility)($a0)
    /* AA4 801032A4 B60C0408 */  j          .L801032D8
    /* AA8 801032A8 C24EC0A0 */   sb        $zero, %lo(_firstAbility)($a2)
  .L801032AC:
    /* AAC 801032AC B50C0408 */  j          .L801032D4
    /* AB0 801032B0 B84E82AC */   sw        $v0, %lo(_highlightedAbility)($a0)
  .L801032B4:
    /* AB4 801032B4 B84EA38C */  lw         $v1, %lo(_highlightedAbility)($a1)
    /* AB8 801032B8 06000224 */  addiu      $v0, $zero, 0x6
    /* ABC 801032BC 04006214 */  bne        $v1, $v0, .L801032D0
    /* AC0 801032C0 01006224 */   addiu     $v0, $v1, 0x1
    /* AC4 801032C4 01008224 */  addiu      $v0, $a0, 0x1
    /* AC8 801032C8 B50C0408 */  j          .L801032D4
    /* ACC 801032CC C24EC2A0 */   sb        $v0, %lo(_firstAbility)($a2)
  .L801032D0:
    /* AD0 801032D0 B84EA2AC */  sw         $v0, %lo(_highlightedAbility)($a1)
  .L801032D4:
    /* AD4 801032D4 1080023C */  lui        $v0, %hi(_highlightedAbility)
  .L801032D8:
    /* AD8 801032D8 1080103C */  lui        $s0, %hi(_firstAbility)
    /* ADC 801032DC C24E0392 */  lbu        $v1, %lo(_firstAbility)($s0)
    /* AE0 801032E0 B84E428C */  lw         $v0, %lo(_highlightedAbility)($v0)
    /* AE4 801032E4 00000000 */  nop
    /* AE8 801032E8 21104300 */  addu       $v0, $v0, $v1
    /* AEC 801032EC 5700C212 */  beq        $s6, $v0, .L8010344C
    /* AF0 801032F0 1080113C */   lui       $s1, %hi(_highlightedAbility)
    /* AF4 801032F4 BE00030C */  jal        vs_battle_playMenuChangeSfx
    /* AF8 801032F8 00000000 */   nop
    /* AFC 801032FC C24E0292 */  lbu        $v0, %lo(_firstAbility)($s0)
    /* B00 80103300 00000000 */  nop
    /* B04 80103304 50005710 */  beq        $v0, $s7, .L80103448
    /* B08 80103308 21880000 */   addu      $s1, $zero, $zero
    /* B0C 8010330C 1080043C */  lui        $a0, %hi(_abilityCount)
    /* B10 80103310 C14E8390 */  lbu        $v1, %lo(_abilityCount)($a0)
    /* B14 80103314 21A8A003 */  addu       $s5, $sp, $zero
    /* B18 80103318 07006224 */  addiu      $v0, $v1, 0x7
    /* B1C 8010331C F8014230 */  andi       $v0, $v0, 0x1F8
    /* B20 80103320 23E8A203 */  subu       $sp, $sp, $v0
    /* B24 80103324 08006010 */  beqz       $v1, .L80103348
    /* B28 80103328 1800B327 */   addiu     $s3, $sp, 0x18
    /* B2C 8010332C 21107102 */  addu       $v0, $s3, $s1
  .L80103330:
    /* B30 80103330 000040A0 */  sb         $zero, 0x0($v0)
    /* B34 80103334 C14E8290 */  lbu        $v0, %lo(_abilityCount)($a0)
    /* B38 80103338 01003126 */  addiu      $s1, $s1, 0x1
    /* B3C 8010333C 2A102202 */  slt        $v0, $s1, $v0
    /* B40 80103340 FBFF4014 */  bnez       $v0, .L80103330
    /* B44 80103344 21107102 */   addu      $v0, $s3, $s1
  .L80103348:
    /* B48 80103348 1080023C */  lui        $v0, %hi(_abilityCount)
    /* B4C 8010334C C14E5090 */  lbu        $s0, %lo(_abilityCount)($v0)
    /* B50 80103350 00000000 */  nop
    /* B54 80103354 0900022E */  sltiu      $v0, $s0, 0x9
    /* B58 80103358 02004014 */  bnez       $v0, .L80103364
    /* B5C 8010335C 00000000 */   nop
    /* B60 80103360 08001024 */  addiu      $s0, $zero, 0x8
  .L80103364:
    /* B64 80103364 0B000012 */  beqz       $s0, .L80103394
    /* B68 80103368 21880000 */   addu      $s1, $zero, $zero
  .L8010336C:
    /* B6C 8010336C 9223030C */  jal        vs_battle_getMenuItem
    /* B70 80103370 14002426 */   addiu     $a0, $s1, 0x14
    /* B74 80103374 21183702 */  addu       $v1, $s1, $s7
    /* B78 80103378 01003126 */  addiu      $s1, $s1, 0x1
    /* B7C 8010337C 04004290 */  lbu        $v0, 0x4($v0)
    /* B80 80103380 21186302 */  addu       $v1, $s3, $v1
    /* B84 80103384 000062A0 */  sb         $v0, 0x0($v1)
    /* B88 80103388 2A103002 */  slt        $v0, $s1, $s0
    /* B8C 8010338C F7FF4014 */  bnez       $v0, .L8010336C
    /* B90 80103390 00000000 */   nop
  .L80103394:
    /* B94 80103394 21880000 */  addu       $s1, $zero, $zero
    /* B98 80103398 1080143C */  lui        $s4, %hi(_abilityText)
    /* B9C 8010339C 1080123C */  lui        $s2, %hi(_firstAbility)
    /* BA0 801033A0 32001024 */  addiu      $s0, $zero, 0x32
  .L801033A4:
    /* BA4 801033A4 14002426 */  addiu      $a0, $s1, 0x14
    /* BA8 801033A8 C2000524 */  addiu      $a1, $zero, 0xC2
    /* BAC 801033AC 21300002 */  addu       $a2, $s0, $zero
    /* BB0 801033B0 C24E4392 */  lbu        $v1, %lo(_firstAbility)($s2)
    /* BB4 801033B4 B44E828E */  lw         $v0, %lo(_abilityText)($s4)
    /* BB8 801033B8 7E000724 */  addiu      $a3, $zero, 0x7E
    /* BBC 801033BC 1000A0AF */  sw         $zero, 0x10($sp)
    /* BC0 801033C0 21187100 */  addu       $v1, $v1, $s1
    /* BC4 801033C4 C0190300 */  sll        $v1, $v1, 7
    /* BC8 801033C8 21104300 */  addu       $v0, $v0, $v1
    /* BCC 801033CC 9723030C */  jal        vs_battle_setMenuItem
    /* BD0 801033D0 1400A2AF */   sw        $v0, 0x14($sp)
    /* BD4 801033D4 C24E4392 */  lbu        $v1, %lo(_firstAbility)($s2)
    /* BD8 801033D8 00000000 */  nop
    /* BDC 801033DC 21182302 */  addu       $v1, $s1, $v1
    /* BE0 801033E0 21186302 */  addu       $v1, $s3, $v1
    /* BE4 801033E4 00006390 */  lbu        $v1, 0x0($v1)
    /* BE8 801033E8 21204000 */  addu       $a0, $v0, $zero
    /* BEC 801033EC 06002016 */  bnez       $s1, .L80103408
    /* BF0 801033F0 040083A0 */   sb        $v1, 0x4($a0)
    /* BF4 801033F4 C24E4292 */  lbu        $v0, %lo(_firstAbility)($s2)
    /* BF8 801033F8 00000000 */  nop
    /* BFC 801033FC 02004010 */  beqz       $v0, .L80103408
    /* C00 80103400 01000224 */   addiu     $v0, $zero, 0x1
    /* C04 80103404 050082A0 */  sb         $v0, 0x5($a0)
  .L80103408:
    /* C08 80103408 1080023C */  lui        $v0, %hi(_abilityCount)
    /* C0C 8010340C C14E4390 */  lbu        $v1, %lo(_abilityCount)($v0)
    /* C10 80103410 01003126 */  addiu      $s1, $s1, 0x1
    /* C14 80103414 0B002312 */  beq        $s1, $v1, .L80103444
    /* C18 80103418 10001026 */   addiu     $s0, $s0, 0x10
    /* C1C 8010341C 08000224 */  addiu      $v0, $zero, 0x8
    /* C20 80103420 E0FF2216 */  bne        $s1, $v0, .L801033A4
    /* C24 80103424 00000000 */   nop
    /* C28 80103428 C24E4292 */  lbu        $v0, %lo(_firstAbility)($s2)
    /* C2C 8010342C 00000000 */  nop
    /* C30 80103430 08004224 */  addiu      $v0, $v0, 0x8
    /* C34 80103434 2A104300 */  slt        $v0, $v0, $v1
    /* C38 80103438 02004010 */  beqz       $v0, .L80103444
    /* C3C 8010343C 02000224 */   addiu     $v0, $zero, 0x2
    /* C40 80103440 050082A0 */  sb         $v0, 0x5($a0)
  .L80103444:
    /* C44 80103444 21E8A002 */  addu       $sp, $s5, $zero
  .L80103448:
    /* C48 80103448 1080113C */  lui        $s1, %hi(_highlightedAbility)
  .L8010344C:
    /* C4C 8010344C B84E248E */  lw         $a0, %lo(_highlightedAbility)($s1)
    /* C50 80103450 9223030C */  jal        vs_battle_getMenuItem
    /* C54 80103454 14008424 */   addiu     $a0, $a0, 0x14
    /* C58 80103458 01000324 */  addiu      $v1, $zero, 0x1
    /* C5C 8010345C 1080103C */  lui        $s0, %hi(cursorAnimStep)
    /* C60 80103460 060043A0 */  sb         $v1, 0x6($v0)
    /* C64 80103464 B84E258E */  lw         $a1, %lo(_highlightedAbility)($s1)
    /* C68 80103468 C44E048E */  lw         $a0, %lo(cursorAnimStep)($s0)
    /* C6C 8010346C 5033030C */  jal        vs_battle_drawCursor
    /* C70 80103470 0200A524 */   addiu     $a1, $a1, 0x2
    /* C74 80103474 C44E02AE */  sw         $v0, %lo(cursorAnimStep)($s0)
    /* C78 80103478 1080023C */  lui        $v0, %hi(_selectedAbilityType)
    /* C7C 8010347C C04E4390 */  lbu        $v1, %lo(_selectedAbilityType)($v0)
    /* C80 80103480 18000224 */  addiu      $v0, $zero, 0x18
    /* C84 80103484 06006214 */  bne        $v1, $v0, .L801034A0
    /* C88 80103488 1080023C */   lui       $v0, %hi(_firstAbility)
    /* C8C 8010348C 1080033C */  lui        $v1, %hi(_unlockedChainAbilities)
    /* C90 80103490 C24E4490 */  lbu        $a0, %lo(_firstAbility)($v0)
    /* C94 80103494 B84E228E */  lw         $v0, %lo(_highlightedAbility)($s1)
    /* C98 80103498 2C0D0408 */  j          .L801034B0
    /* C9C 8010349C D0506324 */   addiu     $v1, $v1, %lo(_unlockedChainAbilities)
  .L801034A0:
    /* CA0 801034A0 1080033C */  lui        $v1, %hi(_unlockedDefenseAbilities)
    /* CA4 801034A4 C24E4490 */  lbu        $a0, %lo(_firstAbility)($v0)
    /* CA8 801034A8 B84E228E */  lw         $v0, %lo(_highlightedAbility)($s1)
    /* CAC 801034AC E0506324 */  addiu      $v1, $v1, %lo(_unlockedDefenseAbilities)
  .L801034B0:
    /* CB0 801034B0 21104400 */  addu       $v0, $v0, $a0
    /* CB4 801034B4 21104300 */  addu       $v0, $v0, $v1
    /* CB8 801034B8 00004490 */  lbu        $a0, 0x0($v0)
    /* CBC 801034BC 190A040C */  jal        _setAbilityCost
    /* CC0 801034C0 00000000 */   nop
  .L801034C4:
    /* CC4 801034C4 21100000 */  addu       $v0, $zero, $zero
  .L801034C8:
    /* CC8 801034C8 21E8C003 */  addu       $sp, $fp, $zero
    /* CCC 801034CC 3C00BF8F */  lw         $ra, 0x3C($sp)
    /* CD0 801034D0 3800BE8F */  lw         $fp, 0x38($sp)
    /* CD4 801034D4 3400B78F */  lw         $s7, 0x34($sp)
    /* CD8 801034D8 3000B68F */  lw         $s6, 0x30($sp)
    /* CDC 801034DC 2C00B58F */  lw         $s5, 0x2C($sp)
    /* CE0 801034E0 2800B48F */  lw         $s4, 0x28($sp)
    /* CE4 801034E4 2400B38F */  lw         $s3, 0x24($sp)
    /* CE8 801034E8 2000B28F */  lw         $s2, 0x20($sp)
    /* CEC 801034EC 1C00B18F */  lw         $s1, 0x1C($sp)
    /* CF0 801034F0 1800B08F */  lw         $s0, 0x18($sp)
    /* CF4 801034F4 0800E003 */  jr         $ra
    /* CF8 801034F8 4000BD27 */   addiu     $sp, $sp, 0x40
endlabel _abilityMenu
