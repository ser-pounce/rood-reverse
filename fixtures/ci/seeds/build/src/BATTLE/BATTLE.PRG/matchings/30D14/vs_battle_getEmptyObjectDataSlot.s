nonmatching vs_battle_getEmptyObjectDataSlot, 0x38

glabel vs_battle_getEmptyObjectDataSlot
    /* 30DB0 800995B0 21180000 */  addu       $v1, $zero, $zero
    /* 30DB4 800995B4 0F80023C */  lui        $v0, %hi(vs_battle_objectDataSlots)
    /* 30DB8 800995B8 10234424 */  addiu      $a0, $v0, %lo(vs_battle_objectDataSlots)
  .L800995BC:
    /* 30DBC 800995BC 00008290 */  lbu        $v0, 0x0($a0)
    /* 30DC0 800995C0 00000000 */  nop
    /* 30DC4 800995C4 06004010 */  beqz       $v0, .L800995E0
    /* 30DC8 800995C8 21106000 */   addu      $v0, $v1, $zero
    /* 30DCC 800995CC 01006324 */  addiu      $v1, $v1, 0x1
    /* 30DD0 800995D0 10006228 */  slti       $v0, $v1, 0x10
    /* 30DD4 800995D4 F9FF4014 */  bnez       $v0, .L800995BC
    /* 30DD8 800995D8 14008424 */   addiu     $a0, $a0, 0x14
    /* 30DDC 800995DC FFFF0224 */  addiu      $v0, $zero, -0x1
  .L800995E0:
    /* 30DE0 800995E0 0800E003 */  jr         $ra
    /* 30DE4 800995E4 00000000 */   nop
endlabel vs_battle_getEmptyObjectDataSlot
