nonmatching func_800834A4, 0x40

glabel func_800834A4
    /* 1ACA4 800834A4 0F80033C */  lui        $v1, %hi(vs_battle_actors)
    /* 1ACA8 800834A8 0000C290 */  lbu        $v0, 0x0($a2)
    /* 1ACAC 800834AC 28196324 */  addiu      $v1, $v1, %lo(vs_battle_actors)
    /* 1ACB0 800834B0 80100200 */  sll        $v0, $v0, 2
    /* 1ACB4 800834B4 21104300 */  addu       $v0, $v0, $v1
    /* 1ACB8 800834B8 0000428C */  lw         $v0, 0x0($v0)
    /* 1ACBC 800834BC 00000000 */  nop
    /* 1ACC0 800834C0 3C00438C */  lw         $v1, 0x3C($v0)
    /* 1ACC4 800834C4 00000000 */  nop
    /* 1ACC8 800834C8 1A006294 */  lhu        $v0, 0x1A($v1)
    /* 1ACCC 800834CC 18006394 */  lhu        $v1, 0x18($v1)
    /* 1ACD0 800834D0 00000000 */  nop
    /* 1ACD4 800834D4 23104300 */  subu       $v0, $v0, $v1
    /* 1ACD8 800834D8 00140200 */  sll        $v0, $v0, 16
    /* 1ACDC 800834DC 0800E003 */  jr         $ra
    /* 1ACE0 800834E0 03140200 */   sra       $v0, $v0, 16
endlabel func_800834A4
