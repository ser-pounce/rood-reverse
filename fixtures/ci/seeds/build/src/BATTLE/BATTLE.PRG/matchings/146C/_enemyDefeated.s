nonmatching _enemyDefeated, 0x84

glabel _enemyDefeated
    /* 39CC 8006C1CC E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 39D0 8006C1D0 0F80023C */  lui        $v0, %hi(vs_battle_actors)
    /* 39D4 8006C1D4 28194224 */  addiu      $v0, $v0, %lo(vs_battle_actors)
    /* 39D8 8006C1D8 80280500 */  sll        $a1, $a1, 2
    /* 39DC 8006C1DC 2128A200 */  addu       $a1, $a1, $v0
    /* 39E0 8006C1E0 1400BFAF */  sw         $ra, 0x14($sp)
    /* 39E4 8006C1E4 1000B0AF */  sw         $s0, 0x10($sp)
    /* 39E8 8006C1E8 0000B08C */  lw         $s0, 0x0($a1)
    /* 39EC 8006C1EC 00000000 */  nop
    /* 39F0 8006C1F0 27000392 */  lbu        $v1, 0x27($s0)
    /* 39F4 8006C1F4 80000224 */  addiu      $v0, $zero, 0x80
    /* 39F8 8006C1F8 11006210 */  beq        $v1, $v0, .L8006C240
    /* 39FC 8006C1FC 00000000 */   nop
    /* 3A00 8006C200 28000292 */  lbu        $v0, 0x28($s0)
    /* 3A04 8006C204 00000000 */  nop
    /* 3A08 8006C208 0D004014 */  bnez       $v0, .L8006C240
    /* 3A0C 8006C20C 00000000 */   nop
    /* 3A10 8006C210 0700C010 */  beqz       $a2, .L8006C230
    /* 3A14 8006C214 00000000 */   nop
    /* 3A18 8006C218 05008014 */  bnez       $a0, .L8006C230
    /* 3A1C 8006C21C 00000000 */   nop
    /* 3A20 8006C220 01B0010C */  jal        _updateEnemyKills
    /* 3A24 8006C224 21200002 */   addu      $a0, $s0, $zero
    /* 3A28 8006C228 59B0010C */  jal        _updateWeaponKillStreak
    /* 3A2C 8006C22C 21200000 */   addu      $a0, $zero, $zero
  .L8006C230:
    /* 3A30 8006C230 99AF010C */  jal        _dropLoot
    /* 3A34 8006C234 21200002 */   addu      $a0, $s0, $zero
    /* 3A38 8006C238 01000224 */  addiu      $v0, $zero, 0x1
    /* 3A3C 8006C23C 280002A2 */  sb         $v0, 0x28($s0)
  .L8006C240:
    /* 3A40 8006C240 1400BF8F */  lw         $ra, 0x14($sp)
    /* 3A44 8006C244 1000B08F */  lw         $s0, 0x10($sp)
    /* 3A48 8006C248 0800E003 */  jr         $ra
    /* 3A4C 8006C24C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel _enemyDefeated
