nonmatching func_800133E0, 0x38

glabel func_800133E0
    /* 3BE0 800133E0 0380023C */  lui        $v0, %hi(D_80035910)
    /* 3BE4 800133E4 10594524 */  addiu      $a1, $v0, %lo(D_80035910)
    /* 3BE8 800133E8 21180000 */  addu       $v1, $zero, $zero
  .L800133EC:
    /* 3BEC 800133EC 3C00A28C */  lw         $v0, 0x3C($a1)
    /* 3BF0 800133F0 1001A524 */  addiu      $a1, $a1, 0x110
    /* 3BF4 800133F4 01006324 */  addiu      $v1, $v1, 0x1
    /* 3BF8 800133F8 000082AC */  sw         $v0, 0x0($a0)
    /* 3BFC 800133FC 0C006228 */  slti       $v0, $v1, 0xC
    /* 3C00 80013400 FAFF4014 */  bnez       $v0, .L800133EC
    /* 3C04 80013404 04008424 */   addiu     $a0, $a0, 0x4
    /* 3C08 80013408 0380023C */  lui        $v0, %hi(g_Sound_VoiceSchedulerState)
    /* 3C0C 8001340C 9078428C */  lw         $v0, %lo(g_Sound_VoiceSchedulerState)($v0)
    /* 3C10 80013410 0800E003 */  jr         $ra
    /* 3C14 80013414 00000000 */   nop
endlabel func_800133E0
