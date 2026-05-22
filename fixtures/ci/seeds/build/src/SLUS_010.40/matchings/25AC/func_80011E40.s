nonmatching func_80011E40, 0x7C

glabel func_80011E40
    /* 2640 80011E40 0380023C */  lui        $v0, %hi(g_pActiveMusicConfig)
    /* 2644 80011E44 2078428C */  lw         $v0, %lo(g_pActiveMusicConfig)($v0)
    /* 2648 80011E48 0380033C */  lui        $v1, %hi(g_pSavedMousicConfig)
    /* 264C 80011E4C 0400428C */  lw         $v0, 0x4($v0)
    /* 2650 80011E50 2866648C */  lw         $a0, %lo(g_pSavedMousicConfig)($v1)
    /* 2654 80011E54 00000000 */  nop
    /* 2658 80011E58 06008010 */  beqz       $a0, .L80011E74
    /* 265C 80011E5C 2B180200 */   sltu      $v1, $zero, $v0
    /* 2660 80011E60 0400828C */  lw         $v0, 0x4($a0)
    /* 2664 80011E64 00000000 */  nop
    /* 2668 80011E68 03004010 */  beqz       $v0, .L80011E78
    /* 266C 80011E6C 0380023C */   lui       $v0, %hi(D_80037788)
    /* 2670 80011E70 02006334 */  ori        $v1, $v1, 0x2
  .L80011E74:
    /* 2674 80011E74 0380023C */  lui        $v0, %hi(D_80037788)
  .L80011E78:
    /* 2678 80011E78 8877428C */  lw         $v0, %lo(D_80037788)($v0)
    /* 267C 80011E7C 00000000 */  nop
    /* 2680 80011E80 02004010 */  beqz       $v0, .L80011E8C
    /* 2684 80011E84 0380023C */   lui       $v0, %hi(g_Sound_VoiceSchedulerState)
    /* 2688 80011E88 10006334 */  ori        $v1, $v1, 0x10
  .L80011E8C:
    /* 268C 80011E8C 9078428C */  lw         $v0, %lo(g_Sound_VoiceSchedulerState)($v0)
    /* 2690 80011E90 00000000 */  nop
    /* 2694 80011E94 02004010 */  beqz       $v0, .L80011EA0
    /* 2698 80011E98 0480023C */   lui       $v0, %hi(D_80039B14)
    /* 269C 80011E9C 00016334 */  ori        $v1, $v1, 0x100
  .L80011EA0:
    /* 26A0 80011EA0 149B428C */  lw         $v0, %lo(D_80039B14)($v0)
    /* 26A4 80011EA4 00000000 */  nop
    /* 26A8 80011EA8 02004010 */  beqz       $v0, .L80011EB4
    /* 26AC 80011EAC 0100023C */   lui       $v0, (0x10000 >> 16)
    /* 26B0 80011EB0 25186200 */  or         $v1, $v1, $v0
  .L80011EB4:
    /* 26B4 80011EB4 0800E003 */  jr         $ra
    /* 26B8 80011EB8 21106000 */   addu      $v0, $v1, $zero
endlabel func_80011E40
