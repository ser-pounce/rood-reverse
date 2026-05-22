nonmatching Sound_Cmd_9D_unk, 0x11C

glabel Sound_Cmd_9D_unk
    /* 9184 80018984 0380023C */  lui        $v0, %hi(g_Sound_VoiceSchedulerState)
    /* 9188 80018988 9078428C */  lw         $v0, %lo(g_Sound_VoiceSchedulerState)($v0)
    /* 918C 8001898C E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 9190 80018990 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 9194 80018994 1800B2AF */  sw         $s2, 0x18($sp)
    /* 9198 80018998 1400B1AF */  sw         $s1, 0x14($sp)
    /* 919C 8001899C 36004010 */  beqz       $v0, .L80018A78
    /* 91A0 800189A0 1000B0AF */   sw        $s0, 0x10($sp)
    /* 91A4 800189A4 21884000 */  addu       $s1, $v0, $zero
    /* 91A8 800189A8 0380023C */  lui        $v0, %hi(D_80035910)
    /* 91AC 800189AC 10594424 */  addiu      $a0, $v0, %lo(D_80035910)
    /* 91B0 800189B0 00101024 */  addiu      $s0, $zero, 0x1000
    /* 91B4 800189B4 21180000 */  addu       $v1, $zero, $zero
    /* 91B8 800189B8 0002053C */  lui        $a1, (0x2000000 >> 16)
  .L800189BC:
    /* 91BC 800189BC 24103002 */  and        $v0, $s1, $s0
    /* 91C0 800189C0 07004010 */  beqz       $v0, .L800189E0
    /* 91C4 800189C4 00000000 */   nop
    /* 91C8 800189C8 2800828C */  lw         $v0, 0x28($a0)
    /* 91CC 800189CC 00000000 */  nop
    /* 91D0 800189D0 24104500 */  and        $v0, $v0, $a1
    /* 91D4 800189D4 02004010 */  beqz       $v0, .L800189E0
    /* 91D8 800189D8 27101000 */   nor       $v0, $zero, $s0
    /* 91DC 800189DC 24882202 */  and        $s1, $s1, $v0
  .L800189E0:
    /* 91E0 800189E0 01006324 */  addiu      $v1, $v1, 0x1
    /* 91E4 800189E4 10018424 */  addiu      $a0, $a0, 0x110
    /* 91E8 800189E8 0C00622C */  sltiu      $v0, $v1, 0xC
    /* 91EC 800189EC F3FF4014 */  bnez       $v0, .L800189BC
    /* 91F0 800189F0 40801000 */   sll       $s0, $s0, 1
    /* 91F4 800189F4 00101024 */  addiu      $s0, $zero, 0x1000
    /* 91F8 800189F8 0C001224 */  addiu      $s2, $zero, 0xC
    /* 91FC 800189FC 0380043C */  lui        $a0, %hi(g_Sound_VoiceSchedulerState)
    /* 9200 80018A00 90788224 */  addiu      $v0, $a0, %lo(g_Sound_VoiceSchedulerState)
    /* 9204 80018A04 100051AC */  sw         $s1, 0x10($v0)
    /* 9208 80018A08 9078828C */  lw         $v0, %lo(g_Sound_VoiceSchedulerState)($a0)
    /* 920C 80018A0C 27181100 */  nor        $v1, $zero, $s1
    /* 9210 80018A10 24104300 */  and        $v0, $v0, $v1
    /* 9214 80018A14 18002012 */  beqz       $s1, .L80018A78
    /* 9218 80018A18 907882AC */   sw        $v0, %lo(g_Sound_VoiceSchedulerState)($a0)
  .L80018A1C:
    /* 921C 80018A1C 24103002 */  and        $v0, $s1, $s0
    /* 9220 80018A20 12004010 */  beqz       $v0, .L80018A6C
    /* 9224 80018A24 21204002 */   addu      $a0, $s2, $zero
    /* 9228 80018A28 21280000 */  addu       $a1, $zero, $zero
    /* 922C 80018A2C 2130A000 */  addu       $a2, $a1, $zero
    /* 9230 80018A30 D64E000C */  jal        SetVoiceVolume
    /* 9234 80018A34 2138A000 */   addu      $a3, $a1, $zero
    /* 9238 80018A38 21204002 */  addu       $a0, $s2, $zero
    /* 923C 80018A3C E84E000C */  jal        SetVoiceSampleRate
    /* 9240 80018A40 21280000 */   addu      $a1, $zero, $zero
    /* 9244 80018A44 21204002 */  addu       $a0, $s2, $zero
    /* 9248 80018A48 7F000524 */  addiu      $a1, $zero, 0x7F
    /* 924C 80018A4C 084F000C */  jal        SetVoiceAdsrAttackRateAndMode
    /* 9250 80018A50 01000624 */   addiu     $a2, $zero, 0x1
    /* 9254 80018A54 21204002 */  addu       $a0, $s2, $zero
    /* 9258 80018A58 7F000524 */  addiu      $a1, $zero, 0x7F
    /* 925C 80018A5C 284F000C */  jal        SetVoiceAdsrSustainRateAndDirection
    /* 9260 80018A60 03000624 */   addiu     $a2, $zero, 0x3
    /* 9264 80018A64 27101000 */  nor        $v0, $zero, $s0
    /* 9268 80018A68 24882202 */  and        $s1, $s1, $v0
  .L80018A6C:
    /* 926C 80018A6C 40801000 */  sll        $s0, $s0, 1
    /* 9270 80018A70 EAFF2016 */  bnez       $s1, .L80018A1C
    /* 9274 80018A74 01005226 */   addiu     $s2, $s2, 0x1
  .L80018A78:
    /* 9278 80018A78 0480033C */  lui        $v1, %hi(D_80039B64)
    /* 927C 80018A7C 649B628C */  lw         $v0, %lo(D_80039B64)($v1)
    /* 9280 80018A80 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 9284 80018A84 1800B28F */  lw         $s2, 0x18($sp)
    /* 9288 80018A88 1400B18F */  lw         $s1, 0x14($sp)
    /* 928C 80018A8C 1000B08F */  lw         $s0, 0x10($sp)
    /* 9290 80018A90 02004234 */  ori        $v0, $v0, 0x2
    /* 9294 80018A94 649B62AC */  sw         $v0, %lo(D_80039B64)($v1)
    /* 9298 80018A98 0800E003 */  jr         $ra
    /* 929C 80018A9C 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel Sound_Cmd_9D_unk
