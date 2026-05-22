nonmatching vs_battle_setSkillUnlocked, 0x44

glabel vs_battle_setSkillUnlocked
    /* 14AFC 8007D2FC FFFF8224 */  addiu      $v0, $a0, -0x1
    /* 14B00 8007D300 FF00422C */  sltiu      $v0, $v0, 0xFF
    /* 14B04 8007D304 0C004010 */  beqz       $v0, .L8007D338
    /* 14B08 8007D308 0580023C */   lui       $v0, %hi(vs_main_skills)
    /* 14B0C 8007D30C DCB94224 */  addiu      $v0, $v0, %lo(vs_main_skills)
    /* 14B10 8007D310 40180400 */  sll        $v1, $a0, 1
    /* 14B14 8007D314 21186400 */  addu       $v1, $v1, $a0
    /* 14B18 8007D318 80180300 */  sll        $v1, $v1, 2
    /* 14B1C 8007D31C 21186400 */  addu       $v1, $v1, $a0
    /* 14B20 8007D320 80180300 */  sll        $v1, $v1, 2
    /* 14B24 8007D324 21186200 */  addu       $v1, $v1, $v0
    /* 14B28 8007D328 0C00628C */  lw         $v0, 0xC($v1)
    /* 14B2C 8007D32C 00000000 */  nop
    /* 14B30 8007D330 00804234 */  ori        $v0, $v0, 0x8000
    /* 14B34 8007D334 0C0062AC */  sw         $v0, 0xC($v1)
  .L8007D338:
    /* 14B38 8007D338 0800E003 */  jr         $ra
    /* 14B3C 8007D33C 00000000 */   nop
endlabel vs_battle_setSkillUnlocked
