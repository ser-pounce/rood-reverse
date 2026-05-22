nonmatching Sound_Cmd_A8_unk, 0x7C

glabel Sound_Cmd_A8_unk
    /* 82D8 80017AD8 00100724 */  addiu      $a3, $zero, 0x1000
    /* 82DC 80017ADC 0380023C */  lui        $v0, %hi(g_Sound_VoiceSchedulerState)
    /* 82E0 80017AE0 9078488C */  lw         $t0, %lo(g_Sound_VoiceSchedulerState)($v0)
    /* 82E4 80017AE4 21300000 */  addu       $a2, $zero, $zero
    /* 82E8 80017AE8 0002093C */  lui        $t1, (0x2000000 >> 16)
    /* 82EC 80017AEC 0380023C */  lui        $v0, %hi(D_80035910)
    /* 82F0 80017AF0 10594224 */  addiu      $v0, $v0, %lo(D_80035910)
    /* 82F4 80017AF4 F8004524 */  addiu      $a1, $v0, 0xF8
  .L80017AF8:
    /* 82F8 80017AF8 24100701 */  and        $v0, $t0, $a3
    /* 82FC 80017AFC 0E004010 */  beqz       $v0, .L80017B38
    /* 8300 80017B00 00000000 */   nop
    /* 8304 80017B04 30FFA28C */  lw         $v0, -0xD0($a1)
    /* 8308 80017B08 00000000 */  nop
    /* 830C 80017B0C 24104900 */  and        $v0, $v0, $t1
    /* 8310 80017B10 09004014 */  bnez       $v0, .L80017B38
    /* 8314 80017B14 00000000 */   nop
    /* 8318 80017B18 00008294 */  lhu        $v0, 0x0($a0)
    /* 831C 80017B1C 0000A38C */  lw         $v1, 0x0($a1)
    /* 8320 80017B20 94FFA0A4 */  sh         $zero, -0x6C($a1)
    /* 8324 80017B24 7F004230 */  andi       $v0, $v0, 0x7F
    /* 8328 80017B28 00120200 */  sll        $v0, $v0, 8
    /* 832C 80017B2C 03006334 */  ori        $v1, $v1, 0x3
    /* 8330 80017B30 E4FFA2A4 */  sh         $v0, -0x1C($a1)
    /* 8334 80017B34 0000A3AC */  sw         $v1, 0x0($a1)
  .L80017B38:
    /* 8338 80017B38 0100C624 */  addiu      $a2, $a2, 0x1
    /* 833C 80017B3C 1001A524 */  addiu      $a1, $a1, 0x110
    /* 8340 80017B40 0C00C22C */  sltiu      $v0, $a2, 0xC
    /* 8344 80017B44 ECFF4014 */  bnez       $v0, .L80017AF8
    /* 8348 80017B48 40380700 */   sll       $a3, $a3, 1
    /* 834C 80017B4C 0800E003 */  jr         $ra
    /* 8350 80017B50 00000000 */   nop
endlabel Sound_Cmd_A8_unk
