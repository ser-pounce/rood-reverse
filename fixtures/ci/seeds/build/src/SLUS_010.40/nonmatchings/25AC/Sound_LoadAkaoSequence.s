nonmatching Sound_LoadAkaoSequence, 0x36C

glabel Sound_LoadAkaoSequence
    /* 6584 80015D84 0380023C */  lui        $v0, %hi(g_pActiveMusicConfig)
    /* 6588 80015D88 2078428C */  lw         $v0, %lo(g_pActiveMusicConfig)($v0)
    /* 658C 80015D8C D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 6590 80015D90 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 6594 80015D94 21988000 */  addu       $s3, $a0, $zero
    /* 6598 80015D98 1000B0AF */  sw         $s0, 0x10($sp)
    /* 659C 80015D9C 2C00BFAF */  sw         $ra, 0x2C($sp)
    /* 65A0 80015DA0 2800B6AF */  sw         $s6, 0x28($sp)
    /* 65A4 80015DA4 2400B5AF */  sw         $s5, 0x24($sp)
    /* 65A8 80015DA8 2000B4AF */  sw         $s4, 0x20($sp)
    /* 65AC 80015DAC 1800B2AF */  sw         $s2, 0x18($sp)
    /* 65B0 80015DB0 1400B1AF */  sw         $s1, 0x14($sp)
    /* 65B4 80015DB4 380053AC */  sw         $s3, 0x38($v0)
    /* 65B8 80015DB8 0380023C */  lui        $v0, %hi(g_pSavedMousicConfig)
    /* 65BC 80015DBC 2866438C */  lw         $v1, %lo(g_pSavedMousicConfig)($v0)
    /* 65C0 80015DC0 2000748E */  lw         $s4, 0x20($s3)
    /* 65C4 80015DC4 08006010 */  beqz       $v1, .L80015DE8
    /* 65C8 80015DC8 21806002 */   addu      $s0, $s3, $zero
    /* 65CC 80015DCC 0380023C */  lui        $v0, %hi(g_pSecondaryMusicChannels)
    /* 65D0 80015DD0 D465448C */  lw         $a0, %lo(g_pSecondaryMusicChannels)($v0)
    /* 65D4 80015DD4 0400658C */  lw         $a1, 0x4($v1)
    /* 65D8 80015DD8 4E57000C */  jal        func_80015D38
    /* 65DC 80015DDC 00000000 */   nop
    /* 65E0 80015DE0 7B570008 */  j          .L80015DEC
    /* 65E4 80015DE4 21884000 */   addu      $s1, $v0, $zero
  .L80015DE8:
    /* 65E8 80015DE8 21880000 */  addu       $s1, $zero, $zero
  .L80015DEC:
    /* 65EC 80015DEC FF00063C */  lui        $a2, (0xFFFFFF >> 16)
    /* 65F0 80015DF0 FFFFC634 */  ori        $a2, $a2, (0xFFFFFF & 0xFFFF)
    /* 65F4 80015DF4 0380023C */  lui        $v0, %hi(g_Sound_VoiceSchedulerState)
    /* 65F8 80015DF8 90784724 */  addiu      $a3, $v0, %lo(g_Sound_VoiceSchedulerState)
    /* 65FC 80015DFC 0480033C */  lui        $v1, %hi(D_80039B14)
    /* 6600 80015E00 27201100 */  nor        $a0, $zero, $s1
    /* 6604 80015E04 9078458C */  lw         $a1, %lo(g_Sound_VoiceSchedulerState)($v0)
    /* 6608 80015E08 149B628C */  lw         $v0, %lo(D_80039B14)($v1)
    /* 660C 80015E0C 0380033C */  lui        $v1, %hi(g_pActiveMusicConfig)
    /* 6610 80015E10 27104500 */  nor        $v0, $v0, $a1
    /* 6614 80015E14 24104600 */  and        $v0, $v0, $a2
    /* 6618 80015E18 24208200 */  and        $a0, $a0, $v0
    /* 661C 80015E1C 0480053C */  lui        $a1, %hi(D_80039B64)
    /* 6620 80015E20 0C00E28C */  lw         $v0, 0xC($a3)
    /* 6624 80015E24 2078668C */  lw         $a2, %lo(g_pActiveMusicConfig)($v1)
    /* 6628 80015E28 649BA38C */  lw         $v1, %lo(D_80039B64)($a1)
    /* 662C 80015E2C 25104400 */  or         $v0, $v0, $a0
    /* 6630 80015E30 01006330 */  andi       $v1, $v1, 0x1
    /* 6634 80015E34 0C00E2AC */  sw         $v0, 0xC($a3)
    /* 6638 80015E38 06006010 */  beqz       $v1, .L80015E54
    /* 663C 80015E3C 1800C0AC */   sw        $zero, 0x18($a2)
    /* 6640 80015E40 1C00C28C */  lw         $v0, 0x1C($a2)
    /* 6644 80015E44 0400C0AC */  sw         $zero, 0x4($a2)
    /* 6648 80015E48 25105400 */  or         $v0, $v0, $s4
    /* 664C 80015E4C 99570008 */  j          .L80015E64
    /* 6650 80015E50 1C00C2AC */   sw        $v0, 0x1C($a2)
  .L80015E54:
    /* 6654 80015E54 0400C28C */  lw         $v0, 0x4($a2)
    /* 6658 80015E58 1C00C0AC */  sw         $zero, 0x1C($a2)
    /* 665C 80015E5C 25105400 */  or         $v0, $v0, $s4
    /* 6660 80015E60 0400C2AC */  sw         $v0, 0x4($a2)
  .L80015E64:
    /* 6664 80015E64 0380023C */  lui        $v0, %hi(g_pActiveMusicConfig)
    /* 6668 80015E68 2078438C */  lw         $v1, %lo(g_pActiveMusicConfig)($v0)
    /* 666C 80015E6C 2400028E */  lw         $v0, 0x24($s0)
    /* 6670 80015E70 00000000 */  nop
    /* 6674 80015E74 080062AC */  sw         $v0, 0x8($v1)
    /* 6678 80015E78 2800028E */  lw         $v0, 0x28($s0)
    /* 667C 80015E7C 0000648C */  lw         $a0, 0x0($v1)
    /* 6680 80015E80 0C0062AC */  sw         $v0, 0xC($v1)
    /* 6684 80015E84 9EFF0224 */  addiu      $v0, $zero, -0x62
    /* 6688 80015E88 24288200 */  and        $a1, $a0, $v0
    /* 668C 80015E8C 0380023C */  lui        $v0, %hi(D_80036774)
    /* 6690 80015E90 000065AC */  sw         $a1, 0x0($v1)
    /* 6694 80015E94 1400048E */  lw         $a0, 0x14($s0)
    /* 6698 80015E98 7467428C */  lw         $v0, %lo(D_80036774)($v0)
    /* 669C 80015E9C 00000000 */  nop
    /* 66A0 80015EA0 02008214 */  bne        $a0, $v0, .L80015EAC
    /* 66A4 80015EA4 2000A434 */   ori       $a0, $a1, 0x20
    /* 66A8 80015EA8 4000A434 */  ori        $a0, $a1, 0x40
  .L80015EAC:
    /* 66AC 80015EAC 000064AC */  sw         $a0, 0x0($v1)
    /* 66B0 80015EB0 3000028E */  lw         $v0, 0x30($s0)
    /* 66B4 80015EB4 00000000 */  nop
    /* 66B8 80015EB8 30004324 */  addiu      $v1, $v0, 0x30
    /* 66BC 80015EBC 21200302 */  addu       $a0, $s0, $v1
    /* 66C0 80015EC0 0380033C */  lui        $v1, %hi(g_pActiveMusicConfig)
    /* 66C4 80015EC4 2078658C */  lw         $a1, %lo(g_pActiveMusicConfig)($v1)
    /* 66C8 80015EC8 02004010 */  beqz       $v0, .L80015ED4
    /* 66CC 80015ECC 21300000 */   addu      $a2, $zero, $zero
    /* 66D0 80015ED0 21308000 */  addu       $a2, $a0, $zero
  .L80015ED4:
    /* 66D4 80015ED4 3C00A6AC */  sw         $a2, 0x3C($a1)
    /* 66D8 80015ED8 3400038E */  lw         $v1, 0x34($s0)
    /* 66DC 80015EDC 21300000 */  addu       $a2, $zero, $zero
    /* 66E0 80015EE0 34006224 */  addiu      $v0, $v1, 0x34
    /* 66E4 80015EE4 02006010 */  beqz       $v1, .L80015EF0
    /* 66E8 80015EE8 21200202 */   addu      $a0, $s0, $v0
    /* 66EC 80015EEC 21308000 */  addu       $a2, $a0, $zero
  .L80015EF0:
    /* 66F0 80015EF0 01001124 */  addiu      $s1, $zero, 0x1
    /* 66F4 80015EF4 21A80000 */  addu       $s5, $zero, $zero
    /* 66F8 80015EF8 0380023C */  lui        $v0, %hi(g_ActiveMusicChannels)
    /* 66FC 80015EFC 90365224 */  addiu      $s2, $v0, %lo(g_ActiveMusicChannels)
    /* 6700 80015F00 40007326 */  addiu      $s3, $s3, 0x40
    /* 6704 80015F04 0380023C */  lui        $v0, %hi(g_Sound_ProgramCounter)
    /* 6708 80015F08 4000A6AC */  sw         $a2, 0x40($a1)
    /* 670C 80015F0C 4800A0AC */  sw         $zero, 0x48($a1)
    /* 6710 80015F10 3800038E */  lw         $v1, 0x38($s0)
    /* 6714 80015F14 38F65624 */  addiu      $s6, $v0, %lo(g_Sound_ProgramCounter)
    /* 6718 80015F18 2C00A3AC */  sw         $v1, 0x2C($a1)
    /* 671C 80015F1C 3C00028E */  lw         $v0, 0x3C($s0)
    /* 6720 80015F20 F4005026 */  addiu      $s0, $s2, 0xF4
    /* 6724 80015F24 3000A2AC */  sw         $v0, 0x30($a1)
  .L80015F28:
    /* 6728 80015F28 24109102 */  and        $v0, $s4, $s1
    /* 672C 80015F2C 36004010 */  beqz       $v0, .L80016008
    /* 6730 80015F30 21204002 */   addu      $a0, $s2, $zero
    /* 6734 80015F34 00006296 */  lhu        $v0, 0x0($s3)
    /* 6738 80015F38 21280000 */  addu       $a1, $zero, $zero
    /* 673C 80015F3C 21106202 */  addu       $v0, $s3, $v0
    /* 6740 80015F40 000042AE */  sw         $v0, 0x0($s2)
    /* 6744 80015F44 04000224 */  addiu      $v0, $zero, 0x4
    /* 6748 80015F48 72FF02A6 */  sh         $v0, -0x8E($s0)
    /* 674C 80015F4C 02000224 */  addiu      $v0, $zero, 0x2
    /* 6750 80015F50 74FF02A6 */  sh         $v0, -0x8C($s0)
    /* 6754 80015F54 007F0224 */  addiu      $v0, $zero, 0x7F00
    /* 6758 80015F58 8EFF02A6 */  sh         $v0, -0x72($s0)
    /* 675C 80015F5C FF3F023C */  lui        $v0, (0x3FFF0000 >> 16)
    /* 6760 80015F60 54FF02AE */  sw         $v0, -0xAC($s0)
    /* 6764 80015F64 00400224 */  addiu      $v0, $zero, 0x4000
    /* 6768 80015F68 E8FF02A6 */  sh         $v0, -0x18($s0)
    /* 676C 80015F6C 0380023C */  lui        $v0, %hi(g_pActiveMusicConfig)
    /* 6770 80015F70 2078438C */  lw         $v1, %lo(g_pActiveMusicConfig)($v0)
    /* 6774 80015F74 00800234 */  ori        $v0, $zero, 0x8000
    /* 6778 80015F78 F0FF00A6 */  sh         $zero, -0x10($s0)
    /* 677C 80015F7C EEFF00A6 */  sh         $zero, -0x12($s0)
    /* 6780 80015F80 A6FF00A6 */  sh         $zero, -0x5A($s0)
    /* 6784 80015F84 3CFF00AE */  sw         $zero, -0xC4($s0)
    /* 6788 80015F88 F4FF00A6 */  sh         $zero, -0xC($s0)
    /* 678C 80015F8C 9EFF00A6 */  sh         $zero, -0x62($s0)
    /* 6790 80015F90 E2FF00A6 */  sh         $zero, -0x1E($s0)
    /* 6794 80015F94 E0FF00A6 */  sh         $zero, -0x20($s0)
    /* 6798 80015F98 9AFF02A6 */  sh         $v0, -0x66($s0)
    /* 679C 80015F9C 9CFF00A6 */  sh         $zero, -0x64($s0)
    /* 67A0 80015FA0 A6FF00A6 */  sh         $zero, -0x5A($s0)
    /* 67A4 80015FA4 98FF00A6 */  sh         $zero, -0x68($s0)
    /* 67A8 80015FA8 94FF00A6 */  sh         $zero, -0x6C($s0)
    /* 67AC 80015FAC 60FF00AE */  sw         $zero, -0xA0($s0)
    /* 67B0 80015FB0 DEFF00A6 */  sh         $zero, -0x22($s0)
    /* 67B4 80015FB4 96FF00A6 */  sh         $zero, -0x6A($s0)
    /* 67B8 80015FB8 A8FF00A6 */  sh         $zero, -0x58($s0)
    /* 67BC 80015FBC FCFF00A6 */  sh         $zero, -0x4($s0)
    /* 67C0 80015FC0 DCFF00A6 */  sh         $zero, -0x24($s0)
    /* 67C4 80015FC4 0C00628C */  lw         $v0, 0xC($v1)
    /* 67C8 80015FC8 02007326 */  addiu      $s3, $s3, 0x2
    /* 67CC 80015FCC D2FF00A6 */  sh         $zero, -0x2E($s0)
    /* 67D0 80015FD0 C6FF00A6 */  sh         $zero, -0x3A($s0)
    /* 67D4 80015FD4 B6FF00A6 */  sh         $zero, -0x4A($s0)
    /* 67D8 80015FD8 D4FF00A6 */  sh         $zero, -0x2C($s0)
    /* 67DC 80015FDC 24105100 */  and        $v0, $v0, $s1
    /* 67E0 80015FE0 0100422C */  sltiu      $v0, $v0, 0x1
    /* 67E4 80015FE4 80110200 */  sll        $v0, $v0, 6
    /* 67E8 80015FE8 40FF02AE */  sw         $v0, -0xC0($s0)
    /* 67EC 80015FEC C8FF00A6 */  sh         $zero, -0x38($s0)
    /* 67F0 80015FF0 B8FF00A6 */  sh         $zero, -0x48($s0)
    /* 67F4 80015FF4 DAFF00A6 */  sh         $zero, -0x26($s0)
    /* 67F8 80015FF8 256C000C */  jal        func_8001B094
    /* 67FC 80015FFC D8FF00A6 */   sh        $zero, -0x28($s0)
    /* 6800 80016000 0F580008 */  j          .L8001603C
    /* 6804 80016004 18000224 */   addiu     $v0, $zero, 0x18
  .L80016008:
    /* 6808 80016008 03000224 */  addiu      $v0, $zero, 0x3
    /* 680C 8001600C 72FF02A6 */  sh         $v0, -0x8E($s0)
    /* 6810 80016010 01000224 */  addiu      $v0, $zero, 0x1
    /* 6814 80016014 74FF02A6 */  sh         $v0, -0x8C($s0)
    /* 6818 80016018 000056AE */  sw         $s6, 0x0($s2)
    /* 681C 8001601C 0400028E */  lw         $v0, 0x4($s0)
    /* 6820 80016020 14000396 */  lhu        $v1, 0x14($s0)
    /* 6824 80016024 00444234 */  ori        $v0, $v0, 0x4400
    /* 6828 80016028 E0FF6330 */  andi       $v1, $v1, 0xFFE0
    /* 682C 8001602C 05006334 */  ori        $v1, $v1, 0x5
    /* 6830 80016030 040002AE */  sw         $v0, 0x4($s0)
    /* 6834 80016034 140003A6 */  sh         $v1, 0x14($s0)
    /* 6838 80016038 18000224 */  addiu      $v0, $zero, 0x18
  .L8001603C:
    /* 683C 8001603C 000002AE */  sw         $v0, 0x0($s0)
    /* 6840 80016040 27101100 */  nor        $v0, $zero, $s1
    /* 6844 80016044 24A08202 */  and        $s4, $s4, $v0
    /* 6848 80016048 10011026 */  addiu      $s0, $s0, 0x110
    /* 684C 8001604C 10015226 */  addiu      $s2, $s2, 0x110
    /* 6850 80016050 0100B526 */  addiu      $s5, $s5, 0x1
    /* 6854 80016054 2000A22E */  sltiu      $v0, $s5, 0x20
    /* 6858 80016058 B3FF4014 */  bnez       $v0, .L80015F28
    /* 685C 8001605C 40881100 */   sll       $s1, $s1, 1
    /* 6860 80016060 0380023C */  lui        $v0, %hi(g_pActiveMusicConfig)
    /* 6864 80016064 2078428C */  lw         $v0, %lo(g_pActiveMusicConfig)($v0)
    /* 6868 80016068 FFFF033C */  lui        $v1, (0xFFFF0000 >> 16)
    /* 686C 8001606C 200043AC */  sw         $v1, 0x20($v0)
    /* 6870 80016070 01000324 */  addiu      $v1, $zero, 0x1
    /* 6874 80016074 280043AC */  sw         $v1, 0x28($v0)
    /* 6878 80016078 0480033C */  lui        $v1, %hi(g_Sound_GlobalFlags)
    /* 687C 8001607C F89A6324 */  addiu      $v1, $v1, %lo(g_Sound_GlobalFlags)
    /* 6880 80016080 6C0040A4 */  sh         $zero, 0x6C($v0)
    /* 6884 80016084 580040AC */  sw         $zero, 0x58($v0)
    /* 6888 80016088 6A0040A4 */  sh         $zero, 0x6A($v0)
    /* 688C 8001608C 5C0040AC */  sw         $zero, 0x5C($v0)
    /* 6890 80016090 7A0040A4 */  sh         $zero, 0x7A($v0)
    /* 6894 80016094 780040A4 */  sh         $zero, 0x78($v0)
    /* 6898 80016098 760040A4 */  sh         $zero, 0x76($v0)
    /* 689C 8001609C 7C0040A4 */  sh         $zero, 0x7C($v0)
    /* 68A0 800160A0 4C0040AC */  sw         $zero, 0x4C($v0)
    /* 68A4 800160A4 500040AC */  sw         $zero, 0x50($v0)
    /* 68A8 800160A8 540040AC */  sw         $zero, 0x54($v0)
    /* 68AC 800160AC 700040A4 */  sh         $zero, 0x70($v0)
    /* 68B0 800160B0 140040AC */  sw         $zero, 0x14($v0)
    /* 68B4 800160B4 100040AC */  sw         $zero, 0x10($v0)
    /* 68B8 800160B8 0800628C */  lw         $v0, 0x8($v1)
    /* 68BC 800160BC 00000000 */  nop
    /* 68C0 800160C0 00014234 */  ori        $v0, $v0, 0x100
    /* 68C4 800160C4 080062AC */  sw         $v0, 0x8($v1)
    /* 68C8 800160C8 2C00BF8F */  lw         $ra, 0x2C($sp)
    /* 68CC 800160CC 2800B68F */  lw         $s6, 0x28($sp)
    /* 68D0 800160D0 2400B58F */  lw         $s5, 0x24($sp)
    /* 68D4 800160D4 2000B48F */  lw         $s4, 0x20($sp)
    /* 68D8 800160D8 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 68DC 800160DC 1800B28F */  lw         $s2, 0x18($sp)
    /* 68E0 800160E0 1400B18F */  lw         $s1, 0x14($sp)
    /* 68E4 800160E4 1000B08F */  lw         $s0, 0x10($sp)
    /* 68E8 800160E8 0800E003 */  jr         $ra
    /* 68EC 800160EC 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel Sound_LoadAkaoSequence
