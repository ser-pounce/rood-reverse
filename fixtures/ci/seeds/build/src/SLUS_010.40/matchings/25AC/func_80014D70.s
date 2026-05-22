nonmatching func_80014D70, 0x24C

glabel func_80014D70
    /* 5570 80014D70 C0FFBD27 */  addiu      $sp, $sp, -0x40
    /* 5574 80014D74 0380023C */  lui        $v0, %hi(g_pActiveMusicConfig)
    /* 5578 80014D78 3800BEAF */  sw         $fp, 0x38($sp)
    /* 557C 80014D7C 21F04000 */  addu       $fp, $v0, $zero
    /* 5580 80014D80 2078C28F */  lw         $v0, %lo(g_pActiveMusicConfig)($fp)
    /* 5584 80014D84 3000B6AF */  sw         $s6, 0x30($sp)
    /* 5588 80014D88 21B08000 */  addu       $s6, $a0, $zero
    /* 558C 80014D8C 2800B4AF */  sw         $s4, 0x28($sp)
    /* 5590 80014D90 21A0A000 */  addu       $s4, $a1, $zero
    /* 5594 80014D94 3400B7AF */  sw         $s7, 0x34($sp)
    /* 5598 80014D98 21B8E000 */  addu       $s7, $a3, $zero
    /* 559C 80014D9C 2000B2AF */  sw         $s2, 0x20($sp)
    /* 55A0 80014DA0 01001224 */  addiu      $s2, $zero, 0x1
    /* 55A4 80014DA4 2C00B5AF */  sw         $s5, 0x2C($sp)
    /* 55A8 80014DA8 21A80000 */  addu       $s5, $zero, $zero
    /* 55AC 80014DAC 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 55B0 80014DB0 3400D126 */  addiu      $s1, $s6, 0x34
    /* 55B4 80014DB4 3C00BFAF */  sw         $ra, 0x3C($sp)
    /* 55B8 80014DB8 2400B3AF */  sw         $s3, 0x24($sp)
    /* 55BC 80014DBC 1800B0AF */  sw         $s0, 0x18($sp)
    /* 55C0 80014DC0 4800A6AF */  sw         $a2, 0x48($sp)
    /* 55C4 80014DC4 1000428C */  lw         $v0, 0x10($v0)
    /* 55C8 80014DC8 F400D326 */  addiu      $s3, $s6, 0xF4
    /* 55CC 80014DCC 24108202 */  and        $v0, $s4, $v0
    /* 55D0 80014DD0 1000A2AF */  sw         $v0, 0x10($sp)
  .L80014DD4:
    /* 55D4 80014DD4 24109202 */  and        $v0, $s4, $s2
    /* 55D8 80014DD8 66004010 */  beqz       $v0, .L80014F74
    /* 55DC 80014DDC 2120C002 */   addu      $a0, $s6, $zero
    /* 55E0 80014DE0 DB50000C */  jal        func_8001436C
    /* 55E4 80014DE4 21284002 */   addu      $a1, $s2, $zero
    /* 55E8 80014DE8 C400228E */  lw         $v0, 0xC4($s1)
    /* 55EC 80014DEC 00000000 */  nop
    /* 55F0 80014DF0 5E004010 */  beqz       $v0, .L80014F6C
    /* 55F4 80014DF4 0380023C */   lui       $v0, %hi(D_800378E4)
    /* 55F8 80014DF8 E478428C */  lw         $v0, %lo(D_800378E4)($v0)
    /* 55FC 80014DFC 00000000 */  nop
    /* 5600 80014E00 24105200 */  and        $v0, $v0, $s2
    /* 5604 80014E04 03004010 */  beqz       $v0, .L80014E14
    /* 5608 80014E08 00000000 */   nop
    /* 560C 80014E0C DA0020A6 */  sh         $zero, 0xDA($s1)
    /* 5610 80014E10 D80020A6 */  sh         $zero, 0xD8($s1)
  .L80014E14:
    /* 5614 80014E14 1000A88F */  lw         $t0, 0x10($sp)
    /* 5618 80014E18 00000000 */  nop
    /* 561C 80014E1C 24101201 */  and        $v0, $t0, $s2
    /* 5620 80014E20 4A004010 */  beqz       $v0, .L80014F4C
    /* 5624 80014E24 00000000 */   nop
    /* 5628 80014E28 4800A88F */  lw         $t0, 0x48($sp)
    /* 562C 80014E2C 00000000 */  nop
    /* 5630 80014E30 24101201 */  and        $v0, $t0, $s2
    /* 5634 80014E34 07004010 */  beqz       $v0, .L80014E54
    /* 5638 80014E38 01000824 */   addiu     $t0, $zero, 0x1
    /* 563C 80014E3C 0000E28E */  lw         $v0, 0x0($s7)
    /* 5640 80014E40 0418A802 */  sllv       $v1, $t0, $s5
    /* 5644 80014E44 25104300 */  or         $v0, $v0, $v1
    /* 5648 80014E48 0000E2AE */  sw         $v0, 0x0($s7)
    /* 564C 80014E4C BD530008 */  j          .L80014EF4
    /* 5650 80014E50 C00035AE */   sw        $s5, 0xC0($s1)
  .L80014E54:
    /* 5654 80014E54 2078C28F */  lw         $v0, %lo(g_pActiveMusicConfig)($fp)
    /* 5658 80014E58 00000000 */  nop
    /* 565C 80014E5C 0800428C */  lw         $v0, 0x8($v0)
    /* 5660 80014E60 00000000 */  nop
    /* 5664 80014E64 24805200 */  and        $s0, $v0, $s2
    /* 5668 80014E68 4253000C */  jal        Sound_FindFreeVoice
    /* 566C 80014E6C 21200002 */   addu      $a0, $s0, $zero
    /* 5670 80014E70 21204000 */  addu       $a0, $v0, $zero
    /* 5674 80014E74 18000824 */  addiu      $t0, $zero, 0x18
    /* 5678 80014E78 13008814 */  bne        $a0, $t0, .L80014EC8
    /* 567C 80014E7C 01000824 */   addiu     $t0, $zero, 0x1
    /* 5680 80014E80 2078C38F */  lw         $v1, %lo(g_pActiveMusicConfig)($fp)
    /* 5684 80014E84 00000000 */  nop
    /* 5688 80014E88 0000628C */  lw         $v0, 0x0($v1)
    /* 568C 80014E8C 21200002 */  addu       $a0, $s0, $zero
    /* 5690 80014E90 02004234 */  ori        $v0, $v0, 0x2
    /* 5694 80014E94 1653000C */  jal        Sound_StealQuietestVoice
    /* 5698 80014E98 000062AC */   sw        $v0, 0x0($v1)
    /* 569C 80014E9C 21204000 */  addu       $a0, $v0, $zero
    /* 56A0 80014EA0 18000824 */  addiu      $t0, $zero, 0x18
    /* 56A4 80014EA4 08008814 */  bne        $a0, $t0, .L80014EC8
    /* 56A8 80014EA8 01000824 */   addiu     $t0, $zero, 0x1
    /* 56AC 80014EAC 2078C38F */  lw         $v1, %lo(g_pActiveMusicConfig)($fp)
    /* 56B0 80014EB0 C00024AE */  sw         $a0, 0xC0($s1)
    /* 56B4 80014EB4 0000628C */  lw         $v0, 0x0($v1)
    /* 56B8 80014EB8 00000000 */  nop
    /* 56BC 80014EBC 01004234 */  ori        $v0, $v0, 0x1
    /* 56C0 80014EC0 BD530008 */  j          .L80014EF4
    /* 56C4 80014EC4 000062AC */   sw        $v0, 0x0($v1)
  .L80014EC8:
    /* 56C8 80014EC8 04188800 */  sllv       $v1, $t0, $a0
    /* 56CC 80014ECC 0380083C */  lui        $t0, %hi(g_SpuVoiceInfo)
    /* 56D0 80014ED0 0000E28E */  lw         $v0, 0x0($s7)
    /* 56D4 80014ED4 30660825 */  addiu      $t0, $t0, %lo(g_SpuVoiceInfo)
    /* 56D8 80014ED8 25104300 */  or         $v0, $v0, $v1
    /* 56DC 80014EDC 0000E2AE */  sw         $v0, 0x0($s7)
    /* 56E0 80014EE0 C0100400 */  sll        $v0, $a0, 3
    /* 56E4 80014EE4 21104800 */  addu       $v0, $v0, $t0
    /* 56E8 80014EE8 FF7F0324 */  addiu      $v1, $zero, 0x7FFF
    /* 56EC 80014EEC C00024AE */  sw         $a0, 0xC0($s1)
    /* 56F0 80014EF0 040043A4 */  sh         $v1, 0x4($v0)
  .L80014EF4:
    /* 56F4 80014EF4 C000248E */  lw         $a0, 0xC0($s1)
    /* 56F8 80014EF8 00000000 */  nop
    /* 56FC 80014EFC 1800822C */  sltiu      $v0, $a0, 0x18
    /* 5700 80014F00 1B004010 */  beqz       $v0, .L80014F70
    /* 5704 80014F04 27101200 */   nor       $v0, $zero, $s2
    /* 5708 80014F08 D6002696 */  lhu        $a2, 0xD6($s1)
    /* 570C 80014F0C 414F000C */  jal        SetVoiceParams
    /* 5710 80014F10 21286002 */   addu      $a1, $s3, $zero
    /* 5714 80014F14 0480083C */  lui        $t0, %hi(g_Sound_VoiceChannelConfigs)
    /* 5718 80014F18 689B0825 */  addiu      $t0, $t0, %lo(g_Sound_VoiceChannelConfigs)
    /* 571C 80014F1C C000228E */  lw         $v0, 0xC0($s1)
    /* 5720 80014F20 2078C38F */  lw         $v1, %lo(g_pActiveMusicConfig)($fp)
    /* 5724 80014F24 80100200 */  sll        $v0, $v0, 2
    /* 5728 80014F28 21104800 */  addu       $v0, $v0, $t0
    /* 572C 80014F2C 000043AC */  sw         $v1, 0x0($v0)
    /* 5730 80014F30 0480033C */  lui        $v1, %hi(g_Sound_GlobalFlags)
    /* 5734 80014F34 F89A6324 */  addiu      $v1, $v1, %lo(g_Sound_GlobalFlags)
    /* 5738 80014F38 0800628C */  lw         $v0, 0x8($v1)
    /* 573C 80014F3C 00000000 */  nop
    /* 5740 80014F40 00014234 */  ori        $v0, $v0, 0x100
    /* 5744 80014F44 DB530008 */  j          .L80014F6C
    /* 5748 80014F48 080062AC */   sw        $v0, 0x8($v1)
  .L80014F4C:
    /* 574C 80014F4C C000248E */  lw         $a0, 0xC0($s1)
    /* 5750 80014F50 00000000 */  nop
    /* 5754 80014F54 1800822C */  sltiu      $v0, $a0, 0x18
    /* 5758 80014F58 05004010 */  beqz       $v0, .L80014F70
    /* 575C 80014F5C 27101200 */   nor       $v0, $zero, $s2
    /* 5760 80014F60 0000268E */  lw         $a2, 0x0($s1)
    /* 5764 80014F64 6C4F000C */  jal        SetVoiceParamsByFlags
    /* 5768 80014F68 21286002 */   addu      $a1, $s3, $zero
  .L80014F6C:
    /* 576C 80014F6C 27101200 */  nor        $v0, $zero, $s2
  .L80014F70:
    /* 5770 80014F70 24A08202 */  and        $s4, $s4, $v0
  .L80014F74:
    /* 5774 80014F74 40901200 */  sll        $s2, $s2, 1
    /* 5778 80014F78 10013126 */  addiu      $s1, $s1, 0x110
    /* 577C 80014F7C 10017326 */  addiu      $s3, $s3, 0x110
    /* 5780 80014F80 1001D626 */  addiu      $s6, $s6, 0x110
    /* 5784 80014F84 93FF8016 */  bnez       $s4, .L80014DD4
    /* 5788 80014F88 0100B526 */   addiu     $s5, $s5, 0x1
    /* 578C 80014F8C 3C00BF8F */  lw         $ra, 0x3C($sp)
    /* 5790 80014F90 3800BE8F */  lw         $fp, 0x38($sp)
    /* 5794 80014F94 3400B78F */  lw         $s7, 0x34($sp)
    /* 5798 80014F98 3000B68F */  lw         $s6, 0x30($sp)
    /* 579C 80014F9C 2C00B58F */  lw         $s5, 0x2C($sp)
    /* 57A0 80014FA0 2800B48F */  lw         $s4, 0x28($sp)
    /* 57A4 80014FA4 2400B38F */  lw         $s3, 0x24($sp)
    /* 57A8 80014FA8 2000B28F */  lw         $s2, 0x20($sp)
    /* 57AC 80014FAC 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 57B0 80014FB0 1800B08F */  lw         $s0, 0x18($sp)
    /* 57B4 80014FB4 0800E003 */  jr         $ra
    /* 57B8 80014FB8 4000BD27 */   addiu     $sp, $sp, 0x40
endlabel func_80014D70
