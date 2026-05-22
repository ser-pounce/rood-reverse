nonmatching vs_battle_isSkillUnlocked, 0x48

glabel vs_battle_isSkillUnlocked
    /* 14AB4 8007D2B4 FFFF8224 */  addiu      $v0, $a0, -0x1
    /* 14AB8 8007D2B8 FF00422C */  sltiu      $v0, $v0, 0xFF
    /* 14ABC 8007D2BC 03004014 */  bnez       $v0, .L8007D2CC
    /* 14AC0 8007D2C0 0580023C */   lui       $v0, %hi(vs_main_skills)
    /* 14AC4 8007D2C4 0800E003 */  jr         $ra
    /* 14AC8 8007D2C8 21100000 */   addu      $v0, $zero, $zero
  .L8007D2CC:
    /* 14ACC 8007D2CC DCB94224 */  addiu      $v0, $v0, %lo(vs_main_skills)
    /* 14AD0 8007D2D0 40180400 */  sll        $v1, $a0, 1
    /* 14AD4 8007D2D4 21186400 */  addu       $v1, $v1, $a0
    /* 14AD8 8007D2D8 80180300 */  sll        $v1, $v1, 2
    /* 14ADC 8007D2DC 21186400 */  addu       $v1, $v1, $a0
    /* 14AE0 8007D2E0 80180300 */  sll        $v1, $v1, 2
    /* 14AE4 8007D2E4 21186200 */  addu       $v1, $v1, $v0
    /* 14AE8 8007D2E8 0C00628C */  lw         $v0, 0xC($v1)
    /* 14AEC 8007D2EC 00000000 */  nop
    /* 14AF0 8007D2F0 C2130200 */  srl        $v0, $v0, 15
    /* 14AF4 8007D2F4 0800E003 */  jr         $ra
    /* 14AF8 8007D2F8 01004230 */   andi      $v0, $v0, 0x1
endlabel vs_battle_isSkillUnlocked
