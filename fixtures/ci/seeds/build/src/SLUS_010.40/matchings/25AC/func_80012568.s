nonmatching func_80012568, 0x40

glabel func_80012568
    /* 2D68 80012568 07008010 */  beqz       $a0, .L80012588
    /* 2D6C 8001256C 0480033C */   lui       $v1, %hi(g_Sound_GlobalFlags)
    /* 2D70 80012570 F89A6324 */  addiu      $v1, $v1, %lo(g_Sound_GlobalFlags)
    /* 2D74 80012574 0400628C */  lw         $v0, 0x4($v1)
    /* 2D78 80012578 00000000 */  nop
    /* 2D7C 8001257C 10004234 */  ori        $v0, $v0, 0x10
    /* 2D80 80012580 68490008 */  j          .L800125A0
    /* 2D84 80012584 040062AC */   sw        $v0, 0x4($v1)
  .L80012588:
    /* 2D88 80012588 0480023C */  lui        $v0, %hi(g_Sound_GlobalFlags)
    /* 2D8C 8001258C F89A4224 */  addiu      $v0, $v0, %lo(g_Sound_GlobalFlags)
    /* 2D90 80012590 0400438C */  lw         $v1, 0x4($v0)
    /* 2D94 80012594 EFFF0424 */  addiu      $a0, $zero, -0x11
    /* 2D98 80012598 24186400 */  and        $v1, $v1, $a0
    /* 2D9C 8001259C 040043AC */  sw         $v1, 0x4($v0)
  .L800125A0:
    /* 2DA0 800125A0 0800E003 */  jr         $ra
    /* 2DA4 800125A4 21100000 */   addu      $v0, $zero, $zero
endlabel func_80012568
