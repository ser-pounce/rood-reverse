nonmatching SoundVM_AC_NoiseClockFrequency, 0x9C

glabel SoundVM_AC_NoiseClockFrequency
    /* CBA4 8001C3A4 0000828C */  lw         $v0, 0x0($a0)
    /* CBA8 8001C3A8 64008394 */  lhu        $v1, 0x64($a0)
    /* CBAC 8001C3AC 00004590 */  lbu        $a1, 0x0($v0)
    /* CBB0 8001C3B0 01004224 */  addiu      $v0, $v0, 0x1
    /* CBB4 8001C3B4 0F006014 */  bnez       $v1, .L8001C3F4
    /* CBB8 8001C3B8 000082AC */   sw        $v0, 0x0($a0)
    /* CBBC 8001C3BC C000A230 */  andi       $v0, $a1, 0xC0
    /* CBC0 8001C3C0 09004010 */  beqz       $v0, .L8001C3E8
    /* CBC4 8001C3C4 0380023C */   lui       $v0, %hi(g_pActiveMusicConfig)
    /* CBC8 8001C3C8 2078448C */  lw         $a0, %lo(g_pActiveMusicConfig)($v0)
    /* CBCC 8001C3CC 00000000 */  nop
    /* CBD0 8001C3D0 72008294 */  lhu        $v0, 0x72($a0)
    /* CBD4 8001C3D4 3F00A330 */  andi       $v1, $a1, 0x3F
    /* CBD8 8001C3D8 21104300 */  addu       $v0, $v0, $v1
    /* CBDC 8001C3DC 3F004230 */  andi       $v0, $v0, 0x3F
    /* CBE0 8001C3E0 09710008 */  j          .L8001C424
    /* CBE4 8001C3E4 720082A4 */   sh        $v0, 0x72($a0)
  .L8001C3E8:
    /* CBE8 8001C3E8 2078428C */  lw         $v0, %lo(g_pActiveMusicConfig)($v0)
    /* CBEC 8001C3EC 09710008 */  j          .L8001C424
    /* CBF0 8001C3F0 720045A4 */   sh        $a1, 0x72($v0)
  .L8001C3F4:
    /* CBF4 8001C3F4 C000A230 */  andi       $v0, $a1, 0xC0
    /* CBF8 8001C3F8 08004010 */  beqz       $v0, .L8001C41C
    /* CBFC 8001C3FC 0380023C */   lui       $v0, %hi(g_Sound_VoiceSchedulerState)
    /* CC00 8001C400 90784224 */  addiu      $v0, $v0, %lo(g_Sound_VoiceSchedulerState)
    /* CC04 8001C404 28004394 */  lhu        $v1, 0x28($v0)
    /* CC08 8001C408 3F00A430 */  andi       $a0, $a1, 0x3F
    /* CC0C 8001C40C 21186400 */  addu       $v1, $v1, $a0
    /* CC10 8001C410 3F006330 */  andi       $v1, $v1, 0x3F
    /* CC14 8001C414 09710008 */  j          .L8001C424
    /* CC18 8001C418 280043A4 */   sh        $v1, 0x28($v0)
  .L8001C41C:
    /* CC1C 8001C41C 0380023C */  lui        $v0, %hi(D_800378B8)
    /* CC20 8001C420 B87845A4 */  sh         $a1, %lo(D_800378B8)($v0)
  .L8001C424:
    /* CC24 8001C424 0480033C */  lui        $v1, %hi(g_Sound_GlobalFlags)
    /* CC28 8001C428 F89A6324 */  addiu      $v1, $v1, %lo(g_Sound_GlobalFlags)
    /* CC2C 8001C42C 0800628C */  lw         $v0, 0x8($v1)
    /* CC30 8001C430 00000000 */  nop
    /* CC34 8001C434 10004234 */  ori        $v0, $v0, 0x10
    /* CC38 8001C438 0800E003 */  jr         $ra
    /* CC3C 8001C43C 080062AC */   sw        $v0, 0x8($v1)
endlabel SoundVM_AC_NoiseClockFrequency
