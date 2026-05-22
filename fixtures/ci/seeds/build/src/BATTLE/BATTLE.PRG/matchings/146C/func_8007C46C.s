nonmatching func_8007C46C, 0x40

glabel func_8007C46C
    /* 13C6C 8007C46C 0F80033C */  lui        $v1, %hi(vs_battle_screenTransitionStep)
    /* 13C70 8007C470 481A628C */  lw         $v0, %lo(vs_battle_screenTransitionStep)($v1)
    /* 13C74 8007C474 00000000 */  nop
    /* 13C78 8007C478 FFFF4224 */  addiu      $v0, $v0, -0x1
    /* 13C7C 8007C47C 0200422C */  sltiu      $v0, $v0, 0x2
    /* 13C80 8007C480 08004014 */  bnez       $v0, .L8007C4A4
    /* 13C84 8007C484 05000224 */   addiu     $v0, $zero, 0x5
    /* 13C88 8007C488 481A62AC */  sw         $v0, %lo(vs_battle_screenTransitionStep)($v1)
    /* 13C8C 8007C48C 0F80023C */  lui        $v0, %hi(vs_battle_screenTransitionEffect)
    /* 13C90 8007C490 981A44AC */  sw         $a0, %lo(vs_battle_screenTransitionEffect)($v0)
    /* 13C94 8007C494 0F80023C */  lui        $v0, %hi(vs_battle_screenTransitionSpeed)
    /* 13C98 8007C498 A81A45AC */  sw         $a1, %lo(vs_battle_screenTransitionSpeed)($v0)
    /* 13C9C 8007C49C 0F80023C */  lui        $v0, %hi(vs_battle_screenTransitionWipeAngle)
    /* 13CA0 8007C4A0 A41A46AC */  sw         $a2, %lo(vs_battle_screenTransitionWipeAngle)($v0)
  .L8007C4A4:
    /* 13CA4 8007C4A4 0800E003 */  jr         $ra
    /* 13CA8 8007C4A8 00000000 */   nop
endlabel func_8007C46C
