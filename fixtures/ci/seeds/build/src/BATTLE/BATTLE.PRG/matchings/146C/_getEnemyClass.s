nonmatching _getEnemyClass, 0x30

glabel _getEnemyClass
    /* 16D18 8007F518 0F80033C */  lui        $v1, %hi(vs_battle_actors)
    /* 16D1C 8007F51C 00008290 */  lbu        $v0, 0x0($a0)
    /* 16D20 8007F520 28196324 */  addiu      $v1, $v1, %lo(vs_battle_actors)
    /* 16D24 8007F524 80100200 */  sll        $v0, $v0, 2
    /* 16D28 8007F528 21104300 */  addu       $v0, $v0, $v1
    /* 16D2C 8007F52C 0000428C */  lw         $v0, 0x0($v0)
    /* 16D30 8007F530 00000000 */  nop
    /* 16D34 8007F534 3C00428C */  lw         $v0, 0x3C($v0)
    /* 16D38 8007F538 00000000 */  nop
    /* 16D3C 8007F53C 37004290 */  lbu        $v0, 0x37($v0)
    /* 16D40 8007F540 0800E003 */  jr         $ra
    /* 16D44 8007F544 07004230 */   andi      $v0, $v0, 0x7
endlabel _getEnemyClass
