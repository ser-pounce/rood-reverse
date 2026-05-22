nonmatching _updateWeaponKillStreak, 0x68

glabel _updateWeaponKillStreak
    /* 3964 8006C164 0F80023C */  lui        $v0, %hi(D_800F19CC)
    /* 3968 8006C168 0F80033C */  lui        $v1, %hi(vs_battle_characterState)
    /* 396C 8006C16C CC19428C */  lw         $v0, %lo(D_800F19CC)($v0)
    /* 3970 8006C170 FC19638C */  lw         $v1, %lo(vs_battle_characterState)($v1)
    /* 3974 8006C174 08004294 */  lhu        $v0, 0x8($v0)
    /* 3978 8006C178 3C00638C */  lw         $v1, 0x3C($v1)
    /* 397C 8006C17C 2800422C */  sltiu      $v0, $v0, 0x28
    /* 3980 8006C180 10004010 */  beqz       $v0, .L8006C1C4
    /* 3984 8006C184 0680023C */   lui       $v0, %hi(vs_main_scoredata)
    /* 3988 8006C188 A0FE4424 */  addiu      $a0, $v0, %lo(vs_main_scoredata)
    /* 398C 8006C18C 58006390 */  lbu        $v1, 0x58($v1)
    /* 3990 8006C190 0E018290 */  lbu        $v0, 0x10E($a0)
    /* 3994 8006C194 00000000 */  nop
    /* 3998 8006C198 04004310 */  beq        $v0, $v1, .L8006C1AC
    /* 399C 8006C19C 00000000 */   nop
    /* 39A0 8006C1A0 0E0183A0 */  sb         $v1, 0x10E($a0)
    /* 39A4 8006C1A4 0800E003 */  jr         $ra
    /* 39A8 8006C1A8 0F0180A0 */   sb        $zero, 0x10F($a0)
  .L8006C1AC:
    /* 39AC 8006C1AC 0F018390 */  lbu        $v1, 0x10F($a0)
    /* 39B0 8006C1B0 00000000 */  nop
    /* 39B4 8006C1B4 6400622C */  sltiu      $v0, $v1, 0x64
    /* 39B8 8006C1B8 02004010 */  beqz       $v0, .L8006C1C4
    /* 39BC 8006C1BC 01006224 */   addiu     $v0, $v1, 0x1
    /* 39C0 8006C1C0 0F0182A0 */  sb         $v0, 0x10F($a0)
  .L8006C1C4:
    /* 39C4 8006C1C4 0800E003 */  jr         $ra
    /* 39C8 8006C1C8 00000000 */   nop
endlabel _updateWeaponKillStreak
