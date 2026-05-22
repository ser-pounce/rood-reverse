nonmatching _initCongratulationsScreen, 0x3FC

glabel _initCongratulationsScreen
    /* 510 80102D10 C0FFBD27 */  addiu      $sp, $sp, -0x40
    /* 514 80102D14 2C00B1AF */  sw         $s1, 0x2C($sp)
    /* 518 80102D18 0F80113C */  lui        $s1, %hi(_submenuState)
    /* 51C 80102D1C D81C238E */  lw         $v1, %lo(_submenuState)($s1)
    /* 520 80102D20 3800BFAF */  sw         $ra, 0x38($sp)
    /* 524 80102D24 3400B3AF */  sw         $s3, 0x34($sp)
    /* 528 80102D28 3000B2AF */  sw         $s2, 0x30($sp)
    /* 52C 80102D2C 18006014 */  bnez       $v1, .L80102D90
    /* 530 80102D30 2800B0AF */   sw        $s0, 0x28($sp)
    /* 534 80102D34 1D000424 */  addiu      $a0, $zero, 0x1D
    /* 538 80102D38 03000524 */  addiu      $a1, $zero, 0x3
    /* 53C 80102D3C FCF7010C */  jal        func_8007DFF0
    /* 540 80102D40 05000624 */   addiu     $a2, $zero, 0x5
    /* 544 80102D44 1080103C */  lui        $s0, %hi(_disFiles)
    /* 548 80102D48 E02A1026 */  addiu      $s0, $s0, %lo(_disFiles)
    /* 54C 80102D4C 0400048E */  lw         $a0, 0x4($s0)
    /* 550 80102D50 8F0F010C */  jal        vs_main_allocHeapR
    /* 554 80102D54 00000000 */   nop
    /* 558 80102D58 21200002 */  addu       $a0, $s0, $zero
    /* 55C 80102D5C 1180103C */  lui        $s0, %hi(timData)
    /* 560 80102D60 C412010C */  jal        vs_main_allocateCdQueueSlot
    /* 564 80102D64 509802AE */   sw        $v0, %lo(timData)($s0)
    /* 568 80102D68 21204000 */  addu       $a0, $v0, $zero
    /* 56C 80102D6C 5098058E */  lw         $a1, %lo(timData)($s0)
    /* 570 80102D70 1180023C */  lui        $v0, %hi(cdSlot)
    /* 574 80102D74 F112010C */  jal        vs_main_cdEnqueue
    /* 578 80102D78 4C9844AC */   sw        $a0, %lo(cdSlot)($v0)
    /* 57C 80102D7C D81C228E */  lw         $v0, %lo(_submenuState)($s1)
    /* 580 80102D80 00000000 */  nop
    /* 584 80102D84 01004224 */  addiu      $v0, $v0, 0x1
    /* 588 80102D88 3B0C0408 */  j          .L801030EC
    /* 58C 80102D8C D81C22AE */   sw        $v0, %lo(_submenuState)($s1)
  .L80102D90:
    /* 590 80102D90 01000224 */  addiu      $v0, $zero, 0x1
    /* 594 80102D94 4B006214 */  bne        $v1, $v0, .L80102EC4
    /* 598 80102D98 1180023C */   lui       $v0, %hi(cdSlot)
    /* 59C 80102D9C 4C98428C */  lw         $v0, %lo(cdSlot)($v0)
    /* 5A0 80102DA0 00000000 */  nop
    /* 5A4 80102DA4 00004384 */  lh         $v1, 0x0($v0)
    /* 5A8 80102DA8 04000224 */  addiu      $v0, $zero, 0x4
    /* 5AC 80102DAC D0006214 */  bne        $v1, $v0, .L801030F0
    /* 5B0 80102DB0 21100000 */   addu      $v0, $zero, $zero
    /* 5B4 80102DB4 21800000 */  addu       $s0, $zero, $zero
    /* 5B8 80102DB8 1180133C */  lui        $s3, %hi(timData)
    /* 5BC 80102DBC 40031224 */  addiu      $s2, $zero, 0x340
    /* 5C0 80102DC0 21880002 */  addu       $s1, $s0, $zero
  .L80102DC4:
    /* 5C4 80102DC4 5098648E */  lw         $a0, %lo(timData)($s3)
    /* 5C8 80102DC8 1000A527 */  addiu      $a1, $sp, 0x10
    /* 5CC 80102DCC 0836020C */  jal        vs_battle_setTimImage
    /* 5D0 80102DD0 21209100 */   addu      $a0, $a0, $s1
    /* 5D4 80102DD4 2000A28F */  lw         $v0, 0x20($sp)
    /* 5D8 80102DD8 00000000 */  nop
    /* 5DC 80102DDC 0E004010 */  beqz       $v0, .L80102E18
    /* 5E0 80102DE0 00000000 */   nop
    /* 5E4 80102DE4 1C00A28F */  lw         $v0, 0x1C($sp)
    /* 5E8 80102DE8 00000000 */  nop
    /* 5EC 80102DEC 000052A4 */  sh         $s2, 0x0($v0)
    /* 5F0 80102DF0 1C00A38F */  lw         $v1, 0x1C($sp)
    /* 5F4 80102DF4 00010224 */  addiu      $v0, $zero, 0x100
    /* 5F8 80102DF8 020062A4 */  sh         $v0, 0x2($v1)
    /* 5FC 80102DFC 1C00A38F */  lw         $v1, 0x1C($sp)
    /* 600 80102E00 FF000224 */  addiu      $v0, $zero, 0xFF
    /* 604 80102E04 060062A4 */  sh         $v0, 0x6($v1)
    /* 608 80102E08 1C00A48F */  lw         $a0, 0x1C($sp)
    /* 60C 80102E0C 2000A58F */  lw         $a1, 0x20($sp)
    /* 610 80102E10 3FA2000C */  jal        LoadImage
    /* 614 80102E14 00000000 */   nop
  .L80102E18:
    /* 618 80102E18 19000016 */  bnez       $s0, .L80102E80
    /* 61C 80102E1C 20820234 */   ori       $v0, $zero, 0x8220
    /* 620 80102E20 1800A28F */  lw         $v0, 0x18($sp)
    /* 624 80102E24 00000000 */  nop
    /* 628 80102E28 14004010 */  beqz       $v0, .L80102E7C
    /* 62C 80102E2C 00030224 */   addiu     $v0, $zero, 0x300
    /* 630 80102E30 1400A38F */  lw         $v1, 0x14($sp)
    /* 634 80102E34 00000000 */  nop
    /* 638 80102E38 000062A4 */  sh         $v0, 0x0($v1)
    /* 63C 80102E3C 1400A38F */  lw         $v1, 0x14($sp)
    /* 640 80102E40 FF010224 */  addiu      $v0, $zero, 0x1FF
    /* 644 80102E44 020062A4 */  sh         $v0, 0x2($v1)
    /* 648 80102E48 1400A38F */  lw         $v1, 0x14($sp)
    /* 64C 80102E4C 80000224 */  addiu      $v0, $zero, 0x80
    /* 650 80102E50 040062A4 */  sh         $v0, 0x4($v1)
    /* 654 80102E54 1400A38F */  lw         $v1, 0x14($sp)
    /* 658 80102E58 01000224 */  addiu      $v0, $zero, 0x1
    /* 65C 80102E5C 060062A4 */  sh         $v0, 0x6($v1)
    /* 660 80102E60 1800A28F */  lw         $v0, 0x18($sp)
    /* 664 80102E64 00000000 */  nop
    /* 668 80102E68 000040AC */  sw         $zero, 0x0($v0)
    /* 66C 80102E6C 1400A48F */  lw         $a0, 0x14($sp)
    /* 670 80102E70 1800A58F */  lw         $a1, 0x18($sp)
    /* 674 80102E74 3FA2000C */  jal        LoadImage
    /* 678 80102E78 00000000 */   nop
  .L80102E7C:
    /* 67C 80102E7C 20820234 */  ori        $v0, $zero, 0x8220
  .L80102E80:
    /* 680 80102E80 21882202 */  addu       $s1, $s1, $v0
    /* 684 80102E84 01001026 */  addiu      $s0, $s0, 0x1
    /* 688 80102E88 0300022A */  slti       $v0, $s0, 0x3
    /* 68C 80102E8C CDFF4014 */  bnez       $v0, .L80102DC4
    /* 690 80102E90 40005226 */   addiu     $s2, $s2, 0x40
    /* 694 80102E94 1180023C */  lui        $v0, %hi(cdSlot)
    /* 698 80102E98 4C98448C */  lw         $a0, %lo(cdSlot)($v0)
    /* 69C 80102E9C E012010C */  jal        vs_main_freeCdQueueSlot
    /* 6A0 80102EA0 00000000 */   nop
    /* 6A4 80102EA4 D20D040C */  jal        func_80103748
    /* 6A8 80102EA8 00000000 */   nop
    /* 6AC 80102EAC 0F80033C */  lui        $v1, %hi(_submenuState)
    /* 6B0 80102EB0 D81C628C */  lw         $v0, %lo(_submenuState)($v1)
    /* 6B4 80102EB4 00000000 */  nop
    /* 6B8 80102EB8 01004224 */  addiu      $v0, $v0, 0x1
    /* 6BC 80102EBC 3B0C0408 */  j          .L801030EC
    /* 6C0 80102EC0 D81C62AC */   sw        $v0, %lo(_submenuState)($v1)
  .L80102EC4:
    /* 6C4 80102EC4 D414010C */  jal        vs_main_clearMusicLoadQueue
    /* 6C8 80102EC8 00000000 */   nop
    /* 6CC 80102ECC 88004014 */  bnez       $v0, .L801030F0
    /* 6D0 80102ED0 21100000 */   addu      $v0, $zero, $zero
    /* 6D4 80102ED4 02000424 */  addiu      $a0, $zero, 0x2
    /* 6D8 80102ED8 7F000524 */  addiu      $a1, $zero, 0x7F
    /* 6DC 80102EDC 0014010C */  jal        func_80045000
    /* 6E0 80102EE0 21300000 */   addu      $a2, $zero, $zero
    /* 6E4 80102EE4 1180023C */  lui        $v0, %hi(timData)
    /* 6E8 80102EE8 5098448C */  lw         $a0, %lo(timData)($v0)
    /* 6EC 80102EEC 180F010C */  jal        vs_main_freeHeapR
    /* 6F0 80102EF0 00000000 */   nop
    /* 6F4 80102EF4 1180023C */  lui        $v0, %hi(D_80109894)
    /* 6F8 80102EF8 949840AC */  sw         $zero, %lo(D_80109894)($v0)
    /* 6FC 80102EFC 1180023C */  lui        $v0, %hi(D_80109898)
    /* 700 80102F00 989840AC */  sw         $zero, %lo(D_80109898)($v0)
    /* 704 80102F04 1180023C */  lui        $v0, %hi(D_8010989C)
    /* 708 80102F08 9C9840AC */  sw         $zero, %lo(D_8010989C)($v0)
    /* 70C 80102F0C 1180023C */  lui        $v0, %hi(D_801098A0)
    /* 710 80102F10 A09840AC */  sw         $zero, %lo(D_801098A0)($v0)
    /* 714 80102F14 1180023C */  lui        $v0, %hi(D_8010988C)
    /* 718 80102F18 B19B000C */  jal        rand
    /* 71C 80102F1C 8C9840AC */   sw        $zero, %lo(D_8010988C)($v0)
    /* 720 80102F20 1180033C */  lui        $v1, %hi(_buffReelSelection)
    /* 724 80102F24 F0004230 */  andi       $v0, $v0, 0xF0
    /* 728 80102F28 08004234 */  ori        $v0, $v0, 0x8
    /* 72C 80102F2C AA23040C */  jal        _getTotalStrength
    /* 730 80102F30 789862AC */   sw        $v0, %lo(_buffReelSelection)($v1)
    /* 734 80102F34 B223040C */  jal        _getTotalIntelligence
    /* 738 80102F38 21804000 */   addu      $s0, $v0, $zero
    /* 73C 80102F3C BA23040C */  jal        _getTotalAgility
    /* 740 80102F40 21884000 */   addu      $s1, $v0, $zero
    /* 744 80102F44 21184000 */  addu       $v1, $v0, $zero
    /* 748 80102F48 2A103002 */  slt        $v0, $s1, $s0
    /* 74C 80102F4C 07004014 */  bnez       $v0, .L80102F6C
    /* 750 80102F50 2A101102 */   slt       $v0, $s0, $s1
    /* 754 80102F54 2A107000 */  slt        $v0, $v1, $s0
    /* 758 80102F58 04004014 */  bnez       $v0, .L80102F6C
    /* 75C 80102F5C 2A101102 */   slt       $v0, $s0, $s1
    /* 760 80102F60 1180023C */  lui        $v0, %hi(_buffReelIndex)
    /* 764 80102F64 E40B0408 */  j          .L80102F90
    /* 768 80102F68 909840AC */   sw        $zero, %lo(_buffReelIndex)($v0)
  .L80102F6C:
    /* 76C 80102F6C 05004014 */  bnez       $v0, .L80102F84
    /* 770 80102F70 2A107100 */   slt       $v0, $v1, $s1
    /* 774 80102F74 04004014 */  bnez       $v0, .L80102F88
    /* 778 80102F78 1180033C */   lui       $v1, %hi(_buffReelIndex)
    /* 77C 80102F7C E30B0408 */  j          .L80102F8C
    /* 780 80102F80 01000224 */   addiu     $v0, $zero, 0x1
  .L80102F84:
    /* 784 80102F84 1180033C */  lui        $v1, %hi(_buffReelIndex)
  .L80102F88:
    /* 788 80102F88 02000224 */  addiu      $v0, $zero, 0x2
  .L80102F8C:
    /* 78C 80102F8C 909862AC */  sw         $v0, %lo(_buffReelIndex)($v1)
  .L80102F90:
    /* 790 80102F90 0F80023C */  lui        $v0, %hi(_submenuState)
    /* 794 80102F94 9223040C */  jal        func_80108E48
    /* 798 80102F98 D81C40AC */   sw        $zero, %lo(_submenuState)($v0)
    /* 79C 80102F9C 0680023C */  lui        $v0, %hi(vs_main_stateFlags)
    /* 7A0 80102FA0 98154390 */  lbu        $v1, %lo(vs_main_stateFlags)($v0)
    /* 7A4 80102FA4 1180023C */  lui        $v0, %hi(_clearCount)
    /* 7A8 80102FA8 809843AC */  sw         $v1, %lo(_clearCount)($v0)
    /* 7AC 80102FAC 0680023C */  lui        $v0, %hi(vs_main_mapStatus)
    /* 7B0 80102FB0 D8FF4324 */  addiu      $v1, $v0, %lo(vs_main_mapStatus)
    /* 7B4 80102FB4 0400648C */  lw         $a0, 0x4($v1)
    /* 7B8 80102FB8 8000023C */  lui        $v0, (0x800000 >> 16)
    /* 7BC 80102FBC 24108200 */  and        $v0, $a0, $v0
    /* 7C0 80102FC0 03004010 */  beqz       $v0, .L80102FD0
    /* 7C4 80102FC4 4000023C */   lui       $v0, (0x400000 >> 16)
    /* 7C8 80102FC8 25108200 */  or         $v0, $a0, $v0
    /* 7CC 80102FCC 040062AC */  sw         $v0, 0x4($v1)
  .L80102FD0:
    /* 7D0 80102FD0 21380000 */  addu       $a3, $zero, $zero
    /* 7D4 80102FD4 2180E000 */  addu       $s0, $a3, $zero
    /* 7D8 80102FD8 01000824 */  addiu      $t0, $zero, 0x1
    /* 7DC 80102FDC 0F80023C */  lui        $v0, %hi(vs_battle_mapCompletionFlags)
    /* 7E0 80102FE0 08854624 */  addiu      $a2, $v0, %lo(vs_battle_mapCompletionFlags)
    /* 7E4 80102FE4 21286000 */  addu       $a1, $v1, $zero
  .L80102FE8:
    /* 7E8 80102FE8 0000A38C */  lw         $v1, 0x0($a1)
    /* 7EC 80102FEC 0000C28C */  lw         $v0, 0x0($a2)
    /* 7F0 80102FF0 21200000 */  addu       $a0, $zero, $zero
    /* 7F4 80102FF4 24186200 */  and        $v1, $v1, $v0
    /* 7F8 80102FF8 04108800 */  sllv       $v0, $t0, $a0
  .L80102FFC:
    /* 7FC 80102FFC 24106200 */  and        $v0, $v1, $v0
    /* 800 80103000 02004010 */  beqz       $v0, .L8010300C
    /* 804 80103004 00000000 */   nop
    /* 808 80103008 0100E724 */  addiu      $a3, $a3, 0x1
  .L8010300C:
    /* 80C 8010300C 01008424 */  addiu      $a0, $a0, 0x1
    /* 810 80103010 20008228 */  slti       $v0, $a0, 0x20
    /* 814 80103014 F9FF4014 */  bnez       $v0, .L80102FFC
    /* 818 80103018 04108800 */   sllv      $v0, $t0, $a0
    /* 81C 8010301C 0400C624 */  addiu      $a2, $a2, 0x4
    /* 820 80103020 01001026 */  addiu      $s0, $s0, 0x1
    /* 824 80103024 1000022A */  slti       $v0, $s0, 0x10
    /* 828 80103028 EFFF4014 */  bnez       $v0, .L80102FE8
    /* 82C 8010302C 0400A524 */   addiu     $a1, $a1, 0x4
    /* 830 80103030 21180000 */  addu       $v1, $zero, $zero
    /* 834 80103034 21806000 */  addu       $s0, $v1, $zero
    /* 838 80103038 0680023C */  lui        $v0, %hi(vs_main_stateFlags)
    /* 83C 8010303C 98154424 */  addiu      $a0, $v0, %lo(vs_main_stateFlags)
    /* 840 80103040 21100402 */  addu       $v0, $s0, $a0
  .L80103044:
    /* 844 80103044 C0034290 */  lbu        $v0, 0x3C0($v0)
    /* 848 80103048 00000000 */  nop
    /* 84C 8010304C 02004010 */  beqz       $v0, .L80103058
    /* 850 80103050 00000000 */   nop
    /* 854 80103054 01006324 */  addiu      $v1, $v1, 0x1
  .L80103058:
    /* 858 80103058 01001026 */  addiu      $s0, $s0, 0x1
    /* 85C 8010305C 4000022A */  slti       $v0, $s0, 0x40
    /* 860 80103060 F8FF4014 */  bnez       $v0, .L80103044
    /* 864 80103064 21100402 */   addu      $v0, $s0, $a0
    /* 868 80103068 0680023C */  lui        $v0, %hi(vs_main_scoredata)
    /* 86C 8010306C A0FE4424 */  addiu      $a0, $v0, %lo(vs_main_scoredata)
    /* 870 80103070 9400828C */  lw         $v0, 0x94($a0)
    /* 874 80103074 00000000 */  nop
    /* 878 80103078 2B104700 */  sltu       $v0, $v0, $a3
    /* 87C 8010307C 02004010 */  beqz       $v0, .L80103088
    /* 880 80103080 00000000 */   nop
    /* 884 80103084 940087AC */  sw         $a3, 0x94($a0)
  .L80103088:
    /* 888 80103088 9800828C */  lw         $v0, 0x98($a0)
    /* 88C 8010308C 00000000 */  nop
    /* 890 80103090 2B104300 */  sltu       $v0, $v0, $v1
    /* 894 80103094 02004010 */  beqz       $v0, .L801030A0
    /* 898 80103098 00000000 */   nop
    /* 89C 8010309C 980083AC */  sw         $v1, 0x98($a0)
  .L801030A0:
    /* 8A0 801030A0 C55A033C */  lui        $v1, (0x5AC5242B >> 16)
    /* 8A4 801030A4 2B246334 */  ori        $v1, $v1, (0x5AC5242B & 0xFFFF)
    /* 8A8 801030A8 40100700 */  sll        $v0, $a3, 1
    /* 8AC 801030AC 21104700 */  addu       $v0, $v0, $a3
    /* 8B0 801030B0 C0100200 */  sll        $v0, $v0, 3
    /* 8B4 801030B4 21104700 */  addu       $v0, $v0, $a3
    /* 8B8 801030B8 80100200 */  sll        $v0, $v0, 2
    /* 8BC 801030BC 18004300 */  mult       $v0, $v1
    /* 8C0 801030C0 1180043C */  lui        $a0, %hi(_mapCompletion)
    /* 8C4 801030C4 C3170200 */  sra        $v0, $v0, 31
    /* 8C8 801030C8 10480000 */  mfhi       $t1
    /* 8CC 801030CC C3190900 */  sra        $v1, $t1, 7
    /* 8D0 801030D0 23186200 */  subu       $v1, $v1, $v0
    /* 8D4 801030D4 AC22040C */  jal        _calculateScore
    /* 8D8 801030D8 889883AC */   sw        $v1, %lo(_mapCompletion)($a0)
    /* 8DC 801030DC 8322040C */  jal        func_80108A0C
    /* 8E0 801030E0 00000000 */   nop
    /* 8E4 801030E4 3C0C0408 */  j          .L801030F0
    /* 8E8 801030E8 01000224 */   addiu     $v0, $zero, 0x1
  .L801030EC:
    /* 8EC 801030EC 21100000 */  addu       $v0, $zero, $zero
  .L801030F0:
    /* 8F0 801030F0 3800BF8F */  lw         $ra, 0x38($sp)
    /* 8F4 801030F4 3400B38F */  lw         $s3, 0x34($sp)
    /* 8F8 801030F8 3000B28F */  lw         $s2, 0x30($sp)
    /* 8FC 801030FC 2C00B18F */  lw         $s1, 0x2C($sp)
    /* 900 80103100 2800B08F */  lw         $s0, 0x28($sp)
    /* 904 80103104 0800E003 */  jr         $ra
    /* 908 80103108 4000BD27 */   addiu     $sp, $sp, 0x40
endlabel _initCongratulationsScreen
