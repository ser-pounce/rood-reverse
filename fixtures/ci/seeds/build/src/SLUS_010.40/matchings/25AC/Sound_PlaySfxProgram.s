nonmatching Sound_PlaySfxProgram, 0x1B4

glabel Sound_PlaySfxProgram
    /* 6F44 80016744 C8FFBD27 */  addiu      $sp, $sp, -0x38
    /* 6F48 80016748 2C00B7AF */  sw         $s7, 0x2C($sp)
    /* 6F4C 8001674C 21B88000 */  addu       $s7, $a0, $zero
    /* 6F50 80016750 2800B6AF */  sw         $s6, 0x28($sp)
    /* 6F54 80016754 21B0A000 */  addu       $s6, $a1, $zero
    /* 6F58 80016758 3000BEAF */  sw         $fp, 0x30($sp)
    /* 6F5C 8001675C 21F0C000 */  addu       $fp, $a2, $zero
    /* 6F60 80016760 3400BFAF */  sw         $ra, 0x34($sp)
    /* 6F64 80016764 2400B5AF */  sw         $s5, 0x24($sp)
    /* 6F68 80016768 2000B4AF */  sw         $s4, 0x20($sp)
    /* 6F6C 8001676C 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 6F70 80016770 1800B2AF */  sw         $s2, 0x18($sp)
    /* 6F74 80016774 1400B1AF */  sw         $s1, 0x14($sp)
    /* 6F78 80016778 0300C016 */  bnez       $s6, .L80016788
    /* 6F7C 8001677C 1000B0AF */   sw        $s0, 0x10($sp)
    /* 6F80 80016780 5100C013 */  beqz       $fp, .L800168C8
    /* 6F84 80016784 00000000 */   nop
  .L80016788:
    /* 6F88 80016788 0800E014 */  bnez       $a3, .L800167AC
    /* 6F8C 8001678C 0380133C */   lui       $s3, %hi(g_Sound_VoiceSchedulerState)
    /* 6F90 80016790 0400E58E */  lw         $a1, 0x4($s7)
    /* 6F94 80016794 00000000 */  nop
    /* 6F98 80016798 0500A010 */  beqz       $a1, .L800167B0
    /* 6F9C 8001679C 90787526 */   addiu     $s5, $s3, %lo(g_Sound_VoiceSchedulerState)
    /* 6FA0 800167A0 7158000C */  jal        func_800161C4
    /* 6FA4 800167A4 21200000 */   addu      $a0, $zero, $zero
    /* 6FA8 800167A8 0380133C */  lui        $s3, %hi(g_Sound_VoiceSchedulerState)
  .L800167AC:
    /* 6FAC 800167AC 90787526 */  addiu      $s5, $s3, %lo(g_Sound_VoiceSchedulerState)
  .L800167B0:
    /* 6FB0 800167B0 0480023C */  lui        $v0, %hi(g_Sound_Cutscene_StreamState)
    /* 6FB4 800167B4 089B5424 */  addiu      $s4, $v0, %lo(g_Sound_Cutscene_StreamState)
    /* 6FB8 800167B8 0380023C */  lui        $v0, %hi(SfxSoundChannels)
    /* 6FBC 800167BC B0635124 */  addiu      $s1, $v0, %lo(SfxSoundChannels)
  .L800167C0:
    /* 6FC0 800167C0 4000103C */  lui        $s0, (0x400000 >> 16)
    /* 6FC4 800167C4 0C000524 */  addiu      $a1, $zero, 0xC
    /* 6FC8 800167C8 9078628E */  lw         $v0, %lo(g_Sound_VoiceSchedulerState)($s3)
    /* 6FCC 800167CC 1000A38E */  lw         $v1, 0x10($s5)
    /* 6FD0 800167D0 0C00848E */  lw         $a0, 0xC($s4)
    /* 6FD4 800167D4 25104300 */  or         $v0, $v0, $v1
    /* 6FD8 800167D8 25904400 */  or         $s2, $v0, $a0
  .L800167DC:
    /* 6FDC 800167DC 40101000 */  sll        $v0, $s0, 1
    /* 6FE0 800167E0 25100202 */  or         $v0, $s0, $v0
    /* 6FE4 800167E4 24104202 */  and        $v0, $s2, $v0
    /* 6FE8 800167E8 05004010 */  beqz       $v0, .L80016800
    /* 6FEC 800167EC 00000000 */   nop
    /* 6FF0 800167F0 FEFFA524 */  addiu      $a1, $a1, -0x2
    /* 6FF4 800167F4 E0FD3126 */  addiu      $s1, $s1, -0x220
    /* 6FF8 800167F8 F8FFA014 */  bnez       $a1, .L800167DC
    /* 6FFC 800167FC 82801000 */   srl       $s0, $s0, 2
  .L80016800:
    /* 7000 80016800 0C00A014 */  bnez       $a1, .L80016834
    /* 7004 80016804 21200000 */   addu      $a0, $zero, $zero
    /* 7008 80016808 7158000C */  jal        func_800161C4
    /* 700C 8001680C 0040053C */   lui       $a1, (0x40000000 >> 16)
    /* 7010 80016810 9078628E */  lw         $v0, %lo(g_Sound_VoiceSchedulerState)($s3)
    /* 7014 80016814 1000A38E */  lw         $v1, 0x10($s5)
    /* 7018 80016818 0C00848E */  lw         $a0, 0xC($s4)
    /* 701C 8001681C 25104300 */  or         $v0, $v0, $v1
    /* 7020 80016820 25104400 */  or         $v0, $v0, $a0
    /* 7024 80016824 28004212 */  beq        $s2, $v0, .L800168C8
    /* 7028 80016828 0380023C */   lui       $v0, %hi(SfxSoundChannels)
    /* 702C 8001682C F0590008 */  j          .L800167C0
    /* 7030 80016830 B0635124 */   addiu     $s1, $v0, %lo(SfxSoundChannels)
  .L80016834:
    /* 7034 80016834 0900C012 */  beqz       $s6, .L8001685C
    /* 7038 80016838 2128E002 */   addu      $a1, $s7, $zero
    /* 703C 8001683C 21202002 */  addu       $a0, $s1, $zero
    /* 7040 80016840 21300002 */  addu       $a2, $s0, $zero
    /* 7044 80016844 4F59000C */  jal        func_8001653C
    /* 7048 80016848 2138C002 */   addu      $a3, $s6, $zero
    /* 704C 8001684C F400258E */  lw         $a1, 0xF4($s1)
    /* 7050 80016850 0380043C */  lui        $a0, %hi(g_ActiveMusicChannels)
    /* 7054 80016854 BA59000C */  jal        FreeVoiceChannels
    /* 7058 80016858 90368424 */   addiu     $a0, $a0, %lo(g_ActiveMusicChannels)
  .L8001685C:
    /* 705C 8001685C 1500C013 */  beqz       $fp, .L800168B4
    /* 7060 80016860 0480033C */   lui       $v1, %hi(g_Sound_GlobalFlags)
    /* 7064 80016864 0300C012 */  beqz       $s6, .L80016874
    /* 7068 80016868 00000000 */   nop
    /* 706C 8001686C 10013126 */  addiu      $s1, $s1, 0x110
    /* 7070 80016870 40801000 */  sll        $s0, $s0, 1
  .L80016874:
    /* 7074 80016874 21202002 */  addu       $a0, $s1, $zero
    /* 7078 80016878 2128E002 */  addu       $a1, $s7, $zero
    /* 707C 8001687C 21300002 */  addu       $a2, $s0, $zero
    /* 7080 80016880 4F59000C */  jal        func_8001653C
    /* 7084 80016884 2138C003 */   addu      $a3, $fp, $zero
    /* 7088 80016888 F400258E */  lw         $a1, 0xF4($s1)
    /* 708C 8001688C 0380043C */  lui        $a0, %hi(g_ActiveMusicChannels)
    /* 7090 80016890 BA59000C */  jal        FreeVoiceChannels
    /* 7094 80016894 90368424 */   addiu     $a0, $a0, %lo(g_ActiveMusicChannels)
    /* 7098 80016898 0500C012 */  beqz       $s6, .L800168B0
    /* 709C 8001689C 0100033C */   lui       $v1, (0x10000 >> 16)
    /* 70A0 800168A0 3400228E */  lw         $v0, 0x34($s1)
    /* 70A4 800168A4 00000000 */  nop
    /* 70A8 800168A8 25104300 */  or         $v0, $v0, $v1
    /* 70AC 800168AC 340022AE */  sw         $v0, 0x34($s1)
  .L800168B0:
    /* 70B0 800168B0 0480033C */  lui        $v1, %hi(g_Sound_GlobalFlags)
  .L800168B4:
    /* 70B4 800168B4 F89A6324 */  addiu      $v1, $v1, %lo(g_Sound_GlobalFlags)
    /* 70B8 800168B8 0800628C */  lw         $v0, 0x8($v1)
    /* 70BC 800168BC 00000000 */  nop
    /* 70C0 800168C0 10014234 */  ori        $v0, $v0, 0x110
    /* 70C4 800168C4 080062AC */  sw         $v0, 0x8($v1)
  .L800168C8:
    /* 70C8 800168C8 3400BF8F */  lw         $ra, 0x34($sp)
    /* 70CC 800168CC 3000BE8F */  lw         $fp, 0x30($sp)
    /* 70D0 800168D0 2C00B78F */  lw         $s7, 0x2C($sp)
    /* 70D4 800168D4 2800B68F */  lw         $s6, 0x28($sp)
    /* 70D8 800168D8 2400B58F */  lw         $s5, 0x24($sp)
    /* 70DC 800168DC 2000B48F */  lw         $s4, 0x20($sp)
    /* 70E0 800168E0 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 70E4 800168E4 1800B28F */  lw         $s2, 0x18($sp)
    /* 70E8 800168E8 1400B18F */  lw         $s1, 0x14($sp)
    /* 70EC 800168EC 1000B08F */  lw         $s0, 0x10($sp)
    /* 70F0 800168F0 0800E003 */  jr         $ra
    /* 70F4 800168F4 3800BD27 */   addiu     $sp, $sp, 0x38
endlabel Sound_PlaySfxProgram
