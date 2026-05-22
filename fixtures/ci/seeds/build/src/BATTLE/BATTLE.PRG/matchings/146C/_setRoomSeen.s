nonmatching _setRoomSeen, 0x90

glabel _setRoomSeen
    /* 6D3C 8006F53C E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 6D40 8006F540 1800B2AF */  sw         $s2, 0x18($sp)
    /* 6D44 8006F544 0F80123C */  lui        $s2, %hi(D_800F19A0)
    /* 6D48 8006F548 A019428E */  lw         $v0, %lo(D_800F19A0)($s2)
    /* 6D4C 8006F54C 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 6D50 8006F550 1400B1AF */  sw         $s1, 0x14($sp)
    /* 6D54 8006F554 17004010 */  beqz       $v0, .L8006F5B4
    /* 6D58 8006F558 1000B0AF */   sw        $s0, 0x10($sp)
    /* 6D5C 8006F55C 0035020C */  jal        vs_battle_getCurrentSceneId
    /* 6D60 8006F560 0680113C */   lui       $s1, %hi(vs_main_mapStatus)
    /* 6D64 8006F564 D8FF3126 */  addiu      $s1, $s1, %lo(vs_main_mapStatus)
    /* 6D68 8006F568 42210200 */  srl        $a0, $v0, 5
    /* 6D6C 8006F56C 80200400 */  sll        $a0, $a0, 2
    /* 6D70 8006F570 21209100 */  addu       $a0, $a0, $s1
    /* 6D74 8006F574 1F004230 */  andi       $v0, $v0, 0x1F
    /* 6D78 8006F578 01001024 */  addiu      $s0, $zero, 0x1
    /* 6D7C 8006F57C 4000838C */  lw         $v1, 0x40($a0)
    /* 6D80 8006F580 04105000 */  sllv       $v0, $s0, $v0
    /* 6D84 8006F584 25186200 */  or         $v1, $v1, $v0
    /* 6D88 8006F588 1DF2010C */  jal        vs_battle_getCurrentRoomId
    /* 6D8C 8006F58C 400083AC */   sw        $v1, 0x40($a0)
    /* 6D90 8006F590 42210200 */  srl        $a0, $v0, 5
    /* 6D94 8006F594 80200400 */  sll        $a0, $a0, 2
    /* 6D98 8006F598 21209100 */  addu       $a0, $a0, $s1
    /* 6D9C 8006F59C 1F004230 */  andi       $v0, $v0, 0x1F
    /* 6DA0 8006F5A0 0000838C */  lw         $v1, 0x0($a0)
    /* 6DA4 8006F5A4 04805000 */  sllv       $s0, $s0, $v0
    /* 6DA8 8006F5A8 A01940AE */  sw         $zero, %lo(D_800F19A0)($s2)
    /* 6DAC 8006F5AC 25187000 */  or         $v1, $v1, $s0
    /* 6DB0 8006F5B0 000083AC */  sw         $v1, 0x0($a0)
  .L8006F5B4:
    /* 6DB4 8006F5B4 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 6DB8 8006F5B8 1800B28F */  lw         $s2, 0x18($sp)
    /* 6DBC 8006F5BC 1400B18F */  lw         $s1, 0x14($sp)
    /* 6DC0 8006F5C0 1000B08F */  lw         $s0, 0x10($sp)
    /* 6DC4 8006F5C4 0800E003 */  jr         $ra
    /* 6DC8 8006F5C8 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel _setRoomSeen
