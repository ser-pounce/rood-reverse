nonmatching func_800122F0, 0x68

glabel func_800122F0
    /* 2AF0 800122F0 0380023C */  lui        $v0, %hi(g_Sound_VoiceSchedulerState)
    /* 2AF4 800122F4 9078468C */  lw         $a2, %lo(g_Sound_VoiceSchedulerState)($v0)
    /* 2AF8 800122F8 00000000 */  nop
    /* 2AFC 800122FC 0300C014 */  bnez       $a2, .L8001230C
    /* 2B00 80012300 0380023C */   lui       $v0, %hi(D_80035910)
    /* 2B04 80012304 0800E003 */  jr         $ra
    /* 2B08 80012308 21100000 */   addu      $v0, $zero, $zero
  .L8001230C:
    /* 2B0C 8001230C 10594524 */  addiu      $a1, $v0, %lo(D_80035910)
    /* 2B10 80012310 21200000 */  addu       $a0, $zero, $zero
    /* 2B14 80012314 00100324 */  addiu      $v1, $zero, 0x1000
    /* 2B18 80012318 FF00073C */  lui        $a3, (0xFFFFFF >> 16)
    /* 2B1C 8001231C FFFFE734 */  ori        $a3, $a3, (0xFFFFFF & 0xFFFF)
  .L80012320:
    /* 2B20 80012320 2410C300 */  and        $v0, $a2, $v1
    /* 2B24 80012324 04004010 */  beqz       $v0, .L80012338
    /* 2B28 80012328 00000000 */   nop
    /* 2B2C 8001232C 2800A28C */  lw         $v0, 0x28($a1)
    /* 2B30 80012330 00000000 */  nop
    /* 2B34 80012334 25208200 */  or         $a0, $a0, $v0
  .L80012338:
    /* 2B38 80012338 40180300 */  sll        $v1, $v1, 1
    /* 2B3C 8001233C 24106700 */  and        $v0, $v1, $a3
    /* 2B40 80012340 F7FF4014 */  bnez       $v0, .L80012320
    /* 2B44 80012344 1001A524 */   addiu     $a1, $a1, 0x110
    /* 2B48 80012348 FF00023C */  lui        $v0, (0xFFFFFF >> 16)
    /* 2B4C 8001234C FFFF4234 */  ori        $v0, $v0, (0xFFFFFF & 0xFFFF)
    /* 2B50 80012350 0800E003 */  jr         $ra
    /* 2B54 80012354 24108200 */   and       $v0, $a0, $v0
endlabel func_800122F0
